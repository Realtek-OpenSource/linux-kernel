/*
 * rtk_sb2_dbg.c - bus debug driver
 *
 * Copyright (c) 2017-2019 Realtek Semiconductor Corp.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/printk.h>
#include <linux/of.h>
#include <linux/of_address.h>
#include <linux/of_irq.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <asm/system_misc.h>

#include "include/rtk_sb2.h"

#define DRIVER_NAME "RTK_SB2_DBG"
#define sb2_info(fmt, ...)  pr_info("[%s] " fmt, DRIVER_NAME, ##__VA_ARGS__)
#define sb2_err(fmt, ...)   pr_err("[%s] " fmt, DRIVER_NAME, ##__VA_ARGS__)
#define sb2_err_hl(fmt, ...)   pr_err("\033[0;31m[%s] " fmt "\033[m\n", DRIVER_NAME, ##__VA_ARGS__)
#define sb2_dbg(fmt, ...)   pr_debug("[%s] " fmt, DRIVER_NAME, ##__VA_ARGS__)

static struct sb2_data *sb2_data;
static int sb2_irq;

static irqreturn_t isr_sb2_dbg(int irq, void *id)
{
	struct platform_device *pdev = id;
	struct sb2_data *data = platform_get_drvdata(pdev);
	struct pt_regs *regs;
	u32 intr;

	intr = sb2_read(data, SB2_DBG_INT);
	regs = get_irq_regs();

	if (intr & (SB2_SCPU_NEG_INT | SB2_SCPU_INT | SB2_ACPU_NEG_INT | SB2_ACPU_INT)) {
		u32 cause, addr, s_a_cpu;
		char buf[128];

		sb2_err("sb2 get int 0x%08x from SB2_DBG_INT\n", intr);
		sb2_write(data, SB2_DBG_INT, SB2_SCPU_INT_EN | SB2_ACPU_INT_EN | WRITE_DATA_1);

		s_a_cpu = (intr & SB2_SCPU_INT) ? 1 : 2; /* SCPU:1, ACPU:2 */
		addr = (s_a_cpu == 1) ? sb2_read(data, SB2_DBG_ADDR_SYSTEM) :
			sb2_read(data, SB2_DBG_ADDR_AUDIO);
		cause = sb2_read(data, SB2_DBG_ADDR1);
		cause = (s_a_cpu == 1) ? (cause >> 2) : (cause >> 4);

		sprintf(buf, "Memory 0x%08x trashed by %sCPU with %s %s\n", addr,
				(s_a_cpu == 1) ? "S" : "A",
				(cause & 1) ? "D" : "I",
				(cause & 2) ? "W" : "R");
		die(buf, regs, 0);

		return IRQ_HANDLED;
	}


	intr = sb2_read(data, SB2_INV_INTSTAT);
	if (intr & (SWCIVA_INT | ACIVA_INT | SCIVA_INT | PCIVA_INT)) {
		sb2_err("sb2 get int 0x%08x from SB2_INV_INTSTAT\n", intr);

		sb2_write(data, SB2_INV_INTSTAT, SWCIVA_INT | ACIVA_INT | SCIVA_INT | PCIVA_INT | WRITE_DATA_0);
		if (intr & SWCIVA_INT)
			sb2_err_hl("Invalid access issued by SCPU security world");
		else if (intr & ACIVA_INT)
			sb2_err_hl("Invalid access issued by ACPU");
		else if (intr & SCIVA_INT)
			sb2_err_hl("Invalid access issued by SCPU");
		else if (intr & PCIVA_INT)
			sb2_err_hl("Invalid access issued by PCPU");
		sb2_err_hl("Invalid address is 0x%x", sb2_read(data, SB2_INV_ADDR));
		sb2_err("Timeout threshold(0x%08x)\n", sb2_read(data, SB2_DEBUG_REG));

		return IRQ_HANDLED;

	}
	return IRQ_NONE;
}

void sb2_dbg_scpu_monitor(int which, u32 start, u32 end, u32 d_i, u32 r_w);
void sb2_dbg_acpu_monitor(int which, u32 start, u32 end, u32 d_i, u32 r_w);

static void sb2_set_l4_icg(struct sb2_data *data)
{
	if (IS_ENABLED(CONFIG_ARCH_RTD139x)) {
		sb2_write(data, SB2_RBUS_ICG1, 0xffffffff);
		sb2_write(data, SB2_RBUS_ICG2, 0x000fe7ff);
		sb2_write(data, SB2_RBUS_ICG3, 0x03ff003f);
	} else if (IS_ENABLED(CONFIG_ARCH_RTD16xx)) {
		sb2_write(data, SB2_RBUS_ICG1, 0xffffffff);
		sb2_write(data, SB2_RBUS_ICG2, 0xffffffff);
		sb2_write(data, SB2_RBUS_ICG3, 0xf73f007f);
	}
}

static void sb2_enable_interrupt(struct sb2_data *data)
{
	/* Enable SB2 interrupt */
	sb2_write(data, SB2_DBG_INT, SB2_ACPU_INT_EN | SB2_SCPU_INT_EN | SB2_PCPU_INT_EN | WRITE_DATA_1);
	sb2_write(data, SB2_INV_INTSTAT, SWCIVA_INT | ACIVA_INT | SCIVA_INT | PCIVA_INT | WRITE_DATA_0);
	sb2_write(data, SB2_INV_INTEN, SWCIVAIRQ_EN | ACIVAIRQ_EN | SCIVAIRQ_EN | PCIVAIRQ_EN | WRITE_DATA_1 | sb2_read(data, SB2_INV_INTEN));
}

static void sb2_disable_interrupt(struct sb2_data *data)
{
	sb2_write(data, SB2_DBG_INT, 0);
}

static int sb2_dbg_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sb2_data *data;
	struct device_node *np = dev->of_node;
	int ret;

	sb2_info("%s\n", __func__);

	data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	sb2_irq = irq_of_parse_and_map(np, 0);
	if (!sb2_irq) {
		sb2_err("failed to parse irq\n");
		return -ENXIO;
	}

	ret = devm_request_irq(dev, sb2_irq, isr_sb2_dbg, IRQF_SHARED, "sb2_dbg", pdev);
	if (ret) {
		sb2_err("request_irq() returns %d\n", ret);
		return -ENXIO;
	}

	ret = of_sb2_data_init(np, data, 0);
	if (ret) {
		sb2_err("of_sb2_data_init() returns %d\n", ret);
		return ret;
	}
	sb2_data = data;

	sb2_info("info 0x%x\n", sb2_read(data, SB2_CHIP_INFO));
	sb2_info("use smc %x\n", SB2_USE_SMCCALL);

	sb2_info("memory monitor 0x98013b00 - 0x98013c00\n");
	sb2_dbg_acpu_monitor(4, 0x98013b00, 0x98013c00,
		SB2_DBG_MONITOR_DATA | SB2_DBG_MONITOR_INST,
		SB2_DBG_MONITOR_READ | SB2_DBG_MONITOR_WRITE);

	platform_set_drvdata(pdev, data);
	sb2_set_l4_icg(data);
	sb2_enable_interrupt(data);
	return 0;
}

static int sb2_dbg_remove(struct platform_device *pdev)
{
	struct sb2_data *data = platform_get_drvdata(pdev);

	sb2_info("%s\n", __func__);
	sb2_disable_interrupt(data);
	sb2_data_fini(data);
	sb2_data = NULL;
	return 0;
}

static int sb2_dbg_suspend(struct device *dev)
{
	struct sb2_data *data = dev_get_drvdata(dev);

	sb2_info("Enter %s\n", __func__);
	sb2_disable_interrupt(data);
	sb2_info("Exit %s\n", __func__);
	return 0;
}

static int sb2_dbg_resume(struct device *dev)
{
	struct sb2_data *data = dev_get_drvdata(dev);

	sb2_info("Enter %s\n", __func__);
	sb2_enable_interrupt(data);
	sb2_info("Exit %s\n", __func__);
	return 0;
}

void sb2_dbg_disable_mem_monitor(int i)
{
	if (!sb2_data) {
		sb2_err("no sb2\n");
		return;
	}
	sb2_write(sb2_data, SB2_DBG_CTRL_REG0 + i * 4,
		CLR_DBG_ACPU_CHK_EN | CLR_DBG_SCPU_CHK_EN | CLR_DBG_EN);
}
EXPORT_SYMBOL(sb2_dbg_disable_mem_monitor);

static void sb2_dbg_set_mem_monitor(int i, u32 start, u32 end, u32 flags)
{
	if (!sb2_data) {
		sb2_err("no sb2\n");
		return;
	}

	/* disable this set first */
	sb2_dbg_disable_mem_monitor(i);

	sb2_info("%s: dbg%d addr %08x-%08x flag %08x\n", __func__,
		i, start, end, flags);
	sb2_write(sb2_data, SB2_DBG_START_REG0 + i * 4, start);
	sb2_write(sb2_data, SB2_DBG_END_REG0 + i * 4, end);
	sb2_write(sb2_data, SB2_DBG_CTRL_REG0 + i * 4,  flags);
}

/*
 * which: 0~7, which register set
 * d_i: SB2_DBG_MONITOR_DATA|SB2_DBG_MONITOR_INST
 * r_w: SB2_DBG_MONITOR_READ|SB2_DBG_MONITOR_WRITE
 */
void sb2_dbg_scpu_monitor(int which, u32 start, u32 end, u32 d_i, u32 r_w)
{
	sb2_dbg_set_mem_monitor(which, start, end,
		CLR_DBG_ACPU_CHK_EN | SET_DBG_SCPU_CHK_EN | SET_DBG_EN |
		d_i | r_w);
}
EXPORT_SYMBOL(sb2_dbg_scpu_monitor);

void sb2_dbg_acpu_monitor(int which, u32 start, u32 end, u32 d_i, u32 r_w)
{
	sb2_dbg_set_mem_monitor(which, start, end,
		SET_DBG_ACPU_CHK_EN | CLR_DBG_SCPU_CHK_EN | SET_DBG_EN |
		d_i | r_w);
}
EXPORT_SYMBOL(sb2_dbg_acpu_monitor);

static struct dev_pm_ops sb2_pm_ops = {
	.suspend_noirq = sb2_dbg_suspend,
	.resume_noirq  = sb2_dbg_resume,
};

static const struct of_device_id rtk_sb2_match[] = {
	{.compatible = "Realtek,rtk-sb2"},
	{.compatible = "realtek,sysbrg2"},
	{},
};

static struct platform_driver rtk_sb2_driver = {
	.probe  = sb2_dbg_probe,
	.remove = sb2_dbg_remove,
	.driver = {
		.owner          = THIS_MODULE,
		.name           = DRIVER_NAME,
		.pm             = &sb2_pm_ops,
		.of_match_table = of_match_ptr(rtk_sb2_match),
	},
};

static void __exit rtk_sb2_exit(void)
{
	platform_driver_unregister(&rtk_sb2_driver);
}
module_exit(rtk_sb2_exit);

static int __init rtk_sb2_init(void)
{
	return platform_driver_register(&rtk_sb2_driver);
}
arch_initcall(rtk_sb2_init);

MODULE_DESCRIPTION("Realtek SB2 driver");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:rtk-sb2");

