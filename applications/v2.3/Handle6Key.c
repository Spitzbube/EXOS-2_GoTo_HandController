

/* 64e18 - todo */
void Handle6Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x64fdc
			g_eSlewRateIndex = SLEW_RATE_128X; //6;
			//->0x65888
			break;
		
		case 101:
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//64ffc
			bData_4000319a_SkyLandTargetId = 6;
			break;
		
		case 5000:
			//6500c
			g_eSlewRateIndex = SLEW_RATE_128X; //6;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//65034
			g_eSlewRateIndex = SLEW_RATE_128X; //6;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//6504c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 6) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 6) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 6;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//650d4
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 6) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 6) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 6;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//65168
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 6) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 6) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 6;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//651fc
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 6) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 6) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 6;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//65290
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 6) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 6) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 6;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//6531c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 6) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 6) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 6;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//653b8
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '6';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '6';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//653ec
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '6';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '6';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//65430
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '6';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '6';
			}
			else
			{
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
			//654f8
			switch (bCustomerObjectNameChar)
			{
				case '6':
					//0x65544
					bCustomerObjectNameChar = 'm';
					break;
				
				case 'm': //109:
					//0x65558
					bCustomerObjectNameChar = 'n';
					break;
				
				case 'n': //110:
					//0x6556c
					bCustomerObjectNameChar = 'o';
					break;
				
				case 'o': //111:
					//0x65580
					bCustomerObjectNameChar = 'M';
					break;
				
				case 'M': //77:
					//0x65594
					bCustomerObjectNameChar = 'N';
					break;
				
				case 'N': //78:
					//0x655a8
					bCustomerObjectNameChar = 'O';
					break;
				
				case 'O': //79:
					//0x655bc
					bCustomerObjectNameChar = '6';
					break;
				
				default:
					//0x655d0
					bCustomerObjectNameChar = '6';
					break;
			}
			//0x655e4
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//65608
			if (bCharacterInputPosition != 1)
			{
				//6561c
				strTrackingRateCustInput[bCharacterInputPosition - 1] = '6';
				strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '6';
			}
			else
			{
				//0x6564c
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
			//0x656c4
			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//656cc
			if (bDateTimeInputMode == 0)
			{
				Data_40002655[bCharacterInputPosition - 1] = '6';
				Data_400037ec[bCharacterInputPosition - 1] = '6';
			}
			else
			{
				//0x65710
				Data_40002660[bCharacterInputPosition - 1] = '6';
				Data_40003150[bCharacterInputPosition - 1] = '6';
			}
			//0x6573c
			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//65744
			HandleCustomSiteInputChar(6);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//65754
			func_623d0(6);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//65764
			Data_4000294a[bCharacterInputPosition - 1] = '6';
			strEng00000s[bCharacterInputPosition - 1] = '6';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//6579c
			Data_40002a3f[bCharacterInputPosition - 1] = '6';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '6';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//657dc
			Data_40002474[bCharacterInputPosition - 1] = '6';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '6';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//65818
			Data_40002481[bCharacterInputPosition - 1] = '6';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '6';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//6584c
			strEyepieceFovInput[bCharacterInputPosition - 1] = '6';
		
			HandleNextEyepieceFovInputPosition();
			break;
		
		case 211001:
			//65870
			func_61ecc(6);
			break;
		
		default:
			//0x65880
			break;
	}
}

