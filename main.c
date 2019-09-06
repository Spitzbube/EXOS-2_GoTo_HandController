
#include <LPC214x.h>
#include "data.h"

extern void uart0_init(int);
extern void uart1_write_byte(char);
extern void uart1_init(int);
extern void uart0_send(unsigned char* a, unsigned char b);
extern void func_394(void);
extern void func_7e8(int, int, int, unsigned char, const unsigned char*);
extern void func_2254(unsigned int);
extern void func_2328(void);
extern void func_243c(int, int, int, char*);
extern void func_24d4(int, int, int, char*);
extern void func_27c4(float*, float*);

extern void func_659c(int);
extern void func_7590(void);
extern void func_75c4(void);
extern void func_7950(int);
extern void func_d2cc(void);
extern void func_acdc(double, double, double*, double*); 
extern void func_b4f0(void);
extern void func_b64c(double, double);

extern void func_5099c(void);
extern void func_51368(void);

extern void func_1e17c(void);

extern char bData_40002c0b; //40002c0b
extern char bData_40002c13; //40002c13
extern char bData_40002c1a; //40002c1a
char bData_40002c58; //40002c58
char bData_40002c5a; //40002c5a
char bData_40002c68; //40002c68
char bData_40002c6a; //40002c6a
double dData_40002c88; //40002c88
double dData_40002c90; //40002c90
double dData_40002c98; //40002c98
double dData_40002ca0; //40002ca0
double dData_40002ca8; //40002ca8
double dData_40002cb0; //40002cb0
int Data_40002cb8; //40002cb8
int Data_40002cbc; //40002cbc
float fData_40002cc0; //40002cc0
int Data_40002cf4; //40002cf4
int Data_40002cf8; //40002cf8
float fData_40002cfc; //40002cfc
int Data_40002d20; //40002d20
int Data_40002d24; //40002d24
float fData_40002d28; //40002d28
int Data_40002d40; //40002d40
int Data_40002d48; //40002d48
int Data_40002d4c; //40002d4c
float fData_40002d50; //40002d50
int Data_40002d68; //40002d68
int Data_40002d6c; //40002d6c
float fData_40002d70; //40002d70
char bData_40002d88; //40002d88
int Data_40002d8c; //40002d8c
int Data_40002d90; //40002d90
float fData_40002d94; //40002d94
char bData_40002da8; //40002da8
int Data_40002dac; //40002dac
int Data_40002db0; //40002db0
float fData_40002db4; //40002db4
int Data_40002de0; //40002de0
int Data_40002de4; //40002de4
float fData_40002de8; //40002de8
int Data_40002e18; //40002e18
int Data_40002e1c; //40002e1c
float fData_40002e20; //40002e20
double dData_40002e28; //40002e28
int Data_40002e34; //40002e34
int Data_40002e38; //40002e38
int Data_40002e3c; //40002e3c
float fData_40002e40; //40002e40
int Data_40002e44; //40002e44
double dData_40002e48; //40002e48
int Data_40002e54; //40002e54
int Data_40002e5c; //40002e5c
char bData_40002e60; //40002e60
char bData_40002e61; //40002e61
char bData_40002e62; //40002e62
char bData_40002e63; //40002e63
char bData_40002e64; //40002e64
char bData_40002e79; //40002e79
char bData_40002e7a; //40002e7a
char bData_40002e7b; //40002e7b
char bData_40002e7c; //40002e7c
unsigned char bData_40002e7d; //40002e7d
char bData_40002e7e; //40002e7e
int Data_40002e80; //40002e80
int Data_40002e84; //40002e84
char bData_40002e88; //40002e88
char bData_40002e89; //40002e89
char bData_40002e8b; //40002e8b
char bData_40002e8c; //40002e8c
int Data_40002e90; //40002e90
int Data_40002e94; //40002e94
float fData_40002e98; //40002e98
int Data_40002e9c; //40002e9c
int Data_40002ea0; //40002ea0
int Data_40002ea4; //40002ea4
float fData_40002ea8; //40002ea8
int Data_40002eac; //40002eac
int Data_40002eb0; //40002eb0
char bData_40002eb4; //40002eb4
char bData_40002eb5; //40002eb5
unsigned short wData_40002eb6; //40002eb6
unsigned short wData_40002eb8; //40002eb8
unsigned short wData_40002eba; //40002eba
unsigned short wData_40002ebc; //40002ebc
unsigned short wData_40002ebe; //40002ebe
unsigned short wData_40002ec0; //40002ec0
int Data_40002ec4; //40002ec4
unsigned short wData_40002ecc; //40002ecc
char bData_40002ece; //40002ece
unsigned short wData_40002ed0; //40002ed0
unsigned char bData_40002ed2; //40002ed2
unsigned short wData_40002ed4; //40002ed4
unsigned short wData_40002ed6; //40002ed6
unsigned short wData_40002ed8; //40002ed8
unsigned short wData_40002eda; //40002eda
char bData_40002ede; //40002ede
char bData_40002edf; //40002edf
char bData_40002ef7; //40002ef7
int Data_40002f04; //40002f04
int Data_40002f08; //40002f08
char bData_40002f0c; //40002f0c
char bData_40002f0d; //40002f0d
int Data_40002f10; //40002f10
char bData_40002f1e; //40002f1e
char bData_4000316e; //4000316e
char bData_40003188; //40003188
char bData_40003189; //40003189
int Data_4000318c; //4000318c
int Data_40003190; //40003190
char bData_40003194; //40003194
char bData_40003195; //40003195
char Data_40003196; //40003196
char bData_40003198; //40003198
char bData_40003199; //40003199
char bData_4000319b; //4000319b
char bData_4000319c; //4000319c
char bData_4000319d; //4000319d
char bData_400031b8; //400031b8
char bData_400031b9; //400031b9
char bData_400031be; //400031be
char bData_400031bf; //400031bf
float fData_400031c0; //400031c0
float fData_400031c4; //400031c4
char bData_400031e0; //400031e0
char bData_400031e1; //400031e1
char bData_400031e9; //400031e9
char bData_400031ea; //400031ea
char bData_400031eb; //400031eb
char bData_400031ec; //400031ec
char bData_400031ed; //400031ed
double dData_400031f0; //400031f0
double dData_400031f8; //400031f8
char bData_40003200; //40003200
char bData_40003201; //40003201
int Data_40003204; //40003204
int Data_40003208; //40003208
char bData_40003210; //40003210
char bData_40003211; //40003211
char bData_4000322d; //4000322d
float Data_4000329c; //4000329c
float Data_400032a0; //400032a0
char bData_400032a4; //400032a4
double dData_400033d8; //400033d8
double dData_400033e0; //400033e0
double dData_40003410; //40003410
double dData_40003418; //40003418
double dData_40003420; //40003420
double dData_40003428; //40003428
char bData_40003431; //40003431
char bData_40003432; //40003432
double dData_40003448; //40003448
double dData_40003450; //40003450
double Data_400034d0; //400034d0
double Data_400034d8; //400034d8
float fData_40003508; //40003508
float fData_4000350c; //4000350c
float fData_40003510; //40003510
float fData_40003514; //40003514
float fData_40003518; //40003518
float fData_4000351c; //4000351c
float fData_40003520; //40003520
int Data_40003524; //40003524
unsigned char bData_40003528; //40003528
unsigned char bData_40003529; //40003529
unsigned char bData_4000352a; //4000352a
unsigned char bData_4000352b; //4000352b
unsigned char bData_4000352c; //4000352c
unsigned char bData_4000352d; //4000352d
unsigned char bData_4000352e; //4000352e
float fData_40003540; //40003540
unsigned char Data_40003588[4]; //40003588
unsigned char Data_40003592[4]; //40003592
Struct_40004128 Data_40004128; //40004128
char Data_40004c58[2 /*???*/]; //40004c58

/* 50b40 - todo */
void func_50b40(void)
{
	//TODO
	//50c98
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;
}

/* 6a2cc - todo */
void func_6a2cc(void)
{
}

/* 6ab74 - todo */
double func_6ab74(int a)
{
	unsigned char r5;
	union
	{
		unsigned char b[4];
		int i;
	} sp8;
	double d;

	bData_40002c13 = 0;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	
	switch (a)
	{
		case 1:
			uart1_write_byte(0x10);
			break;
		
		case 2:
			uart1_write_byte(0x30);
			break;
		
		case 3:
			uart1_write_byte(0x50);
			break;
		
		case 4:
			uart1_write_byte(0x70);
			break;
		
		default:
			break;
	}

	bData_40002c13 = 0;
	
	func_2254(10);
	
	for (r5 = 50; (bData_40002c13 == 0) && (r5 > 2); r5--)
	{
		func_659c(5);
	}
	
	sp8.i = 0;
		
	if (bData_40002c13 == 1)
	{
		switch (a)
		{
			case 1:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  d = sp8.i;
				break;
			
			case 2:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  d = sp8.i;
				break;
			
			case 3:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  d = sp8.i;
				break;
			
			case 4:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  d = sp8.i;
				break;
		}
		
		bData_40002c13 = 0;
	}

	return d;
}

/* 6c804 */
void func_6c804(void)
{
	func_7e8(0, 3, 1, 22, " BRESSER GOTO SYSTEM  ");
	func_7e8(0, 5, 1, 22, "     EXOS EQ v2.3     ");
}

/* 6c848 - todo */
int func_6c848(void)
{
	if (bData_40002c0b == 1)
	{
		bData_4000352d = Data_40003588[0];
		
		switch (bData_4000352d)
		{
			case 35:
				//6c898
			case 36:
				//6c8a0
				Data_40002c28.bData[0] = Data_40003588[1];
				Data_40002c28.bData[1] = Data_40003588[2];
				Data_40002c28.bData[2] = Data_40003588[3];
				Data_40002c28.bData[3] = Data_40003588[4];
				fData_40003510 = *((float*)&Data_40002c28);
			
				Data_40002c28.bData[0] = Data_40003588[5];
				Data_40002c28.bData[1] = Data_40003588[6];
				Data_40002c28.bData[2] = Data_40003588[7];
				Data_40002c28.bData[3] = Data_40003588[8];
				fData_40003514 = *((float*)&Data_40002c28);
				//->6ca60
				break;
			
			case 37:
				//6c92c
				Data_40002c28.bData[0] = Data_40003588[1];
				Data_40002c28.bData[1] = Data_40003588[2];
				Data_40002c28.bData[2] = Data_40003588[3];
				Data_40002c28.bData[3] = Data_40003588[4];
				fData_40003518 = *((float*)&Data_40002c28);
			
				Data_40002c28.bData[0] = Data_40003588[5];
				Data_40002c28.bData[1] = Data_40003588[6];
				Data_40002c28.bData[2] = Data_40003588[7];
				Data_40002c28.bData[3] = Data_40003588[8];
				fData_4000351c = *((float*)&Data_40002c28);
				//->6ca60
				break;
			
			case 38:
				//6c9bc
				Data_40003524 = Data_40003588[1] * 100 + Data_40003588[2]; //year
				bData_40003528 = Data_40003588[3]; //month
				bData_40003529 = Data_40003588[4]; //day
				bData_4000352a = Data_40003588[5]; //hour
				bData_4000352b = Data_40003588[6]; //min
				bData_4000352c = Data_40003588[7]; //sec
				fData_40003520 = (float)Data_40003588[8] - 12;
				//->6ca60
				break;
			
			default:
				//6ca58
				break;
		}
		
		bData_40002c0b = 0;
	}
	//6ca70
	return bData_4000352d;
}

/* 6cb38 - todo */
void func_6cb38(void)
{
	union 
	{
		unsigned char bData[4];
		float fData;
	} sp60, sp56;
	unsigned char sp40[13];
	
	sp40[0] = 0x55;
	sp40[1] = 0xaa;
	sp40[2] = 0x01;
	sp40[3] = 0x09;
	
	bData_4000352d = func_6c848();
	
	switch (bData_4000352d)
	{
		case 29:
			//6cbd8
			func_b4f0();
		
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 30:
			//6cbf0
			func_75c4();
		
			bData_40003431 = 1;
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 31:
			//6cc10
			sp60.fData = dData_40002e28;
			sp56.fData = dData_40002e48;
		
			sp40[4] = 0xfe;
			sp40[5] = sp60.bData[0];
			sp40[6] = sp60.bData[1];
			sp40[7] = sp60.bData[2];
			sp40[8] = sp60.bData[3];
			sp40[9] = sp56.bData[0];
			sp40[10] = sp56.bData[1];
			sp40[11] = sp56.bData[2];
			sp40[12] = sp56.bData[3];
			
			uart0_send(sp40, 13);
		
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 32:
			//6cc98
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 33:
			//6ccac
			if (bData_40002c1a == 1)
			{
				sp40[4] = 0x50;
			}
			else if (bData_40002c1a == 2)
			{
				sp40[4] = 0x41;
			}
			
			uart0_send(sp40, 13);
			
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 34:
			//6cd00
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 35:
			//6cd14
			func_b64c(fData_40003510, fData_40003514);
		
			dData_400031f0 = 0;
			dData_400031f8 = 0;
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 36:
			//6cd7c
			dData_40003410 = dData_400033d8;
			dData_40003418 = -dData_400033e0;
			dData_40003420 = dData_400033d8;
			dData_40003428 = dData_400033e0;
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 37:
			//6cdd4
			bData_40002e89 = 1;
		
			func_b4f0();
		
			dData_40002e28 = fData_40003518;
			dData_40002e48 = fData_4000351c;
			Data_40004128.dData_48 = fData_40003518;
			Data_40004128.dData_56 = fData_4000351c;
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 38:
			//6ce50
			bData_40002e89 = 1;
		
			func_b4f0();
		
			Data_40002e54 = fData_40003520;
			Data_40004128.Data_64 = fData_40003520;
		
			CCR = (1 << 4); //clock from the 32 kHz oscillator that’s connected to the RTCX1 and RTCX2 pins
			YEAR = Data_40003524;
			MONTH = bData_40003528; 
			DOM = bData_40003529;
			HOUR = bData_4000352a;
			MIN = bData_4000352b;
			SEC = bData_4000352c;
			CCR = (1 << 4) | (1 << 0); //CLKEN = 1
		
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 1:
			//6cef8
			if (bData_4000352e > 2)
			{
				//6cf0c
				if (bData_40002c1a == 2)
				{
					//6cf1c
					double sp32, sp24;
					func_acdc(fData_4000350c, fData_40003508, &sp32, &sp24);					
					fData_40003508 = sp32;
					fData_4000350c = sp24;
					dData_40003448 = sp32;
					dData_40003450 = sp24;
				}
				//6cfa8
				sp60.fData = fData_40003508;
				sp56.fData = fData_4000350c;
				
				sp40[4] = 0xff;
				sp40[5] = sp60.bData[0];
				sp40[6] = sp60.bData[1];
				sp40[7] = sp60.bData[2];
				sp40[8] = sp60.bData[3];
				sp40[9] = sp56.bData[0];
				sp40[10] = sp56.bData[1];
				sp40[11] = sp56.bData[2];
				sp40[12] = sp56.bData[3];
				
				uart0_send(sp40, 13);
				
				bData_4000352e = 0;
				//->6d038
			}
			else
			{
				//6d024
				bData_4000352e++;
			}
			//6d038 -> 6d044
			break;
		
		default:
			//6d03c
			break;
	}
}

/* 6d054 - todo */
int main(void)
{
	func_2328();
	uart0_init(360);
	uart1_init(360);
	func_7590();
	func_d2cc();
	func_5099c();
	func_243c(0xdcb, 0, 10, Data_40004c58);
	Data_40003196 = Data_40004c58[0];
	if (Data_40004c58[1] == 1)
	{
		func_51368();
		Data_40004c58[1] = 0;
		func_24d4(0xdcb, 0, 2, Data_40004c58);
	}

	func_6c804();
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x44);

	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x64);
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x04);

	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x24);
	
	func_659c(10);
	
	fData_40002e98 = func_6ab74(1);

	func_659c(50);
	
	fData_40002ea8 = func_6ab74(2);

	func_659c(50);

	if (bData_40002c1a == 1)
	{
		bData_40002e7a = 1;
	}
	else
	{
		bData_40002e7a = 0;
	}
	
	bData_40003432 = 0;
		
	Data_400034d0 = 0.05; //?
	Data_400034d8 = 0.045; //?
	
	Data_40004128.dData_192 = 100.0; //?
	Data_40004128.dData_200 = 60.0; //?
	
	func_27c4(&Data_4000329c, &Data_400032a0);
	
	Data_40004128.dData_192 = Data_4000329c;
	Data_40004128.dData_200 = Data_400032a0;
	
	//TODO
	
	
	//6d364
	if (fData_40003540 > 0)
	{
		//6d378
		int r4;
		int r5;
		
		r4 = (fData_40003540 - (int)fData_40003540) * 60;
		r5 = fData_40003540;
		sprintf(&bData_40002837, "  Lon:E%03dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
		//->6d494
	}
	else
	{
		//6d408
	}
	//6d494
	
	//TODO
	
	//6f8d0
	if (bData_400031ed == 0)
	{
		//6f8e0
		func_394();
		func_7e8(0, 4, 1, 22, "System Initializing...");
		func_1e17c();
		func_659c(1000);
		func_7950(1);
		func_394();
		func_7e8(0, 4, 1, 22, "System Initialized    ");
		func_659c(1000);
		func_394();
		
		bData_400031ed = 1;
	}	
	func_6a2cc();
}


