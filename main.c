
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
extern void func_7e8(int, unsigned char, unsigned char, unsigned char, const unsigned char*);
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

extern void get_all_solar_system_object_equatorial_coordinates(void);
extern void func_1e228(void);
extern void func_3d72c(void);
extern void func_20b94(void);


/* 24574 - todo */
void func_24574(void)
{
}

/* 2575c - todo */
void func_2575c(void)
{
	switch (bData_40003196)
	{
		case 1:
			//0x25788
			Data_40002f20 = Data_400008ad;
			Data_40002f24 = Data_400008bd;
			Data_40002f28 = Data_400008c8;
			Data_40002f2c = Data_400008d2;
			Data_40002f30 = Data_400008d8;
			Data_40002f34 = Data_400008e7;
			Data_40002f38 = Data_400008f6;
			Data_40002f3c = Data_40000907;
			Data_40002f40 = Data_40000913;
			Data_40002f44 = Data_40000923;
		
			//TODO
		
			break;

		case 2:
			//0x26010
			break;
		
		case 3:
			//0x264d4
			break;
		
		case 4:
			//0x26ae0
			break;
		
		case 5:
			//0x270d0
			break;
		
		default:
			//0x27834
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
				func_7e8(1, 1, 3, strlen(Data_40003360), Data_40003360);
				func_7e8(0, 2, 3, strlen(Data_40003364), Data_40003364);
				func_7e8(0, 3, 3, strlen(Data_40003368), Data_40003368);
				func_7e8(0, 4, 3, strlen(Data_4000336c), Data_4000336c);
				func_7e8(0, 5, 3, strlen(Data_40003370), Data_40003370);
				func_7e8(0, 6, 3, strlen(Data_40003374), Data_40003374);
				func_7e8(0, 7, 3, strlen(Data_40003378), Data_40003378);
				func_7e8(0, 8, 3, strlen(Data_4000337c), Data_4000337c);
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
	switch (Data_40002c64)
	{
		case 0:
			//0x60e60
			Data_40002c64 = 0;
			bData_4000319a_SkyLandTargetId = 1;
			bData_4000319b = 1;
		
			func_394();
			//->0x60ec4
			break;
		
		case 23012:
			//0x60e8c
		case 23002:
			//0x60e94
		case 1:
			//0x60e98
		case 2:
			//0x60e9c
		case 23005:
			//0x60ea0
		case 23006:
			//0x60ea4
		case 23007:
			//0x60ea8
			func_394();
		
			Data_40002ec8 = 0;
		
			func_7950(1);
			break;
				
	}
}

/* 60ed0 - todo */
void func_60ed0(void)
{
	switch (Data_40002c64)
	{
		case 0:
			//0x611f8
			Data_40002c64 = 500;
			bData_40002c58 = 1;
		
			func_394();
		
			bData_40002c59 = 1;
			//->0x61ec0
			break;

		case 1000:
			//0x61228
			Data_40002c64 = 501; //Telescope align
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2000:
			//0x6124c
			Data_40002c64 = 502; //Target navigation
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3000:
			//0x61270
			Data_40002c64 = 503; //Utilities Commands
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4000:
			//0x61294
			Data_40002c64 = 504; //Parameter Setup
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
				
		case 1100: //1000 = Telescope align
			//0x612b8
			Data_40002c64 = 505; //One star align
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 1200:
			//0x612dc
			Data_40002c64 = 506; //Two stars align
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 1300:
			//0x61300
			Data_40002c64 = 507; //Three star align
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 1400:
			//0x61324
			Data_40002c64 = 508; //Target Sync
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 1500:
			//0x61348
			Data_40002c64 = 509; //Pole-Axis Deviation
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 1600:
			//0x6136c
			Data_40002c64 = 510; //RA Bklash Correction
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 1700:
			//0x61390
			Data_40002c64 = 511; //DEC Bklash Correction
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2100: //2000 = Target navigation
			//0x613b4
			Data_40002c64 = 516; //Solar System
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2200:
			//0x613d8
			Data_40002c64 = 517; //Constellation
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2300:
			//0x613fc
			Data_40002c64 = 518; //Famous Star
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2400:
			//0x61420
			Data_40002c64 = 519; //Messier Catalogue
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2500:
			//0x61444
			Data_40002c64 = 520; //NGC Deep Sky
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2600:
			//0x61468
			Data_40002c64 = 521; //IC Deep Sky
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2700:
			//0x6148c
			Data_40002c64 = 522; //Sh2 Deep Sky
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2800:
			//0x614b0
			Data_40002c64 = 523; //Bright Stars
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2900:
			//0x614d4
			Data_40002c64 = 524; //SAO Star
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2110:
			//0x614f8
			Data_40002c64 = 525; //User-def Object
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2120:
			//0x6151c
			Data_40002c64 = 526; //Specify Ra Dec
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 2130:
			//0x61540
			Data_40002c64 = 527; //Landmarks
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3100: //3000 = Utilities Commands
			//0x61564
			Data_40002c64 = 528; //Current Objects
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3200:
			//0x61588
			Data_40002c64 = 529; //Object Rise/Set
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3300:
			//0x615ac
			Data_40002c64 = 530; //Lunar Phase
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3400:
			//0x615d0
			Data_40002c64 = 531; //Timer
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3500:
			//0x615f4
			Data_40002c64 = 532; //Alarm
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3600:
			//0x61618
			Data_40002c64 = 533; //Field Angle Cal
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3700:
			//0x6163c
			Data_40002c64 = 534; //Magify Power Cal
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3800:
			//0x61660
			Data_40002c64 = 535; //Illumination
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 3900:
			//0x61684
			Data_40002c64 = 537; //Parkzen
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4100:
			//0x616a8
			Data_40002c64 = 538; //Time and Date
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4200:
			//0x616cc
			Data_40002c64 = 539; //Daylight Saving
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4300:
			//0x616f0
			Data_40002c64 = 540; //Site Setting
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4400:
			//0x61714
			Data_40002c64 = 541; //Sky/ Land
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4500:
			//0x61738
			Data_40002c64 = 542; //AZ/EQ
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4600:
			//0x6175c
			Data_40002c64 = 543; //Telescope Zero
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4700:
			//0x61780
			Data_40002c64 = 544; //Tracking Rate
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4800:
			//0x617a4
			Data_40002c64 = 545; //Language
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 4900:
			//0x617c8
			Data_40002c64 = 546; //Reset
			bData_40002c58 = 1;
		
			func_394();
			//->0x61ec0
			break;
		
		case 500:
			//0x617ec
			Data_40002c64 = 0;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 501: //0x1f5
			//0x6180c: Telescope align?
			Data_40002c64 = 1000;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 502:
			//0x61830: Target navigation?
			Data_40002c64 = 2000;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 503:
			//0x61854: Utilities Commands?
			Data_40002c64 = 3000;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 504: //0x1f8
			//0x61878: Parameter Setup?
			Data_40002c64 = 4000;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 505:
			//0x6189c
			Data_40002c64 = 1100;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 506:
			//0x618c0
			Data_40002c64 = 1200;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 507:
			//0x618e4
			Data_40002c64 = 1300;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 508:
			//0x61908
			Data_40002c64 = 1400;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 509: //0x1fd
			//0x6192c: Pole-Axis Deviation?
			Data_40002c64 = 1500;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;

		case 510:
			//0x61950
			Data_40002c64 = 1600;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 511:
			//0x61974
			Data_40002c64 = 1700;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 516:
			//0x61998
			Data_40002c64 = 2100;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 517:
			//0x619bc
			Data_40002c64 = 2200;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 518:
			//0x619e0
			Data_40002c64 = 2300;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 519:
			//0x61a04
			Data_40002c64 = 2400;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;

		case 520:
			//0x61a28
			Data_40002c64 = 2500;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 521:
			//0x61a4c
			Data_40002c64 = 2600;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 522:
			//0x61b60
			Data_40002c64 = 2700;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 523:
			//0x61b84
			Data_40002c64 = 2800;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 524: //0x20c
			//0x61ba8
			Data_40002c64 = 2900;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 525:
			//0x61bcc
			Data_40002c64 = 2110;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 526:
			//0x61bf0
			Data_40002c64 = 2120;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 527:
			//0x61c14
			Data_40002c64 = 2130;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 528:
			//0x61c38
			Data_40002c64 = 3100;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 529:
			//0x61c5c
			Data_40002c64 = 3200;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 530:
			//0x61c80
			Data_40002c64 = 3300;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 531:
			//0x61ca4
			Data_40002c64 = 3400;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 532:
			//0x61cc8
			Data_40002c64 = 3500;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 533:
			//0x61cec
			Data_40002c64 = 3600;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 534:
			//0x61d10
			Data_40002c64 = 3700;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 535:
			//0x61d34
			Data_40002c64 = 3800;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		#if 0
		case 536:
			//0x61ec0
			break;
		#endif
		
		case 537:
			//0x61d58
			Data_40002c64 = 3900;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 538:
			//0x61d7c
			Data_40002c64 = 4100;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 539:
			//0x61da0
			Data_40002c64 = 4200;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 540:
			//0x61dc4
			Data_40002c64 = 4300;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 541:
			//0x61de8
			Data_40002c64 = 4400;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 542:
			//0x61e0c
			Data_40002c64 = 4500;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 543:
			//0x61e30
			Data_40002c64 = 4600;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 544:
			//0x61e54
			Data_40002c64 = 4700;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		case 545:
			//0x61e78
			Data_40002c64 = 4800;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;

		case 546: //0x222
			//0x61e9c
			Data_40002c64 = 4900;
			bData_40002c58 = 0;
		
			func_394();
			//->0x61ec0
			break;
		
		#if 0
		default:
			//0x61ec0
			break;
		#endif
	}
}

/* 61ecc - todo */
void func_61ecc(void)
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
		(Data_40002c64 != 0x2ee1) && //12001
		(Data_40002c64 != 0x2b5f) && //11103
		(Data_40002c64 != 0x2bc3) && //11203
		(Data_40002c64 != 0x2b5e) && //11102
		(Data_40002c64 != 0x2bc2) && //11202
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
	#if 0
	int r4;
	int r5;
	#endif
		
	func_2328();
	uart0_init(360);
	uart1_init(360);
	func_7590();
	func_d2cc();
	func_5099c();
	func_243c(0xdcb, 0, 10, Data_40004c58);
	bData_40003196 = Data_40004c58[0];
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
		#if 0
		r4 = (fData_40003540 - (int)fData_40003540) * 60;
		r5 = fData_40003540;
		sprintf(Data_40002837, "  Lon:E%03dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
		#else
		sprintf(Data_40002837, "  Lon:E%03dd%02df ", 
			abs(fData_40003540), 
			abs((fData_40003540 - (int)fData_40003540) * 60));
		#endif
		//->6d494
	}
	else
	{
		//6d408
		#if 0
		r4 = (fData_40003540 - (int)fData_40003540) * 60;
		r5 = fData_40003540;
		sprintf(Data_40002837, "  Lon:W%03dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
		#else
		sprintf(Data_40002837, "  Lon:W%03dd%02df ", 
			abs(fData_40003540), 
			abs((fData_40003540 - (int)fData_40003540) * 60));
		#endif
	}
	//6d494
	if (fData_40003544 > 0)
	{
		//6d4a8
		#if 0
		r4 = (fData_40003544 - (int)fData_40003544) * 60;
		r5 = fData_40003544;
		sprintf(Data_40002847, "  Lat:N%02dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
		#else
		sprintf(Data_40002847, "  Lat:N%02dd%02df ", 
			abs(fData_40003544), 
			abs((fData_40003544 - (int)fData_40003544) * 60));
		#endif
		//->6d5c4
	}
	else
	{
		//6d538
		#if 0
		r4 = (fData_40003544 - (int)fData_40003544) * 60;
		r5 = fData_40003544;
		sprintf(Data_40002847, "  Lat:S%02dd%02df ", (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
		#else
		sprintf(Data_40002847, "  Lat:S%02dd%02df ", 
			abs(fData_40003544), 
			abs((fData_40003544 - (int)fData_40003544) * 60));
		#endif
	}
	//6d5c4
	if (Data_40003548 > 0)
	{
		//6d5d4
		#if 0
		r4 = Data_40003548;
		sprintf(Data_40002856, " Zone:E%02d", (r4 >= 0)? r4: -r4);
		#else
		sprintf(Data_40002856, " Zone:E%02d", abs(Data_40003548));
		#endif
	}
	else
	{
		//6d604
		#if 0
		r4 = Data_40003548;
		sprintf(Data_40002856, " Zone:W%02d", (r4 >= 0)? r4: -r4);
		#else
		sprintf(Data_40002856, " Zone:W%02d", abs(Data_40003548));
		#endif
	}
	//6d630
	func_659c(2000);
	func_394();
	
	if (bData_40002f1e == 1)
	{
		//6d64c
		func_6518(); //-> get time from RTC
		
		if (Data_40002e5c < 2000)
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
		Data_40002c64 = 41001; //0xa029;
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
			dData_40002ce8 = Data_40004128.dData_144 - 0.00083333333333/* 1/1200 */;
			Data_40002cd8 = dData_40002ce8;
			
			#if 0
			sp64 = Data_40002cd8;
			sp56 = dData_40002ce8 - sp64;
			sp48 = sp56 * 60.0;
			Data_40002cdc = sp48;
			#else
			Data_40002cdc = (dData_40002ce8 - Data_40002cd8) * 60.0;
			#endif
			
			#if 0
			sp64 = Data_40002cdc;
			sp56 = sp64 / 60.0;
			sp48 = Data_40002cd8;
			sp40 = dData_40002ce8 - sp48;
			sp32 = sp40 - sp56;
			sp24 = sp32 * 3600.0;
			fData_40002ce0 = sp24;
			#else
			fData_40002ce0 = (dData_40002ce8 - Data_40002cd8 - Data_40002cdc / 60.0) * 3600.0;
			#endif
			
			fData_40002d18_ObjectDeclination = fabs(Data_40004128.dData_152);
			Data_40002d00_ObjectDeclinationDegrees = fData_40002d18_ObjectDeclination;
			
			#if 0
			float r5 = Data_40002d00;
			float r4 = fData_40002d18_ObjectDeclination - r5;
			sp64 = r4;
			sp56 = sp64 * 60.0;
			Data_40002d04_ObjectDeclinationMinutes = sp56;
			#else
			Data_40002d04_ObjectDeclinationMinutes = (fData_40002d18_ObjectDeclination - 
				(float)Data_40002d00_ObjectDeclinationDegrees) * 60.0;
			#endif
			
			#if 0
			sp64 = Data_40002d04_ObjectDeclinationMinutes;
			sp56 = sp64 / 60.0;
			r5 = Data_40002d00;
			r4 = fData_40002d18_ObjectDeclination - r5;
			sp48 = r4;
			sp40 = sp48 - sp56;
			sp32 = sp40 * 3600.0;
			fData_40002d08_ObjectDeclinationSeconds = sp32;
			#else
			fData_40002d08_ObjectDeclinationSeconds = (fData_40002d18_ObjectDeclination - 
				(float)Data_40002d00_ObjectDeclinationDegrees - Data_40002d04_ObjectDeclinationMinutes / 60.0) * 3600.0;
			#endif
			
			//6db14
			if (Data_40004128.dData_80 >= 0.0)
			{
				//6db30
				Data_40002d44 = 1;
			}
			else
			{
				//0x6db40
				Data_40002d44 = -1;
			}
			//6db4c
			func_6ae24(1);
			
			Data_40004128.dData_208 = dData_40002d80;
			dData_400034e8 = dData_40002d80;
			dData_40002dc0 = Data_40004128.dData_208;
			dData_40002d78 = dData_40002d80;
			
			func_659c(5);
			func_6ae24(2);
			//6dbbc
			Data_40004128.dData_216 = dData_40002da0;
			dData_400034f8 = dData_40002da0;
			dData_40002df8 = fabs(Data_40004128.dData_216);
			dData_40002d98 = dData_40002df8;
			dData_40002d98 = fabs(dData_40002d98);
			//->0x6dc9c
			while (dData_40002d98 > 360.0)
			{
				//0x6dc80
				dData_40002d98 -= 360.0;
			}
			//6dcb4
			
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
			get_all_solar_system_object_equatorial_coordinates();
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
