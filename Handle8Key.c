

/* 637e8 - todo */
void Handle8Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x639ac
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_512; //8;
			//->0x64318
			break;
		
		case 101:
		case 201:
		case 202:
			//639cc
			bData_4000319a_SkyLandTargetId = 8;
			break;
		
		case 5000:
			//639dc
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_512; //8;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//63a04
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_512; //8;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//63adc
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}
			//0x63b30
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//63b64
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//63bf8
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//63c8c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//63d20
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//63dac
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//63e48
			Data_400022f2[bData_4000318a - 1] = '8';
			Data_400027df[bData_4000318a - 1] = '8';
		
			func_57b40();
			break;
		
		case 207:
			//63e7c
			Data_400022f2[bData_4000318a - 1] = '8';
			Data_400027df[bData_4000318a - 1] = '8';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//63ec0
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '8';
				Data_400027ef[bData_4000318a - 1] = '8';
			}
			else
			{
				//0x63f00
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
			//63f88
			switch (bData_400031e8)
			{
				case '8':
					//0x63fd4
					bData_400031e8 = 't';
					break;
				
				case 't': //116:
					//0x63fe8
					bData_400031e8 = 'u';
					break;
				
				case 'u': //117:
					//0x63ffc
					bData_400031e8 = 'v';
					break;
				
				case 'v': //118:
					//0x64010
					bData_400031e8 = 'T';
					break;
								
				case 'T': //84:
					//0x64024
					bData_400031e8 = 'U';
					break;
				
				case 'U': //85:
					//0x64038
					bData_400031e8 = 'V';
					break;
				
				case 'V': //86:
					//0x6404c
					bData_400031e8 = '8';
					break;
				
				default:
					//0x64060
					bData_400031e8 = '8';
					break;
			}
			//0x64074
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//64098
			if (bData_4000318a != 1)
			{
				//640ac
				Data_400037cc[bData_4000318a - 1] = '8';
				Data_400037dc[bData_4000318a - 1] = '8';
			}
			else
			{
				//0x640dc
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
			//0x64154
			func_57370();
			break;
		
		case 41001:
			//6415c
			if (bData_40002e78 == 0)
			{
				//64170
				Data_40002655[bData_4000318a - 1] = '8';
				Data_400037ec[bData_4000318a - 1] = '8';
			}
			else
			{
				//0x641a0
				Data_40002660[bData_4000318a - 1] = '8';
				Data_40003150[bData_4000318a - 1] = '8';
			}
			//0x641cc
			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//641d4
			func_62524(8);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//641e4
			func_623d0(8);
			break;
		
		case 34001:
			//641f4
			Data_4000294a[bData_4000318a - 1] = '8';
			strEng00000s[bData_4000318a - 1] = '8';
		
			func_56d0c();
			break;
		
		case 35001:
			//6422c
			Data_40002a3f[bData_4000318a - 1] = '8';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '8';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//6426c
			Data_40002474[bData_4000318a - 1] = '8';
			Data_400024c9[bData_4000318a - 1] = '8';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//642a8
			Data_40002481[bData_4000318a - 1] = '8';
			Data_400024d6[bData_4000318a - 1] = '8';
		
			func_56bf8();
			break;
		
		case 370023:
			//642dc
			Data_400024e1[bData_4000318a - 1] = '8';
		
			func_56b54();
			break;
		
		case 211001:
			//64300
			func_61ecc(8);
			break;
		
		default:
			//0x64310
			break;
	}
}

