

/* 66e3c - todo */
void Handle3Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x67000
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
			//->0x678ac
			break;
		
		case 101:
		case 201:
		case 202:
			//67020
			bData_4000319a_SkyLandTargetId = 3;
			break;
		
		case 5000:
			//67030
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//67058
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//67070
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 3) <= 110) && ((10*Data_40002ec8 + 3) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 3;
			}

			if ((Data_40002ec8 <= 110) && (Data_40002ec8 != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//670f8
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 3) <= 7840) && ((10*Data_40002ec8 + 3) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 3;
			}

			if ((Data_40002ec8 <= 7840) && (Data_40002ec8 != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//6718c
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 3) <= 5386) && ((10*Data_40002ec8 + 3) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 3;
			}

			if ((Data_40002ec8 <= 5386) && (Data_40002ec8 != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//67220
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 3) <= 313) && ((10*Data_40002ec8 + 3) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 3;
			}

			if ((Data_40002ec8 <= 313) && (Data_40002ec8 != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//672b4
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 3) <= 167) && ((10*Data_40002ec8 + 3) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 3;
			}

			if ((Data_40002ec8 <= 167) && (Data_40002ec8 != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//67340
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 3) <= 258997) && ((10*Data_40002ec8 + 3) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 3;
			}

			if ((Data_40002ec8 <= 258997) && (Data_40002ec8 != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//673dc
			Data_400022f2[bData_4000318a - 1] = '3';
			Data_400027df[bData_4000318a - 1] = '3';
		
			func_57b40();
			break;
		
		case 207:
			//67410
			Data_400022f2[bData_4000318a - 1] = '3';
			Data_400027df[bData_4000318a - 1] = '3';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//67454
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '3';
				Data_400027ef[bData_4000318a - 1] = '3';
			}
			else
			{
				//0x67494
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
			//6751c
			switch (bData_400031e8)
			{
				case '3':
					//0x67568
					bData_400031e8 = 'd';
					break;
				
				case 'd': //100
					//0x6757c
					bData_400031e8 = 'e';
					break;
				
				case 'e': //101
					//0x67590
					bData_400031e8 = 'f';
					break;
				
				case 'f': //102
					//0x675a4
					bData_400031e8 = 'D';
					break;
								
				case 'D': //68
					//0x675b8
					bData_400031e8 = 'E';
					break;
				
				case 'E': //69
					//0x675cc
					bData_400031e8 = 'F';
					break;
				
				case 'F': //70
					//0x675e0
					bData_400031e8 = '3';
					break;
								
				default:
					//0x675f4
					bData_400031e8 = '3';
					break;
			}
			//0x67608
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//6762c
			if (bData_4000318a != 1)
			{
				Data_400037cc[bData_4000318a - 1] = '3';
				Data_400037dc[bData_4000318a - 1] = '3';
			}
			else
			{
				//0x67670
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
			//0x676e8
			func_57370();
			break;
		
		case 41001:
			//676f0
			if (bData_40002e78 == 0)
			{
				Data_40002655[bData_4000318a - 1] = '3';
				Data_400037ec[bData_4000318a - 1] = '3';
			}
			else
			{
				//0x67734
				Data_40002660[bData_4000318a - 1] = '3';
				Data_40003150[bData_4000318a - 1] = '3';
			}
			//0x67760
			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//67768
			func_62524(3);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//67778
			func_623d0(3);
			break;
		
		case 34001:
			//67788
			Data_4000294a[bData_4000318a - 1] = '3';
			strEng00000s[bData_4000318a - 1] = '3';
		
			func_56d0c();
			break;
		
		case 35001:
			//677c0
			Data_40002a3f[bData_4000318a - 1] = '3';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '3';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//67800
			Data_40002474[bData_4000318a - 1] = '3';
			Data_400024c9[bData_4000318a - 1] = '3';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//6783c
			Data_40002481[bData_4000318a - 1] = '3';
			Data_400024d6[bData_4000318a - 1] = '3';
		
			func_56bf8();
			break;
		
		case 370023:
			//67870
			Data_400024e1[bData_4000318a - 1] = '3';
		
			func_56b54();
			break;
		
		case 211001:
			//67894
			func_61ecc(3);
			break;
		
		default:
			//0x678a4
			break;
	}
}

