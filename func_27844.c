
extern unsigned char func_57b8(unsigned char* a, int* b, void* c);
extern void func_240e8(unsigned char a, int b);
extern void func_24574(void);
extern void func_2575c(void);


/* 27844 - todo */
void func_27844(void)
{
	func_2575c();
	
	switch (Data_40002c64)
	{
		case 0:
			//0x28030
			func_24574();
		
			bData_4000316e = 10;
			bData_40003197 = 1;
			//->3d71c
			break;
		
		case 2:
			//0x28054
			Data_40003364 = Data_400030c0;
			Data_4000336c = Data_400030c4;
			Data_40003374 = Data_400030c8;
		
			func_23130();
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
					
					Data_40004ad8.dData_0 = Data_40004128.dData_48;
					Data_40004ad8.dData_8 = Data_40004128.dData_56;
					Data_40004ae8.dData_0 = Data_40003f50.fData_12;
					Data_40004ae8.dData_8 = Data_40003f50.fData_16;
					fData_40002cd0_ObjectRightAscension = Data_40003f50.fData_12;
					fData_40002d18_ObjectDeclination = Data_40003f50.fData_16;
					
					func_8ba4(Data_40004ad8, Data_40004ae8, 
						Data_40004128.Data_40, Data_40004128.bData_44, Data_40004b08);
					//284f8
					#if 0
					r4 = (int)(Data_40004b08[1] * 3600.0) % 60;
					r6 = (int)((Data_40004b08[1] - (int)(Data_40004b08[1])) * 60.0);
					r5 = (int)(Data_40004b08[1]);
					
					sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
						r5, r6, r4);
					#else
					sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
						(int)(Data_40004b08[1]), 
						(int)((Data_40004b08[1] - (int)(Data_40004b08[1])) * 60.0), 
						(int)(Data_40004b08[1] * 3600.0) % 60);
					#endif
						
					if (Data_40004b08[3] > 0)
					{
						//285d0
						#if 0
						r4 = (int)(Data_40004b08[3] * 3600.0) % 60;
						r5 = (int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0);
						r6 = (int)Data_40004b08[3];
						
						sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
							(r6 >= 0)? r6: -r6, (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
						#else
						sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
							abs((int)Data_40004b08[3]), 
							abs((int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0)), 
							abs((int)(Data_40004b08[3] * 3600.0) % 60));
						#endif
						//->2885c
					}
					else
					{
						//286cc
						#if 0
						r4 = (int)(Data_40004b08[3] * 3600.0) % 60;
						r5 = (int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0);
						r6 = (int)Data_40004b08[3];
						
						sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
							(r6 >= 0)? r6: -r6, (r5 >= 0)? r5: -r5, (r4 >= 0)? r4: -r4);
						#else
						sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
							abs((int)Data_40004b08[3]), 
							abs((int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0)), 
							abs((int)(Data_40004b08[3] * 3600.0) % 60));
						#endif
					}
					//2885c
					if ((int)(Data_40004b08[1]) < 100)
					{
						Data_40003ffd[11] = ' ';
					}
					
					if ((int)(Data_40004b08[1]) < 10)
					{
						Data_40003ffd[12] = ' ';
					}
					//288a4
					if ((int)((Data_40004b08[1] - (int)Data_40004b08[1]) * 60.0) < 10)
					{
						Data_40003ffd[15] = ' ';
					}
					//28910
					if (((int)(Data_40004b08[1] * 3600.0) % 60) < 10)
					{
						Data_40003ffd[18] = ' ';
					}
					//28954
					if (abs((int)Data_40004b08[3]) < 10)
					{
						Data_40004012[5] = ' ';
					}
					//2898c
					if (abs((int)((Data_40004b08[3] - (int)Data_40004b08[3]) * 60.0)) < 10)
					{
						Data_40004012[8] = ' ';
					}
					//28a0c
					if (abs(((int)(Data_40004b08[3] * 3600.0)) % 60) < 10)
					{
						Data_40004012[11] = ' ';
					}
					//28a64
					Data_40003370 = Data_40003ffd;
					Data_40003374 = Data_40004012;
					
					#if 0
					r4 = (int)(fData_40002cd0_ObjectRightAscension * 3600.0) % 60;
					r5 = (int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60.0);
					r9 = (int)fData_40002cd0_ObjectRightAscension;
					#else
					sprintf(Data_40004027, "R.a: %02dh%02dm%02ds         ",
						(int)fData_40002cd0_ObjectRightAscension,
						(int)((fData_40002cd0_ObjectRightAscension - (int)fData_40002cd0_ObjectRightAscension) * 60),
						(int)(fData_40002cd0_ObjectRightAscension * 3600) % 60);
					#endif
						
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
						#if 0
						r4 = ((int)(fData_40002d18_ObjectDeclination * 3600) % 60);
						r6 = (int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60);
						r5 = (int)fData_40002d18_ObjectDeclination;
						#endif
						sprintf(Data_4000403c, "Dec:+%02d %02d %02d      ",
							abs((int)fData_40002d18_ObjectDeclination),
							abs((int)((fData_40002d18_ObjectDeclination - (int)(fData_40002d18_ObjectDeclination)) * 60)),
							abs(((int)(fData_40002d18_ObjectDeclination * 3600) % 60)));
						//->28dc4
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

					Data_40004b08[1] = Data_40003f64.fData_12;
					Data_40004b08[3] = Data_40003f64.fData_16;
										
					sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
						(int)Data_40004b08[1],
						(int)((Data_40004b08[1] - (int)Data_40004b08[1]) * 60.0),
						(int)(Data_40004b08[1] * 3600.0) % 60);
					//28fe8
					if (Data_40004b08[3] >= 0)
					{
						//29004
						sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
							abs((int)Data_40004b08[3]),
							abs((int)((Data_40004b08[3] - (int)Data_40004b08[3]) * 60.0)),
							abs((int)(Data_40004b08[3] * 3600.0) % 60));
					}
					else
					{
						//2915c
						sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
							abs((int)Data_40004b08[3]),
							abs((int)((Data_40004b08[3] - (int)Data_40004b08[3]) * 60.0)),
							abs((int)(Data_40004b08[3] * 3600.0) % 60));
					}
					//29254
					if ((int)Data_40004b08[1] < 100)
					{
						Data_40003ffd[11] = ' ';
					}
					//29278
					if ((int)Data_40004b08[1] < 10)
					{
						Data_40003ffd[12] = ' ';
					}
					//2929c
					if ((int)((Data_40004b08[1] - (int)Data_40004b08[1]) * 60.0) < 10)
					{
						Data_40003ffd[15] = ' ';
					}
					//29308
					if (((int)(Data_40004b08[1] * 3600.0) % 60) < 10)
					{
						Data_40003ffd[18] = ' ';
					}
					//2934c
					if (abs((int)Data_40004b08[3]) < 10)
					{
						Data_40004012[5] = ' ';
					}
					//29384
					if (abs((int)((Data_40004b08[3] - (int)Data_40004b08[3]) * 60.0)) < 10)
					{
						Data_40004012[8] = ' ';
					}
					//29404
					if (abs(((int)(Data_40004b08[3] * 3600.0)) % 60) < 10)
					{
						Data_40004012[11] = ' ';
					}
					//2945c
					Data_40003370 = Data_40003ffd;
					Data_40003374 = Data_40004012;
					
					dData_40002dd0 = dData_40002dc0;
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
			bData_4000316e = 0;
			bData_40003197 = 1;
			//->3d71c
			break;
		
		case 1:
			//0x29994
			bData_40002f14_RecentTargetCount = func_57b8(Data_40002f15, Data_4000359c, &Data_400035bc);
			
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
					bData_40002f0d = Data_40002f15[7];
					Data_40002f10 = Data_4000359c[7];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
					bData_40002f0d = Data_40002f15[6];
					Data_40002f10 = Data_4000359c[6];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
					bData_40002f0d = Data_40002f15[5];
					Data_40002f10 = Data_4000359c[5];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
					bData_40002f0d = Data_40002f15[4];
					Data_40002f10 = Data_4000359c[4];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
					bData_40002f0d = Data_40002f15[3];
					Data_40002f10 = Data_4000359c[3];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
					bData_40002f0d = Data_40002f15[2];
					Data_40002f10 = Data_4000359c[2];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
					bData_40002f0d = Data_40002f15[1];
					Data_40002f10 = Data_4000359c[1];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
					bData_40002f0d = Data_40002f15[0];
					Data_40002f10 = Data_4000359c[0];
				
					func_240e8(bData_40002f0d, Data_40002f10);
				
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
		
		case 0x3e8: //1000
			//0x2a100
			break;
		
		case 3:
			//0x2c658
			break;
		
		case 0xc9: //201
			//0x3b414
			break;
		
		case 0xca: //202
			//0x3b850
			break;
		
		case 0xcb: //203
			//0x3b4ac
			break;
		
		case 0xcc: //204:
			//0x3b540
			break;
		
		case 0xcd: //205
			//0x3b5d4
			break;
		
		case 0xce: //206
			//0x3b8e8
			break;
		
		case 0xcf: //207
			//0x3b97c
			break;
		
		case 0xd0: //208
			//0x3ba10
			break;
		
		case 0x44c: //1100
			//0x2a49c
			break;
		
		case 0x4b0: //1200
			//0x2a4a4
			break;
		
		case 0x514: //1300
			//0x2a4a8
			break;
		
		case 1400:
			//0x2a4ac
			break;
		
		case 1401: 
			//0x2c6e0
			break;
		
		case 1402:
			//0x2c760
			break;
		
		case 0x57b: //1403
			//0x2c7dc
			break;
		
		case 0x5DC: //1500
			//0x2a4b0
			break;
		
		case 0x640: //1600
			//0x2a4b4
			break;
		
		case 0x6A4: //1700
			//0x2a4b8
			break;
		
		case 0x7D0: //2000
			//0x2a220
			break;
		
		case 0x834: //2100
			//0x2a500
			break;
		
		case 0x898: //2200
			//0x2a508
			break;
		
		case 0x8FC: //2300
			//0x2a50c
			break;
		
		case 0x960: //2400
			//0x2a510
			break;
		
		case 0x9C4: //2500
			//0x2a514
			break;
		
		case 0x83E: //2110
			//0x2a528
			break;
		
		case 0x848: //2120
			//0x2a52c
			break;
		
		case 0x852: //2130
			//0x2a530
			break;
		
		case 0x899: //2201
			//0x2a650
			break;
		
		case 0x89A: //2202
			//0x2a658
			break;
		
		case 0x89B: //2203
			//0x2a65c
			break;

		case 0x89C: //2204
			//0x2a660
			break;
		
		case 0x89D: //2205
			//0x2a664
			break;

		case 0x89E: //2206
			//0x2a668
			break;
		
		case 0x89F: //2207
			//0x2a66c
			break;
		
		case 0x8A0: //2208
			//0x2a670
			break;
		
		case 0x8A1: //2209
			//0x2a674
			break;
		
		case 0x8FD: //2301
			//0x2a6a8
			break;
		
		case 0x8FE: //2302
			//0x2a6b0
			break;
		
		case 0x8ff: //2303
			//0x2a6b4
			break;
		
		case 0x900: //2304
			//0x2a6b8
			break;
		
		case 2305: 
			//0x2a6bc
			break;
		
		case 2306:
			//0x2a6c0
			break;
		
		case 2307:
			//0x2a6c4
			break;
		
		case 2308:
			//0x2a6c8
			break;
		
		case 0x9c5: //2501
			//0x2a6f8
			break;
		
		case 0x9c6: //2502
			//0x2a780
			break;
		
		case 0x9C7: //2503
			//0x2a80c
			break;
		
		case 0xA28: //2600
			//0x2a518
			break;
		
		case 0xA8C: //2700
			//0x2a51c
			break;
				
		case 0xAF0: //2800
			//0x2a520
			break;
		
		case 0xAF1: //2801
			//0x2a898
			break;
		
		case 0xAF2: //2802
			//0x2a924
			break;
		
		case 0xAF3: //2803
			//0x2aa2c
			break;
		
		case 0xAF4: //2804
			//0x2aabc
			break;
		
		case 0xB54: //2900
			//0x2a524
			break;
		
		case 0xBB8: //3000
			//0x2a2f4
			break;
		
		case 0xC1C: //3100
			//0x2a578
			break;
		
		case 0xC80: //3200
			//0x2a580
			break;
		
		case 0xCE4: //3300
			//0x2a584
			break;
		
		case 0xD48: //3400
			//0x2a588
			break;
		
		case 0xDAC: //3500
			//0x2a58c
			break;
		
		case 0xE10: //3600
			//0x2a590
			break;
		
		case 0xE11: //3601
			//0x2acec
			break;

		case 0xE12: //3602
			//0x2ad70
			break;
		
		case 0xE74: //3700
			//0x2a594
			break;
		
		case 0xED8: //3800
			//0x2a598
			break;
		
		case 0xED9: //3801
			//0x2adf8
			break;
		
		case 0xEDA: //3802
			//0x2ae7c
			break;

		case 0xF3C: //3900
			//0x2a59c
			break;
		
		case 0xFA0: //4000
			//0x2a3c8
			break;
		
		case 0x1004: //4100
			//0x2a5e4
			break;
		
		case 0x1068: //4200
			//0x2a5ec
			break;
		
		case 0x10CC: //4300
			//0x2a5f0
			break;
		
		case 0x10CD: //4301
			//0x2af04
			break;
		
		case 0x10CE: //4302
			//0x2af88
			break;
		
		case 0x1130: //4400
			//0x2a5f4
			break;
		
		case 0x1194: //4500
			//0x2a5f8
			break;
		
		case 0x11F8: //4600
			//0x2a5fc
			break;
		
		case 0x125C: //4700
			//0x2a600
			break;
		
		case 0x12C0: //4800
			//0x2a604
			break;
		
		case 0x12c1: //4801
			//0x2b2a4
			break;
		
		case 0x12c2: //4802
			//0x2b334
			break;
		
		case 0x12c3: //4803
			//0x2b3c8
			break;
		
		case 0x12C4: //4804
			//0x2b45c
			break;
		
		case 0x12C5: //4805
			//0x2b4f0
			break;
		
		case 0x1324: //4900
			//0x2a608
			break;
		
		case 0x2B5D: //11101
			//0x2cb60
			break;
		
		case 0x2B5E: //11102
			//0x2cad0
			break;
		
		case 0x2B5F: //11103
			//0x2cbf0
			break;
		
		case 0x2B60: //11104
			//0x2cc80
			break;
		
		case 0x2B61: //11105
			//0x2cdc0
			break;
		
		case 0x2BC1: //11201
			//0x2cf00
			break;
		
		case 0x2BC2: //11202
			//0x2ce70
			break;
		
		case 0x2BC3: //11203
			//0x2cf90
			break;
		
		case 0x2BC4: //11204
			//0x2d020
			break;

		case 0x2BC5: //11205
			//0x2d100
			break;
		
		case 0x2EE1: //12001
			//0x2b68c
			break;
		
		case 0x4651: //18001
			//0x2c85c
			break;
		
		case 0x526D: //21101
			//0x2ab4c
			break;
		
		case 0x526E: //21102
			//0x2abd4
			break;
		
		case 0x526F: //21103
			//0x2ac60
			break;
		
		case 0x55F1: //22001
			//0x2d1b0
			break;
		
		case 0x55FC: //22012
			//0x2a678
			break;
		
		case 0x565F: //22111
			//0x2dd24
			break;
		
		case 0x5660: //22112
			//0x2db70
			break;
		
		case 0x59DA: //23002
			//0x31ef0
			break;
	
		case 0x59DB: //23003
			//0x33750
			break;
		
		case 0x59DC: //23004
			//0x350c0
			break;
		
		case 0x59DD: //23005
			//0x36a10
			break;
		
		case 0x59DE: //23006
			//0x382a0
			break;
		
		case 0x59DF: //23007
			//0x39b90
			break;
		
		case 0x59E4: //23012
			//0x31c44
			break;
		
		case 0x59E5: //23013
			//0x34278
			break;
		
		case 0x59E6: //23014
			//0x35bb4
			break;
		
		case 0x59E7: //23015
			//0x374a0
			break;
		
		case 0x59E8: //23016
			//0x38d80
			break;
		
		case 0x59E9: //23017
			//0x3a618
			flash_get_sao_data(Data_40002ec4_SAONr, &Data_40003358_SAORecord);
		
			fData_40002cd0_ObjectRightAscension = Data_40003358_SAORecord.fData_0;
			fData_40002d18_ObjectDeclination = Data_40003358_SAORecord.fData_4;
			Data_40004ad8.dData_0 = Data_40004128.dData_48;
			Data_40004ad8.dData_8 = Data_40004128.dData_56;
			Data_40004ae8.dData_0 = fData_40002cd0_ObjectRightAscension;
			Data_40004ae8.dData_8 = fData_40002d18_ObjectDeclination;

			func_8ba4(Data_40004ad8, Data_40004ae8, 
				Data_40004128.Data_40, Data_40004128.bData_44, Data_40004b08);

			sprintf(Data_40003ffd, "OBJ    Azi:%03d %02d %02d                ",
				(int)(Data_40004b08[1]), 
				(int)((Data_40004b08[1] - (int)(Data_40004b08[1])) * 60.0), 
				(int)(Data_40004b08[1] * 3600.0) % 60);

			if (Data_40004b08[3] >= 0)
			{
				//3a7ac
				sprintf(Data_40004012, "Alt:+%02d %02d %02d               ",
					abs((int)Data_40004b08[3]), 
					abs((int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0)), 
					abs((int)(Data_40004b08[3] * 3600.0) % 60));
				//->3a9ac
			}
			else
			{
				//3a8a8
				sprintf(Data_40004012, "Alt:-%02d %02d %02d               ",
					abs((int)Data_40004b08[3]), 
					abs((int)((Data_40004b08[3] - (int)(Data_40004b08[3])) * 60.0)), 
					abs((int)(Data_40004b08[3] * 3600.0) % 60));
					
				bData_40002e8a = 3;
			}
			//3a9ac
			if ((int)(Data_40004b08[1]) < 100)
			{
				Data_40003ffd[11] = ' ';
			}
			//3a9d0
			if ((int)(Data_40004b08[1]) < 10)
			{
				Data_40003ffd[12] = ' ';
			}
			//3a9f4
			if ((int)((Data_40004b08[1] - (int)Data_40004b08[1]) * 60.0) < 10)
			{
				Data_40003ffd[15] = ' ';
			}
			//3aa60
			if (((int)(Data_40004b08[1] * 3600.0) % 60) < 10)
			{
				Data_40003ffd[18] = ' ';
			}
			//3aaa4
			if (abs((int)Data_40004b08[3]) < 10)
			{
				Data_40004012[5] = ' ';
			}
			//3aadc
			if (abs((int)((Data_40004b08[3] - (int)Data_40004b08[3]) * 60.0)) < 10)
			{
				Data_40004012[8] = ' ';
			}
			//3ab5c
			if (abs(((int)(Data_40004b08[3] * 3600.0)) % 60) < 10)
			{
				Data_40004012[11] = ' ';
			}
			//3abb4
			
			//TODO
			
			break; //case 23017:
		
		case 0x59EE: //23022
			//0x32940
			break;
		
		case 0x5DC1: //24001
			//0x2ea8c
			break;
		
		case 0x5DC2: //24002
			//0x2f624
			break;
		
		case 0x61A9: //25001
			//0x30404
			break;
		
		case 0x61AA: //25002
			//0x30ea8
			break;
		
		case 0x7149: //29001
			//0x3b668
			break;
		
		case 0x714A: //29002
			//0x3b7d0
			break;
		
		case 0x7919: //31001
			//0x3baa4
			break;
		
		case 0x7D01: //32001
			//0x3be30
			break;
		
		case 0x80E9: //33001
			//0x3c088
			break;
		
		case 0x84D1: //34001
			//0x3c13c
			break;
		
		case 0x84D2: //34002
			//0x3c0a8
			break;
		
		case 0x88B9: //35001
			//0x3c1bc
			break;
		
		case 0x88BA: //35002
			//0x3c23c
			break;
		
		case 0xA029: //41001
			//0x3c64c
			break;
		
		case 0xA411: //42001
			//0x3c6cc
			break;
		
		case 0xA803: //43011
			//0x3c8f4
			break;
		
		case 0xA80D: //43021
			//0x2b010
			break;
		
		case 0xA80E: //43022
			//0x2b09c
			break;
		
		case 0xA80F: //43023
			//0x2b184
			break;
		
		case 0xA810: //43024
			//0x2b214
			break;
		
		case 0xAFC9: //45001
			//0x3cf10
			break;
		
		case 0xAFCA: //45002
			//0x3cf90
			break;
		
		case 0xB3B1: //46001
			//0x3d010
			break;
		
		case 0xB3B2: //46002
			//0x3d154
			break;
		
		case 0xB7A3: //47011
			//0x3d1d4
			break;
		
		case 0xB7BD: //47037
			//0x3d2c4
			break;
		
		case 0xBB81: //48001
			//0x3d694
			break;
		
		case 0xBBB3: //48051
			//0x2b584
			break;
		
		case 0xBBB4: //48052
			//0x2b600
			break;
		
		case 0xBBB5: //48053
			//0x2b614
			break;
		
		case 0xBBB6: //48054
			//0x2b628
			break;
		
		case 0xBBB7: //48055
			//0x2b63c
			break;
		
		case 0xBBB8: //48056
			//0x2b650
			break;
		
		case 0xBBB9: //
			//0x2b664
			break;
		
		case 0xBBBA: //
			//0x2b678
			break;
		
		case 0xBF69: //49001
			//0x3d344
			break;
		
		case 0xBF6A: //49002
			//0x3d3c0
			break;
		
		case 0xBF6B: //49003
			//0x3d440
			break;
		
		case 0xBF6C: //49004
			//0x3d594
			break;
		
		case 0xBF6D: //49005
			//0x3d614
			break;
		
		case 0x57E4B: //360011
			//0x3c2bc
			break;
		
		case 0x57E55: //360021
			//0x3c33c		
			break;
		
		case 0x57E56: //360022
			//0x3c41c
			break;
		
		case 0x57E57: //360023
			//0x3c524
			break;
		
		case 0x5A565: //370021
			//0x3c49c
			break;
		
		case 0x5A566: //370022
			//0x3c4a4
			break;
		
		case 0x5A567: //370023
			//0x3c4a8
			break;
		
		case 0x5CC6B: //380011
			//0x3c5cc
			break;
		
		default:
			//0x3d714
			break;
	}
}

