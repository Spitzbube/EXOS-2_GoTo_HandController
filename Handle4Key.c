

/* 66378 - todo */
void Handle4Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x6653c
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_16; //4;
			//->0x66e30
			break;
		
		case 101:
		case 201:
		case 202:
			//6655c
			bData_4000319a_SkyLandTargetId = 4;
			break;
		
		case 5000:
			//6656c
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_16; //4;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//66594
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_16; //4;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//665ac
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 4) <= 110) && ((10*Data_40002ec8 + 4) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 4;
			}
			//0x62fbc
			if ((Data_40002ec8 <= 110) && (Data_40002ec8 != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//66634
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 4) <= 7840) && ((10*Data_40002ec8 + 4) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 4;
			}

			if ((Data_40002ec8 <= 7840) && (Data_40002ec8 != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//666c8
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 4) <= 5386) && ((10*Data_40002ec8 + 4) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 4;
			}

			if ((Data_40002ec8 <= 5386) && (Data_40002ec8 != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//6675c
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 4) <= 313) && ((10*Data_40002ec8 + 4) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 4;
			}

			if ((Data_40002ec8 <= 313) && (Data_40002ec8 != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//667f0
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 4) <= 167) && ((10*Data_40002ec8 + 4) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 4;
			}

			if ((Data_40002ec8 <= 167) && (Data_40002ec8 != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//6687c
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 4) <= 258997) && ((10*Data_40002ec8 + 4) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 4;
			}

			if ((Data_40002ec8 <= 258997) && (Data_40002ec8 != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//66918
			Data_400022f2[bData_4000318a - 1] = '4';
			Data_400027df[bData_4000318a - 1] = '4';
		
			func_57b40();
			break;
		
		case 207:
			//6694c
			Data_400022f2[bData_4000318a - 1] = '4';
			Data_400027df[bData_4000318a - 1] = '4';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//66990
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '4';
				Data_400027ef[bData_4000318a - 1] = '4';
			}
			else
			{
				//0x669d0
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
			//66a58
			switch (bData_400031e8)
			{
				case '4':
					//0x66aa4
					bData_400031e8 = 'g';
					break;
				
				case 'g': //103
					//0x66ab8
					bData_400031e8 = 'h';
					break;
				
				case 'h': //104
					//0x66acc
					bData_400031e8 = 'i';
					break;
				
				case 'i': //105
					//0x66ae0
					bData_400031e8 = 'G';
					break;
								
				case 'G': //71
					//0x66af4
					bData_400031e8 = 'H';
					break;
				
				case 'H': //72
					//0x66b08
					bData_400031e8 = 'I';
					break;
				
				case 'I': //73
					//0x66b1c
					bData_400031e8 = '4';
					break;
				
				default:
					//0x66b30
					bData_400031e8 = '4';
					break;
			}
			//0x66b44
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//66b68
			if (bData_4000318a != 1)
			{
				Data_400037cc[bData_4000318a - 1] = '4';
				Data_400037dc[bData_4000318a - 1] = '4';
			}
			else
			{
				//0x66bac
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
			//0x66c24
			func_57370();
			break;
		
		case 41001:
			//66c2c
			if (bData_40002e78 == 0)
			{
				Data_40002655[bData_4000318a - 1] = '4';
				Data_400037ec[bData_4000318a - 1] = '4';
			}
			else
			{
				//0x66c70
				Data_40002660[bData_4000318a - 1] = '4';
				Data_40003150[bData_4000318a - 1] = '4';
			}
			//0x66c9c
			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//66ca4
			func_62524(4);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//66cb4
			func_623d0(4);
			break;
		
		case 34001:
			//66cc4
			Data_4000294a[bData_4000318a - 1] = '4';
			strEng00000s[bData_4000318a - 1] = '4';
		
			func_56d0c();
			break;
		
		case 35001:
			//66cfc
			Data_40002a3f[bData_4000318a - 1] = '4';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '4';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//66d3c
			Data_40002474[bData_4000318a - 1] = '4';
			Data_400024c9[bData_4000318a - 1] = '4';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//66d78
			Data_40002481[bData_4000318a - 1] = '4';
			Data_400024d6[bData_4000318a - 1] = '4';
		
			func_56bf8();
			break;
		
		case 370023:
			//66df4
			Data_400024e1[bData_4000318a - 1] = '4';
		
			func_56b54();
			break;
		
		case 211001:
			//66e18
			func_61ecc(4);
			break;
		
		default:
			//0x66e28
			break;
	}
}

