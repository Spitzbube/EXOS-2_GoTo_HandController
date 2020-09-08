
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <LPC214x.h>
#include "my_types.h"
#include "data.h"
#include "menu.h"
#include "file_79080.c"
#include "macros.h"

// configuration for the Atmel AT45DB161D device
#define FLASH_PAGE_BITS 10
#define FLASH_PAGE_SIZE 528

// Dataflash commands
#define FLASH_CMD_BUF1_TO_MEM 0x83
#define FLASH_CMD_BUF1_WRITE 0x84
#define FLASH_CMD_CONT_ARRAY_READ 0xE8

#define GPIO_FLASH_CS (1 << 24) //P1.24
#define ENABLE_FLASH_CS (IO1CLR = GPIO_FLASH_CS)
#define DISABLE_FLASH_CS (IO1SET = GPIO_FLASH_CS)

#define GPIO_FONTROM_CS (1 << 25) //P1.25
#define ENABLE_FONTROM_CS (IO1CLR = GPIO_FONTROM_CS)
#define DISABLE_FONTROM_CS (IO1SET = GPIO_FONTROM_CS)

// LCD Display commands
#define ST7565_CMD_DISPLAY_ON             0xAF
#define ST7565_CMD_SET_PAGE               0xB0
#define ST7565_CMD_SET_COLUMN_UPPER       0x10
#define ST7565_CMD_SET_COLUMN_LOWER       0x00
#define ST7565_CMD_SET_BIAS_9             0xA2
#define ST7565_CMD_INTERNAL_RESET         0xE2
#define ST7565_CMD_SET_VOLUME_FIRST       0x81
#define ST7565_CMD_SET_DISP_NORMAL        0xA6
#define ST7565_CMD_SET_ALLPTS_NORMAL      0xA4
#define ST7565_CMD_SET_COM_REVERSE        0xC8

	
/* 224 - complete */
void lcd_write_data(unsigned char a)
{
	unsigned char i;
	
	IOCLR0 |= 0x400;
	IOSET1 |= (1 << 23); // A0 = 1 -> Display Data

	for (i = 0; i < 8; i++)
	{	
		IOCLR0 |= (1 << 12);
		if (a & 0x80)
		{
			IOSET0 |= (1 << 15);
		}
		else
		{
			IOCLR0 |= (1 << 15);
		}
		
		a <<= 1;
		
		IOSET0 |= (1 << 12);
	}
	
	IOSET0 |= 0x400;
}
	
/* 2dc - complete */
void lcd_write_command(unsigned char a)
{
	unsigned char i;
	
	IOCLR0 |= 0x400;
	IOCLR1 |= (1 << 23); // A0 = 0 -> Control Data

	for (i = 0; i < 8; i++)
	{	
		IOCLR0 |= (1 << 12);
		if (a & 0x80)
		{
			IOSET0 |= (1 << 15);
		}
		else
		{
			IOCLR0 |= (1 << 15);
		}
		
		a <<= 1;
		
		IOSET0 |= (1 << 12);
	}
	
	IOSET0 |= 0x400;
}

/* 394 - complete */
void lcd_display_clear(void)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		lcd_write_command((i & 0xff) | ST7565_CMD_SET_PAGE);
		lcd_write_command(ST7565_CMD_SET_COLUMN_LOWER);
		lcd_write_command(ST7565_CMD_SET_COLUMN_UPPER);
		
		for (j = 133; j > 0; j--)
		{
			lcd_write_data(0);
		}
	}
}

/* 3ec - complete */
void lcd_display_configure(void)
{
	lcd_write_command(ST7565_CMD_INTERNAL_RESET);
	lcd_write_command(ST7565_CMD_SET_BIAS_9);
	lcd_write_command(0x26);
	lcd_write_command(0x2f);
	lcd_write_command(ST7565_CMD_SET_VOLUME_FIRST);
	lcd_write_command(0x80);
	lcd_write_command(ST7565_CMD_SET_DISP_NORMAL);
	lcd_write_command(ST7565_CMD_SET_ALLPTS_NORMAL);
	lcd_write_command(ST7565_CMD_SET_COM_REVERSE);
	lcd_write_command(ST7565_CMD_DISPLAY_ON);
	lcd_write_command(0x60);
	
	lcd_display_clear();

	//Backlight?
	PWMPR = 0;
	PWMMCR = 2;
	PWMPCR = 0x2000;
	PWMMR0 = 0x00002b33;
	PWMMR5 = 0;
	PWMMR2 = 0;
	PWMLER = 0x21;
	PWMTCR = 0x02;
	PWMTCR = 0x09;
}

/* 49c - complete */
void setDisplayPWM(int a)
{
	if (a == 0)
	{
		PWMMR5 = 0;		
	}
	else
	{
		PWMMR5 = (PWMMR0 * a) / 0xFF;
	}
	
	PWMLER = 0x21;
}
	
/* 4ec - complete */
void func_4ec(int a)
{
	if (a == 0)
	{
		PWMMR5 = 0;		
	}
	else
	{
		PWMMR2 = (PWMMR0 * a) / 0xFF;
	}
	
	PWMLER = 0x21;
}
	
/* 53c - complete */
void lcd_display_brightness(unsigned char a)
{
	a = a / 2 + 80;
	lcd_write_command(ST7565_CMD_SET_VOLUME_FIRST);
	lcd_write_command(a);
}

/* 570 - complete */
int func_570(unsigned int a)
{
	unsigned short r2 = 0;
	unsigned short ip = 0x43f;
	unsigned short lr = 0x21f;
	unsigned short r3;
	do
	{
		r3 = lr;
		if (a > Data_79080[lr])
		{
			r2 = lr;
		}
		else if (a < Data_79080[lr])
		{
			ip = lr;
		}
		else
		{
			return lr;
		}	
		
		lr = (r2 + ip) / 2;
	}
	while (lr != r3);
	
	return 0x21a;
}

/* 5ec - complete */
void spi0_init(void)
{
   //SPI Clock Counter Register: PCLK / 8
	S0SPCCR = 8;

	//SPI Control Register: MSTR
	S0SPCR = (1 << 5);
}

/* 604 - complete */
unsigned char spi0_write_read_byte(unsigned char a)
{
	S0SPDR = a;
	while (!(S0SPSR & 0x80)) {}
	return S0SPDR;
}


/* 634 - complete */
void lcd_display_character(int inv, int row, unsigned char col, const unsigned char* d)
{
#ifndef OLIMEX_LPC2148
	char i, j, sl;
	unsigned char bitmap[6]; //sp4
	unsigned char sp[4]; //sp

	if ((d[0] >= 0x20) && (d[0] <= 0x7e))
	{
		((unsigned int*)sp)[0] = 0x00188bd8 + ((d[0] - 0x20) << 3);
	}
	else
	{
		((unsigned int*)sp)[0] = 0;
	}

	sp[3] = 0x0b;

	lcd_write_command(((col - 1) * 6 + 1) & 0x0f);
	lcd_write_command(((((col - 1) * 6 + 1) & 0xf0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
	lcd_write_command(((row - 1) & 0x0f) | ST7565_CMD_SET_PAGE);

	ENABLE_FONTROM_CS;

	for (i = 3; i >= 0; i--)
	{
		spi0_write_read_byte(sp[i]);
	}

	for (i = 0; i < 8; i++)
	{
		sl = spi0_write_read_byte(0);
		
		for (j = 0; j < 6; j++)
		{
			if (sl & (0x80 >> j))
			{
				bitmap[j] |= (1 << i);
			}
			else
			{
				bitmap[j] &= ~(1 << i);
			}
		}
	}

	for (i = 0; i < 6; i++)
	{
		if (inv == 0)
		{
			lcd_write_data(bitmap[i]);
		}
		else
		{
			lcd_write_data(~bitmap[i]);
		}
	}

	DISABLE_FONTROM_CS;
#endif
}

/* 7e8 - complete */
void lcd_display_string(int a, unsigned char b, unsigned char c, unsigned char d, const unsigned char* e)
{
	unsigned char i;

	if ((c + d) > 22)
	{
		d = 22 - c;
	}

	for (i = 0; i < d; i++)
	{
		if (e[i])
		{
			lcd_display_character(a, b, c + i, &e[i]);
		}
		else
		{
			break;
		}
	}
}

/* 864 - complete */
void lcd_display_bitmap(int inv, int row, int col, unsigned char* bitmap)
{
	unsigned char i;
	
	// Column Address Set 
	lcd_write_command(((((col - 1) * 6 + 1) & 0x0f) >> 0) | ST7565_CMD_SET_COLUMN_LOWER);
	lcd_write_command(((((col - 1) * 6 + 1) & 0xf0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
	
	// Page Address Set
	lcd_write_command(((row - 1) & 0x0f) | ST7565_CMD_SET_PAGE);
	
	if (inv == 0)
	{
		for (i = 0; i < 6; i++)
		{
			lcd_write_data(bitmap[i]);
		}
	}
	else
	{
		for (i = 0; i < 6; i++)
		{
			lcd_write_data(~bitmap[i]);
		}
	}
}

/* 91c - todo */
unsigned char func_91c(int r4, int r5, int r6, int r7, char* sp76)
{
#ifndef OLIMEX_LPC2148
	unsigned char sp24[16];
	union
	{
		unsigned char b[4];
		unsigned int d;
	} sp20;
	char sp16;
	unsigned char r8;
	unsigned char r9 = 0;
	unsigned char sl;
	char fp;
	unsigned char sp12;
	char sp8;
	char sp4 = 0;
	unsigned short sp;

	while ((sp = ((unsigned short*)sp76)[sp4]) != 0)
	{		
		sp16 = 2;
		sl = 8;
	
		if ((sp >= 0x20) && (sp <= 0x7F))
		{
			sp20.d = 0x001883d8 + ((sp - 0x20) << 4);
		}
		else if ((sp >= 0xaca1) && (sp <= 0xacdf))
		{
			sp20.d = 0x0018d878 + ((sp - 0xaca0) << 4);
		}
		else if ((sp >= 0xa0) && (sp < 0x218))
		{
			sp20.d = 0x0018ab58 + ((sp - 0xa0) << 4);
		}
		else if ((sp >= 0x370) && (sp < 0x3d0))
		{
			sp20.d = 0x0018c2d8 + ((sp - 0x370) << 4);
		}
		else if ((sp >= 0x400) && (sp <= 0x4f9))
		{
			sp20.d = 0x0018c8d8 + ((sp - 0x400) << 4);
		}
		else
		{
			sp16 = 3;
			
			if ((sp >= 0x600) && (sp <= 0x6f9))
			{
				sp20.d = 0x001a2f36 + ((sp - 0x600)*34);
			}
			else if ((sp >= 0xb000) && (sp <= 0xb1f1))
			{
				sp20.d = 0x001a506a + ((sp - 0xb000)*34);
			}
			else
			{
				sp16 = 1;
				sl = 16;
				
				if ((sp >= 0x3400) && (sp <= 0x4db5))
				{
					sp20.d = 0x000a76b8 + ((sp - 0x3400) << 5);
				}
				else if ((sp >= 0x4e00) && (sp <= 0x9fa5))
				{
					sp20.d = 0x000a76b8 + ((sp - 0x344a) << 5);
				}
				else if ((sp >= 0xff00) && (sp <= 0xff5e))
				{
					if (sp == 0xff00)
					{
						sp20.d = 0x000b2554;
					}
					else
					{
						sp20.d = 0x000a76b8 + ((sp - 0x8fc9) << 5);
					}
				}
				else if (((sp >= 0xa1) && (sp <= 0x33d5)) ||
					((sp >= 0xe76c) && (sp <= 0xffe5)))
				{					
					sp20.d = 0x000d6b80 + (func_570(sp) << 5) + 0x000a76b8;
				}
				else
				{
					break;
				}
			}
		}

		sp20.b[3] = 0x0b;
		
		ENABLE_FONTROM_CS;
		
		for (sp8 = 3; sp8 >= 0; sp8--)
		{
			spi0_write_read_byte(sp20.b[sp8]);
		}
		
		spi0_write_read_byte(0);
		
		if (sp16 == 3)
		{
			spi0_write_read_byte(0);
			sl = spi0_write_read_byte(0);
		}
		
		if ((r7 - r6) < (r9 + sl))
		{
			break;
		}
		
		sp12 = r6 + r9;
		r9 += sl;
		
		if (sl > 8)
		{
			for (sp8 = 0; sp8 < 16; sp8++)
			{
				r8 = spi0_write_read_byte(0);
				
				for (fp = 0; fp < 8; fp++)
				{
					if (r8 & (0x80 >> fp))
					{
						sp24[fp + ((sp8%2)*8)] |= (1 << (sp8/2)); //???
					}
					else
					{
						sp24[fp + ((sp8%2)*8)] &= ~(1 << (sp8/2)); //???
					}
				}
			}
		}
		else
		{
			for (sp8 = 0; sp8 < 8; sp8++)
			{
				r8 = spi0_write_read_byte(0);
				
				for (fp = 0; fp < 8; fp++)
				{
					if (r8 & (0x80 >> fp))
					{
						sp24[fp] |= (1 << sp8);
					}
					else
					{
						sp24[fp] &= ~(1 << sp8);
					}
				}
			}
		}

		lcd_write_command((sp12 + 1) & 0x0f);
		lcd_write_command((((sp12 + 1) & 0xf0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
		lcd_write_command((((r5 - 1) << 1) & 0x0f) | ST7565_CMD_SET_PAGE);
		
		for (sp8 = 0; sp8 < sl; sp8++)
		{
			if (r4 == 0)
			{
				lcd_write_data(sp24[sp8]);
			}
			else
			{
				lcd_write_data(~sp24[sp8]);
			}
		}

		if (sl > 8)
		{
			for (sp8 = 0; sp8 < 16; sp8++)
			{
				r8 = spi0_write_read_byte(0);
				
				for (fp = 0; fp < 8; fp++)
				{
					if (r8 & (0x80 >> fp))
					{
						sp24[fp + ((sp8%2)*8)] |= (1 << (sp8/2)); //???
					}
					else
					{
						sp24[fp + ((sp8%2)*8)] &= ~(1 << (sp8/2)); //???
					}
				}
			}
		}
		else
		{
			for (sp8 = 0; sp8 < 8; sp8++)
			{
				r8 = spi0_write_read_byte(0);
				
				for (fp = 0; fp < 8; fp++)
				{
					if (r8 & (0x80 >> fp))
					{
						sp24[fp] |= (1 << sp8);
					}
					else
					{
						sp24[fp] &= ~(1 << sp8);
					}
				}
			}
		}

		lcd_write_command((sp12 + 1) & 0x0f);
		lcd_write_command((((sp12 + 1) & 0xf0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
		lcd_write_command(((((r5 - 1) << 1) + 1) & 0x0f) | ST7565_CMD_SET_PAGE);
		
		for (sp8 = 0; sp8 < sl; sp8++)
		{
			if (r4 == 0)
			{
				lcd_write_data(sp24[sp8]);
			}
			else
			{
				lcd_write_data(~sp24[sp8]);
			}	
		}

		sp4++;
		
		DISABLE_FONTROM_CS;
	} //while ((sp = ((unsigned short*)sp76)[sp4]) != 0)
	
	DISABLE_FONTROM_CS;
	
	return r6 + r9;
#endif
}

/* 11d8 - complete */
unsigned char get_hw_key_code(void)
{
	if (bHwKeyQueueReadPtr == bHwKeyQueueWritePtr)
	{
		return bHwKeyCode;
	}
	else
	{
		return sHwKeyQueue[bHwKeyQueueReadPtr];
	}
}

/* 1210 - complete */
void ack_hw_key(void)
{
	if (bHwKeyQueueReadPtr == bHwKeyQueueWritePtr)
	{
		bHwKeyCode |= 0x80;
	}
	else
	{
		bHwKeyQueueReadPtr = (bHwKeyQueueReadPtr + 1) % 8;
	}
}

/* 1268 - complete */
void read_key_matrix(void)
{
	unsigned char row, col, i, r3, ip, lr;
	unsigned int r4;
	
	r3 = 0;
	col = 0;
	row = 0;
	ip = 0;
	
	for (i = 0; i < 4; i++)
	{
		// Write Value 1 on Column GPIO lines: P1.16, P1.17, P1.18, P1.19
		IO1SET = (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19);
		
		// Output: P1.22, P1.23, P1.24, P1.25
		IO1DIR = (1 << 22) | (1 << 23) | (1 << 24) | (1 << 25);
		
		// Output: P1.16 + i
		IO1DIR |= ((1 << 19) >> i); // 19 / 18 / 17 / 16
		
		// Write Value 0 on Column GPIO lines: P1.16 + i
		IO1CLR = (1 << 19) >> i;
		
		// Read Row GPIO lines: P0.22, P0.25, P0.28, P0.29, P0.30
		if ((IO0PIN & ((1 << 22) | (1 << 25) | (1 << 28) | (1 << 29) | (1 << 30))) ^ 
				((1 << 22) | (1 << 25) | (1 << 28) | (1 << 29) | (1 << 30)))
		{
			r4 = IO0PIN;
			if ((r4 & (1 << 22)) == 0)
			{
				row = 1;
				lr = col;
				col = i;
				r3++;
				ip++;
			}

			if ((r4 & (1 << 25)) == 0)
			{
				row = 2;
				col = i;
				r3++;
			}

			if ((r4 & (1 << 28)) == 0)
			{
				row = 3;
				col = i;
				r3++;
			}

			if ((r4 & (1 << 29)) == 0)
			{
				row = 4;
				col = i;
				r3++;
			}

			if ((r4 & (1 << 30)) == 0)
			{
				row = 5;
				col = i;
				r3++;
			}
		}
	} //for (i = 0; i < 4; i++)

	if (r3 == 0)
	{
		//No Key
		lr = 0;
	}
	else if (r3 == 1)
	{
		//Single Key
		lr = col * 5 + row;
	}
	else if ((r3 == 2) && (ip == 2))
	{
		//Two Keys (First Row)
		switch (lr)
		{
			case 0:
				if (col == 1)
				{
					lr = 21;
				}
				else if (col == 3)
				{
					lr = 22;
				}
				else
				{
					lr = 0;
				}	
				break;
				
			case 1:
				if (col == 2)
				{
					lr = 23;
				}
				else
				{
					lr = 0;
				}
				break;
			
			case 2:
				if (col == 3)
				{
					lr = 24;
				}
				else
				{
					lr = 0;
				}
				break;
			
			default:
				break;
		}
	}
	else
	{
		lr = 0;
	}

	if (lr != 0)
	{
		if ((bHwKeyCode & 0x1f) == lr)
		{
			if (bData_40002c02 > 9)
			{
				//Valid
				bHwKeyCode |= 0x20;
			}

			if (bData_40002c02 > 0xc0)
			{
				//Long Press
				bHwKeyCode |= 0x40;
			}

			if (bData_40002c02 < 0xff)
			{
				bData_40002c02++;
			}
		}
		else if ((bHwKeyCode & 0x1f) >= 21)
		{
			switch (bHwKeyCode & 0x1f)
			{
				case 21:
					if ((lr == 1) || (lr == 6))
					{
						bHwKeyCode = (bHwKeyCode & 0xe0) | lr;
					}
					break;
				
				case 22:
					if ((lr == 1) || (lr == 16))
					{
						bHwKeyCode = (bHwKeyCode & 0xe0) | lr;
					}
					break;
				
				case 23:
					if ((lr == 11) || (lr == 6))
					{
						bHwKeyCode = (bHwKeyCode & 0xe0) | lr;
					}
					break;
				
				case 24:
					if ((lr == 11) || (lr == 16))
					{
						bHwKeyCode = (bHwKeyCode & 0xe0) | lr;
					}
					break;
				
				default:
					break;
			}
		}
		else if (ip == 2)
		{
			if (bData_40002c05 == lr)
			{
				if (bData_40002c03 > 9)
				{
						bHwKeyCode = (bHwKeyCode & 0xe0) | lr;
				}

				if (bData_40002c03 < 0xff)
				{
					bData_40002c03++;
				}
			}
			else
			{
				bData_40002c05 = 0;
				
				switch (bHwKeyCode & 0x1f)
				{
					case 1:
						if ((lr == 21) || (lr == 22))
						{
							bData_40002c05 = lr;
						}
						break;
					
					case 6:
						if ((lr == 21) || (lr == 23))
						{
							bData_40002c05 = lr;
						}
						break;
					
					case 11:
						if ((lr == 23) || (lr == 24))
						{
							bData_40002c05 = lr;
						}
						break;
					
					case 16:
						if ((lr == 22) || (lr == 24))
						{
							bData_40002c05 = lr;
						}
						break;
					
					default:
						break;
				}
			}
		}
		else
		{
			bHwKeyCode = lr;
			bData_40002c05 = 0;
			bData_40002c03 = 0;
			bData_40002c02 = 0;
		}
	} //if (lr != 0)
	else
	{
		if ((bHwKeyCode & 0x20) && ((bHwKeyCode & 0x80) == 0))
		{
			if (((bHwKeyQueueWritePtr + 1) % 8) != bHwKeyQueueReadPtr)
			{
				sHwKeyQueue[bHwKeyQueueWritePtr] = bHwKeyCode;
				bHwKeyQueueWritePtr = (bHwKeyQueueWritePtr + 1) % 8;
			}
		}
		
		bHwKeyCode = 0;
		bData_40002c02 = 0;
	}
}

/* 17d0 - complete */
void func_17d0(void)
{
	bData_40002c02 = 0;
	bHwKeyQueueWritePtr = 0;
	bHwKeyQueueReadPtr = 0;
	bHwKeyCode = 0;
}

/* 17f8 - complete */
#ifdef __GNUC__
void timer_isr(void) __attribute__ ((interrupt ("IRQ")));
void timer_isr(void)
#else
void timer_isr(void) __irq
#endif
{
	read_key_matrix();
	
	if (bData_40002c08 == 0)
	{
		IO1SET = (1 << 22);
#ifdef OLIMEX_LPC2148
		// Set LED1
		IOSET0 = (1 << 10);
#endif
				
		bData_40002c07 = 0;
	}
	else if (bData_40002c09 == 0)
	{
		IO1CLR = (1 << 22);
#ifdef OLIMEX_LPC2148
		// Clear LED1
		IOCLR0 = (1 << 10);
#endif
		
		bData_40002c07 = 0;
	}
	else if (bData_40002c07 <= bData_40002c08)
	{
		IO1CLR = (1 << 22);
#ifdef OLIMEX_LPC2148
		// Clear LED1
		IOCLR0 = (1 << 10);
#endif
		
		bData_40002c07++;
	}
	else if (bData_40002c07 <= bData_40002c09)
	{
		IO1SET = (1 << 22);
#ifdef OLIMEX_LPC2148
		// Set LED1
		IOSET0 = (1 << 10);
#endif
		
		bData_40002c07++;
	}
	else if (bData_40002c08 >= bData_40002c09)
	{
		IO1SET = (1 << 22);
#ifdef OLIMEX_LPC2148
		// Set LED1
		IOSET0 = (1 << 10);
#endif
		
		bData_40002c07 = 0;
		bData_40002c08 = 0;
	}
	else
	{
		bData_40002c07 = 0;
	}

	bData_40002c06++;
	
	if (Data_40003214_UserTimerSeconds != 0)
	{
		bData_40003265--;
		if (bData_40003265 == 0)
		{
			bData_40003265 = 100;
			
			Data_40003214_UserTimerSeconds--;
			if (Data_40003214_UserTimerSeconds == 0)
			{
				bData_40002c08 = 160;
				bData_40002c09 = bData_40002c08 - 1;				
			}
		}
	}

	T0IR = 1; //Reset MR0 Interrupt
	VICVectAddr = 0;
}

/* 19cc - complete */
#ifdef __GNUC__
void rtc_isr(void) __attribute__ ((interrupt ("IRQ")));
void rtc_isr(void)
#else
void rtc_isr(void) __irq
#endif
{
	// Clear the RTC Interrupt Location Register regarding..
	ILR = (1 << 0) // increment, 
		| (1 << 1); // Alarm.
	
	bData_40002c06 = 0;
	
#ifdef OLIMEX_LPC2148
	{
		// Blinking LED2
		static int flag = 0;
		if (flag)
		{
			IOSET0 = (1 << 11);
			flag = 0;
		}
		else
		{
			IOCLR0 = (1 << 11);
			flag = 1;
		}
	}
#endif
	
	VICVectAddr = 0;
}

#include "uart.c"

#ifdef __GNUC__
//void delay_loop(unsigned int a) __attribute__((optimize(-O0)));
#endif

/* 2254 - complete */
void delay_loop(unsigned int a)
{
#ifdef __GNUC__
   volatile unsigned int b;
#else
	unsigned int b;
#endif
	for ( ; a > 1; a--)
	{	
		for (b = 0x0000ffff; b > 1; b--)
		{
		}
	}
}

#ifdef USE_USB
#include "usb.c"
#endif

#if 0
#include "LPCUSB/usbinit.c"
#include "LPCUSB/usbhw_lpc.c"
#include "LPCUSB/usbcontrol.c"
#include "LPCUSB/usbstdreq.c"
#endif

#ifdef OLIMEX_LPC2148
#include "ssp.c"
#include "mmc.c"
#endif

/* 227c - complete */
void lpc_interrupt_init(void)
{
	//Timer0
	// Prescale Register
	T0PR = 0;
	// Match Control Register
	T0MCR = 3;
	// Match Register 0
	T0MR0 = 0x1b000;
	// Timer Control Register
	T0TCR = 3;
	T0TCR = 1;
	
	VICIntSelect = 0;
	
	// Slot 0 has the highest priority and slot 15 the lowest

	#if 1
	VICVectCntl0 = (1 << 5) | 4; // TIMER0 -> Slot 0
	VICVectAddr0 = (unsigned int) timer_isr;
	VICIntEnable = (1 << 4); // Enable TIMER0
	
	VICVectCntl3 = (1 << 5) | 13; // RTC -> Slot 3
	VICVectAddr3 = (unsigned int) rtc_isr;
	VICIntEnable = (1 << 13); // Enable RTC
	#else
	VICVectCntl1 = (1 << 5) | 4; // TIMER0 -> Slot 1
	VICVectAddr1 = (unsigned int) timer_isr;
	VICIntEnable = (1 << 4); // Enable TIMER0
	
	VICVectCntl4 = (1 << 5) | 13; // RTC -> Slot 4
	VICVectAddr4 = (unsigned int) rtc_isr;
	VICIntEnable = (1 << 13); // Enable RTC
	#endif
	
	// Counter Increment Interrupt Register
	CIIR = (1 << 0); //an increment of the Second value generates an interrupt

	// Clear the RTC Interrupt Location Register regarding...
	ILR = (1 << 0) // increment, 
		| (1 << 1); // Alarm.
	
	// Clock Control Register
	CCR = (1 << 4) | (1 << 0); //CLKEN + CLKSRC (from Oscillator)
	
	#if 1
	VICVectCntl1 = (1 << 5) | 6; // UART0 -> Slot 1
	VICVectCntl2 = (1 << 5) | 7; // UART1 -> Slot 2
	#else
	VICVectCntl2 = (1 << 5) | 6; // UART0 -> Slot 2
	VICVectCntl3 = (1 << 5) | 7; // UART1 -> Slot 3
	#endif
	VICIntEnable = (1 << 7); // Enable UART1
	VICIntEnable = (1 << 6); // Enable UART0
}

/* 2328 - complete */
void lpc_hw_init(void)
{
	// Enable the PLL
	PLL0CON = 0x01;
	
	// Setting peripheral Clock (pclk) to System Clock (cclk) / 4
	VPBDIV = 0;
	
#ifdef OLIMEX_LPC2148
	// Setup the PLL to multiply the 12 MHz XTAL input...
	PLL0CFG = 0x03 //by 4
		| (1 << 5); //divide by 2.
#else
	// Setup the PLL to multiply the 11.0592 MHz XTAL input...
	PLL0CFG = 0x03 //by 4,
		| (1 << 5); //divide by 2. CCLK = 44.2368 MHz / Fcco = 176,9472
#endif
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	// Wait for the PLL to lock to set frequency 
	while (!(PLL0STAT & 0x400)) {}
	
	// Connect the PLL as the clock source 
	PLL0CON = 0x01 | 0x02;
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	MAMCR = 2;
	MAMTIM = 3;
	
	PINSEL0 = //0x00059505 = 00 00 00 00 00 00 01 01 10 01 01 01 00 00 01 01
		(1 << 0) | // P0.0 = TXD (UART0)
		(1 << 2) | // P0.1 = RXD (UART0)
		(0 << 4) | // P0.2 = GPIO Port 0.2
		(0 << 6) | // P0.3 = GPIO Port 0.3
		(1 << 8) | // P0.4 = SCK0 (SPI0)
		(1 <<10) | // P0.5 = MISO0 (SPI0)
		(1 <<12) | // P0.6 = MOSI0 (SPI0)
		(2 <<14) | // P0.7 = PWM2
		(1 <<16) | // P0.8 = TXD (UART1)
		(1 <<18) | // P0.9 = RxD (UART1)
		(0 <<20) | // P0.10 = GPIO Port 0.10
		(0 <<22) | // P0.11 = GPIO Port 0.11
		(0 <<24) | // P0.12 = GPIO Port 0.12 -> LCD Data Latch ?
		(0 <<26) | // P0.13 = GPIO Port 0.13
		(0 <<28) | // P0.14 = GPIO Port 0.14
		(0 <<30);  // P0.15 = GPIO Port 0.15 -> LCD D7-D0 ?
	PINSEL1 = //0x800046a8 = 10 00 00 00 00 00 00 00 01 00 01 10 10 10 10 00
		(0 << 0) | // P0.16 = GPIO Port 0.16
		(2 << 2) | // P0.17 = SCK1 (SSP)
		(2 << 4) | // P0.18 = MISO1 (SSP)
		(2 << 6) | // P0.19 = MOSI1 (SSP)
		(2 << 8) | // P0.20 = SSEL1 (SSP)
		(1 <<10) | // P0.21 = PWM5
		(0 <<12) | // P0.22 = GPIO Port 0.22
		(1 <<14) | // P0.23 = VBUS
		(0 <<16) | // P0.24 = Reserved
		(0 <<18) | // P0.25 = GPIO Port 0.25
		(0 <<20) | // P0.26 = Reserved
		(0 <<22) | // P0.27 = Reserved
		(0 <<24) | // P0.28 = GPIO Port 0.28
		(0 <<26) | // P0.29 = GPIO Port 0.29
		(0 <<28) | // P0.30 = GPIO Port 0.30
		(2 <<30);  // P0.31 = CONNECT
	PINSEL2 = //0x00000004 = 00 00 00 00 00 00 00 00 00 00 00 00 00 00 01 00
		(0 << 0) | // Reserved
		(1 << 2) | // Pins P1.36-26 are used as a Debug port.
		(0 << 3);  // Pins P1.25-16 are used as GPIO pins.
		
	IO0DIR = //0x0001b480 = 00 00 00 00 00 00 00 01 10 11 01 00 10 00 00 00
		(0 << 2) | // P0.2 = In
		(0 << 3) | // P0.3 = In
		(1 << 7) | // P0.7 = Out
#ifdef OLIMEX_LPC2148
		(1 <<10) | // P0.10 = Out -> LED1
		(1 <<11) | // P0.11 = Out -> LED2
#else
		(1 <<10) | // P0.10 = Out
		(0 <<11) | // P0.11 = In
#endif
		(1 <<12) | // P0.12 = Out -> LCD Data Latch ?
		(1 <<13) | // P0.13 = Out -> LED torch?
		(0 <<14) | // P0.14 = In
		(1 <<15) | // P0.15 = Out -> LCD D7-D0 ?
		(1 <<16) | // P0.16 = Out -> LED torch?
		(0 <<22) | // P0.22 = In -> Key Matrix Row 1
		(0 <<25) | // P0.25 = In -> Key Matrix Row 2
		(0 <<28) | // P0.28 = In -> Key Matrix Row 3
		(0 <<29) | // P0.29 = In -> Key Matrix Row 4
		(0 <<30);  // P0.30 = In -> Key Matrix Row 5
	IO1DIR = //0x03cf0000 = 00 00 00 11 11 00 11 11 00 00 00 00 00 00 00 00
		(1 <<16) | // P1.16 = Out -> Key Matrix Column 3
		(1 <<17) | // P1.17 = Out -> Key Matrix Column 2
		(1 <<18) | // P1.18 = Out -> Key Matrix Column 1
		(1 <<19) | // P1.19 = Out -> Key Matrix Column 0
		(0 <<20) | // P1.20 = In
		(0 <<21) | // P1.21 = In
		(1 <<22) | // P1.22 = Out -> Buzzer???
		(1 <<23) | // P1.23 = Out -> LCD A0 Pin (Command/Data) ?
		(1 <<24) | // P1.24 = Out -> Chip Select for SPI Flash
		(1 <<25);  // P1.25 = Out -> Chip Select for SPI Font ROM
	IO1SET = 1 << 22; //0x00400000; P1.22 = High
	IO0SET = 1 << 13; //0x00002000; P0.13 = High
	IO0CLR = 1 << 16; //0x00010000; P0.16 = Low
	IO1SET = 1 << 24; //0x01000000; P1.24 = High
	IO1SET = 1 << 25; //0x02000000; P1.25 = High
	
	spi0_init();
#ifdef OLIMEX_LPC2148
	ssp_init();
#endif

	lcd_display_configure();
	lcd_display_clear();
	lcd_display_brightness(0x80);
	setDisplayPWM(0xff);
	
	func_17d0();
	
	bData_40002c08 = 0x10;
	bData_40002c09 = 0x10;
	bData_40002c07 = 0x00;

	lpc_interrupt_init();
}

/* 243c - complete */
void flash_read(unsigned int PageAdr, int b, int Count, unsigned char* Data)
{
#ifndef OLIMEX_LPC2148
	unsigned short i = 0;
	
	ENABLE_FLASH_CS;
	
	spi0_write_read_byte(FLASH_CMD_CONT_ARRAY_READ);
	spi0_write_read_byte(PageAdr >> (16 - FLASH_PAGE_BITS));
	spi0_write_read_byte(PageAdr << (FLASH_PAGE_BITS - 8));
	
	while (i < (b+5 + Count))
	{
		if (i < (b+5))
		{
			spi0_write_read_byte(0);
		}
		else
		{
			Data[i - (b+5)] = spi0_write_read_byte(0);
		}
		
		i++;
	}
	
	DISABLE_FLASH_CS;
#endif
}

/* 24d4 - complete */
void flash_write(int PageAdr, unsigned short BufAdr, int Count, unsigned char* Data)
{
#ifndef OLIMEX_LPC2148
	unsigned short i;
	ENABLE_FLASH_CS;

	spi0_write_read_byte(FLASH_CMD_BUF1_WRITE);
	spi0_write_read_byte(0x00);
	spi0_write_read_byte(BufAdr >> 8);
	spi0_write_read_byte(BufAdr & 0xFF);
	
	for (i = 0; i < Count; i++)
	{
		spi0_write_read_byte(Data[i]);
	}
	
	DISABLE_FLASH_CS;
	ENABLE_FLASH_CS;
	
	if (PageAdr < 0x1000)
	{
		spi0_write_read_byte(FLASH_CMD_BUF1_TO_MEM);
		spi0_write_read_byte(PageAdr >> (16 - FLASH_PAGE_BITS));
		spi0_write_read_byte(PageAdr << (FLASH_PAGE_BITS - 8));
		spi0_write_read_byte(0);
	}
	
	DISABLE_FLASH_CS;
	
	delay_loop(5);
#endif
}

/* 258c - complete */
void flash_write_cust_sky_target(int a, unsigned char* b)
{
	unsigned char sp[FLASH_PAGE_SIZE];
	unsigned char i = 0;
	b[0] = 1;

	flash_read((0x37 << 6) | 5, 0, sizeof(sp), sp);

	for (i = 0; i < 24; i++)
	{
		sp[(a - 1)*24 + i] = b[i];
	}

	flash_write((0x37 << 6) | 5, 0, sizeof(sp), sp);
}

/* 260c - complete */
void flash_write_cust_land_target(int a, unsigned char* b)
{
	unsigned char sp[FLASH_PAGE_SIZE];
	unsigned char i = 0;
	b[0] = 1;

	flash_read((0x37 << 6) | 6, 0, sizeof(sp), sp);

	for (i = 0; i < 25; i++)
	{
		sp[25*(a - 1) + i] = b[i];
	}

	flash_write((0x37 << 6) | 6, 0, sizeof(sp), sp);
}

/* 268c - complete */
void flash_write_recent_target(unsigned char targetType, unsigned int targetId)
{
	unsigned char oldType;
	unsigned int oldId;
	unsigned char buf[57];

	flash_read((0x37 << 6) | 7, 0, sizeof(buf), buf);

	oldType = buf[1];
	oldId = ((buf[2] - '0') * 100000) + 
		(((buf[3] - '0') * 10000)) + 
		(((buf[4] - '0') * 1000)) +
		(((buf[5] - '0') * 100)) +
		(((buf[6] - '0') * 10)) +
		(buf[7] - '0');

	if ((targetType == oldType) && (oldId == targetId))
	{
		oldType = 0;
	}
	else
	{
		buf[0]++;
		if (buf[0] > 8) 
		{
			buf[0] = 8;
		}

		flash_write((0x37 << 6) | 7, 0, sizeof(buf[0]), buf);
		flash_write((0x37 << 6) | 7, 8, sizeof(buf) - sizeof(buf[0]), &buf[1]);
		buf[1] = targetType;
		flash_write((0x37 << 6) | 7, 1, sizeof(buf[1]), &buf[1]);
		sprintf(buf, "%06d", targetId);
		flash_write((0x37 << 6) | 7, 2, 6, &buf[0]);
	}
}

/* 27c4 - complete */
void flash_get_ota_zero_data(float* a, float* b)
{
	unsigned char buf[5];

	flash_read((0x37 << 6) | 9, 0, sizeof(buf), buf);

	*a = (buf[0] - '0') * 100.0 + (buf[1] - '0') * 10.0 + buf[2] - '0';
	*b = (buf[3] - '0') * 10.0 + buf[4] - '0';
}

/* 2910 - complete */
void flash_write_ota_zero_data(int a, int b)
{
	unsigned char buf[5];
	sprintf(buf, "%03d%02d", a, b);
	flash_write((0x37 << 6) | 9, 0, sizeof(buf), buf);
}

/* 29b0 - complete */
void flash_write_custom_site_data(unsigned char* name, unsigned char* lon, unsigned char* lat, unsigned char* tz)
{
	flash_write((0x37 << 6) | 10, 10, 8, name);
	flash_write((0x37 << 6) | 10, 18, 6, lon);
	flash_write((0x37 << 6) | 10, 24, 5, lat);
	flash_write((0x37 << 6) | 10, 29, 3, tz);
}

/* 2a1c - complete */
void flash_get_custom_site_data(unsigned char* pName, 
		float* pLongitude, float* pLatitude, int* pTimeZone)
{
	unsigned char buf[22];
	unsigned char i = 0;
	
	flash_read((0x37 << 6) | 10, 10, sizeof(buf), buf);
	
	for (i = 0; i < 8; i++)
	{
		pName[i] = buf[i];
	}
	
	*pLongitude = (buf[9] - '0') * 100.0 + (buf[10] - '0') * 10.0 + buf[11] - '0' + 
		((buf[12] - '0') * 10.0 + buf[13] - '0') / 60.0;
	
	if (buf[8] == 'W')
	{
		*pLongitude *= -1.0;
	}
	
	*pLatitude = (buf[15] - '0') * 10.0 + buf[16] - '0' +
		((buf[17] - '0') * 10.0 + buf[18] - '0') / 60.0;
	
	if (buf[14] == 'S')
	{
		*pLatitude *= -1.0;
	}
		
	*pTimeZone = (buf[20] - '0') * 10.0 + buf[21] - '0';
	
	if (buf[19] == 'W')
	{
		*pTimeZone *= -1.0;
	}
}

/* 2df8 - complete */
void func_2df8(int a, int b, int c, int d, unsigned char* e)
{
	unsigned char buf[528];
	unsigned char i = 0;
	
	flash_read(b, 0, sizeof(buf), buf);
	
	for (i = 0; i < d; i++)
	{
		buf[d * (a % (528 / d)) + c + i] = e[i];
	}
	
	flash_write(b, 0, sizeof(buf), buf);
}

/* 2e94 - todo */
void func_2e94(unsigned short a)
{
	unsigned char buf[528];
	
	if (a > 500)
	{
		return;
	}

	Data_40002c24.wData = a;
	
	flash_read(0xFFF, 0, sizeof(buf), buf);
	
	buf[4] = Data_40002c24.bData[0];
	buf[5] = Data_40002c24.bData[1];
	
	flash_write(0xFFF, 0, sizeof(buf), buf);
}

/* 2f00 - todo */
unsigned short func_2f00(void)
{
	flash_read(0xFFF, 0x04, 2, Data_40002c24.bData);
	
	if (Data_40002c24.wData > 500)
	{
		func_2e94(0);
		return 0;
	}
	
	return Data_40002c24.wData;
}

/* 2f48 - todo */
void func_2f48(int a, unsigned char* b)
{
	func_2df8(a, 0xfde, 0, 16, b);
}

/* 2f74 - todo */
int func_2f74(int a, int* b, int* c, int* d, int* e)
{
	unsigned char buf[16];
	unsigned char i;
	unsigned short sl;
	unsigned short fp;
	
	sl = func_2f00();
	
	if ((sl == 0) || ((sl-1) < a))
	{
		return 0;
	}
	
	fp = 16 * (a % 33);
	
	flash_read((unsigned short)(0xfde + (a / 33)), fp, sizeof(buf), buf);
	
	for (i = 0; i < 4; i++)
	{
		Data_40002c28.bData[i] = buf[i];
	}
	
	*b = Data_40002c28.Data;

	for (i = 0; i < 4; i++)
	{
		Data_40002c28.bData[i] = buf[i + 4];
	}
	
	*c = Data_40002c28.Data;

	for (i = 0; i < 4; i++)
	{
		Data_40002c28.bData[i] = buf[i + 8];
	}
	
	*d = Data_40002c28.Data;

	for (i = 0; i < 4; i++)
	{
		Data_40002c28.bData[i] = buf[i + 12];
	}
	
	*e = Data_40002c28.Data;
	
	return 1;
}

/* 30e4 - todo */
int func_30e4(unsigned char* a, int b, int c, int d, int e)
{
	unsigned char buf[16];
	unsigned char i;
	unsigned short sl;
	
	sl = func_2f00();

	if (a[0] == 0)
	{
		if (sl != 0)
		{
			func_2e94(0);
			sl = 0;
		}
		a[0] = 1;
	}

	if (sl >= 500)
	{
		return 0;
	}
	
	Data_40002c28.Data = b;
	
	for (i = 0; i < 4; i++)
	{
		buf[i] = Data_40002c28.bData[i];
	}

	Data_40002c28.Data = c;
	
	for (i = 0; i < 4; i++)
	{
		buf[i + 4] = Data_40002c28.bData[i];
	}

	Data_40002c28.Data = d;
	
	for (i = 0; i < 4; i++)
	{
		buf[i + 8] = Data_40002c28.bData[i];
	}

	Data_40002c28.Data = e;
	
	for (i = 0; i < 4; i++)
	{
		buf[i + 12] = Data_40002c28.bData[i];
	}
	
	func_2f48(sl, buf);
	
	func_2e94(sl + 1);
		
	return 1;
}

/* 3230 - todo */
void func_3230(unsigned char* a, float* b, float* c)
{
	a = a;
}

/* 3238 - complete */
void func_3238(unsigned short a)
{
	unsigned char buf[528];
	
	if (a > 66)
	{
		return;
	}
	
	Data_40002c24.wData = a;
	
	flash_read(0xfff, 0, sizeof(buf), buf);
	
	buf[8] = Data_40002c24.bData[0];
	buf[9] = Data_40002c24.bData[1];
	
	flash_write(0xfff, 0, sizeof(buf), buf);
}

/* 32a4 - todo */
int func_32a4(void)
{
	flash_read(0xfff, 0x08, 2, Data_40002c24.bData);
	
	if (Data_40002c24.wData > 66)
	{
		func_3238(0);
		return 0;
	}
	
	return Data_40002c24.wData;
}

/* 32ec - complete */
void func_32ec(unsigned short a)
{
	unsigned char buf[528];
	
	if (a > 65)
	{
		return;
	}
	
	Data_40002c24.wData = a;
	
	flash_read(0xfff, 0, sizeof(buf), buf);
	
	buf[10] = Data_40002c24.bData[0];
	buf[11] = Data_40002c24.bData[1];
	
	flash_write(0xfff, 0, sizeof(buf), buf);
}

/* 3358 - todo */
int func_3358(void)
{
	flash_read(0xfff, 0x0a, 2, Data_40002c24.bData);
	
	if (Data_40002c24.wData > 65)
	{
		func_32ec(0);
		return 0;
	}
	
	return Data_40002c24.wData;
}

/* 33a0 - todo */
void func_33a0(int a, unsigned char* b)
{
	func_2df8(a, 0, 0, 8, b);
}

/* 33cc - todo */
int func_33cc(unsigned short a, int* b, int* c)
{
	unsigned char buf[8];
	unsigned char i;
	int r8, r9;
	unsigned short sl;
	unsigned short fp;
	
	r8 = func_32a4();
	r9 = func_3358();
	
	if ((r8 == 0) || ((r8-1) < a))
	{
		return 0;
	}
	
	if (r9 < a)
	{
		a = r9 + 66 - a;
	}
	else
	{
		a = r9 - a;
	}
	
	sl = 8 * (a % 66);
	fp = a / 66;
	
	flash_read(fp, sl, sizeof(buf), buf);
	
	for (i = 0; i < 4; i++)
	{
		Data_40002c28.bData[i] = buf[i];
	}
	
	*b = Data_40002c28.Data;

	for (i = 0; i < 4; i++)
	{
		Data_40002c28.bData[i] = buf[i+4];
	}
	
	*c = Data_40002c28.Data;
	
	return 1;
}

#include "object_database.c"

/* 4dd0 - todo */
int func_4dd0(int a, Struct_4dd0* b)
{
	unsigned char buf[20];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;

	if ((a == 0) && (a > 640))
	{
		return 0;
	}
	
	r6 = (a - 1) / 26;
	r7 = ((a - 1) % 26) * 20;

	flash_read((unsigned short)(0xd9e + r6), r7, sizeof(buf), buf);

	for (i = 0; i < 8; i++)
	{
		b->bData_0[i-0] = buf[i];
	}
	
	b->bData_0[8] = 0;
	b->bData_0[9] = 0;

		for (i = 8; i < 16; i++)
	{
		b->bData_10[i-8] = buf[i];
	}
	
	b->bData_10[8] = 0;
	b->bData_10[9] = 0;
	
	b->fData_20 = buf[16] + buf[17] / 100.0;
	b->fData_24 = buf[18] + buf[19] / 100.0;

	return 1;
}

/* 4f5c - todo */
int flash_get_site_data(int a, Struct_SiteData* b)
{
	unsigned char buf[40];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;
	
	if ((a == 0) && (a > 170))
	{
		return 0;
	}
	
	r6 = (a - 1) / 13;
	r7 = ((a - 1) % 13) * 40;
	
	flash_read((unsigned short)(0xdb7 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 18; i++)
	{
		b->cCountry[i-0] = buf[i];
	}
	
	b->cCountry[18] = ' ';
	b->cCountry[19] = 0;
	
	for (i = 18; i < 34; i++)
	{
		b->cCity[i-18] = buf[i];
	}
	
	b->cCity[16] = ' ';
	b->cCity[17] = 0;
	
	if (buf[34] >= 0x80)
	{
		b->fLongitude = ((0x80 - buf[34]) * 100) - buf[35] - buf[36] / 60.0;
	}
	else
	{
		b->fLongitude = (buf[34] * 100) + buf[35] + buf[36] / 60.0;
	}
	
	if (buf[37] >= 0x80)
	{
		b->fLatitude = (0x80 - buf[37]) - buf[38] / 60.0;
	}
	else
	{
		b->fLatitude = buf[37] + buf[38] / 60.0;
	}
	
	if (buf[39] > 0x80)
	{
		b->Zone = 0x80 - buf[39];
	}
	else
	{
		b->Zone = buf[39];
	}
	
	return 1;
}

/* 5218 - complete */
int func_5218(int a, Struct_5218* b)
{
	unsigned char sp104[22 * 24];
	unsigned char sp80[24];
	unsigned char i;
	
	if ((a == 0) && (a > 10))
	{
		return 0;
	}
	
	flash_read(0xdc5, 0, sizeof(sp104), sp104);
	
	for (i = 0; i < 24; i++)
	{
		sp80[i] = sp104[(a - 1) * 24 + i];
	}
	
	b->bData_0 = sp80[0];
	
	for (i = 1; i < 9; i++)
	{
		b->bData_1[i-1] = sp80[i];
	}

	b->fData_12 = sp80[9] * 10 + sp80[10] +
		(sp80[11] * 10 + sp80[12]) / 60.0 +
		(sp80[13] * 10 + sp80[14] + sp80[15] / 10.0) / 3600.0;
	
	b->fData_16 = sp80[17] * 10 + sp80[18] +
		(sp80[19] * 10 + sp80[20]) / 60.0 +
		(sp80[21] * 10 + sp80[22] + sp80[23] / 10.0) / 3600.0;
	
	if (sp80[16] == '-')
	{
		b->fData_16 *= -1.0;
	}
	
	return 1;
}

/* 54e0 - complete */
int func_54e0(int a, Struct_54e0* b)
{
	unsigned char sp108[528];
	unsigned char sp80[25];
	unsigned char i;
	
	if ((a == 0) && (a > 9))
	{
		return 0;
	}
	
	flash_read(0xdc6, 0, sizeof(sp108), sp108);

	for (i = 0; i < 25; i++)
	{
		sp80[i] = sp108[(a - 1) * 25 + i];
	}
	
	b->bData_0 = sp80[0];
	
	for (i = 1; i < 9; i++)
	{
		b->bData_1[i-1] = sp80[i];
	}
	
	b->fData_12 = sp80[9] * 100 + sp80[10] * 10 + sp80[11] +	
		(sp80[12] * 10 + sp80[13]) / 60.0 +
		(sp80[14] * 10 + sp80[15] + sp80[16] / 10.0) / 3600.0;

	b->fData_16 = sp80[18] * 10 + sp80[19] +	
		(sp80[20] * 10 + sp80[21]) / 60.0 +
		(sp80[22] * 10 + sp80[23] + sp80[24] / 10.0) / 3600.0;
	
	if (sp80[17] == '-')
	{
		b->fData_16 *= -1.0;
	}
	
	return 1;
}

/* 57b8 - complete */
unsigned char flash_get_recent_targets(unsigned char* targetTypes, int* targetIds, void* c)
{
	unsigned char buf[57];
	unsigned char i;
	unsigned char count;
	
	flash_read((0x37 << 6) | 7, 0, sizeof(buf), buf);
	
	count = buf[0];
	for (i = 0; i < count; i++)
	{
		targetTypes[i] = buf[1 + i*7];
	}

	for (i = 0; i < count; i++)
	{
		targetIds[i] = 
		(buf[2 + i*7] - '0') * 100000 +
		(buf[3 + i*7] - '0') * 10000 +
		(buf[4 + i*7] - '0') * 1000 +
		(buf[5 + i*7] - '0') * 100 +
		(buf[6 + i*7] - '0') * 10 +
		(buf[7 + i*7] - '0');
	}
	
	c = buf;
	return buf[0];
}

#include "align_stars.c"

/* 5f40 - todo */
void initialize_variables(void)
{
	bData_40002f1e_SetupLocalData = 1;
	bData_40002c58 = 0;
	bData_40002c5a = 0;
	bData_40002c68 = 0;
	bDaylightSavingTime = 0;
	dData_40002c98 = 0.0;
	bData_40002e7c_TrackingRateType = 0;
	dData_40002ca0 = 1.0;
	dData_40002ca8 = 0.235;
	dData_40002cb0 = 0.326;
	dData_40002c88 = 0.0;
	dData_40002c90 = 0.0;
	
	//Rectascension
	Data_40002cb8 = 11;
	Data_40002cbc = 41;
	fData_40002cc0 = 12.6;
	
	//Declination
	Data_40002d40 = 1;
	Data_40002cf4 = 55;
	Data_40002cf8 = 11;
	fData_40002cfc = 1.9;
	
	Data_40002d20 = 1;
	Data_40002d24 = 3;
	fData_40002d28 = 5.9;
	
	Data_40002d48 = 6;
	Data_40002d4c = 3;
	fData_40002d50 = 5.8;
	
	Data_40002d68_OTARightAscensionHours = 2;
	Data_40002d6c_OTARightAscensionMinutes = 3;
	fData_40002d70_OTARightAscensionSeconds = 2.3;
	Data_40002d8c_OTADeclinationDegrees = 5;
	Data_40002d90_OTADeclinationMinutes = 2;
	fData_40002d94_OTADeclinationSeconds = 5.6;
	Data_40002dac = 8;
	Data_40002db0 = 2;
	fData_40002db4 = 5.8;
	Data_40002de0 = 3;
	Data_40002de4 = 6;
	fData_40002de8 = 2.5;
	Data_40002e18_SiteLongitudeDegrees = 12;
	Data_40002e1c_SiteLongitudeMinutes = 7;
	fData_40002e20_SiteLongitudeSeconds = 1.3;
	Data_40002e34 = 1;
	Data_40002e38_SiteLatitudeDegrees = 5;
	Data_40002e3c_SiteLatitudeMinutes = 1;
	fData_40002e40_SiteLatitudeSeconds = 8.9;
	Data_40002e44 = 1;
	Data_40002e54_Zone = 8;
	Data_40002e5c_Year = 2010;
	bData_40002e60_Month = 8;
	bData_40002e61_Day = 28;
	bData_40002e62_Hours = 18;
	bData_40002e63_Minutes = 18;
	bData_40002e64_Seconds = 18;
	bData_40002e79_SkyLandTargetSeletion = 0;
	bData_40002e7a_MountType = MENU_MOUNT_TYPE_AZ; //0;
	bData_40002e7b_GpsAvailable = 0;
	bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_64; //5;
	bData_40002e7e = 0;
	bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
	bData_40002e89 = 1;
	bData_40002e8b = 0;
	bData_40002e8c = 0;
	fData_40002e90 = 0;
	fData_40002e98 = 23.8;
	Data_40002e9c = 0;
	Data_40002e94 = 0;
	fData_40002ea0 = 0;
	fData_40002ea8 = 23.8;
	fData_40002eac = 0;
	fData_40002ea4 = 0;
	iBacklashCorrectionSlewing = 0;
	bData_40002eb4 = 0;
	bData_40002eb5_SolarSystemObjectNr = 0;
	wData_40002eb6 = 0;
	wData_40002eb8_MessierNr = 0;
	wData_40002eba_NGCNr = 0;
	wData_40002ebc_ICNr = 0;
	wData_40002ebe_ShNr = 0;
	wData_40002ec0_BrightStarNr = 0;
	Data_40002ec4_SAONr = 0;
	wData_40002ecc = 0;
	bData_40002ece_ConstellationNr = 1;
	wData_40002ed0 = 0;
	bData_40002ed2_FamousStarNr = 0;
	wData_40002ed4 = 0;
	wData_40002ed6 = 0;
	wData_40002ed8 = 0;
	wData_40002eda = 1;
	bData_40002ede = 1;
	bData_40002edf = 1;
	bData_40002ef7 = 0;
	Data_40002f04 = 0;
	Data_40002f08 = 0;
	bData_40002f0c = 0;
	bData_40002f0d_RecentTargetType = 0;
	bData_40002f10_RecentTargetId = 0;
}

/* 6518 - complete */
void get_rtc_date_time(void)
{
	unsigned int r0 = CTIME0;
	unsigned int r1 = CTIME1;
	
	Data_40002e5c_Year = (r1 >> 16) & 0x0fff;
	bData_40002e60_Month = (r1 >> 8) & 0x0f;
	bData_40002e61_Day = r1 & 0x1f; //Day
	bData_40002e62_Hours = (r0 >> 16) & 0x1f;
	bData_40002e63_Minutes = (r0 >> 8) & 0x3f;
	bData_40002e64_Seconds = r0 & 0x3f; //Seconds
	wData_40002e66 = bData_40002c06 * 10;
}

#ifdef __GNUC__
//void func_659c(unsigned short a) __attribute__((optimize(-O0)));
#endif

/* 659c - complete */
void func_659c(unsigned short a)
{
#ifdef __GNUC__
	volatile unsigned short b;
#else
	unsigned short b;
#endif
	for (; a > 1; a--)
	{
		for (b = 10000; b > 1; b--)
		{
		}
	}
}

/* 65d4 - todo */
void func_65d4(double sp40, double sp48)
{
//	double sp48;
//	double sp40;
	
	if (bData_40002c1a == 1)
	{
		#if 0
		Data_40004128.dData_8 = 0.0754242657290017382010205437837;
		Data_40004128.dData_16 = 0.0754242657290017382010205437837;
		Data_40004128.dData_24 = 0.000109484484490649148667393286694;
		Data_40004128.dData_32 = 0.000109484484490649148667393286694;
		#else
		Data_40004128.dData_8 = Data_40004128.dData_16 = 0.0754242657290017382010205437837;
		Data_40004128.dData_24 = Data_40004128.dData_32 = 0.000109484484490649148667393286694;
		#endif
	}
	//6634
	if (bData_40002e8b == 0)
	{
		if (((Data_40004128.dData_176 > 0) &&
			((Data_40004128.dData_208 - Data_40004128.dData_160) > 0.005)) ||
			((Data_40004128.dData_176 < 0) &&
			((Data_40004128.dData_208 - Data_40004128.dData_160) < -0.005)))
		{
			//66e4
			if (bData_40002c1a == 1)
			{
				//66f4
				Data_400033c8.dwData = (Data_40004128.dData_160 - 0.0 * Data_40004128.dData_176 / 3600.0) *
					256 / Data_40004128.dData_24;
				//->6818
			}
			else
			{
				//6788
				Data_400033c8.dwData = (Data_40004128.dData_160 - 0.6 * Data_40004128.dData_176 / 3600.0) *
					256 / Data_40004128.dData_24;
			}
			//6818
			Data_400033cc.dwData = sp40 * 1.0 / Data_40004128.dData_8;
			//->6a44
		}
		else
		{
			//6860
			if (bData_40002c1a == 1)
			{
				//6870
				Data_400033c8.dwData = (0.0 * Data_40004128.dData_176 / 3600.0 + Data_40004128.dData_160) *
					256 / Data_40004128.dData_24;
				//->6a00
			}
			else
			{
				//6970
				Data_400033c8.dwData = (0.6 * Data_40004128.dData_176 / 3600.0 + Data_40004128.dData_160) *
					256 / Data_40004128.dData_24;
			}
			//6a00
			Data_400033cc.dwData = sp40 * 1.0 / Data_40004128.dData_8;
		}
		//6a44
		if (bData_40002c1a == 2)
		{
			//6a54
			if (Data_400033cc.dwData > 980)
			{
				Data_400033cc.dwData = 980;
			}
			//->6a90
		}
		else
		{
			//6a74
			if (Data_400033cc.dwData > 2000)
			{
				Data_400033cc.dwData = 2000;
			}
		}
		//6a90
		if (Data_40004128.Data_352 == 1)
		{
			Data_400033cc.dwData = 0;
		}
		//6aac
		if (bData_40002c1a == 1)
		{
			//6abc
			if (Data_40004128.dData_304 == 2)
			{
				//6ad8
				if (Data_40003408 == 0)
				{
					Data_400033cc.dwData = 5;
				}
				//6af4
				if ((Data_40003204 != 0) || (Data_40003488 != 0))
				{
					Data_400033cc.dwData = abs(2*((Data_40003204 + 6 * Data_40003488)) + 6); 
					
					if (Data_40003204 == 1)
					{
						Data_400033cc.dwData = 12;
					}
				}
				//6b68
			}
			//6b68
			if (Data_40003408 != 0)
			{
				switch (bData_40002e7d_RotatingSpeed)
				{
					case MENU_ROTATING_SPEED_1: //1:
						//->6bb4
						Data_400033cc.dwData = 2*Data_40003408 + 6;
						break;
					
					case MENU_ROTATING_SPEED_2: //2:
						//->6bd4
						Data_400033cc.dwData = 16;
						break;
					
					case MENU_ROTATING_SPEED_8: //3:
						//->6be8
						Data_400033cc.dwData = 60;
						break;
					
					case MENU_ROTATING_SPEED_16: //4:
						//->6bfc
						Data_400033cc.dwData = 240;
						break;
					
					case MENU_ROTATING_SPEED_64: //5:
						//->6c10
						Data_400033cc.dwData = 460;
						break;
					
					case MENU_ROTATING_SPEED_128: //6:
						//->6c24
						Data_400033cc.dwData = 640;
						break;
					
					case MENU_ROTATING_SPEED_256: //7:
						//->6c38
						Data_400033cc.dwData = 2000;
					
						if (Data_400033cc.dwData <= Data_40002e80)
						{
							Data_40002e80 = Data_400033cc.dwData;
						}
						else
						{
							Data_40002e80 += 400;
						}
						Data_400033cc.dwData = Data_40002e80;
						break;
					
					case MENU_ROTATING_SPEED_512: //8:
						//->6c9c
						Data_400033cc.dwData = 3200;
					
						if (Data_400033cc.dwData <= Data_40002e80)
						{
							Data_40002e80 = Data_400033cc.dwData;
						}
						else
						{
							Data_40002e80 += 640;
						}
						Data_400033cc.dwData = Data_40002e80;
						break;
					
					case MENU_ROTATING_SPEED_MAX: //9:
						//->6d00
						Data_400033cc.dwData = 4800;
					
						if (Data_400033cc.dwData <= Data_40002e80)
						{
							Data_40002e80 = Data_400033cc.dwData;
						}
						else
						{
							Data_40002e80 += 800;
						}
						Data_400033cc.dwData = Data_40002e80;
						break;
						
					#if 0
					default:
						//->6d64
						break;
					#endif
				}
				//6d64
			} //if (Data_40003408 != 0)
			//6d68
			uart1_write_byte(0x55);
			uart1_write_byte(0xaa);
			uart1_write_byte(0x01);
			uart1_write_byte(1 + 2 + 3);
			uart1_write_byte(0x02); //Send RA?
			uart1_write_byte(Data_400033cc.bData[1]);
			uart1_write_byte(Data_400033cc.bData[0]);
			uart1_write_byte(Data_400033c8.bData[3]);
			uart1_write_byte(Data_400033c8.bData[2]);
			uart1_write_byte(Data_400033c8.bData[1]);
			//->6f6c
		} //if (bData_40002c1a == 1)
		else
		{
			//6dec
			if (Data_40003408 != 0)
			{
				switch (bData_40002e7d_RotatingSpeed)
				{
					case MENU_ROTATING_SPEED_1: //1:
						//->6e38
						Data_400033cc.dwData = 8;
						break;
					
					case MENU_ROTATING_SPEED_2: //2:
						//->6e4c
						Data_400033cc.dwData = 16;
						break;
					
					case MENU_ROTATING_SPEED_8: //3:
						//->6e60
						Data_400033cc.dwData = 32;
						break;
					
					case MENU_ROTATING_SPEED_16: //4:
						//->6e74
						Data_400033cc.dwData = 64;
						break;
					
					case MENU_ROTATING_SPEED_64: //5:
						//->6e88
						Data_400033cc.dwData = 100;
						break;
					
					case MENU_ROTATING_SPEED_128: //6:
						//->6e9c
						Data_400033cc.dwData = 200;
						break;
					
					case MENU_ROTATING_SPEED_256: //7:
						//->6eb0
						Data_400033cc.dwData = 400;
						break;
					
					case MENU_ROTATING_SPEED_512: //8:
						//->6ec4
						Data_400033cc.dwData = 600;
						//break; //-> BUG??
					
					case MENU_ROTATING_SPEED_MAX: //9:
						//->6ed8
						Data_400033cc.dwData = 980;
						break;
					
					#if 0
					default:
						//->6ee8
						break;
					#endif
				}
			} //if (Data_40003408 != 0)
			//6eec
			if (Data_400033cc.dwData > 980)
			{
				Data_400033cc.dwData = 980;
			}
			//6f08
			uart1_write_byte(0x55);
			uart1_write_byte(0xaa);
			uart1_write_byte(0x01);
			uart1_write_byte(0x06);
			uart1_write_byte(0x42);
			uart1_write_byte(Data_400033cc.bData[1]);
			uart1_write_byte(Data_400033cc.bData[0]);
			uart1_write_byte(Data_400033c8.bData[3]);
			uart1_write_byte(Data_400033c8.bData[2]);
			uart1_write_byte(Data_400033c8.bData[1]);
		}
		//6f6c
		if (bData_40002c1a == 1)
		{
			Data_400033c8.dwData = (0.0 * Data_40004128.dData_184 / 3600.0 + Data_40004128.dData_168) *
				256 / Data_40004128.dData_32;
			//->70a0
		}		
		else
		{
			//7010
			Data_400033c8.dwData = (1.0 * Data_40004128.dData_184 / 3600.0 + Data_40004128.dData_168) * 
				256 / Data_40004128.dData_32;
		}
		//70a0
		Data_400033cc.dwData = 1.0 * sp48 / Data_40004128.dData_16;
		
		if (bData_40002c1a == 2)
		{
			if (Data_400033cc.dwData > 980)
			{
				Data_400033cc.dwData = 980;
			}
		}
		else
		{
			//7114
			if (Data_400033cc.dwData > 2000)
			{
				Data_400033cc.dwData = 2000;
			}
		}
		//7130
		if (Data_40004128.Data_352 == 1)
		{
			Data_400033cc.dwData = 0;
		}
		
		func_659c(20);
		//7154
		if (bData_40002c1a == 1)
		{
			//7164
			if ((Data_40004128.dData_312 == 2) && (Data_4000348c != 0))
			{
				Data_400033cc.dwData = 32;
			}
			//719c
			if (Data_4000340c != 0)
			{
				switch (bData_40002e7d_RotatingSpeed)
				{
					case MENU_ROTATING_SPEED_1: //1:
						//->71e8
						Data_400033cc.dwData = 4;
						break;
					
					case MENU_ROTATING_SPEED_2: //2:
						//->71fc
						Data_400033cc.dwData = 16;
						break;
					
					case MENU_ROTATING_SPEED_8: //3:
						//->7210
						Data_400033cc.dwData = 60;
						break;
					
					case MENU_ROTATING_SPEED_16: //4:
						//->7224
						Data_400033cc.dwData = 240;
						break;
					
					case MENU_ROTATING_SPEED_64: //5:
						//->7238
						Data_400033cc.dwData = 460;
						break;
					
					case MENU_ROTATING_SPEED_128: //6:
						//->724c
						Data_400033cc.dwData = 640;
						break;
					
					case MENU_ROTATING_SPEED_256: //7:
						//->7260
						Data_400033cc.dwData = 2000;
					
						if (Data_400033cc.dwData <= Data_40002e84)
						{
							Data_40002e84 = Data_400033cc.dwData;
						}
						else
						{
							Data_40002e84 += 400;
						}
						Data_400033cc.dwData = Data_40002e84;
						break;
					
					case MENU_ROTATING_SPEED_512: //8:
						//->72c4
						Data_400033cc.dwData = 3200;
					
						if (Data_400033cc.dwData <= Data_40002e84)
						{
							Data_40002e84 = Data_400033cc.dwData;
						}
						else
						{
							Data_40002e84 += 640;
						}
						Data_400033cc.dwData = Data_40002e84;
						break;
					
					case MENU_ROTATING_SPEED_MAX: //9:
						//->7328
						Data_400033cc.dwData = 4800;
					
						if (Data_400033cc.dwData <= Data_40002e84)
						{
							Data_40002e84 = Data_400033cc.dwData;
						}
						else
						{
							Data_40002e84 += 800;
						}
						Data_400033cc.dwData = Data_40002e84;
						break;
						
					#if 0
					default:
						//->738c
						break;
					#endif
				}
			}
			//7390
			uart1_write_byte(0x55);
			uart1_write_byte(0xaa);
			uart1_write_byte(0x01);
			uart1_write_byte(1 + 2 + 3);
			uart1_write_byte(0x22); //Send DEC?
			uart1_write_byte(Data_400033cc.bData[1]);
			uart1_write_byte(Data_400033cc.bData[0]);
			uart1_write_byte(Data_400033c8.bData[3]);
			uart1_write_byte(Data_400033c8.bData[2]);
			uart1_write_byte(Data_400033c8.bData[1]);
			//->757c
		} //if (bData_40002c1a == 1)
		else
		{
			//73f8
			if (Data_4000340c != 0)
			{
				switch (bData_40002e7d_RotatingSpeed)
				{
					case MENU_ROTATING_SPEED_1: //1:
						//->7444
						Data_400033cc.dwData = 5;
						break;
					
					case MENU_ROTATING_SPEED_2: //2:
						//->0x7458
						Data_400033cc.dwData = 13;
						break;
					
					case MENU_ROTATING_SPEED_8: //3:
						//->0x746c
						Data_400033cc.dwData = 50;
						break;
					
					case MENU_ROTATING_SPEED_16: //4:
						//->0x7480
						Data_400033cc.dwData = 85;
						break;
					
					case MENU_ROTATING_SPEED_64: //5:
						//->0x7494
						Data_400033cc.dwData = 150;
						break;
					
					case MENU_ROTATING_SPEED_128: //6:
						//->74a8
						Data_400033cc.dwData = 220;
						break;
					
					case MENU_ROTATING_SPEED_256: //7:
						//->0x74bc
						Data_400033cc.dwData = 500;
						break;
					
					case MENU_ROTATING_SPEED_512: //8:
						//->0x74d0
						Data_400033cc.dwData = 800;
						break;
					
					case MENU_ROTATING_SPEED_MAX: //9:
						//->0x74e4
						Data_400033cc.dwData = 980;
						break;
					
					#if 0
					default:
						//->74f8
						break;
					#endif
				}
			}
			//74fc
			if (Data_400033cc.dwData > 980)
			{
				Data_400033cc.dwData = 980;
			}
			
			uart1_write_byte(0x55);
			uart1_write_byte(0xaa);
			uart1_write_byte(0x01);
			uart1_write_byte(0x06);
			uart1_write_byte(0x62);
			uart1_write_byte(Data_400033cc.bData[1]);
			uart1_write_byte(Data_400033cc.bData[0]);
			uart1_write_byte(Data_400033c8.bData[3]);
			uart1_write_byte(Data_400033c8.bData[2]);
			uart1_write_byte(Data_400033c8.bData[1]);
		}
		//757c
		func_659c(10);
	} //if (bData_40002e8b == 0)
}

/* 7590 - complete */
void func_7590(void)
{
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0xff);
}

/* 75c4 - todo */
void func_75c4(void)
{
	func_7590();
	
	Data_40004128.bData_357 = 1;
	bData_40003431 = 0;
	bData_40002e8c = 0;
	Data_40004128.dData_312 = 0.0;
	Data_40004128.dData_304 = 0.0;
	Data_40004128.Data_352 = 0;
	Data_40004128.dData_264 = 0.0;
	Data_40004128.dData_256 = 0.0;
	bData_40002e89 = 0;	
}

/* 7654 - todo */
double func_7654(int a, int b, double sp64, double sp88, double sp96)
{
	double sp48, sp40, sp32;
	double sp24, sp16, sp8, sp;
	
	switch (a)
	{
		case 1:
			//0x7680
			sp24 = 6.0;
			sp16 = 18.0;
			sp8 = 6.0;
			sp = 9.0;
			break;
		
		case 2:
			//0x76c4
			sp24 = 2.0;
			sp16 = 1.0;
			sp8 = 6.0;
			sp = 9.0;
			break;
		
		case 3:
			//0x7708
			break;		
		
		default:
			break;		
	}
	
	switch (b)
	{
		case 1:
			//0x7730
			sp40 = sp88 * sp24;
			if (sp96 < 0.0)
			{
				sp40 *= -1;
			}
			//7784
			if (sp40 > 10.0)
			{
				sp40 = 10.0;
			}
			//77ac
			if (sp40 < -10.0)
			{
				sp40 = -10.0;
			}
			//77d4
			sp32 = sp64;
			Data_40004128.dData_240 = sp32;
			//->78d0
			break;
		
		case 2:
			//0x77fc
			sp40 = sp88 * sp16;
			if (sp96 < 0.0)
			{
				sp40 *= -1;
			}
			//0x7850
			if (sp40 > 10.0)
			{
				sp40 = 10.0;
			}
			//7878
			if (sp40 < -10.0)
			{
				sp40 = -10.0;
			}
			//78a0
			sp32 = sp64;
			Data_40004128.dData_248 = sp32;
			//->78d0		
			break;
			
		default:
			break;
	}
	//78d0
	sp48 = sp40 + sp32;
	
	return sp48;
}

/* 7950 - todo */
void beep1(int a)
{
	bData_40002c08 = a << 5;
	bData_40002c09 = bData_40002c08 - 1;
}

/* 7978 - todo */
void func_7978(Struct_7978 sp, double* sp272, double* sp276)
{
	double sp200;
	double sp192;
	double RAD = 0.0174532922222222219854614877477; //sp184
	double sp176;
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	
	sp200 = /*360/24*/15.0 * *sp272 + 180.0;
	if (sp200 > 360.0)
	{
		sp200 -= 360.0;
	}
	
	sp200 *= RAD;
	sp192 = *sp276 * RAD;
	sp160 = sp.dData_32; //sp256;
	sp152 = sp.dData_40; //sp264;
	sp144 = sp.dData_8; //sp232;
	sp136 = sp.dData_0; //sp224;
	sp128 = sp.dData_24; //sp248;
	sp120 = sp.dData_16; //sp240;
	
	sp176 = sp160 - sp144 / cos(sp192) + 
		tan(sp192) * sp136 + 
		tan(sp192) * sp120 * sin(sp200) + 
		tan(sp192) * sp128 * cos(sp200);
	sp168 = cos(sp200) * sp120 + sp152 - sin(sp200) * sp128;
	
	*sp272 += (sp176 / 15.0);
	while (*sp272 > 24)
	{
		*sp272 -= 24;
	}

	while (*sp272 < 0)
	{
		*sp272 += 24;
	}

	*sp276 += sp168;
}

/* 7d1c - todo */
void func_7d1c(Struct_7d1c* a)
{
	unsigned int r1 = CTIME0;
	unsigned int r2 = CTIME1;
	
	a->wYear = (r2 >> 16) & 0xFFF;
	a->bMonth = (r2 >> 8) & 0x0F;
	a->bDay = r2 & 0x1F;
	a->bHours = (r1 >> 16) & 0x1F;
	a->bMinutes = (r1 >> 8) & 0x3F;
	a->bSeconds = r1 & 0x3F;
	a->wData_8 = bData_40002c06 * 10;
	
	if (bDaylightSavingTime != 0)
	{
		if (a->bHours >= 1)
		{
			a->bHours--;
		}
		else
		{
			a->bHours = 23;
			a->bDay--;
			if (a->bDay == 0)
			{
				switch (a->bMonth)
				{
					case 1: a->bDay = 31; break;
					case 2: a->bDay = 31; break;
					case 3: a->bDay = 28; break;
					case 4: a->bDay = 31; break;
					case 5: a->bDay = 30; break;
					case 6: a->bDay = 31; break;
					case 7: a->bDay = 30; break;
					case 8: a->bDay = 31; break;
					case 9: a->bDay = 31; break;
					case 10: a->bDay = 30; break;
					case 11: a->bDay = 31; break;
					case 12: a->bDay = 30; break;
					default: break;
				}
				
				a->bMonth--;
				if (a->bMonth == 0)
				{
					a->bMonth += 12;
					a->wYear--;
				}
			}
		}
	}
}

/* 7f30 - todo */
double get_local_sidereal_time(int a, int unused, double longitude/*sp192*/)
{
	double JD; //sp176;
	double T; //sp168;
	double theta0; //sp160;
	double theta; //sp152;
	Struct_7d1c sp140;
	Struct_7d1c sp128;
	Struct_7d1c sp116;
	double A; //sp104;
	double B; //sp96;
	double hours; //sp88;
	double sp80 = 3.1415927;
	
	func_7d1c(&sp140);
	
	switch (a)
	{
		case 1:
			//0x7f6c
			sp128 = sp140;
			sp116 = sp128;
			if ((sp128.bHours - Data_40004128.timeZone) < 0)
			{
				sp116.bHours = sp116.bHours - Data_40004128.timeZone + 24;
				sp116.bDay--;
				if (sp116.bDay < 1)
				{
					//7fd4
					switch (sp116.bMonth)
					{
						case 1: 
							sp116.bDay = 31;
							sp116.bMonth = 12;
							sp116.wYear--;
							break;
						case 2: 
							sp116.bDay = 31; 
							sp116.bMonth = 1;
							break;
						case 3: 
							sp116.bDay = 28; 
							sp116.bMonth = 2;
							break;
						case 4: 
							sp116.bDay = 31; 
							sp116.bMonth = 3;
							break;
						case 5: 
							sp116.bDay = 30; 
							sp116.bMonth = 4;
							break;
						case 6: 
							sp116.bDay = 31; 
							sp116.bMonth = 5;
							break;
						case 7: 
							sp116.bDay = 30; 
							sp116.bMonth = 6;
							break;
						case 8: 
							sp116.bDay = 31; 
							sp116.bMonth = 7;
							break;
						case 9: 
							sp116.bDay = 31; 
							sp116.bMonth = 8;
							//break; //Bug: Missing break!
						
						case 10: 
							sp116.bDay = 30; 
							sp116.bMonth = 9;
							break;
						case 11: 
							sp116.bDay = 31; 
							sp116.bMonth = 10;
							break;
						case 12: 
							sp116.bDay = 30; 
							sp116.bMonth = 11;
							break;
						default: /*->8148*/ break;
					}
					//8150 -> 83b0
				}
				//83b0
			} //if ((sp128.bHours - Data_40004128.timeZone) < 0)
			else
			{
				//8154
				if ((sp128.bHours - Data_40004128.timeZone) > 24)
				{
					sp116.bHours = sp116.bHours - Data_40004128.timeZone - 24;
					sp116.bDay++;
					switch (sp116.bMonth)
					{
						case 1:
							if (sp116.bDay > 31)
							{
								sp116.bDay = 1;
								sp116.bMonth = 2;
							}
							break;
						case 2:
							if (sp116.bDay > 28)
							{
								sp116.bDay = 1;
								sp116.bMonth = 3;
							}
							//break; //Bug: missing break!
							
						case 3:
							if (sp116.bDay > 31)
							{
								sp116.bDay = 1;
								sp116.bMonth = 4;
							}
							//break; //Bug: missing break!
							
						case 4:
							if (sp116.bDay > 30)
							{
								sp116.bDay = 1;
								sp116.bMonth = 5;
							}
							break;
						case 5:
							if (sp116.bDay > 31)
							{
								sp116.bDay = 1;
								sp116.bMonth = 6;
							}
							break;
						case 6:
							if (sp116.bDay > 30)
							{
								sp116.bDay = 1;
								sp116.bMonth = 7;
							}
							break;
						case 7:
							if (sp116.bDay > 31)
							{
								sp116.bDay = 1;
								sp116.bMonth = 8;
							}
							break;
						case 8:
							if (sp116.bDay > 31)
							{
								sp116.bDay = 1;
								sp116.bMonth = 9;
							}
							break;
						case 9:
							if (sp116.bDay > 30)
							{
								sp116.bDay = 1;
								sp116.bMonth = 10;
							}
							//break; //Bug: Missing break!
							
						case 10:
							if (sp116.bDay > 31)
							{
								sp116.bDay = 1;
								sp116.bMonth = 11;
							}
							break;
						case 11:
							if (sp116.bDay > 30)
							{
								sp116.bDay = 1;
								sp116.bMonth = 12;
							}
							break;
						case 12:
							if (sp116.bDay > 31)
							{
								sp116.bDay = 1;
								sp116.bMonth = 1;
								sp116.wYear++;
							}
							break;
						default: /*->8390*/ break;
					}
					//8398 -> 83b0
				}
				else
				{
					//839c
					sp116.bHours = sp128.bHours - Data_40004128.timeZone;
				}
			}
			//83b0 -> 83d4
			break;
		
		case 2:
			//0x83b4
			sp116 = sp140;
			break;
		
		default:
			//0x83cc
			break;
	}
	//83d4
	if (sp116.bMonth < 3)
	{
		sp116.wYear--;
		sp116.bMonth += 12;
	}
	//8404
	A = (int)(sp116.wYear * 1.0 / 100.0);
	B = 2.0 - A + (int)(A * 1.0 / 4.0);
	
	hours/*sp88*/ = (sp116.bHours + sp116.bMinutes / 60.0 + 
		sp116.bSeconds / 3600.0 + 
		sp116.wData_8 / 3600000.0) / 24.0;
	
	Data_40004128.dFractionalDay = hours/*sp88*/;
	
	JD/*sp176*/ = (int)((sp116.wYear + 4716) * 365.25) + 
		(int)((sp116.bMonth + 1) * 30.6001) + 
		sp116.bDay + hours/*sp88*/ + B - 1524.5;
		
	Data_40004128.dJulianDay = JD/*sp176*/;
	
	//http://www.geoastro.de/elevaz/basics/meeus.htm
	//-> compute sidereal time at Greenwich (according to: Jean Meeus: Astronomical Algorithms)
	T/*sp168*/ = (JD/*sp176*/ - 2451545.0) / 36525.0;
		
	theta0/*sp160*/ = 280.46061837 + 360.98564736629 * (JD - 2451545.0) + 
		0.000387993 * T*T - T*T*T / 38710000.0;	
	//883c
	while (theta0 > 360.0)
	{
		theta0 -= 360.0;
	}
	
	while (theta0 < 0.0)
	{
		theta0 += 360.0;
	}
	//888c
	JD/*sp176*/ = (int)((sp116.wYear + 4716) * 365.25) + 
		(int)((sp116.bMonth + 1) * 30.6001) + 
		sp116.bDay + B - 1524.5;
		
	T/*sp168*/ = (JD/*sp176*/ - 2451545.0) / 36525.0;
	
	dData_400034a0_SiderealTimeGreenwich0UT = 280.46061837 + 360.98564736629 * (JD - 2451545.0) + 
		0.000387993 * T*T - T*T*T / 38710000.0;
	
	while (dData_400034a0_SiderealTimeGreenwich0UT > 360.0)
	{
		dData_400034a0_SiderealTimeGreenwich0UT -= 360.0;
	}

	while (dData_400034a0_SiderealTimeGreenwich0UT < 0.0)
	{
		dData_400034a0_SiderealTimeGreenwich0UT += 360.0;
	}
	//8acc
	dData_400034a0_SiderealTimeGreenwich0UT /= 15;
	
	theta/*sp152*/ = longitude/*sp192*/ + theta0/*sp160*/;
	
	while (theta > 360.0)
	{
		theta -= 360.0;
	}
	
	while (theta < 0.0)
	{
		theta += 360.0;
	}
	
	theta /= 15.0; //conversion to hours
	
	return theta;
}

/* 8ba4 - todo */
void convert_equatorial_to_horizontal(Struct_GeographicCoordinates a/*sp176*/, 
							Struct_EquatorialCoordinates b/*sp208*/, 
							int r4, int r5, 
							Struct_HorizontalCoordinates* hor/*r6*/)
{
	double pi = 3.14159265359;
	double longitude = a.dData_0; //sp176; 
	double phi = a.dLatitude/*sp184*/; //Geographic latitude / sp152 
	double alpha =  b.dRA; //Right ascension / sp208
	double delta = b.dData_8; //Declination / sp216
	double tau; //Local hour angle / sp128
	double Theta; //Local sidereal time / sp120
	double z; //Zenith distance / sp112
	double A; //Azimuth / sp104
	double sp96;
	double sp88;
	
	Theta = get_local_sidereal_time(r4, r5, longitude);
	
	tau = Theta - alpha;
	while (tau >= 24)
	{
		tau -= 24;
	}
	
	while (tau < 0)
	{
		tau += 24;
	}
	//8cac
	tau = tau * pi * 15.0 / 180.0;	
	phi = phi * pi / 180.0;
	delta = delta * pi / 180.0;
	
	z = acos(sin(phi) * sin(delta) + cos(phi) * cos(delta) * cos(tau));
	A = acos((sin(phi) * cos(delta) * cos(tau) - cos(phi) * sin(delta)) / sin(z));
	
	if (tau > pi)
	{
		A = -1 * A;
	}
	//8f38
	sp96 = (sin(phi) * sin(z) + cos(z) * cos(A) * cos(phi)) / sin(z) * 15.04; //15.041067?
	sp88 = cos(phi) * 15.04 * sin(A);

	hor->dData_0 = A * 57.2957795130823228646477218717;
	hor->dAzimuth = A * 57.2957795130823228646477218717 + 180.0;
	hor->dData_32 = sp96;
	hor->dZenithDistance = z * 57.2957795130823228646477218717;
	hor->dAltitude = 90.0 - z * 57.2957795130823228646477218717;
	hor->dData_40 = sp88;
	hor->dData_48 = -sp88;
}

/* 9178 - todo */
void func_9178(void)
{
	Struct_GeographicCoordinates geoCoord; //sp256;
	Struct_EquatorialCoordinates equCoord; //sp224;
	Struct_HorizontalCoordinates horCoord; //sp152;
	Struct_7978 sp104;
	double sp96;
	double sp88;
	double theta; //Local sidereal time //sp80;
	double H; //Local hour angle //sp72;
	double sp64;
	double sp56;
	double sp48; 
	
	if (Data_40004128.bData_357 != 0)
	{
		if (bData_40003431 == 0)
		{
			//91a0
			/*sp256*/geoCoord.dData_0 = Data_40004128.geographicLongitude;
			/*sp264*/geoCoord.dLatitude = Data_40004128.geographicLatitude;
			Data_40004128.bData_356 = 1;
			
			switch (Data_40004128.Data_68)
			{
				case 1:
					//91e4
					Data_40004128.dData_72 += dData_40002c98;
					if (Data_40004128.dData_72 >= 24)
					{
						Data_40004128.dData_72 -= 24;
					}
					//924c
					if (Data_40004128.dData_72 < 0)
					{
						Data_40004128.dData_72 += 24;
					}
					//928c
					/*sp224*/equCoord.dRA = Data_40004128.dData_72;
					/*sp224*/equCoord.dData_8 = Data_40004128.dData_80;					
					break;
					
				default:
					break;
			}
			//92c0
			theta = get_local_sidereal_time(Data_40004128.Data_40, Data_40004128.bData_44, 
				Data_40004128.geographicLongitude);
			
			fData_400034c8 = theta;

			convert_equatorial_to_horizontal(geoCoord/*sp256*/, 
				equCoord/*sp224*/, 
				Data_40004128.Data_40, 
				Data_40004128.bData_44, 
				&horCoord/*sp152*/);
			
			//Compute the local hour angle
			H = theta - /*sp224*/equCoord.dRA;
			
			while (H >= 24)
			{
				H -= 24;
			}

			while (H < 0)
			{
				H += 24;
			}
			
			sp64 = H;
			sp56 = Data_40004128.dData_80;
			sp104.dData_32 = Data_40004380.dData_32;
			sp104.dData_40 = Data_40004380.dData_40;
			sp104.dData_8 = Data_40004380.dData_8;
			sp104.dData_0 = Data_40004380.dData_0;
			sp104.dData_24 = Data_40004380.dData_24;
			sp104.dData_16 = Data_40004380.dData_16;
			
			dData_40003458 = H;
			dData_40003460 = Data_40004128.dData_80;
			
			func_7978(sp104, &dData_40003458, &dData_40003460);
			
			sp64 = dData_40003458;
			sp56 = dData_40003460;
			
			fData_400034c0 = sp64 - H;
			fData_400034c4 = sp56 - Data_40004128.dData_80;
			
			if (bData_400034cc == 1)
			{
				//9548
				sp64 = dData_40003458 - fData_400034c0;
				sp56 = dData_40003460 - fData_400034c4;
			}
			//95a0
			Data_40004128.dData_112 = sp64 * 15.0;
			Data_40004128.dData_88 = sp64;
			Data_40004128.dData_144 = H;
			Data_40004128.dData_152 = Data_40004128.dData_80;
			
			if (bData_40002c1a == 1)
			{
				//9608
				if (/*sp264*/geoCoord.dLatitude >= 0)
				{
					//9620
					if (sp64 >= 12)
					{
						//9638
						Data_40004128.dData_112 -= 180; 
					}
					//965c
					Data_40004128.dData_112 -= 90; 
					Data_40004128.dData_120 = 90 - sp56;
					
					if (sp64 < 12)
					{
						//96b8
						Data_40004128.dData_120 = -1 * Data_40004128.dData_120;
					}
					//97b4
				} //if (/*sp264*/geoCoord.dLatitude >= 0)
				else
				{
					//96e0
					if (sp64 >= 12)
					{
						//9638
						Data_40004128.dData_112 -= 180; 
					}
					//971c
					Data_40004128.dData_112 = 90 - 1.0 * Data_40004128.dData_112;
					Data_40004128.dData_120 = -90.0 - sp56;
					
					if (sp64 < 12)
					{
						//9790
						Data_40004128.dData_120 = -1 * Data_40004128.dData_120;
					}
					//97b4
				}
				//97b4
				Data_40004128.dData_176 = 3.6;
				Data_40004128.dData_184 = 2.1;
			} //if (bData_40002c1a == 1)
			//97dc
			if (bData_40002c1a == 2)
			{
				//97ec
				if (/*sp264*/geoCoord.dLatitude >= 0)
				{
					//9804
					Data_40004128.dData_112 += 180;
					
					if (Data_40004128.dData_112 > 360)
					{
						Data_40004128.dData_112 -= 360;
					}
					//9868
					Data_40004128.dData_120 = 90 - sp56;
					//->9934
				} //if (/*sp264*/geoCoord.dLatitude >= 0)
				else
				{
					//988c
					Data_40004128.dData_112 += 180;
					
					if (Data_40004128.dData_112 > 360)
					{
						Data_40004128.dData_112 -= 360;
					}
					//98f0
					Data_40004128.dData_112 = -1 * Data_40004128.dData_112;
					Data_40004128.dData_120 = 90 + sp56;
				}
				//9934
				Data_40004128.dData_176 = 3.6;
				Data_40004128.dData_184 = 3.0;
			} //if (bData_40002c1a == 2)
			//9958
			Data_40004128.dData_128 = Data_40004128.dData_112;
			Data_40004128.dData_136 = Data_40004128.dData_120;
			Data_40004128.dData_328 = dData_400033d8;
			Data_40004128.dData_336 = -1 * dData_400033e0;
			Data_40004128.dData_160 = Data_40004128.dData_128 + Data_40004128.dData_328 + Data_40004128.dData_584;
		
			if (Data_40004128.dData_216 >= 0)
			{
				//9a68
				Data_40004128.dData_168 = Data_40004128.dData_136 + Data_40004128.dData_336 + Data_40004128.dData_592;
				//->9b78
			}
			else
			{
				//9aac
				Data_40004128.dData_168 = Data_40004128.dData_136 - Data_40004128.dData_336 - Data_40004128.dData_592;
			}
			//->9b78
		} //if (bData_40003431 == 0)
		else
		{
			//9af0
			Data_40004128.dData_112 = -180.0;
			Data_40004128.dData_120 = 90.0;
			Data_40004128.dData_128 = 0.0;
			Data_40004128.dData_136 = 0.0;
			Data_40004128.dData_160 = 0.0;
			Data_40004128.dData_168 = 0.0;
			Data_40004128.dData_176 = 3.6;
			Data_40004128.dData_184 = 3.0;
		}
		//9b78
		Data_40004128.dData_224 = Data_40004128.dData_160 - Data_40004128.dData_208;
		Data_40004128.dData_232 = Data_40004128.dData_168 - Data_40004128.dData_216;
		
		if (Data_40004128.dData_304 == 0)
		{
			if (Data_40004128.dData_256 > 400.0)
			{
				//9bf8
				Data_40004128.dData_256 = fabs(Data_40004128.dData_176) + 400;
			}
			else
			{
				//9c30
				Data_40004128.dData_256 += 10;
			}
		}
		//9c54
		if (Data_40004128.dData_312 == 0)
		{
			if (Data_40004128.dData_264 > 400.0)
			{
				//9c8c
				Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + 400;
			}
			else
			{
				//9cc4
				Data_40004128.dData_264 += 10;
			}
		}
		//9ce8
		if (fabs(Data_40004128.dData_224) > 0.11)
		{
			//9d14
			if (Data_40004128.dData_304 == 2)
			{
				Data_40004128.dData_304 = 0;
				
				if (bData_40002e7d_RotatingSpeed > MENU_ROTATING_SPEED_128/*6*/)
				{
					bData_40003498 = 1;
				}
			}
		}
		//9d60
		if (fabs(Data_40004128.dData_232) > 0.11)
		{
			if (Data_40004128.dData_312 == 2)
			{
				Data_40004128.dData_312 = 0;
				
				if (bData_40002e7d_RotatingSpeed > MENU_ROTATING_SPEED_128/*6*/)
				{
					bData_40003498 = 1;
				}
			}
		}
		//9dd8
		if ((fabs(Data_40004128.dData_224) > 10.0) ||
			(fabs(Data_40004128.dData_232) > 5.0))
		{
			//9e30
			bData_40003498 = 1;
		}
		//9e3c
		if (fabs(Data_40004128.dData_224) <= 15)
		{
			if ((Data_40004128.dData_304 == 0) || 
				(Data_40004128.dData_304 == 1))
			{
				//9ed8
				Data_40004128.dData_304 = 1;
				
				if (Data_40004128.dData_256 > 180.0)
				{
					//9f08
					Data_40004128.dData_256 -= 10.0;
					//->9f88
				}
				else
				{
					//9f30
					if (Data_40004128.dData_256 < 180.0)
					{
						//9f08
						Data_40004128.dData_256 += 10.0;
						//->9f88
					}
					else
					{
						//9f74
						Data_40004128.dData_256 = 180.0;
					}
				}
				//9f88
				if (fabs(Data_40004128.dData_224) <= 10.0)
				{
					//9fb4
					if (Data_40004128.dData_256 < 150.0)
					{
						//9fd0
						Data_40004128.dData_256 += 10;
						//->a02c
					}
					else
					{
						//9ff8
						Data_40004128.dData_256 = fabs(Data_40004128.dData_176) + 150.0;
					}
				}
				//a02c
				if (fabs(Data_40004128.dData_224) <= 5.0)
				{
					//a058
					if (Data_40004128.dData_256 < 120.0)
					{
						//a074
						Data_40004128.dData_256 += 10.0;
					}
					else
					{
						//a09c
						Data_40004128.dData_256 = fabs(Data_40004128.dData_176) + 120.0;
					}
				}
				//a0d0
				if (fabs(Data_40004128.dData_224) <= 3.0)
				{
					//a0fc
					if (Data_40004128.dData_256 < 80.0)
					{
						//a118
						Data_40004128.dData_256 += 10.0;
					}
					else
					{
						//a140
						Data_40004128.dData_256 = fabs(Data_40004128.dData_176) + 80.0;
					}					
				}
				//a174
				if (fabs(Data_40004128.dData_224) <= 1.0)
				{
					//a1a0
					Data_40004128.dData_256 = fabs(Data_40004128.dData_176) + 50.0;
				}
				//a1d4
				if (fabs(Data_40004128.dData_224) <= 0.1)
				{
					//a200
					Data_40004128.dData_256 = fabs(Data_40004128.dData_176) + 10.0;
				}
				//a234
				if (fabs(Data_40004128.dData_224) <= 0.01)
				{
					//a260
					Data_40004128.dData_304 = 2.0;
				}
				//a274
			}
			//a274
		}
		//a274
		if (fabs(Data_40004128.dData_232) <= 15.0)
		{
			//a2a0
			if ((Data_40004128.dData_312 == 0.0) ||
				(Data_40004128.dData_312 == 1.0))
			{
				//a2d8
				Data_40004128.dData_312 = 1.0;
				
				if (Data_40004128.dData_264 > 180.0)
				{
					//a308
					Data_40004128.dData_264 -= 10.0;
					//->a3c0
				}
				else
				{
					//a368
					if (Data_40004128.dData_264 < 180.0)
					{
						Data_40004128.dData_264 += 10.0;
					}
					else
					{
						//a3ac
						Data_40004128.dData_264 = 180.0;
					}
				}
				//a3c0
				if (fabs(Data_40004128.dData_232) <= 10.0)
				{
					//a3ec
					if (Data_40004128.dData_264 < 150.0)
					{
						//a408
						Data_40004128.dData_264 += 10.0;
					}
					else
					{
						//a430
						Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + 150.0;
					}
				}
				//a464
				if (fabs(Data_40004128.dData_232) <= 5.0)
				{
					//a490
					if (Data_40004128.dData_264 < 120.0)
					{
						//a4ac
						Data_40004128.dData_264 += 10.0;
					}
					else
					{
						//a4d4
						Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + 120.0;
					}
				}
				//a508
				if (fabs(Data_40004128.dData_232) <= 3.0)
				{
					//a534
					if (Data_40004128.dData_264 < 80.0)
					{
						//a550
						Data_40004128.dData_264 += 10.0;
					}
					else
					{
						//a578
						Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + 80.0;
					}
				}
				//a5ac
				if (fabs(Data_40004128.dData_232) <= 1.0)
				{
					//a5d8
					Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + 50.0;
				}
				//a60c
				if (fabs(Data_40004128.dData_232) <= 0.1)
				{
					//a638
					Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + 20.0;
				}
				//a66c
				if (fabs(Data_40004128.dData_232) <= 0.05)
				{
					//a698
					Data_40004128.dData_312 = 2.0;
				}
			}
			//a6ac
		}				
		//a6ac
		if ((Data_40004128.dData_304 == 2.0) && 
			(Data_40004128.dData_312 == 2.0))
		{
			//a6e4
			bData_40002e8c = 1;
			
			if (bData_40003498 != 0)
			{
				beep1(1);
			}
			
			bData_40003498 = 0;
			bData_40002e88 = MENU_TRACKING_MODE_TRACKING; //2;
			//->a730
		}
		else
		{
			//a724
			bData_40002e88 = MENU_TRACKING_MODE_POINTING; //1;
		}
		//a730
		if ((Data_40004128.dData_304 == 2.0) && 
			(Data_40004128.dData_312 == 2.0) &&
			(bData_40003431 != 0))
		{
			Data_40004128.bData_357 = 0;
			Data_40004128.bData_356 = 0;
			bData_40002e8c = 0;
			
			beep1(1);
			
			bData_40002e88 = 100;
		}
		//a7a4
		if (Data_40004128.dData_304 == 2.0)
		{
			//a7c0
			sp96 = func_7654(2, 1, 
				Data_40004128.dData_240, Data_40004128.dData_224, Data_40004128.dData_176);
		}
		//a804
		if (Data_40004128.dData_312 == 2.0)
		{
			//a820
			sp88 = func_7654(Data_40004128.Data_0, 2, 
				Data_40004128.dData_248, Data_40004128.dData_232, Data_40004128.dData_184);
		}
		//a864
		if (Data_40004128.dData_304 == 2.0)
		{
			if (Data_40003408 == 0)
			{
				//a890
				sp48 = 100000.0 * sp96 * sp96 * sp96 * sp96 * sp96 * sp96 - 0.05;
				
				Data_40004128.dData_256 = fabs(Data_40004128.dData_176) / 9.5 + sp48;
				//->aa9c
			}
			else
			{
				//a9ac
				sp48 = 100000.0 * sp96 * sp96 * sp96 * sp96 * sp96 * sp96 - 0.05;
				
				Data_40004128.dData_256 = fabs(Data_40004128.dData_176) / 9.5 + fabs(sp48);
			}
			//aa9c
			if (Data_40004128.dData_256 < 0)
			{
				Data_40004128.dData_256 = 0;
			}
		}
		//aacc
		if (Data_40004128.dData_312 == 2.0)
		{
			//aae8
			if (Data_4000340c == 0)
			{
				//aaf8
				Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + sp88;
				//->ab70
			}
			else
			{
				//ab2c
				Data_40004128.dData_264 = fabs(Data_40004128.dData_184) + fabs(sp88);
			}
			//ab70
			if (Data_40004128.dData_264 < 0)
			{
				Data_40004128.dData_264 = 0;
			}
		}
		//aba0
		if (/*sp176*/horCoord.dAltitude >= 0)
		{
			//abb8
			if (bData_40003431 == 0)
			{
				//abc8
				func_65d4(Data_40004128.dData_256, Data_40004128.dData_264);
				//->ac38
			}
			else
			{
				//abe4
				func_65d4(Data_40004128.dData_256, Data_40004128.dData_264);
				//->ac38
			}
		} //if (horCoord.dAltitude >= 0)
		else
		{
			//ac00: Under Horizon
			func_65d4(0.0, 0.0);
			
			Data_40004128.bData_357 = 0;
			Data_40004128.bData_356 = 0;
			Data_40004128.bData_358 = 1;
			bData_40002e88 = MENU_TRACKING_MODE_UNDER_HORIZON; //3;			
		}
		//ac38
		if (bData_40003431 == 0)
		{
			//ac48
			if ((dData_40003490 == Data_40004128.dData_216) &&
				(Data_40004128.dData_312 != 2.0))
			{
				//ac80
				func_75c4();
			}
			//ac84
			dData_40003490 = Data_40004128.dData_216;
		}
		//accc
	} //if (Data_40004128.bData_357 != 0)
	else
	{
		//ac9c
		if (Data_40004128.bData_356 != 0)
		{
			func_65d4(0.0, 0.0);
			
			Data_40004128.bData_356 = 0;
		}
	}
	//accc
}

void dummy_acd4(void)
{
}

/* acd8 - complete */
void func_acd8(void)
{
	/* empty */
}

/* acdc - todo */
void func_acdc(double sp144, double sp152, /*sp176*/double* r4, double* r5)
{
	double sp136 = 0.0174532925199444438613127772442;
	double sp128;
	double sp120;
	double sp112;
	
	if (sp144 < 0.0003)
	{
		sp144 = 0.0003;
	}
	//ad24
	if (sp152 < 0.0003)
	{
		sp152 = 0.0003;
	}
	//ad4c
	sp120 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude);
	
	sp112 = Data_40004128.geographicLatitude;
	sp144 -= 180.0;
	
	sp128 = atan(sin(sp144 * sp136) / 
		(cos(sp144 * sp136) * sin(sp112 * sp136) + tan(sp152 * sp136) * cos(sp112 * sp136)));

	sp128 = sp128 / sp136 / 15.0;
	
	if (sp152 > sp112)
	{
		if (sp128 < 0)
		{
			sp128 = 24.0 + sp128;
			//af34 -> b00c
		}
		else
		{
			//af38 -> b00c
			sp128 = sp128;
		}
	}
	else
	{
		//af3c
		if (sp128 < 0)
		{
			if (sp144 < 0)
			{
				//af6c
				sp128 += 24.0;
				//->b00c
			}
			else
			{
				//af8c
				sp128 += 12.0;
				//->b00c
			}
		}
		else
		{
			//afac
			if (sp144 < 0)
			{
				sp128 += 12.0;
				//->b00c
			}
			else
			{
				//b008
				sp128 = sp128;
			}
		}
	}
	//b00c
	*r4 = sp120 - sp128;
	
	if (*r4 > 24.0)
	{
		*r4 -= 24.0;
	}
	//b044
	if (*r4 < 0.0)
	{
		*r4 += 24.0;
	}
	//b06c
	*r5 = asin(sin(sp112 * sp136) * sin(sp152 * sp136) - cos(sp112 * sp136) * cos(sp152 * sp136) * cos(sp144 * sp136));
	*r5 /= sp136;
}

/* b1a8 - todo */
void func_b1a8(Struct_b1a8 a/*sp216*/, double *r4/*sp264*/)
{
	double sp200;
	double sp192;
	double sp184 = 0.0174532922222222219854614877477;
	double sp176;
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	
	sp200 = (r4[0] + 180.0) * sp184;
	sp192 = (90.0 - r4[1]) * sp184;
	sp160 = a.dData_32; //sp248;
	sp152 = a.dData_40; //sp256;
	sp144 = a.dData_8; //sp224;
	sp136 = a.dData_0; //sp216
	sp128 = a.dData_24; //sp240;
	sp120 = a.dData_16; //sp232;

	sp176 = sp160 - sp144 / cos(sp192) + 
		tan(sp192) * sp136 + 
		tan(sp192) * sp120 * sin(sp200) + 
		tan(sp192) * sp128 * cos(sp200);
	sp168 = cos(sp200) * sp120 + sp152 - sin(sp200) * sp128;
	
	r4[2] = r4[0] + sp176;
	r4[3] = r4[1] - sp168;
}

/* b484 - todo */
void func_b484(double* a, double* b)
{
	*a = Data_40004128.dData_128 - 0.0028; 
	*b = Data_40004128.dData_136 - 0.0028; 
}

/* b4d0 - todo */
void func_b4d0(void)
{
	Data_40004128.bData_357 = 0;
	dData_40003490 = 10000.0;
}

/* b4f0 - todo */
void func_b4f0(void)
{
	Data_40004128.bData_357 = 0;
	Data_40004128.dData_312 = 0.0;
	Data_40004128.dData_304 = 0.0;
	bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0x00);
	
	Data_40004128.Data_352 = 1;
	Data_40004128.dData_264 = 0.0;
	Data_40004128.dData_256 = 0.0;
}

/* b594 - todo */
void func_b594(void)
{
	Data_40004128.bData_357 = 1;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0xFF);
	
	Data_40004128.Data_352 = 0;
	Data_40004128.dData_264 = 0.0;
	Data_40004128.dData_256 = 0.0;
	
	bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
	bData_40003200 = 1;
	bData_40003201 = 1;
	
	Data_40004128.dData_584 = 0.0;
	Data_40004128.dData_592 = 0.0;
}

/* b64c - todo */
void func_b64c(double a, double b)
{
	Data_40004128.dData_72 = a;
	Data_40004128.dData_80 = b;
	
	bData_400034b5 = 1;
	fData_400034b8 = a;
	fData_400034bc = b;
	bData_400034b4 = 1;
	bData_40003430 = 1;
	
	Data_40004128.bData_344 = 0;
	Data_40004128.bData_345 = 0;
	Data_40004128.Data_348 = 0;
	
	dData_400033d8 = dData_40003420;
	dData_400033e0 = dData_40003428;
	bData_40003498 = 1;
	bData_400034aa = 0;
	
	func_75c4();
	
	bData_400034cc = 0;
	bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
	bData_40003200 = 1;
	bData_40003201 = 1;
	
	Data_40004128.dData_584 = 0.0;
	Data_40004128.dData_592 = 0.0;

	bData_40003210 = 0;
	bData_40003211 = 0;
}

/* b7c8 - todo */
void func_b7c8(double a, double b)
{
	Data_40004128.geographicLongitude = a;
	Data_40004128.geographicLatitude = b;
}

typedef struct
{
	double dData_0; //0
	double dData_8; //8
	double dData_16; //16
	double dData_24; //24
	double dData_32; //32 sp336;
	double dData_40; //40 sp344;
	double dData_48; //48 sp352;
	double dData_56; //56 sp360;
	double dData_64; //64 sp368;
	double dData_72; //72 sp376;
	double dData_80; //80 sp384;
	double dData_88; //88 sp392;
} Struct_b7f4_1;

/* b7f4 - todo */
void func_b7f4(Struct_b7f4_1 a/*sp336*/, Struct_b7f4* r4/*sp400*/)
{
	double sp288 = 0.0174532925200000001153544104682;
	double sp280;
	double sp272;
	double sp264;
	double sp256;
	double sp248;
	double sp240;
	double sp232;
	double sp224;
	double sp216;
	double sp208;
	double sp200;
	double sp192;
	double sp184;
	double sp176;
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	double sp80;
	double sp72;
	double sp64;
	double sp56;
	double sp48;
	
	sp280 = a.dData_32/*sp336*/ * sp288;
	sp272 = a.dData_40/*sp344*/ * sp288;
	sp264 = a.dData_64/*sp368*/ * sp288;
	sp256 = a.dData_72/*sp376*/ * sp288;
	sp248 = a.dData_48; //sp352;
	sp232 = a.dData_80; //sp384;
	sp240 = a.dData_56; //sp360;
	sp224 = a.dData_88; //sp392;
	sp216 = 1.0;	
	sp208 = sin(sp280) * sin(sp272) / cos(sp272);
	sp200 = cos(sp280) * sin(sp272) / cos(sp272);
	sp192 = 1.0;
	sp184 = sin(sp264) * sin(sp256) / cos(sp256);
	sp176 = cos(sp264) * sin(sp256) / cos(sp256);
	sp168 = 1.0;
	sp160 = cos(sp280);
	sp152 = sin(sp280) * -1.0;
	sp144 = 1.0;
	sp136 = cos(sp264);
	sp128 = sin(sp264) * -1.0;
	sp120 = sp232 - sp248;
	sp112 = sp184 - sp208;
	sp104 = sp176 - sp200;
	sp96 = sp224 - sp240;
	sp88 = sp136 - sp160;
	sp80 = sp128 - sp152;
	
	sp56 = (sp120 * sp88 - sp112 * sp96) / (sp88 * sp104 - sp80 * sp112);
	sp48 = (sp120 * sp80 - sp104 * sp96) / (sp80 * sp112 - sp88 * sp104);
	sp72 = sp248 - sp208 * sp48 - sp200 * sp56;	
	sp64 = sp240 - sp160 * sp48 - sp152 * sp56;
	
	sp56 = 0.0;
	sp48 = 0.0;
	sp72 = a.dData_80; //sp384;
	sp64 = a.dData_88; //sp392;
	r4->dData_32 = sp72;
	r4->dData_40 = sp64;
	r4->dData_24 = sp56;
	r4->dData_16 = sp48;
	r4->dData_8 = 0.0;
	r4->dData_0 = 0.0;
}

/* be8c - todo */
void func_be8c(Struct_b7f4_1 a/*sp304*/, Struct_b7f4* r4/*sp400*/)
{
	double sp288 = 0.0174532925200000001153544104682;
	double sp280;
	double sp272;
	double sp264;
	double sp256;
	double sp248;
	double sp240;
	double sp232;
	double sp224;
	double sp216;
	double sp208;
	double sp200;
	double sp192;
	double sp184;
	double sp176;
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	double sp80;
	double sp72;
	double sp64;
	double sp56;
	double sp48;
	
	sp280 = a.dData_0/*sp304*/ * sp288;
	sp272 = a.dData_8/*sp312*/ * sp288;
	sp264 = a.dData_32/*sp336*/ * sp288;
	sp256 = a.dData_40/*sp344*/ * sp288;
	sp248 = a.dData_16; //sp320;
	sp232 = a.dData_48; //sp352;
	sp240 = a.dData_24; //sp328;
	sp224 = a.dData_56; //sp360;
	sp216 = 1.0;		
	sp208 = sin(sp280) * sin(sp272) / cos(sp272);
	sp200 = cos(sp280) * sin(sp272) / cos(sp272);
	sp192 = 1.0;
	sp184 = sin(sp264) * sin(sp256) / cos(sp256);
	sp176 = cos(sp264) * sin(sp256) / cos(sp256);
	sp168 = 1.0;
	sp160 = cos(sp280);
	sp152 = sin(sp280) * -1.0;
	sp144 = 1.0;
	sp136 = cos(sp264);
	sp128 = sin(sp264) * -1.0;
	sp120 = sp232 - sp248;
	sp112 = sp184 - sp208;
	sp104 = sp176 - sp200;
	sp96 = sp224 - sp240;
	sp88 = sp136 - sp160;
	sp80 = sp128 - sp152;
	
	sp56 = (sp120 * sp88 - sp112 * sp96) / (sp88 * sp104 - sp80 * sp112);
	sp48 = (sp120 * sp80 - sp104 * sp96) / (sp80 * sp112 - sp88 * sp104);
	sp72 = sp248 - sp208 * sp48 - sp200 * sp56;	
	sp64 = sp240 - sp160 * sp48 - sp152 * sp56;
	sp56 = 0.0;
	sp48 = 0.0;
	sp72 = a.dData_80; //sp384;
	sp64 = a.dData_88; //sp392;
	r4->dData_32 = sp72;
	r4->dData_40 = sp64;
	r4->dData_24 = sp56;
	r4->dData_16 = sp48;
	r4->dData_8 = 0.0;
	r4->dData_0 = 0.0;
}

/* c510 - todo */
void func_c510(Struct_b7f4_1 a/*sp336*/, Struct_b7f4* ip/*sp96*/)
{
	ip->dData_32 = a.dData_16; //sp16
	ip->dData_40 = a.dData_24; //sp24;
	ip->dData_24 = 0.0;
	ip->dData_16 = 0.0;
	ip->dData_8 = 0.0;
	ip->dData_0 = 0.0;
}

/* c57c - todo */
void func_c57c(void)
{
	#if 0
	double sp136;
	double sp144;
	double sp152;
	double sp160;
	double sp168;
	double sp176;
	double sp184;
	double sp192;
	double sp200;
	double sp208;
	double sp216;
	double sp224;
	#else
	Struct_b7f4_1 sp136;
	#endif
	Struct_b7f4 sp88;
	
	int r4 = 0;
	
	if (Data_40004128.Data_372 < Data_40004128.Data_360)
	{
		Data_40004128.bData_344 = 0;
		Data_40004128.bData_345 = 0;
		Data_40004128.Data_348 = 0;
		
		switch (Data_40004128.Data_372)
		{
			case 0:
				//c5d8
				Data_40004128.dData_72 = Data_40004128.dData_376;
				Data_40004128.dData_80 = Data_40004128.dData_384;
				break;
			
			case 1:
				//c60c
				Data_40004128.dData_72 = Data_40004128.dData_392;
				Data_40004128.dData_80 = Data_40004128.dData_400;
				break;
			
			case 2:
				//c640
				Data_40004128.dData_72 = Data_40004128.dData_408;
				Data_40004128.dData_80 = Data_40004128.dData_416;
				break;
			
			default:
				break;
		}
		//c678
		//c680 -> c8e8
	}
	else
	{
		//c684
		r4 = Data_40004128.Data_360;
		
		sp136.dData_0 /*sp136*/ = Data_40004128.dData_424;
		sp136.dData_8 /*sp144*/ = Data_40004128.dData_432;
		sp136.dData_16 /*sp152*/ = Data_40004128.dData_440;
		sp136.dData_24 /*sp160*/ = Data_40004128.dData_448;
		sp136.dData_32 /*sp168*/ = Data_40004128.dData_456;
		sp136.dData_40 /*sp176*/ = Data_40004128.dData_464;
		sp136.dData_48 /*sp184*/ = Data_40004128.dData_472;
		sp136.dData_56 /*sp192*/ = Data_40004128.dData_480;
		sp136.dData_64 /*sp200*/ = Data_40004128.dData_488;
		sp136.dData_72 /*sp208*/ = Data_40004128.dData_496;
		sp136.dData_80 /*sp216*/ = Data_40004128.dData_504;
		sp136.dData_88 /*sp224*/ = Data_40004128.dData_512;
		
		switch (r4)
		{
			case 1:
				//c798
				func_c510(sp136, &sp88);
				break;
			
			case 2:
				//c7c4
				func_be8c(sp136, &sp88);
				break;
			
			case 3:
				//c7f0
				func_b7f4(sp136, &sp88);
				break;
			
			default:
				break;
		}
		//c81c
		//c828
		Data_40004380.dData_32 = sp88.dData_32; //sp120
		Data_40004380.dData_40 = sp88.dData_40; //sp128
		Data_40004380.dData_8 = sp88.dData_8; //sp96
		Data_40004380.dData_0 = sp88.dData_0; //sp88
		Data_40004380.dData_24 = sp88.dData_24; //sp112
		Data_40004380.dData_16 = sp88.dData_16; //sp104
		
		Data_40004128.bData_364 = 1;
		
		dData_400033d8 = 0.0;
		dData_400033e0 = 0.0;
		dData_40003420 = 0.0;
		dData_40003428 = 0.0;
		
		bData_40003200 = 1;
		bData_40003201 = 1;
	}
}

/* c8f4 - todo */
void func_c8f4(void)
{
	if ((Data_40004128.bData_364 == 0) &&
		(Data_40004128.dData_304 == 2.0) &&
		(Data_40004128.dData_312 == 2.0))
	{
		//c940
		Data_40004128.Data_372++;
		
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			//c964
			switch (Data_40004128.Data_372)
			{
				case 1:
					//0xc988
					Data_40004128.dData_424 = 180.0 + Data_40004128.dData_112;
					Data_40004128.dData_432 = 90.0 - Data_40004128.dData_120;
					Data_40004128.dData_440 = Data_40004128.dData_328;
					Data_40004128.dData_448 = -1.0 * Data_40004128.dData_336; 
					//->0xcb2c
					break;
				
				case 2:
					//0xca14
					Data_40004128.dData_456 = 180.0 + Data_40004128.dData_112;
					Data_40004128.dData_464 = 90.0 - Data_40004128.dData_120;
					Data_40004128.dData_472 = Data_40004128.dData_328;
					Data_40004128.dData_480 = -1.0 * Data_40004128.dData_336;
					//->0xcb2c
					break;
				
				case 3:
					//0xca9c
					Data_40004128.dData_488 = 180.0 + Data_40004128.dData_112;
					Data_40004128.dData_496 = 90.0 - Data_40004128.dData_120;
					Data_40004128.dData_504 = Data_40004128.dData_328;
					Data_40004128.dData_512 = -1.0 * Data_40004128.dData_336;
					//->0xcb2c
					break;
				
				default:
					//0xcb24
					break;
			}
			//->0xcdc8
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0xcb30
			switch (Data_40004128.Data_372)
			{
				case 1:
					//0xcb54
					Data_40004128.dData_424 = 180.0 + 15.0 * Data_40004128.dData_88;
					if (Data_40004128.dData_424 > 360.0)
					{
						Data_40004128.dData_424 -= 360.0;
					}					
					Data_40004128.dData_432 = Data_40004128.dData_80;
					Data_40004128.dData_440 = Data_40004128.dData_328;
					Data_40004128.dData_448 = -1.0 * Data_40004128.dData_336;
					//->0xcdc4
					break;
				
				case 2:
					//0xcc20
					Data_40004128.dData_456 = 180.0 + 15.0 * Data_40004128.dData_88;
					if (Data_40004128.dData_456 > 360.0)
					{
						Data_40004128.dData_456 -= 360.0;
					}					
					Data_40004128.dData_464 = Data_40004128.dData_80;
					Data_40004128.dData_472 = Data_40004128.dData_328;
					Data_40004128.dData_480 = -1.0 * Data_40004128.dData_336;
					//->0xcdc4
					break;
				
				case 3:
					//0xccec
					Data_40004128.dData_488 = 180.0 + 15.0 * Data_40004128.dData_88;
					if (Data_40004128.dData_488 > 360.0)
					{
						Data_40004128.dData_488 -= 360.0;
					}					
					Data_40004128.dData_496 = Data_40004128.dData_80;
					Data_40004128.dData_504 = Data_40004128.dData_328;
//					Data_40004128.dData_512 = -1.0 * Data_40004128.dData_336;
					//->0xcdc4
					break;
				
				default:
					//0xcdbc
					break;
			}
		}
	}
}

void fill_cdc4(int a, int b, int c)
{
	a = b;
	b = c;
}

/* cdd0 - todo */
void func_cdd0(void)
{
	unsigned char strStarNames[28][10];
	unsigned char sp16[28][22];
	
	Data_40004128.Data_360 = 2;
	Data_40004128.bData_364 = 0;
	Data_40004128.Data_372 = 0;

	bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(
		get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), 
		Data_40004128.geographicLatitude, Data_40004a68_CurrentAlignStarEquatorialCoord, strStarNames, sp16);
	
	#if 0
	Data_40004128.dData_376 = Data_40004a68_CurrentAlignStarEquatorialCoord[0][0];
	Data_40004128.dData_384 = Data_40004a68_CurrentAlignStarEquatorialCoord[0][1];
	Data_40004128.dData_392 = Data_40004a68_CurrentAlignStarEquatorialCoord[1][0];
	Data_40004128.dData_400 = Data_40004a68_CurrentAlignStarEquatorialCoord[1][1];
	#else
	Data_40004128.dData_376 = Data_40004a68_CurrentAlignStarEquatorialCoord[0];
	Data_40004128.dData_384 = Data_40004a68_CurrentAlignStarEquatorialCoord[1];
	Data_40004128.dData_392 = Data_40004a68_CurrentAlignStarEquatorialCoord[2];
	Data_40004128.dData_400 = Data_40004a68_CurrentAlignStarEquatorialCoord[3];
	#endif
	
	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;

	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;
	
	func_75c4();
}

/* cf8c - todo */
void func_cf8c(void)
{
	Data_40004128.Data_360 = 1;
	Data_40004128.bData_364 = 0;
	Data_40004128.Data_372 = 0;
	
	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;
	
	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;
	
	func_75c4();
}

/* d07c - todo */
void func_d07c(void)
{
	Data_40004128.Data_360 = 2;
	Data_40004128.bData_364 = 0;
	Data_40004128.Data_372 = 0;
	
	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;
	
	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;
	
	func_75c4();
}

/* d16c - todo */
void func_d16c(void)
{
	Data_40004128.Data_360 = 3;
	Data_40004128.bData_364 = 0;
	Data_40004128.Data_372 = 0;
	
	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_40003410 = 0.0;
	dData_40003418 = 0.0;
	
	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_16 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;

	dData_400034e0 = dData_400034e8;
	dData_400034f0 = dData_400034f8;
	
	func_75c4();
}

typedef struct
{
	double fill_0[13]; 
} Struct_d2bc;

/* d2bc - todo */
void func_d2bc(Struct_d2bc a, int b)
{
}

/* d2cc - todo */
void func_d2cc(void)
{
	Data_40004128.Data_0 = 1;
	Data_40004128.Data_40 = 1;
	Data_40004128.bData_44 = 0;
	
	Data_40004128.dData_8 = 0.22701751051996060803972454778;
	Data_40004128.dData_16 = 0.165215023456907555976513890528;
	Data_40004128.dData_24 = 0.000330464898018532459832846681635;
	Data_40004128.dData_32 = 0.000240500240500240509066917637959;
	Data_40004128.geographicLongitude = 102.7944;
	Data_40004128.geographicLatitude = 25.027777;

	Data_40004128.timeZone = 8;
	Data_40004128.Data_68 = 1;
	
	Data_40004128.dData_72 = 4.4993833;
	Data_40004128.dData_80 = -26.4534166669999990517680998892;
	
	Data_40004128.dData_240 = 0.0;
	Data_40004128.dData_248 = 0.0;
	
	Data_40004128.dData_272 = 500.0;
	Data_40004128.dData_280 = 160.0;
	Data_40004128.dData_288 = 100.0;
	Data_40004128.dData_296 = 50.0;
	Data_40004128.dData_304 = 0.0;
	Data_40004128.dData_312 = 0.0;
	
	Data_40004128.bData_356 = 0;
	Data_40004128.bData_357 = 0;
	Data_40004128.bData_358 = 0;
	Data_40004128.bData_344 = 0;
	Data_40004128.bData_345 = 0;
	Data_40004128.Data_348 = 0;
	Data_40004128.Data_352 = 0;
	Data_40004128.Data_360 = 0;
	Data_40004128.bData_364 = 1;
	Data_40004128.bData_365 = 0;
	Data_40004128.Data_368 = 0;
	Data_40004128.Data_372 = 0;
	
	Data_40004128.dData_376 = 12.0;
	Data_40004128.dData_384 = -16.0;
	Data_40004128.dData_392 = 10.0;
	Data_40004128.dData_400 = 0.0;
	Data_40004128.dData_408 = 16.0;
	Data_40004128.dData_416 = 10.0;
	Data_40004128.dData_520 = 0.0;
	Data_40004128.dData_528 = 0.0;
	Data_40004128.dData_536 = 0.0;
	Data_40004128.dData_544 = 0.0;
	Data_40004128.dData_552 = 10.0;
	Data_40004128.dData_560 = 0.0;
	Data_40004128.dData_568 = 0.0;
	Data_40004128.dData_576 = 0.0;
	Data_40004128.dData_144 = 0.0;
	Data_40004128.dData_152 = 0.0;
	
	bData_400034a9 = 0;
	
	Data_40004380.dData_32 = 0.0;
	Data_40004380.dData_40 = 0.0;
	Data_40004380.dData_8 = 0.0;
	Data_40004380.dData_0 = 0.0;
	Data_40004380.dData_24 = 0.0;
	Data_40004380.dData_16 = 0.0;
	
	bData_400034b5 = 0;
	
	dData_400033d8 = 0.0;
	dData_400033e0 = 0.0;
	dData_400033e8 = 0.0;
	dData_400033f0 = 0.0;
	
	dData_40003420 = 0.0;
	dData_40003428 = 0.0;
	
	bData_400034cd = 0;
	bData_400034b4 = 0;
	bData_40003430 = 0;
	
	Data_40004128.dData_584 = 0.0;
	Data_40004128.dData_592 = 0.0;
	
	Data_40003488 = 0;
	Data_4000348c = 0;
}

/* d784 - todo */
void func_d784(int a)
{
	bData_40002c08 = a << 1;
	bData_40002c09 = bData_40002c08 - 1;
}

/* d7ac - todo */
double get_object_visibility_time(int a, 
	double rightAscension, double declination, 
	double geoLongitude, double geoLatitude, int timeZone)
{
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	
	rightAscension *= 15.0;
	
	sp136 = 0.00273043357646934187199505572607;
	sp128 = 0.00273790925583078815358506474809;
	
	sp120 = fabs(acos((cos(1.58068652588952995863280648337) - 
		sin(geoLatitude * 0.0174532925199399994997673246644) * 
		sin(declination * 0.0174532925199399994997673246644)) / 
		(cos(geoLatitude * 0.0174532925199399994997673246644) * 
		cos(declination * 0.0174532925199399994997673246644)))) * 3.81971863420548984890956489835;
	
	if (a == 1)
	{
		//d930: Rise
		sp152 = rightAscension / 15.0 - sp120;
	}
	//0xd960
	if (a == 2)
	{
		//d968: Transit
		sp152 = rightAscension / 15.0;
	}
	//0xd984
	if (a == 3)
	{
		//d98c: Set
		sp152 = rightAscension / 15.0 + sp120;
	}
	//0xd9bc
	sp144 = dData_400034a0_SiderealTimeGreenwich0UT - geoLongitude / 15.0 * sp128;
	//->0xda24
	while ((sp152 - sp144) < 0.0)
	{
		//da08
		sp152 += 24.0;
	}
	//->0xda74
	while ((sp152 - sp144) > 24.0)
	{
		//da58
		sp152 -= 24.0;
	}
	//daa4
	sp160 = (sp152 - sp144) * (1.0 - sp136);	
	sp168 = Data_40004128.timeZone - geoLongitude / 15.0 + sp160;
	//->dbb8
	while (sp168 <= 0.0)
	{
		//db9c
		sp168 += 24.0;
	}
	//->0xdbf0
	while (sp168 >= 24.0)
	{
		//dbd4
		sp168 -= 24.0;
	}
	
	return sp168;
}

/* dc1c - todo */
void func_dc1c(void)
{
}

/* dc20 - todo */
void lcd_display_lunar_phase(unsigned char row, unsigned char col, unsigned char idx)
{
	int i;
	char bitmap[8][32] = 
	{
		{
		0xe0, 0x18, 0x04, 0x02, 0x00, 0x01, 0x01, 0x01, 
		0x01, 0x01, 0x01, 0x00, 0x02, 0x04, 0x18, 0xe0, 
		0x07, 0x18, 0x20, 0x40, 0x00, 0x80, 0x80, 0x80, 
		0x80, 0x80, 0x80, 0x00, 0x40, 0x20, 0x18, 0x07,
		},
		{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 
		0x03, 0x07, 0x1f, 0xfe, 0xfe, 0xfc, 0xf8, 0xe0, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
		0xc0, 0xe0, 0xf8, 0x7f, 0x7f, 0x3f, 0x1f, 0x07,
		},
		{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xe0, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x07, 
		},
		{
		0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xfe, 0xff, 
		0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xe0, 
		0x00, 0x00, 0x00, 0x03, 0x0f, 0x3f, 0x7f, 0xff, 
		0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x07, 
		},
		{
		0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xfc, 0xe0, 
		0x07, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
		0xff, 0xff, 0xff, 0x7f, 0x7f, 0x3f, 0x1f, 0x07, 
		},
		{
		0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 
		0xff, 0xfe, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 
		0x07, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
		0xff, 0x7f, 0x3f, 0x0f, 0x03, 0x00, 0x00, 0x00, 
		},
		{
		0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0xff, 0xff, 0xff, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x07, 0x1f, 0x3f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		},
		{
		0xe0, 0xf8, 0xfc, 0xfe, 0xfe, 0x1f, 0x07, 0x03, 
		0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		0x07, 0x1f, 0x3f, 0x7f, 0x7f, 0xf8, 0xe0, 0xc0, 
		0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
		}
	};
	
	lcd_write_command(((col - 1) * 6 + 2) & 0x0F);
	lcd_write_command(((((col - 1) * 6 + 2) & 0xF0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
	lcd_write_command(((row - 1) & 0x0F) | ST7565_CMD_SET_PAGE);
	
	for (i = 0; i < 16; i++)
	{
		lcd_write_data(bitmap[idx][i]);
	}
	
	lcd_write_command(((col - 1) * 6 + 2) & 0x0F);
	lcd_write_command(((((col - 1) * 6 + 2) & 0xF0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
	lcd_write_command((row & 0x0F) | ST7565_CMD_SET_PAGE);
	
	for (i = 0; i < 16; i++)
	{
		lcd_write_data(bitmap[idx][i+16]);	
	}
}

/* dd28 - complete */
char is_leap_year(int y)
{
	if (!(y % 4) && (!(y % 400) || (y % 100)))
	{
		return 1;
	}
	
	return 0;
}

/* dd84 - complete */
int get_days_of_month(int year, int month)
{
	int days = 31;
	switch (month - 2)
	{
		case 2:
			//0xddcc
		case 4:
			//0xddd4
		case 7:
			//0xddd8
		case 9:
			//0xdddc
			days = 30;
			break;
				
		case 0:
			//0xdde4
			if (is_leap_year(year) == 1)
			{
				days = 29;
			}
			else
			{
				days = 28;
			}
			break;
	}
	
	return days;
}

/* de18 - todo */
int get_lunar_phase(int year, int month, int day)
{
	//Computes the moon phase index as a value from 0 to 7
	//See: https://github.com/sighrobot/Moon/blob/master/src/com/abe/moon/MoonPhase.java

	int phase;
	int cent; //Number of century
	int epact; //Epact (Date of Full Moon)
	int diy; //Day in the year
	int golden; //Golden number of year
	
	if ((month < 0) || (month > 12))
	{
		month = 0;
	}
	
	diy = Data_40002bc4_DayYear[month] + day;
	
	if (month > 2)
	{
		//de50
		if (!(year % 4) && (!(year % 400) || (year % 100)))
		{
			diy++;
		}
	}
	//0xde94
	cent = year / 100 + 1;
	golden = year % 19 + 1;
	
	#if 0
	X = (3 * C / 4) - 12;
	Z = ((8 * C + 5) / 25 - 5;
	E = (11 * G + 20 + Z - X) % 30;
	#else
	epact = ((8 * cent + 5) / 25 + (golden * 11 + 20) - 5 - ((cent * 3) / 4 - 12)) % 30;
	#endif

	if (epact <= 0)
	{
		epact += 30;
	}
	//0xdf18
	if (((epact == 25) && (golden > 11)) || (epact == 24))
	{
		//0xdf38
		epact++;
	}
	//0xdf44
	phase = ((11 + (epact + diy) * 6) % 177 / 22) & 0x07;
	return phase;
}

/* df84 - todo */
void lcd_display_lunar_phase_screen(int year, int month)
{
	int day;
	int phaseIndex;
	int phaseIndexPrevious = -1;
	int row = 2;
	int col = 1;
	unsigned char dayDigits[][2] = 
	{
		{'0', '1'}, 
		{'0', '2'}, 
		{'0', '3'}, 
		{'0', '4'}, 
		{'0', '5'},
		{'0', '6'}, 
		{'0', '7'}, 
		{'0', '8'}, 
		{'0', '9'}, 
		{'1', '0'},
		{'1', '1'}, 
		{'1', '2'}, 
		{'1', '3'}, 
		{'1', '4'}, 
		{'1', '5'}, 
		{'1', '6'}, 
		{'1', '7'}, 
		{'1', '8'}, 
		{'1', '9'}, 
		{'2', '0'},
		{'2', '1'}, 
		{'2', '2'}, 
		{'2', '3'}, 
		{'2', '4'}, 
		{'2', '5'},
		{'2', '6'}, 
		{'2', '7'}, 
		{'2', '8'}, 
		{'2', '9'}, 
		{'3', '0'},
		{'3', '1'}, 
	};
	unsigned char year_month[7];
	
	year_month[0] = year / 1000 + '0';
	year_month[1] = (year % 1000) / 100 + '0';
	year_month[2] = (year % 100) / 10 + '0';
	year_month[3] = (year % 100) % 10 + '0';
	year_month[4] = '-';
	year_month[5] = month / 10 + '0';
	year_month[6] = month % 10 + '0';
	
	lcd_display_string(0, 1, 8, 7, year_month);
	
	for (day = 1; day <= get_days_of_month(year, month); day++)
	{
		//0xe084
		phaseIndex = get_lunar_phase(year, month, day);
		if (phaseIndex == phaseIndexPrevious)
		{
			continue;
		}

		phaseIndexPrevious = phaseIndex;
		
		lcd_display_lunar_phase(row, col, phaseIndex);		
		lcd_display_string(0, row + 2, col, 2, dayDigits[day-1]);
		
		col += 4;
		
		if (col > 20)
		{
			col -= 20;
			row += 3;
		}
	}
}

#include "earth.c"
#include "mercury.c"
#include "venus.c"
#include "mars.c"
#include "jupiter.c"
#include "saturn.c"
#include "uranus.c"
#include "neptun.c"
#include "pluto.c"

/* 1af1c - todo */
double func_1af1c(double a)
{
	//->0x1af80
	while (1)
	{
		//0x1af24
		if (a > 360.0)
		{
			//1af38
			a -= 360.0;
		}
		else if (a < 0.0)
		{
			//1af64
			a += 360.0;
		}
		else
		{
			//0x1af7c -> 0x1af84
			break;
		}
	}
	//1af88
	return a;
}

/* 1afc0 - complete */
void transform_ecliptical_to_equatorial_coordinates(double Lambda, double Beta, double Epsilon, double* pAlpha, double* pDelta)
{
	double Pi = 3.1415927;
	double Alpha;
	double Delta;
	int r6;
	
	Lambda = Lambda * Pi / 180.0;
	Beta = Beta * Pi / 180.0;
	Epsilon = Epsilon * Pi / 180.0;
	
	Alpha = atan((sin(Lambda) * cos(Epsilon) - (tan(Beta) * sin(Epsilon))) / cos(Lambda));
	
	Alpha = Alpha * 180.0 / Pi;

	Delta = asin(sin(Beta) * cos(Epsilon) + cos(Beta) * sin(Epsilon) * sin(Lambda));
	
	Delta = Delta * 180.0 / Pi;
	Lambda = Lambda * 180.0 / Pi;
	
	if ((Lambda > 0.0) && (Lambda <= 90.0))
	{
		//1b2b4
		r6 = 1;
	}
	//0x1b2b8
	if ((Lambda > 90.0) && (Lambda <= 180.0))
	{
		//1b2e8
		r6 = 2;
	}
	//0x1b2ec
	if ((Lambda > 180.0) && (Lambda <= 270.0))
	{
		//1b31c
		r6 = 3;
	}
	//0x1b320
	if ((Lambda > 270.0) && (Lambda <= 360.0))
	{
		//1b350
		r6 = 4;
	}
	//0x1b354
	switch (r6)
	{
		case 1:
			//0x1b378
			if (Alpha < 0)
			{
				Alpha = -1.0 * Alpha;
			}
			//->0x1b4d0
			break;
		
		case 2:
			//0x1b3b4
			if (Alpha >= 0)
			{
				//1b3d0
				Alpha = 180.0 - Alpha;
			}
			else
			{
				//0x1b3f0
				Alpha = 180.0 + Alpha;
			}
			//0x1b40c -> 0x1b4d0
			break;
		
		case 3:
			//0x1b410
			if (Alpha >= 0)
			{
				//1b42c
				Alpha = 180.0 + Alpha;
			}
			else
			{
				//0x1b44c
				Alpha = 180.0 - Alpha;
			}
			//1b468 -> 0x1b4d0
			break;
		
		case 4:
			//0x1b46c
			if (Alpha >= 0)
			{
				//1b488
				Alpha = 360.0 - Alpha;
			}
			else
			{
				//0x1b4a8
				Alpha = 360.0 + Alpha;
			}
			break;
		
		default:
			//0x1b4c8
			break;
	}
	//1b4d4
	Alpha /= 15.0;
	*pAlpha = Alpha;
	*pDelta = Delta;
}

/* 1b528 - todo */
void calculate_solar_system_object_equatorial_coordinates(int a, double* pAlpha, double* pDelta)
{
	double Tau; //sp536
	double T; //sp528
	double Lrad = 0.0; /*sp520*/ //Planet's Ecliptic Longitude in Radians 
	double Brad = 0.0; /*sp512*/ //Planet's Ecliptic Latitude in Radians 
	double R = 0.0; /*sp504*/ //Planet's Radius Vector
	double L; /*sp496*/ //Planet's Ecliptic Longitude in Degrees
	double B; /*sp488*/ //Planet's Ecliptic Latitude in Degrees
	double L0rad; //sp480; //Earth Ecliptic Longitude in Radians
	double B0rad; //sp472; //Earth Ecliptic Latitude in Radians
	double R0; //sp464; //Earth Radius Vector
	double L0; //sp456; //Earth Ecliptic Longitude in Degrees
	double B0; //sp448; //Earth Ecliptic Latitude in Degrees
	double x; /*sp440*/
	double y; /*sp432*/
	double z; /*sp424*/
	double Epsilon; /*sp416*/ //Obliquity of the Ecliptic
	double Lambda = 0.0; /*sp408*/
	double Beta; ///*sp400*/
	double Alpha; //sp392; //Right Ascension
	double Delta; //sp384; //Declination
	double JD; //sp376; //Julian Day
	double sp368;
	double sp360;
	double sp352;
	double x0; //sp344;
	double y0; //sp336;
	double z0; //sp328;
	double sp320;
	double AlphaPlutoRadians; //sp312;
	double DeltaPlutoRadians; //sp304;
	double AlphaPluto; //sp296;
	double DeltaPluto; //sp288;
	double lp = 0.0; /*sp280*/ //Moon mean longitude
	double d = 0.0; /*sp272*/ //Moon mean elongation
	double m = 0.0; /*sp264*/ //Sun mean anomaly
	double mp = 0.0; /*sp256*/ //Moon mean anomaly
	double f = 0.0; /*sp248*/ //Moon arg of latitude
	double a1 = 0.0; /*sp240*/
	double a2 = 0.0; /*sp232*/
	double a3 = 0.0; /*sp224*/
	double e = 0.0; /*sp216*/
	double sl = 0.0; /*sp208*/
	double sb = 0.0; /*sp200*/
	
	/*sp192 =*/ get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude);
	
	JD/*sp376*/ = Data_40004128.dJulianDay;
	Tau = (JD - 2451545.0) / 365250.0;
	T = 10.0 * Tau;
	
	switch (a - 2)
	{
		case 0: //Mercury
			//0x1b6dc
			Lrad = mercury_ecliptic_longitude(Tau);
			Brad = mercury_ecliptic_latitude(Tau);
			R = mercury_radius_vector(Tau);
			//->0x1b8c0
			break;
		
		case 1: //Venus
			//0x1b720
			Lrad = venus_ecliptic_longitude(Tau);
			Brad = venus_ecliptic_latitude(Tau);
			R = venus_radius_vector(Tau);
			//->0x1b8c0
			break;
		
		case 2: //Mars
			//0x1b764
			Lrad = mars_ecliptic_longitude(Tau);
			Brad = mars_ecliptic_latitude(Tau);
			R = mars_radius_vector(Tau);
			//->0x1b8c0
			break;
		
		case 3: //Jupiter
			//0x1b7a8
			Lrad = jupiter_ecliptic_longitude(Tau);
			Brad = jupiter_ecliptic_latitude(Tau);
			R = jupiter_radius_vector(Tau);
			//->0x1b8c0
			break;
		
		case 4: //Saturn
			//0x1b7ec
			Lrad = saturn_ecliptic_longitude(Tau);
			Brad = saturn_ecliptic_latitude(Tau);
			R = saturn_radius_vector(Tau);
			//->0x1b8c0
			break;
		
		case 5: //Uranus
			//0x1b830
			Lrad = uranus_ecliptic_longitude(Tau);
			Brad = uranus_ecliptic_latitude(Tau);
			R = uranus_radius_vector(Tau);
			//->0x1b8c0
			break;
		
		case 6: //Neptune
			//0x1b874
			Lrad = neptune_ecliptic_longitude(Tau);
			Brad = neptune_ecliptic_latitude(Tau);
			R = neptune_radius_vector(Tau);
			//->0x1b8c0
			break;
		
		default:
			//0x1b8b8
			break;
	}
	//1b8c4: Radians to Degrees
	L = Lrad / 3.1415927 * 180.0;
	B = Brad / 3.1415927 * 180.0;
	
	L0rad/*sp480*/ = earth_heliocentric_longitude(Tau);
	B0rad/*sp472*/ = earth_heliocentric_latitude(Tau);
	R0 = earth_radius_vector(Tau);
	
	//Radians to Degrees
	L0 = L0rad/*sp480*/ * 57.295779513; 
	B0 = B0rad/*sp472*/ * 57.295779513;
	//->0x1ba40
	while (1)
	{
		//0x1b9cc
		if (L < 0.0)
		{
			L += 360.0;
			//->0x1ba40
		}
		//0x1ba04
		else if (L > 360.0)
		{
			L -= 360.0;
			//->0x1ba40
		}
		else
		{
			//0x1ba3c -> 0x1ba44
			break;
		}
	}
	//0x1ba48 -> 0x1bac0
	while (1)
	{
		//0x1ba4c
		if (L0 < 0.0)
		{
			L0 += 360.0;
			//->0x1bac0
		}
		//0x1ba84
		else if (L0 > 360.0)
		{
			L0 -= 360.0;
			//->0x1bac0
		}
		else
		{
			//0x1babc -> 0x1bac4
			break;
		}
	}
	//1bac8: get rectangular coords of planets
	x = R * cos(B / 180.0 * 3.1415927) * cos(L / 180.0 * 3.1415927) - 
		R0 * cos(B0 / 180.0 * 3.1415927) * cos(L0 / 180.0 * 3.1415927);
	//1bc2c
	y = R * cos(B / 180.0 * 3.1415927) * sin(L / 180.0 * 3.1415927) - 
		R0 * cos(B0 / 180.0 * 3.1415927) * sin(L0 / 180.0 * 3.1415927);
	//1bd90: get geocentric longitude lambda
	z = R * sin(B / 180.0 * 3.1415927) - 
		R0 * sin(B0 / 180.0 * 3.1415927);
	//1be4c
	Lambda = atan(y / x); //???
	
	if (x < 0)
	{
		//1be84
		Lambda += 3.1415927;
	}
	//0x1bea0: get geocentric latitude, beta
	Beta = atan(z / sqrt(x * x + y * y));
	//1bf20
	Lambda = Lambda / 3.1415927 * 180.0;
	//1bf54 -> 0x1bfcc
	while (1)
	{
		//0x1bf58
		if (Lambda < 0.0)
		{
			Lambda += 360.0;
			//->0x1bfcc
		}
		//0x1bf90
		else if (Lambda > 360.0)
		{
			Lambda -= 360.0;
			//->0x1bfcc
		}
		else
		{
			//0x1bfc8 -> 0x1bfd0
			break;
		}
	}
	//1bfd4
	Beta = Beta / 3.1415927 * 180.0;
	//1c008
	Epsilon = 23.4392911111111104105475533288 - 
		46.8150 * T / 3600.0 - 
		0.00059 * T * T / 3600.0 + 
		0.001813 * T * T * T / 3600.0;
	//1c120
	if (a == 1) //Sun
	{
		//1c128
		Lambda = L0 + 180.0;
		//->0x1c164
		while (Lambda >= 360.0)
		{
			//0x1c148
			Lambda -= 360.0;
		}
		//1c17c
		if (Lambda < 0)
		{
			//1c194
			Lambda += 360.0;
		}
		//0x1c1b0
		Beta = 1.0 * B0;
	}
	//0x1c1cc
	if (a == 9) //Pluto
	{
		//1c1d4
		sp368 = pluto_ecliptic_longitude(T);
		sp360 = pluto_ecliptic_latitude(T);
		sp352 = pluto_radius_vector(T);
		
		Lambda = L0;
		//->0x1c240
		while (Lambda >= 360.0)
		{
			//0x1c224
			Lambda -= 360.0;
		}
		//1c258
		if (Lambda < 0.0)
		{
			Lambda += 360.0;
		}
		//0x1c28c
		Beta = -1.0 * B0;
		
		x0 = -1.0 * R0 * cos(Beta / 180.0 * 3.1415927) * 
			cos(Lambda / 180.0 * 3.1415927);
		
		y0 = -1.0 * R0 * cos(Beta / 180.0 * 3.1415927) * 
			sin(Lambda / 180.0 * 3.1415927);

		z0 = -1.0 * R0 * sin(Beta / 180.0 * 3.1415927);
		
		x0 = 0.00000044036 * y0 + x0 - 0.000000190919 * z0;

		y0 = -0.000000479966 * x0 + 
			0.917482137087 * y0 - 
			0.3977776982902/*BUG?*/ * z0;
		
		z0 = 0.397776982902 * y0 + 0.917482137087 * z0;

		x = cos(sp368 / 180.0 * 3.1415927) * sp352 * 
			cos(sp360 / 180.0 * 3.1415927);

		y = (sin(sp368 / 180.0 * 3.1415927) * 
			cos(sp360 / 180.0 * 3.1415927) * 0.917482062 - 
			sin(sp360 / 180.0 * 3.1415927) * 0.397777156) * sp352;

		z = (sin(sp368 / 180.0 * 3.1415927) * 
			cos(sp360 / 180.0 * 3.1415927) * 0.397777156 + 
			sin(sp360 / 180.0 * 3.1415927) * 0.917482062) * sp352;

		sp320 = sqrt((x0 + x) * (x0 + x) + 
			(y0 + y) * (y0 + y) + 
			(z0 + z) * (z0 + z));

		AlphaPlutoRadians = atan((y0 + y) / (x0 + x));

		if ((x0 + x) > 0)
		{
			//1cadc
			AlphaPlutoRadians += 3.1415927;
		}
		//0x1caf8

		DeltaPlutoRadians = asin((z0 + z) / sp320);

		AlphaPluto = AlphaPlutoRadians / 3.1415927 * 180.0;

		DeltaPluto = DeltaPlutoRadians / 3.1415927 * 180.0;
		AlphaPluto += 180.0;
		
		if (AlphaPluto > 360.0)
		{
			//1cbd0
			AlphaPluto -= 360.0;
		}
		//0x1cbec
	} //if (a == 9) //Pluto
	//0x1cbec
	if (a == 10) //Moon
	{
		//See: https://github.com/openhab/openhab1-addons/blob/master/bundles/binding/org.openhab.binding.astro/src/main/java/org/openhab/binding/astro/internal/calc/MoonCalc.java
		
		//1cbf4
		lp = 218.3164591 + 481267.88134236 * T - 
			0.0013268 * T * T + T * T * T / 538841.0 - T * T * T * T / 65194000.0;
		lp = func_1af1c(lp);
		
		d = 297.8502042 + 445267.1115168 * T - 
			0.00163 * T * T + T * T * T / 545868.0 - T * T * T * T / 113065000.0;
		d = func_1af1c(d);
		
		m = 357.5291092 + 35999.0502909 * T - 
			0.0001536 * T * T + T * T * T / 24490000.0;
		m = func_1af1c(m);
		
		mp = 134.9634114 + 477198.8676313 * T - 
			0.008997 * T * T + T * T * T / 69699.0 - T * T * T * T / 14712000.0;
		mp = func_1af1c(mp);
		//1d164		
		f = 93.2720993 + 483202.0175273 * T - 
			0.0034029 * T * T - T * T * T / 3526000 + T * T * T * T / 863310000;
		f = func_1af1c(f);
		//1d2bc
		a1 = 119.75 + 131.849 * T;
		a1 = func_1af1c(a1);
		
		a2 = 53.09 + 479264.29 * T;
		a2 = func_1af1c(a2);

		a3 = 313.45 + 481266.484 * T;
		a3 = func_1af1c(a3);
		//1d394
		e = 1.0 - 0.002516 * T - 0.0000074 * T * T;
		
		sl = sin(/*0 * d*/ mp * 0.01745329252) * 6288774.0 + 
			sin((2 * d - mp) * 0.01745329252) * 1274027.0 + 
			sin(2 * d * /*0 * mp*/ 0.01745329252) * 658314.0 + 
			sin(/*0 * d*/ 2 * mp * 0.01745329252) * 213628.0;
			
		sl += sin(m * 0.01745329252) * -185116.0 - 
			sin(2 * f * 0.01745329252) * 114332.0 + 
			sin((2 * d - 2 * mp) * 0.01745329252) * 58793.0 + 
			sin((2 * d - m - mp) * 0.01745329252) * 57066.0;

		sl += sin((2 * d + mp) * 0.01745329252) * 53322.0 + 
			sin((2 * d - m) * 0.01745329252) * 45758.0 - 
			sin((m - mp) * 0.01745329252) * 40923.0 - 
			sin(d * 0.01745329252) * 34720.0;

		sl += sin((m + mp) * 0.01745329252) * -30383.0 + 
			sin((2 * d - 2 * f) * 0.01745329252) * 15327.0 - 
			sin((2 * f + mp) * 0.01745329252) * 12528.0 + 
			//sin((2 * f - mp) * 0.01745329252) * 10980.0; 
			sin((mp - 2 * f) * 0.01745329252) * 10980.0; //->BUG?

		sb = sin(f * 0.01745329252) * 5128122.0 + 
			sin((mp + f) * 0.01745329252) * 280602.0 + 
			sin((mp - f) * 0.01745329252) * 277693.0 + 
			sin((2 * d - f) * 0.01745329252) * 173237.0;

		sb += sin((2 * d - mp + f) * 0.01745329252) * 55413.0 + 
			sin((2 * d - mp - f) * 0.01745329252) * 46271.0 + 
			sin((2 * d + f) * 0.01745329252) * 32573.0 + 
			sin((2 * mp + f) * 0.01745329252) * 17198.0;

		Lambda = sl / 1000000 + lp;
		Lambda = func_1af1c(Lambda);
		
		Beta = sb / 1000000;
		Beta = func_1af1c(Beta);
	} //if (a == 10) //Moon
	//0x1e0bc
	transform_ecliptical_to_equatorial_coordinates(Lambda, Beta, Epsilon, &Alpha, &Delta);
	
	*pAlpha = Alpha;
	*pDelta = Delta;
	
	if (a == 9) //Pluto
	{
		//1e14c
		*pAlpha = AlphaPluto / 15.0;
		*pDelta = DeltaPluto;
	}
}

/* 1e17c - todo */
void get_all_solar_system_object_equatorial_coordinates(void)
{
	calculate_solar_system_object_equatorial_coordinates(1, &dData_400032b0_SunRightAscension, &dData_400032b8_SunDeclination); //Sun
	calculate_solar_system_object_equatorial_coordinates(2, &dData_400032d0, &dData_400032d8); //Mercury
	calculate_solar_system_object_equatorial_coordinates(3, &dData_400032e0, &dData_400032e8); //Venus
	calculate_solar_system_object_equatorial_coordinates(4, &dData_400032f0, &dData_400032f8); //Mars
	calculate_solar_system_object_equatorial_coordinates(5, &dData_40003300, &dData_40003308); //Jupiter
	calculate_solar_system_object_equatorial_coordinates(6, &dData_40003310, &dData_40003318); //Saturn
	calculate_solar_system_object_equatorial_coordinates(7, &dData_40003320, &dData_40003328); //Uranus
	calculate_solar_system_object_equatorial_coordinates(8, &dData_40003330, &dData_40003338); //Neptune
	calculate_solar_system_object_equatorial_coordinates(9, &dData_40003340, &dData_40003348); //Pluto
	calculate_solar_system_object_equatorial_coordinates(10, &dData_400032c0_MoonRightAscension, &dData_400032c8_MoonDeclination); //Moon
}

/* 1e228 - todo */
void func_1e228(void)
{
	if (Data_4000318c != Data_40003190)
	{
		Data_40003190 = Data_4000318c;
	}
	
	switch (Data_40002c64_MenuContextId - 500)
	{
		case 0: 
			//0x1e328: 500 = Main Screen Help Pages
			switch (bData_40002c59_MainScreenHelpPage)
			{
				case 1:
					//0x1e36c
					lcd_display_string(0, 1, 1, 21, "*Key:                  ");
					lcd_display_string(0, 3, 1, 21, "Press the key to cha- ");
					lcd_display_string(0, 5, 1, 21, "-nge LED illuminance. ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 2:
					//0x1e3e4
					lcd_display_string(0, 1, 1, 21, "Green Key:             ");
					lcd_display_string(0, 3, 1, 21, "Press the key to show ");
					lcd_display_string(0, 5, 1, 21, "and select hitoric    ");
					lcd_display_string(0, 7, 1, 21, "target quickly.       ");
					//->0x1eb90
					break;
				
				case 3:
					//0x1e580
					lcd_display_string(0, 1, 1, 21, "Red Key:               ");
					lcd_display_string(0, 3, 1, 21, "Show function menu    ");
					lcd_display_string(0, 5, 1, 21, "or Enter.             ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 4:
					//0x1e5f8
					lcd_display_string(0, 1, 1, 21, "Yellow Key:            ");
					lcd_display_string(0, 3, 1, 21, "Press the key to stop ");
					lcd_display_string(0, 5, 1, 21, "or abandon or quit.   ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 5:
					//0x1e670
					lcd_display_string(0, 1, 1, 21, "Arrow Keys:            ");
					lcd_display_string(0, 3, 1, 21, "Slew the telescope    ");
					lcd_display_string(0, 5, 1, 21, "or Scroll in menu.    ");
					lcd_display_string(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 6:
					//0x1e6e8
					lcd_display_string(0, 1, 1, 21, "Number Keys:            ");
					lcd_display_string(0, 3, 1, 21, "Press to input digits  ");
					lcd_display_string(0, 5, 1, 21, "0 to 9, input letter   ");
					lcd_display_string(0, 7, 1, 21, "or Change slew speed.  ");
					//->0x1eb90
					break;
				
				case 7:
					//0x1e89c
					lcd_display_string(0, 1, 1, 21, "Stop Key:               ");
					lcd_display_string(0, 3, 1, 21, "Press to pause when    ");
					lcd_display_string(0, 5, 1, 21, "telescope in tracking, ");
					lcd_display_string(0, 7, 1, 21, "moving or slewing.     ");
					//->0x1eb90
					break;
				
				case 8:
					//0x1e914
					lcd_display_string(0, 1, 1, 21, "Help Key:               ");
					lcd_display_string(0, 3, 1, 21, "Show help file         ");
					lcd_display_string(0, 5, 1, 21, "can be used in all     ");
					lcd_display_string(0, 7, 1, 21, "levels menu.           ");
					//->0x1eb90
					break;
				
				case 9:
					//0x1e98c
					lcd_display_string(0, 1, 1, 21, "F+(1 to 9):             ");
					lcd_display_string(0, 3, 1, 21, "Show historic target   ");
					lcd_display_string(0, 5, 1, 21, "                       ");
					lcd_display_string(0, 7, 1, 21, "                       ");
					//->0x1eb90
					break;
				
				case 10:
					//0x1eb18
					lcd_display_string(0, 1, 1, 21, "F+0                     ");
					lcd_display_string(0, 3, 1, 21, "Open or close key      ");
					lcd_display_string(0, 5, 1, 21, "beep                   ");
					lcd_display_string(0, 7, 1, 21, "                       ");
					//->0x1eb90
					break;
				#if 0
				default:
					//0x1eb90
					break;
				#endif
			}
			//->0x20a50
			break;
		
		case 1:
			//0x1eb98: 501 = Telescope Align
			lcd_display_string(0, 1, 1, 21, "Telescope align:      ");
			lcd_display_string(0, 3, 1, 21, "Align Telescop point ");
			lcd_display_string(0, 5, 1, 21, "Pole-axis aim and    ");
			lcd_display_string(0, 7, 1, 21, "correct Backlash.    ");
			//->0x20a50
			break;
		
		case 2:
			//0x1ec10
			lcd_display_string(0, 1, 1, 21, "Target navigation:    ");
			lcd_display_string(0, 3, 1, 21, "Select Target from   ");
			lcd_display_string(0, 5, 1, 21, "database or input    ");
			lcd_display_string(0, 7, 1, 21, "data.                ");
			//->0x20a50
			break;
		
		case 3:
			//0x1ed94
			lcd_display_string(0, 1, 1, 21, "Utilities Commands:   ");
			lcd_display_string(0, 3, 1, 21, "Some tools in common ");
			lcd_display_string(0, 5, 1, 21, "use.                 ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 4:
			//0x1ee0c
			lcd_display_string(0, 1, 1, 21, "Parameter Setup:      ");
			lcd_display_string(0, 3, 1, 21, "Setup some parameter ");
			lcd_display_string(0, 5, 1, 21, "in system.           ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 5:
			//0x1ee84
			lcd_display_string(0, 1, 1, 21, "One star align:       ");
			lcd_display_string(0, 3, 1, 21, "Select one star align");
			lcd_display_string(0, 5, 1, 21, "the telescope point  ");
			lcd_display_string(0, 7, 1, 21, "by hand.             ");
			//->0x20a50
			break;
		
		case 6:
			//0x1f004
			lcd_display_string(0, 1, 1, 21, "Two stars align:      ");
			lcd_display_string(0, 3, 1, 21, "Select two star align");
			lcd_display_string(0, 5, 1, 21, "the telescope point  ");
			lcd_display_string(0, 7, 1, 21, "by hand.             ");
			//->0x20a50
			break;
		
		case 7:
			//0x1f07c
			lcd_display_string(0, 1, 1, 21, "Three star align:      ");
			lcd_display_string(0, 3, 1, 21, "Select three stars    ");
			lcd_display_string(0, 5, 1, 21, "align the telescope   ");
			lcd_display_string(0, 7, 1, 21, "point by hand.        ");
			//->0x20a50
			break;
		
		case 8:
			//0x1f0f4
			lcd_display_string(0, 1, 1, 21, "Target Sync:           ");
			lcd_display_string(0, 3, 1, 21, "Synchronizing the     ");
			lcd_display_string(0, 5, 1, 21, "target parameter with ");
			lcd_display_string(0, 7, 1, 21, "thetelescope point.   ");
			//->0x20a50
			break;
		
		case 9:
			//0x1f16c
			lcd_display_string(0, 1, 1, 21, "Pole-Axis Deviation:     ");
			lcd_display_string(0, 3, 1, 21, "Show the Pole-Axis      ");
			lcd_display_string(0, 5, 1, 21, "practice Deviation      ");
			lcd_display_string(0, 7, 1, 21, "through the align.      ");
			//->0x20a50
			break;
		
		case 10:
			//0x1f344
			lcd_display_string(0, 1, 1, 21, "RA Bklash Correction:     ");
			lcd_display_string(0, 3, 1, 21, "Correct the backlash     ");
			lcd_display_string(0, 5, 1, 21, "in RA motor gear.        ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 11:
			//0x1f3bc
			lcd_display_string(0, 1, 1, 21, "DEC Bklash Correction:    ");
			lcd_display_string(0, 3, 1, 21, "Correct the backlash     ");
			lcd_display_string(0, 5, 1, 21, "in DED motor gear.       ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 16:
			//0x1f434
			lcd_display_string(0, 1, 1, 21, "Solar System:            ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto      ");
			lcd_display_string(0, 5, 1, 21, "point at Planet, Sun,   ");
			lcd_display_string(0, 7, 1, 21, "Moon.                   ");
			//->0x20a50
			break;
		
		case 17:
			//0x1f5c4
			lcd_display_string(0, 1, 1, 21, "Constellation:         ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto     ");
			lcd_display_string(0, 5, 1, 21, "point at Constell-     ");
			lcd_display_string(0, 7, 1, 21, "ation.                  ");
			//->0x20a50
			break;
		
		case 18:
			//0x1f63c
			lcd_display_string(0, 1, 1, 21, "Famous Star:           ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all famous   ");
			lcd_display_string(0, 7, 1, 21, "stars.                ");
			//->0x20a50
			break;
		
		case 19:
			//0x1f6b4
			lcd_display_string(0, 1, 1, 21, "Messier Catalogue:     ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars in ");
			lcd_display_string(0, 7, 1, 21, "Messier Catalogue.    ");
			//->0x20a50
			break;
		
		case 20:
			//0x1f838
			lcd_display_string(0, 1, 1, 21, "NGC Deep Sky:           ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in NGC deep sky.      ");
			//->0x20a50
			break;
		
		case 21:
			//0x1f8b0
			lcd_display_string(0, 1, 1, 21, "IC Deep Sky:           ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in IC deep sky.       ");
			//->0x20a50
			break;
		
		case 22:
			//0x1f928
			lcd_display_string(0, 1, 1, 21, "Sh2 Deep Sky:          ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto    ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in Sh2 Deep Sky.      ");
			//->0x20a50
			break;
		
		case 23:
			//0x1f9a0
			lcd_display_string(0, 1, 1, 21, "Bright Stars:         ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto   ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in Bright Stars.      ");
			//->0x20a50
			break;
		
		case 24:
			//0x1fa18
			lcd_display_string(0, 1, 1, 21, "SAO Star:              ");
			lcd_display_string(0, 3, 1, 21, "Telescope can auto   ");
			lcd_display_string(0, 5, 1, 21, "point at all stars    ");
			lcd_display_string(0, 7, 1, 21, "in SAO Star.         ");
			//->0x20a50
			break;
		
		case 25:
			//0x1fbb4
			lcd_display_string(0, 1, 1, 21, "User-def Object:        ");
			lcd_display_string(0, 3, 1, 21, "Input sky target        ");
			lcd_display_string(0, 5, 1, 21, "parameter and save it.  ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 26:
			//0x1fc2c
			lcd_display_string(0, 1, 1, 21, "Specify Ra Dec:           ");
			lcd_display_string(0, 3, 1, 21, "Input Target R.a and    ");
			lcd_display_string(0, 5, 1, 21, "Des ,then point to it.   ");
			lcd_display_string(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 27:
			//0x1fca4
			lcd_display_string(0, 1, 1, 21, "Landmarks:             ");
			lcd_display_string(0, 3, 1, 21, "Input land target     ");
			lcd_display_string(0, 5, 1, 21, "parameter and save it. ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 28:
			//0x1fd1c
			lcd_display_string(0, 1, 1, 21, "Current Objects:      ");
			lcd_display_string(0, 3, 1, 21, "Give planet's,solar  ");
			lcd_display_string(0, 5, 1, 21, "and lunar rise,      ");
			lcd_display_string(0, 7, 1, 21, "transit and set time. ");
			//->0x20a50
			break;
		
		case 29:
			//0x1feec
			lcd_display_string(0, 1, 1, 21, "Object Rise/Set:       ");
			lcd_display_string(0, 3, 1, 21, "calculate star rise,  ");
			lcd_display_string(0, 5, 1, 21, "transit and set time. ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 30:
			//0x1ff64
			lcd_display_string(0, 1, 1, 21, "Lunar Phase:         ");
			lcd_display_string(0, 3, 1, 21, "Show the lunar phase ");
			lcd_display_string(0, 5, 1, 21, "                     ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 31:
			//0x1ffdc
			lcd_display_string(0, 1, 1, 21, "Timer:                 ");
			lcd_display_string(0, 3, 1, 21, "Count down reminder  ");
			lcd_display_string(0, 5, 1, 21, "                      ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 32:
			//0x20054
			lcd_display_string(0, 1, 1, 21, "Alarm:                  ");
			lcd_display_string(0, 3, 1, 21, "Timeing alarm.         ");
			lcd_display_string(0, 5, 1, 21, "                       ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 33:
			//0x200cc
			lcd_display_string(0, 1, 1, 21, "Field Angle Cal:        ");
			lcd_display_string(0, 3, 1, 21, "Calculate the teles- ");
			lcd_display_string(0, 5, 1, 21, "cope's field angel.  ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 34:
			//0x2025c
			lcd_display_string(0, 1, 1, 21, "Magify Power Cal:      ");
			lcd_display_string(0, 3, 1, 21, "Calculate the teles-  ");
			lcd_display_string(0, 5, 1, 21, "cope's magify power.  ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 35:
			//0x202d4
			lcd_display_string(0, 1, 1, 21, "Illumination:          ");
			lcd_display_string(0, 3, 1, 21, "Set screen illumina-  ");
			lcd_display_string(0, 5, 1, 21, "tion.                 ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 37:
			//0x2034c
			lcd_display_string(0, 1, 1, 21, "Parkzen:               ");
			lcd_display_string(0, 3, 1, 21, "Slew telescope to     ");
			lcd_display_string(0, 5, 1, 21, "Original Position.    ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 38:
			//0x203c4
			lcd_display_string(0, 1, 1, 21, "Time and Date:         ");
			lcd_display_string(0, 3, 1, 21, "Set local time and   ");
			lcd_display_string(0, 5, 1, 21, "data for system.      ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 39:
			//0x2055c
			lcd_display_string(0, 1, 1, 21, "Daylight Saving:        ");
			lcd_display_string(0, 3, 1, 21, "Set Daylight Saving.   ");
			lcd_display_string(0, 5, 1, 21, "                       ");
			lcd_display_string(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 40:
			//0x205d4
			lcd_display_string(0, 1, 1, 21, "Site Setting:            ");
			lcd_display_string(0, 3, 1, 21, "Select local site       ");
			lcd_display_string(0, 5, 1, 21, "from database or        ");
			lcd_display_string(0, 7, 1, 21, "input data.             ");
			//->0x20a50
			break;
		
		case 41:
			//0x2064c
			lcd_display_string(0, 1, 1, 21, "Sky/ Land:             ");
			lcd_display_string(0, 3, 1, 21, "Select sky or land    ");
			lcd_display_string(0, 5, 1, 21, "mode                  ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 42:
			//0x206c4
			lcd_display_string(0, 1, 1, 21, "AZ/EQ:                 ");
			lcd_display_string(0, 3, 1, 21, "Set mount mode to be  ");
			lcd_display_string(0, 5, 1, 21, "AZ or EQ mode.        ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 43:
			//0x20870
			lcd_display_string(0, 1, 1, 21, "Telescope Zero:        ");
			lcd_display_string(0, 3, 1, 21, "Set telescope Origin- ");
			lcd_display_string(0, 5, 1, 21, "al Position.          ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 44:
			//0x208e8
			lcd_display_string(0, 1, 1, 21, "Tracking Rate:         ");
			lcd_display_string(0, 3, 1, 21, "Set telescope track   ");
			lcd_display_string(0, 5, 1, 21, "speed.                ");
			lcd_display_string(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 45:
			//0x20960
			lcd_display_string(0, 1, 1, 21, "Language:             ");
			lcd_display_string(0, 3, 1, 21, "Select the menu      ");
			lcd_display_string(0, 5, 1, 21, "language.            ");
			lcd_display_string(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 46:
			//0x209d8
			lcd_display_string(0, 1, 1, 21, "Reset:                ");
			lcd_display_string(0, 3, 1, 21, "All parameter resume ");
			lcd_display_string(0, 5, 1, 21, "to the leave factory ");
			lcd_display_string(0, 7, 1, 21, "state.               ");
			//->0x20a50
			break;
		#if 0
		default:
			//0x20a50
			break;
		#endif
	}
}

/* 20b94 - todo */
void DisplayMainScreen(void)
{
	lcd_display_string(0, 1, 1, strlen(Data_40003360), (unsigned char*)Data_40003360);
	lcd_display_string(0, 1, 14, strlen(Data_40003364), (unsigned char*)Data_40003364);
	
	if (bData_400031ea == 1)
	{
		if (bData_400031eb == 0)
		{
			//20c18
			lcd_display_string(0, 2, 1, 22, ">>>>synchronizing<<<<");
			
			bData_400031eb = 1;
		}
		else
		{
			//0x20c44
			lcd_display_string(0, 2, 1, 22, "                      ");
			
			bData_400031eb = 0;
		}
	}
	else
	{
		//0x20c70
			lcd_display_string(0, 2, 1, 22, "                      ");		
	}
	//0x20c8c
	lcd_display_string(0, 3, 1, strlen(Data_40003370), Data_40003370);
	lcd_display_string(0, 3, 6, 9, Data_40003374);
	lcd_display_string(0, 3, 16, 2, Data_40003374 + 10);
	lcd_display_string(0, 3, 19, 2, Data_40003374 + 13);
	
	lcd_display_bitmap(0, 3, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 3, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 3, 21, (unsigned char*)cBitmapSecond);
	
	if (abs(Data_40002e18_SiteLongitudeDegrees) < 100)
	{
		lcd_display_string(0, 3, 12, 1, " ");
	}
	
	if (abs(Data_40002e18_SiteLongitudeDegrees) < 10)
	{
		lcd_display_string(0, 3, 13, 1, " ");
	}
	
	if (abs(Data_40002e1c_SiteLongitudeMinutes) < 10)
	{
		lcd_display_string(0, 3, 16, 1, " ");
	}
	
	if (abs(fData_40002e20_SiteLongitudeSeconds) < 10)
	{
		lcd_display_string(0, 3, 19, 1, " ");
	}
	
	lcd_display_string(0, 4, 1, strlen(Data_40003378), Data_40003378);
	lcd_display_string(0, 4, 6, 9, Data_4000337c);
	lcd_display_string(0, 4, 16, 2, Data_4000337c + 10);
	lcd_display_string(0, 4, 19, 2, Data_4000337c + 13);
	
	lcd_display_bitmap(0, 4, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 4, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 4, 21, (unsigned char*)cBitmapSecond);
	
	if (abs(Data_40002e38_SiteLatitudeDegrees) < 100)
	{
		lcd_display_string(0, 4, 12, 1, " ");
	}
	
	if (abs(Data_40002e38_SiteLatitudeDegrees) < 10)
	{
		lcd_display_string(0, 4, 13, 1, " ");
	}
	
	if (abs(Data_40002e3c_SiteLatitudeMinutes) < 10)
	{
		lcd_display_string(0, 4, 16, 1, " ");
	}
	
	if (abs(fData_40002e40_SiteLatitudeSeconds) < 10)
	{
		lcd_display_string(0, 4, 19, 1, " ");
	}
	
	lcd_display_string(0, 5, 1, strlen(Data_40003380), Data_40003380);
	lcd_display_string(0, 5, 6, 9, Data_40003384);
	lcd_display_string(0, 5, 16, 2, Data_40003384 + 10);
	lcd_display_string(0, 5, 19, 2, Data_40003384 + 13);
	
	if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
	{
		//21138
		lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
		lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
		lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
		
		if (abs(Data_40002d20) < 100)
		{
			lcd_display_string(0, 5, 12, 1, " ");
		}
		
		if (abs(Data_40002d20) < 10)
		{
			lcd_display_string(0, 5, 13, 1, " ");
		}

		if (abs(Data_40002d24) < 10)
		{
			lcd_display_string(0, 5, 16, 1, " ");
		}
		
		if (abs(fData_40002d28) < 10)
		{
			lcd_display_string(0, 5, 19, 1, " ");
		}
	} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
	else
	{
		//0x2127c
		lcd_display_string(0, 5, 15, 1, "h");
		lcd_display_string(0, 5, 18, 1, "m");
		lcd_display_string(0, 5, 21, 1, "s");

		if (Data_40002cd8_ObjectRightAscensionHours < 100)
		{
			lcd_display_string(0, 5, 12, 1, " ");
		}
		
		if (Data_40002cd8_ObjectRightAscensionHours < 10)
		{
			lcd_display_string(0, 5, 13, 1, " ");
		}
		
		if (Data_40002cdc_ObjectRightAscensionMinutes < 10)
		{
			lcd_display_string(0, 5, 16, 1, " ");
		}
		
		if (fData_40002ce0_ObjectRightAscensionSeconds < 10)
		{
			lcd_display_string(0, 5, 19, 1, " ");
		}
	}
	//0x213c8
	lcd_display_string(0, 6, 1, strlen(Data_40003388), Data_40003388);
	lcd_display_string(0, 6, 6, 9, Data_4000338c);
	lcd_display_string(0, 6, 16, 2, Data_4000338c + 10);
	lcd_display_string(0, 6, 19, 2, Data_4000338c + 13);
	
	lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
	
	if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
	{
		//214ac
		if (abs(Data_40002d48) < 10)
		{
			lcd_display_string(0, 6, 13, 1, " ");
		}
		
		if (abs(Data_40002d4c) < 10)
		{
			lcd_display_string(0, 6, 16, 1, " ");
		}
		
		if (abs(fData_40002d50) < 10)
		{
			lcd_display_string(0, 6, 19, 1, " ");
		}
	} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
	else
	{
		//0x21574
		if (abs(Data_40002d00_ObjectDeclinationDegrees) < 10)
		{
			lcd_display_string(0, 6, 13, 1, " ");
		}
		
		if (abs(Data_40002d04_ObjectDeclinationMinutes) < 10)
		{
			lcd_display_string(0, 6, 16, 1, " ");
		}

		if (abs(fData_40002d08_ObjectDeclinationSeconds) < 10)
		{
			lcd_display_string(0, 6, 19, 1, " ");
		}
	}
	//0x21638
	lcd_display_string(0, 7, 1, strlen(Data_40003390), Data_40003390);
	lcd_display_string(0, 7, 6, 9, Data_40003394);
	lcd_display_string(0, 7, 16, 2, Data_40003394 + 10);
	lcd_display_string(0, 7, 19, 2, Data_40003394 + 13);
	
	if ((bData_400034b4 == 1) &&
		(bData_40002e88 == MENU_TRACKING_MODE_TRACKING)) //2))
	{
		//216f0
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
			lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
			lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
			
			if (abs(Data_40002d20) < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}
			
			if (abs(Data_40002d20) < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}
			
			if (abs(Data_40002d24) < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}
			
			if (abs(fData_40002d28) < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21844
			lcd_display_string(0, 7, 15, 1, "h");
			lcd_display_string(0, 7, 18, 1, "m");
			lcd_display_string(0, 7, 21, 1, "s");
			
			if (Data_40002cd8_ObjectRightAscensionHours < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}
			
			if (Data_40002cd8_ObjectRightAscensionHours < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}
			
			if (Data_40002cdc_ObjectRightAscensionMinutes < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}
						
			if (fData_40002ce0_ObjectRightAscensionSeconds < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
		}
	}
	else
	{
		//0x21950
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			//21960
			lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
			lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
			lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
			
			if (abs(Data_40002dac) < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}
			
			if (abs(Data_40002dac) < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}
			
			if (abs(Data_40002db0) < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}
			
			if (abs(fData_40002db4) < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21aec
			lcd_display_string(0, 7, 15, 1, "h");
			lcd_display_string(0, 7, 18, 1, "m");
			lcd_display_string(0, 7, 21, 1, "s");
			
			if (Data_40002d68_OTARightAscensionHours < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}
			
			if (Data_40002d68_OTARightAscensionHours < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}
			
			if (Data_40002d6c_OTARightAscensionMinutes < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}
			
			if (fData_40002d70_OTARightAscensionSeconds < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
		}
	}
	//0x21bf4
	lcd_display_string(0, 8, 1, strlen(Data_40003398), Data_40003398);
	lcd_display_string(0, 8, 6, 9, Data_4000339c);
	lcd_display_string(0, 8, 16, 2, Data_4000339c + 10);
	lcd_display_string(0, 8, 19, 2, Data_4000339c + 13);
	
	lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
	
	if ((bData_400034b4 == 1) &&
		(bData_40002e88 == MENU_TRACKING_MODE_TRACKING)) //2))
	{
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			if (abs(Data_40002d48) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002d4c) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002d50) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21dc0
			if (abs(Data_40002d00_ObjectDeclinationDegrees) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002d04_ObjectDeclinationMinutes) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002d08_ObjectDeclinationSeconds) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
		}
	}
	else
	{
		//0x21e88
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			if (abs(Data_40002de0) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002de4) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002de8) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21f60
			if (abs(Data_40002d8c_OTADeclinationDegrees) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002d90_OTADeclinationMinutes) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002d94_OTADeclinationSeconds) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
		}	
	}
}

char Data_40000380[10] = "         "; //40000380, size???
char Data_4000038a[10] = "         "; //4000038a, size???
char Data_40000394[10] = "         "; //40000394, size???
char Data_4000039e[10] = "         "; //4000039e, size???
char Data_400003a8[10] = "         "; //400003a8, size???
char Data_400003b2[8] = "       "; //400003b2, size???
char Data_400003ba[8] = "       "; //400003ba, size???
char Data_400003c2[8] = "       "; //400003c2, size???
char Data_400003ca[10] = "         "; //400003ca, size???
char Data_400003d4[10] = "         "; //400003d4, size???

/* 22060 - todo */
void get_solar_system_object_data(int a, float* pRightAscension, float* pDeclination)
{
	switch (a)
	{
		case 0:
			//0x220a4
			*pRightAscension = dData_400032d0;
			*pDeclination = dData_400032d8;
			Data_4000314c_SolarSystemObjectName = "Mercury                ";
			Data_40003140 = Data_40000380;
			//->0x22450
			break;
		
		case 1:
			//0x220e4
			*pRightAscension = dData_400032e0;
			*pDeclination = dData_400032e8;
			Data_4000314c_SolarSystemObjectName = "Venus                    ";
			Data_40003140 = Data_4000038a;
			//->0x22450
			break;
		
		case 2:
			//0x22124
			*pRightAscension = dData_400032f0;
			*pDeclination = dData_400032f8;
			Data_4000314c_SolarSystemObjectName = "Mars                      ";
			Data_40003140 = Data_40000394;
			//->0x22450
			break;
		
		case 3:
			//0x22164
			*pRightAscension = dData_40003300;
			*pDeclination = dData_40003308;
			Data_4000314c_SolarSystemObjectName = "Jupiter                  ";
			Data_40003140 = Data_4000039e;
			//->0x22450
			break;
		
		case 4:
			//0x221a4
			*pRightAscension = dData_40003310;
			*pDeclination = dData_40003318;
			Data_4000314c_SolarSystemObjectName = "Saturn                     ";
			Data_40003140 = Data_400003a8;
			//->0x22450
			break;
		
		case 5:
			//0x221e4
			*pRightAscension = dData_40003320;
			*pDeclination = dData_40003328;
			Data_4000314c_SolarSystemObjectName = "Uranus                      ";
			Data_40003140 = Data_400003b2;
			//->0x22450
			break;
		
		case 6:
			//0x22224
			*pRightAscension = dData_40003330;
			*pDeclination = dData_40003338;
			Data_4000314c_SolarSystemObjectName = "Neptune                       ";
			Data_40003140 = Data_400003ba;
			//->0x22450
			break;
		
		case 7:
			//0x22388
			*pRightAscension = dData_40003340;
			*pDeclination = dData_40003348;
			Data_4000314c_SolarSystemObjectName = "Pluto                      ";
			Data_40003140 = Data_400003c2;
			//->0x22450
			break;
		
		case 8:
			//0x223c8
			*pRightAscension = dData_400032b0_SunRightAscension;
			*pDeclination = dData_400032b8_SunDeclination;
			Data_4000314c_SolarSystemObjectName = "Sun                     ";
			Data_40003140 = Data_400003ca;
			//->0x22450
			break;
		
		case 9:
			//0x22408
			*pRightAscension = dData_400032c0_MoonRightAscension;
			*pDeclination = dData_400032c8_MoonDeclination;
			Data_4000314c_SolarSystemObjectName = "Moon                       ";
			Data_40003140 = Data_400003d4;
			//->0x22450
			break;
		
		default:
			//0x22448
			break;
	}
}

#include "func_23130.c"

/* 24574 - todo */
void PrepareMainScreenItems(void)
{
	dData_40002e28_SiteLongitude = Data_40004128.geographicLongitude;
	dData_40002e48_SiteLatitude = Data_40004128.geographicLatitude;
	Data_40002e54_Zone = Data_40004128.timeZone;
	
	Data_40002e18_SiteLongitudeDegrees = dData_40002e28_SiteLongitude;	
	Data_40002e1c_SiteLongitudeMinutes = (dData_40002e28_SiteLongitude - Data_40002e18_SiteLongitudeDegrees) * 60.0;
	fData_40002e20_SiteLongitudeSeconds = (dData_40002e28_SiteLongitude * 60.0 - Data_40002e18_SiteLongitudeDegrees * 60.0 - Data_40002e1c_SiteLongitudeMinutes) * 60.0;
	
	Data_40002e38_SiteLatitudeDegrees = dData_40002e48_SiteLatitude;
	Data_40002e3c_SiteLatitudeMinutes = (dData_40002e48_SiteLatitude - Data_40002e38_SiteLatitudeDegrees) * 60.0;
	fData_40002e40_SiteLatitudeSeconds = (dData_40002e48_SiteLatitude * 60.0 - Data_40002e38_SiteLatitudeDegrees * 60.0 - Data_40002e3c_SiteLatitudeMinutes) * 60.0;
	
	sprintf(Data_40003fa9, "%04d-%02d-%02d", 
		Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
	Data_40003360 = Data_40003fa9;
	
	sprintf(Data_40003fbe, "%02d:%02d:%02d", 
		bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
	Data_40003364 = Data_40003fbe;
	
	switch (bData_40002e79_SkyLandTargetSeletion)
	{
		case 0:
			//0x24950
			Data_40003370 = "Sky ";
			break;
		
		case 1:
			//0x24964
			Data_40003370 = "Land";
			break;
		
		default:
			//0x24978
			break;
	}
	//24984
	if (dData_40002e28_SiteLongitude < 0)
	{
		//2499c
		sprintf(Data_40004012, "Site:W%03d?%02d'%02d^", 
			abs(Data_40002e18_SiteLongitudeDegrees), 
			abs(Data_40002e1c_SiteLongitudeMinutes), 
			abs(fData_40002e20_SiteLongitudeSeconds) & 0xff);
	}
	else
	{
		//0x24a14
		sprintf(Data_40004012, "Site:E%03d?%02d'%02d^", 
			abs(Data_40002e18_SiteLongitudeDegrees), 
			abs(Data_40002e1c_SiteLongitudeMinutes), 
			abs(fData_40002e20_SiteLongitudeSeconds) & 0xff);
	}
	//0x24a88
	Data_40003374 = Data_40004012;
	
	switch (bData_40002e7a_MountType)
	{
		case MENU_MOUNT_TYPE_AZ: //0:
			//0x24ab0
			Data_40003378 = "AZ";
			break;
		
		case MENU_MOUNT_TYPE_EQU: //1:
			//0x24ac4
			Data_40003378 = "EQ";
			break;
		
		default:
			//0x24ad8
			break;
	}
	//0x24ae0
	if (dData_40002e48_SiteLatitude < 0)
	{
		//24afc
		sprintf(Data_4000403c, "     S%03d?%02d'%02d^", 
			abs(Data_40002e38_SiteLatitudeDegrees), 
			abs(Data_40002e3c_SiteLatitudeMinutes), 
			abs(fData_40002e40_SiteLatitudeSeconds) & 0xff);
	}
	else
	{
		//0x24b74
		sprintf(Data_4000403c, "     N%03d?%02d'%02d^", 
			abs(Data_40002e38_SiteLatitudeDegrees), 
			abs(Data_40002e3c_SiteLatitudeMinutes), 
			abs(fData_40002e40_SiteLatitudeSeconds) & 0xff);
	}
	//0x24be8
	Data_4000337c = Data_4000403c;
	
	switch (bData_40002e7b_GpsAvailable)
	{
		case 0:
			//0x24c10
			Data_40003380 = "    ";
			break;
		
		case 1:
			//0x24c24
			Data_40003380 = "GPS!";
			break;
		
		default:
			//0x24ce4
			break;
	}
	
	switch (bData_40002e7a_MountType)
	{
		case MENU_MOUNT_TYPE_AZ: //0:
			//0x24d0c
			sprintf(Data_40004066, " OBJ: %03d?%02d'%02.0f^", 
				abs(Data_40002d20), abs(Data_40002d24), fabs(fData_40002d28));
			break;
		
		case MENU_MOUNT_TYPE_EQU: //1:
			//0x24d88
			sprintf(Data_40004066, " OBJ: %03dh%02dm%02ds",
				Data_40002cd8_ObjectRightAscensionHours, 
				Data_40002cdc_ObjectRightAscensionMinutes, 
				(unsigned int)fData_40002ce0_ObjectRightAscensionSeconds & 0xFF);
			break;
		
		default:
			//0x24dc0
			break;
	}
	//24dcc
	Data_40003384 = Data_40004066;
	
	switch (bData_40002e7c_TrackingRateType)
	{
		case MENU_TRACKING_RATE_STAR_SPEED: //0:
			//0x24e04
			Data_40003388 = "Cel";
			break;
			
		case MENU_TRACKING_RATE_SOLAR_SPEED: //1:
			//0x24e18
			Data_40003388 = "Sun";
			break;
		
		case MENU_TRACKING_RATE_MOON_SPEED: //2:
			//0x24e2c
			Data_40003388 = "Lun";
			break;
		
		case 3:
			//0x24e40
			Data_40003388 = "Def";
			break;
		
		default:
			//0x24e54
			break;
	}
	//24e60
	switch (bData_40002e7a_MountType)
	{
		case MENU_MOUNT_TYPE_AZ: //0:
			//0x24e7c
			if (Data_40004128.dData_120 > 90)
			{
				//24e9c
				sprintf(Data_40004090, "      -%02d?%02d'%02d^", 
					abs(Data_40002d48), abs(Data_40002d4c), abs(fData_40002d50));
			}
			else
			{
				//0x24f10
				sprintf(Data_40004090, "      +%02d?%02d'%02d^", 
					abs(Data_40002d48), abs(Data_40002d4c), abs(fData_40002d50));
			}
			//->0x25048
			break;
		
		case MENU_MOUNT_TYPE_EQU: //1:
			//0x24f84
			if (Data_40002d44 == -1)
			{
				//24f98
				sprintf(Data_40004090, "      -%02d?%02d'%02d^",
					abs(Data_40002d00_ObjectDeclinationDegrees), 
					abs(Data_40002d04_ObjectDeclinationMinutes), 
					abs(fData_40002d08_ObjectDeclinationSeconds));
			}
			else
			{
				//0x2500c
				sprintf(Data_40004090, "      +%02d?%02d'%02d^",
					Data_40002d00_ObjectDeclinationDegrees,
					Data_40002d04_ObjectDeclinationMinutes,
					((unsigned int)fData_40002d08_ObjectDeclinationSeconds) & 0xff);
			}
			break;
		
		default:
			//0x25040
			break;
	}
	//2504c
	Data_4000338c = Data_40004090;
	//25058
	switch (bData_40002e7d_RotatingSpeed)
	{
		case MENU_ROTATING_SPEED_1: //1:
			//0x25158
			Data_40003390 = "1X   ";
			break;
		
		case MENU_ROTATING_SPEED_2: //2:
			//0x2516c
			Data_40003390 = "2X   ";
			break;
		
		case MENU_ROTATING_SPEED_8: //3:
			//0x25180
			Data_40003390 = "8X   ";
			break;
		
		case MENU_ROTATING_SPEED_16: //4:
			//0x25194
			Data_40003390 = "16X  ";
			break;
		
		case MENU_ROTATING_SPEED_64: //5:
			//0x251a8
			Data_40003390 = "64X  ";
			break;
		
		case MENU_ROTATING_SPEED_128: //6:
			//0x251bc
			Data_40003390 = "128X";
			break;
		
		case MENU_ROTATING_SPEED_256: //7:
			//0x251d0
			Data_40003390 = "256X";
			break;
		
		case MENU_ROTATING_SPEED_512: //8:
			//0x251e4
			Data_40003390 = "512X";
			break;
		
		case MENU_ROTATING_SPEED_MAX: //9:
			//0x251f8
			Data_40003390 = "Max ";
			break;
		
		default:
			//0x2520c
			break;
	}
	//25218
	switch (bData_40002e7a_MountType)
	{
		case MENU_MOUNT_TYPE_AZ: //0:
			//0x25234
			sprintf(Data_400040ba, " OTA: %03d?%02d'%02d^", 
				abs(Data_40002dac), abs(Data_40002db0), abs(fData_40002db4) & 0xff);
			break;
		
		case MENU_MOUNT_TYPE_EQU: //1:
			//0x252b0
			sprintf(Data_400040ba, " OTA: %03dh%02dm%02ds", 
				Data_40002d68_OTARightAscensionHours, 
				Data_40002d6c_OTARightAscensionMinutes, 
				abs(fData_40002d70_OTARightAscensionSeconds) & 0xff);
			break;
		
		default:
			//0x252fc
			break;
	}
	//0x25304
	Data_40003394 = Data_400040ba;
	
	switch (bData_40002e7a_MountType)
	{
		case MENU_MOUNT_TYPE_AZ: //0:
			//0x25330
			if ((fabs(Data_40004128.dData_216) > 90) ||
				(dData_40002df8 < 0))
			{
				//0x25378
				sprintf(Data_400040e4, "      -%02d?%02d'%02d^", 
					abs(Data_40002de0), abs(Data_40002de4), abs(fData_40002de8) & 0xFF);
			}
			else
			{
				//0x253f0
				sprintf(Data_400040e4, "      +%02d?%02d'%02d^", 
					abs(Data_40002de0), abs(Data_40002de4), abs(fData_40002de8) & 0xFF);
			}
			break;
		
		case MENU_MOUNT_TYPE_EQU: //1:
			//0x25518
			if (dData_40002d98 < 0)
			{
				//25534
				sprintf(Data_400040e4, "      -%02d?%02d'%02d      ",
					abs(Data_40002d8c_OTADeclinationDegrees), 
					abs(Data_40002d90_OTADeclinationMinutes), 
					abs(fData_40002d94_OTADeclinationSeconds) & 0xFF);
			}
			else
			{
				//0x255ac
				sprintf(Data_400040e4, "      +%02d?%02d'%02d      ",
					abs(Data_40002d8c_OTADeclinationDegrees), 
					abs(Data_40002d90_OTADeclinationMinutes), 
					abs(fData_40002d94_OTADeclinationSeconds) & 0xFF);
			}
			break;
		
		default:
			//0x25624
			break;
	}
	//0x2562c
	Data_4000339c = Data_400040e4;
	
	switch (bData_40002e88)
	{
		case MENU_TRACKING_MODE_STOP: //0:
			//0x25678
		case 100:
			//0x25680
			Data_40003398 = "Stop";
			break;
		
		case MENU_TRACKING_MODE_POINTING: //1:
			//0x25690
			Data_40003398 = "Poin";
			break;
		
		case MENU_TRACKING_MODE_TRACKING: //2:
			//0x256a4
			Data_40003398 = "Trac";
			break;
		
		case MENU_TRACKING_MODE_UNDER_HORIZON: //3:
			//0x256b8
			Data_40003398 = "UdHn";
			break;
		
		default:
			//0x256cc
			Data_40003398 = "Slew";
			break;
	}
	
	if ((bData_400034b4 == 1) &&
		(bData_40002e88 == MENU_TRACKING_MODE_TRACKING)) //2))
	{
		Data_40003394 = Data_40004066;
		Data_4000339c = Data_40004090;
		Data_400040ba[1] = 'O';
		Data_400040ba[2] = 'T';
		Data_400040ba[3] = 'A';
		Data_40003394 = Data_400040ba;
		Data_4000339c = Data_400040e4;
	}
}

#include "language.c"

#include "func_27844.c"

#include "func_3d72c.c"

