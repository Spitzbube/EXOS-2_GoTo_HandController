
//#include "menu.h"

/* 5ab50 - todo */
void HandleDownKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 1:
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
			func_5a57c(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TWO_STAR_ALIGN; //1200;
			break;
		
		case MENU_CONTEXT_TWO_STAR_ALIGN: //1200:
			//0x5b370: Two Star Align
			func_5a57c(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_THREE_STAR_ALIGN; //1300;
			break;
		
		case MENU_CONTEXT_THREE_STAR_ALIGN: //1300:
			//0x5b390: Three Star Align
			func_5a57c(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TARGET_SYNC; //1400;
			break;
		
		case MENU_CONTEXT_TARGET_SYNC: //1400:
			//0x5b3b0: Target Sync
			func_5a57c(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_POLE_AXIS_DEV; //1500;
			break;
		
		case MENU_CONTEXT_POLE_AXIS_DEV: //1500:
			//0x5b3d0: Pole-Axis Dev.
			func_5a57c(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR; //1600;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR: //1600:
			//0x5b3f0: RA Bklash Corr.
			func_5a57c(1, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKLASH_CORR; //1700;
			break;
		
		case MENU_CONTEXT_DEC_BKLASH_CORR: //1700:
			//0x5b410: DEC Bklash Correction
			bData_40003173 = 1;
			bData_40003171 = 1;
			bData_40003172 = 1;
			bData_40003170 = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_ONE_STAR_ALIGN; //1100;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM: //2100:
			//0x5b448
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CONSTELLATION; //2200;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CONSTELLATION: //2200:
			//0x5b468
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_FAMOUS_STAR; //2300;
			break;
		
		case MENU_CONTEXT_NAVIGATION_FAMOUS_STAR: //2300:
			//0x5b488
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_MESSIER_CAT; //2400;
			break;
		
		case MENU_CONTEXT_NAVIGATION_MESSIER_CAT: //2400:
			//0x5b4a8
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_NGC_CAT; //2500;
			break;
		
		case MENU_CONTEXT_NAVIGATION_NGC_CAT: //2500:
			//0x5b4c8
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_IC_CAT; //2600;
			break;
		
		case MENU_CONTEXT_NAVIGATION_IC_CAT: //2600:
			//0x5b4e8
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SH2_CAT; //2700;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SH2_CAT: //2700:
			//0x5b508
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_BRIGHT_STAR; //2800;
			break;
		
		case MENU_CONTEXT_NAVIGATION_BRIGHT_STAR: //2800:
			//0x5b528
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SAO_CAT; //2900;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SAO_CAT: //2900:
			//0x5b548
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; 2110;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_OBJ: //2110:
			//0x5b568
			func_5a57c(1, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_RA_DEC; //2120;
			break;
		
		case MENU_CONTEXT_NAVIGATION_RA_DEC: //2120:
			//0x5b588
			func_5a57c(1, 12);
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
			func_5a57c(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_OBJECT_RISE_SET; //3200;
			break;
		
		case MENU_CONTEXT_OBJECT_RISE_SET: //3200:
			//0x5b600
			func_5a57c(1, 13);
			Data_40002c64_MenuContextId = 3300;
			break;
		
		case 3300:
			//0x5b620
			func_5a57c(1, 13);
			Data_40002c64_MenuContextId = 3400;
			break;
		
		case 3400:
			//0x5b640
			func_5a57c(1, 13);
			Data_40002c64_MenuContextId = 3500;
			break;
		
		case 3500:
			//0x5b660
			func_5a57c(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV; //3600;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV: //3600:
			//0x5b680
			func_5a57c(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_MAGN; //3700;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN: //3700:
			//0x5b6a0
			func_5a57c(1, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION; //3800;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION: //3800:
			//0x5b6c0
			func_5a57c(1, 13);
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
			func_5a57c(1, 14);
			Data_40002c64_MenuContextId = 4200;
			break;
		
		case 4200:
			//0x5b738
			func_5a57c(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_SITE_SETTING; //4300;
			break;
		
		case MENU_CONTEXT_SITE_SETTING: //4300:
			//0x5b758
			func_5a57c(1, 14);
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case 4400:
			//0x5b778
			func_5a57c(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_AZ_EQU; //4500;
			break;
		
		case MENU_CONTEXT_AZ_EQU: //4500:
			//0x5b798
			func_5a57c(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TELESCOPE_MOUNT; //4600;
			break;
		
		case MENU_CONTEXT_TELESCOPE_MOUNT: //4600:
			//0x5b7b8
			func_5a57c(1, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE; //4700;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE: //4700:
			//0x5b7d8
			func_5a57c(1, 14);
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 4800:
			//0x5b7f8
			func_5a57c(1, 14);
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
		
		case 1402:
			//0x5b850
			Data_40002c64_MenuContextId = 1403;
			break;
		
		case 1403:
			//0x5b864
			Data_40002c64_MenuContextId = 1402;
			break;
		
		case 22011:
			//0x5b878
			bData_40003182 = 1;
			bData_40003180 = 1;
			Data_40002c64_MenuContextId = 2201;
			break;
		
		case 2301:
			//0x5b8a0
			Data_40002c64_MenuContextId = 2302;
			break;
		
		case 2302:
			//0x5b8c0
			Data_40002c64_MenuContextId = 2303;
			break;
		
		case 2303:
			//0x5b8e0
			func_5a57c(1, 23);
			Data_40002c64_MenuContextId = 2304;
			break;
		
		case 2304:
			//0x5b900
			func_5a57c(1, 23);
			Data_40002c64_MenuContextId = 2305;
			break;
		
		case 2305:
			//0x5b920
			func_5a57c(1, 23);
			Data_40002c64_MenuContextId = 2306;
			break;
		
		case 2306:
			//0x5b940
			func_5a57c(1, 23);
			Data_40002c64_MenuContextId = 2307;
			break;
		
		case 2307:
			//0x5b960
			func_5a57c(1, 23);
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
		
		case 4801:
			//0x5bbe8: Tracking Rate -> "Star Speed"
			Data_40002c64_MenuContextId = 4802;
			break;
		
		case 4802:
			//0x5bbfc -> "Solar Speed"
			Data_40002c64_MenuContextId = 4803;
			break;
		
		case 4803:
			//0x5bc10 -> "Moon Speed"
			Data_40002c64_MenuContextId = 4804;
			break;
		
		case 4804:
			//0x5bc24 -> "Customize Speed"
			Data_40002c64_MenuContextId = 4805;
			break;
		
		case 4805:
			//0x5bc38 -> "Guiding Speed"
			Data_40002c64_MenuContextId = 4801;
			break;
		
		case 48051:
			//0x5bc4c
			Data_40002c64_MenuContextId = 48052;
			break;
		
		case 48052:
			//0x5bc60
			Data_40002c64_MenuContextId = 48053;
			break;
		
		case 48053:
			//0x5bc74
			Data_40002c64_MenuContextId = 48054;
			break;
		
		case 48054:
			//0x5bc88
			Data_40002c64_MenuContextId = 48055;
			break;
		
		case 48055:
			//0x5bc9c
			Data_40002c64_MenuContextId = 48056;
			break;
		
		case 48056:
			//0x5bcb0
			Data_40002c64_MenuContextId = 48057;
			break;
		
		case 48057:
			//0x5bcc4
			Data_40002c64_MenuContextId = 48058;
			break;
		
		case 48058:
			//0x5bcd8
			Data_40002c64_MenuContextId = 48051;
			break;
		
		case 0:
			//0x5bcec
		case 11102:
			//0x5bcf4
		case 11202:
			//0x5bcf8
		case 22111:
			//0x5bcfc
		case 24002:
			//0x5bd00
		case 25002:
			//0x5bd04
		case 23022:
			//0x5bd08
		case 23013:
			//0x5bd0c
		case 23014:
			//0x5bd10
		case 23015:
			//0x5bd14
		case 23016:
			//0x5bd18
		case 23017:
			//0x5bd1c
			if (bData_400034a9 == 0)
			{
				//5bd2c
				if ((Data_40004128.bData_356 != 0) &&
					(bData_40002e89 != 1))
				{
					//5bd4c
					Data_4000340c = -1;
					bData_40003201 = 0;
				}
				else
				{
					//0x5bd68
					if (bData_40002c1a == 1)
					{
						//5bd78
						func_57414(2, 2, bData_40002e7d_RotatingSpeed);
					}
					else
					{
						//0x5bd90
						func_57414(4, 2, bData_40002e7d_RotatingSpeed);
					}
				}
			}
			else
			{
				//0x5bda8
				if (bData_40002c1a == 1)
				{
					//5bdb8
					func_57414(2, 2, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x5bdd0
					func_57414(4, 2, bData_40002e7d_RotatingSpeed);
				}
			}
			//->0x5ca8c
			break;
		
		case 11201:
			//0x5bde8
			dData_40002e00 = dData_40002df8;
			if (bData_40002c1a == 1)
			{
				//5be0c
				func_57414(2, 2, 3);
				bData_40002edd = 3;
			}
			else
			{
				//0x5be2c
				func_57414(4, 2, 3);
				bData_40002edd = 1;
			}
			Data_40002eb0 = 1;
			bData_40003189 = 1;
			Data_40002c64_MenuContextId = 11203;
			break;
		
		case 11203:
			//0x5be6c
			if (bData_40003189 == 2)
			{
				if (bData_40002c1a == 1)
				{
					//5be90
					func_57414(2, 2, 3);
				}
				else
				{
					//0x5bea4
					func_57414(4, 2, 3);
				}
			}
			//5beb4 -> 0x5ca8c
			break;
		
		case 45001:
			//0x5beb8
			Data_40002c64_MenuContextId = 45002;
			break;
		
		case 45002:
			//0x5becc
			Data_40002c64_MenuContextId = 45001;
			break;
		
		case MENU_CONTEXT_MOUNT_AZ: //46001:
			//0x5bee0
			Data_40002c64_MenuContextId = MENU_CONTEXT_MOUNT_EQU; //46002;
			break;
		
		case MENU_CONTEXT_MOUNT_EQU: //46002:
			//0x5bef4
			Data_40002c64_MenuContextId = MENU_CONTEXT_MOUNT_AZ; //46001;
			break;
		
		case 49001:
			//0x5bf08: Language -> English
			Data_40002c64_MenuContextId = 49002;
			break;
		
		case 49002:
			//0x5bf1c
			Data_40002c64_MenuContextId = 49003;
			break;
		
		case 49003:
			//0x5bf30
			Data_40002c64_MenuContextId = 49004;
			break;
		
		case 49004:
			//0x5bf44
			Data_40002c64_MenuContextId = 49005;
			break;
		
		case 49005:
			//0x5bf58
			Data_40002c64_MenuContextId = 49001;
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
		
		case 22001:
			//0x5bfb4: Navigation -> Solar System
			lcd_display_clear();
		case 31001:
			//0x5bfc0
			bData_40002eb5_SolarSystemObjectNr++;
			if (bData_40002eb5_SolarSystemObjectNr > 9)
			{
				bData_40002eb5_SolarSystemObjectNr = 0;
			}
			break;
		
		case 24001:
			//0x5bff4: Navigation - Constellation
			lcd_display_clear();
		
			bData_40002ece_ConstellationNr++;
			if (bData_40002ece_ConstellationNr > 88)
			{
				bData_40002ece_ConstellationNr = 1;
			}
			break;
		
		case 25001:
			//0x5c030
			lcd_display_clear();
		
			bData_40002ed2_FamousStarNr++;
			if (bData_40002ed2_FamousStarNr > 33)
			{
				bData_40002ed2_FamousStarNr = 1;
			}
			break;
		
		case 23012:
			//0x5c06c
		case 23002:
			//0x5c074
			lcd_display_clear();
		
			wData_40002eb8_MessierNr++;
			if (wData_40002eb8_MessierNr > 110)
			{
				wData_40002eb8_MessierNr = 1;
			}
			break;
		
		case 23003:
			//0x5c0b0
			lcd_display_clear();
		
			wData_40002eba_NGCNr++;
			if (wData_40002eba_NGCNr > 7840)
			{
				wData_40002eba_NGCNr = 1;
			}
			break;
		
		case 23004:
			//0x5c0f4
			lcd_display_clear();
		
			wData_40002ebc_ICNr++;
			if (wData_40002ebc_ICNr > 5386)
			{
				wData_40002ebc_ICNr = 1;
			}
			break;
		
		case 23005:
			//0x5c138
			lcd_display_clear();
		
			wData_40002ebe_ShNr++;
			if (wData_40002ebe_ShNr > 313)
			{
				wData_40002ebe_ShNr = 1;
			}
			break;
		
		case 23006:
			//0x5c17c
			lcd_display_clear();
		
			wData_40002ec0++;
			if (wData_40002ec0 > 167)
			{
				wData_40002ec0 = 1;
			}
			break;
		
		case 23007:
			//0x5c1bc
			lcd_display_clear();
		
			Data_40002ec4_SAONr++;
			if (Data_40002ec4_SAONr > 258997)
			{
				Data_40002ec4_SAONr = 1;
			}
			break;
		
		case 203:
			//0x5c1fc
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = 204;
			break;
		
		case 204:
			//0x5c21c
			bData_4000318a = 5;
			Data_40002c64_MenuContextId = 205;
			break;
		
		case 205:
			//0x5c23c
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = 203;
			break;
		
		case 201:
			//0x5c25c
		case 202:
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
			
		case 29001:
			//0x5c360
			Data_40002c64_MenuContextId = 29002;
			bData_4000318a = 5;
			break;
		
		case 29002:
			//0x5c380
			Data_40002c64_MenuContextId = 29001;
			bData_4000318a = 6;
			break;
		
		case 206:
			//0x5c3a0
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = 207;
			break;
		
		case 207:
			//0x5c3c0
			bData_4000318a = 5;
			Data_40002c64_MenuContextId = 208;
			break;
		
		case 208:
			//0x5c3e0
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = 206;
			break;
		
		case 41001:
			//0x5c400
			if (bData_40002e78 == 0)
			{
				bData_40002e78 = 1;
			}
			else
			{
				bData_40002e78 = 0;
			}			
			bData_4000318a = 1;
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
			if (bData_40003144 == 3)
			{
				bData_40003144 = 0;
				bData_4000318a = 7;
			}
			else
			{
				bData_40003144++;
				bData_4000318a = 7;
			}			
			break;
		
		case 47011:
			//0x5c4e4
			Data_40002c64_MenuContextId = 47011;
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
				bData_4000318a = 5;
			}
			else
			{
				bData_4000318a = 6;
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
				Data_4000340c = -1;
				bData_40003201 = 0;
			}
			else
			{
				//0x5c6a4
				if (bData_40002c60_CurrentAlignStarIndex == bData_400034a8_CurrentAlignStarCount)
				{
					bData_40002c60_CurrentAlignStarIndex = 1;
				}
				else
				{
					bData_40002c60_CurrentAlignStarIndex++;
				}
			}
			
			break;
		
		case 360021:
			//0x5c6e4
			Data_40002c64_MenuContextId = 360022;
			bData_4000318a = 7;
			break;
		
		case 360022:
			//0x5c704
			Data_40002c64_MenuContextId = 360021;
			bData_4000318a = 7;
			break;
		
		case 370021:
			//0x5c724
			Data_40002c64_MenuContextId = 370022;
			bData_4000318a = 7;
			break;
		
		case 370022:
			Data_40002c64_MenuContextId = 370023;
			bData_4000318a = 7;
			//0x5c744
			break;
		
		case 370023:
			Data_40002c64_MenuContextId = 370021;
			bData_4000318a = 7;
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
		
		case 380011:
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
						bData_4000318a = 7;
					}
					else
					{
						//0x5c908
						bData_40003261++;
						bData_4000318a = 7;
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
						bData_4000318a = 7;
					}
					else
					{
						bData_40003260++;
						bData_4000318a = 7;
					}
					break;

				default:
					break;
			}
			break;
		
		case 42001:
			//0x5ca24
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42002;
				bData_40002c6a = 0;
			}
			break;
		
		case 42002:
			//0x5ca54
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42001;
				bData_40002c6a = 1;
			}
			break;
			
		default:
			break;
	}
}

