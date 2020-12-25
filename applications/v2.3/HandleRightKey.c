

/* 563c8 - todo */
void func_563c8(void)
{
	switch (bData_40003263)
	{
		case 1:
			//0x563e4
		case 3:
			//0x563ec
			switch (bData_40003260)
			{
				case 0:
					//0x56410
					if (bCharacterInputPosition < 13)
					{
						//56424
						bCharacterInputPosition++;
					}
					else
					{
						//0x5643c
						bCharacterInputPosition = 7;
					}
					//0x56448 -> 0x565f4
					break;
				
				case 1:
					//0x5644c
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x56488
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							//0x5649c
							bCharacterInputPosition = 10;
							break;
						
						case 10:
							//0x564b0
							bCharacterInputPosition = 11;
							break;
						
						case 11:
							//0x564c4
							bCharacterInputPosition = 13;
							break;
						
						case 13:
							//0x564d8
							bCharacterInputPosition = 14;
							break;
						
						case 14:
							//0x564ec
							bCharacterInputPosition = 7;
							break;
						
						default:
							//0x56500
							break;
					} //switch (bCharacterInputPosition)
					//->0x565f4
					break;
				
				case 2:
					//0x56510
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x56550
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							//0x56564
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							//0x56578
							bCharacterInputPosition = 11;
							break;
												
						case 11:
							//0x5658c
							bCharacterInputPosition = 12;
							break;
						
						case 12:
							//0x565a0
							bCharacterInputPosition = 14;
							break;
						
						case 14:
							//0x565b4
							bCharacterInputPosition = 15;
							break;
						
						case 15:
							//0x565c8
							bCharacterInputPosition = 7;
							break;
						
						default:
							//0x565dc
							break;
					} //switch (bCharacterInputPosition)
					//->
					break;
				
				default:
					//0x565ec
					break;
			} //switch (bData_40003260)
			
			break;
		
		default:
			//0x565fc
			break;
	} //switch (bData_40003263)
}

/* 5660c - todo */
void func_5660c(void)
{
	switch (bData_40003262)
	{
		case 1:
			//5661c
			switch (bData_40003261)
			{
				case 0:
					//0x56644
					if (bCharacterInputPosition < 13)
					{
						bCharacterInputPosition++;
					}
					else
					{
						//0x56670
						bCharacterInputPosition = 7;
					}
					//->0x56828
					break;
				
				case 1:
					//0x56680
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x566c0
							bCharacterInputPosition = 8;
							break;

						case 8:
							//0x566d4
							bCharacterInputPosition = 9;
							break;

						case 9:
							//0x566e8
							bCharacterInputPosition = 11;
							break;

						case 11:
							//0x566fc
							bCharacterInputPosition = 12;
							break;

						case 12:
							//0x56710
							bCharacterInputPosition = 14;
							break;

						case 14:
							//0x56724
							bCharacterInputPosition = 15;
							break;

						case 15:
							//0x56738
							bCharacterInputPosition = 7;
							break;

						default:
							//0x5674c
							break;
					}
					break;
				
				case 2:
					//0x5675c
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x56798
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							//0x567ac
							bCharacterInputPosition = 10;
							break;
						
						case 10:
							//0x567c0
							bCharacterInputPosition = 11;
							break;
						
						case 11:
							//0x567d4
							bCharacterInputPosition = 13;
							break;
						
						case 13:
							//0x567e8
							bCharacterInputPosition = 14;
							break;
						
						case 14:
							//0x567fc
							bCharacterInputPosition = 7;
							break;
						
						default:
							//0x56810
							break;
					}
					break;
				
				default:
					//0x56820
					break;
			} //switch (bData_40003261)
			break;
		
		default:
			//0x56830
			break;
	} //switch (bData_40003262)
}

/* 56840 - complete */
void HandleNextCity(void)
{
	switch (wData_40003250)
	{
		case 3:
			//0x568e4
			wData_40003252++;
			if (wData_40003252 > 21)
			{
				wData_40003252 = 0;
			}
			break;
		
		case 26:
			//0x56920
		case 35:
			//0x56928
		case 77:
			//0x5692c
			wData_40003252++;
			if (wData_40003252 > 2)
			{
				wData_40003252 = 0;
			}
			break;
		
		case 40:
			//0x56964
		case 48:
			//0x5696c
			wData_40003252++;
			if (wData_40003252 > 4)
			{
				wData_40003252 = 0;
			}
			break;
		
		case 60:
			//0x569a4
		case 90:
			//0x569ac
		case 119:
			//0x569b0
		case 150:
			//0x569b4
		case 152:
			//0x569b8
		case 156:
			//0x569bc
			wData_40003252++;
			if (wData_40003252 > 1)
			{
				wData_40003252 = 0;
			}
			break;
		
		case 64:
			//0x569f4
		case 134:
			//0x569fc
			wData_40003252++;
			if (wData_40003252 > 8)
			{
				wData_40003252 = 0;
			}
			break;
		
		case 82:
			//0x56a34
			wData_40003252++;
			if (wData_40003252 > 6)
			{
				wData_40003252 = 0;
			}
			break;
		
		case 99:
			//0x56a70
			wData_40003252++;
			if (wData_40003252 > 5)
			{
				wData_40003252 = 0;
			}
			break;
		
		default:
			//0x56aac
			wData_40003252 = 0;
			break;
	}
}

/* 56ac8 - todo */
void HandleNextMfInputPosition(void)
{
	switch (bCharacterInputPosition)
	{
		case 7:
			//0x56af4
			bCharacterInputPosition = 8;
			break;
		
		case 8:
			//0x56b08
			bCharacterInputPosition = 9;
			break;
		
		case 9:
			//0x56b1c
			bCharacterInputPosition = 10;
			break;
		
		case 10:
			//0x56b30
			bCharacterInputPosition = 7;
			break;
		
		default:
			//0x56b44
			break;
	}
}

/* 56b54 - todo */
void HandleNextEyepieceFovInputPosition(void)
{
	switch (bCharacterInputPosition)
	{
		case 7:
			//0x56b84
			bCharacterInputPosition = 8;
			break;
		
		case 8:
			//0x56b98
			bCharacterInputPosition = 9;
			break;
		
		case 9:
			//0x56bac
			bCharacterInputPosition = 11;
			break;
		
		case 11:
			//0x56bc0
			bCharacterInputPosition = 12;
			break;
		
		case 12:
			//0x56bd4
			bCharacterInputPosition = 7;
			break;
		
		default:
			//0x56be8
			break;
	}
}

/* 56bf8 - todo */
void HandleNextSfInputPosition(void)
{
	switch (bCharacterInputPosition)
	{
		case 7:
			//0x56c14
			bCharacterInputPosition = 8;
			break;
		
		case 8:
			//0x56c28
			bCharacterInputPosition = 7;
			break;
				
		default:
			//0x56be8
			break;
	}
}

/* 56c4c - todo */
void func_56c4c(void)
{
	switch (bCharacterInputPosition)
	{
		case 1:
			//0x56c84
			bCharacterInputPosition = 2;
			break;
		
		case 2:
			//0x56c98
			bCharacterInputPosition = 4;
			break;
		
		case 4:
			//0x56cac
			bCharacterInputPosition = 5;
			break;
		
		case 5:
			//0x56cc0
			bCharacterInputPosition = 7;
			break;
		
		case 7:
			//0x56cd4
			bCharacterInputPosition = 8;
			break;
		
		case 8:
			//0x56ce8
			bCharacterInputPosition = 1;
			break;
		
		default:
			//0x56cfc
			break;
	}
}

/* 56d0c - todo */
void HandleNextTimerInputPosition(void)
{
	switch (bCharacterInputPosition)
	{
		case 1:
			//0x56d38
			bCharacterInputPosition = 2;
			break;
		
		case 2:
			//0x56d4c
			bCharacterInputPosition = 3;
			break;
		
		case 3:
			//0x56d60
			bCharacterInputPosition = 4;
			break;
		
		case 4:
			//0x56d74
			bCharacterInputPosition = 5;
			break;
		
		case 5:
			//0x56d88
			bCharacterInputPosition = 1;
			break;
		
		default:
			break;
	}
}

/* 56dac - todo */
void func_56dac(void)
{
	switch (bData_4000316d)
	{
		case 0:
			//0x56dc8
			if (bCharacterInputPosition < 7)
			{
				bCharacterInputPosition++;
			}
			else
			{
				bCharacterInputPosition = 5;
			}
			break;
		
		case 1:
			//0x56e04
			if (bCharacterInputPosition < 7)
			{
				bCharacterInputPosition++;
			}
			else
			{
				bCharacterInputPosition = 6;
			}
			break;
		
		default:
			//0x56e40
			break;
	}
}

/* 56e50 - complete */
void HandleNextCustomSiteInputPosition(void)
{
	switch (bData_40002edc)
	{
		case 1:
			//0x56e6c
		case 3:
			//0x56e74
			switch (bCurrentCustomSiteInputLine)
			{
				case 0:
					//0x56e9c: Name
					if (bCharacterInputPosition < 14)
					{
						bCharacterInputPosition++;
					}
					else
					{
						bCharacterInputPosition = 7;
					}
					break;

				case 1:
					//0x56ed8: Longitude
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x56f10
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							//0x56f24
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							//0x56f38
							bCharacterInputPosition = 10;
							break;
						
						case 10:
							//0x56f4c
							bCharacterInputPosition = 12;
							break;
						
						case 12:
							//0x56f60
							bCharacterInputPosition = 13;
							break;
						
						case 13:
							//0x56f74
							bCharacterInputPosition = 7;
							break;
						
						default:
							//0x56f88
							break;
					}
					break;

				case 2:
					//0x56f98: Latitude
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x56fcc
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							//0x56fe0
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							//0x56ff4
							bCharacterInputPosition = 11;
							break;
						
						case 11:
							//0x57008
							bCharacterInputPosition = 12;
							break;
						
						case 12:
							//0x5701c
							bCharacterInputPosition = 7;
							break;
												
						default:
							//0x57030
							break;
					}
					break;

				case 3:
					//0x57040: Time Zone
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x57068
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							//0x5707c
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							//0x57090
							bCharacterInputPosition = 7;
							break;
																		
						default:
							//0x570a4
							break;
					}
					break;

				case 4:
					//0x570b4
					switch (bCharacterInputPosition)
					{
						case 7:
							//0x570e4
							bCharacterInputPosition = 8;
							break;
						
						case 8:
							//0x570f8
							bCharacterInputPosition = 9;
							break;
						
						case 9:
							//0x5710c
							bCharacterInputPosition = 10;
							break;
																		
						case 10:
							//0x57120
							bCharacterInputPosition = 7;
							break;
																		
						default:
							//0x57134
							break;
					}
					break;

				default:
					//0x57144
					break;
			}			
			break;
		
		default:
			//0x57154
			break;
	}
}

/* 5718c - complete */
void HandleNextDateTimeInputPosition(void)
{
	switch (bDateTimeInputMode)
	{
		case 0:
			//0x571a8
			switch (bCharacterInputPosition)
			{
				case 1:
					//0x571ec
					bCharacterInputPosition = 2;
					break;

				case 2:
					//0x57200
					bCharacterInputPosition = 3;
					break;

				case 3:
					//0x57214
					bCharacterInputPosition = 4;
					break;

				case 4:
					//0x57228
					bCharacterInputPosition = 6;
					break;

				case 6:
					//0x5723c
					bCharacterInputPosition = 7;
					break;

				case 7:
					//0x57250
					bCharacterInputPosition = 9;
					break;

				case 9:
					//0x57264
					bCharacterInputPosition = 10;
					break;

				case 10:
					//0x57278
					bCharacterInputPosition = 1;
					break;

				default:
					//0x5728c
					break;
			}
			break;
		
		case 1:
			//0x5729c
			switch (bCharacterInputPosition)
			{
				case 1:
					//0x572d8
					bCharacterInputPosition = 2;
					break;

				case 2:
					//0x572ec
					bCharacterInputPosition = 4;
					break;

				case 4:
					//0x57300
					bCharacterInputPosition = 5;
					break;

				case 5:
					//0x57314
					bCharacterInputPosition = 7;
					break;

				case 7:
					//0x57328
					bCharacterInputPosition = 8;
					break;

				case 8:
					//0x5733c
					bCharacterInputPosition = 1;
					break;

				default:
					//0x57350
					break;
			}
			break;
		
		default:
			//0x57360
			break;
	}
}

/* 57370 - todo */
void func_57370(void)
{
	switch (bCharacterInputPosition)
	{
		case 1:
			//0x573a0
			bCharacterInputPosition = 2;
			break;

		case 2:
			//0x573b4
			bCharacterInputPosition = 3;
			break;

		case 3:
			//0x573c8
			bCharacterInputPosition = 5;
			break;

		case 5:
			//0x573dc
			bCharacterInputPosition = 6;
			break;

		case 6:
			//0x573f0
			bCharacterInputPosition = 1;
			break;
		
		default:
			//0x57404
			break;
	}
}

#include "slew1.c"

/* 57a4c - complete */
void func_57a4c(void)
{
	switch (bCharacterInputPosition)
	{
		case 5:
			//0x57a90
			bCharacterInputPosition = 6;
			break;

		case 6:
			//0x57aa4
			bCharacterInputPosition = 7;
			break;

		case 7:
			//0x57ab8
			bCharacterInputPosition = 9;
			break;

		case 9:
			//0x57acc
			bCharacterInputPosition = 10;
			break;

		case 10:
			//0x57ae0
			bCharacterInputPosition = 12;
			break;

		case 12:
			//0x57af4
			bCharacterInputPosition = 13;
			break;

		case 13:
			//0x57b08
			bCharacterInputPosition = 15;
			break;
		
		case 15:
			//0x57b1c
			bCharacterInputPosition = 5;
			break;

		default:
			//0x57b30
			break;
	}
}

/* 57b40 - complete */
void func_57b40(void)
{
	switch (bCharacterInputPosition)
	{
		case 6:
			//0x57b80
			bCharacterInputPosition = 7;
			break;

		case 7:
			//0x57b94
			bCharacterInputPosition = 9;
			break;

		case 9:
			//0x57ba8
			bCharacterInputPosition = 10;
			break;

		case 10:
			//0x57bbc
			bCharacterInputPosition = 12;
			break;

		case 12:
			//0x57bd0
			bCharacterInputPosition = 13;
			break;

		case 13:
			//0x57be4
			bCharacterInputPosition = 15;
			break;

		case 15:
			//0x57bf8
			bCharacterInputPosition = 6;
			break;
		
		default:
			//0x57c0c
			break;
	}
}

/* 57c1c - todo */
void HandleRightKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 29001:
			//0x57e3c
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x57e44
			func_57b40();
			break;
		
		case 29002:
			//0x57e4c
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x57e54
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x57e58
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x57e5c
			func_57a4c();
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x57e64
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x57e6c
			bCharacterInputPosition++;
			if (bCharacterInputPosition > 13)
			{
				bCharacterInputPosition = 6;
			}
			//->0x583d0
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x57ea0
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x57ea8
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x57eac
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x57eb0
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x57eb4
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x57eb8
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x57ebc
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x57ec0
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x57ec4
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x57ec8
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x57ecc
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			//0x57ed0
			if (g_bLandTarget == 0)
			{
				//57ee0
				if ((Data_40004128.bTrackingActive != 0) && (g_bSlewingStop != 1))
				{
					//57f00
					g_iSlewStepRaAxis = 1;
					bData_40003200 = 0;
				}
				else
				{
					//0x57f1c
					if (bData_40002c1a == 1)
					{
						//57f2c
						SlewAxis(1, 4, g_eSlewRateIndex);
					}
					else
					{
						//0x57f44
						SlewAxis(3, 4, g_eSlewRateIndex);
					}
				}
			}
			else
			{
				//0x57f5c
				if (bData_40002c1a == 1)
				{
					//57f6c
					SlewAxis(1, 4, g_eSlewRateIndex);
				}
				else
				{
					//0x57f84
					SlewAxis(3, 4, g_eSlewRateIndex);
				}
			}
			//0x57f98 -> 0x583d0
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x57f9c
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				//57fb0
				g_iSlewStepRaAxis = 1;
				bData_40003200 = 0;
			}
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
			//0x57fcc
			dRaBklashCorrStartAzimuth = dData_40002dc0_Azimuth;
			if (bData_40002c1a == 1)
			{
				//57ff0
				SlewAxis(1, 4, SLEW_RATE_8X); //3);
				
				bData_40002edd = 2;
			}
			else
			{
				//0x58010
				SlewAxis(3, 4, SLEW_RATE_8X); //3);
				
				bData_40002edd = 0;
			}
			//0x5802c
			iBacklashCorrectionSlewing = 1;
			bRaBacklashCorrectionDirection = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT; //11103;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
			//0x58050
			if (bRaBacklashCorrectionDirection == 2)
			{
				//58064: Slewing Right when started Left
				if (bData_40002c1a == 1)
				{
					//58074
					SlewAxis(1, 4, g_eSlewRateIndex);
				}
				else
				{
					//0x58120
					SlewAxis(3, 4, g_eSlewRateIndex);
				}
			}
			//0x58134
			//break; //BUG: Fall through?
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//0x58138
			func_57370();
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//0x58140
			HandleNextDateTimeInputPosition();
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x5814c
			HandleNextCustomSiteInputPosition();
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x58158		
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//0x58160
		case 101:
			//0x58164
			switch (bData_4000319a_SkyLandTargetId)
			{
				case 1:
					//0x581a0
					bData_4000319a_SkyLandTargetId = 2;
					break;
				
				case 2:
					//0x581b4
					bData_4000319a_SkyLandTargetId = 3;
					break;
				
				case 3:
					//0x581c8
					bData_4000319a_SkyLandTargetId = 1;
					break;
				
				case 4:
					//0x581dc
					bData_4000319a_SkyLandTargetId = 5;
					break;
				
				case 5:
					//0x581f0
					bData_4000319a_SkyLandTargetId = 6;
					break;
				
				case 6:
					//0x58204
					bData_4000319a_SkyLandTargetId = 4;
					break;
				
				case 7:
					//0x58218
					bData_4000319a_SkyLandTargetId = 8;
					break;
				
				case 8:
					//0x5822c
					bData_4000319a_SkyLandTargetId = 9;
					break;
				
				case 9:
					//0x58240
					bData_4000319a_SkyLandTargetId = 7;
					break;
				
				#if 0
				default:
					//0x58254
					break;
				#endif
			}
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
			//0x5825c
			func_56dac();
			break;
		
		case 33001:
			//0x58268
			if (Data_40003168_LunarPhaseMonth < 12)
			{
				Data_40003168_LunarPhaseMonth++;
			}
			else
			{
				Data_40003168_LunarPhaseMonth = 0;
			}
			break;
		
		case MENU_CONTEXT_TIMER_SET: //34001:
			//0x582a4
			HandleNextTimerInputPosition();
			break;
		
		case MENU_CONTEXT_ALARM_INPUT: //35001:
			//0x582b0
			func_56c4c();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
			//0x582bc
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//0x582c4
			HandleNextSfInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//0x582cc
			HandleNextEyepieceFovInputPosition();
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
			//0x582d8
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//0x582e0
			HandleNextMfInputPosition();
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x582e8
			lcd_display_clear();
			HandleNextCity();
			break;
		
		case 211001:
			//0x582f8
			switch (bData_40003262)
			{
				case 1:
					//5830c
					func_5660c();
					break;
				
				default:
					break;
			}			
			break;
		
		case 28001:
			//0x58328
			switch (bData_40003263)
			{
				case 1:
					//0x58348
				case 3:
					//0x58350
					func_563c8();
					break;
								
				default:
					//0x59d4c
					break;
			}
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_ON: //42001:
			//0x58368
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_OFF; //42002;
				bDaylightSavingTime = 0;
			}
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_OFF: //42002:
			//0x58398
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_ON; //42001;
				bDaylightSavingTime = 1;
			}
			break;
		
		default:
			//0x583c8
			break;
	}
}

