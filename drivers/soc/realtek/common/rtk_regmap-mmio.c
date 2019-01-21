/*
 * This file is based on 'drivers/base/regmap/regmap-mmio.c'
 *
 * Copyright (c) 2012, NVIDIA CORPORATION.  All rights reserved.
 * Copyright (c) 2018, Realtek Semiconductor Corporation
 * Copyright (C) 2018, Cheng-Yu Lee <cylee12@realtek.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/err.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/regmap.h>
#include <linux/slab.h>
#include <soc/realtek/rtk_regmap.h>
#include <soc/realtek/rtk_smccall.h>

static u32 swc_write(u32 addr, u32 tar, u32 val)
{
#ifdef CONFIG_RTK_REGMAP_SECURE_MMIO
	return rtk_smc(tar, val, 0);
#else
	BUG();
	return 0;
#endif
}

static u32 swc_read(u32 addr, u32 tar)
{
#ifdef CONFIG_RTK_REGMAP_SECURE_MMIO
	return rtk_smc(tar, 0, 0);
#else
	BUG();
	return 0;
#endif
}

struct rtk_regmap_mmio_context {
	void __iomem *regs;
	struct rtk_secure_regfield *srfs;
	u32 num_srfs;
	u32 addr;
};

enum {
	SWC_READ,
	SWC_WRITE,
};

#ifdef CONFIG_RTK_REGMAP_SECURE_MMIO

static struct rtk_secure_regfield *find_secure_register(struct rtk_regmap_mmio_context *ctx,
							u32 reg,
							u32 type)
{
	u32 i;

	if (!ctx->srfs)
		return NULL;

	for (i = 0; i < ctx->num_srfs; i++) {
		struct rtk_secure_regfield *srf = &ctx->srfs[i];

		if (srf->offset == reg) {
			switch (type) {
			case SWC_READ:
				return srf->rcmd ? srf : NULL;
			case SWC_WRITE:
				return srf->wcmd ? srf : NULL;
			default:
				return NULL;
			}
		}
	}
	return NULL;
}

#else
static inline struct rtk_secure_regfield *find_secure_register(struct rtk_regmap_mmio_context *ctx,
							       u32 reg,
							       u32 type)
{
	return NULL;
}
#endif

static int rtk_regmap_mmio_write(void *context, unsigned int reg, unsigned int val)
{
	struct rtk_regmap_mmio_context *ctx = context;
	struct rtk_secure_regfield *srf = NULL;

	pr_debug("%s: reg=%03x, val=%08x\n", __func__, reg, val);
	srf = find_secure_register(ctx, reg, SWC_WRITE);
	if (srf) {
		swc_write(ctx->addr + srf->offset, srf->wcmd, val);
	} else
		writel(val, ctx->regs + reg);
	return 0;
}

static int rtk_regmap_mmio_read(void *context, unsigned int reg, unsigned int *val)
{
	struct rtk_regmap_mmio_context *ctx = context;
	struct rtk_secure_regfield *srf = NULL;

	srf = find_secure_register(ctx, reg, SWC_READ);
	if (srf) {
		*val = swc_read(ctx->addr + srf->offset, srf->rcmd);
	} else
		*val = readl(ctx->regs + reg);
	pr_debug("%s: reg=%03x, val=%08x\n", __func__, reg, *val);
	return 0;
}

static void rtk_regmap_mmio_free_context(void *context)
{
	struct rtk_regmap_mmio_context *ctx = context;

	kfree(ctx->srfs);
	kfree(ctx);
}

static const struct regmap_bus rtk_regmap_mmio = {
	.fast_io      = true,
	.reg_write    = rtk_regmap_mmio_write,
	.reg_read     = rtk_regmap_mmio_read,
	.free_context = rtk_regmap_mmio_free_context,
};

static struct rtk_regmap_mmio_context *regmap_mmio_gen_context(struct device *dev,
							       void __iomem *regs,
							       const struct regmap_config *config)
{
	struct rtk_regmap_mmio_context *ctx;

	BUG_ON(config->reg_bits != 32);
	BUG_ON(config->pad_bits);
	BUG_ON(config->reg_stride != 4);

	ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
	if (!ctx)
		return ERR_PTR(-ENOMEM);

	ctx->regs = regs;

	return ctx;
}

struct regmap *__rtk_regmap_init_mmio(struct device *dev,
				      void __iomem *regs,
				      const struct regmap_config *config,
				      struct lock_class_key *lock_key,
				      const char *lock_name)
{
	struct rtk_regmap_mmio_context *ctx;

	ctx = regmap_mmio_gen_context(dev, regs, config);
	if (IS_ERR(ctx))
		return ERR_CAST(ctx);

	return __regmap_init(dev, &rtk_regmap_mmio, ctx, config, lock_key,
		lock_name);
}
EXPORT_SYMBOL_GPL(__rtk_regmap_init_mmio);

struct regmap *__devm_rtk_regmap_init_mmio(struct device *dev,
					   void __iomem *regs,
					   const struct regmap_config *config,
					   struct lock_class_key *lock_key,
					   const char *lock_name)
{
	struct rtk_regmap_mmio_context *ctx;

	ctx = regmap_mmio_gen_context(dev, regs, config);
	if (IS_ERR(ctx))
		return ERR_CAST(ctx);

	return __devm_regmap_init(dev, &rtk_regmap_mmio, ctx, config,
		lock_key, lock_name);
}
EXPORT_SYMBOL_GPL(__devm_rtk_regmap_init_mmio);

static struct rtk_regmap_mmio_context *regmap_secure_mmio_gen_context(struct device *dev,
								      void __iomem *regs,
								      const struct rtk_regmap_config *config)
{
	struct rtk_regmap_mmio_context *ctx;

	ctx = regmap_mmio_gen_context(dev, regs, &config->config);
	if (IS_ERR(ctx))
		return ctx;

	ctx->addr = config->addr;
	ctx->num_srfs = config->num_srfs;
	ctx->srfs = kmemdup(config->srfs, sizeof(*config->srfs) * config->num_srfs, GFP_KERNEL);
	if (!ctx->srfs) {
		rtk_regmap_mmio_free_context(ctx);
		return ERR_PTR(-ENOMEM);
	}

	return ctx;
}

struct regmap *__rtk_regmap_init_secure_mmio(struct device *dev,
					     void __iomem *regs,
					     const struct rtk_regmap_config *config,
					     struct lock_class_key *lock_key,
					     const char *lock_name)
{
	struct rtk_regmap_mmio_context *ctx;

	ctx = regmap_secure_mmio_gen_context(dev, regs, config);
	if (IS_ERR(ctx))
		return ERR_CAST(ctx);

	return __regmap_init(dev, &rtk_regmap_mmio, ctx, &config->config,
		lock_key, lock_name);
}
EXPORT_SYMBOL_GPL(__rtk_regmap_init_secure_mmio);

struct regmap *__devm_rtk_regmap_init_secure_mmio(struct device *dev,
						  void __iomem *regs,
						  const struct rtk_regmap_config *config,
						  struct lock_class_key *lock_key,
						  const char *lock_name)
{
	struct rtk_regmap_mmio_context *ctx;

	ctx = regmap_secure_mmio_gen_context(dev, regs, config);
	if (IS_ERR(ctx))
		return ERR_CAST(ctx);

	return __devm_regmap_init(dev, &rtk_regmap_mmio, ctx, &config->config,
		lock_key, lock_name);
}
EXPORT_SYMBOL_GPL(__devm_rtk_regmap_init_secure_mmio);

MODULE_LICENSE("GPL v2");
