
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <LPC214x.h>
#include "my_types.h"
#include "data.h"
#include "file_79080.c"


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

void uart1_send(unsigned char* a, unsigned char b)
{
	while (b--)
	{
		uart1_write_byte(*a++);
	}
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

