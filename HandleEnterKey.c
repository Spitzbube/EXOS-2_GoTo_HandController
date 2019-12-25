
extern double func_52720(int a);


/* 52898 - todo */
void HandleEnterKey(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case 0:
			//0x52e68
			if (Data_40004128.bData_364 == 0)
			{
				//52e7c
				func_c8f4();
			}
			else
			{
				//0x52e84
				Data_40002c64_MenuContextId = 1000; //Telescope Align
			}
			//->0x563b8
			break;
		
		case 3:
			//0x52e94
			bData_40003210 = 0;
			bData_40003211 = 0;
			Data_40002c64_MenuContextId = 0;
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
						bData_40002e88 = 1;
						
						func_b64c(dData_40002cc8, dData_40002d10);
						
						bData_40002f0d = 10;
						Data_40002f10 = bData_4000319a_SkyLandTargetId;
						
						func_268c(bData_40002f0d, Data_40002f10);
						func_7950(1);
						
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
						bData_40002e88 = 1;
						
						func_b64c(dData_40002cc8, dData_40002d10);
						
						bData_400034aa = 1;
						bData_40002f0d = 12;
						Data_40002f10 = bData_4000319a_SkyLandTargetId;
						
						func_268c(bData_40002f0d, Data_40002f10);
						func_7950(1);
						
						Data_40002c64_MenuContextId = 0;
						//->0x53150
					}
					else
					{
						//0x530f4
						lcd_display_clear();
						func_7950(1);
						func_7e8(0, 3, 1, 22, " Target Out of Range  ");
						func_7e8(0, 5, 1, 22, "Altitude < -15 Degree ");
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
		
		case 1000:
			//0x53698
			bData_40003173 = 1;
			bData_40003171 = 1;
			bData_40003172 = 1;
			bData_40003170 = 1;
			Data_40002c64_MenuContextId = 1100;
			break;
		
		case 2000:
			//0x536d0
			bData_40003177 = 1;
			bData_40003175 = 1;
			bData_40003176 = 1;
			bData_40003174 = 1;
			Data_40002c64_MenuContextId = 2100;
			break;
		
		case 3000:
			//0x53708
			bData_4000317b = 1;
			bData_40003179 = 1;
			bData_4000317a = 1;
			bData_40003178 = 1;
			Data_40002c64_MenuContextId = 3100;
			break;
		
		case 4000:
			//0x53740
			bData_4000317f = 1;
			bData_4000317d = 1;
			bData_4000317e = 1;
			bData_4000317c = 1;
			Data_40002c64_MenuContextId = 4100;
			break;
		
		case 3600: // Eyepiece FOV
			//0x53778
			bData_4000318a = 7;
			Data_40002c64_MenuContextId = 370021; //->"Eyep. focal length:"
			break;
		
		case 3700: // Eyepiece Magn.
			//0x53798
			bData_4000318a = 7;
			Data_40002c64_MenuContextId = 360021; //->"Eyep. focal length:"
			break;
		
		case 3800: //Display Illumination
			//0x537b8
			Data_40002c64_MenuContextId = 380011;
			//->0x563b8
			break;
		
		case 4300: // Site Setting
			//537cc
			Data_40002c64_MenuContextId = 4301;
			break;
		
		case 4600: // Telescope Mount
			//0x537e0
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
		
		case 4700: // Tracking Rate
			//0x538b4
			Data_40002c64_MenuContextId = 4801;
			break;
		
		case 1100:
			//0x538c8: One Star Align
			Data_40002c5c = 1;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62 = 0; //Alignment Star Selection
		
			bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(func_7f30(1, 0, Data_40004128.geographicLongitude), 
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c); 
		
			Data_40002c64_MenuContextId = 12001;
			//->0x563b8
			break;
		
		case 1200:
			//0x53960: Two Star Align
			Data_40002c5c = 2;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62 = 0;
		
			bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(func_7f30(1, 0, Data_40004128.geographicLongitude), 
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c); 
		
			Data_40002c64_MenuContextId = 12001;
			//->0x563b8
			break;
		
		case 1300:
			//0x539fc: Three Star Align
			Data_40002c5c = 3;
			bData_40002c60_CurrentAlignStarIndex = 1;
			bData_40002c61 = 1;
			bData_40002c62 = 0;
		
			bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(func_7f30(1, 0, Data_40004128.geographicLongitude), 
				Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c); 
		
			Data_40002c64_MenuContextId = 12001;
			//->0x563b8
			break;
		
		case 12001:
			//0x53b68
			bData_400034cd = 0;
			bData_40003430 = 1;
		
			if (bData_40002c62 == 0)
			{
				//53b94: Alignment Star Selection
				switch (bData_40002c61)
				{
					case 1:
						//0x53bb8
						bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(func_7f30(1, 0, Data_40004128.geographicLongitude), 
							Data_40004128.geographicLatitude,
							Data_40004a68_CurrentAlignStarEquatorialCoord, Data_40003a14, Data_40003b2c);
					
						Data_40004128.dData_376 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2];
						Data_40004128.dData_384 = Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2 + 1];
						
						switch (Data_40002c5c)
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
						Data_40002c5c--;
						bData_40002c62 = 1; //"Slewing to Target"
						bData_40002e88 = 0;
						//->0x53f44
						break;
					
					case 2:
						//0x53d04
						if (bData_40002e88 == 2)
						{
							//53d18
							bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(func_7f30(1, 0, Data_40004128.geographicLongitude), 
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
							Data_40002c5c--;
							bData_40002c62 = 1; //"Slewing to Target"
							bData_40002e88 = 0;
						}
						//0x53e1c -> 0x53f44
						break;
					
					case 3:
						//0x53e20
						if (bData_40002e88 == 2)
						{
							bData_400034a8_CurrentAlignStarCount = GetCurrentAlignStars(func_7f30(1, 0, Data_40004128.geographicLongitude), 
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
							Data_40002c5c--;
							bData_40002c62 = 1; //"Slewing to Target"
							bData_40002e88 = 0;
						}
						//0x53f38 -> 0x53f44
						break;
				}
				//53f44 -> 0x53f74
			} //if (bData_40002c62 == 0)
			else
			{
				//0x53f48
				if ((bData_400031e9 == 4) || (bData_400031e9 == 8))
				{
					//0x53f68
					bData_40002c62 = 0; //->(Next) Alignment Star Selection
				}
			}
			//0x53f74
			if (Data_40002c5c != -1)
			{
				//53f84
				Data_40002c64_MenuContextId = 12001;
			}
			//0x53f90 -> 0x563b8
			break;
		
		case 1400: // Target Sync
			//0x53f94
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
			
			func_7950(2);
			break;
		
		case 1402:
			//0x53ffc
			dData_40003410 = dData_400033d8;
			dData_40003418 = -dData_400033e0;
			dData_40003420 = dData_400033d8;
			dData_40003428 = dData_400033e0;
		
			Data_40002c64_MenuContextId = 0;
			bData_400031ea = 0;
			
			func_7950(2);
			break;
		
		case 1403:
			//0x54064
			bData_400031ea = 0;
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 1500: // Pole-Axis Dev.
			//0x54080
			Data_40002c64_MenuContextId = 18001; //->"Pole Axis Dev: "
			break;
		
		case 1600: // RA Bklash Corr.
			//0x54094
			Data_40002c64_MenuContextId = 11102;
			break;
		
		case 11102:
			//0x540a8
			Data_40002c64_MenuContextId = 11101;
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
			//0x54200
			if (Data_40002e9c != 0)
			{
				//54218
				fData_40002e98 = Data_40002e94 / Data_40002e9c;
				
				func_52720(1);
			}
			//0x54244
			
			//TODO
			break;
		
		case 1700: // DEC Bklash Corr.
			//0x54270
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
		
		case 2100:
			//0x543a8: Navigation -> Solar System
			bData_40002eb5_SolarSystemObjectNr = 0;
			lcd_display_clear();
			bData_40003432 = 0;
			Data_40002c64_MenuContextId = 22001; 
			break;
		
		case 22001:
			//0x543d8
			if (bData_40002eb5_SolarSystemObjectNr == 8/*Sun*/)
			{
				lcd_display_clear();
				
				Data_40002c64_MenuContextId = 22112; //->Sun Warning screen
				
				func_7950(1);
			}
			else
			{
				//0x54408
				func_22060(bData_40002eb5_SolarSystemObjectNr, 
					&fData_40002cd0_ObjectRightAscension,
					&fData_40002d18_ObjectDeclination);
				
				dData_40002cc8 = fData_40002cd0_ObjectRightAscension;
				dData_40002d10 = fData_40002d18_ObjectDeclination;
				bData_40002e88 = 1;
				
				func_b64c(dData_40002cc8, dData_40002d10);
				
				bData_40002f0d = 1;
				Data_40002f10 = bData_40002eb5_SolarSystemObjectNr;
				
				func_268c(bData_40002f0d, Data_40002f10);
				lcd_display_clear();
				
				Data_40002c64_MenuContextId = 22111;
			}
			//->0x563b8
			break;
		
		case 22112:
			//0x544a8
			//TODO
			break;
		
		case 2200:
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
			bData_40002e88 = 1;
		
			func_b64c(dData_40002cc8, dData_40002d10);
		
			bData_40002f0d = 2;
			Data_40002f10 = bData_40002ece_ConstellationNr;
		
			func_268c(bData_40002f0d, Data_40002f10);
			lcd_display_clear();
		
			Data_40002c64_MenuContextId = 24002;
			//->0x563b8
			break;
		
		case 2300:
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
		
		case 2400:
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
		
		case 2500:
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
		
		case 2600:
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
		
		case 2700:
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
		
		case 2800:
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
		
		case 2900:
			//0x54c48
			Data_40002ec4_SAONr = 1;
			Data_40002ec8 = 0;
			bData_40003432 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = 23007;
			break;

		case 23007:
			//0x54c80
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);

			dData_40002cc8 = Data_40003358_SAORecord.fData_0;
			dData_40002d10 = Data_40003358_SAORecord.fData_4;
			bData_40002e88 = 1;
			
			func_b64c(dData_40002cc8, dData_40002d10);
			
			bData_40002f0d = 9;
			Data_40002f10 = Data_40002ec4_SAONr;
			
			func_268c(bData_40002f0d, Data_40002f10);
			lcd_display_clear();
			
			Data_40002c64_MenuContextId = 23017;
			//->0x563b8
		
		case 2110: // Customer Objects
			//0x54d20
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
		
		case 2120:
			//0x54d84
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
		
		case 2130:
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
		
		case 4500: // AZ / EQ
			//0x54fc4
			Data_40002c64_MenuContextId = 4500;
			break;
		
		case 46001:
			//0x54fd8
			bData_40002e7a = 0;
			Data_40002c64_MenuContextId = 4500;
			break;
		
		case 46002:
			//0x54ff8
			bData_40002e7a = 1;
			Data_40002c64_MenuContextId = 4500;
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
		
		case 4801:
			//0x551e4
			dData_40002c98 = 0;
			bData_40002e7c = 0;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 4802:
			//0x5521c
			dData_40002c98 = 0.000000298199444444444492059666153988;
			bData_40002e7c = 1;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 4803:
			//0x55254
			dData_40002c98 = 0.00000376886111111111134081550801123;
			bData_40002e7c = 2;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 4804:
			//0x55288
			bData_4000318a = 1;
			sprintf(Data_400037cc, "+0%.2f", 1.0); //String???
			sprintf(Data_400037dc, "+0%.2f  starspeed", 1.0);
			Data_40002c64_MenuContextId = 48001;
			break;
		
		case 4805:
			//0x552d0
			Data_40002c64_MenuContextId = 48051;
			break;
		
		case 48001:
			//0x552e4
			//TODO
			break;
		
		case 48051: //???
			//0x55364
			//TODO
			break;
		
		case 48052:
			//0x55490
			dData_40002ca0 = 0.25;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 48053:
			//0x554bc
			dData_40002ca0 = 0.375;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 48054:
			//0x554e8
			dData_40002ca0 = 0.5;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 48055:
			//0x55514
			dData_40002ca0 = 0.625;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 48056:
			//0x55540
			dData_40002ca0 = 0.75;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 48057:
			//0x5556c
			dData_40002ca0 = 0.875;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 48058:
			//0x55598
			dData_40002ca0 = 1.0;
			func_7950(2);
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 3900: // Parkposition
			//0x555c4
			func_75c4();
			bData_40003431 = 1;
			Data_40002c64_MenuContextId = 0;
			break;
		
		case 3100: // Current Objects
			//0x555e8
			bData_40002eb5_SolarSystemObjectNr = 0;
			Data_40002c64_MenuContextId = 31001;
			break;
		
		case 4100: // Time and Date
			//55608
			//TODO
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
					Data_40002c64_MenuContextId = 4100;
				}
				func_7950(1);
			}
			else
			{
				//0x55720
				func_6518();
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
				func_7950(1);
				Data_40002c64_MenuContextId = 4200; //Daylight Saving?
			}
			break;
		
		case 4301: //Country & City
			//0x558dc
			wData_40003250 = 1;
			wData_40003252 = 0;
			lcd_display_clear();
			Data_40002c64_MenuContextId = 43011;
			break;
		
		case 43011:
			//0x5590c
			flash_get_site_data((unsigned short)(wData_40003250 + wData_40003252), &Data_40003f1c_FlashSiteData);
		
			dData_40002e28_SiteLongitude = Data_40003f1c_FlashSiteData.fLongitude;
			dData_40002e48_SiteLatitude = Data_40003f1c_FlashSiteData.fLatitude;
			Data_40002e54_Zone = Data_40003f1c_FlashSiteData.Zone;
			Data_40004128.geographicLongitude = dData_40002e28_SiteLongitude;
			Data_40004128.geographicLatitude = dData_40002e48_SiteLatitude;
			Data_40004128.Data_64 = Data_40002e54_Zone;
			
			func_7950(2);
		
			if (bData_40002f1e_SetupLocalData == 1)
			{
				//559b8
				if (bData_40002c1a == 1)
				{
					bData_400031ed = 0;
					Data_40002c64_MenuContextId = 0;
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
				Data_40002c64_MenuContextId = 0;
			}
			//->0x563b8
			break;
		
		case 4302: //Custom Site
			//0x55a08
			//TODO
			break;
		
		case 43002: //Custom Site
			//0x55d84
			func_5104c();
			break;
		
		case 4900: // Reset
			//0x55d90
			Data_40002c64_MenuContextId = 100;
			break;
		
		case 100:
			//0x55da4: Reset -> Enter
			HandleReset();
			break;
		
		case 47011: //????
			//0x55db0
			func_50778();
			break;
		
		case 3200: // Object Rise/Set
			//0x55dbc
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
			if (Data_40003214 != 0)
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
			//-> "Input time:"
			break;
		
		case 35001:
			//0x55f20
			break;
		
		case 35002:
			//0x55f2c
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
		
		case 380011:
			//0x56360
			break;
		
		case 3802:
			//0x5636c
			break;
		
		//TODO
	}	
}

