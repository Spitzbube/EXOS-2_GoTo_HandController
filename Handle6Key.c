

/* 64e18 - todo */
void Handle6Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x64fdc
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_128; //6;
			//->0x65888
			break;
		
		case 101:
		case 201:
		case 202:
			//64ffc
			bData_4000319a_SkyLandTargetId = 6;
			break;
		
		case 5000:
			//6500c
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_128; //6;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//65034
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_128; //6;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//6504c
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 6) <= 110) && ((10*Data_40002ec8 + 6) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 6;
			}

			if ((Data_40002ec8 <= 110) && (Data_40002ec8 != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//650d4
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 6) <= 7840) && ((10*Data_40002ec8 + 6) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 6;
			}

			if ((Data_40002ec8 <= 7840) && (Data_40002ec8 != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//65168
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 6) <= 5386) && ((10*Data_40002ec8 + 6) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 6;
			}

			if ((Data_40002ec8 <= 5386) && (Data_40002ec8 != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//651fc
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 6) <= 313) && ((10*Data_40002ec8 + 6) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 6;
			}

			if ((Data_40002ec8 <= 313) && (Data_40002ec8 != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//65290
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 6) <= 167) && ((10*Data_40002ec8 + 6) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 6;
			}

			if ((Data_40002ec8 <= 167) && (Data_40002ec8 != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//6531c
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 6) <= 258997) && ((10*Data_40002ec8 + 6) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 6;
			}

			if ((Data_40002ec8 <= 258997) && (Data_40002ec8 != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//653b8
			Data_400022f2[bData_4000318a - 1] = '6';
			Data_400027df[bData_4000318a - 1] = '6';
		
			func_57b40();
			break;
		
		case 207:
			//653ec
			Data_400022f2[bData_4000318a - 1] = '6';
			Data_400027df[bData_4000318a - 1] = '6';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//65430
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '6';
				Data_400027ef[bData_4000318a - 1] = '6';
			}
			else
			{
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
			//654f8
			switch (bData_400031e8)
			{
				case '6':
					//0x65544
					bData_400031e8 = 'm';
					break;
				
				case 'm': //109:
					//0x65558
					bData_400031e8 = 'n';
					break;
				
				case 'n': //110:
					//0x6556c
					bData_400031e8 = 'o';
					break;
				
				case 'o': //111:
					//0x65580
					bData_400031e8 = 'M';
					break;
				
				case 'M': //77:
					//0x65594
					bData_400031e8 = 'N';
					break;
				
				case 'N': //78:
					//0x655a8
					bData_400031e8 = 'O';
					break;
				
				case 'O': //79:
					//0x655bc
					bData_400031e8 = '6';
					break;
				
				default:
					//0x655d0
					bData_400031e8 = '6';
					break;
			}
			//0x655e4
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//65608
			if (bData_4000318a != 1)
			{
				//6561c
				Data_400037cc[bData_4000318a - 1] = '6';
				Data_400037dc[bData_4000318a - 1] = '6';
			}
			else
			{
				//0x6564c
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
			//0x656c4
			func_57370();
			break;
		
		case 41001:
			//656cc
			if (bData_40002e78 == 0)
			{
				Data_40002655[bData_4000318a - 1] = '6';
				Data_400037ec[bData_4000318a - 1] = '6';
			}
			else
			{
				//0x65710
				Data_40002660[bData_4000318a - 1] = '6';
				Data_40003150[bData_4000318a - 1] = '6';
			}
			//0x6573c
			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//65744
			func_62524(6);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//65754
			func_623d0(6);
			break;
		
		case 34001:
			//65764
			Data_4000294a[bData_4000318a - 1] = '6';
			strEng00000s[bData_4000318a - 1] = '6';
		
			func_56d0c();
			break;
		
		case 35001:
			//6579c
			Data_40002a3f[bData_4000318a - 1] = '6';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '6';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//657dc
			Data_40002474[bData_4000318a - 1] = '6';
			Data_400024c9[bData_4000318a - 1] = '6';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//65818
			Data_40002481[bData_4000318a - 1] = '6';
			Data_400024d6[bData_4000318a - 1] = '6';
		
			func_56bf8();
			break;
		
		case 370023:
			//6584c
			Data_400024e1[bData_4000318a - 1] = '6';
		
			func_56b54();
			break;
		
		case 211001:
			//65870
			func_61ecc(6);
			break;
		
		default:
			//0x65880
			break;
	}
}

