

/* 678b8 - todo */
void Handle2Key(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x67a7c
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_2; //2;
			//->0x68388
			break;
		
		case 101:
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//67a9c
			bData_4000319a_SkyLandTargetId = 2;
			break;
		
		case 5000:
			//67aac
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_2; //2;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//67ad4
			bData_40002e7d_RotatingSpeed = MENU_ROTATING_SPEED_2; //2;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//67aec
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 2) <= 110) && ((10*Data_40002ec8_NavigationDirectInputNr + 2) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 2;
			}
			//0x62fbc
			if ((Data_40002ec8_NavigationDirectInputNr <= 110) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eb8_MessierNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//67b74
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 2) <= 7840) && ((10*Data_40002ec8_NavigationDirectInputNr + 2) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 2;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 7840) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002eba_NGCNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//67c08
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 2) <= 5386) && ((10*Data_40002ec8_NavigationDirectInputNr + 2) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 2;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 5386) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebc_ICNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//67c9c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 2) <= 313) && ((10*Data_40002ec8_NavigationDirectInputNr + 2) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 2;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 313) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ebe_ShNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//67d90
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 2) <= 167) && ((10*Data_40002ec8_NavigationDirectInputNr + 2) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 2;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 167) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				wData_40002ec0_BrightStarNr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//67e1c
			lcd_display_clear();
		
			if (((10*Data_40002ec8_NavigationDirectInputNr + 2) <= 258997) && ((10*Data_40002ec8_NavigationDirectInputNr + 2) != 0))
			{
				Data_40002ec8_NavigationDirectInputNr = 10*Data_40002ec8_NavigationDirectInputNr + 2;
			}

			if ((Data_40002ec8_NavigationDirectInputNr <= 258997) && (Data_40002ec8_NavigationDirectInputNr != 0))
			{
				Data_40002ec4_SAONr = Data_40002ec8_NavigationDirectInputNr;
			}
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//67eb8
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '2';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '2';
		
			func_57b40();
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//67eec
			strCustomerObjectRaAziInputForTracking[bCharacterInputPosition - 1] = '2';
			strCustomerObjectRaAziInputForStoring[bCharacterInputPosition - 1] = '2';
		
			func_57a4c();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//67f30
			if (bCharacterInputPosition != 5)
			{
				Data_40002302[bCharacterInputPosition - 1] = '2';
				strCustomerObjectDecAltInputForStoring[bCharacterInputPosition - 1] = '2';
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
			//67ff8
			switch (bCustomerObjectNameChar)
			{
				case '2':
					//0x68044
					bCustomerObjectNameChar = 'a';
					break;
				
				case 'a': //97
					//0x68058
					bCustomerObjectNameChar = 'b';
					break;
				
				case 'b': //98
					//0x6806c
					bCustomerObjectNameChar = 'c';
					break;
				
				case 'c': //99
					//0x68080
					bCustomerObjectNameChar = 'A';
					break;
								
				case 'A': //65
					//0x68094
					bCustomerObjectNameChar = 'B';
					break;
				
				case 'B': //66
					//0x680a8
					bCustomerObjectNameChar = 'C';
					break;
				
				case 'C': //67
					//0x680bc
					bCustomerObjectNameChar = '2';
					break;
				
				default:
					//0x680d0
					bCustomerObjectNameChar = '2';
					break;
			}

			strCustomerObjectNameInput[bCharacterInputPosition - 1] = bCustomerObjectNameChar;
			break;
		
		case 48001:
			//68108
			if (bCharacterInputPosition != 1)
			{
				Data_400037cc[bCharacterInputPosition - 1] = '2';
				Data_400037dc[bCharacterInputPosition - 1] = '2';
			}
			else
			{
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

			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//681cc
			if (bDateTimeInputMode == 0)
			{
				Data_40002655[bCharacterInputPosition - 1] = '2';
				Data_400037ec[bCharacterInputPosition - 1] = '2';
			}
			else
			{
				Data_40002660[bCharacterInputPosition - 1] = '2';
				Data_40003150[bCharacterInputPosition - 1] = '2';
			}

			HandleNextDateTimeInputPosition();
			break;
			
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//68244
			HandleCustomSiteInputChar(2);
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//68254
			func_623d0(2);
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//68264
			Data_4000294a[bCharacterInputPosition - 1] = '2';
			strEng00000s[bCharacterInputPosition - 1] = '2';
		
			HandleNextTimerInputPosition();
			break;
		
		case 35001:
			//6829c
			Data_40002a3f[bCharacterInputPosition - 1] = '2';
			strEngAlarm21h34m23s[bCharacterInputPosition - 1] = '2';
		
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//682dc
			Data_40002474[bCharacterInputPosition - 1] = '2';
			strEyepieceFovMfInput[bCharacterInputPosition - 1] = '2';
		
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//68318
			Data_40002481[bCharacterInputPosition - 1] = '2';
			strEyepieceFovSfInput[bCharacterInputPosition - 1] = '2';
		
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//6834c
			strEyepieceFovInput[bCharacterInputPosition - 1] = '2';
		
			HandleNextEyepieceFovInputPosition();
			break;
		
		case 211001:
			//68370
			func_61ecc(2);
			break;
		
		default:
			//0x68380
			break;
	}
}

