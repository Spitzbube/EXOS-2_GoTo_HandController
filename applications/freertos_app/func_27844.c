

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
			g_pcstrMenuLine2 = strThereIsNoTele;
			g_pcstrMenuLine4 = strScopeToConnectThis;
			g_pcstrMenuLine6 = strControlTerminal;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case 0x65: //101
			//0x28090
			g_pcstrMenuLine1 = "F1";
			g_pcstrMenuLine2 = "F2";
			g_pcstrMenuLine3 = "F3";
			g_pcstrMenuLine4 = "F4";
			g_pcstrMenuLine5 = "F5";
			g_pcstrMenuLine6 = "F6";
			g_pcstrMenuLine7 = "F7";
			g_pcstrMenuLine8 = "F8";
			g_pcstrMenuLine9 = "F9";

			switch (bData_40002e79_SkyLandTargetSeletion)
			{
				case 0:
					//0x2811c
					g_pcstrMenuLine10 = "Select Sky Target No ";
					break;
				
				case 1:
					//0x28130
					g_pcstrMenuLine10 = "Select Land Target No";
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
				g_pcstrMenuLine1 = "                      ";
				g_pcstrMenuLine2 = "Sorry                 ";
				g_pcstrMenuLine3 = "                      ";
				
				if (bData_40002e79_SkyLandTargetSeletion == 0)
				{
					//28224
					sprintf(g_MenuStringBuffer4, "Your Sky F%d is Blank  ", bData_4000319a_SkyLandTargetId);
				}
				//28238
				if (bData_40002e79_SkyLandTargetSeletion == 1)
				{
					//28248
					sprintf(g_MenuStringBuffer4, "Your Land F%d is Blank  ", bData_4000319a_SkyLandTargetId);
				}
				//2825c
				g_pcstrMenuLine4 = g_MenuStringBuffer4;
				g_pcstrMenuLine5 = "                      ";
				g_pcstrMenuLine6 = "Please Input Data    ";
				g_pcstrMenuLine7 = "                      ";
				g_pcstrMenuLine8 = "                      ";
				//->29978
			}
			else
			{
				//283fc
				if (bData_40002e79_SkyLandTargetSeletion == 0)
				{					
					//2840c
					sprintf(g_MenuStringBuffer1, "My Sky Target %d   ", bData_4000319a_SkyLandTargetId);
					
					g_pcstrMenuLine1 = g_MenuStringBuffer1;
					g_pcstrMenuLine2 = "                      ";
					g_pcstrMenuLine3 = Data_40003f50.bData_1;
					g_pcstrMenuLine4 = "                      ";
					
					Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
					Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
					Data_40004ae8.dRA = Data_40003f50.fData_12;
					Data_40004ae8.dDec = Data_40003f50.fData_16;
					fData_40002cd0_ObjectRightAscension = Data_40003f50.fData_12;
					fData_40002d18_ObjectDeclination = Data_40003f50.fData_16;
					
					convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
						Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
					//284f8
					sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
						(int)(Data_40004b08.dAzimuth), 
						(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
						(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
						
					if (Data_40004b08.dAltitude >= 0)
					{
						//285d0
						sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude), 
							abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					else
					{
						//286cc
						sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude), 
							abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					//2885c
					if ((int)(Data_40004b08.dAzimuth) < 100)
					{
						g_MenuStringBuffer5[11] = ' ';
					}
					
					if ((int)(Data_40004b08.dAzimuth) < 10)
					{
						g_MenuStringBuffer5[12] = ' ';
					}
					//288a4
					if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
					{
						g_MenuStringBuffer5[15] = ' ';
					}
					//28910
					if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
					{
						g_MenuStringBuffer5[18] = ' ';
					}
					//28954
					if (abs((int)Data_40004b08.dAltitude) < 10)
					{
						g_MenuStringBuffer6[5] = ' ';
					}
					//2898c
					if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
					{
						g_MenuStringBuffer6[8] = ' ';
					}
					//28a0c
					if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
					{
						g_MenuStringBuffer6[11] = ' ';
					}
					//28a64
					g_pcstrMenuLine5 = g_MenuStringBuffer5;
					g_pcstrMenuLine6 = g_MenuStringBuffer6;
					
					sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
						(int)fData_40002cd0_ObjectRightAscension,
						(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
						(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
						
					if ((int)fData_40002cd0_ObjectRightAscension < 10)
					{
						g_MenuStringBuffer7[5] = ' ';
					}
					//28b2c
					if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
					{
						g_MenuStringBuffer7[8] = ' ';
					}
					//28b7c
					if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
					{
						g_MenuStringBuffer7[11] = ' ';
					}
					//28bb4
					g_pcstrMenuLine7 = g_MenuStringBuffer7;
					
					if (fData_40002d18_ObjectDeclination >= 0)
					{
						//28bd4
						sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
							abs((int)fData_40002d18_ObjectDeclination),
							abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
							abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
					}
					else
					{
						//28cf8
						sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
							abs((int)fData_40002d18_ObjectDeclination),
							abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
							abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
					}
					//28dc4
					if (abs((int)fData_40002d18_ObjectDeclination) < 10)
					{
						g_MenuStringBuffer8[5] = ' ';
					}
					//28df8
					if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
					{
						g_MenuStringBuffer8[8] = ' ';
					}
					//28e5c
					if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
					{
						g_MenuStringBuffer8[11] = ' ';
					}
					//28ea8
					g_pcstrMenuLine8 = g_MenuStringBuffer8;
					//->29978
				}
				else
				{
					//28eb8
					sprintf(g_MenuStringBuffer1, "My Land Target %d", bData_4000319a_SkyLandTargetId);
					
					g_pcstrMenuLine1 = g_MenuStringBuffer1;
					g_pcstrMenuLine2 = "                      ";
					g_pcstrMenuLine3 = Data_40003f64.bData_1;
					g_pcstrMenuLine4 = "                      ";

					Data_40004b08.dAzimuth = Data_40003f64.fData_12;
					Data_40004b08.dAltitude = Data_40003f64.fData_16;
										
					sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
						(int)Data_40004b08.dAzimuth,
						(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
						(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
					//28fe8
					if (Data_40004b08.dAltitude >= 0)
					{
						//29004
						sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude),
							abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)),
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					else
					{
						//2915c
						sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
							abs((int)Data_40004b08.dAltitude),
							abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)),
							abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					}
					//29254
					if ((int)Data_40004b08.dAzimuth < 100)
					{
						g_MenuStringBuffer5[11] = ' ';
					}
					//29278
					if ((int)Data_40004b08.dAzimuth < 10)
					{
						g_MenuStringBuffer5[12] = ' ';
					}
					//2929c
					if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
					{
						g_MenuStringBuffer5[15] = ' ';
					}
					//29308
					if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
					{
						g_MenuStringBuffer5[18] = ' ';
					}
					//2934c
					if (abs((int)Data_40004b08.dAltitude) < 10)
					{
						g_MenuStringBuffer6[5] = ' ';
					}
					//29384
					if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
					{
						g_MenuStringBuffer6[8] = ' ';
					}
					//29404
					if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
					{
						g_MenuStringBuffer6[11] = ' ';
					}
					//2945c
					g_pcstrMenuLine5 = g_MenuStringBuffer5;
					g_pcstrMenuLine6 = g_MenuStringBuffer6;
					
					dData_40002dd0 = dData_40002dc0_Azimuth;
					dData_40002e08 = dData_40002df8;
					
					sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
						(int)dData_40002dd0,
						(int)((dData_40002dd0 - (int)dData_40002dd0) * 60),
						(int)(dData_40002dd0 * 3600) % 60);
					//29540
					if (dData_40002e08 >= 0)
					{
						//29558
						sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
							abs((int)dData_40002e08),
							abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
							abs(((int)(dData_40002e08 * 3600) % 60)));
						//->2972c
					}
					else
					{
						//29644
						sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
							abs((int)dData_40002e08),
							abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
							abs(((int)(dData_40002e08 * 3600) % 60)));
					}
					//2972c
					if ((int)dData_40002dd0 < 100)
					{
						g_MenuStringBuffer7[11] = ' ';
					}
					//2974c
					if ((int)dData_40002dd0 < 10)
					{
						g_MenuStringBuffer7[12] = ' ';
					}
					//2976c
					if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
					{
						g_MenuStringBuffer7[15] = ' ';
					}
					//297d0
					if (((int)(dData_40002dd0 * 3600) % 60) < 10)
					{
						g_MenuStringBuffer7[18] = ' ';
					}
					//29810
					if (abs((int)dData_40002e08) < 10)
					{
						g_MenuStringBuffer8[5] = ' ';
					}
					//29894
					if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
					{
						g_MenuStringBuffer8[8] = ' ';
					}
					//2990c
					if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
					{
						g_MenuStringBuffer8[11] = ' ';
					}
					//29960
					g_pcstrMenuLine7 = g_MenuStringBuffer7;
					g_pcstrMenuLine8 = g_MenuStringBuffer8;
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
			
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = "                      ";
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = "                      ";
			g_pcstrMenuLine5 = "                      ";
			g_pcstrMenuLine6 = "                      ";
			g_pcstrMenuLine7 = "                      ";
			g_pcstrMenuLine8 = "                      ";
		
			g_pcstrMenuLine9 = "   ";
			g_pcstrMenuLine10 = "   ";
			g_pcstrMenuLine11 = "   ";
			g_pcstrMenuLine12 = "   ";
			g_pcstrMenuLine13 = "   ";
			g_pcstrMenuLine14 = "   ";
			g_pcstrMenuLine15 = "   ";
			g_pcstrMenuLine16 = "   ";
			//29a70
			switch (bData_40002f14_RecentTargetCount)
			{
				case 0:
					//0x29aa8
					g_pcstrMenuLine1 = "                      ";
					g_pcstrMenuLine2 = "                      ";
					g_pcstrMenuLine3 = "Sorry                 ";
					g_pcstrMenuLine4 = "                      ";
					g_pcstrMenuLine5 = "No Recent Target     ";
					g_pcstrMenuLine6 = "                      ";
					g_pcstrMenuLine7 = "                      ";
					g_pcstrMenuLine8 = "                      ";
					//->2a0f8
					break;
				
				case 8:
					//0x29b10
					g_pcstrMenuLine16 = "8: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[7];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[7];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//29b64
						g_MenuStringBuffer8[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
					
					g_pcstrMenuLine8 = g_MenuStringBuffer8;
					//break; //fall through
				
				case 7:
					//0x29bb8
					g_pcstrMenuLine15 = "7: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[6];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[6];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//29c08
						g_MenuStringBuffer7[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}

					g_pcstrMenuLine7 = g_MenuStringBuffer7;
					//break; //fall through
				
				case 6:
					//0x29c5c
					g_pcstrMenuLine14 = "6: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[5];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[5];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
#if 0
					g_pcstrMenuLine6 = Data_400033a4;
#endif

					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//29cbc
						g_MenuStringBuffer6[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					g_pcstrMenuLine6 = g_MenuStringBuffer6;
					//break; //fall through
				
				case 5:
					//0x29d10
					g_pcstrMenuLine13 = "5: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[4];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[4];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29e04
						g_MenuStringBuffer5[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					g_pcstrMenuLine5 = g_MenuStringBuffer5;
					//break; //fall through
				
				case 4:
					//0x29e58
					g_pcstrMenuLine12 = "4: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[3];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[3];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29ea8
						g_MenuStringBuffer4[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					g_pcstrMenuLine4 = g_MenuStringBuffer4;
					//break; //fall through
				
				case 3:
					//0x29efc
					g_pcstrMenuLine11 = "3: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[2];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[2];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29f4c
						g_MenuStringBuffer3[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					g_pcstrMenuLine3 = g_MenuStringBuffer3;
					//break; //fall through
				
				case 2:
					//0x29fa0
					g_pcstrMenuLine10 = "2: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[1];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[1];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x29ff0
						g_MenuStringBuffer2[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					g_pcstrMenuLine2 = g_MenuStringBuffer2;
					//break; //fall through
		
				case 1:
					//0x2a044
					g_pcstrMenuLine9 = "1: ";
					bData_40002f0d_RecentTargetType = Data_40002f15_RecentTargetTypeArray[0];
					bData_40002f10_RecentTargetId = Data_4000359c_RecentTargetIdArray[0];
				
					func_240e8(bData_40002f0d_RecentTargetType, bData_40002f10_RecentTargetId);
				
#if 0
					g_pcstrMenuLine1 = Data_400033a4;
#endif
				
					for (bData_40002f1d = 0; bData_40002f1d < 21; bData_40002f1d++)
					{
						//0x2a0a4
						g_MenuStringBuffer1[bData_40002f1d] = Data_4000410e[bData_40002f1d];
					}
				
					g_pcstrMenuLine1 = g_MenuStringBuffer1;
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
			g_pcstrMenuLine1 = strTelescopeAlign;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strNavigation;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strUtilities;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strSetup;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 1;
		
			g_pcstrBigMenuLine1 = strTelescopeAlign;
			g_pcstrBigMenuLine2 = strNavigation;
			g_pcstrBigMenuLine3 = strUtilities;
			g_pcstrBigMenuLine4 = strSetup;
		
			bData_4000316f_FocusLineOn4LineDisplay = 1;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_NAVIGATION: //2000:
			//0x2a220 - Navigation
			g_pcstrMenuLine1 = strTelescopeAlign;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strNavigation;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strUtilities;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strSetup;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 3;
		
			g_pcstrBigMenuLine1 = strTelescopeAlign;
			g_pcstrBigMenuLine2 = strNavigation;
			g_pcstrBigMenuLine3 = strUtilities;
			g_pcstrBigMenuLine4 = strSetup;
		
			bData_4000316f_FocusLineOn4LineDisplay = 2;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_UTILITIES: //3000:
			//0x2a2f4 - Utilities
			g_pcstrMenuLine1 = strTelescopeAlign;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strNavigation;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strUtilities;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strSetup;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 5;
		
			g_pcstrBigMenuLine1 = strTelescopeAlign;
			g_pcstrBigMenuLine2 = strNavigation;
			g_pcstrBigMenuLine3 = strUtilities;
			g_pcstrBigMenuLine4 = strSetup;
		
			bData_4000316f_FocusLineOn4LineDisplay = 3;
		
			AdaptDisplayLinesPerMenuLine();
			//->3d71c
			break;
		
		case MENU_CONTEXT_SETUP: //4000:
			//0x2a3c8 - Setup
			g_pcstrMenuLine1 = strTelescopeAlign;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strNavigation;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strUtilities;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strSetup;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 7;
		
			g_pcstrBigMenuLine1 = strTelescopeAlign;
			g_pcstrBigMenuLine2 = strNavigation;
			g_pcstrBigMenuLine3 = strUtilities;
			g_pcstrBigMenuLine4 = strSetup;
		
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
			PrepareEightLineMenuScroll(14, g_bSetupEightLineMenuTopItem);
		
			bData_4000316e_FocusLineOn8LineDisplay = g_bSetupEightLineMenuFocusItem;
		
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
			g_pcstrMenuLine1 = strScientificName;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strSAOCatalog;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strHRCatalog;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0x9c6: //2502
			//0x2a780
			g_pcstrMenuLine1 = strScientificName;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strSAOCatalog;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strHRCatalog;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0x9C7: //2503
			//0x2a80c
			g_pcstrMenuLine1 = strScientificName;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strSAOCatalog;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strHRCatalog;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xAF1: //2801
			//0x2a898
			g_pcstrMenuLine1 = strSelect;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strAdd;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strDelete;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strModify;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xAF2: //2802
			//0x2a924
			g_pcstrMenuLine1 = strSelect;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strAdd;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strDelete;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strModify;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xAF3: //2803
			//0x2aa2c
			g_pcstrMenuLine1 = strSelect;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strAdd;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strDelete;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strModify;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xAF4: //2804
			//0x2aabc
			g_pcstrMenuLine1 = strSelect;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strAdd;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strDelete;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strModify;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 7;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0x526D: //21101
			//0x2ab4c
			g_pcstrMenuLine1 = Data_40003044;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = Data_40003048;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = Data_4000304c;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0x526E: //21102
			//0x2abd4
			g_pcstrMenuLine1 = Data_40003044;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = Data_40003048;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = Data_4000304c;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0x526F: //21103
			//0x2ac60
			g_pcstrMenuLine1 = Data_40003044;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = Data_40003048;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = Data_4000304c;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xE11: //3601
			//0x2acec
			g_pcstrMenuLine1 = strEyeshot;
			g_pcstrMenuLine2 = strRatio;
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xE12: //3602
			//0x2ad70
			g_pcstrMenuLine1 = strEyeshot;
			g_pcstrMenuLine2 = strRatio;
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xED9: //3801
			//0x2adf8
			g_pcstrMenuLine1 = strBackBoard;
			g_pcstrMenuLine2 = strAccessory;
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xEDA: //3802
			//0x2ae7c
			g_pcstrMenuLine1 = strBackBoard;
			g_pcstrMenuLine2 = strAccessory;
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case MENU_CONTEXT_COUNTRY_CITY: //4301:
			//0x2af04: Country & City
			g_pcstrMenuLine1 = strCountryAndCity;
			g_pcstrMenuLine3 = strCustomSite;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE: //4302:
			//0x2af88: Custom Site
			g_pcstrMenuLine1 = strCountryAndCity;
			g_pcstrMenuLine3 = strCustomSite;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case 0xA80D: //43021
			//0x2b010
			g_pcstrMenuLine1 = Data_40003068;
			g_pcstrMenuLine3 = Data_4000306c;
			g_pcstrMenuLine5 = Data_40003070;
			g_pcstrMenuLine7 = Data_40003074;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xA80E: //43022
			//0x2b09c
			g_pcstrMenuLine1 = Data_40003068;
			g_pcstrMenuLine3 = Data_4000306c;
			g_pcstrMenuLine5 = Data_40003070;
			g_pcstrMenuLine7 = Data_40003074;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xA80F: //43023
			//0x2b184
			g_pcstrMenuLine1 = Data_40003068;
			g_pcstrMenuLine3 = Data_4000306c;
			g_pcstrMenuLine5 = Data_40003070;
			g_pcstrMenuLine7 = Data_40003074;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case 0xA810: //43024
			//0x2b214
			g_pcstrMenuLine1 = Data_40003068;
			g_pcstrMenuLine3 = Data_4000306c;
			g_pcstrMenuLine5 = Data_40003070;
			g_pcstrMenuLine7 = Data_40003074;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 7;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case MENU_CONTEXT_TRACKING_RATE_STAR_SPEED: //4801:
			//0x2b2a4
			g_pcstrMenuLine1 = strStarSpeed;
			g_pcstrMenuLine2 = strSolarSpeed;
			g_pcstrMenuLine3 = strMoonSpeed;
			g_pcstrMenuLine4 = Data_40003094; // "Customize Speed"
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = Data_40003098; // "Guiding Speed"
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED: //4802:
			//0x2b334
			g_pcstrMenuLine1 = strStarSpeed;
			g_pcstrMenuLine2 = strSolarSpeed;
			g_pcstrMenuLine3 = strMoonSpeed;
			g_pcstrMenuLine4 = Data_40003094;
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = Data_40003098;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_MOON_SPEED: //4803
			//0x2b3c8
			g_pcstrMenuLine1 = strStarSpeed;
			g_pcstrMenuLine2 = strSolarSpeed;
			g_pcstrMenuLine3 = strMoonSpeed;
			g_pcstrMenuLine4 = Data_40003094;
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = Data_40003098;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED: //4804
			//0x2b45c
			g_pcstrMenuLine1 = strStarSpeed;
			g_pcstrMenuLine2 = strSolarSpeed;
			g_pcstrMenuLine3 = strMoonSpeed;
			g_pcstrMenuLine4 = Data_40003094;
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = Data_40003098;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 4;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;
		
		case MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED: //4805
			//0x2b4f0
			g_pcstrMenuLine1 = strStarSpeed;
			g_pcstrMenuLine2 = strSolarSpeed;
			g_pcstrMenuLine3 = strMoonSpeed;
			g_pcstrMenuLine4 = Data_40003094;
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = Data_40003098;
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 7;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->3d71c
			break;

		case MENU_CONTEXT_GUIDING_SPEED1: //48051
			//0x2b584: Setup -> Tracking Rate -> Guiding Speed
			g_pcstrMenuLine1 = "speed1:   x 0.125";
			g_pcstrMenuLine2 = "speed2:   x 0.250";
			g_pcstrMenuLine3 = "speed3:   x 0.375";
			g_pcstrMenuLine4 = "speed4:   x 0.500";
			g_pcstrMenuLine5 = "speed5:   x 0.625";
			g_pcstrMenuLine6 = "speed6:   x 0.750";
			g_pcstrMenuLine7 = "speed7:   x 0.875";
			g_pcstrMenuLine8 = "speed8:   x 1.000";
		
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
			
			sprintf(g_MenuStringBuffer5, "R.a: %02dh%02dm                ",
				(int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2],
				(int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2]) * 60));

			if ((int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2] < 10)
			{
				g_MenuStringBuffer5[5] = ' ';
			}
			
			if ((int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[(bData_40002c60_CurrentAlignStarIndex - 1)*2]) * 60) < 10)
			{
				g_MenuStringBuffer5[8] = ' ';
			}
			
			if (Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] < 0)
			{
				//2b848
				sprintf(g_MenuStringBuffer6, "Dec:-%02d %02d                 ",
					abs((int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1]),
					abs((int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1]) * 60)));				
			}
			else
			{
				//0x2ba08
				sprintf(g_MenuStringBuffer6, "Dec:+%02d %02d                 ",
					(int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1],
					abs((int) ((Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1]) * 60)));				
			}

			if ((int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			
			if ((int) (((Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) + 1] - (int) Data_40004a68_CurrentAlignStarEquatorialCoord[2*(bData_40002c60_CurrentAlignStarIndex - 1) /*+ 1*/])+1) * 60) < 10) //BUG!
			{
				g_MenuStringBuffer6[8] = ' ';
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
						sprintf(g_MenuStringBuffer5, "Azi:%03d %02d          ",
							abs(Data_40002dac), abs(Data_40002db0));
					
						if (abs(Data_40002dac) < 100)
						{
							g_MenuStringBuffer5[4] = ' ';
						}
						if (abs(Data_40002dac) < 10)
						{
							g_MenuStringBuffer5[5] = ' ';
						}
						if (abs(Data_40002db0) < 10)
						{
							g_MenuStringBuffer5[8] = ' ';
						}
						
						sprintf(g_MenuStringBuffer6, "Alt: %02d %02d          ",
							abs(Data_40002de0), abs(Data_40002de4));

						if (abs(Data_40002de0) < 10)
						{
							g_MenuStringBuffer6[5] = ' ';
						}
						if (abs(Data_40002de4) < 10)
						{
							g_MenuStringBuffer6[8] = ' ';
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

			sprintf(g_MenuStringBuffer7, "Azi:%03d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60));
				
			sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d               ",
				abs((int)Data_40004b08.dAltitude),
				abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)));
			
			if (bTrackingMode == 1)
			{
				//2c2cc
				sprintf(g_MenuStringBuffer7, "Azi:%03d %02d                ",
					(int)Data_40004b08.dAzimuth,
					(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60));
				
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)));			
			}
			//0x2c3fc
			if ((int)Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer7[4] = ' ';
			}
			if ((int)Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			
			g_pcstrMenuLine1 = strListAlignStars; //"List align stars:"
			g_pcstrMenuLine2 = "                     ";
			g_pcstrMenuLine3 = arAlignmentStarNames[bData_40002c60_CurrentAlignStarIndex - 1];
			g_pcstrMenuLine4 = "                        ";
			g_pcstrMenuLine5 = g_MenuStringBuffer7; //"OBJ:      Azi:..."???
			g_pcstrMenuLine6 = g_MenuStringBuffer8;
			g_pcstrMenuLine7 = g_MenuStringBuffer5;
			g_pcstrMenuLine8 = g_MenuStringBuffer6;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_MERIDIAN_FLIP: //3:
			//0x2c658
			beep1(1);
		
			g_pcstrMenuLine1 = "Star move meridian";
			g_pcstrMenuLine2 = "and telestope stop or";
			g_pcstrMenuLine3 = "reverse after 10 mins";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "ENTER:  Reverse";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "CANCEL: Stop";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SYNC_OPEN: //1401:
			//0x2c6e0
			g_pcstrMenuLine1 = "";
			g_pcstrMenuLine2 = "Targers Sync. Open?";
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "     ENTER:Yes";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "     CANCEL:No";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SYNC_ENSURE: //1402:
			//0x2c760
			g_pcstrMenuLine1 = "Targers Sync. ensure!";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = "Targers Sync. cancel!";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SYNC_CANCEL: //1403
			//0x2c7dc
			g_pcstrMenuLine1 = "Targers Sync. ensure!";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = "Targers Sync. cancel!";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_POLE_AXIS_DEV_INPUT: //18001:
			//0x2c85c
			g_pcstrMenuLine1 = "Pole Axis Dev: ";
			g_pcstrMenuLine2 = "";
		
			if (g_dPoleAxisDevEastWest > 0)
			{
				//2c890
				sprintf(g_MenuStringBuffer1, "ToE:%.5f\011Degree", fabs(g_dPoleAxisDevEastWest));
			}
			else
			{
				//0x2c8bc
				sprintf(g_MenuStringBuffer1, "ToW:%.5f\011Degree", fabs(g_dPoleAxisDevEastWest));
			}
			//0x2c8e4
			g_pcstrMenuLine3 = g_MenuStringBuffer1;
			
			if (g_dPoleAxisDevNorthSouth > 0)
			{
				//2c908
				sprintf(g_MenuStringBuffer2, "ToN:%.5f\011Degree", fabs(g_dPoleAxisDevNorthSouth));
			}
			else
			{
				//0x2ca50
				sprintf(g_MenuStringBuffer2, "ToS:%.5f\011Degree", fabs(g_dPoleAxisDevNorthSouth));
			}
			//0x2ca78
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = g_MenuStringBuffer2;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
			//0x2cad0: RA Bklash Corr. - 1st page
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = strPleaseAimAtThe;
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = strTelescopeToDistant;
			g_pcstrMenuLine5 = "                      ";
			g_pcstrMenuLine6 = strTargetThenPress;
			g_pcstrMenuLine7 = "                      ";
			g_pcstrMenuLine8 = strEnterKey;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
			//0x2cb60: RA Bklash Corr. - 2nd page
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = Data_400030dc; // "Press RIGHT or LEFT"
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = Data_400030e0; // "key to start Ra(Azi)"
			g_pcstrMenuLine5 = "                      ";
			g_pcstrMenuLine6 = Data_400030e4; // "backlash align,press"
			g_pcstrMenuLine7 = "                      ";
			g_pcstrMenuLine8 = Data_400030e8; // "ENTER key to finish!"
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103
			//0x2cbf0
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = Data_400030ec; //"Slewing....."
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = Data_400030f0; //"After beep, turn tele"
			g_pcstrMenuLine5 = "                      ";
			g_pcstrMenuLine6 = Data_400030f4; //"-cope back to target"
			g_pcstrMenuLine7 = "                      ";
			g_pcstrMenuLine8 = Data_400030f8; //"then press,ENTER!"
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_RA_BKBLASH_CORR_RESULT: //11104
			//0x2cc80
			sprintf(g_MenuStringBuffer1, "%.1f", fData_40002e90);
		
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = "                      ";
		
			if (bRaBacklashCorrectionDirection == 2)
			{
				g_pcstrMenuLine3 = Data_400030fc;
			}
			//0x2cce4
			if (bRaBacklashCorrectionDirection == 1)
			{
				g_pcstrMenuLine3 = Data_40003100;
			}
			//0x2cd04
			g_pcstrMenuLine4 = "                      ";
			g_pcstrMenuLine5 = g_MenuStringBuffer1;
			g_pcstrMenuLine6 = "                      ";
			g_pcstrMenuLine7 = Data_40003104; //"          arcsecond"
			g_pcstrMenuLine8 = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case 11105:
			//0x2cdc0
			sprintf(g_MenuStringBuffer1, "%.1f", fData_40002e98);
		
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = "                      ";
			g_pcstrMenuLine3 = Data_40003108; //"The mean backlash is:"
			g_pcstrMenuLine4 = "                      ";
			g_pcstrMenuLine5 = g_MenuStringBuffer1;
			g_pcstrMenuLine6 = "                      ";
			g_pcstrMenuLine7 = Data_40003104; //"          arcsecond"
			g_pcstrMenuLine8 = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
			//0x2ce70
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = strPleaseAimAtThe;
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = strTelescopeToDistant;
			g_pcstrMenuLine5 = "                      ";
			g_pcstrMenuLine6 = strTargetThenPress;
			g_pcstrMenuLine7 = "                      ";
			g_pcstrMenuLine8 = strEnterKey;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN: //11201:
			//0x2cf00
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = Data_4000310c; // "press UP or DOWN"
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = Data_40003110; // "key to start Dec(Alt)"
			g_pcstrMenuLine5 = "                      ";
			g_pcstrMenuLine6 = Data_400030e4; // "backlash align,press"
			g_pcstrMenuLine7 = "                      ";
			g_pcstrMenuLine8 = Data_400030e8; // "ENTER key to finish!"
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203
			//0x2cf90
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = Data_400030ec;
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = Data_400030f0;
			g_pcstrMenuLine5 = "                      ";
			g_pcstrMenuLine6 = Data_400030f4;
			g_pcstrMenuLine7 = "                      ";
			g_pcstrMenuLine8 = Data_400030f8;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_DEC_BKBLASH_CORR_RESULT: //11204
			//0x2d020
			sprintf(g_MenuStringBuffer1, "%.1f", fData_40002ea0);
		
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = "                      ";
		
			if (bDecBacklashCorrectionDirection == 2)
			{
				g_pcstrMenuLine3 = Data_400030fc;
			}
			//0x2d084
			if (bDecBacklashCorrectionDirection == 1)
			{
				g_pcstrMenuLine3 = Data_40003100;
			}
			//0x2d0a4
			g_pcstrMenuLine4 = "                      ";
			g_pcstrMenuLine5 = g_MenuStringBuffer1;
			g_pcstrMenuLine6 = "                      ";
			g_pcstrMenuLine7 = Data_40003104;
			g_pcstrMenuLine8 = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case 0x2BC5: //11205
			//0x2d100
			sprintf(g_MenuStringBuffer1, "%.1f", fData_40002ea8);
		
			g_pcstrMenuLine1 = "                      ";
			g_pcstrMenuLine2 = "                      ";
			g_pcstrMenuLine3 = Data_40003108; //"The mean backlash is:"
			g_pcstrMenuLine4 = "                      ";
			g_pcstrMenuLine5 = g_MenuStringBuffer1;
			g_pcstrMenuLine6 = "                      ";
			g_pcstrMenuLine7 = Data_40003104; //"          arcsecond"
			g_pcstrMenuLine8 = "                      ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
			//0x2d1b0
			get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
				&fData_40002cd0_ObjectRightAscension, &fData_40002d18_ObjectDeclination);
		
			g_pcstrMenuLine1 = Data_4000314c_SolarSystemObjectName;
			g_pcstrMenuLine2 = "                      ";
			g_pcstrMenuLine3 = "                      ";
			g_pcstrMenuLine4 = "                      ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int) Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60),
				((int) (Data_40004b08.dAzimuth * 3600)) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//2d35c
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
			}
			else				
			{
				//0x2d458
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
			}
			//0x2d550
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x2d758
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			//2d770
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int) fData_40002cd0_ObjectRightAscension,
				(int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60),
				(int) (fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			//2d8a8
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//2d8c8
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			else
			{
				//0x2d998
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			//0x2da64
			if (abs((int) fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int) (fData_40002d18_ObjectDeclination * 3600) % 60)) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x2db48
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;

		case MENU_CONTEXT_SUN_WARNING: //22112:
			//0x2db70: Sun Warning screen
			g_pcstrMenuLine1 = "                     ";
			g_pcstrMenuLine2 = "    DO NOT POINT     ";
			g_pcstrMenuLine3 = "the telescope or its ";
			g_pcstrMenuLine4 = "viewfinder at or near";
			g_pcstrMenuLine5 = "the Sun!!!           ";
			g_pcstrMenuLine6 = "                     ";
			g_pcstrMenuLine7 = "ENTER:continue       ";
			g_pcstrMenuLine8 = "    -:return         ";
			
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

			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int) Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60),
				((int) (Data_40004b08.dAzimuth * 3600)) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//2de9c
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
			}
			else				
			{
				//0x2df98
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int) Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)),
					abs(((int) (Data_40004b08.dAltitude * 3600)) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x2e09c
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x2e2a4
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
			//2e534
			if (dData_40002e08 >= 0)
			{
				//2e54c
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
				//->0x2e720
			}
			else
			{
				//0x2e638
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//2e720
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x2e904
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x2e9d4
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x2e9e8
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x2ea08
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x2ea1c
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x2ea30
					g_pcstrMenuLine1 = "                              ";
					break;
			}
			//0x2ea44
			g_pcstrMenuLine2 = "                              ";
			g_pcstrMenuLine3 = Data_4000314c_SolarSystemObjectName;
			g_pcstrMenuLine4 = "                              ";

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
		
			g_pcstrMenuLine1 = Data_40003dd4_FlashConstellationData.bData_5;
			g_pcstrMenuLine2 = "                      ";
		
			sprintf(g_MenuStringBuffer3, "    Area: %d SQ.Deg               ",
				Data_40003dd4_FlashConstellationData.wArea);
		
			g_pcstrMenuLine3 = g_MenuStringBuffer3;
			g_pcstrMenuLine3[0] = Data_40003dd4_FlashConstellationData.bData_5[0];
			g_pcstrMenuLine3[1] = Data_40003dd4_FlashConstellationData.bData_5[1];
			g_pcstrMenuLine3[2] = Data_40003dd4_FlashConstellationData.bData_5[2];
		
			sprintf(g_MenuStringBuffer4, "Quantity: %d (>6Mag)             ",
				Data_40003dd4_FlashConstellationData.bQuantity);
		
			g_pcstrMenuLine4 = g_MenuStringBuffer4;
			
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
			
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//2ecb0
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x2ef0c
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			//0x2f004
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x2f20c
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int) fData_40002cd0_ObjectRightAscension,
				(int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60),
				(int) (fData_40002cd0_ObjectRightAscension * 3600) % 60);
			
			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			//0x2f35c
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//2f37c
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			else
			{
				//0x2f44c
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			//0x2f518
			if (abs((int) fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int) (fData_40002d18_ObjectDeclination * 3600) % 60)) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x2f5fc
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//2f7b8
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x2f8b4
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
					
				bTrackingModeMenu = 3;
			}
			//0x2f9b8
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x2fbc0
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//2fec8
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x2ffb4
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3009c
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x30280
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x30350
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x30364
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x30384
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x30398
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x303ac
					g_pcstrMenuLine1 = "                              ";
					break;
			}
			//303c4
			g_pcstrMenuLine2 = "                              ";
			g_pcstrMenuLine3 = Data_40003dd4_FlashConstellationData.bData_5;
			g_pcstrMenuLine4 = "                              ";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
			//0x30404: Famous Star item
			flash_get_famous_star_data(bData_40002ed2_FamousStarNr, &Data_40003d94_FlashFamousStarData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003d94_FlashFamousStarData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003d94_FlashFamousStarData.fDeclination;
		
			g_pcstrMenuLine1 = Data_40003d94_FlashFamousStarData.bData_0;
			g_pcstrMenuLine2 = "                                        ";
			g_pcstrMenuLine3 = Data_40003d94_FlashFamousStarData.bData_28;
		
			sprintf(g_MenuStringBuffer4, "SAO:%d  MEG:%.1f",
				Data_40003d94_FlashFamousStarData.Data_24, Data_40003d94_FlashFamousStarData.fData_52);
		
			g_pcstrMenuLine4 = g_MenuStringBuffer4;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
		
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//305f4
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x30790
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			//0x30888
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x30a90
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int) fData_40002cd0_ObjectRightAscension,
				(int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60),
				(int) (fData_40002cd0_ObjectRightAscension * 3600) % 60);

			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			//0x30be0
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//30c00
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			else
			{
				//0x30cd0
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int) fData_40002d18_ObjectDeclination),
					abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)),
					abs((int) (fData_40002d18_ObjectDeclination * 3600) % 60));
			}
			//0x30d9c
			if (abs((int) fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int) ((fData_40002d18_ObjectDeclination - (int) fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int) (fData_40002d18_ObjectDeclination * 3600) % 60)) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x30e80
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
				
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
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//31040
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
			}
			else
			{
				//0x3113c
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude),
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60)),
					abs(((int)(Data_40004b08.dAltitude * 3600) % 60)));
					
				bTrackingModeMenu = 3;
			}
			//0x31240
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x31448
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
			//316dc
			if (dData_40002e08 >= 0)
			{
				//316f4
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{
				//0x317e0
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x318c8
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}
			
			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x31aac
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x31b7c
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x31b90
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x31bb0
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x31bc4
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x31bd8
					g_pcstrMenuLine1 = "                              ";
					break;
			}
			//0x31bec
			sprintf(g_MenuStringBuffer2, "Sao:%d                  ",
				Data_40003d94_FlashFamousStarData.Data_24);
			
			g_pcstrMenuLine2 = g_MenuStringBuffer2;
			g_pcstrMenuLine3 = "                                        ";
			g_pcstrMenuLine4 = Data_40003d94_FlashFamousStarData.bData_28;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012
			//0x31c44
			flash_get_messier_data((unsigned char)wData_40002eb8_MessierNr, 
					&Data_40003e08_FlashMessierData);
		
			sprintf(g_MenuStringBuffer1, "Messier:%d   NGC:%d                   ",
				wData_40002eb8_MessierNr, Data_40003e08_FlashMessierData.wData_0);
			
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = Data_40003e08_FlashMessierData.bData_32;
			g_pcstrMenuLine3 = Data_40003e08_FlashMessierData.bData_60;
			g_pcstrMenuLine4 = Data_40003e08_FlashMessierData.bData_108;
			g_pcstrMenuLine5 = "                                                   ";
		
			sprintf(g_MenuStringBuffer6, "Size:%.1f Arc Minute                  ",
				Data_40003e08_FlashMessierData.fData_12);
		
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
		
			sprintf(g_MenuStringBuffer7, "Distance:%.1f                         ",
				Data_40003e08_FlashMessierData.dData_16);
		
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = "         K Light-Years";
		
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
		
			sprintf(g_MenuStringBuffer1, "Messier:%d                        ",
				wData_40002eb8_MessierNr);
		
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = Data_40003e08_FlashMessierData.bData_32;
			g_pcstrMenuLine3 = Data_40003e08_FlashMessierData.bData_60;
			g_pcstrMenuLine4 = "                                                ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;
		
			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
			//320b0
			if (Data_40004b08.dAltitude >= 0)
			{
				//320cc
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x321c8
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x32320
			if ((int) Data_40004b08.dAzimuth < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if ((int) Data_40004b08.dAzimuth < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int) Data_40004b08.dAzimuth) * 60) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if ((((int) (Data_40004b08.dAzimuth * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			
			if (abs((int) Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int) Data_40004b08.dAltitude) * 60)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int) (Data_40004b08.dAltitude * 3600)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x32528
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);

			if ((int) fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if ((int) ((fData_40002cd0_ObjectRightAscension - (int) fData_40002cd0_ObjectRightAscension) * 60) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int) (fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			//0x32678
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
				
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//32698
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x32768
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x32834
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x32918
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
					
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
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//32adc
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x32bd8
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x32cdc
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x32ee4
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//33188
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x33274
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3335c
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x335b8
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;

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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x33688
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					bData_40003432 = 1;
					break;
				
				case 3:
					//0x336a8
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x336bc
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x336d0
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x336e4
					g_pcstrMenuLine1 = "                              ";
					break;
			}
			//0x336f8
			sprintf(g_MenuStringBuffer2, "Messier:%d                        ",
				wData_40002eb8_MessierNr);
			
			g_pcstrMenuLine2 = g_MenuStringBuffer2;
			g_pcstrMenuLine3 = Data_40003e08_FlashMessierData.bData_32;
			g_pcstrMenuLine4 = Data_40003e08_FlashMessierData.bData_60;
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003
			//0x33750
			flash_get_ngc_data(wData_40002eba_NGCNr, &Data_40003ee0_FlashNGCData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ee0_FlashNGCData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ee0_FlashNGCData.fDeclination;
		
			sprintf(g_MenuStringBuffer1, "NGC:%d                          ",
				wData_40002eba_NGCNr);
		
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = Data_40003ee0_FlashNGCData.bData_0;
		
			if (Data_40003ee0_FlashNGCData.fData_16 != 0)
			{
				//337c4
				sprintf(g_MenuStringBuffer3, "MEG:%.1f                          ",
					Data_40003ee0_FlashNGCData.fData_16);
				g_pcstrMenuLine3 = g_MenuStringBuffer3;
			}
			else
			{
				//0x337fc
				g_pcstrMenuLine3 = "                                          ";
			}
			//0x33808
			g_pcstrMenuLine4 = Data_40003ee0_FlashNGCData.bData_20;
			
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
			//3389c
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//33974
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x33b60
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x33c58
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x33e60
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//33fd0
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x340a0
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x3416c
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x34250
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//3440c
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x34508
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x3460c
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x34814
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;

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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//34ab8
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x34ba4
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x34c8c
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x34edc
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;

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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x34fac
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x34fc0
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x34fe0
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x34ff4
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x35008
					g_pcstrMenuLine1 = "                     ";
					break;
			}
			//0x336f8
			sprintf(g_MenuStringBuffer2, "NGC:%d                          ",
				wData_40002eba_NGCNr);
			
			g_pcstrMenuLine2 = g_MenuStringBuffer2;
			g_pcstrMenuLine3 = Data_40003ee0_FlashNGCData.bData_0;
			
			if (Data_40003ee0_FlashNGCData.fData_16 != 0)
			{
				//35060
				sprintf(g_MenuStringBuffer4, "MEG:%.1f          ",
					Data_40003ee0_FlashNGCData.fData_16);
				g_pcstrMenuLine4 = g_MenuStringBuffer4;
			}
			else
			{
				//0x35098
				g_pcstrMenuLine4 = "                     ";
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
		
			sprintf(g_MenuStringBuffer1, "IC:%d                          ",
				wData_40002ebc_ICNr);
		
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = Data_40003ec0_FlashICData.bData_0;
		
			if (Data_40003ec0_FlashICData.fData_16 != 0)
			{
				//35134
				sprintf(g_MenuStringBuffer3, "MEG:%.1f                          ",
					Data_40003ec0_FlashICData.fData_16);
				g_pcstrMenuLine3 = g_MenuStringBuffer3;
			}
			else
			{
				//0x3516c
				g_pcstrMenuLine3 = "                                          ";
			}
			//0x35178
			g_pcstrMenuLine4 = Data_40003ec0_FlashICData.bData_20;
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
			//3520c
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//352e4
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x3549c
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x35594
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x3579c
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//3590c
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x359dc
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x35aa8
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x35b8c
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//35d4c
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x35e48
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x35f4c
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x36154
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;

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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//363fc
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x364e8
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x365d0
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x3682c
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;

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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x368fc
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x36910
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x36930
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x36944
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x36958
					g_pcstrMenuLine1 = "                     ";
					break;
			}
			//0x3696c
			sprintf(g_MenuStringBuffer2, "IC:%d                          ",
				wData_40002ebc_ICNr);
			
			g_pcstrMenuLine2 = g_MenuStringBuffer2;
			g_pcstrMenuLine3 = Data_40003ec0_FlashICData.bData_0;
			
			if (Data_40003ec0_FlashICData.fData_16 != 0)
			{
				//369b0
				sprintf(g_MenuStringBuffer4, "MEG:%.1f          ",
					Data_40003ec0_FlashICData.fData_16);
				g_pcstrMenuLine4 = g_MenuStringBuffer4;
			}
			else
			{
				//0x369e8
				g_pcstrMenuLine4 = "                     ";
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
		
			sprintf(g_MenuStringBuffer1, "Sh2:%d                          ",
				wData_40002ebe_ShNr);
		
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                                        ";
			g_pcstrMenuLine3 = "                                        ";
			g_pcstrMenuLine4 = "                                        ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//36be8
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x36d88
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x36e80
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x37088
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//371f8
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x372c8
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x37394
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x37478
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//37634
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x37730
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x37834
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x37a3c
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;

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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//37ce4
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x37dd0
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x37eb8
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x38108
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;

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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x381d8
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x381ec
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x3820c
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x38220
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x38234
					g_pcstrMenuLine1 = "                              ";
					break;
			}
			//0x38248
			sprintf(g_MenuStringBuffer3, "Sh2:%d                          ",
				wData_40002ebe_ShNr);
			
			g_pcstrMenuLine3 = g_MenuStringBuffer3;
			g_pcstrMenuLine2 = "                                        ";
			g_pcstrMenuLine4 = "                                        ";

			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c					
			break;
		
		case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006
			//0x382a0
			flash_get_bright_star_data((unsigned char)wData_40002ec0_BrightStarNr, &Data_40003ea0_FlashBrightStarData);
		
			fData_40002cd0_ObjectRightAscension = Data_40003ea0_FlashBrightStarData.fRightAscension;
			fData_40002d18_ObjectDeclination = Data_40003ea0_FlashBrightStarData.fDeclination;
		
			sprintf(g_MenuStringBuffer1, "Bright:%d                          ",
				wData_40002ec0_BrightStarNr);
		
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = Data_40003ea0_FlashBrightStarData.bData_0;
		
			if (Data_40003ea0_FlashBrightStarData.fData_28 != 0)
			{
				//38318
				sprintf(g_MenuStringBuffer3, "MEG:%.1f                          ",
					Data_40003ea0_FlashBrightStarData.fData_28);
				g_pcstrMenuLine3 = g_MenuStringBuffer3;
			}
			else
			{
				//0x38350
				g_pcstrMenuLine3 = "                                          ";
			}
			//0x3835c
			g_pcstrMenuLine4 = "                                          ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//384cc
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x38668
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x38760
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x38968
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//38ad8
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x38ba8
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x38c74
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x38d58
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
		
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)Data_40004b08.dAzimuth,
				(int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0),
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//38f18
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x39014
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//0x39118
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x39320
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;

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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));
				
			if (dData_40002e08 >= 0)
			{
				//395c8
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{	
				//0x396b4
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3979c
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x399f8
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;

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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x39ac8
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x39adc
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x39afc
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x39b10
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x39b24
					g_pcstrMenuLine1 = "                              ";
					break;
			}
			//0x39b38
			sprintf(g_MenuStringBuffer2, "Bright:%d                          ",
				wData_40002ec0_BrightStarNr);
			
			g_pcstrMenuLine2 = g_MenuStringBuffer2;
			g_pcstrMenuLine3 = Data_40003ea0_FlashBrightStarData.bData_0;
			g_pcstrMenuLine4 = "                              ";

			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c					
			break;
		
		case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
			//0x39b90: SAO item
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);
		
			fData_40002cd0_ObjectRightAscension = Data_40003358_SAORecord.ra;
			fData_40002d18_ObjectDeclination = Data_40003358_SAORecord.dec;
		
			sprintf(g_MenuStringBuffer1, "SAO:%d                          ",
				Data_40002ec4_SAONr);
		
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                                        ";
			g_pcstrMenuLine3 = "                                        ";
			g_pcstrMenuLine4 = "                                        ";
		
			Data_40004ad8.dLongitude = Data_40004128.geographicLongitude;
			Data_40004ad8.dLatitude = Data_40004128.geographicLatitude;
			Data_40004ae8.dRA = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dDec = fData_40002d18_ObjectDeclination;

			convert_equatorial_to_horizontal(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, &Data_40004b08);
				
			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);
				
			if (Data_40004b08.dAltitude >= 0)
			{
				//39d68
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//0x39f00
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			//0x39ff8
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}			
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}

			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//0x3a200
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
			sprintf(g_MenuStringBuffer7, "R.a: %02dh%02dm%02ds         ",
				(int)fData_40002cd0_ObjectRightAscension,
				(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
				(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
				
			if ((int)fData_40002cd0_ObjectRightAscension < 10)
			{
				g_MenuStringBuffer7[5] = ' ';
			}
			if (((int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60)) < 10)
			{
				g_MenuStringBuffer7[8] = ' ';
			}
			if (((int)(fData_40002cd0_ObjectRightAscension * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			
			if (fData_40002d18_ObjectDeclination >= 0)
			{
				//3a370
				sprintf(g_MenuStringBuffer8, "Dec:+%02d %02d %02d      ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			else
			{
				//0x3a440
				sprintf(g_MenuStringBuffer8, "Dec:-%02d %02d %02d        ",
					abs((int)fData_40002d18_ObjectDeclination),
					abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
					abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
			}
			//0x3a50c
			if (abs((int)fData_40002d18_ObjectDeclination) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((fData_40002d18_ObjectDeclination - (int)fData_40002d18_ObjectDeclination) * 60)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs((int)(fData_40002d18_ObjectDeclination * 3600) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x3a5f0
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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

			sprintf(g_MenuStringBuffer5, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08.dAzimuth), 
				(int)((Data_40004b08.dAzimuth - (int)(Data_40004b08.dAzimuth)) * 60.0), 
				(int)(Data_40004b08.dAzimuth * 3600.0) % 60);

			if (Data_40004b08.dAltitude >= 0)
			{
				//3a7ac
				sprintf(g_MenuStringBuffer6, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
			}
			else
			{
				//3a8a8
				sprintf(g_MenuStringBuffer6, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08.dAltitude), 
					abs((int)((Data_40004b08.dAltitude - (int)(Data_40004b08.dAltitude)) * 60.0)), 
					abs((int)(Data_40004b08.dAltitude * 3600.0) % 60));
					
				bTrackingModeMenu = 3;
			}
			//3a9ac
			if ((int)(Data_40004b08.dAzimuth) < 100)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			//3a9d0
			if ((int)(Data_40004b08.dAzimuth) < 10)
			{
				g_MenuStringBuffer5[12] = ' ';
			}
			//3a9f4
			if ((int)((Data_40004b08.dAzimuth - (int)Data_40004b08.dAzimuth) * 60.0) < 10)
			{
				g_MenuStringBuffer5[15] = ' ';
			}
			//3aa60
			if (((int)(Data_40004b08.dAzimuth * 3600.0) % 60) < 10)
			{
				g_MenuStringBuffer5[18] = ' ';
			}
			//3aaa4
			if (abs((int)Data_40004b08.dAltitude) < 10)
			{
				g_MenuStringBuffer6[5] = ' ';
			}
			//3aadc
			if (abs((int)((Data_40004b08.dAltitude - (int)Data_40004b08.dAltitude) * 60.0)) < 10)
			{
				g_MenuStringBuffer6[8] = ' ';
			}
			//3ab5c
			if (abs(((int)(Data_40004b08.dAltitude * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer6[11] = ' ';
			}
			//3abb4
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
			g_pcstrMenuLine6 = g_MenuStringBuffer6;
			
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
			sprintf(g_MenuStringBuffer7, "OTA    Azi:%03d %02d %02d                ",
				abs((int)dData_40002dd0),
				abs((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)),
				abs((int)(dData_40002dd0 * 3600) % 60));

			if (dData_40002e08 >= 0)
			{
				//3ae58
				sprintf(g_MenuStringBuffer8, "Alt:+%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			else
			{
				//0x3af44
				sprintf(g_MenuStringBuffer8, "Alt:-%02d %02d %02d               ",
					abs((int)dData_40002e08),
					abs((int)((dData_40002e08 - (int)(dData_40002e08)) * 60)),
					abs(((int)(dData_40002e08 * 3600) % 60)));
			}
			//0x3b02c
			if ((int)dData_40002dd0 < 100)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if ((int)dData_40002dd0 < 10)
			{
				g_MenuStringBuffer7[12] = ' ';
			}
			if (((int)((dData_40002dd0 - (int)dData_40002dd0) * 60)) < 10)
			{
				g_MenuStringBuffer7[15] = ' ';
			}
			if (((int)(dData_40002dd0 * 3600) % 60) < 10)
			{
				g_MenuStringBuffer7[18] = ' ';
			}

			if (abs((int)dData_40002e08) < 10)
			{
				g_MenuStringBuffer8[5] = ' ';
			}
			if (abs((int)((dData_40002e08 - (int)dData_40002e08) * 60.0)) < 10)
			{
				g_MenuStringBuffer8[8] = ' ';
			}
			if (abs(((int)(dData_40002e08 * 3600.0)) % 60) < 10)
			{
				g_MenuStringBuffer8[11] = ' ';
			}
			//0x3b27c
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
			g_pcstrMenuLine8 = g_MenuStringBuffer8;
			
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
					g_pcstrMenuLine1 = "Slewing to Target       ";
					break;
				
				case 2:
					//0x3b34c
					g_pcstrMenuLine1 = "Find Target,Tracking    ";
					break;
				
				case 3:
					//0x3b360
					g_pcstrMenuLine1 = "Target Under Horizon    ";
					bData_40003432 = 1;
					break;
				
				case MENU_TRACKING_MODE_PAUSE: //4:
					//0x3b380
					g_pcstrMenuLine1 = "Pause                 ";
					break;
				
				case MENU_TRACKING_MODE_CANCEL: //5:
					//0x3b394
					g_pcstrMenuLine1 = "Cancel Operation          ";
					break;
				
				default:
					//0x3b3a8
					g_pcstrMenuLine1 = "                              ";
					break;
			}
			//0x3b3bc
			g_pcstrMenuLine2 = "                              ";
			
			sprintf(g_MenuStringBuffer3, "SAO:%d                          ",
				Data_40002ec4_SAONr);
			
			g_pcstrMenuLine3 = g_MenuStringBuffer3;
			g_pcstrMenuLine4 = "                              ";

			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break; //case 23017:
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
			//0x3b414
			g_pcstrMenuLine1 = "F1";
			g_pcstrMenuLine2 = "F2";
			g_pcstrMenuLine3 = "F3";
			g_pcstrMenuLine4 = "F4";
			g_pcstrMenuLine5 = "F5";
			g_pcstrMenuLine6 = "F6";
			g_pcstrMenuLine7 = "F7";
			g_pcstrMenuLine8 = "F8";
			g_pcstrMenuLine9 = "F9";
			g_pcstrMenuLine10 = "Select F? For Target ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			//->0x3d71c
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
			//0x3b4ac
			sprintf(g_MenuStringBuffer1, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                    ";
			g_pcstrMenuLine3 = "  Please Save Current";
			g_pcstrMenuLine4 = "Target & Input Target";
			g_pcstrMenuLine5 = "                    ";
			g_pcstrMenuLine6 = strCustomerObjectNameInput;
			g_pcstrMenuLine7 = strCustomerObjectRaAziInputForStoring;
			g_pcstrMenuLine8 = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
			//0x3b540
			sprintf(g_MenuStringBuffer1, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                    ";
			g_pcstrMenuLine3 = "  Please Save Current";
			g_pcstrMenuLine4 = "Target & Input Target";
			g_pcstrMenuLine5 = "                    ";
			g_pcstrMenuLine6 = strCustomerObjectNameInput;
			g_pcstrMenuLine7 = strCustomerObjectRaAziInputForStoring;
			g_pcstrMenuLine8 = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
			//0x3b5d4
			sprintf(g_MenuStringBuffer1, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                    ";
			g_pcstrMenuLine3 = "  Please Save Current";
			g_pcstrMenuLine4 = "Target & Input Target";
			g_pcstrMenuLine5 = "                    ";
			g_pcstrMenuLine6 = strCustomerObjectNameInput;
			g_pcstrMenuLine7 = strCustomerObjectRaAziInputForStoring;
			g_pcstrMenuLine8 = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;

		case MENU_CONTEXT_RA_INPUT: //29001: // "Object Rise/Set" -> "Input Ra Dec:"
			//0x3b668
			g_pcstrMenuLine1 = strInputRaDec; // "Input Ra Dec:"?
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strCustomerObjectRaAziInputForStoring; // "R.a: 19h52m12.0s"?
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strCustomerObjectDecAltInputForStoring; // "Dec:+90 00 00.0 "?
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DEC_INPUT: //29002
			//0x3b7d0
			g_pcstrMenuLine1 = strInputRaDec;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strCustomerObjectRaAziInputForStoring;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strCustomerObjectDecAltInputForStoring;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
				
		case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
			//0x3b850
			g_pcstrMenuLine1 = "F1";
			g_pcstrMenuLine2 = "F2";
			g_pcstrMenuLine3 = "F3";
			g_pcstrMenuLine4 = "F4";
			g_pcstrMenuLine5 = "F5";
			g_pcstrMenuLine6 = "F6";
			g_pcstrMenuLine7 = "F7";
			g_pcstrMenuLine8 = "F8";
			g_pcstrMenuLine9 = "F9";
			g_pcstrMenuLine10 = "Select F? For Target ";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
			//0x3b8e8
			sprintf(g_MenuStringBuffer1, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                    ";
			g_pcstrMenuLine3 = "  Please Save Current";
			g_pcstrMenuLine4 = "Target & Input Target";
			g_pcstrMenuLine5 = "                    ";
			g_pcstrMenuLine6 = strCustomerObjectNameInput;
			g_pcstrMenuLine7 = strCustomerObjectRaAziInputForStoring;
			g_pcstrMenuLine8 = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
			//0x3b97c
			sprintf(g_MenuStringBuffer1, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                    ";
			g_pcstrMenuLine3 = "  Please Save Current";
			g_pcstrMenuLine4 = "Target & Input Target";
			g_pcstrMenuLine5 = "                    ";
			g_pcstrMenuLine6 = strCustomerObjectNameInput;
			g_pcstrMenuLine7 = strCustomerObjectRaAziInputForStoring;
			g_pcstrMenuLine8 = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
			//0x3ba10
			sprintf(g_MenuStringBuffer1, "F%d                 ",
				bData_4000319a_SkyLandTargetId);
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
			g_pcstrMenuLine2 = "                    ";
			g_pcstrMenuLine3 = "  Please Save Current";
			g_pcstrMenuLine4 = "Target & Input Target";
			g_pcstrMenuLine5 = "                    ";
			g_pcstrMenuLine6 = strCustomerObjectNameInput;
			g_pcstrMenuLine7 = strCustomerObjectRaAziInputForStoring;
			g_pcstrMenuLine8 = strCustomerObjectDecAltInputForStoring;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJ_RISE_SET_TIMES: //31001:
			//0x3baa4
			get_solar_system_object_data(bData_40002eb5_SolarSystemObjectNr, 
				&fData_40002cd0_ObjectRightAscension, &fData_40002d18_ObjectDeclination);
		
			g_pcstrMenuLine1 = Data_4000314c_SolarSystemObjectName;
		
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
				
			sprintf(g_MenuStringBuffer3, "RiseTime:   %02dh%02dm",
				(int)dObjectRiseTime,
				(int)((dObjectRiseTime - (int)dObjectRiseTime) * 60));
			g_pcstrMenuLine3 = g_MenuStringBuffer3;

			sprintf(g_MenuStringBuffer5, "TransitTime:%02dh%02dm",
				(int)dObjectTransitTime,
				(int)((dObjectTransitTime - (int)dObjectTransitTime) * 60));
			g_pcstrMenuLine5 = g_MenuStringBuffer5;
				
			sprintf(g_MenuStringBuffer7, "SetTime:    %02dh%02dm",
				(int)dObjectSetTime,
				(int)((dObjectSetTime - (int)dObjectSetTime) * 60));
			g_pcstrMenuLine7 = g_MenuStringBuffer7;
				
			g_pcstrMenuLine2 = "                    ";
			g_pcstrMenuLine4 = "                    ";
			g_pcstrMenuLine6 = "                    ";
			g_pcstrMenuLine8 = "                    ";
				
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_RISE_SET_TIMES: //32001
			//0x3be30
			sprintf(g_MenuStringBuffer1, "RiseTime:   %02dh%02dm",
				(int)dObjectRiseTime,
				(int)((dObjectRiseTime - (int)dObjectRiseTime) * 60));		
			g_pcstrMenuLine1 = g_MenuStringBuffer1;
		
			sprintf(g_MenuStringBuffer2, "TransitTime:%02dh%02dm",
				(int)dObjectTransitTime,
				(int)((dObjectTransitTime - (int)dObjectTransitTime) * 60));
			g_pcstrMenuLine3 = g_MenuStringBuffer2;
				
			sprintf(g_MenuStringBuffer3, "SetTime:    %02dh%02dm",
				(int)dObjectSetTime,
				(int)((dObjectSetTime - (int)dObjectSetTime) * 60));
			g_pcstrMenuLine5 = g_MenuStringBuffer3;
				
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
				
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
		
			g_pcstrMenuLine1 = strEngCountingDown; // "Counting down:"?
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEngTimeRemain; // "Time remain:"
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strEngTimeRemain00000s; // "00000s"
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine8 = "";
			g_pcstrMenuLine7 = strEngStopBack; // "       Stop      Back"?
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
				
		case MENU_CONTEXT_TIMER_SET: //34001:
			//0x3c13c
			g_pcstrMenuLine1 = strEngSetTimer; // "Set timer:"?
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEng00000s; // "00000s"?
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = Data_400029b3;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strEngStartBack; // "      Start      Back"?
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_ALARM_INPUT: //35001:
			//0x3c1bc: Alarm start
			g_pcstrMenuLine1 = strEngInputTime;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEngAlarm21h34m23s;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine8 = "";
			g_pcstrMenuLine7 = strEngAlarmOnBack;
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case 35002:
			//0x3c23c: Alarm stop
			g_pcstrMenuLine1 = "";
			g_pcstrMenuLine2 = strEngCloseAlarm;
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine8 = "";
			g_pcstrMenuLine7 = strEngAlarmCloseBack;
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case 0x57E4B: //360011
			//0x3c2bc
			g_pcstrMenuLine1 = strEngTelescopeOneMX51;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = Data_4000239a; //"Scope:3'.3'"
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021
			//0x3c33c		
			g_pcstrMenuLine1 = strEyepieceMagnCaption; //->"Eyep. focal length:"?
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEyepieceFovMfInput;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strEyepieceFovSfInput;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strEyepieceMagnification;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022
			//0x3c41c
			g_pcstrMenuLine1 = strEyepieceMagnCaption;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEyepieceFovMfInput;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strEyepieceFovSfInput;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strEyepieceMagnification;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021
			//0x3c49c
		case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022
			//0x3c4a4
		case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023
			//0x3c4a8
			g_pcstrMenuLine1 = strEyepieceFovCaption; // "Eyep. focal length:"
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEyepieceFovMfInput; // "MF:1893mm"
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strEyepieceFovSfInput; // "SF:43mm"
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strEyepieceFovInput; // "E-FOV:001°00'"
			g_pcstrMenuLine8 = strEyepieceFOV; // "         FOV:0.02272°"
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case 0x57E57: //360023
			//0x3c524
			sprintf(Data_4000248c, "MultiplyM:%d", fEyepieceMagnification);
		
			g_pcstrMenuLine1 = strEyepieceMagnCaption;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEyepieceFovMfInput;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strEyepieceFovSfInput;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = strEyepieceMagnification;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL: //380011:
			//0x3c5cc
			g_pcstrMenuLine1 = strEngBackgroundLight;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strEngPressUpDownKey;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = Data_40002aee;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = Data_40002aef;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
				
		case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
			//0x3c64c
			g_pcstrMenuLine1 = "Date and Time Set: ";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = Data_400037ec;
			g_pcstrMenuLine4 = "           YYYY-MM-DD";
			g_pcstrMenuLine5 = Data_40003150;
			g_pcstrMenuLine6 = "         HH:MM:SS";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_ON: //42001:
			//0x3c6cc
			g_pcstrMenuLine1 = Data_40002b70; //"daylight saving"
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = Data_40002b80; //"status:on"
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = Data_40002b8a;
		
			if (bData_40002f1e_SetupLocalData == 1)
			{
				g_pcstrMenuLine6 = "hit direction key!";
			}
			else
			{
				g_pcstrMenuLine6 = "Restart & Change!";
			}
			g_pcstrMenuLine7 = Data_40002b8b;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_DAYLIGHT_SAVING_OFF: //42002:
			//3c76c
			g_pcstrMenuLine1 = Data_40002ba5; //"Daylight saving"
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = Data_40002bb5; //"status:off"
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = Data_40002bc0;
		
			if (bData_40002f1e_SetupLocalData == 1)
			{
				g_pcstrMenuLine6 = "hit direction key!";
			}
			else
			{
				g_pcstrMenuLine6 = "Restart & Change!";
			}
			g_pcstrMenuLine7 = Data_40002bc1;
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_COUNTRY_CITY_SELECTION: //43011:
			//0x3c8f4: Country & City
			flash_get_site_data((unsigned short)(wData_40003250 + wData_40003252), &Data_40003f1c_FlashSiteData);

			if (Data_40003f1c_FlashSiteData.fLongitude >= 0)
			{
				//3c92c
				sprintf(g_MenuStringBuffer5, "     Lon:E%03d %02d          ",
					abs((int)Data_40003f1c_FlashSiteData.fLongitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLongitude - (int)Data_40003f1c_FlashSiteData.fLongitude) * 60)));
			}
			else
			{
				//0x3c9bc
				sprintf(g_MenuStringBuffer5, "     Lon:W%03d %02d         ",
					abs((int)Data_40003f1c_FlashSiteData.fLongitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLongitude - (int)Data_40003f1c_FlashSiteData.fLongitude) * 60)));
			}
			//0x3ca48
			if (abs((int)Data_40003f1c_FlashSiteData.fLongitude) < 100)
			{
				g_MenuStringBuffer5[10] = ' ';
			}
			if (abs((int)Data_40003f1c_FlashSiteData.fLongitude) < 10)
			{
				g_MenuStringBuffer5[11] = ' ';
			}
			if (abs((int)((Data_40003f1c_FlashSiteData.fLongitude - (int)Data_40003f1c_FlashSiteData.fLongitude) * 60)) < 10)
			{
				g_MenuStringBuffer5[14] = ' ';
			}
			//0x3cb14
			if (Data_40003f1c_FlashSiteData.fLatitude >= 0)
			{
				//3cb28
				sprintf(g_MenuStringBuffer7, "     Lat:N %02d %02d          ",
					abs((int)Data_40003f1c_FlashSiteData.fLatitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLatitude - (int)Data_40003f1c_FlashSiteData.fLatitude) * 60)));
			}
			else
			{
				//0x3cbb8
				sprintf(g_MenuStringBuffer7, "     Lat:S %02d %02d         ",
					abs((int)Data_40003f1c_FlashSiteData.fLatitude),
					abs((int)((Data_40003f1c_FlashSiteData.fLatitude - (int)Data_40003f1c_FlashSiteData.fLatitude) * 60)));
			}
			//0x3cc44
			if (abs((int)Data_40003f1c_FlashSiteData.fLatitude) < 10)
			{
				g_MenuStringBuffer7[11] = ' ';
			}
			if (abs((int)((Data_40003f1c_FlashSiteData.fLatitude - (int)Data_40003f1c_FlashSiteData.fLatitude) * 60)) < 10)
			{
				g_MenuStringBuffer7[14] = ' ';
			}
			//0x3cd74
			if (Data_40003f1c_FlashSiteData.Zone > 0)
			{
				//3cd84
				sprintf(g_MenuStringBuffer8, "    Zone:E%d   ",
					abs(Data_40003f1c_FlashSiteData.Zone));
			}
			else if (Data_40003f1c_FlashSiteData.Zone < 0)
			{
				//0x3cdb4
				sprintf(g_MenuStringBuffer8, "    Zone:W%d    ",
					abs(Data_40003f1c_FlashSiteData.Zone));
			}
			else
			{
				//0x3cdf4
				sprintf(g_MenuStringBuffer8, "    Zone:%d    ",
					abs(Data_40003f1c_FlashSiteData.Zone));
			}
			//0x3ce20
			g_pcstrMenuLine1 = Data_40003f1c_FlashSiteData.cCountry;
			g_pcstrMenuLine2 = Data_40003f1c_FlashSiteData.cCity;
			g_pcstrMenuLine3 = g_MenuStringBuffer5;
			g_pcstrMenuLine4 = g_MenuStringBuffer7;
			g_pcstrMenuLine5 = g_MenuStringBuffer8;
			g_pcstrMenuLine6 = "                     ";
			g_pcstrMenuLine7 = "up&down key: country!";
			g_pcstrMenuLine8 = "left&right key: city!";
			
			bData_4000316e_FocusLineOn8LineDisplay = 0;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x3ce9c: "Custom Site"
			g_pcstrMenuLine1 = "Please Input Data: ";
			//g_pcstrMenuLine2 = ""; //?????
			g_pcstrMenuLine3 = strCustomSiteName; //" Name:"
			g_pcstrMenuLine4 = strCustomSiteLongitude; //"  Lon:"
			g_pcstrMenuLine5 = strCustomSiteLatitude; //"  Lat:"
			g_pcstrMenuLine6 = strCustomSiteTimezone; //" Zone:"
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_SKY_TARGET: //45001
			//0x3cf10
			g_pcstrMenuLine1 = "Object Mode:";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strSkyTarget;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strLandTarget;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_LAND_TARGET: //45002
			//0x3cf90
			g_pcstrMenuLine1 = "Object Mode:";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strSkyTarget;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strLandTarget;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_MOUNT_AZ: //46001:
			//0x3d010
			g_pcstrMenuLine1 = "Telescope Mount:";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strAltTelescope;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strEquTelescope;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_MOUNT_EQU: //46002:
			//0x3d154
			g_pcstrMenuLine1 = "Telescope Mount:";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = strAltTelescope;
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = strEquTelescope;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
			
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP: //47011: // "Telescope Mount" -> "Please setup OTA zero"
			//0x3d1d4
			g_pcstrMenuLine1 = strEngPleaseSetupOtaZero; // "Please setup OTA zero"
			g_pcstrMenuLine3 = Data_400028d7; // "Azi:000°"
			g_pcstrMenuLine5 = Data_400028e1; // "Alt: 00°"
			g_pcstrMenuLine4 = "        Range:0-360";
			g_pcstrMenuLine6 = "        Range:0-90";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			if (bData_400032a4_OTAZeroDataErrorCount > 0)
			{
				bData_400032a4_OTAZeroDataErrorCount--;
				g_pcstrMenuLine6 = "                                ";
				g_pcstrMenuLine7 = Data_400028eb;
			}
			else
			{
				g_pcstrMenuLine6 = "                                        ";
				g_pcstrMenuLine7 = "                                      ";
			}

			g_pcstrMenuLine2	= "                              ";
			g_pcstrMenuLine4 = "          Range:0-360";
			g_pcstrMenuLine6 = "          Range:0-90";
			
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_OTA_ZERO_SETUP_RESTART: //47041:
			//0x3d2c4
			g_pcstrMenuLine1 = strEngPleaseSetupOtaZero; // "Please setup OTA zero"
			g_pcstrMenuLine3 = Data_400028d7;
			g_pcstrMenuLine5 = Data_400028e1;
			g_pcstrMenuLine7 = Data_40002901;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine6 = "                                                       ";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;

#if 0
		case MENU_CONTEXT_ENGLISH: //49001
			//0x3d344
			g_pcstrMenuLine1 = strEngEnglish;
			g_pcstrMenuLine2 = strEngGerman;
			g_pcstrMenuLine3 = strEngFrench;
			g_pcstrMenuLine4 = strEngItalian;
			g_pcstrMenuLine5 = strEngSpanish;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
#else
		case MENU_CONTEXT_ENGLISH: //49001
			//0x3d344
			g_pcstrMenuLine1 = strEngEnglish;
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = "";
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";

			bData_4000316e_FocusLineOn8LineDisplay = 1;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
#endif
		
#if 0
		case MENU_CONTEXT_GERMAN: //49002
			//0x3d3c0
			g_pcstrMenuLine1 = strEngEnglish;
			g_pcstrMenuLine2 = strEngGerman;
			g_pcstrMenuLine3 = strEngFrench;
			g_pcstrMenuLine4 = strEngItalian;
			g_pcstrMenuLine5 = strEngSpanish;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 2;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_FRENCH: //49003
			//0x3d440
			g_pcstrMenuLine1 = strEngEnglish;
			g_pcstrMenuLine2 = strEngGerman;
			g_pcstrMenuLine3 = strEngFrench;
			g_pcstrMenuLine4 = strEngItalian;
			g_pcstrMenuLine5 = strEngSpanish;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 3;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_ITALIAN: //49004
			//0x3d594
			g_pcstrMenuLine1 = strEngEnglish;
			g_pcstrMenuLine2 = strEngGerman;
			g_pcstrMenuLine3 = strEngFrench;
			g_pcstrMenuLine4 = strEngItalian;
			g_pcstrMenuLine5 = strEngSpanish;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 4;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		case MENU_CONTEXT_SPANISH: //49005
			//0x3d614
			g_pcstrMenuLine1 = strEngEnglish;
			g_pcstrMenuLine2 = strEngGerman;
			g_pcstrMenuLine3 = strEngFrench;
			g_pcstrMenuLine4 = strEngItalian;
			g_pcstrMenuLine5 = strEngSpanish;
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 5;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
#endif
		
		case MENU_CONTEXT_TRACKING_RATE_INPUT: //48001
			//0x3d694
			g_pcstrMenuLine1 = "Input Treaking Speed:";
			g_pcstrMenuLine2 = "";
			g_pcstrMenuLine3 = "";
			g_pcstrMenuLine4 = strTrackingRateCustDisplay;
			g_pcstrMenuLine5 = "";
			g_pcstrMenuLine6 = "";
			g_pcstrMenuLine7 = "";
			g_pcstrMenuLine8 = "";
		
			bData_4000316e_FocusLineOn8LineDisplay = 10;
			bData_40003197_DisplayLinesPerMenuLine = 1;
			break;
		
		default:
			//0x3d714			
			break;
	}
}

