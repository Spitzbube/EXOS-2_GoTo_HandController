
//#include "menu.h"

/* 5ab50 - todo */
void HandleDownKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_RECENT_TARGETS: //1:
			//0x5b27c
			if (bData_4000316e_FocusLineOn8LineDisplay == bData_40002f14_RecentTargetCount)
			{
				bData_4000316e_FocusLineOn8LineDisplay = 1;
			}
			else
			{
				bData_4000316e_FocusLineOn8LineDisplay++;
			}
			//->0x5ca8c
			break;
		
		case 500:
			//0x5b2c0: Main Screen Help Pages
			lcd_display_clear();
		
			if (bData_40002c59_MainScreenHelpPage == 10)
			{
				bData_40002c59_MainScreenHelpPage = 1;
			}
			else
			{
				bData_40002c59_MainScreenHelpPage++;
			}
			//->0x5ca8c
			break;
			
		case MENU_CONTEXT_ALIGNMENT: //1000:
			//0x5b300: Telescope Align
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION; //2000;
			//->0x5ca8c
			break;
		
		case MENU_CONTEXT_NAVIGATION: //2000:
			//0x5b314
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES; //3000;
			break;
		
		case MENU_CONTEXT_UTILITIES: //3000:
			//0x5b328
			Data_40002c64_MenuContextId = MENU_CONTEXT_SETUP; //4000;
			break;
		
		case MENU_CONTEXT_SETUP: //4000:
			//0x5b33c
			Data_40002c64_MenuContextId = 1000;
			break;
		
		case MENU_CONTEXT_ONE_STAR_ALIGN: //1100:
			//0x5b350: One Star Align
			HandleLongListScroll(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TWO_STAR_ALIGN; //1200;
			break;
		
		case MENU_CONTEXT_TWO_STAR_ALIGN: //1200:
			//0x5b370: Two Star Align
			HandleLongListScroll(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_THREE_STAR_ALIGN; //1300;
			break;
		
		case MENU_CONTEXT_THREE_STAR_ALIGN: //1300:
			//0x5b390: Three Star Align
			HandleLongListScroll(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TARGET_SYNC; //1400;
			break;
		
		case MENU_CONTEXT_TARGET_SYNC: //1400:
			//0x5b3b0: Target Sync
			HandleLongListScroll(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_POLE_AXIS_DEV; //1500;
			break;
		
		case MENU_CONTEXT_POLE_AXIS_DEV: //1500:
			//0x5b3d0: Pole-Axis Dev.
			HandleLongListScroll(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR; //1600;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR: //1600:
			//0x5b3f0: RA Bklash Corr.
			HandleLongListScroll(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKLASH_CORR; //1700;
			break;
		
		case MENU_CONTEXT_DEC_BKLASH_CORR: //1700:
			//0x5b410: DEC Bklash Correction
			g_bAlignmentFourLineMenuFocusItem = 1;
			g_bAlignmentFourLineMenuTopItem = 1;
			g_bAlignmentEightLineMenuFocusItem = 1;
			g_bAlignmentEightLineMenuTopItem = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_ONE_STAR_ALIGN; //1100;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM: //2100:
			//0x5b448
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CONSTELLATION; //2200;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CONSTELLATION: //2200:
			//0x5b468
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_FAMOUS_STAR; //2300;
			break;
		
		case MENU_CONTEXT_NAVIGATION_FAMOUS_STAR: //2300:
			//0x5b488
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_MESSIER_CAT; //2400;
			break;
		
		case MENU_CONTEXT_NAVIGATION_MESSIER_CAT: //2400:
			//0x5b4a8
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_NGC_CAT; //2500;
			break;
		
		case MENU_CONTEXT_NAVIGATION_NGC_CAT: //2500:
			//0x5b4c8
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_IC_CAT; //2600;
			break;
		
		case MENU_CONTEXT_NAVIGATION_IC_CAT: //2600:
			//0x5b4e8
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SH2_CAT; //2700;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SH2_CAT: //2700:
			//0x5b508
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_BRIGHT_STAR; //2800;
			break;
		
		case MENU_CONTEXT_NAVIGATION_BRIGHT_STAR: //2800:
			//0x5b528
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SAO_CAT; //2900;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SAO_CAT: //2900:
			//0x5b548
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_OBJ: //2110:
			//0x5b568
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_RA_DEC; //2120;
			break;
		
		case MENU_CONTEXT_NAVIGATION_RA_DEC: //2120:
			//0x5b588
			HandleLongListScroll(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_LAND; //2130;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_LAND: //2130:
			//0x5b5a8
			bData_40003177 = 1;
			bData_40003175 = 1;
			bData_40003176 = 1;
			bData_40003174 = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM; //2100;
			break;
		
		case MENU_CONTEXT_CURRENT_OBJECTS: //3100:
			//0x5b5e0
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_OBJECT_RISE_SET; //3200;
			break;
		
		case MENU_CONTEXT_OBJECT_RISE_SET: //3200:
			//0x5b600
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LUNAR_PHASE; //3300;
			break;
		
		case MENU_CONTEXT_LUNAR_PHASE: //3300:
			//0x5b620
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIMER; //3400;
			break;
		
		case MENU_CONTEXT_TIMER: //3400:
			//0x5b640
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALARM; //3500;
			break;
		
		case MENU_CONTEXT_ALARM: //3500:
			//0x5b660
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV; //3600;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV: //3600:
			//0x5b680
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_MAGN; //3700;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN: //3700:
			//0x5b6a0
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION; //3800;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION: //3800:
			//0x5b6c0
			HandleLongListScroll(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_PARK_POSITION; //3900;
			break;
		
		case MENU_CONTEXT_PARK_POSITION: //3900:
			//0x5b6e0
			bData_4000317b = 1;
			bData_40003179 = 1;
			bData_4000317a = 1;
			bData_40003178 = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CURRENT_OBJECTS; //3100;
			break;
		
		case MENU_CONTEXT_TIME_DATE: //4100:
			//0x5b718
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING; //4200;
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING: //4200:
			//0x5b738
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_SITE_SETTING; //4300;
			break;
		
		case MENU_CONTEXT_SITE_SETTING: //4300:
			//0x5b758
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_SKY_LAND; //4400;
			break;
		
		case MENU_CONTEXT_SKY_LAND: //4400:
			//0x5b778
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_AZ_EQU; //4500;
			break;
		
		case MENU_CONTEXT_AZ_EQU: //4500:
			//0x5b798
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TELESCOPE_MOUNT; //4600;
			break;
		
		case MENU_CONTEXT_TELESCOPE_MOUNT: //4600:
			//0x5b7b8
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE; //4700;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE: //4700:
			//0x5b7d8
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LANGUAGE; //4800;
			break;
		
		case MENU_CONTEXT_LANGUAGE: //4800:
			//0x5b7f8
			HandleLongListScroll(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_RESET; //4900;
			break;
		
		case MENU_CONTEXT_RESET: //4900:
			//0x5b818
			bData_4000317f = 1;
			bData_4000317d = 1;
			bData_4000317e = 1;
			bData_4000317c = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE; //4100;
			break;
		
		case MENU_CONTEXT_SYNC_ENSURE: //1402:
			//0x5b850
			Data_40002c64_MenuContextId = MENU_CONTEXT_SYNC_CANCEL; //1403;
			break;
		
		case MENU_CONTEXT_SYNC_CANCEL: //1403:
			//0x5b864
			Data_40002c64_MenuContextId = MENU_CONTEXT_SYNC_ENSURE; //1402;
			break;
		
		case 22011:
			//0x5b878
			bData_40003182 = 1;
			bData_40003180 = 1;
			Data_40002c64_MenuContextId = 2201;
			break;
		
		case 2301:
			//0x5b8a0
			HandleLongListScroll(1, 23);
			Data_40002c64_MenuContextId = 2302;
			break;
		
		case 2302:
			//0x5b8c0
			HandleLongListScroll(1, 23);
			Data_40002c64_MenuContextId = 2303;
			break;
		
		case 2303:
			//0x5b8e0
			HandleLongListScroll(1, 23);
			Data_40002c64_MenuContextId = 2304;
			break;
		
		case 2304:
			//0x5b900
			HandleLongListScroll(1, 23);
			Data_40002c64_MenuContextId = 2305;
			break;
		
		case 2305:
			//0x5b920
			HandleLongListScroll(1, 23);
			Data_40002c64_MenuContextId = 2306;
			break;
		
		case 2306:
			//0x5b940
			HandleLongListScroll(1, 23);
			Data_40002c64_MenuContextId = 2307;
			break;
		
		case 2307:
			//0x5b960
			HandleLongListScroll(1, 23);
			Data_40002c64_MenuContextId = 2308;
			break;
		
		case 2308:
			//0x5b980
			bData_40003186 = 1;
			bData_40003184 = 1;
			Data_40002c64_MenuContextId = 2301;
			break;
		
		case 2501:
			//0x5b9a8
			Data_40002c64_MenuContextId = 2502;
			break;
		
		case 2502:
			//0x5b9bc
			Data_40002c64_MenuContextId = 2503;
			break;
		
		case 2503:
			//0x5b9d0
			Data_40002c64_MenuContextId = 2501;
			break;
		
		case 2801:
			//0x5b9e4
			Data_40002c64_MenuContextId = 2802;
			break;
		
		case 2802:
			//0x5b9f8
			Data_40002c64_MenuContextId = 2803;
			break;
		
		case 2803:
			//0x5ba0c
			Data_40002c64_MenuContextId = 2804;
			break;
		
		case 2804:
			//0x5ba20
			Data_40002c64_MenuContextId = 2801;
			break;
		
		case 21101:
			//0x5ba34
			Data_40002c64_MenuContextId = 21102;
			break;
		
		case 21102:
			//0x5ba48
			Data_40002c64_MenuContextId = 21103;
			break;
		
		case 21103:
			//0x5ba5c
			Data_40002c64_MenuContextId = 21101;
			break;
		
		case 3601:
			//0x5ba70
			Data_40002c64_MenuContextId = 3602;
			break;
		
		case 3602:
			//0x5ba84
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 3801:
			//0x5ba98
			Data_40002c64_MenuContextId = 3802;
			break;
		
		case 3802:
			//0x5baac
			Data_40002c64_MenuContextId = 3801;
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY: //4301:
			//0x5bbc0
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOM_SITE; //4302;
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE: //4302:
			//0x5bbd4
			Data_40002c64_MenuContextId = MENU_CONTEXT_COUNTRY_CITY; //4301;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_STAR_SPEED: //4801:
			//0x5bbe8: Tracking Rate -> "Star Speed"
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED; //4802;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED: //4802:
			//0x5bbfc -> "Solar Speed"
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_MOON_SPEED; //4803;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_MOON_SPEED: //4803:
			//0x5bc10 -> "Moon Speed"
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED; //4804;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED: //4804:
			//0x5bc24 -> "Customize Speed"
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED; //4805;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED: //4805:
			//0x5bc38 -> "Guiding Speed"
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_STAR_SPEED; //4801;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED1: //48051:
			//0x5bc4c
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED2; //48052;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED2: //48052:
			//0x5bc60
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED3; //48053;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED3: //48053:
			//0x5bc74
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED4; //48054;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED4: //48054:
			//0x5bc88
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED5; //48055;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED5: //48055:
			//0x5bc9c
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED6; //48056;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED6: //48056:
			//0x5bcb0
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED7; //48057;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED7: //48057:
			//0x5bcc4
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED8; //48058;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED8: //48058:
			//0x5bcd8
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED1; //48051;
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x5bcec
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x5bcf4
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x5bcf8
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x5bcfc
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x5bd00
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x5bd04
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x5bd08
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x5bd0c
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x5bd10
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x5bd14
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x5bd18
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			//0x5bd1c
			if (g_bLandTarget == 0)
			{
				//5bd2c
				if ((Data_40004128.bTrackingActive != 0) &&
					(g_bSlewingStop != 1))
				{
					//5bd4c
					g_iSlewStepDecAxis = -1;
					bData_40003201 = 0;
				}
				else
				{
					//0x5bd68
					if (g_bMountType == 1)
					{
						//5bd78
						SlewAxis(2, 2, g_eSlewRateIndex);
					}
					else
					{
						//0x5bd90
						SlewAxis(4, 2, g_eSlewRateIndex);
					}
				}
			}
			else
			{
				//0x5bda8
				if (g_bMountType == 1)
				{
					//5bdb8
					SlewAxis(2, 2, g_eSlewRateIndex);
				}
				else
				{
					//0x5bdd0
					SlewAxis(4, 2, g_eSlewRateIndex);
				}
			}
			//->0x5ca8c
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN: //11201:
			//0x5bde8
			dData_40002e00 = dData_40002df8;
			if (g_bMountType == 1)
			{
				//5be0c
				SlewAxis(2, 2, SLEW_RATE_8X);
				bData_40002edd = 3;
			}
			else
			{
				//0x5be2c
				SlewAxis(4, 2, SLEW_RATE_8X);
				bData_40002edd = 1;
			}
			iBacklashCorrectionSlewing = 1;
			bDecBacklashCorrectionDirection = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN; //11203;
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
			//0x5be6c
			if (bDecBacklashCorrectionDirection == 2)
			{
				if (g_bMountType == 1)
				{
					//5be90
					SlewAxis(2, 2, SLEW_RATE_8X);
				}
				else
				{
					//0x5bea4
					SlewAxis(4, 2, SLEW_RATE_8X);
				}
			}
			//5beb4 -> 0x5ca8c
			break;
		
		case MENU_CONTEXT_SKY_TARGET: //45001:
			//0x5beb8
			Data_40002c64_MenuContextId = MENU_CONTEXT_LAND_TARGET; //45002;
			break;
		
		case MENU_CONTEXT_LAND_TARGET: //45002:
			//0x5becc
			Data_40002c64_MenuContextId = MENU_CONTEXT_SKY_TARGET; //45001;
			break;
		
		case MENU_CONTEXT_MOUNT_AZ: //46001:
			//0x5bee0
			Data_40002c64_MenuContextId = MENU_CONTEXT_MOUNT_EQU; //46002;
			break;
		
		case MENU_CONTEXT_MOUNT_EQU: //46002:
			//0x5bef4
			Data_40002c64_MenuContextId = MENU_CONTEXT_MOUNT_AZ; //46001;
			break;
		
		case MENU_CONTEXT_ENGLISH: //49001:
			//0x5bf08: Language -> English
			Data_40002c64_MenuContextId = MENU_CONTEXT_GERMAN; //49002;
			break;
		
		case MENU_CONTEXT_GERMAN: //49002:
			//0x5bf1c
			Data_40002c64_MenuContextId = MENU_CONTEXT_FRENCH; //49003;
			break;
		
		case MENU_CONTEXT_FRENCH: //49003:
			//0x5bf30
			Data_40002c64_MenuContextId = MENU_CONTEXT_ITALIAN; //49004;
			break;
		
		case MENU_CONTEXT_ITALIAN: //49004:
			//0x5bf44
			Data_40002c64_MenuContextId = MENU_CONTEXT_SPANISH; //49005;
			break;
		
		case MENU_CONTEXT_SPANISH: //49005:
			//0x5bf58
			Data_40002c64_MenuContextId = MENU_CONTEXT_ENGLISH; //49001;
			break;
		
		case 21001:
			//0x5bf6c
			if ((bData_40003161 - 1) == bData_40002eb4)
			{
				bData_40002eb4 = 0;
			}
			else
			{
				bData_40002eb4++;
			}
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
			//0x5bfb4: Navigation -> Solar System
			lcd_display_clear();
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJ_RISE_SET_TIMES: //31001:
			//0x5bfc0
			bData_40002eb5_SolarSystemObjectNr++;
			if (bData_40002eb5_SolarSystemObjectNr > 9)
			{
				bData_40002eb5_SolarSystemObjectNr = 0;
			}
			break;
		
		case MENU_CONTEXT_CONSTELLATION_SELECTION: //24001:
			//0x5bff4: Navigation - Constellation
			lcd_display_clear();
		
			bData_40002ece_ConstellationNr++;
			if (bData_40002ece_ConstellationNr > 88)
			{
				bData_40002ece_ConstellationNr = 1;
			}
			break;
		
		case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
			//0x5c030
			lcd_display_clear();
		
			bData_40002ed2_FamousStarNr++;
			if (bData_40002ed2_FamousStarNr > 33)
			{
				bData_40002ed2_FamousStarNr = 1;
			}
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
			//0x5c06c
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//0x5c074
			lcd_display_clear();
		
			wData_40002eb8_MessierNr++;
			if (wData_40002eb8_MessierNr > 110)
			{
				wData_40002eb8_MessierNr = 1;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//0x5c0b0
			lcd_display_clear();
		
			wData_40002eba_NGCNr++;
			if (wData_40002eba_NGCNr > 7840)
			{
				wData_40002eba_NGCNr = 1;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//0x5c0f4
			lcd_display_clear();
		
			wData_40002ebc_ICNr++;
			if (wData_40002ebc_ICNr > 5386)
			{
				wData_40002ebc_ICNr = 1;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//0x5c138
			lcd_display_clear();
		
			wData_40002ebe_ShNr++;
			if (wData_40002ebe_ShNr > 313)
			{
				wData_40002ebe_ShNr = 1;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//0x5c17c
			lcd_display_clear();
		
			wData_40002ec0_BrightStarNr++;
			if (wData_40002ec0_BrightStarNr > 167)
			{
				wData_40002ec0_BrightStarNr = 1;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x5c1bc
			lcd_display_clear();
		
			Data_40002ec4_SAONr++;
			if (Data_40002ec4_SAONr > 258997)
			{
				Data_40002ec4_SAONr = 1;
			}
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x5c1fc
			bCharacterInputPosition = 6;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT; //204;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x5c21c
			bCharacterInputPosition = 5;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT; //205;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x5c23c
			bCharacterInputPosition = 6;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT; //203;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x5c25c
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//0x5c264
		case 101:
			//0x5c268
			switch (bData_4000319a_SkyLandTargetId)
			{
				case 1:
					//0x5c2a4
					bData_4000319a_SkyLandTargetId = 4;
					break;

				case 4:
					//0x5c2b8
					bData_4000319a_SkyLandTargetId = 7;
					break;

				case 7:
					//0x5c2cc
					bData_4000319a_SkyLandTargetId = 1;
					break;
				
				case 2:
					//0x5c2e0
					bData_4000319a_SkyLandTargetId = 5;
					break;

				case 5:
					//0x5c2f4
					bData_4000319a_SkyLandTargetId = 8;
					break;

				case 8:
					//0x5c308
					bData_4000319a_SkyLandTargetId = 2;
					break;
				
				case 3:
					//0x5c31c
					bData_4000319a_SkyLandTargetId = 6;
					break;
				
				case 6:
					//0x5c330
					bData_4000319a_SkyLandTargetId = 9;
					break;
				
				case 9:
					//0x5c344
					bData_4000319a_SkyLandTargetId = 3;
					break;
				#if 0
				default:
					//0x5c358
					break;
				#endif
			}
			break;
			
		case MENU_CONTEXT_RA_INPUT: //29001:
			//0x5c360
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_INPUT; //29002;
			bCharacterInputPosition = 5;
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
			//0x5c380
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_INPUT; //29001;
			bCharacterInputPosition = 6;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x5c3a0
			bCharacterInputPosition = 5;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT; //207;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x5c3c0
			bCharacterInputPosition = 5;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT; //208;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x5c3e0
			bCharacterInputPosition = 6;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT; //206;
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//0x5c400
			if (bDateTimeInputMode == 0)
			{
				bDateTimeInputMode = 1;
			}
			else
			{
				bDateTimeInputMode = 0;
			}			
			bCharacterInputPosition = 1;
			break;
		
		case 43021:
			//0x5c440
			Data_40002c64_MenuContextId = 43022;
			break;
		
		case 43022:
			//0x5c454
			Data_40002c64_MenuContextId = 43023;
			break;
		
		case 43023:
			//0x5c468
			Data_40002c64_MenuContextId = 43024;
			break;
		
		case 43024:
			//0x5c47c
			Data_40002c64_MenuContextId = 43021;
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x5c490
			if (bCurrentCustomSiteInputLine == 3)
			{
				bCurrentCustomSiteInputLine = 0;
				bCharacterInputPosition = 7;
			}
			else
			{
				bCurrentCustomSiteInputLine++;
				bCharacterInputPosition = 7;
			}			
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x5c4e4
			Data_40002c64_MenuContextId = MENU_CONTEXT_OTA_ZERO_SETUP; //47011;
			if (bData_4000316d < 1)
			{
				bData_4000316d++;
			}
			else
			{
				bData_4000316d = 0;
			}
			if (bData_4000316d == 0)
			{
				bCharacterInputPosition = 5;
			}
			else
			{
				bCharacterInputPosition = 6;
			}
			break;
		
		case 33001:
			//0x5c558: Curr. Lunar Phase
			Data_40003164_LunarPhaseYear++;
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x5c674
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				g_iSlewStepDecAxis = -1;
				bData_40003201 = 0;
			}
			else
			{
				//0x5c6a4
				if (bData_40002c60_CurrentAlignStarIndex == numVisibleAlignmentStars)
				{
					bData_40002c60_CurrentAlignStarIndex = 1;
				}
				else
				{
					bData_40002c60_CurrentAlignStarIndex++;
				}
			}
			
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
			//0x5c6e4
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT; //360022;
			bCharacterInputPosition = 7;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
			//0x5c704
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT; //360021;
			bCharacterInputPosition = 7;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//0x5c724
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT; //370022;
			bCharacterInputPosition = 7;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV_INPUT; //370023;
			bCharacterInputPosition = 7;
			//0x5c744
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT; //370021;
			bCharacterInputPosition = 7;
			//0x5c764
			break;
		
		case 360111:
			//0x5c784
			Data_40002c64_MenuContextId = 360112;
			break;
		
		case 360112:
			//0x5c798
			Data_40002c64_MenuContextId = 360113;
			break;
		
		case 360113:
			//0x5c7ac
			Data_40002c64_MenuContextId = 360111;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL: //380011:
			//0x5c7c0
			if (Data_40003248_CurrentDisplayPWM == 255)
			{
				setDisplayPWM(191);
				Data_40003248_CurrentDisplayPWM = 191;
			}
			else if (Data_40003248_CurrentDisplayPWM == 191)
			{
				setDisplayPWM(127);
				Data_40003248_CurrentDisplayPWM = 127;
			}
			else if (Data_40003248_CurrentDisplayPWM == 127)
			{
				setDisplayPWM(63);
				Data_40003248_CurrentDisplayPWM = 63;
			}
			else
			{
				setDisplayPWM(0);
				Data_40003248_CurrentDisplayPWM = 0;
			}
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x5c854
			lcd_display_clear();
			func_59dd0(); //->Next country
			break;
		
		case 211001:
			//0x5c864
			switch (bData_40003262)
			{
				case 0:
					//0x5c88c
				case 2:
					//0x5c894
					if ((bData_40003258-1) == bData_4000325c)
					{
						bData_4000325c = 0;
					}
					else
					{
						bData_4000325c++;
					}
					//->0x5c934
					break;

				case 1:
					//0x5c8d8
					if (bData_40003261 == 2)
					{
						bData_40003261 = 0;
						bCharacterInputPosition = 7;
					}
					else
					{
						//0x5c908
						bData_40003261++;
						bCharacterInputPosition = 7;
					}
					break;

				default:
					break;
			}
			break;
		
		case 28001:
			//0x5c93c
			switch (bData_40003263)
			{
				case 0:
					//0x5c96c
				case 2:
					//0x5c974
					if ((wData_40003256 - 1) == wData_4000325a)
					{
						wData_4000325a = 0;
					}
					else
					{
						wData_4000325a++;
					}
					break;
								
				case 1:
					//0x5c9bc
				case 3:
					//0x5c9c4
					if (bData_40003260 == 2)
					{
						bData_40003260 = 0;
						bCharacterInputPosition = 7;
					}
					else
					{
						bData_40003260++;
						bCharacterInputPosition = 7;
					}
					break;

				default:
					break;
			}
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_ON: //42001:
			//0x5ca24
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_OFF; //42002;
				bDaylightSavingTime = 0;
			}
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_OFF: //42002:
			//0x5ca54
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_ON; //42001;
				bDaylightSavingTime = 1;
			}
			break;
			
		default:
			break;
	}
}

