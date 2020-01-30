

/* 65894 - todo */
void Handle5Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x65a58
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_64; //5;
			//->0x6636c
			break;
		
		case 101:
		case 201:
		case 202:
			//65a78
			bData_4000319a_SkyLandTargetId = 5;
			break;
		
		case 5000:
			//65a88
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_64; //5;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//65ab0
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_64; //5;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//65ac8
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 5) <= 110) && ((10*Data_40002ec8 + 5) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 5;
			}

			if ((Data_40002ec8 <= 110) && (Data_40002ec8 != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//65b50
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 5) <= 7840) && ((10*Data_40002ec8 + 5) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 5;
			}

			if ((Data_40002ec8 <= 7840) && (Data_40002ec8 != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//65be4
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 5) <= 5386) && ((10*Data_40002ec8 + 5) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 5;
			}

			if ((Data_40002ec8 <= 5386) && (Data_40002ec8 != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//65c78
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 5) <= 313) && ((10*Data_40002ec8 + 5) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 5;
			}

			if ((Data_40002ec8 <= 313) && (Data_40002ec8 != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//65d74
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 5) <= 167) && ((10*Data_40002ec8 + 5) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 5;
			}

			if ((Data_40002ec8 <= 167) && (Data_40002ec8 != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//65e00
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 5) <= 258997) && ((10*Data_40002ec8 + 5) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 5;
			}

			if ((Data_40002ec8 <= 258997) && (Data_40002ec8 != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//65e9c
			Data_400022f2[bData_4000318a - 1] = '5';
			Data_400027df[bData_4000318a - 1] = '5';
		
			func_57b40();
			break;
		
		case 207:
			//65ed0
			Data_400022f2[bData_4000318a - 1] = '5';
			Data_400027df[bData_4000318a - 1] = '5';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//65f14
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '5';
				Data_400027ef[bData_4000318a - 1] = '5';
			}
			else
			{
				//0x65f54
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
			//65fdc
			switch (bData_400031e8)
			{
				case '5':
					//0x66028
					bData_400031e8 = 'j';
					break;
				
				case 'j': //106:
					//0x6603c
					bData_400031e8 = 'k';
					break;
				
				case 'k': //107
					//0x66050
					bData_400031e8 = 'l';
					break;
				
				case 'l': //108
					//0x66064
					bData_400031e8 = 'J';
					break;
				
				case 'J': //74:
					//0x66078
					bData_400031e8 = 'K';
					break;
				
				case 'K': //75:
					//0x6608c
					bData_400031e8 = 'L';
					break;
				
				case 'L': //76:
					//0x660a0
					bData_400031e8 = '5';
					break;
								
				default:
					//0x660b4
					bData_400031e8 = '5';
					break;
			}
			//0x660c8
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//660ec
			if (bData_4000318a != 1)
			{
				Data_400037cc[bData_4000318a - 1] = '5';
				Data_400037dc[bData_4000318a - 1] = '5';
			}
			else
			{
				//0x66130
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
			//0x661a8
			func_57370();
			break;
		
		case 41001:
			//661b0
			if (bData_40002e78 == 0)
			{
				Data_40002655[bData_4000318a - 1] = '5';
				Data_400037ec[bData_4000318a - 1] = '5';
			}
			else
			{
				//0x661f4
				Data_40002660[bData_4000318a - 1] = '5';
				Data_40003150[bData_4000318a - 1] = '5';
			}
			//0x66220
			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//66228
			func_62524(5);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//66238
			func_623d0(5);
			break;
		
		case 34001:
			//66248
			Data_4000294a[bData_4000318a - 1] = '5';
			strEng00000s[bData_4000318a - 1] = '5';
		
			func_56d0c();
			break;
		
		case 35001:
			//66280
			Data_40002a3f[bData_4000318a - 1] = '5';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '5';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//662c0
			Data_40002474[bData_4000318a - 1] = '5';
			Data_400024c9[bData_4000318a - 1] = '5';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//662fc
			Data_40002481[bData_4000318a - 1] = '5';
			Data_400024d6[bData_4000318a - 1] = '5';
		
			func_56bf8();
			break;
		
		case 370023:
			//66330
			Data_400024e1[bData_4000318a - 1] = '5';
		
			func_56b54();
			break;
		
		case 211001:
			//66354
			func_61ecc(5);
			break;
		
		default:
			//0x66364
			break;
	}
}

