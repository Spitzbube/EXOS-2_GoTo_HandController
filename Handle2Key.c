

/* 678b8 - todo */
void Handle2Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x67a7c
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_2; //2;
			//->0x68388
			break;
		
		case 101:
		case 201:
		case 202:
			//67a9c
			bData_4000319a_SkyLandTargetId = 2;
			break;
		
		case 5000:
			//67aac
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_2; //2;
			break;
		
		case 11102:
		case 11202:
		case 11103:
		case 11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//67ad4
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_2; //2;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//67aec
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 2) <= 110) && ((10*Data_40002ec8 + 2) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 2;
			}
			//0x62fbc
			if ((Data_40002ec8 <= 110) && (Data_40002ec8 != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//67b74
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 2) <= 7840) && ((10*Data_40002ec8 + 2) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 2;
			}

			if ((Data_40002ec8 <= 7840) && (Data_40002ec8 != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//67c08
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 2) <= 5386) && ((10*Data_40002ec8 + 2) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 2;
			}

			if ((Data_40002ec8 <= 5386) && (Data_40002ec8 != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//67c9c
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 2) <= 313) && ((10*Data_40002ec8 + 2) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 2;
			}

			if ((Data_40002ec8 <= 313) && (Data_40002ec8 != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//67d90
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 2) <= 167) && ((10*Data_40002ec8 + 2) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 2;
			}

			if ((Data_40002ec8 <= 167) && (Data_40002ec8 != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//67e1c
			lcd_display_clear();
		
			if (((10*Data_40002ec8 + 2) <= 258997) && ((10*Data_40002ec8 + 2) != 0))
			{
				Data_40002ec8 = 10*Data_40002ec8 + 2;
			}

			if ((Data_40002ec8 <= 258997) && (Data_40002ec8 != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case 204:
			//67eb8
			Data_400022f2[bData_4000318a - 1] = '2';
			Data_400027df[bData_4000318a - 1] = '2';
		
			func_57b40();
			break;
		
		case 207:
			//67eec
			Data_400022f2[bData_4000318a - 1] = '2';
			Data_400027df[bData_4000318a - 1] = '2';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case 205:
		case 208:
			//67f30
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '2';
				Data_400027ef[bData_4000318a - 1] = '2';
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
			//67ff8
			switch (bData_400031e8)
			{
				case '2':
					//0x68044
					bData_400031e8 = 'a';
					break;
				
				case 'a': //97
					//0x68058
					bData_400031e8 = 'b';
					break;
				
				case 'b': //98
					//0x6806c
					bData_400031e8 = 'c';
					break;
				
				case 'c': //99
					//0x68080
					bData_400031e8 = 'A';
					break;
								
				case 'A': //65
					//0x68094
					bData_400031e8 = 'B';
					break;
				
				case 'B': //66
					//0x680a8
					bData_400031e8 = 'C';
					break;
				
				case 'C': //67
					//0x680bc
					bData_400031e8 = '2';
					break;
				
				default:
					//0x680d0
					bData_400031e8 = '2';
					break;
			}

			Data_400027ff[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//68108
			if (bData_4000318a != 1)
			{
				Data_400037cc[bData_4000318a - 1] = '2';
				Data_400037dc[bData_4000318a - 1] = '2';
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
			//681cc
			if (bData_40002e78 == 0)
			{
				Data_40002655[bData_4000318a - 1] = '2';
				Data_400037ec[bData_4000318a - 1] = '2';
			}
			else
			{
				Data_40002660[bData_4000318a - 1] = '2';
				Data_40003150[bData_4000318a - 1] = '2';
			}

			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//68244
			func_62524(2);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//68254
			func_623d0(2);
			break;
		
		case 34001:
			//68264
			Data_4000294a[bData_4000318a - 1] = '2';
			strEng00000s[bData_4000318a - 1] = '2';
		
			func_56d0c();
			break;
		
		case 35001:
			//6829c
			Data_40002a3f[bData_4000318a - 1] = '2';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '2';
		
			func_56c4c();
			break;
		
		case 360021:
		case 370021:
			//682dc
			Data_40002474[bData_4000318a - 1] = '2';
			Data_400024c9[bData_4000318a - 1] = '2';
		
			func_56ac8();
			break;
		
		case 360022:
		case 370022:
			//68318
			Data_40002481[bData_4000318a - 1] = '2';
			Data_400024d6[bData_4000318a - 1] = '2';
		
			func_56bf8();
			break;
		
		case 370023:
			//6834c
			Data_400024e1[bData_4000318a - 1] = '2';
		
			func_56b54();
			break;
		
		case 211001:
			//68370
			func_61ecc(2);
			break;
		
		default:
			//0x68380
			break;
	}
}

