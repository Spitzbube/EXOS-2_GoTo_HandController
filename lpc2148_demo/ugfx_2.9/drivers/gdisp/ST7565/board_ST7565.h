/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.io/license.html
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

//#define GDISP_INITIAL_CONTRAST  224
#define ST7565_LCD_BIAS         ST7565_LCD_BIAS_7
#define ST7565_ADC              ST7565_ADC_NORMAL
#define ST7565_COM_SCAN         ST7565_COM_SCAN_DEC
#define ST7565_PAGE_ORDER       0,1,2,3,4,5,6,7
/*
 * Custom page order for several LCD boards, e.g. HEM12864-99
 * #define ST7565_PAGE_ORDER       4,5,6,7,0,1,2,3
 */

#define LCD_DATA      GPIO_IO_P15
#define LCD_CLK       GPIO_IO_P12
#define LCD_E         GPIO_IO_P10
#define LCD_RS        GPIO_IO_P23

static GFXINLINE void init_board(GDisplay *g) {
	(void) g;
//	uart1_write_byte('1');
//	printf("init_board()\n");

	GPIO0_FIODIR |= (LCD_E | LCD_CLK | LCD_DATA);
	GPIO1_FIODIR |= (LCD_RS);
}

static GFXINLINE void write_cmd(GDisplay *g, gU8 cmd);

static GFXINLINE void post_init_board(GDisplay *g) {
	(void) g;
//	uart1_write_byte('2');
//	printf("post_init_board()\n");
	write_cmd(g, 0x60); //ST7565_START_LINE | (GDISP_SCREEN_HEIGHT/2));
}

static GFXINLINE void setpin_reset(GDisplay *g, gBool state) {
	(void) g;
	(void) state;
//	uart1_write_byte('3');
//	printf("setpin_reset(state=%d)\n", state);
}

static GFXINLINE void acquire_bus(GDisplay *g) {
	(void) g;
//	uart1_write_byte('4');
//	printf("acquire_bus()\n");

	GPIO0_FIOCLR |= LCD_E;
}

static GFXINLINE void release_bus(GDisplay *g) {
	(void) g;
//	uart1_write_byte('5');
//	printf("release_bus()\n");

	GPIO0_FIOSET |= LCD_E;
}

static GFXINLINE void write_cmd(GDisplay *g, gU8 cmd) {
	(void) g;
	(void) cmd;
	  unsigned char i;

//	uart1_write_byte('6');
	printf("write_cmd(cmd=0x%x)\n", cmd);

	  GPIO1_FIOCLR |= LCD_RS;

	  for (i = 0; i < 8; i++)
	  {
		  GPIO0_FIOCLR |= LCD_CLK;

	    if (cmd & 0x80)
	    	  GPIO0_FIOSET |= LCD_DATA;
	    else
	    	  GPIO0_FIOCLR |= LCD_DATA;

	    cmd <<= 1;
	    GPIO0_FIOSET |= LCD_CLK;
	  }

}

static GFXINLINE void write_data(GDisplay *g, gU8* data, gU16 length) {
	(void) g;
	(void) data;
	(void) length;
	gU16 j;
	  unsigned char i;

//	uart1_write_byte('7');
	printf("write_data(length=%d)\n", length);

	  GPIO1_FIOSET |= LCD_RS;

	  for (j = 0; j < length; j++)
	  {
		  gU8 c = data[j];

		  for (i = 0; i < 8; i++)
		  {
			  GPIO0_FIOCLR |= LCD_CLK;

			if (c & 0x80)
				  GPIO0_FIOSET |= LCD_DATA;
			else
				  GPIO0_FIOCLR |= LCD_DATA;

			c <<= 1;
			GPIO0_FIOSET |= LCD_CLK;
		  }
	  }
}

#endif /* _GDISP_LLD_BOARD_H */
