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

struct regmap_mmio_context {
	void __iomem *regs;
	const u32 *reg_swc;
};

static int regmap_mmio_write(void *context, unsigned int reg, unsigned int val)
{
	struct regmap_mmio_context *ctx = context;

	pr_debug("%s: reg=%03x val=%08x\n", __func__, reg, val);
	writel(val, ctx->regs + reg);
	return 0;
}

static int regmap_mmio_read(void *context, unsigned int reg, unsigned int *val)
{
	struct regmap_mmio_context *ctx = context;

	*val = readl(ctx->regs + reg);
	pr_debug("%s: reg=%03x val=%08x\n", __func__, reg, *val);
	return 0;
}

static const struct regmap_bus regmap_mmio = {
	.fast_io = true,
	.reg_write  = regmap_mmio_write,
	.reg_read   = regmap_mmio_read,
};

static struct regmap_mmio_context *regmap_mmio_gen_context(struct device *dev,
					void __iomem *regs,
					const struct regmap_config *config)
{
	struct regmap_mmio_context *ctx;

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
	struct regmap_mmio_context *ctx;

	ctx = regmap_mmio_gen_context(dev, regs, config);
	if (IS_ERR(ctx))
		return ERR_CAST(ctx);

	return __regmap_init(dev, &regmap_mmio, ctx, config,
			     lock_key, lock_name);
}
EXPORT_SYMBOL_GPL(__rtk_regmap_init_mmio);

struct regmap *__devm_regmap_init_mmio(struct device *dev,
				       void __iomem *regs,
				       const struct regmap_config *config,
				       struct lock_class_key *lock_key,
				       const char *lock_name)
{
	struct regmap_mmio_context *ctx;

	ctx = regmap_mmio_gen_context(dev, regs, config);
	if (IS_ERR(ctx))
		return ERR_CAST(ctx);

	return __devm_regmap_init(dev, &regmap_mmio, ctx, config,
				  lock_key, lock_name);
}
EXPORT_SYMBOL_GPL(__devm_regmap_init_mmio);

MODULE_LICENSE("GPL v2");
