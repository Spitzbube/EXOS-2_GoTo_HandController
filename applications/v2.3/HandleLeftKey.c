

/* 583dc - todo */
void func_583dc(void)
{
	switch (bData_40003263)
	{
		case 1:
			//0x583f8
		case 3:
			//0x58400
			switch (bData_40003260)
			{
				case 0:
					//0x58424
					if (bCharacterInputPosition > 7)
					{
						bCharacterInputPosition--;
					}
					else
					{
						bCharacterInputPosition = 13;
					}
					break;
				
				case 1:
					//0x58460
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x5849c
							bCharacterInputPosition = 14;
							break;
						
						case 8:
							//0x584b0
							bCharacterInputPosition = 7;
							break;
						
						case 10:
							//0x584c4
							bCharacterInputPosition = 8;
							break;
						
						case 11:
							//0x584d8
							bCharacterInputPosition = 10;
							break;
						
						case 13:
							//0x584ec
							bCharacterInputPosition = 11;
							break;
						
						case 14:
							//0x58500
							bCharacterInputPosition = 13;
							break;
						
						default:
							//0x58514
							break;
					} //switch (bCharacterInputPosition)
					//->0x565f4
					break;
				
				case 2:
					//0x58524
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x58564
							bCharacterInputPosition = 15;
							break;
						
						case 8:
							//0x58578
							bCharacterInputPosition = 7;
							break;
						
						case 9:
							//0x5858c
							bCharacterInputPosition = 8;
							break;
												
						case 11:
							//0x585a0
							bCharacterInputPosition = 9;
							break;
						
						case 12:
							//0x585b4
							bCharacterInputPosition = 11;
							break;
						
						case 14:
							//0x585c8
							bCharacterInputPosition = 12;
							break;
						
						case 15:
							//0x585dc
							bCharacterInputPosition = 14;
							break;
						
						default:
							//0x585f0
							break;
					} //switch (bCharacterInputPosition)
					//->
					break;
				
				default:
					//0x58600
					break;
			} //switch (bData_40003260)
			
			break;
		
		default:
			//0x58610
			break;
	} //switch (bData_40003263)
}

/* 58620 - todo */
void func_58620(void)
{
	switch (bData_40003262)
	{
		case 1:
			//58630
			switch (bData_40003261)
			{
				case 0:
					//0x58658
					if (bCharacterInputPosition > 7)
					{
						bCharacterInputPosition--;
					}
					else
					{
						bCharacterInputPosition = 13;
					}
					//->0x56828
					break;
				
				case 1:
					//0x58694
					switch (bCharacterInputPosition)
					{
						case 7:
							bCharacterInputPosition = 15;
							break;

						case 8:
							bCharacterInputPosition = 7;
							break;

						case 9:
							bCharacterInputPosition = 8;
							break;

						case 11:
							bCharacterInputPosition = 9;
							break;

						case 12:
							bCharacterInputPosition = 11;
							break;

						case 14:
							bCharacterInputPosition = 12;
							break;

						case 15:
							bCharacterInputPosition = 14;
							break;

						default:
							break;
					}
					break;
				
				case 2:
					//0x58770
					switch (bCharacterInputPosition)
					{
						case 7:
							bCharacterInputPosition = 14;
							break;
						
						case 8:
							bCharacterInputPosition = 7;
							break;
						
						case 10:
							bCharacterInputPosition = 8;
							break;
						
						case 11:
							bCharacterInputPosition = 10;
							break;
						
						case 13:
							bCharacterInputPosition = 11;
							break;
						
						case 14:
							bCharacterInputPosition = 13;
							break;
						
						default:
							break;
					}
					break;
				
				default:
					//0x58834
					break;
			} //switch (bData_40003261)
			break;
		
		default:
			//0x58844
			break;
	} //switch (bData_40003262)
}

/* 58854 - todo */
void HandlePreviousCity(void)
{
	switch (wData_40003250)
	{
		case 3:
			//0x588f8
			if (wData_40003252 == 0)
			{
				wData_40003252 = 21;
			}
			else
			{
				wData_40003252--;
			}
			break;
		
		case 26:
			//0x58934
		case 35:
			//0x5893c
		case 77:
			//0x58940
			if (wData_40003252 == 0)
			{
				wData_40003252 = 2;
			}
			else
			{
				wData_40003252--;
			}
			break;
		
		case 40:
			//0x58978
		case 48:
			//0x58980
			if (wData_40003252 == 0)
			{
				wData_40003252 = 4;
			}
			else
			{
				wData_40003252--;
			}
			break;
		
		case 60:
			//0x589b8
		case 90:
			//0x589c0
		case 119:
			//0x589c4
		case 150:
			//0x589c8
		case 152:
			//0x589cc
		case 156:
			//0x589d0
			if (wData_40003252 == 0)
			{
				wData_40003252 = 1;
			}
			else
			{
				wData_40003252--;
			}
			break;
		
		case 64:
			//0x58a08
		case 134:
			//0x58a10
			if (wData_40003252 == 0)
			{
				wData_40003252 = 8;
			}
			else
			{
				wData_40003252--;
			}
			break;
		
		case 82:
			//0x58a48
			if (wData_40003252 == 0)
			{
				wData_40003252 = 6;
			}
			else
			{
				wData_40003252--;
			}
			break;
		
		case 99:
			//0x58a84
			if (wData_40003252 == 0)
			{
				wData_40003252 = 5;
			}
			else
			{
				wData_40003252--;
			}
			break;
		
		default:
			//0x58ac0
			wData_40003252 = 0;
			break;
	}
}

/* 58adc - todo */
void func_58adc(void)
{
	switch (bCharacterInputPosition)
	{
		case 7:
			bCharacterInputPosition = 10;
			break;
		
		case 8:
			bCharacterInputPosition = 7;
			break;
		
		case 9:
			bCharacterInputPosition = 8;
			break;
		
		case 10:
			bCharacterInputPosition = 9;
			break;
		
		default:
			break;
	}
}

/* 58b68 - todo */
void func_58b68(void)
{
	switch (bCharacterInputPosition)
	{
		case 7:
			bCharacterInputPosition = 12;
			break;
		
		case 12:
			bCharacterInputPosition = 11;
			break;
		
		case 11:
			bCharacterInputPosition = 9;
			break;
		
		case 9:
			bCharacterInputPosition = 8;
			break;
		
		case 8:
			bCharacterInputPosition = 7;
			break;
		
		default:
			break;
	}
}

/* 58c0c - todo */
void func_58c0c(void)
{
	switch (bCharacterInputPosition)
	{
		case 7:
			bCharacterInputPosition = 8;
			break;
		
		case 8:
			bCharacterInputPosition = 7;
			break;
				
		default:
			break;
	}
}

/* 58c60 - todo */
void func_58c60(void)
{
	switch (bCharacterInputPosition)
	{
		case 1:
			bCharacterInputPosition = 8;
			break;
		
		case 2:
			bCharacterInputPosition = 1;
			break;
		
		case 4:
			bCharacterInputPosition = 2;
			break;
		
		case 5:
			bCharacterInputPosition = 4;
			break;
		
		case 7:
			bCharacterInputPosition = 5;
			break;
		
		case 8:
			bCharacterInputPosition = 7;
			break;
		
		default:
			break;
	}
}

/* 58d20 - todo */
void HandlePrevTimerInputPosition(void)
{
	switch (bCharacterInputPosition)
	{
		case 1:
			bCharacterInputPosition = 5;
			break;
		
		case 2:
			bCharacterInputPosition = 1;
			break;
		
		case 3:
			bCharacterInputPosition = 2;
			break;
		
		case 4:
			bCharacterInputPosition = 3;
			break;
		
		case 5:
			bCharacterInputPosition = 4;
			break;
		
		default:
			break;
	}
}

/* 58dc0 - todo */
void func_58dc0(void)
{
	switch (bData_4000316d)
	{
		case 0:
			if (bCharacterInputPosition > 5)
			{
				bCharacterInputPosition--;
			}
			else
			{
				bCharacterInputPosition = 7;
			}
			break;
		
		case 1:
			if (bCharacterInputPosition > 6)
			{
				bCharacterInputPosition--;
			}
			else
			{
				bCharacterInputPosition = 7;
			}
			break;
		
		default:
			break;
	}
}

/* 58e64 - complete */
void HandlePrevCustomSiteInputPosition(void)
{
	switch (bData_40002edc)
	{
		case 1:
		case 3:
			switch (bCurrentCustomSiteInputLine)
			{
				case 0: //Name
					if (bCharacterInputPosition > 7)
					{
						bCharacterInputPosition--;
					}
					else
					{
						bCharacterInputPosition = 14;
					}
					break;

				case 1: //Longitude
					switch (bCharacterInputPosition)
					{
						case 7:
							bCharacterInputPosition = 13;
							break;
						
						case 13:
							bCharacterInputPosition = 12;
							break;
						
						case 12:
							bCharacterInputPosition = 10;
							break;
						
						case 10:
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							bCharacterInputPosition = 7;
							break;
						
						default:
							break;
					}
					break;

				case 2: //Latitude
					switch (bCharacterInputPosition)
					{
						case 7:
							bCharacterInputPosition = 12;
							break;
						
						case 12:
							bCharacterInputPosition = 11;
							break;
												
						case 11:
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							bCharacterInputPosition = 7;
							break;
						
						default:
							break;
					}
					break;

				case 3: //Time Zone
					switch (bCharacterInputPosition)
					{
						case 7:
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							bCharacterInputPosition = 8;
							break;
																		
						case 8:
							bCharacterInputPosition = 7;
							break;
						
						default:
							break;
					}
					break;

				case 4:
					switch (bCharacterInputPosition)
					{
						case 7:
							bCharacterInputPosition = 10;
							break;
						
						case 10:
							bCharacterInputPosition = 9;
							break;
																		
						case 9:
							bCharacterInputPosition = 8;
							break;
																		
						case 8:
							bCharacterInputPosition = 7;
							break;
						
						default:
							break;
					}
					break;

				default:
					break;
			}			
			break;
		
		default:
			break;
	}
}

/* 591b8 - todo */
void HandlePrevDateTimeInputPosition(void)
{
	switch (bDateTimeInputMode)
	{
		case 0:
			switch (bCharacterInputPosition)
			{
				case 1:
					bCharacterInputPosition = 10;
					break;

				case 10:
					bCharacterInputPosition = 9;
					break;

				case 9:
					bCharacterInputPosition = 7;
					break;

				case 7:
					bCharacterInputPosition = 6;
					break;

				case 6:
					bCharacterInputPosition = 4;
					break;

				case 4:
					bCharacterInputPosition = 3;
					break;

				case 3:
					bCharacterInputPosition = 2;
					break;

				case 2:
					bCharacterInputPosition = 1;
					break;

				default:
					break;
			}
			break;
		
		case 1:
			switch (bCharacterInputPosition)
			{
				case 1:
					bCharacterInputPosition = 8;
					break;

				case 8:
					bCharacterInputPosition = 7;
					break;

				case 7:
					bCharacterInputPosition = 5;
					break;

				case 5:
					bCharacterInputPosition = 4;
					break;

				case 4:
					bCharacterInputPosition = 2;
					break;

				case 2:
					bCharacterInputPosition = 1;
					break;

				default:
					break;
			}
			break;
		
		default:
			break;
	}
}

/* 5939c - complete */
void func_5939c(void)
{
	switch (bCharacterInputPosition)
	{
		case 1:
			bCharacterInputPosition = 6;
			break;

		case 6:
			bCharacterInputPosition = 5;
			break;
		
		case 5:
			bCharacterInputPosition = 3;
			break;

		case 3:
			bCharacterInputPosition = 2;
			break;

		case 2:
			bCharacterInputPosition = 1;
			break;

		default:
			break;
	}
}

/* 59440 - complete */
void func_59440(void)
{
	switch (bCharacterInputPosition)
	{
		case 5:
			bCharacterInputPosition = 15;
			break;

		case 15:
			bCharacterInputPosition = 13;
			break;

		case 13:
			bCharacterInputPosition = 12;
			break;
		
		case 12:
			bCharacterInputPosition = 10;
			break;

		case 10:
			bCharacterInputPosition = 9;
			break;

		case 9:
			bCharacterInputPosition = 7;
			break;

		case 7:
			bCharacterInputPosition = 6;
			break;

		case 6:
			bCharacterInputPosition = 5;
			break;

		default:
			break;
	}
}

/* 59534 - complete */
void func_59534(void)
{
	switch (bCharacterInputPosition)
	{
		case 6:
			bCharacterInputPosition = 15;
			break;

		case 15:
			bCharacterInputPosition = 13;
			break;
		
		case 13:
			bCharacterInputPosition = 12;
			break;

		case 12:
			bCharacterInputPosition = 10;
			break;

		case 10:
			bCharacterInputPosition = 9;
			break;

		case 9:
			bCharacterInputPosition = 7;
			break;

		case 7:
			bCharacterInputPosition = 6;
			break;

		default:
			break;
	}
}

/* 59610 - todo */
void func_59610(void)
{
	switch (wData_40002eda)
	{
		case 1:
			//0x5963c
			wData_40002eda = 10;
			break;
		
		case 10:
			//0x59650
			wData_40002eda = 100;
			break;
		
		case 100:
			//0x59664
			wData_40002eda = 1000;
			break;
		
		case 1000:
			//0x59678
			wData_40002eda = 10000;
			break;
		
		default:
			//0x5968c
			break;
	}
}

/* 5969c - todo */
void HandleLeftKey(void)
{
	func_59610();
	
	switch (Data_40002c64_MenuContextId)
	{
		case 29001:
			//0x598c0
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x598c8
			func_59534();
			break;
		
		case 29002:
			//0x598d0
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x598d8
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x598dc
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x598e0
			func_59440();
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x598e8
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x598f0
			bCharacterInputPosition--;
			if (bCharacterInputPosition < 6)
			{
				bCharacterInputPosition = 13;
			}
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x59924
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x5992c
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x59930
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x59934
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x59938
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x5993c
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x59940
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x59944
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x59948
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x5994c
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x59950
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			//0x59954
			if (g_bLandTarget == 0)
			{
				if ((Data_40004128.bTrackingActive != 0) && (g_bSlewingStop != 1))
				{
					//59984
					g_iSlewStepRaAxis = -1;
					bData_40003200 = 0;
					//->0x59a1c
				}
				else
				{
					//0x599a0
					if (bData_40002c1a == 1)
					{
						//599b0
						func_57414(1, 3, bData_40002e7d_RotatingSpeed);
						//->0x59a1c
					}
					else
					{
						//0x599c8
						func_57414(3, 3, bData_40002e7d_RotatingSpeed);
						//->0x59a1c
					}
				}
			}
			else
			{
				//0x599e0
				if (bData_40002c1a == 1)
				{
					//599f0
					func_57414(1, 3, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x59a08
					func_57414(3, 3, bData_40002e7d_RotatingSpeed);
				}
			}
			//-> 0x59dc4
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x59a20
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				//59a34
				g_iSlewStepRaAxis = -1;
				bData_40003200 = 0;
			}
			//0x59a4c -> 0x59dc4
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
			//0x59a50
			dRaBklashCorrStartAzimuth = dData_40002dc0_Azimuth;
		
			if (bData_40002c1a == 1)
			{
				//59a74
				func_57414(1, 3, MENU_ROTATING_SPEED_8); //3);
				
				bData_40002edd = 2;
			}
			else
			{
				//0x59a94
				func_57414(3, 3, MENU_ROTATING_SPEED_8); //3);
				
				bData_40002edd = 0;
			}
			//0x59ab0
			iBacklashCorrectionSlewing = 1;
			bRaBacklashCorrectionDirection = 2;
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT; //11103;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
			//0x59ad8
			if (bRaBacklashCorrectionDirection == 1)
			{
				//Slewing Left when started Right
				if (bData_40002c1a == 1)
				{
					//59afc
					func_57414(1, 3, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x59b14
					func_57414(3, 3, bData_40002e7d_RotatingSpeed);
				}
			}
			//0x59b28 -> 0x59dc4
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//0x59b2c
			func_5939c();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//0x59b38
			HandlePrevDateTimeInputPosition();
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x59b44
			HandlePrevCustomSiteInputPosition();
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x59b50
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//0x59b58
		case 101:
			//0x59b5c
			switch (bData_4000319a_SkyLandTargetId)
			{
				case 1:
					//0x59b98
					bData_4000319a_SkyLandTargetId = 3;
					break;
				
				case 3:
					//0x59bac
					bData_4000319a_SkyLandTargetId = 2;
					break;
				
				case 2:
					//0x59bc0
					bData_4000319a_SkyLandTargetId = 1;
					break;
				
				case 4:
					//0x59bd4
					bData_4000319a_SkyLandTargetId = 6;
					break;
				
				case 6:
					//0x59be8
					bData_4000319a_SkyLandTargetId = 5;
					break;
				
				case 5:
					//0x59bfc
					bData_4000319a_SkyLandTargetId = 4;
					break;
				
				case 7:
					//0x59c10
					bData_4000319a_SkyLandTargetId = 9;
					break;
				
				case 9:
					//0x59c24
					bData_4000319a_SkyLandTargetId = 8;
					break;
				
				case 8:
					//0x59c38
					bData_4000319a_SkyLandTargetId = 7;
					break;
				#if 0
				default:
					//0x59c4c
					break;
				#endif
			}
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x59c54
			func_58dc0();
			break;
		
		case 33001:
			//0x59c60
			if (Data_40003168_LunarPhaseMonth > 0)
			{
				Data_40003168_LunarPhaseMonth--;
			}
			else
			{
				//0x59c8c
				Data_40003168_LunarPhaseMonth = 12;
			}
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//0x59c9c
			HandlePrevTimerInputPosition();
			break;
		
		case MENU_CONTEXT_ALARM_INPUT: //35001:
			//0x59ca8
			func_58c60();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
			//0x59cb4
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//0x59cbc
			func_58c0c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//0x59cc4
			func_58b68();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
			//0x59cd0
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//0x59cd8
			func_58adc();
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x59ce0
			lcd_display_clear();
			HandlePreviousCity();
			//break;
		case 211001:
			//0x59cf0
			switch (bData_40003262)
			{
				case 1:
					//59d00
					func_58620();
					break;
				
				default:
					break;
			}
			break;
		
		case 28001:
			//0x59d1c
			switch (bData_40003263)
			{
				case 1:
					//0x59d3c
				case 3:
					//0x59d44
					func_583dc();
					break;
								
				default:
					//0x59d4c
					break;
			}
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_ON: //42001:
			//0x59d5c
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_OFF; //42002;
				bDaylightSavingTime = 0;
			}
			//0x59d88
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_OFF: //42002:
			//0x59d8c
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_ON; //42001;
				bDaylightSavingTime = 1;
			}
			break;
		
		default:
			//0x59dbc
			break;
	}
}

