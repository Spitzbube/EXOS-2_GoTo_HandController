
//#include "menu.h"

/* 5ca98 - complete */
void func_5ca98(void)
{
	wData_40003252 = 0;
	
	switch (wData_40003250)
	{
		case 1:
			//0x5cd64
			wData_40003250 = 170;
			break;
		
		case 2:
			//0x5cd78
		case 3:
			//0x5cd80
			wData_40003250--;
			break;
		
		case 25:
			//0x5cd98
			wData_40003250 = 3;
			break;
		
		case 26:
			//0x5cdac
			wData_40003250 = 25;
			break;
		
		case 29:
			//0x5cdc0
			wData_40003250 = 26;
			break;
		
		case 30:
			//0x5cdd4
		case 31:
			//0x5cddc
		case 32:
			//0x5cde0
		case 33:
			//0x5cde4
		case 34:
			//0x5cde8
		case 35:
			//0x5cdec
			wData_40003250--;
			break;
		
		case 38:
			//0x5ce04
			wData_40003250 = 35;
			break;
		
		case 39:
			//0x5ce18
		case 40:
			//0x5ce20
			wData_40003250--;
			break;
		
		case 45:
			//0x5ce38
			wData_40003250 = 40;
			break;
		
		case 46:
			//0x5ce4c
		case 47:
			//0x5ce54
		case 48:
			//0x5ce58
			wData_40003250--;
			break;
		
		case 53:
			//0x5ce70
			wData_40003250 = 48;
			break;
		
		case 54:
			//0x5ce84
		case 55:
			//0x5ce8c
		case 56:
			//0x5ce90
		case 57:
			//0x5ce94
		case 58:
			//0x5ce98
		case 59:
			//0x5ce9c
		case 60:
			//0x5cea0
			wData_40003250--;
			break;
		
		case 62:
			//0x5ceb8
			wData_40003250 = 60;
			break;
		
		case 63:
			//0x5cecc
		case 64:
			//0x5ced4
			wData_40003250--;
			break;
		
		case 73:
			//0x5ceec
			wData_40003250 = 64;
			break;
		
		case 74:
			//0x5cf00
		case 75:
			//0x5cf08
		case 76:
			//0x5cf0c
		case 77:
			//0x5cf10
			wData_40003250--;
			break;
		
		case 80:
			//0x5cf28
			wData_40003250 = 77;
			break;
		
		case 81:
			//0x5cf3c
		case 82:
			//0x5cf44
			wData_40003250--;
			break;
		
		case 89:
			//0x5cf5c
			wData_40003250 = 82;
			break;
		
		case 90:
			//0x5cf70
			wData_40003250 = 89;
			break;
		
		case 92:
			//0x5cf84
			wData_40003250 = 90;
			break;
		
		case 93:
			//0x5cf98
		case 94:
			//0x5cfa0
		case 95:
			//0x5cfa4
		case 96:
			//0x5cfa8
		case 97:
			//0x5cfac
			wData_40003250--;
			break;
		
		case 99:
			//0x5cfc4
			wData_40003250 = 98;
			break;
		
		case 98:
			//0x5cfd8
			wData_40003250 = 97;
			break;
		
		case 105:
			//0x5cfec
			wData_40003250 = 99;
			break;
		
		case 106:
			//0x5d000
		case 107:
		case 108:
		case 109:
		case 110:
		case 111:
		case 112:
		case 113:
		case 114:
		case 115:
		case 116:
		case 117:
		case 118:
		case 119:
			//0x5d038
			wData_40003250--;
			break;
		
		case 121:
			//0x5d050
			wData_40003250 = 119;
			break;
		
		case 122:
			//0x5d064
		case 123:
			//0x5d06c
		case 124:
		case 125:
		case 126:
		case 127:
		case 128:
		case 129:
		case 130:
		case 131:
		case 132:
		case 133:
		case 134:
			//0x5d098
			wData_40003250--;
			break;
		
		case 143:
			//0x5d0b0
			wData_40003250 = 134;
			break;
		
		case 144:
			//0x5d0c4
		case 145:
			//0x5d0cc
		case 146:
		case 147:
		case 148:
		case 149:
		case 150:
			//0x5d0e0
			wData_40003250--;
			break;
		
		case 152:
			//0x5d0f8
			wData_40003250 = 150;
			break;
		
		case 154:
			//0x5d10c
			wData_40003250 = 152;
			break;
		
		case 155:
			//0x5d120
			wData_40003250 = 154;
			break;
		
		case 156:
			//0x5d134
			wData_40003250 = 155;
			break;
		
		case 158:
			//0x5d148
			wData_40003250 = 156;
			break;
		
		case 159:
			//0x5d15c
		case 160:
			//0x5d164
		case 161:
			//0x5d168
		case 162:
		case 163:
		case 164:
		case 165:
		case 166:
		case 167:
		case 168:
		case 169:
		case 170:
			//0x5d18c
			wData_40003250--;		
			break;
	}
}

/* 5d1ac - todo */
void HandleUpKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_RECENT_TARGETS: //1:
			//0x5d8d4
			if (bData_4000316e_FocusLineOn8LineDisplay == 1)
			{
				//5d8e8
				bData_4000316e_FocusLineOn8LineDisplay = bData_40002f14_RecentTargetCount;
			}
			else
			{
				//0x5d8fc
				bData_4000316e_FocusLineOn8LineDisplay--;
			}
			break;
		
		case 500:
			//0x5d914: Main Screen Help Pages
			lcd_display_clear();
		
			if (bData_40002c59_MainScreenHelpPage == 1)
			{
				bData_40002c59_MainScreenHelpPage = 10;
			}
			else
			{
				bData_40002c59_MainScreenHelpPage--;
			}
			//->0x5f0b4
			break;
			
		case MENU_CONTEXT_ALIGNMENT: //1000:
			//0x5d954
			Data_40002c64_MenuContextId = MENU_CONTEXT_SETUP;
			break;
		
		case MENU_CONTEXT_NAVIGATION: //2000:
			//0x5d968
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT;
			break;
		
		case MENU_CONTEXT_UTILITIES: //3000:
			//0x5d97c
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION;
			break;
		
		case MENU_CONTEXT_SETUP: //4000:
			//0x5d990
			Data_40002c64_MenuContextId = MENU_CONTEXT_UTILITIES;
			break;
		
		case MENU_CONTEXT_ONE_STAR_ALIGN: //1100:
			//0x5d9a4	
			bData_40003173 = 4;
			bData_40003171 = 4;
			bData_40003172 = 7;
			bData_40003170 = 8;
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKLASH_CORR;
			break;
			
		case MENU_CONTEXT_TWO_STAR_ALIGN: //1200:
			//0x5d9e4
			func_5a57c(0, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_ONE_STAR_ALIGN; //1100;
			//->0x5f0b4
			break;
		
		case MENU_CONTEXT_THREE_STAR_ALIGN: //1300:
			//0x5da04
			func_5a57c(0, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TWO_STAR_ALIGN; //1200;
			break;
		
		case MENU_CONTEXT_TARGET_SYNC: //1400:
			//0x5da24
			func_5a57c(0, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_THREE_STAR_ALIGN; //1300;
			break;
		
		case MENU_CONTEXT_POLE_AXIS_DEV: //1500:
			//0x5da44
			func_5a57c(0, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TARGET_SYNC; //1400;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR: //1600:
			//0x5da64
			func_5a57c(0, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_POLE_AXIS_DEV; //1500;
			break;
		
		case MENU_CONTEXT_DEC_BKLASH_CORR: //1700:
			//0x5da84
			func_5a57c(0, 11);
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR; //1600;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM: //2100:
			//0x5daa4
			bData_40003177 = 4;
			bData_40003175 = 9;
			bData_40003176 = 8;
			bData_40003174 = 5;
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_LAND; //2130
			break;
		
		case MENU_CONTEXT_NAVIGATION_CONSTELLATION: //2200:
			//0x5dae8
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM; //2100;
			break;
		
		case MENU_CONTEXT_NAVIGATION_FAMOUS_STAR: //2300:
			//0x5db08
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CONSTELLATION; //2200;
			break;
		
		case MENU_CONTEXT_NAVIGATION_MESSIER_CAT: //2400:
			//0x5db28
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_FAMOUS_STAR; //2300;
			break;
		
		case MENU_CONTEXT_NAVIGATION_NGC_CAT: //2500:
			//0x5db48
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_MESSIER_CAT; //2400;
			break;
		
		case MENU_CONTEXT_NAVIGATION_IC_CAT: //2600:
			//0x5db68
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_NGC_CAT; //2500;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SH2_CAT: //2700:
			//0x5db88
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_IC_CAT; //2600;
			break;

		case MENU_CONTEXT_NAVIGATION_BRIGHT_STAR: //2800:
			//0x5dba8
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SH2_CAT; //2700;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SAO_CAT: //2900:
			//0x5dbc8
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_BRIGHT_STAR; //2800;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_OBJ: //2110:
			//0x5dbe8
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SAO_CAT; //2900;
			break;
		
		case MENU_CONTEXT_NAVIGATION_RA_DEC: //2120:
			//0x5dc08
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_LAND: //2130:
			//0x5dc28
			func_5a57c(0, 12);
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_RA_DEC; //2120;
			break;
		
		case MENU_CONTEXT_CURRENT_OBJECTS: //3100:
			//0x5dc48
			bData_4000317b = 4;
			bData_40003179 = 6;
			bData_4000317a = 8;
			bData_40003178 = 2;
			Data_40002c64_MenuContextId = MENU_CONTEXT_PARK_POSITION; //3900;
			break;
		
		case MENU_CONTEXT_OBJECT_RISE_SET: //3200:
			//0x5dc8c
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_CURRENT_OBJECTS; //3100;
			break;
		
		case 3300:
			//0x5dcac
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_OBJECT_RISE_SET; //3200;
			break;
		
		case 3400:
			//0x5dccc
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = 3300;
			break;
		
		case 3500:
			//0x5dcec
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = 3400;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV: //3600:
			//0x5dd0c
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = 3500;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN: //3700:
			//0x5dd2c
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION: //3800:
			//0x5dd4c
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_MAGN;
			break;
		
		case MENU_CONTEXT_PARK_POSITION: //3900:
			//0x5dd6c
			func_5a57c(0, 13);
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION;
			break;
		
		case MENU_CONTEXT_TIME_DATE: //4100:
			//0x5dd8c
			bData_4000317f = 4;
			bData_4000317d = 6;
			bData_4000317e = 8;
			bData_4000317c = 2;
			Data_40002c64_MenuContextId = MENU_CONTEXT_RESET;
			break;
		
		case 4200:
			//0x5ddd0
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE;
			break;
		
		case MENU_CONTEXT_SITE_SETTING: //4300:
			//0x5ddf0
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = 4200;
			break;
		
		case 4400:
			//0x5de10
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_SITE_SETTING;
			break;
		
		case MENU_CONTEXT_AZ_EQU: //4500:
			//0x5de30
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case MENU_CONTEXT_TELESCOPE_MOUNT: //4600:
			//0x5de50
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_AZ_EQU;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE: //4700:
			//0x5de70
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TELESCOPE_MOUNT;
			break;
		
		case MENU_CONTEXT_LANGUAGE: //4800:
			//0x5de90
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE;
			break;
		
		case MENU_CONTEXT_RESET: //4900:
			//0x5deb0
			func_5a57c(0, 14);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LANGUAGE; //4800;
			break;
		
		case 1402:
			//0x5ded0
			Data_40002c64_MenuContextId = 1403;
			break;
		
		case 1403:
			//0x5dee4
			Data_40002c64_MenuContextId = 1402;
			break;
		
		case 2301:
			//0x5def8
			bData_40003182 = 8;
			bData_40003180 = 1;
			Data_40002c64_MenuContextId = 2308;
			break;
		
		case 2302:
			//0x5df24
			func_5a57c(0, 23);
			Data_40002c64_MenuContextId = 2301;
			break;
		
		case 2303:
			//0x5df44
			func_5a57c(0, 23);
			Data_40002c64_MenuContextId = 2302;
			break;
		
		case 2304:
			//0x5df64
			func_5a57c(0, 23);
			Data_40002c64_MenuContextId = 2303;
			break;
		
		case 2305:
			//0x5df84
			func_5a57c(0, 23);
			Data_40002c64_MenuContextId = 2304;
			break;
		
		case 2306:
			//0x5dfa4
			func_5a57c(0, 23);
			Data_40002c64_MenuContextId = 2305;
			break;
		
		case 2307:
			//0x5e0c4
			func_5a57c(0, 23);
			Data_40002c64_MenuContextId = 2306;
			break;
		
		case 2308:
			//0x5e0e4
			func_5a57c(0, 23);
			Data_40002c64_MenuContextId = 2307;
			break;
		
		case 2501:
			//0x5e104
			Data_40002c64_MenuContextId = 2503;
			break;
		
		case 2502:
			//0x5e118
			Data_40002c64_MenuContextId = 2501;
			break;
		
		case 2503:
			//0x5e12c
			Data_40002c64_MenuContextId = 2502;
			break;
		
		case 2801:
			//0x5e140
			Data_40002c64_MenuContextId = 2804;
			break;
		
		case 2802:
			//0x5e154
			Data_40002c64_MenuContextId = 2801;
			break;
		
		case 2803:
			//0x5e168
			Data_40002c64_MenuContextId = 2802;
			break;
		
		case 2804:
			//0x5e17c
			Data_40002c64_MenuContextId = 2803;
			break;
		
		case 21101:
			//0x5e190
			Data_40002c64_MenuContextId = 21103;
			break;
		
		case 21102:
			//0x5e1a4
			Data_40002c64_MenuContextId = 21101;
			break;
		
		case 21103:
			//0x5e1b8
			Data_40002c64_MenuContextId = 21102;
			break;
		
		case 3601:
			//0x5e1cc
			Data_40002c64_MenuContextId = 3602;
			break;
		
		case 3602:
			//0x5e1e0
			Data_40002c64_MenuContextId = 3601;
			break;
		
		case 3801:
			//0x5e1f4
			Data_40002c64_MenuContextId = 3802;
			break;
		
		case 3802:
			//0x5e208
			Data_40002c64_MenuContextId = 3801;
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY: //4301:
			//0x5e21c
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOM_SITE; //4302;
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE: //4302:
			//0x5e230
			Data_40002c64_MenuContextId = MENU_CONTEXT_COUNTRY_CITY; //4301;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_STAR_SPEED: //4801:
			//0x5e244
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED; //4805;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED: //4802:
			//0x5e258
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_STAR_SPEED; //4801;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_MOON_SPEED: //4803:
			//0x5e26c
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED; //4802;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED: //4804:
			//0x5e280
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_MOON_SPEED; //4803;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED: //4805:
			//0x5e294
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED; //4804;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED1: //48051:
			//0x5e2a8
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED8; //48058;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED2: //48052:
			//0x5e2bc
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED1; //48051;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED3: //48053:
			//0x5e2d0
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED2; //48052;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED4: //48054:
			//0x5e2e4
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED3; //48053;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED5: //48055:
			//0x5e2f8
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED4; //48054;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED6: //48056:
			//0x5e30c
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED5; //48055;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED7: //48057:
			//0x5e320
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED6; //48056;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED8: //48058:
			//0x5e334
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED7; //48057;
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x5e348
		case 11102:
			//0x5e350
		case 11202:
			//0x5e354
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x5e358
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x5e35c
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x5e360
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x5e364
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x5e368
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x5e36c
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x5e370
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x5e374
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			//0x5e378
			if (bData_400034a9 == 0)
			{
				//5e388
				if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
				{
					//5e3a8
					Data_4000340c = 1;
					bData_40003201 = 0;
				}
				else
				{
					//0x5e3c4
					if (bData_40002c1a == 1)
					{
						//5e3d4
						func_57414(2, 1, bData_40002e7d_RotatingSpeed);
					}
					else
					{
						//0x5e3ec
						func_57414(4, 1, bData_40002e7d_RotatingSpeed);
					}
				}
			}
			else
			{
				//0x5e404
				if (bData_40002c1a == 1)
				{
					//5e414
					func_57414(2, 1, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x5e42c
					func_57414(4, 1, bData_40002e7d_RotatingSpeed);
				}
			}
			//0x5e440 -> 0x5f0b4
			break;
		
		case 11201:
			//0x5e444
			dData_40002e00 = dData_40002df8;
		
			if (bData_40002c1a == 1)
			{
				//5e468
				func_57414(2, 1, MENU_ROTATING_SPEED_8);
				
				bData_40002edd = 3;
			}
			else
			{
				//0x5e488
				func_57414(4, 1, MENU_ROTATING_SPEED_8);
				
				bData_40002edd = 1;
			}
			//0x5e4a4
			Data_40002eb0 = 1;
			bData_40003189 = 2;
			Data_40002c64_MenuContextId = 11203;
			break;
		
		case 11203:
			//0x5e4cc
			if (bData_40003189 == 1)
			{
				//5e4e0
				if (bData_40002c1a == 1)
				{
					//5e414
					func_57414(2, 1, MENU_ROTATING_SPEED_8);
				}
				else
				{
					//0x5e504
					func_57414(4, 1, MENU_ROTATING_SPEED_8);
				}
			}
			//0x5e514
			break;
		
		case 45001:
			//0x5e518
			Data_40002c64_MenuContextId = 45002;
			break;
		
		case 45002:
			//0x5e52c
			Data_40002c64_MenuContextId = 45001;
			break;
		
		case 46001:
			//0x5e540
			Data_40002c64_MenuContextId = 46002;
			break;
		
		case 46002:
			//0x5e554
			Data_40002c64_MenuContextId = 46001;
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
			//0x5e568
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_INPUT; //29002;
			bData_4000318a = 5;
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
			//0x5e588
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_INPUT; //29001;
			bData_4000318a = 6;
			break;
		
		case MENU_CONTEXT_ENGLISH: //49001:
			//0x5e5a8
			Data_40002c64_MenuContextId = MENU_CONTEXT_SPANISH; //49005;
			break;
		
		case MENU_CONTEXT_SPANISH: //49005:
			//0x5e5bc
			Data_40002c64_MenuContextId = MENU_CONTEXT_ITALIAN; //49004;
			break;
		
		case MENU_CONTEXT_ITALIAN: //49004:
			//0x5e5d0
			Data_40002c64_MenuContextId = MENU_CONTEXT_FRENCH; //49003;
			break;
		
		case MENU_CONTEXT_FRENCH: //49003:
			//0x5e5e4
			Data_40002c64_MenuContextId = MENU_CONTEXT_GERMAN; //49002;
			break;
		
		case MENU_CONTEXT_GERMAN: //49002:
			//0x5e5f8
			Data_40002c64_MenuContextId = MENU_CONTEXT_ENGLISH; //49001;
			break;
		
		case 21001:
			//0x5e60c
			if (bData_40002eb4 == 0)
			{
				bData_40002eb4 = bData_40003161 - 1;
			}
			else
			{
				bData_40002eb4--;
			}
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
			//0x5e650
			lcd_display_clear();			
			//break;
		
		case 31001:
			//0x5e65c
			if (bData_40002eb5_SolarSystemObjectNr == 0)
			{
				bData_40002eb5_SolarSystemObjectNr = 9;
			}
			else
			{
				bData_40002eb5_SolarSystemObjectNr--;
			}		
			break;
		
		case MENU_CONTEXT_CONSTELLATION_SELECTION: //24001:
			//0x5e694
			lcd_display_clear();
		
			bData_40002ece_ConstellationNr--;
			if (bData_40002ece_ConstellationNr == 0)
			{
				bData_40002ece_ConstellationNr = 88;
			}
			break;
		
		case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
			//0x5e6d0
			lcd_display_clear();
		
			bData_40002ed2_FamousStarNr--;
			if (bData_40002ed2_FamousStarNr == 0)
			{
				bData_40002ed2_FamousStarNr = 33;
			}
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
			//0x5e70c
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//0x5e714
			lcd_display_clear();
		
			wData_40002eb8_MessierNr--;
			if (wData_40002eb8_MessierNr == 0)
			{
				wData_40002eb8_MessierNr = 110;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//0x5e74c
			lcd_display_clear();
		
			wData_40002eba_NGCNr--;
			if (wData_40002eba_NGCNr == 0)
			{
				wData_40002eba_NGCNr = 7840;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//0x5e788
			lcd_display_clear();

			wData_40002ebc_ICNr--;
			if (wData_40002ebc_ICNr == 0)
			{
				wData_40002ebc_ICNr = 5386;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//0x5e8c8
			lcd_display_clear();
		
			wData_40002ebe_ShNr--;
			if (wData_40002ebe_ShNr == 0)
			{
				wData_40002ebe_ShNr = 313;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//0x5e904
			lcd_display_clear();
		
			wData_40002ec0_BrightStarNr--;
			if (wData_40002ec0_BrightStarNr == 0)
			{
				wData_40002ec0_BrightStarNr = 167;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x5e940
			lcd_display_clear();
		
			Data_40002ec4_SAONr--;
			if (Data_40002ec4_SAONr == 0)
			{
				Data_40002ec4_SAONr = 258997;
			}
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x5e97c
			bData_4000318a = 5;
			Data_40002c64_MenuContextId = 205;
			break;
		
		case 205:
			//0x5e99c
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = 204;
			break;
		
		case 204:
			//0x5e9bc
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT; //203;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x5e9dc
		case 202:
			//0x5e9e4
		case 101:
			//0x5e9e8
			switch (bData_4000319a_SkyLandTargetId)
			{
				case 1:
					//0x5ea24
					bData_4000319a_SkyLandTargetId = 7;
					break;

				case 7:
					//0x5ea38
					bData_4000319a_SkyLandTargetId = 4;
					break;
				
				case 4:
					//0x5ea4c
					bData_4000319a_SkyLandTargetId = 1;
					break;

				case 2:
					//0x5ea60
					bData_4000319a_SkyLandTargetId = 8;
					break;

				case 8:
					//0x5ea74
					bData_4000319a_SkyLandTargetId = 5;
					break;
				
				case 5:
					//0x5ea88
					bData_4000319a_SkyLandTargetId = 2;
					break;

				case 3:
					//0x5ea9c
					bData_4000319a_SkyLandTargetId = 9;
					break;
				
				case 9:
					//0x5eab0
					bData_4000319a_SkyLandTargetId = 6;
					break;
				
				case 6:
					//0x5eac4
					bData_4000319a_SkyLandTargetId = 3;
					break;
				
				#if 0
				default:
					//0x5ead8
					break;
				#endif
			}
			break;
		
		case 206:
			//0x5eae0
			bData_4000318a = 5;
			Data_40002c64_MenuContextId = 208;
			break;
		
		case 208:
			//0x5eb00
			bData_4000318a = 5;
			Data_40002c64_MenuContextId = 207;
			break;
		
		case 207:
			//0x5eb20
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = 206;
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//0x5eb40
			if (bData_40002e78 == 0)
			{
				//5eb54
				bData_40002e78 = 1;
			}
			else
			{
				//0x5eb64
				bData_40002e78 = 0;
			}
			//0x5eb70
			bData_4000318a = 1;
			break;
		
		case 43021:
			//0x5eb80
			Data_40002c64_MenuContextId = 43024;
			break;
		
		case 43022:
			//0x5eb94
			Data_40002c64_MenuContextId = 43021;
			break;
		
		case 43023:
			//0x5eba8
			Data_40002c64_MenuContextId = 43022;
			break;
		
		case 43024:
			//0x5ebbc
			Data_40002c64_MenuContextId = 43023;
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x5ebd0
			if (bData_40003144 == 0)
			{
				bData_40003144 = 3;
				bData_4000318a = 7;
			}
			else
			{
				//0x5ec00
				bData_40003144--;
				bData_4000318a = 7;
			}
			//0x5ec20
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x5ec24
			Data_40002c64_MenuContextId = MENU_CONTEXT_OTA_ZERO_SETUP; //47011;
			if (bData_4000316d > 0)
			{
				//5ec44
				bData_4000316d--;
			}
			else
			{
				//0x5ec5c
				bData_4000316d = 1;
			}
			//0x5ec68
			if (bData_4000316d == 0)
			{
				bData_4000318a = 5;
			}
			else
			{
				//0x5ec88
				bData_4000318a = 6;
			}
			//0x5ec94
			break;
		
		case 33001:
			//0x5ec98
			Data_40003164_LunarPhaseYear--;
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x5ecb4
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				Data_4000340c = 1;
				bData_40003201 = 0;
			}
			else
			{
				if (bData_40002c60_CurrentAlignStarIndex == 1)
				{
					bData_40002c60_CurrentAlignStarIndex = bData_400034a8_CurrentAlignStarCount;
				}
				else
				{
					bData_40002c60_CurrentAlignStarIndex--;
				}
			}
			//->0x5f0b4
			break;
			
		case 360021:
			//0x5ed20
			Data_40002c64_MenuContextId = 360022;
			bData_4000318a = 7;
			break;
		
		case 360022:
			//0x5ed40
			Data_40002c64_MenuContextId = 360021;
			bData_4000318a = 7;
			break;
		
		case 370021:
			//0x5ed60
			Data_40002c64_MenuContextId = 370023;
			bData_4000318a = 7;
			break;
		
		case 370023:
			//0x5ed80
			Data_40002c64_MenuContextId = 370022;
			bData_4000318a = 7;
			break;
		
		case 370022:
			//0x5eda0
			Data_40002c64_MenuContextId = 370021;
			bData_4000318a = 7;
			break;
		
		case 360111:
			//0x5edc0
			Data_40002c64_MenuContextId = 360113;
			break;

		case 360112:
			//0x5edd4
			Data_40002c64_MenuContextId = 360111;
			break;
		
		case 360113:
			//0x5ede8
			Data_40002c64_MenuContextId = 360112;
			break;

		case MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL: //380011:
			//0x5edfc: Background light
			if (Data_40003248_CurrentDisplayPWM == 0)
			{
				//5ee10
				setDisplayPWM(63);
				Data_40003248_CurrentDisplayPWM = 63;
			}
			else if (Data_40003248_CurrentDisplayPWM == 63)
			{
				//5ee38
				setDisplayPWM(127);
				Data_40003248_CurrentDisplayPWM = 127;
			}
			else if (Data_40003248_CurrentDisplayPWM == 127)
			{
				//5ee38
				setDisplayPWM(191);
				Data_40003248_CurrentDisplayPWM = 191;
			}
			else
			{
				//0x5ee78
				setDisplayPWM(255);
				Data_40003248_CurrentDisplayPWM = 255;
			}
			//->0x5f0b4
			break;
			
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x5ee90
			lcd_display_clear();
			func_5ca98(); //->Previous country
			break;
		
		case 211001:
			//0x5eea0
			switch (bData_40003262)
			{
				case 0:
					//0x5eec8
				case 2:
					//0x5eed0
					if (bData_4000325c == 0)
					{
						bData_4000325c = bData_40003258 - 1;
					}
					else
					{
						//0x5eef8
						bData_4000325c--;
					}
					break;
		
				case 1:
					//0x5ef10
					if (bData_40003261 == 0)
					{
						bData_40003261 = 2;
						bData_4000318a = 7;
					}
					else
					{
						//0x5ef40
						bData_40003261--;
						bData_4000318a = 7;
					}
					//break;
				
				default:
					//0x5ef64
					break;
			}
			break;
			
		case 28001:
			//0x5ef70
			switch (bData_40003263)
			{
				case 0:
					//0x5efa0
				case 2:
					//0x5efa8
					if (wData_4000325a == 0)
					{
						wData_4000325a = wData_40003256 - 1;
					}
					else
					{
						wData_4000325a--;
					}
					break;
				
				case 1:
					//0x5efe8
				case 3:
					//0x5eff0
					if (bData_40003260 == 0)
					{
						bData_40003260 = 2;
						bData_4000318a = 7;
					}
					else
					{
						bData_40003260--;
						bData_4000318a = 7;
					}
					//break;
				
				default:
					//0x5f040
					break;
			}
			break;
		
		case 42001:
			//0x5f04c
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42002;
				bData_40002c6a = 0;
			}
			break;
			
		case 42002:
			//0x5f07c
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42001;
				bData_40002c6a = 1;
			}
			break;
			
		default:
			//0x5f0ac
			break;
	}
}

