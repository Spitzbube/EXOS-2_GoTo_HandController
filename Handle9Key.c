

/* 62ce0 - todo */
void Handle9Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{		
		case MENU_CONTEXT_MAIN: //0:
			//0x62ea4
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_MAX; //9;
			if (bData_40002e89 == 0)
			{
				bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_512; //8;
			}
			//0x62ed0 -> 0x637dc
			break;
			
		case 101:
			//0x62ed4
		case 201:
			//0x62edc	
		case 202:
			//0x62ee0
			bData_4000319a_SkyLandTargetId = 9;
			break;
		
		case 5000:
			//0x62ef0
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_MAX; //9;
			if (bData_40002e89 == 0)
			{
				bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_512; //8;
			}
			break;
		
		case 11102:
			//0x62f20
		case 11202:
			//0x62f28
		case 11103:
			//0x62f2c
		case 11203:
			//0x62f30
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x62f34
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_MAX; //9;
			if (bData_40002e89 == 0)
			{
				bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_512; //8;
			}
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
			//0x62f60
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//0x62f68
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 9) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 9) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 9;
			}
			//0x62fbc
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//0x62ff0
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 9) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 9) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 9;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//0x63084
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 9) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 9) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 9;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//0x63118
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 9) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 9) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 9;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//0x631ac
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 9) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 9) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 9;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x63238
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 9) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 9) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 9;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
			//0x632cc		
		case 204:
			//0x632d4
			strCustomerObjectRaAziInputCheck[bData_4000318a - 1] = '9';
			Data_400027df[bData_4000318a - 1] = '9';
		
			func_57b40();
			break;
		
		case 207:
			//0x63308
			strCustomerObjectRaAziInputCheck[bData_4000318a - 1] = '9';
			Data_400027df[bData_4000318a - 1] = '9';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
			//0x63340
		case 205:
			//0x63348
		case 208:
			//0x6334c
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '9';
				Data_400027ef[bData_4000318a - 1] = '9';
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
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x6340c
		case 206:
			//0x63414
			switch (bData_400031e8)
			{
				case '9':
					//0x63470
					bData_400031e8 = 'w';
					break;
				
				case 'w': //119:
					//0x63484
					bData_400031e8 = 'x';
					break;
				
				case 'x': //120:
					//0x63498
					bData_400031e8 = 'y';
					break;
				
				case 'y': //121:
					//0x634ac
					bData_400031e8 = 'z';
					break;
				
				case 'z': //122:
					//0x634c0
					bData_400031e8 = 'W';
					break;
				
				case 'W': //87:
					//0x634d4
					bData_400031e8 = 'X';
					break;
				
				case 'X': //88:
					//0x634e8
					bData_400031e8 = 'Y';
					break;
				
				case 'Y': //89:
					//0x634fc
					bData_400031e8 = 'Z';
					break;
				
				case 'Z': //90
					//0x63510
					bData_400031e8 = '9';
					break;
				
				default:
					//0x63524
					bData_400031e8 = '9';
					break;
			}
			//0x63538
			strCustomerObjectNameInput[bData_4000318a - 1] = bData_400031e8;
			break;
		
		case 48001:
			//0x6355c
			if (bData_4000318a != 1)
			{
				//63570
				Data_400037cc[bData_4000318a - 1] = '9';
				Data_400037dc[bData_4000318a - 1] = '9';
			}
			else
			{
				//0x635a0
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
			//0x63618
			func_57370();
			break;
		
		case 41001:
			//0x63620
			if (bData_40002e78 == 0)
			{
				//63634
				Data_40002655[bData_4000318a - 1] = '9';
				Data_400037ec[bData_4000318a - 1] = '9';
			}
			else
			{
				//0x63664
				Data_40002660[bData_4000318a - 1] = '9';
				Data_40003150[bData_4000318a - 1] = '9';
			}
			//0x63690
			func_5718c();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x63698
			func_62524(9);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x636a8
			func_623d0(9);
			break;
		
		case 34001:
			//0x636b8
			Data_4000294a[bData_4000318a - 1] = '9';
			strEng00000s[bData_4000318a - 1] = '9';
		
			func_56d0c();
			break;
		
		case 35001:
			//0x636f0
			Data_40002a3f[bData_4000318a - 1] = '9';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '9';
		
			func_56c4c();
			break;
		
		case 360021:
			//0x63728
		case 370021:
			//0x63730
			Data_40002474[bData_4000318a - 1] = '9';
			Data_400024c9[bData_4000318a - 1] = '9';
		
			func_56ac8();
			break;
		
		case 360022:
			//0x63764
		case 370022:
			//0x6376c
			Data_40002481[bData_4000318a - 1] = '9';
			Data_400024d6[bData_4000318a - 1] = '9';
		
			func_56bf8();
			break;
		
		case 370023:
			//0x637a0
			Data_400024e1[bData_4000318a - 1] = '9';
		
			func_56b54();
			break;
		
		case 211001:
			//0x637c4
			func_61ecc(9);
			break;
		
		default:
			//0x637d4
			break;
	}
}

