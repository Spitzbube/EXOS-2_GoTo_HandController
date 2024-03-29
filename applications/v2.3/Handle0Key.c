

/* 69348 - todo */
void Handle0Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x6958c
			if (g_bLandTarget == 0)
			{
				if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
				{
					if (g_bSlewingStop == 0)
					{
						g_bSlewingStop = 1;
						
						StopSlewing();
						//->0x69780
					}
					else
					{
						//0x695d4
						g_bSlewingStop = 0;

						convert_horizontal_to_equatorial(dData_40002dc0_Azimuth + dData_400033e8,
							dData_40002df8 + dData_400033f0,
							&dData_40002c88, &dData_40002c90);
						
						GotoEQCoordinates(dData_40002c88, dData_40002c90);
						
						bData_400034cc = 1;
						
						ResumeSlewing();
						//->0x69780
					}
				} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
				else
				{
					//0x69658
					if (g_bSlewingStop == 0)
					{
						g_bSlewingStop = 1;
						
						StopSlewing();
						//->0x69780
					}
					else
					{
						//0x6967c
						g_bSlewingStop = 0;
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
						
						GotoEQCoordinates(dData_40002c88, dData_40002c90);
						
						bData_400034cc = 1;
						
						ResumeSlewing();
					}
				}
			} //if (g_bLandTarget == 0)
			//0x69780 -> 0x6a0d4
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x69784
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x6978c
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
			//0x69790
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
			//0x69794
			if (g_bSlewingStop == 0)
			{
				g_bSlewingStop = 1;
				
				StopSlewing();
			}
			else
			{
				//0x697b8
				g_bSlewingStop = 0;
				
				ResumeSlewing();
			}
			//->0x6a0d4
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x697cc
			if (Data_40004128.alignmentPause == 0)
			{
				Data_40004128.alignmentPause = 1;
			}
			else
			{
				Data_40004128.alignmentPause = 0;
			}
			break;
		
		case 101:
			//0x69800
			if (g_bKeyBeepEnabled == 0)
			{
				g_bKeyBeepEnabled = 1;
			}
			else
			{
				g_bKeyBeepEnabled = 0;
			}
			break;
		
		case 5000:
			//0x69834
			g_eSlewRateIndex = 0;
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
			if (bTrackingModeMenu == MENU_TRACKING_MODE_PAUSE) //4)
			{
				ResumeSlewing();
			}
			
			if ((bTrackingModeMenu == MENU_TRACKING_MODE_POINTING/*1*/) ||
					(bTrackingModeMenu == MENU_TRACKING_MODE_TRACKING/*2*/))
			{
				bTrackingModeMenu = MENU_TRACKING_MODE_PAUSE; //4;
				
				StopSlewing();
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
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x69bf8
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '0';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '0';
		
			func_57b40();
			//->0x6a0d4
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x69c2c
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '0';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '0';
		
			func_57a4c();
			break;
		
		case 29002:
			//0x69c64
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x69c6c
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x69c70
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '0';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '0';
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
			//0x69d30
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x69d38
			switch (bCustomerObjectNameChar)
			{
				case '0':
					//69d50
					bCustomerObjectNameChar = ' ';
					break;
				
				case ' ':
					//0x69d64
					bCustomerObjectNameChar = '0';
					break;
				
				default:
					//0x69d78
					bCustomerObjectNameChar = '0';
					break;
			}
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;			
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//0x69e54
			if (bCharacterInputPosition != 1)
			{
				strTrackingRateCustInput[bCharacterInputPosition - 1] = '0';
				strTrackingRateCustDisplay[bCharacterInputPosition - 1] = '0';
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
			//0x69f18
			if (bDateTimeInputMode == 0)
			{
				Data_40002655[bCharacterInputPosition - 1] = '0';
				Data_400037ec[bCharacterInputPosition - 1] = '0';
			}
			else
			{
				Data_40002660[bCharacterInputPosition - 1] = '0';
				Data_40003150[bCharacterInputPosition - 1] = '0';
			}

			HandleNextDateTimeInputPosition();
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x69f90
			HandleCustomSiteInputChar(0);
			//->0x6a0d4
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x69fa0
			func_623d0(0);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//0x69fb0
			Data_4000294a[bCharacterInputPosition - 1] = '0';
			strEng00000s[bCharacterInputPosition - 1] = '0';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//0x69fe8
			Data_40002a3f[bCharacterInputPosition - 1] = '0';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '0';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
			//0x6a020
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//0x6a028
			Data_40002474[bCharacterInputPosition - 1] = '0';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '0';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
			//0x6a05c
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//0x6a064
			Data_40002481[bCharacterInputPosition - 1] = '0';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '0';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//0x6a098
			strEyepieceFovInput[bCharacterInputPosition - 1] = '0';
		
			HandleNextEyepieceFovInputPosition();
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

