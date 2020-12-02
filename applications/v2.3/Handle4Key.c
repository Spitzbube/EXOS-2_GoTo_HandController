

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
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//6655c
			bData_4000319a_SkyLandTargetId = 4;
			break;
		
		case 5000:
			//6656c
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_16; //4;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//66594
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_16; //4;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//665ac
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 4) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 4) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 4;
			}
			//0x62fbc
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//66634
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 4) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 4) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 4;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//666c8
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 4) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 4) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 4;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//6675c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 4) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 4) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 4;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//667f0
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 4) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 4) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 4;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//6687c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 4) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 4) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 4;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//66918
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '4';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '4';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//6694c
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '4';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '4';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//66990
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '4';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '4';
			}
			else
			{
				//0x669d0
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
			//66a58
			switch (bCustomerObjectNameChar)
			{
				case '4':
					//0x66aa4
					bCustomerObjectNameChar = 'g';
					break;
				
				case 'g': //103
					//0x66ab8
					bCustomerObjectNameChar = 'h';
					break;
				
				case 'h': //104
					//0x66acc
					bCustomerObjectNameChar = 'i';
					break;
				
				case 'i': //105
					//0x66ae0
					bCustomerObjectNameChar = 'G';
					break;
								
				case 'G': //71
					//0x66af4
					bCustomerObjectNameChar = 'H';
					break;
				
				case 'H': //72
					//0x66b08
					bCustomerObjectNameChar = 'I';
					break;
				
				case 'I': //73
					//0x66b1c
					bCustomerObjectNameChar = '4';
					break;
				
				default:
					//0x66b30
					bCustomerObjectNameChar = '4';
					break;
			}
			//0x66b44
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//66b68
			if (bCharacterInputPosition != 1)
			{
				strTrackingRateCustInput[bCharacterInputPosition - 1] = '4';
				strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '4';
			}
			else
			{
				//0x66bac
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
			//0x66c24
			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//66c2c
			if (bDateTimeInputMode == 0)
			{
				Data_40002655[bCharacterInputPosition - 1] = '4';
				Data_400037ec[bCharacterInputPosition - 1] = '4';
			}
			else
			{
				//0x66c70
				Data_40002660[bCharacterInputPosition - 1] = '4';
				Data_40003150[bCharacterInputPosition - 1] = '4';
			}
			//0x66c9c
			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//66ca4
			HandleCustomSiteInputChar(4);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//66cb4
			func_623d0(4);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//66cc4
			Data_4000294a[bCharacterInputPosition - 1] = '4';
			strEng00000s[bCharacterInputPosition - 1] = '4';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//66cfc
			Data_40002a3f[bCharacterInputPosition - 1] = '4';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '4';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//66d3c
			Data_40002474[bCharacterInputPosition - 1] = '4';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '4';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//66d78
			Data_40002481[bCharacterInputPosition - 1] = '4';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '4';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//66df4
			strEyepieceFovInput[bCharacterInputPosition - 1] = '4';
		
			HandleNextEyepieceFovInputPosition();
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

