

/* 52898 - todo */
void HandleEnterKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x52e68
			if (Data_40004128.bAlignmentComplete == 0)
			{
				//52e7c
				ProcessNextAlignmentStar();
			}
			else
			{
				//0x52e84
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT; //1000;
			}
			//->0x563b8
			break;
		
		case MENU_CONTEXT_MERIDIAN_FLIP: //3:
			//0x52e94
			bData_40003210 = 0;
			bData_40003211 = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case 101:
			//0x52eb8
			lcd_display_clear();
			Data_40002c64_MenuContextId = 102;		
			break;
		
		case 102:
			//0x52ed0
			switch (bData_40002e79_SkyLandTargetSeletion)
			{
				case 0:
					//0x52ef0
					func_5218(bData_4000319a_SkyLandTargetId, &Data_40003f50);
				
					if (Data_40003f50.bData_0 == 1)
					{
						//52f14
						dData_40002cc8 = Data_40003f50.fData_12;
						dData_40002d10 = Data_40003f50.fData_16;
						bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
						
						GotoEQCoordinates(dData_40002cc8, dData_40002d10);
						
						bData_40002f0d_RecentTargetType = 10;
						bData_40002f10_RecentTargetId = bData_4000319a_SkyLandTargetId;
						
						flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
						beep1(1);
						
						Data_40002c64_MenuContextId = 0;
					}
					//0x52fa0 -> 0x5315c
					break;
				
				case 1:
					//0x53038
					func_54e0(bData_4000319a_SkyLandTargetId, &Data_40003f64);
				
					fData_400034ac = Data_40003f64.fData_12;
					fData_400034b0 = Data_40003f64.fData_16;
				
					if (Data_40003f64.fData_16 >= -15)
					{
						//53080
						bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
						
						GotoEQCoordinates(dData_40002cc8, dData_40002d10);
						
						bData_400034aa = 1;
						bData_40002f0d_RecentTargetType = 12;
						bData_40002f10_RecentTargetId = bData_4000319a_SkyLandTargetId;
						
						flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
						beep1(1);
						
						Data_40002c64_MenuContextId = 0;
						//->0x53150
					}
					else
					{
						//0x530f4
						lcd_display_clear();
						beep1(1);
						lcd_display_string(0, 3, 1, 22, " Target Out of Range  ");
						lcd_display_string(0, 5, 1, 22, "Altitude < -15 Degree ");
						func_659c(2000);
						lcd_display_clear();
						
						Data_40002c64_MenuContextId = 101;
					}
					break;
					
				default:
					break;
			}
			//->0x563b8
			break;
		
		case MENU_CONTEXT_RECENT_TARGETS: //1:
			//0x53164
			bData_40002f14_RecentTargetCount = flash_get_recent_targets(Data_40002f15_RecentTargetTypeArray,
				Data_4000359c_RecentTargetIdArray,
				Data_400035bc);
		
			switch (Data_40002f15_RecentTargetTypeArray[bData_4000316e_FocusLineOn8LineDisplay - 1])
			{
				case 1:
					//0x531d4
					bData_40003176 = 1;
					bData_40003174 = 1;				
					bData_40002eb5_SolarSystemObjectNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION; //22001;
					//->0x53690
					break;
				
				case 2:
					//0x5321c
					bData_40003176 = 2;
					bData_40003174 = 1;				
					bData_40002ece_ConstellationNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_CONSTELLATION_SELECTION; //24001;
					//->0x53690
					break;
				
				case 3:
					//0x53268
					bData_40003176 = 3;
					bData_40003174 = 1;				
					bData_40002ed2_FamousStarNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_FAMOUS_STAR_SELECTION; //25001;
					//->0x53690
					break;
				
				case 4:
					//0x532b4
					bData_40003176 = 4;
					bData_40003174 = 1;				
					wData_40002eb8_MessierNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
					Data_40002ec8_NavigationDirectInputNr = 0;
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_MESSIER_OBJECT_DETAILS; //23012;
					//->0x53690
					break;
				
				case 5:
					//0x5330c
					bData_40003176 = 5;
					bData_40003174 = 1;				
					wData_40002eba_NGCNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
					Data_40002ec8_NavigationDirectInputNr = 0;
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_NGC_OBJECT_SELECTION; //23003;
					//->0x53690
					break;
				
				case 6:
					//0x53364
					bData_40003176 = 6;
					bData_40003174 = 1;				
					wData_40002ebc_ICNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
					Data_40002ec8_NavigationDirectInputNr = 0;
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_IC_OBJECT_SELECTION; //23004;
					//->0x53690
					break;
				
				case 7:
					//0x5345c
					bData_40003176 = 7;
					bData_40003174 = 1;				
					wData_40002ebe_ShNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
					Data_40002ec8_NavigationDirectInputNr = 0;
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_SH2_OBJECT_SELECTION; //23005;
					//->0x53690
					break;
				
				case 8:
					//0x534b4
					bData_40003176 = 8;
					bData_40003174 = 1;				
					wData_40002ec0_BrightStarNr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
					Data_40002ec8_NavigationDirectInputNr = 0;
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_BRIGHT_STAR_SELECTION; //23006;
					//->0x53690
					break;
				
				case 9:
					//0x5350c
					bData_40003176 = 8;
					bData_40003174 = 2;				
					Data_40002ec4_SAONr = 
						Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
					Data_40002ec8_NavigationDirectInputNr = 0;
				
					lcd_display_clear();
				
					Data_40002c64_MenuContextId = MENU_CONTEXT_SAO_OBJECT_SELECTION; //23007;
					//->0x53690
					break;
				
				case 10:
					//0x53564
					if (bData_40002e79_SkyLandTargetSeletion == 0)
					{
						//53578
						bData_4000319a_SkyLandTargetId = 
							Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
						Data_40002c64_MenuContextId = 101;
					}
					else
					{
						//0x535a4
						Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					}
					break;
				
				case 11:
					//0x535b4
					func_5218(10, &Data_40003f50);
				
					if (Data_40003f50.bData_0 == 111)
					{
						//535d4
						dData_40002cc8 = Data_40003f50.fData_12;
						dData_40002d10 = Data_40003f50.fData_16;
						bTrackingMode = 1;
						
						GotoEQCoordinates(dData_40002cc8, dData_40002d10);
					}
					//0x5361c
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					break;
				
				case 12:
					//0x5362c
					if (bData_40002e79_SkyLandTargetSeletion == 1)
					{
						//53640
						bData_4000319a_SkyLandTargetId = 
							Data_4000359c_RecentTargetIdArray[bData_4000316e_FocusLineOn8LineDisplay - 1];
						Data_40002c64_MenuContextId = 101;
					}
					else
					{
						//0x5366c
						Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					}
					break;
				
				default:
					//0x5367c
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					break;
			}
			//->0x563b8
			break;
		
		case MENU_CONTEXT_ALIGNMENT: //1000:
			//0x53698
			bData_40003173 = 1;
			bData_40003171 = 1;
			bData_40003172 = 1;
			bData_40003170 = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_ONE_STAR_ALIGN; //1100;
			break;
		
		case MENU_CONTEXT_NAVIGATION: //2000:
			//0x536d0
			bData_40003177 = 1;
			bData_40003175 = 1;
			bData_40003176 = 1;
			bData_40003174 = 1;	
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM; //2100;
			break;
		
		case MENU_CONTEXT_UTILITIES: //3000:
			//0x53708
			bData_4000317b = 1;
			bData_40003179 = 1;
			bData_4000317a = 1;
			bData_40003178 = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CURRENT_OBJECTS; //3100;
			break;
		
		case MENU_CONTEXT_SETUP: //4000:
			//0x53740
			bData_4000317f = 1;
			bData_4000317d = 1;
			bData_4000317e = 1;
			bData_4000317c = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE; //4100;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV: //3600:
			//0x53778: Eyepiece FOV
			bCharacterInputPosition = 7;
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT; //370021;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN: //3700:
			//0x53798: Eyepiece Magn.
			bCharacterInputPosition = 7;
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT; //360021;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION: //3800:
			//0x537b8: Display Illumination
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL; //380011;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_SITE_SETTING: //4300:
			//537cc: Site Setting
			Data_40002c64_MenuContextId = MENU_CONTEXT_COUNTRY_CITY; //4301;
			break;
		
		case MENU_CONTEXT_TELESCOPE_MOUNT: //4600:
			//0x537e0: Telescope Mount
			Data_40002c64_MenuContextId = MENU_CONTEXT_OTA_ZERO_SETUP; //47011; //->"Please setup OTA zero"
			bData_4000316d = 0;
			bCharacterInputPosition = 5;
			bData_400032a4_OTAZeroDataErrorCount = 0;
		
			flash_get_ota_zero_data(&fData_4000329c, &fData_400032a0);
		
			sprintf(Data_400028d7, "Azi:%03d", (unsigned short)fData_4000329c);
			sprintf(Data_400028e1, "Alt: %02d", (unsigned short)fData_400032a0);
			sprintf(Data_40002789, "Azi:%03d", (unsigned short)fData_4000329c);
			sprintf(Data_40002792, "Alt: %02d", (unsigned short)fData_400032a0);
			break;
		
		case MENU_CONTEXT_TRACKING_RATE: //4700:
			//0x538b4: Tracking Rate
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_STAR_SPEED; //4801;
			break;
		
		case MENU_CONTEXT_ONE_STAR_ALIGN: //1100:
			//0x538c8: One Star Align
			Data_40002c5c_AlignmentStarCount = 1;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62_AlignmentStarMode = 0; //Alignment Star Selection
		
			numVisibleAlignmentStars = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude),
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, arAlignmentStarNames, Data_40003b2c);
		
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT_STAR_CONTROL; //12001;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_TWO_STAR_ALIGN: //1200:
			//0x53960: Two Star Align
			Data_40002c5c_AlignmentStarCount = 2;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62_AlignmentStarMode = 0;
		
			numVisibleAlignmentStars = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude),
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, arAlignmentStarNames, Data_40003b2c);
		
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT_STAR_CONTROL; //12001;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_THREE_STAR_ALIGN: //1300:
			//0x539fc: Three Star Align
			Data_40002c5c_AlignmentStarCount = 3;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62_AlignmentStarMode = 0;
		
			numVisibleAlignmentStars = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude),
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, arAlignmentStarNames, Data_40003b2c);
		
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT_STAR_CONTROL; //12001;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x53b68
			bData_400034cd = 0;
			bData_40003430 = 1;
		
			if (bData_40002c62_AlignmentStarMode == 0)
			{
				//53b94: Alignment Star Selection
				switch (bData_40002c61)
				{
					case 1:
						//0x53bb8
						numVisibleAlignmentStars = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude),
							Data_40004128.geographicLatitude,
							Data_40004a68_CurrentAlignStarEquatorialCoord, arAlignmentStarNames, Data_40003b2c);
					
						Data_40004128.dFirstAlignmentStarRa =
							Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2];
						Data_40004128.dFirstAlignmentStarDec =
							Data_40004a68_CurrentAlignStarEquatorialCoord[1 + (bData_40002c60_CurrentAlignStarIndex - 1)*2];
						
						switch (Data_40002c5c_AlignmentStarCount)
						{
							case 1:
								//0x53c90
								StartOneStarAlignment();
								break;
							
							case 2:
								//0x53c9c
								StartTwoStarAlignment();
								break;
							
							case 3:
								//0x53ca8
								StartThreeStarAlignment();
								break;
							
							default:
								break;
						}
						//0x53cbc
						bData_40002c61++;
						Data_40002c5c_AlignmentStarCount--;
						bData_40002c62_AlignmentStarMode = 1; //"Slewing to Target"
						bTrackingMode = MENU_TRACKING_MODE_STOP; //0;
						//->0x53f44
						break;
					
					case 2:
						//0x53d04
						if (bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)
						{
							//53d18
							numVisibleAlignmentStars = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude),
								Data_40004128.geographicLatitude,
								Data_40004a68_CurrentAlignStarEquatorialCoord, arAlignmentStarNames, Data_40003b2c);
							
							Data_40004128.dSecondAlignmentStarRa =
								Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2];
							Data_40004128.dSecondAlignmentStarDec =
								Data_40004a68_CurrentAlignStarEquatorialCoord[1 + (bData_40002c60_CurrentAlignStarIndex - 1)*2];
							
							if (Data_40004128.bAlignmentComplete == 0)
							{
								ProcessNextAlignmentStar();
							}
							//0x53ddc
							bData_40002c61++;
							Data_40002c5c_AlignmentStarCount--;
							bData_40002c62_AlignmentStarMode = 1; //"Slewing to Target"
							bTrackingMode = MENU_TRACKING_MODE_STOP; //0;
						}
						//0x53e1c -> 0x53f44
						break;
					
					case 3:
						//0x53e20
						if (bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)
						{
							numVisibleAlignmentStars = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude),
								Data_40004128.geographicLatitude,
								Data_40004a68_CurrentAlignStarEquatorialCoord, arAlignmentStarNames, Data_40003b2c);
							
							Data_40004128.dThirdAlignmentStarRa =
								Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2];
							Data_40004128.dThirdAlignmentStarDec =
								Data_40004a68_CurrentAlignStarEquatorialCoord[1 + (bData_40002c60_CurrentAlignStarIndex - 1)*2];
							
							if (Data_40004128.bAlignmentComplete == 0)
							{
								ProcessNextAlignmentStar();
							}
							//0x53ef8
							bData_40002c61++;
							Data_40002c5c_AlignmentStarCount--;
							bData_40002c62_AlignmentStarMode = 1; //"Slewing to Target"
							bTrackingMode = MENU_TRACKING_MODE_STOP; //0;
						}
						//0x53f38 -> 0x53f44
						break;
						
					default:
						//53f3c
						break;
				}
				//53f44 -> 0x53f74
			} //if (bData_40002c62_AlignmentStarMode == 0)
			else
			{
				//0x53f48
				if ((bData_400031e9 == 4) || (bData_400031e9 == 8))
				{
					//0x53f68
					bData_40002c62_AlignmentStarMode = 0; //->(Next) Alignment Star Selection
				}
			}
			//0x53f74
			if (Data_40002c5c_AlignmentStarCount != -1)
			{
				//53f84
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT_STAR_CONTROL; //12001;
			}
			//0x53f90 -> 0x563b8
			break;
		
		case MENU_CONTEXT_TARGET_SYNC: //1400:
			//0x53f94: Target Sync
			bData_400031eb = 0;
			if (g_bTargetSyncOpen == FALSE)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_SYNC_OPEN; //1401;
			}
			else
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_SYNC_ENSURE; //1402;
			}
			break;
		
		case MENU_CONTEXT_SYNC_OPEN: //1401:
			//0x53fd4
			g_bTargetSyncOpen = TRUE;
			Data_40002c64_MenuContextId = 0;
			
			beep1(2);
			break;
		
		case MENU_CONTEXT_SYNC_ENSURE: //1402:
			//0x53ffc
			dData_40003410 = dData_400033d8;
			dData_40003418 = -dData_400033e0;
			dData_40003420 = dData_400033d8;
			dData_40003428 = dData_400033e0;
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			g_bTargetSyncOpen = 0;
			
			beep1(2);
			break;
		
		case MENU_CONTEXT_SYNC_CANCEL: //1403:
			//0x54064
			g_bTargetSyncOpen = 0;
			Data_40002c64_MenuContextId = 0;
			break;
		
		case MENU_CONTEXT_POLE_AXIS_DEV: //1500:
			//0x54080: Pole-Axis Dev.
			Data_40002c64_MenuContextId = MENU_CONTEXT_POLE_AXIS_DEV_INPUT; //18001; //->"Pole Axis Dev: "
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR: //1600:
			//0x54094: RA Bklash Corr.
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11102;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x540a8
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT; //11101;
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
			//0x540bc
			if (fabs(dData_40002dc0_Azimuth - dRaBklashCorrStartAzimuth) > 5.0)
			{
				//540fc
				fData_40002e90 = fabs((dData_40002dc0_Azimuth - dRaBklashCorrStartAzimuth - 360.0) * 3600.0);
				//->0x541b0
			}
			else
			{
				//0x54164
				fData_40002e90 = fabs((dData_40002dc0_Azimuth - dRaBklashCorrStartAzimuth) * 3600.0);
			}
			//0x541b0
			Data_40002e94 += fData_40002e90;
			Data_40002e9c += 1;
			iBacklashCorrectionSlewing = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_RESULT; //11104;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
			//0x54200: RA Bklash Corr. - 2nd page
			if (Data_40002e9c != 0)
			{
				//54218
				fData_40002e98 = Data_40002e94 / Data_40002e9c;
				
				func_52720(1);
			}
			//0x54244
			Data_40002e94 = 0;
			fData_40002e90 = 0;
			Data_40002e9c = 0;
			Data_40002c64_MenuContextId = 11105;
			break;
		
		case MENU_CONTEXT_DEC_BKLASH_CORR: //1700:
			//0x54270: DEC Bklash Corr.
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11202;
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x54284
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN; //11201;
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
			//0x54298
			fData_40002ea0 = fabs((dData_40002df8 - dData_40002e00) * 3600.0);
			fData_40002ea4 += fData_40002ea0;
			fData_40002eac += 1;
			iBacklashCorrectionSlewing = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKBLASH_CORR_RESULT; //11204;
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN: //11201:
			//0x54338
			if (fData_40002eac != 0)
			{
				//54350
				fData_40002ea8 = fData_40002ea4 / fData_40002eac;

				func_52720(2);
			}
			//0x5437c
			fData_40002ea4 = 0;
			fData_40002ea0 = 0;
			fData_40002eac = 0;
			Data_40002c64_MenuContextId = 11205;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM: //2100:
			//0x543a8: Navigation -> Solar System
			bData_40002eb5_SolarSystemObjectNr = 0;
			lcd_display_clear();
			bData_40003432 = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION; //22001; 
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
			//0x543d8
			if (bData_40002eb5_SolarSystemObjectNr == 8/*Sun*/)
			{
				lcd_display_clear();
				
				Data_40002c64_MenuContextId = MENU_CONTEXT_SUN_WARNING; //22112;
				
				beep1(1);
			}
			else
			{
				//0x54408
				get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
					&fData_40002cd0_ObjectRightAscension,
					&fData_40002d18_ObjectDeclination);
				
				dData_40002cc8 = fData_40002cd0_ObjectRightAscension;
				dData_40002d10 = fData_40002d18_ObjectDeclination;
				bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
				
				GotoEQCoordinates(dData_40002cc8, dData_40002d10);
				
				bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_SOLAR_SYSTEM; //1;
				bData_40002f10_RecentTargetId = bData_40002eb5_SolarSystemObjectNr;
				
				flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				lcd_display_clear();
				
				Data_40002c64_MenuContextId = MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING; //22111;
			}
			//->0x563b8
			break;
		
		case MENU_CONTEXT_SUN_WARNING: //22112:
			//0x544a8
			get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
				&fData_40002cd0_ObjectRightAscension,
				&fData_40002d18_ObjectDeclination);
			
			dData_40002cc8 = fData_40002cd0_ObjectRightAscension;
			dData_40002d10 = fData_40002d18_ObjectDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
			
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);
			
			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_SOLAR_SYSTEM; //1;
			bData_40002f10_RecentTargetId = bData_40002eb5_SolarSystemObjectNr;
			
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
			
			Data_40002c64_MenuContextId = MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING; //22111;
			break;
		
		case MENU_CONTEXT_NAVIGATION_CONSTELLATION: //2200:
			//0x5454c: Navigation -> Constellation
			bData_40002ece_ConstellationNr = 1;
			lcd_display_clear();
			bData_40003432 = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CONSTELLATION_SELECTION; //24001;
			break;
		
		case MENU_CONTEXT_CONSTELLATION_SELECTION: //24001:
			//0x5457c
			flash_get_constellation_data(bData_40002ece_ConstellationNr, 
				&Data_40003dd4_FlashConstellationData);
		
			dData_40002cc8 = Data_40003dd4_FlashConstellationData.fRightAscension;
			dData_40002d10 = Data_40003dd4_FlashConstellationData.fDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
		
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);
		
			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_CONSTELLATION; //2;
			bData_40002f10_RecentTargetId = bData_40002ece_ConstellationNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_CONSTELLATION_TRACKING; //24002;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_NAVIGATION_FAMOUS_STAR: //2300:
			//0x5461c: Navigation -> Famous Star
			bData_40002ed2_FamousStarNr = 1;
			lcd_display_clear();
			bData_40003432 = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_FAMOUS_STAR_SELECTION; //25001;
			break;
		
		case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
			//0x5464c
			flash_get_famous_star_data(bData_40002ed2_FamousStarNr, &Data_40003d94_FlashFamousStarData);
		
			dData_40002cc8 = Data_40003d94_FlashFamousStarData.fRightAscension;
			dData_40002d10 = Data_40003d94_FlashFamousStarData.fDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
		
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);

			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_FAMOUS_STAR; //3;
			bData_40002f10_RecentTargetId = bData_40002ed2_FamousStarNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_FAMOUS_STAR_TRACKING; //25002;
			break;
		
		case MENU_CONTEXT_NAVIGATION_MESSIER_CAT: //2400:
			//0x546ec
			wData_40002eb8_MessierNr = 1;
			Data_40002ec8_NavigationDirectInputNr = 0;
			lcd_display_clear();
			bData_40003432 = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_MESSIER_OBJECT_DETAILS; //23012;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
			//0x54728
			lcd_display_clear();
			Data_40002c64_MenuContextId = MENU_CONTEXT_MESSIER_OBJECT_SELECTION; //23002;
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
			//0x54740
			flash_get_messier_data((unsigned char)wData_40002eb8_MessierNr, 
				&Data_40003e08_FlashMessierData);
		
			dData_40002cc8 = Data_40003e08_FlashMessierData.fRightAscension;
			dData_40002d10 = Data_40003e08_FlashMessierData.fDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
		
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);

			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_MESSIER; //4;
			bData_40002f10_RecentTargetId = wData_40002eb8_MessierNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_MESSIER_OBJECT_TRACKING; //23022;
			break;
		
		case MENU_CONTEXT_NAVIGATION_NGC_CAT: //2500:
			//0x548e4
			wData_40002eba_NGCNr = 1;
			Data_40002ec8_NavigationDirectInputNr = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = MENU_CONTEXT_NGC_OBJECT_SELECTION; //23003;
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
			//0x5491c
			flash_get_ngc_data(wData_40002eba_NGCNr, &Data_40003ee0_FlashNGCData);
		
			dData_40002cc8 = Data_40003ee0_FlashNGCData.fRightAscension;
			dData_40002d10 = Data_40003ee0_FlashNGCData.fDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
		
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);

			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_NGC; //5;
			bData_40002f10_RecentTargetId = wData_40002eba_NGCNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_NGC_OBJECT_TRACKING; //23013;
			break;
		
		case MENU_CONTEXT_NAVIGATION_IC_CAT: //2600:
			//0x549bc
			wData_40002ebc_ICNr = 1;
			Data_40002ec8_NavigationDirectInputNr = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = MENU_CONTEXT_IC_OBJECT_SELECTION; //23004;
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
			//0x549f4
			flash_get_ic_data(wData_40002ebc_ICNr, &Data_40003ec0_FlashICData);
		
			dData_40002cc8 = Data_40003ec0_FlashICData.fRightAscension;
			dData_40002d10 = Data_40003ec0_FlashICData.fDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
		
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);

			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_IC; //6;
			bData_40002f10_RecentTargetId = wData_40002ebc_ICNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_IC_OBJECT_TRACKING; //23014;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SH2_CAT: //2700:
			//0x54a94
			wData_40002ebe_ShNr = 1;
			Data_40002ec8_NavigationDirectInputNr = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = MENU_CONTEXT_SH2_OBJECT_SELECTION; //23005;
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
			//0x54acc
			flash_get_sh2_data(wData_40002ebe_ShNr, &Data_40003350_FlashSh2Data);
		
			dData_40002cc8 = Data_40003350_FlashSh2Data.fRightAscension;
			dData_40002d10 = Data_40003350_FlashSh2Data.fDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
		
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);

			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_SH2; //7;
			bData_40002f10_RecentTargetId = wData_40002ebe_ShNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_SH2_OBJECT_TRACKING; //23015;
			break;
		
		case MENU_CONTEXT_NAVIGATION_BRIGHT_STAR: //2800:
			//0x54b6c
			wData_40002ec0_BrightStarNr = 1;
			Data_40002ec8_NavigationDirectInputNr = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = MENU_CONTEXT_BRIGHT_STAR_SELECTION; //23006;
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
			//0x54ba4
			flash_get_bright_star_data((unsigned char)wData_40002ec0_BrightStarNr, &Data_40003ea0_FlashBrightStarData);
		
			dData_40002cc8 = Data_40003ea0_FlashBrightStarData.fRightAscension;
			dData_40002d10 = Data_40003ea0_FlashBrightStarData.fDeclination;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
		
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);

			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_BRIGHT_STAR; //8;
			bData_40002f10_RecentTargetId = wData_40002ec0_BrightStarNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_BRIGHT_STAR_TRACKING; //23016;
			break;
		
		case MENU_CONTEXT_NAVIGATION_SAO_CAT: //2900:
			//0x54c48: SAO Catalogue
			Data_40002ec4_SAONr = 1;
			Data_40002ec8_NavigationDirectInputNr = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = MENU_CONTEXT_SAO_OBJECT_SELECTION; //23007;
			break;

		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x54c80: SAO item
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);

			dData_40002cc8 = Data_40003358_SAORecord.ra;
			dData_40002d10 = Data_40003358_SAORecord.dec;
			bTrackingMode = MENU_TRACKING_MODE_POINTING; //1;
			
			GotoEQCoordinates(dData_40002cc8, dData_40002d10);
			
			bData_40002f0d_RecentTargetType = MENU_RECENT_TARGET_SAO_CAT; //9;
			bData_40002f10_RecentTargetId = Data_40002ec4_SAONr;
			
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
			
			Data_40002c64_MenuContextId = MENU_CONTEXT_SAO_OBJECT_TRACKING; //23017;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_OBJ: //2110:
			//0x54d20: Customer Objects
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION; //201;
			bData_4000319a_SkyLandTargetId = 1;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x54d40
			bCharacterInputPosition = 6;		
			PrepareCustomerSkyObjectInputData();
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT; //203;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x54d64		
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x54d6c
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x54d70
			HandleCustomerSkyObjectInput();
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_OBJ; //2110;
			break;
		
		case MENU_CONTEXT_NAVIGATION_RA_DEC: //2120:
			//0x54d84: Input RA/DEC
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_INPUT; //29001;
			bCharacterInputPosition = 6;
			PrepareCustomerSkyObjectInputData();
			break;
		
		case MENU_CONTEXT_RA_INPUT: //29001:
			//0x54da8
			HandleRectascensionDeclinationInput();
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002:
			//0x54db4
			HandleRectascensionDeclinationInput();
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_LAND: //2130:
			//0x54dc0
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_LAND; //2130;
			bData_4000319a_SkyLandTargetId = 1;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//0x54de0
			PrepareCustomerLandObjectInputData();
			bCharacterInputPosition = 6;
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT; //206;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x54e04
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x54e0c
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x54e10
			HandleCustomerLandObjectInput();
			Data_40002c64_MenuContextId = MENU_CONTEXT_NAVIGATION_CUST_LAND; //2130;
			break;
		
		case MENU_CONTEXT_SKY_LAND: //4400:
			//0x54e24
#ifdef V2_3
			Data_40002c64_MenuContextId = MENU_CONTEXT_SKY_LAND; //4400;
#else
			Data_40002c64_MenuContextId = MENU_CONTEXT_SKY_TARGET; //45001;
#endif
			break;
		
		case MENU_CONTEXT_SKY_TARGET: //45001:
			//0x54e38
			bData_40002e79_SkyLandTargetSeletion = 0;
			g_bLandTarget = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_SKY_LAND; //4400;
		
			Data_40003500.dwData = fabs((int) ((6.0 * dTrackingRate) / 15.04));
		
			UART1_WRITE_HEADER(4);
			uart1_write_byte(0x41);
		
			if (dTrackingRate > 0)
			{
				//54efc
				uart1_write_byte(0x01);
			}
			else
			{
				//0x54f08
				uart1_write_byte(0x00);
			}
			//0x54f10
			uart1_write_byte(Data_40003500.bData[1]);
			uart1_write_byte(Data_40003500.bData[0]);

			UART1_WRITE_HEADER(4);
			uart1_write_byte(0x01);
			
			if (dTrackingRate > 0)
			{
				//54f68
				uart1_write_byte(0x00);
			}
			else
			{
				//0x54f74
				uart1_write_byte(0x01);
			}
			//0x54f7c
			uart1_write_byte(Data_40003500.bData[1]);
			uart1_write_byte(Data_40003500.bData[0]);
			break;
		
		case MENU_CONTEXT_LAND_TARGET: //45002:
			//0x54f98
			bData_40002e79_SkyLandTargetSeletion = 1;
			g_bLandTarget = 1;
			func_b4d0();
			Data_40002c64_MenuContextId = MENU_CONTEXT_SKY_LAND; //4400;
			break;
		
		case MENU_CONTEXT_AZ_EQU: //4500:
			//0x54fc4: AZ / EQ
#ifdef V2_3
			Data_40002c64_MenuContextId = MENU_CONTEXT_AZ_EQU; //4500;
#else
			Data_40002c64_MenuContextId = MENU_CONTEXT_MOUNT_AZ; //46001;
#endif
			break;
		
		case MENU_CONTEXT_MOUNT_AZ: //46001:
			//0x54fd8
			bData_40002e7a_MountType = MENU_MOUNT_TYPE_AZ; //0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_AZ_EQU; //4500;
			break;
		
		case MENU_CONTEXT_MOUNT_EQU: //46002:
			//0x54ff8
			bData_40002e7a_MountType = MENU_MOUNT_TYPE_EQU; //1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_AZ_EQU; //4500;
			break;
		
		case MENU_CONTEXT_LANGUAGE: //4800:
			//0x55018
			Data_40002c64_MenuContextId = MENU_CONTEXT_ENGLISH; //49001;
			break;
		
		case MENU_CONTEXT_ENGLISH: //49001:
			//0x5502c
			bData_40003196_CurrentLanguage = MENU_LANGUAGE_ENGLISH; //1;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LANGUAGE; //4800;
			break;
		
		case MENU_CONTEXT_GERMAN: //49002:
			//0x55084
			bData_40003196_CurrentLanguage = MENU_LANGUAGE_GERMAN; //2;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LANGUAGE; //4800;
			break;
		
		case MENU_CONTEXT_FRENCH: //49003:
			//0x550dc
			bData_40003196_CurrentLanguage = MENU_LANGUAGE_FRENCH; //3;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LANGUAGE; //4800;
			break;
		
		case MENU_CONTEXT_ITALIAN: //49004:
			//0x55134
			bData_40003196_CurrentLanguage = MENU_LANGUAGE_ITALIAN; //4;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LANGUAGE; //4800;
			break;
		
		case MENU_CONTEXT_SPANISH: //49005:
			//0x5518c
			bData_40003196_CurrentLanguage = MENU_LANGUAGE_SPANISH; //5;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = MENU_CONTEXT_LANGUAGE; //4800;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_STAR_SPEED: //4801:
			//0x551e4: Tracking Rate -> "Star Speed"
			dTrackingRate = 0;
			bData_40002e7c_TrackingRateType = MENU_TRACKING_RATE_STAR_SPEED; //0;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED: //4802:
			//0x5521c: Tracking Rate -> "Solar Speed"
			dTrackingRate = 0.000000298199444444444492059666153988;
			bData_40002e7c_TrackingRateType = MENU_TRACKING_RATE_SOLAR_SPEED; //1;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_MOON_SPEED: //4803:
			//0x55254: "Moon Speed"
			dTrackingRate = 0.00000376886111111111134081550801123;
			bData_40002e7c_TrackingRateType = MENU_TRACKING_RATE_MOON_SPEED; //2;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED: //4804:
			//0x55288: "Customize Speed"
			bCharacterInputPosition = 1;
			sprintf(strTrackingRateCustInput, "+0%.2f\272\343\320\307\313\331      ", 1.0);
			sprintf(strTrackingRateCustDisplay, "+0%.2f  starspeed", 1.0);
			Data_40002c64_MenuContextId = MENU_CONTEXT_TRACKING_RATE_INPUT; //48001;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED: //4805:
			//0x552d0: "Guiding Speed"
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED1; //48051;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001:
			//0x552e4
			bData_40002e7c_TrackingRateType = MENU_TRACKING_RATE_CUST_SPEED; //3;
			dTrackingRate = (1 - atof(strTrackingRateCustInput)) * 0.37 / 3600.0;
		
			beep1(2);
		
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED1: //48051:
			//0x55364
			dGuidingSpeed = 0.125;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED2: //48052:
			//0x55490
			dGuidingSpeed = 0.25;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED3: //48053:
			//0x554bc
			dGuidingSpeed = 0.375;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED4: //48054:
			//0x554e8
			dGuidingSpeed = 0.5;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED5: //48055:
			//0x55514
			dGuidingSpeed = 0.625;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED6: //48056:
			//0x55540
			dGuidingSpeed = 0.75;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED7: //48057:
			//0x5556c
			dGuidingSpeed = 0.875;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED8: //48058:
			//0x55598
			dGuidingSpeed = 1.0;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_PARK_POSITION: //3900:
			//0x555c4: Parkposition
			func_75c4();
			bGotoParkPosition = 1;
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_CURRENT_OBJECTS: //3100:
			//0x555e8: Current Objects
			bData_40002eb5_SolarSystemObjectNr = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_SOLAR_SYSTEM_OBJ_RISE_SET_TIMES; //31001;
			break;
		
		case MENU_CONTEXT_TIME_DATE: //4100:
			//55608: Time and Date
			get_rtc_date_time();
		
			sprintf(Data_400037ec, "%04d-%02d-%02d",
				Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40003150, "%02d:%02d:%02d",
				bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
			sprintf(Data_40002655, "%04d-%02d-%02d", 
				Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40002660, "%02d:%02d:%02d", 
				bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
			
			bCharacterInputPosition = 1;
			bDateTimeInputMode = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE_INPUT; //41001;
			break;
		
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//0x556d8
			if (ValidateDateTimeSetRTC() == 1)
			{
				//556e8
				if (bData_40002f1e_SetupLocalData == 1)
				{
					Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_OFF; //42002;
				}
				else
				{
					Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE; //4100;
				}
				beep1(1);
			}
			else
			{
				//0x55720
				get_rtc_date_time();
				
				sprintf(Data_400037ec, "%04d-%02d-%02d",
					Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
				sprintf(Data_40003150, "%02d:%02d:%02d",
					bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
				sprintf(Data_40002655, "%04d-%02d-%02d", 
					Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
				sprintf(Data_40002660, "%02d:%02d:%02d", 
					bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
				
				bCharacterInputPosition = 1;
				bDateTimeInputMode = 0;
				Data_40002c64_MenuContextId = MENU_CONTEXT_TIME_DATE_INPUT; //41001;
			}
			//0x557e8 -> 0x563b8
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING: //4200:
			//0x55868	
			if (bDaylightSavingTime == 0)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_OFF; //42002;
			}
			else
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING_ON; //42001;
			}
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_ON: //42001:
			//0x5589c		
		case MENU_CONTEXT_DAYLIGHT_SAVING_OFF: //42002:
			//0x558a4
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_COUNTRY_CITY; //4301;
			}
			else
			{
				beep1(1);
				Data_40002c64_MenuContextId = MENU_CONTEXT_DAYLIGHT_SAVING; //4200;
			}
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY: //4301:
			//0x558dc: Country & City
			wData_40003250 = 1;
			wData_40003252 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = MENU_CONTEXT_COUNTRY_CITY_SELECTION; //43011;
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x5590c
			flash_get_site_data((unsigned short)(wData_40003250 + wData_40003252), &Data_40003f1c_FlashSiteData);
		
			dData_40002e28_SiteLongitude = Data_40003f1c_FlashSiteData.fLongitude;
			dData_40002e48_SiteLatitude = Data_40003f1c_FlashSiteData.fLatitude;
			Data_40002e54_Zone = Data_40003f1c_FlashSiteData.Zone;
			Data_40004128.geographicLongitude = dData_40002e28_SiteLongitude;
			Data_40004128.geographicLatitude = dData_40002e48_SiteLatitude;
			Data_40004128.timeZone = Data_40002e54_Zone;
			
			beep1(2);
		
			if (bData_40002f1e_SetupLocalData == 1)
			{
				//559b8
				if (bData_40002c1a == 1)
				{
					bSystemInitialized = 0;
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					bData_40002f1e_SetupLocalData = 0;
				}
				else
				{
					//0x559e8
					Data_40002c64_MenuContextId = MENU_CONTEXT_OTA_ZERO_SETUP; //47011;
				}
			}
			else
			{
				//0x559f8
				Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			}
			//->0x563b8
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE: //4302:
			//0x55a08: Custom Site
			bData_40002edc = 1;
			bCurrentCustomSiteInputLine = 0;
			bCharacterInputPosition = 7;
		
			flash_get_custom_site_data(arCustomSiteName, 
				&fCustomSiteLongitude, &fCustomSiteLatitude, 
				&iCustomSiteTimeZone);
		
			/*Name:*/
			strCustomSiteName[6] = arCustomSiteName[0];
			strCustomSiteName[7] = arCustomSiteName[1];
			strCustomSiteName[8] = arCustomSiteName[2];		
			strCustomSiteName[9] = arCustomSiteName[3];		
			strCustomSiteName[10] = arCustomSiteName[4];		
			strCustomSiteName[11] = arCustomSiteName[5];		
			strCustomSiteName[12] = arCustomSiteName[6];		
			strCustomSiteName[13] = arCustomSiteName[7];		
		
			if (fCustomSiteLongitude > 0)
			{
				//55abc
				sprintf(strCustomSiteLongitude, "  Lon:E%03dd%02df ",
					DEGREES_MINUTES_ABS(fCustomSiteLongitude));
			}
			else
			{
				//0x55b4c
				sprintf(strCustomSiteLongitude, "  Lon:W%03dd%02df ",
					DEGREES_MINUTES_ABS(fCustomSiteLongitude));
			}
			//0x55bd8
			if (fCustomSiteLatitude > 0)
			{
				//55bec
				sprintf(strCustomSiteLatitude, "  Lat:N%02dd%02df ",
					DEGREES_MINUTES_ABS(fCustomSiteLatitude));
			}
			else
			{
				//0x55c7c
				sprintf(strCustomSiteLatitude, "  Lat:S%02dd%02df ",
					DEGREES_MINUTES_ABS(fCustomSiteLatitude));
			}
			//0x55d08
			if (iCustomSiteTimeZone > 0)
			{
				//55d18
				sprintf(strCustomSiteTimezone, " Zone:E%02d", abs(iCustomSiteTimeZone));
			}
			else
			{
				//0x55d48
				sprintf(strCustomSiteTimezone, " Zone:W%02d", abs(iCustomSiteTimeZone));
			}
			
			Data_40002c64_MenuContextId = MENU_CONTEXT_CUSTOM_SITE_INPUT; //43002;
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x55d84
			HandleCustomSiteData();
			break;
		
		case MENU_CONTEXT_RESET: //4900:
			//0x55d90: Reset
			Data_40002c64_MenuContextId = MENU_CONTEXT_RESET_CONFIRM; //100;
			break;
		
		case MENU_CONTEXT_RESET_CONFIRM: //100:
			//0x55da4: Reset -> Enter
			HandleReset();
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011: //Telescope Mount -> "Please setup OTA zero"
			//0x55db0
			HandleOTAZeroData();
			break;
		
		case MENU_CONTEXT_OBJECT_RISE_SET: //3200:
			//0x55dbc: Object Rise/Set
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_INPUT; //29001;
			bCharacterInputPosition = 6;
			PrepareCustomerSkyObjectInputData();
			bData_40003162 = 1;
			break;
		
		case MENU_CONTEXT_RISE_SET_TIMES: //32001:
			//0x55dec
			Data_40002c64_MenuContextId = MENU_CONTEXT_RA_INPUT; //29001;
			break;
		
		case MENU_CONTEXT_LUNAR_PHASE: //3300:
			//0x55e00
			Data_40002c64_MenuContextId = 33001;
			func_50018();
			break;
		
		case MENU_CONTEXT_TIMER: //3400:
			//0x55e18
			if (Data_40003214_UserTimerSeconds != 0)
			{
				Data_40002c64_MenuContextId = 34002; //->"Counting down:"
			}
			else
			{
				//0x55e3c
				Data_40002c64_MenuContextId = MENU_CONTEXT_TIMER_SET; //34001;
				bCharacterInputPosition = 1;
			}
			break;
			
		case MENU_CONTEXT_TIMER_SET: //34001:
			//0x55e58
			if (bData_40003196_CurrentLanguage == 1)
			{
				//755e6c
				Data_40003214_UserTimerSeconds = atoi(strEng00000s);
			}
			else
			{
				//0x55e80
				Data_40003214_UserTimerSeconds = atoi(Data_4000294a);
			}
			//0x55e90
			if (Data_40003214_UserTimerSeconds == 0)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_TIMER_SET; //34001;
			}
			else
			{
				//0x55eb0
				Data_40002c64_MenuContextId = MENU_CONTEXT_TIMER_COUNTING; //34002;
			}
			//0x55ebc -> 0x563b8
			break;
			
		case MENU_CONTEXT_TIMER_COUNTING: //34002:
			//0x55ec0
			Data_40003214_UserTimerSeconds = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_TIMER_SET; //34001;
			break;
			
		case MENU_CONTEXT_ALARM: //3500:
			//0x55ee0
			if (bData_4000322c == 1)
			{
				//55ef4
				Data_40002c64_MenuContextId = 35002;
			}
			else
			{
				//0x55f04
				//-> "Input time:"
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALARM_INPUT; //35001;
				bCharacterInputPosition = 1;
			}
			//->563b8
			break;
		
		case MENU_CONTEXT_ALARM_INPUT: //35001:
			//0x55f20: Alarm start?
			HandleAlarmInputData();
			break;
		
		case 35002:
			//0x55f2c: Alarm stop?
			bData_4000322c = 0;
			Data_40002c64_MenuContextId = MENU_CONTEXT_ALARM_INPUT; //35001;
			break;
		
		case 3601:
			//0x55f4c
			Data_40002c64_MenuContextId = 360011;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
			//0x55f60
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
			//0x55f68
			fMainFocalLength = atoi(&strEyepieceFovMfInput[6]) * 1.0;
			fSecondaryFocalLength = atoi(&strEyepieceFovSfInput[6]) * 1.0;
			fEyepieceMagnification = fMainFocalLength / fSecondaryFocalLength;
		
			sprintf(strEyepieceMagnification, "Magnification = %.1f         ", fEyepieceMagnification);
			beep1(1);
		
			bCharacterInputPosition = 7;
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT; //360021;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
			//0x56048
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
			//0x56050
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
			//0x56054
			fMainFocalLength = atoi(&strEyepieceFovMfInput[6]) * 1.0;
			fSecondaryFocalLength = atoi(&strEyepieceFovSfInput[6]) * 1.0;
			fEyepieceFOV = atoi(&strEyepieceFovInput[6]) * 1.0 + 
				atoi(&strEyepieceFovInput[9]) * 0.016666667;
			fEyepieceMagnification = fMainFocalLength / fSecondaryFocalLength;
			fFieldOfView = fEyepieceFOV / fEyepieceMagnification;

			sprintf(strEyepieceFOV, "         FOV:%0.5f         ", fFieldOfView);
			beep1(1);
		
			bCharacterInputPosition = 7;
			Data_40002c64_MenuContextId = MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT; //370021;
			break;
		
		case 360023:
			//0x562f8
			fMainFocalLength = atoi(&Data_40002474[6]);
			fSecondaryFocalLength = atoi(&Data_40002481[6]);
			fEyepieceMagnification = fMainFocalLength / fSecondaryFocalLength;
			break;
		
		case 3801:
			//0x5634c
			Data_40002c64_MenuContextId = MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL; //380011;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL: //380011:
			//0x56360
			HandleStarKey();
			break;
		
		case 3802:
			//0x5636c
			if (bData_40003194 == 0)
			{
				setDisplayPWM(0xFF);
				bData_40003194 = 1;
			}
			else
			{
				setDisplayPWM(0x00);
				bData_40003194 = 0;
			}
			break;
			
		default:
			break;
	}	
}

