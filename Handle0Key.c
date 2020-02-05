

/* 69348 - todo */
void Handle0Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x6958c
			if (bData_400034a9 == 0)
			{
				if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
				{
					if (bData_40002e89 == 0)
					{
						bData_40002e89 = 1;
						
						func_b4f0();
						//->0x69780
					}
					else
					{
						//0x695d4
						bData_40002e89 = 0;

						func_acdc(dData_40002dc0 + dData_400033e8,
							dData_40002df8 + dData_400033f0,
							&dData_40002c88, &dData_40002c90);
						
						func_b64c(dData_40002c88, dData_40002c90);
						
						bData_400034cc = 1;
						
						func_b594();
						//->0x69780
					}
				} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
				else
				{
					//0x69658
					if (bData_40002e89 == 0)
					{
						bData_40002e89 = 1;
						
						func_b4f0();
						//->0x69780
					}
					else
					{
						//0x6967c
						bData_40002e89 = 0;
						dData_40002c90 = dData_40002d98;
						
						dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - 
							dData_40002d78;
						
						dData_40002c88 += dData_400033e8;
						//->0x6970c
						while (dData_40002c88 >= 24)
						{
							dData_40002c88 -= 24;
						}
						
						while (dData_40002c88 < 0)
						{
							dData_40002c88 += 24;
						}
						
						func_b64c(dData_40002c88, dData_40002c90);
						
						bData_400034cc = 1;
						
						func_b594();
					}
				}
			} //if (bData_400034a9 == 0)
			//0x69780 -> 0x6a0d4
			break;
		
		case 11102:
			//0x69784
		case 11202:
			//0x6978c
		case 11103:
			//0x69790
		case 11203:
			//0x69794
			if (bData_40002e89 == 0)
			{
				bData_40002e89 = 1;
				
				func_b4f0();
			}
			else
			{
				//0x697b8
				bData_40002e89 = 0;
				
				func_b594();
			}
			//->0x6a0d4
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x697cc
			if (Data_40004128.Data_352 == 0)
			{
				Data_40004128.Data_352 = 1;
			}
			else
			{
				Data_40004128.Data_352 = 0;
			}
			break;
		
		case 101:
			//0x69800
			if (bData_40002c5a == 0)
			{
				bData_40002c5a = 1;
			}
			else
			{
				bData_40002c5a = 0;
			}
			break;
		
		case 5000:
			//0x69834
			bData_40002e7d_RotatingSpeed = 0;
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x69848
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x69850
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x69854
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x69858
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x6985c
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x69860
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x69864
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x69868
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			//0x6986c
			if (bData_40002e8a == 4)
			{
				func_b594();
			}
			
			if ((bData_40002e8a == 1) || (bData_40002e8a == 2))
			{
				bData_40002e8a = 4;
				
				func_b4f0();
			}
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
			//0x698b4
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//0x698bc
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 0) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 0) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr;
			}
			//0x69908
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//0x6993c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 0) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 0) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//0x699c8
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 0) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 0) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//0x69a54
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 0) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 0) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//0x69ae0
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 0) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 0) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x69b64
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 0) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 0) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
			//0x69bf0
		case 204:
			//0x69bf8
			Data_400022f2[bData_4000318a - 1] = '0';
			Data_400027df[bData_4000318a - 1] = '0';
		
			func_57b40();
			//->0x6a0d4
			break;
		
		case 207:
			//0x69c2c
			Data_400022f2[bData_4000318a - 1] = '0';
			Data_400027df[bData_4000318a - 1] = '0';
		
			func_57a4c();
			break;
		
		case 29002:
			//0x69c64
		case 205:
			//0x69c6c
		case 208:
			//0x69c70
			if (bData_4000318a != 5)
			{
				Data_40002302[bData_4000318a - 1] = '0';
				Data_400027ef[bData_4000318a - 1] = '0';
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
			//0x69d30
		case 206:
			//0x69d38
			switch (bData_400031e8)
			{
				case '0':
					//69d50
					bData_400031e8 = ' ';
					break;
				
				case ' ':
					//0x69d64
					bData_400031e8 = '0';
					break;
				
				default:
					//0x69d78
					bData_400031e8 = '0';
					break;
			}
			Data_400027ff[bData_4000318a - 1] = bData_400031e8;			
			break;
		
		case 48001:
			//0x69e54
			if (bData_4000318a != 1)
			{
				Data_400037cc[bData_4000318a - 1] = '0';
				Data_400037dc[bData_4000318a - 1] = '0';
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
			//0x69f18
			if (bData_40002e78 == 0)
			{
				Data_40002655[bData_4000318a - 1] = '0';
				Data_400037ec[bData_4000318a - 1] = '0';
			}
			else
			{
				Data_40002660[bData_4000318a - 1] = '0';
				Data_40003150[bData_4000318a - 1] = '0';
			}

			func_5718c();
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x69f90
			func_62524(0);
			//->0x6a0d4
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x69fa0
			func_623d0(0);
			break;
		
		case 34001:
			//0x69fb0
			Data_4000294a[bData_4000318a - 1] = '0';
			strEng00000s[bData_4000318a - 1] = '0';
		
			func_56d0c();
			break;
		
		case 35001:
			//0x69fe8
			Data_40002a3f[bData_4000318a - 1] = '0';
			strEngAlarm21h34m23s[bData_4000318a - 1] = '0';
		
			func_56c4c();
			break;
		
		case 360021:
			//0x6a020
		case 370021:
			//0x6a028
			Data_40002474[bData_4000318a - 1] = '0';
			Data_400024c9[bData_4000318a - 1] = '0';
		
			func_56ac8();
			break;
		
		case 360022:
			//0x6a05c
		case 370022:
			//0x6a064
			Data_40002481[bData_4000318a - 1] = '0';
			Data_400024d6[bData_4000318a - 1] = '0';
		
			func_56bf8();
			break;
		
		case 370023:
			//0x6a098
			Data_400024e1[bData_4000318a - 1] = '0';
		
			func_56b54();
			break;
		
		case 211001:
			//0x6a0bc
			func_61ecc(0);
			break;
		
		default:
			//0x6a0cc
			break;
	}
}

