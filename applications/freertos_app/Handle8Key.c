

/* 637e8 - todo */
void Handle8Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x639ac
			g_eSlewRateIndex = SLEW_RATE_512X; //8;
			//->0x64318
			break;
		
		case 101:
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//639cc
			bData_4000319a_SkyLandTargetId = 8;
			break;
		
		case 5000:
			//639dc
			g_eSlewRateIndex = SLEW_RATE_512X; //8;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//63a04
			g_eSlewRateIndex = SLEW_RATE_512X; //8;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//63adc
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}
			//0x63b30
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//63b64
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//63bf8
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//63c8c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//63d20
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//63dac
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 8) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 8) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 8;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//63e48
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '8';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '8';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//63e7c
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '8';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '8';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//63ec0
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '8';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '8';
			}
			else
			{
				//0x63f00
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
			//63f88
			switch (bCustomerObjectNameChar)
			{
				case '8':
					//0x63fd4
					bCustomerObjectNameChar = 't';
					break;
				
				case 't': //116:
					//0x63fe8
					bCustomerObjectNameChar = 'u';
					break;
				
				case 'u': //117:
					//0x63ffc
					bCustomerObjectNameChar = 'v';
					break;
				
				case 'v': //118:
					//0x64010
					bCustomerObjectNameChar = 'T';
					break;
								
				case 'T': //84:
					//0x64024
					bCustomerObjectNameChar = 'U';
					break;
				
				case 'U': //85:
					//0x64038
					bCustomerObjectNameChar = 'V';
					break;
				
				case 'V': //86:
					//0x6404c
					bCustomerObjectNameChar = '8';
					break;
				
				default:
					//0x64060
					bCustomerObjectNameChar = '8';
					break;
			}
			//0x64074
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//64098
			if (bCharacterInputPosition != 1)
			{
				//640ac
				strTrackingRateCustInput[bCharacterInputPosition - 1] = '8';
				strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '8';
			}
			else
			{
				//0x640dc
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
			//0x64154
			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//6415c
			if (bDateTimeInputMode == 0)
			{
				//64170
				Data_40002655[bCharacterInputPosition - 1] = '8';
				Data_400037ec[bCharacterInputPosition - 1] = '8';
			}
			else
			{
				//0x641a0
				Data_40002660[bCharacterInputPosition - 1] = '8';
				Data_40003150[bCharacterInputPosition - 1] = '8';
			}
			//0x641cc
			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//641d4
			HandleCustomSiteInputChar(8);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//641e4
			func_623d0(8);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//641f4
			Data_4000294a[bCharacterInputPosition - 1] = '8';
			strEng00000s[bCharacterInputPosition - 1] = '8';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//6422c
			Data_40002a3f[bCharacterInputPosition - 1] = '8';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '8';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//6426c
			Data_40002474[bCharacterInputPosition - 1] = '8';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '8';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//642a8
			Data_40002481[bCharacterInputPosition - 1] = '8';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '8';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//642dc
			strEyepieceFovInput[bCharacterInputPosition - 1] = '8';
		
			HandleNextEyepieceFovInputPosition();
			break;
		
		case 211001:
			//64300
			func_61ecc(8);
			break;
		
		default:
			//0x64310
			break;
	}
}

