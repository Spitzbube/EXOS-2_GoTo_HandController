
#include <LPC214x.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_types.h"
#include "data.h"

extern void uart0_init(int);
extern void uart1_write_byte(char);
extern void uart1_init(int);
extern void uart0_send(unsigned char* a, unsigned char b);
extern void func_394(void);
extern void func_7e8(int, int, int, unsigned char, const unsigned char*);
extern int func_11d8(void);
extern void func_1210(void);
extern void func_2254(unsigned int);
extern void func_2328(void);
extern void func_243c(int, int, int, char*);
extern void func_24d4(int, int, int, char*);
extern void func_27c4(float*, float*);
extern void func_2a1c(unsigned char* a, float* b, float* c, int* d);

extern int func_5218(int a, Struct_5218* b);
extern int func_54e0(int a, Struct_54e0* b);
extern void func_6518(void);
extern void func_659c(int);
extern void func_7590(void);
extern void func_75c4(void);
extern void func_c57c(void);
extern void func_7950(int);
extern void func_8ba4(Struct_8ba4_0 a, Struct_8ba4 b/*sp208*/, int r4, int r5, double* r6);
extern void func_d2cc(void);
extern void func_9178(void);
extern void func_acdc(double, double, double*, double*); 
extern void func_acd8(void);
extern void func_b4f0(void);
extern void func_b64c(double, double);
extern void func_d784(int a);

extern void func_5099c(void);
extern void func_51368(void);

extern void func_1e17c(void);
extern void func_1e228(void);
extern void func_3d72c(void);

/* 20b94 - todo */
void func_20b94(void)
{
}

/* 23130 - todo */
void func_23130(void)
{
}

/* 24574 - todo */
void func_24574(void)
{
}

/* 2575c - todo */
void func_2575c(void)
{
}

/* 27844 - todo */
void func_27844(void)
{
	func_2575c();
	
	switch (Data_40002c64)
	{
		case 0:
			//0x28030
			func_24574();
		
			bData_4000316e = 10;
			bData_40003197 = 1;
			//->3d71c
			break;
		
		case 2:
			//0x28054
			Data_40003364 = Data_400030c0;
			Data_4000336c = Data_400030c4;
			Data_40003374 = Data_400030c8;
		
			func_23130();
			//->3d71c
			break;
		
		case 0x65: //101
			//0x28090
			Data_40003360 = "F1";
			Data_40003364 = "F2";
			Data_40003368 = "F3";
			Data_4000336c = "F4";
			Data_40003370 = "F5";
			Data_40003374 = "F6";
			Data_40003378 = "F7";
			Data_4000337c = "F8";
			Data_40003380 = "F9";

			switch (bData_40002e79)
			{
				case 0:
					//0x2811c
					Data_40003384 = "Select Sky Target No ";
					break;
				
				case 1:
					//0x28130
					Data_40003384 = "Select Land Target No";
					break;
				
				default:
					//0x28144
					break;
			}
			//->3d71c
			break;
		
		case 0x66: //102
			//0x28154
			switch (bData_40002e79)
			{
				case 0:
					//0x28174
					func_5218(bData_4000319a, &Data_40003f50);
					break;
				
				case 1:
					//0x2818c
					func_54e0(bData_4000319a, &Data_40003f64);
					break;
				
				default:
					//0x281a4
					break;
			}
			//281b0
			if (((Data_40003f64.bData_0 != 1) && (bData_40002e79 == 1)) ||
					((Data_40003f50.bData_0 != 1) && (bData_40002e79 == 0)))
			{
				//281f0
				Data_40003360 = "                      ";
				Data_40003364 = "Sorry                 ";
				Data_40003368 = "                      ";
				
				if (bData_40002e79 == 0)
				{
					//28224
					sprintf(Data_40003fe8, "Your Sky F%d is Blank  ", bData_4000319a);
				}
				//28238
				if (bData_40002e79 == 1)
				{
					//28248
					sprintf(Data_40003fe8, "Your Land F%d is Blank  ", bData_4000319a);
				}
				//2825c
				Data_4000336c = Data_40003fe8;
				Data_40003370 = "                      ";
				Data_40003374 = "Please Input Data    ";
				Data_40003378 = "                      ";
				Data_4000337c = "                      ";
				//->29978
			}
			else
			{
				//283fc
				if (bData_40002e79 == 0)
				{					
					//2840c
					sprintf(Data_40003fa9, "My Sky Target %d   ", bData_4000319a);
					
					Data_40003360 = Data_40003fa9;
					Data_40003364 = "                      ";
					Data_40003368 = Data_40003f50.bData_1;
					Data_4000336c = "                      ";
					
					Data_40004ad8.dData_0 = Data_40004128.dData_48;
					Data_40004ad8.dData_8 = Data_40004128.dData_56;
					Data_40004ae8.dData_0 = Data_40003f50.fData_12;
					Data_40004ae8.dData_8 = Data_40003f50.fData_16;
					fData_40002cd0 = Data_40003f50.fData_12;
					fData_40002d18 = Data_40003f50.fData_16;
					
					func_8ba4(Data_40004ad8, Data_40004ae8, 
						Data_40004128.Data_40, Data_40004128.bData_44, Data_40004b08);
					//284f8
					#if 0
					r4 = (int)(Data_40004b08[1] * 3600.0) % 60;
					r6 = (int)((Data_40004b08[1] - (int)(Data_40004b08[1])) * 60.0);
					r5 = (int)(Data_40004b08[1]);
					
					sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
						r5, r6, r4);
					#else
					sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
						(int)(Data_40004b08[1]), 
						(int)((Data_40004b08[1] - (int)(Data_40004b08[1])) * 60.0), 
						(int)(Data_40004b08[1] * 3600.0) % 60);
					#endif
						
					if (Data_40004b08[3] > 0)
					{
						//285d0
						#if 0
						r4 = (int)(Data_40004b08[3] * 3600.0) % 60;
						r5 = (int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0);
						r6 = (int)Data_40004b08[3];
						
						sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
							(r6 >= 0)? r6: -r6, (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
						#else
						sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
							abs((int)Data_40004b08[3]), 
							abs((int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0)), 
							abs((int)(Data_40004b08[3] * 3600.0) % 60));
						#endif
						//->2885c
					}
					else
					{
						//286cc
						#if 0
						r4 = (int)(Data_40004b08[3] * 3600.0) % 60;
						r5 = (int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0);
						r6 = (int)Data_40004b08[3];
						
						sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
							(r6 >= 0)? r6: -r6, (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
						#else
						sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
							abs((int)Data_40004b08[3]), 
							abs((int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0)), 
							abs((int)(Data_40004b08[3] * 3600.0) % 60));
						#endif
					}
					//2885c
					if ((int)(Data_40004b08[1]) < 100)
					{
						Data_40003ffd[11] = ' ';
					}
					
					if ((int)(Data_40004b08[1]) < 10)
					{
						Data_40003ffd[12] = ' ';
					}
					//288a4
					if ((int)((Data_40004b08[1] - (int)Data_40004b08[1]) * 60.0) < 10)
					{
						Data_40003ffd[15] = ' ';
					}
					//28910
					if (((int)(Data_40004b08[1] * 3600.0) % 60) < 10)
					{
						Data_40003ffd[18] = ' ';
					}
					//28954
					if (abs((int)Data_40004b08[3]) < 10)
					{
						Data_40004012[5] = ' ';
					}
					//2898c
					if (abs((int)((Data_40004b08[3] - (int)Data_40004b08[3]) * 60.0)) < 10)
					{
						Data_40004012[8] = ' ';
					}
					//28a0c
					if (abs(((int)(Data_40004b08[3] * 3600.0)) % 60) < 10)
					{
						Data_40004012[11] = ' ';
					}
					//28a64
					Data_40003370 = Data_40003ffd;
					Data_40003374 = Data_40004012;
					
					#if 0
					r4 = (int)(fData_40002cd0 * 3600.0) % 60;
					r5 = (int)((fData_40002cd0 - (int)fData_40002cd0) * 60.0);
					r9 = (int)fData_40002cd0;
					#else
					sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
						(int)fData_40002cd0,
						(int)((fData_40002cd0 - (int)fData_40002cd0) * 60),
						(int)(fData_40002cd0 * 3600) % 60);
					#endif
						
					if ((int)fData_40002cd0 < 10)
					{
						Data_40004027[5] = ' ';
					}
					//28b2c
					if (((int)((fData_40002cd0 - (int)fData_40002cd0) * 60)) < 10)
					{
						Data_40004027[8] = ' ';
					}
					//28b7c
					if (((int)(fData_40002cd0 * 3600) % 60) < 10)
					{
						Data_40004027[11] = ' ';
					}
					//28bb4
					Data_40003378 = Data_40004027;
					
					if (fData_40002d18 >= 0)
					{
						//28bd4
						#if 0
						r4 = ((int)(fData_40002d18 * 3600) % 60);
						r6 = (int)((fData_40002d18 - (int)(fData_40002d18)) * 60);
						r5 = (int)fData_40002d18;
						#endif
						sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
							abs((int)fData_40002d18),
							abs((int)((fData_40002d18 - (int)(fData_40002d18)) * 60)),
							abs(((int)(fData_40002d18 * 3600) % 60)));
						//->28dc4
					}
					else
					{
						//28cf8
						sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
							abs((int)fData_40002d18),
							abs((int)((fData_40002d18 - (int)(fData_40002d18)) * 60)),
							abs(((int)(fData_40002d18 * 3600) % 60)));
					}
					//28dc4
					if (abs((int)fData_40002d18) < 10)
					{
						Data_4000403c[5] = ' ';
					}
					//28df8
					if (abs((int)((fData_40002d18 - (int)fData_40002d18) * 60)) < 10)
					{
						Data_4000403c[8] = ' ';
					}
					//28e5c
					if (abs((int)(fData_40002d18 * 3600) % 60) < 10)
					{
						Data_4000403c[11] = ' ';
					}
					//28ea8
					Data_4000337c = Data_4000403c;
					//->29978
				}
				else
				{
					//28eb8
				}
			}
			//29978
			bData_4000316e = 0;
			bData_40003197 = 1;
			//->3d71c
			break;
		
		case 1:
			//0x29994
			break;
		
		case 0x3e8: //1000
			//0x2a100
			break;
		
		case 3:
			//0x2c658
			break;
		
		case 0xc9: //201
			//0x3b414
			break;
		
		case 0xca: //202
			//0x3b850
			break;
		
		case 0xcb: //203
			//0x3b4ac
			break;
		
		case 0xcc: //204:
			//0x3b540
			break;
		
		case 0xcd: //205
			//0x3b5d4
			break;
		
		case 0xce: //206
			//0x3b8e8
			break;
		
		case 0xcf: //207
			//0x3b97c
			break;
		
		case 0xd0: //208
			//0x3ba10
			break;
		
		case 0x44c: //1100
			//0x2a49c
			break;
		
		case 0x4b0: //1200
			//0x2a4a4
			break;
		
		case 0x514: //1300
			//0x2a4a8
			break;
		
		case 1400:
			//0x2a4ac
			break;
		
		case 1401: 
			//0x2c6e0
			break;
		
		case 1402:
			//0x2c760
			break;
		
		case 0x57b: //1403
			//0x2c7dc
			break;
		
		case 0x5DC: //1500
			//0x2a4b0
			break;
		
		case 0x640: //1600
			//0x2a4b4
			break;
		
		case 0x6A4: //1700
			//0x2a4b8
			break;
		
		case 0x7D0: //2000
			//0x2a220
			break;
		
		case 0x834: //2100
			//0x2a500
			break;
		
		case 0x83E: //2110
			//0x2a528
			break;
		
		case 0x848: //2120
			//0x2a52c
			break;
		
		case 0x852: //2130
			//0x2a530
			break;
		
		case 0x898: //2200
			//0x2a508
			break;
		
		case 0x899: //2201
			//0x2a650
			break;
		
		case 0x89A: //2202
			//0x2a658
			break;
		
		case 0x89B: //2203
			//0x2a65c
			break;

		case 0x89C: //2204
			//0x2a660
			break;
		
		case 0x89D: //2205
			//0x2a664
			break;

		case 0x89E: //2206
			//0x2a668
			break;
		
		case 0x89F: //2207
			//0x2a66c
			break;
		
		case 0x8A0: //2208
			//0x2a670
			break;
		
		case 0x8A1: //2209
			//0x2a674
			break;
		
		case 0x8FC: //2300
			//0x2a50c
			break;
		
		case 0x8FD: //2301
			//0x2a6a8
			break;
		
		case 0x8FE: //2302
			//0x2a6b0
			break;
		
		case 0x8ff: //2303
			//0x2a6b4
			break;
		
		case 0x900: //2304
			//0x2a6b8
			break;
		
		case 2305: 
			//0x2a6bc
			break;
		
		case 2306:
			//0x2a6c0
			break;
		
		case 2307:
			//0x2a6c4
			break;
		
		case 2308:
			//0x2a6c8
			break;
		
		case 0x960: //2400
			//0x2a510
			break;
		
		case 0x9C4: //2500
			//0x2a514
			break;
		
		case 0x9c5: //2501
			//0x2a6f8
			break;
		
		case 0x9c6: //2502
			//0x2a780
			break;
		
		case 0x9C7: //2503
			//0x2a80c
			break;
		
		case 0xA28: //2600
			//0x2a518
			break;
		
		case 0xA8C: //2700
			//0x2a51c
			break;
				
		case 0xAF0: //2800
			//0x2a520
			break;
		
		case 0xAF1: //2801
			//0x2a898
			break;
		
		case 0xAF2: //2802
			//0x2a924
			break;
		
		case 0xAF3: //2803
			//0x2aa2c
			break;
		
		case 0xAF4: //2804
			//0x2aabc
			break;
		
		case 0xB54: //2900
			//0x2a524
			break;
		
		case 0xBB8: //3000
			//0x2a2f4
			break;
		
		case 0xC1C: //3100
			//0x2a578
			break;
		
		case 0xC80: //3200
			//0x2a580
			break;
		
		case 0xCE4: //3300
			//0x2a584
			break;
		
		case 0xD48: //3400
			//0x2a588
			break;
		
		case 0xDAC: //3500
			//0x2a58c
			break;
		
		case 0xE10: //3600
			//0x2a590
			break;
		
		case 0xE11: //3601
			//0x2acec
			break;

		case 0xE12: //3602
			//0x2ad70
			break;
		
		case 0xE74: //3700
			//0x2a594
			break;
		
		case 0xED8: //3800
			//0x2a598
			break;
		
		case 0xED9: //3801
			//0x2adf8
			break;
		
		case 0xEDA: //3802
			//0x2ae7c
			break;

		case 0xF3C: //3900
			//0x2a59c
			break;
		
		case 0xFA0: //4000
			//0x2a3c8
			break;
		
		case 0x1004: //4100
			//0x2a5e4
			break;
		
		case 0x1068: //4200
			//0x2a5ec
			break;
		
		case 0x10CC: //4300
			//0x2a5f0
			break;
		
		case 0x10CD: //4301
			//0x2af04
			break;
		
		case 0x10CE: //4302
			//0x2af88
			break;
		
		case 0x1130: //4400
			//0x2a5f4
			break;
		
		case 0x1194: //4500
			//0x2a5f8
			break;
		
		case 0x11F8: //4600
			//0x2a5fc
			break;
		
		case 0x125C: //4700
			//0x2a600
			break;
		
		case 0x12C0: //4800
			//0x2a604
			break;
		
		case 0x12c1: //4801
			//0x2b2a4
			break;
		
		case 0x12c2: //4802
			//0x2b334
			break;
		
		case 0x12c3: //4803
			//0x2b3c8
			break;
		
		case 0x12C4: //4804
			//0x2b45c
			break;
		
		case 0x12C5: //4805
			//0x2b4f0
			break;
		
		case 0x1324: //4900
			//0x2a608
			break;
		
		case 0x2B5D: //11101
			//0x2cb60
			break;
		
		case 0x2B5E: //11102
			//0x2cad0
			break;
		
		case 0x2B5F: //11103
			//0x2cbf0
			break;
		
		case 0x2B60: //11104
			//0x2cc80
			break;
		
		case 0x2B61: //11105
			//0x2cdc0
			break;
		
		case 0x2BC1: //11201
			//0x2cf00
			break;
		
		case 0x2BC2: //11202
			//0x2ce70
			break;
		
		case 0x2BC3: //11203
			//0x2cf90
			break;
		
		case 0x2BC4: //11204
			//0x2d020
			break;

		case 0x2BC5: //11205
			//0x2d100
			break;
		
		case 0x2EE1: //12001
			//0x2b68c
			break;
		
		case 0x4651: //18001
			//0x2c85c
			break;
		
		case 0x526D: //21101
			//0x2ab4c
			break;
		
		case 0x526E: //21102
			//0x2abd4
			break;
		
		case 0x526F: //21103
			//0x2ac60
			break;
		
		case 0x55F1: //22001
			//0x2d1b0
			break;
		
		case 0x55FC: //22012
			//0x2a678
			break;
		
		case 0x565F: //22111
			//0x2dd24
			break;
		
		case 0x5660: //22112
			//0x2db70
			break;
		
		case 0x59DA: //23002
			//0x31ef0
			break;
	
		case 0x59DB: //23003
			//0x33750
			break;
		
		case 0x59DC: //23004
			//0x350c0
			break;
		
		case 0x59DD: //23005
			//0x36a10
			break;
		
		case 0x59DE: //23006
			//0x382a0
			break;
		
		case 0x59DF: //23007
			//0x39b90
			break;
		
		case 0x59E4: //23012
			//0x31c44
			break;
		
		case 0x59E5: //23013
			//0x34278
			break;
		
		case 0x59E6: //23014
			//0x35bb4
			break;
		
		case 0x59E7: //23015
			//0x374a0
			break;
		
		case 0x59E8: //23016
			//0x38d80
			break;
		
		case 0x59E9: //23017
			//0x3a618
			break;
		
		case 0x59EE: //23022
			//0x32940
			break;
		
		case 0x5DC1: //24001
			//0x2ea8c
			break;
		
		case 0x5DC2: //24002
			//0x2f624
			break;
		
		case 0x61A9: //25001
			//0x30404
			break;
		
		case 0x61AA: //25002
			//0x30ea8
			break;
		
		case 0x7149: //29001
			//0x3b668
			break;
		
		case 0x714A: //29002
			//0x3b7d0
			break;
		
		case 0x7919: //31001
			//0x3baa4
			break;
		
		case 0x7D01: //32001
			//0x3be30
			break;
		
		case 0x80E9: //33001
			//0x3c088
			break;
		
		case 0x84D1: //34001
			//0x3c13c
			break;
		
		case 0x84D2: //34002
			//0x3c0a8
			break;
		
		case 0x88B9: //35001
			//0x3c1bc
			break;
		
		case 0x88BA: //35002
			//0x3c23c
			break;
		
		case 0xA029: //41001
			//0x3c64c
			break;
		
		case 0xA411: //42001
			//0x3c6cc
			break;
		
		case 0xA803: //43011
			//0x3c8f4
			break;
		
		case 0xA80D: //43021
			//0x2b010
			break;
		
		case 0xA80E: //43022
			//0x2b09c
			break;
		
		case 0xA80F: //43023
			//0x2b184
			break;
		
		case 0xA810: //43024
			//0x2b214
			break;
		
		case 0xAFC9: //45001
			//0x3cf10
			break;
		
		case 0xAFCA: //45002
			//0x3cf90
			break;
		
		case 0xB3B1: //46001
			//0x3d010
			break;
		
		case 0xB3B2: //46002
			//0x3d154
			break;
		
		case 0xB7A3: //47011
			//0x3d1d4
			break;
		
		case 0xB7BD: //47037
			//0x3d2c4
			break;
		
		case 0xBB81: //48001
			//0x3d694
			break;
		
		case 0xBBB3: //48051
			//0x2b584
			break;
		
		case 0xBBB4: //48052
			//0x2b600
			break;
		
		case 0xBBB5: //48053
			//0x2b614
			break;
		
		case 0xBBB6: //48054
			//0x2b628
			break;
		
		case 0xBBB7: //48055
			//0x2b63c
			break;
		
		case 0xBBB8: //48056
			//0x2b650
			break;
		
		case 0xBBB9: //
			//0x2b664
			break;
		
		case 0xBBBA: //
			//0x2b678
			break;
		
		case 0xBF69: //49001
			//0x3d344
			break;
		
		case 0xBF6A: //49002
			//0x3d3c0
			break;
		
		case 0xBF6B: //49003
			//0x3d440
			break;
		
		case 0xBF6C: //49004
			//0x3d594
			break;
		
		case 0xBF6D: //49005
			//0x3d614
			break;
		
		case 0x57E4B: //360011
			//0x3c2bc
			break;
		
		case 0x57E55: //360021
			//0x3c33c		
			break;
		
		case 0x57E56: //360022
			//0x3c41c
			break;
		
		case 0x57E57: //360023
			//0x3c524
			break;
		
		case 0x5A565: //370021
			//0x3c49c
			break;
		
		case 0x5A566: //370022
			//0x3c4a4
			break;
		
		case 0x5A567: //370023
			//0x3c4a8
			break;
		
		case 0x5CC6B: //380011
			//0x3c5cc
			break;
		
		default:
			//0x3d714
			break;
	}
}

/* 3d72c - todo */
void func_3d72c(void)
{
	func_27844();
	
	switch (bData_40003197)
	{
		case 1:
			//0x3d750
			Data_4000318c = Data_40002c64;
			if (Data_4000318c != Data_40003190)
			{
				//3d77c
				func_394();				
				Data_40003190 = Data_4000318c;
			}
			//3d790
			switch (Data_40002c64)
			{
				case 0:
					//0x3da9c
					if (bData_400031ed == 1)
					{
						func_20b94();
					}
					//->4684c
					break;
				
				case 1:
					//0x3dab8
					break;
				
				case 2:
					//0x3f8d0
					break;
				
				case 0x64:
					//0x446e8
					break;
				
				case 0x65:
					//0x41c8c
					break;
				
				case 0x66:
					//0x3f230
					break;
				
				case 0xc9:
					//0x41c80
					break;
				
				case 0xca:
					//0x41c88
					break;
				
				case 0xcb:
					//0x42788
					break;
				
				case 0xcc:
					//0x4298c
					break;
				
				case 0xcd:
					//0x42b90
					break;
				
				case 0xce:
					//0x42d94
					break;
				
				case 0xcf:
					//0x43048
					break;
				
				case 0xd0:
					//0x43328
					break;
				
				case 0x2b5d:
					//0x40488
					break;
				
				case 0x2b5e:
					//0x40480
					break;

				case 0x80E9:
					//0x44760
					break;
				
				case 0x59de:
					//0x40e44
					break;
				
				case 0x59DF:
					//0x40e48
					break;
				
				case 0x59E4:
					//0x41af8
					break;
				
				case 0x59E5:
					//0x4161c
					break;
				
				case 0x59E6:
					//0x41624
					break;
				
				case 0x59E7:
					//0x4130c
					break;
				
				case 0x59E8:
					//0x41310
					break;
				
				case 0x59E9:
					//0x41314
					break;
				
				case 0x59EE:
					//0x41308
					break;
				
				case 0x61AA:
					//0x41304
					break;
				
				case 0x5DC1:
					//0x40e38
					break;
				
				case 0x5DC2:
					//0x41300
					break;
				
				case 0x5DC3:
					//0x418fc
					break;
				
				case 0x6D61:
					//0x4575c
					break;
				
				case 0xBB81:
					//0x43a04
					break;
				
				case 0x5A565:
					//0x44ee8
					break;
				
				case 0x5A566:
					//0x450e0
					break;
				
				case 0x5A567:
					//0x452d8
					break;
				
				default:
					//->459f8
					break;
			}
			//46850 -> 4edd8
			
			break;
		
		case 2:
			//0x46854
			break;
	}
	//0x4edd0
	
#if 0
	//3dab8
	if (bData_40002f14 != 0)
	{
		//3dacc
		switch (bData_4000316e)
		{
			#if 0
			case 0:
				//->3efa0
				break;
			#endif
			
			case 1:
				//3db08
				func_7e8(1, 1, 1, 2, Data_40003380);
				func_7e8(0, 2, 1, 2, Data_40003384);
				func_7e8(0, 3, 1, 2, Data_40003388);
				func_7e8(0, 4, 1, 2, Data_4000338c);
				func_7e8(0, 5, 1, 2, Data_40003390);
				func_7e8(0, 6, 1, 2, Data_40003394);
				func_7e8(0, 7, 1, 2, Data_40003398);
				func_7e8(0, 8, 1, 2, Data_4000339c);	
				func_7e8(1, 1, 3, strlen(Data_40003360) & 0xFF, Data_40003360);
				func_7e8(0, 2, 3, strlen(Data_40003364) & 0xFF, Data_40003364);
				func_7e8(0, 3, 3, strlen(Data_40003368) & 0xFF, Data_40003368);
				func_7e8(0, 4, 3, strlen(Data_4000336c) & 0xFF, Data_4000336c);
				func_7e8(0, 5, 3, strlen(Data_40003370) & 0xFF, Data_40003370);
				func_7e8(0, 6, 3, strlen(Data_40003374) & 0xFF, Data_40003374);
				func_7e8(0, 7, 3, strlen(Data_40003378) & 0xFF, Data_40003378);
				func_7e8(0, 8, 3, strlen(Data_4000337c) & 0xFF, Data_4000337c);
				//->3efa8
			
			case 2:
				//3dd8c
				break;
			
			case 3:
				//0x3e014
				break;
			
			case 4:
				//0x3e29c
				break;
			
			case 5:
				//0x3e524
				break;
			
			case 6:
				//0x3e7ac
				break;
			
			case 7:
				//0x3ea90
				break;
			
			case 8:
				//0x3ed18
				break;
			
			default:
				//->3efa0
				break;
		}
	}
	//3efac
#endif
}




/* 4ede4 - todo */
void func_4ede4(void)
{
	switch (bData_40003195)
	{
		case 0:
			//0x4ee08
			IO0SET = 0x2000;
			IO0CLR = 0x10000;
			bData_40003195 = 1;
			break;
		
		case 1:
			//0x4ee30
			IO0SET = 0x2000;
			IO0SET = 0x10000;
			bData_40003195 = 2;
			break;
		
		case 2:
			//0x4ee58
			IO0CLR = 0x2000;
			IO0SET = 0x10000;
			bData_40003195 = 0;
			break;
		
		default:
			break;
	}		
}

/* 4ee90 - todo */
void func_4ee90(int a, int b, int c, int d, int e, int f)
{
}

/* 4f804 - todo */
void func_4f804(void)
{
	switch (Data_40002c64)
	{
		case 0:
			//0x4f88c
//			break;
		
		case 0x565f:
			//0x4f894
//			break;
		
		case 0x5DC2:
			//0x4f898
//			break;
		
		case 0x61AA:
			//0x4f89c
//			break;
		
		case 0x59EE:
			//0x4f8a0
//			break;
		
		case 0x59e5:
			//0x4f8a4
//			break;
		
		case 0x59e6:
			//0x4f8a8
//			break;

		case 0x59e7:
			//0x4f8ac
//			break;
		
		case 0x59e8:
			//0x4f8b0
//			break;

		case 0x59e9:
			//0x4f8b4
			if (bData_400034a9 == 0)
			{
				//4f8c4
				if ((Data_40004128.bData_356 != 0) &&
					(bData_40002e89 != 1))
				{
					//4f8e4
					Data_40003408 = 1;
					Data_4000340c = 1;
					bData_40003201 = 0;
					bData_40003200 = 0;
					//->4f9cc
				}
				//4f910
				else if (bData_40002c1a == 1)
				{
					//4f920
					//40002e7d
					func_4ee90(1, 4, bData_40002e7d, 2, 1, bData_40002e7d);
					//->4f9cc
				}
				else
				{
					//0x4f948
					func_4ee90(3, 4, bData_40002e7d, 4, 1, bData_40002e7d);
					//->4f9cc
				}
			}
			else
			{
				//0x4f970
				if (bData_40002c1a == 1)
				{
					//4f980
					func_4ee90(1, 4, bData_40002e7d, 2, 1, bData_40002e7d);
					//->4f9cc
				}
				else
				{
					//4f9a8
					func_4ee90(3, 4, bData_40002e7d, 4, 1, bData_40002e7d);
					//->4f9cc
				}
			}			
			break;
		
		default:
			//0x4f9d0
			break;
	}	
}

/* 4f9e4 - todo */
void func_4f9e4(void)
{
}

/* 4fbc8 - todo */
void func_4fbc8(void)
{
}

/* 4fda8 - todo */
void func_4fda8(void)
{
}

/* 50b40 - todo */
void func_50b40(void)
{
	//TODO
	//50c98
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;
}

/* 52898 - todo */
void func_52898(void)
{
}

/* 57414 - todo */
void func_57414(int a, int b, int c)
{
}

/* 57c1c - todo */
void func_57c1c(void)
{
}

/* 5969c - todo */
void func_5969c(void)
{
}

/* 5ab50 - todo */
void func_5ab50(void)
{
}

/* 5d1ac - todo */
void func_5d1ac(void)
{
}

/* 5f0c0 - todo */
void func_5f0c0(void)
{
}

/* 5f230 - todo */
void func_5f230(void)
{
}

/* 60d54 - todo */
void func_60d54(void)
{
}

/* 60dfc - todo */
void func_60dfc(void)
{
}

/* 60ed0 - todo */
void func_60ed0(void)
{
}

/* 62ce0 - todo */
void func_62ce0(void)
{
}

/* 637e8 - todo */
void func_637e8(void)
{
}

/* 64324 - todo */
void func_64324(void)
{
}

/* 64e18 - todo */
void func_64e18(void)
{
}

/* 65894 - todo */
void func_65894(void)
{
}

/* 66378 - todo */
void func_66378(void)
{
}

/* 66e3c - todo */
void func_66e3c(void)
{
}

/* 678b8 - todo */
void func_678b8(void)
{
}

/* 68934 - todo */
void func_68934(void)
{
}

/* 69348 - todo */
void func_69348(void)
{
}

/* 6a0e4 - todo */
char func_6a0e4(void)
{
	char r4;
	int r3 = func_11d8();
	if (r3 & 0x20)
	{
		r3 &= 0x1f;
		
		func_1210();
		
		bData_40002c68 = 0;
		Data_400031e4 = 0;
	}
	else
	{
		r3 = 100;
	}
	
	switch (r3)
	{
		case 1:
			//0x6a18c
			r4 = 16;
			break;
		
		case 2:
			//0x6a198
			r4 = 1;
			break;
		
		case 3:
			//0x6a1a4
			r4 = 4;
			break;
		
		case 4:
			//0x6a1b0
			r4 = 7;
			break;
		
		case 5:
			//0x6a1bc
			r4 = 10;
			break;
		
		case 6:
			//0x6a1c8
			r4 = 15;
			break;
		
		case 7:
			//0x6a1d4
			r4 = 2;
			break;
		
		case 8:
			//0x6a1e0
			r4 = 5;
			break;
		
		case 9:
			//0x6a1ec
			r4 = 8;
			break;
		
		case 10:
			//0x6a1f8
			r4 = 0;
			break;
		
		case 11:
			//0x6a204
			r4 = 17;
			break;
		
		case 12:
			//0x6a210
			r4 = 3;
			break;
		
		case 13:
			//0x6a21c
			r4 = 6;
			break;
		
		case 14:
			//0x6a228
			r4 = 9;
			break;
		
		case 15:
			//0x6a234
			r4 = 11;
			break;
		
		case 16:
			//0x6a240
			r4 = 14;
			break;
		
		case 17:
			//0x6a24c
			r4 = 19;
			break;
		
		case 18:
			//0x6a258
			r4 = 12;
			break;
		
		case 19:
			//0x6a264
			r4 = 20;
			break;
		
		case 20:
			//0x6a270
			r4 = 13;
			break;
		
		case 21:
			//0x6a27c
			r4 = 21;
			break;
		
		case 22:
			//0x6a288
			r4 = 22;
			break;
		
		case 23:
			//0x6a294
			r4 = 23;
			break;
		
		case 24:
			//0x6a2a0
			r4 = 24;
			break;

		default:
			//6a2ac
			func_5f0c0();
			func_5f0c0();
			break;
	}
	
	return r4;
}

/* 6a2cc - todo */
void func_6a2cc(void)
{
	func_6518(); //-> get time from RTC
	
	if (bData_40003505 != 0)
	{
		func_659c(10);
		func_1210();
		
		if (bData_4000322d == 1)
		{
			bData_4000322c = 0;
			bData_4000322d = 0;
		}
	}
	//6a314
	bData_40002c69 = func_6a0e4();
	
	if (bData_40002c68 == 0)
	{
		//6a330
		if (bData_40002c5a == 1)
		{
			func_d784(1);
		}
		//6a348
		switch (bData_40002c69)
		{
			case 0:
				//0x6a3c0
				func_69348();
				bData_40003505 = 1;
				break;
			
			case 1:
				//0x6a3d8
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a40c
					func_68934();
				}
				bData_40003505 = 1;
				break;
				
			case 2:
				//0x6a420
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a454
					func_678b8();
				}
				bData_40003505 = 1;
				break;
			
			case 3:
				//0x6a468
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a49c
					func_66e3c();
				}
				bData_40003505 = 1;
				break;
			
			case 4:
				//0x6a4b0
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a4e4
					func_66378();
				}
				bData_40003505 = 1;
				break;
			
			case 5:
				//0x6a4f8
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a52c
					func_65894();
				}
				bData_40003505 = 1;
				break;
						
			case 6:
				//0x6a540
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a574
					func_64e18();
				}
				bData_40003505 = 1;
				break;
			
			case 7:
				//0x6a588
				func_64324();
				bData_40003505 = 1;
				break;
			
			case 8:
				//0x6a5a0
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a5d4
					func_637e8();
				}
				bData_40003505 = 1;
				break;
			
			case 9:
				//0x6a5e8
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a61c
					func_62ce0();
				}
				bData_40003505 = 1;
				break;
			
			case 10:
				//0x6a630
				func_60ed0();
				bData_40003505 = 1;
				break;
			
			case 11:
				//0x6a648
				func_60dfc();
				bData_40003505 = 1;
				break;
			
			case 12:
				//0x6a660
				func_60d54();
				bData_40003505 = 1;
				break;
			
			case 13:
				//0x6a678
				func_5f230();
				bData_40003505 = 1;
				break;
			
			case 14:
				//0x6a690
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a6c4
					func_5d1ac();
				}
				bData_40003505 = 1;
				break;
			
			case 15:
				//0x6a6d8
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a70c
					func_5ab50();
				}
				bData_40003505 = 1;
				break;
			
			case 16:
				//0x6a720
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a754
					func_5969c();
				}
				bData_40003505 = 1;
				break;
			
			case 17:
				//0x6a768
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a79c
					func_57c1c();
				}
				bData_40003505 = 1;
				break;
			
			#if 0
			case 18:
				//0x6a900
			#endif
			
			case 19:
				//0x6a7b0
				func_52898();
				bData_40003505 = 1;
				break;
			
			case 22:
				//0x6a7c8
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a7fc
					func_4fda8();
				}
				bData_40003505 = 1;
				break;
			
			case 21:
				//0x6a810
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a844
					func_4fbc8();
				}
				bData_40003505 = 1;
				break;
			
			case 23:
				//0x6a858
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a88c
					func_4f9e4();
				}
				bData_40003505 = 1;
				break;
			
			case 24:
				//0x6a8a0
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a8d4
					func_4f804();
				}
				bData_40003505 = 1;
				break;

			case 20:
				//0x6a8e8
				func_4ede4();
				bData_40003505 = 1;
				break;
			
			default:
				//6a900
				break;
		}
		
		bData_40002c68 = 1;
		//->6a948
	}
	else
	{
		//6a91c
		bData_40003505 = 0;
		Data_40003408 = 0;
		Data_4000340c = 0;
		Data_40002e80 = 0;
		Data_40002e84 = 0;
	}
	//6a948
	if ((Data_40002c64 != 0) &&
		(Data_40002c64 != 0x2ee1) &&
		(Data_40002c64 != 0x2b5f) &&
		(Data_40002c64 != 0x2bc3) &&
		(Data_40002c64 != 0x2b5e) &&
		(Data_40002c64 != 0x2bc2) &&
		(bData_40003505 == 0))
	{
		if (bData_40002ef6 == 0)
		{
			bData_40002ef6 = 1;
			Data_40002ef8 = 0;
		}
		//->6aa04
	}
	else
	{
		//6a9f8
		bData_40002ef6 = 0;		
	}
	//6aa04
	if (bData_40002f1e == 1)
	{
		//6aa14
		if (bData_400031ec != 0)
		{
			//6aa24
			func_6518(); //-> get time from RTC
			
			sprintf(Data_400037ec, "%04d-%02d-%02d", Data_40002e5c, bData_40002e60, bData_40002e61);
			sprintf(Data_40003150, "%02d:%02d:%02d", bData_40002e62, bData_40002e63, bData_40002e64);
			sprintf(Data_40002655, "%04d-%02d-%02d", Data_40002e5c, bData_40002e60, bData_40002e61);
			sprintf(Data_40002660, "%02d:%02d:%02d", bData_40002e62, bData_40002e63, bData_40002e64);
			
			bData_400031ec = 0;
		}
		//6aad4
	}
	//6aad4
	if (bData_40002c58 == 0)
	{
		func_3d72c();
	}
	else
	{
		func_1e228();
	}
	//6aaf0
	if ((bData_4000322c == 1) && 
		(Data_40003220 == bData_40002e62) &&
		(Data_40003224 == bData_40002e63) &&
		(Data_40003228 == bData_40002e64))
	{
		bData_4000322d = 1;
	}
	//6ab54
	if (bData_4000322d == 1)
	{
		func_7950(10);
	}
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

/* 6ae24 - todo */
double func_6ae24(int a)
{
}

/* 6b17c - todo */
void func_6b17c(void)
{
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
		
			CCR = (1 << 4); //clock from the 32 kHz oscillator that�s connected to the RTCX1 and RTCX2 pins
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
	int r4;
	int r5;
		
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
		
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;
	
	Data_40004128.dData_192 = 100.0; 
	Data_40004128.dData_200 = 60.0;
	
	func_27c4(&Data_4000329c, &Data_400032a0);
	
	Data_40004128.dData_192 = Data_4000329c;
	Data_40004128.dData_200 = Data_400032a0;
	
	Data_40004128.dData_112 = -180.0;
	Data_40004128.dData_120 = 90.0;
	
	func_2a1c(Data_40004bb8, &fData_40003540, &fData_40003544, &Data_40003548);
	
	Data_40004128.dData_48 = fData_40003540;
	Data_40004128.dData_56 = fData_40003544;
	Data_40002e54 = Data_40003548;
	
	Data_40002827[6] = Data_40004bb8[0];
	Data_40002827[7] = Data_40004bb8[1];
	Data_40002827[8] = Data_40004bb8[2];
	Data_40002827[9] = Data_40004bb8[3];
	Data_40002827[10] = Data_40004bb8[4];
	Data_40002827[11] = Data_40004bb8[5];
	Data_40002827[12] = Data_40004bb8[6];
	Data_40002827[13] = Data_40004bb8[7];	
	//6d364
	if (fData_40003540 > 0)
	{
		//6d378
		r4 = (fData_40003540 - (int)fData_40003540) * 60;
		r5 = fData_40003540;
		sprintf(Data_40002837, "  Lon:E%03dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
		//->6d494
	}
	else
	{
		//6d408
		r4 = (fData_40003540 - (int)fData_40003540) * 60;
		r5 = fData_40003540;
		sprintf(Data_40002837, "  Lon:W%03dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
	}
	//6d494
	if (fData_40003544 > 0)
	{
		//6d4a8
		r4 = (fData_40003544 - (int)fData_40003544) * 60;
		r5 = fData_40003544;
		sprintf(Data_40002847, "  Lat:N%02dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
		//->6d5c4
	}
	else
	{
		//6d538
		r4 = (fData_40003544 - (int)fData_40003544) * 60;
		r5 = fData_40003544;
		sprintf(Data_40002847, "  Lat:S%02dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
	}
	//6d5c4
	if (Data_40003548 > 0)
	{
		//6d5d4
		r4 = Data_40003548;
		sprintf(Data_40002856, " Zone:E%02d", (r4 >= 0)? r4: -r4);
	}
	else
	{
		//6d604
		r4 = Data_40003548;
		sprintf(Data_40002856, " Zone:W%02d", (r4 >= 0)? r4: -r4);
	}
	//6d630
	func_659c(2000);
	func_394();
	
	if (bData_40002f1e == 1)
	{
		//6d64c
		func_6518(); //-> get time from RTC
		
		if (Data_40002e5c > 2000)
		{
			//6d660
			Data_40002e5c = 2000;
			bData_40002e60 = 1;
			bData_40002e61 = 1;
			bData_40002e62 = 0;
			bData_40002e63 = 0;
			bData_40002e64 = 0;			
		}
		//6d69c
		sprintf(Data_400037ec, "%04d-%02d-%02d", Data_40002e5c, bData_40002e60, bData_40002e61);
		sprintf(Data_40003150, "%02d:%02d:%02d", bData_40002e62, bData_40002e63, bData_40002e64);
		sprintf(Data_40002655, "%04d-%02d-%02d", Data_40002e5c, bData_40002e60, bData_40002e61);
		sprintf(Data_40002660, "%02d:%02d:%02d", bData_40002e62, bData_40002e63, bData_40002e64);
		
		bData_4000318a = 1;
		bData_40002e78 = 0;
		Data_40002c64 = 0x0000a029;
		//->6d880
	}
	else
	{
		//6d874
		Data_40002c64 = 0;
	}
	//6d880
	Data_40002c1c = 0;
	Data_40002c20 = 0;
	//6d894 -> 729ec
	while (1) //Main Loop
	{
		//6d898
		fData_40002efc = dData_40002dc0;
		fData_40002f00 = dData_40002df8;
		
		func_6cb38();
		
		if (bData_40002c1a == 1)
		{
			//6d8d4
			bData_40002e7a = 1;
			//6d8e0
			
			//TODO
			
			//6e554 ->6f8d0??
		}
		//6e558
		else if (bData_40002c1a == 2)
		{
			//6e568
			if (bData_40002e7a == 0)
			{
				//6e578
				
				//TODO
				
				//6ee74 -> 6f8d0???
			}
			else
			{
				//6ee78
				
				//TODO
			}
			
			//TODO
		}
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
		//6f94c
		func_6a2cc();
		//6f950
		if (Data_40004128.bData_364 == 0)
		{
			//6f960
			func_c57c();
			
			bData_400034cc = 0;
		}
		//6f970
		if ((bData_400031b8 != 0) && (Data_400031a4 <= 4800))
		{
			//6f990
			
			//TODO
		}
		//6fb24
		if (bData_40002e88 == 2)
		{
			//6fb34
			func_6b17c();
			
			//TODO
		}
		//6fd3c
		if (bData_40003211 == 0)
		{
			//6fd4c
			
			//TODO
		}
		//6fd80
		if (bData_40003211 != 0)
		{
			//6fd90
			
			//TODO
		}
		//6fdf8
		if (bData_40003210 != 0)
		{
			//6fe08
			
			//TODO
		}
		//6fe64
		if (bData_40002c1a == 1)
		{
			//6fe74
			
			//TODO
		}
		//70f38
		if (Data_40004128.bData_356 != 0)
		{
			//70f48
			
			//TODO
		}
		//72040
		if ((Data_4000340c != 0) || (Data_40003408 != 0))
		{
			//72060
			bData_400034b4 = 0;
		}
		//7206c
		if (Data_40004128.bData_357 != 0)
		{
			//7207c
			if (bData_40002c1a == 0)
			{
				//7208c
				Data_40002c64 = 2;
				Data_40004128.bData_357 = 0;
				Data_40004128.bData_364 = 1;
			}
			else
			{
				//720b0
				if (bData_40002e7a == 0)
				{
					//720c0
					func_acd8();
				}
				else
				{
					//720c8
					func_9178();
				}
			}
		}
		//720cc
		if (Data_40002eb0 == 1)
		{
			//720dc
			func_659c(3000);
			
			switch (bData_40002edd)
			{
				case 0:
					//0x72110
					func_6ae24(3);
				
					Data_40004128.dData_208 = dData_40002db8;
				  dData_40002dc0 = Data_40004128.dData_208;
					//->7221c
					break;
				
				case 1:
					//0x72150
					func_6ae24(4);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = fabs(Data_40004128.dData_216);
					//->7221c
					break;
				
				case 2:
					//0x72194
					func_6ae24(1);
				
					Data_40004128.dData_208 = dData_40002d80;
					dData_40002dc0 = Data_40004128.dData_208;
					break;
				
				case 3:
					//0x721d4
					func_6ae24(2);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = Data_40004128.dData_216;
					break;
				
				default:
					//0x72214
					break;
			}
			//7221c
			func_5f0c0();			
			func_659c(100);
			
			switch (bData_40002edd)
			{
				case 0:
					//0x72258
					func_6ae24(3);
				
					Data_40004128.dData_208 = dData_40002db8;
				  dData_40002dc0 = Data_40004128.dData_208;
					//->0x72364
					break;
				
				case 1:
					//0x72298
					func_6ae24(4);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = fabs(Data_40004128.dData_216);
					//->0x72364
					break;
				
				case 2:
					//0x722dc
					func_6ae24(1);
				
					Data_40004128.dData_208 = dData_40002d80;
					dData_40002dc0 = Data_40004128.dData_208;
					break;
				
				case 3:
					//0x7231c
					func_6ae24(2);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = Data_40004128.dData_216;
					break;
				
				default:
					//7235c
					break;
			}
			//72368
			switch (bData_40002edd)
			{
				case 0:
					//0x72394
					func_6ae24(3);
				
					Data_40004128.dData_208 = dData_40002db8;
				  dData_40002dc0 = Data_40004128.dData_208;
					dData_40002dc0 += Data_40004128.dData_192;
					//->72410
					while (dData_40002dc0 >= 360.0)
					{
						//723f4
						dData_40002dc0 -= 360.0;
					}
					//->72448
					while (dData_40002dc0 < 0.0)
					{
						//7242c
						dData_40002dc0 += 360.0;
					}
					//->7257c
					while (fabs(dData_40002dc0 - dData_40002dc8) > 0.0014)
					{
						//72464
						if (bData_40003188 == 2)
						{
							//72474
							func_57414(3, 4, 1);
						}
						//72484
						if (bData_40003188 == 1)
						{
							//72494
							func_57414(3, 3, 1);
						}
						//724a4
						func_659c(10);
						func_6ae24(3);
						func_659c(10);
						//724c4
						Data_40004128.dData_208 = dData_40002db8;
						dData_40002dc0 = Data_40004128.dData_208;
						dData_40002dc0 += Data_40004128.dData_192;
						//->7252c
						while (dData_40002dc0 >= 360.0)
						{
							//72510
							dData_40002dc0 -= 360.0;
						}
						//->72564
						while (dData_40002dc0 < 0.0)
						{
							//72548
							dData_40002dc0 += 360.0;
						}
					} //while(...)
					//->72968
					break;
				
				case 1:
					//0x725bc
					func_6ae24(4);
				
					Data_40004128.dData_216 = dData_40002df0;
					dData_40002df8 = Data_40004128.dData_216;
					dData_40002df8 = Data_40004128.dData_200 - dData_40002df8;
					//->0x726bc
					while (fabs(dData_40002df8 - dData_40002e00) > 0.0014)
					{
						//0x72618
						if (bData_40003189 == 2)
						{
							//72628
							func_57414(4, 2, 1);
						}
						//72638
						if (bData_40003189 == 1)
						{
							//72648
							func_57414(4, 1, 1);
						}
						//72658
						func_659c(10);
						func_6ae24(4);
						func_659c(10);
						//72678
						Data_40004128.dData_216 = dData_40002df0;
						dData_40002df8 = Data_40004128.dData_216;
						dData_40002df8 = Data_40004128.dData_200 - dData_40002df8;
					}
					//->72968
					break;
				
				case 2:
					//0x726fc
					func_6ae24(1);
				
					Data_40004128.dData_208 = dData_40002d80;
					dData_40002dc0 = Data_40004128.dData_208;
					//->727c4
					while (fabs(dData_40002dc0 - dData_40002dc8) > 0.0014)
					{
						//7273c
						if (bData_40003188 == 2)
						{
							func_57414(1, 4, 2);
						}
						
						if (bData_40003188 == 1)
						{
							func_57414(1, 3, 2);
						}
						
						func_659c(10);
						func_6ae24(1);
						func_659c(10);
						
						Data_40004128.dData_208 = dData_40002d80;
						dData_40002dc0 = Data_40004128.dData_208;
					}
					//->72968
					break;
				
				case 3:
					//0x72804
					func_6ae24(2);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = fabs(Data_40004128.dData_216);
					//->72928
					while (fabs(dData_40002df8 - dData_40002e00) > 0.0014)
					{
						//728a0
						if (bData_40003189 == 2)
						{
							func_57414(2, 2, 2);
						}
						
						if (bData_40003189 == 1)
						{
							func_57414(1, 1, 2);
						}
						
						func_659c(10);
						func_6ae24(2);
						func_659c(10);
						
						Data_40004128.dData_216 = dData_40002da0;
						dData_40002df8 = fabs(Data_40004128.dData_216);
					}				
					#if 0
					break;
					#endif
				
				#if 0
				default:
					//0x72968
					break;
				#endif
			}
			//7296c
			func_5f0c0();			
			func_659c(100);
			func_7950(2);		
			//72980
			Data_40002eb0 = 0;
		} //if (Data_40002eb0 == 1)
		//7298c
		dData_40002ca8 = Data_40004380.dData_24;
		dData_40002cb0 = Data_40004380.dData_16;
		
		func_659c(2);
		//729bc
		if (bData_40002c1a == 0)
		{
			func_659c(50);
		}
		//729d4
		if (Data_40004128.bData_357 == 0)
		{
			func_659c(100);
		}
		//729ec -> 6d898
	} //while (1)
}
