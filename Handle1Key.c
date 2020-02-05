

/* 68934 - todo */
void Handle1Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x68af8
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_1; //1;
			//->0x6933c
			break;
		
		case 101:
		case 201:
		case 202:
			//68b18
			bData_4000319a_SkyLandTargetId = 1;
			break;
		
		case 5000:
			//68b28
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_1; //1;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//68b50
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_1; //1;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//68b68
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}
			//0x62fbc
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//68bf0
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//68c84
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//68d18
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//68e28
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//68eb4
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//68f50
			Data_400022f2[bData_4000318a - 1] = '1';
			Data_400027df[bData_4000318a - 1] = '1';
		
			func_57b40();
			break;
		
		case 207:
			//68f84
			Data_400022f2[bData_4000318a - 1] = '1';
			Data_400027df[bData_4000318a - 1] = '1';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//68fc8
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '1';
				Data_400027ef[bData_4000318a - 1] = '1';
			}
			else
			{
				//0x6338c
				if (Data_40002302[bData_4000318a - 1] == '+')
				{
					Data_40002302[bData_4000318a - 1] = '-';
					Data_400027ef[bData_4000318a - 1] = '-';
				}
				else
				{
					Data_40002302[bData_4000318a - 1] = '+';
					Data_400027ef[bData_4000318a - 1] = '+';
				}
			}
			
			func_57a4c();
			break;
		
		case 203:
		case 206:
			//69090
			bData_400031e8 = '1';
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//690bc
			if (bData_4000318a != 1)
			{
				Data_400037cc[bData_4000318a - 1] = '1';
				Data_400037dc[bData_4000318a - 1] = '1';
			}
			else
			{
				if (Data_400037cc[bData_4000318a - 1] == '+')
				{
					Data_400037cc[bData_4000318a - 1] = '-';
					Data_400037dc[bData_4000318a - 1] = '-';
				}
				else
				{
					Data_400037cc[bData_4000318a - 1] = '+';
					Data_400037dc[bData_4000318a - 1] = '+';
				}
			}

			func_57370();
			break;
		
		case 41001:
			//69180
			if (bData_40002e78 == 0)
			{
				Data_40002655[bData_4000318a - 1] = '1';
				Data_400037ec[bData_4000318a - 1] = '1';
			}
			else
			{
				Data_40002660[bData_4000318a - 1] = '1';
				Data_40003150[bData_4000318a - 1] = '1';
			}

			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//691f8
			func_62524(1);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//69208
			func_623d0(1);
			break;
		
		case 34001:
			//69218
			Data_4000294a[bData_4000318a - 1] = '1';
			strEng00000s[bData_4000318a - 1] = '1';
		
			func_56d0c();
			break;
		
		case 35001:
			//69250
			Data_40002a3f[bData_4000318a - 1] = '1';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '1';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//69290
			Data_40002474[bData_4000318a - 1] = '1';
			Data_400024c9[bData_4000318a - 1] = '1';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//692cc
			Data_40002481[bData_4000318a - 1] = '1';
			Data_400024d6[bData_4000318a - 1] = '1';
		
			func_56bf8();
			break;
		
		case 370023:
			//69300
			Data_400024e1[bData_4000318a - 1] = '1';
		
			func_56b54();
			break;
		
		case 211001:
			//69324
			func_61ecc(1);
			break;
		
		default:
			//0x69334
			break;
	}
}

