
//#include "menu.h"

/* 5f230 - todo */
void HandleMinusKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_RECENT_TARGETS: //1:
			//0x5f9e0
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case 5000:
			//0x5f9f4
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case 101:
			//0x5fa08
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case 102:
			//0x5fa1c
			Data_40002c64_MenuContextId = 101;
			break;
		
		case MENU_CONTEXT_MERIDIAN_FLIP: //3:
			//0x5fa30
			bData_40003210 = 1;
			bData_40003211 = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x5fa58: One / Two / Three Star Align
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				//5fa6c
				Data_40004128.bAlignmentComplete = 1;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				lcd_display_string(0, 1, 1, 21, "                     ");
				lcd_display_string(0, 2, 1, 21, "                     ");
				lcd_display_string(0, 3, 1, 21, "                     ");
				lcd_display_string(0, 4, 1, 21, "This Align Canceled  ");
				lcd_display_string(0, 5, 1, 21, "                     ");
				lcd_display_string(0, 6, 1, 21, "                     ");
				lcd_display_string(0, 7, 1, 21, "                     ");
				lcd_display_string(0, 8, 1, 21, "                     ");
				
				func_659c(1000);
				beep1(2);
				func_659c(100);
				
				Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			}
			else
			{
				//0x5fb8c
				switch (Data_40002c5c_AlignmentStarCount)
				{
					case 1:
						//0x5fbb0
						Data_40002c64_MenuContextId = MENU_CONTEXT_ONE_STAR_ALIGN; //1100;
						break;
					
					case 2:
						//0x5fbc4
						Data_40002c64_MenuContextId = MENU_CONTEXT_TWO_STAR_ALIGN; //1200;
						break;
					
					case 3:
						//0x5fbd8
						Data_40002c64_MenuContextId = MENU_CONTEXT_THREE_STAR_ALIGN; //1300;
						break;
					
					default:
						//0x5fbec
						break;
				}
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_ALIGNMENT: //1000:
			//0x5fbfc
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			//->0x60d48
			break;
		
		case MENU_CONTEXT_NAVIGATION: //2000:
			//0x5fc10
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_UTILITIES: //3000:
			//0x5fc24
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_SETUP: //4000:
			//0x5fc38
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_ONE_STAR_ALIGN: //1100:
			//0x5fc4c
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			break;
		
		case MENU_CONTEXT_TWO_STAR_ALIGN: //1200:
			//0x5fc60
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			break;
		
		case MENU_CONTEXT_THREE_STAR_ALIGN: //1300:
			//0x5fc74
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			break;
		
		case MENU_CONTEXT_TARGET_SYNC: //1400:
			//0x5fc88
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			break;
		
		case MENU_CONTEXT_POLE_AXIS_DEV: //1500:
			//0x5fc9c
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR: //1600:
			//0x5fcb0
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			break;
		
		case MENU_CONTEXT_DEC_BKLASH_CORR: //1700:
			//0x5fcc4
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM: //2100:
			//0x5fcd8
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CONSTELLATION: //2200:
			//0x5fcec
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2300:
			//0x5fd00
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2400:
			//0x5fd14
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2500:
			//0x5fd28
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2600:
			//0x5fd3c
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2700:
			//0x5fd50
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2800:
			//0x5fd64
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2900:
			//0x5fd78
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_OBJ: //2110:
			//0x5fdd8
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case MENU_CONTEXT_NAVIGATION_RA_DEC: //2120:
			//0x5fdec
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case 2130:
			//0x5fe00
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			break;
		
		case MENU_CONTEXT_CURRENT_OBJECTS: //3100:
			//0x5fe14
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_OBJECT_RISE_SET: //3200:
			//0x5fe28
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_LUNAR_PHASE: //3300:
			//0x5fe3c
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_TIMER: //3400:
			//0x5fe50
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_ALARM: //3500:
			//0x5fe64
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV: //3600:
			//0x5fe78
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN: //3700:
			//0x5fe8c
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION: //3800:
			//0x5fea0
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_PARK_POSITION: //3900:
			//0x5feb4
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case 4100:
			//0x5fec8
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4200:
			//0x5fedc: Daylight Saving
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4300:
			//0x5fef0
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4400:
			//0x5ff04
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4500:
			//0x5ff18
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4600:
			//0x5ff2c
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4700:
			//0x5ff40
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4800:
			//0x5ff54
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case 4900:
			//0x5ff68
			Data_40002c64_MenuContextId = 4000;
			break;
		
		case MENU_CONTEXT_SYNC_OPEN: //1401:
			//0x5ff7c
			g_bTargetSyncOpen = FALSE;
		case MENU_CONTEXT_SYNC_ENSURE: //1402:
			//0x5ff90
		case MENU_CONTEXT_SYNC_CANCEL: //1403:
			//0x5ff94
			Data_40002c64_MenuContextId = MENU_CONTEXT_TARGET_SYNC; //1400;
			break;
		
		case 2801:
			//0x5ffa4
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case 2802:
			//0x5ffb8
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case 2803:
			//0x5ffcc
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case 2804:
			//0x5ffe0
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case 21101:
			//0x5fff4
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case 21102:
			//0x60008
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case 21103:
			//0x6001c
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//0x60030
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIMER; //3400;
			break;
		
		case MENU_CONTEXT_TIMER_COUNTING: //34002:
			//0x60044
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIMER; //3400;
			break;
		
		case MENU_CONTEXT_ALARM_INPUT: //35001:
			//0x60058
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALARM; //3500;
			break;
		
		case 35002:
			//0x6006c
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALARM; //3500;
			break;
		
		case 360021:
			//0x60080
		case 360022:
			//0x60088
			Data_40002c64_MenuContextId = 3700;
			break;
		
		case 370021:
			//0x60098
		case 370022:
			//0x600a0
		case 370023:
			//0x600a4
			Data_40002c64_MenuContextId = 3600;
			break;
		
		case 3602:
			//0x600b4
			Data_40002c64_MenuContextId = 3600;
			break;
		
		case 3801:
			//0x600c8
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION; //3800;
			break;
		
		case 3802:
			//0x600dc
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION; //3800;
			break;
		
		case 4301:
			//0x600f0
		case 4302:
			//0x600f8
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = 4300;
			}
			else
			{
				//0x60118
				Data_40002c64_MenuContextId = 42001;
			}
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_STAR_SPEED: //4801:
			//0x60128
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE; //4700;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED: //4802:
			//0x6013c
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE; //4700;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_MOON_SPEED: //4803:
			//0x60150
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE; //4700;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED: //4804:
			//0x60164
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE; //4700;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED: //4805:
			//0x60178
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE; //4700;
			break;
		
		case 45001:
			//0x6018c
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case 45002:
			//0x601a0
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case 46001:
			//0x601b4
			Data_40002c64_MenuContextId = 4500;
			break;
		
		case 46002:
			//0x601c8
			Data_40002c64_MenuContextId = 4500;
			break;
		
		case 18001:
			//0x601dc
			Data_40002c64_MenuContextId = 1500;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x601f0
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR; //1600;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
			//0x60204
			SlewStop();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11102;
			iBacklashCorrectionSlewing = 0;
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x60228
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKLASH_CORR; //1700;
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN: //11201:
			//0x6023c
			SlewStop();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11202;
			iBacklashCorrectionSlewing = 0;
			break;
		
		case 31001:
			//0x60260
			Data_40002c64_MenuContextId = 3100;
			break;
		
		case 26001:
			//0x60274
			Data_40002c64_MenuContextId = 2600;
			break;
		
		case 27001:
			//0x60288
			Data_40002c64_MenuContextId = 2700;
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
			//0x6029c
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM; //2100;
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x602b0
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x602e0
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION; //22001;
			}
			else
			{
				//0x60300
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_SUN_WARNING: //22112:
			//0x60328
			Data_40002c64_MenuContextId = MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION; //22001;
			break;
		
		case MENU_CONTEXT_CONSTELLATION_SELECTION: //24001:
			//0x6033c
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CONSTELLATION; //2200;
			break;
		
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x60350
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//60380
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_CONSTELLATION_SELECTION; //24001;
			}
			else
			{
				//0x603a0
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;

		case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
			//0x603c8
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_FAMOUS_STAR; //2300;
			break;
			
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x603dc
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x6040c
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_FAMOUS_STAR_SELECTION; //25001;
			}
			else
			{
				//6042c
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
			//0x60454
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_MESSIER_CAT; //2400;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//0x60468
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_MESSIER_OBJECT_DETAILS; //23012;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x60480
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x604b0
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_MESSIER_OBJECT_SELECTION; //23002;
			}
			else
			{
				//0x604d0
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//0x604f8
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_NGC_CAT; //2500;
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x6050c
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x6053c
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_NGC_OBJECT_SELECTION; //23003;
			}
			else
			{
				//0x6055c
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//0x60584
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_IC_CAT; //2600;
			break;
		
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x60598
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x605c8
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_IC_OBJECT_SELECTION; //23004;
			}
			else
			{
				//0x605e8
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//0x60610
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SH2_CAT; //2700;
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x60624
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x60654
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_SH2_OBJECT_SELECTION; //23005;
			}
			else
			{
				//0x60674
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//0x6069c
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_BRIGHT_STAR; //2800;
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x606b0
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x606e0
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_BRIGHT_STAR_SELECTION; //23006;
			}
			else
			{
				//0x60700
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x60728
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SAO_CAT; //2900;
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			//0x6073c
			bData_40003432 = 0;
		
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_CANCEL/*5*/) ||
					(bTrackingModeMenu == 3))
			{
				//0x6076c
				lcd_display_clear();
				
				Data_40004128.bTrackingRequest = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_SAO_OBJECT_SELECTION; //23007;
			}
			else
			{
				//0x6078c
				bTrackingModeMenu = MENU_TRACKING_MODE_CANCEL; //5;
				
				StopSlewing();
				
				bData_40002e8c = 0;
				
				beep1(2);
			}
			//->0x60d48
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x607b4
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x607c8
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x607d0
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x607d4
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION; //201;
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
			//0x607e4
			if (bData_40003162 == 0)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_RA_DEC; //2120;
			}
			else
			{
				//0x60808
				Data_40002c64_MenuContextId = MENU_CONTEXT_OBJECT_RISE_SET; //3200;
			}
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
			//0x60818
			if (bData_40003162 == 0)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_RA_DEC; //2120;
			}
			else
			{
				//0x6083c
				Data_40002c64_MenuContextId = MENU_CONTEXT_OBJECT_RISE_SET; //3200;
			}
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//0x6084c
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_LAND; //2130;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x60860
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x60868
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x6086c
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUST_LAND_OBJ_SELECTION; //202;
			break;
		
		case 360111:
			//0x6087c
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 360112:
			//0x60890
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 360113:
			//0x608a4
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL: //380011:
			//0x608b8
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION; //3800;
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_ON: //42001:
			//0x608cc
		case MENU_CONTEXT_DAYLIGHT_SAVING_OFF: //42002:
			//0x608d4
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING; //4200;
			}
			else
			{
				//0x608f4
				get_rtc_date_time();
				
				sprintf(Data_400037ec, "%04d-%02d-%02d",
					Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
				sprintf(Data_40003150, "%02d:%02d:%02d",
					bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
				
				sprintf(Data_40002655, "%04d-%02d-%02d",
					Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
				sprintf(Data_40002660, "%02d:%02d:%02d",
					bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
				
				bCharacterInputPosition = 1;
				bDateTimeInputMode = 0;
				
				Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE_INPUT; //41001;
			}
			//0x609bc -> 0x60d48
			break;
		
		case 211001:
			//0x609c0
			switch (bData_40003262)
			{
				case 0:
					//0x609e8
					Data_40002c64_MenuContextId = 21101;
					break;
				
				case 1:
					//0x609fc
					Data_40002c64_MenuContextId = 21102;
					break;
				
				case 2:
					//0x60a10
					Data_40002c64_MenuContextId = 21103;
					break;
				
				default:
					//0x60a24
					break;
			}
			break;
		
		case 28001:
			//0x60a34
			switch (bData_40003263)
			{
				case 0:
					//0x60a64
					Data_40002c64_MenuContextId = 2801;
					break;
				
				case 1:
					//0x60a78
					Data_40002c64_MenuContextId = 2802;
					break;
				
				case 2:
					//0x60b8c
					Data_40002c64_MenuContextId = 2803;
					break;
				
				case 3:
					//0x60ba0
					Data_40002c64_MenuContextId = 2804;
					break;
				
				default:
					//0x60bb4
					break;
				
			}
			break;
		
		case 49001:
			//0x60bc4
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49002:
			//0x60bd8
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49003:
			//0x60bec
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49004:
			//0x60c00
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49005:
			//0x60c14
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//0x60c28
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED; //4804;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED1: //48051:
			//0x60c3c
		case MENU_CONTEXT_GUIDING_SPEED2: //48052:
			//0x60c44
		case MENU_CONTEXT_GUIDING_SPEED3: //48053:
			//0x60c48
		case MENU_CONTEXT_GUIDING_SPEED4: //48054:
			//0x60c4c
		case MENU_CONTEXT_GUIDING_SPEED5: //48055:
			//0x60c50
		case MENU_CONTEXT_GUIDING_SPEED6: //48056:
			//0x60c54
		case MENU_CONTEXT_GUIDING_SPEED7: //48057:
			//0x60c58
		case MENU_CONTEXT_GUIDING_SPEED8: //48058:
			//0x60c5c
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED; //4805;
			break;
		
		case 360011: //???
			//0x60c6c
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 41001:
			//0x60c80
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = 4100;
			}
			break;
		
		case 43011:
			//0x60ca4
			Data_40002c64_MenuContextId = 4301;
			break;
		
		case 43002:
			//0x60cb8
			Data_40002c64_MenuContextId = 4302;
			break;
		
		case MENU_CONTEXT_RESET_CONFIRM: //100:
			//0x60ccc: Reset -> Cancel
			Data_40002c64_MenuContextId = MENU_CONTEXT_RESET; //4900;
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x60ce0
			if (bData_40002f1e_SetupLocalData == 0)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_TELESCOPE_MOUNT; //4600;
			}
			else
			{
				//0x60d04
				Data_40002c64_MenuContextId = MENU_CONTEXT_COUNTRY_CITY; //4301;
			}
			break;
		
		case MENU_CONTEXT_RISE_SET_TIMES: //32001:
			//0x60d14
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_INPUT; //29001;
			break;
		
		case 33001:
			//0x60d28: Curr. Lunar Phase
			Data_40002c64_MenuContextId = 3300;
			break;
		
		default:
			//60d3c
			func_b4d0();
			break;
	}
}

