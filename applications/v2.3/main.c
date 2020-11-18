
#if 0
#include <LPC214x.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_types.h"
#include "data.h"
#include "menu.h"
#endif

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

//#define UART0_DEBUG
#define V2_3

extern void uart0_send(unsigned char* a, unsigned char b);

#include "file_1f30.c"

/* 4ede4 - todo */
void HandleStarKey(void)
{
	switch (bData_40003195)
	{
		case 0:
			//0x4ee08
			IO0SET = (1 << 13);
			IO0CLR = (1 << 16);
			bData_40003195 = 1;
			break;
		
		case 1:
			//0x4ee30
			IO0SET = (1 << 13);
			IO0SET = (1 << 16);
			bData_40003195 = 2;
			break;
		
		case 2:
			//0x4ee58
			IO0CLR = (1 << 13);
			IO0SET = (1 << 16);
			bData_40003195 = 0;
			break;
		
		default:
			break;
	}		
}

/* 4ee90 - todo */
void func_4ee90(int a, int b, int c, int d, int e, int f)
{
	unsigned char sp[12];
	unsigned char i;
	
	bData_40003430 = 1;
	bData_40003200 = 0;
	bData_40003201 = 0;
	
	if (bData_4000319d == 1)
	{
		//4eed4
		sp[0] = 0x55;
		sp[1] = 0xaa;
		sp[2] = 0x01;
		sp[3] = 0x04;
		
		switch (a)
		{
			case 1:
				//0x4ef18
				sp[4] = 0x01;
				break;
			
			case 2:
				//0x4ef28
				sp[4] = 0x21;
				break;
			
			case 3:
				//0x4ef38
				sp[4] = 0x41;
				break;
			
			case 4:
				//0x4ef48
				sp[4] = 0x61;
				break;
			
			default:
				//0x4ef58
				break;
		}
		
		switch (b)
		{
			case 3:
				//0x4ef88
			case 1:
				//0x4ef90
				sp[5] = 0x00;
				break;
			
			case 4:
				//0x4ef9c
			case 2:
				//0x4efa4
				sp[5] = 0x01;
				break;
						
			default:
				//0x4efb0
				break;
		}
		
		if (bData_40002c1a == 1)
		{
			//4efcc
			switch (c)
			{
				case 0:
					//0x4f000
					sp[6] = 0x00;
					sp[7] = 0x00;
					bData_40002e88 = 0;
					break;
				
				case 1:
					//0x4f06c
					sp[6] = 0;
					sp[7] = 5;
					bData_40002e88 = 10;
					break;
				
				case 2:
					//0x4f090
					sp[6] = 0;
					sp[7] = 10;
					bData_40002e88 = 10;
					break;
				
				case 3:
					//0x4f0b0
					sp[6] = 0;
					sp[7] = 40;
					bData_40002e88 = 10;
					break;
				
				case 4:
					//0x4f0d4
					sp[6] = 0;
					sp[7] = 160;
					bData_40002e88 = 10;
					break;
				
				case 5:
					//0x4f0f8
					sp[6] = 1;
					sp[7] = 64;
					bData_40002e88 = 10;
					break;
				
				case 6:
					//0x4f11c
					sp[6] = 2;
					sp[7] = 128;
					bData_40002e88 = 10;
					break;
				
				case 7:
					//0x4f140
					sp[6] = 5;
					sp[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case 8:
					//0x4f164
					sp[6] = 10;
					sp[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case 9:
					//0x4f188
					sp[6] = 10;
					sp[7] = 0;
					bData_40002e88 = 10;
					break;
				#if 0
				default:
					//0x4f1ac
					break;
				#endif
			} //switch (c)			
		} //if (bData_40002c1a == 1)
		//0x4f1b0
		if (bData_40002c1a == 2)
		{
			//4f1c0
			switch (c)
			{
				case 0:
					//0x4f1f4
					sp[6] = 0;
					sp[7] = 0;
					bData_40002e88 = 0;
					break;
				
				case 1:
					//0x4f210
					sp[6] = 0;
					sp[7] = 6;
					bData_40002e88 = 10;
					break;
				
				case 2:
					//0x4f234
					sp[6] = 0;
					sp[7] = 12;
					bData_40002e88 = 10;
					break;
				
				case 3:
					//0x4f258
					sp[6] = 0;
					sp[7] = 48;
					bData_40002e88 = 10;
					break;
				
				case 4:
					//0x4f27c
					sp[6] = 0;
					sp[7] = 96;
					bData_40002e88 = 10;
					break;
				
				case 5:
					//0x4f2a0
					sp[6] = 0;
					sp[7] = 192;
					bData_40002e88 = 10;
					break;
				
				case 6:
					//0x4f2c4
					sp[6] = 1;
					sp[7] = 128;
					bData_40002e88 = 10;
					break;
				
				case 7:
					//0x4f2e8
					sp[6] = 2;
					sp[7] = 28;
					bData_40002e88 = 10;
					break;
				
				case 8:
					//0x4f30c
					sp[6] = 3;
					sp[7] = 56;
					bData_40002e88 = 10;
					break;
				
				case 9:
					//0x4f330
					sp[6] = 3;
					sp[7] = 212;
					bData_40002e88 = 10;
					break;
				#if 0
				default:
					//0x4f354
					break;
				#endif
			} //switch (c)			
		}
		//0x4f358
		for (i = 0; i < 8; i++)
		{
			//0x4f360
			uart1_write_byte(sp[i]);
		}
		
		switch (d)
		{
			case 1:
				//0x4f3a0
				sp[4] = 0x01;
				break;
			
			case 2:
				//0x4f3b0
				sp[4] = 0x21;
				break;
			
			case 3:
				//0x4f3c0
				sp[4] = 0x41;
				break;
			
			case 4:
				//0x4f3d0
				sp[4] = 0x61;
				break;
			
			default:
				//0x4f3e0
				break;
		}
		
		switch (e)
		{
			case 3:
				//0x4f410
			case 1:
				//0x4f418
				sp[5] = 0x00;
				break;
			
			case 4:
				//0x4f424
			case 2:
				//0x4f42c
				sp[5] = 0x01;
				break;
						
			default:
				//0x4f438
				break;
		}
		//0x4f440
		if (bData_40002c1a == 1)
		{
			//4f454
			switch (f)
			{
				case 0:
					//0x4f488
					sp[6] = 0x00;
					sp[7] = 0x00;
					bData_40002e88 = 0;
					break;
				
				case 1:
					//0x4f4a4
					sp[6] = 0;
					sp[7] = 5;
					bData_40002e88 = 10;
					break;
				
				case 2:
					//0x4f4c8
					sp[6] = 0;
					sp[7] = 10;
					bData_40002e88 = 10;
					break;
				
				case 3:
					//0x4f4e8
					sp[6] = 0;
					sp[7] = 40;
					bData_40002e88 = 10;
					break;
				
				case 4:
					//0x4f50c
					sp[6] = 0;
					sp[7] = 160;
					bData_40002e88 = 10;
					break;
				
				case 5:
					//0x4f530
					sp[6] = 1;
					sp[7] = 64;
					bData_40002e88 = 10;
					break;
				
				case 6:
					//0x4f554
					sp[6] = 2;
					sp[7] = 128;
					bData_40002e88 = 10;
					break;
				
				case 7:
					//0x4f578
					sp[6] = 5;
					sp[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case 8:
					//0x4f59c
					sp[6] = 10;
					sp[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case 9:
					//0x4f5c0
					sp[6] = 10;
					sp[7] = 0;
					bData_40002e88 = 10;
					break;
				#if 0
				default:
					//0x4f5e4
					break;
				#endif
			} //switch (f)			
		}
		//0x4f5e8
		if (bData_40002c1a == 2)
		{
			//4f5f8
			switch (f)
			{
				case 0:
					//0x4f62c
					sp[6] = 0;
					sp[7] = 0;
					bData_40002e88 = 0;
					break;
				
				case 1:
					//0x4f648
					sp[6] = 0;
					sp[7] = 6;
					bData_40002e88 = 10;
					break;
				
				case 2:
					//0x4f66c
					sp[6] = 0;
					sp[7] = 12;
					bData_40002e88 = 10;
					break;
				
				case 3:
					//0x4f690
					sp[6] = 0;
					sp[7] = 48;
					bData_40002e88 = 10;
					break;
				
				case 4:
					//0x4f6b4
					sp[6] = 0;
					sp[7] = 96;
					bData_40002e88 = 10;
					break;
				
				case 5:
					//0x4f6d8
					sp[6] = 0;
					sp[7] = 192;
					bData_40002e88 = 10;
					break;
				
				case 6:
					//0x4f6fc
					sp[6] = 1;
					sp[7] = 128;
					bData_40002e88 = 10;
					break;
				
				case 7:
					//0x4f720
					sp[6] = 2;
					sp[7] = 28;
					bData_40002e88 = 10;
					break;
				
				case 8:
					//0x4f744
					sp[6] = 3;
					sp[7] = 56;
					bData_40002e88 = 10;
					break;
				
				case 9:
					//0x4f768
					sp[6] = 3;
					sp[7] = 212;
					bData_40002e88 = 10;
					break;
				#if 0
				default:
					//0x4f78c
					break;
				#endif
			} //switch (f)			
		} //if (bData_40002c1a == 2)
		//0x4f790
		for (i = 0; i < 8; i++)
		{
			//0x4f798
			uart1_write_byte(sp[i]);
		}
	} //if (bData_4000319d == 1)
	else
	{
		//0x4f7b8
		bData_4000319d = 1;
		
		if (bData_4000319c == 0)
		{
			uart1_write_byte(0x55);
			uart1_write_byte(0xaa);
			uart1_write_byte(0x01);
			uart1_write_byte(0x01);
			uart1_write_byte(0xff);
		}
	}
}

/* 4f804 - todo */
void func_4f804(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x4f88c
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x4f894
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x4f898
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x4f89c
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x4f8a0
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x4f8a4
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x4f8a8
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x4f8ac
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x4f8b0
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
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
					func_4ee90(1, 4, bData_40002e7d_RotatingSpeed, 2, 1, bData_40002e7d_RotatingSpeed);
					//->4f9cc
				}
				else
				{
					//0x4f948
					func_4ee90(3, 4, bData_40002e7d_RotatingSpeed, 4, 1, bData_40002e7d_RotatingSpeed);
					//->4f9cc
				}
			}
			else
			{
				//0x4f970
				if (bData_40002c1a == 1)
				{
					//4f980
					func_4ee90(1, 4, bData_40002e7d_RotatingSpeed, 2, 1, bData_40002e7d_RotatingSpeed);
					//->4f9cc
				}
				else
				{
					//4f9a8
					func_4ee90(3, 4, bData_40002e7d_RotatingSpeed, 4, 1, bData_40002e7d_RotatingSpeed);
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
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			if (bData_400034a9 == 0)
			{
				//4faa4
				if ((Data_40004128.bData_356 != 0) &&
					(bData_40002e89 != 1))
				{
					Data_40003408 = 1;
					Data_4000340c = -1;
					bData_40003201 = 0;
					bData_40003200 = 0;
				}
				//0x4faf4
				else if (bData_40002c1a == 1)
				{
					func_4ee90(1, 4, bData_40002e7d_RotatingSpeed, 2, 2, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x4fb2c
					func_4ee90(3, 4, bData_40002e7d_RotatingSpeed, 4, 2, bData_40002e7d_RotatingSpeed);
				}
			}
			else
			{
				//0x4fb54
				if (bData_40002c1a == 1)
				{
					func_4ee90(1, 4, bData_40002e7d_RotatingSpeed, 2, 2, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					func_4ee90(3, 4, bData_40002e7d_RotatingSpeed, 4, 2, bData_40002e7d_RotatingSpeed);
				}
			}			
			break;
		
		default:
			break;
	}	
}

/* 4fbc8 - todo */
void func_4fbc8(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			if (bData_400034a9 == 0)
			{
				//4fc88
				if ((Data_40004128.bData_356 != 0) &&
					(bData_40002e89 != 1))
				{
					Data_40003408 = -1;
					Data_4000340c = -1;
					bData_40003201 = 0;
					bData_40003200 = 0;
				}
				//0x4fcd4
				else if (bData_40002c1a == 1)
				{
					func_4ee90(1, 3, bData_40002e7d_RotatingSpeed, 2, 2, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x4fd0c
					func_4ee90(3, 3, bData_40002e7d_RotatingSpeed, 4, 2, bData_40002e7d_RotatingSpeed);
				}
			}
			else
			{
				//0x4fd34
				if (bData_40002c1a == 1)
				{
					func_4ee90(1, 3, bData_40002e7d_RotatingSpeed, 2, 2, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					func_4ee90(3, 3, bData_40002e7d_RotatingSpeed, 4, 2, bData_40002e7d_RotatingSpeed);
				}
			}			
			break;
		
		default:
			break;
	}	
}

/* 4fda8 - todo */
void func_4fda8(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			if (bData_400034a9 == 0)
			{
				//4fe68
				if ((Data_40004128.bData_356 != 0) &&
					(bData_40002e89 != 1))
				{
					Data_40003408 = -1;
					Data_4000340c = 1;
					bData_40003201 = 0;
					//bData_40003200 = 0; //Bug??
				}
				//0x4feb0
				else if (bData_40002c1a == 1)
				{
					func_4ee90(1, 3, bData_40002e7d_RotatingSpeed, 2, 1, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x4fee8
					func_4ee90(3, 3, bData_40002e7d_RotatingSpeed, 4, 1, bData_40002e7d_RotatingSpeed);
				}
			}
			else
			{
				//0x4ff10
				if (bData_40002c1a == 1)
				{
					func_4ee90(1, 3, bData_40002e7d_RotatingSpeed, 2, 1, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					func_4ee90(3, 3, bData_40002e7d_RotatingSpeed, 4, 1, bData_40002e7d_RotatingSpeed);
				}
			}			
			break;
		
		default:
			break;
	}	
}

/* 4ff84 - todo */
void HandleAlarmInputData(void)
{
	int h = atoi(Data_40002a3f);
	int m = atoi(&Data_40002a3f[3]);
	int s = atoi(&Data_40002a3f[6]);
	
	if ((h > 23) || (m > 59) || (s > 59))
	{
		Data_40002c64_MenuContextId = 35001;
		bCharacterInputPosition = 1;
	}
	else
	{
		//0x4ffe0
		bData_4000322c = 1;
		Data_40002c64_MenuContextId = MENU_CONTEXT_ALARM; //3500;
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
void PrepareCustomerSkyObjectInputData(void)
{
	if (bData_40002e7a_MountType == 0)
	{
		//50060
		func_acdc(dData_40002dc0_Azimuth, dData_40002df8, &dData_40002c88, &dData_40002c90);
		//->0x5013c
	}
	else
	{
		//0x50084
		dData_40002c90 = dData_40002d98;		
		dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - 
			dData_40002d78;
		
		while (dData_40002c88 >= 24)
		{
			dData_40002c88 -= 24;
		}
		while (dData_40002c88 < 0)
		{
			dData_40002c88 += 24;
		}		
	}
	//5013c
	dData_40002cc8 = dData_40002c88;
	Data_40002cb8 = dData_40002cc8;		
	Data_40002cbc = (dData_40002cc8 - Data_40002cb8) * 60.0;
	fData_40002cc0 = (dData_40002cc8 - Data_40002cb8 - Data_40002cbc / 60.0) * 3600.0;
	//50238
	dData_40002d10 = fabs(dData_40002c90);
	Data_40002cf4 = dData_40002d10;		
	Data_40002cf8 = (dData_40002d10 - Data_40002cf4) * 60.0;
	fData_40002cfc = (dData_40002d10 - Data_40002cf4 - Data_40002cf8 / 60.0) * 3600.0;
	//5033c
	if (dData_40002c90 > 0)
	{
		//50354
		Data_40002d40 = 1;
	}
	else
	{
		//0x50364
		Data_40002d40 = -1;
	}
	//0x50370
	if (fData_40002cc0 < 10)
	{
		//50384
		sprintf(strCustomerObjectRaAziInputForTracking, "R.a: %02dh%02dm0%2.1fs",
			Data_40002cb8, Data_40002cbc, fData_40002cc0);		
		sprintf(strCustomerObjectRaAziInputForStoring, "R.a: %02dh%02dm0%2.1fs",
			Data_40002cb8, Data_40002cbc, fData_40002cc0);
	}
	else
	{
		//0x503f0
		sprintf(strCustomerObjectRaAziInputForTracking, "R.a: %02dh%02dm%3.1fs",
			Data_40002cb8, Data_40002cbc, fData_40002cc0);
		sprintf(strCustomerObjectRaAziInputForStoring, "R.a: %02dh%02dm%3.1fs",
			Data_40002cb8, Data_40002cbc, fData_40002cc0);
	}
	//0x50458
	if (fData_40002cfc < 10)
	{
		//5046c
		if (Data_40002d40 == -1)
		{
			sprintf(Data_40002302, "Dec:-%02d %02d 0%2.1f ",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
			sprintf(strCustomerObjectDecAltInputForStoring, "Dec:-%02dd%02dm0%2.1fs",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
		}
		else
		{
			//0x5060c
			sprintf(Data_40002302, "Dec:+%02d %02d 0%2.1f ",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
			sprintf(strCustomerObjectDecAltInputForStoring, "Dec:+%02dd%02dm0%2.1fs",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
		}
	}
	else
	{
		//0x50678
		if (Data_40002d40 == -1)
		{
			sprintf(Data_40002302, "Dec:-%02d %02d %3.1f ",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
			sprintf(strCustomerObjectDecAltInputForStoring, "Dec:-%02dd%02dm%3.1fs",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
		}
		else
		{
			//0x506f4
			sprintf(Data_40002302, "Dec:+%02d %02d %3.1f ",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
			sprintf(strCustomerObjectDecAltInputForStoring, "Dec:+%02dd%02dm%3.1fs",
				Data_40002cf4, Data_40002cf8, fData_40002cfc);
		}
	}
	
	sprintf(strCustomerObjectNameInput, "Name:Target0%d", 0);
}

/* 50778 - todo */
void HandleOTAZeroData(void)
{
	fData_4000329c = (unsigned short) atoi(&Data_400028d7[4]); //"Azi:%03d"
	fData_400032a0 = (unsigned char) atoi(&Data_400028e1[5]); //"Alt: %02d"
	
	if ((fData_4000329c >= 0) && (fData_4000329c <= 360) &&
		(fData_400032a0 >= 0) && (fData_400032a0 <= 90))
	{
		//50808
		Data_40004128.dData_192 = fData_4000329c;
		Data_40004128.dData_200 = fData_400032a0;
		
		flash_write_ota_zero_data((unsigned short) fData_4000329c, (unsigned short) fData_400032a0);
		
		if (bData_40002f1e_SetupLocalData == 1)
		{
			//5087c
			bSystemInitialized = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			bData_40002f1e_SetupLocalData = 0;
		}
		else
		{
			//0x5089c
			Data_40002c64_MenuContextId = MENU_CONTEXT_OTA_ZERO_SETUP_RESTART; //47041;
		}
	}
	else
	{
		//0x508ac
		Data_40002c64_MenuContextId = MENU_CONTEXT_OTA_ZERO_SETUP; //47011;
		bData_400032a4_OTAZeroDataErrorCount = 20;
	}
}

#include "file_5099c.c"

/* 50b40 - todo */
void HandleReset(void)
{
	char sp40[528];
	unsigned char customSiteName[20];
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
		bData_40002e7a_MountType = MENU_MOUNT_TYPE_EQU; //1;
	}
	else
	{
		bData_40002e7a_MountType = MENU_MOUNT_TYPE_AZ; //0;
	}
	//50c98
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;
	
	flash_get_ota_zero_data(&fData_4000329c, &fData_400032a0);
	
	Data_40004128.dData_192 = fData_4000329c;
	Data_40004128.dData_200 = fData_400032a0;
	
	flash_get_custom_site_data(customSiteName, &lon, &lat, &zone);
	
	Data_40004128.geographicLongitude = lon;
	Data_40004128.geographicLatitude = lat;
	
	Data_40002e54_Zone = zone;
	
	strCustomSiteName[6] = customSiteName[0];
	strCustomSiteName[7] = customSiteName[1];
	strCustomSiteName[8] = customSiteName[2];
	strCustomSiteName[9] = customSiteName[3];
	strCustomSiteName[10] = customSiteName[4];
	strCustomSiteName[11] = customSiteName[5];
	strCustomSiteName[12] = customSiteName[6];
	strCustomSiteName[13] = customSiteName[7];
	
	if (lon > 0) //BUG? East is negative!
	{
		//50d90
		sprintf(strCustomSiteLongitude, "  Lon:E%03dd%02df ",
			DEGREES_MINUTES(lon));
	}
	else
	{
		//0x50edc
		sprintf(strCustomSiteLongitude, "  Lon:W%03dd%02df ",
			DEGREES_MINUTES(lon)); //Bug: abs()?
	}
	//0x50f30
	if (lat > 0)
	{
		//50f40
		sprintf(strCustomSiteLatitude, "  Lat:N%02dd%02df ",
			DEGREES_MINUTES(lat));
	}
	else
	{
		//0x50f98
		sprintf(strCustomSiteLatitude, "  Lat:S%02dd%02df ",
			DEGREES_MINUTES(lat)); //Bug: abs()
	}
	//0x50fec
	if (zone > 0)
	{
		sprintf(strCustomSiteTimezone, " Zone:E%02d", zone);
	}
	else
	{
		//0x5100c
		sprintf(strCustomSiteTimezone, " Zone:W%02d", zone);
	}
	
	func_659c(2000);
	beep1(2);
	func_659c(100);
	
	Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
}

/* 5104c - todo */
void HandleCustomSiteData(void)
{
	unsigned char i;
	unsigned char name[8];
	unsigned char lon[8];
	unsigned char lat[8];
	unsigned char tz[4];
	
	for (i = 0; i < 8; i++)
	{
		name[i] = strCustomSiteName[i + 6];
	}
	
	lon[0] = strCustomSiteLongitude[6];
	lon[1] = atoi(&strCustomSiteLongitude[7]);
	lon[2] = atoi(&strCustomSiteLongitude[11]);
	
	lat[0] = strCustomSiteLatitude[6];
	lat[1] = atoi(&strCustomSiteLatitude[7]);
	lat[2] = atoi(&strCustomSiteLatitude[10]);
	
	tz[0] = strCustomSiteTimezone[6];
	tz[1] = atoi(&strCustomSiteTimezone[7]);
	
	if ((lon[1] > 179) || (lon[2] > 59) ||
		(lat[1] > 89) || (lat[2] > 59) ||
		(tz[1] > 11))
	{
		//0x5111c: Invalid Data
		Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOM_SITE_INPUT; //43002;
	}
	else
	{
		//0x5112c
		lon[0] = strCustomSiteLongitude[6];
		lon[1] = strCustomSiteLongitude[7];
		lon[2] = strCustomSiteLongitude[8];
		lon[3] = strCustomSiteLongitude[9];
		lon[4] = strCustomSiteLongitude[11];
		lon[5] = strCustomSiteLongitude[12];
		
		lat[0] = strCustomSiteLatitude[6];
		lat[1] = strCustomSiteLatitude[7];
		lat[2] = strCustomSiteLatitude[8];
		lat[3] = strCustomSiteLatitude[10];
		lat[4] = strCustomSiteLatitude[11];
		
		tz[0] = strCustomSiteTimezone[6];
		tz[1] = strCustomSiteTimezone[7];
		tz[2] = strCustomSiteTimezone[8];
		
		flash_write_custom_site_data(name, lon, lat, tz);
		flash_get_custom_site_data(arCustomSiteName, 
			&fCustomSiteLongitude, &fCustomSiteLatitude, 
			&iCustomSiteTimeZone);
		
		dData_40002e28_SiteLongitude = fCustomSiteLongitude;
		dData_40002e48_SiteLatitude = fCustomSiteLatitude;
		Data_40002e54_Zone = iCustomSiteTimeZone;
		
		Data_40004128.geographicLongitude = dData_40002e28_SiteLongitude;
		Data_40004128.geographicLatitude = dData_40002e48_SiteLatitude;
		Data_40004128.timeZone = Data_40002e54_Zone;
		
		beep1(2);
		
		if (bData_40002f1e_SetupLocalData == 1)
		{
			if (bData_40002c1a == 1)
			{
				//51290
				lcd_display_clear();
				
				bSystemInitialized = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
				bData_40002f1e_SetupLocalData = 0;
			}
			else
			{
				//0x51340
				Data_40002c64_MenuContextId = MENU_CONTEXT_OTA_ZERO_SETUP; //47011;
			}
		}
		else
		{
			//0x51350
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
		}
	}
}

/* 51368 - todo */
int ValidateDateTimeSetRTC(void)
{
	int valid = 1;
	unsigned short y;
	unsigned char m;
	unsigned char d;
	unsigned char h;
	unsigned char min;
	unsigned char s;
	y = atoi(Data_40002655);
	m = atoi(&Data_40002655[5]);
	
	if ((m > 12) || (m == 0))
	{
		return 0;
	}
	
	d = atoi(&Data_40002655[8]);
	
	switch (m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d > 31) valid = 0;
			break;
		
		case 2:
			if (d > 29) valid = 0;
			break;
		
		case 4:
		case 6:
		case 9:
		case 11:
			if (d > 30) valid = 0;
			break;
		
		default:
			break;
	}
	
	if (d < 1) valid = 0;
	
	if (valid == 0) 
	{
		return 0;
	}
	
	h = atoi(Data_40002660);
	min = atoi(&Data_40002660[3]);
	s = atoi(&Data_40002660[6]);
	
	if ((h > 23) || (min > 59) || (s > 59))
	{
		return 0;
	}
	
	CCR = (1 << 4);
	YEAR = y;
	MONTH = m;
	DOM = d;
	HOUR = h;
	MIN = min;
	SEC = s;
	CCR = (1 << 4) | (1 << 0); //CLKEN = 1
	
	return 1;
}

/* 514f8 - todo */
void HandleCustomerLandObjectInput(void)
{
	int r4 = atoi(&strCustomerObjectRaAziInputForTracking[4]);
	int r5 = atoi(&strCustomerObjectRaAziInputForTracking[8]);
	float sl = atof(&strCustomerObjectRaAziInputForTracking[11]);
	int r6 = atoi(&Data_40002302[5]);
	int r7 = atoi(&Data_40002302[8]);
	float r8 = atof(&Data_40002302[11]);
	unsigned char i;
	
	if ((r4 >= 360) || (r5 > 59) || (sl > 59.9999899999999968258634908125/*60.0*/) || 
		(r6 > 89) || (r7 > 59) || (r8 > 59.9999899999999968258634908125/*60.0*/))
	{
		//0x515c0
		if ((r6 > 89) || (r7 > 59) || (r8 > 59.9999899999999968258634908125/*60.0*/))
		{
			//0x515f4
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT; //208;
			bCharacterInputPosition = 6;
		}
		//0x5160c
		if ((r4 >= 360) || (r5 > 59) || (sl > 59.9999899999999968258634908125/*60.0*/))
		{
			//0x51640
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT; //207;
			bCharacterInputPosition = 6;
		}
		//0x5179c
	}
	else
	{
		//0x5165c
		for (i = 1; i < 9; i++)
		{
			//0x51664
			Data_40003f90[i] = strCustomerObjectNameInput[i + 4];
		}
		
		Data_40003f90[9] = strCustomerObjectRaAziInputForStoring[4] - '0';
		Data_40003f90[10] = strCustomerObjectRaAziInputForStoring[5] - '0';
		Data_40003f90[11] = strCustomerObjectRaAziInputForStoring[6] - '0';
		
		Data_40003f90[12] = strCustomerObjectRaAziInputForStoring[8] - '0';
		Data_40003f90[13] = strCustomerObjectRaAziInputForStoring[9] - '0';
		
		Data_40003f90[14] = strCustomerObjectRaAziInputForStoring[11] - '0';
		Data_40003f90[15] = strCustomerObjectRaAziInputForStoring[12] - '0';
		
		Data_40003f90[16] = strCustomerObjectRaAziInputForStoring[14] - '0';
		
		Data_40003f90[17] = strCustomerObjectDecAltInputForStoring[4]; // - '0';
		Data_40003f90[18] = strCustomerObjectDecAltInputForStoring[5] - '0';
		Data_40003f90[19] = strCustomerObjectDecAltInputForStoring[6] - '0';
		
		Data_40003f90[20] = strCustomerObjectDecAltInputForStoring[8] - '0';
		Data_40003f90[21] = strCustomerObjectDecAltInputForStoring[9] - '0';
		
		Data_40003f90[22] = strCustomerObjectDecAltInputForStoring[11] - '0';
		Data_40003f90[23] = strCustomerObjectDecAltInputForStoring[12] - '0';
		
		Data_40003f90[24] = strCustomerObjectDecAltInputForStoring[14] - '0';
		
		flash_write_cust_land_target(bData_4000319a_SkyLandTargetId, Data_40003f90);
		beep1(1);
	}
}

/* 517f4 - todo */
void PrepareCustomerLandObjectInputData(void)
{
	if (fData_40002db4 < 10)
	{
		//51810
		sprintf(strCustomerObjectRaAziInputForStoring, "Azi:%03dh%02dm0%2.1fs",
			Data_40002dac, Data_40002db0, fData_40002db4);
		sprintf(strCustomerObjectRaAziInputForTracking, "Azi:%03dh%02dm0%2.1fs",
			Data_40002dac, Data_40002db0, fData_40002db4);
	}
	else
	{
		//0x5187c
		sprintf(strCustomerObjectRaAziInputForStoring, "Azi:%03dh%02dm%2.1fs",
			Data_40002dac, Data_40002db0, fData_40002db4);
		sprintf(strCustomerObjectRaAziInputForTracking, "Azi:%03dh%02dm0%2.1fs", //"Azi:%03dh%02dm%2.1fs", //BUG?
			Data_40002dac, Data_40002db0, fData_40002db4);
	}
	//0x518e4
	if (fData_40002de8 < 10)
	{
		//518f8
		if (dData_40002df8 < 0)
		{
			//51910
			sprintf(strCustomerObjectDecAltInputForStoring, "Alt:-%02dd%02dm%2.1fs",
				abs(Data_40002de0), abs(Data_40002de4), fabs(fData_40002de8));
			sprintf(Data_40002302, "Alt:-%02dd%02dm%2.1fs",
				abs(Data_40002de0), abs(Data_40002de4), fabs(fData_40002de8));
		}
		else
		{
			//0x519fc
			sprintf(strCustomerObjectDecAltInputForStoring, "Alt:+%02dd%02dm0%2.1fs",
				Data_40002de0, Data_40002de4, fData_40002de8);
			sprintf(Data_40002302, "Alt:+%02dd%02dm0%2.1fs",
				Data_40002de0, Data_40002de4, fData_40002de8);
		}
	}
	else
	{
		//0x51a68
		if (dData_40002df8 < 0)
		{
			//51a80
			sprintf(strCustomerObjectDecAltInputForStoring, "Alt:-%02dd%02dm%2.1fs",
				abs(Data_40002de0), abs(Data_40002de4), fabs(fData_40002de8));
			sprintf(Data_40002302, "Alt:-%02dd%02dm%2.1fs",
				abs(Data_40002de0), abs(Data_40002de4), fabs(fData_40002de8));
		}
		else
		{
			//0x51bf8
			sprintf(strCustomerObjectDecAltInputForStoring, "Alt:+%02dd%02dm%2.1fs",
				Data_40002de0, Data_40002de4, fData_40002de8);
			sprintf(Data_40002302, "Alt:+%02dd%02dm%2.1fs",
				Data_40002de0, Data_40002de4, fData_40002de8);
		}
	}
	//0x51c60
	sprintf(strCustomerObjectNameInput, "Name:Target0%d", 0);
}

/* 51c7c - todo */
void HandleRectascensionDeclinationInput(void)
{
	int raHours = atoi(&strCustomerObjectRaAziInputForTracking[5]);
	int raMinutes = atoi(&strCustomerObjectRaAziInputForTracking[8]);
	float raSeconds = atof(&strCustomerObjectRaAziInputForTracking[11]);
	int decDegrees = atoi(&Data_40002302[5]);
	int decMinutes = atoi(&Data_40002302[8]);
	float decSeconds = atof(&Data_40002302[11]);
	unsigned char i;
	
	if ((raHours > 23) || (raMinutes > 59) || (raSeconds > 59.99) ||
		(decDegrees > 89) || (decMinutes > 59) || (decSeconds > 59.99))
	{
		//0x51d4c
		if ((decDegrees > 89) || (decMinutes > 59) || (decSeconds > 59.99))
		{
			//0x51d80
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_INPUT; //29002;
			bCharacterInputPosition = 5;
		}
		//0x51d98
		if ((raHours > 23) || (raMinutes > 59) || (raSeconds > 59.99))
		{
			//0x51dcc
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_INPUT; //29001;
			bCharacterInputPosition = 6;
		}
		//->0x5246c
	}
	else
	{
		//0x51de8
		if (bData_40003162 == 0)
		{
			//51df8
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			Data_40002cb8 = raHours;
			Data_40002cbc = raMinutes;
			fData_40002cc0 = raSeconds;
			
			if (Data_40002302[4] == '-')
			{
				//51e2c
				Data_40002d40 = -1;
			}
			else
			{
				//0x51e3c
				Data_40002d40 = 1;
			}
			//0x51e48
			Data_40002cf4 = decDegrees;
			Data_40002cf8 = decMinutes;
			fData_40002cfc = decSeconds;
			
			dData_40002cc8 = Data_40002cb8 + Data_40002cbc / 60.0 + fData_40002cc0 / 3600.0;
			dData_40002d10 = Data_40002cf4 + Data_40002cf8 / 60.0 + fData_40002cfc / 3600.0;
			dData_40002d10 = Data_40002d40 * dData_40002d10;
			
			bData_40002e88 = 1;
			
			func_b64c(dData_40002cc8, dData_40002d10);
			
			bData_40002f0d_RecentTargetType = 11;
			bData_40002f10_RecentTargetId = 10;
			
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			
			Data_40003f78[0] = 111;
			
			for (i = 1; i < 9; i++)
			{
				//0x52078
				Data_40003f78[i] = strCustomerObjectNameInput[i + 4];
			}
			//5209c
			Data_40003f78[9] = strCustomerObjectRaAziInputForStoring[5] - '0';
			Data_40003f78[10] = strCustomerObjectRaAziInputForStoring[6] - '0';
			Data_40003f78[11] = strCustomerObjectRaAziInputForStoring[8] - '0';
			Data_40003f78[12] = strCustomerObjectRaAziInputForStoring[9] - '0';
			Data_40003f78[13] = strCustomerObjectRaAziInputForStoring[11] - '0';
			Data_40003f78[14] = strCustomerObjectRaAziInputForStoring[12] - '0';
			Data_40003f78[15] = strCustomerObjectRaAziInputForStoring[14] - '0';
			
			Data_40003f78[16] = strCustomerObjectDecAltInputForStoring[4];
			Data_40003f78[17] = strCustomerObjectDecAltInputForStoring[5] - '0';
			Data_40003f78[18] = strCustomerObjectDecAltInputForStoring[6] - '0';
			Data_40003f78[19] = strCustomerObjectDecAltInputForStoring[8] - '0';
			Data_40003f78[20] = strCustomerObjectDecAltInputForStoring[9] - '0';
			Data_40003f78[21] = strCustomerObjectDecAltInputForStoring[11] - '0';
			Data_40003f78[22] = strCustomerObjectDecAltInputForStoring[12] - '0';
			Data_40003f78[23] = strCustomerObjectDecAltInputForStoring[14] - '0';
			
			flash_write_cust_sky_target((unsigned char) bData_40002f10_RecentTargetId, Data_40003f78);
			//->0x5246c
		} //if (bData_40003162 == 0)
		else
		{
			//0x521a4
			Data_40002c64_MenuContextId = MENU_CONTEXT_RISE_SET_TIMES; //32001;
			Data_40002cb8 = raHours;
			Data_40002cbc = raMinutes;
			fData_40002cc0 = raSeconds;
			
			if (Data_40002302[4] == '-')
			{
				//521d8
				Data_40002d40 = -1;
			}
			else
			{
				//0x521e8
				Data_40002d40 = 1;
			}
			//0x521f4
			Data_40002cf4 = decDegrees;
			Data_40002cf8 = decMinutes;
			fData_40002cfc = decSeconds;
			
			dData_40002cc8 = Data_40002cb8 + Data_40002cbc / 60.0 + fData_40002cc0 / 3600.0;
			dData_40002d10 = Data_40002cf4 + Data_40002cf8 / 60.0 + fData_40002cfc / 3600.0;
			dData_40002d10 = Data_40002d40 * dData_40002d10;
			
			dObjectRiseTime = get_object_visibility_time(1, 
				dData_40002cc8, dData_40002d10, 
				Data_40004128.geographicLongitude, Data_40004128.geographicLatitude, 
				(unsigned char) Data_40004128.timeZone);
			
			dObjectTransitTime = get_object_visibility_time(2, 
				dData_40002cc8, dData_40002d10, 
				Data_40004128.geographicLongitude, Data_40004128.geographicLatitude, 
				(unsigned char) Data_40004128.timeZone);
			
			dObjectSetTime = get_object_visibility_time(3, 
				dData_40002cc8, dData_40002d10, 
				Data_40004128.geographicLongitude, Data_40004128.geographicLatitude, 
				(unsigned char) Data_40004128.timeZone);
		}
	}
}

/* 52478 - todo */
void HandleCustomerSkyObjectInput(void)
{
	int raHours = atoi(&strCustomerObjectRaAziInputForTracking[5]);
	int raMinutes = atoi(&strCustomerObjectRaAziInputForTracking[8]);
	float raSeconds = atof(&strCustomerObjectRaAziInputForTracking[11]);
	int r6 = atoi(&Data_40002302[5]);
	int r7 = atoi(&Data_40002302[8]);
	float r8 = atof(&Data_40002302[11]);
	unsigned char i;
	
	if ((raHours > 23) || (raMinutes > 59) || (raSeconds > 59.99) ||
		(r6 > 89) || (r7 > 59) || (r8 > 59.99))
	{
		//0x52540
		if ((r6 > 89) || (r7 > 59) || (r8 > 59.99))
		{
			//0x52574
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT; //205;
			bCharacterInputPosition = 5;
		}
		//0x5258c
		if ((raHours > 23) || (raMinutes > 59) || (raSeconds > 59.99))
		{
			//0x525c0
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT; //204;
			bCharacterInputPosition = 6;
		}
		//->0x52718
	}
	else
	{
		//0x525dc
		Data_40003f78[0] = 111;
		
		for (i = 1; i < 9; i++)
		{
			//0x525f0
			Data_40003f78[i] = strCustomerObjectNameInput[i + 4];
		}
		//5209c
		Data_40003f78[9] = strCustomerObjectRaAziInputForStoring[5] - '0';
		Data_40003f78[10] = strCustomerObjectRaAziInputForStoring[6] - '0';
		Data_40003f78[11] = strCustomerObjectRaAziInputForStoring[8] - '0';
		Data_40003f78[12] = strCustomerObjectRaAziInputForStoring[9] - '0';
		Data_40003f78[13] = strCustomerObjectRaAziInputForStoring[11] - '0';
		Data_40003f78[14] = strCustomerObjectRaAziInputForStoring[12] - '0';
		Data_40003f78[15] = strCustomerObjectRaAziInputForStoring[14] - '0';
		
		Data_40003f78[16] = strCustomerObjectDecAltInputForStoring[4];
		Data_40003f78[17] = strCustomerObjectDecAltInputForStoring[5] - '0';
		Data_40003f78[18] = strCustomerObjectDecAltInputForStoring[6] - '0';
		Data_40003f78[19] = strCustomerObjectDecAltInputForStoring[8] - '0';
		Data_40003f78[20] = strCustomerObjectDecAltInputForStoring[9] - '0';
		Data_40003f78[21] = strCustomerObjectDecAltInputForStoring[11] - '0';
		Data_40003f78[22] = strCustomerObjectDecAltInputForStoring[12] - '0';
		Data_40003f78[23] = strCustomerObjectDecAltInputForStoring[14] - '0';
		
		flash_write_cust_sky_target(bData_4000319a_SkyLandTargetId, Data_40003f78);
		beep1(1);
	}
}

/* 52720 - todo */
double func_52720(int a)
{
	union 
	{
		int a;
		char b[4];
	} sp8;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x03);
	
	switch (a)
	{
		case 1:
			//0x5276c
			uart1_write_byte(0x0f);
			break;
		
		case 2:
			//0x5277c
			uart1_write_byte(0x2f);
			break;
		
		case 3:
			//0x5278c
			uart1_write_byte(0x4f);
			break;
		
		case 4:
			//0x5279c
			uart1_write_byte(0x6f);
			break;
		
		default:
			//0x527ac
			break;
	}
	
	switch (a)
	{
		case 1:
			//0x527dc
			sp8.a = fData_40002e98;
			uart1_write_byte(sp8.b[1]);
			uart1_write_byte(sp8.b[0]);
			break;
		
		case 2:
			//0x52804
			sp8.a = fData_40002ea8;
			uart1_write_byte(sp8.b[1]);
			uart1_write_byte(sp8.b[0]);
			break;
		
		case 3:
			//0x5282c
			sp8.a = fData_40002e98;
			uart1_write_byte(sp8.b[1]);
			uart1_write_byte(sp8.b[0]);
			break;
		
		case 4:
			//0x52854
			sp8.a = fData_40002ea8;
			uart1_write_byte(sp8.b[1]);
			uart1_write_byte(sp8.b[0]);
			break;
		
		default:
			//0x5287c
			break;
	}
}

#include "HandleEnterKey.c"

#include "HandleRightKey.c"

#include "HandleLeftKey.c"

/* 59dd0 - todo */
void func_59dd0(void)
{
	wData_40003252 = 0;
	
	switch (wData_40003250)
	{
		case 1:
			//0x5a104
		case 2:
			//0x5a10c
			wData_40003250++;
			break;
		
		case 3:
			//0x5a128
			wData_40003250 = 25;
			break;
		
		case 25:
			//0x5a13c
			wData_40003250 = 26;
			break;
		
		case 26:
			//0x5a150
			wData_40003250 = 29;
			break;
		
		case 29:
			//0x5a164
		case 30:
			//0x5a16c
		case 31:
			//0x5a170
		case 32:
			//0x5a174
		case 33:
			//0x5a178
		case 34:
			//0x5a17c
			wData_40003250++;
			break;
		
		case 35:
			//0x5a198
			wData_40003250 = 38;
			break;
		
		case 38:
			//0x5a1ac
		case 39:
			//0x5a1b4
			wData_40003250++;
			break;
		
		case 40:
			//0x5a1d0
			wData_40003250 = 45;
			break;
		
		case 45:
			//0x5a1e4
		case 46:
			//0x5a1ec
		case 47:
			//0x5a1f0
			wData_40003250++;
			break;
		
		case 48:
			//0x5a20c
			wData_40003250 = 53;
			break;
		
		case 53:
			//0x5a220
		case 54:
			//0x5a228
		case 55:
			//0x5a22c
		case 56:
			//0x5a230
		case 57:
			//0x5a234
		case 58:
			//0x5a238
		case 59:
			//0x5a23c
			wData_40003250++;
			break;
		
		case 60:
			//0x5a258
			wData_40003250 = 62;
			break;
		
		case 62:
			//0x5a26c
		case 63:
			//0x5a274
			wData_40003250++;
			break;
		
		case 64:
			//0x5a290
			wData_40003250 = 73;
			break;
		
		case 73:
			//0x5a2a4
		case 74:
			//0x5a2ac
		case 75:
			//0x5a2b0
		case 76:
			//0x5a2b4
			wData_40003250++;
			break;
		
		case 77:
			//0x5a2d0
			wData_40003250 = 80;
			break;
		
		case 80:
			//0x5a2e4
		case 81:
			//0x5a2ec
			wData_40003250++;
			break;
		
		case 82:
			//0x5a308
			wData_40003250 = 89;
			break;
		
		case 89:
			//0x5a31c
			wData_40003250 = 90;
			break;
		
		case 90:
			//0x5a330
			wData_40003250 = 92;
			break;
		
		case 92:
			//0x5a344
		case 93:
			//0x5a34c
		case 94:
			//0x5a350
		case 95:
			//0x5a354
		case 96:
			//0x5a358
			wData_40003250++;
			break;
		
		case 97:
			//0x5a374
			wData_40003250 = 98;
			break;
		
		case 98:
			//0x5a388
			wData_40003250 = 99;
			break;
		
		case 99:
			//0x5a39c
			wData_40003250 = 105;
			break;
		
		case 105:
			//0x5a3b0
		case 106:
			//0x5a3b8
		case 107:
			//0x5a3bc
		case 108:
			//0x5a3c0
		case 109:
			//0x5a3c4
		case 110:
			//0x5a3c8
		case 111:
			//0x5a3cc
		case 112:
			//0x5a3d0
		case 113:
			//0x5a3d4
		case 114:
			//0x5a3d8
		case 115:
			//0x5a3dc
		case 116:
			//0x5a3e0
		case 117:
			//0x5a3e4
		case 118:
			//0x5a3e8
			wData_40003250++;
			break;
		
		case 119:
			//0x5a404
			wData_40003250 = 121;
			break;
		
		case 121:
			//0x5a418
		case 122:
			//0x5a420
		case 123:
			//0x5a424
		case 124:
			//0x5a428
		case 125:
			//0x5a42c
		case 126:
			//0x5a430
		case 127:
			//0x5a434
		case 128:
			//0x5a438
		case 129:
			//0x5a43c
		case 130:
			//0x5a440
		case 131:
			//0x5a444
		case 132:
			//0x5a448
		case 133:
			//0x5a44c
			wData_40003250++;
			break;
		
		case 134:
			//0x5a468
			wData_40003250 = 143;
			break;
		
		case 143:
			//0x5a47c
		case 144:
			//0x5a484
		case 145:
			//0x5a488
		case 146:
			//0x5a48c
		case 147:
			//0x5a490
		case 148:
			//0x5a494
		case 149:
			//0x5a498
			wData_40003250++;
			break;
		
		case 150:
			//0x5a4b4
			wData_40003250 = 152;
			break;
		
		case 152:
			//0x5a4c8
			wData_40003250 = 154;
			break;
		
		case 154:
			//0x5a4dc
			wData_40003250 = 155;
			break;
		
		case 155:
			//0x5a4f0
			wData_40003250 = 156;
			//break; //BUG?
		
		case 156:
			//0x5a504
			wData_40003250 = 158;
			break;
		
		case 158:
			//0x5a514
		case 159:
			//0x5a51c
		case 160:
			//0x5a520
		case 161:
			//0x5a524
		case 162:
			//0x5a528
		case 163:
			//0x5a52c
		case 164:
			//0x5a530
		case 165:
			//0x5a534
		case 166:
			//0x5a538
		case 167:
			//0x5a53c
		case 168:
			//0x5a540
		case 169:
			//0x5a544
			wData_40003250++;
			break;
		
		case 170:
			//0x5a560
			wData_40003250 = 1;		
			break;
#if 0
		default:
			//0x5a574
			break;
#endif		
	}
}

/* 5a57c - complete */
void HandleLongListScroll(int upDown, int b)
{
	switch (upDown)
	{
		case 0:
			//0x5a590: Scroll Up
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
					if (bData_40003177 > 1)
					{
						bData_40003177--;
					}
					else
					{
						bData_40003175--;
					}
					//0x5a690
					if (bData_40003176 > 1)
					{
						bData_40003176--;
					}
					else
					{
						bData_40003174--;
					}
					//0x5a6cc -> 0x5a860
					break;
				
				case 13:
					//0x5a6d0
					if (bData_4000317b > 1)
					{
						bData_4000317b--;
					}
					else
					{
						bData_40003179--;
					}

					if (bData_4000317a > 1)
					{
						bData_4000317a--;
					}
					else
					{
						bData_40003178--;
					}
					break;
				
				case 14:
					//0x5a750
					if (bData_4000317f > 1)
					{
						bData_4000317f--;
					}
					else
					{
						bData_4000317d--;
					}

					if (bData_4000317e > 1)
					{
						bData_4000317e--;
					}
					else
					{
						bData_4000317c--;
					}
					break;
				
				case 22:
					//0x5a7d0
					if (bData_40003182 > 1)
					{
						bData_40003182--;
					}
					else
					{
						bData_40003180--;
					}
					break;
				
				case 23:
					//0x5a814
					if (bData_40003186 > 1)
					{
						bData_40003186--;
					}
					else
					{
						bData_40003184--;
					}
					break;
				
				default:
					//0x5a858
					break;
			}
			break;
		
		case 1:
			//0x5a868: Scroll Down
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
					
				default:
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

/* 5f0c0 - complete */
void func_5f0c0(void)
{
	if ((bData_4000319c == 1) || (bData_4000319d == 1))
	{
		//0x5f0e4
		if (bData_4000319d == 1)
		{
			uart1_write_byte(0x55);
			uart1_write_byte(0xaa);
			uart1_write_byte(1);
			uart1_write_byte(1);
			uart1_write_byte(0);
			
			bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
		}
		//0x5f128
		if (bData_4000319c == 1)
		{
			if (bData_40002c1a == 2)
			{
				uart1_write_byte(0x55);
				uart1_write_byte(0xaa);
				uart1_write_byte(1);
				uart1_write_byte(1);
				uart1_write_byte(0);
				
				bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
			}
			else
			{
				//0x5f180
				if (bData_40002e7d_RotatingSpeed != MENU_ROTATING_SPEED_MAX) //9)
				{
					uart1_write_byte(0x55);
					uart1_write_byte(0xaa);
					uart1_write_byte(1);
					uart1_write_byte(1);
					uart1_write_byte(0);
					
					bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
				}
				else
				{
					//0x5f1c8
					if (Data_400031a4.Data >= 4800)
					{
						Data_400031a4.Data = 4700;
					}
					//0x5f1e4
					Data_400031b4 = -4;					
				}
			}
		}
		//0x5f1f0
		if (bData_4000319c == 1)
		{
			bData_4000319c = 0;
		}
		//0x5f20c
		if (bData_4000319d == 1)
		{
			bData_4000319d = 0;
		}
	}
	//0x5f228
}

#include "HandleMinusKey.c"

/* 60d54 - complete */
void HandlePlusKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x60d78
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_RECENT_TARGETS; //1;
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

/* 60dfc - complete */
void HandleFKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x60e60
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			bData_4000319a_SkyLandTargetId = 1;
			bData_4000319b = 1;
		
			lcd_display_clear();
			//->0x60ec4
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
			//0x60e8c
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//0x60e94
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//0x60e98
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//0x60e9c
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//0x60ea0
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//0x60ea4
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x60ea8
			lcd_display_clear();
		
			Data_40002ec8_NavigationDirectInputNr = 0;
		
			beep1(1);
			break;
				
	}
}

#include "HandleHelpKey.c"

/* 61ecc - todo */
void func_61ecc(int a)
{
	int r3;
	unsigned char r4;
	unsigned char sp[10];
	
	if (bCapsLock != 0)
	{
		r3 = 5;
	}
	else
	{
		r3 = 0;
	}
	
	switch (a)
	{
		case 0:
			//0x61f24
			r4 = '0';
			sp[0] = '0';
			sp[1] = '0';
			sp[2] = '0';
			sp[3] = '0';
			sp[4] = '0';
			sp[5] = '0';
			sp[6] = '0';
			sp[7] = '0';
			sp[8] = '0';
			sp[9] = '0';
			break;

		case 1:
			//0x61f5c
			r4 = '1';
			sp[0] = '1';
			sp[1] = '1';
			sp[2] = '1';
			sp[3] = '1';
			sp[4] = '1';
			sp[5] = '1';
			sp[6] = '1';
			sp[7] = '1';
			sp[8] = '1';
			sp[9] = '1';
			break;

		case 2:
			//0x61f94
			r4 = '2';
			sp[0] = '2';
			sp[1] = 'a';
			sp[2] = 'b';
			sp[3] = 'c';
			sp[4] = ' ';
			sp[5] = '2';
			sp[6] = 'A';
			sp[7] = 'B';
			sp[8] = 'C';
			sp[9] = ' ';
			break;

		case 3:
			//0x61ff0
			r4 = '3';
			sp[0] = '3';
			sp[1] = 'd';
			sp[2] = 'e';
			sp[3] = 'f';
			sp[4] = ' ';
			sp[5] = '3';
			sp[6] = 'D';
			sp[7] = 'E';
			sp[8] = 'F';
			sp[9] = ' ';
			break;

		case 4:
			//0x6204c
			r4 = '4';
			sp[0] = '4';
			sp[1] = 'g';
			sp[2] = 'h';
			sp[3] = 'i';
			sp[4] = ' ';
			sp[5] = '4';
			sp[6] = 'G';
			sp[7] = 'H';
			sp[8] = 'I';
			sp[9] = ' ';
			break;

		case 5:
			//0x620a8
			r4 = '5';
			sp[0] = '5';
			sp[1] = 'j';
			sp[2] = 'k';
			sp[3] = 'l';
			sp[4] = ' ';
			sp[5] = '5';
			sp[6] = 'J';
			sp[7] = 'K';
			sp[8] = 'L';
			sp[9] = ' ';
			break;

		case 6:
			//0x62104
			r4 = '6';
			sp[0] = '6';
			sp[1] = 'm';
			sp[2] = 'n';
			sp[3] = 'o';
			sp[4] = ' ';
			sp[5] = '6';
			sp[6] = 'M';
			sp[7] = 'N';
			sp[8] = 'O';
			sp[9] = ' ';
			break;

		case 7:
			//0x62160
			r4 = '7';
			sp[0] = '7';
			sp[1] = 'p';
			sp[2] = 'q';
			sp[3] = 'r';
			sp[4] = 's';
			sp[5] = '7';
			sp[6] = 'P';
			sp[7] = 'Q';
			sp[8] = 'R';
			sp[9] = 'S';
			break;

		case 8:
			//0x621bc
			r4 = '8';
			sp[0] = '8';
			sp[1] = 't';
			sp[2] = 'u';
			sp[3] = 'v';
			sp[4] = ' ';
			sp[5] = '8';
			sp[6] = 'T';
			sp[7] = 'U';
			sp[8] = 'V';
			sp[9] = ' ';
			break;

		case 9:
			//0x62218
			r4 = '9';
			sp[0] = '9';
			sp[1] = 'w';
			sp[2] = 'x';
			sp[3] = 'y';
			sp[4] = 'z';
			sp[5] = '2';
			sp[6] = 'W';
			sp[7] = 'X';
			sp[8] = 'Y';
			sp[9] = 'Z';
			break;

		default:
			//0x62274
			break;
	}
	
	switch (bData_40003262)
	{
		case 1:
			//62290
			switch (bData_40003261)
			{
				case 0:
					//0x622b8
					Data_4000251d[bCharacterInputPosition - 1] = sp[bMapKeyToCharIndex + r3];
					Data_4000257e[bCharacterInputPosition - 1] = sp[bMapKeyToCharIndex + r3];
				
					if (bMapKeyToCharIndex < 4)
					{
						bMapKeyToCharIndex++;
					}
					else
					{
						//0x62334
						bMapKeyToCharIndex = 0;
					}
					//->0x623b4
					break;
				
				case 1:
					//0x62344
					Data_4000253d[bCharacterInputPosition - 1] = r4;
					Data_4000258c[bCharacterInputPosition - 1] = r4;
				
					func_5660c();
					break;
				
				case 2:
					//0x62378
					Data_4000255d[bCharacterInputPosition - 1] = r4;
					Data_400025a0[bCharacterInputPosition - 1] = r4;
				
					func_5660c();
					break;
				
				default:
					//0x623ac
					break;
				
			} //switch (bData_40003261)
			break;
		
		default:
			//0x623bc
			break;
	} //switch (bData_40003262)
}

/* 623d0 - todo */
void func_623d0(int a)
{
	unsigned char r3;
	
	switch (a)
	{
		case 0:
			//0x6240c
			r3 = '0';
			break;

		case 1:
			//0x62418
			r3 = '1';
			break;

		case 2:
			//0x62424
			r3 = '2';
			break;

		case 3:
			//0x62430
			r3 = '3';
			break;

		case 4:
			//0x6243c
			r3 = '4';
			break;

		case 5:
			//0x62448
			r3 = '5';
			break;

		case 6:
			//0x62454
			r3 = '6';
			break;

		case 7:
			//0x62460
			r3 = '7';
			break;

		case 8:
			//0x6246c
			r3 = '8';
			break;

		case 9:
			//0x62478
			r3 = '9';
			break;

		default:
			//0x62484
			break;
	}
	
	switch (bData_4000316d)
	{
		case 0:
			//0x624ac
			Data_40002789[bCharacterInputPosition - 1] = r3;
			Data_400028d7[bCharacterInputPosition - 1] = r3;
			break;
		
		case 1:
			//0x624dc
			Data_40002792[bCharacterInputPosition - 1] = r3;
			Data_400028e1[bCharacterInputPosition - 1] = r3;
			break;
		
		default:
			//0x6250c
			break;
	}
	
	func_56dac();
}

/* 62524 - todo */
void HandleCustomSiteInputChar(int key)
{
	int capsOffset;
	unsigned char digitChar;
	unsigned char alphaNumChars[10];
	
	if (bCapsLock != 0)
	{
		capsOffset = 5;
	}
	else
	{
		capsOffset = 0;
	}
	
	switch (key)
	{
		case 0:
			//0x6257c
			digitChar = '0';
			alphaNumChars[0] = '0';
			alphaNumChars[1] = '0';
			alphaNumChars[2] = '0';
			alphaNumChars[3] = '0';
			alphaNumChars[4] = '0';
			alphaNumChars[5] = '0';
			alphaNumChars[6] = '0';
			alphaNumChars[7] = '0';
			alphaNumChars[8] = '0';
			alphaNumChars[9] = '0';
			break;

		case 1:
			//0x625b4
			digitChar = '1';
			alphaNumChars[0] = '1';
			alphaNumChars[1] = '1';
			alphaNumChars[2] = '1';
			alphaNumChars[3] = '1';
			alphaNumChars[4] = '1';
			alphaNumChars[5] = '1';
			alphaNumChars[6] = '1';
			alphaNumChars[7] = '1';
			alphaNumChars[8] = '1';
			alphaNumChars[9] = '1';
			break;

		case 2:
			//0x625ec
			digitChar = '2';
			alphaNumChars[0] = '2';
			alphaNumChars[1] = 'a';
			alphaNumChars[2] = 'b';
			alphaNumChars[3] = 'c';
			alphaNumChars[4] = ' ';
			alphaNumChars[5] = '2';
			alphaNumChars[6] = 'A';
			alphaNumChars[7] = 'B';
			alphaNumChars[8] = 'C';
			alphaNumChars[9] = ' ';
			break;

		case 3:
			//0x62648
			digitChar = '3';
			alphaNumChars[0] = '3';
			alphaNumChars[1] = 'd';
			alphaNumChars[2] = 'e';
			alphaNumChars[3] = 'f';
			alphaNumChars[4] = ' ';
			alphaNumChars[5] = '3';
			alphaNumChars[6] = 'D';
			alphaNumChars[7] = 'E';
			alphaNumChars[8] = 'F';
			alphaNumChars[9] = ' ';
			break;

		case 4:
			//0x626a4
			digitChar = '4';
			alphaNumChars[0] = '4';
			alphaNumChars[1] = 'g';
			alphaNumChars[2] = 'h';
			alphaNumChars[3] = 'i';
			alphaNumChars[4] = ' ';
			alphaNumChars[5] = '4';
			alphaNumChars[6] = 'G';
			alphaNumChars[7] = 'H';
			alphaNumChars[8] = 'I';
			alphaNumChars[9] = ' ';
			break;

		case 5:
			//0x62700
			digitChar = '5';
			alphaNumChars[0] = '5';
			alphaNumChars[1] = 'j';
			alphaNumChars[2] = 'k';
			alphaNumChars[3] = 'l';
			alphaNumChars[4] = ' ';
			alphaNumChars[5] = '5';
			alphaNumChars[6] = 'J';
			alphaNumChars[7] = 'K';
			alphaNumChars[8] = 'L';
			alphaNumChars[9] = ' ';
			break;

		case 6:
			//0x6275c
			digitChar = '6';
			alphaNumChars[0] = '6';
			alphaNumChars[1] = 'm';
			alphaNumChars[2] = 'n';
			alphaNumChars[3] = 'o';
			alphaNumChars[4] = ' ';
			alphaNumChars[5] = '6';
			alphaNumChars[6] = 'M';
			alphaNumChars[7] = 'N';
			alphaNumChars[8] = 'O';
			alphaNumChars[9] = ' ';
			break;

		case 7:
			//0x627b8
			digitChar = '7';
			alphaNumChars[0] = '7';
			alphaNumChars[1] = 'p';
			alphaNumChars[2] = 'q';
			alphaNumChars[3] = 'r';
			alphaNumChars[4] = 's';
			alphaNumChars[5] = '7';
			alphaNumChars[6] = 'P';
			alphaNumChars[7] = 'Q';
			alphaNumChars[8] = 'R';
			alphaNumChars[9] = 'S';
			break;

		case 8:
			//0x62814
			digitChar = '8';
			alphaNumChars[0] = '8';
			alphaNumChars[1] = 't';
			alphaNumChars[2] = 'u';
			alphaNumChars[3] = 'v';
			alphaNumChars[4] = ' ';
			alphaNumChars[5] = '8';
			alphaNumChars[6] = 'T';
			alphaNumChars[7] = 'U';
			alphaNumChars[8] = 'V';
			alphaNumChars[9] = ' ';
			break;

		case 9:
			//0x62870
			digitChar = '9';
			alphaNumChars[0] = '9';
			alphaNumChars[1] = 'w';
			alphaNumChars[2] = 'x';
			alphaNumChars[3] = 'y';
			alphaNumChars[4] = 'z';
			alphaNumChars[5] = '2';
			alphaNumChars[6] = 'W';
			alphaNumChars[7] = 'X';
			alphaNumChars[8] = 'Y';
			alphaNumChars[9] = 'Z';
			break;

		default:
			//0x628cc
			break;
	}
	
	switch (bData_40002edc)
	{
		case 1:
			//0x628f4
		case 3:
			//0x628fc
			switch (bCurrentCustomSiteInputLine)
			{
				case 0:
					//0x62924: Name
					Data_400026c3[bCharacterInputPosition - 1] = alphaNumChars[bMapKeyToCharIndex + capsOffset];
					strCustomSiteName[bCharacterInputPosition - 1] = alphaNumChars[bMapKeyToCharIndex + capsOffset];
				
					if (bMapKeyToCharIndex < 4)
					{
						bMapKeyToCharIndex++;
					}
					else
					{
						bMapKeyToCharIndex = 0;
					}
					//->0x62cc4
					break;
				
				case 1:
					//0x629b0: Longitude
					if (bCharacterInputPosition != 7)
					{
						Data_400026db[bCharacterInputPosition - 1] = digitChar;
						strCustomSiteLongitude[bCharacterInputPosition - 1] = digitChar;
					}
					else
					{
						//0x629f0
						if (Data_400026db[bCharacterInputPosition - 1] == 'E')
						{
							//62a0c
							Data_400026db[bCharacterInputPosition - 1] = 'W';
							strCustomSiteLongitude[bCharacterInputPosition - 1] = 'W';
						}
						else
						{
							//0x62ad4
							Data_400026db[bCharacterInputPosition - 1] = 'E';
							strCustomSiteLongitude[bCharacterInputPosition - 1] = 'E';
						}
					}
					//0x62b00
					HandleNextCustomSiteInputPosition();
					//->0x62cc4
					break;
				
				case 2:
					//0x62b08: Latitude
					if (bCharacterInputPosition != 7)
					{
						Data_400026f3[bCharacterInputPosition - 1] = digitChar;
						strCustomSiteLatitude[bCharacterInputPosition - 1] = digitChar;
					}
					else
					{
						//0x62b48
						if (Data_400026f3[bCharacterInputPosition - 1] == 'N')
						{
							//62b64
							Data_400026f3[bCharacterInputPosition - 1] = 'S';
							strCustomSiteLatitude[bCharacterInputPosition - 1] = 'S';
						}
						else
						{
							//0x62b94
							Data_400026f3[bCharacterInputPosition - 1] = 'N';
							strCustomSiteLatitude[bCharacterInputPosition - 1] = 'N';
						}
					}
					//0x62bc0
					HandleNextCustomSiteInputPosition();
					//->0x62cc4
					break;
				
				case 3:
					//0x62bc8: Time Zone
					if (bCharacterInputPosition != 7)
					{
						Data_4000270a[bCharacterInputPosition - 1] = digitChar;
						strCustomSiteTimezone[bCharacterInputPosition - 1] = digitChar;
					}
					else
					{
						//0x62c08
						if (Data_4000270a[bCharacterInputPosition - 1] == 'E')
						{
							//62c24
							Data_4000270a[bCharacterInputPosition - 1] = 'W';
							strCustomSiteTimezone[bCharacterInputPosition - 1] = 'W';
						}
						else
						{
							//0x62c54
							Data_4000270a[bCharacterInputPosition - 1] = 'E';
							strCustomSiteTimezone[bCharacterInputPosition - 1] = 'E';
						}
					}
					//0x62c80
					HandleNextCustomSiteInputPosition();
					//->0x62cc4
					break;
				
				case 4:
					//0x62c88: Altitude
					Data_4000271a[bCharacterInputPosition - 1] = digitChar;
					strCustomSiteAltitude[bCharacterInputPosition - 1] = digitChar;
				
					HandleNextCustomSiteInputPosition();
					//->0x62cc4
					break;
				
				default:
					//0x62cbc
					break;				
			} //switch (bCurrentCustomSiteInputLine)
			break;
		
		default:
			//0x62ccc
			break;
	} //switch (bData_40003262)
}

#include "Handle9Key.c"
#include "Handle8Key.c"
#include "Handle7Key.c"
#include "Handle6Key.c"
#include "Handle5Key.c"
#include "Handle4Key.c"
#include "Handle3Key.c"
#include "Handle2Key.c"


/* 68394 - todo */
void func_68394(int a)
{
	int r3;
	unsigned char r4;
	unsigned char sp[10];
	
	if (bCapsLock != 0)
	{
		r3 = 5;
	}
	else
	{
		r3 = 0;
	}
	
	switch (a)
	{
		case 0:
			r4 = '0';
			sp[0] = '0';
			sp[1] = '0';
			sp[2] = '0';
			sp[3] = '0';
			sp[4] = '0';
			sp[5] = '0';
			sp[6] = '0';
			sp[7] = '0';
			sp[8] = '0';
			sp[9] = '0';
			break;

		case 1:
			r4 = '1';
			sp[0] = '1';
			sp[1] = '1';
			sp[2] = '1';
			sp[3] = '1';
			sp[4] = '1';
			sp[5] = '1';
			sp[6] = '1';
			sp[7] = '1';
			sp[8] = '1';
			sp[9] = '1';
			break;

		case 2:
			r4 = '2';
			sp[0] = '2';
			sp[1] = 'a';
			sp[2] = 'b';
			sp[3] = 'c';
			sp[4] = ' ';
			sp[5] = '2';
			sp[6] = 'A';
			sp[7] = 'B';
			sp[8] = 'C';
			sp[9] = ' ';
			break;

		case 3:
			r4 = '3';
			sp[0] = '3';
			sp[1] = 'd';
			sp[2] = 'e';
			sp[3] = 'f';
			sp[4] = ' ';
			sp[5] = '3';
			sp[6] = 'D';
			sp[7] = 'E';
			sp[8] = 'F';
			sp[9] = ' ';
			break;

		case 4:
			r4 = '4';
			sp[0] = '4';
			sp[1] = 'g';
			sp[2] = 'h';
			sp[3] = 'i';
			sp[4] = ' ';
			sp[5] = '4';
			sp[6] = 'G';
			sp[7] = 'H';
			sp[8] = 'I';
			sp[9] = ' ';
			break;

		case 5:
			r4 = '5';
			sp[0] = '5';
			sp[1] = 'j';
			sp[2] = 'k';
			sp[3] = 'l';
			sp[4] = ' ';
			sp[5] = '5';
			sp[6] = 'J';
			sp[7] = 'K';
			sp[8] = 'L';
			sp[9] = ' ';
			break;

		case 6:
			r4 = '6';
			sp[0] = '6';
			sp[1] = 'm';
			sp[2] = 'n';
			sp[3] = 'o';
			sp[4] = ' ';
			sp[5] = '6';
			sp[6] = 'M';
			sp[7] = 'N';
			sp[8] = 'O';
			sp[9] = ' ';
			break;

		case 7:
			r4 = '7';
			sp[0] = '7';
			sp[1] = 'p';
			sp[2] = 'q';
			sp[3] = 'r';
			sp[4] = 's';
			sp[5] = '7';
			sp[6] = 'P';
			sp[7] = 'Q';
			sp[8] = 'R';
			sp[9] = 'S';
			break;

		case 8:
			r4 = '8';
			sp[0] = '8';
			sp[1] = 't';
			sp[2] = 'u';
			sp[3] = 'v';
			sp[4] = ' ';
			sp[5] = '8';
			sp[6] = 'T';
			sp[7] = 'U';
			sp[8] = 'V';
			sp[9] = ' ';
			break;

		case 9:
			r4 = '9';
			sp[0] = '9';
			sp[1] = 'w';
			sp[2] = 'x';
			sp[3] = 'y';
			sp[4] = 'z';
			sp[5] = '2';
			sp[6] = 'W';
			sp[7] = 'X';
			sp[8] = 'Y';
			sp[9] = 'Z';
			break;

		default:
			break;
	}
	
	switch (bData_40003263)
	{
		case 1:
			//0x68764
		case 3:
			//0x6876c
			switch (bData_40003260)
			{
				case 0:
					//0x68790
					Data_400025b5[bCharacterInputPosition - 1] = sp[bMapKeyToCharIndex + r3];
					Data_40002625[bCharacterInputPosition - 1] = sp[bMapKeyToCharIndex + r3];
				
					if (bMapKeyToCharIndex < 4)
					{
						bMapKeyToCharIndex++;
					}
					else
					{
						bMapKeyToCharIndex = 0;
					}
					break;
				
				case 1:
					//0x6881c
					Data_400025d9[bCharacterInputPosition - 1] = r4;
					Data_40002634[bCharacterInputPosition - 1] = r4;

					func_563c8();
					//->0x62cc4
					break;
				
				case 2:
					//0x68850
					if (bCharacterInputPosition != 7)
					{
						Data_400025fe[bCharacterInputPosition - 1] = r4;
						Data_40002644[bCharacterInputPosition - 1] = r4;
					}
					else
					{
						//0x68890
						if (Data_400025fe[bCharacterInputPosition - 1] == '+')
						{
							Data_400025fe[bCharacterInputPosition - 1] = '-';
							Data_40002644[bCharacterInputPosition - 1] = '-';
						}
						else
						{
							//0x688dc
							Data_400025fe[bCharacterInputPosition - 1] = '+';
							Data_40002644[bCharacterInputPosition - 1] = '+';
						}
					}
					//0x68908
					func_563c8();
					break;
								
				default:
					//0x68910
					break;				
			} //switch (bData_40003260)
			break;
		
		default:
			//0x68920
			break;
	} //switch (bData_40003262)
}

#include "Handle1Key.c"

#include "Handle0Key.c"

/* 6a0e4 - todo */
unsigned char ConvertKeyCode(void)
{
#ifndef OLIMEX_LPC2148
	unsigned char hwKey = get_hw_key_code();
	unsigned char menuKey;
	
	if (hwKey & 0x20) //Valid?
	{
		hwKey &= 0x1f;
		
		ack_hw_key();
		
		bData_40002c68 = 0;
		Data_400031e4 = 0;
	}
	else
	{
		hwKey = 100;
	}
	
	switch (hwKey)
	{
		case 1:
			//0x6a18c: 10100001 / 11100001
			menuKey = 16;
			break;
		
		case 2:
			//0x6a198: 10100010 / 11100010
			menuKey = 1;
			break;
		
		case 3:
			//0x6a1a4: 10100011 / 11100011
			menuKey = 4;
			break;
		
		case 4:
			//0x6a1b0: 10100100 / 11100100
			menuKey = 7;
			break;
		
		case 5:
			//0x6a1bc: 10100101 / 11100101
			menuKey = 10;
			break;
		
		case 6:
			//0x6a1c8: 10100110 / 11100110
			menuKey = 15;
			break;
		
		case 7:
			//0x6a1d4: 10100111 / 11100111
			menuKey = 2;
			break;
		
		case 8:
			//0x6a1e0: 10101000 / 11101000
			menuKey = 5;
			break;
		
		case 9:
			//0x6a1ec: 10101001 / 11101001
			menuKey = 8;
			break;
		
		case 10:
			//0x6a1f8: 10101010 / 11101010
			menuKey = 0;
			break;
		
		case 11:
			//0x6a204: 10101011 / 11101011
			menuKey = 17;
			break;
		
		case 12:
			//0x6a210: 10101100 / 11101100
			menuKey = 3;
			break;
		
		case 13:
			//0x6a21c: 10101101 / 11101101
			menuKey = 6;
			break;
		
		case 14:
			//0x6a228: 10101110 / 11101110
			menuKey = 9;
			break;
		
		case 15:
			//0x6a234: 10101111 / 11101111
			menuKey = 11;
			break;
		
		case 16:
			//0x6a240: 10110000 / 11110000
			menuKey = 14;
			break;
		
		case 17:
			//0x6a24c: 10110001 / 11110001
			menuKey = 19;
			break;
		
		case 18:
			//0x6a258: 10110010 / 11110010
			menuKey = 12;
			break;
		
		case 19:
			//0x6a264: 10110011 / 11110011
			menuKey = 20;
			break;
		
		case 20:
			//0x6a270: 10110100 / 11110100
			menuKey = 13;
			break;
		
		case 21:
			//0x6a27c
			menuKey = 21;
			break;
		
		case 22:
			//0x6a288
			menuKey = 22;
			break;
		
		case 23:
			//0x6a294
			menuKey = 23;
			break;
		
		case 24:
			//0x6a2a0
			menuKey = 24;
			break;

		default:
			//6a2ac
			func_5f0c0();
			func_5f0c0();
			break;
	}
	
	return menuKey;
#else
	return 0xFF;
#endif
}

/* 6a2cc - todo */
void UserInterfaceCycle(void)
{
	get_rtc_date_time();
	
	if (bData_40003505 != 0)
	{
		func_659c(10);
		ack_hw_key();
		
		if (bData_4000322d_AlarmTimeElapsed == 1)
		{
			bData_4000322c = 0;
			bData_4000322d_AlarmTimeElapsed = 0;
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
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a40c
					Handle1Key();
				}
				bData_40003505 = 1;
				break;
				
			case 2:
				//0x6a420
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a454
					Handle2Key();
				}
				bData_40003505 = 1;
				break;
			
			case 3:
				//0x6a468
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a49c
					Handle3Key();
				}
				bData_40003505 = 1;
				break;
			
			case 4:
				//0x6a4b0
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a4e4
					Handle4Key();
				}
				bData_40003505 = 1;
				break;
			
			case 5:
				//0x6a4f8
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a52c
					Handle5Key();
				}
				bData_40003505 = 1;
				break;
						
			case 6:
				//0x6a540
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
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
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a5d4
					Handle8Key();
				}
				bData_40003505 = 1;
				break;
			
			case 9:
				//0x6a5e8
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
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
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a6c4
					HandleUpKey();
				}
				bData_40003505 = 1;
				break;
			
			case 15:
				//0x6a6d8: "Down"
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a70c
					HandleDownKey();
				}
				bData_40003505 = 1;
				break;
			
			case 16:
				//0x6a720: "Left"
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a754
					HandleLeftKey();
				}
				bData_40003505 = 1;
				break;
			
			case 17:
				//0x6a768: "Right"
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
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
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a7fc
					func_4fda8();
				}
				bData_40003505 = 1;
				break;
			
			case 21:
				//0x6a810
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a844
					func_4fbc8();
				}
				bData_40003505 = 1;
				break;
			
			case 23:
				//0x6a858
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bData_357 == 0))
				{
					//6a88c
					func_4f9e4();
				}
				bData_40003505 = 1;
				break;
			
			case 24:
				//0x6a8a0
				if (((Data_40004128.bData_357 != 0) && 
					(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
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
	if ((Data_40002c64_MenuContextId != MENU_CONTEXT_MAIN) && //0
		(Data_40002c64_MenuContextId != MENU_CONTEXT_ALIGNMENT_STAR_CONTROL) && //12001
		(Data_40002c64_MenuContextId != MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT) && //11103
		(Data_40002c64_MenuContextId != MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN) && //11203
		(Data_40002c64_MenuContextId != MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET) && //11102
		(Data_40002c64_MenuContextId != MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET) && //11202
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
			get_rtc_date_time();
			
			sprintf(Data_400037ec, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40003150, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
			sprintf(Data_40002655, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40002660, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
			
			bData_400031ec = 0;
		}
		//6aad4
	}
	//6aad4
	if (bHelpActive == 0)
	{
		DisplayScreenItems();
	}
	else
	{
		//0x6aaec
		DisplayHelpScreen();
	}
	//6aaf0
	if ((bData_4000322c == 1) && 
		(Data_40003220_AlarmHours == bData_40002e62_Hours) &&
		(Data_40003224_AlarmMinutes == bData_40002e63_Minutes) &&
		(Data_40003228_AlarmSeconds == bData_40002e64_Seconds))
	{
		bData_4000322d_AlarmTimeElapsed = 1;
	}
	//6ab54
	if (bData_4000322d_AlarmTimeElapsed == 1)
	{
		beep1(10);
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
	
	delay_loop(10);
	
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
			
			default:
				break;
		}
		
		bData_40002c13_uart1ReceiveComplete = 0;
	}

	return d;
}

/* 6ae24 - todo */
double InquireMotorData(int a)
{
	unsigned char r5;
	double sp8;
	
	bData_40002c13_uart1ReceiveComplete = 0;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(1);

	switch (a)
	{
		case 1:
			//0x6ae7c
			uart1_write_byte(0x04); //RA Inquire?
			break;
		
		case 2:
			//0x6ae8c
			uart1_write_byte(0x24); //DEC Inquire?
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
	
	delay_loop(2);
	
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
					dData_40002d80 = sp8 * 360.0 / 841763108.524032;
				}
				//0x6afcc -> 0x6b15c
				break;
			
			case 2:
				//0x6afd0
				if (Data_40003592_uart1ReceiveDataBuffer[0] == 0x24)
				{
					//6af64: DEC Inquire response?
					Data_400031a0.bData[3] = Data_40003592_uart1ReceiveDataBuffer[2];
					Data_400031a0.bData[2] = Data_40003592_uart1ReceiveDataBuffer[3];
					Data_400031a0.bData[1] = Data_40003592_uart1ReceiveDataBuffer[4];
					
					sp8 = Data_400031a0.Data;
					dData_40002da0 = sp8 * 360.0 / 841763108.524032;
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
					dData_40002db8 = sp8 * 360.0 / 278879846.40000004;
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
	} //if (bData_40002c13_uart1ReceiveComplete == 1)
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
		delay_loop(1);
		r3--;
	}
	//0x6b208
	if (bData_40002c13_uart1ReceiveComplete == 1)
	{
		//6b218
		if (Data_40003592_uart1ReceiveDataBuffer[0] == 0x81)
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

/* 6b310 - todo */
void func_6b310(void)
{
	switch (wData_40002eda)
	{
		case 10000:
			//6b33c
			wData_40002eda = 1000;
			break;

		case 1000:
			//0x6b350
			wData_40002eda = 100;
			break;

		case 100:
			//0x6b364
			wData_40002eda = 10;
			break;
		
		case 10:
			//0x6b378
			wData_40002eda = 1;
			break;
		
		default:
			//0x6b38c
			break;
	}
}

/* 6b39c - complete */
void func_6b39c(void)
{
}

/* 6b3a0 - complete */
void func_6b3a0(void)
{
}

/* 6b3a4 - complete */
void func_6b3a4(void)
{
}

/* 6b3a8 - todo */
int func_6b3a8(double a, double b, double c, double d)
{
	float r6;
	float r7;
	float r4;
	float r5;
	
	if ((d >= 4) || (d <= 20))
	{
		//0x6b3e0
		r6 = d - 4;
		r7 = d + 4;
	}
	else
	{
		//0x6b42c
		if (d < 4)
		{
			//6b444
			r6 = d + 24 - 4;
			r7 = d + 4;
		}
		else
		{
			//0x6b4a4
			r6 = d - 4;
			r7 = d - 24 + 4;
		}
	}
	//0x6b500
	if (c >= 0)
	{
		//6b518
		r4 = c - 60;
		r5 = c + 60;
		
		if (r5 > 90)
		{
			r5 = 90;
		}
	}
	else
	{
		//0x6b578
		r4 = c - 60;
		r5 = c + 60;
		
		if (r4 < -90)
		{
			r4 = -90;
		}
	}
	//0x6b5d4
	if ((d >= 4) || (d <= 20))
	{
		//0x6b604
		if ((a >= r6) && (a <= r7))
		{
			if ((b >= r4) && (b <= r5))
			{
				return 1;
			}
		}
		//0x6b774
	}
	else
	{
		//0x6b68c
		if ((d <= 4) || (d >= 20))
		{
			//0x6b6bc
			if (((a >= r6) && (a <= 24)) || ((a >= 0) && (a <= r7)))
			{
				if ((b >= r4) && (b <= r5))
				{
					return 1;
				}
			}
			//0x6b774
		}
		else
		{
			//0x6b76c
			return 0;
		}
	}
}

/* 6b778 - todo */
void func_6b778(void)
{
	double sp456;
	float sp452;
	float sp448;
	unsigned char strStarNames[10][10]; //sp348
	unsigned char sp128[10][22]; 
	unsigned char sp36[9][10] = 
	{
		"Moon     ",
		"Mercury  ",
		"Vernus   ",
		"Mars     ",
		"Jupiter  ",
		"Saturn   ",
		"Uranrs   ",
		"Neptune  ",
		"Sun      "
	};
	
	unsigned char r4 = 0;
	unsigned char r5;
	
	sp456 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude);
	
	bData_40003161 = GetCurrentAlignStars(sp456,
		Data_40004128.geographicLatitude, 
		Data_40004a68_CurrentAlignStarEquatorialCoord,
		strStarNames, sp128);
	
	get_solar_system_object_data(8, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			//0x6b894
			Data_400038e8[r4 - 1][r5] = sp36[0][r5];
		}
	}
	//0x6b8c0
	get_solar_system_object_data(0, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			//0x6b95c
			Data_400038e8[r4 - 1][r5] = sp36[1][r5];
		}
	}
	//6b988
	get_solar_system_object_data(1, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			Data_400038e8[r4 - 1][r5] = sp36[2][r5];
		}
	}
	//6ba50
	get_solar_system_object_data(2, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			Data_400038e8[r4 - 1][r5] = sp36[3][r5];
		}
	}
	//6bb18
	get_solar_system_object_data(3, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			Data_400038e8[r4 - 1][r5] = sp36[4][r5];
		}
	}
	//6bbe0
	get_solar_system_object_data(4, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			Data_400038e8[r4 - 1][r5] = sp36[5][r5];
		}
	}
	//6bca8
	get_solar_system_object_data(5, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			Data_400038e8[r4 - 1][r5] = sp36[6][r5];
		}
	}
	//6bd70
	get_solar_system_object_data(6, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			Data_400038e8[r4 - 1][r5] = sp36[7][r5];
		}
	}
	//6be38
	get_solar_system_object_data(7, &sp452, &sp448);
	
	if (1 == func_6b3a8(sp452, sp448, Data_40004128.geographicLatitude, sp456))
	{
		r4++;
		
		Data_400037f8[2*(r4 - 1)] = sp452;
		Data_400037f8[2*(r4 - 1) + 1] = sp448;
		
		for (r5 = 0; r5 < 10; r5++)
		{
			Data_400038e8[r4 - 1][r5] = sp36[8][r5];
		}
	}
	//6bf00
	for (bData_40003504 = 0; bData_40003504 < bData_40003161; bData_40003504++)
	{
		//0x6bf10
		Data_400037f8[2*r4 + 2*bData_40003504] = 
			Data_40004a68_CurrentAlignStarEquatorialCoord[2 * bData_40003504];
		Data_400037f8[2*r4 + 2*bData_40003504 + 1] = 
			Data_40004a68_CurrentAlignStarEquatorialCoord[2 * bData_40003504 + 1];
		
		for (r5 = 0; r5 < 10; r5++)
		{
			//0x6bf7c
			Data_400038e8[bData_40003504 + r4][r5] = strStarNames[bData_40003504][r5];
		}
	}
	//6bfec
	bData_40003161 += r4;
}

/* 6c00c - todo */
void func_6c00c(void)
{
	double sp1000;
	float sp996;
	float sp992;
	unsigned char strStarNames[28][10]; //sp712
	unsigned char sp96[28][22]; 
	unsigned char sp4[9][10] = 
	{
		"Moon     ",
		"Mercury  ",
		"Vernus   ",
		"Mars     ",
		"Jupiter  ",
		"Saturn   ",
		"Uranrs   ",
		"Neptune  ",
		"Sun      "
	};
	
	unsigned char r4 = 0;
	unsigned char r5;
	
	sp1000 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude);
	
	bData_40003161 = GetCurrentAlignStars(sp1000,
		Data_40004128.geographicLatitude, 
		Data_40004a68_CurrentAlignStarEquatorialCoord,
		strStarNames, sp96);
	
	get_solar_system_object_data(8, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		//0x6c0d0
		Data_400038e8[r4 - 1][r5] = sp4[0][r5];
	}
	//6c0fc
	get_solar_system_object_data(0, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[1][r5];
	}
	//6c170
	get_solar_system_object_data(1, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[2][r5];
	}
	//6c1e4
	get_solar_system_object_data(2, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[3][r5];
	}
	//6c298
	get_solar_system_object_data(3, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[4][r5];
	}
	//6c30c
	get_solar_system_object_data(4, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[5][r5];
	}
	//6c380
	get_solar_system_object_data(5, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[6][r5];
	}
	//6c3f4
	get_solar_system_object_data(6, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[7][r5];
	}
	//6c468
	get_solar_system_object_data(7, &sp996, &sp992);
	
	r4++;
	
	Data_400037f8[2*(r4 - 1)] = sp996;
	Data_400037f8[2*(r4 - 1) + 1] = sp992;
	
	for (r5 = 0; r5 < 10; r5++)
	{
		Data_400038e8[r4 - 1][r5] = sp4[8][r5];
	}
	//6c4dc
	for (bData_40003504 = 0; bData_40003504 < bData_40003161; bData_40003504++)
	{
		//6c4ec
		Data_400037f8[2*r4 + 2*bData_40003504] = 
			Data_40004a68_CurrentAlignStarEquatorialCoord[2 * bData_40003504];
		Data_400037f8[2*r4 + 2*bData_40003504 + 1] = 
			Data_40004a68_CurrentAlignStarEquatorialCoord[2 * bData_40003504 + 1];
		
		for (r5 = 0; r5 < 10; r5++)
		{
			//0x6c558
			Data_400038e8[bData_40003504 + r4][r5] = strStarNames[bData_40003504][r5];
		}
	}
	//6c5c8
	bData_40003161 += r4;
}

/* 6c5e8 - todo */
void func_6c5e8(void)
{
	unsigned char i;
	
	for (i = 0; i < 7; i++)
	{
		Data_4000327f[i] = Data_4000251d[i + 6];
	}
	
	Data_4000327f[7] = 0;
	
	Data_40003290.wData_0 = atoi(&Data_4000253d[6]);
	Data_40003290.wData_2 = atoi(&Data_4000253d[10]);
	Data_40003290.wData_4 = atoi(&Data_4000253d[13]);
	
	Data_40003296.bData_0 = atoi(&Data_4000255d[6]);
	Data_40003296.bData_1 = atoi(&Data_4000255d[9]);
	Data_40003296.bData_2 = atoi(&Data_4000255d[12]);
	
	if ((Data_40003290.wData_0 >= 360) ||
		(Data_40003290.wData_2 > 59) ||
		(Data_40003290.wData_4 > 59) ||
		(Data_40003296.bData_0 > 89) ||
		(Data_40003296.bData_1 > 59) ||
		(Data_40003296.bData_2 > 59))
	{
		Data_40002c64_MenuContextId = 211001;
	}
	else
	{
		//0x6c6f4
		fData_40003288 = (float)Data_40003290.wData_0 + 
			(float)Data_40003290.wData_2 / 60 + 
			(float)Data_40003290.wData_2 / 3600; //BUG?
		
		fData_4000328c = (float)Data_40003296.bData_0 + 
			(float)Data_40003296.bData_1 / 60 + 
			(float)Data_40003296.bData_1 / 3600; //BUG?
		
		switch (bData_40003262)
		{
			case 1:
				//6c7cc
				func_3230(Data_4000327f, &fData_40003288, &fData_4000328c);
			
				Data_40002c64_MenuContextId = 21102;
				break;
			
			default:
				break;
		}
	}	
}

/* 6c804 - complete */
void ShowStartupScreen(void)
{
	#ifdef UART0_DEBUG
	lcd_display_string(0, 1, 1, 22, "   OPEN GOTO SYSTEM   ");
	lcd_display_string(0, 2, 1, 22, "based on EXOS EQ v2.3 ");
	lcd_display_string(0, 4, 1, 22, "github.com/Spitzbube/ ");
	lcd_display_string(0, 5, 1, 22, "Commit: 08ba598fa99635");
	#else
	lcd_display_string(0, 3, 1, 22, " BRESSER GOTO SYSTEM  ");
	lcd_display_string(0, 5, 1, 22, "     EXOS EQ v2.3     ");
	#endif
}

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
			Data_40004128.timeZone = fData_40003520;
		
			CCR = (1 << 4); //clock from the 32 kHz oscillator that�s connected to the RTCX1 and RTCX2 pins
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
				if (bData_40002c1a == 2)
				{
					//6cf1c
					double sp32, sp24;
					func_acdc(fData_40003508, fData_4000350c, &sp32, &sp24);					
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


static void vLEDTask( void *pvParameters )
{
	int off = 1;

	//OFF
	IO0SET = (1 << 16);

	for( ;; )
	{
		vTaskDelay( ( TickType_t ) 1000 / portTICK_PERIOD_MS );

		if (off)
		{
			//ON
			IO0CLR = (1 << 16);
			off = 0;
		}
		else
		{
			//OFF
			IO0SET = (1 << 16);
			off = 1;
		}
	}
}

static void vUART0Task( void *pvParameters )
{
#if 0
	uart0_init(360);

	VICVectCntl1 = (1 << 5) | 6; // UART0 -> Slot 1
	VICIntEnable = (1 << 6); // Enable UART0
#endif

	for( ;; )
	{
		vTaskDelay( ( TickType_t ) 1000 / portTICK_PERIOD_MS );
#if 0
		{
			static char buf[105];
			portTickType xtick = xTaskGetTickCount();

			snprintf(buf, 100, "vUART0Task=%u\n\r", (unsigned int)xtick);
			uart1_send((unsigned char*)buf, strlen(buf));
		}
#endif
	}
}

static void vUART1Task( void *pvParameters )
{
#if 0
	uart1_init(360);

	VICVectCntl2 = (1 << 5) | 7; // UART1 -> Slot 2
	VICIntEnable = (1 << 7); // Enable UART1
#endif

	for( ;; )
	{
		extern QueueHandle_t xQueueUart1;
		unsigned char uart1ReceiveDataBuffer[10];
		if (xQueueReceive(xQueueUart1, &uart1ReceiveDataBuffer, 100))
		{
			static char buf[35];
			portTickType xtick = xTaskGetTickCount();

			snprintf(buf, 30, "vUART1Task=%u\n\r", (unsigned int)xtick);
			uart0_send((unsigned char*)buf, strlen(buf));
		}

//		vTaskDelay( ( TickType_t ) 1000 / portTICK_PERIOD_MS );
#if 0
		{
			static char buf[105];
			portTickType xtick = xTaskGetTickCount();

			snprintf(buf, 100, "vUART1Task=%u\n\r", (unsigned int)xtick);
			uart1_send((unsigned char*)buf, strlen(buf));
		}
#endif
	}
}

static void vTimerTask( void *pvParameters )
{
	for( ;; )
	{
		vTaskDelay( ( TickType_t ) 10 / portTICK_PERIOD_MS );
		timer_isr();
#if 0
		{
			static char buf[105];
			portTickType xtick = xTaskGetTickCount();

			snprintf(buf, 100, "vTimerTask=%u\n\r", (unsigned int)xtick);
			uart1_send((unsigned char*)buf, strlen(buf));
		}
#endif
	}
}

/* 6d054 - todo */
static void vMainTask(void *pvParameters)
{
#if 0
	{
		static char buf[105];

		snprintf(buf, 100, "vMainTask\n\r");
		uart1_send((unsigned char*)buf, strlen(buf));
	}
#endif

	func_7590(); //Send Stop on Uart1?
	func_d2cc(); //Initialize variables
	func_5099c(); //Initialize variables

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
	
	func_659c(10); //delay
	
	fData_40002e98 = func_6ab74(1); //receive data for Cmd=0x10

	func_659c(50); //delay
	
	fData_40002ea8 = func_6ab74(2); //receive data for Cmd=0x30

	func_659c(50); //delay

	if (bData_40002c1a == 1)
	{
		bData_40002e7a_MountType = MENU_MOUNT_TYPE_EQU; //1;
	}
	else
	{
		bData_40002e7a_MountType = MENU_MOUNT_TYPE_AZ; //0;
	}
	
	bData_40003432 = 0;
		
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;
	
	Data_40004128.dData_192 = 100.0; 
	Data_40004128.dData_200 = 60.0;
	
	flash_get_ota_zero_data(&fData_4000329c, &fData_400032a0);
	
	Data_40004128.dData_192 = fData_4000329c;
	Data_40004128.dData_200 = fData_400032a0;
	
	Data_40004128.dData_112 = -180.0;
	Data_40004128.dData_120 = 90.0;
	
	flash_get_custom_site_data(arInitialCustomSiteName, 
		&fInitialCustomSiteLongitude, 
		&fInitialCustomSiteLatitude, 
		&iInitialCustomSiteTimezone);
	
	Data_40004128.geographicLongitude = fInitialCustomSiteLongitude;
	Data_40004128.geographicLatitude = fInitialCustomSiteLatitude;
	Data_40002e54_Zone = iInitialCustomSiteTimezone;
	
	strCustomSiteName[6] = arInitialCustomSiteName[0];
	strCustomSiteName[7] = arInitialCustomSiteName[1];
	strCustomSiteName[8] = arInitialCustomSiteName[2];
	strCustomSiteName[9] = arInitialCustomSiteName[3];
	strCustomSiteName[10] = arInitialCustomSiteName[4];
	strCustomSiteName[11] = arInitialCustomSiteName[5];
	strCustomSiteName[12] = arInitialCustomSiteName[6];
	strCustomSiteName[13] = arInitialCustomSiteName[7];	
	//6d364
	if (fInitialCustomSiteLongitude > 0)
	{
		//6d378
		sprintf(strCustomSiteLongitude, "  Lon:E%03dd%02df ", 
			DEGREES_MINUTES_ABS(fInitialCustomSiteLongitude));
		//->6d494
	}
	else
	{
		//6d408
		sprintf(strCustomSiteLongitude, "  Lon:W%03dd%02df ", 
			DEGREES_MINUTES_ABS(fInitialCustomSiteLongitude));
	}
	//6d494
	if (fInitialCustomSiteLatitude > 0)
	{
		//6d4a8
		sprintf(strCustomSiteLatitude, "  Lat:N%02dd%02df ", 
			DEGREES_MINUTES_ABS(fInitialCustomSiteLatitude));
		//->6d5c4
	}
	else
	{
		//6d538
		sprintf(strCustomSiteLatitude, "  Lat:S%02dd%02df ", 
			DEGREES_MINUTES_ABS(fInitialCustomSiteLatitude));
	}
	//6d5c4
	if (iInitialCustomSiteTimezone > 0)
	{
		//6d5d4
		sprintf(strCustomSiteTimezone, " Zone:E%02d", abs(iInitialCustomSiteTimezone));
	}
	else
	{
		//6d604
		sprintf(strCustomSiteTimezone, " Zone:W%02d", abs(iInitialCustomSiteTimezone));
	}
	//6d630

	func_659c(2000);
	lcd_display_clear();
	
	if (bData_40002f1e_SetupLocalData == 1)
	{
		//6d64c
		get_rtc_date_time();
		
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
		
		bCharacterInputPosition = 1;
		bDateTimeInputMode = 0;
		Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE_INPUT; //41001;
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
	//6d894 -> 729ec
	
	//##########################################################################
	//#################### Main Loop ###########################################
	//##########################################################################
	while (1) 
	{
#if 0
		{
			static char buf[100];
			snprintf(buf, sizeof(buf)-1, "Main Loop (Context: %d)\n\r", Data_40002c64_MenuContextId);
			uart1_send(buf, strlen(buf));
		}
#endif

		#if 0 //def UART0_DEBUG
		{
			static char buf[100];
			snprintf(buf, sizeof(buf)-1, "Main Loop (Context: %d)\n\r", Data_40002c64_MenuContextId);
			uart0_send(buf, strlen(buf));			
			
			snprintf(buf, sizeof(buf)-1, "dData_40002dc0_Azimuth: %f\n\r", dData_40002dc0_Azimuth);
			uart0_send(buf, strlen(buf));
			
			snprintf(buf, sizeof(buf)-1, "dData_40002df8: %f\n\r", dData_40002df8);
			uart0_send(buf, strlen(buf));
			
			snprintf(buf, sizeof(buf)-1, "bData_40002c1a: %d\n\r", bData_40002c1a);
			uart0_send(buf, strlen(buf));
		}
		#endif 
	
		//6d898		
		fData_40002efc = dData_40002dc0_Azimuth;
		fData_40002f00 = dData_40002df8;

		func_6cb38(); //check data from uart0

#if 0 //OLIMEX_LPC2148
		volatile int j;
		//for (j = 0; j < 500000; j++ );		// wait 500 msec
		func_659c(500);
//		IOSET0 = 0x00000800;
		IOCLR0 = 0x00000400;
		//for (j = 0; j < 500000; j++ );		// wait 500 msec
		func_659c(500);
		IOSET0 = 0x00000400;
//		IOCLR0 = 0x00000800;
#endif

		if (bData_40002c1a == 1)
		{
			//6d8d4
			bData_40002e7a_MountType = MENU_MOUNT_TYPE_EQU; //1;
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
			InquireMotorData(1); //RA Inquire?
			
			Data_40004128.dData_208 = dData_40002d80;
			dData_400034e8 = dData_40002d80;
			dData_40002dc0_Azimuth = Data_40004128.dData_208;
			dData_40002d78 = dData_40002d80;
			
			func_659c(5);
			InquireMotorData(2); //DEC Inquire?
			//6dbbc
			Data_40004128.dData_216 = dData_40002da0;
			dData_400034f8 = dData_40002da0;
			dData_40002df8 = fabs(Data_40004128.dData_216);
			dData_40002d98 = dData_40002df8; // = fabs(Data_40004128.dData_216);
			dData_40002d98 = fabs(dData_40002d98);
			//->0x6dc9c
			while (dData_40002d98 > 360.0)
			{
				//0x6dc80
				dData_40002d98 -= 360.0;
			}
			//6dcb4
			if (Data_40004128.geographicLatitude >= 0)
			{
				//6dcd0
				if (dData_40002d98 > 180)
				{
					//6dce8
					dData_40002d98 -= 270.0;
				}
				else
				{
					//0x6dd08
					dData_40002d98 = 90.0 - dData_40002d98;
				}
				//0x6dd24
				dData_40002d78 += 90.0;
				
				if ((dData_40002da0 > 0) && (dData_40002da0 < 180))
				{
					//6dd70
					dData_40002d78 += 180;
				}
				//0x6dd8c
				if ((dData_40002da0 < 0) && (dData_40002da0 < -180))
				{
					//6ddbc
					dData_40002d78 += 90;
				}
				//0x6ddd8 -> 0x6ddf8
				while (dData_40002d78 >= 360)
				{
					//0x6dddc
					dData_40002d78 -= 360;
				}
				//->0x6de30
				while (dData_40002d78 < 0)
				{
					//0x6de14
					dData_40002d78 += 360;
				}
				//->0x6dfc4
			} //if (Data_40004128.geographicLatitude >= 0)
			else
			{
				//0x6de4c
				if (dData_40002d98 > 180)
				{
					//6dce8
					dData_40002d98 = 270.0 - dData_40002d98;
					//->0x6dea0
				}
				else
				{
					//0x6de84
					dData_40002d98 -= 90.0;
				}
				//0x6dea0
				dData_40002d78 = 270.0 - dData_40002d78;
				
				if ((dData_40002da0 > 0) && (dData_40002da0 < 180))
				{
					//6deec
					dData_40002d78 -= 180;
				}
				//0x6df08
				if ((dData_40002da0 < 0) && (dData_40002da0 < -180))
				{
					//6df38
					dData_40002d78 -= 90;
				}
				//0x6df54 -> 0x6df74
				while (dData_40002d78 >= 360)
				{
					//0x6df58
					dData_40002d78 -= 360;
				}
				//->0x6dfac
				while (dData_40002d78 < 0)
				{
					//0x6df90
					dData_40002d78 += 360;
				}
			}
			//0x6dfc4
			dData_40002d78 /= 15.0;
			#if 0
			sp64 = dData_400031f0 / 15.0;
			sp56 = dData_40003420 / 15.0;
			sp48 = dData_40002d78 - sp56;
			sp40 = sp48 - sp64;
			sp32 = fData_400034c8;
			sp24 = sp32 - sp40;
			fData_40003508 = sp24;
			#else
			fData_40003508 = fData_400034c8 - 
				((dData_40002d78 - dData_40003420 / 15.0) - dData_400031f0 / 15.0);
			#endif
			if (fData_40003508 < 0)
			{
				//6e08c
				fData_40003508 += 24;				
			}
			//0x6e0a4
			if (fData_40003508 > 24)
			{
				//6e0b8
				fData_40003508 -= 24;
			}
			//0x6e0d0
			#if 0
			sp64 = dData_40003420 / 15.0;
			sp56 = dData_40002d78 - sp64;
			sp48 = sp56 + dData_400033e8;
			Data_40002d68_OTARightAscensionHours = sp48;
			#else
			Data_40002d68_OTARightAscensionHours = dData_40002d78 - 
				dData_40003420 / 15.0 + dData_400033e8;
			#endif
			
			#if 0
			sp64 = Data_40002d68_OTARightAscensionHours;
			sp56 = dData_40003420 / 15.0;
			sp48 = dData_40002d78 - sp56;
			sp40 = sp48 + dData_400033e8;
			sp32 = sp40 - sp64;
			sp24 = sp32 * 60.0;
			40002d6c = sp24;
			#else
			Data_40002d6c_OTARightAscensionMinutes = 60 *
				(dData_40002d78 - dData_40003420 / 15.0 + dData_400033e8 - 
					Data_40002d68_OTARightAscensionHours);
			#endif
			
			#if 0
			sp64 = Data_40002d6c_OTARightAscensionMinutes;
			sp56 = sp64 / 60.0;
			sp48 = Data_40002d68_OTARightAscensionHours;
			sp40 = dData_40003420 / 15.0;
			sp32 = dData_40002d78 - sp40;
			sp24 = sp32 + dData_400033e8;
			sp16 = sp24 - sp48;
			sp8 = sp16 - sp56;
			sp = sp8 * 3600.0;
			#else
			fData_40002d70_OTARightAscensionSeconds = 3600.0 *
				((dData_40002d78 - dData_40003420 / 15.0 + dData_400033e8 - 
					Data_40002d68_OTARightAscensionHours) - 
					Data_40002d6c_OTARightAscensionMinutes / 60.0);
			#endif
			
			if ((bData_40003200 == 1) && (Data_40004128.dData_304 == 2.0))
			{
				//6e2c0
				dData_400033e8 = dData_40002ce8 - dData_40002d78;
				Data_40002d68_OTARightAscensionHours = Data_40002cd8_ObjectRightAscensionHours;
				Data_40002d6c_OTARightAscensionMinutes = Data_40002cdc_ObjectRightAscensionMinutes;
				fData_40002d70_OTARightAscensionSeconds = fData_40002ce0_ObjectRightAscensionSeconds;
			}
			//0x6e30c
			#if 0
			sp64 = dData_40002d98 - dData_40003428;
			sp56 = sp64 - dData_400031f8;
			fData_4000350c = sp56;
			#else
			fData_4000350c = dData_40002d98 - dData_40003428 - dData_400031f8;
			#endif

			#if 0
			sp64 = dData_40002d98 - dData_40003428;
			sp56 = sp64 + dData_400033f0;
			Data_40002d8c_OTADeclinationDegrees = sp56;
			#else
			Data_40002d8c_OTADeclinationDegrees = dData_40002d98 - dData_40003428 + dData_400033f0;
			#endif
			
			#if 0
			sp64 = Data_40002d8c_OTADeclinationDegrees;
			sp56 = dData_40002d98 - dData_40003428;
			sp48 = sp56 + dData_400033f0;
			sp40 = sp48 - sp64;
			sp32 = sp40 * 60.0;
			Data_40002d90_OTADeclinationMinutes = sp32;
			#else
			Data_40002d90_OTADeclinationMinutes = 60.0 *
				(dData_40002d98 - dData_40003428 + dData_400033f0 - Data_40002d8c_OTADeclinationDegrees);
			#endif
			
			#if 0
			sp64 = Data_40002d90_OTADeclinationMinutes;
			sp56 = sp64 / 60.0;
			sp48 = Data_40002d8c_OTADeclinationDegrees;
			sp40 = dData_40002d98 - dData_40003428;
			sp32 = sp40 + dData_400033f0;
			sp24 = sp32 - sp48;
			sp16 = sp24 - sp56;
			sp8 = sp16 * 3600.0;
			#else
			fData_40002d94_OTADeclinationSeconds = 3600.0 *
				(dData_40002d98 - dData_40003428 + dData_400033f0 - Data_40002d8c_OTADeclinationDegrees - 
					Data_40002d90_OTADeclinationMinutes / 60.0);
			#endif
			
			if ((bData_40003201 == 1) && (Data_40004128.dData_312 == 2.0))
			{
				//6e4f8
				#if 0
				sp64 = fData_40002d18_ObjectDeclination;
				dData_400033f0 = sp64 - dData_40002d98;
				#else
				dData_400033f0 = fData_40002d18_ObjectDeclination - dData_40002d98;
				#endif
				
				Data_40002d8c_OTADeclinationDegrees = Data_40002d00_ObjectDeclinationDegrees;
				Data_40002d90_OTADeclinationMinutes = Data_40002d04_ObjectDeclinationMinutes;
				fData_40002d94_OTADeclinationSeconds = fData_40002d08_ObjectDeclinationSeconds;
			}
			//6e554 -> 0x6f8d0
		} //if (bData_40002c1a == 1)
		//6e558
		else if (bData_40002c1a == 2)
		{
			//6e568
			if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
			{
				//6e578
				dData_40002d30 = Data_40004128.dData_144 + 180.0;
				Data_40002d20 = dData_40002d30;
				Data_40002d24 = (dData_40002d30 - Data_40002d20) * 60.0;
				fData_40002d28 = (dData_40002d30 - Data_40002d20 - Data_40002d24 / 60.0) * 3600.0;
				//6e68c
				dData_40002d58 = 90.0 - Data_40004128.dData_152;
				Data_40002d48 = dData_40002d58;
				Data_40002d4c = (dData_40002d58 - Data_40002d48) * 60.0;
				fData_40002d50 = (dData_40002d58 - Data_40002d48 - Data_40002d4c / 60.0) * 3600.0;
				
				InquireMotorData(3);
				
				Data_40004128.dData_208 = dData_40002db8;
				dData_40002dc0_Azimuth = Data_40004128.dData_208;
				
				if (bData_40003430 == 0)
				{
					//6e7e8
					dData_40002dc0_Azimuth = Data_40004128.dData_192;
				}
				else
				{
					//0x6e800
					dData_40002dc0_Azimuth += Data_40004128.dData_192;
				}
				//0x6e820
				while (dData_40002dc0_Azimuth >= 360)
				{
					dData_40002dc0_Azimuth -= 360;
				}

				while (dData_40002dc0_Azimuth < 0)
				{
					dData_40002dc0_Azimuth += 360;
				}
				//6e890
				fData_40003508 = dData_40002dc0_Azimuth - dData_40003410 - dData_400031f0;
				Data_40002dac = dData_40002dc0_Azimuth - dData_40003410 + dData_400033e8;
				Data_40002db0 = (dData_40002dc0_Azimuth - dData_40003410 + dData_400033e8 - Data_40002dac) * 60.0;
				fData_40002db4 = (int)((dData_40002dc0_Azimuth - dData_40003410 + dData_400033e8 - 
						Data_40002dac - Data_40002db0 / 60.0) * 3600.0);
				//6ea58
				if ((bData_40003200 == 1) && (Data_40004128.dData_304 == 2.0))
				{
					//6ea84
					dData_400033e8 = dData_40002d30 - dData_40002dc0_Azimuth;
					Data_40002dac = Data_40002d20;
					Data_40002db0 = Data_40002d24;
					fData_40002db4 = fData_40002d28;
				}
				//0x6ead0
				func_659c(2);
				InquireMotorData(4);
				//6eae8
				Data_40004128.dData_216 = dData_40002df0;
				dData_40002df8 = Data_40004128.dData_216;
				
				if (bData_40003430 == 0)
				{
					//6eb20
					dData_40002df8 = Data_40004128.dData_200;
				}
				else
				{
					//0x6eb38
					dData_40002df8 = Data_40004128.dData_200 - dData_40002df8;
				}
				//0x6eb58
				if (dData_40002df8 > 90)
				{
					dData_40002df8 = 180 - dData_40002df8;
				}
				//0x6eb8c
				fData_4000350c = dData_40002df8 - dData_40003418 - dData_400031f8;
				Data_40002de0 = dData_40002df8 - dData_40003418 + dData_400033f0;
				Data_40002de4 = (dData_40002df8 - dData_40003418 + dData_400033f0 - Data_40002de0) * 60.0;
				fData_40002de8 = (int)((dData_40002df8 - dData_40003418 + dData_400033f0 - 
						Data_40002de0 - Data_40002de4 / 60.0) * 3600.0);
				
				if ((bData_40003201 == 1) && (Data_40004128.dData_312 == 2.0))
				{
					//6ee28
					dData_400033f0 = dData_40002d58 - dData_40002df8;
					Data_40002de0 = Data_40002d48;
					Data_40002de4 = Data_40002d4c;
					fData_40002de8 = fData_40002d50;
				}
				//0x6f8d0
			} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
			else
			{
				//6ee78
				dData_40002ce8 = Data_40004128.dData_88;
				Data_40002cd8_ObjectRightAscensionHours = dData_40002ce8;
				Data_40002cdc_ObjectRightAscensionMinutes =
					(dData_40002ce8 - Data_40002cd8_ObjectRightAscensionHours) * 60.0;
				fData_40002ce0_ObjectRightAscensionSeconds = 
					((dData_40002ce8 - Data_40002cd8_ObjectRightAscensionHours) - 
						Data_40002cdc_ObjectRightAscensionMinutes / 60.0) * 3600.0;
				//6ef7c
				fData_40002d18_ObjectDeclination = fabs(Data_40004128.dData_80);
				Data_40002d00_ObjectDeclinationDegrees = fData_40002d18_ObjectDeclination;
				Data_40002d04_ObjectDeclinationMinutes = 
					(fData_40002d18_ObjectDeclination - Data_40002d00_ObjectDeclinationDegrees) * 60.0;
				fData_40002d08_ObjectDeclinationSeconds = 
					((fData_40002d18_ObjectDeclination - Data_40002d00_ObjectDeclinationDegrees) - 
						Data_40002d04_ObjectDeclinationMinutes / 60.0) * 3600.0;
				
				if (Data_40004128.dData_80 > 0)
				{
					Data_40002d44 = 1;
				}
				else
				{
					Data_40002d44 = -1;
				}
				//0x6f0d4
				InquireMotorData(3);
			
				Data_40004128.dData_208 = dData_40002db8;
				dData_40002dc0_Azimuth = Data_40004128.dData_208;
				//->0x6f12c
				while (dData_40002dc0_Azimuth >= 360)
				{
					dData_40002dc0_Azimuth -= 360;
				}
				//->0x6f164
				while (dData_40002dc0_Azimuth < 0)
				{
					dData_40002dc0_Azimuth += 360;
				}
				//6f17c
				dData_40002d78 = dData_40002dc0_Azimuth;
				
				func_659c(2);
				InquireMotorData(4);
				
				Data_40004128.dData_216 = dData_40002df0;
				dData_40002df8 = fabs(Data_40004128.dData_216);
				dData_40002d98 = dData_40002df8;
				
				if (Data_40004128.geographicLatitude >= 0)
				{
					//6f1f8
					if (dData_40002d78 > 360)
					{
						dData_40002d78 += 360; //BUG?
					}
					//0x6f22c
					dData_40002d78 -= 180;
					
					if (dData_40002d78 < 0)
					{
						dData_40002d78 += 360;
					}
					//0x6f27c
					dData_40002d98 = 90 - dData_40002d98;
					//->0x6f328
				}
				else
				{
					//0x6f29c
					dData_40002d78 -= 180;
					
					if (dData_40002d78 < 0)
					{
						dData_40002d78 = -1 * dData_40002d78;
					}
					else
					{
						//0x6f2f0
						dData_40002d78 = 360 - dData_40002d78;
					}
					//0x6f30c
					dData_40002d98 -= 90;
				}
				//0x6f328
				dData_40002d78 /= 15;

				fData_40003508 = fData_400034c8 - 
					(dData_40002d78 - dData_40003420 / 15 - dData_400031f0 / 15);
				
				if (fData_40003508 < 0)
				{
					fData_40003508 += 24;
				}
				//0x6f408
				if (fData_40003508 > 24)
				{
					fData_40003508 -= 24;
				}
				//0x6f434
				Data_40002d68_OTARightAscensionHours = dData_40002d78 - dData_40003420 / 15 + dData_400033e8;
				Data_40002d6c_OTARightAscensionMinutes = (dData_40002d78 - dData_40003420 / 15 + dData_400033e8 - Data_40002d68_OTARightAscensionHours) * 60;
				fData_40002d70_OTARightAscensionSeconds = (dData_40002d78 - dData_40003420 / 15 + 
					dData_400033e8 - Data_40002d68_OTARightAscensionHours - Data_40002d6c_OTARightAscensionMinutes / 60.0) * 3600.0;
				//6f5f8
				if ((bData_40003200 == 1) && (Data_40004128.dData_304 == 2))
				{
					//6f624
					dData_400033e8 = dData_40002ce8 - dData_40002d78;
					Data_40002d68_OTARightAscensionHours = Data_40002cd8_ObjectRightAscensionHours;
					Data_40002d6c_OTARightAscensionMinutes = Data_40002cdc_ObjectRightAscensionMinutes;
					fData_40002d70_OTARightAscensionSeconds = fData_40002ce0_ObjectRightAscensionSeconds;
					bData_40002d88 = 1;
				}
				//0x6f67c
				fData_4000350c = dData_40002d98 - dData_40003428 - dData_400031f8;
				Data_40002d8c_OTADeclinationDegrees = dData_40002d98 - dData_40003428 + dData_400033f0;
				Data_40002d90_OTADeclinationMinutes = (dData_40002d98 - dData_40003428 + dData_400033f0 - Data_40002d8c_OTADeclinationDegrees) * 60;
				fData_40002d94_OTADeclinationSeconds = (dData_40002d98 - dData_40003428 + 
					dData_400033f0 - Data_40002d8c_OTADeclinationDegrees - Data_40002d90_OTADeclinationMinutes / 60.0) * 3600.0;
				
				if ((bData_40003201 == 1) && (Data_40004128.dData_312 == 2))
				{
					//6f868
					dData_400033f0 = fData_40002d18_ObjectDeclination - dData_40002d98;
					Data_40002d8c_OTADeclinationDegrees = Data_40002d00_ObjectDeclinationDegrees;
					Data_40002d90_OTADeclinationMinutes = Data_40002d04_ObjectDeclinationMinutes;
					fData_40002d94_OTADeclinationSeconds = fData_40002d08_ObjectDeclinationSeconds;
					bData_40002da8 = 1;
				}
				//0x6f8d0
			}
		} //else if (bData_40002c1a == 2)
		//6f8d0
		if (bSystemInitialized == 0)
		{
			//6f8e0
			lcd_display_clear();
			lcd_display_string(0, 4, 1, 22, "System Initializing...");
			get_all_solar_system_object_equatorial_coordinates();
			func_659c(1000);
			beep1(1);
			lcd_display_clear();
			lcd_display_string(0, 4, 1, 22, "System Initialized    ");
			func_659c(1000);
			lcd_display_clear();
			
			bSystemInitialized = 1;
		}
		//6f94c
		UserInterfaceCycle();
		//6f950
		if (Data_40004128.bData_364 == 0)
		{
			//6f960
			func_c57c();
			
			bData_400034cc = 0;
		}
		//6f970
		if ((bData_400031b8 != 0) && (Data_400031a4.Data <= 4800))
		{
			//6f990
			if (Data_400031a4.Data < 4800)
			{
				if (Data_400031b4 == 1)
				{
					//6f9b0
					Data_400031a4.Data = Data_400031a4.Data + Data_400031b4 * 100;
				}
				else
				{
					//0x6f9d8
					Data_400031a4.Data = Data_400031a4.Data + Data_400031b4 * 300;
				}
			}
			//0x6f9fc
			if (Data_400031a4.Data >= 2560)
			{
				//6fa0c
				if (bData_400031bc == 1)
				{
					//6fa1c
					Data_400031ac.Data = 2514862080.0;
				}
				else
				{
					//0x6fa34
					Data_400031ac.Data = -2514862080.0;
				}
				//0x6fa48
				if (bData_4000319d != 1)
				{
					//6fa58
					uart1_write_byte(0x55);
					uart1_write_byte(0xaa);
					uart1_write_byte(0x01);
					uart1_write_byte(1 + 2 + 3);
					
					if (bData_400031ba == 0x01)
					{
						//6fa88
						uart1_write_byte(0x02); //Send RA?
					}
					//0x6fa90
					if (bData_400031ba == 0x21)
					{
						//6faa0
						uart1_write_byte(0x22); //Send DEC?
					}
					//0x6faa8
					uart1_write_byte(Data_400031a4.bData[1]);
					uart1_write_byte(Data_400031a4.bData[0]);
					uart1_write_byte(Data_400031ac.bData[3]);
					uart1_write_byte(Data_400031ac.bData[2]);
					uart1_write_byte(Data_400031ac.bData[1]);
				}
				//0x6fb24
			} //if (Data_400031a4.Data >= 2560)
			else
			{
				//0x6fae8
				uart1_write_byte(0x55);
				uart1_write_byte(0xaa);
				uart1_write_byte(0x01);
				uart1_write_byte(1);
				uart1_write_byte(0x00);
				
				bData_400031b8 = 0;
				bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
			}
		} //if ((bData_400031b8 != 0) && (Data_400031a4.Data <= 4800))
		//6fb24
		if (bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)
		{
			//6fb34: Receive guiding value?
			func_6b17c();
			
			Data_40003488 = Data_40002c1c;
			Data_4000348c = Data_40002c20;
			#if 0
			sp64 = 2 * Data_40003488 + Data_40003204;
			sp56 = sp64 * dData_40002ca0;
			sp48 = sp56 * 0.00153;
			Data_40004128.dData_584 = sp48 + Data_40004128.dData_584;
			#else
			Data_40004128.dData_584 = (2 * Data_40003488 + Data_40003204) * 
				dData_40002ca0 * 0.00153 + Data_40004128.dData_584;
			#endif

			#if 0
			sp64 = 4 * Data_4000348c + Data_40003208;
			sp56 = sp64 * dData_40002ca0;
			sp48 = sp56 * 0.00153;
			Data_40004128.dData_592 = sp48 + Data_40004128.dData_592;
			#else
			Data_40004128.dData_592 = (4 * Data_4000348c + Data_40003208) * 
				dData_40002ca0 * 0.00153 + Data_40004128.dData_592;
			#endif
			
			Data_40002c1c = 0;
			Data_40002c20 = 0;
		}
		//6fd3c
		if ((bData_40003211 == 0) && 
			(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/) &&
			(dData_40002ce8 < 23.99999))
		{
			//6fd4c
			bData_40003211 = 1;
		}
		//6fd80
		if ((bData_40003211 != 0) && 
				(bData_40003210 == 0) && 
				(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/) &&
				(dData_40002ce8 >= 23.83) &&
				(dData_40002ce8 < 23.99717))
		{
			//6fde0
			bData_40003210 = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_MERIDIAN_FLIP;
		}
		//6fdf8
		if ((bData_40003210 != 0) &&
				(bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/) &&
				(dData_40002ce8 >= 23.99717))
		{
			//6fe30
			bData_40002e89 = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN;
			bData_40003210 = 0;
			bData_40003211 = 0;
			
			beep1(3);
			func_b4f0();
		}
		//6fe64
		if (bData_40002c1a == 1)
		{
			//6fe74
			if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
			{
				//6fe94
				if (Data_40002c64_MenuContextId != MENU_CONTEXT_ALIGNMENT_STAR_CONTROL) //12001)
				{
					//6fea8
					switch (bData_40002e7d_RotatingSpeed)
					{
						case 0:
							//0x6fee4
							dData_400033f8 = 0;
							dData_40003400 = 0;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 1:
							//0x6ff94
							dData_400033f8 = 0.00153;
							dData_40003400 = 0.0012;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 2:
							//0x70098
							dData_400033f8 = 0.0031;
							dData_40003400 = 0.0031;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 3:
							//0x70148
							dData_400033f8 = 0.0148;
							dData_40003400 = 0.0148;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 4:
							//0x701f8
							dData_400033f8 = 0.0602;
							dData_40003400 = 0.0602;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 5:
							//0x702a8
							dData_400033f8 = 0.11;
							dData_40003400 = 0.11;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 6:
							//0x70358
							dData_400033f8 = 0.16;
							dData_40003400 = 0.16;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 7:
							//0x7042c						
							dData_400033f8 = 0.481;
							dData_40003400 = 0.481;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 8:
							//0x704dc
							dData_400033f8 = 0.765;
							dData_40003400 = 0.765;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						case 9:
							//0x7058c
							dData_400033f8 = 1.56;
							dData_40003400 = 1.56;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
						
						default:
							//0x7063c
							dData_400033f8 = 0;
							dData_40003400 = 0;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x706ec
							break;
					} //switch (bData_40002e7d_RotatingSpeed)
					//706ec -> 0x72040
				} //if (Data_40002c64_MenuContextId != MENU_CONTEXT_ALIGNMENT_STAR_CONTROL)
				else
				{
					//0x706f0
					switch (bData_40002e7d_RotatingSpeed)
					{
						case 0:
							//0x70744
							dData_400033f8 = 0;
							dData_40003400 = 0;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 1:
							//0x707f4
							dData_400033f8 = 0.00154;
							dData_40003400 = 0.00154;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 2:
							//0x708a4
							dData_400033f8 = 0.0031;
							dData_40003400 = 0.0031;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 3:
							//0x70954
							dData_400033f8 = 0.026;
							dData_40003400 = 0.0236;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 4:
							//0x70a04
							dData_400033f8 = 0.084;
							dData_40003400 = 0.084;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 5:
							//0x70ab4
							dData_400033f8 = 0.154;
							dData_40003400 = 0.142;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 6:
							//0x70b98
							dData_400033f8 = 0.2423;
							dData_40003400 = 0.2187;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 7:
							//0x70c48						
							dData_400033f8 = 0.6305;
							dData_40003400 = 0.6305;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 8:
							//0x70cf8
							dData_400033f8 = 1.031;
							dData_40003400 = 1.031;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case 9:
							//0x70da8
							dData_400033f8 = 2.15;
							dData_40003400 = 2.15;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x70f08
							break;
						
						default:
							//0x70e58
							dData_400033f8 = 0;
							dData_40003400 = 0;
						
							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
					} //switch (bData_40002e7d_RotatingSpeed)
					//0x70f08 -> 0x72040
				}
			} //if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
			//->0x72040
		} //if (bData_40002c1a == 1)
		else
		{
			//70f38
			if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
			{
				//70f58
				if (Data_40002c64_MenuContextId != MENU_CONTEXT_ALIGNMENT_STAR_CONTROL) //12001)
				{
					//70f6c
					switch (bData_40002e7d_RotatingSpeed)
					{
						case 0:
							//0x70fa8
							dData_400033f8 = 0.0007;
							dData_40003400 = 0.0007;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x717d4
							break;
						
						case MENU_ROTATING_SPEED_1: //1:
							//0x71058
							dData_400033f8 = 0.0015;
							dData_40003400 = 0.0015;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_2: //2:
							//0x71108
							dData_400033f8 = 0.0083;
							dData_40003400 = 0.0083;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_8: //3:
							//0x711b8
							dData_400033f8 = 0.0234;
							dData_40003400 = 0.0235;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_16: //4:
							//0x71268
							dData_400033f8 = 0.042;
							dData_40003400 = 0.041;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_64: //5:
							//0x71368
							dData_400033f8 = 0.071;
							dData_40003400 = 0.0708;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_128: //6:
							//0x71418
							dData_400033f8 = 0.142;
							dData_40003400 = 0.106;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_256: //7:
							//0x714c8
							dData_400033f8 = 0.26;
							dData_40003400 = 0.236;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_512: //8:
							//0x71578
							dData_400033f8 = 0.634;
							dData_40003400 = 0.39;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_MAX: //9:
							//0x71628
							dData_400033f8 = 0.98;
							dData_40003400 = 0.45;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x717d4
							break;
						
						default:
							//0x71724
							dData_400033f8 = 0.0;
							dData_40003400 = 0.0;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
					} //switch (bData_40002e7d_RotatingSpeed)
					//0x717d4 -> 0x72040
					
				} //if (Data_40002c64_MenuContextId != MENU_CONTEXT_ALIGNMENT_STAR_CONTROL)
				else
				{
					//0x717d8
					switch (bData_40002e7d_RotatingSpeed)
					{
						case 0:
							//0x71814
							dData_400033f8 = 0.0011;
							dData_40003400 = 0.0007;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x717d4
							break;
						
						case MENU_ROTATING_SPEED_1: //1:
							//0x718c4
							dData_400033f8 = 0.0024;
							dData_40003400 = 0.0019;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_2: //2:
							//0x71974
							dData_400033f8 = 0.015;
							dData_40003400 = 0.0076;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_8: //3:
							//0x71a24
							dData_400033f8 = 0.035;
							dData_40003400 = 0.035;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_16: //4:
							//0x71ad4
							dData_400033f8 = 0.062;
							dData_40003400 = 0.06;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_64: //5:
							//0x71bcc
							dData_400033f8 = 0.093;
							dData_40003400 = 0.09;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_128: //6:
							//0x71c7c
							dData_400033f8 = 0.178;
							dData_40003400 = 0.13;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_256: //7:
							//0x71d2c
							dData_400033f8 = 0.335;
							dData_40003400 = 0.3;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_512: //8:
							//0x71ddc
							dData_400033f8 = 0.805;
							dData_40003400 = 0.485;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
						
						case MENU_ROTATING_SPEED_MAX: //9:
							//0x71e8c
							dData_400033f8 = 1.005;
							dData_40003400 = 0.69;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							//->0x7203c
							break;
						
						default:
							//0x71f8c
							dData_400033f8 = 0.0;
							dData_40003400 = 0.0;

							dData_400033d8 = Data_40003408 * dData_400033f8 + dData_400033d8;
							dData_400033e0 = Data_4000340c * dData_40003400 + dData_400033e0;
							break;
					} //switch (bData_40002e7d_RotatingSpeed)
				}
			} //if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
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
				Data_40002c64_MenuContextId = MENU_CONTEXT_NO_TELESCOPE; //2;
				Data_40004128.bData_357 = 0;
				Data_40004128.bData_364 = 1;
			}
			else
			{
				//720b0
				if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
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
		if (iBacklashCorrectionSlewing == 1)
		{
			//720dc
			func_659c(3000);
			
			switch (bData_40002edd)
			{
				case 0:
					//0x72110
					InquireMotorData(3);
				
					Data_40004128.dData_208 = dData_40002db8;
					dData_40002dc0_Azimuth = Data_40004128.dData_208;
					//->7221c
					break;
				
				case 1:
					//0x72150
					InquireMotorData(4);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = fabs(Data_40004128.dData_216);
					//->7221c
					break;
				
				case 2:
					//0x72194
					InquireMotorData(1);
				
					Data_40004128.dData_208 = dData_40002d80;
					dData_40002dc0_Azimuth = Data_40004128.dData_208;
					break;
				
				case 3:
					//0x721d4
					InquireMotorData(2);
				
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
					InquireMotorData(3);
				
					Data_40004128.dData_208 = dData_40002db8;
					dData_40002dc0_Azimuth = Data_40004128.dData_208;
					//->0x72364
					break;
				
				case 1:
					//0x72298
					InquireMotorData(4);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = fabs(Data_40004128.dData_216);
					//->0x72364
					break;
				
				case 2:
					//0x722dc
					InquireMotorData(1);
				
					Data_40004128.dData_208 = dData_40002d80;
					dData_40002dc0_Azimuth = Data_40004128.dData_208;
					break;
				
				case 3:
					//0x7231c
					InquireMotorData(2);
				
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
					InquireMotorData(3);
				
					Data_40004128.dData_208 = dData_40002db8;
					dData_40002dc0_Azimuth = Data_40004128.dData_208;
					dData_40002dc0_Azimuth += Data_40004128.dData_192;
					//->72410
					while (dData_40002dc0_Azimuth >= 360.0)
					{
						//723f4
						dData_40002dc0_Azimuth -= 360.0;
					}
					//->72448
					while (dData_40002dc0_Azimuth < 0.0)
					{
						//7242c
						dData_40002dc0_Azimuth += 360.0;
					}
					//->7257c
					while (fabs(dData_40002dc0_Azimuth - dRaBklashCorrStartAzimuth) > 0.0014)
					{
						//72464
						if (bRaBacklashCorrectionDirection == 2)
						{
							//72474
							func_57414(3, 4, 1);
						}
						//72484
						if (bRaBacklashCorrectionDirection == 1)
						{
							//72494
							func_57414(3, 3, 1);
						}
						//724a4
						func_659c(10);
						InquireMotorData(3);
						func_659c(10);
						//724c4
						Data_40004128.dData_208 = dData_40002db8;
						dData_40002dc0_Azimuth = Data_40004128.dData_208;
						dData_40002dc0_Azimuth += Data_40004128.dData_192;
						//->7252c
						while (dData_40002dc0_Azimuth >= 360.0)
						{
							//72510
							dData_40002dc0_Azimuth -= 360.0;
						}
						//->72564
						while (dData_40002dc0_Azimuth < 0.0)
						{
							//72548
							dData_40002dc0_Azimuth += 360.0;
						}
					} //while(...)
					//->72968
					break;
				
				case 1:
					//0x725bc
					InquireMotorData(4);
				
					Data_40004128.dData_216 = dData_40002df0;
					dData_40002df8 = Data_40004128.dData_216;
					dData_40002df8 = Data_40004128.dData_200 - dData_40002df8;
					//->0x726bc
					while (fabs(dData_40002df8 - dData_40002e00) > 0.0014)
					{
						//0x72618
						if (bDecBacklashCorrectionDirection == 2)
						{
							//72628
							func_57414(4, 2, 1);
						}
						//72638
						if (bDecBacklashCorrectionDirection == 1)
						{
							//72648
							func_57414(4, 1, 1);
						}
						//72658
						func_659c(10);
						InquireMotorData(4);
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
					InquireMotorData(1);
				
					Data_40004128.dData_208 = dData_40002d80;
					dData_40002dc0_Azimuth = Data_40004128.dData_208;
					//->727c4
					while (fabs(dData_40002dc0_Azimuth - dRaBklashCorrStartAzimuth) > 0.0014)
					{
						//7273c
						if (bRaBacklashCorrectionDirection == 2)
						{
							func_57414(1, 4, 2);
						}
						
						if (bRaBacklashCorrectionDirection == 1)
						{
							func_57414(1, 3, 2);
						}
						
						func_659c(10);
						InquireMotorData(1);
						func_659c(10);
						
						Data_40004128.dData_208 = dData_40002d80;
						dData_40002dc0_Azimuth = Data_40004128.dData_208;
					}
					//->72968
					break;
				
				case 3:
					//0x72804
					InquireMotorData(2);
				
					Data_40004128.dData_216 = dData_40002da0;
					dData_40002df8 = fabs(Data_40004128.dData_216);
					//->72928
					while (fabs(dData_40002df8 - dData_40002e00) > 0.0014)
					{
						//728a0
						if (bDecBacklashCorrectionDirection == 2)
						{
							func_57414(2, 2, 2);
						}
						
						if (bDecBacklashCorrectionDirection == 1)
						{
							func_57414(1, 1, 2);
						}
						
						func_659c(10);
						InquireMotorData(2);
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
			beep1(2);		
			//72980
			iBacklashCorrectionSlewing = 0;
		} //if (iBacklashCorrectionSlewing == 1)
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


/* 6d054 - todo */
int main(void)
{
	lpc_hw_init();
	uart0_init(360);
	uart1_init(360);

	VICVectCntl1 = (1 << 5) | 6; // UART0 -> Slot 1
	VICIntEnable = (1 << 6); // Enable UART0

	VICVectCntl2 = (1 << 5) | 7; // UART1 -> Slot 2
	VICIntEnable = (1 << 7); // Enable UART1

	//ON
	IO0CLR = (1 << 16);

	xTaskCreate( vLEDTask, "LEDTask", /*configMINIMAL_STACK_SIZE*/100, NULL, tskIDLE_PRIORITY+1, NULL );
	xTaskCreate( vMainTask, "MainTask", /*configMINIMAL_STACK_SIZE*/1000, NULL, tskIDLE_PRIORITY+1, NULL );
	xTaskCreate( vTimerTask, "TimerTask", /*configMINIMAL_STACK_SIZE*/100, NULL, tskIDLE_PRIORITY+2, NULL );
	xTaskCreate( vUART0Task, "UART0Task", /*configMINIMAL_STACK_SIZE*/100, NULL, tskIDLE_PRIORITY+3, NULL );
	xTaskCreate( vUART1Task, "UART1Task", /*configMINIMAL_STACK_SIZE*/100, NULL, tskIDLE_PRIORITY+3, NULL );

#if 0
	{
		static char buf[105];

		snprintf(buf, 100, "vTaskStartScheduler\n\r");
		uart1_send((unsigned char*)buf, strlen(buf));
	}
#endif

	vTaskStartScheduler();
}

