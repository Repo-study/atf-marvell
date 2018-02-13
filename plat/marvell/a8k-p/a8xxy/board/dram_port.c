/*
 * Copyright (C) 2017 Marvell International Ltd.
 *
 * SPDX-License-Identifier:	BSD-3-Clause
 * https://spdx.org/licenses
 */

#include <plat_marvell.h>
#include <mv_ddr_if.h>
#include <plat_def.h>

/* DB-88F8160-MODULAR has 4 DIMMs on board that are connected to
 * AP2 I2C bus-0 at the following addresses:
 * AP0 DIMM0 - 0x53
 * AP0 DIMM1 - 0x54
 * AP1 DIMM0 - 0x55
 * AP1 DIMM1 - 0x56
 */
#define I2C_SPD_BASE_ADDR		0x53
#define I2C_SPD_DATA_ADDR(ap_id, iface)	(I2C_SPD_BASE_ADDR + (ap_id * DDR_MAX_UNIT_PER_AP) + (iface))
#define I2C_SPD_P0_SEL_ADDR		0x36	/* Select SPD data page 0 */

#define MC_RAR_INTERLEAVE_SZ		(128) /* Also possible to set to 4Kb */

uint32_t dram_rar_interleave(void)
{
	return MC_RAR_INTERLEAVE_SZ;
}

/*
 * This struct provides the DRAM training code with
 * the appropriate board DRAM configuration
 */
struct mv_ddr_iface dram_iface_ap0[DDR_MAX_UNIT_PER_AP] = {
	{
		.state = MV_DDR_IFACE_NRDY,
		.id = 0,
		.spd_data_addr = I2C_SPD_DATA_ADDR(0, 0),
		.spd_page_sel_addr = I2C_SPD_P0_SEL_ADDR,
		.tm = {
			/* MISL board with 1CS 8Gb x4 devices of Micron 2400T */
			DEBUG_LEVEL_ERROR,
			0x1, /* active interfaces */
			/* cs_mask, mirror, dqs_swap, ck_swap X subphys */
			{ { { {0x1, 0x0, 0, 0},	/* FIXME: change the cs mask for all 64 bit */
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0} },
			/* TODO: double check if the speed bin is 2400T */
			SPEED_BIN_DDR_2400T,		/* speed_bin */
			MV_DDR_DEV_WIDTH_8BIT,	/* sdram device width */
			MV_DDR_DIE_CAP_8GBIT,	/* die capacity */
			MV_DDR_FREQ_SAR,		/* frequency */
			0, 0,			/* cas_l, cas_wl */
			MV_DDR_TEMP_LOW} },		/* temperature */
			MV_DDR_64BIT_ECC_PUP8_BUS_MASK, /* subphys mask */
			MV_DDR_CFG_SPD,			/* ddr configuration data source */
			{ {0} },			/* raw spd data */
			{0}				/* timing parameters */
		},
	},
	{
		.state = MV_DDR_IFACE_NRDY,
		.id = 1,
		.spd_data_addr = I2C_SPD_DATA_ADDR(0, 1),
		.spd_page_sel_addr = I2C_SPD_P0_SEL_ADDR,
		.tm = {
			/* MISL board with 1CS 8Gb x4 devices of Micron 2400T */
			DEBUG_LEVEL_ERROR,
			0x1, /* active interfaces */
			/* cs_mask, mirror, dqs_swap, ck_swap X subphys */
			{ { { {0x1, 0x0, 0, 0},	/* FIXME: change the cs mask for all 64 bit */
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0} },
			/* TODO: double check if the speed bin is 2400T */
			SPEED_BIN_DDR_2400T,		/* speed_bin */
			MV_DDR_DEV_WIDTH_8BIT,	/* sdram device width */
			MV_DDR_DIE_CAP_8GBIT,	/* die capacity */
			MV_DDR_FREQ_SAR,		/* frequency */
			0, 0,			/* cas_l, cas_wl */
			MV_DDR_TEMP_LOW} },		/* temperature */
			MV_DDR_64BIT_ECC_PUP8_BUS_MASK, /* subphys mask */
			MV_DDR_CFG_SPD,			/* ddr configuration data source */
			{ {0} },			/* raw spd data */
			{0}				/* timing parameters */
		},
	},
};
struct mv_ddr_iface dram_iface_ap1[DDR_MAX_UNIT_PER_AP] = {
	{
		.state = MV_DDR_IFACE_NRDY,
		.id = 0,
		.spd_data_addr = I2C_SPD_DATA_ADDR(1, 0),
		.spd_page_sel_addr = I2C_SPD_P0_SEL_ADDR,
		.tm = {
			/* MISL board with 1CS 8Gb x4 devices of Micron 2400T */
			DEBUG_LEVEL_ERROR,
			0x1, /* active interfaces */
			/* cs_mask, mirror, dqs_swap, ck_swap X subphys */
			{ { { {0x1, 0x0, 0, 0},	/* FIXME: change the cs mask for all 64 bit */
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0} },
			/* TODO: double check if the speed bin is 2400T */
			SPEED_BIN_DDR_2400T,		/* speed_bin */
			MV_DDR_DEV_WIDTH_8BIT,	/* sdram device width */
			MV_DDR_DIE_CAP_8GBIT,	/* die capacity */
			MV_DDR_FREQ_SAR,		/* frequency */
			0, 0,			/* cas_l, cas_wl */
			MV_DDR_TEMP_LOW} },		/* temperature */
			MV_DDR_64BIT_ECC_PUP8_BUS_MASK, /* subphys mask */
			MV_DDR_CFG_SPD,			/* ddr configuration data source */
			{ {0} },			/* raw spd data */
			{0}				/* timing parameters */
		},
	},
	{
		.state = MV_DDR_IFACE_NRDY,
		.id = 1,
		.spd_data_addr = I2C_SPD_DATA_ADDR(1, 1),
		.spd_page_sel_addr = I2C_SPD_P0_SEL_ADDR,
		.tm = {
			/* MISL board with 1CS 8Gb x4 devices of Micron 2400T */
			DEBUG_LEVEL_ERROR,
			0x1, /* active interfaces */
			/* cs_mask, mirror, dqs_swap, ck_swap X subphys */
			{ { { {0x1, 0x0, 0, 0},	/* FIXME: change the cs mask for all 64 bit */
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0},
				    {0x1, 0x0, 0, 0} },
			/* TODO: double check if the speed bin is 2400T */
			SPEED_BIN_DDR_2400T,		/* speed_bin */
			MV_DDR_DEV_WIDTH_8BIT,	/* sdram device width */
			MV_DDR_DIE_CAP_8GBIT,	/* die capacity */
			MV_DDR_FREQ_SAR,		/* frequency */
			0, 0,			/* cas_l, cas_wl */
			MV_DDR_TEMP_LOW} },		/* temperature */
			MV_DDR_64BIT_ECC_PUP8_BUS_MASK, /* subphys mask */
			MV_DDR_CFG_SPD,			/* ddr configuration data source */
			{ {0} },			/* raw spd data */
			{0}				/* timing parameters */
		},
	},
};

/* Pointer to the first DRAM interface in the system */
struct mv_ddr_iface *ptr_iface = &dram_iface_ap0[0];
