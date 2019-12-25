
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <LPC214x.h>
#include "my_types.h"
#include "data.h"
#include "file_79080.c"

// configuration for the Atmel AT45DB161D device
#define FLASH_PAGE_BITS 10
#define FLASH_PAGE_SIZE 528

// Dataflash commands
#define FLASH_CMD_BUF1_TO_MEM 0x83
#define FLASH_CMD_BUF1_WRITE 0x84
#define FLASH_CMD_CONT_ARRAY_READ 0xE8

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

extern void lcd_display_clear(void);
extern void lcd_display_configure(void);
extern void spi0_init(void);


int unknown_prologue(void)
{
	int a;
	int b;
	int c;
	int d;
	return a+b * b / b - b-1;
}

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
	S0SPCCR = 0x08;
	S0SPCR = 0x20;
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

	IO1CLR = (1 << 25);

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

	IO1SET = (1 << 25);
}

/* 7e8 - complete */
void func_7e8(int a, unsigned char b, unsigned char c, unsigned char d, const unsigned char* e)
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
		
		IO1CLR = (1 << 25);
		
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
		
		IO1SET = (1 << 25);
	}
	
	IO1SET = (1 << 25);
	
	return r6 + r9;
}

/* 11d8 - complete */
unsigned char func_11d8(void)
{
	if (bData_40002c00 == bData_40002c01)
	{
		return bData_40002c04;
	}
	else
	{
		return Data_40002bf8[bData_40002c00];
	}
}

/* 1210 - complete */
void func_1210(void)
{
	if (bData_40002c00 == bData_40002c01)
	{
		bData_40002c04 |= 0x80;
	}
	else
	{
		bData_40002c00 = (bData_40002c00 + 1) % 8;
	}
}

/* 1268 - complete */
void func_1268(void)
{
	unsigned char r0, r1, i, r3, ip, lr;
	unsigned int r4;
	
	r3 = 0;
	r1 = 0;
	r0 = 0;
	ip = 0;
	
	for (i = 0; i < 4; i++)
	{
		IO1SET = 0xf0000;
		IO1DIR = 0x3c00000;
		IO1DIR |= (0x80000 >> i);
		IO1CLR = 0x80000 >> i;
		
		if ((IO0PIN & 0x72400000) ^ 0x72400000)
		{
			r4 = IO0PIN;
			if ((r4 & 0x400000) == 0)
			{
				r0 = 1;
				lr = r1;
				r1 = i;
				r3++;
				ip++;
			}

			if ((r4 & 0x2000000) == 0)
			{
				r0 = 2;
				r1 = i;
				r3++;
			}

			if ((r4 & 0x10000000) == 0)
			{
				r0 = 3;
				r1 = i;
				r3++;
			}

			if ((r4 & 0x20000000) == 0)
			{
				r0 = 4;
				r1 = i;
				r3++;
			}

			if ((r4 & 0x40000000) == 0)
			{
				r0 = 5;
				r1 = i;
				r3++;
			}
		}
	}

	if (r3 == 0)
	{
		lr = 0;
	}
	else if (r3 == 1)
	{
		lr = r1 * 5 + r0;
	}
	else if ((r3 == 2) && (ip == 2))
	{
		switch (lr)
		{
			case 0:
				if (r1 == 1)
				{
					lr = 21;
				}
				else if (r1 == 3)
				{
					lr = 22;
				}
				else
				{
					lr = 0;
				}	
				break;
				
			case 1:
				if (r1 == 2)
				{
					lr = 23;
				}
				else
				{
					lr = 0;
				}
				break;
			
			case 2:
				if (r1 == 3)
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
		if ((bData_40002c04 & 0x1f) == lr)
		{
			if (bData_40002c02 > 9)
			{
				bData_40002c04 |= 0x20;
			}

			if (bData_40002c02 > 0xc0)
			{
				bData_40002c04 |= 0x40;
			}

			if (bData_40002c02 < 0xff)
			{
				bData_40002c02++;
			}
		}
		else if ((bData_40002c04 & 0x1f) >= 21)
		{
			switch (bData_40002c04 & 0x1f)
			{
				case 21:
					if ((lr == 1) || (lr == 6))
					{
						bData_40002c04 = (bData_40002c04 & 0xe0) | lr;
					}
					break;
				
				case 22:
					if ((lr == 1) || (lr == 16))
					{
						bData_40002c04 = (bData_40002c04 & 0xe0) | lr;
					}
					break;
				
				case 23:
					if ((lr == 11) || (lr == 6))
					{
						bData_40002c04 = (bData_40002c04 & 0xe0) | lr;
					}
					break;
				
				case 24:
					if ((lr == 11) || (lr == 16))
					{
						bData_40002c04 = (bData_40002c04 & 0xe0) | lr;
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
						bData_40002c04 = (bData_40002c04 & 0xe0) | lr;
				}

				if (bData_40002c03 < 0xff)
				{
					bData_40002c03++;
				}
			}
			else
			{
				bData_40002c05 = 0;
				
				switch (bData_40002c04 & 0x1f)
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
			bData_40002c04 = lr;
			bData_40002c05 = 0;
			bData_40002c03 = 0;
			bData_40002c02 = 0;
		}
	}
	else
	{
		if ((bData_40002c04 & 0x20) && ((bData_40002c04 & 0x80) == 0))
		{
			if (((bData_40002c01 + 1) % 8) != bData_40002c00)
			{
				Data_40002bf8[bData_40002c01] = bData_40002c04;
				bData_40002c01 = (bData_40002c01 + 1) % 8;
			}
		}
		
		bData_40002c04 = 0;
		bData_40002c02 = 0;
	}
}

/* 17d0 - complete */
void func_17d0(void)
{
	bData_40002c02 = 0;
	bData_40002c01 = 0;
	bData_40002c00 = 0;
	bData_40002c04 = 0;
}

/* 17f8 - complete */
#ifdef OLIMEX_LPC2148
void timer_isr(void) __attribute__ ((interrupt ("IRQ")));
void timer_isr(void)
#else
void timer_isr(void) __irq
#endif
{
	func_1268();
	
	if (bData_40002c08 == 0)
	{
		IO1SET = 0x400000;
		
		bData_40002c07 = 0;
	}
	else if (bData_40002c09 == 0)
	{
		IO1CLR = 0x400000;
		
		bData_40002c07 = 0;
	}
	else if (bData_40002c07 <= bData_40002c08)
	{
		IO1CLR = 0x400000;
		
		bData_40002c07++;
	}
	else if (bData_40002c07 <= bData_40002c09)
	{
		IO1SET = 0x400000;
		
		bData_40002c07++;
	}
	else if (bData_40002c08 >= bData_40002c09)
	{
		IO1SET = 0x400000;
		
		bData_40002c07 = 0;
		bData_40002c08 = 0;
	}
	else
	{
		bData_40002c07 = 0;
	}

	bData_40002c06++;
	
	if (Data_40003214 != 0)
	{
		bData_40003265--;
		if (bData_40003265 == 0)
		{
			bData_40003265 = 100;
			
			Data_40003214--;
			if (Data_40003214 == 0)
			{
				bData_40002c08 = 160;
				bData_40002c09 = bData_40002c08 - 1;				
			}
		}
	}

	T0IR = 1;
	VICVectAddr = 0;
}

/* 19cc - complete */
#ifdef OLIMEX_LPC2148
void rtc_isr(void) __attribute__ ((interrupt ("IRQ")));
void rtc_isr(void)
#else
void rtc_isr(void) __irq
#endif
{
	ILR = 3;
	
	bData_40002c06 = 0;
	
	VICVectAddr = 0;
}

/* 19f0 - complete */
#ifdef OLIMEX_LPC2148
void uart1_isr(void) __attribute__ ((interrupt ("IRQ")));
void uart1_isr(void)
#else
void uart1_isr(void) __irq
#endif
{
	uart1_bRxData = U1RBR;
	
	if (bData_40002c1a == 0)
	{
		bData_40002c1a = 3;
	}
	
	if (bData_40002c13_uart1ReceiveComplete == 0)
	{
		switch (bData_40002c14_uart1ReceiveStep)
		{
			case 0:
				//Check first byte of header signature
				if (bData_40002c15_uart1ReceiveHeader[0] == uart1_bRxData)
				{
					bData_40002c14_uart1ReceiveStep++;
				}
				break;
			
			case 1:
				//Check second byte of header signature
				if (bData_40002c15_uart1ReceiveHeader[1] == uart1_bRxData)
				{
					bData_40002c14_uart1ReceiveStep++;
				}
				else
				{
					bData_40002c14_uart1ReceiveStep = 0;
				}
				break;
			
			case 2:
				//Check third byte of header signature
				if (bData_40002c15_uart1ReceiveHeader[2] == uart1_bRxData)
				{
					bData_40002c14_uart1ReceiveStep++;
				}
				else
				{
					bData_40002c14_uart1ReceiveStep = 0;
				}
				break;
			
			case 3:
				//Check and store payload length information
				if (uart1_bRxData < 10)
				{
					bData_40002c15_uart1ReceiveHeader[3] = uart1_bRxData;
					bData_40002c14_uart1ReceiveStep++;
				}
				else
				{
					bData_40002c14_uart1ReceiveStep = 0;
				}
				break;
			
			case 4:
				//Store payload data
				if (bData_40002c15_uart1ReceiveHeader[3] > bData_40002c12_uart1ReceiveDataCount)
				{
					Data_40003592_uart1ReceiveDataBuffer[bData_40002c12_uart1ReceiveDataCount] = uart1_bRxData;
					bData_40002c12_uart1ReceiveDataCount++;
					if (bData_40002c12_uart1ReceiveDataCount == bData_40002c15_uart1ReceiveHeader[3])
					{
						bData_40002c13_uart1ReceiveComplete = 1;
						bData_40002c14_uart1ReceiveStep = 0;
						bData_40002c12_uart1ReceiveDataCount = 0;
						
						if (!((bData_40002c1a == 1) && (bData_40002c1a == 2)))
						{
							switch (Data_40003592_uart1ReceiveDataBuffer[0])
							{
								case 0x04:
								case 0x24:
									bData_40002c1a = 1;
									break;
								
								case 0x44:
								case 0x64:
									bData_40002c1a = 2;
									break;
								
								default:
									break;
							}
						}
					}
				}
				break;

			default:
				break;
		}
	}
	
	VICVectAddr = 0;
}

/* 1c88 - complete */
#ifdef OLIMEX_LPC2148
void uart0_isr(void) __attribute__ ((interrupt ("IRQ")));
void uart0_isr(void)
#else
void uart0_isr(void) __irq
#endif
{
	uart0_bRxData = U0RBR;
	
	if (bData_40002c0b_uart0ReceiveComplete == 0)
	{
		switch (bData_40002c0c_uart0ReceiveStep)
		{
			case 0:
				//Check first byte of header signature
				if (Data_40002c0d_uart0ReceiveHeader[0] == uart0_bRxData)
				{
					bData_40002c0c_uart0ReceiveStep++;
				}
				break;
			
			case 1:
				//Check second byte of header signature
				if (Data_40002c0d_uart0ReceiveHeader[1] == uart0_bRxData)
				{
					bData_40002c0c_uart0ReceiveStep++;
				}
				else
				{
					bData_40002c0c_uart0ReceiveStep = 0;
				}
				break;
			
			case 2:
				//Check third byte of header signature
				if (Data_40002c0d_uart0ReceiveHeader[2] == uart0_bRxData)
				{
					bData_40002c0c_uart0ReceiveStep++;
				}
				else
				{
					bData_40002c0c_uart0ReceiveStep = 0;
				}
				break;
			
			case 3:
				//Store payload length information
				if (uart0_bRxData < 10)
				{
					Data_40002c0d_uart0ReceiveHeader[3] = uart0_bRxData;
					bData_40002c0c_uart0ReceiveStep++;
				}
				else
				{
					bData_40002c0c_uart0ReceiveStep = 0;
				}
				break;
			
			case 4:
				//Store payload data
				if (Data_40002c0d_uart0ReceiveHeader[3] > bData_40002c0a_uart0ReceiveDataCount)
				{
					Data_40003588_uart0ReceiveDataBuffer[bData_40002c0a_uart0ReceiveDataCount] = uart0_bRxData;
					bData_40002c0a_uart0ReceiveDataCount++;
					if (Data_40002c0d_uart0ReceiveHeader[3] == bData_40002c0a_uart0ReceiveDataCount)
					{
						bData_40002c0b_uart0ReceiveComplete = 1;
						bData_40002c0c_uart0ReceiveStep = 0;
						bData_40002c0a_uart0ReceiveDataCount = 0;
						
						switch (Data_40003588_uart0ReceiveDataBuffer[0])
						{
							case 1:
								Data_40002c1c = -1;
								bData_40002c0b_uart0ReceiveComplete = 0;
								break;
							
							case 2:
								Data_40002c1c = 1;
								bData_40002c0b_uart0ReceiveComplete = 0;
								break;
							
							case 4:
								Data_40002c20 = -1;
								bData_40002c0b_uart0ReceiveComplete = 0;
								break;
							
							case 8:
								Data_40002c20 = 1;
								bData_40002c0b_uart0ReceiveComplete = 0;
								break;
							
							default:
								break;
						}
					}
				}
				break;
		
			default:
				break;
		}
	}
	
	VICVectAddr = 0;
}

/* 1f30 - complete */
void uart0_init(int a)
{
	U0LCR = 0x83;

#ifdef OLIMEX_LPC2148
	// 12000000 * 2/2 / (16 * 78) = 9615.38 => 9600
	U0DLM = 0;
	U0DLL = 78;
#else
	// 12000000 * 2/2 / (16 * 72) = 10416.67 => 10000?
	U0DLM = 0;
	U0DLL = 72;
#endif

	U0LCR = 0x03;
	U0FCR = 0x01; //U0IIR = 0x01;?
	U0IER = 0x01;
	VICVectAddr1 = (unsigned int) uart0_isr;
	
	bData_40002c0a_uart0ReceiveDataCount = 0;
	bData_40002c0b_uart0ReceiveComplete = 0;
	bData_40002c0c_uart0ReceiveStep = 0;
	Data_40002c0d_uart0ReceiveHeader[0] = 0x55;
	Data_40002c0d_uart0ReceiveHeader[1] = 0xaa;
	Data_40002c0d_uart0ReceiveHeader[2] = 0x01;
	Data_40002c0d_uart0ReceiveHeader[3] = 0x00; //payload length information
}

/* 1fb0 - complete */
unsigned char uart0_read_byte(void)
{
	unsigned char b;
	while (!(U0LSR & 0x01)) {}
  b = U0RBR;
	return b;
}

/* 2054 - complete */
void uart0_receive(unsigned char* a, int b)
{
	while (b)
	{
		*a++ = uart0_read_byte();
		b--;
	}
}

/* 2080 - complete */
void uart0_write_byte(unsigned char a)
{
	U0THR = a;
	while (!(U0LSR & 0x40)) {}
}

/* 20a0 - complete */
void uart0_send(unsigned char* a, unsigned char b)
{
	while (b--)
	{
		uart0_write_byte(*a++);
	}
}

/* 20d0 - complete */
void uart0_send_packets(unsigned char* a)
{
	unsigned char i;
	
	while (1)
	{
		if (*a == 0) break;
		
		for (i = 0; i < 44; i++)
		{
			uart0_write_byte(*a++);
		}
	}
}

/* 211c - complete */
void uart1_init(int a)
{
	U1LCR = 0x83;

#ifdef OLIMEX_LPC2148
	// 12000000 * 2/2 / (16 * 78) = 9615.38 => 9600
	U1DLM = 0;
	U1DLL = 78;
#else
	// 12000000 * 2/2 / (16 * 72) = 10416.67 => 10000?
	U1DLM = 0;
	U1DLL = 72;
#endif

	U1LCR = 0x03;
	U1FCR = 0x01; //
	U1IER = 0x01;
	VICVectAddr2 = (unsigned int) uart1_isr;
	
	bData_40002c12_uart1ReceiveDataCount = 0;
	bData_40002c13_uart1ReceiveComplete = 0;
	bData_40002c14_uart1ReceiveStep = 0;
	bData_40002c15_uart1ReceiveHeader[0] = 0x55;
	bData_40002c15_uart1ReceiveHeader[1] = 0xaa;
	bData_40002c15_uart1ReceiveHeader[2] = 0x01;
	bData_40002c15_uart1ReceiveHeader[3] = 0x00;
}

/* 219c - complete */
unsigned char uart1_read_byte(void)
{
	unsigned char b;
	while (!(U1LSR & 0x01)) {}
	b = U1RBR;
	return b;
}

/* 21bc - complete */
void uart1_receive(unsigned char* a, int b)
{
	while (b)
	{
		*a++ = uart1_read_byte();
		b--;
	}
}

/* 21e8 - complete */
void uart1_write_byte(unsigned char a)
{
	U1THR = a;
	while (!(U1LSR & 0x40)) {}
}

#ifdef OLIMEX_LPC2148
void uart1_send(unsigned char* a, unsigned char b)
{
	while (b--)
	{
		uart1_write_byte(*a++);
	}
}
#endif

/* 2208 - complete */
void uart1_send_packets(unsigned char* a)
{
	unsigned char i;
	
	while (1)
	{
		if (*a == 0) break;
		
		for (i = 0; i < 44; i++)
		{
			uart1_write_byte(*a++);
		}
	}
}

/* 2254 - complete */
void func_2254(unsigned int a)
{
	unsigned int b;
	for ( ; a > 1; a--)
	{	
		for (b = 0x0000ffff; b > 1; b--)
		{
		}
	}
}

/* 227c - complete */
void func_227c(void)
{
	T0PR = 0;
	T0MCR = 3;
	T0MR0 = 0x1b000;
	T0TCR = 3;
	T0TCR = 1;
	
	VICIntSelect = 0;
	VICVectCntl0 = 0x24;
	VICVectAddr0 = (unsigned int) timer_isr;
	VICIntEnable = 0x10;
	VICVectCntl3 = 0x2d;
	VICVectAddr3 = (unsigned int) rtc_isr;
	VICIntEnable = 0x2000;
	CIIR = 0x01;
	ILR = 0x03;
	CCR = 0x11;
	VICVectCntl1 = 0x26;
	VICVectCntl2 = 0x27;
	VICIntEnable = 0x80;
	VICIntEnable = 0x40;
}

/* 2328 - complete */
void lpc_hw_init(void)
{
	PLL0CON = 0x01;
	VPBDIV = 0;
	PLL0CFG = 0x23;
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	while (!(PLL0STAT & 0x400)) {}
	
	PLL0CON = 0x03;
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
		(1 <<13) | // P0.13 = Out
		(0 <<14) | // P0.14 = In
		(1 <<15) | // P0.15 = Out -> LCD D7-D0 ?
		(1 <<16) | // P0.16 = Out
		(0 <<22) | // P0.22 = In
		(0 <<25) | // P0.25 = In
		(0 <<28) | // P0.28 = In
		(0 <<29) | // P0.29 = In
		(0 <<30);  // P0.30 = In
	IO1DIR = //0x03cf0000 = 00 00 00 11 11 00 11 11 00 00 00 00 00 00 00 00
		(1 <<16) | // P1.16 = Out
		(1 <<17) | // P1.17 = Out
		(1 <<18) | // P1.18 = Out
		(1 <<19) | // P1.19 = Out
		(0 <<20) | // P1.20 = In
		(0 <<21) | // P1.21 = In
		(1 <<22) | // P1.22 = Out
		(1 <<23) | // P1.23 = Out -> LCD A0 Pin (Command/Data) ?
		(1 <<24) | // P1.24 = Out -> Chip Select for SPI Flash
		(1 <<25);  // P1.25 = Out -> Chip Select for SPI Font ROM
	IO1SET = 1 << 22; //0x00400000; P1.22 = High
	IO0SET = 1 << 13; //0x00002000; P0.13 = High
	IO0CLR = 1 << 16; //0x00010000; P0.16 = Low
	IO1SET = 1 << 24; //0x01000000; P1.24 = High
	IO1SET = 1 << 25; //0x02000000; P1.25 = High
	
	spi0_init();

#ifndef OLIMEX_LPC2148
	lcd_display_configure();
	lcd_display_clear();
	lcd_display_brightness(0x80);
	setDisplayPWM(0xff);
	
	func_17d0();
	
	bData_40002c08 = 0x10;
	bData_40002c09 = 0x10;
	bData_40002c07 = 0x00;
#endif

	func_227c();
}

/* 243c - complete */
void flash_read(unsigned int PageAdr, int b, int Count, unsigned char* Data)
{
	unsigned short i = 0;
	
	IO1CLR = (1 << 24);
	
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
	
	IO1SET = (1 << 24);
}

/* 24d4 - complete */
void flash_write(int PageAdr, unsigned short BufAdr, int Count, unsigned char* Data)
{
	unsigned short i;
	IO1CLR = (1 << 24);

	spi0_write_read_byte(FLASH_CMD_BUF1_WRITE);
	spi0_write_read_byte(0x00);
	spi0_write_read_byte(BufAdr >> 8);
	spi0_write_read_byte(BufAdr & 0xFF);
	
	for (i = 0; i < Count; i++)
	{
		spi0_write_read_byte(Data[i]);
	}
	
	IO1SET = (1 << 24);
	IO1CLR = (1 << 24);
	
	if (PageAdr < 0x1000)
	{
		spi0_write_read_byte(FLASH_CMD_BUF1_TO_MEM);
		spi0_write_read_byte(PageAdr >> (16 - FLASH_PAGE_BITS));
		spi0_write_read_byte(PageAdr << (FLASH_PAGE_BITS - 8));
		spi0_write_read_byte(0);
	}
	
	IO1SET = (1 << 24);
	
	func_2254(5);
}

/* 258c - complete */
void func_258c(int a, unsigned char* b)
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
void func_260c(int a, unsigned char* b)
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
void func_268c(unsigned char a, unsigned int b)
{
	unsigned char r6;
	unsigned int r7;
	unsigned char buf[57];

	flash_read((0x37 << 6) | 7, 0, sizeof(buf), buf);

	r6 = buf[1];
	r7 = ((buf[2] - '0') * 100000) + 
		(((buf[3] - '0') * 10000)) + 
		(((buf[4] - '0') * 1000)) +
		(((buf[5] - '0') * 100)) +
		(((buf[6] - '0') * 10)) +
		(buf[7] - '0');

	if ((a == r6) && (r7 == b))
	{
		r6 = 0;
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
		buf[1] = a;
		flash_write((0x37 << 6) | 7, 1, sizeof(buf[1]), &buf[1]);
		sprintf(buf, "%06d", b);
		flash_write((0x37 << 6) | 7, 2, 6, &buf[0]);
	}
}

/* 27c4 - complete */
void func_27c4(float* a, float* b)
{
	unsigned char buf[5];

	flash_read((0x37 << 6) | 9, 0, sizeof(buf), buf);

	*a = (buf[0] - '0') * 100.0 + (buf[1] - '0') * 10.0 + buf[2] - '0';
	*b = (buf[3] - '0') * 10.0 + buf[4] - '0';
}

/* 2910 - complete */
void func_2910(int a, int b)
{
	unsigned char buf[5];
	sprintf(buf, "%03d%02d", a, b);
	flash_write((0x37 << 6) | 9, 0, sizeof(buf), buf);
}

/* 29b0 - complete */
void func_29b0(unsigned char* a, unsigned char* b, unsigned char* c, unsigned char* d)
{
	flash_write(0xdca, 10, 8, a);
	flash_write(0xdca, 18, 6, b);
	flash_write(0xdca, 24, 5, c);
	flash_write(0xdca, 29, 3, d);
}

/* 2a1c - complete */
void func_2a1c(unsigned char* a, float* b, float* c, int* d)
{
	unsigned char buf[22];
	unsigned char i = 0;
	
	flash_read(0xdca, 10, sizeof(buf), buf);
	
	for (i = 0; i < 8; i++)
	{
		a[i] = buf[i];
	}
	
	*b = (buf[9] - '0') * 100.0 + (buf[10] - '0') * 10.0 + buf[11] - '0' + 
		((buf[12] - '0') * 10.0 + buf[13] - '0') / 60.0;
	
	if (buf[8] == 'W')
	{
		*b *= -1.0;
	}
	
	*c = (buf[15] - '0') * 10.0 + buf[16] - '0' +
		((buf[17] - '0') * 10.0 + buf[18] - '0') / 60.0;
	
	if (buf[14] == 'S')
	{
		*c *= -1.0;
	}
		
	*d = (buf[20] - '0') * 10.0 + buf[21] - '0';
	
	if (buf[19] == 'W')
	{
		*d *= -1.0;
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

/* 3230 - complete */
void func_3230(int a, int b, int c, int d)
{
	d = a;
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

/* 34e4 - todo */
int func_34e4(int a, Struct_34e4* b)
{
	unsigned char buf[51];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;
	
	if ((a == 0) && (a > 33))
	{
		return 0;
	}
	
	r6 = (a - 1) / 10;
	r7 = ((a - 1) % 10) * 51;

	flash_read((unsigned short)(0x00 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 10; i++)
	{
		b->bData_0[i] = buf[i];
	}
	b->bData_0[10] = 0;
	b->bData_0[11] = 0;

	for (i = 10; i < 20; i++)
	{
		b->bData_12[i-10] = buf[i];
	}
	b->bData_12[10] = 0;
	b->bData_12[11] = 0;
	
	b->Data_24 = buf[20] * 10000 + buf[21] * 100 + buf[22];

	for (i = 23; i < 35; i++)
	{
		b->bData_28[i-22] = buf[i];
	}
	b->bData_28[0] = ' ';
	b->bData_28[13] = 0;

	for (i = 35; i < 43; i++)
	{
		b->bData_42[i-35] = buf[i];
	}
	b->bData_42[8] = 0;
	b->bData_42[9] = 0;
	
	if (buf[43] >= 0x80)
	{
		b->fData_52 = 0x80 - buf[43] - buf[44] / 10.0;
	}
	else
	{
		b->fData_52 = buf[43] + buf[44] / 10.0;
	}
	
	b->fData_56 = buf[45] + buf[46] / 60.0 + buf[47] / 3600.00;
	
	if (buf[48] >= 0x80)
	{
		b->fData_60 = 0x80 - buf[48] - buf[49] / 60.0 - buf[50] / 3600.0;
	}
	else
	{
		b->fData_60 = buf[48] + buf[49] / 60.0 + buf[50] / 3600.0;
	}
	
	return 1;
}

/* 38dc - todo */
int func_38dc(int a, Struct_38dc* b)
{
	unsigned char buf[38];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;

	if ((a == 0) && (a > 33))
	{
		return 0;
	}
	
	r6 = (a - 1) / 13;
	r7 = ((a - 1) % 13) * 38;

	flash_read((unsigned short)(0x04 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 3; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[3] = ' ';
	b->bData_0[4] = 0;

	for (i = 3; i < 22; i++)
	{
		b->bData_5[i-3] = buf[i];
	}
	
	b->bData_5[19] = ' ';
	b->bData_5[20] = 0;
	
	for (i = 22; i < 30; i++)
	{
		b->bData_26[i-22] = buf[i];
	}
	
	b->bData_26[8] = 0;
	b->bData_26[9] = 0;
	
	b->fData_36 = buf[30] + buf[31] / 60.0;
	
	if (buf[32] >= 0x80)
	{
		b->fData_40 = 0x80 - buf[32] - buf[33] / 100.0;
	}
	else
	{
		b->fData_40 = buf[32] + buf[33] / 100.0;
	}
	
	b->wData_44 = buf[34] * 100 + buf[35];
	
	b->bData_46 = buf[36];
	b->bData_47 = buf[37];
	
	return 1;
}

/* 3b58 - todo */
int func_3b58(int a, Struct_3b58* b)
{
	unsigned char buf[124];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;

	if ((a == 0) && (a > 110))
	{
		return 0;
	}
	
	r6 = (a - 1) / 4;
	r7 = ((a - 1) % 4) * 124;
	
	flash_read((unsigned short)(0x0b + r6), r7, sizeof(buf), buf);

	b->wData_0 = buf[0] * 100 + buf[1];
	b->fData_4 = buf[2] + buf[3] / 60.0 + buf[4] / 3600.0;
	
	if (buf[5] >= 0x80)
	{
		b->fData_8 = 0x80 - buf[5] - buf[6] / 60.0 - buf[7] / 3600.0; 
	}
	else
	{
		b->fData_8 = buf[5] + buf[6] / 60.0 + buf[7] / 3600.0; 
	}
	
	b->fData_12 = buf[8] + buf[9] / 10.0;
	
	b->dData_16 = buf[10] * 10000.0 + buf[11] * 100.0 + buf[12] + buf[13] / 10.0;
	
	for (i = 14; i < 20; i++)
	{
		b->bData_24[i-14] = buf[i];
	}
	
	b->bData_24[6] = 0;
	b->bData_24[7] = 0;

	for (i = 20; i < 34; i++)
	{
		b->bData_32[i-20] = buf[i];
	}
	
	b->bData_32[14] = ' ';
	b->bData_32[15] = 0;

	for (i = 34; i < 44; i++)
	{
		b->bData_48[i-34] = buf[i];
	}
	
	b->bData_48[10] = 0;
	b->bData_48[11] = 0;

	for (i = 44; i < 68; i++)
	{
		b->bData_60[i-44] = buf[i];
	}
	
	b->bData_60[24] = ' ';
	b->bData_60[25] = 0;
	
	for (i = 68; i < 90; i++)
	{
		b->bData_86[i-68] = buf[i];
	}
	
	b->bData_86[22] = 0; //Bug
	b->bData_86[23] = 0; //Bug
	
	for (i = 90; i < 124; i++)
	{
		b->bData_108[i-90] = buf[i];
	}
	
	b->bData_108[34] = ' ';
	b->bData_108[35] = 0;
	
	return 1;
}

/* 4028 - todo */
int func_4028(int a, Struct_4028* b)
{
	unsigned char buf[24];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;

	if ((a == 0) && (a > 167))
	{
		return 0;
	}
	
	r6 = (a - 1) / 22;
	r7 = ((a - 1) % 22) * 24;
	
	flash_read((unsigned short)(0x27 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 16; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[16] = ' ';
	b->bData_0[17] = 0;
	
	b->fData_20 = buf[16] + buf[17] / 60.0 + buf[18] / 3600.0;
	
	if (buf[19] >= 0x80)
	{
		b->fData_24 = 0x80 - buf[19] - buf[20] / 60.0 - buf[21] / 3600.0;
	}
	else
	{
		b->fData_24 = buf[19] + buf[20] / 60.0 + buf[21] / 3600.0;
	}

	if (buf[22] >= 0x80)
	{
		b->fData_28 = 0x80 - buf[22] - buf[23] / 100.0;
	}
	else
	{
		b->fData_28 = buf[22] + buf[23] / 100.0;
	}
		
	return 1;
}

/* 435c - todo */
int func_435c(int a, Struct_435c* b)
{
	unsigned char buf[6];
	unsigned short r6;
	unsigned short r7;

	if ((a == 0) && (a > 313))
	{
		return 0;
	}
	
	r6 = (a - 1) / 88;
	r7 = ((a - 1) % 88) * 6;
	
	flash_read((unsigned short)(0x2f + r6), r7, sizeof(buf), buf);
	
	b->fData_0 = buf[0] + buf[1] / 60.0 + buf[2] / 3600.0;
	
	if (buf[3] >= 0x80)
	{
		b->fData_4 = 0x80 - buf[3] - buf[4] / 60.0 - buf[5] / 3600.0;
	}
	else
	{
		b->fData_4 = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	}

	return 1;
}

/* 4594 - todo */
int func_4594(int a, Struct_4594* b)
{
	unsigned char buf[19];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;
	
	if ((a == 0) && (a > 5386))
	{
		return 0;
	}
	
	r6 = (a - 1) / 27;
	r7 = ((a - 1) % 27) * 19;
	
	flash_read((unsigned short)(0x33 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 3; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[3] = ' ';
	b->bData_0[4] = 0;
	
	b->fData_8 = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	
	if (buf[6] >= 0x80)
	{
		b->fData_12 = 0x80 - buf[6] - buf[7] / 60.0 - buf[8] / 3600.0;
	}
	else
	{
		b->fData_12 = buf[6] + buf[7] / 60.0 + buf[8] / 3600.0;
	}
	
	b->fData_16 = buf[9] + buf[10] / 10.0;
	
	for (i = 11; i < 19; i++)
	{
		b->bData_20[i-11] = buf[i];
	}

	b->bData_0[8] = ' '; //bug!
	b->bData_0[9] = 0; //bug!

	return 1;
}

/* 4894 - todo */
int func_4894(int a, Struct_4894* b)
{
	unsigned char buf[19];
	unsigned short r6;
	unsigned short r7;
	unsigned char i;
	
	if ((a == 0) && (a > 7840))
	{
		return 0;
	}
	
	r6 = (a - 1) / 27;
	r7 = ((a - 1) % 27) * 19;
	
	flash_read((unsigned short)(0xfb + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 3; i++)
	{
		b->bData_0[i] = buf[i];
	}
	
	b->bData_0[3] = ' ';
	b->bData_0[4] = 0;
	
	b->fData_8 = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	
	if (buf[6] >= 0x80)
	{
		b->fData_12 = 0x80 - buf[6] - buf[7] / 60.0 - buf[8] / 3600.0;
	}
	else
	{
		b->fData_12 = buf[6] + buf[7] / 60.0 + buf[8] / 3600.0;
	}
	
	b->fData_16 = buf[9] + buf[10] / 10.0;
	
	for (i = 11; i < 19; i++)
	{
		b->bData_20[i-11] = buf[i];
	}

	b->bData_0[8] = ' '; //bug!
	b->bData_0[9] = 0; //bug!

	return 1;
}

/* 4b94 - complete */
int flash_get_sao_data(unsigned int a, Struct_4b94* b)
{
	unsigned char buf[6];
	unsigned short r6;
	unsigned short r7;

	if ((a == 0) && (a > 258997))
	{
		return 0;
	}
	
	r6 = (a - 1) / 88;
	r7 = ((a - 1) % 88) * 6;
	
	flash_read((unsigned short)(0x21e + r6), r7, sizeof(buf), buf);
	
	b->fData_0 = buf[0] + buf[1] / 60.0 + buf[2] / 3600.0;
	
	if (buf[3] >= 0x80)
	{
		b->fData_4 = 0x80 - buf[3] - buf[4] / 60.0 - buf[5] / 3600.0;
	}
	else
	{
		b->fData_4 = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
	}
	
	return 1;
}

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
unsigned char func_57b8(unsigned char* a, int* b, void* c)
{
	unsigned char buf[57];
	unsigned char i;
	unsigned char r8;
	
	flash_read(0xdc7, 0, sizeof(buf), buf);
	
	r8 = buf[0];
	for (i = 0; i < r8; i++)
	{
		a[i] = buf[1 + i*7];
	}

	for (i = 0; i < r8; i++)
	{
		b[i] = 
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

/* 58ec - todo */
unsigned char GetCurrentAlignStars(float r4, float r5, float* equatorialCoord, unsigned char strNames[][10], unsigned char sp304[][22])
{
	int i; 
	unsigned char cnt;
	unsigned char j;
	
	float ra[28];
	float dec[28];
	unsigned char visible[20]; //size??
	unsigned char k;
	float sp16, sp12, sp8, sp4;

	ra[0] = 6.75850009918212890625; //Sirius - Alpha CMa
	dec[0] = -16.7263050079345703125;
	ra[1] = 6.40180301666259765625; //Canopus - Alpha Car
	dec[1] = -52.69824981689453125;
	ra[2] = 18.620929718017578125; //Vega - Alpha Lyr
	dec[2] = 38.790943145751953125;
	ra[3] = 14.6703472137451171875; // Rigil Kentaurus / Toliman  - Alpa Cen
	dec[3] = -60.875278472900390625;
	ra[4] = 14.26785564422607421875; //Arcturus - Alpha Boo
	dec[4] = 19.1384716033935546875;
	ra[5] = 5.288404941558837890625; //Capella - Alpha Aur
	dec[5] = 46.0066375732421875;
	ra[6] = 5.248960971832275390625; //Rigel - Beta Ori
	dec[6] = -8.18952846527099609375;
	ra[7] = 7.662292003631591796875; //Procyon - Alpha CMi
	dec[7] = 5.204332828521728515625;
	ra[8] = 1.63397800922393798828125; //Achernar - Alpha Eri
	dec[8] = -57.187053680419921875;
	ra[9] = 5.09371089935302734375; //Betelgeuse - Alpa Ori
	dec[9] = 7.410167217254638671875;
	ra[10] = 19.8538360595703125; //Altair - Alpha Aql
	dec[10] = 8.890472412109375;
	ra[11] = 4.60669994354248046875; //Aldebaran - Alpha Tau
	dec[11] = 16.52752685546875;
	ra[12] = 13.4276142120361328125; //Spica - Alpha Vir
	dec[12] = -11.2079448699951171875;
	ra[13] = 16.49939727783203125; //Antares - Alpha Sco
	dec[13] = -26.4533329010009765625;
	ra[14] = 22.9691143035888671875; //Formalhaut - Alpha PsA
	dec[14] = -29.5733890533447265625;
	ra[15] = 20.6958770751953125; //Deneb - Alpha Cyg
	dec[15] = 45.308834075927734375;
	ra[16] = 10.14705562591552734375; //Regulus - Alpha Leo
	dec[16] = 11.9264163970947265625;
	ra[17] = 3.41538906097412109375; //Mirfak - Alpha Per
	dec[17] = 49.890056610107421875;
	ra[18] = 7.5854969024658203125; //Castor - Alpha Gem
	dec[18] = 31.87105560302734375;
	ra[19] = 9.46664142608642578125; //Alphard - Alpha Hya
	dec[19] = -8.69580554962158203125;
	ra[20] = 2.6790111064910888671875; //Polaris - Alpha UMi
	dec[20] = 89.2981109619140625;
	ra[21] = 0.1473419964313507080078125; //Sirrah / Alpheratz - Alpha And
	dec[21] = 29.136417388916015625;
	ra[22] = 17.5893688201904296875; //Rasalhagu - Alpha Oph
	dec[22] = 12.55330562591552734375;
	ra[23] = 11.82501697540283203125; //Denebola - Beta Leo
	dec[23] = 14.52511119842529296875;
	ra[24] = 0.953800022602081298828125; //Navi / Tsih / 27 Cas - Gamma Cas
	dec[24] = 60.759693145751953125;
	ra[25] = 9.13812732696533203125; //Suhail - Lambda Velorum
	dec[25] = -43.468776702880859375;
	ra[26] = 13.40486621856689453125; //Mizar - Zeta UMa
	dec[26] = 54.884029388427734375;
	ra[27] = 19.51886749267578125; //Albireo - Beta Cyg
	dec[27] = 27.982250213623046875;
	
	if ((r4 >= 4) || (r4 <= 20))
	{
		sp8 = r4 - 4;
		sp4 = r4 + 4;
	}
	//5c10
	else if (r4 < 4)
	{
		sp8 = r4 + 24 - 4;
		sp4 = r4 + 4;
	}
	else
	{
		sp8 = r4 - 4;
		sp4 = r4 - 24 + 4;
	}
	//5c7c
	if (r5 >= 0)
	{
		sp16 = r5 - 60;
		sp12 = r5 + 60;
		
		if (sp12 > 90)
		{
			sp12 = 90;
		}
	}
	else
	{
		//5cc8
		sp16 = r5 - 60;
		sp12 = r5 + 60;
		
		if (sp16 < -90)
		{
			sp16 = -90;
		}
	}
	//5d00
	i = 0;
	cnt = 0; 
	for (; i < 28; i++)
	{
		//5d0c
		if ((r4 >= 4) || (r4 <= 20))
		{
			//5d2c
			if ((ra[i] >= sp8) && (ra[i] <= sp4) &&
				(dec[i] >= sp16) && (dec[i] <= sp12))
			{
				visible[cnt] = i;
				cnt++;
			}
		}
		else
		{
			//5d90
			if ((r4 <= 4) || (r4 >= 20))
			{
				//5db0
				if (((ra[i] >= sp8) && (ra[i] <= 24)) ||
					((ra[i] >= 0) && (ra[i] <= sp4)))
				{
					//5e00
					if ((dec[i] >= sp16) && (dec[i] <= sp12))
					{
						//5e28
						visible[cnt] = i;
						cnt++;
					}
				}
			}
		}		
	}
	//5e44
	if (cnt > 0)
	{
		for (i = 0; i <= (cnt-1); i++)
		{
			//5e54
			*(equatorialCoord + i*2)     = ra[ visible[i] ];
			*(equatorialCoord + i*2 + 1) = dec[ visible[i] ];
			
			for (j = 0; j < 10; j++)
			{
				//5e8c
				strNames[i][j] = strAlignStarsNames[visible[i]][j];
			}
			//5ec0
			for (k = 0; k < 22; k++)
			{
				//5ecc
				sp304[i][k] = Data_40000118[visible[i]][k];
			}
		}		
	}
	//5f2c
	return cnt-1;
}

/* 5f40 - todo */
void func_5f40(void)
{
	bData_40002f1e_SetupLocalData = 1;
	bData_40002c58 = 0;
	bData_40002c5a = 0;
	bData_40002c68 = 0;
	bData_40002c6a = 0;
	dData_40002c98 = 0.0;
	bData_40002e7c = 0;
	dData_40002ca0 = 1.0;
	dData_40002ca8 = 0.235;
	dData_40002cb0 = 0.326;
	dData_40002c88 = 0.0;
	dData_40002c90 = 0.0;
	Data_40002cb8 = 0x0b;
	Data_40002cbc = 0x29;
	fData_40002cc0 = 12.6;
	Data_40002d40 = 1;
	Data_40002cf4 = 0x37;
	Data_40002cf8 = 0x0b;
	fData_40002cfc = 1.9;
	Data_40002d20 = 1;
	Data_40002d24 = 3;
	fData_40002d28 = 5.9;
	Data_40002d48 = 6;
	Data_40002d4c = 3;
	fData_40002d50 = 5.8;
	Data_40002d68 = 2;
	Data_40002d6c = 3;
	fData_40002d70 = 2.3;
	Data_40002d8c = 5;
	Data_40002d90 = 2;
	fData_40002d94 = 5.6;
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
	bData_40002e7a = 0;
	bData_40002e7b = 0;
	bData_40002e7d = 5;
	bData_40002e7e = 0;
	bData_40002e88 = 0;
	bData_40002e89 = 1;
	bData_40002e8b = 0;
	bData_40002e8c = 0;
	fData_40002e90 = 0;
	fData_40002e98 = 23.8;
	Data_40002e9c = 0;
	Data_40002e94 = 0;
	fData_40002ea0 = 0;
	fData_40002ea8 = 23.8;
	Data_40002eac = 0;
	Data_40002ea4 = 0;
	Data_40002eb0 = 0;
	bData_40002eb4 = 0;
	bData_40002eb5_SolarSystemObjectNr = 0;
	wData_40002eb6 = 0;
	wData_40002eb8_MessierNr = 0;
	wData_40002eba_NGCNr = 0;
	wData_40002ebc_ICNr = 0;
	wData_40002ebe_ShNr = 0;
	wData_40002ec0 = 0;
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
	bData_40002f0d = 0;
	Data_40002f10 = 0;
}

/* 6518 - complete */
void func_6518(void)
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

/* 659c - complete */
void func_659c(unsigned short a)
{
	unsigned short b;
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
				switch (bData_40002e7d)
				{
					#if 0
					case 0:
						//->6d64
						break;
					#endif
					case 1:
						//->6bb4
						Data_400033cc.dwData = 2*Data_40003408 + 6;
						break;
					
					case 2:
						//->6bd4
						Data_400033cc.dwData = 16;
						break;
					
					case 3:
						//->6be8
						Data_400033cc.dwData = 60;
						break;
					
					case 4:
						//->6bfc
						Data_400033cc.dwData = 240;
						break;
					
					case 5:
						//->6c10
						Data_400033cc.dwData = 460;
						break;
					
					case 6:
						//->6c24
						Data_400033cc.dwData = 640;
						break;
					
					case 7:
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
					
					case 8:
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
					
					case 9:
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
			}
			//6d68
			uart1_write_byte(0x55);
			uart1_write_byte(0xaa);
			uart1_write_byte(0x01);
			uart1_write_byte(0x06);
			uart1_write_byte(0x02);
			uart1_write_byte(Data_400033cc.bData[1]);
			uart1_write_byte(Data_400033cc.bData[0]);
			uart1_write_byte(Data_400033c8.bData[3]);
			uart1_write_byte(Data_400033c8.bData[2]);
			uart1_write_byte(Data_400033c8.bData[1]);
			//->6f6c
		}
		else
		{
			//6dec
			if (Data_40003408 != 0)
			{
				switch (bData_40002e7d)
				{
					#if 0
					case 0:
						//->6ee8
						break;
					#endif
					case 1:
						//->6e38
						Data_400033cc.dwData = 8;
						break;
					
					case 2:
						//->6e4c
						Data_400033cc.dwData = 16;
						break;
					
					case 3:
						//->6e60
						Data_400033cc.dwData = 32;
						break;
					
					case 4:
						//->6e74
						Data_400033cc.dwData = 64;
						break;
					
					case 5:
						//->6e88
						Data_400033cc.dwData = 100;
						break;
					
					case 6:
						//->6e9c
						Data_400033cc.dwData = 200;
						break;
					
					case 7:
						//->6eb0
						Data_400033cc.dwData = 400;
						break;
					
					case 8:
						//->6ec4
						Data_400033cc.dwData = 600;
						//break; //-> BUG??
					
					case 9:
						//->6ed8
						Data_400033cc.dwData = 980;
						break;
					#if 0
					default:
						//->6ee8
						break;
						#endif
				}
			}
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
				switch (bData_40002e7d)
				{
					#if 0
					case 0:
						//->738c
						break;
					#endif
					case 1:
						//->71e8
						Data_400033cc.dwData = 4;
						break;
					
					case 2:
						//->71fc
						Data_400033cc.dwData = 16;
						break;
					
					case 3:
						//->7210
						Data_400033cc.dwData = 60;
						break;
					
					case 4:
						//->7224
						Data_400033cc.dwData = 240;
						break;
					
					case 5:
						//->7238
						Data_400033cc.dwData = 460;
						break;
					
					case 6:
						//->724c
						Data_400033cc.dwData = 640;
						break;
					
					case 7:
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
					
					case 8:
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
					
					case 9:
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
			uart1_write_byte(0x06);
			uart1_write_byte(0x22);
			uart1_write_byte(Data_400033cc.bData[1]);
			uart1_write_byte(Data_400033cc.bData[0]);
			uart1_write_byte(Data_400033c8.bData[3]);
			uart1_write_byte(Data_400033c8.bData[2]);
			uart1_write_byte(Data_400033c8.bData[1]);
			//->757c
		}
		else
		{
			//73f8
			if (Data_4000340c != 0)
			{
				switch (bData_40002e7d)
				{
					#if 0
					case 0:
						//->74f8
						break;
					#endif
					case 1:
						//->7444
						Data_400033cc.dwData = 5;
						break;
					
					case 2:
						//->0x7458
						Data_400033cc.dwData = 13;
						break;
					
					case 3:
						//->0x746c
						Data_400033cc.dwData = 50;
						break;
					
					case 4:
						//->0x7480
						Data_400033cc.dwData = 85;
						break;
					
					case 5:
						//->0x7494
						Data_400033cc.dwData = 150;
						break;
					
					case 6:
						//->74a8
						Data_400033cc.dwData = 220;
						break;
					
					case 7:
						//->0x74bc
						Data_400033cc.dwData = 500;
						break;
					
					case 8:
						//->0x74d0
						Data_400033cc.dwData = 800;
						break;
					
					case 9:
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
	}
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
void func_7950(int a)
{
	bData_40002c08 = a << 5;
	bData_40002c09 = bData_40002c08 - 1;
}

#ifndef OLIMEX_LPC2148

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
	
	if (bData_40002c6a != 0)
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
double func_7f30(int a, int b, double sp192)
{
	double JD; //sp176;
	double T; //sp168;
	double sp160;
	double sp152;
	Struct_7d1c sp140;
	Struct_7d1c sp128;
	Struct_7d1c sp116;
	double sp104;
	double sp96;
	double hours; //sp88;
	double sp80 = 3.1415927;
	
	func_7d1c(&sp140);
	
	switch (a)
	{
		case 1:
			//0x7f6c
			sp128 = sp140;
			sp116 = sp128;
			if ((sp128.bHours - Data_40004128.Data_64) < 0)
			{
				sp116.bHours = sp116.bHours - Data_40004128.Data_64 + 24;
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
			}
			else
			{
				//8154
				if ((sp128.bHours - Data_40004128.Data_64) > 24)
				{
					sp116.bHours = sp116.bHours - Data_40004128.Data_64 - 24;
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
					sp116.bHours = sp128.bHours - Data_40004128.Data_64;
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
	sp104 = (int)(sp116.wYear * 1.0 / 100.0);
	sp96 = 2.0 - sp104 + (int)(sp104 * 1.0 / 4.0);
	
	hours/*sp88*/ = (sp116.bHours + sp116.bMinutes / 60.0 + sp116.bSeconds / 3600.0 + sp116.wData_8 / 3600000.0) / 24.0;
	Data_40004128.dData_104 = hours/*sp88*/;
	
	JD/*sp176*/ = (int)((sp116.wYear + 4716) * 365.25) + (int)((sp116.bMonth + 1) * 30.6001) + sp116.bDay + hours/*sp88*/ + sp96 - 1524.5;
		
	Data_40004128.dData_96 = JD/*sp176*/;
	
	//http://www.geoastro.de/elevaz/basics/meeus.htm
	//-> compute sidereal time at Greenwich (according to: Jean Meeus: Astronomical Algorithms)
	T/*sp168*/ = (JD/*sp176*/ - 2451545.0) / 36525.0;
	sp160 = (JD/*sp176*/ - 2451545.0) * 360.985647366289981619047466666 + 280.460618370000020149745978415 + 
		0.000387993 * T*T/*sp168 * sp168*/ - T*T*T/*sp168 * sp168 * sp168*/ / 38710000.0;	
	//883c
	while (sp160 > 360.0)
	{
		sp160 -= 360.0;
	}
	
	while (sp160 < 0.0)
	{
		sp160 += 360.0;
	}
	//888c
	JD/*sp176*/ = (int)((sp116.wYear + 4716) * 365.25) + (int)((sp116.bMonth + 1) * 30.6001) + sp116.bDay + sp96 - 1524.5;
	T/*sp168*/ = (JD/*sp176*/ - 2451545.0) / 36525.0;
	
	dData_400034a0 = (JD/*sp176*/ - 2451545.0) * 360.985647366289981619047466666 + 280.460618370000020149745978415 + 
		0.000387993 * T*T/*sp168 * sp168*/ - T*T*T/*sp168 * sp168 * sp168*/ / 38710000.0;
	
	while (dData_400034a0 > 360.0)
	{
		dData_400034a0 -= 360.0;
	}

	while (dData_400034a0 < 0.0)
	{
		dData_400034a0 += 360.0;
	}
	//8acc
	dData_400034a0 /= 15;
	
	sp152 = sp192 + sp160;
	
	while (sp152 > 360.0)
	{
		sp152 -= 360.0;
	}
	
	while (sp152 < 0.0)
	{
		sp152 += 360.0;
	}
	
	sp152 /= 15.0;
	
	return sp152;
}

/* 8ba4 - todo */
void func_8ba4(Struct_8ba4_0 a/*sp176*/, Struct_8ba4 b/*sp208*/, int r4, int r5, double* r6)
{
	double sp168 = 3.14159265359;
	double sp160 = a.dData_0; //sp176; 
	double sp152 = a.dData_8; //sp184; 
	double sp144 = b.dData_0; //sp208
	double sp136 = b.dData_8; //sp216
	double sp128;
	double sp120;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	
	sp120 = func_7f30(r4, r5, sp160);
	
	sp128 = sp120 - sp144;
	while (sp128 >= 24)
	{
		sp128 -= 24;
	}
	
	while (sp128 < 0)
	{
		sp128 += 24;
	}
	//8cac
	sp128 = sp128 * sp168 * 15.0 / 180.0;	
	sp152 = sp152 * sp168 / 180.0;
	sp136 = sp136 * sp168 / 180.0;
	
	sp112 = acos(sin(sp152) * sin(sp136) + cos(sp152) * cos(sp136) * cos(sp128));
	sp104 = acos((sin(sp152) * cos(sp136) * cos(sp128) - cos(sp152) * sin(sp136)) / sin(sp112));
	
	if (sp128 > sp168)
	{
		sp104 = -1 * sp104;
	}
	//8f38
	sp96 = (sin(sp152) * sin(sp112) + cos(sp112) * cos(sp104) * cos(sp152)) / sin(sp112) * 15.04;
	sp88 = cos(sp152) * 15.04 * sin(sp104);
	
	r6[0] = sp104 * 57.2957795130823228646477218717;
	r6[1] = sp104 * 57.2957795130823228646477218717 + 180.0;
	r6[4] = sp96;
	r6[2] = sp112 * 57.2957795130823228646477218717;
	r6[3] = 90.0 - sp112 * 57.2957795130823228646477218717;
	r6[5] = sp88;
	r6[6] = -sp88;
}

/* 9178 - todo */
void func_9178(void)
{
	#if 0
	double sp264;
	double sp256;
	#else
	Struct_8ba4_0 sp256;
	#endif
	Struct_8ba4 sp224;
	double sp152[9]; //size??
	Struct_7978 sp104;
	double sp96;
	double sp88;
	double sp80;
	double sp72;
	double sp64;
	double sp56;
	double sp48; 
	
	if (Data_40004128.bData_357 != 0)
	{
		if (bData_40003431 == 0)
		{
			//91a0
			/*sp256*/sp256.dData_0 = Data_40004128.geographicLongitude;
			/*sp264*/sp256.dData_8 = Data_40004128.geographicLatitude;
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
					sp224.dData_0 = Data_40004128.dData_72;
					sp224.dData_8 = Data_40004128.dData_80;					
					break;
					
				default:
					break;
			}
			//92c0
			sp80 = func_7f30(Data_40004128.Data_40, Data_40004128.bData_44, Data_40004128.geographicLongitude);
			
			fData_400034c8 = sp80;

			#if 0
			func_8ba4(sp256, sp264, sp224, Data_40004128.Data_40, Data_40004128.bData_44, sp152);
			#else
			func_8ba4(sp256, sp224, Data_40004128.Data_40, Data_40004128.bData_44, sp152);
			#endif
			
			sp72 = sp80 - sp224.dData_0;
			
			while (sp72 >= 24)
			{
				sp72 -= 24;
			}

			while (sp72 < 0)
			{
				sp72 += 24;
			}
			
			sp64 = sp72;
			sp56 = Data_40004128.dData_80;
			sp104.dData_32 = Data_40004380.dData_32;
			sp104.dData_40 = Data_40004380.dData_40;
			sp104.dData_8 = Data_40004380.dData_8;
			sp104.dData_0 = Data_40004380.dData_0;
			sp104.dData_24 = Data_40004380.dData_24;
			sp104.dData_16 = Data_40004380.dData_16;
			
			dData_40003458 = sp72;
			dData_40003460 = Data_40004128.dData_80;
			
			func_7978(sp104, &dData_40003458, &dData_40003460);
			
			sp64 = dData_40003458;
			sp56 = dData_40003460;
			
			fData_400034c0 = sp64 - sp72;
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
			Data_40004128.dData_144 = sp72;
			Data_40004128.dData_152 = Data_40004128.dData_80;
			
			if (bData_40002c1a == 1)
			{
				//9608
				if (/*sp264*/sp256.dData_8 >= 0)
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
				}
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
				if (/*sp264*/sp256.dData_8 >= 0)
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
				}
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
		}
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
				
				if (bData_40002e7d > 6)
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
				
				if (bData_40002e7d > 6)
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
				func_7950(1);
			}
			
			bData_40003498 = 0;
			bData_40002e88 = 2;
			//->a730
		}
		else
		{
			//a724
			bData_40002e88 = 1;
		}
		//a730
		if ((Data_40004128.dData_304 == 2.0) && 
			(Data_40004128.dData_312 == 2.0) &&
			(bData_40003431 != 0))
		{
			Data_40004128.bData_357 = 0;
			Data_40004128.bData_356 = 0;
			bData_40002e8c = 0;
			
			func_7950(1);
			
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
		if (/*sp176*/sp152[3] >= 0)
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
		}
		else
		{
			//ac00
			func_65d4(0.0, 0.0);
			
			Data_40004128.bData_357 = 0;
			Data_40004128.bData_356 = 0;
			Data_40004128.bData_358 = 1;
			bData_40002e88 = 3;			
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
	}
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
	sp120 = func_7f30(1, 0, Data_40004128.geographicLongitude);
	
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

#endif //OLIMEX_LPC2148

/* b4f0 - todo */
void func_b4f0(void)
{
	Data_40004128.bData_357 = 0;
	Data_40004128.dData_312 = 0.0;
	Data_40004128.dData_304 = 0.0;
	bData_40002e88 = 0;
	
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
	
	bData_40002e7d = 3;
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
	bData_40002e7d = 3;
	bData_40003200 = 1;
	bData_40003201 = 1;
	
	Data_40004128.dData_584 = 0.0;
	Data_40004128.dData_592 = 0.0;

	bData_40003210 = 0;
	bData_40003211 = 0;
}

#ifndef OLIMEX_LPC2148

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
		
		if (bData_40002e7a == 0)
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
		}
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

	bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(func_7f30(1, 0, Data_40004128.geographicLongitude), 
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

	Data_40004128.Data_64 = 8;
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
double func_d7ac(int a/*r4*/, double sp184, double sp208, double sp216, double sp224, int sp232/*r5*/)
{
	double sp168;
	double sp160;
	double sp152;
	double sp144;
	double sp136;
	double sp128;
	double sp120;
	
	sp184 *= 15.0;
	
	sp136 = 0.00273043357646934187199505572607;
	sp128 = 0.00273790925583078815358506474809;
	
	sp120 = fabs(acos((cos(1.58068652588952995863280648337) - 
		sin(sp224 * 0.0174532925199399994997673246644) * 
		sin(sp208 * 0.0174532925199399994997673246644)) / 
		(cos(sp224 * 0.0174532925199399994997673246644) * 
		cos(sp208 * 0.0174532925199399994997673246644)))) * 3.81971863420548984890956489835;
	
	if (a == 1)
	{
		//d930
		sp152 = sp184 / 15.0 - sp120;
	}
	//0xd960
	if (a == 2)
	{
		//d968
		sp152 = sp184 / 15.0;
	}
	//0xd984
	if (a == 3)
	{
		//d98c
		sp152 = sp184 / 15.0 + sp120;
	}
	//0xd9bc
	sp144 = dData_400034a0 - sp216 / 15.0 * sp128;
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
	sp168 = Data_40004128.Data_64 - sp216 / 15.0 + sp160;
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
void func_dc20(unsigned char a, unsigned char b, unsigned char c)
{
	int i;
	char sp4[8][32] = 
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
	
	lcd_write_command(((b - 1) * 6 + 2) & 0x0F);
	lcd_write_command(((((b - 1) * 6 + 2) & 0xF0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
	lcd_write_command(((a - 1) & 0x0F) | ST7565_CMD_SET_PAGE);
	
	for (i = 0; i < 16; i++)
	{
		lcd_write_data(sp4[c][i]);
	}
	
	lcd_write_command(((b - 1) * 6 + 2) & 0x0F);
	lcd_write_command(((((b - 1) * 6 + 2) & 0xF0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
	lcd_write_command((a & 0x0F) | ST7565_CMD_SET_PAGE);
	
	for (i = 0; i < 16; i++)
	{
		lcd_write_data(sp4[c][i+16]);	
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
int func_dd84(int year, int month)
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
int func_de18(int a, int b, int c)
{
	int r7;
	int r8;
	int sp;
	int r9;
	int sp4;
	
	if ((b < 0) || (b > 12))
	{
		b = 0;
	}
	
	r8 = Data_40002bc4[b] + c;
	
	if (b > 2)
	{
		//de50
		if (!(a % 4) && (!(a % 400) || (a % 100)))
		{
			r8++;
		}
	}
	//0xde94
	r7 = a / 100 + 1;
	r9 = a % 19 + 1;
	
	sp = ((r7 * 8 + 5) / 25 + (r9 * 11 + 20) - 5 - ((r7 * 3) / 4 - 12)) % 30;

	if (sp <= 0)
	{
		sp += 30;
	}
	//0xdf18
	if (((sp == 25) && (r9 > 11)) || (sp == 24))
	{
		//0xdf38
		sp++;
	}
	//0xdf44
	sp4 = ((11 + (sp + r8) * 6) % 177 / 22) & 0x07;

	return sp4;
}

/* df84 - todo */
void func_df84(int year, int month)
{
	int r6;
	int r7;
	int r8 = -1;
	int r9 = 2;
	int sl = 1;
	unsigned char sp12[][2] = 
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
	unsigned char sp4[7];
	
	sp4[0] = year / 1000 + '0';
	sp4[1] = (year % 1000) / 100 + '0';
	sp4[2] = (year % 100) / 10 + '0';
	sp4[3] = (year % 100) % 10 + '0';
	sp4[4] = '-';
	sp4[5] = month / 10 + '0';
	sp4[6] = month % 10 + '0';
	
	func_7e8(0, 1, 8, 7, sp4);
	
	for (r6 = 1; r6 <= func_dd84(year, month); r6++)
	{
		//0xe084
		r7 = func_de18(year, month, r6);
		if (r7 == r8)
		{
			continue;
		}

		r8 = r7;
		
		func_dc20(r9, sl, r7);		
		func_7e8(0, r9 + 2, sl, 2, sp12[r6-1]);
		
		sl += 4;
		
		if (sl > 20)
		{
			sl -= 20;
			r9 += 3;
		}
	}
}

//For the following see: https://pymeeus.readthedocs.io/en/latest/Earth.html
//https://www.avrfreaks.net/forum/best-microcontroller-heavy-computation?page=all

/* e11c - complete */
double earth_heliocentric_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;

	L0 += 175347046 * cos(0.0 + a * 0.0);
	L0 += 3341656 * cos(4.6692568 + a * 6283.07585); 
	L0 += 34894 * cos(4.6261 + a * 12566.1517); 
	L0 += 3497 * cos(2.7441 + a * 5753.3849);
	L0 += 3418 * cos(2.8289 + a * 3.5231);
	L0 += 3136 * cos(3.6277 + a * 77713.7715);
	
	L1 += 628331966747 * cos(0.0 + a * 0.0);
	L1 += 206059 * cos(2.678235 + a * 6283.07585);
	L1 += 4303 * cos(2.6351 + a * 12566.1517);
	
	L2 += 52919 * cos(0.0 + a * 0.0);
	L2 += 8720 * cos(1.0721 + a * 6283.0758);
		
	res = (L0 +
		L1 * a +
		L2 * a*a + 
		L3 * a*a*a + 
		L4 * a*a*a*a + 
		L5 * a*a*a*a*a) / 100000000.0;
	
	return res;
}

/* e8fc - todo */
double earth_heliocentric_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double res = 0.0;
	
	B0 += 280.0 * cos(3.199 + a * 84334.662);
	B0 += 102.0 * cos(5.422 + a * 5507.553);
	B0 += 80.0 * cos(3.88 + a * 5223.69);
	B0 += 44.0 * cos(3.7 + a * 2352.87);
	B0 += 32.0 * cos(4 + a * 1577.34);
	
	B1 += 9.0 * cos(3.9 + a * 5507.55);
	B1 += 6.0 * cos(1.73 + a * 1577.34); //5223.69); //BUG!!!
	
	res = (B0 + B1 * a) / 100000000.0;
	
	return res;
}

/* ecf8 - todo */
double earth_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double res = 0.0;
	
	R0 += 100013989 * cos(0.0 + a * 0.0);
	R0 += 1670700 * cos(3.0984635 + a * 6283.07585);
	R0 += 13956 * cos(3.05525 + a * 12566.1517);
	R0 += 3084 * cos(5.1985 + a * 77713.7715);
	
	R1 += 103019 * cos(1.10749 + a * 6283.07585);
	R1 += 1721 * cos(1.0644 + a * 12566.1517);
	
	R2 += 4359 * cos(5.7846 + a * 6283.0758);
	
	res = (R0 +
		R1 * a +
		R2 * a*a + 
		R3 * a*a*a + 
		R4 * a*a*a*a) / 100000000.0;
		
	return res;
}

//http://home.mnet-online.de/reimay/Projects/pc/Astronomie/libaa/AAMercury.cpp

/* f22c - todo */
double mercury_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;
	
	L0 += 440250710 * cos(0.0 + a * 0.0);
	L0 += 40989415 * cos(1.48302034 + a * 26087.90314157);
	L0 += 5046294 * cos(4.4778549 + a * 52175.8062831);
	L0 += 855347 * cos(1.165203 + a * 78263.709425);
	L0 += 165590 * cos(4.119692 + a * 104351.612566);
	L0 += 34562 * cos(0.77931 + a * 130439.51571);
	L0 += 7583 * cos(3.7135 + a * 156527.4188);
	L0 += 3560 * cos(1.5120 + a * 1109.3786);
	
	L1 += 2608814706223 * cos(0.0 + a * 0.0);
	L1 += 1126008 * cos(6.2170397 + a * 26087.9031416);
	L1 += 303471 * cos(3.055655 + a * 52175.806283);
	L1 += 80538 * cos(6.10455 + a * 78263.70942);
	L1 += 21245 * cos(2.83532 + a * 104351.61257);
	
	L2 += 53050 * cos(0.0 + a * 0.0);
	L2 += 16904 * cos(4.69072 + a * 26087.90314);
	
	res = (L0 +
		L1 * a +
		L2 * a*a + 
		L3 * a*a*a + 
		L4 * a*a*a*a +
		L5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* fc20 - todo */
double mercury_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 11737529 * cos(1.98357499 + a * 26087.90314157);
	B0 += 2388077 * cos(5.0373896 + a * 52175.8062831);
	B0 += 1222840 * cos(3.1415927 + a * 0.0);
	B0 += 543252 * cos(1.796444 + a * 78263.709425);
	B0 += 129779 * cos(4.832325 + a * 104351.612566);
	B0 += 31867 * cos(1.58088 + a * 130439.51571);
	
	B1 += 429151 * cos(3.501698 + a * 26087.903142);
	B1 += 146234 * cos(3.141593 + a * 0.0);
	B1 += 22675 * cos(0.01515 + a * 52175.80628);
	
	B2 += 11831 * cos(4.79066 + a * 26087.90314);
	B2 += 1914 * cos(0.0 + a * 0.0);
	B2 += 1045 * cos(1.2122 + a * 52175.8063);
	
	res = (B0 +
		B1 * a +
		B2 * a*a + 
		B3 * a*a*a + 
		B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 103dc - todo */
double mercury_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double res = 0.0;
	
	R0 += 39528272 * cos(0.0 + a * 0.0);
	R0 += 7834132 * cos(6.1923372 + a * 26087.9031416);
	R0 += 795526 * cos(2.959897 + a * 52175.806283);
	R0 += 121282 * cos(6.010642 + a * 78263.709425);
	R0 += 21922 * cos(2.77820 + a * 104351.61257);

	R1 += 217348 * cos(4.656172 + a * 26087.9031416); //26087.903142); //BUG???
	R1 += 44142 * cos(1.42386 + a * 52175.80628);
	R1 += 10094 * cos(4.47466 + a * 8263.70942); //78263.70942); //BUG???
	
	R2 += 3118 * cos(3.0823 + a * 26087.9031);
	R2 += 1245 * cos(6.1518 + a * 52175.8063);
	R2 += 425 * cos(2.926 + a * 78263.709);
	R2 += 136 * cos(5.98 + a * 104351.613);
	
	res = (R0 +
		R1 * a +
		R2 * a*a + 
		R3 * a*a*a) / 100000000.0;
		
	return res;
}

/* 10b2c - todo */
double venus_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;
	
	L0 += 317614667 * cos(0.0 + a * 0.0);
	L0 += 1353968 * cos(5.5931332 + a * 10213.2855462);
	L0 += 89892 * cos(5.30650 + a * 20426.57109);
	L0 += 5477 * cos(4.4163 + a * 7860.4194);
	
	L1 += 1021352943053 * cos(0.0 + a * 0.0);
	L1 += 95708 * cos(2.46424 + a * 10213.28555);
	L1 += 14445 * cos(0.51625 + a * 20426.57109);
	
	L2 += 54127 * cos(0.0 + a * 0.0);
	L2 += 3891 * cos(0.3451 + a * 10213.2855);
	L2 += 1338 * cos(2.0201 + a * 20426.5711);
	
	res = (L0 +
		L1 * a +
		L2 * a*a + 
		L3 * a*a*a +
		L4 * a*a*a*a +
		L5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 1127c - todo */
double venus_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 5923638 * cos(0.2670278 + a * 10213.2855462);
	B0 += 40108 * cos(1.14737 + a * 20426.57109);
	B0 += 32815 * cos(3.14159 + a * 0.0);
	
	B1 += 513348 * cos(1.803643 + a * 10213.285546);
	B1 += 4380 * cos(3.3862 + a * 20426.5711);
	
	B2 += 22378 * cos(3.38509 + a * 10213.28555);
	
	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 1173c - todo */
double venus_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double res = 0.0;
	
	R0 += 72334821 * cos(0.0 + a * 0.0);
	R0 += 489824 * cos(4.021518 + a * 10213.285546);

	R1 += 34551 * cos(0.89199 + a * 10213.28555);

	R2 += 1407 * cos(5.0637 + a * 10213.2855);
	
	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a + R4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 11af4 - todo */
double mars_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;
	
	L0 += 620347712 * cos(0.0 + a * 0.0);
	L0 += 18656368 * cos(5.05037100 + a * 3340.61242670);
	L0 += 1108217 * cos(5.4009984 + a * 6681.2248534);
	L0 += 91798 * cos(5.75479 + a * 10021.83728);
	L0 += 27745 * cos(5.97050 + a * 3.52312);
	L0 += 12316 * cos(0.84956 + a * 2810.92146);
	L0 += 10610 * cos(2.93959 + a * 2281.23050);

	L1 += 334085627474 * cos(0.0 + a * 0.0);
	L1 += 1458227 * cos(3.6042605 + a * 3340.6124267);
	L1 += 164901 * cos(3.926313 + a * 6681.224853);
	L1 += 19963 * cos(4.26594 + a * 10021.83728);

	L2 += 58016 * cos(2.04979 + a * 3340.61243);
	L2 += 54188 * cos(0.0 + a * 0.0);
	L2 += 13908 * cos(2.45742 + a * 6681.22485);
	
	res = (L0 + L1 * a + L2 * a*a + L3 * a*a*a + L4 * a*a*a*a + L5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}
	
/* 12450 - todo */
double mars_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 3197135 * cos(3.7683204 + a * 3340.6124267);
	B0 += 298033 * cos(4.106170 + a * 6681.224853);
	B0 += 289105 * cos(0.0 + a * 0.0);
	B0 += 31366 * cos(4.44651 + a * 10021.83728);
	
	B1 += 350069 * cos(5.368478 + a * 3340.612427);
	B1 += 14116 * cos(3.14159 + a * 0.0);
	B1 += 9671 * cos(5.4788 + a * 6681.2249);

	B2 += 16727 * cos(0.60221 + a * 3340.61243);
	B2 += 4987 * cos(3.1416 + a * 0.0);

	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 12a8c - todo */
double mars_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double res = 0.0;
	
	R0 += 153033488 * cos(0.0 + a * 0.0);
	R0 += 14184953 * cos(3.47971284 + a * 3340.61242670);
	R0 += 660776 * cos(3.817834 + a * 6681.224853);
	R0 += 46179 * cos(4.15595 + a * 10021.83728);
	R0 += 8110 * cos(5.5596 + a * 2810.9215);
	
	R1 += 1107433 * cos(2.0325052 + a * 3340.6124267);
	R1 += 103176 * cos(2.370718 + a * 6681.224853);
	R1 += 12877 * cos(0.0 + a * 0.0);
	R1 += 10816 * cos(2.70888 + a * 10021.83728);
	
	R2 += 44242 * cos(0.47931 + a * 3340.61243);
	R2 += 8138 * cos(0.8700 + a * 6681.2249);

	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a + R4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 131ac - todo */
double jupiter_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;
	
	L0 += 59954691 * cos(0.0 + a * 0.0);
	L0 += 9695899 * cos(5.0619179 + a * 529.6909651);
	L0 += 573610 * cos(1.444062 + a * 7.113547);
	L0 += 306389 * cos(5.41734/*5.417347*/ + a * 1059.381930); //BUG?
	L0 += 97178 * cos(4.14265 + a * 632.78374);
	L0 += 72903 * cos(3.64043 + a * 522.57742);
	L0 += 64264 * cos(3.41145 + a * 103.09277);

	L1 += 52993480757 * cos(0.0 + a * 0.0);
	L1 += 489741 * cos(4.220667 + a * 529.690965);
	L1 += 228919 * cos(6.026475 + a * 7.113547);
	L1 += 27655 * cos(4.57266 + a * 1059.38193);
	L1 += 20721 * cos(5.45939 + a * 522.57742);
	L1 += 12106 * cos(0.16986 + a * 536.80451);

	L2 += 47234 * cos(4.32148 + a * 7.11355);
	L2 += 38966 * cos(0.0 + a * 0.0);
	L2 += 30629 * cos(2.93021 + a * 529.69097);

	L3 += 6502 * cos(2.5986 + a * 7.1135);
	L3 += 1357 * cos(1.3464 + a * 529.6910);

	res = (L0 + L1 * a + L2 * a*a + L3 * a*a*a + L4 * a*a*a*a + L5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 13d10 - todo */
double jupiter_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double B5 = 0.0;
	double res = 0.0;
	
	B0 += 2268616 * cos(3.5585261 + a * 529.6909651);
	B0 += 110090 * cos(0.0 + a * 0.0);
	B0 += 109972 * cos(3.908093 + a * 1059.381930);

	B1 += 177352 * cos(5.701665 + a * 529.690965);
	B1 += 3230 * cos(5.7794 + a * 1059.3819);
	B1 += 3081 * cos(5.4746 + a * 522.5774);
	B1 += 2212 * cos(4.7346/*4.7348*/ + a * 536.8045); //BUG?
	B1 += 1694 * cos(3.1416 + a * 0.0);

	B2 += 8094 * cos(1.4632 + a * 529.6910);
	B2 += 813 * cos(3.1416 + a * 0.0);
	B2 += 742 * cos(0.957 + a * 522.577);
	B2 += 399 * cos(2.899 + a * 536.8); //536.805); //BUG?
	B2 += 342 * cos(1.447 + a * 1059.382);
	
	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a + B5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 145e4 - todo */
double jupiter_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double R5 = 0.0;
	double res = 0.0;
	
	R0 += 520887429 * cos(0.0 + a * 0.0);
	R0 += 25209327 * cos(3.49108640 + a * 529.69096509);
	R0 += 610600 * cos(3.841154 + a * 1059.381930);
	R0 += 282029 * cos(2.574199 + a * 632.783739);
	R0 += 187647 * cos(2.075904 + a * 522.577418);
	R0 += 86793 * cos(0.71001 + a * 419.48464);
	R0 += 72063 * cos(0.21466 + a * 536.80451);
	R0 += 65517 * cos(5.97996 + a * 316.39187);
	R0 += 30135 * cos(2.16132 + a * 949.17561);
	R0 += 29135 * cos(1.67759 + a * 103.02977); //103.09277); //BUG?
	R0 += 23947 * cos(0.27458 + a * 7.11355);

	R1 += 1271802 * cos(2.6493751 + a * 529.6909651);
	R1 += 61662 * cos(3.00076 + a * 1059.38193);
	R1 += 53444 * cos(3.89718 + a * 522.57742);
	R1 += 41390 * cos(0.0 + a * 0.0);
	R1 += 31185 * cos(4.88277 + a * 536.80451);
	R1 += 11847 * cos(2.41330 + a * 419.48464);
	R1 += 9166 * cos(4.7598 + a * 7.1135);

	R2 += 79645 * cos(1.35866 + a * 529.69097);
	R2 += 8252 * cos(5.7777 + a * 522.5774);
	R2 += 7030 * cos(3.2748 + a * 536.8045);
	R2 += 5314 * cos(1.8384 + a * 1059.3819);

	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a + R4 * a*a*a*a + R5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 15340 - todo */
double saturn_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double L5 = 0.0;
	double res = 0.0;
	
	L0 += 87401354 * cos(0.0 + a * 0.0);
	L0 += 11107660 * cos(3.96205090 + a * 213.29909544);
	L0 += 1414151 * cos(4.5858152 + a * 7.1135470);
	L0 += 398379 * cos(0.521120 + a * 206.185548);
	L0 += 350769 * cos(3.303299 + a * 426.598191);
	L0 += 206816 * cos(0.246584 + a * 103.092774);
	L0 += 79271 * cos(3.84007 + a * 220.41264);
	L0 += 23990 * cos(4.66977 + a * 110.20632);
	L0 += 16574 * cos(0.43719 + a * 419.48464);
	L0 += 15820 * cos(0.93809 + a * 632.78374);
	L0 += 15054 * cos(2.71670 + a * 639.89729);
	L0 += 14907 * cos(5.76903 + a * 316.39187);

	L1 += 21354295596 * cos(0.0 + a * 0.0);
	L1 += 1296855 * cos(1.828205/*1.8282054*/ + a * 213.2990954); //BUG?
	L1 += 564348 * cos(2.885001 + a * 7.113547);
	L1 += 107679 * cos(2.277699 + a * 206.185548);
	L1 += 98323 * cos(1.08070 + a * 426.59819);
	L1 += 40255 * cos(2.04128 + a * 220.41264);
	L1 += 19942 * cos(1.27955 + a * 103.09277);
	L1 += 10512 * cos(2.74880 + a * 14.22709);

	L2 += 116441 * cos(1.179879 + a * 7.113547);
	L2 += 91921 * cos(0.07425 + a * 213.29910);
	L2 += 90592 * cos(0.0 + a * 0.0);

	res = (L0 + L1 * a + L2 * a*a + L3 * a*a*a + L4 * a*a*a*a + L5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 16114 - todo */
double saturn_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double B5 = 0.0;
	double res = 0.0;
	
	B0 += 4330678 * cos(3.6028443 + a * 213.2990954);
	B0 += 240348 * cos(2.852385 + a * 426.598191);
	B0 += 84746 * cos(0.0 + a * 0.0);
	B0 += 34116 * cos(0.57297 + a * 206.18555);
	B0 += 30863 * cos(3.48442 + a * 220.41264);

	B1 += 397555 * cos(5.332900 + a * 213.299095);
	B1 += 49479 * cos(3.14159 + a * 0.0);
	B1 += 18572 * cos(6.09919 + a * 426.59819);
	B1 += 14801 * cos(2.30586 + a * 206.18555);
	B1 += 9644 * cos(1.6967 + a * 220.4126);

	B2 += 20630 * cos(0.50482 + a * 213.29910);
	B2 += 3720 * cos(3.9983 + a * 206.1855);
	B2 += 1627 * cos(6.1819 + a * 220.4126);
	B2 += 1346 * cos(0.0 + a * 0.0);
	
	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a + B5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 16a5c - todo */
double saturn_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double R5 = 0.0;
	double res = 0.0;
	
	R0 += 955758136 * cos(0.0 + a * 0.0);
	R0 += 52921382 * cos(2.39226220 + a * 213.29909544);
	R0 += 1873680 * cos(5.2354961 + a * 206.1855484);
	R0 += 1464664 * cos(1.6476305 + a * 426.5981909);
	R0 += 821891 * cos(5.935200 + a * 316.391870);
	R0 += 547507 * cos(5.015326 + a * 103.092774);
	R0 += 371684 * cos(2.271148 + a * 220.412642);
	R0 += 361778 * cos(3.139043 + a * 7.113547);
	R0 += 140618 * cos(5.074067/*5.704067*/ + a * 632.783739); //BUG?
	R0 += 108975 * cos(3.293136 + a * 110.206321);

	R1 += 6182981 * cos(0.2584352 + a * 213.2990954);
	R1 += 506578 * cos(0.711147 + a * 206.185548);
	R1 += 341394 * cos(5.796358 + a * 426.598191);
	R1 += 188491 * cos(0.472157 + a * 220.412642);
	R1 += 186262 * cos(3.141593 + a * 0.0);
	R1 += 143891 * cos(1.407449 + a * 7.113547);

	R2 += 436902 * cos(4.786717 + a * 213.299095);
	R2 += 71923 * cos(2.50070 + a * 206.18555);
	R2 += 49767 * cos(4.97168 + a * 220.412642); //220.41264); //BUG?

	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a + R4 * a*a*a*a + R5 * a*a*a*a*a) / 100000000.0;
		
	return res;
}

/* 17630 - todo */
double uranus_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double res = 0.0;
	
	L0 += 548129294 * cos(0.0 + a * 0.0);
	L0 += 9260408 * cos(0.8910642 + a * 74.7815986);
	L0 += 1504248 * cos(3.6271926 + a * 1.4844727);
	L0 += 365982 * cos(1.899622 + a * 73.297126);
	L0 += 272328 * cos(3.358237 + a * 149.563197);
	L0 += 70328 * cos(5.39254 + a * 63.73590);
	L0 += 68893 * cos(6.09292 + a * 76.26607);
	L0 += 61999 * cos(2.26952 + a * 2.96895);
	L0 += 61951 * cos(2.85099 + a * 11.04570);
	L0 += 26469 * cos(3.14152 + a * 71.81265 );
	L0 += 25711 * cos(6.11380 + a * 454.90937 );

	L1 += 7502543122 * cos(0.0 + a * 0.0);
	L1 += 154458 * cos(5.242017 + a * 74.7815986); //74.781599); //BUG?
	L1 += 24456 * cos(1.71256 + a * 1.4844727); //1.48447); //BUG?
	L1 += 9258 * cos(0.4284 + a * 73.297126); //11.0457); //BUG?
	L1 += 8266 * cos(1.5022 + a * 149.563197); //63.7359); //BUG?
	L1 += 7842 * cos(1.3198 + a * 63.7359); //149.5632); //BUG?

	L2 += 53033 * cos(0.0 + a * 0.0);
	L2 += 2358 * cos(2.2601 + a * 74.7816);

	res = (L0 + L1 * a + L2 * a*a + L3 * a*a*a + L4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 18160 - todo */
double uranus_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 1346278 * cos(2.6187781 + a * 74.7815986);
	B0 += 62341 * cos(5.08111 + a * 149.56320);
	B0 += 61601 * cos(3.14159 + a * 0.0);
	B0 += 9964 * cos(1.6160 + a * 76.2661);
	B0 += 9926 * cos(0.5763 + a * 73.2971);

	B1 += 206366 * cos(4.123943 + a * 74.781599);
	B1 += 8563 * cos(0.3382 + a * 149.5632);

	B2 += 9212 * cos(5.8004 + a * 74.7816);
	
	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 18748 - todo */
double uranus_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double R4 = 0.0;
	double res = 0.0;
	
	R0 += 1921264848 * cos(0 + a * 0);
	R0 += 88784984 * cos(5.60377527 + a * 74.78159857);
	R0 += 3440836 * cos(0.3283610 + a * 73.2971259);
	R0 += 2055653 * cos(1.7829517 + a * 149.5631971);
	R0 += 649322 * cos(4.522473 + a * 76.266071);
	R0 += 602248 * cos(3.860038 + a * 63.735898);
	R0 += 496404 * cos(1.401399 + a * 454.909367);
	R0 += 338526 * cos(1.580027 + a * 138.517497);

	R1 += 1479896 * cos(3.6720571 + a * 74.7815986);
	R1 += 71212 * cos(6.22601 + a * 63.73590);
	R1 += 68627 * cos(6.13411 + a * 149.56320);
	R1 += 24060 * cos(3.14159 + a * 0);
	R1 += 21468 * cos(2.60177 + a * 76.26607);
	R1 += 20857 * cos(5.24625 + a * 11.04570);

	R2 += 22440 * cos(0.69953 + a * 74.78160);
	R2 += 4727 * cos(1.6990 + a * 63.7359);

	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a + R4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 19118 - todo */
double neptune_ecliptic_longitude(double a)
{
	double L0 = 0.0;
	double L1 = 0.0;
	double L2 = 0.0;
	double L3 = 0.0;
	double L4 = 0.0;
	double res = 0.0;
	
	L0 += 531188633 * cos(0 + a * 0);
	L0 += 1798476 * cos(2.9010127 + a * 38.1330356);
	L0 += 1019728 * cos(0.4858092 + a * 1.4844727);
	L0 += 124532 * cos(4.830081 + a * 36.648563);
	L0 += 42064 * cos(5.41055 + a * 2.96895);
	L0 += 37715 * cos(6.09222 + a * 35.16409);

	L1 += 3837687717 * cos(0 + a * 0);

	L2 += 53893 * cos(0 + a * 0);

	res = (L0 + L1 * a + L2 * a*a + L3 * a*a*a + L4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 196cc - todo */
double neptune_ecliptic_latitude(double a)
{
	double B0 = 0.0;
	double B1 = 0.0;
	double B2 = 0.0;
	double B3 = 0.0;
	double B4 = 0.0;
	double res = 0.0;
	
	B0 += 3088623 * cos(1.4410437 + a * 38.1330356);
	B0 += 27780 * cos(5.91272 + a * 76.26607);
	B0 += 27624 * cos(0 + a * 0);
	B0 += 15448 * cos(3.50877 + a * 39.61751);
	B0 += 15355 * cos(2.52124 + a * 36.64856);

	B1 += 227279 * cos(3.807931 + a * 38.133036);
	
//	B2 += 9691 * cos(5.5712 + a * 38.1330); 
	B2 += 273 * cos(1.107 + a * 38.1330); //BUG!
	
	res = (B0 + B1 * a + B2 * a*a + B3 * a*a*a + B4 * a*a*a*a) / 100000000.0;
		
	return res;
}

/* 19c18 - todo */
double neptune_radius_vector(double a)
{
	double R0 = 0.0;
	double R1 = 0.0;
	double R2 = 0.0;
	double R3 = 0.0;
	double res = 0.0;
	
	R0 += 3007013206 * cos(0 + a * 0); 
	R0 += 27062259 * cos(1.32999459 + a * 38.13303364); //38.13303564); //BUG?
	R0 += 1691764 * cos(3.2518614 + a * 36.6485629);
	R0 += 807831 * cos(5.185928 + a * 1.484473 );
	R0 += 537761 * cos(4.521139 + a * 35.164090);
	R0 += 495726 * cos(1.571057 + a * 491.557929);
	R0 += 274572 * cos(1.845523 + a * 175.166060);

	R1 += 236339 * cos(0.704980 + a * 38.133036);
	R1 += 13220 * cos(3.32015 + a * 1.48447);
	R1 += 8622 * cos(6.2163 + a * 35.1641);

	R2 += 4247 * cos(5.8991 + a * 38.1330);
	
	res = (R0 + R1 * a + R2 * a*a + R3 * a*a*a) / 100000000.0;
		
	return res;
}

/* 1a2d0 - todo */
double func_1a2d0(double a)
{
	double sp120 = 0.0;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	
	sp112 = 34.35 + a * 3034.9057;
	sp104 = 50.08 + a * 1222.1138;
	sp96 = 238.96 + a * 144.96;
	
	#if 0
	sp80 = 1.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 19848454;
	
	sp40 = 1.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * -19798886;
	sp = sp8 + sp48;
	
	sp120 += sp;
	#else
	sp120 += sin(1.0 * sp96 / 180.0 * 3.1415927) * -19798886 + 
		cos(1.0 * sp96 / 180.0 * 3.1415927) * 19848454;
	#endif
	
	#if 0
	sp80 = 2.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 4955707;
	
	sp40 = 2.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * 897499;
	sp = sp8 - sp48;
	sp120 += sp;
	#else
	sp120 += sin(2.0 * sp96 / 180.0 * 3.1415927) * 897499 - 
		cos(2.0 * sp96 / 180.0 * 3.1415927) * 4955707;
	#endif
	
	sp88 = a * 144.96 + 238.956785 + sp120 / 1000000;
	
	return sp88;
}

/* 1a680 - todo */
double func_1a680(double a)
{
	double sp120 = 0.0;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	
	sp112 = 34.35 + a * 3034.9057;
	sp104 = 50.08 + a * 1222.1138;
	sp96 = 238.96 + a * 144.96;
	
	#if 0
	sp80 = 1.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 14974876;
	
	sp40 = 1.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * -5453098;
	sp = sp8 - sp48;
	sp120 += sp;
	#else
	sp120 += sin(1.0 * sp96 / 180.0 * 3.1415927) * -5453098 - 
		cos(1.0 * sp96 / 180.0 * 3.1415927) * 14974876;
	#endif
	
	#if 0
	sp80 = 2.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 1672673;
	
	sp40 = 2.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * 3527363;
	sp = sp8 + sp48;
	sp120 += sp;
	#else
	sp120 += sin(2.0 * sp96 / 180.0 * 3.1415927) * 3527363 + 
		cos(2.0 * sp96 / 180.0 * 3.1415927) * 1672673;
	#endif
	
	#if 0
	sp80 = 3.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 327763;
	
	sp40 = 3.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * -1050939;
	sp = sp8 + sp48;
	sp120 += sp;
	#else
	sp120 += sin(3.0 * sp96 / 180.0 * 3.1415927) * -1050939 + 
		cos(3.0 * sp96 / 180.0 * 3.1415927) * 327763;
	#endif
	
	sp88 = -3.908202 + sp120 / 1000000;
	
	return sp88;
}

/* 1aac4 - todo */
double func_1aac4(double sp128)
{
	//See: https://github.com/engerim42/wmsolar/blob/master/Pluto.cpp
	//See: home.mnet-online.de/reimay/Projects/pc/Astronomie/libaa/AAPluto.cpp
	
	double sp120 = 0.0;
	double sp112;
	double sp104;
	double sp96;
	double sp88;
	
	sp112 = sp128 * 3034.9057 + 34.35;
	sp104 = sp128 * 1222.1138 + 50.08;
	sp96 = sp128 * 144.96 + 238.96;
	
	#if 0
	sp80 = 1.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 0x419070bb90000000;
	sp40 = 1.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * 0x418fe28430000000;
	sp = sp8 + sp48;
	sp120 = sp + sp120;
	#else
	sp120 += sin((1.0 * sp96) / 180.0 * 3.1415927) * 66867334.0 + 
		cos((1.0 * sp96) / 180.0 * 3.1415927) * 68955876.0;
	#endif

	#if 0
	sp80 = 2.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 333765;
	sp40 = 2.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * -11826086;
	sp = sp8 - sp48;
	sp120 = sp + sp120;
	#else
	sp120 += sin((2.0 * sp96) / 180.0 * 3.1415927) * -11826086 -
		cos((2.0 * sp96) / 180.0 * 3.1415927) * 333765;
	#endif
	
	#if 0
	sp80 = 3.0 * sp96;
	sp72 = sp80 / 180.0;
	sp64 = sp72 * 3.1415927;
	sp56 = cos(sp64);
	sp48 = sp56 * 1439953;
	
	sp40 = 3.0 * sp96;
	sp32 = sp40 / 180.0;
	sp24 = sp32 * 3.1415927;
	sp16 = sin(sp24);
	sp8 = sp16 * 1593657;
	sp = sp8 - sp48;
	sp120 += sp;
	#else
	sp120 += sin(3.0 * sp96 / 180.0 * 3.1415927) * 1593657 -
		cos(3.0 * sp96 / 180.0 * 3.1415927) * 1439953;
	#endif
	
	sp88 = 40.7247248 + sp120 / 10000000;
	
	return sp88;
}

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
void get_solar_system_object_equatorial_coordinates(int a, double* pAlpha, double* pDelta)
{
	double Tau/*sp536*/;
	double T/*sp528*/;
	double Lrad/*sp520*/ = 0.0; //Planet's Ecliptic Longitude in Radians
	double Brad/*sp512*/ = 0.0; //Planet's Ecliptic Latitude in Radians
	double R/*sp504*/ = 0.0; //Planet's Radius Vector
	double L/*sp496*/; //Planet's Ecliptic Longitude in Degrees
	double B/*sp488*/; //Planet's Ecliptic Latitude in Degrees
	double L0rad; //sp480; //Earth Ecliptic Longitude in Radians
	double B0rad; //sp472; //Earth Ecliptic Latitude in Radians
	double R0; //sp464; //Earth Radius Vector
	double L0; //sp456; //Earth Ecliptic Longitude in Degrees
	double B0; //sp448; //Earth Ecliptic Latitude in Degrees
	double x/*sp440*/;
	double y/*sp432*/;
	double z/*sp424*/;
	double Epsilon/*sp416*/; //Obliquity of the Ecliptic
	double Lambda/*sp408*/ = 0.0;
	double Beta/*sp400*/;
	double Alpha; //sp392; //Right Ascension
	double Delta; //sp384; //Declination
	double sp376;
	double sp368;
	double sp360;
	double sp352;
	double sp344;
	double sp336;
	double sp328;
	double sp320;
	double AlphaPlutoRadians; //sp312;
	double DeltaPlutoRadians; //sp304;
	double AlphaPluto; //sp296;
	double DeltaPluto; //sp288;
	double sp280 = 0.0;
	double sp272 = 0.0;
	double sp264 = 0.0;
	double sp256 = 0.0;
	double sp248 = 0.0;
	double sp240 = 0.0;
	double sp232 = 0.0;
	double sp224 = 0.0;
	double sp216 = 0.0;
	double sp208 = 0.0;
	double sp200 = 0.0;
	
	/*sp192 =*/ func_7f30(1, 0, Data_40004128.geographicLongitude);
	
	sp376 = Data_40004128.dData_96;
	Tau/*sp536*/ = (sp376 - 2451545.0) / 365250.0;
	T/*sp528*/ = 10.0 * Tau/*sp536*/;
	
	switch (a - 2)
	{
		case 0: //Mercury
			//0x1b6dc
			Lrad/*sp520*/ = mercury_ecliptic_longitude(Tau/*sp536*/);
			Brad/*sp512*/ = mercury_ecliptic_latitude(Tau/*sp536*/);
			R/*sp504*/ = mercury_radius_vector(Tau/*sp536*/);
			//->0x1b8c0
			break;
		
		case 1: //Venus
			//0x1b720
			Lrad/*sp520*/ = venus_ecliptic_longitude(Tau/*sp536*/);
			Brad/*sp512*/ = venus_ecliptic_latitude(Tau/*sp536*/);
			R/*sp504*/ = venus_radius_vector(Tau/*sp536*/);
			//->0x1b8c0
			break;
		
		case 2: //Mars
			//0x1b764
			Lrad/*sp520*/ = mars_ecliptic_longitude(Tau/*sp536*/);
			Brad/*sp512*/ = mars_ecliptic_latitude(Tau/*sp536*/);
			R/*sp504*/ = mars_radius_vector(Tau/*sp536*/);
			//->0x1b8c0
			break;
		
		case 3: //Jupiter
			//0x1b7a8
			Lrad/*sp520*/ = jupiter_ecliptic_longitude(Tau/*sp536*/);
			Brad/*sp512*/ = jupiter_ecliptic_latitude(Tau/*sp536*/);
			R/*sp504*/ = jupiter_radius_vector(Tau/*sp536*/);
			//->0x1b8c0
			break;
		
		case 4: //Saturn
			//0x1b7ec
			Lrad/*sp520*/ = saturn_ecliptic_longitude(Tau/*sp536*/);
			Brad/*sp512*/ = saturn_ecliptic_latitude(Tau/*sp536*/);
			R/*sp504*/ = saturn_radius_vector(Tau/*sp536*/);
			//->0x1b8c0
			break;
		
		case 5: //Uranus
			//0x1b830
			Lrad/*sp520*/ = uranus_ecliptic_longitude(Tau/*sp536*/);
			Brad/*sp512*/ = uranus_ecliptic_latitude(Tau/*sp536*/);
			R/*sp504*/ = uranus_radius_vector(Tau/*sp536*/);
			//->0x1b8c0
			break;
		
		case 6: //Neptune
			//0x1b874
			Lrad/*sp520*/ = neptune_ecliptic_longitude(Tau/*sp536*/);
			Brad/*sp512*/ = neptune_ecliptic_latitude(Tau/*sp536*/);
			R/*sp504*/ = neptune_radius_vector(Tau/*sp536*/);
			//->0x1b8c0
			break;
		
		default:
			//0x1b8b8
			break;
	}
	//1b8c4: Radians to Degrees
	L/*sp496*/ = Lrad/*sp520*/ / 3.1415927 * 180.0;
	B/*sp488*/ = Brad/*sp512*/ / 3.1415927 * 180.0;
	
	L0rad/*sp480*/ = earth_heliocentric_longitude(Tau/*sp536*/);
	B0rad/*sp472*/ = earth_heliocentric_latitude(Tau/*sp536*/);
	R0/*sp464*/ = earth_radius_vector(Tau/*sp536*/);
	
	//Radians to Degrees
	L0/*sp456*/ = L0rad/*sp480*/ * 57.295779513; 
	B0/*sp448*/ = B0rad/*sp472*/ * 57.295779513;
	//->0x1ba40
	while (1)
	{
		//0x1b9cc
		if (L/*sp496*/ < 0.0)
		{
			L/*sp496*/ += 360.0;
			//->0x1ba40
		}
		//0x1ba04
		else if (L/*sp496*/ > 360.0)
		{
			L/*sp496*/ -= 360.0;
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
		if (L0/*sp456*/ < 0.0)
		{
			L0/*sp456*/ += 360.0;
			//->0x1bac0
		}
		//0x1ba84
		else if (L0/*sp456*/ > 360.0)
		{
			L0/*sp456*/ -= 360.0;
			//->0x1bac0
		}
		else
		{
			//0x1babc -> 0x1bac4
			break;
		}
	}
	//1bac8: get rectangular coords of planets
	x/*sp440*/ = R/*sp504*/ * cos(B/*sp488*/ / 180.0 * 3.1415927) * cos(L/*sp496*/ / 180.0 * 3.1415927) - 
		R0/*sp464*/ * cos(B0/*sp448*/ / 180.0 * 3.1415927) * cos(L0/*sp456*/ / 180.0 * 3.1415927);
	//1bc2c
	y/*sp432*/ = R/*sp504*/ * cos(B/*sp488*/ / 180.0 * 3.1415927) * sin(L/*sp496*/ / 180.0 * 3.1415927) - 
		R0/*sp464*/ * cos(B0/*sp448*/ / 180.0 * 3.1415927) * sin(L0/*sp456*/ / 180.0 * 3.1415927);
	//1bd90: get geocentric longitude lambda
	z/*sp424*/ = R/*sp504*/ * sin(B/*sp488*/ / 180.0 * 3.1415927) - 
		R0/*sp464*/ * sin(B0/*sp448*/ / 180.0 * 3.1415927);
	//1be4c
	Lambda/*sp408*/ = atan(y/*sp432*/ / x/*sp440*/); //???
	
	if (x/*sp440*/ < 0)
	{
		//1be84
		Lambda/*sp408*/ += 3.1415927;
	}
	//0x1bea0: get geocentric latitude, beta
	Beta/*sp400*/ = atan(z/*sp424*/ / sqrt(x/*sp440*/ * x/*sp440*/ + y/*sp432*/ * y/*sp432*/));
	//1bf20
	Lambda/*sp408*/ = Lambda/*sp408*/ / 3.1415927 * 180.0;
	//1bf54 -> 0x1bfcc
	while (1)
	{
		//0x1bf58
		if (Lambda/*sp408*/ < 0.0)
		{
			Lambda/*sp408*/ += 360.0;
			//->0x1bfcc
		}
		//0x1bf90
		else if (Lambda/*sp408*/ > 360.0)
		{
			Lambda/*sp408*/ -= 360.0;
			//->0x1bfcc
		}
		else
		{
			//0x1bfc8 -> 0x1bfd0
			break;
		}
	}
	//1bfd4
	Beta/*sp400*/ = Beta/*sp400*/ / 3.1415927 * 180.0;
	//1c008
	Epsilon/*sp416*/ = 23.4392911111111104105475533288 - 
		46.8150 * T / 3600.0 - 
		0.00059 * T * T / 3600.0 + 
		0.001813 * T * T * T / 3600.0;
	//1c120
	if (a == 1) //Sun
	{
		//1c128
		Lambda/*sp408*/ = L0/*sp456*/ + 180.0;
		//->0x1c164
		while (Lambda/*sp408*/ >= 360.0)
		{
			//0x1c148
			Lambda/*sp408*/ -= 360.0;
		}
		//1c17c
		if (Lambda/*sp408*/ < 0)
		{
			//1c194
			Lambda/*sp408*/ += 360.0;
		}
		//0x1c1b0
		Beta/*sp400*/ = 1.0 * B0/*sp448*/;
	}
	//0x1c1cc
	if (a == 9) //Pluto
	{
		//1c1d4
		sp368 = func_1a2d0(T);
		sp360 = func_1a680(T);
		sp352 = func_1aac4(T);
		
		Lambda/*sp408*/ = L0/*sp456*/;
		//->0x1c240
		while (Lambda/*sp408*/ >= 360.0)
		{
			//0x1c224
			Lambda/*sp408*/ -= 360.0;
		}
		//1c258
		if (Lambda/*sp408*/ < 0.0)
		{
			Lambda/*sp408*/ += 360.0;
		}
		//0x1c28c
		Beta/*sp400*/ = -1.0 * B0/*sp448*/;
		
		sp344 = -1.0 * R0/*sp464*/ * cos(Beta/*sp400*/ / 180.0 * 3.1415927) * 
			cos(Lambda/*sp408*/ / 180.0 * 3.1415927);
		
		sp336 = -1.0 * R0/*sp464*/ * cos(Beta/*sp400*/ / 180.0 * 3.1415927) * 
			sin(Lambda/*sp408*/ / 180.0 * 3.1415927);

		sp328 = -1.0 * R0/*sp464*/ * sin(Beta/*sp400*/ / 180.0 * 3.1415927);
		
		sp344 = 0.00000044036 * sp336/*y*/ + sp344/*x*/ - 0.000000190919 * sp328/*z*/;		

		sp336 = -0.000000479965999999999971489545586012 * sp344 + 
			0.917482137086999993691449617472 * sp336 - 
			0.397777698290199988040427570013 * sp328;
		
		sp328 = 0.397776982901999975883455817893 * sp336 + 0.917482137086999993691449617472 * sp328;

		x/*sp440*/ = cos(sp368 / 180.0 * 3.1415927) * sp352 * 
			cos(sp360 / 180.0 * 3.1415927);

		y/*sp432*/ = (sin(sp368 / 180.0 * 3.1415927) * 
			cos(sp360 / 180.0 * 3.1415927) * 0.917482062000000042623071294656 - 
			sin(sp360 / 180.0 * 3.1415927) * 0.397777156000000020608098338926) * sp352;

		z/*sp424*/ = (sin(sp368 / 180.0 * 3.1415927) * 
			cos(sp360 / 180.0 * 3.1415927) * 0.397777156000000020608098338926 + 
			sin(sp360 / 180.0 * 3.1415927) * 0.917482062000000042623071294656) * sp352;

		sp320 = sqrt((sp344 + x/*sp440*/) * (sp344 + x/*sp440*/) + 
			(sp336 + y/*sp432*/) * (sp336 + y/*sp432*/) + 
			(sp328 + z/*sp424*/) * (sp328 + z/*sp424*/));

		AlphaPlutoRadians = atan((sp336 + y/*sp432*/) / (sp344 + x/*sp440*/));

		if ((sp344 + x/*sp440*/) > 0)
		{
			//1cadc
			AlphaPlutoRadians += 3.1415927;
		}
		//0x1caf8

		DeltaPlutoRadians = asin((sp328 + z/*sp424*/) / sp320);

		AlphaPluto = AlphaPlutoRadians / 3.1415927 * 180.0;

		DeltaPluto = DeltaPlutoRadians / 3.1415927 * 180.0;
		AlphaPluto += 180.0;
		
		if (AlphaPluto > 360.0)
		{
			//1cbd0
			AlphaPluto -= 360.0;
		}
		//0x1cbec
	}
	//0x1cbec
	if (a == 10) //Moon
	{
		//See: https://github.com/openhab/openhab1-addons/blob/master/bundles/binding/org.openhab.binding.astro/src/main/java/org/openhab/binding/astro/internal/calc/MoonCalc.java
		
		//1cbf4
		sp280 = 218.3164591 + 481267.88134236 * T - 
			0.0013268 * T * T + T * T * T / 538841.0 - T * T * T * T / 65194000.0;
		sp280 = func_1af1c(sp280);
		
		sp272 = 297.8502042 + 445267.1115168 * T - 
			0.00163 * T * T + T * T * T / 545868.0 - T * T * T * T / 113065000.0;
		sp272 = func_1af1c(sp272);
		
		sp264 = 357.5291092 + 35999.0502909 * T - 
			0.0001536 * T * T + T * T * T / 24490000.0;
		sp264 = func_1af1c(sp264);
		
		sp256 = 134.9634114 + 477198.8676313 * T - 
			0.008997 * T * T + T * T * T / 69699.0 - T * T * T * T / 14712000.0;
		sp256 = func_1af1c(sp256);
		//1d164		
		sp248 = 93.2720993 + 483202.0175273 * T - 
			0.0034029 * T * T - T * T * T / 3526000 + T * T * T * T / 863310000;
		sp248 = func_1af1c(sp248);
		//1d2bc
		sp240 = 119.75 + 131.849 * T;
		sp240 = func_1af1c(sp240);
		
		sp232 = 53.09 + 479264.29 * T;
		sp232 = func_1af1c(sp232);

		sp224 = 313.45 + 481266.484 * T;
		sp224 = func_1af1c(sp224);
		//1d394
		sp216 = 1.0 - 0.002516 * T - 0.0000074 * T * T;
		
		sp208 = sin(/*0 * sp272*/ sp256 * 0.01745329252) * 6288774.0 + 
			sin((2 * sp272 - sp256) * 0.01745329252) * 1274027.0 + 
			sin(2 * sp272 * /*0 * sp256*/ 0.01745329252) * 658314.0 + 
			sin(/*0 * sp272*/ 2 * sp256 * 0.01745329252) * 213628.0;
			
		sp208 += sin(sp264 * 0.01745329252) * -185116.0 - 
			sin(2 * sp248 * 0.01745329252) * 114332.0 + 
			sin((2 * sp272 - 2 * sp256) * 0.01745329252) * 58793.0 + 
			sin((2 * sp272 - sp264 - sp256) * 0.01745329252) * 57066.0;

		sp208 += sin((2 * sp272 + sp256) * 0.01745329252) * 53322.0 + 
			sin((2 * sp272 - sp264) * 0.01745329252) * 45758.0 - 
			sin((sp264 - sp256) * 0.01745329252) * 40923.0 - 
			sin(sp272 * 0.01745329252) * 34720.0;

		sp208 += sin((sp264 + sp256) * 0.01745329252) * -30383.0 + 
			sin((2 * sp272 - 2 * sp248) * 0.01745329252) * 15327.0 - 
			sin((2 * sp248 + sp256) * 0.01745329252) * 12528.0 + 
			sin((2 * sp248 - sp256) * 0.01745329252) * 10980.0;

		sp200 = sin(sp248 * 0.01745329252) * 5128122.0 + 
			sin((sp256 + sp248) * 0.01745329252) * 280602.0 + 
			sin((sp256 - sp248) * 0.01745329252) * 277693.0 + 
			sin((2 * sp272 - sp248) * 0.01745329252) * 173237.0;

		sp200 += sin((2 * sp272 - sp256 + sp248) * 0.01745329252) * 55413.0 + 
			sin((2 * sp272 - sp256 - sp248) * 0.01745329252) * 46271.0 + 
			sin((2 * sp272 + sp248) * 0.01745329252) * 32573.0 + 
			sin((2 * sp256 + sp248) * 0.01745329252) * 17198.0;

		Lambda/*sp408*/ = sp208 / 1000000 + sp280;
		Lambda/*sp408*/ = func_1af1c(Lambda/*sp408*/);
		
		Beta/*sp400*/ = sp200 / 1000000;
		Beta/*sp400*/ = func_1af1c(Beta/*sp400*/);
	}
	//0x1e0bc
	transform_ecliptical_to_equatorial_coordinates(Lambda/*sp408*/, Beta/*sp400*/, Epsilon/*sp416*/, &Alpha, &Delta);
	
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
	get_solar_system_object_equatorial_coordinates(1, &dData_400032b0_SunRightAscension, &dData_400032b8_SunDeclination); //Sun
	get_solar_system_object_equatorial_coordinates(2, &dData_400032d0, &dData_400032d8); //Mercury
	get_solar_system_object_equatorial_coordinates(3, &dData_400032e0, &dData_400032e8); //Venus
	get_solar_system_object_equatorial_coordinates(4, &dData_400032f0, &dData_400032f8); //Mars
	get_solar_system_object_equatorial_coordinates(5, &dData_40003300, &dData_40003308); //Jupiter
	get_solar_system_object_equatorial_coordinates(6, &dData_40003310, &dData_40003318); //Saturn
	get_solar_system_object_equatorial_coordinates(7, &dData_40003320, &dData_40003328); //Uranus
	get_solar_system_object_equatorial_coordinates(8, &dData_40003330, &dData_40003338); //Neptune
	get_solar_system_object_equatorial_coordinates(9, &dData_40003340, &dData_40003348); //Pluto
	get_solar_system_object_equatorial_coordinates(10, &dData_400032c0, &dData_400032c8); //Moon
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
					func_7e8(0, 1, 1, 21, "*Key:                  ");
					func_7e8(0, 3, 1, 21, "Press the key to cha- ");
					func_7e8(0, 5, 1, 21, "-nge LED illuminance. ");
					func_7e8(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 2:
					//0x1e3e4
					func_7e8(0, 1, 1, 21, "Green Key:             ");
					func_7e8(0, 3, 1, 21, "Press the key to show ");
					func_7e8(0, 5, 1, 21, "and select hitoric    ");
					func_7e8(0, 7, 1, 21, "target quickly.       ");
					//->0x1eb90
					break;
				
				case 3:
					//0x1e580
					func_7e8(0, 1, 1, 21, "Red Key:               ");
					func_7e8(0, 3, 1, 21, "Show function menu    ");
					func_7e8(0, 5, 1, 21, "or Enter.             ");
					func_7e8(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 4:
					//0x1e5f8
					func_7e8(0, 1, 1, 21, "Yellow Key:            ");
					func_7e8(0, 3, 1, 21, "Press the key to stop ");
					func_7e8(0, 5, 1, 21, "or abandon or quit.   ");
					func_7e8(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 5:
					//0x1e670
					func_7e8(0, 1, 1, 21, "Arrow Keys:            ");
					func_7e8(0, 3, 1, 21, "Slew the telescope    ");
					func_7e8(0, 5, 1, 21, "or Scroll in menu.    ");
					func_7e8(0, 7, 1, 21, "                      ");
					//->0x1eb90
					break;
				
				case 6:
					//0x1e6e8
					func_7e8(0, 1, 1, 21, "Number Keys:            ");
					func_7e8(0, 3, 1, 21, "Press to input digits  ");
					func_7e8(0, 5, 1, 21, "0 to 9, input letter   ");
					func_7e8(0, 7, 1, 21, "or Change slew speed.  ");
					//->0x1eb90
					break;
				
				case 7:
					//0x1e89c
					func_7e8(0, 1, 1, 21, "Stop Key:               ");
					func_7e8(0, 3, 1, 21, "Press to pause when    ");
					func_7e8(0, 5, 1, 21, "telescope in tracking, ");
					func_7e8(0, 7, 1, 21, "moving or slewing.     ");
					//->0x1eb90
					break;
				
				case 8:
					//0x1e914
					func_7e8(0, 1, 1, 21, "Help Key:               ");
					func_7e8(0, 3, 1, 21, "Show help file         ");
					func_7e8(0, 5, 1, 21, "can be used in all     ");
					func_7e8(0, 7, 1, 21, "levels menu.           ");
					//->0x1eb90
					break;
				
				case 9:
					//0x1e98c
					func_7e8(0, 1, 1, 21, "F+(1 to 9):             ");
					func_7e8(0, 3, 1, 21, "Show historic target   ");
					func_7e8(0, 5, 1, 21, "                       ");
					func_7e8(0, 7, 1, 21, "                       ");
					//->0x1eb90
					break;
				
				case 10:
					//0x1eb18
					func_7e8(0, 1, 1, 21, "F+0                     ");
					func_7e8(0, 3, 1, 21, "Open or close key      ");
					func_7e8(0, 5, 1, 21, "beep                   ");
					func_7e8(0, 7, 1, 21, "                       ");
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
			func_7e8(0, 1, 1, 21, "Telescope align:      ");
			func_7e8(0, 3, 1, 21, "Align Telescop point ");
			func_7e8(0, 5, 1, 21, "Pole-axis aim and    ");
			func_7e8(0, 7, 1, 21, "correct Backlash.    ");
			//->0x20a50
			break;
		
		case 2:
			//0x1ec10
			func_7e8(0, 1, 1, 21, "Target navigation:    ");
			func_7e8(0, 3, 1, 21, "Select Target from   ");
			func_7e8(0, 5, 1, 21, "database or input    ");
			func_7e8(0, 7, 1, 21, "data.                ");
			//->0x20a50
			break;
		
		case 3:
			//0x1ed94
			func_7e8(0, 1, 1, 21, "Utilities Commands:   ");
			func_7e8(0, 3, 1, 21, "Some tools in common ");
			func_7e8(0, 5, 1, 21, "use.                 ");
			func_7e8(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 4:
			//0x1ee0c
			func_7e8(0, 1, 1, 21, "Parameter Setup:      ");
			func_7e8(0, 3, 1, 21, "Setup some parameter ");
			func_7e8(0, 5, 1, 21, "in system.           ");
			func_7e8(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 5:
			//0x1ee84
			func_7e8(0, 1, 1, 21, "One star align:       ");
			func_7e8(0, 3, 1, 21, "Select one star align");
			func_7e8(0, 5, 1, 21, "the telescope point  ");
			func_7e8(0, 7, 1, 21, "by hand.             ");
			//->0x20a50
			break;
		
		case 6:
			//0x1f004
			func_7e8(0, 1, 1, 21, "Two stars align:      ");
			func_7e8(0, 3, 1, 21, "Select two star align");
			func_7e8(0, 5, 1, 21, "the telescope point  ");
			func_7e8(0, 7, 1, 21, "by hand.             ");
			//->0x20a50
			break;
		
		case 7:
			//0x1f07c
			func_7e8(0, 1, 1, 21, "Three star align:      ");
			func_7e8(0, 3, 1, 21, "Select three stars    ");
			func_7e8(0, 5, 1, 21, "align the telescope   ");
			func_7e8(0, 7, 1, 21, "point by hand.        ");
			//->0x20a50
			break;
		
		case 8:
			//0x1f0f4
			func_7e8(0, 1, 1, 21, "Target Sync:           ");
			func_7e8(0, 3, 1, 21, "Synchronizing the     ");
			func_7e8(0, 5, 1, 21, "target parameter with ");
			func_7e8(0, 7, 1, 21, "thetelescope point.   ");
			//->0x20a50
			break;
		
		case 9:
			//0x1f16c
			func_7e8(0, 1, 1, 21, "Pole-Axis Deviation:     ");
			func_7e8(0, 3, 1, 21, "Show the Pole-Axis      ");
			func_7e8(0, 5, 1, 21, "practice Deviation      ");
			func_7e8(0, 7, 1, 21, "through the align.      ");
			//->0x20a50
			break;
		
		case 10:
			//0x1f344
			func_7e8(0, 1, 1, 21, "RA Bklash Correction:     ");
			func_7e8(0, 3, 1, 21, "Correct the backlash     ");
			func_7e8(0, 5, 1, 21, "in RA motor gear.        ");
			func_7e8(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 11:
			//0x1f3bc
			func_7e8(0, 1, 1, 21, "DEC Bklash Correction:    ");
			func_7e8(0, 3, 1, 21, "Correct the backlash     ");
			func_7e8(0, 5, 1, 21, "in DED motor gear.       ");
			func_7e8(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 16:
			//0x1f434
			func_7e8(0, 1, 1, 21, "Solar System:            ");
			func_7e8(0, 3, 1, 21, "Telescope can auto      ");
			func_7e8(0, 5, 1, 21, "point at Planet, Sun,   ");
			func_7e8(0, 7, 1, 21, "Moon.                   ");
			//->0x20a50
			break;
		
		case 17:
			//0x1f5c4
			func_7e8(0, 1, 1, 21, "Constellation:         ");
			func_7e8(0, 3, 1, 21, "Telescope can auto     ");
			func_7e8(0, 5, 1, 21, "point at Constell-     ");
			func_7e8(0, 7, 1, 21, "ation.                  ");
			//->0x20a50
			break;
		
		case 18:
			//0x1f63c
			func_7e8(0, 1, 1, 21, "Famous Star:           ");
			func_7e8(0, 3, 1, 21, "Telescope can auto    ");
			func_7e8(0, 5, 1, 21, "point at all famous   ");
			func_7e8(0, 7, 1, 21, "stars.                ");
			//->0x20a50
			break;
		
		case 19:
			//0x1f6b4
			func_7e8(0, 1, 1, 21, "Messier Catalogue:     ");
			func_7e8(0, 3, 1, 21, "Telescope can auto    ");
			func_7e8(0, 5, 1, 21, "point at all stars in ");
			func_7e8(0, 7, 1, 21, "Messier Catalogue.    ");
			//->0x20a50
			break;
		
		case 20:
			//0x1f838
			func_7e8(0, 1, 1, 21, "NGC Deep Sky:           ");
			func_7e8(0, 3, 1, 21, "Telescope can auto    ");
			func_7e8(0, 5, 1, 21, "point at all stars    ");
			func_7e8(0, 7, 1, 21, "in NGC deep sky.      ");
			//->0x20a50
			break;
		
		case 21:
			//0x1f8b0
			func_7e8(0, 1, 1, 21, "IC Deep Sky:           ");
			func_7e8(0, 3, 1, 21, "Telescope can auto    ");
			func_7e8(0, 5, 1, 21, "point at all stars    ");
			func_7e8(0, 7, 1, 21, "in IC deep sky.       ");
			//->0x20a50
			break;
		
		case 22:
			//0x1f928
			func_7e8(0, 1, 1, 21, "Sh2 Deep Sky:          ");
			func_7e8(0, 3, 1, 21, "Telescope can auto    ");
			func_7e8(0, 5, 1, 21, "point at all stars    ");
			func_7e8(0, 7, 1, 21, "in Sh2 Deep Sky.      ");
			//->0x20a50
			break;
		
		case 23:
			//0x1f9a0
			func_7e8(0, 1, 1, 21, "Bright Stars:         ");
			func_7e8(0, 3, 1, 21, "Telescope can auto   ");
			func_7e8(0, 5, 1, 21, "point at all stars    ");
			func_7e8(0, 7, 1, 21, "in Bright Stars.      ");
			//->0x20a50
			break;
		
		case 24:
			//0x1fa18
			func_7e8(0, 1, 1, 21, "SAO Star:              ");
			func_7e8(0, 3, 1, 21, "Telescope can auto   ");
			func_7e8(0, 5, 1, 21, "point at all stars    ");
			func_7e8(0, 7, 1, 21, "in SAO Star.         ");
			//->0x20a50
			break;
		
		case 25:
			//0x1fbb4
			func_7e8(0, 1, 1, 21, "User-def Object:        ");
			func_7e8(0, 3, 1, 21, "Input sky target        ");
			func_7e8(0, 5, 1, 21, "parameter and save it.  ");
			func_7e8(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 26:
			//0x1fc2c
			func_7e8(0, 1, 1, 21, "Specify Ra Dec:           ");
			func_7e8(0, 3, 1, 21, "Input Target R.a and    ");
			func_7e8(0, 5, 1, 21, "Des ,then point to it.   ");
			func_7e8(0, 7, 1, 21, "                         ");
			//->0x20a50
			break;
		
		case 27:
			//0x1fca4
			func_7e8(0, 1, 1, 21, "Landmarks:             ");
			func_7e8(0, 3, 1, 21, "Input land target     ");
			func_7e8(0, 5, 1, 21, "parameter and save it. ");
			func_7e8(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 28:
			//0x1fd1c
			func_7e8(0, 1, 1, 21, "Current Objects:      ");
			func_7e8(0, 3, 1, 21, "Give planet's,solar  ");
			func_7e8(0, 5, 1, 21, "and lunar rise,      ");
			func_7e8(0, 7, 1, 21, "transit and set time. ");
			//->0x20a50
			break;
		
		case 29:
			//0x1feec
			func_7e8(0, 1, 1, 21, "Object Rise/Set:       ");
			func_7e8(0, 3, 1, 21, "calculate star rise,  ");
			func_7e8(0, 5, 1, 21, "transit and set time. ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 30:
			//0x1ff64
			func_7e8(0, 1, 1, 21, "Lunar Phase:         ");
			func_7e8(0, 3, 1, 21, "Show the lunar phase ");
			func_7e8(0, 5, 1, 21, "                     ");
			func_7e8(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 31:
			//0x1ffdc
			func_7e8(0, 1, 1, 21, "Timer:                 ");
			func_7e8(0, 3, 1, 21, "Count down reminder  ");
			func_7e8(0, 5, 1, 21, "                      ");
			func_7e8(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 32:
			//0x20054
			func_7e8(0, 1, 1, 21, "Alarm:                  ");
			func_7e8(0, 3, 1, 21, "Timeing alarm.         ");
			func_7e8(0, 5, 1, 21, "                       ");
			func_7e8(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 33:
			//0x200cc
			func_7e8(0, 1, 1, 21, "Field Angle Cal:        ");
			func_7e8(0, 3, 1, 21, "Calculate the teles- ");
			func_7e8(0, 5, 1, 21, "cope's field angel.  ");
			func_7e8(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 34:
			//0x2025c
			func_7e8(0, 1, 1, 21, "Magify Power Cal:      ");
			func_7e8(0, 3, 1, 21, "Calculate the teles-  ");
			func_7e8(0, 5, 1, 21, "cope's magify power.  ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 35:
			//0x202d4
			func_7e8(0, 1, 1, 21, "Illumination:          ");
			func_7e8(0, 3, 1, 21, "Set screen illumina-  ");
			func_7e8(0, 5, 1, 21, "tion.                 ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 37:
			//0x2034c
			func_7e8(0, 1, 1, 21, "Parkzen:               ");
			func_7e8(0, 3, 1, 21, "Slew telescope to     ");
			func_7e8(0, 5, 1, 21, "Original Position.    ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 38:
			//0x203c4
			func_7e8(0, 1, 1, 21, "Time and Date:         ");
			func_7e8(0, 3, 1, 21, "Set local time and   ");
			func_7e8(0, 5, 1, 21, "data for system.      ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 39:
			//0x2055c
			func_7e8(0, 1, 1, 21, "Daylight Saving:        ");
			func_7e8(0, 3, 1, 21, "Set Daylight Saving.   ");
			func_7e8(0, 5, 1, 21, "                       ");
			func_7e8(0, 7, 1, 21, "                       ");
			//->0x20a50
			break;
		
		case 40:
			//0x205d4
			func_7e8(0, 1, 1, 21, "Site Setting:            ");
			func_7e8(0, 3, 1, 21, "Select local site       ");
			func_7e8(0, 5, 1, 21, "from database or        ");
			func_7e8(0, 7, 1, 21, "input data.             ");
			//->0x20a50
			break;
		
		case 41:
			//0x2064c
			func_7e8(0, 1, 1, 21, "Sky/ Land:             ");
			func_7e8(0, 3, 1, 21, "Select sky or land    ");
			func_7e8(0, 5, 1, 21, "mode                  ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 42:
			//0x206c4
			func_7e8(0, 1, 1, 21, "AZ/EQ:                 ");
			func_7e8(0, 3, 1, 21, "Set mount mode to be  ");
			func_7e8(0, 5, 1, 21, "AZ or EQ mode.        ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 43:
			//0x20870
			func_7e8(0, 1, 1, 21, "Telescope Zero:        ");
			func_7e8(0, 3, 1, 21, "Set telescope Origin- ");
			func_7e8(0, 5, 1, 21, "al Position.          ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 44:
			//0x208e8
			func_7e8(0, 1, 1, 21, "Tracking Rate:         ");
			func_7e8(0, 3, 1, 21, "Set telescope track   ");
			func_7e8(0, 5, 1, 21, "speed.                ");
			func_7e8(0, 7, 1, 21, "                      ");
			//->0x20a50
			break;
		
		case 45:
			//0x20960
			func_7e8(0, 1, 1, 21, "Language:             ");
			func_7e8(0, 3, 1, 21, "Select the menu      ");
			func_7e8(0, 5, 1, 21, "language.            ");
			func_7e8(0, 7, 1, 21, "                     ");
			//->0x20a50
			break;
		
		case 46:
			//0x209d8
			func_7e8(0, 1, 1, 21, "Reset:                ");
			func_7e8(0, 3, 1, 21, "All parameter resume ");
			func_7e8(0, 5, 1, 21, "to the leave factory ");
			func_7e8(0, 7, 1, 21, "state.               ");
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
void func_20b94(void)
{
	func_7e8(0, 1, 1, strlen(Data_40003360), (unsigned char*)Data_40003360);
	func_7e8(0, 1, 14, strlen(Data_40003364), (unsigned char*)Data_40003364);
	
	if (bData_400031ea == 1)
	{
		if (bData_400031eb == 0)
		{
			//20c18
			func_7e8(0, 2, 1, 22, ">>>>synchronizing<<<<");
			
			bData_400031eb = 1;
		}
		else
		{
			//0x20c44
			func_7e8(0, 2, 1, 22, "                      ");
			
			bData_400031eb = 0;
		}
	}
	else
	{
		//0x20c70
			func_7e8(0, 2, 1, 22, "                      ");		
	}
	//0x20c8c
	func_7e8(0, 3, 1, strlen(Data_40003370), Data_40003370);
	func_7e8(0, 3, 6, 9, Data_40003374);
	func_7e8(0, 3, 16, 2, Data_40003374 + 10);
	func_7e8(0, 3, 19, 2, Data_40003374 + 13);
	
	lcd_display_bitmap(0, 3, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 3, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 3, 21, (unsigned char*)cBitmapSecond);
	
	if (abs(Data_40002e18_SiteLongitudeDegrees) < 100)
	{
		func_7e8(0, 3, 12, 1, " ");
	}
	
	if (abs(Data_40002e18_SiteLongitudeDegrees) < 10)
	{
		func_7e8(0, 3, 13, 1, " ");
	}
	
	if (abs(Data_40002e1c_SiteLongitudeMinutes) < 10)
	{
		func_7e8(0, 3, 16, 1, " ");
	}
	
	if (abs(fData_40002e20_SiteLongitudeSeconds) < 10)
	{
		func_7e8(0, 3, 19, 1, " ");
	}
	
	func_7e8(0, 4, 1, strlen(Data_40003378), Data_40003378);
	func_7e8(0, 4, 6, 9, Data_4000337c);
	func_7e8(0, 4, 16, 2, Data_4000337c + 10);
	func_7e8(0, 4, 19, 2, Data_4000337c + 13);
	
	lcd_display_bitmap(0, 4, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 4, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 4, 21, (unsigned char*)cBitmapSecond);
	
	if (abs(Data_40002e38_SiteLatitudeDegrees) < 100)
	{
		func_7e8(0, 4, 12, 1, " ");
	}
	
	if (abs(Data_40002e38_SiteLatitudeDegrees) < 10)
	{
		func_7e8(0, 4, 13, 1, " ");
	}
	
	if (abs(Data_40002e3c_SiteLatitudeMinutes) < 10)
	{
		func_7e8(0, 4, 16, 1, " ");
	}
	
	if (abs(fData_40002e40_SiteLatitudeSeconds) < 10)
	{
		func_7e8(0, 4, 19, 1, " ");
	}
	
	func_7e8(0, 5, 1, strlen(Data_40003380), Data_40003380);
	func_7e8(0, 5, 6, 9, Data_40003384);
	func_7e8(0, 5, 16, 2, Data_40003384 + 10);
	func_7e8(0, 5, 19, 2, Data_40003384 + 13);
	
	if (bData_40002e7a == 0)
	{
		//21138
		lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
		lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
		lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
		
		if (abs(Data_40002d20) < 100)
		{
			func_7e8(0, 5, 12, 1, " ");
		}
		
		if (abs(Data_40002d20) < 10)
		{
			func_7e8(0, 5, 13, 1, " ");
		}

		if (abs(Data_40002d24) < 10)
		{
			func_7e8(0, 5, 16, 1, " ");
		}
		
		if (abs(fData_40002d28) < 10)
		{
			func_7e8(0, 5, 19, 1, " ");
		}
	}
	else
	{
		//0x2127c
		func_7e8(0, 5, 15, 1, "h");
		func_7e8(0, 5, 18, 1, "m");
		func_7e8(0, 5, 21, 1, "s");

		if (Data_40002cd8_ObjectRightAscensionHours < 100)
		{
			func_7e8(0, 5, 12, 1, " ");
		}
		
		if (Data_40002cd8_ObjectRightAscensionHours < 10)
		{
			func_7e8(0, 5, 13, 1, " ");
		}
		
		if (Data_40002cdc_ObjectRightAscensionMinutes < 10)
		{
			func_7e8(0, 5, 16, 1, " ");
		}
		
		if (fData_40002ce0_ObjectRightAscensionSeconds < 10)
		{
			func_7e8(0, 5, 19, 1, " ");
		}
	}
	//0x213c8
	func_7e8(0, 6, 1, strlen(Data_40003388), Data_40003388);
	func_7e8(0, 6, 6, 9, Data_4000338c);
	func_7e8(0, 6, 16, 2, Data_4000338c + 10);
	func_7e8(0, 6, 19, 2, Data_4000338c + 13);
	
	lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
	
	if (bData_40002e7a == 0)
	{
		//214ac
		if (abs(Data_40002d48) < 10)
		{
			func_7e8(0, 6, 13, 1, " ");
		}
		
		if (abs(Data_40002d4c) < 10)
		{
			func_7e8(0, 6, 16, 1, " ");
		}
		
		if (abs(fData_40002d50) < 10)
		{
			func_7e8(0, 6, 19, 1, " ");
		}
	}
	else
	{
		//0x21574
		if (abs(Data_40002d00_ObjectDeclinationDegrees) < 10)
		{
			func_7e8(0, 6, 13, 1, " ");
		}
		
		if (abs(Data_40002d04_ObjectDeclinationMinutes) < 10)
		{
			func_7e8(0, 6, 16, 1, " ");
		}

		if (abs(fData_40002d08_ObjectDeclinationSeconds) < 10)
		{
			func_7e8(0, 6, 19, 1, " ");
		}
	}
	//0x21638
	func_7e8(0, 7, 1, strlen(Data_40003390), Data_40003390);
	func_7e8(0, 7, 6, 9, Data_40003394);
	func_7e8(0, 7, 16, 2, Data_40003394 + 10);
	func_7e8(0, 7, 19, 2, Data_40003394 + 13);
	
	if ((bData_400034b4 == 1) &&
		(bData_40002e88 == 2))
	{
		//216f0
		if (bData_40002e7a == 0)
		{
			lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
			lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
			lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
			
			if (abs(Data_40002d20) < 100)
			{
				func_7e8(0, 7, 12, 1, " ");
			}
			
			if (abs(Data_40002d20) < 10)
			{
				func_7e8(0, 7, 13, 1, " ");
			}
			
			if (abs(Data_40002d24) < 10)
			{
				func_7e8(0, 7, 16, 1, " ");
			}
			
			if (abs(fData_40002d28) < 10)
			{
				func_7e8(0, 7, 19, 1, " ");
			}
		}
		else
		{
			//0x21844
			func_7e8(0, 7, 15, 1, "h");
			func_7e8(0, 7, 18, 1, "m");
			func_7e8(0, 7, 21, 1, "s");
			
			if (Data_40002cd8_ObjectRightAscensionHours < 100)
			{
				func_7e8(0, 7, 12, 1, " ");
			}
			
			if (Data_40002cd8_ObjectRightAscensionHours < 10)
			{
				func_7e8(0, 7, 13, 1, " ");
			}
			
			if (Data_40002cdc_ObjectRightAscensionMinutes < 10)
			{
				func_7e8(0, 7, 16, 1, " ");
			}
						
			if (fData_40002ce0_ObjectRightAscensionSeconds < 10)
			{
				func_7e8(0, 7, 19, 1, " ");
			}
		}
	}
	else
	{
		//0x21950
		if (bData_40002e7a == 0)
		{
			//21960
			lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
			lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
			lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
			
			if (abs(Data_40002dac) < 100)
			{
				func_7e8(0, 7, 12, 1, " ");
			}
			
			if (abs(Data_40002dac) < 10)
			{
				func_7e8(0, 7, 13, 1, " ");
			}
			
			if (abs(Data_40002db0) < 10)
			{
				func_7e8(0, 7, 16, 1, " ");
			}
			
			if (abs(fData_40002db4) < 10)
			{
				func_7e8(0, 7, 19, 1, " ");
			}
		}
		else
		{
			//0x21aec
			func_7e8(0, 7, 15, 1, "h");
			func_7e8(0, 7, 18, 1, "m");
			func_7e8(0, 7, 21, 1, "s");
			
			if (Data_40002d68 < 100)
			{
				func_7e8(0, 7, 12, 1, " ");
			}
			
			if (Data_40002d68 < 10)
			{
				func_7e8(0, 7, 13, 1, " ");
			}
			
			if (Data_40002d6c < 10)
			{
				func_7e8(0, 7, 16, 1, " ");
			}
			
			if (fData_40002d70 < 10)
			{
				func_7e8(0, 7, 19, 1, " ");
			}
		}
	}
	//0x21bf4
	func_7e8(0, 8, 1, strlen(Data_40003398), Data_40003398);
	func_7e8(0, 8, 6, 9, Data_4000339c);
	func_7e8(0, 8, 16, 2, Data_4000339c + 10);
	func_7e8(0, 8, 19, 2, Data_4000339c + 13);
	
	lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
	
	if ((bData_400034b4 == 1) &&
		(bData_40002e88 == 2))
	{
		if (bData_40002e7a == 0)
		{
			if (abs(Data_40002d48) < 10)
			{
				func_7e8(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002d4c) < 10)
			{
				func_7e8(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002d50) < 10)
			{
				func_7e8(0, 8, 19, 1, " ");
			}
		}
		else
		{
			//0x21dc0
			if (abs(Data_40002d00_ObjectDeclinationDegrees) < 10)
			{
				func_7e8(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002d04_ObjectDeclinationMinutes) < 10)
			{
				func_7e8(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002d08_ObjectDeclinationSeconds) < 10)
			{
				func_7e8(0, 8, 19, 1, " ");
			}
		}
	}
	else
	{
		//0x21e88
		if (bData_40002e7a == 0)
		{
			if (abs(Data_40002de0) < 10)
			{
				func_7e8(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002de4) < 10)
			{
				func_7e8(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002de8) < 10)
			{
				func_7e8(0, 8, 19, 1, " ");
			}
		}
		else
		{
			//0x21f60
			if (abs(Data_40002d8c) < 10)
			{
				func_7e8(0, 8, 13, 1, " ");
			}
			
			if (abs(Data_40002d90) < 10)
			{
				func_7e8(0, 8, 16, 1, " ");
			}
			
			if (abs(fData_40002d94) < 10)
			{
				func_7e8(0, 8, 19, 1, " ");
			}
		}	
	}
}

/* 22060 - todo */
void func_22060(int a, float* pRightAscension, float* pDeclination)
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
			*pRightAscension = dData_400032c0;
			*pDeclination = dData_400032c8;
			Data_4000314c_SolarSystemObjectName = "Moon                       ";
			Data_40003140 = Data_400003d4;
			//->0x22450
			break;
		
		default:
			//0x22448
			break;
	}
}

/* 2245c - todo */
void func_2245c(int a, int b)
{
	switch (a)
	{
		case 11:
			//0x22498: Telescope Align
			switch (b)
			{
				case 1:
					//0x224c0
					Data_40003360 = Data_40002f30;
					Data_40003364 = Data_40002f34;
					Data_40003368 = Data_40002f38;
					Data_4000336c = Data_40002f3c;
					Data_40003370 = Data_40002f40;
					Data_40003374 = Data_40002f44;
					Data_40003378 = Data_40002f48;
					Data_4000337c = Data_40002f4c;
					//->0x227ac
					break;
				
				case 2:
					//0x22548
					Data_40003360 = Data_40002f34;
					Data_40003364 = Data_40002f38;
					Data_40003368 = Data_40002f3c;
					Data_4000336c = Data_40002f40;
					Data_40003370 = Data_40002f44;
					Data_40003374 = Data_40002f48;
					Data_40003378 = Data_40002f4c;
					Data_4000337c = Data_40002f50;
					//->0x227ac
					break;
				
				case 3:
					//0x225d0
					Data_40003360 = Data_40002f38;
					Data_40003364 = Data_40002f3c;
					Data_40003368 = Data_40002f40;
					Data_4000336c = Data_40002f44;
					Data_40003370 = Data_40002f48;
					Data_40003374 = Data_40002f4c;
					Data_40003378 = Data_40002f50;
					Data_4000337c = Data_40002f54;
					//->0x227ac
					break;
				
				case 4:
					//0x22658
					Data_40003360 = Data_40002f3c;
					Data_40003364 = Data_40002f40;
					Data_40003368 = Data_40002f44;
					Data_4000336c = Data_40002f48;
					Data_40003370 = Data_40002f4c;
					Data_40003374 = Data_40002f50;
					Data_40003378 = Data_40002f54;
					Data_4000337c = Data_40002f58;
					//->0x227ac
					break;
				
				default:
					//227a4
					break;
			}
			//->0x23128
			break;
		
		case 12:
			//0x227b4: Navigation
			switch (b)
			{
				case 1:
					//0x227dc
					Data_40003360 = Data_40002f5c;
					Data_40003364 = Data_40002f60;
					Data_40003368 = Data_40002f64;
					Data_4000336c = Data_40002f68;
					Data_40003370 = Data_40002f6c;
					Data_40003374 = Data_40002f70;
					Data_40003378 = Data_40002f74;
					Data_4000337c = Data_40002f78;
					//->0x22a8c
					break;
				
				case 2:
					//0x22864
					Data_40003360 = Data_40002f60;
					Data_40003364 = Data_40002f64;
					Data_40003368 = Data_40002f68;
					Data_4000336c = Data_40002f6c;
					Data_40003370 = Data_40002f70;
					Data_40003374 = Data_40002f74;
					Data_40003378 = Data_40002f78;
					Data_4000337c = Data_40002f7c;
					//->0x22a8c
					break;
				
				case 3:
					//0x228ec
					Data_40003360 = Data_40002f64;
					Data_40003364 = Data_40002f68;
					Data_40003368 = Data_40002f6c;
					Data_4000336c = Data_40002f70;
					Data_40003370 = Data_40002f74;
					Data_40003374 = Data_40002f78;
					Data_40003378 = Data_40002f7c;
					Data_4000337c = Data_40002f80;
					//->0x22a8c
					break;
				
				case 4:
					//0x22974
					Data_40003360 = Data_40002f68;
					Data_40003364 = Data_40002f6c;
					Data_40003368 = Data_40002f70;
					Data_4000336c = Data_40002f74;
					Data_40003370 = Data_40002f78;
					Data_40003374 = Data_40002f7c;
					Data_40003378 = Data_40002f80;
					Data_4000337c = Data_40002f84;
					//->0x22a8c
					break;
				
				case 5:
					//0x229fc
					Data_40003360 = Data_40002f6c;
					Data_40003364 = Data_40002f70;
					Data_40003368 = Data_40002f74;
					Data_4000336c = Data_40002f78;
					Data_40003370 = Data_40002f7c;
					Data_40003374 = Data_40002f80;
					Data_40003378 = Data_40002f84;
					Data_4000337c = Data_40002f88;
					//->0x22a8c
					break;
				
				default:
					//0x22a84
					break;
			}
			break;
		
		case 13:
			//0x22a94: Utilities
			switch (b)
			{
				case 1:
					//0x22ab4
					Data_40003360 = Data_40002f8c;
					Data_40003364 = Data_40002f90;
					Data_40003368 = Data_40002f94;
					Data_4000336c = Data_40002f98;
					Data_40003370 = Data_40002f9c;
					Data_40003374 = Data_40002fa0;
					Data_40003378 = Data_40002fa4;
					Data_4000337c = Data_40002fa8;
					//->0x22c54
					break;
				
				case 2:
					//0x22b3c
					Data_40003360 = Data_40002f90;
					Data_40003364 = Data_40002f94;
					Data_40003368 = Data_40002f98;
					Data_4000336c = Data_40002f9c;
					Data_40003370 = Data_40002fa0;
					Data_40003374 = Data_40002fa4;
					Data_40003378 = Data_40002fa8;
					Data_4000337c = Data_40002fac;
					//->0x22c54
					break;
				
				case 3:
					//0x22bc4
					Data_40003360 = Data_40002f94;
					Data_40003364 = Data_40002f98;
					Data_40003368 = Data_40002f9c;
					Data_4000336c = Data_40002fa0;
					Data_40003370 = Data_40002fa4;
					Data_40003374 = Data_40002fa8;
					Data_40003378 = Data_40002fac;
					Data_4000337c = Data_40002fb0;
					//->0x22c54
					break;
				
				default:
					//0x22c4c
					break;				
			}
			break;
		
		case 14:
			//0x22c5c: Setup
			switch (b)
			{
				case 1:
					//0x22c7c
					Data_40003360 = Data_40002fb4;
					Data_40003364 = Data_40002fb8;
					Data_40003368 = Data_40002fbc;
					Data_4000336c = Data_40002fc0;
					Data_40003370 = Data_40002fc4;
					Data_40003374 = Data_40002fc8;
					Data_40003378 = Data_40002fcc;
					Data_4000337c = Data_40002fd0;
					//->0x22e1c
					break;
				
				case 2:
					//0x22d04
					Data_40003360 = Data_40002fb8;
					Data_40003364 = Data_40002fbc;
					Data_40003368 = Data_40002fc0;
					Data_4000336c = Data_40002fc4;
					Data_40003370 = Data_40002fc8;
					Data_40003374 = Data_40002fcc;
					Data_40003378 = Data_40002fd0;
					Data_4000337c = Data_40002fd4;
					//->0x22e1c
					break;
				
				case 3:
					//0x22d8c
					Data_40003360 = Data_40002fbc;
					Data_40003364 = Data_40002fc0;
					Data_40003368 = Data_40002fc4;
					Data_4000336c = Data_40002fc8;
					Data_40003370 = Data_40002fcc;
					Data_40003374 = Data_40002fd0;
					Data_40003378 = Data_40002fd4;
					Data_4000337c = Data_40002fd8;
					//->0x22e1c
					break;
				
				default:
					//0x22e14
					break;
			}
			break;
		
		case 22:
			//0x22e24
			switch (b)
			{
				case 1:
					//0x22e4c
					Data_40003360 = Data_40002fdc;
					Data_40003364 = Data_40002fe0;
					Data_40003368 = Data_40002fe4;
					Data_4000336c = Data_40002fe8;
					Data_40003370 = Data_40002fec;
					Data_40003374 = Data_40002ff0;
					Data_40003378 = Data_40002ff4;
					Data_4000337c = Data_40002ff8;
					//->0x23074
					break;
				
				case 2:
					//0x22ed4
					Data_40003360 = Data_40002fe0;
					Data_40003364 = Data_40002fe4;
					Data_40003368 = Data_40002fe8;
					Data_4000336c = Data_40002fec;
					Data_40003370 = Data_40002ff0;
					Data_40003374 = Data_40002ff4;
					Data_40003378 = Data_40002ff8;
					Data_4000337c = Data_40002ffc;
					//->0x23074
					break;
				
				case 3:
					//0x22f5c
					Data_40003360 = Data_40002fe4;
					Data_40003364 = Data_40002fe8;
					Data_40003368 = Data_40002fec;
					Data_4000336c = Data_40002ff0;
					Data_40003370 = Data_40002ff4;
					Data_40003374 = Data_40002ff8;
					Data_40003378 = Data_40002ffc;
					Data_4000337c = Data_40003000;
					//->0x23074
					break;
				
				case 4:
					//0x22fe4
					Data_40003360 = Data_40002fe8;
					Data_40003364 = Data_40002fec;
					Data_40003368 = Data_40002ff0;
					Data_4000336c = Data_40002ff4;
					Data_40003370 = Data_40002ff8;
					Data_40003374 = Data_40002ffc;
					Data_40003378 = Data_40003000;
					Data_4000337c = Data_40003004;
					//->0x23074
					break;
				
				default:
					//0x2306c
					break;
			}
			break;
		
		case 23:
			//0x2307c
			switch (b)
			{
				case 1:
					//23088
					Data_40003360 = Data_40003008;
					Data_40003364 = Data_4000300c;
					Data_40003368 = Data_40003010;
					Data_4000336c = Data_40003014;
					Data_40003370 = Data_40003018;
					Data_40003374 = Data_4000301c;
					Data_40003378 = Data_40003020;
					Data_4000337c = Data_40003024;
					//->0x23074
					break;
				
				default:
					//0x23110
					break;
			}
			break;
			
		default:
			break;
	}
}

#include "func_23130.c"

/* 24574 - todo */
void func_24574(void)
{
	dData_40002e28_SiteLongitude = Data_40004128.geographicLongitude;
	dData_40002e48_SiteLatitude = Data_40004128.geographicLatitude;
	Data_40002e54_Zone = Data_40004128.Data_64;
	
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
	
	switch (bData_40002e7a)
	{
		case 0:
			//0x24ab0
			Data_40003378 = "AZ";
			break;
		
		case 1:
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
	
	switch (bData_40002e7b)
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
	
	switch (bData_40002e7a)
	{
		case 0:
			//0x24d0c
			sprintf(Data_40004066, " OBJ: %03d?%02d'%02.0f^", 
				abs(Data_40002d20), abs(Data_40002d24), fabs(fData_40002d28));
			break;
		
		case 1:
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
	
	switch (bData_40002e7c)
	{
		case 0:
			//0x24e04
			Data_40003388 = "Cel";
			break;
			
		case 1:
			//0x24e18
			Data_40003388 = "Sun";
			break;
		
		case 2:
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
	switch (bData_40002e7a)
	{
		case 0:
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
		
		case 1:
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
	switch (bData_40002e7d)
	{
		case 1:
			//0x25158
			Data_40003390 = "1X   ";
			break;
		
		case 2:
			//0x2516c
			Data_40003390 = "2X   ";
			break;
		
		case 3:
			//0x25180
			Data_40003390 = "8X   ";
			break;
		
		case 4:
			//0x25194
			Data_40003390 = "16X  ";
			break;
		
		case 5:
			//0x251a8
			Data_40003390 = "64X  ";
			break;
		
		case 6:
			//0x251bc
			Data_40003390 = "128X";
			break;
		
		case 7:
			//0x251d0
			Data_40003390 = "256X";
			break;
		
		case 8:
			//0x251e4
			Data_40003390 = "512X";
			break;
		
		case 9:
			//0x251f8
			Data_40003390 = "Max ";
			break;
		
		default:
			//0x2520c
			break;
	}
	//25218
	switch (bData_40002e7a)
	{
		case 0:
			//0x25234
			sprintf(Data_400040ba, " OTA: %03d?%02d'%02d^", 
				abs(Data_40002dac), abs(Data_40002db0), abs(fData_40002db4) & 0xff);
			break;
		
		case 1:
			//0x252b0
			sprintf(Data_400040ba, " OTA: %03dh%02dm%02ds", 
				Data_40002d68, Data_40002d6c, abs(fData_40002d70) & 0xff);
			break;
		
		default:
			//0x252fc
			break;
	}
	//0x25304
	Data_40003394 = Data_400040ba;
	
	switch (bData_40002e7a)
	{
		case 0:
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
		
		case 1:
			//0x25518
			if (dData_40002d98 < 0)
			{
				//25534
				sprintf(Data_400040e4, "      -%02d?%02d'%02d      ",
					abs(Data_40002d8c), abs(Data_40002d90), abs(fData_40002d94) & 0xFF);
			}
			else
			{
				//0x255ac
				sprintf(Data_400040e4, "      +%02d?%02d'%02d      ",
					abs(Data_40002d8c), abs(Data_40002d90), abs(fData_40002d94) & 0xFF);
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
		case 0:
			//0x25678
		case 100:
			//0x25680
			Data_40003398 = "Stop";
			break;
		
		case 1:
			//0x25690
			Data_40003398 = "Poin";
			break;
		
		case 2:
			//0x256a4
			Data_40003398 = "Trac";
			break;
		
		case 3:
			//0x256b8
			Data_40003398 = "UdHn";
			break;
		
		default:
			//0x256cc
			Data_40003398 = "Slew";
			break;
	}
	
	if ((bData_400034b4 == 1) &&
		(bData_40002e88 == 2))
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

/* 2575c - todo */
void SwapLanguageStrings(void)
{
	switch (bData_40003196_CurrentLanguage)
	{
		case 1:
			//0x25788
			Data_40002f20 = strEngTelescopeAlign;
			Data_40002f24 = Data_400008bd;
			Data_40002f28 = Data_400008c8;
			Data_40002f2c = Data_400008d2;
			Data_40002f30 = strEngOneStarAlign;
			Data_40002f34 = strEngTwoStarAlign;
			Data_40002f38 = strEngThreeStarAlign;
			Data_40002f3c = Data_40000907;
			Data_40002f40 = Data_40000913;
			Data_40002f44 = Data_40000923;
			Data_40002f48 = Data_40000933;
			Data_40002f4c = "                     ";
		
			Data_40002f5c = strEngSolarSystem;
			Data_40002f60 = strEngConstellation;
			Data_40002f64 = strEngFamousStar;
			Data_40002f68 = strEngMessierCatal;
			Data_40002f6c = strEngNGCCatalog;
			Data_40002f70 = strEngICCatalogue;
			Data_40002f74 = strEngSh2Catalog;
			Data_40002f78 = strEngBrightStarCat;
			Data_40002f7c = strEngSAOStarCatal;
			Data_40002f80 = strEngCustomerObjects;
			Data_40002f84 = strEngInputRAandDEC;
			Data_40002f88 = strEngCustomLandGoal;
			
			Data_40002f8c = strEngCurrentObjects;
			Data_40002f90 = Data_40000a05;
			Data_40002f94 = Data_40000a15;
			Data_40002f98 = Data_40000a27;
			Data_40002f9c = Data_40000a2d;
			Data_40002fa0 = Data_40000a33;
			Data_40002fa4 = Data_40000a40;
			Data_40002fa8 = Data_40000a4f;
			Data_40002fac = Data_40000a60;
			
			Data_40002fb4 = strEngTimeAndDate;
			Data_40002fb8 = Data_40000a7c;
			Data_40002fbc = Data_40000a8c;
			Data_40002fc0 = Data_40000a99;
			Data_40002fc4 = Data_40000aa2;
			Data_40002fc8 = Data_40000aab;
			Data_40002fcc = Data_40000abb;
			Data_40002fd0 = Data_40000ac9;
			Data_40002fd4 = Data_40000ad2;

			Data_40003028 = Data_40000ad8;
			Data_4000302c = Data_40000ae8;
			Data_40003030 = Data_40000af4;
			Data_40003034 = Data_40000aff;
			Data_40003038 = Data_40000b06;
			Data_4000303c = Data_40000b0a;
			Data_40003040 = Data_40000b11;
			Data_40003044 = Data_40000b18;
			Data_40003048 = Data_40000b1f;
			Data_4000304c = Data_40000b23;
			Data_40003050 = Data_40000b4d;
			Data_40003054 = Data_40000b55;
			Data_40003058 = Data_40000b5b;
			Data_4000305c = Data_40000b65;
			Data_40003060 = strEngCountryAndCity;
			Data_40003064 = strEngCustomSite;
			Data_40003068 = Data_40000b8a;
			Data_4000306c = Data_40000b91;
			Data_40003070 = Data_40000b95;
			Data_40003074 = Data_40000b9c;
			Data_40003078 = Data_40000ba3;
			Data_4000307c = Data_40000baa;
			Data_40003080 = Data_40000bae;
			Data_40003084 = Data_40000bb5;
			Data_40003088 = Data_40000bbc;
			Data_4000308c = Data_40000bc7;
			Data_40003090 = Data_40000bd3;
			Data_40003094 = Data_40000bde;
			Data_40003098 = Data_40000bee;
			Data_4000309c = strEngListAlignStars;
			Data_400030a0 = Data_40000c14;
			Data_400030a4 = Data_40000c20;
			Data_400030a8 = Data_40000c35;
			Data_400030ac = Data_40000c4b;
			Data_400030b0 = Data_40000c60;
			Data_400030b4 = Data_40000c7a;
			Data_400030b8 = Data_40000c92;
			Data_400030bc = Data_40000ca6;

			Data_400030cc = Data_40000cbe;			
			Data_400030d0 = Data_40000cd3;
			Data_400030d4 = Data_40000ce8;
			Data_400030d8 = Data_40000cfb;
			Data_400030dc = Data_40000d06;
			Data_400030e0 = Data_40000d1a;
			Data_400030e4 = Data_40000d2f;
			Data_400030e8 = Data_40000d44;
			Data_400030ec = Data_40000d59;
			Data_400030f0 = Data_40000d66;
			Data_400030f4 = Data_40000d7b;
			Data_400030f8 = Data_40000d90;
			Data_400030fc = Data_40000da2;
			Data_40003100 = Data_40000db8;
			Data_40003104 = Data_40000dcf;
			Data_40003108 = Data_40000de3;
			Data_4000310c = Data_40000df9;
			Data_40003110 = Data_40000e0a;
			Data_40003114 = Data_40000e20;

			Data_400030c0 = Data_40000e21;
			Data_400030c4 = Data_40000e38;
			Data_400030c8 = Data_40000e4e;
			//25df4 ->0x2783c
			break;

		case 2:
			//0x26010
			Data_40002f20 = Data_40000e62;
			Data_40002f24 = Data_40000e82;
			Data_40002f28 = Data_40000ea2;
			Data_40002f2c = Data_40000ec2;
			Data_40002f30 = Data_40000ee2;
			Data_40002f34 = Data_40000f02;
			Data_40002f38 = Data_40000f22;
			Data_40002f3c = Data_40000f42;
			Data_40002f40 = Data_40000f62;
			Data_40002f44 = Data_40000f82;
			Data_40002f48 = Data_40000fa2;
		
			Data_40002f5c = Data_40000fc2;
			Data_40002f60 = Data_40000fe2;
			Data_40002f64 = Data_40001002;
			Data_40002f68 = Data_40001022;
			Data_40002f6c = Data_40001042;
			Data_40002f70 = Data_40001062;
			Data_40002f74 = Data_40001082;
			Data_40002f78 = Data_400010a2;
			Data_40002f7c = Data_400010c2;
			Data_40002f80 = Data_400010e2;
			Data_40002f84 = Data_40001102;
			Data_40002f88 = Data_40001122;
			Data_40002f8c = Data_40001142;
			Data_40002f90 = Data_40001162;
			Data_40002f94 = Data_40001182;
			Data_40002f98 = Data_400011a2;
			Data_40002f9c = Data_400011c2;
			Data_40002fa0 = Data_400011e2;
			Data_40002fa4 = Data_40001202;
			Data_40002fa8 = Data_40001222;
			Data_40002fac = Data_40001242;
			
			Data_40002fb4 = Data_40001262;
			Data_40002fb8 = Data_40001282;
			Data_40002fbc = Data_400012a2;
			Data_40002fc0 = Data_400012c2;
			Data_40002fc4 = Data_400012e2;
			Data_40002fc8 = Data_40001302;
			Data_40002fcc = Data_40001322;
			Data_40002fd0 = Data_40001342;
			Data_40002fd4 = Data_40001362;

			Data_40003028 = Data_40000ad8;
			Data_4000302c = Data_40000ae8;
			Data_40003030 = Data_40000af4;
			Data_40003034 = Data_40000aff;
			Data_40003038 = Data_40000b06;
			Data_4000303c = Data_40000b0a;
			Data_40003040 = Data_40000b11;
			Data_40003044 = Data_40000b18;
			Data_40003048 = Data_40000b1f;
			Data_4000304c = Data_40000b23;
			Data_40003050 = Data_40000b4d;
			Data_40003054 = Data_40000b55;
			Data_40003058 = Data_40000b5b;
			Data_4000305c = Data_40000b65;
			Data_40003060 = strEngCountryAndCity;
			Data_40003064 = strEngCustomSite;
			Data_40003068 = Data_40000b8a;
			Data_4000306c = Data_40000b91;
			Data_40003070 = Data_40000b95;
			Data_40003074 = Data_40000b9c;
			Data_40003078 = Data_40000ba3;
			Data_4000307c = Data_40000baa;
			Data_40003080 = Data_40000bae;
			Data_40003084 = Data_40000bb5;
			Data_40003088 = Data_40000bbc;
			Data_4000308c = Data_40000bc7;
			Data_40003090 = Data_40000bd3;
			Data_40003094 = Data_40000bde;
			Data_40003098 = Data_40000bee;
			Data_4000309c = strEngListAlignStars;
			Data_400030a0 = Data_40000c14;
			Data_400030a4 = Data_40000c20;
			Data_400030a8 = Data_40000c35;
			Data_400030ac = Data_40000c4b;
			Data_400030b0 = Data_40000c60;
			Data_400030b4 = Data_40000c7a;
			Data_400030b8 = Data_40000c92;
			Data_400030bc = Data_40000ca6;

			Data_400030cc = Data_40000cbe;			
			Data_400030d0 = Data_40000cd3;
			Data_400030d4 = Data_40000ce8;
			Data_400030d8 = Data_40000cfb;
			Data_400030dc = Data_40000d06;
			Data_400030e0 = Data_40000d1a;
			Data_400030e4 = Data_40000d2f;
			Data_400030e8 = Data_40000d44;
			Data_400030ec = Data_40000d59;
			Data_400030f0 = Data_40000d66;
			Data_400030f4 = Data_40000d7b;
			Data_400030f8 = Data_40000d90;
			Data_400030fc = Data_40000da2;
			Data_40003100 = Data_40000db8;
			Data_40003104 = Data_40000dcf;
			Data_40003108 = Data_40000de3;
			Data_4000310c = Data_40000df9;
			Data_40003110 = Data_40000e0a;
			Data_40003114 = Data_40000e20;

			Data_400030c0 = Data_40000e21;
			Data_400030c4 = Data_40000e38;
			Data_400030c8 = Data_40000e4e;
			//264d0 ->0x2783c
			break;
		
		case 3:
			//0x264d4
			Data_40002f20 = Data_40001382;
			Data_40002f24 = Data_400013a2;
			Data_40002f28 = Data_400013c2;
			Data_40002f2c = Data_400013e2;
			Data_40002f30 = Data_40001402;
			Data_40002f34 = Data_40001422;
			Data_40002f38 = Data_40001442;
			Data_40002f3c = Data_40001462;
			Data_40002f40 = Data_40001482;
			Data_40002f44 = Data_400014a2;
			Data_40002f48 = Data_400014c2;
		
			Data_40002f5c = Data_400014e2;
			Data_40002f60 = Data_40001502;
			Data_40002f64 = Data_40001522;
			Data_40002f68 = Data_40001542;
			Data_40002f6c = Data_40001562;
			Data_40002f70 = Data_40001582;
			Data_40002f74 = Data_400015a2;
			Data_40002f78 = Data_400015c2;
			Data_40002f7c = Data_400015e2;
			Data_40002f80 = Data_40001602;
			Data_40002f84 = Data_40001622;
			Data_40002f88 = Data_40001642;
			Data_40002f8c = Data_40001662;
			Data_40002f90 = Data_40001682;
			Data_40002f94 = Data_400016a2;
			Data_40002f98 = Data_400016c2;
			Data_40002f9c = Data_400016e2;
			Data_40002fa0 = Data_40001702;
			Data_40002fa4 = Data_40001722;
			Data_40002fa8 = Data_40001742;
			Data_40002fac = Data_40001762;
			Data_40002fb4 = Data_40001782;
			Data_40002fb8 = Data_400017a2;
			Data_40002fbc = Data_400017c2;
			Data_40002fc0 = Data_400017e2;
			Data_40002fc4 = Data_40001802;
			Data_40002fc8 = Data_40001822;
			Data_40002fcc = Data_40001842;
			Data_40002fd0 = Data_40001862;
			Data_40002fd4 = Data_40001882;

			Data_40003028 = Data_40000ad8;
			Data_4000302c = Data_40000ae8;
			Data_40003030 = Data_40000af4;
			Data_40003034 = Data_40000aff;
			Data_40003038 = Data_40000b06;
			Data_4000303c = Data_40000b0a;
			Data_40003040 = Data_40000b11;
			Data_40003044 = Data_40000b18;
			Data_40003048 = Data_40000b1f;
			Data_4000304c = Data_40000b23;
			Data_40003050 = Data_40000b4d;
			Data_40003054 = Data_40000b55;
			Data_40003058 = Data_40000b5b;
			Data_4000305c = Data_40000b65;
			Data_40003060 = strEngCountryAndCity;
			Data_40003064 = strEngCustomSite;
			Data_40003068 = Data_40000b8a;
			Data_4000306c = Data_40000b91;
			Data_40003070 = Data_40000b95;
			Data_40003074 = Data_40000b9c;
			Data_40003078 = Data_40000ba3;
			Data_4000307c = Data_40000baa;
			Data_40003080 = Data_40000bae;
			Data_40003084 = Data_40000bb5;
			Data_40003088 = Data_40000bbc;
			Data_4000308c = Data_40000bc7;
			Data_40003090 = Data_40000bd3;
			Data_40003094 = Data_40000bde;
			Data_40003098 = Data_40000bee;
			Data_4000309c = strEngListAlignStars;
			Data_400030a0 = Data_40000c14;
			Data_400030a4 = Data_40000c20;
			Data_400030a8 = Data_40000c35;
			Data_400030ac = Data_40000c4b;
			Data_400030b0 = Data_40000c60;
			Data_400030b4 = Data_40000c7a;
			Data_400030b8 = Data_40000c92;
			Data_400030bc = Data_40000ca6;

			Data_400030cc = Data_40000cbe;			
			Data_400030d0 = Data_40000cd3;
			Data_400030d4 = Data_40000ce8;
			Data_400030d8 = Data_40000cfb;
			Data_400030dc = Data_40000d06;
			Data_400030e0 = Data_40000d1a;
			Data_400030e4 = Data_40000d2f;
			Data_400030e8 = Data_40000d44;
			Data_400030ec = Data_40000d59;
			Data_400030f0 = Data_40000d66;
			Data_400030f4 = Data_40000d7b;
			Data_400030f8 = Data_40000d90;
			Data_400030fc = Data_40000da2;
			Data_40003100 = Data_40000db8;
			Data_40003104 = Data_40000dcf;
			Data_40003108 = Data_40000de3;
			Data_4000310c = Data_40000df9;
			Data_40003110 = Data_40000e0a;
			Data_40003114 = Data_40000e20;

			Data_400030c0 = Data_40000e21;
			Data_400030c4 = Data_40000e38;
			Data_400030c8 = Data_40000e4e;
			//26994 ->0x2783c
			break;
		
		case 4:
			//0x26ae0
			Data_40002f20 = Data_400018a2;
			Data_40002f24 = Data_400018c2;
			Data_40002f28 = Data_400018e2;
			Data_40002f2c = Data_40001902;
			Data_40002f30 = Data_40001922;
			Data_40002f34 = Data_40001942;
			Data_40002f38 = Data_40001962;
			Data_40002f3c = Data_40001982;
			Data_40002f40 = Data_400019a2;
			Data_40002f44 = Data_400019c2;
			Data_40002f48 = Data_400019e2;
		
			Data_40002f5c = Data_40001a02;
			Data_40002f60 = Data_40001a22;
			Data_40002f64 = Data_40001a42;
			Data_40002f68 = Data_40001a62;
			Data_40002f6c = Data_40001a82;
			Data_40002f70 = Data_40001aa2;
			Data_40002f74 = Data_40001ac2;
			Data_40002f78 = Data_40001ae2;
			Data_40002f7c = Data_40001b02;
			Data_40002f80 = Data_40001b22;
			Data_40002f84 = Data_40001b42;
			Data_40002f88 = Data_40001b62;
			Data_40002f8c = Data_40001b82;
			Data_40002f90 = Data_40001ba2;
			Data_40002f94 = Data_40001bc2;
			Data_40002f98 = Data_40001be2;
			Data_40002f9c = Data_40001c02;
			Data_40002fa0 = Data_40001c22;
			Data_40002fa4 = Data_40001c42;
			Data_40002fa8 = Data_40001c62;
			Data_40002fac = Data_40001c82;
			Data_40002fb4 = Data_40001ca2;
			Data_40002fb8 = Data_40001cc2;
			Data_40002fbc = Data_40001ce2;
			Data_40002fc0 = Data_40001d02;
			Data_40002fc4 = Data_40001d22;
			Data_40002fc8 = Data_40001d42;
			Data_40002fcc = Data_40001d62;
			Data_40002fd0 = Data_40001d82;
			Data_40002fd4 = Data_40001da2;

			Data_40003028 = Data_40000ad8;
			Data_4000302c = Data_40000ae8;
			Data_40003030 = Data_40000af4;
			Data_40003034 = Data_40000aff;
			Data_40003038 = Data_40000b06;
			Data_4000303c = Data_40000b0a;
			Data_40003040 = Data_40000b11;
			Data_40003044 = Data_40000b18;
			Data_40003048 = Data_40000b1f;
			Data_4000304c = Data_40000b23;
			Data_40003050 = Data_40000b4d;
			Data_40003054 = Data_40000b55;
			Data_40003058 = Data_40000b5b;
			Data_4000305c = Data_40000b65;
			Data_40003060 = strEngCountryAndCity;
			Data_40003064 = strEngCustomSite;
			Data_40003068 = Data_40000b8a;
			Data_4000306c = Data_40000b91;
			Data_40003070 = Data_40000b95;
			Data_40003074 = Data_40000b9c;
			Data_40003078 = Data_40000ba3;
			Data_4000307c = Data_40000baa;
			Data_40003080 = Data_40000bae;
			Data_40003084 = Data_40000bb5;
			Data_40003088 = Data_40000bbc;
			Data_4000308c = Data_40000bc7;
			Data_40003090 = Data_40000bd3;
			Data_40003094 = Data_40000bde;
			Data_40003098 = Data_40000bee;
			Data_4000309c = strEngListAlignStars;
			Data_400030a0 = Data_40000c14;
			Data_400030a4 = Data_40000c20;
			Data_400030a8 = Data_40000c35;
			Data_400030ac = Data_40000c4b;
			Data_400030b0 = Data_40000c60;
			Data_400030b4 = Data_40000c7a;
			Data_400030b8 = Data_40000c92;
			Data_400030bc = Data_40000ca6;
			
			Data_400030cc = Data_40000cbe;
			Data_400030d0 = Data_40000cd3;
			Data_400030d4 = Data_40000ce8;
			Data_400030d8 = Data_40000cfb;
			Data_400030dc = Data_40000d06;
			Data_400030e0 = Data_40000d1a;
			Data_400030e4 = Data_40000d2f;
			Data_400030e8 = Data_40000d44;
			Data_400030ec = Data_40000d59;
			Data_400030f0 = Data_40000d66;
			Data_400030f4 = Data_40000d7b;
			Data_400030f8 = Data_40000d90;
			Data_400030fc = Data_40000da2;
			Data_40003100 = Data_40000db8;
			Data_40003104 = Data_40000dcf;
			Data_40003108 = Data_40000de3;
			Data_4000310c = Data_40000df9;
			Data_40003110 = Data_40000e0a;
			Data_40003114 = Data_40000e20;

			Data_400030c0 = Data_40000e21;
			Data_400030c4 = Data_40000e38;
			Data_400030c8 = Data_40000e4e;
			//26fa0 ->0x2783c
			break;
		
		case 5:
			//0x270d0
			Data_40002f20 = Data_40001dc2;
			Data_40002f24 = Data_40001de2;
			Data_40002f28 = Data_40001e02;
			Data_40002f2c = Data_40001e22;
			Data_40002f30 = Data_40001e42;
			Data_40002f34 = Data_40001e62;
			Data_40002f38 = Data_40001e82;
			Data_40002f3c = Data_40001ea2;
			Data_40002f40 = Data_40001ec2;
			Data_40002f44 = Data_40001ee2;
			Data_40002f48 = Data_40001f02;
		
			Data_40002f5c = Data_40001f22;
			Data_40002f60 = Data_40001f42;
			Data_40002f64 = Data_40001f62;
			Data_40002f68 = Data_40001f82;
			Data_40002f6c = Data_40001fa2;
			Data_40002f70 = Data_40001fc2;
			Data_40002f74 = Data_40001fe2;
			Data_40002f78 = Data_40002002;
			Data_40002f7c = Data_40002022;
			Data_40002f80 = Data_40002042;
			Data_40002f84 = Data_40002062;
			Data_40002f88 = Data_40002082;
			Data_40002f8c = Data_400020a2;
			Data_40002f90 = Data_400020c2;
			Data_40002f94 = Data_400020e2;
			Data_40002f98 = Data_40002102;
			Data_40002f9c = Data_40002122;
			Data_40002fa0 = Data_40002142;
			Data_40002fa4 = Data_40002162;
			Data_40002fa8 = Data_40002182;
			Data_40002fac = Data_400021a2;
			Data_40002fb4 = Data_400021c2;
			Data_40002fb8 = Data_400021e2;
			Data_40002fbc = Data_40002202;
			Data_40002fc0 = Data_40002222;
			Data_40002fc4 = Data_40002242;
			Data_40002fc8 = Data_40002262;
			Data_40002fcc = Data_40002282;
			Data_40002fd0 = Data_400022a2;
			Data_40002fd4 = Data_400022c2;

			Data_40003028 = Data_40000ad8;
			Data_4000302c = Data_40000ae8;
			Data_40003030 = Data_40000af4;
			Data_40003034 = Data_40000aff;
			Data_40003038 = Data_40000b06;
			Data_4000303c = Data_40000b0a;
			Data_40003040 = Data_40000b11;
			Data_40003044 = Data_40000b18;
			Data_40003048 = Data_40000b1f;
			Data_4000304c = Data_40000b23;
			Data_40003050 = Data_40000b4d;
			Data_40003054 = Data_40000b55;
			Data_40003058 = Data_40000b5b;
			Data_4000305c = Data_40000b65;
			Data_40003060 = strEngCountryAndCity;
			Data_40003064 = strEngCustomSite;
			Data_40003068 = Data_40000b8a;
			Data_4000306c = Data_40000b91;
			Data_40003070 = Data_40000b95;
			Data_40003074 = Data_40000b9c;
			Data_40003078 = Data_40000ba3;
			Data_4000307c = Data_40000baa;
			Data_40003080 = Data_40000bae;
			Data_40003084 = Data_40000bb5;
			Data_40003088 = Data_40000bbc;
			Data_4000308c = Data_40000bc7;
			Data_40003090 = Data_40000bd3;
			Data_40003094 = Data_40000bde;
			Data_40003098 = Data_40000bee;
			Data_4000309c = strEngListAlignStars;
			Data_400030a0 = Data_40000c14;
			Data_400030a4 = Data_40000c20;
			Data_400030a8 = Data_40000c35;
			Data_400030ac = Data_40000c4b;
			Data_400030b0 = Data_40000c60;
			Data_400030b4 = Data_40000c7a;
			Data_400030b8 = Data_40000c92;
			Data_400030bc = Data_40000ca6;
		
			Data_400030cc = Data_40000cbe;			
			Data_400030d0 = Data_40000cd3;
			Data_400030d4 = Data_40000ce8;
			Data_400030d8 = Data_40000cfb;
			Data_400030dc = Data_40000d06;
			Data_400030e0 = Data_40000d1a;
			Data_400030e4 = Data_40000d2f;
			Data_400030e8 = Data_40000d44;
			Data_400030ec = Data_40000d59;
			Data_400030f0 = Data_40000d66;
			Data_400030f4 = Data_40000d7b;
			Data_400030f8 = Data_40000d90;
			Data_400030fc = Data_40000da2;
			Data_40003100 = Data_40000db8;
			Data_40003104 = Data_40000dcf;
			Data_40003108 = Data_40000de3;
			Data_4000310c = Data_40000df9;
			Data_40003110 = Data_40000e0a;
			Data_40003114 = Data_40000e20;

			Data_400030c0 = Data_40000e21;
			Data_400030c4 = Data_40000e38;
			Data_400030c8 = Data_40000e4e;
			//27590 ->0x2783c
			break;
		
		default:
			//0x27834
			break;
	}
}


#include "func_27844.c"

#include "func_3d72c.c"

#include "HandleEnterKey.c"

#endif //OLIMEX_LPC2148
