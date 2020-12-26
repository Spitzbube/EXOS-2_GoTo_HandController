

/* 68934 - todo */
void Handle1Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x68af8
			g_eSlewRateIndex = SLEW_RATE_1X; //1;
			//->0x6933c
			break;
		
		case 101:
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//68b18
			bData_4000319a_SkyLandTargetId = 1;
			break;
		
		case 5000:
			//68b28
			g_eSlewRateIndex = SLEW_RATE_1X; //1;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//68b50
			g_eSlewRateIndex = SLEW_RATE_1X; //1;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//68b68
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}
			//0x62fbc
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//68bf0
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//68c84
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//68d18
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//68e28
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//68eb4
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 1) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 1) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 1;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//68f50
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '1';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '1';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//68f84
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '1';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '1';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//68fc8
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '1';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '1';
			}
			else
			{
				//0x6338c
				if (Data_40002302[bCharacterInputPosition - 1] == '+')
				{
					Data_40002302[bCharacterInputPosition - 1] = '-';
					strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '-';
				}
				else
				{
					Data_40002302[bCharacterInputPosition - 1] = '+';
					strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '+';
				}
			}
			
			func_57a4c();
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//69090
			bCustomerObjectNameChar = '1';
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//690bc
			if (bCharacterInputPosition != 1)
			{
				strTrackingRateCustInput[bCharacterInputPosition - 1] = '1';
				strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '1';
			}
			else
			{
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

			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//69180
			if (bDateTimeInputMode == 0)
			{
				Data_40002655[bCharacterInputPosition - 1] = '1';
				Data_400037ec[bCharacterInputPosition - 1] = '1';
			}
			else
			{
				Data_40002660[bCharacterInputPosition - 1] = '1';
				Data_40003150[bCharacterInputPosition - 1] = '1';
			}

			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//691f8
			HandleCustomSiteInputChar(1);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//69208
			func_623d0(1);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//69218
			Data_4000294a[bCharacterInputPosition - 1] = '1';
			strEng00000s[bCharacterInputPosition - 1] = '1';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//69250
			Data_40002a3f[bCharacterInputPosition - 1] = '1';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '1';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//69290
			Data_40002474[bCharacterInputPosition - 1] = '1';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '1';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//692cc
			Data_40002481[bCharacterInputPosition - 1] = '1';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '1';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//69300
			strEyepieceFovInput[bCharacterInputPosition - 1] = '1';
		
			HandleNextEyepieceFovInputPosition();
			break;
		
		case 211001:
			//69324
			func_61ecc(1);
			break;
		
		default:
			//0x69334
			break;
	}
}

