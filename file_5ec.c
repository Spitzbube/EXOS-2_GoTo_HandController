
#include <LPC214x.h>

/* 224 - todo */
void func_224(unsigned a)
{
	char i;
	
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
		
		a <<= 25;
		a >>= 24;
		
		IOSET0 |= 0x1000;
	}
	
	IOSET0 |= 0x400;
}
	
/* 2dc - todo */
void func_2dc(unsigned a)
{
	char i;
	
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
		
		a = (a << 25) >> 24;
		
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

/* 49c - todo */
void func_49c(int a)
{
	if (a == 0)
	{
		PWMMR5 = 0;		
	}
	else
	{
		PWMMR5 = (PWMMR0 * a) / 0xFF; //???
	}
	
	PWMLER = 0x21;
}
	
/* 4ec - todo */
void func_4ec(int a)
{
	if (a == 0)
	{
		PWMMR5 = 0;		
	}
	else
	{
		PWMMR2 = (PWMMR0 * a) / 0xFF; //???
	}
	
	PWMLER = 0x21;
}
	
/* 53c - todo */
void func_53c(int a)
{
	a = (a / 2 + 80) & 0xff;
	func_2dc(0x81);
	func_2dc(a);
}

/* 5ec - complete */
void spi0_init(void)
{
	S0SPCCR = 0x08;
	S0SPCR = 0x20;
}

#if 0
/* 604 - complete */
char func_604(char a)
{
	S0SPDR = a;
	while (!(S0SPSR & 0x80)) {}
	return S0SPDR;
}

#endif

