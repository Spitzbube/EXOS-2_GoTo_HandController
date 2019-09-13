
#include <LPC214x.h>
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

extern void func_6518(void);
extern void func_659c(int);
extern void func_7590(void);
extern void func_75c4(void);
extern void func_7950(int);
extern void func_d2cc(void);
extern void func_acdc(double, double, double*, double*); 
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

/* 27844 - todo */
void func_27844(void)
{
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
}

/* 4f804 - todo */
void func_4f804(void)
{
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


