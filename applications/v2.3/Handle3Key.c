

/* 66e3c - todo */
void Handle3Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x67000
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
			//->0x678ac
			break;
		
		case 101:
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//67020
			bData_4000319a_SkyLandTargetId = 3;
			break;
		
		case 5000:
			//67030
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//67058
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_8; //3;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//67070
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 3) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 3) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 3;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//670f8
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 3) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 3) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 3;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//6718c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 3) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 3) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 3;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//67220
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 3) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 3) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 3;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//672b4
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 3) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 3) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 3;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//67340
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 3) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 3) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 3;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//673dc
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '3';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '3';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//67410
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '3';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '3';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//67454
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '3';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '3';
			}
			else
			{
				//0x67494
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
			//6751c
			switch (bCustomerObjectNameChar)
			{
				case '3':
					//0x67568
					bCustomerObjectNameChar = 'd';
					break;
				
				case 'd': //100
					//0x6757c
					bCustomerObjectNameChar = 'e';
					break;
				
				case 'e': //101
					//0x67590
					bCustomerObjectNameChar = 'f';
					break;
				
				case 'f': //102
					//0x675a4
					bCustomerObjectNameChar = 'D';
					break;
								
				case 'D': //68
					//0x675b8
					bCustomerObjectNameChar = 'E';
					break;
				
				case 'E': //69
					//0x675cc
					bCustomerObjectNameChar = 'F';
					break;
				
				case 'F': //70
					//0x675e0
					bCustomerObjectNameChar = '3';
					break;
								
				default:
					//0x675f4
					bCustomerObjectNameChar = '3';
					break;
			}
			//0x67608
			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case 48001:
			//6762c
			if (bCharacterInputPosition != 1)
			{
				Data_400037cc[bCharacterInputPosition - 1] = '3';
				Data_400037dc[bCharacterInputPosition - 1] = '3';
			}
			else
			{
				//0x67670
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
			//0x676e8
			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//676f0
			if (bDateTimeInputMode == 0)
			{
				Data_40002655[bCharacterInputPosition - 1] = '3';
				Data_400037ec[bCharacterInputPosition - 1] = '3';
			}
			else
			{
				//0x67734
				Data_40002660[bCharacterInputPosition - 1] = '3';
				Data_40003150[bCharacterInputPosition - 1] = '3';
			}
			//0x67760
			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//67768
			HandleCustomSiteInputChar(3);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//67778
			func_623d0(3);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//67788
			Data_4000294a[bCharacterInputPosition - 1] = '3';
			strEng00000s[bCharacterInputPosition - 1] = '3';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//677c0
			Data_40002a3f[bCharacterInputPosition - 1] = '3';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '3';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//67800
			Data_40002474[bCharacterInputPosition - 1] = '3';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '3';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//6783c
			Data_40002481[bCharacterInputPosition - 1] = '3';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '3';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//67870
			strEyepieceFovInput[bCharacterInputPosition - 1] = '3';
		
			HandleNextEyepieceFovInputPosition();
			break;
		
		case 211001:
			//67894
			func_61ecc(3);
			break;
		
		default:
			//0x678a4
			break;
	}
}

