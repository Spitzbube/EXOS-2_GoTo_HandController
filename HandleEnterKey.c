

/* 52898 - todo */
void HandleEnterKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x52e68
			if (Data_40004128.bData_364 == 0)
			{
				//52e7c
				func_c8f4();
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
						bData_40002e88 = MENU_TRACKING_MODE_POINTING; //1;
						
						func_b64c(dData_40002cc8, dData_40002d10);
						
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
						bData_40002e88 = MENU_TRACKING_MODE_POINTING; //1;
						
						func_b64c(dData_40002cc8, dData_40002d10);
						
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
		
		case 1:
			//0x53164
			//TODO
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
			bData_4000318a = 7;
			Data_40002c64_MenuContextId = 370021; //->"Eyep. focal length:"
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN: //3700:
			//0x53798: Eyepiece Magn.
			bData_4000318a = 7;
			Data_40002c64_MenuContextId = 360021; //->"Eyep. focal length:"
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
			Data_40002c64_MenuContextId = 47011; //->"Please setup OTA zero"
			bData_4000316d = 0;
			bData_4000318a = 5;
			bData_400032a4 = 0;
		
			func_27c4(&Data_4000329c, &Data_400032a0);
		
			sprintf(Data_400028d7, "Azi:%03d", (unsigned short)Data_4000329c);
			sprintf(Data_400028e1, "Alt: %02d", (unsigned short)Data_400032a0);
			sprintf(Data_40002789, "Azi:%03d", (unsigned short)Data_4000329c);
			sprintf(Data_40002792, "Alt: %02d", (unsigned short)Data_400032a0);
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
		
			bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), 
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c); 
		
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT_STAR_CONTROL; //12001;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_TWO_STAR_ALIGN: //1200:
			//0x53960: Two Star Align
			Data_40002c5c_AlignmentStarCount = 2;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62_AlignmentStarMode = 0;
		
			bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), 
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c); 
		
				Data_40002c64_MenuContextId = MENU_CONTEXT_ALIGNMENT_STAR_CONTROL; //12001;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_THREE_STAR_ALIGN: //1300:
			//0x539fc: Three Star Align
			Data_40002c5c_AlignmentStarCount = 3;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62_AlignmentStarMode = 0;
		
			bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), 
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c); 
		
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
						bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), 
							Data_40004128.geographicLatitude,
							Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c);
					
						Data_40004128.dData_376 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2];
						Data_40004128.dData_384 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2 + 1];
						
						switch (Data_40002c5c_AlignmentStarCount)
						{
							case 1:
								//0x53c90
								func_cf8c();
								break;
							
							case 2:
								//0x53c9c
								func_d07c();
								break;
							
							case 3:
								//0x53ca8
								func_d16c();
								break;
						}
						//0x53cbc
						bData_40002c61++;
						Data_40002c5c_AlignmentStarCount--;
						bData_40002c62_AlignmentStarMode = 1; //"Slewing to Target"
						bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
						//->0x53f44
						break;
					
					case 2:
						//0x53d04
						if (bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)
						{
							//53d18
							bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), 
								Data_40004128.geographicLatitude,
								Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c);
							
							Data_40004128.dData_392 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2];
							Data_40004128.dData_400 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2 + 1];
							
							if (Data_40004128.bData_364 == 0)
							{
								func_c8f4();
							}
							//0x53ddc
							bData_40002c61++;
							Data_40002c5c_AlignmentStarCount--;
							bData_40002c62_AlignmentStarMode = 1; //"Slewing to Target"
							bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
						}
						//0x53e1c -> 0x53f44
						break;
					
					case 3:
						//0x53e20
						if (bData_40002e88 == MENU_TRACKING_MODE_TRACKING/*2*/)
						{
							bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), 
								Data_40004128.geographicLatitude,
								Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c);
							
							Data_40004128.dData_408 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2];
							Data_40004128.dData_416 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2 + 1];
							
							if (Data_40004128.bData_364 == 0)
							{
								func_c8f4();
							}
							//0x53ef8
							bData_40002c61++;
							Data_40002c5c_AlignmentStarCount--;
							bData_40002c62_AlignmentStarMode = 1; //"Slewing to Target"
							bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
						}
						//0x53f38 -> 0x53f44
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
			if (bData_400031ea == 0)
			{
				Data_40002c64_MenuContextId = 1401;
			}
			else
			{
				Data_40002c64_MenuContextId = 1402;
			}
			break;
		
		case 1401:
			//0x53fd4
			bData_400031ea = 1;
			Data_40002c64_MenuContextId = 0;
			
			beep1(2);
			break;
		
		case 1402:
			//0x53ffc
			dData_40003410 = dData_400033d8;
			dData_40003418 = -dData_400033e0;
			dData_40003420 = dData_400033d8;
			dData_40003428 = dData_400033e0;
		
			Data_40002c64_MenuContextId = 0;
			bData_400031ea = 0;
			
			beep1(2);
			break;
		
		case 1403:
			//0x54064
			bData_400031ea = 0;
			Data_40002c64_MenuContextId = 0;
			break;
		
		case MENU_CONTEXT_POLE_AXIS_DEV: //1500:
			//0x54080: Pole-Axis Dev.
			Data_40002c64_MenuContextId = 18001; //->"Pole Axis Dev: "
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR: //1600:
			//0x54094: RA Bklash Corr.
			Data_40002c64_MenuContextId = 11102; //->RA Bklash Corr. - 1st page
			break;
		
		case 11102:
			//0x540a8
			Data_40002c64_MenuContextId = 11101; //->RA Bklash Corr. - 2nd page
			break;
		
		case 11103:
			//0x540bc
			if (fabs(dData_40002dc0 - dData_40002dc8) > 5.0)
			{
				//540fc
				fData_40002e90 = fabs((dData_40002dc0 - dData_40002dc8 - 360.0) * 3600.0);
				//->0x541b0
			}
			else
			{
				//0x54164
				fData_40002e90 = fabs((dData_40002dc0 - dData_40002dc8) * 3600.0);
			}
			//0x541b0
			Data_40002e94 += fData_40002e90;
			Data_40002e9c += 1;
			Data_40002eb0 = 0;
			Data_40002c64_MenuContextId = 11104;
			//->0x563b8
			break;
		
		case 11101:
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
			Data_40002c64_MenuContextId = 11202;
			break;
		
		case 11202:
			//0x54284
			Data_40002c64_MenuContextId = 11201;
			break;
		
		case 11203:
			//0x54298
			//TODO
			break;
		
		case 11201:
			//0x54338
			//TODO
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
				bData_40002e88 = MENU_TRACKING_MODE_POINTING; //1;
				
				func_b64c(dData_40002cc8, dData_40002d10);
				
				bData_40002f0d_RecentTargetType = 1;
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
			bData_40002e88 = MENU_TRACKING_MODE_POINTING; //1;
			
			func_b64c(dData_40002cc8, dData_40002d10);
			
			bData_40002f0d_RecentTargetType = 1;
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
			Data_40002c64_MenuContextId = 24001;
			break;
		
		case 24001:
			//0x5457c
			func_38dc(bData_40002ece_ConstellationNr, &Data_40003dd4);
		
			dData_40002cc8 = Data_40003dd4.fData_36;
			dData_40002d10 = Data_40003dd4.fData_40;
			bData_40002e88 = MENU_TRACKING_MODE_POINTING; //1;
		
			func_b64c(dData_40002cc8, dData_40002d10);
		
			bData_40002f0d_RecentTargetType = 2;
			bData_40002f10_RecentTargetId = bData_40002ece_ConstellationNr;
		
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = 24002;
			//->0x563b8
			break;
		
		case MENU_CONTEXT_NAVIGATION_FAMOUS_STAR: //2300:
			//0x5461c: Navigation -> Famous Star
			bData_40002ed2_FamousStarNr = 1;
			lcd_display_clear();
			bData_40003432 = 0;
			Data_40002c64_MenuContextId = 25001;
			break;
		
		case 25001:
			//0x5464c
			//TODO
			break;
		
		case MENU_CONTEXT_NAVIGATION_MESSIER_CAT: //2400:
			//0x546ec
			wData_40002eb8_MessierNr = 1;
			Data_40002ec8 = 0;
			lcd_display_clear();
			bData_40003432 = 0;
			Data_40002c64_MenuContextId = 23012;
			break;
		
		case 23012:
			//0x54728
			lcd_display_clear();
			Data_40002c64_MenuContextId = 23002;
			break;
		
		case 23002: //???
			//0x54740
			//TODO
			break;
		
		case MENU_CONTEXT_NAVIGATION_NGC_CAT: //2500:
			//0x548e4
			wData_40002eba_NGCNr = 1;
			Data_40002ec8 = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = 23003;
			break;
		
		case 23003:
			//0x5491c
			//TODO
			break;
		
		case MENU_CONTEXT_NAVIGATION_IC_CAT: //2600:
			//0x549bc
			wData_40002ebc_ICNr = 1;
			Data_40002ec8 = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = 23004;
			break;
		
		case 23004:
			//0x549f4
			//TODO
			break;
		
		case MENU_CONTEXT_NAVIGATION_SH2_CAT: //2700:
			//0x54a94
			wData_40002ebe_ShNr = 1;
			Data_40002ec8 = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = 23005;
			break;
		
		case 23005:
			//0x54acc
			//TODO
			break;
		
		case MENU_CONTEXT_NAVIGATION_BRIGHT_STAR: //2800:
			//0x54b6c
			wData_40002ec0 = 1;
			Data_40002ec8 = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = 23006;
			break;
		
		case 23006:
			//0x54ba4
			//TODO
			break;
		
		case MENU_CONTEXT_NAVIGATION_SAO_CAT: //2900:
			//0x54c48: SAO Catalogue
			Data_40002ec4_SAONr = 1;
			Data_40002ec8 = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = 23007;
			break;

		case 23007:
			//0x54c80: SAO item
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);

			dData_40002cc8 = Data_40003358_SAORecord.ra;
			dData_40002d10 = Data_40003358_SAORecord.dec;
			bData_40002e88 = MENU_TRACKING_MODE_POINTING; //1;
			
			func_b64c(dData_40002cc8, dData_40002d10);
			
			bData_40002f0d_RecentTargetType = 9;
			bData_40002f10_RecentTargetId = Data_40002ec4_SAONr;
			
			flash_write_recent_target(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
			lcd_display_clear();
			
			Data_40002c64_MenuContextId = 23017;
			//->0x563b8
		
		case MENU_CONTEXT_NAVIGATION_CUST_OBJ: //2110:
			//0x54d20: Customer Objects
			Data_40002c64_MenuContextId = 201;
			bData_4000319a_SkyLandTargetId = 1;
			break;
		
		case 201:
			//0x54d40
			bData_4000318a = 6;		
			func_50048();
			Data_40002c64_MenuContextId = 203;
			break;
		
		case 203:
			//0x54d64		
		case 204:
			//0x54d6c
		case 205:
			//0x54d70
			func_52478();
			Data_40002c64_MenuContextId = 2110;
			break;
		
		case MENU_CONTEXT_NAVIGATION_RA_DEC: //2120:
			//0x54d84: Input RA/DEC
			Data_40002c64_MenuContextId = 29001;
			bData_4000318a = 6;
			func_50048();
			break;
		
		case 29001:
			//0x54da8
			func_51c7c();
			break;
		
		case 29002:
			//0x54db4
			func_51c7c();
			break;
		
		case MENU_CONTEXT_NAVIGATION_CUST_LAND: //2130:
			//0x54dc0
			Data_40002c64_MenuContextId = 2130;
			bData_4000319a_SkyLandTargetId = 1;
			break;
		
		case 202:
			//0x54de0
			func_517f4();
			bData_4000318a = 6;
			Data_40002c64_MenuContextId = 206;
			break;
		
		case 206:
			//0x54e04
		case 207:
			//0x54e0c
		case 208:
			//0x54e10
			func_514f8();
			Data_40002c64_MenuContextId = 2130;
			break;
		
		case 4400: // Sky/Land
			//0x54e24
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case 45001:
			//0x54e38
			//TODO
			break;
		
		case 45002:
			//0x54f98
			bData_40002e79_SkyLandTargetSeletion = 1;
			bData_400034a9 = 1;
			func_b4d0();
			Data_40002c64_MenuContextId = 4400;
			break;
		
		case MENU_CONTEXT_AZ_EQU: //4500:
			//0x54fc4: AZ / EQ
			#if 1 //Original
			Data_40002c64_MenuContextId = MENU_CONTEXT_AZ_EQU; //4500; //Bug? -> Non-functional
			#else
			if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_MOUNT_AZ; //46001;
			}
			else if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_EQU) //1)
			{
				Data_40002c64_MenuContextId = MENU_CONTEXT_MOUNT_EQU; //46002;
			}
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
		
		case 4800: // Language
			//0x55018
			Data_40002c64_MenuContextId = 49001;
			break;
		
		case 49001: //???
			//0x5502c
			bData_40003196_CurrentLanguage = 1;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49002:
			//0x55084
			bData_40003196_CurrentLanguage = 2;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49003:
			//0x550dc
			bData_40003196_CurrentLanguage = 3;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49004:
			//0x55134
			bData_40003196_CurrentLanguage = 4;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case 49005:
			//0x5518c
			bData_40003196_CurrentLanguage = 5;
			flash_read(0xdcb, 0, 528, Data_400035bc);	
			Data_400035bc[0] = bData_40003196_CurrentLanguage;		
			flash_write(0xdcb, 0, 528, Data_400035bc);
			Data_40002c64_MenuContextId = 4800;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_STAR_SPEED: //4801:
			//0x551e4: Tracking Rate -> "Star Speed"
			dData_40002c98 = 0;
			bData_40002e7c_TrackingRateType = MENU_TRACKING_RATE_STAR_SPEED; //0;
			beep1(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED: //4802:
			//0x5521c: Tracking Rate -> "Solar Speed"
			dData_40002c98 = 0.000000298199444444444492059666153988;
			bData_40002e7c_TrackingRateType = MENU_TRACKING_RATE_SOLAR_SPEED; //1;
			beep1(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_MOON_SPEED: //4803:
			//0x55254: "Moon Speed"
			dData_40002c98 = 0.00000376886111111111134081550801123;
			bData_40002e7c_TrackingRateType = MENU_TRACKING_RATE_MOON_SPEED; //2;
			beep1(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED: //4804:
			//0x55288: "Customize Speed"
			bData_4000318a = 1;
			sprintf(Data_400037cc, "+0%.2f", 1.0); //String???
			sprintf(Data_400037dc, "+0%.2f  starspeed", 1.0);
			Data_40002c64_MenuContextId = 48001;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED: //4805:
			//0x552d0: "Guiding Speed"
			Data_40002c64_MenuContextId = MENU_CONTEXT_GUIDING_SPEED1; //48051;
			break;
		
		case 48001:
			//0x552e4
			//TODO
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED1: //48051:
			//0x55364
			dData_40002ca0 = 0.125;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED2: //48052:
			//0x55490
			dData_40002ca0 = 0.25;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED3: //48053:
			//0x554bc
			dData_40002ca0 = 0.375;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED4: //48054:
			//0x554e8
			dData_40002ca0 = 0.5;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED5: //48055:
			//0x55514
			dData_40002ca0 = 0.625;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED6: //48056:
			//0x55540
			dData_40002ca0 = 0.75;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED7: //48057:
			//0x5556c
			dData_40002ca0 = 0.875;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED8: //48058:
			//0x55598
			dData_40002ca0 = 1.0;
			beep1(2);
			Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
			break;
		
		case MENU_CONTEXT_PARK_POSITION: //3900:
			//0x555c4: Parkposition
			func_75c4();
			bData_40003431 = 1;
			Data_40002c64_MenuContextId = 0;
			break;
		
		case MENU_CONTEXT_CURRENT_OBJECTS: //3100:
			//0x555e8: Current Objects
			bData_40002eb5_SolarSystemObjectNr = 0;
			Data_40002c64_MenuContextId = 31001;
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
			
			bData_4000318a = 1;
			bData_40002e78 = 0;
			Data_40002c64_MenuContextId = 41001;
			break;
		
		case 41001: //"Date and Time Set: "
			//0x556d8
			if (ValidateDateTimeSetRTC() == 1)
			{
				//556e8
				if (bData_40002f1e_SetupLocalData == 1)
				{
					Data_40002c64_MenuContextId = 42002; //->"Daylight saving off"
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
				
				bData_4000318a = 1;
				bData_40002e78 = 0;
				Data_40002c64_MenuContextId = 41001;
			}
			//0x557e8 -> 0x563b8
			break;
		
		case 4200: // Daylight Saving
			//0x55868	
			if (bData_40002c6a == 0)
			{
				Data_40002c64_MenuContextId = 42002; //Daylight saving off
			}
			else
			{
				Data_40002c64_MenuContextId = 42001; //Daylight saving on
			}
			break;
		
		case 42001:
			//0x5589c		
		case 42002: // "Daylight saving"
			//0x558a4
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 4301; //->"Country & City"
			}
			else
			{
				beep1(1);
				Data_40002c64_MenuContextId = 4200; //Daylight Saving?
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
					bData_400031ed = 0;
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					bData_40002f1e_SetupLocalData = 0;
				}
				else
				{
					//0x559e8
					Data_40002c64_MenuContextId = 47011;
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
			bData_40003144 = 0;
			bData_4000318a = 7;
		
			func_2a1c(Data_40003159, &fData_40002e30, &fData_40002e50, &Data_40002e58);
		
			/*Name:*/
			Data_40002827[6] = Data_40003159[0];
			Data_40002827[7] = Data_40003159[1];
			Data_40002827[8] = Data_40003159[2];		
			Data_40002827[9] = Data_40003159[3];		
			Data_40002827[10] = Data_40003159[4];		
			Data_40002827[11] = Data_40003159[5];		
			Data_40002827[12] = Data_40003159[6];		
			Data_40002827[13] = Data_40003159[7];		
		
			if (fData_40002e30 > 0)
			{
				//55abc
				sprintf(Data_40002837, "  Lon:E%03dd%02df ",
					abs((int)fData_40002e30),
					abs((int)((fData_40002e30 - (int)fData_40002e30) * 60)));
			}
			else
			{
				//0x55b4c
				sprintf(Data_40002837, "  Lon:W%03dd%02df ",
					abs((int)fData_40002e30),
					abs((int)((fData_40002e30 - (int)fData_40002e30) * 60)));
			}
			//0x55bd8
			if (fData_40002e50 > 0)
			{
				//55bec
				sprintf(Data_40002847, "  Lat:N%02dd%02df ",
					abs((int)fData_40002e50),
					abs((int)((fData_40002e50 - (int)fData_40002e50) * 60)));
			}
			else
			{
				//0x55c7c
				sprintf(Data_40002847, "  Lat:S%02dd%02df ",
					abs((int)fData_40002e50),
					abs((int)((fData_40002e50 - (int)fData_40002e50) * 60)));
			}
			//0x55d08
			if (Data_40002e58 > 0)
			{
				//55d18
				sprintf(Data_40002856, " Zone:E%02d", abs(Data_40002e58));
			}
			else
			{
				//0x55d48
				sprintf(Data_40002856, " Zone:W%02d", abs(Data_40002e58));
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
		
		case 47011: //Telescope Mount -> "Please setup OTA zero"
			//0x55db0
			func_50778();
			break;
		
		case MENU_CONTEXT_OBJECT_RISE_SET: //3200:
			//0x55dbc: Object Rise/Set
			Data_40002c64_MenuContextId = 29001;
			bData_4000318a = 6;
			func_50048();
			bData_40003162 = 1;
			break;
		
		case 32001:
			//0x55dec
			break;
		
		case 3300: // Curr. Lunar Phase
			//0x55e00
			Data_40002c64_MenuContextId = 33001;
			func_50018();
			break;
		
		case 3400: // Timer
			//0x55e18
			if (Data_40003214_UserTimerSeconds != 0)
			{
				Data_40002c64_MenuContextId = 34002; //->"Counting down:"
			}
			else
			{
				//0x55e3c
				Data_40002c64_MenuContextId = 34001; //->"Set timer:"
				bData_4000318a = 1;
			}
			break;
			
		case 34001:
			//0x55e58
			break;
			
		case 34002:
			//0x55ec0
			break;
			
		case 3500: // Alarm
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
				Data_40002c64_MenuContextId = 35001;
				bData_4000318a = 1;
			}
			//->563b8
			break;
		
		case 35001:
			//0x55f20: Alarm start?
			func_4ff84();
			break;
		
		case 35002:
			//0x55f2c: Alarm stop?
			bData_4000322c = 0;
			Data_40002c64_MenuContextId = 35001;
			break;
		
		case 3601:
			//0x55f4c
			break;
		
		case 360021:
			//0x55f60
			break;
		
		case 360022:
			//0x55f68
			break;
		
		case 370021:
			//0x56048
			break;
		
		case 370022:
			//0x56050
			break;
		
		case 370023:
			//0x56054
			break;
		
		case 360023:
			//0x562f8
			break;
		
		case 3801:
			//0x5634c
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL: //380011:
			//0x56360
			HandleStarKey();
			break;
		
		case 3802:
			//0x5636c
			break;
		
		//TODO
	}	
}

