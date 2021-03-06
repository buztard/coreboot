/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2020 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <commonlib/helpers.h>

/* Pad configuration in ramstage*/
static const struct pad_config gpio_table[] = {
	/* PCH M.2 SSD */
	PAD_CFG_GPO(GPP_B16, 1, PLTRST),
	PAD_CFG_GPO(GPP_H0, 1, PLTRST),

	/* Camera */
	PAD_CFG_GPO(GPP_B23, 0, PLTRST),
	PAD_CFG_GPO(GPP_C15, 0, PLTRST),
	PAD_CFG_GPO(GPP_R6, 0, PLTRST),
	PAD_CFG_GPO(GPP_H12, 0, PLTRST),

	/* Image clock: IMGCLKOUT_0, IMGCLKOUT_1 */
	PAD_CFG_NF(GPP_D4, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_H20, NONE, PLTRST, NF1),

	/* ISH UART0 RX/TX */
	PAD_CFG_NF(GPP_D13, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D14, NONE, PLTRST, NF1),

	/* ISH I2C0 */
	PAD_CFG_NF(GPP_B5, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_B6, NONE, PLTRST, NF1),

	/* ISH GPI 0-6 */
	PAD_CFG_NF(GPP_D0, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D1, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D2, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D3, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D17, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_D18, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_E15, NONE, PLTRST, NF1),
	PAD_CFG_NF(GPP_E16, NONE, PLTRST, NF1),
};

/* Early pad configuration in bootblock */
static const struct pad_config early_gpio_table[] = {
/* ToDo: Fill early gpio configurations for TPM and WWAN */
};

const struct pad_config *variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}

static const struct cros_gpio cros_gpios[] = {
	CROS_GPIO_REC_AL(CROS_GPIO_VIRTUAL, CROS_GPIO_COMM0_NAME),
};

const struct cros_gpio *variant_cros_gpios(size_t *num)
{
	*num = ARRAY_SIZE(cros_gpios);
	return cros_gpios;
}
