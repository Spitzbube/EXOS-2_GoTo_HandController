
#include <LPC214x.h>

extern void func_394(void);
extern void func_3ec(void);
extern void func_49c(int);
extern void func_53c(int);
extern void spi0_init(void);
extern char func_604(char);

char bData_40002c00; //40002c00
char bData_40002c01; //40002c01
char bData_40002c02; //40002c02
char bData_40002c04; //40002c04
char bData_40002c07; //40002c07
char bData_40002c08; //40002c08
char bData_40002c09; //40002c09
char bData_40002c0a; //40002c0a
char bData_40002c0b; //40002c0b
char bData_40002c0c; //40002c0c
char bData_40002c0d[4]; //40002c0d
char bData_40002c12; //40002c12
char bData_40002c13; //40002c13
char bData_40002c14; //40002c14
char bData_40002c15[4]; //40002c15

/* 604 - complete */
char func_604(char a)
{
	S0SPDR = a;
	while (!(S0SPSR & 0x80)) {}
	return S0SPDR;
}

/* 17d0 - complete */
void func_17d0(void)
{
	bData_40002c02 = 0;
	bData_40002c01 = 0;
	bData_40002c00 = 0;
	bData_40002c04 = 0;
}

/* 17f8 - todo */
void func_17f8(void) __irq
{
}

/* 19c8 - todo */
void func_19c8(void) __irq
{
}

/* 19f0 - todo */
void uart1_isr(void) __irq
{
}

/* 1c84 - todo */
void uart0_isr(void) __irq
{
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
char uart0_read_byte(void)
{
	char b;
	while (!(U0LSR & 0x01)) {}
  b = U0RBR;
	return b;
}

/* 2054 - complete */
void uart0_receive(char* a, int b)
{
	while (b)
	{
		*a++ = uart0_read_byte();
		b--;
	}
}

/* 2080 - complete */
void uart0_write_byte(char a)
{
	U0THR = a;
	while (!(U0LSR & 0x40)) {}
}

/* 20a0 - nearly complete */
void uart0_send(char* a, char b)
{
	while (b--)
	{
		uart0_write_byte(*a++);
	}
}

/* 20d0 - complete */
void uart0_send_packets(char* a)
{
	char i;
	
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
char uart1_read_byte(void)
{
	char b;
	while (!(U1LSR & 0x01)) {}
	b = U1RBR;
	return b;
}

/* 21bc - complete */
void uart1_receive(char* a, int b)
{
	while (b)
	{
		*a++ = uart1_read_byte();
		b--;
	}
}

/* 21e8 - complete */
void uart1_write_byte(char a)
{
	U1THR = a;
	while (!(U1LSR & 0x40)) {}
}

/* 2208 - complete */
void uart1_send_packets(char* a)
{
	char i;
	
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
	for ( ; a > 1; a--)
	{	unsigned int b;	
		for (/*unsigned int*/ b = 0x0000ffff; b > 1; b--)
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
	VICVectAddr3 = (unsigned int) func_19c8;
	VICIntEnable = 0x2000;
	CIIR = 0x01;
	ILR = 0x03;
	CCR = 0x11;
	VICVectCntl1 = 0x26;
	VICVectCntl2 = 0x27;
	VICIntEnable = 0x80;
	VICIntEnable = 0x40;
}

/* 2328 - todo */
void func_2328(void)
{
	PLL0CON = 0x01;
	VPBDIV = 0;
	PLL0CFG = 0x23;
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	while (!(PLL0STAT & 0x400));
	
	PLL0CON = 0x03;
	PLL0FEED = 0xaa;
	PLL0FEED = 0x55;
	
	MAMCR = 2;
	MAMTIM = 3;
	
	PINSEL0 = 0x00059505;
	PINSEL1 = 0x800046a8;
	PINSEL2 = 0x00000004;
		
	IODIR0 = 0x0001b480;
	IODIR1 = 0x03cf0000;
	IOSET1 = 0x00400000;
	IOSET0 = 0x00002000;
	IOCLR0 = 0x00010000;
	IOSET1 = 0x01000000;
	IOSET1 = 0x02000000;
	
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

/* 243c - todo */
void func_243c(unsigned int a, int b, int c, char* d)
{
	int r4 = 0;
	
	IO1CLR = 0x1000000;
	
	func_604(0xE8);
	func_604(a << 18 >> 24);
	func_604(a << 26 >> 24);
	
	while (r4 < (b+5+c))
	{
		if (r4 < (b+5))
		{
			func_604(0);
		}
		else
		{
			d[r4 - (b+5)] = func_604(0);
		}
		
		r4 = (r4 + 1) & ~0x10000;
	}
	
	IOSET1 = 0x1000000;
}

/* 24d4 - todo */
void func_24d4(int a, int b, int c, char* d)
{
	int i;
	IO1CLR = 0x1000000;

	func_604(0x84);
	func_604(0x00);
	func_604(b >> 8);
	func_604(b & 0xFF);
	
	for (i = 0; i < c; i = (i + 1) & ~0x10000)
	{
		func_604(d[i]);
	}
	
	IO1SET = 0x1000000;
	IO1CLR = 0x1000000;
	
	if (a < 0x1000)
	{
		func_604(0x83);
		func_604(a >> 6); //<< 18 >> 24);
		func_604(a << 26 >> 24);
		func_604(0);
	}
	
	IO1SET = 0x1000000;
	
	func_2254(5);
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

