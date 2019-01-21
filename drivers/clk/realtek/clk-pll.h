/*
 * clk-pll.h - pll clock with regmap
 *
 * Copyright (C) 2017-2018 Realtek Semiconductor Corporation
 * Copyright (C) 2017-2018 Cheng-Yu Lee <cylee12@realtek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __CLK_REALTEK_CLK_PLL_H
#define __CLK_REALTEK_CLK_PLL_H

#include "common.h"

/**
 * struct freq_table - clock frequency table
 *
 * @val:  register valute
 * @mask: mask to apply value to register
 * @rate: frequency
 */
struct freq_table {
	unsigned int val;
	unsigned int mask;
	unsigned long rate;
};

#define FREQ_TABLE_END                  { .rate = 0 }
#define IS_FREQ_TABLE_END(_f)           ((_f)->rate == 0)

/**
 * struct div_table - clock divisor table
 *
 * @rate: rate for divisor selection. When target rate is greater-equal than
 *     the rate, using the divisor.
 * @div:  divisor
 * @val:  register value
 */
struct div_table {
	unsigned long rate;
	unsigned int div;
	unsigned int val;
};

#define DIV_TABLE_END                   { .rate = 0 }
#define IS_DIV_TABLE_END(_d)            ((_d)->rate == 0)

/**
 * struct clk_pll - pll clock with regmap. Using a frequency table to lookup
 * for frequency.
 *
 * @base:       handle for common, hw and register access interface
 * @pll_offset: offset of register to set pll rate
 * @freq_table: frequency table
 * @ssc_offset: offset of ssc register
 * @lock:       register lock
 * @flags:      clk_pll flags
 * @status:     clk_pll status
 * @conf        clk_pll hw configure
 *
 * Flags:
 * CLK_PLL_LSM_STEP_HIGH  - faster pll rate adjustment
 * CLK_PLL_DIV_WORKAROUND - (kylin) workaround for clk_pll_div
 *
 * Status:
 * CLK_PLL_ENABLED - indicate the pll is enabled
 */
struct clk_pll {
	struct clk_reg base;

	const struct freq_table *freq_tbl;
	int pll_offset;
	int ssc_offset;
	spinlock_t *lock;

	unsigned int flags;
	unsigned int status;
	unsigned int conf;

	const struct clk_ops *ops;
};

#define to_clk_pll(_hw) container_of(to_clk_reg(_hw), struct clk_pll, base)
#define __clk_pll_hw(_ptr)  __clk_reg_hw(&(_ptr)->base)

/* clk_pll flags */
#define CLK_PLL_LSM_STEP_HIGH           BIT(1)
#define CLK_PLL_DIV_WORKAROUND          BIT(2)

/* clk_pll status */
#define CLK_PLL_ENABLED                 BIT(0)

/* clk_pll conf & functions */
#define CLK_PLL_CONF_POW_MASK           (0xf)
#define CLK_PLL_CONF_POW_LOC_CTL2       BIT(0)
#define CLK_PLL_CONF_POW_LOC_CTL3       BIT(1)
#define CLK_PLL_CONF_FREQ_MASK          (0xf0)
#define CLK_PLL_CONF_FREQ_LOC_CTL1      BIT(4)
#define CLK_PLL_CONF_FREQ_LOC_CTL2      BIT(5)
#define CLK_PLL_CONF_FREQ_LOC_SSC1      BIT(6)

/* clk_pll helper macros & functions */
#define SSC_VALID(_pll)                 CLK_OFFSET_IS_VALID((_pll)->ssc_offset)

static inline unsigned long clk_pll_lock(struct clk_pll *pll)
{
	unsigned long flags = 0;

	if (pll->lock)
		spin_lock_irqsave(pll->lock, flags);
	return flags;
}

static inline void clk_pll_unlock(struct clk_pll *pll, unsigned long flags)
{
	if (pll->lock)
		spin_unlock_irqrestore(pll->lock, flags);
}

/**
 * struct clk_pll_div - pll clock externion with divisor
 *
 * @clkp:       pll clock
 * @div_offset: offset of divsor register
 * @div_shift:  shift of divsor bit field
 * @div_width:  width of divsor bit field
 * @div_tbl:    divsor table
 * @lock        divsor register lock
 */
struct clk_pll_div {
	struct clk_pll clkp;
	int div_offset;
	int div_shift;
	int div_width;
	const struct div_table *div_tbl;
	spinlock_t *lock;
};

#define to_clk_pll_div(_hw) \
	container_of(to_clk_pll(_hw), struct clk_pll_div, clkp)
#define __clk_pll_div_hw(_ptr) __clk_pll_hw(&(_ptr)->clkp)

/* clk_pll_div helper functions */
static inline unsigned long clk_pll_div_lock(struct clk_pll_div *plld)
{
	unsigned long flags = 0;

	if (plld->lock)
		spin_lock_irqsave(plld->lock, flags);
	return flags;
}

static inline void clk_pll_div_unlock(struct clk_pll_div *plld,
	unsigned long flags)
{
	if (plld->lock)
		spin_unlock_irqrestore(plld->lock, flags);
}

extern const struct clk_ops clk_pll_ops;
extern const struct clk_ops clk_pll_div_ops;
#ifdef CONFIG_COMMON_CLK_RTD16XX
extern const struct clk_ops clk_pll_dif_ops;
#endif

bool clk_hw_is_pll(struct clk_hw *hw);
int clk_pll_init(struct clk_hw *hw);

#endif /* __CLK_REALTEK_CLK_PLL_H */
