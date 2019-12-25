
/* 3d72c - todo */
void func_3d72c(void)
{
	func_27844();
	
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
				case 0:
					//0x3da9c
					if (bData_400031ed == 1)
					{
						func_20b94();
					}
					//->4684c
					break;
				
				case 1:
					//0x3dab8
					if (bData_40002f14_RecentTargetCount != 0)
					{
						//3dacc
						switch (bData_4000316e_FocusLineOn8LineDisplay)
						{
							case 1:
								//0x3db04
								func_7e8(1, 1, 1, 2, Data_40003380);
								func_7e8(0, 2, 1, 2, Data_40003384);
								func_7e8(0, 3, 1, 2, Data_40003388);
								func_7e8(0, 4, 1, 2, Data_4000338c);
								func_7e8(0, 5, 1, 2, Data_40003390);
								func_7e8(0, 6, 1, 2, Data_40003394);
								func_7e8(0, 7, 1, 2, Data_40003398);
								func_7e8(0, 8, 1, 2, Data_4000339c);
							
								func_7e8(1, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 2:
								//0x3dd8c
								func_7e8(0, 1, 1, 2, Data_40003380);
								func_7e8(1, 2, 1, 2, Data_40003384);
								func_7e8(0, 3, 1, 2, Data_40003388);
								func_7e8(0, 4, 1, 2, Data_4000338c);
								func_7e8(0, 5, 1, 2, Data_40003390);
								func_7e8(0, 6, 1, 2, Data_40003394);
								func_7e8(0, 7, 1, 2, Data_40003398);
								func_7e8(0, 8, 1, 2, Data_4000339c);
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(2, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 3:
								//0x3e014
								func_7e8(0, 1, 1, 2, Data_40003380);
								func_7e8(0, 2, 1, 2, Data_40003384);
								func_7e8(1, 3, 1, 2, Data_40003388);
								func_7e8(0, 4, 1, 2, Data_4000338c);
								func_7e8(0, 5, 1, 2, Data_40003390);
								func_7e8(0, 6, 1, 2, Data_40003394);
								func_7e8(0, 7, 1, 2, Data_40003398);
								func_7e8(0, 8, 1, 2, Data_4000339c);
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(1, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 4:
								//0x3e29c
								func_7e8(0, 1, 1, 2, Data_40003380);
								func_7e8(0, 2, 1, 2, Data_40003384);
								func_7e8(0, 3, 1, 2, Data_40003388);
								func_7e8(1, 4, 1, 2, Data_4000338c);
								func_7e8(0, 5, 1, 2, Data_40003390);
								func_7e8(0, 6, 1, 2, Data_40003394);
								func_7e8(0, 7, 1, 2, Data_40003398);
								func_7e8(0, 8, 1, 2, Data_4000339c);
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(1, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 5:
								//0x3e524
								func_7e8(0, 1, 1, 2, Data_40003380);
								func_7e8(0, 2, 1, 2, Data_40003384);
								func_7e8(0, 3, 1, 2, Data_40003388);
								func_7e8(0, 4, 1, 2, Data_4000338c);
								func_7e8(1, 5, 1, 2, Data_40003390);
								func_7e8(0, 6, 1, 2, Data_40003394);
								func_7e8(0, 7, 1, 2, Data_40003398);
								func_7e8(0, 8, 1, 2, Data_4000339c);
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(1, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 6:
								//0x3e7ac
								func_7e8(0, 1, 1, 2, Data_40003380);
								func_7e8(0, 2, 1, 2, Data_40003384);
								func_7e8(0, 3, 1, 2, Data_40003388);
								func_7e8(0, 4, 1, 2, Data_4000338c);
								func_7e8(0, 5, 1, 2, Data_40003390);
								func_7e8(1, 6, 1, 2, Data_40003394);
								func_7e8(0, 7, 1, 2, Data_40003398);
								func_7e8(0, 8, 1, 2, Data_4000339c);
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(1, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 7:
								//0x3ea90
								func_7e8(0, 1, 1, 2, Data_40003380);
								func_7e8(0, 2, 1, 2, Data_40003384);
								func_7e8(0, 3, 1, 2, Data_40003388);
								func_7e8(0, 4, 1, 2, Data_4000338c);
								func_7e8(0, 5, 1, 2, Data_40003390);
								func_7e8(0, 6, 1, 2, Data_40003394);
								func_7e8(1, 7, 1, 2, Data_40003398);
								func_7e8(0, 8, 1, 2, Data_4000339c);
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(1, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
								//->0x3efa8
								break;
							
							case 8:
								//0x3ed18
								func_7e8(0, 1, 1, 2, Data_40003380);
								func_7e8(0, 2, 1, 2, Data_40003384);
								func_7e8(0, 3, 1, 2, Data_40003388);
								func_7e8(0, 4, 1, 2, Data_4000338c);
								func_7e8(0, 5, 1, 2, Data_40003390);
								func_7e8(0, 6, 1, 2, Data_40003394);
								func_7e8(0, 7, 1, 2, Data_40003398);
								func_7e8(1, 8, 1, 2, Data_4000339c);
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(1, 8, 3, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
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
						func_7e8(0, 1, 1, 2, Data_40003380);
						func_7e8(0, 2, 1, 2, Data_40003384);
						func_7e8(0, 3, 1, 2, Data_40003388);
						func_7e8(0, 4, 1, 2, Data_4000338c);
						func_7e8(0, 5, 1, 2, Data_40003390);
						func_7e8(0, 6, 1, 2, Data_40003394);
						func_7e8(0, 7, 1, 2, Data_40003398);
						func_7e8(0, 8, 1, 2, Data_4000339c);
						
						func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
						func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
						func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
						func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
						func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
						func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
						func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
						func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					}
					//->0x4684c
					break;
				
				case 102:
					//0x3f230
					if (((Data_40003f64.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 1)) ||
						((Data_40003f50.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 0)))
					{
						//0x3f274
						func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
						func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
						func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
						func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
						func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
						func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
						func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
						func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);						
						//->0x3f8cc
					}
					else
					{
						//0x3f3f8
						switch (bData_40002e79_SkyLandTargetSeletion)
						{
							case 0:
								//0x3f414
								func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
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
								func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
								func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
								func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
								func_7e8(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
								func_7e8(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
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
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
				
					func_7950(1);
					func_2254(200);
					func_7950(1);
					func_2254(200);
					func_7950(1);
					func_2254(200);
					Data_40002c64_MenuContextId = 0;
					//->0x4684c
					break;
				
				case 12001:
					//0x3f9a4: One / Two / Three Star Align
					if (bData_40002c62 == 0)
					{
						//3f9b8: Alignment Star Selection
						if (Data_40002c5c == 0)
						{
							//3f9c8
							if (bData_400031e9 != 5)
							{
								lcd_display_clear();
							}
							//0x3f9dc
							bData_400031e9 = 5;
							func_c8f4();
							func_7950(3);
							
							Data_40003364 = Data_400030b4;
							Data_4000336c = Data_400030b8;
							Data_40003374 = Data_400030bc;
							
							func_7e8(0, 1, 1, 22, "                       ");
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, 22, "                       ");
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, 22, "                       ");
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, 22, "                       ");
							func_7e8(0, 8, 1, 22, "                       ");
							
							func_2254(300);
							
							Data_40002c64_MenuContextId = 0;
							//->0x4047c
						} //if (Data_40002c5c == 0)
						else
						{
							//0x3fb58
							if (bData_400031e9 != 6)
							{
								lcd_display_clear();
							}
							//0x3fb6c
							bData_400031e9 = 6;
							
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, 4, "OBJ:");
							func_7e8(0, 7, 11, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 11, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							func_7e8(0, 5, 11, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 11, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							
							lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapMinute);
							
							func_7e8(0, 6, 1, 4, "      ");
							//->0x4047c
						}
					} //if (bData_40002c62 == 0)
					else
					{
						//0x3fdac: "Slewing to Target" / "Please center this star to the field of view"
						if ((bData_40002e88 == 1) && (bData_400034cd == 0))
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
								func_7e8(0, 1, 1, 21, "Slewing to Target   ");
							}
							else
							{
								//0x3fe3c
								func_7e8(0, 1, 1, 21, "Pause                ");
							}
							//0x3fe58
							func_7e8(0, 2, 1, 21, "                     ");
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, 4, "OBJ:");
							func_7e8(0, 5, 11, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 11, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);

							lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapMinute);
							
							func_7e8(0, 6, 1, 6, "       ");
							func_7e8(0, 7, 1, 4, "OTA:");
							func_7e8(0, 7, 11, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 11, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							
							lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapMinute);
							lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapDegree);
							lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapMinute);
							
							func_7e8(0, 6, 1, 4, "    ");
							//->0x402d8
						} //if ((bData_40002e88 == 1) && (bData_400034cd == 0))
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
								
								func_7e8(0, 1, 1, 22, "                       ");
								func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
								func_7e8(0, 3, 1, 22, "                       ");
								func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
								func_7e8(0, 5, 1, 22, "                       ");
								func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
								func_7e8(0, 7, 1, 22, "                       ");
								func_7e8(0, 8, 1, 22, "                       ");																
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
							
							func_7e8(0, 1, 1, 22, "                       ");
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, 22, "                       ");
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, 22, "                       ");
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, 22, "                       ");
							func_7e8(0, 8, 1, 22, "                       ");																
						}
					}
					//0x4047c -> 0x4684c
					break;
				
				case 11102: //0x2b5e:
					//0x40480
				case 11101: //0x2b5d:
					//0x40488
				case 11103:
					//0x4048c
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					//->0x4684c
					break;
				
				case 11104:
					//0x40610
					func_7950(1);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					func_2254(800);
					Data_40002c64_MenuContextId = 11102;
					//->0x4684c
					break;
				
				case 11105:
					//0x407b4
					func_7950(3);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					func_2254(800);
					Data_40002c64_MenuContextId = 0;
					break;
				
				case 11202:
					//0x40958
				case 11201:
					//0x40960
				case 11203:
					//0x40964
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);				
					break;
				
				case 11204:
					//0x40ae8
					func_7950(1);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					func_2254(800);
					Data_40002c64_MenuContextId = 11202;
					break;
				
				case 11205:
					//0x40c8c
					func_7950(3);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					func_2254(800);
					Data_40002c64_MenuContextId = 0;
					break;
				
				case 22001:
					//0x40e30
				case 24001:
					//0x40e38
				case 23002:
					//0x40e3c
				case 23005:
					//0x40e40
				case 23006:
					//0x40e44
				case 23007:
					//0x40e48
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
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
				
				case 23003:
					//0x41080
				case 23004:
					//0x41088
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, 14, "Constellation:");
					func_7e8(0, 2, 15, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, 5, "Type:");
					func_7e8(0, 4, 6, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
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
				
				case 22111:
					//0x412f8
				case 24002:
					//0x41300
				case 25002:
					//0x41304
				case 23022:
					//0x41308
				case 23015:
					//0x4130c
				case 23016:
					//0x41310
				case 23017:
					//0x41314
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
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
						func_7950(1);
						func_659c(1000);
						func_7950(1);
						func_659c(1000);
						
						Data_40002c64_MenuContextId = 0;
					}
					//0x41618 -> 0x4684c
					break;
				
				case 23013:
					//0x4161c
				case 23014:
					//0x41624
					lcd_display_clear();
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, 14, "Constellation:");
					func_7e8(0, 3, 15, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

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
						func_7950(1);
						func_659c(1000);
						func_7950(1);
						func_659c(1000);
						
						Data_40002c64_MenuContextId = 0;
					}
					//0x418f8 -> 0x4684c
					break;
				
				case 25001:
					//0x418fc
					func_91c(0, 1, 1, 64, (unsigned char*)Data_40003360);
					func_7e8(0, 3, 0, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 8, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 8, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 8, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

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
				
				case 23012:
					//0x41af8
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					break;
				
				case 201:
					//0x41c80
				case 202:
					//0x41c88
				case 101:
					//0x41c8c
					func_7e8(0, 1, 1, (char)strlen(Data_40003384), (unsigned char*)Data_40003384);
				
					switch (bData_4000319a_SkyLandTargetId)
					{
						case 1:
							//0x41cf8
							func_7e8(1, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 2:
							//0x41e20
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(1, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 3:
							//0x41f48
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(1, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 4:
							//0x42070
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(1, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 5:
							//0x42198
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(1, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 6:
							//0x422c0
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(1, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 7:
							//0x423e8
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(1, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 8:
							//0x42530
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(1, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(0, 7, 17, 2, (unsigned char*)Data_40003380);
							//->0x42780
							break;
						
						case 9:
							//0x42658
							func_7e8(0, 3, 3, 2, (unsigned char*)Data_40003360);
							func_7e8(0, 3, 10, 2, (unsigned char*)Data_40003364);
							func_7e8(0, 3, 17, 2, (unsigned char*)Data_40003368);
							func_7e8(0, 5, 3, 2, (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 10, 2, (unsigned char*)Data_40003370);
							func_7e8(0, 5, 17, 2, (unsigned char*)Data_40003374);
							func_7e8(0, 7, 3, 2, (unsigned char*)Data_40003378);
							func_7e8(0, 7, 10, 2, (unsigned char*)Data_4000337c);
							func_7e8(1, 7, 17, 2, (unsigned char*)Data_40003380);
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
				
				case 203:
					//0x42788
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, 13, (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, 16, (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					func_7e8(1, 6, bData_4000318a, 1, (unsigned char*)&Data_40003374[bData_4000318a - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 204:
					//0x4298c
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, 13, (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, 16, (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					func_7e8(1, 7, bData_4000318a, 1, (unsigned char*)&Data_40003378[bData_4000318a - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 205:
					//0x42b90
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);

					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, 13, (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, 16, (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					func_7e8(1, 8, bData_4000318a, 1, (unsigned char*)&Data_4000337c[bData_4000318a - 1]);
				
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 206:
					//0x42d94
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, 13, (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, 16, (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					func_7e8(0, 7, 1, 3, "Azi");
					func_7e8(0, 8, 1, 3, "Alt");
					func_7e8(1, 6, bData_4000318a, 1, (unsigned char*)&Data_40003374[bData_4000318a - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 207:
					//0x43048
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, 13, (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, 16, (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					func_7e8(0, 7, 1, 3, "Azi");
					func_7e8(0, 8, 1, 3, "Alt");
					func_7e8(1, 7, bData_4000318a, 1, (unsigned char*)&Data_40003378[bData_4000318a - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 208:
					//0x43328
					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, 13, (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, 16, (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, 16, (unsigned char*)Data_4000337c);
					func_7e8(0, 7, 1, 3, "Azi");
					func_7e8(0, 8, 1, 3, "Alt");
					func_7e8(1, 8, bData_4000318a, 1, (unsigned char*)&Data_4000337c[bData_4000318a - 1]);

					lcd_display_bitmap(0, 8, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 8, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 8, 16, (unsigned char*)cBitmapSecond);
					lcd_display_bitmap(0, 7, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 7, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 7, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 29001:
					//0x435dc
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, 16, (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, 16, (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					func_7e8(1, 3, bData_4000318a, 1, (unsigned char*)&Data_40003368[bData_4000318a - 1]);
				
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 29002: //???
					//0x437f0
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
				
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, 16, (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, 16, (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					func_7e8(1, 5, bData_4000318a, 1, (unsigned char*)&Data_40003370[bData_4000318a - 1]);
				
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 11, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 16, (unsigned char*)cBitmapSecond);
					break;
				
				case 48001:
					//0x43a04
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
					func_7e8(1, 4, bData_4000318a, 1, (unsigned char*)&Data_4000336c[bData_4000318a - 1]);
					break;
								
				case 41001: //"Date and Time Set: "
					//0x43bc0
					switch (bData_40002e78)
					{
						case 0:
							//0x43be0
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);

							func_7e8(1, 3, bData_4000318a, 1, &Data_40003368[bData_4000318a - 1]);
							//->0x43f60
							break;
						
						case 1:
							//0x43d9c
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
						
							func_7e8(1, 5, bData_4000318a, 1, (unsigned char*)&Data_40003370[bData_4000318a - 1]);
							//->0x43f60
							break;
						
						default:
							//0x43f58
							break;
					}
					break;
				
				case 43011: //Country & City
					//0x43f68
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					lcd_display_bitmap(0, 3, 14, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 3, 17, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 17, (unsigned char*)cBitmapMinute);
					//->0x4684c
					break;
				
				case 43002:
					//0x44140
					lcd_display_bitmap(0, 4, 11, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 13, (unsigned char*)cBitmapMinute);

					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					switch (bData_40003144)
					{
						case 0:
							//0x44340
							func_7e8(1, 3, bData_4000318a, 1, (unsigned char*)&Data_40003368[bData_4000318a - 1]);
							break;
						
						case 1:
							//0x4437c
							func_7e8(1, 4, bData_4000318a, 1, (unsigned char*)&Data_4000336c[bData_4000318a - 1]);
							break;
						
						case 2:
							//0x443b8
							func_7e8(1, 5, bData_4000318a, 1, (unsigned char*)&Data_40003370[bData_4000318a - 1]);
							break;
						
						case 3:
							//0x443f4
							func_7e8(1, 6, bData_4000318a, 1, (unsigned char*)&Data_40003374[bData_4000318a - 1]);
							break;						
					}
				
					lcd_display_bitmap(0, 4, 11, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 4, 14, (unsigned char*)cBitmapMinute);
					lcd_display_bitmap(0, 5, 10, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 13, (unsigned char*)cBitmapMinute);
					break;
				
				case 47041:
					//0x444b4
				case 47011:
					//0x444bc
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
					func_7e8(0, 3, 1, 8, (unsigned char*)Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
					func_7e8(0, 5, 1, 8, (unsigned char*)Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003374); //BUG!
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
				
					switch (bData_4000316d)
					{
						case 0:
							//0x44638
							func_7e8(1, 3, bData_4000318a, 1, (unsigned char*)&Data_40003368[bData_4000318a - 1]);
							break;
						
						case 1:
							//0x44674
							func_7e8(1, 5, bData_4000318a, 1, (unsigned char*)&Data_40003370[bData_4000318a - 1]);
							break;
						
						default:
							//0x446b0
							break;
					}
				
					lcd_display_bitmap(0, 3, 8, (unsigned char*)cBitmapDegree);
					lcd_display_bitmap(0, 5, 8, (unsigned char*)cBitmapDegree);					
					break;
				
				case 100:
					//0x446e8: Reset
					func_7e8(0, 1, 1, 21, "Are you sure reset   ");
					func_7e8(0, 3, 1, 21, "System.                ");
					func_7e8(0, 5, 1, 21, "Back: Cancel          ");
					func_7e8(0, 7, 1, 21, "Enter: Begin Reset      ");
					break;
				
				case 33001:
					//0x44760
					func_df84(Data_40003164, Data_40003168);
					break;
				
				case 34001:
					//0x4477c
					break;
				
				case 35001:
					//0x44938
					break;
				
				case 360021:
					//0x44b70
					break;
				
				case 360022:
					//0x44d2c
					break;
				
				case 370021: //0x5A565:
					//0x44ee8
					break;
				
				case 370022: //0x5A566:
					//0x450e0
					break;
				
				case 370023: //0x5A567:
					//0x452d8
					break;
				
				case 211001:
					//0x454d0
					break;
				
				case 28001: //0x6D61:
					//0x4575c
					break;
				
				default:
					//->459f8
					switch (bData_4000316e_FocusLineOn8LineDisplay)
					{
						case 0: 
							//0x45a34
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 1: 
							//0x45bbc
							func_7e8(1, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 2: 
							//0x45d44
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(1, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 3: 
							//0x45ecc
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(1, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 4: 
							//0x46054
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(1, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 5: 
							//0x461dc
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(1, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 6: 
							//0x46364
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(1, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 7: 
							//0x4652c
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(1, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
							//->0x46844
							break;
						
						case 8: 
							//0x466b4
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), (unsigned char*)Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), (unsigned char*)Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), (unsigned char*)Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), (unsigned char*)Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), (unsigned char*)Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), (unsigned char*)Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), (unsigned char*)Data_40003378);
							func_7e8(1, 8, 1, (char)strlen(Data_4000337c), (unsigned char*)Data_4000337c);
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
				Data_40003190 = Data_4000318c;
			}
			
			switch (Data_40002c64_MenuContextId)
			{
				case 202:
					//0x4ad30
					break;
				
				//TODO
				
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
							func_91c(0, 1, 1, 136, Data_400033a8);
							func_91c(0, 2, 1, 136, Data_400033ac);
							func_91c(0, 3, 1, 136, Data_400033b0);
							func_91c(1, 4, 1, 136, Data_400033b4);
							//->0x4edc0
							break;
						
						default:
							//0x4edb8
							break;
					}
					break;
				
			} //switch (Data_40002c64_MenuContextId)
		
			break;
	} //switch (bData_40003197_DisplayLinesPerMenuLine)
	//0x4edd0
	
}

