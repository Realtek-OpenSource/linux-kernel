/*
 * Power Control core & APIs
 *
 * Copyright (C) 2016-2017,2019 Realtek Semiconductor Corporation
 * Copyright (C) 2016-2017,2019 Cheng-Yu Lee <cylee12@realtek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#define pr_fmt(fmt) "power_control: " fmt
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/of.h>
#include <linux/spinlock.h>
#include "pwrctrl_driver.h"

DEFINE_MUTEX(power_control_list_lock);
LIST_HEAD(power_control_list);

int power_control_power_on(struct power_control *pctrl)
{
	int ret = 0;

	if (!pctrl)
		return -EINVAL;

	if (pctrl->ops->power_on)
		ret = pctrl->ops->power_on(pctrl);

	__power_control_stat_update(pctrl, POWER_CONTROL_ACT_CALL_ON);
	return ret;
}
EXPORT_SYMBOL_GPL(power_control_power_on);

int power_control_power_off(struct power_control *pctrl)
{
	int ret = 0;

	if (!pctrl)
		return -EINVAL;

	if (pctrl->ops->power_off)
		ret = pctrl->ops->power_off(pctrl);

	__power_control_stat_update(pctrl, POWER_CONTROL_ACT_CALL_OFF);
	return ret;
}
EXPORT_SYMBOL_GPL(power_control_power_off);

int power_control_is_powered_on(struct power_control *pctrl)
{
	if (!pctrl)
		return -EINVAL;

	if (pctrl->ops->is_powered_on)
		return pctrl->ops->is_powered_on(pctrl);

	return -EINVAL;
}
EXPORT_SYMBOL_GPL(power_control_is_powered_on);

int power_control_init(struct power_control *pctrl)
{
	if (WARN_ON(!pctrl))
		return -ENODEV;

	if (pctrl->ops->init)
		return pctrl->ops->init(pctrl);
	return -EINVAL;
}
EXPORT_SYMBOL_GPL(power_control_init);

struct power_control *__power_control_get(const char *name)
{
	struct power_control *ctrl = NULL;
	struct list_head *it = NULL;

	list_for_each(it, &power_control_list) {
		ctrl = to_power_control(it);
		if (!strcmp(ctrl->name, name))
			return ctrl;
	}

	return NULL;
}
EXPORT_SYMBOL_GPL(__power_control_get);

struct power_control *power_control_get(const char *name)
{
	struct power_control *ctrl;

	__list_lock();
	ctrl = __power_control_get(name);
	__list_unlock();
	atomic_inc(&ctrl->usage_cnt);
	return ctrl;
}
EXPORT_SYMBOL_GPL(power_control_get);

struct of_power_control_provider {
	struct list_head list;
	struct device_node *node;
	power_control_xlate_t xlate;
	void *data;
};

static LIST_HEAD(of_power_control_providers);
static DEFINE_MUTEX(of_power_control_provider_lock);

struct power_control *of_power_control_xlate_simple(
	struct of_phandle_args *args, void *data)
{
	if (args->args_count != 0)
		return ERR_PTR(-EINVAL);
	return data;
}

struct power_control *of_power_control_xlate_onecell(
	struct of_phandle_args *args, void *data)
{
	struct power_control_onecell_data *ctrl_data = data;
	unsigned int idx = args->args[0];

	if (args->args_count != 1)
		return ERR_PTR(-EINVAL);

	if (idx > ctrl_data->num_controls) {
		pr_err("%s: invalid index %u\n", __func__, idx);
		return ERR_PTR(-EINVAL);
	}

	if (!ctrl_data->controls[idx])
		return ERR_PTR(-ENOENT);

	return ctrl_data->controls[idx];
}

int of_power_control_add_provider(struct device_node *np,
				  power_control_xlate_t xlate,
				  void *data)
{
	struct of_power_control_provider *pp;

	pp = kzalloc(sizeof(*pp), GFP_KERNEL);
	if (!pp)
		return -ENOMEM;

	pp->node = np;
	pp->data = data;
	pp->xlate = xlate;

	mutex_lock(&of_power_control_provider_lock);
	list_add(&pp->list, &of_power_control_providers);
	mutex_unlock(&of_power_control_provider_lock);
	return 0;
}

void of_power_control_del_provider(struct device_node *np)
{
	struct of_power_control_provider *pp;

	mutex_lock(&of_power_control_provider_lock);
	list_for_each_entry(pp, &of_power_control_providers, list) {
		if (pp->node == np) {
			list_del(&pp->list);
			of_node_put(pp->node);
			kfree(pp);
			break;
		}
	}
	mutex_unlock(&of_power_control_provider_lock);
}

struct power_control *of_power_control_get_from_provider(struct of_phandle_args *args)
{
	struct power_control *ctrl = ERR_PTR(-ENOENT);
	struct of_power_control_provider *provider;


	mutex_lock(&of_power_control_provider_lock);
	list_for_each_entry(provider, &of_power_control_providers, list) {
		if (provider->node == args->np)
			ctrl = provider->xlate(args, provider->data);
		if (!IS_ERR(ctrl))
			break;
	}
	mutex_unlock(&of_power_control_provider_lock);

	return ctrl;
}

struct power_control *__of_power_control_get_by_index(struct device_node *node,
						      int index)
{
	struct of_phandle_args args;
	int ret;

	ret = of_parse_phandle_with_args(node, "powerctrls", "#powerctrl-cells",
		index, &args);
	if (ret)
		return ERR_PTR(ret);

	return of_power_control_get_from_provider(&args);
}

struct power_control *of_power_control_get_by_index(struct device_node *node,
						    int index)
{
	struct power_control *ctrl = NULL;

	__list_lock();
	ctrl = __of_power_control_get_by_index(node, index);
	__list_unlock();

	if (IS_ERR(ctrl))
		return ctrl;

	atomic_inc(&ctrl->usage_cnt);
	return ctrl;
}
EXPORT_SYMBOL_GPL(of_power_control_get_by_index);

struct power_control *__of_power_control_get(struct device_node *node,
					     const char *id)
{
	int index = 0;

	if (id)
		index = of_property_match_string(node, "powerctrl-names", id);

	return __of_power_control_get_by_index(node, index);
}
EXPORT_SYMBOL_GPL(__of_power_control_get);

struct power_control *of_power_control_get(struct device_node *node,
					   const char *id)
{
	int index = 0;

	if (id)
		index = of_property_match_string(node, "powerctrl-names", id);

	return of_power_control_get_by_index(node, index);
}
EXPORT_SYMBOL_GPL(of_power_control_get);

void power_control_put(struct power_control *pctrl)
{
	atomic_dec(&pctrl->usage_cnt);
}
EXPORT_SYMBOL_GPL(power_control_put);

int power_control_register(struct power_control *pctrl)
{
	__list_lock();
	list_add(&pctrl->list, &power_control_list);
	__list_unlock();

	atomic_set(&pctrl->usage_cnt, 0);
	return 0;
}
EXPORT_SYMBOL_GPL(power_control_register);

void power_control_unregister(struct power_control *pctrl)
{
	WARN_ON(atomic_read(&pctrl->usage_cnt) != 0);

	__list_lock();
	list_del(&pctrl->list);
	__list_unlock();
}
EXPORT_SYMBOL_GPL(power_control_unregister);

static bool power_control_ignore_unused;
static int __init power_control_ignore_unused_setup(char *__unused)
{
	power_control_ignore_unused = true;
	return 0;
}
__setup("power_control_ignore_unused", power_control_ignore_unused_setup);

static int power_control_power_off_unused(void)
{
	struct power_control *ctrl = NULL;
	struct list_head *it = NULL;

	if (power_control_ignore_unused) {
		pr_warn("Not powering off unused controls\n");
		return 0;
	}

	list_for_each(it, &power_control_list) {
		ctrl = to_power_control(it);
		if (atomic_read(&ctrl->usage_cnt) == 0) {
			if (ctrl->ops->power_off_unused)
				ctrl->ops->power_off_unused(ctrl);
			else if (ctrl->ops->power_off)
				ctrl->ops->power_off(ctrl);
		}
	}
	return 0;
}
late_initcall_sync(power_control_power_off_unused);

int power_control_self_get(struct power_control *pctrl)
{
	atomic_inc(&pctrl->usage_cnt);
	return 0;
}

MODULE_LICENSE("GPL");

