
#include <stdio.h>
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

extern void func_394(void);
extern void func_3ec(void);
extern void func_49c(int);
extern void spi0_init(void);


int unknown_prologue(void)
{
	int a;
	int b;
	int c;
	int d;
	return a+b * b / b - b % b + b << 21 - c * d;
}

/* 224 - complete */
void func_224(unsigned char a)
{
	unsigned char i;
	
	IOCLR0 |= 0x400;
	IOSET1 |= 0x800000;

	for (i = 0; i < 8; i++)
	{	
		IOCLR0 |= 0x1000;
		if (a & 0x80)
		{
			IOSET0 |= 0x8000;
		}
		else
		{
			IOCLR0 |= 0x8000;
		}
		
		a <<= 1;
		
		IOSET0 |= 0x1000;
	}
	
	IOSET0 |= 0x400;
}
	
/* 2dc - complete */
void func_2dc(unsigned char a)
{
	unsigned char i;
	
	IOCLR0 |= 0x400;
	IOCLR1 |= 0x800000;

	for (i = 0; i < 8; i++)
	{	
		IOCLR0 |= 0x1000;
		if (a & 0x80)
		{
			IOSET0 |= 0x8000;
		}
		else
		{
			IOCLR0 |= 0x8000;
		}
		
		a <<= 1;
		
		IOSET0 |= 0x1000;
	}
	
	IOSET0 |= 0x400;
}

/* 394 - complete */
void func_394(void)
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		func_2dc((i & 0xff) | 0xb0);
		func_2dc(0x00);
		func_2dc(0x10);
		
		for (j = 133; j > 0; j--)
		{
			func_224(0);
		}
	}
}

/* 3ec - complete */
void func_3ec(void)
{
	func_2dc(0xe2);
	func_2dc(0xa2);
	func_2dc(0x26);
	func_2dc(0x2f);
	func_2dc(0x81);
	func_2dc(0x80);
	func_2dc(0xa6);
	func_2dc(0xa4);
	func_2dc(0xc8);
	func_2dc(0xaf);
	func_2dc(0x60);
	
	func_394();

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
void func_49c(int a)
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
void func_53c(unsigned char a)
{
	a = a / 2 + 80;
	func_2dc(0x81);
	func_2dc(a);
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
void func_634(int a, int b, unsigned char c, const unsigned char* d)
{
	char i, j, sl;
	unsigned char sp4[6]; //sp4
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

	func_2dc(((c - 1) * 6 + 1) & 0x0f);
	func_2dc(((((c - 1) * 6 + 1) & 0xf0) >> 4) | 0x10);
	func_2dc(((b - 1) & 0x0f) | 0xb0);

	IO1CLR = 0x2000000;

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
				sp4[j] |= (1 << i);
			}
			else
			{
				sp4[j] &= ~(1 << i);
			}
		}
	}

	for (i = 0; i < 6; i++)
	{
		if (a == 0)
		{
			func_224(sp4[i]);
		}
		else
		{
			func_224(~sp4[i]);
		}
	}

	IO1SET = 0x2000000;
}

/* 7e8 - complete */
void func_7e8(int a, int b, int c, unsigned char d, const unsigned char* e)
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
			func_634(a, b, c + i, &e[i]);
		}
		else
		{
			break;
		}
	}
}

/* 864 - complete */
void func_864(int a, int b, int c, unsigned char* d)
{
	unsigned char i;
	
	func_2dc(((c - 1) * 6 + 1) & 0x0f);
	func_2dc(((((c - 1) * 6 + 1) & 0xf0) >> 4) | 0x10);
	func_2dc(((b - 1) & 0x0f) | 0xb0);
	
	if (a == 0)
	{
		for (i = 0; i < 6; i++)
		{
			func_224(d[i]);
		}
	}
	else
	{
		for (i = 0; i < 6; i++)
		{
			func_224(~d[i]);
		}
	}
}

/* 91c - todo */
unsigned char func_91c(int r4, int r5, int r6, int r7, unsigned short* sp76)
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

	while ((sp = sp76[sp4]) != 0)
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
		
		IO1CLR = 0x2000000;
		
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

		func_2dc((sp12 + 1) & 0x0f);
		func_2dc((((sp12 + 1) & 0xf0) >> 4) | 0x10);
		func_2dc((((r5 - 1) << 1) & 0x0f) | 0xb0);
		
		for (sp8 = 0; sp8 < sl; sp8++)
		{
			if (r4 == 0)
			{
				func_224(sp24[sp8]);
			}
			else
			{
				func_224(~sp24[sp8]);
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

		func_2dc((sp12 + 1) & 0x0f);
		func_2dc((((sp12 + 1) & 0xf0) >> 4) | 0x10);
		func_2dc(((((r5 - 1) << 1) + 1) & 0x0f) | 0xb0);
		
		for (sp8 = 0; sp8 < sl; sp8++)
		{
			if (r4 == 0)
			{
				func_224(sp24[sp8]);
			}
			else
			{
				func_224(~sp24[sp8]);
			}	
		}

		sp4++;
		
		IO1SET = 0x2000000;
	}
	
	IO1SET = 0x2000000;
	
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
void func_17f8(void) __irq
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
void func_19cc(void) __irq
{
	ILR = 3;
	
	bData_40002c06 = 0;
	
	VICVectAddr = 0;
}

/* 19f0 - complete */
void uart1_isr(void) __irq
{
	uart1_bRxData = U1RBR;
	
	if (bData_40002c1a == 0)
	{
		bData_40002c1a = 3;
	}
	
	if (bData_40002c13 == 0)
	{
		switch (bData_40002c14)
		{
			case 0:
				if (bData_40002c15[0] == uart1_bRxData)
				{
					bData_40002c14++;
				}
				break;
			
			case 1:
				if (bData_40002c15[1] == uart1_bRxData)
				{
					bData_40002c14++;
				}
				else
				{
					bData_40002c14 = 0;
				}
				break;
			
			case 2:
				if (bData_40002c15[2] == uart1_bRxData)
				{
					bData_40002c14++;
				}
				else
				{
					bData_40002c14 = 0;
				}
				break;
			
			case 3:
				if (uart1_bRxData < 10)
				{
					bData_40002c15[3] = uart1_bRxData;
					bData_40002c14++;
				}
				else
				{
					bData_40002c14 = 0;
				}
				break;
			
			case 4:
				if (bData_40002c15[3] > bData_40002c12)
				{
					Data_40003592[bData_40002c12] = uart1_bRxData;
					bData_40002c12++;
					if (bData_40002c12 == bData_40002c15[3])
					{
						bData_40002c13 = 1;
						bData_40002c14 = 0;
						bData_40002c12 = 0;
						
						if (!((bData_40002c1a == 1) && (bData_40002c1a == 2)))
						{
							switch (Data_40003592[0])
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
void uart0_isr(void) __irq
{
	uart0_bRxData = U0RBR;
	
	if (bData_40002c0b == 0)
	{
		switch (bData_40002c0c)
		{
			case 0:
				if (bData_40002c0d[0] == uart0_bRxData)
				{
					bData_40002c0c++;
				}
				break;
			
			case 1:
				if (bData_40002c0d[1] == uart0_bRxData)
				{
					bData_40002c0c++;
				}
				else
				{
					bData_40002c0c = 0;
				}
				break;
			
			case 2:
				if (bData_40002c0d[2] == uart0_bRxData)
				{
					bData_40002c0c++;
				}
				else
				{
					bData_40002c0c = 0;
				}
				break;
			
			case 3:
				if (uart0_bRxData < 10)
				{
					bData_40002c0d[3] = uart0_bRxData;
					bData_40002c0c++;
				}
				else
				{
					bData_40002c0c = 0;
				}
				break;
			
			case 4:
				if (bData_40002c0d[3] > bData_40002c0a)
				{
					Data_40003588[bData_40002c0a] = uart0_bRxData;
					bData_40002c0a++;
					if (bData_40002c0d[3] == bData_40002c0a)
					{
						bData_40002c0b = 1;
						bData_40002c0c = 0;
						bData_40002c0a = 0;
						
						switch (Data_40003588[0])
						{
							case 1:
								Data_40002c1c = -1;
								bData_40002c0b = 0;
								break;
							
							case 2:
								Data_40002c1c = 1;
								bData_40002c0b = 0;
								break;
							
							case 4:
								Data_40002c20 = -1;
								bData_40002c0b = 0;
								break;
							
							case 8:
								Data_40002c20 = 1;
								bData_40002c0b = 0;
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
	U0DLM = 0x00;
	U0DLL = 0x48;
	U0LCR = 0x03;
	U0FCR = 0x01; //U0IIR = 0x01;?
	U0IER = 0x01;
	VICVectAddr1 = (unsigned int) uart0_isr;
	
	bData_40002c0a = 0;
	bData_40002c0b = 0;
	bData_40002c0c = 0;
	bData_40002c0d[0] = 0x55;
	bData_40002c0d[1] = 0xaa;
	bData_40002c0d[2] = 0x01;
	bData_40002c0d[3] = 0x00;
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
	U1DLM = 0x00;
	U1DLL = 0x48;
	U1LCR = 0x03;
	U1FCR = 0x01; //
	U1IER = 0x01;
	VICVectAddr2 = (unsigned int) uart1_isr;
	
	bData_40002c12 = 0;
	bData_40002c13 = 0;
	bData_40002c14 = 0;
	bData_40002c15[0] = 0x55;
	bData_40002c15[1] = 0xaa;
	bData_40002c15[2] = 0x01;
	bData_40002c15[3] = 0x00;
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
	VICVectAddr0 = (unsigned int) func_17f8;
	VICIntEnable = 0x10;
	VICVectCntl3 = 0x2d;
	VICVectAddr3 = (unsigned int) func_19cc;
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
void func_2328(void)
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
		(0 <<24) | // P0.12 = GPIO Port 0.12
		(0 <<26) | // P0.13 = GPIO Port 0.13
		(0 <<28) | // P0.14 = GPIO Port 0.14
		(0 <<30);  // P0.15 = GPIO Port 0.15
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
		(1 <<10) | // P0.10 = Out
		(0 <<11) | // P0.11 = In
		(1 <<12) | // P0.12 = Out
		(1 <<13) | // P0.13 = Out
		(0 <<14) | // P0.14 = In
		(1 <<15) | // P0.15 = Out
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
		(1 <<23) | // P1.23 = Out
		(1 <<24) | // P1.24 = Out
		(1 <<25);  // P1.25 = Out
	IO1SET = 1 << 22; //0x00400000; P1.22 = High
	IO0SET = 1 << 13; //0x00002000; P0.13 = High
	IO0CLR = 1 << 16; //0x00010000; P0.16 = Low
	IO1SET = 1 << 24; //0x01000000; P1.24 = High
	IO1SET = 1 << 25; //0x02000000; P1.25 = High
	
	spi0_init();
	func_3ec();
	func_394();
	func_53c(0x80);
	func_49c(0xff);
	
	func_17d0();
	
	bData_40002c08 = 0x10;
	bData_40002c09 = 0x10;
	bData_40002c07 = 0x00;

	func_227c();
}

/* 243c - complete */
void func_243c(unsigned int PageAdr, int b, int Count, unsigned char* Data)
{
	unsigned short i = 0;
	
	IO1CLR = 0x1000000;
	
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
	
	IOSET1 = 0x1000000;
}

/* 24d4 - complete */
void func_24d4(unsigned int PageAdr, unsigned short BufAdr, int Count, unsigned char* Data)
{
	unsigned short i;
	IO1CLR = 0x1000000;

	spi0_write_read_byte(FLASH_CMD_BUF1_WRITE);
	spi0_write_read_byte(0x00);
	spi0_write_read_byte(BufAdr >> 8);
	spi0_write_read_byte(BufAdr & 0xFF);
	
	for (i = 0; i < Count; i++)
	{
		spi0_write_read_byte(Data[i]);
	}
	
	IO1SET = 0x1000000;
	IO1CLR = 0x1000000;
	
	if (PageAdr < 0x1000)
	{
		spi0_write_read_byte(FLASH_CMD_BUF1_TO_MEM);
		spi0_write_read_byte(PageAdr >> (16 - FLASH_PAGE_BITS));
		spi0_write_read_byte(PageAdr << (FLASH_PAGE_BITS - 8));
		spi0_write_read_byte(0);
	}
	
	IO1SET = 0x1000000;
	
	func_2254(5);
}

/* 258c - complete */
void func_258c(int a, unsigned char* b)
{
	unsigned char sp[FLASH_PAGE_SIZE];
	unsigned char i = 0;
	b[0] = 1;

	func_243c((0x37 << 6) | 5, 0, sizeof(sp), sp);

	for (i = 0; i < 24; i++)
	{
		sp[(a - 1)*24 + i] = b[i];
	}

	func_24d4((0x37 << 6) | 5, 0, sizeof(sp), sp);
}

/* 260c - complete */
void func_260c(int a, unsigned char* b)
{
	unsigned char sp[FLASH_PAGE_SIZE];
	unsigned char i = 0;
	b[0] = 1;

	func_243c((0x37 << 6) | 6, 0, sizeof(sp), sp);

	for (i = 0; i < 25; i++)
	{
		sp[25*(a - 1) + i] = b[i];
	}

	func_24d4((0x37 << 6) | 6, 0, sizeof(sp), sp);
}

/* 268c - complete */
void func_268c(unsigned char a, unsigned int b)
{
	unsigned char r6;
	unsigned int r7;
	unsigned char buf[57];

	func_243c((0x37 << 6) | 7, 0, sizeof(buf), buf);

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

		func_24d4((0x37 << 6) | 7, 0, sizeof(buf[0]), buf);
		func_24d4((0x37 << 6) | 7, 8, sizeof(buf) - sizeof(buf[0]), &buf[1]);
		buf[1] = a;
		func_24d4((0x37 << 6) | 7, 1, sizeof(buf[1]), &buf[1]);
		sprintf(buf, "%06d", b);
		func_24d4((0x37 << 6) | 7, 2, 6, &buf[0]);
	}
}

/* 27c4 - complete */
void func_27c4(float* a, float* b)
{
	unsigned char buf[5];

	func_243c((0x37 << 6) | 9, 0, sizeof(buf), buf);

	*a = (buf[0] - '0') * 100.0 + (buf[1] - '0') * 10.0 + buf[2] - '0';
	*b = (buf[3] - '0') * 10.0 + buf[4] - '0';
}

/* 2910 - complete */
void func_2910(int a, int b)
{
	unsigned char buf[5];
	sprintf(buf, "%03d%02d", a, b);
	func_24d4((0x37 << 6) | 9, 0, sizeof(buf), buf);
}

/* 29b0 - complete */
void func_29b0(unsigned char* a, unsigned char* b, unsigned char* c, unsigned char* d)
{
	func_24d4(0xdca, 10, 8, a);
	func_24d4(0xdca, 18, 6, b);
	func_24d4(0xdca, 24, 5, c);
	func_24d4(0xdca, 29, 3, d);
}

/* 2a1c - complete */
void func_2a1c(unsigned char* a, float* b, float* c, int* d)
{
	unsigned char buf[22];
	unsigned char i = 0;
	
	func_243c(0xdca, 10, sizeof(buf), buf);
	
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
	
	func_243c(b, 0, sizeof(buf), buf);
	
	for (i = 0; i < d; i++)
	{
		buf[d * (a % (528 / d)) + c + i] = e[i];
	}
	
	func_24d4(b, 0, sizeof(buf), buf);
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
	
	func_243c(0xFFF, 0, sizeof(buf), buf);
	
	buf[4] = Data_40002c24.bData[0];
	buf[5] = Data_40002c24.bData[1];
	
	func_24d4(0xFFF, 0, sizeof(buf), buf);
}

/* 2f00 - todo */
unsigned short func_2f00(void)
{
	func_243c(0xFFF, 0x04, 2, Data_40002c24.bData);
	
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
	
	func_243c((unsigned short)(0xfde + (a / 33)), fp, sizeof(buf), buf);
	
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

/* 3238 - todo */
void func_3238(int a)
{
	unsigned char buf[528];
	
	if (a > 66)
	{
		return;
	}
	
	Data_40002c24.wData = a;
	
	func_243c(0xfff, 0, sizeof(buf), buf);
	
	buf[8] = Data_40002c24.bData[0];
	buf[9] = Data_40002c24.bData[1];
	
	func_24d4(0xfff, 0, sizeof(buf), buf);
}

/* 32a4 - todo */
int func_32a4(void)
{
	func_243c(0xfff, 0x08, 2, Data_40002c24.bData);
	
	if (Data_40002c24.wData > 66)
	{
		func_3238(0);
		return 0;
	}
	
	return Data_40002c24.wData;
}

/* 32ec - todo */
void func_32ec(int a)
{
	unsigned char buf[528];
	
	if (a > 65)
	{
		return;
	}
	
	Data_40002c24.wData = a;
	
	func_243c(0xfff, 0, sizeof(buf), buf);
	
	buf[10] = Data_40002c24.bData[0];
	buf[11] = Data_40002c24.bData[1];
	
	func_24d4(0xfff, 0, sizeof(buf), buf);
}

/* 3358 - todo */
int func_3358(void)
{
	func_243c(0xfff, 0x0a, 2, Data_40002c24.bData);
	
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
	
	func_243c(fp, sl, sizeof(buf), buf);
	
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

	func_243c((unsigned short)(0x00 + r6), r7, sizeof(buf), buf);
	
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

	func_243c((unsigned short)(0x04 + r6), r7, sizeof(buf), buf);
	
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
	
	func_243c((unsigned short)(0x0b + r6), r7, sizeof(buf), buf);

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
	
	func_243c((unsigned short)(0x27 + r6), r7, sizeof(buf), buf);
	
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
int func_435c(int a, float* b)
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
	
	func_243c((unsigned short)(0x2f + r6), r7, sizeof(buf), buf);
	
	b[0] = buf[0] + buf[1] / 60.0 + buf[2] / 3600.0;
	
	if (buf[3] >= 0x80)
	{
		b[1] = 0x80 - buf[3] - buf[4] / 60.0 - buf[5] / 3600.0;
	}
	else
	{
		b[1] = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
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
	
	func_243c((unsigned short)(0x33 + r6), r7, sizeof(buf), buf);
	
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
	
	func_243c((unsigned short)(0xfb + r6), r7, sizeof(buf), buf);
	
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

/* 4b94 - todo */
int func_4b94(unsigned int a, float* b)
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
	
	func_243c((unsigned short)(0x21e + r6), r7, sizeof(buf), buf);
	
	b[0] = buf[0] + buf[1] / 60.0 + buf[2] / 3600.0;
	
	if (buf[3] >= 0x80)
	{
		b[1] = 0x80 - buf[3] - buf[4] / 60.0 - buf[5] / 3600.0;
	}
	else
	{
		b[1] = buf[3] + buf[4] / 60.0 + buf[5] / 3600.0;
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

	func_243c((unsigned short)(0xd9e + r6), r7, sizeof(buf), buf);

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
int func_4f5c(int a, Struct_4f5c* b)
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
	
	func_243c((unsigned short)(0xdb7 + r6), r7, sizeof(buf), buf);
	
	for (i = 0; i < 18; i++)
	{
		b->bData_0[i-0] = buf[i];
	}
	
	b->bData_0[18] = ' ';
	b->bData_0[19] = 0;
	
	for (i = 18; i < 34; i++)
	{
		b->bData_20[i-18] = buf[i];
	}
	
	b->bData_20[16] = ' ';
	b->bData_20[17] = 0;
	
	if (buf[34] >= 0x80)
	{
		b->fData_40 = ((0x80 - buf[34]) * 100) - buf[35] - buf[36] / 60.0;
	}
	else
	{
		b->fData_40 = (buf[34] * 100) + buf[35] + buf[36] / 60.0;
	}
	
	if (buf[37] >= 0x80)
	{
		b->fData_44 = (0x80 - buf[37]) - buf[38] / 60.0;
	}
	else
	{
		b->fData_44 = buf[37] + buf[38] / 60.0;
	}
	
	if (buf[39] > 0x80)
	{
		b->Data_48 = 0x80 - buf[39];
	}
	else
	{
		b->Data_48 = buf[39];
	}
	
	return 1;
}

/* 5218 - todo */
int func_5218(int a, Struct_5218* b)
{
	unsigned char sp104[22 * 24];
	unsigned char sp80[24];
	unsigned char i;
	
	if ((a == 0) && (a > 10))
	{
		return 0;
	}
	
	func_243c(0xdc5, 0, sizeof(sp104), sp104);
	
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

/* 54e0 - todo */
int func_54e0(int a, Struct_54e0* b)
{
	unsigned char sp108[528];
	unsigned char sp80[25];
	unsigned char i;
	
	if ((a == 0) && (a > 9))
	{
		return 0;
	}
	
	func_243c(0xdc6, 0, sizeof(sp108), sp108);

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
int func_57b8(unsigned char* a, int* b, void* c)
{
	unsigned char buf[57];
	unsigned char i;
	unsigned char r8;
	
	func_243c(0xdc7, 0, sizeof(buf), buf);
	
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
unsigned char func_58ec(float r4, float r5, float r6[][2], unsigned char r7[][10], unsigned char sp304[][22])
{
	int r9; 
	unsigned char sl;
	unsigned char fp;
	
	float sp156[28];
	float sp44[28];
	unsigned char sp24[20]; //size??
	unsigned char sp20;
	float sp16, sp12, sp8, sp4;

	sp156[0] = 6.75850009918212890625;
	sp44[0] = -16.7263050079345703125;
	sp156[1] = 6.40180301666259765625;
	sp44[1] = -52.69824981689453125;
	sp156[2] = 18.620929718017578125;
	sp44[2] = 38.790943145751953125;
	sp156[3] = 14.6703472137451171875;
	sp44[3] = -60.875278472900390625;
	sp156[4] = 14.26785564422607421875;
	sp44[4] = 19.1384716033935546875;
	sp156[5] = 5.288404941558837890625;
	sp44[5] = 46.0066375732421875;
	sp156[6] = 5.248960971832275390625;
	sp44[6] = -8.18952846527099609375;
	sp156[7] = 7.662292003631591796875;
	sp44[7] = 5.204332828521728515625;
	sp156[8] = 1.63397800922393798828125;
	sp44[8] = -57.187053680419921875;
	sp156[9] = 5.09371089935302734375;
	sp44[9] = 7.410167217254638671875;
	sp156[10] = 19.8538360595703125;
	sp44[10] = 8.890472412109375;
	sp156[11] = 4.60669994354248046875;
	sp44[11] = 16.52752685546875;
	sp156[12] = 13.4276142120361328125;
	sp44[12] = -11.2079448699951171875;
	sp156[13] = 16.49939727783203125;
	sp44[13] = -26.4533329010009765625;
	sp156[14] = 22.9691143035888671875;
	sp44[14] = -29.5733890533447265625;
	sp156[15] = 20.6958770751953125;
	sp44[15] = 45.308834075927734375;
	sp156[16] = 10.14705562591552734375;
	sp44[16] = 11.9264163970947265625;
	sp156[17] = 3.41538906097412109375;
	sp44[17] = 49.890056610107421875;
	sp156[18] = 7.5854969024658203125;
	sp44[18] = 31.87105560302734375;
	sp156[19] = 9.46664142608642578125;
	sp44[19] = -8.69580554962158203125;
	sp156[20] = 2.6790111064910888671875;
	sp44[20] = 89.2981109619140625;
	sp156[21] = 0.1473419964313507080078125;
	sp44[21] = 29.136417388916015625;
	sp156[22] = 17.5893688201904296875;
	sp44[22] = 12.55330562591552734375;
	sp156[23] = 11.82501697540283203125;
	sp44[23] = 14.52511119842529296875;
	sp156[24] = 0.953800022602081298828125;
	sp44[24] = 60.759693145751953125;
	sp156[25] = 9.13812732696533203125;
	sp44[25] = -43.468776702880859375;
	sp156[26] = 13.40486621856689453125;
	sp44[26] = 54.884029388427734375;
	sp156[27] = 19.51886749267578125;
	sp44[27] = 27.982250213623046875;
	
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
	r9 = 0;
	sl = 0; 
	for (; r9 < 28; r9++)
	{
		//5d0c
		if ((r4 >= 4) || (r4 <= 20))
		{
			//5d2c
			if ((sp156[r9] >= sp8) && (sp156[r9] <= sp4) &&
				(sp44[r9] >= sp16) && (sp44[r9] <= sp12))
			{
				sp24[sl] = r9;
				sl++;
			}
		}
		else
		{
			//5d90
			if ((r4 <= 4) || (r4 >= 20))
			{
				//5db0
				if (((sp156[r9] >= sp8) && (sp156[r9] <= 24)) ||
					((sp156[r9] >= 0) && (sp156[r9] <= sp4)))
				{
					//5e00
					if ((sp44[r9] >= sp16) && (sp44[r9] <= sp12))
					{
						//5e28
						sp24[sl] = r9;
						sl++;
					}
				}
			}
		}		
	}
	//5e44
	if (sl > 0)
	{
		for (r9 = 0; r9 <= (sl-1); r9++)
		{
			//5e54
			#if 0
			r6[r9][0] = sp156[ sp24[r9] ];
			#else
			((float*)r6)[r9*2] = sp156[ sp24[r9] ];
			#endif
			r6[r9][1] = sp44[ sp24[r9] ];
			
			for (fp = 0; fp < 10; fp++)
			{
				//5e8c
				r7[r9][fp] = Data_40000000[sp24[r9]][fp];
			}
			//5ec0
			for (sp20 = 0; sp20 < 22; sp20++)
			{
				//5ecc
				sp304[r9][sp20] = Data_40000118[sp24[r9]][sp20];
			}
		}		
	}
	//5f2c
	return sl-1;
}

/* 5f40 - todo */
void func_5f40(void)
{
	bData_40002f1e = 1;
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
	Data_40002e18 = 12;
	Data_40002e1c = 7;
	fData_40002e20 = 1.3;
	Data_40002e34 = 1;
	Data_40002e38 = 5;
	Data_40002e3c = 1;
	fData_40002e40 = 8.9;
	Data_40002e44 = 1;
	Data_40002e54 = 8;
	Data_40002e5c = 2010;
	bData_40002e60 = 8;
	bData_40002e61 = 28;
	bData_40002e62 = 18;
	bData_40002e63 = 18;
	bData_40002e64 = 18;
	bData_40002e79 = 0;
	bData_40002e7a = 0;
	bData_40002e7b = 0;
	bData_40002e7d = 5;
	bData_40002e7e = 0;
	bData_40002e88 = 0;
	bData_40002e89 = 1;
	bData_40002e8b = 0;
	bData_40002e8c = 0;
	Data_40002e90 = 0;
	fData_40002e98 = 23.8;
	Data_40002e9c = 0;
	Data_40002e94 = 0;
	Data_40002ea0 = 0;
	fData_40002ea8 = 23.8;
	Data_40002eac = 0;
	Data_40002ea4 = 0;
	Data_40002eb0 = 0;
	bData_40002eb4 = 0;
	bData_40002eb5 = 0;
	wData_40002eb6 = 0;
	wData_40002eb8 = 0;
	wData_40002eba = 0;
	wData_40002ebc = 0;
	wData_40002ebe = 0;
	wData_40002ec0 = 0;
	Data_40002ec4 = 0;
	wData_40002ecc = 0;
	bData_40002ece = 1;
	wData_40002ed0 = 0;
	bData_40002ed2 = 0;
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

/* 6518 - todo */
void func_6518(void)
{
	int r0 = CTIME0;
	int r1 = CTIME1;
	
	Data_40002e5c = (r1 >> 16) & 0x0fff; //Year
	bData_40002e60 = (r1 >> 8) & 0x0f; //Month
	bData_40002e61 = r1 & 0x1f; //Day
	bData_40002e62 = (r0 >> 16) & 0x1f; //Hours
	bData_40002e63 = (r0 >> 8) & 0x3f; //Minutes
	bData_40002e64 = r0 & 0x3f; //Seconds
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
				Data_400033c8.dwData = (0.0 * Data_40004128.dData_176 / 3600.0 - Data_40004128.dData_160) *
					256 / Data_40004128.dData_24;
				//->6818
			}
			else
			{
				//6788
				Data_400033c8.dwData = (0.6 * Data_40004128.dData_176 / 3600.0 - Data_40004128.dData_160) *
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
			if (sp40 < 10.0)
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
			if (sp40 < 10.0)
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

typedef struct
{
	double dData_0; //0
	double dData_8; //8 
	double dData_16; //16
	double dData_24; //24
	double dData_32; //32
	double dData_40; //40
} Struct_7978;

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
void func_8ba4(double sp176, double sp184, Struct_8ba4 b, int r4, int r5, double* r6)
{
	double sp168 = 3.14159265359;
	double sp160 = sp176; 
	double sp152 = sp184; 
	double sp144 = b.dData_0; 
	double sp136 = b.dData_8; 
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
	double sp264;
	double sp256;
	Struct_8ba4 sp224;
	double sp152[9]; //size??
	Struct_7978 sp104;
	double sp88[2];
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
			sp256 = Data_40004128.dData_48;
			sp264 = Data_40004128.dData_56;
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
			sp80 = func_7f30(Data_40004128.Data_40, Data_40004128.bData_44, Data_40004128.dData_48);
			
			fData_400034c8 = sp80;

			func_8ba4(sp256, sp264, sp224, Data_40004128.Data_40, Data_40004128.bData_44, sp152);
			
			sp72 = sp80 - sp224.dData_0;
			
			while (sp72 > 24)
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
				if (sp264 >= 0)
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
			}
			//97dc
			if (bData_40002c1a == 2)
			{
				//97ec
				if (sp264 >= 0)
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
			}
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
			#if 0
			sp48 = 0; //test
			sp88[0] = 0;
			#endif
		}
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




