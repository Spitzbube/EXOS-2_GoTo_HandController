
/* 3d72c - todo */
void DisplayScreenItems(void)
{
	PrepareScreenItems();
	
	switch (bData_40003197_DisplayLinesPerMenuLine)
	{
		case 1:
			//0x3d750
			Data_4000318c = Data_40002c64_MenuContextId;
			if (Data_4000318c != Data_40003190)
			{
				//3d77c
				lcd_display_clear();				
				Data_40003190 = Data_4000318c;
			}
			//3d790
			switch (Data_40002c64_MenuContextId)
			{
				case MENU_CONTEXT_MAIN: //0:
					//0x3da9c
					if (bSystemInitialized == 1)
					{
						DisplayMainScreen();
					}
					//->4684c
					break;
				
				case MENU_CONTEXT_RECENT_TARGETS: //1:
					//0x3dab8
					if (bData_40002f14_RecentTargetCount != 0)
					{
						//3dacc
						switch (bData_4000316e_FocusLineOn8LineDisplay)
						{
							case 1:
								//0x3db04
								lcd_display_string(1, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(1, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 2:
								//0x3dd8c
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(1, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(2, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 3:
								//0x3e014
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(1, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(1, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 4:
								//0x3e29c
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(1, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(1, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 5:
								//0x3e524
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(1, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(1, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 6:
								//0x3e7ac
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(1, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(1, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 7:
								//0x3ea90
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(1, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(1, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 8:
								//0x3ed18
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(1, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(1, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;

							default:
								//0x3efa0
								break;
						}
					}
					else
					{
						//0x3efac
						lcd_display_string(0, 1, 1, 2, Data_40003380);
						lcd_display_string(0, 2, 1, 2, Data_40003384);
						lcd_display_string(0, 3, 1, 2, Data_40003388);
						lcd_display_string(0, 4, 1, 2, Data_4000338c);
						lcd_display_string(0, 5, 1, 2, Data_40003390);
						lcd_display_string(0, 6, 1, 2, Data_40003394);
						lcd_display_string(0, 7, 1, 2, Data_40003398);
						lcd_display_string(0, 8, 1, 2, Data_4000339c);
						
						lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
						lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
						lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
						lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
						lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
						lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
						lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
						lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					}
					//->0x4684c
					break;
				
				case 102:
					//0x3f230
					if (((Data_40003f64.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 1)) ||
						((Data_40003f50.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 0)))
					{
						//0x3f274
						lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
						lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
						lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
						lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
						lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
						lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
						lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
						lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);						
						//->0x3f8cc
					}
					else
					{
						//0x3f3f8
						switch (bData_40002e79_SkyLandTargetSeletion)
						{
							case 0:
								//0x3f414
								lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
								lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
								//->0x3f8c8
								break;
							
							case 1:
								//0x3f650
								lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
								lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
								break;
						}
					}
					//->0x4684c
					break;
				
				case 2:
					//0x3f8d0
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
				
					beep1(1);
					delay_loop(200);
					beep1(1);
					delay_loop(200);
					beep1(1);
					delay_loop(200);
					Data_40002c64_MenuContextId = 0;
					//->0x4684c
					break;
				
				case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
					//0x3f9a4: One / Two / Three Star Align
					if (bData_40002c62_AlignmentStarMode == 0)
					{
						//3f9b8: Alignment Star Selection
						if (Data_40002c5c_AlignmentStarCount == 0)
						{
							//3f9c8: Alignment complete
							if (bData_400031e9 != 5)
							{
								lcd_display_clear();
							}
							//0x3f9dc
							bData_400031e9 = 5;
							func_c8f4();
							beep1(3);
							
							Data_40003364 = Data_400030b4; //"The telescope has be"
							Data_4000336c = Data_400030b8; //"aligned!"
							Data_40003374 = Data_400030bc;
							
							lcd_display_string(0, 1, 1, 22, "                       ");
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, 22, "                       ");
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 22, "                       ");
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, 22, "                       ");
							lcd_display_string(0, 8, 1, 22, "                       ");
							
							delay_loop(300);
							
							Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
							//->0x4047c
						} //if (Data_40002c5c_AlignmentStarCount == 0)
						else
						{
							//0x3fb58
							if (bData_400031e9 != 6)
							{
								lcd_display_clear();
							}
							//0x3fb6c
							bData_400031e9 = 6;
							
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 4, "OBJ:");
							lcd_display_string(0, 7, 11, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 11, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							lcd_display_string(0, 5, 11, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 11, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							
							lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapMinute);
							
							lcd_display_string(0, 6, 1, 4, "      ");
							//->0x4047c
						}
					} //if (bData_40002c62_AlignmentStarMode == 0)
					else
					{
						//0x3fdac: "Slewing to Target" / "Please center this star to the field of view"
						if ((bData_40002e88 == MENU_TRACKING_MODE_POINTING/*1*/) && (bData_400034cd == 0))
						{
							//3fdcc
							if (bData_400031e9 != 7)
							{
								lcd_display_clear();
							}
							bData_400031e9 = 7;
							
							Data_40003360 = Data_400030a0;
							Data_40003364 = Data_400030a4;
							
							if (Data_40004128.Data_352 == 0)
							{
								//3fe1c
								lcd_display_string(0, 1, 1, 21, "Slewing to Target   ");
							}
							else
							{
								//0x3fe3c
								lcd_display_string(0, 1, 1, 21, "Pause                ");
							}
							//0x3fe58
							lcd_display_string(0, 2, 1, 21, "                     ");
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 4, "OBJ:");
							lcd_display_string(0, 5, 11, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 11, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);

							lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapMinute);
							
							lcd_display_string(0, 6, 1, 6, "       ");
							lcd_display_string(0, 7, 1, 4, "OTA:");
							lcd_display_string(0, 7, 11, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 11, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
							lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapMinute);
							
							lcd_display_string(0, 6, 1, 4, "    ");
							//->0x402d8
						} //if ((bData_40002e88 == MENU_TRACKING_MODE_POINTING) && (bData_400034cd == 0))
						else
						{
							//0x4015c
							if (bData_400034cd == 1)
							{
								//4016c
								if (bData_400031e9 != 8)
								{
									lcd_display_clear();
								}
								bData_400031e9 = 8;
								
								Data_40003364 = Data_400030a8; //"  Please center this "
								Data_4000336c = Data_400030ac; //"star to the field of"
								Data_40003374 = Data_400030b0; //"view"
								
								lcd_display_string(0, 1, 1, 22, "                       ");
								lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 1, 22, "                       ");
								lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 1, 22, "                       ");
								lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 1, 22, "                       ");
								lcd_display_string(0, 8, 1, 22, "                       ");																
							}
						}
						//0x402d8
						if (bData_40002e88 == 2)
						{
							//402e8
							bData_400034cd = 1;
							
							if (bData_400031e9 != 8)
							{
								lcd_display_clear();
							}
							bData_400031e9 = 8;
							
							Data_40003364 = Data_400030a8;
							Data_4000336c = Data_400030ac;
							Data_40003374 = Data_400030b0;
							
							lcd_display_string(0, 1, 1, 22, "                       ");
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, 22, "                       ");
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 22, "                       ");
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, 22, "                       ");
							lcd_display_string(0, 8, 1, 22, "                       ");																
						}
					}
					//0x4047c -> 0x4684c
					break;
				
				case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102: 
					//0x40480
				case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
					//0x40488
				case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
					//0x4048c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					//->0x4684c
					break;
				
				case MENU_CONTEXT_RA_BKBLASH_CORR_RESULT: //11104:
					//0x40610
					beep1(1);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11102;
					//->0x4684c
					break;
				
				case 11105:
					//0x407b4
					beep1(3);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					break;
				
				case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
					//0x40958
				case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN: //11201:
					//0x40960
				case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
					//0x40964
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);				
					break;
				
				case MENU_CONTEXT_DEC_BKBLASH_CORR_RESULT: //11204:
					//0x40ae8
					beep1(1);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11202;
					break;
				
				case 11205:
					//0x40c8c
					beep1(3);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					break;
				
				case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
					//0x40e30: Solar System object
				case MENU_CONTEXT_CONSTELLATION_SELECTION: //24001:
					//0x40e38: Constellation item
				case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
					//0x40e3c
				case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
					//0x40e40: Sh2 item
				case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
					//0x40e44: Bright Star item
				case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
					//0x40e48: SAO item
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
					//0x41080: NGC item
				case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
					//0x41088: IC item
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, 14, "Constellation:");
					lcd_display_string(0, 2, 15, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, 5, "Type:");
					lcd_display_string(0, 4, 6, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
					//0x412f8
				case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
					//0x41300
				case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
					//0x41304
				case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
					//0x41308
				case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
					//0x4130c
				case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
					//0x41310
				case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
					//0x41314
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
					
					if (bData_40002e8a == 2)
					{
						//415e4
						func_659c(2000);
						beep1(1);
						func_659c(1000);
						beep1(1);
						func_659c(1000);
						
						Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					}
					//0x41618 -> 0x4684c
					break;
				
				case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
					//0x4161c
				case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
					//0x41624
					lcd_display_clear();
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 14, "Constellation:");
					lcd_display_string(0, 3, 15, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
				
					if (bData_40002e8a == 2)
					{
						//418c4
						func_659c(2000);
						beep1(1);
						func_659c(1000);
						beep1(1);
						func_659c(1000);
						
						Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					}
					//0x418f8 -> 0x4684c
					break;
				
				case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
					//0x418fc: Famous Star item
					func_91c(0, 1, 1, 64, (unsigned char*)Data_40003360);
					lcd_display_string(0, 3, 0, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);				
					break;
				
				case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
					//0x41af8: Messier item
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
					//0x41c80
				case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
					//0x41c88
				case 101:
					//0x41c8c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003384), (unsigned char*)Data_40003384);
				
					switch (bData_4000319a_SkyLandTargetId)
					{
						case 1:
							//0x41cf8
							lcd_display_string(1, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 2:
							//0x41e20
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(1, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 3:
							//0x41f48
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(1, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 4:
							//0x42070
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(1, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 5:
							//0x42198
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(1, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 6:
							//0x422c0
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(1, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 7:
							//0x423e8
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(1, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 8:
							//0x42530
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(1, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 9:
							//0x42658
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(1, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						#if 0
						default:
							//0x42780
							break;
						#endif
					}
					//->0x4684c
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
					//0x42788
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(1, 6, bCharacterInputPosition, 1, (unsigned char*)&Data_40003374[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
					//0x4298c
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(1, 7, bCharacterInputPosition, 1, (unsigned char*)&Data_40003378[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
					//0x42b90
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(1, 8, bCharacterInputPosition, 1, (unsigned char*)&Data_4000337c[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
					//0x42d94
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(0, 7, 1, 3, "Azi");
					lcd_display_string(0, 8, 1, 3, "Alt");
					lcd_display_string(1, 6, bCharacterInputPosition, 1, (unsigned char*)&Data_40003374[bCharacterInputPosition - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
					//0x43048
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(0, 7, 1, 3, "Azi");
					lcd_display_string(0, 8, 1, 3, "Alt");
					lcd_display_string(1, 7, bCharacterInputPosition, 1, (unsigned char*)&Data_40003378[bCharacterInputPosition - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
					//0x43328
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(0, 7, 1, 3, "Azi");
					lcd_display_string(0, 8, 1, 3, "Alt");
					lcd_display_string(1, 8, bCharacterInputPosition, 1, (unsigned char*)&Data_4000337c[bCharacterInputPosition - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_RA_INPUT: //29001:
					//0x435dc
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 16, (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, 16, (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_DEC_INPUT: //29002:
					//0x437f0
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 16, (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, 16, (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 48001:
					//0x43a04
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
					break;
								
				case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
					//0x43bc0
					switch (bDateTimeInputMode)
					{
						case 0:
							//0x43be0
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

							lcd_display_string(1, 3, bCharacterInputPosition, 1, &Data_40003368[bCharacterInputPosition - 1]);
							//->0x43f60
							break;
						
						case 1:
							//0x43d9c
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
						
							lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
							//->0x43f60
							break;
						
						default:
							//0x43f58
							break;
					}
					break;
				
				case 43011: //Country & City
					//0x43f68
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 3, 14, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 3, 17, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 17, (unsigned char*)cBitmapMinute);
					//->0x4684c
					break;
				
				case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
					//0x44140
					lcd_display_bitmap(0, 4, 11, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 13, (unsigned char*)cBitmapMinute);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					switch (bCurrentCustomSiteInputLine)
					{
						case 0:
							//0x44340
							lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
							break;
						
						case 1:
							//0x4437c
							lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
							break;
						
						case 2:
							//0x443b8
							lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
							break;
						
						case 3:
							//0x443f4
							lcd_display_string(1, 6, bCharacterInputPosition, 1, (unsigned char*)&Data_40003374[bCharacterInputPosition - 1]);
							break;						
					}
				
					lcd_display_bitmap(0, 4, 11, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 13, (unsigned char*)cBitmapMinute);
					break;
				
				case MENU_CONTEXT_OTA_ZERO_SETUP_RESTART: //47041:
					//0x444b4
				case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
					//0x444bc
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 8, (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, 8, (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003374); //BUG!
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					switch (bData_4000316d)
					{
						case 0:
							//0x44638
							lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
							break;
						
						case 1:
							//0x44674
							lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
							break;
						
						default:
							//0x446b0
							break;
					}
				
					lcd_display_bitmap(0, 3, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);					
					break;
				
				case MENU_CONTEXT_RESET_CONFIRM: //100:
					//0x446e8: Reset
					lcd_display_string(0, 1, 1, 21, "Are you sure reset   ");
					lcd_display_string(0, 3, 1, 21, "System.                ");
					lcd_display_string(0, 5, 1, 21, "Back: Cancel          ");
					lcd_display_string(0, 7, 1, 21, "Enter: Begin Reset      ");
					break;
				
				case 33001:
					//0x44760: Curr. Lunar Phase
					lcd_display_lunar_phase_screen(Data_40003164_LunarPhaseYear, Data_40003168_LunarPhaseMonth);
					break;
				
				case MENU_CONTEXT_TIMER_SET: //34001:
					//0x4477c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003378/*BUG!*/), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
					//->0x4684c
					break;
				
				case 35001:
					//0x44938: Alarm
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
					//->0x4684c
					break;
				
				case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
					//0x44b70
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
					break;
				
				case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
					//0x44d2c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
					break;
				
				case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
					//0x44ee8
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 7, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 13, (unsigned char*)cBitmapMinute);					
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapDegree);					
					break;
				
				case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
					//0x450e0
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 7, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 13, (unsigned char*)cBitmapMinute);					
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapDegree);					
					break;
				
				case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
					//0x452d8
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 7, bCharacterInputPosition, 1, (unsigned char*)&Data_40003378[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 7, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 13, (unsigned char*)cBitmapMinute);					
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapDegree);					
					break;
				
				case 211001:
					//0x454d0
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					switch (bData_40003262)
					{
						case 1:
							//45664
							switch (bData_40003261)
							{
								case 0:
									//0x4568c
									lcd_display_string(1, 2, bCharacterInputPosition, 1, (unsigned char*)&Data_40003364[bCharacterInputPosition - 1]);
									break;
								
								case 1:
									//0x456c8
									lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
									break;
								
								case 2:
									//0x45704
									lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
									break;
								
								default:
									//0x45740
//									break;
							}
//							break;
						
						default:
							//0x45750
							break;
					}
					//->0x4684c
					break;
				
				case 28001: //0x6D61:
					//0x4575c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					switch (bData_40003263)
					{
						case 1:
							//0x458fc
						case 3:
							//0x45904
							switch (bData_40003260)
							{
								case 0:
									//0x45928
									lcd_display_string(1, 2, bCharacterInputPosition, 1, (unsigned char*)&Data_40003364[bCharacterInputPosition - 1]);
									break;
								
								case 1:
									//0x45964
									lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
									break;
								
								case 2:
									//0x459a0
									lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
									break;
								
								default:
									//0x459dc
//									break;
							}
//							break;
						
						default:
							//0x459ec
							break;
					}
					//->0x4684c
					break;
				
				default:
					//->459f8
					switch (bData_4000316e_FocusLineOn8LineDisplay)
					{
						case 0: 
							//0x45a34
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 1: 
							//0x45bbc
							lcd_display_string(1, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 2: 
							//0x45d44
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(2/*1*/, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364); //BUG?
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 3: 
							//0x45ecc
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(1, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 4: 
							//0x46054
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(1, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 5: 
							//0x461dc
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(1, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 6: 
							//0x46364
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(1, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 7: 
							//0x4652c
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(1, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 8: 
							//0x466b4
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(1, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						default:
							//0x4683c
							break;
					} //switch (bData_4000316e_FocusLineOn8LineDisplay)
					break;
			} //switch (Data_40002c64_MenuContextId)
			//46850 -> 4edd8			
			break;
		
		case 2:
			//0x46854
			Data_4000318c = Data_40002c64_MenuContextId;
		
			if (Data_4000318c != Data_40003190)
			{
				//46880
				lcd_display_clear();
				
				Data_40003190 = Data_4000318c;
			}
			//0x46894
			switch (Data_40002c64_MenuContextId)
			{
				case MENU_CONTEXT_MAIN: //0:
					//0x46b64
					if (bSystemInitialized == 1)
					{
						DisplayMainScreen();
					}
					//->0x4edc8
					break;
				
				case MENU_CONTEXT_RECENT_TARGETS: //1:
					//0x46b80
					if (bData_40002f14_RecentTargetCount != 0)
					{
						//46b94
						switch (bData_4000316e_FocusLineOn8LineDisplay)
						{
							case 1:
								//0x46bcc
								lcd_display_string(1, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(1, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x4808c
								break;
							
							case 2:
								//0x46e54
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(1, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(2/*1*/, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364); //BUG?
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								break;
							
							case 3:
								//0x470dc
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(1, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(1, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								break;
							
							case 4:
								//0x47364
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(1, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(1, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								break;
							
							case 5:
								//0x475ec
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(1, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(1, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								break;
							
							case 6:
								//0x478ec
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(1, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(1, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								break;
							
							case 7:
								//0x47b74
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(1, 7, 1, 2, Data_40003398);
								lcd_display_string(0, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(1, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								break;
							
							case 8:
								//0x47dfc
								lcd_display_string(0, 1, 1, 2, Data_40003380);
								lcd_display_string(0, 2, 1, 2, Data_40003384);
								lcd_display_string(0, 3, 1, 2, Data_40003388);
								lcd_display_string(0, 4, 1, 2, Data_4000338c);
								lcd_display_string(0, 5, 1, 2, Data_40003390);
								lcd_display_string(0, 6, 1, 2, Data_40003394);
								lcd_display_string(0, 7, 1, 2, Data_40003398);
								lcd_display_string(1, 8, 1, 2, Data_4000339c);
							
								lcd_display_string(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(1, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								break;
							
							default:
								//0x48084
								break;
						} //switch (bData_4000316e_FocusLineOn8LineDisplay)
						//4808c -> 0x48310
					} //if (bData_40002f14_RecentTargetCount != 0)
					else
					{
						//0x48090
						lcd_display_string(0, 1, 1, 2, Data_40003380);
						lcd_display_string(0, 2, 1, 2, Data_40003384);
						lcd_display_string(0, 3, 1, 2, Data_40003388);
						lcd_display_string(0, 4, 1, 2, Data_4000338c);
						lcd_display_string(0, 5, 1, 2, Data_40003390);
						lcd_display_string(0, 6, 1, 2, Data_40003394);
						lcd_display_string(0, 7, 1, 2, Data_40003398);
						lcd_display_string(0, 8, 1, 2, Data_4000339c);
						
						lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
						lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
						lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
						lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
						lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
						lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
						lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
						lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					}
					//0x48310 -> 0x4edc8
					break;
				
				case 102:
					//0x48314
					if (((Data_40003f64.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 1)) ||
						((Data_40003f50.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 0)))
					{
						//0x48358
						lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
						lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
						lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
						lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
						lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
						lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
						lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
						lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);						
						//->0x489b0
					}
					else
					{
						//0x484dc
						switch (bData_40002e79_SkyLandTargetSeletion)
						{
							case 0:
								//0x484f8
								lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
								lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
								//->0x3f8c8
								break;
							
							case 1:
								//0x48734
								lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
								lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
								lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
								lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
								lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
								break;
						}
					}
					break;
				
				case 2:
					//0x489b4
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
				
					beep1(1);
					delay_loop(200);
					beep1(1);
					delay_loop(200);
					beep1(1);
					delay_loop(200);
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					//->0x4edc8
					break;
				
				case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
					//0x48a88
					if (bData_40002c62_AlignmentStarMode == 0)
					{
						//48a9c: Alignment Star Selection
						if (Data_40002c5c_AlignmentStarCount == 0)
						{
							//48aac: Alignment complete
							if (bData_400031e9 != 5)
							{
								lcd_display_clear();
							}
							//0x48ac0
							bData_400031e9 = 5;
							func_c8f4();
							beep1(3);
							
							Data_40003364 = Data_400030b4; //"The telescope has be"
							Data_4000336c = Data_400030b8; //"aligned!"
							Data_40003374 = Data_400030bc;
							
							lcd_display_string(0, 1, 1, 22, "                       ");
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, 22, "                       ");
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 22, "                       ");
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, 22, "                       ");
							lcd_display_string(0, 8, 1, 22, "                       ");
							
							delay_loop(300);
							
							Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
							//->0x4952c
						} //if (Data_40002c5c_AlignmentStarCount == 0)
						else
						{
							//0x48c3c
							if (bData_400031e9 != 6)
							{
								lcd_display_clear();
							}
							//0x48c50
							bData_400031e9 = 6;
							
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 4, "OBJ:");
							lcd_display_string(0, 7, 11, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 11, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							lcd_display_string(0, 5, 11, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 11, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							
							lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapMinute);
							
							lcd_display_string(0, 6, 1, 4, "      ");
							//->0x4952c
						}
					} //if (bData_40002c62_AlignmentStarMode == 0)
					else
					{
						//0x48e90: "Slewing to Target" / "Please center this star to the field of view"
						if ((bData_40002e88 == MENU_TRACKING_MODE_POINTING/*1*/) && (bData_400034cd == 0))
						{
							//48eb0
							if (bData_400031e9 != 7)
							{
								lcd_display_clear();
							}
							bData_400031e9 = 7;
							
							Data_40003360 = Data_400030a0;
							Data_40003364 = Data_400030a4;
							
							if (Data_40004128.Data_352 == 0)
							{
								//48f00
								lcd_display_string(0, 1, 1, 21, "Slewing to Target   ");
							}
							else
							{
								//0x48f20
								lcd_display_string(0, 1, 1, 21, "Pause                ");
							}
							//0x48f3c
							lcd_display_string(0, 2, 1, 21, "                     ");
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 4, "OBJ:");
							lcd_display_string(0, 5, 11, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 11, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);

							lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapMinute);
							
							lcd_display_string(0, 6, 1, 6, "       ");
							lcd_display_string(0, 7, 1, 4, "OTA:");
							lcd_display_string(0, 7, 11, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 11, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
							lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapMinute);
							
							lcd_display_string(0, 6, 1, 4, "    ");
							//->0x493a4
						} //if ((bData_40002e88 == MENU_TRACKING_MODE_POINTING) && (bData_400034cd == 0))
						else
						{
							//0x4918c
							if (bData_400034cd == 1)
							{
								//4919c
								if (bData_400031e9 != 8)
								{
									lcd_display_clear();
								}
								bData_400031e9 = 8;
								
								Data_40003364 = Data_400030a8; //"  Please center this "
								Data_4000336c = Data_400030ac; //"star to the field of"
								Data_40003374 = Data_400030b0; //"view"
								
								lcd_display_string(0, 1, 1, 22, "                       ");
								lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								lcd_display_string(0, 3, 1, 22, "                       ");
								lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								lcd_display_string(0, 5, 1, 22, "                       ");
								lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								lcd_display_string(0, 7, 1, 22, "                       ");
								lcd_display_string(0, 8, 1, 22, "                       ");																
							}
						}
						//0x493a4
						if (bData_40002e88 == 2)
						{
							//493b4
							bData_400034cd = 1;
							
							if (bData_400031e9 != 8)
							{
								lcd_display_clear();
							}
							bData_400031e9 = 8;
							
							Data_40003364 = Data_400030a8;
							Data_4000336c = Data_400030ac;
							Data_40003374 = Data_400030b0;
							
							lcd_display_string(0, 1, 1, 22, "                       ");
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, 22, "                       ");
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, 22, "                       ");
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, 22, "                       ");
							lcd_display_string(0, 8, 1, 22, "                       ");																
						}
					}
					//0x4952c -> 0x4edc8
					break;
				
				case MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11102:
					//0x49530
				case MENU_CONTEXT_RA_BKBLASH_CORR_2ND_STEP_START_LEFT_RIGHT: //11101:
					//0x49538
				case MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT: //11103:
					//0x4953c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					break;
				
				case MENU_CONTEXT_RA_BKBLASH_CORR_RESULT: //11104:
					//0x496c0
					beep1(1);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11102;
					break;
				
				case 11105:
					//0x49864
					beep1(3);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					break;
				
				case MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET: //11202:
					//0x49a08
				case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_START_UP_DOWN: //11201:
					//0x49a10
				case MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN: //11203:
					//0x49a14
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);				
					break;
				
				case MENU_CONTEXT_DEC_BKBLASH_CORR_RESULT: //11204:
					//0x49b98
					beep1(1);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET; //11202;
					break;
				
				case 11205:
					//0x49d3c
					beep1(3);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 8, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					delay_loop(800);
					Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					break;
				
				case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION: //22001:
					//0x49ee0
				case MENU_CONTEXT_CONSTELLATION_SELECTION: //24001:
					//0x49ee8
				case MENU_CONTEXT_MESSIER_OBJECT_SELECTION: //23002:
					//0x49eec
				case MENU_CONTEXT_SH2_OBJECT_SELECTION: //23005:
					//0x49ef0
				case MENU_CONTEXT_BRIGHT_STAR_SELECTION: //23006:
					//0x49ef4
				case MENU_CONTEXT_SAO_OBJECT_SELECTION: //23007:
					//0x49ef8
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_NGC_OBJECT_SELECTION: //23003:
					//0x4a130
				case MENU_CONTEXT_IC_OBJECT_SELECTION: //23004:
					//0x4a138
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, 14, "Constellation:");
					lcd_display_string(0, 2, 15, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, 5, "Type:");
					lcd_display_string(0, 4, 6, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
					//0x4a3a8
				case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
					//0x4a3b0
				case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
					//0x4a3b4
				case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
					//0x4a3b8
				case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
					//0x4a3bc
				case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
					//0x4a3c0
				case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
					//0x4a3c4
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
					
					if (bData_40002e8a == 2)
					{
						//4a644
						func_659c(2000);
						beep1(1);
						func_659c(1000);
						beep1(1);
						func_659c(1000);
						
						Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					}
					break;
				
				case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
					//0x4a67c
				case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
					//0x4a684
					lcd_display_clear();
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 14, "Constellation:");
					lcd_display_string(0, 3, 15, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);
				
					if (bData_40002e8a == 2)
					{
						//4a96c
						func_659c(2000);
						beep1(1);
						func_659c(1000);
						beep1(1);
						func_659c(1000);
						
						Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
					}
					break;
				
				case MENU_CONTEXT_FAMOUS_STAR_SELECTION: //25001:
					//0x4a9a4
					func_91c(0, 1, 1, 64, (unsigned char*)Data_40003360);
					lcd_display_string(0, 3, 0, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);				
					break;
				
				case MENU_CONTEXT_MESSIER_OBJECT_DETAILS: //23012:
					//0x4aba0
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_SELECTION: //201:
					//0x4ad28
				case MENU_CONTEXT_CUST_LAND_OBJ_SELECTION: //202:
					//0x4ad30
				case 101:
					//0x4ad34
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003384), (unsigned char*)Data_40003384);
				
					switch (bData_4000319a_SkyLandTargetId)
					{
						case 1:
							//0x4ada0
							lcd_display_string(1, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 2:
							//0x4aec8
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(1, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 3:
							//0x4aff0
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(1, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 4:
							//0x4b118
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(1, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 5:
							//0x4b240
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(1, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 6:
							//0x4b368
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(1, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 7:
							//0x4b490
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(1, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 8:
							//0x4b5b8
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(1, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 9:
							//0x4b6e0
							lcd_display_string(0, 3, 3, 2, (unsigned char*)Data_40003360);
							lcd_display_string(0, 3, 10, 2, (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 17, 2, (unsigned char*)Data_40003368);
							lcd_display_string(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 10, 2, (unsigned char*)Data_40003370);
							lcd_display_string(0, 5, 17, 2, (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 3, 2, (unsigned char*)Data_40003378);
							lcd_display_string(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							lcd_display_string(1, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						#if 0
						default:
							//0x4b808
							break;
						#endif
					}
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_NAME_INPUT: //203:
					//0x4b810
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(1, 6, bCharacterInputPosition, 1, (unsigned char*)&Data_40003374[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_RA_INPUT: //204:
					//0x4ba14
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(1, 7, bCharacterInputPosition, 1, (unsigned char*)&Data_40003378[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUSTOMER_OBJECT_DEC_INPUT: //205:
					//0x4bc54
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(1, 8, bCharacterInputPosition, 1, (unsigned char*)&Data_4000337c[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUST_LAND_OBJ_NAME_INPUT: //206:
					//0x4be58
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(0, 7, 1, 3, "Azi");
					lcd_display_string(0, 8, 1, 3, "Alt");
					lcd_display_string(1, 6, bCharacterInputPosition, 1, (unsigned char*)&Data_40003374[bCharacterInputPosition - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUST_LAND_OBJ_AZI_INPUT: //207:
					//0x4c10c
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(0, 7, 1, 3, "Azi");
					lcd_display_string(0, 8, 1, 3, "Alt");
					lcd_display_string(1, 7, bCharacterInputPosition, 1, (unsigned char*)&Data_40003378[bCharacterInputPosition - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case MENU_CONTEXT_CUST_LAND_OBJ_ALT_INPUT: //208:
					//0x4c3c0
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, 13, (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, 16, (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					lcd_display_string(0, 7, 1, 3, "Azi");
					lcd_display_string(0, 8, 1, 3, "Alt");
					lcd_display_string(1, 8, bCharacterInputPosition, 1, (unsigned char*)&Data_4000337c[bCharacterInputPosition - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 29001:
					//0x4c674
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 16, (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, 16, (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 29002:
					//0x4c888
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
				
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 16, (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, 16, (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 48001:
					//0x4ca9c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
					break;
				
				case MENU_CONTEXT_TIME_DATE_INPUT: //41001:
					//0x4cc58
					switch (bDateTimeInputMode)
					{
						case 0:
							//0x4cc78
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

							lcd_display_string(1, 3, bCharacterInputPosition, 1, &Data_40003368[bCharacterInputPosition - 1]);
							break;
						
						case 1:
							//0x4ce34
							lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
						
							lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
							break;
						
						default:
							//0x4d024
							break;
					}
					break;
				
				case 43011:
					//0x4d034
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 3, 14, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 3, 17, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 17, (unsigned char*)cBitmapMinute);
					break;
				
				case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
					//0x4d20c
					lcd_display_bitmap(0, 4, 11, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 13, (unsigned char*)cBitmapMinute);

					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					switch (bCurrentCustomSiteInputLine)
					{
						case 0:
							//0x4d40c
							lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
							break;
						
						case 1:
							//0x4d448
							lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
							break;
						
						case 2:
							//0x4d484
							lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
							break;
						
						case 3:
							//0x4d4c0
							lcd_display_string(1, 6, bCharacterInputPosition, 1, (unsigned char*)&Data_40003374[bCharacterInputPosition - 1]);
							break;						
					}
				
					lcd_display_bitmap(0, 4, 11, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 13, (unsigned char*)cBitmapMinute);
					break;
				
				case MENU_CONTEXT_OTA_ZERO_SETUP_RESTART: //47041:
					//0x4d554
				case MENU_CONTEXT_OTA_ZERO_SETUP: //47011:
					//0x4d55c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, 8, (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, 8, (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003374); //BUG!
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					switch (bData_4000316d)
					{
						case 0:
							//0x4d6d8
							lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
							break;
						
						case 1:
							//0x4d714
							lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
							break;
						
						default:
							//0x4d750
							break;
					}
				
					lcd_display_bitmap(0, 3, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);					
					break;
				
				case MENU_CONTEXT_RESET_CONFIRM: //100:
					//0x4d788
					lcd_display_string(0, 1, 1, 21, "Are you sure reset   ");
					lcd_display_string(0, 3, 1, 21, "System.                ");
					lcd_display_string(0, 5, 1, 21, "Back: Cancel          ");
					lcd_display_string(0, 7, 1, 21, "Enter: Begin Reset      ");
					break;
				
				case 33001:
					//0x4d800
					lcd_display_lunar_phase_screen(Data_40003164_LunarPhaseYear, Data_40003168_LunarPhaseMonth);
					break;
				
				case 34001:
					//0x4d81c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003378/*BUG!*/), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
					break;
				
				case 35001:
					//0x4d9d8
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
					break;
				
				case MENU_CONTEXT_EYEPIECE_MAGN_MF_INPUT: //360021:
					//0x4db94
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
					break;
				
				case MENU_CONTEXT_EYEPIECE_MAGN_SF_INPUT: //360022:
					//0x4dd50
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
					break;
				
				case MENU_CONTEXT_EYEPIECE_FOV_MF_INPUT: //370021:
					//0x4df0c
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 7, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 13, (unsigned char*)cBitmapMinute);					
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapDegree);					
					break;
				
				case MENU_CONTEXT_EYEPIECE_FOV_SF_INPUT: //370022:
					//0x4e140
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 5, bCharacterInputPosition, 1, (unsigned char*)&Data_40003370[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 7, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 13, (unsigned char*)cBitmapMinute);					
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapDegree);					
					break;
				
				case MENU_CONTEXT_EYEPIECE_FOV_INPUT: //370023:
					//0x4e338
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					lcd_display_string(1, 7, bCharacterInputPosition, 1, (unsigned char*)&Data_40003378[bCharacterInputPosition - 1]);
				
					lcd_display_bitmap(0, 7, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 13, (unsigned char*)cBitmapMinute);					
					lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapDegree);					
					break;
				
				case 211001:
					//0x4e530
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					switch (bData_40003262)
					{
						case 1:
							//4e6c4
							switch (bData_40003261)
							{
								case 0:
									//0x4e6ec
									lcd_display_string(1, 2, bCharacterInputPosition, 1, (unsigned char*)&Data_40003364[bCharacterInputPosition - 1]);
									break;
								
								case 1:
									//0x4e728
									lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
									break;
								
								case 2:
									//0x4e764
									lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
									break;
								
								default:
									//0x4e7a0
//									break;
							}
//							break;
						
						default:
							//0x4e7b0
							break;
					}
					break;
				
				case 28001:
					//0x4e7bc
					lcd_display_string(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					lcd_display_string(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					lcd_display_string(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					lcd_display_string(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					lcd_display_string(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					lcd_display_string(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					lcd_display_string(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					lcd_display_string(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

					switch (bData_40003263)
					{
						case 1:
							//0x4e95c
						case 3:
							//0x4e964
							switch (bData_40003260)
							{
								case 0:
									//0x4e988
									lcd_display_string(1, 2, bCharacterInputPosition, 1, (unsigned char*)&Data_40003364[bCharacterInputPosition - 1]);
									break;
								
								case 1:
									//0x4e9c4
									lcd_display_string(1, 3, bCharacterInputPosition, 1, (unsigned char*)&Data_40003368[bCharacterInputPosition - 1]);
									break;
								
								case 2:
									//0x4ea00
									lcd_display_string(1, 4, bCharacterInputPosition, 1, (unsigned char*)&Data_4000336c[bCharacterInputPosition - 1]);
									break;
								
								default:
									//0x4ea3c
//									break;
							}
//							break;
						
						default:
							//0x4ea4c
							break;
					}
					break;
				
				default:
					//0x4ea58
					switch (bData_4000316f_FocusLineOn4LineDisplay)
					{
						case 0: 
							//0x4ea88
							func_91c(0, 1, 1, 136, Data_400033a8);
							func_91c(0, 2, 1, 136, Data_400033ac);
							func_91c(0, 3, 1, 136, Data_400033b0);
							func_91c(0, 4, 1, 136, Data_400033b4);
							//->0x4edc0
							break;
						
						case 1: 
							//0x4eb10
							func_91c(1, 1, 1, 136, Data_400033a8);
							func_91c(0, 2, 1, 136, Data_400033ac);
							func_91c(0, 3, 1, 136, Data_400033b0);
							func_91c(0, 4, 1, 136, Data_400033b4);
							//->0x4edc0
							break;
						
						case 2: 
							//0x4eb98
							func_91c(0, 1, 1, 136, Data_400033a8);
							func_91c(1, 2, 1, 136, Data_400033ac);
							func_91c(0, 3, 1, 136, Data_400033b0);
							func_91c(0, 4, 1, 136, Data_400033b4);
							//->0x4edc0
							break;
						
						case 3: 
							//0x4ec20
							func_91c(0, 1, 1, 136, Data_400033a8);
							func_91c(0, 2, 1, 136, Data_400033ac);
							func_91c(1, 3, 1, 136, Data_400033b0);
							func_91c(0, 4, 1, 136, Data_400033b4);
							//->0x4edc0
							break;
						
						case 4:
							//0x4eca8
							func_91c(0, 1, 1, 136, Data_400033a8);
							func_91c(0, 2, 1, 136, Data_400033ac);
							func_91c(0, 3, 1, 136, Data_400033b0);
							func_91c(1, 4, 1, 136, Data_400033b4);
							//->0x4edc0
							break;
						
						case 5:
							//0x4ed30
							func_91c(1, 1, 1, 136, Data_400033a8);
							func_91c(1, 2, 1, 136, Data_400033ac);
							func_91c(1, 3, 1, 136, Data_400033b0);
							func_91c(1, 4, 1, 136, Data_400033b4);
							//->0x4edc0
							break;
						
						default:
							//0x4edb8
							break;
					} //switch (bData_4000316f_FocusLineOn4LineDisplay)
					break;
				
			} //switch (Data_40002c64_MenuContextId)
			break;
			
		default:
			break;
	} //switch (bData_40003197_DisplayLinesPerMenuLine)
	//0x4edd0
	
}

