

/* 27844 - todo */
void PrepareScreenItems(void)
{
	SwapLanguageStrings();
	
	#ifdef UART0_DEBUG
	{
		char buf[100];
		snprintf(buf, sizeof(buf)-1, "PrepareScreenItems: MenuContextId=%d\n\r", Data_40002c64_MenuContextId);
		uart0_send(buf, strlen(buf));
	}
	#endif
	
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x28030
			PrepareMainScreenItems();
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_NO_TELESCOPE: //2:
			//0x28054
			Data_40003364 = strThereIsNoTele;
			Data_4000336c = strScopeToConnectThis;
			Data_40003374 = strControlTerminal;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case 0x65: //101
			//0x28090
			Data_40003360 = "F1";
			Data_40003364 = "F2";
			Data_40003368 = "F3";
			Data_4000336c = "F4";
			Data_40003370 = "F5";
			Data_40003374 = "F6";
			Data_40003378 = "F7";
			Data_4000337c = "F8";
			Data_40003380 = "F9";

			switch (bData_40002e79_SkyLandTargetSeletion)
			{
				case 0:
					//0x2811c
					Data_40003384 = "Select Sky Target No ";
					break;
				
				case 1:
					//0x28130
					Data_40003384 = "Select Land Target No";
					break;
				
				default:
					//0x28144
					break;
			}
			//->3d71c
			break;
		
		case 0x66: //102
			//0x28154
			switch (bData_40002e79_SkyLandTargetSeletion)
			{
				case 0:
					//0x28174
					func_5218(bData_4000319a_SkyLandTargetId, &Data_40003f50);
					break;
				
				case 1:
					//0x2818c
					func_54e0(bData_4000319a_SkyLandTargetId, &Data_40003f64);
					break;
				
				default:
					//0x281a4
					break;
			}
			//281b0
			if (((Data_40003f64.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 1)) ||
					((Data_40003f50.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 0)))
			{
				//281f0
				Data_40003360 = "                      ";
				Data_40003364 = "Sorry                 ";
				Data_40003368 = "                      ";
				
				if (bData_40002e79_SkyLandTargetSeletion == 0)
				{
					//28224
					sprintf(Data_40003fe8, "Your Sky F%d is Blank  ", bData_4000319a_SkyLandTargetId);
				}
				//28238
				if (bData_40002e79_SkyLandTargetSeletion == 1)
				{
					//28248
					sprintf(Data_40003fe8, "Your Land F%d is Blank  ", bData_4000319a_SkyLandTargetId);
				}
				//2825c
				Data_4000336c = Data_40003fe8;
				Data_40003370 = "                      ";
				Data_40003374 = "Please Input Data    ";
				Data_40003378 = "                      ";
				Data_4000337c = "                      ";
				//->29978
			}
			else
			{
				//283fc
				if (bData_40002e79_SkyLandTargetSeletion == 0)
				{					
					//2840c
					sprintf(Data_40003fa9, "My Sky Target %d   ", bData_4000319a_SkyLandTargetId);
					
					Data_40003360 = Data_40003fa9;
					Data_40003364 = "                      ";
					Data_40003368 = Data_40003f50.bData_1;
					Data_4000336c = "                      ";
					
					Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
					Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
					Data_40004ae8.dRA = Data_40003f50.fData_12;
					Data_40004ae8.dDec = Data_40003f50.fData_16;
					fData_40002cd0_ObjectRightAscension = Data_40003f50.fData_12;
					fData_40002d18_ObjectDeclination = Data_40003f50.fData_16;
					
					convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
						Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
					//284f8
					sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
						(int)(Data_40004b08.dAzimuth), 
						(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
						(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
						
					if (Data_40004b08.dAltitude >= 0)
					{
						//285d0
						sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude), 
							abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					else
					{
						//286cc
						sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude), 
							abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					//2885c
					if ((int)(Data_40004b08.dAzimuth) < 100)
					{
						Data_40003ffd[11] = ' ';
					}
					
					if ((int)(Data_40004b08.dAzimuth) < 10)
					{
						Data_40003ffd[12] = ' ';
					}
					//288a4
					if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
					{
						Data_40003ffd[15] = ' ';
					}
					//28910
					if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
					{
						Data_40003ffd[18] = ' ';
					}
					//28954
					if (abs((int)Data_40004b08.dAltitude) < 10)
					{
						Data_40004012[5] = ' ';
					}
					//2898c
					if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
					{
						Data_40004012[8] = ' ';
					}
					//28a0c
					if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
					{
						Data_40004012[11] = ' ';
					}
					//28a64
					Data_40003370 = Data_40003ffd;
					Data_40003374 = Data_40004012;
					
					sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
						(int)fData_40002cd0_ObjectRightAscension,
						(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
						(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
						
					if ((int)fData_40002cd0_ObjectRightAscension < 10)
					{
						Data_40004027[5] = ' ';
					}
					//28b2c
					if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
					{
						Data_40004027[8] = ' ';
					}
					//28b7c
					if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
					{
						Data_40004027[11] = ' ';
					}
					//28bb4
					Data_40003378 = Data_40004027;
					
					if (fData_40002d18_ObjectDeclination >= 0)
					{
						//28bd4
						sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
							abs((int)fData_40002d18_ObjectDeclination),
							abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
							abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
					}
					else
					{
						//28cf8
						sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
							abs((int)fData_40002d18_ObjectDeclination),
							abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
							abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
					}
					//28dc4
					if (abs((int)fData_40002d18_ObjectDeclination) < 10)
					{
						Data_4000403c[5] = ' ';
					}
					//28df8
					if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
					{
						Data_4000403c[8] = ' ';
					}
					//28e5c
					if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
					{
						Data_4000403c[11] = ' ';
					}
					//28ea8
					Data_4000337c = Data_4000403c;
					//->29978
				}
				else
				{
					//28eb8
					sprintf(Data_40003fa9, "My Land Target %d", bData_4000319a_SkyLandTargetId);
					
					Data_40003360 = Data_40003fa9;
					Data_40003364 = "                      ";
					Data_40003368 = Data_40003f64.bData_1;
					Data_4000336c = "                      ";

					Data_40004b08.dAzimuth = Data_40003f64.fData_12;
					Data_40004b08.dAltitude = Data_40003f64.fData_16;
										
					sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
						(int)Data_40004b08.dAzimuth,
						(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
						(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
					//28fe8
					if (Data_40004b08.dAltitude >= 0)
					{
						//29004
						sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude),
							abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)),
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					else
					{
						//2915c
						sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude),
							abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)),
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					//29254
					if ((int)Data_40004b08.dAzimuth < 100)
					{
						Data_40003ffd[11] = ' ';
					}
					//29278
					if ((int)Data_40004b08.dAzimuth < 10)
					{
						Data_40003ffd[12] = ' ';
					}
					//2929c
					if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
					{
						Data_40003ffd[15] = ' ';
					}
					//29308
					if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
					{
						Data_40003ffd[18] = ' ';
					}
					//2934c
					if (abs((int)Data_40004b08.dAltitude) < 10)
					{
						Data_40004012[5] = ' ';
					}
					//29384
					if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
					{
						Data_40004012[8] = ' ';
					}
					//29404
					if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
					{
						Data_40004012[11] = ' ';
					}
					//2945c
					Data_40003370 = Data_40003ffd;
					Data_40003374 = Data_40004012;
					
					dData_40002dd0 = dData_40002dc0_Azimuth;
					dData_40002e08 = dData_40002df8;
					
					sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
						(int)dData_40002dd0,
						(int)((dData_40002dd0 - (int)dData_40002dd0) * 60),
						(int)(dData_40002dd0 * 3600) % 60);
					//29540
					if (dData_40002e08 >= 0)
					{
						//29558
						sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
							abs((int)dData_40002e08),
							abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
							abs(((int)(dData_40002e08 * 3600) % 60)));
						//->2972c
					}
					else
					{
						//29644
						sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
							abs((int)dData_40002e08),
							abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
							abs(((int)(dData_40002e08 * 3600) % 60)));
					}
					//2972c
					if ((int)dData_40002dd0 < 100)
					{
						Data_40004027[11] = ' ';
					}
					//2974c
					if ((int)dData_40002dd0 < 10)
					{
						Data_40004027[12] = ' ';
					}
					//2976c
					if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
					{
						Data_40004027[15] = ' ';
					}
					//297d0
					if (((int)(dData_40002dd0 * 3600) % 60) < 10)
					{
						Data_40004027[18] = ' ';
					}
					//29810
					if (abs((int)dData_40002e08) < 10)
					{
						Data_4000403c[5] = ' ';
					}
					//29894
					if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
					{
						Data_4000403c[8] = ' ';
					}
					//2990c
					if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
					{
						Data_4000403c[11] = ' ';
					}
					//29960
					Data_40003378 = Data_40004027;
					Data_4000337c = Data_4000403c;
				}
			}
			//29978
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_RECENT_TARGETS: //1:
			//0x29994: Recent Targets
			bData_40002f14_RecentTargetCount = flash_get_recent_targets(Data_40002f15_RecentTargetTypeArray, 
				Data_4000359c_RecentTargetIdArray, Data_400035bc);
			
			Data_40003360 = "                      ";
			Data_40003364 = "                      ";
			Data_40003368 = "                      ";
			Data_4000336c = "                      ";
			Data_40003370 = "                      ";
			Data_40003374 = "                      ";
			Data_40003378 = "                      ";
			Data_4000337c = "                      ";
		
			Data_40003380 = "   ";
			Data_40003384 = "   ";
			Data_40003388 = "   ";
			Data_4000338c = "   ";
			Data_40003390 = "   ";
			Data_40003394 = "   ";
			Data_40003398 = "   ";
			Data_4000339c = "   ";
			//29a70
			switch (bData_40002f14_RecentTargetCount)
			{
				case 0:
					//0x29aa8
					Data_40003360 = "                      ";
					Data_40003364 = "                      ";
					Data_40003368 = "Sorry                 ";
					Data_4000336c = "                      ";
					Data_40003370 = "No Recent Target     ";
					Data_40003374 = "                      ";
					Data_40003378 = "                      ";
					Data_4000337c = "                      ";
					//->2a0f8
					break;
				
				case 8:
					//0x29b10
					Data_4000339c = "8: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[7];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[7];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//29b64
						Data_4000403c[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
					
					Data_4000337c = Data_4000403c;
					//break; //fall through
				
				case 7:
					//0x29bb8
					Data_40003398 = "7: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[6];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[6];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//29c08
						Data_40004027[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}

					Data_40003378 = Data_40004027;
					//break; //fall through
				
				case 6:
					//0x29c5c
					Data_40003394 = "6: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[5];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[5];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					Data_40003374 = Data_400033a4;

					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//29cbc
						Data_40004012[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					Data_40003374 = Data_40004012;
					//break; //fall through
				
				case 5:
					//0x29d10
					Data_40003390 = "5: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[4];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[4];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29e04
						Data_40003ffd[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					Data_40003370 = Data_40003ffd;
					//break; //fall through
				
				case 4:
					//0x29e58
					Data_4000338c = "4: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[3];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[3];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29ea8
						Data_40003fe8[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					Data_4000336c = Data_40003fe8;
					//break; //fall through
				
				case 3:
					//0x29efc
					Data_40003388 = "3: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[2];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[2];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29f4c
						Data_40003fd3[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					Data_40003368 = Data_40003fd3;
					//break; //fall through
				
				case 2:
					//0x29fa0
					Data_40003384 = "2: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[1];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[1];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29ff0
						Data_40003fbe[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					Data_40003364 = Data_40003fbe;
					//break; //fall through
		
				case 1:
					//0x2a044
					Data_40003380 = "1: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[0];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[0];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					Data_40003360 = Data_400033a4;
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x2a0a4
						Data_40003fa9[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					Data_40003360 = Data_40003fa9;
					//break; //fall through
				
				#if 0
				default:
					//0x2a0f8
					break;
				#endif
			}
			//->3d71c
			break;
		
		case MENU_CONTEXT_ALIGNMENT: //1000:
			//0x2a100 - Telescope Align
			Data_40003360 = strTelescopeAlign;
			Data_40003364 = "";
			Data_40003368 = strNavigation;
			Data_4000336c = "";
			Data_40003370 = strUtilities;
			Data_40003374 = "";
			Data_40003378 = strSetup;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 1;
		
			g_pcstrFourLineMenu1 = strTelescopeAlign;
			g_pcstrFourLineMenu2 = strNavigation;
			g_pcstrFourLineMenu3 = strUtilities;
			g_pcstrFourLineMenu4 = strSetup;
		
			bData_4000316f_FocusLineOn4LineDisplay = 1;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_NAVIGATION: //2000:
			//0x2a220 - Navigation
			Data_40003360 = strTelescopeAlign;
			Data_40003364 = "";
			Data_40003368 = strNavigation;
			Data_4000336c = "";
			Data_40003370 = strUtilities;
			Data_40003374 = "";
			Data_40003378 = strSetup;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 3;
		
			g_pcstrFourLineMenu1 = strTelescopeAlign;
			g_pcstrFourLineMenu2 = strNavigation;
			g_pcstrFourLineMenu3 = strUtilities;
			g_pcstrFourLineMenu4 = strSetup;
		
			bData_4000316f_FocusLineOn4LineDisplay = 2;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_UTILITIES: //3000:
			//0x2a2f4 - Utilities
			Data_40003360 = strTelescopeAlign;
			Data_40003364 = "";
			Data_40003368 = strNavigation;
			Data_4000336c = "";
			Data_40003370 = strUtilities;
			Data_40003374 = "";
			Data_40003378 = strSetup;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 5;
		
			g_pcstrFourLineMenu1 = strTelescopeAlign;
			g_pcstrFourLineMenu2 = strNavigation;
			g_pcstrFourLineMenu3 = strUtilities;
			g_pcstrFourLineMenu4 = strSetup;
		
			bData_4000316f_FocusLineOn4LineDisplay = 3;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_SETUP: //4000:
			//0x2a3c8 - Setup
			Data_40003360 = strTelescopeAlign;
			Data_40003364 = "";
			Data_40003368 = strNavigation;
			Data_4000336c = "";
			Data_40003370 = strUtilities;
			Data_40003374 = "";
			Data_40003378 = strSetup;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 7;
		
			g_pcstrFourLineMenu1 = strTelescopeAlign;
			g_pcstrFourLineMenu2 = strNavigation;
			g_pcstrFourLineMenu3 = strUtilities;
			g_pcstrFourLineMenu4 = strSetup;
		
			bData_4000316f_FocusLineOn4LineDisplay = 4;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_ONE_STAR_ALIGN: //1100:
			//0x2a49c: One Star Align
		case MENU_CONTEXT_TWO_STAR_ALIGN: //1200:
			//0x2a4a4: Two Star Align
		case MENU_CONTEXT_THREE_STAR_ALIGN: //1300:
			//0x2a4a8: Three Star Align
		case MENU_CONTEXT_TARGET_SYNC: //1400:
			//0x2a4ac: Target Sync
		case MENU_CONTEXT_POLE_AXIS_DEV: //1500:
			//0x2a4b0: Pole-Axis Dev.
		case MENU_CONTEXT_RA_BKBLASH_CORR: //1600:
			//0x2a4b4: RA Bklash Corr.
		case MENU_CONTEXT_DEC_BKLASH_CORR: //1700:
			//0x2a4b8: DEC Bklash Corr.
			PrepareEightLineMenuScroll(11, g_bAlignmentEightLineMenuTopItem);
		
			bData_4000316e_FocusLineOn8LineDisplay = g_bAlignmentEightLineMenuFocusItem;
		
			PrepareFourLineMenuScroll(11, g_bAlignmentFourLineMenuTopItem);
		
			bData_4000316f_FocusLineOn4LineDisplay = g_bAlignmentFourLineMenuFocusItem;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM: //2100:
			//0x2a500: Solar System
		case MENU_CONTEXT_NAVIGATION_CONSTELLATION: //2200:
			//0x2a508: Constellation
		case MENU_CONTEXT_NAVIGATION_FAMOUS_STAR: //2300:
			//0x2a50c: Famous Star
		case MENU_CONTEXT_NAVIGATION_MESSIER_CAT: //2400:
			//0x2a510: Messier Catal.
		case MENU_CONTEXT_NAVIGATION_NGC_CAT: //2500:
			//0x2a514: NGC Catalog.
		case MENU_CONTEXT_NAVIGATION_IC_CAT: //2600:
			//0x2a518: IC Catalogue
		case MENU_CONTEXT_NAVIGATION_SH2_CAT: //2700:
			//0x2a51c: Sh2 Catalog.
		case MENU_CONTEXT_NAVIGATION_BRIGHT_STAR: //2800:
			//0x2a520: Bright Star Cat.
		case MENU_CONTEXT_NAVIGATION_SAO_CAT: //2900:
			//0x2a524: SAO Star Catal.
		case MENU_CONTEXT_NAVIGATION_CUST_OBJ: //2110:
			//0x2a528: Customer Objects
		case MENU_CONTEXT_NAVIGATION_RA_DEC: //2120:
			//0x2a52c: Input RA and DEC
		case MENU_CONTEXT_NAVIGATION_CUST_LAND: //2130:
			//0x2a530: Custom Land Goal
			PrepareEightLineMenuScroll(12, bData_40003174);
		
			bData_4000316e_FocusLineOn8LineDisplay = bData_40003176;
		
			PrepareFourLineMenuScroll(12, bData_40003175);
		
			bData_4000316f_FocusLineOn4LineDisplay = bData_40003177;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_CURRENT_OBJECTS: //3100:
			//0x2a578: Current Objects
		case MENU_CONTEXT_OBJECT_RISE_SET: //3200:
			//0x2a580: Object Rise/Set
		case MENU_CONTEXT_LUNAR_PHASE: //3300:
			//0x2a584
		case MENU_CONTEXT_TIMER: //3400:
			//0x2a588
		case MENU_CONTEXT_ALARM: //3500:
			//0x2a58c
		case MENU_CONTEXT_EYEPIECE_FOV: //3600:
			//0x2a590: Eyepiece FOV
		case MENU_CONTEXT_EYEPIECE_MAGN: //3700:
			//0x2a594: Eyepiece Magn.
		case MENU_CONTEXT_DISPLAY_ILLUMINATION: //3800:
			//0x2a598: Display Illumin.
		case MENU_CONTEXT_PARK_POSITION: //3900:
			//0x2a59c: Parkposition
			PrepareEightLineMenuScroll(13, bData_40003178);
		
			bData_4000316e_FocusLineOn8LineDisplay = bData_4000317a;
		
			PrepareFourLineMenuScroll(13, bData_40003179);
		
			bData_4000316f_FocusLineOn4LineDisplay = bData_4000317b;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_TIME_DATE: //4100:
			//0x2a5e4: Time and Date
		case MENU_CONTEXT_DAYLIGHT_SAVING: //4200:
			//0x2a5ec
		case MENU_CONTEXT_SITE_SETTING: //4300:
			//0x2a5f0: Site Setting
		case MENU_CONTEXT_SKY_LAND: //4400:
			//0x2a5f4
		case MENU_CONTEXT_AZ_EQU: //4500:
			//0x2a5f8
		case MENU_CONTEXT_TELESCOPE_MOUNT: //4600:
			//0x2a5fc: Telescope Mount
		case MENU_CONTEXT_TRACKING_RATE: //4700:
			//0x2a600
		case MENU_CONTEXT_LANGUAGE: //4800:
			//0x2a604
		case MENU_CONTEXT_RESET: //4900:
			//0x2a608
			PrepareEightLineMenuScroll(14, bData_4000317c);
		
			bData_4000316e_FocusLineOn8LineDisplay = bData_4000317e;
		
			PrepareFourLineMenuScroll(14, bData_4000317d);
		
			bData_4000316f_FocusLineOn4LineDisplay = bData_4000317f;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case 0x899: //2201
			//0x2a650
		case 0x89A: //2202
			//0x2a658
		case 0x89B: //2203
			//0x2a65c
		case 0x89C: //2204
			//0x2a660
		case 0x89D: //2205
			//0x2a664
		case 0x89E: //2206
			//0x2a668
		case 0x89F: //2207
			//0x2a66c
		case 0x8A0: //2208
			//0x2a670
		case 0x8A1: //2209
			//0x2a674
		case 0x55FC: //22012
			//0x2a678
			PrepareEightLineMenuScroll(22, bData_40003180);
		
			bData_4000316e_FocusLineOn8LineDisplay = bData_40003182;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0x8FD: //2301
			//0x2a6a8
		case 0x8FE: //2302
			//0x2a6b0
		case 0x8ff: //2303
			//0x2a6b4
		case 0x900: //2304
			//0x2a6b8
		case 2305: 
			//0x2a6bc
		case 2306:
			//0x2a6c0
		case 2307:
			//0x2a6c4
		case 2308:
			//0x2a6c8
			PrepareEightLineMenuScroll(23, bData_40003184);
		
			bData_4000316e_FocusLineOn8LineDisplay = bData_40003186;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0x9c5: //2501
			//0x2a6f8
			Data_40003360 = strScientificName;
			Data_40003364 = "";
			Data_40003368 = strSAOCatalog;
			Data_4000336c = "";
			Data_40003370 = strHRCatalog;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0x9c6: //2502
			//0x2a780
			Data_40003360 = strScientificName;
			Data_40003364 = "";
			Data_40003368 = strSAOCatalog;
			Data_4000336c = "";
			Data_40003370 = strHRCatalog;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0x9C7: //2503
			//0x2a80c
			Data_40003360 = strScientificName;
			Data_40003364 = "";
			Data_40003368 = strSAOCatalog;
			Data_4000336c = "";
			Data_40003370 = strHRCatalog;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xAF1: //2801
			//0x2a898
			Data_40003360 = strSelect;
			Data_40003364 = "";
			Data_40003368 = strAdd;
			Data_4000336c = "";
			Data_40003370 = strDelete;
			Data_40003374 = "";
			Data_40003378 = strModify;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xAF2: //2802
			//0x2a924
			Data_40003360 = strSelect;
			Data_40003364 = "";
			Data_40003368 = strAdd;
			Data_4000336c = "";
			Data_40003370 = strDelete;
			Data_40003374 = "";
			Data_40003378 = strModify;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xAF3: //2803
			//0x2aa2c
			Data_40003360 = strSelect;
			Data_40003364 = "";
			Data_40003368 = strAdd;
			Data_4000336c = "";
			Data_40003370 = strDelete;
			Data_40003374 = "";
			Data_40003378 = strModify;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xAF4: //2804
			//0x2aabc
			Data_40003360 = strSelect;
			Data_40003364 = "";
			Data_40003368 = strAdd;
			Data_4000336c = "";
			Data_40003370 = strDelete;
			Data_40003374 = "";
			Data_40003378 = strModify;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 7;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0x526D: //21101
			//0x2ab4c
			Data_40003360 = Data_40003044; //"Select"
			Data_40003364 = "";
			Data_40003368 = Data_40003048; //"Add"
			Data_4000336c = "";
			Data_40003370 = Data_4000304c; //"Delete"
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0x526E: //21102
			//0x2abd4
			Data_40003360 = Data_40003044;
			Data_40003364 = "";
			Data_40003368 = Data_40003048;
			Data_4000336c = "";
			Data_40003370 = Data_4000304c;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0x526F: //21103
			//0x2ac60
			Data_40003360 = Data_40003044;
			Data_40003364 = "";
			Data_40003368 = Data_40003048;
			Data_4000336c = "";
			Data_40003370 = Data_4000304c;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xE11: //3601
			//0x2acec
			Data_40003360 = strEyeshot;
			Data_40003364 = strRatio;
			Data_40003368 = "";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xE12: //3602
			//0x2ad70
			Data_40003360 = strEyeshot;
			Data_40003364 = strRatio;
			Data_40003368 = "";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xED9: //3801
			//0x2adf8
			Data_40003360 = strBackBoard;
			Data_40003364 = strAccessory;
			Data_40003368 = "";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xEDA: //3802
			//0x2ae7c
			Data_40003360 = strBackBoard;
			Data_40003364 = strAccessory;
			Data_40003368 = "";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case MENU_CONTEXT_COUNTRY_CITY: //4301:
			//0x2af04: Country & City
			Data_40003360 = strCountryAndCity;
			Data_40003368 = strCustomSite;
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE: //4302:
			//0x2af88: Custom Site
			Data_40003360 = strCountryAndCity;
			Data_40003368 = strCustomSite;
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xA80D: //43021
			//0x2b010
			Data_40003360 = Data_40003068; //"Select"
			Data_40003368 = Data_4000306c;
			Data_40003370 = Data_40003070;
			Data_40003378 = Data_40003074; //"Modify"
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003374 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xA80E: //43022
			//0x2b09c
			Data_40003360 = Data_40003068;
			Data_40003368 = Data_4000306c;
			Data_40003370 = Data_40003070;
			Data_40003378 = Data_40003074;
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003374 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xA80F: //43023
			//0x2b184
			Data_40003360 = Data_40003068;
			Data_40003368 = Data_4000306c;
			Data_40003370 = Data_40003070;
			Data_40003378 = Data_40003074;
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003374 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xA810: //43024
			//0x2b214
			Data_40003360 = Data_40003068;
			Data_40003368 = Data_4000306c;
			Data_40003370 = Data_40003070;
			Data_40003378 = Data_40003074;
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003374 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 7;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case MENU_CONTEXT_TRACKING_RATE_STAR_SPEED: //4801:
			//0x2b2a4
			Data_40003360 = strStarSpeed;
			Data_40003364 = strSolarSpeed;
			Data_40003368 = strMoonSpeed;
			Data_4000336c = Data_40003094; // "Customize Speed"
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = Data_40003098; // "Guiding Speed"
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED: //4802:
			//0x2b334
			Data_40003360 = strStarSpeed;
			Data_40003364 = strSolarSpeed;
			Data_40003368 = strMoonSpeed;
			Data_4000336c = Data_40003094;
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = Data_40003098;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_MOON_SPEED: //4803
			//0x2b3c8
			Data_40003360 = strStarSpeed;
			Data_40003364 = strSolarSpeed;
			Data_40003368 = strMoonSpeed;
			Data_4000336c = Data_40003094;
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = Data_40003098;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED: //4804
			//0x2b45c
			Data_40003360 = strStarSpeed;
			Data_40003364 = strSolarSpeed;
			Data_40003368 = strMoonSpeed;
			Data_4000336c = Data_40003094;
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = Data_40003098;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 4;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED: //4805
			//0x2b4f0
			Data_40003360 = strStarSpeed;
			Data_40003364 = strSolarSpeed;
			Data_40003368 = strMoonSpeed;
			Data_4000336c = Data_40003094;
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = Data_40003098;
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 7;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case MENU_CONTEXT_GUIDING_SPEED1: //48051
			//0x2b584: Setup -> Tracking Rate -> Guiding Speed
			Data_40003360 = "speed1:   x 0.125";
			Data_40003364 = "speed2:   x 0.250";
			Data_40003368 = "speed3:   x 0.375";
			Data_4000336c = "speed4:   x 0.500";
			Data_40003370 = "speed5:   x 0.625";
			Data_40003374 = "speed6:   x 0.750";
			Data_40003378 = "speed7:   x 0.875";
			Data_4000337c = "speed8:   x 1.000";
		
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED2: //48052
			//0x2b600
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			//->3d71c
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED3: //48053
			//0x2b614
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			//->3d71c
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED4: //48054
			//0x2b628
			bData_4000316e_FocusLineOn8LineDisplay = 4;
			//->3d71c
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED5: //48055
			//0x2b63c
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			//->3d71c
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED6: //48056
			//0x2b650
			bData_4000316e_FocusLineOn8LineDisplay = 6;
			//->3d71c
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED7: //48057
			//0x2b664
			bData_4000316e_FocusLineOn8LineDisplay = 7;
			//->3d71c
			break;
		
		case MENU_CONTEXT_GUIDING_SPEED8: //48058
			//0x2b678
			bData_4000316e_FocusLineOn8LineDisplay = 8;
			//->3d71c
			break;

		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x2b68c: One / Two / Three Star Align
			numVisibleAlignmentStars = GetCurrentAlignStars(get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude), Data_40004128.geographicLatitude,
				Data_40004a68_CurrentAlignStarEquatorialCoord, arAlignmentStarNames, Data_40003b2c);
			
			sprintf(Data_40003ffd, "R.a: %02dh%02dm                ",
				(int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2],
				(int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2]) * 60));

			if ((int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2] < 10)
			{
				Data_40003ffd[5] = ' ';
			}
			
			if ((int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2]) * 60) < 10)
			{
				Data_40003ffd[8] = ' ';
			}
			
			if (Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] < 0)
			{
				//2b848
				sprintf(Data_40004012, "Dec:-%02d %02d                 ",
					abs((int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1]),
					abs((int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1]) * 60)));				
			}
			else
			{
				//0x2ba08
				sprintf(Data_40004012, "Dec:+%02d %02d                 ",
					(int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1],
					abs((int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1]) * 60)));				
			}

			if ((int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] < 10)
			{
				Data_40004012[5] = ' ';
			}
			
			if ((int) (((Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) /*+ 1*/])+1) * 60) < 10) //BUG!
			{
				Data_40004012[8] = ' ';
			}
			//2bb70
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				//2bb80: Slewing to target -> Show OTA Az/Alt
				switch (bData_40002e7a_MountType)
				{
					case 1:
						//2bb98
						dData_40002c90 = dData_40002d98;					
						dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;
						//->0x2bc04
						while (dData_40002c88 >= 24)
						{
							dData_40002c88 -= 24;
						}
						while (dData_40002c88 < 0)
						{
							dData_40002c88 += 24;
						}
						//2bc54
						Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
						Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
						
						Data_40004b50.dRA = dData_40002c88;
						Data_40004b50.dDec = dData_40002c90;
						
						convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
							Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

						dData_40002dd0 = Data_40004b70.dAzimuth;
						dData_40002e08 = Data_40004b70.dAltitude;
						
						Data_40002dac = dData_40002dd0;
						Data_40002db0 = (dData_40002dd0 - Data_40002dac) * 60;
						
						Data_40002de0 = dData_40002e08;
						Data_40002de4 = (dData_40002e08 - Data_40002de0) * 60;
						//2be4c
						fData_40002de8 = (dData_40002e08 - Data_40002de0 - Data_40002de4 / 60.0) * 3600;						
						//break; // Fall through?
					
					case 0:
						//0x2bedc
						sprintf(Data_40003ffd, "Azi:%03d %02d          ",
							abs(Data_40002dac), abs(Data_40002db0));
					
						if (abs(Data_40002dac) < 100)
						{
							Data_40003ffd[4] = ' ';
						}
						if (abs(Data_40002dac) < 10)
						{
							Data_40003ffd[5] = ' ';
						}
						if (abs(Data_40002db0) < 10)
						{
							Data_40003ffd[8] = ' ';
						}
						
						sprintf(Data_40004012, "Alt: %02d %02d          ", 
							abs(Data_40002de0), abs(Data_40002de4));

						if (abs(Data_40002de0) < 10)
						{
							Data_40004012[5] = ' ';
						}
						if (abs(Data_40002de4) < 10)
						{
							Data_40004012[8] = ' ';
						}						
						break;
					
					default:
						//0x2c068
						break;
				} //switch (bData_40002e7a_MountType)
			} //if (bData_40002c62_AlignmentStarMode != 0)
			//0x2c074
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			
			Data_40004ae8.dRA = Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1)];
			Data_40004ae8.dDec = Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1];
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);

			sprintf(Data_40004027, "Azi:%03d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60));
				
			sprintf(Data_4000403c, "Alt:+%02d %02d               ",
				abs((int)Data_40004b08.dAltitude),
				abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)));
			
			if (bTrackingMode == 1)
			{
				//2c2cc
				sprintf(Data_40004027, "Azi:%03d %02d                ",
					(int)Data_40004b08.dAzimuth,
					(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60));
				
				sprintf(Data_4000403c, "Alt:+%02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)));			
			}
			//0x2c3fc
			if ((int)Data_40004b08.dAzimuth < 100)
			{
				Data_40004027[4] = ' ';
			}
			if ((int)Data_40004b08.dAzimuth < 10)
			{
				Data_40004027[5] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40004027[8] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			
			Data_40003360 = strListAlignStars; //"List align stars:"
			Data_40003364 = "                     ";
			Data_40003368 = arAlignmentStarNames[bData_40002c60_CurrentAlignStarIndex - 1];
			Data_4000336c = "                        ";
			Data_40003370 = Data_40004027; //"OBJ:      Azi:..."???
			Data_40003374 = Data_4000403c;
			Data_40003378 = Data_40003ffd;
			Data_4000337c = Data_40004012;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_MERIDIAN_FLIP: //3:
			//0x2c658
			beep1(1);
		
			Data_40003360 = "Star move meridian";
			Data_40003364 = "and telestope stop or";
			Data_40003368 = "reverse after 10 mins";
			Data_4000336c = "";
			Data_40003370 = "ENTER:  Reverse";
			Data_40003374 = "";
			Data_40003378 = "CANCEL: Stop";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SYNC_OPEN: //1401:
			//0x2c6e0
			Data_40003360 = "";
			Data_40003364 = "Targers Sync. Open?";
			Data_40003368 = "";
			Data_4000336c = "";
			Data_40003370 = "     ENTER:Yes";
			Data_40003374 = "";
			Data_40003378 = "     CANCEL:No";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SYNC_ENSURE: //1402:
			//0x2c760
			Data_40003360 = "Targers Sync. ensure!";
			Data_40003364 = "";
			Data_40003368 = "Targers Sync. cancel!";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SYNC_CANCEL: //1403
			//0x2c7dc
			Data_40003360 = "Targers Sync. ensure!";
			Data_40003364 = "";
			Data_40003368 = "Targers Sync. cancel!";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_POLE_AXIS_DEV_INPUT: //18001:
			//0x2c85c
			Data_40003360 = "Pole Axis Dev: ";
			Data_40003364 = "";
		
			if (g_dPoleAxisDevEastWest > 0)
			{
				//2c890
				sprintf(Data_40003fa9, "ToE:%.5f\011Degree", fabs(g_dPoleAxisDevEastWest));
			}
			else
			{
				//0x2c8bc
				sprintf(Data_40003fa9, "ToW:%.5f\011Degree", fabs(g_dPoleAxisDevEastWest));
			}
			//0x2c8e4
			Data_40003368 = Data_40003fa9;
			
			if (g_dPoleAxisDevNorthSouth > 0)
			{
				//2c908
				sprintf(Data_40003fbe, "ToN:%.5f\011Degree", fabs(g_dPoleAxisDevNorthSouth));
			}
			else
			{
				//0x2ca50
				sprintf(Data_40003fbe, "ToS:%.5f\011Degree", fabs(g_dPoleAxisDevNorthSouth));
			}
			//0x2ca78
			Data_4000336c = "";
			Data_40003370 = Data_40003fbe;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x2cad0: RA Bklash Corr. - 1st page
			Data_40003360 = "                      ";
			Data_40003364 = strPleaseAimAtThe;
			Data_40003368 = "                      ";
			Data_4000336c = strTelescopeToDistant;
			Data_40003370 = "                      ";
			Data_40003374 = strTargetThenPress;
			Data_40003378 = "                      ";
			Data_4000337c = strEnterKey;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
			//0x2cb60: RA Bklash Corr. - 2nd page
			Data_40003360 = "                      ";
			Data_40003364 = Data_400030dc; // "Press RIGHT or LEFT"
			Data_40003368 = "                      ";
			Data_4000336c = Data_400030e0; // "key to start Ra(Azi)"
			Data_40003370 = "                      ";
			Data_40003374 = Data_400030e4; // "backlash align,press"
			Data_40003378 = "                      ";
			Data_4000337c = Data_400030e8; // "ENTER key to finish!"
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103
			//0x2cbf0
			Data_40003360 = "                      ";
			Data_40003364 = Data_400030ec; //"Slewing....."
			Data_40003368 = "                      ";
			Data_4000336c = Data_400030f0; //"After beep, turn tele"
			Data_40003370 = "                      ";
			Data_40003374 = Data_400030f4; //"-cope back to target"
			Data_40003378 = "                      ";
			Data_4000337c = Data_400030f8; //"then press,ENTER!"
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_RESULT: //11104
			//0x2cc80
			sprintf(Data_40003fa9, "%.1f", fData_40002e90);
		
			Data_40003360 = "                      ";
			Data_40003364 = "                      ";
		
			if (bRaBacklashCorrectionDirection == 2)
			{
				Data_40003368 = Data_400030fc; //"Positive backlash is:"
			}
			//0x2cce4
			if (bRaBacklashCorrectionDirection == 1)
			{
				Data_40003368 = Data_40003100; //"Negative backlash is: "
			}
			//0x2cd04
			Data_4000336c = "                      ";
			Data_40003370 = Data_40003fa9;
			Data_40003374 = "                      ";
			Data_40003378 = Data_40003104; //"          arcsecond"
			Data_4000337c = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case 11105:
			//0x2cdc0
			sprintf(Data_40003fa9, "%.1f", fData_40002e98);
		
			Data_40003360 = "                      ";
			Data_40003364 = "                      ";
			Data_40003368 = Data_40003108; //"The mean backlash is:"
			Data_4000336c = "                      ";
			Data_40003370 = Data_40003fa9;
			Data_40003374 = "                      ";
			Data_40003378 = Data_40003104; //"          arcsecond"
			Data_4000337c = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x2ce70
			Data_40003360 = "                      ";
			Data_40003364 = strPleaseAimAtThe;
			Data_40003368 = "                      ";
			Data_4000336c = strTelescopeToDistant;
			Data_40003370 = "                      ";
			Data_40003374 = strTargetThenPress;
			Data_40003378 = "                      ";
			Data_4000337c = strEnterKey;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN: //11201:
			//0x2cf00
			Data_40003360 = "                      ";
			Data_40003364 = Data_4000310c; // "press UP or DOWN"
			Data_40003368 = "                      ";
			Data_4000336c = Data_40003110; // "key to start Dec(Alt)"
			Data_40003370 = "                      ";
			Data_40003374 = Data_400030e4; // "backlash align,press"
			Data_40003378 = "                      ";
			Data_4000337c = Data_400030e8; // "ENTER key to finish!"
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203
			//0x2cf90
			Data_40003360 = "                      ";
			Data_40003364 = Data_400030ec;
			Data_40003368 = "                      ";
			Data_4000336c = Data_400030f0;
			Data_40003370 = "                      ";
			Data_40003374 = Data_400030f4;
			Data_40003378 = "                      ";
			Data_4000337c = Data_400030f8;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_RESULT: //11204
			//0x2d020
			sprintf(Data_40003fa9, "%.1f", fData_40002ea0);
		
			Data_40003360 = "                      ";
			Data_40003364 = "                      ";
		
			if (bDecBacklashCorrectionDirection == 2)
			{
				Data_40003368 = Data_400030fc; //"Positive backlash is:"
			}
			//0x2d084
			if (bDecBacklashCorrectionDirection == 1)
			{
				Data_40003368 = Data_40003100; //"Negative backlash is: "
			}
			//0x2d0a4
			Data_4000336c = "                      ";
			Data_40003370 = Data_40003fa9;
			Data_40003374 = "                      ";
			Data_40003378 = Data_40003104;
			Data_4000337c = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case 0x2BC5: //11205
			//0x2d100
			sprintf(Data_40003fa9, "%.1f", fData_40002ea8);
		
			Data_40003360 = "                      ";
			Data_40003364 = "                      ";
			Data_40003368 = Data_40003108; //"The mean backlash is:"
			Data_4000336c = "                      ";
			Data_40003370 = Data_40003fa9;
			Data_40003374 = "                      ";
			Data_40003378 = Data_40003104; //"          arcsecond"
			Data_4000337c = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
			//0x2d1b0
			get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
				&fData_40002cd0_ObjectRightAscension, &fData_40002d18_ObjectDeclination);
		
			Data_40003360 = Data_4000314c_SolarSystemObjectName;
			Data_40003364 = "                      ";
			Data_40003368 = "                      ";
			Data_4000336c = "                      ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ", 
				(int) Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60),
				((int) (Data_40004b08.dAzimuth * 3600)) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//2d35c
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
			}
			else				
			{
				//0x2d458
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
			}
			//0x2d550
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x2d758
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			//2d770
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int) fData_40002cd0_ObjectRightAscension,
				(int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60),
				(int) (fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			//2d8a8
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//2d8c8
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			else
			{
				//0x2d998
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			//0x2da64
			if (abs((int) fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int) (fData_40002d18_ObjectDeclination * 3600) % 60)) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x2db48
			Data_4000337c = Data_4000403c;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_SUN_WARNING: //22112:
			//0x2db70: Sun Warning screen
			Data_40003360 = "                     ";
			Data_40003364 = "    DO NOT POINT     ";
			Data_40003368 = "the telescope or its ";
			Data_4000336c = "viewfinder at or near";
			Data_40003370 = "the Sun!!!           ";
			Data_40003374 = "                     ";
			Data_40003378 = "ENTER:continue       ";
			Data_4000337c = "    -:return         ";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x2dd24: Target Under Horizon / Slewing To Target / Find Target,Tracking
			get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
				&fData_40002cd0_ObjectRightAscension, &fData_40002d18_ObjectDeclination);
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);

			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ", 
				(int) Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60),
				((int) (Data_40004b08.dAzimuth * 3600)) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//2de9c
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
			}
			else				
			{
				//0x2df98
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x2e09c
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x2e2a4
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//2e2ec
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;
				//->0x2e354
				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//2e3a4
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;
			}
			//0x2e44c
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
			//2e534
			if (dData_40002e08 >= 0)
			{
				//2e54c
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
				//->0x2e720
			}
			else
			{
				//0x2e638
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//2e720
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x2e904
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;
			
			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x2e93c
				bTrackingModeMenu = bTrackingMode;
			}
			//0x2e94c
			#if 1
			if (Data_40004b08.dAltitude < 0)
			{
				if ((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2))
				{
					//0x2e988
					bTrackingModeMenu = 3;
				}
			}
			#else
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x2e988
				bTrackingModeMenu = 3;
			}
			#endif
			//0x2e994
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x2e9c0
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x2e9d4
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x2e9e8
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x2ea08
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x2ea1c
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x2ea30
					Data_40003360 = "                              ";
					break;
			}
			//0x2ea44
			Data_40003364 = "                              ";
			Data_40003368 = Data_4000314c_SolarSystemObjectName;
			Data_4000336c = "                              ";

			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_CONSTELLATION_SELECTION: //24001:
			//0x2ea8c
			flash_get_constellation_data(bData_40002ece_ConstellationNr, 
				&Data_40003dd4_FlashConstellationData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003dd4_FlashConstellationData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003dd4_FlashConstellationData.fDeclination;
		
			Data_40003360 = Data_40003dd4_FlashConstellationData.bData_5;
			Data_40003364 = "                      ";
		
			sprintf(Data_40003fd3, "    Area: %d SQ.Deg               ", 
				Data_40003dd4_FlashConstellationData.wArea);
		
			Data_40003368 = Data_40003fd3;
			Data_40003368[0] = Data_40003dd4_FlashConstellationData.bData_5[0];
			Data_40003368[1] = Data_40003dd4_FlashConstellationData.bData_5[1];
			Data_40003368[2] = Data_40003dd4_FlashConstellationData.bData_5[2];
		
			sprintf(Data_40003fe8, "Quantity: %d (>6Mag)             ",
				Data_40003dd4_FlashConstellationData.bQuantity);
		
			Data_4000336c = Data_40003fe8;
			
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
			
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//2ecb0
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x2ef0c
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			//0x2f004
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x2f20c
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int) fData_40002cd0_ObjectRightAscension,
				(int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60),
				(int) (fData_40002cd0_ObjectRightAscension * 3600) % 60);
			
			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			//0x2f35c
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//2f37c
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			else
			{
				//0x2f44c
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			//0x2f518
			if (abs((int) fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int) (fData_40002d18_ObjectDeclination * 3600) % 60)) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x2f5fc
			Data_4000337c = Data_4000403c;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002
			//0x2f624
			flash_get_constellation_data(bData_40002ece_ConstellationNr, &Data_40003dd4_FlashConstellationData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003dd4_FlashConstellationData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003dd4_FlashConstellationData.fDeclination;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//2f7b8
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x2f8b4
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
					
				bTrackingModeMenu = 3;
			}
			//0x2f9b8
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x2fbc0
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//2fc08
				dData_40002c90 = dData_40002d98;				
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;
				//->0x2fc70
				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//2fcc0
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);
				
				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;
			}
			//0x2fd68
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//2fec8
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x2ffb4
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3009c
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x30280
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;
			
			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x302b8
				bTrackingModeMenu = bTrackingMode;
			}
			//0x302c8
			if (Data_40004b08.dAltitude < 0)
			{
				if ((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2))
				{
					//0x30304
					bTrackingModeMenu = 3;
				}
			}
			//0x30310
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x3033c
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x30350
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x30364
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x30384
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x30398
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x303ac
					Data_40003360 = "                              ";
					break;
			}
			//303c4
			Data_40003364 = "                              ";
			Data_40003368 = Data_40003dd4_FlashConstellationData.bData_5;
			Data_4000336c = "                              ";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
			//0x30404: Famous Star item
			flash_get_famous_star_data(bData_40002ed2_FamousStarNr, &Data_40003d94_FlashFamousStarData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003d94_FlashFamousStarData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003d94_FlashFamousStarData.fDeclination;
		
			Data_40003360 = Data_40003d94_FlashFamousStarData.bData_0;
			Data_40003364 = "                                        ";
			Data_40003368 = Data_40003d94_FlashFamousStarData.bData_28;
		
			sprintf(Data_40003fe8, "SAO:%d  MEG:%.1f",
				Data_40003d94_FlashFamousStarData.Data_24, Data_40003d94_FlashFamousStarData.fData_52);
		
			Data_4000336c = Data_40003fe8;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//305f4
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x30790
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			//0x30888
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x30a90
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int) fData_40002cd0_ObjectRightAscension,
				(int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60),
				(int) (fData_40002cd0_ObjectRightAscension * 3600) % 60);

			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			//0x30be0
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//30c00
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			else
			{
				//0x30cd0
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			//0x30d9c
			if (abs((int) fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int) (fData_40002d18_ObjectDeclination * 3600) % 60)) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x30e80
			Data_4000337c = Data_4000403c;
				
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002
			//0x30ea8
			flash_get_famous_star_data(bData_40002ed2_FamousStarNr, &Data_40003d94_FlashFamousStarData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003d94_FlashFamousStarData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003d94_FlashFamousStarData.fDeclination;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//31040
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x3113c
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
					
				bTrackingModeMenu = 3;
			}
			//0x31240
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x31448
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			//31460
			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//31490
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;
				//->0x314f8
				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//31548
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;
			}
			//0x315f4
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
			//316dc
			if (dData_40002e08 >= 0)
			{
				//316f4
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{
				//0x317e0
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x318c8
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}
			
			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x31aac
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;
			
			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				bTrackingModeMenu = bTrackingMode;
			}
			
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x31b30
				bTrackingModeMenu = 3;
			}
			//0x31b3c
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x31b68
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x31b7c
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x31b90
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x31bb0
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x31bc4
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x31bd8
					Data_40003360 = "                              ";
					break;
			}
			//0x31bec
			sprintf(Data_40003fbe, "Sao:%d                  ", 
				Data_40003d94_FlashFamousStarData.Data_24);
			
			Data_40003364 = Data_40003fbe;
			Data_40003368 = "                                        ";
			Data_4000336c = Data_40003d94_FlashFamousStarData.bData_28;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012
			//0x31c44
			flash_get_messier_data((unsigned char)wData_40002eb8_MessierNr, 
					&Data_40003e08_FlashMessierData);
		
			sprintf(Data_40003fa9, "Messier:%d   NGC:%d                   ",
				wData_40002eb8_MessierNr, Data_40003e08_FlashMessierData.wData_0);
			
			Data_40003360 = Data_40003fa9;
			Data_40003364 = Data_40003e08_FlashMessierData.bData_32;
			Data_40003368 = Data_40003e08_FlashMessierData.bData_60;
			Data_4000336c = Data_40003e08_FlashMessierData.bData_108;
			Data_40003370 = "                                                   ";
		
			sprintf(Data_40004012, "Size:%.1f Arc Minute                  ",
				Data_40003e08_FlashMessierData.fData_12);
		
			Data_40003374 = Data_40004012;
		
			sprintf(Data_40004027, "Distance:%.1f                         ",
				Data_40003e08_FlashMessierData.dData_16);
		
			Data_40003378 = Data_40004027;
			Data_4000337c = "         K Light-Years";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002
			//0x31ef0
			flash_get_messier_data((unsigned char)wData_40002eb8_MessierNr, 
					&Data_40003e08_FlashMessierData);

			fData_40002cd0_ObjectRightAscension = Data_40003e08_FlashMessierData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003e08_FlashMessierData.fDeclination;
		
			sprintf(Data_40003fa9, "Messier:%d                        ",
				wData_40002eb8_MessierNr);
		
			Data_40003360 = Data_40003fa9;
			Data_40003364 = Data_40003e08_FlashMessierData.bData_32;
			Data_40003368 = Data_40003e08_FlashMessierData.bData_60;
			Data_4000336c = "                                                ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
			//320b0
			if (Data_40004b08.dAltitude >= 0)
			{
				//320cc
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x321c8
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x32320
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x32528
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);

			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			//0x32678
			Data_40003378 = Data_40004027;
				
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//32698
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x32768
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x32834
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x32918
			Data_4000337c = Data_4000403c;
					
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022
			//0x32940
			flash_get_messier_data((unsigned char)wData_40002eb8_MessierNr, 
					&Data_40003e08_FlashMessierData);

			fData_40002cd0_ObjectRightAscension = Data_40003e08_FlashMessierData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003e08_FlashMessierData.fDeclination;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//32adc
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x32bd8
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x32cdc
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x32ee4
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//32f2c
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;
				//->0x2e354
				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//32fe4
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;				
			}
			//0x33088
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//33188
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x33274
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3335c
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x335b8
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;

			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x335f0
				bTrackingModeMenu = bTrackingMode;
			}
			//0x33600
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x3363c
				bTrackingModeMenu = 3;
			}
			//0x33648
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x33674
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x33688
					Data_40003360 = "Find Target,Tracking    ";
					bData_40003432 = 1;
					break;
				
				case 3:
					//0x336a8
					Data_40003360 = "Target Under Horizon    ";
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x336bc
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x336d0
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x336e4
					Data_40003360 = "                              ";
					break;
			}
			//0x336f8
			sprintf(Data_40003fbe, "Messier:%d                        ", 
				wData_40002eb8_MessierNr);
			
			Data_40003364 = Data_40003fbe;
			Data_40003368 = Data_40003e08_FlashMessierData.bData_32;
			Data_4000336c = Data_40003e08_FlashMessierData.bData_60;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003
			//0x33750
			flash_get_ngc_data(wData_40002eba_NGCNr, &Data_40003ee0_FlashNGCData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ee0_FlashNGCData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ee0_FlashNGCData.fDeclination;
		
			sprintf(Data_40003fa9, "NGC:%d                          ", 
				wData_40002eba_NGCNr);
		
			Data_40003360 = Data_40003fa9;
			Data_40003364 = Data_40003ee0_FlashNGCData.bData_0;
		
			if (Data_40003ee0_FlashNGCData.fData_16 != 0)
			{
				//337c4
				sprintf(Data_40003fd3, "MEG:%.1f                          ", 
					Data_40003ee0_FlashNGCData.fData_16);
				Data_40003368 = Data_40003fd3;
			}
			else
			{
				//0x337fc
				Data_40003368 = "                                          ";
			}
			//0x33808
			Data_4000336c = Data_40003ee0_FlashNGCData.bData_20;
			
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
			//3389c
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//33974
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x33b60
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x33c58
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x33e60
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//33fd0
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x340a0
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x3416c
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x34250
			Data_4000337c = Data_4000403c;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013
			//0x34278
			flash_get_ngc_data(wData_40002eba_NGCNr, &Data_40003ee0_FlashNGCData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ee0_FlashNGCData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ee0_FlashNGCData.fDeclination;

			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//3440c
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x34508
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x3460c
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x34814
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;

			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//3485c
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;

				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//34914
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;				
			}
			//0x349b8
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//34ab8
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x34ba4
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x34c8c
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x34edc
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;

			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x34f14
				bTrackingModeMenu = bTrackingMode;
			}
			//0x34f24
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x34f60
				bTrackingModeMenu = 3;
			}
			//0x34f6c
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x34f98
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x34fac
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x34fc0
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x34fe0
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x34ff4
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x35008
					Data_40003360 = "                     ";
					break;
			}
			//0x336f8
			sprintf(Data_40003fbe, "NGC:%d                          ", 
				wData_40002eba_NGCNr);
			
			Data_40003364 = Data_40003fbe;
			Data_40003368 = Data_40003ee0_FlashNGCData.bData_0;
			
			if (Data_40003ee0_FlashNGCData.fData_16 != 0)
			{
				//35060
				sprintf(Data_40003fe8, "MEG:%.1f          ", 
					Data_40003ee0_FlashNGCData.fData_16);
				Data_4000336c = Data_40003fe8;
			}
			else
			{
				//0x35098
				Data_4000336c = "                     ";
			}
			//0x350a4			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c			
			break;
		
		case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004
			//0x350c0
			flash_get_ic_data(wData_40002ebc_ICNr, &Data_40003ec0_FlashICData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ec0_FlashICData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ec0_FlashICData.fDeclination;
		
			sprintf(Data_40003fa9, "IC:%d                          ", 
				wData_40002ebc_ICNr);
		
			Data_40003360 = Data_40003fa9;
			Data_40003364 = Data_40003ec0_FlashICData.bData_0;
		
			if (Data_40003ec0_FlashICData.fData_16 != 0)
			{
				//35134
				sprintf(Data_40003fd3, "MEG:%.1f                          ", 
					Data_40003ec0_FlashICData.fData_16);
				Data_40003368 = Data_40003fd3;
			}
			else
			{
				//0x3516c
				Data_40003368 = "                                          ";
			}
			//0x35178
			Data_4000336c = Data_40003ec0_FlashICData.bData_20;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
			//3520c
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//352e4
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x3549c
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x35594
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x3579c
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//3590c
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x359dc
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x35aa8
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x35b8c
			Data_4000337c = Data_4000403c;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014
			//0x35bb4
			flash_get_ic_data(wData_40002ebc_ICNr, &Data_40003ec0_FlashICData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ec0_FlashICData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ec0_FlashICData.fDeclination;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//35d4c
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x35e48
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x35f4c
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x36154
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;

			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//3619c
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;

				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//36254
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;				
			}
			//0x362fc
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//363fc
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x364e8
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x365d0
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x3682c
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;

			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x36864
				bTrackingModeMenu = bTrackingMode;
			}
			//0x36874
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x368b0
				bTrackingModeMenu = 3;
			}
			//0x368bc
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x368e8
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x368fc
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x36910
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x36930
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x36944
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x36958
					Data_40003360 = "                     ";
					break;
			}
			//0x3696c
			sprintf(Data_40003fbe, "IC:%d                          ", 
				wData_40002ebc_ICNr);
			
			Data_40003364 = Data_40003fbe;
			Data_40003368 = Data_40003ec0_FlashICData.bData_0;
			
			if (Data_40003ec0_FlashICData.fData_16 != 0)
			{
				//369b0
				sprintf(Data_40003fe8, "MEG:%.1f          ", 
					Data_40003ec0_FlashICData.fData_16);
				Data_4000336c = Data_40003fe8;
			}
			else
			{
				//0x369e8
				Data_4000336c = "                     ";
			}
			//0x350a4			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c					
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005
			//0x36a10
			flash_get_sh2_data(wData_40002ebe_ShNr, &Data_40003350_FlashSh2Data);
		
			fData_40002cd0_ObjectRightAscension = Data_40003350_FlashSh2Data.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003350_FlashSh2Data.fDeclination;
		
			sprintf(Data_40003fa9, "Sh2:%d                          ",
				wData_40002ebe_ShNr);
		
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                                        ";
			Data_40003368 = "                                        ";
			Data_4000336c = "                                        ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//36be8
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x36d88
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x36e80
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x37088
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//371f8
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x372c8
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x37394
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x37478
			Data_4000337c = Data_4000403c;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c		
			break;
		
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015
			//0x374a0
			flash_get_sh2_data(wData_40002ebe_ShNr, &Data_40003350_FlashSh2Data);
		
			fData_40002cd0_ObjectRightAscension = Data_40003350_FlashSh2Data.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003350_FlashSh2Data.fDeclination;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//37634
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x37730
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x37834
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x37a3c
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;

			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//37a84
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;

				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}

				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;				
			}
			//0x37be4
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//37ce4
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x37dd0
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x37eb8
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x38108
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;

			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x38140
				bTrackingModeMenu = bTrackingMode;
			}
			//0x38150
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x3818c
				bTrackingModeMenu = 3;
			}
			//0x38198
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x381c4
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x381d8
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x381ec
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x3820c
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x38220
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x38234
					Data_40003360 = "                              ";
					break;
			}
			//0x38248
			sprintf(Data_40003fd3, "Sh2:%d                          ", 
				wData_40002ebe_ShNr);
			
			Data_40003368 = Data_40003fd3;
			Data_40003364 = "                                        ";
			Data_4000336c = "                                        ";

			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c					
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006
			//0x382a0
			flash_get_bright_star_data((unsigned char)wData_40002ec0_BrightStarNr, &Data_40003ea0_FlashBrightStarData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ea0_FlashBrightStarData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ea0_FlashBrightStarData.fDeclination;
		
			sprintf(Data_40003fa9, "Bright:%d                          ",
				wData_40002ec0_BrightStarNr);
		
			Data_40003360 = Data_40003fa9;
			Data_40003364 = Data_40003ea0_FlashBrightStarData.bData_0;
		
			if (Data_40003ea0_FlashBrightStarData.fData_28 != 0)
			{
				//38318
				sprintf(Data_40003fd3, "MEG:%.1f                          ",
					Data_40003ea0_FlashBrightStarData.fData_28);
				Data_40003368 = Data_40003fd3;
			}
			else
			{
				//0x38350
				Data_40003368 = "                                          ";
			}
			//0x3835c
			Data_4000336c = "                                          ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//384cc
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x38668
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x38760
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x38968
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//38ad8
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x38ba8
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x38c74
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x38d58
			Data_4000337c = Data_4000403c;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c		
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016
			//0x38d80
			flash_get_bright_star_data((unsigned char)wData_40002ec0_BrightStarNr, &Data_40003ea0_FlashBrightStarData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ea0_FlashBrightStarData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ea0_FlashBrightStarData.fDeclination;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//38f18
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x39014
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x39118
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x39320
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;

			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//39368
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;

				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//39420
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;				
			}
			//0x394c8
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//395c8
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x396b4
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3979c
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x399f8
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;

			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x39a30
				bTrackingModeMenu = bTrackingMode;
			}
			//0x39a40
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x39a7c
				bTrackingModeMenu = 3;
			}
			//0x39a88
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x39ab4
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x39ac8
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x39adc
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x39afc
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x39b10
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x39b24
					Data_40003360 = "                              ";
					break;
			}
			//0x39b38
			sprintf(Data_40003fbe, "Bright:%d                          ", 
				wData_40002ec0_BrightStarNr);
			
			Data_40003364 = Data_40003fbe;
			Data_40003368 = Data_40003ea0_FlashBrightStarData.bData_0;
			Data_4000336c = "                              ";

			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c					
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x39b90: SAO item
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);
		
			fData_40002cd0_ObjectRightAscension = Data_40003358_SAORecord.ra;
			fData_40002d18_ObjectDeclination = Data_40003358_SAORecord.dec;
		
			sprintf(Data_40003fa9, "SAO:%d                          ",
				Data_40002ec4_SAONr);
		
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                                        ";
			Data_40003368 = "                                        ";
			Data_4000336c = "                                        ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//39d68
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x39f00
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x39ff8
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//0x3a200
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				Data_40004027[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				Data_40004027[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				Data_40004027[11] = ' ';
			}
			
			Data_40003378 = Data_40004027;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//3a370
				sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x3a440
				sprintf(Data_4000403c, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x3a50c
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x3a5f0
			Data_4000337c = Data_4000403c;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c		
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017
			//0x3a618
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);
		
			fData_40002cd0_ObjectRightAscension = Data_40003358_SAORecord.ra;
			fData_40002d18_ObjectDeclination = Data_40003358_SAORecord.dec;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);

			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//3a7ac
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//3a8a8
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//3a9ac
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			//3a9d0
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			//3a9f4
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			//3aa60
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			//3aaa4
			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				Data_40004012[5] = ' ';
			}
			//3aadc
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			//3ab5c
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//3abb4
			Data_40003370 = Data_40003ffd;
			Data_40003374 = Data_40004012;
			
			dData_40002dd0 = dData_40002dc0_Azimuth;
			dData_40002e08 = dData_40002df8;
			
			if (bData_40002e7a_MountType == 1)
			{
				//3abfc
				dData_40002c90 = dData_40002d98;					
				dData_40002c88 = get_local_sidereal_time(1, 0, Data_40004128.geographicLongitude) - dData_40002d78;

				while (dData_40002c88 >= 24)
				{
					dData_40002c88 -= 24;
				}
				while (dData_40002c88 < 0)
				{
					dData_40002c88 += 24;
				}
				//3acb4
				Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
				Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
				
				Data_40004b50.dRA = dData_40002c88;
				Data_40004b50.dDec = dData_40002c90;
				
				convert_equatorial_to_horizontal(Data_40004ad8, Data_40004b50, 
					Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b70);

				dData_40002dd0 = Data_40004b70.dAzimuth;
				dData_40002e08 = Data_40004b70.dAltitude;
			}
			//0x3ad58
			sprintf(Data_40004027, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));

			if (dData_40002e08 >= 0)
			{
				//3ae58
				sprintf(Data_4000403c, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{
				//0x3af44
				sprintf(Data_4000403c, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3b02c
			if ((int)dData_40002dd0 < 100)
			{
				Data_40004027[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				Data_40004027[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				Data_40004027[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				Data_40004027[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				Data_4000403c[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				Data_4000403c[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				Data_4000403c[11] = ' ';
			}
			//0x3b27c
			Data_40003378 = Data_40004027;
			Data_4000337c = Data_4000403c;
			
			if ((bTrackingMode == 1) || (bTrackingMode == 2))
			{
				//0x3b2b4
				bTrackingModeMenu = bTrackingMode;
			}
			//0x3b2c4
			if ((Data_40004b08.dAltitude < 0) &&
				((bTrackingModeMenu == 1) || (bTrackingModeMenu == 2)))
			{
				//0x3b300
				bTrackingModeMenu = 3;
			}
			//0x3b30c
			switch (bTrackingModeMenu)
			{
				case 1:
					//0x3b338
					Data_40003360 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x3b34c
					Data_40003360 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x3b360
					Data_40003360 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x3b380
					Data_40003360 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x3b394
					Data_40003360 = "Cancel Operation          ";
					break;
				
				default:
					//0x3b3a8
					Data_40003360 = "                              ";
					break;
			}
			//0x3b3bc
			Data_40003364 = "                              ";
			
			sprintf(Data_40003fd3, "SAO:%d                          ",
				Data_40002ec4_SAONr);
			
			Data_40003368 = Data_40003fd3;
			Data_4000336c = "                              ";

			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break; //case 23017:
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x3b414
			Data_40003360 = "F1";
			Data_40003364 = "F2";
			Data_40003368 = "F3";
			Data_4000336c = "F4";
			Data_40003370 = "F5";
			Data_40003374 = "F6";
			Data_40003378 = "F7";
			Data_4000337c = "F8";
			Data_40003380 = "F9";
			Data_40003384 = "Select F? For Target ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x3b4ac
			sprintf(Data_40003fa9, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                    ";
			Data_40003368 = "  Please Save Current";
			Data_4000336c = "Target & Input Target";
			Data_40003370 = "                    ";
			Data_40003374 = strCustomerObjectNameInput;
			Data_40003378 = strCustomerObjectRaAziInputForStoring;
			Data_4000337c = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x3b540
			sprintf(Data_40003fa9, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                    ";
			Data_40003368 = "  Please Save Current";
			Data_4000336c = "Target & Input Target";
			Data_40003370 = "                    ";
			Data_40003374 = strCustomerObjectNameInput;
			Data_40003378 = strCustomerObjectRaAziInputForStoring;
			Data_4000337c = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x3b5d4
			sprintf(Data_40003fa9, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                    ";
			Data_40003368 = "  Please Save Current";
			Data_4000336c = "Target & Input Target";
			Data_40003370 = "                    ";
			Data_40003374 = strCustomerObjectNameInput;
			Data_40003378 = strCustomerObjectRaAziInputForStoring;
			Data_4000337c = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;

		case MENU_CONTEXT_RA_INPUT: //29001: // "Object Rise/Set" -> "Input Ra Dec:"
			//0x3b668
			Data_40003360 = strInputRaDec; // "Input Ra Dec:"?
			Data_40003364 = "";
			Data_40003368 = strCustomerObjectRaAziInputForStoring; // "R.a: 19h52m12.0s"?
			Data_4000336c = "";
			Data_40003370 = strCustomerObjectDecAltInputForStoring; // "Dec:+90 00 00.0 "?
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002
			//0x3b7d0
			Data_40003360 = strInputRaDec;
			Data_40003364 = "";
			Data_40003368 = strCustomerObjectRaAziInputForStoring;
			Data_4000336c = "";
			Data_40003370 = strCustomerObjectDecAltInputForStoring;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
				
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//0x3b850
			Data_40003360 = "F1";
			Data_40003364 = "F2";
			Data_40003368 = "F3";
			Data_4000336c = "F4";
			Data_40003370 = "F5";
			Data_40003374 = "F6";
			Data_40003378 = "F7";
			Data_4000337c = "F8";
			Data_40003380 = "F9";
			Data_40003384 = "Select F? For Target ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x3b8e8
			sprintf(Data_40003fa9, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                    ";
			Data_40003368 = "  Please Save Current";
			Data_4000336c = "Target & Input Target";
			Data_40003370 = "                    ";
			Data_40003374 = strCustomerObjectNameInput;
			Data_40003378 = strCustomerObjectRaAziInputForStoring;
			Data_4000337c = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x3b97c
			sprintf(Data_40003fa9, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                    ";
			Data_40003368 = "  Please Save Current";
			Data_4000336c = "Target & Input Target";
			Data_40003370 = "                    ";
			Data_40003374 = strCustomerObjectNameInput;
			Data_40003378 = strCustomerObjectRaAziInputForStoring;
			Data_4000337c = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x3ba10
			sprintf(Data_40003fa9, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			Data_40003360 = Data_40003fa9;
			Data_40003364 = "                    ";
			Data_40003368 = "  Please Save Current";
			Data_4000336c = "Target & Input Target";
			Data_40003370 = "                    ";
			Data_40003374 = strCustomerObjectNameInput;
			Data_40003378 = strCustomerObjectRaAziInputForStoring;
			Data_4000337c = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJ_RISE_SET_TIMES: //31001:
			//0x3baa4
			get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
				&fData_40002cd0_ObjectRightAscension, &fData_40002d18_ObjectDeclination);
		
			Data_40003360 = Data_4000314c_SolarSystemObjectName;
		
			dObjectRiseTime = get_object_visibility_time(1, 
				fData_40002cd0_ObjectRightAscension, 
				fData_40002d18_ObjectDeclination, 
				Data_40004128.geographicLongitude, 
				Data_40004128.geographicLatitude, 
				(unsigned char)Data_40004128.timeZone);

			dObjectTransitTime = get_object_visibility_time(2, 
				fData_40002cd0_ObjectRightAscension, 
				fData_40002d18_ObjectDeclination, 
				Data_40004128.geographicLongitude, 
				Data_40004128.geographicLatitude, 
				(unsigned char)Data_40004128.timeZone);

			dObjectSetTime = get_object_visibility_time(3, 
				fData_40002cd0_ObjectRightAscension, 
				fData_40002d18_ObjectDeclination, 
				Data_40004128.geographicLongitude, 
				Data_40004128.geographicLatitude, 
				(unsigned char)Data_40004128.timeZone);
				
			sprintf(Data_40003fd3, "RiseTime:   %02dh%02dm",
				(int)dObjectRiseTime,
				(int)((dObjectRiseTime - (int)dObjectRiseTime) * 60));
			Data_40003368 = Data_40003fd3;

			sprintf(Data_40003ffd, "TransitTime:%02dh%02dm",
				(int)dObjectTransitTime,
				(int)((dObjectTransitTime - (int)dObjectTransitTime) * 60));
			Data_40003370 = Data_40003ffd;
				
			sprintf(Data_40004027, "SetTime:    %02dh%02dm",
				(int)dObjectSetTime,
				(int)((dObjectSetTime - (int)dObjectSetTime) * 60));
			Data_40003378 = Data_40004027;
				
			Data_40003364 = "                    ";
			Data_4000336c = "                    ";
			Data_40003374 = "                    ";
			Data_4000337c = "                    ";
				
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_RISE_SET_TIMES: //32001
			//0x3be30
			sprintf(Data_40003fa9, "RiseTime:   %02dh%02dm", 
				(int)dObjectRiseTime,
				(int)((dObjectRiseTime - (int)dObjectRiseTime) * 60));		
			Data_40003360 = Data_40003fa9;
		
			sprintf(Data_40003fbe, "TransitTime:%02dh%02dm",
				(int)dObjectTransitTime,
				(int)((dObjectTransitTime - (int)dObjectTransitTime) * 60));
			Data_40003368 = Data_40003fbe;
				
			sprintf(Data_40003fd3, "SetTime:    %02dh%02dm",
				(int)dObjectSetTime,
				(int)((dObjectSetTime - (int)dObjectSetTime) * 60));
			Data_40003370 = Data_40003fd3;
				
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
				
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case 33001: // "Curr. Lunar Phase" -> "2019-11"
			//0x3c088
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_TIMER_COUNTING: //34002:
			//0x3c0a8
			sprintf(strEngTimeRemain00000s, "%5lds", Data_40003214_UserTimerSeconds);
		
			Data_40003360 = strEngCountingDown; // "Counting down:"?
			Data_40003364 = "";
			Data_40003368 = strEngTimeRemain; // "Time remain:"
			Data_4000336c = "";
			Data_40003370 = strEngTimeRemain00000s; // "00000s"
			Data_40003374 = "";
			Data_4000337c = "";
			Data_40003378 = strEngStopBack; // "       Stop      Back"?
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
				
		case MENU_CONTEXT_TIMER_SET: //34001:
			//0x3c13c
			Data_40003360 = strEngSetTimer; // "Set timer:"?
			Data_40003364 = "";
			Data_40003368 = strEng00000s; // "00000s"?
			Data_4000336c = "";
			Data_40003370 = Data_400029b3;
			Data_40003374 = "";
			Data_40003378 = strEngStartBack; // "      Start      Back"?
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_ALARM_INPUT: //35001:
			//0x3c1bc: Alarm start
			Data_40003360 = strEngInputTime;
			Data_40003364 = "";
			Data_40003368 = strEngAlarm21h34m23s;
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_4000337c = "";
			Data_40003378 = strEngAlarmOnBack;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case 35002:
			//0x3c23c: Alarm stop
			Data_40003360 = "";
			Data_40003364 = strEngCloseAlarm;
			Data_40003368 = "";
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_4000337c = "";
			Data_40003378 = strEngAlarmCloseBack;
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case 0x57E4B: //360011
			//0x3c2bc
			Data_40003360 = strEngTelescopeOneMX51;
			Data_40003364 = "";
			Data_40003368 = Data_4000239a; //"Scope:3'.3'"
			Data_4000336c = "";
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021
			//0x3c33c		
			Data_40003360 = strEyepieceMagnCaption; //->"Eyep. focal length:"?
			Data_40003364 = "";
			Data_40003368 = strEyepieceFovMfInput;
			Data_4000336c = "";
			Data_40003370 = strEyepieceFovSfInput;
			Data_40003374 = "";
			Data_40003378 = strEyepieceMagnification;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022
			//0x3c41c
			Data_40003360 = strEyepieceMagnCaption;
			Data_40003364 = "";
			Data_40003368 = strEyepieceFovMfInput;
			Data_4000336c = "";
			Data_40003370 = strEyepieceFovSfInput;
			Data_40003374 = "";
			Data_40003378 = strEyepieceMagnification;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021
			//0x3c49c
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022
			//0x3c4a4
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023
			//0x3c4a8
			Data_40003360 = strEyepieceFovCaption; // "Eyep. focal length:"
			Data_40003364 = "";
			Data_40003368 = strEyepieceFovMfInput; // "MF:1893mm"
			Data_4000336c = "";
			Data_40003370 = strEyepieceFovSfInput; // "SF:43mm"
			Data_40003374 = "";
			Data_40003378 = strEyepieceFovInput; // "E-FOV:001�00'"
			Data_4000337c = strEyepieceFOV; // "         FOV:0.02272�"
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case 0x57E57: //360023
			//0x3c524
			sprintf(Data_4000248c, "MultiplyM:%d", fEyepieceMagnification);
		
			Data_40003360 = strEyepieceMagnCaption;
			Data_40003364 = "";
			Data_40003368 = strEyepieceFovMfInput;
			Data_4000336c = "";
			Data_40003370 = strEyepieceFovSfInput;
			Data_40003374 = "";
			Data_40003378 = strEyepieceMagnification;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL: //380011:
			//0x3c5cc
			Data_40003360 = strEngBackgroundLight;
			Data_40003364 = "";
			Data_40003368 = strEngPressUpDownKey;
			Data_4000336c = "";
			Data_40003370 = Data_40002aee;
			Data_40003374 = "";
			Data_40003378 = Data_40002aef;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
				
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//0x3c64c
			Data_40003360 = "Date and Time Set: ";
			Data_40003364 = "";
			Data_40003368 = Data_400037ec;
			Data_4000336c = "           YYYY-MM-DD";
			Data_40003370 = Data_40003150;
			Data_40003374 = "         HH:MM:SS";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_ON: //42001:
			//0x3c6cc
			Data_40003360 = Data_40002b70; //"daylight saving"
			Data_40003364 = "";
			Data_40003368 = Data_40002b80; //"status:on"
			Data_4000336c = "";
			Data_40003370 = Data_40002b8a;
		
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40003374 = "hit direction key!";
			}
			else
			{
				Data_40003374 = "Restart & Change!";
			}
			Data_40003378 = Data_40002b8b;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_OFF: //42002:
			//3c76c
			Data_40003360 = Data_40002ba5; //"Daylight saving"
			Data_40003364 = "";
			Data_40003368 = Data_40002bb5; //"status:off"
			Data_4000336c = "";
			Data_40003370 = Data_40002bc0;
		
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40003374 = "hit direction key!";
			}
			else
			{
				Data_40003374 = "Restart & Change!";
			}
			Data_40003378 = Data_40002bc1;
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x3c8f4: Country & City
			flash_get_site_data((unsigned short)(wData_40003250 + wData_40003252), &Data_40003f1c_FlashSiteData);

			if (Data_40003f1c_FlashSiteData.fLongitude >= 0)
			{
				//3c92c
				sprintf(Data_40003ffd, "     Lon:E%03d %02d          ",
					abs((int)Data_40003f1c_FlashSiteData.fLongitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLongitude - (int)Data_40003f1c_FlashSiteData.fLongitude) * 60)));
			}
			else
			{
				//0x3c9bc
				sprintf(Data_40003ffd, "     Lon:W%03d %02d         ",
					abs((int)Data_40003f1c_FlashSiteData.fLongitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLongitude - (int)Data_40003f1c_FlashSiteData.fLongitude) * 60)));
			}
			//0x3ca48
			if (abs((int)Data_40003f1c_FlashSiteData.fLongitude) < 100)
			{
				Data_40003ffd[10] = ' ';
			}
			if (abs((int)Data_40003f1c_FlashSiteData.fLongitude) < 10)
			{
				Data_40003ffd[11] = ' ';
			}
			if (abs((int)((Data_40003f1c_FlashSiteData.fLongitude - (int)Data_40003f1c_FlashSiteData.fLongitude) * 60)) < 10)
			{
				Data_40003ffd[14] = ' ';
			}
			//0x3cb14
			if (Data_40003f1c_FlashSiteData.fLatitude >= 0)
			{
				//3cb28
				sprintf(Data_40004027, "     Lat:N %02d %02d          ",
					abs((int)Data_40003f1c_FlashSiteData.fLatitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLatitude - (int)Data_40003f1c_FlashSiteData.fLatitude) * 60)));
			}
			else
			{
				//0x3cbb8
				sprintf(Data_40004027, "     Lat:S %02d %02d         ",
					abs((int)Data_40003f1c_FlashSiteData.fLatitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLatitude - (int)Data_40003f1c_FlashSiteData.fLatitude) * 60)));
			}
			//0x3cc44
			if (abs((int)Data_40003f1c_FlashSiteData.fLatitude) < 10)
			{
				Data_40004027[11] = ' ';
			}
			if (abs((int)((Data_40003f1c_FlashSiteData.fLatitude - (int)Data_40003f1c_FlashSiteData.fLatitude) * 60)) < 10)
			{
				Data_40004027[14] = ' ';
			}
			//0x3cd74
			if (Data_40003f1c_FlashSiteData.Zone > 0)
			{
				//3cd84
				sprintf(Data_4000403c, "    Zone:E%d   ",
					abs(Data_40003f1c_FlashSiteData.Zone));
			}
			else if (Data_40003f1c_FlashSiteData.Zone < 0)
			{
				//0x3cdb4
				sprintf(Data_4000403c, "    Zone:W%d    ",
					abs(Data_40003f1c_FlashSiteData.Zone));
			}
			else
			{
				//0x3cdf4
				sprintf(Data_4000403c, "    Zone:%d    ",
					abs(Data_40003f1c_FlashSiteData.Zone));
			}
			//0x3ce20
			Data_40003360 = Data_40003f1c_FlashSiteData.cCountry;
			Data_40003364 = Data_40003f1c_FlashSiteData.cCity;
			Data_40003368 = Data_40003ffd;
			Data_4000336c = Data_40004027;
			Data_40003370 = Data_4000403c;
			Data_40003374 = "                     ";
			Data_40003378 = "up&down key: country!";
			Data_4000337c = "left&right key: city!";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x3ce9c: "Custom Site"
			Data_40003360 = "Please Input Data: ";
			//Data_40003364 = ""; //?????
			Data_40003368 = strCustomSiteName; //" Name:"
			Data_4000336c = strCustomSiteLongitude; //"  Lon:"
			Data_40003370 = strCustomSiteLatitude; //"  Lat:"
			Data_40003374 = strCustomSiteTimezone; //" Zone:"
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_SKY_TARGET: //45001
			//0x3cf10
			Data_40003360 = "Object Mode:";
			Data_40003364 = "";
			Data_40003368 = strSkyTarget;
			Data_4000336c = "";
			Data_40003370 = strLandTarget;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_LAND_TARGET: //45002
			//0x3cf90
			Data_40003360 = "Object Mode:";
			Data_40003364 = "";
			Data_40003368 = strSkyTarget;
			Data_4000336c = "";
			Data_40003370 = strLandTarget;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_MOUNT_AZ: //46001:
			//0x3d010
			Data_40003360 = "Telescope Mount:";
			Data_40003364 = "";
			Data_40003368 = Data_400028a5;
			Data_4000336c = "";
			Data_40003370 = Data_400028b3;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_MOUNT_EQU: //46002:
			//0x3d154
			Data_40003360 = "Telescope Mount:";
			Data_40003364 = "";
			Data_40003368 = Data_400028a5;
			Data_4000336c = "";
			Data_40003370 = Data_400028b3;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011: // "Telescope Mount" -> "Please setup OTA zero"
			//0x3d1d4
			Data_40003360 = strEngPleaseSetupOtaZero; // "Please setup OTA zero"
			Data_40003368 = Data_400028d7; // "Azi:000�"
			Data_40003370 = Data_400028e1; // "Alt: 00�"
			Data_4000336c = "        Range:0-360";
			Data_40003374 = "        Range:0-90";
			Data_40003378 = "";
			Data_4000337c = "";
		
			if (bData_400032a4_OTAZeroDataErrorCount > 0)
			{
				bData_400032a4_OTAZeroDataErrorCount--;
				Data_40003374 = "                                ";
				Data_40003378 = Data_400028eb;
			}
			else
			{
				Data_40003374 = "                                        ";
				Data_40003378 = "                                      ";
			}

			Data_40003364	= "                              ";
			Data_4000336c = "          Range:0-360";
			Data_40003374 = "          Range:0-90";
			
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP_RESTART: //47041:
			//0x3d2c4
			Data_40003360 = strEngPleaseSetupOtaZero; // "Please setup OTA zero"
			Data_40003368 = Data_400028d7;
			Data_40003370 = Data_400028e1;
			Data_40003378 = Data_40002901;
			Data_40003364 = "";
			Data_4000336c = "";
			Data_40003374 = "                                                       ";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_ENGLISH: //49001
			//0x3d344
			Data_40003360 = strEngEnglish;
			Data_40003364 = strEngGerman;
			Data_40003368 = strEngFrench;
			Data_4000336c = strEngItalian;
			Data_40003370 = strEngSpanish;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_GERMAN: //49002
			//0x3d3c0
			Data_40003360 = strEngEnglish;
			Data_40003364 = strEngGerman;
			Data_40003368 = strEngFrench;
			Data_4000336c = strEngItalian;
			Data_40003370 = strEngSpanish;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_FRENCH: //49003
			//0x3d440
			Data_40003360 = strEngEnglish;
			Data_40003364 = strEngGerman;
			Data_40003368 = strEngFrench;
			Data_4000336c = strEngItalian;
			Data_40003370 = strEngSpanish;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_ITALIAN: //49004
			//0x3d594
			Data_40003360 = strEngEnglish;
			Data_40003364 = strEngGerman;
			Data_40003368 = strEngFrench;
			Data_4000336c = strEngItalian;
			Data_40003370 = strEngSpanish;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 4;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_SPANISH: //49005
			//0x3d614
			Data_40003360 = strEngEnglish;
			Data_40003364 = strEngGerman;
			Data_40003368 = strEngFrench;
			Data_4000336c = strEngItalian;
			Data_40003370 = strEngSpanish;
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001
			//0x3d694
			Data_40003360 = "Input Treaking Speed:";
			Data_40003364 = "";
			Data_40003368 = "";
			Data_4000336c = strTrackingRateCustDisplay;
			Data_40003370 = "";
			Data_40003374 = "";
			Data_40003378 = "";
			Data_4000337c = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		default:
			//0x3d714			
			break;
	}
}

