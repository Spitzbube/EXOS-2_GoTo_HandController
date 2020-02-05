

/* 64324 - todo */
void Handle7Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x644e8
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_256; //7;
			//->0x64e0c
			break;
		
		case 101:
		case 201:
		case 202:
			//64508
			bData_4000319a_SkyLandTargetId = 7;
			break;
		
		case 5000:
			//64518
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_256; //7;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//64540
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_256; //7;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//64558
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 7) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 7) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 7;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//645e0
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 7) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 7) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 7;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//64674
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 7) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 7) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 7;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//64708
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 7) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 7) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 7;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//6479c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 7) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 7) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 7;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//64828
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 7) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 7) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 7;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//648c4
			Data_400022f2[bData_4000318a - 1] = '7';
			Data_400027df[bData_4000318a - 1] = '7';
		
			func_57b40();
			break;
		
		case 207:
			//648f8
			Data_400022f2[bData_4000318a - 1] = '7';
			Data_400027df[bData_4000318a - 1] = '7';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//6493c
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '7';
				Data_400027ef[bData_4000318a - 1] = '7';
			}
			else
			{
				//0x6497c
				if (Data_40002302[bData_4000318a - 1] == '+')
				{
					Data_40002302[bData_4000318a - 1] = '-';
					Data_400027ef[bData_4000318a - 1] = '-';
				}
				else
				{
					//0x649c8
					Data_40002302[bData_4000318a - 1] = '-'; //'+'; //BUG! 
					Data_400027ef[bData_4000318a - 1] = '-'; //'+'; //BUG! 
				}
			}
			
			func_57a4c();
			break;
		
		case 203:
		case 206:
			//64a04
			switch (bData_400031e8)
			{
				case '7':
					//0x64a60
					bData_400031e8 = 'p';
					break;
				
				case 'p': //112:
					//0x64a74
					bData_400031e8 = 'q';
					break;
				
				case 'q': //113:
					//0x64a88
					bData_400031e8 = 'r';
					break;
				
				case 'r': //114:
					//0x64a9c
					bData_400031e8 = 's';
					break;
				
				case 's': //115:
					//0x64ab0
					bData_400031e8 = 'P';
					break;
				
				case 'P': //80:
					//0x64ac4
					bData_400031e8 = 'Q';
					break;
				
				case 'Q': //81:
					//0x64ad8
					bData_400031e8 = 'R';
					break;
				
				case 'R': //82:
					//0x64aec
					bData_400031e8 = 'S';
					break;
				
				case 'S': //83
					//0x64b00
					bData_400031e8 = '7';
					break;
				
				default:
					//0x64b14
					bData_400031e8 = '7';
					break;
			}
			//0x64b28
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//64b4c
			if (bData_4000318a != 1)
			{
				//64b60
				Data_400037cc[bData_4000318a - 1] = '7';
				Data_400037dc[bData_4000318a - 1] = '7';
			}
			else
			{
				//0x64b90
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
			//0x64c08
			func_57370();
			break;
		
		case 41001:
			//64c10
			if (bData_40002e78 == 0)
			{
				//64c24
				Data_40002655[bData_4000318a - 1] = '7';
				Data_400037ec[bData_4000318a - 1] = '7';
			}
			else
			{
				//0x64c54
				Data_40002660[bData_4000318a - 1] = '7';
				Data_40003150[bData_4000318a - 1] = '7';
			}
			//0x64c80
			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//64c88
			func_62524(7);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//64c98
			func_623d0(7);
			break;
		
		case 34001:
			//64ca8
			Data_4000294a[bData_4000318a - 1] = '7';
			strEng00000s[bData_4000318a - 1] = '7';
		
			func_56d0c();
			break;
		
		case 35001:
			//64ce0
			Data_40002a3f[bData_4000318a - 1] = '7';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '7';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//64d20
			Data_40002474[bData_4000318a - 1] = '7';
			Data_400024c9[bData_4000318a - 1] = '7';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//64d9c
			Data_40002481[bData_4000318a - 1] = '7';
			Data_400024d6[bData_4000318a - 1] = '7';
		
			func_56bf8();
			break;
		
		case 370023:
			//64dd0
			Data_400024e1[bData_4000318a - 1] = '7';
		
			func_56b54();
			break;
		
		case 211001:
			//64df4
			func_61ecc(7);
			break;
		
		default:
			//0x64e04
			break;
	}
}

