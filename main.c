
#include <LPC214x.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_types.h"
#include "data.h"

extern void uart0_init(int);
extern void uart1_write_byte(unsigned char);
extern void uart1_init(int);
extern void uart0_send(unsigned char* a, unsigned char b);
extern void lcd_display_clear(void);
extern void lcd_display_string(int, unsigned char, unsigned char, unsigned char, const unsigned char*);
extern int func_11d8(void);
extern void func_1210(void);
extern void func_2254(unsigned int);
extern void lpc_hw_init(void);
extern void flash_read(int, int, int, char*);
extern void flash_write(int, int, int, char*);
extern void func_27c4(float*, float*);
extern void func_2a1c(unsigned char* a, float* b, float* c, int* d);
extern char func_32a4();

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
extern void ValidateDateTimeSetRTC(void);

extern void get_all_solar_system_object_equatorial_coordinates(void);
extern void func_1e228(void);
extern void func_3d72c(void);
extern void func_20b94(void);

#ifndef OLIMEX_LPC2148

/* 4ede4 - todo */
void HandleStarKey(void)
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
	switch (Data_40002c64_MenuContextId)
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

/* 4ff84 - todo */
void func_4ff84(void)
{
	int h = atoi(Data_40002a3f);
	int m = atoi(Data_40002a42);
	int s = atoi(Data_40002a45);
	
	if ((h > 23) || (m > 59) || (s > 59))
	{
		Data_40002c64_MenuContextId = 35001;
		bData_4000318a = 1;
	}
	else
	{
		//0x4ffe0
		bData_4000322c = 1;
		Data_40002c64_MenuContextId = 3500;
		Data_40003220_AlarmHours = h;
		Data_40003224_AlarmMinutes = m;
		Data_40003228_AlarmSeconds = s;
	}
}

/* 50018 - todo */
void func_50018(void)
{
	unsigned int r1 = CTIME0;
	unsigned int r0 = CTIME1;
	
	Data_40003164_LunarPhaseYear = (r0 >> 16) & 0xfff;
	Data_40003168_LunarPhaseMonth = (r0 >> 8) & 0xf;
}

/* 50048 - todo */
void func_50048(void)
{
}

/* 50778 - todo */
void func_50778(void)
{

}

/* 50b40 - todo */
void HandleReset(void)
{
	char sp40[528];
	unsigned char sp20[20];
	float lon;
	float lat;
	int zone;
	unsigned short i;
	
	lcd_display_clear();
	lcd_display_string(0, 4, 1, 21, "System resetting...    ");
	
	i = 0;
	for (i = 0; i < 16; i++)
	{
		//0x50b74
		flash_read((unsigned short)(0xddd + i), 0, sizeof(sp40), sp40);		
		flash_write((unsigned short)(0xdc9 + i), 0, sizeof(sp40), sp40);
	}
	
	func_d2cc();
	func_5099c();
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0x44);
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0x64);

	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0x04);
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0x24);
	
	func_659c(10);
	
	if (bData_40002c1a == 1)
	{
		bData_40002e7a = 1;
	}
	else
	{
		bData_40002e7a = 0;
	}
	//50c98
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;
	
	func_27c4(&Data_4000329c, &Data_400032a0);
	
	Data_40004128.dData_192 = Data_4000329c;
	Data_40004128.dData_200 = Data_400032a0;
	
	func_2a1c(sp20, &lon, &lat, &zone);
	
	Data_40004128.geographicLongitude = lon;
	Data_40004128.geographicLatitude = lat;
	
	Data_40002e54_Zone = zone;
	
	Data_40002827[6] = sp20[0];
	Data_40002827[7] = sp20[1];
	Data_40002827[8] = sp20[2];
	Data_40002827[9] = sp20[3];
	Data_40002827[10] = sp20[4];
	Data_40002827[11] = sp20[5];
	Data_40002827[12] = sp20[6];
	Data_40002827[13] = sp20[7];
	
	if (lon > 0) //BUG? East is negative!
	{
		//50d90
		sprintf(Data_40002837, "  Lon:E%03dd%02df ",
			(int)lon,
			(int)((lon - (int)lon) * 60));
	}
	else
	{
		//0x50edc
		sprintf(Data_40002837, "  Lon:W%03dd%02df ",
			(int)lon,
			(int)((lon - (int)lon) * 60));
	}
	//0x50f30
	if (lat > 0)
	{
		//50f40
		sprintf(Data_40002847, "  Lat:N%02dd%02df ",
			(int)lat,
			(int)((lat - (int)lat) * 60));
	}
	else
	{
		//0x50f98
		sprintf(Data_40002847, "  Lat:S%02dd%02df ",
			(int)lat,
			(int)((lat - (int)lat) * 60));
	}
	//0x50fec
	if (zone > 0)
	{
		sprintf(Data_40002856, " Zone:E%02d", zone);
	}
	else
	{
		//0x5100c
		sprintf(Data_40002856, " Zone:W%02d", zone);
	}
	
	func_659c(2000);
	func_7950(2);
	func_659c(100);
	
	Data_40002c64_MenuContextId = 0;
}

/* 5104c - todo */
void func_5104c(void)
{
}

/* 514f8 - todo */
void func_514f8(void)
{
}

/* 517f4 - todo */
void func_517f4(void)
{
}

/* 51c7c - todo */
void func_51c7c(void)
{
}

/* 52478 - todo */
void func_52478(void)
{
}

/* 52720 - todo */
double func_52720(int a)
{
}

/* 57414 - todo */
void func_57414(int a, int b, int c)
{
	char sp12[8];
	char sp[8];
	unsigned char i;
	
	bData_40003430 = 1;
	bData_40003200 = 0;
	bData_40003201 = 0;
	
	sp[0] = 0x55;
	sp[1] = 0xaa;
	sp[2] = 0x01;
	sp[3] = 0x04;
	
	switch (a)
	{
		case 1:
			//0x57488
			sp[4] = 0x21;
			break;
		
		case 2:
			//0x57498
			sp[4] = 0x01;
			break;
		
		case 3:
			//0x574a8
			sp[4] = 0x61;
			break;
		
		case 4:
			//0x574b8
			sp[4] = 0x41;
			break;
		
		default:
			//0x574c8
			break;
	}

	switch (b)
	{
		case 3:
			//0x574f8
		case 1:
			//0x57500
			sp[5] = 0;
			break;
		
		case 4:
			//0x5750c
		case 2:
			//0x57514
			sp[5] = 1;
			break;
		
		default:
			//0x57520
			break;
	}
	
	sp[6] = 0;
	sp[7] = 0;
	
	for (i = 0; i < 8; i++)
	{
		//0x57540
		uart1_write_byte(sp[i]);
	}
	
	if (bData_4000319c == 0)
	{
		//5756c
		bData_4000319c = 1;
		
		func_7590();
		
		sp12[0] = 0x55;
		sp12[1] = 0xaa;
		sp12[2] = 0x01;
		sp12[3] = 0x04;
		
		switch (a)
		{
			case 1:
				//0x575c0
				sp12[4] = 0x01;
				break;
			
			case 2:
				//0x575d0
				sp12[4] = 0x21;
				break;
			
			case 3:
				//0x575e0
				sp12[4] = 0x41;
				break;
			
			case 4:
				//0x575f0
				sp12[4] = 0x61;
				break;
			
			default:
				//0x57600
				break;
		}
		
		switch (b)
		{
			case 3:
				//0x57630
			case 1:
				//0x57638
				sp12[5] = 0;
				break;
			
			case 4:
				//0x57644
			case 2:
				//0x5764c
				sp12[5] = 1;
				break;
			
			default:
				//0x57658
				break;
		}
		
		if (bData_40002c1a == 1)
		{
			//57674
			switch (c)
			{
				case 0:
					//0x576a8
					sp12[6] = 0;
					sp12[7] = 0;
					bData_40002e88 = 0;
					break;
				
				case 1:
					//0x576c4
					sp12[6] = 0;
					sp12[7] = 5;
					bData_40002e88 = 10;
					break;
				
				case 2:
					//0x576e8
					sp12[6] = 0;
					sp12[7] = 10;
					bData_40002e88 = 10;
					break;
				
				case 3:
					//0x57708
					sp12[6] = 0;
					sp12[7] = 40;
					bData_40002e88 = 10;
					break;
				
				case 4:
					//0x5772c
					sp12[6] = 0;
					sp12[7] = 160;
					bData_40002e88 = 10;
					break;
				
				case 5:
					//0x57750
					sp12[6] = 1;
					sp12[7] = 64;
					bData_40002e88 = 10;
					break;
				
				case 6:
					//0x57774
					sp12[6] = 2;
					sp12[7] = 128;
					bData_40002e88 = 10;
					break;
				
				case 7:
					//0x57798
					sp12[6] = 5;
					sp12[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case 8:
					//0x577bc
					sp12[6] = 10;
					sp12[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case 9:
					//0x577e0
					sp12[6] = 10;
					sp12[7] = 0;
					Data_400031a4 = 2560;
					bData_400031b8 = 1;
					bData_400031ba = sp12[4];
					bData_400031bc = sp12[5];
					Data_400031b4 = 1;
					bData_400031b9 = 0;
					bData_400031bb = sp12[4];
					bData_400031bd = sp12[5];
					Data_400031a8 = 0;
					bData_40002e88 = 10;
					break;
				#if 0				
				default:
					//0x57870
					break;
				#endif
			}
		} //if (bData_40002c1a == 1)
		//0x57874
		if (bData_40002c1a == 2)
		{
			//57884
			switch (c)
			{
				case 0:
					//0x578b8
					sp12[6] = 0;
					sp12[7] = 0;
					bData_40002e88 = 0;
					break;
				
				case 1:
					//0x578d4
					sp12[6] = 0;
					sp12[7] = 6;
					bData_40002e88 = 10;
					break;

				case 2:
					//0x578f8
					sp12[6] = 0;
					sp12[7] = 12;
					bData_40002e88 = 10;
					break;

				case 3:
					//0x5791c
					sp12[6] = 0;
					sp12[7] = 48;
					bData_40002e88 = 10;
					break;

				case 4:
					//0x57940
					sp12[6] = 0;
					sp12[7] = 96;
					bData_40002e88 = 10;
					break;

				case 5:
					//0x57964
					sp12[6] = 0;
					sp12[7] = 192;
					bData_40002e88 = 10;
					break;

				case 6:
					//0x57988
					sp12[6] = 1;
					sp12[7] = 128;
					bData_40002e88 = 10;
					break;

				case 7:
					//0x579ac
					sp12[6] = 2;
					sp12[7] = 28;
					bData_40002e88 = 10;
					break;

				case 8:
					//0x579d0
					sp12[6] = 3;
					sp12[7] = 56;
					bData_40002e88 = 10;
					break;

				case 9:
					//0x579f4
					sp12[6] = 3;
					sp12[7] = 212;
					bData_40002e88 = 10;
					break;
				#if 0
				default:
					//0x57a18
					break;
				#endif
			}
		} //if (bData_40002c1a == 2)
		//0x57a1c
		for (i = 0; i < 8; i++)
		{
			//0x57a24
			uart1_write_byte(sp12[i]);
		}
	} //if (bData_4000319c == 0)
	//0x57a40
}

/* 57a4c - todo */
void func_57a4c(void)
{
	switch (bData_4000318a - 5)
	{
		case 0:
			//0x57a90
			bData_4000318a = 6;
			break;

		case 1:
			//0x57aa4
			bData_4000318a = 7;
			break;

		case 2:
			//0x57ab8
			bData_4000318a = 9;
			break;

		case 4:
			//0x57acc
			bData_4000318a = 10;
			break;

		case 5:
			//0x57ae0
			bData_4000318a = 12;
			break;

		case 7:
			//0x57af4
			bData_4000318a = 13;
			break;

		case 8:
			//0x57b08
			bData_4000318a = 15;
			break;
		
		case 10:
			//0x57b1c
			bData_4000318a = 5;
			break;

		default:
			//0x57b30
			break;
	}
}

/* 57b40 - todo */
void func_57b40(void)
{
	switch (bData_4000318a - 6)
	{
		case 0:
			//0x57b80
			bData_4000318a = 7;
			break;

		case 1:
			//0x57b94
			bData_4000318a = 9;
			break;

		case 3:
			//0x57ba8
			bData_4000318a = 10;
			break;

		case 4:
			//0x57bbc
			bData_4000318a = 12;
			break;

		case 6:
			//0x57bd0
			bData_4000318a = 13;
			break;

		case 7:
			//0x57be4
			bData_4000318a = 15;
			break;

		case 9:
			//0x57bf8
			bData_4000318a = 6;
			break;
		
		default:
			//0x57c0c
			break;
	}
}

/* 57c1c - todo */
void HandleRightKey(void)
{
}

/* 5969c - todo */
void HandleLeftKey(void)
{
}

/* 59dd0 - todo */
void func_59dd0(void)
{
}

/* 5a57c - todo */
void func_5a57c(int a, int b)
{
	switch (a)
	{
		case 0:
			//0x5a590
			switch (b)
			{
				case 11:
					//0x5a5d0
					if (bData_40003173 > 1)
					{
						//5a5e4
						bData_40003173--;
					}
					else
					{
						//0x5a5fc
						bData_40003171--;
					}
					//0x5a610
					if (bData_40003172 > 1)
					{
						//5a620
						bData_40003172--;
					}
					else
					{
						//0x5a638
						bData_40003170--;
					}
					//0x5a64c -> 0x5a860
					break;
				
				case 12:
					//0x5a650
					break;
				
				case 13:
					//0x5a6d0
					break;
				
				case 14:
					//0x5a750
					break;
				
				case 22:
					//0x5a7d0
					break;
				
				case 23:
					//0x5a814
					break;
				
				default:
					//0x5a858
					break;
			}
			break;
		
		case 1:
			//0x5a868
			switch (b)
			{
				case 11:
					//0x5a8a8: Alignment items
					if (bData_40003173 < 4)
					{
						bData_40003173++;
					}
					else
					{
						bData_40003171++;
					}

					if (bData_40003172 < 8)
					{
						bData_40003172++;
					}
					else
					{
						bData_40003170++;
					}
					break;
				
				case 12:
					//0x5a928: Navigation items
					if (bData_40003177 < 4)
					{
						//5a93c
						bData_40003177++;
					}
					else
					{
						//0x5a954
						bData_40003175++;
					}
					//0x5a968
					if (bData_40003176 < 8)
					{
						bData_40003176++;
					}
					else
					{
						//0x5a990
						bData_40003174++;
					}
					//0x5a9a4 -> 0x5ab38
					break;
				
				case 13:
					//0x5a9a8: Utilities items
					if (bData_4000317b < 4)
					{
						bData_4000317b++;
					}
					else
					{
						bData_40003179++;
					}

					if (bData_4000317a < 8)
					{
						bData_4000317a++;
					}
					else
					{
						bData_40003178++;
					}
					break;
				
				case 14:
					//0x5aa28: Setup items
					if (bData_4000317f < 4)
					{
						bData_4000317f++;
					}
					else
					{
						bData_4000317d++;
					}

					if (bData_4000317e < 8)
					{
						bData_4000317e++;
					}
					else
					{
						bData_4000317c++;
					}
					break;
				
				case 22:
					//0x5aaa8
					if (bData_40003182 < 8)
					{
						bData_40003182++;
					}
					else
					{
						bData_40003180++;
					}
					break;
				
				case 23:
					//0x5aaec
					if (bData_40003186 < 8)
					{
						bData_40003186++;
					}
					else
					{
						bData_40003184++;
					}
					break;
			}
			break;
		
		default:
			//0x5ab40
			break;
	}
}

#include "HandleDownKey.c"

#include "HandleUpKey.c"

/* 5f0c0 - todo */
void func_5f0c0(void)
{
}

#include "HandleMinusKey.c"

/* 60d54 - todo */
void HandlePlusKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 0:
			//0x60d78
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = 1;
			bData_400031be = 1;
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_400031e0 = 1;
		
			bData_400031bf = func_32a4();
		
			bData_400031be = 0;
			break;
		
		case 5000:
			//0x60dc0
			Data_40002c64_MenuContextId = 1;
			bData_400031be = 1;
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_400031e0 = 1;		
			//break;
		
		default:
			//0x60dec
			break;
	}
}

/* 60dfc - todo */
void HandleFKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 0:
			//0x60e60
			Data_40002c64_MenuContextId = 0;
			bData_4000319a_SkyLandTargetId = 1;
			bData_4000319b = 1;
		
			lcd_display_clear();
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
			lcd_display_clear();
		
			Data_40002ec8 = 0;
		
			func_7950(1);
			break;
				
	}
}

/* 60ed0 - todo */
void HandleHelpKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 0:
			//0x611f8
			Data_40002c64_MenuContextId = 500; //Main Screen Help Pages
			bData_40002c58 = 1;
		
			lcd_display_clear();
		
			bData_40002c59_MainScreenHelpPage = 1;
			//->0x61ec0
			break;

		case 1000:
			//0x61228
			Data_40002c64_MenuContextId = 501; //Telescope align
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2000:
			//0x6124c
			Data_40002c64_MenuContextId = 502; //Target navigation
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3000:
			//0x61270
			Data_40002c64_MenuContextId = 503; //Utilities Commands
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4000:
			//0x61294
			Data_40002c64_MenuContextId = 504; //Parameter Setup
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
				
		case 1100: //1000 = Telescope align
			//0x612b8
			Data_40002c64_MenuContextId = 505; //One star align
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1200:
			//0x612dc
			Data_40002c64_MenuContextId = 506; //Two stars align
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1300:
			//0x61300
			Data_40002c64_MenuContextId = 507; //Three star align
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1400:
			//0x61324
			Data_40002c64_MenuContextId = 508; //Target Sync
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1500:
			//0x61348
			Data_40002c64_MenuContextId = 509; //Pole-Axis Deviation
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1600:
			//0x6136c
			Data_40002c64_MenuContextId = 510; //RA Bklash Correction
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 1700:
			//0x61390
			Data_40002c64_MenuContextId = 511; //DEC Bklash Correction
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2100: //2000 = Target navigation
			//0x613b4
			Data_40002c64_MenuContextId = 516; //Solar System
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2200:
			//0x613d8
			Data_40002c64_MenuContextId = 517; //Constellation
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2300:
			//0x613fc
			Data_40002c64_MenuContextId = 518; //Famous Star
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2400:
			//0x61420
			Data_40002c64_MenuContextId = 519; //Messier Catalogue
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2500:
			//0x61444
			Data_40002c64_MenuContextId = 520; //NGC Deep Sky
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2600:
			//0x61468
			Data_40002c64_MenuContextId = 521; //IC Deep Sky
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2700:
			//0x6148c
			Data_40002c64_MenuContextId = 522; //Sh2 Deep Sky
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2800:
			//0x614b0
			Data_40002c64_MenuContextId = 523; //Bright Stars
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2900:
			//0x614d4
			Data_40002c64_MenuContextId = 524; //SAO Star
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2110:
			//0x614f8
			Data_40002c64_MenuContextId = 525; //User-def Object
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2120:
			//0x6151c
			Data_40002c64_MenuContextId = 526; //Specify Ra Dec
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 2130:
			//0x61540
			Data_40002c64_MenuContextId = 527; //Landmarks
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3100: //3000 = Utilities Commands
			//0x61564
			Data_40002c64_MenuContextId = 528; //Current Objects
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3200:
			//0x61588
			Data_40002c64_MenuContextId = 529; //Object Rise/Set
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3300:
			//0x615ac
			Data_40002c64_MenuContextId = 530; //Lunar Phase
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3400:
			//0x615d0
			Data_40002c64_MenuContextId = 531; //Timer
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3500:
			//0x615f4
			Data_40002c64_MenuContextId = 532; //Alarm
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3600:
			//0x61618
			Data_40002c64_MenuContextId = 533; //Field Angle Cal
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3700:
			//0x6163c
			Data_40002c64_MenuContextId = 534; //Magify Power Cal
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3800:
			//0x61660
			Data_40002c64_MenuContextId = 535; //Illumination
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 3900:
			//0x61684
			Data_40002c64_MenuContextId = 537; //Parkzen
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4100:
			//0x616a8
			Data_40002c64_MenuContextId = 538; //Time and Date
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4200:
			//0x616cc
			Data_40002c64_MenuContextId = 539; //Daylight Saving
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4300:
			//0x616f0
			Data_40002c64_MenuContextId = 540; //Site Setting
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4400:
			//0x61714
			Data_40002c64_MenuContextId = 541; //Sky/ Land
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4500:
			//0x61738
			Data_40002c64_MenuContextId = 542; //AZ/EQ
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4600:
			//0x6175c
			Data_40002c64_MenuContextId = 543; //Telescope Zero
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4700:
			//0x61780
			Data_40002c64_MenuContextId = 544; //Tracking Rate
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4800:
			//0x617a4
			Data_40002c64_MenuContextId = 545; //Language
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 4900:
			//0x617c8
			Data_40002c64_MenuContextId = 546; //Reset
			bData_40002c58 = 1;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 500:
			//0x617ec
			Data_40002c64_MenuContextId = 0;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 501: //0x1f5
			//0x6180c: Telescope align?
			Data_40002c64_MenuContextId = 1000;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 502:
			//0x61830: Target navigation?
			Data_40002c64_MenuContextId = 2000;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 503:
			//0x61854: Utilities Commands?
			Data_40002c64_MenuContextId = 3000;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 504: //0x1f8
			//0x61878: Parameter Setup?
			Data_40002c64_MenuContextId = 4000;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 505:
			//0x6189c
			Data_40002c64_MenuContextId = 1100;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 506:
			//0x618c0
			Data_40002c64_MenuContextId = 1200;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 507:
			//0x618e4
			Data_40002c64_MenuContextId = 1300;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 508:
			//0x61908
			Data_40002c64_MenuContextId = 1400;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 509: //0x1fd
			//0x6192c: Pole-Axis Deviation?
			Data_40002c64_MenuContextId = 1500;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;

		case 510:
			//0x61950
			Data_40002c64_MenuContextId = 1600;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 511:
			//0x61974
			Data_40002c64_MenuContextId = 1700;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 516:
			//0x61998
			Data_40002c64_MenuContextId = 2100;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 517:
			//0x619bc
			Data_40002c64_MenuContextId = 2200;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 518:
			//0x619e0
			Data_40002c64_MenuContextId = 2300;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 519:
			//0x61a04
			Data_40002c64_MenuContextId = 2400;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;

		case 520:
			//0x61a28
			Data_40002c64_MenuContextId = 2500;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 521:
			//0x61a4c
			Data_40002c64_MenuContextId = 2600;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 522:
			//0x61b60
			Data_40002c64_MenuContextId = 2700;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 523:
			//0x61b84
			Data_40002c64_MenuContextId = 2800;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 524: //0x20c
			//0x61ba8
			Data_40002c64_MenuContextId = 2900;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 525:
			//0x61bcc
			Data_40002c64_MenuContextId = 2110;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 526:
			//0x61bf0
			Data_40002c64_MenuContextId = 2120;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 527:
			//0x61c14
			Data_40002c64_MenuContextId = 2130;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 528:
			//0x61c38
			Data_40002c64_MenuContextId = 3100;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 529:
			//0x61c5c
			Data_40002c64_MenuContextId = 3200;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 530:
			//0x61c80
			Data_40002c64_MenuContextId = 3300;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 531:
			//0x61ca4
			Data_40002c64_MenuContextId = 3400;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 532:
			//0x61cc8
			Data_40002c64_MenuContextId = 3500;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 533:
			//0x61cec
			Data_40002c64_MenuContextId = 3600;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 534:
			//0x61d10
			Data_40002c64_MenuContextId = 3700;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 535:
			//0x61d34
			Data_40002c64_MenuContextId = 3800;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		#if 0
		case 536:
			//0x61ec0
			break;
		#endif
		
		case 537:
			//0x61d58
			Data_40002c64_MenuContextId = 3900;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 538:
			//0x61d7c
			Data_40002c64_MenuContextId = 4100;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 539:
			//0x61da0
			Data_40002c64_MenuContextId = 4200;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 540:
			//0x61dc4
			Data_40002c64_MenuContextId = 4300;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 541:
			//0x61de8
			Data_40002c64_MenuContextId = 4400;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 542:
			//0x61e0c
			Data_40002c64_MenuContextId = 4500;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 543:
			//0x61e30
			Data_40002c64_MenuContextId = 4600;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 544:
			//0x61e54
			Data_40002c64_MenuContextId = 4700;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;
		
		case 545:
			//0x61e78
			Data_40002c64_MenuContextId = 4800;
			bData_40002c58 = 0;
		
			lcd_display_clear();
			//->0x61ec0
			break;

		case 546: //0x222
			//0x61e9c
			Data_40002c64_MenuContextId = 4900;
			bData_40002c58 = 0;
		
			lcd_display_clear();
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
void Handle9Key(void)
{
}

/* 637e8 - todo */
void Handle8Key(void)
{
}

/* 64324 - todo */
void Handle7Key(void)
{
}

/* 64e18 - todo */
void Handle6Key(void)
{
}

/* 65894 - todo */
void Handle5Key(void)
{
}

/* 66378 - todo */
void Handle4Key(void)
{
}

/* 66e3c - todo */
void Handle3Key(void)
{
}

/* 678b8 - todo */
void Handle2Key(void)
{
}

/* 68934 - todo */
void Handle1Key(void)
{
}

/* 69348 - todo */
void Handle0Key(void)
{
}

/* 6a0e4 - todo */
char ConvertKeyCode(void)
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
			//0x6a18c: 10100001 / 11100001
			r4 = 16;
			break;
		
		case 2:
			//0x6a198: 10100010 / 11100010
			r4 = 1;
			break;
		
		case 3:
			//0x6a1a4: 10100011 / 11100011
			r4 = 4;
			break;
		
		case 4:
			//0x6a1b0: 10100100 / 11100100
			r4 = 7;
			break;
		
		case 5:
			//0x6a1bc: 10100101 / 11100101
			r4 = 10;
			break;
		
		case 6:
			//0x6a1c8: 10100110 / 11100110
			r4 = 15;
			break;
		
		case 7:
			//0x6a1d4: 10100111 / 11100111
			r4 = 2;
			break;
		
		case 8:
			//0x6a1e0: 10101000 / 11101000
			r4 = 5;
			break;
		
		case 9:
			//0x6a1ec: 10101001 / 11101001
			r4 = 8;
			break;
		
		case 10:
			//0x6a1f8: 10101010 / 11101010
			r4 = 0;
			break;
		
		case 11:
			//0x6a204: 10101011 / 11101011
			r4 = 17;
			break;
		
		case 12:
			//0x6a210: 10101100 / 11101100
			r4 = 3;
			break;
		
		case 13:
			//0x6a21c: 10101101 / 11101101
			r4 = 6;
			break;
		
		case 14:
			//0x6a228: 10101110 / 11101110
			r4 = 9;
			break;
		
		case 15:
			//0x6a234: 10101111 / 11101111
			r4 = 11;
			break;
		
		case 16:
			//0x6a240: 10110000 / 11110000
			r4 = 14;
			break;
		
		case 17:
			//0x6a24c: 10110001 / 11110001
			r4 = 19;
			break;
		
		case 18:
			//0x6a258: 10110010 / 11110010
			r4 = 12;
			break;
		
		case 19:
			//0x6a264: 10110011 / 11110011
			r4 = 20;
			break;
		
		case 20:
			//0x6a270: 10110100 / 11110100
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
	bData_40002c69_KeyCode = ConvertKeyCode();
	
	if (bData_40002c68 == 0)
	{
		//6a330
		if (bData_40002c5a == 1)
		{
			func_d784(1);
		}
		//6a348
		switch (bData_40002c69_KeyCode)
		{
			case 0:
				//0x6a3c0: "0 / Stop"
				Handle0Key();
				bData_40003505 = 1;
				break;
			
			case 1:
				//0x6a3d8: "1"
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a40c
					Handle1Key();
				}
				bData_40003505 = 1;
				break;
				
			case 2:
				//0x6a420
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a454
					Handle2Key();
				}
				bData_40003505 = 1;
				break;
			
			case 3:
				//0x6a468
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a49c
					Handle3Key();
				}
				bData_40003505 = 1;
				break;
			
			case 4:
				//0x6a4b0
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a4e4
					Handle4Key();
				}
				bData_40003505 = 1;
				break;
			
			case 5:
				//0x6a4f8
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a52c
					Handle5Key();
				}
				bData_40003505 = 1;
				break;
						
			case 6:
				//0x6a540
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a574
					Handle6Key();
				}
				bData_40003505 = 1;
				break;
			
			case 7:
				//0x6a588
				Handle7Key();
				bData_40003505 = 1;
				break;
			
			case 8:
				//0x6a5a0
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a5d4
					Handle8Key();
				}
				bData_40003505 = 1;
				break;
			
			case 9:
				//0x6a5e8
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a61c
					Handle9Key();
				}
				bData_40003505 = 1;
				break;
			
			case 10:
				//0x6a630: "Help"
				HandleHelpKey();
				bData_40003505 = 1;
				break;
			
			case 11:
				//0x6a648: "F"
				HandleFKey();
				bData_40003505 = 1;
				break;
			
			case 12:
				//0x6a660: "+"
				HandlePlusKey();
				bData_40003505 = 1;
				break;
			
			case 13:
				//0x6a678: "-"
				HandleMinusKey();
				bData_40003505 = 1;
				break;
			
			case 14:
				//0x6a690: "Up"
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a6c4
					HandleUpKey();
				}
				bData_40003505 = 1;
				break;
			
			case 15:
				//0x6a6d8: "Down"
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a70c
					HandleDownKey();
				}
				bData_40003505 = 1;
				break;
			
			case 16:
				//0x6a720: "Left"
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a754
					HandleLeftKey();
				}
				bData_40003505 = 1;
				break;
			
			case 17:
				//0x6a768: "Right"
				if (((Data_40004128.bData_357 != 0) && (bData_40002e88 == 2)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a79c
					HandleRightKey();
				}
				bData_40003505 = 1;
				break;
			
			#if 0
			case 18:
				//0x6a900
			#endif
			
			case 19:
				//0x6a7b0: "Enter"
				HandleEnterKey();
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
				//0x6a8e8: "*"
				HandleStarKey();
				bData_40003505 = 1;
				break;
			
			default:
				//6a900
				break;
		} //switch (bData_40002c69_KeyCode)
		
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
	if ((Data_40002c64_MenuContextId != 0) &&
		(Data_40002c64_MenuContextId != 0x2ee1) && //12001
		(Data_40002c64_MenuContextId != 0x2b5f) && //11103
		(Data_40002c64_MenuContextId != 0x2bc3) && //11203
		(Data_40002c64_MenuContextId != 0x2b5e) && //11102
		(Data_40002c64_MenuContextId != 0x2bc2) && //11202
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
	if (bData_40002f1e_SetupLocalData == 1)
	{
		//6aa14
		if (bData_400031ec != 0)
		{
			//6aa24
			func_6518(); //-> get time from RTC
			
			sprintf(Data_400037ec, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40003150, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
			sprintf(Data_40002655, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40002660, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
			
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
		//0x6aaec
		func_1e228();
	}
	//6aaf0
	if ((bData_4000322c == 1) && 
		(Data_40003220_AlarmHours == bData_40002e62_Hours) &&
		(Data_40003224_AlarmMinutes == bData_40002e63_Minutes) &&
		(Data_40003228_AlarmSeconds == bData_40002e64_Seconds))
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

	bData_40002c13_uart1ReceiveComplete = 0;
	
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

	bData_40002c13_uart1ReceiveComplete = 0;
	
	func_2254(10);
	
	for (r5 = 50; (bData_40002c13_uart1ReceiveComplete == 0) && (r5 > 2); r5--)
	{
		func_659c(5);
	}
	
	sp8.i = 0;
		
	if (bData_40002c13_uart1ReceiveComplete == 1)
	{
		switch (a)
		{
			case 1:
				sp8.b[1] = Data_40003592_uart1ReceiveDataBuffer[1];
				sp8.b[0] = Data_40003592_uart1ReceiveDataBuffer[2];
			  d = sp8.i;
				break;
			
			case 2:
				sp8.b[1] = Data_40003592_uart1ReceiveDataBuffer[1];
				sp8.b[0] = Data_40003592_uart1ReceiveDataBuffer[2];
			  d = sp8.i;
				break;
			
			case 3:
				sp8.b[1] = Data_40003592_uart1ReceiveDataBuffer[1];
				sp8.b[0] = Data_40003592_uart1ReceiveDataBuffer[2];
			  d = sp8.i;
				break;
			
			case 4:
				sp8.b[1] = Data_40003592_uart1ReceiveDataBuffer[1];
				sp8.b[0] = Data_40003592_uart1ReceiveDataBuffer[2];
			  d = sp8.i;
				break;
		}
		
		bData_40002c13_uart1ReceiveComplete = 0;
	}

	return d;
}

/* 6ae24 - todo */
double func_6ae24(int a)
{
	unsigned char r5;
	double sp8;
	
	bData_40002c13_uart1ReceiveComplete = 0;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);

	switch (a)
	{
		case 1:
			//0x6ae7c
			uart1_write_byte(0x04);
			break;
		
		case 2:
			//0x6ae8c
			uart1_write_byte(0x24);
			break;
		
		case 3:
			//0x6ae9c
			uart1_write_byte(0x44);
			break;
		
		case 4:
			//0x6aeac
			uart1_write_byte(0x64);
			break;
		
		default:
			//0x6aebc
			break;		
	}
	
	bData_40002c13_uart1ReceiveComplete = 0;
	
	func_2254(2);
	
	r5 = 20;
	
	if (bData_40002c1a != 0)
	{
		while ((bData_40002c13_uart1ReceiveComplete == 0) && (r5 > 2))
		{
			//0x6aef4
			func_659c(5);
			r5--;
		}
	}
	//0x6af1c
	if (bData_40002c13_uart1ReceiveComplete == 1)
	{
		//6af2c
		switch (a)
		{
			case 1:
				//0x6af50
				if (Data_40003592_uart1ReceiveDataBuffer[0] == 0x04)
				{
					//6af64
					Data_400031a0.bData[3] = Data_40003592_uart1ReceiveDataBuffer[2];
					Data_400031a0.bData[2] = Data_40003592_uart1ReceiveDataBuffer[3];
					Data_400031a0.bData[1] = Data_40003592_uart1ReceiveDataBuffer[4];
					
					sp8 = Data_400031a0.Data;
					dData_40002d80 = sp8 * 360.0 / 841763108.524031996726989746094;
				}
				//0x6afcc -> 0x6b15c
				break;
			
			case 2:
				//0x6afd0
				if (Data_40003592_uart1ReceiveDataBuffer[0] == 0x24)
				{
					//6af64
					Data_400031a0.bData[3] = Data_40003592_uart1ReceiveDataBuffer[2];
					Data_400031a0.bData[2] = Data_40003592_uart1ReceiveDataBuffer[3];
					Data_400031a0.bData[1] = Data_40003592_uart1ReceiveDataBuffer[4];
					
					sp8 = Data_400031a0.Data;
					dData_40002da0 = sp8 * 360.0 / 841763108.524031996726989746094;
				}
				//0x6b04c -> 0x6b15c
				break;
			
			case 3:
				//0x6b050
				if (Data_40003592_uart1ReceiveDataBuffer[0] == 0x44)
				{
					//6b064
					Data_400031a0.bData[3] = Data_40003592_uart1ReceiveDataBuffer[2];
					Data_400031a0.bData[2] = Data_40003592_uart1ReceiveDataBuffer[3];
					Data_400031a0.bData[1] = Data_40003592_uart1ReceiveDataBuffer[4];
					
					sp8 = Data_400031a0.Data;
					dData_40002db8 = sp8 * 360.0 / 278879846.400000035762786865234;
					#if 1
					if (Data_400031a0.Data == 0)
					{
					}
					#endif
				}
				//0x6b0d0 -> 0x6b15c
				break;
			
			case 4:
				//0x6b0d4
				if (Data_40003592_uart1ReceiveDataBuffer[0] == 0x64)
				{
					//6b0e8
					Data_400031a0.bData[3] = Data_40003592_uart1ReceiveDataBuffer[2];
					Data_400031a0.bData[2] = Data_40003592_uart1ReceiveDataBuffer[3];
					Data_400031a0.bData[1] = Data_40003592_uart1ReceiveDataBuffer[4];
					
					sp8 = Data_400031a0.Data;
					dData_40002df0 = sp8 * 360.0 / 383201280.0;
				}
				//0x6b150 -> 0x6b15c
				break;
			
			default:
				//0x6b154
				break;		
		}
		//6b160
		bData_40002c13_uart1ReceiveComplete = 0;
	}
	//0x6b16c
}

/* 6b17c - todo */
void func_6b17c(void)
{
	unsigned char r3;
	
	Data_40003204 = 0;
	Data_40003208 = 0;
	bData_40002c13_uart1ReceiveComplete = 0;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	uart1_write_byte(0x81);
	
	bData_40002c13_uart1ReceiveComplete = 0;
	
	r3 = 10;
	while ((bData_40002c13_uart1ReceiveComplete == 0) &&
		(bData_40002c13_uart1ReceiveComplete == 0))
	{
		//0x6b1d8
		func_2254(1);
		r3--;
	}
	//0x6b208
	if (bData_40002c13_uart1ReceiveComplete == 1)
	{
		//6b218
		if (Data_40003592_uart1ReceiveDataBuffer[0] == 129)
		{
			//6b228
			Data_40003592_uart1ReceiveDataBuffer[1] = 
				~Data_40003592_uart1ReceiveDataBuffer[1];
			
			if ((Data_40003592_uart1ReceiveDataBuffer[1] & 1) == 1)
			{
				//6b250
				Data_40003204 = 1;
			}
			//0x6b25c
			if ((Data_40003592_uart1ReceiveDataBuffer[1] & 8) == 8)
			{
				//6b270
				Data_40003204 = -1;
			}
			//0x6b27c
			if ((Data_40003592_uart1ReceiveDataBuffer[1] & 2) == 2)
			{
				//6b290
				Data_40003208 = 1;
			}
			//0x6b29c
			if ((Data_40003592_uart1ReceiveDataBuffer[1] & 4) == 4)
			{
				//6b290
				Data_40003208 = -1;
			}
			#if 1			
			if ((Data_40003592_uart1ReceiveDataBuffer[1] & 16) == 16)
			{
			}
			#endif
		}
		//0x6b2c0
		bData_40002c13_uart1ReceiveComplete = 0;
	}
	//0x6b2cc
}

/* 6c804 - complete */
void ShowStartupScreen(void)
{
	lcd_display_string(0, 3, 1, 22, " BRESSER GOTO SYSTEM  ");
	lcd_display_string(0, 5, 1, 22, "     EXOS EQ v2.3     ");
}

#endif //OLIMEX_LPC2148

/* 6c848 - todo */
int func_6c848(void)
{
	if (bData_40002c0b_uart0ReceiveComplete == 1)
	{
		bData_4000352d = Data_40003588_uart0ReceiveDataBuffer[0];
		
#ifdef OLIMEX_LPC2148
		{
			static char buf[105];

			snprintf(buf, 100, "func_6c848: bData_4000352d: 0x%x\n\r", bData_4000352d);
			uart1_send((unsigned char*)buf, strlen(buf));
		}
#endif

		switch (bData_4000352d)
		{
			case 35:
				//6c898
			case 36:
				//6c8a0
				Data_40002c28.bData[0] = Data_40003588_uart0ReceiveDataBuffer[1];
				Data_40002c28.bData[1] = Data_40003588_uart0ReceiveDataBuffer[2];
				Data_40002c28.bData[2] = Data_40003588_uart0ReceiveDataBuffer[3];
				Data_40002c28.bData[3] = Data_40003588_uart0ReceiveDataBuffer[4];
				fData_40003510 = *((float*)&Data_40002c28);
			
				Data_40002c28.bData[0] = Data_40003588_uart0ReceiveDataBuffer[5];
				Data_40002c28.bData[1] = Data_40003588_uart0ReceiveDataBuffer[6];
				Data_40002c28.bData[2] = Data_40003588_uart0ReceiveDataBuffer[7];
				Data_40002c28.bData[3] = Data_40003588_uart0ReceiveDataBuffer[8];
				fData_40003514 = *((float*)&Data_40002c28);
				//->6ca60
				break;
			
			case 37:
				//6c92c: "Standort einstellen"
				Data_40002c28.bData[0] = Data_40003588_uart0ReceiveDataBuffer[1];
				Data_40002c28.bData[1] = Data_40003588_uart0ReceiveDataBuffer[2];
				Data_40002c28.bData[2] = Data_40003588_uart0ReceiveDataBuffer[3];
				Data_40002c28.bData[3] = Data_40003588_uart0ReceiveDataBuffer[4];
				fData_40003518_ReceiveExternalSiteLongitude = *((float*)&Data_40002c28);
			
				Data_40002c28.bData[0] = Data_40003588_uart0ReceiveDataBuffer[5];
				Data_40002c28.bData[1] = Data_40003588_uart0ReceiveDataBuffer[6];
				Data_40002c28.bData[2] = Data_40003588_uart0ReceiveDataBuffer[7];
				Data_40002c28.bData[3] = Data_40003588_uart0ReceiveDataBuffer[8];
				fData_4000351c_ReceiveExternalSiteLatitude = *((float*)&Data_40002c28);
				//->6ca60
				break;
			
			case 38:
				//6c9bc: "Zeit einstellen"
				Data_40003524_ReceiveExternalYear = Data_40003588_uart0ReceiveDataBuffer[1] * 100 + 
												Data_40003588_uart0ReceiveDataBuffer[2];
				bData_40003528_ReceiveExternalMonth = Data_40003588_uart0ReceiveDataBuffer[3];
				bData_40003529_ReceiveExternalDay = Data_40003588_uart0ReceiveDataBuffer[4];
				bData_4000352a_ReceiveExternalHours = Data_40003588_uart0ReceiveDataBuffer[5];
				bData_4000352b_ReceiveExternalMinutes = Data_40003588_uart0ReceiveDataBuffer[6];
				bData_4000352c_ReceiveExternalSeconds = Data_40003588_uart0ReceiveDataBuffer[7];
				fData_40003520 = (float)Data_40003588_uart0ReceiveDataBuffer[8] - 12;
#ifdef OLIMEX_LPC2148
				{
					static char buf[105];

					snprintf(buf, 100, "Date: %u-%u-%u\n\r",
							Data_40003524_ReceiveExternalYear,
							bData_40003528_ReceiveExternalMonth,
							bData_40003529_ReceiveExternalDay);
					uart1_send((unsigned char*)buf, strlen(buf));

					snprintf(buf, 100, "Time: %u:%u:%u\n\r",
							bData_4000352a_ReceiveExternalHours,
							bData_4000352b_ReceiveExternalMinutes,
							bData_4000352c_ReceiveExternalSeconds);
					uart1_send((unsigned char*)buf, strlen(buf));

					snprintf(buf, 100, "%d.%d\n\r",
							(int)fData_40003520,
							(fData_40003520 - (int)fData_40003520) * 1000);
					uart1_send((unsigned char*)buf, strlen(buf));
				}
#endif
				//->6ca60
				break;
			
			default:
				//6ca58
				break;
		}
		
		bData_40002c0b_uart0ReceiveComplete = 0;
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
			//6cbd8: "Schwenk abbrechen"
			func_b4f0();
		
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 30:
			//6cbf0: "Park Scope"?
			func_75c4();
		
			bData_40003431 = 1;
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 31:
			//6cc10: "Teleskop verbinden"?
			sp60.fData = dData_40002e28_SiteLongitude;
			sp56.fData = dData_40002e48_SiteLatitude;
		
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
			//6cdd4: "Standort einstellen"
			bData_40002e89 = 1;
		
			func_b4f0();
		
			dData_40002e28_SiteLongitude = fData_40003518_ReceiveExternalSiteLongitude;
			dData_40002e48_SiteLatitude = fData_4000351c_ReceiveExternalSiteLatitude;
			Data_40004128.geographicLongitude = fData_40003518_ReceiveExternalSiteLongitude;
			Data_40004128.geographicLatitude = fData_4000351c_ReceiveExternalSiteLatitude;
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 38:
			//6ce50 - Set Clock
			bData_40002e89 = 1;
		
			func_b4f0();
		
			Data_40002e54_Zone = fData_40003520;
			Data_40004128.Data_64 = fData_40003520;
		
			CCR = (1 << 4); //clock from the 32 kHz oscillator that’s connected to the RTCX1 and RTCX2 pins
			YEAR = Data_40003524_ReceiveExternalYear;
			MONTH = bData_40003528_ReceiveExternalMonth; 
			DOM = bData_40003529_ReceiveExternalDay;
			HOUR = bData_4000352a_ReceiveExternalHours;
			MIN = bData_4000352b_ReceiveExternalMinutes;
			SEC = bData_4000352c_ReceiveExternalSeconds;
			CCR = (1 << 4) | (1 << 0); //CLKEN = 1
		
			bData_4000352d = 1;
			//->6d044
			break;
		
		case 1:
			//6cef8
			if (bData_4000352e > 2)
			{
				//6cf0c
#ifndef OLIMEX_LPC2148
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
#endif
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
	lpc_hw_init();
	uart0_init(360);
	uart1_init(360);

#ifndef OLIMEX_LPC2148
	func_7590();
	func_d2cc();
	func_5099c();
	flash_read(0xdcb, 0, 10, Data_40004c58);
	bData_40003196_CurrentLanguage = Data_40004c58[0];
	if (Data_40004c58[1] == 1)
	{
		ValidateDateTimeSetRTC();
		Data_40004c58[1] = 0;
		flash_write(0xdcb, 0, 2, Data_40004c58);
	}

	ShowStartupScreen();
	
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
	
	Data_40004128.geographicLongitude = fData_40003540;
	Data_40004128.geographicLatitude = fData_40003544;
	Data_40002e54_Zone = Data_40003548;
	
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
	lcd_display_clear();
	
	if (bData_40002f1e_SetupLocalData == 1)
	{
		//6d64c
		func_6518(); //-> get time from RTC
		
		if (Data_40002e5c_Year < 2000)
		{
			//6d660
			Data_40002e5c_Year = 2000;
			bData_40002e60_Month = 1;
			bData_40002e61_Day = 1;
			bData_40002e62_Hours = 0;
			bData_40002e63_Minutes = 0;
			bData_40002e64_Seconds = 0;			
		}
		//6d69c
		sprintf(Data_400037ec, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
		sprintf(Data_40003150, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
		sprintf(Data_40002655, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
		sprintf(Data_40002660, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
		
		bData_4000318a = 1;
		bData_40002e78 = 0;
		Data_40002c64_MenuContextId = 41001; //"Date and Time Set: "
		//->6d880
	}
	else
	{
		//6d874
		Data_40002c64_MenuContextId = 0;
	}
	//6d880
	Data_40002c1c = 0;
	Data_40002c20 = 0;
#endif //OLIMEX_LPC2148
	//6d894 -> 729ec
	while (1) //Main Loop
	{
		//6d898
		fData_40002efc = dData_40002dc0;
		fData_40002f00 = dData_40002df8;
		
		func_6cb38();
		
#ifdef OLIMEX_LPC2148
		int j;
		for (j = 0; j < 500000; j++ );		// wait 500 msec
//		IOSET0 = 0x00000800;
		IOCLR0 = 0x00000400;
		for (j = 0; j < 500000; j++ );		// wait 500 msec
		IOSET0 = 0x00000400;
//		IOCLR0 = 0x00000800;
#endif

#ifndef OLIMEX_LPC2148
		if (bData_40002c1a == 1)
		{
			//6d8d4
			bData_40002e7a = 1;
			//6d8e0
			dData_40002ce8 = Data_40004128.dData_144 - 0.00083333333333/* 1/1200 */;
			Data_40002cd8_ObjectRightAscensionHours = dData_40002ce8;
			
			#if 0
			sp64 = Data_40002cd8;
			sp56 = dData_40002ce8 - sp64;
			sp48 = sp56 * 60.0;
			Data_40002cdc = sp48;
			#else
			Data_40002cdc_ObjectRightAscensionMinutes = (dData_40002ce8 - Data_40002cd8_ObjectRightAscensionHours) * 60.0;
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
			fData_40002ce0_ObjectRightAscensionSeconds = (dData_40002ce8 - Data_40002cd8_ObjectRightAscensionHours - Data_40002cdc_ObjectRightAscensionMinutes / 60.0) * 3600.0;
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
		} //if (bData_40002c1a == 1)
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
		} //else if (bData_40002c1a == 2)
		//6f8d0
		if (bData_400031ed == 0)
		{
			//6f8e0
			lcd_display_clear();
			lcd_display_string(0, 4, 1, 22, "System Initializing...");
			get_all_solar_system_object_equatorial_coordinates();
			func_659c(1000);
			func_7950(1);
			lcd_display_clear();
			lcd_display_string(0, 4, 1, 22, "System Initialized    ");
			func_659c(1000);
			lcd_display_clear();
			
			bData_400031ed = 1;
		}
		//6f94c
		func_6a2cc(); //->KeyHandling
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
				Data_40002c64_MenuContextId = 2;
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
#endif //OLIMEX_LPC2148
	} //while (1)
}

