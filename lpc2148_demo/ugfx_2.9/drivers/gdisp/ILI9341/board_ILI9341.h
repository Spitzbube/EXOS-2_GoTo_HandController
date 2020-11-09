/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

static GFXINLINE void init_board(GDisplay *g) {
	(void) g;

	GPIO0_FIODIR |= GPIO_IO_P7; //Chip Select
	GPIO0_FIODIR |= GPIO_IO_P21; //Command/Data
	GPIO0_FIODIR |= GPIO_IO_P22; //Reset
}

static GFXINLINE void post_init_board(GDisplay *g) {
	(void) g;
}

static GFXINLINE void setpin_reset(GDisplay *g, gBool state) {
	(void) g;
	(void) state;

	if (state)
		GPIO0_FIOCLR = GPIO_IO_P22;
	else
		GPIO0_FIOSET = GPIO_IO_P22;
}

static GFXINLINE void set_backlight(GDisplay *g, gU8 percent) {
	(void) g;
	(void) percent;
}

static GFXINLINE void acquire_bus(GDisplay *g) {
	(void) g;

	GPIO0_FIOCLR = GPIO_IO_P7;
}

static GFXINLINE void release_bus(GDisplay *g) {
	(void) g;

	GPIO0_FIOSET = GPIO_IO_P7;
}

static GFXINLINE void write_index(GDisplay *g, gU16 index) {
	(void) g;
	(void) index;

	GPIO0_FIOCLR = GPIO_IO_P21;

	spiPut( index & 0xFF );
}

static GFXINLINE void write_data(GDisplay *g, gU16 data) {
	(void) g;
	(void) data;

	GPIO0_FIOSET = GPIO_IO_P21;

	spiPut( data & 0xFF );
}

static GFXINLINE void setreadmode(GDisplay *g) {
	(void) g;
}

static GFXINLINE void setwritemode(GDisplay *g) {
	(void) g;
}

static GFXINLINE gU16 read_data(GDisplay *g) {
	(void) g;
	return 0;
}

#endif /* _GDISP_LLD_BOARD_H */
