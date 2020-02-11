

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
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
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
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 5) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 5) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 5;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//65b50
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 5) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 5) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 5;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//65be4
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 5) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 5) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 5;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//65c78
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 5) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 5) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 5;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//65d74
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 5) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 5) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 5;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//65e00
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 5) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 5) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 5;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//65e9c
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '5';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '5';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//65ed0
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '5';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '5';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//65f14
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '5';
				Data_400027ef[bCharacterInputPosition - 1] = '5';
			}
			else
			{
				//0x65f54
				if (Data_40002302[bCharacterInputPosition - 1] == '+')
				{
					Data_40002302[bCharacterInputPosition - 1] = '-';
					Data_400027ef[bCharacterInputPosition - 1] = '-';
				}
				else
				{
					Data_40002302[bCharacterInputPosition - 1] = '+';
					Data_400027ef[bCharacterInputPosition - 1] = '+';
				}
			}
			
			func_57a4c();
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//65fdc
			switch (bCustomerObjectNameChar)
			{
				case '5':
					//0x66028
					bCustomerObjectNameChar = 'j';
					break;
				
				case 'j': //106:
					//0x6603c
					bCustomerObjectNameChar = 'k';
					break;
				
				case 'k': //107
					//0x66050
					bCustomerObjectNameChar = 'l';
					break;
				
				case 'l': //108
					//0x66064
					bCustomerObjectNameChar = 'J';
					break;
				
				case 'J': //74:
					//0x66078
					bCustomerObjectNameChar = 'K';
					break;
				
				case 'K': //75:
					//0x6608c
					bCustomerObjectNameChar = 'L';
					break;
				
				case 'L': //76:
					//0x660a0
					bCustomerObjectNameChar = '5';
					break;
								
				default:
					//0x660b4
					bCustomerObjectNameChar = '5';
					break;
			}
			//0x660c8
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case 48001:
			//660ec
			if (bCharacterInputPosition != 1)
			{
				Data_400037cc[bCharacterInputPosition - 1] = '5';
				Data_400037dc[bCharacterInputPosition - 1] = '5';
			}
			else
			{
				//0x66130
				if (Data_400037cc[bCharacterInputPosition - 1] == '+')
				{
					Data_400037cc[bCharacterInputPosition - 1] = '-';
					Data_400037dc[bCharacterInputPosition - 1] = '-';
				}
				else
				{
					Data_400037cc[bCharacterInputPosition - 1] = '+';
					Data_400037dc[bCharacterInputPosition - 1] = '+';
				}
			}
			//0x661a8
			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//661b0
			if (bDateTimeInputMode == 0)
			{
				Data_40002655[bCharacterInputPosition - 1] = '5';
				Data_400037ec[bCharacterInputPosition - 1] = '5';
			}
			else
			{
				//0x661f4
				Data_40002660[bCharacterInputPosition - 1] = '5';
				Data_40003150[bCharacterInputPosition - 1] = '5';
			}
			//0x66220
			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//66228
			HandleCustomSiteInputChar(5);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//66238
			func_623d0(5);
			break;
		
		case 34001:
			//66248
			Data_4000294a[bCharacterInputPosition - 1] = '5';
			strEng00000s[bCharacterInputPosition - 1] = '5';
		
			func_56d0c();
			break;
		
		case 35001:
			//66280
			Data_40002a3f[bCharacterInputPosition - 1] = '5';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '5';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//662c0
			Data_40002474[bCharacterInputPosition - 1] = '5';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '5';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//662fc
			Data_40002481[bCharacterInputPosition - 1] = '5';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '5';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//66330
			strEyepieceFovInput[bCharacterInputPosition - 1] = '5';
		
			HandleNextEyepieceFovInputPosition();
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

