/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2013 Siemens Schweiz AG
 * (C) Heiko Schocher, DENX Software Engineering, hs@denx.de.
 *
 * Based on:
 * U-Boot file:/include/configs/am335x_evm.h
 *
 * Copyright (C) 2011 Texas Instruments Incorporated - http://www.ti.com/
 */

#ifndef __CONFIG_DRACO_H
#define __CONFIG_DRACO_H

#include "siemens-am33x-common.h"

#define DDR_PLL_FREQ	303

#define BOARD_DFU_BUTTON_GPIO	27	/* Use as default */
#define GPIO_LAN9303_NRST	88	/* GPIO2_24 = gpio88 */

#define CONFIG_ENV_SETTINGS_BUTTONS_AND_LEDS \
	"button_dfu0=27\0" \
	"led0=103,1,0\0" \
	"led1=64,0,1\0"

 /* Physical Memory Map */
#define CONFIG_MAX_RAM_BANK_SIZE	(1024 << 20)	/* 1GB */

#define CONFIG_FACTORYSET

/* Define own nand partitions */
#define CONFIG_ENV_RANGE        (4 * CONFIG_SYS_ENV_SECT_SIZE)

#ifndef CONFIG_SPL_BUILD

/* Default env settings */
#define CONFIG_EXTRA_ENV_SETTINGS \
	"hostname=draco\0" \
	"ubi_off=2048\0"\
	"nand_img_size=0x400000\0" \
	"optargs=\0" \
	"preboot=draco_led 0\0" \
	CONFIG_ENV_SETTINGS_BUTTONS_AND_LEDS \
	CONFIG_ENV_SETTINGS_V2 \
	CONFIG_ENV_SETTINGS_NAND_V2

#ifndef CONFIG_RESTORE_FLASH
/* set to negative value for no autoboot */
#endif
#endif	/* CONFIG_SPL_BUILD */
#endif	/* ! __CONFIG_DRACO_H */
