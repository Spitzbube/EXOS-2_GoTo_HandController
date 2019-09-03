
#include "my_types.h"
#include "data.h"

extern void func_243c(unsigned int PageAdr, int b, int Count, unsigned char* Data);
extern void func_24d4(unsigned int PageAdr, unsigned short BufAdr, int Count, unsigned char* Data);
extern void func_2df8(int a, int b, int c, int d, unsigned char* e);
extern void func_5f40(void);

extern char bData_40002c1a; //40002c1a
extern union
{
	unsigned char bData[2]; 
	unsigned short wData;
} Data_40002c24; //40002c24
extern union
{
	unsigned char bData[4]; 
	int Data;
} Data_40002c28; //40002c28
extern char bData_40002c58; //40002c58
extern char bData_40002c5a; //40002c5a
extern char bData_40002c68; //40002c68
extern char bData_40002c6a; //40002c6a
extern double dData_40002c88; //40002c88
extern double dData_40002c90; //40002c90
extern double dData_40002c98; //40002c98
extern double dData_40002ca0; //40002ca0
extern double dData_40002ca8; //40002ca8
extern double dData_40002cb0; //40002cb0
extern int Data_40002cb8; //40002cb8
extern int Data_40002cbc; //40002cbc
extern float fData_40002cc0; //40002cc0
extern int Data_40002cf4; //40002cf4
extern int Data_40002cf8; //40002cf8
extern float fData_40002cfc; //40002cfc
extern int Data_40002d20; //40002d20
extern int Data_40002d24; //40002d24
extern float fData_40002d28; //40002d28
extern int Data_40002d40; //40002d40
extern int Data_40002d48; //40002d48
extern int Data_40002d4c; //40002d4c
extern float fData_40002d50; //40002d50
extern int Data_40002d68; //40002d68
extern int Data_40002d6c; //40002d6c
extern float fData_40002d70; //40002d70
extern char bData_40002d88; //40002d88
extern int Data_40002d8c; //40002d8c
extern int Data_40002d90; //40002d90
extern float fData_40002d94; //40002d94
extern char bData_40002da8; //40002da8
extern int Data_40002dac; //40002dac
extern int Data_40002db0; //40002db0
extern float fData_40002db4; //40002db4
extern int Data_40002de0; //40002de0
extern int Data_40002de4; //40002de4
extern float fData_40002de8; //40002de8
extern int Data_40002e18; //40002e18
extern int Data_40002e1c; //40002e1c
extern float fData_40002e20; //40002e20
extern int Data_40002e34; //40002e34
extern int Data_40002e38; //40002e38
extern int Data_40002e3c; //40002e3c
extern float fData_40002e40; //40002e40
extern int Data_40002e44; //40002e44
extern int Data_40002e54; //40002e54
extern int Data_40002e5c; //40002e5c
extern char bData_40002e60; //40002e60
extern char bData_40002e61; //40002e61
extern char bData_40002e62; //40002e62
extern char bData_40002e63; //40002e63
extern char bData_40002e64; //40002e64
extern char bData_40002e79; //40002e79
extern char bData_40002e7a; //40002e7a
extern char bData_40002e7b; //40002e7b
extern char bData_40002e7c; //40002e7c
extern char bData_40002e7d; //40002e7d
extern char bData_40002e7e; //40002e7e
extern int Data_40002e80; //40002e80
extern int Data_40002e84; //40002e84
extern char bData_40002e88; //40002e88
extern char bData_40002e89; //40002e89
extern char bData_40002e8b; //40002e8b
extern char bData_40002e8c; //40002e8c
extern int Data_40002e90; //40002e90
extern int Data_40002e94; //40002e94
extern float fData_40002e98; //40002e98
extern int Data_40002e9c; //40002e9c
extern int Data_40002ea0; //40002ea0
extern int Data_40002ea4; //40002ea4
extern float fData_40002ea8; //40002ea8
extern int Data_40002eac; //40002eac
extern int Data_40002eb0; //40002eb0
extern char bData_40002eb4; //40002eb4
extern char bData_40002eb5; //40002eb5
extern unsigned short wData_40002eb6; //40002eb6
extern unsigned short wData_40002eb8; //40002eb8
extern unsigned short wData_40002eba; //40002eba
extern unsigned short wData_40002ebc; //40002ebc
extern unsigned short wData_40002ebe; //40002ebe
extern unsigned short wData_40002ec0; //40002ec0
extern int Data_40002ec4; //40002ec4
extern unsigned short wData_40002ecc; //40002ecc
extern char bData_40002ece; //40002ece
extern unsigned short wData_40002ed0; //40002ed0
extern unsigned short wData_40002ed2; //40002ed2
extern unsigned short wData_40002ed4; //40002ed4
extern unsigned short wData_40002ed6; //40002ed6
extern unsigned short wData_40002ed8; //40002ed8
extern unsigned short wData_40002eda; //40002eda
extern char bData_40002ede; //40002ede
extern char bData_40002edf; //40002edf
extern char bData_40002ef7; //40002ef7
extern int Data_40002f04; //40002f04
extern int Data_40002f08; //40002f08
extern char bData_40002f0c; //40002f0c
extern char bData_40002f0d; //40002f0d
extern int Data_40002f10; //40002f10
extern char bData_40002f1e; //40002f1e
extern char bData_4000316e; //4000316e
extern char bData_40003188; //40003188
extern char bData_40003189; //40003189
extern int Data_4000318c; //4000318c
extern int Data_40003190; //40003190
extern char bData_40003194; //40003194
extern char bData_40003195; //40003195
extern char Data_40003196; //40003196
extern char bData_40003198; //40003198
extern char bData_40003199; //40003199
extern char bData_4000319b; //4000319b
extern char bData_4000319c; //4000319c
extern char bData_4000319d; //4000319d
extern char bData_400031b8; //400031b8
extern char bData_400031b9; //400031b9
extern char bData_400031be; //400031be
extern char bData_400031bf; //400031bf
extern float fData_400031c0; //400031c0
extern float fData_400031c4; //400031c4
extern char bData_400031e0; //400031e0
extern char bData_400031e1; //400031e1
extern char bData_400031e9; //400031e9
extern char bData_400031ea; //400031ea
extern char bData_400031eb; //400031eb
extern char bData_400031ec; //400031ec
extern char bData_400031ed; //400031ed
extern double dData_400031f0; //400031f0
extern double dData_400031f8; //400031f8
extern char bData_40003200; //40003200
extern char bData_40003201; //40003201
extern int Data_40003204; //40003204
extern int Data_40003208; //40003208
extern char bData_40003210; //40003210
extern char bData_40003211; //40003211
extern char bData_4000322d; //4000322d
extern char bData_400032a4; //400032a4
extern char bData_40003431; //40003431

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
void func_33a0(int a, unsigned char* b, int c)
{
	func_2df8(a, c, 0, 8, b);
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
		sp4 = r4 - 24 -4;
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
			r6[r9][0] = sp156[ sp24[r9] ];
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
	fData_40002e98 = 23.8;
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
	wData_40002ed2 = 0;
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

/* 5099c - todo */
void func_5099c(void)
{
	func_5f40();
	
	bData_4000316e = 0;
	Data_4000318c = 0;
	Data_40003190 = 1;
	bData_40003194 = 0;
	Data_40003196 = 1;
	bData_4000319c = 0;
	bData_4000319d = 0;
	bData_40003198 = 0;
	bData_40003199 = 0;
	bData_40002c1a = 0;
	bData_40003431 = 0;
	bData_40003210 = 0;
	bData_40003211 = 0;
	bData_400031bf = 0x42;
	bData_400031be = 0;
	fData_400031c0 = 10.6;
	fData_400031c4 = 63.25;
	bData_400031e0 = 1;
	bData_40003188 = 0;
	bData_40003189 = 0;
	bData_40003195 = 0;
	bData_400031e1 = 0;
	bData_400032a4 = 0;
	bData_4000319b = 0;
	bData_400031e9 = 0;
	bData_400031b8 = 0;
	bData_400031b9 = 0;
	Data_40002e80 = 0;
	Data_40002e84 = 0;
	bData_4000322d = 0;
	bData_400031ea = 0;
	bData_400031eb = 0;
	bData_400031ec = 1;
	bData_400031ed = 1;
	dData_400031f0 = 0.0;
	dData_400031f8 = 0.0;
	bData_40003200 = 0;
	bData_40003201 = 0;
	Data_40003204 = 0;
	Data_40003208 = 0;
	bData_40002d88 = 0;
	bData_40002da8 = 0;
}


void func_51368(void)
	{
	//TODO
}

