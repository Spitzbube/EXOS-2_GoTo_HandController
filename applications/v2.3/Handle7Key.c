

/* 64324 - todo */
void Handle7Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x644e8
			g_eSlewRateIndex = SLEW_RATE_256X; //7;
			//->0x64e0c
			break;
		
		case 101:
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//64508
			bData_4000319a_SkyLandTargetId = 7;
			break;
		
		case 5000:
			//64518
			g_eSlewRateIndex = SLEW_RATE_256X; //7;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//64540
			g_eSlewRateIndex = SLEW_RATE_256X; //7;
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
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//648c4
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '7';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '7';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//648f8
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '7';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '7';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//6493c
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '7';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '7';
			}
			else
			{
				//0x6497c
				if (Data_40002302[bCharacterInputPosition - 1] == '+')
				{
					Data_40002302[bCharacterInputPosition - 1] = '-';
					strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '-';
				}
				else
				{
					//0x649c8
					Data_40002302[bCharacterInputPosition - 1] = '-'; //'+'; //BUG! 
					strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '-'; //'+'; //BUG! 
				}
			}
			
			func_57a4c();
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//64a04
			switch (bCustomerObjectNameChar)
			{
				case '7':
					//0x64a60
					bCustomerObjectNameChar = 'p';
					break;
				
				case 'p': //112:
					//0x64a74
					bCustomerObjectNameChar = 'q';
					break;
				
				case 'q': //113:
					//0x64a88
					bCustomerObjectNameChar = 'r';
					break;
				
				case 'r': //114:
					//0x64a9c
					bCustomerObjectNameChar = 's';
					break;
				
				case 's': //115:
					//0x64ab0
					bCustomerObjectNameChar = 'P';
					break;
				
				case 'P': //80:
					//0x64ac4
					bCustomerObjectNameChar = 'Q';
					break;
				
				case 'Q': //81:
					//0x64ad8
					bCustomerObjectNameChar = 'R';
					break;
				
				case 'R': //82:
					//0x64aec
					bCustomerObjectNameChar = 'S';
					break;
				
				case 'S': //83
					//0x64b00
					bCustomerObjectNameChar = '7';
					break;
				
				default:
					//0x64b14
					bCustomerObjectNameChar = '7';
					break;
			}
			//0x64b28
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//64b4c
			if (bCharacterInputPosition != 1)
			{
				//64b60
				strTrackingRateCustInput[bCharacterInputPosition - 1] = '7';
				strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '7';
			}
			else
			{
				//0x64b90
				if (strTrackingRateCustInput[bCharacterInputPosition - 1] == '+')
				{
					strTrackingRateCustInput[bCharacterInputPosition - 1] = '-';
					strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '-';
				}
				else
				{
					strTrackingRateCustInput[bCharacterInputPosition - 1] = '+';
					strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '+';
				}
			}
			//0x64c08
			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//64c10
			if (bDateTimeInputMode == 0)
			{
				//64c24
				Data_40002655[bCharacterInputPosition - 1] = '7';
				Data_400037ec[bCharacterInputPosition - 1] = '7';
			}
			else
			{
				//0x64c54
				Data_40002660[bCharacterInputPosition - 1] = '7';
				Data_40003150[bCharacterInputPosition - 1] = '7';
			}
			//0x64c80
			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//64c88
			HandleCustomSiteInputChar(7);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//64c98
			func_623d0(7);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//64ca8
			Data_4000294a[bCharacterInputPosition - 1] = '7';
			strEng00000s[bCharacterInputPosition - 1] = '7';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//64ce0
			Data_40002a3f[bCharacterInputPosition - 1] = '7';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '7';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//64d20
			Data_40002474[bCharacterInputPosition - 1] = '7';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '7';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//64d9c
			Data_40002481[bCharacterInputPosition - 1] = '7';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '7';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//64dd0
			strEyepieceFovInput[bCharacterInputPosition - 1] = '7';
		
			HandleNextEyepieceFovInputPosition();
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

