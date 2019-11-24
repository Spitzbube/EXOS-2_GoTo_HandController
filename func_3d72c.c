
/* 3d72c - todo */
void func_3d72c(void)
{
	func_27844();
	
	switch (bData_40003197_DisplayLinesPerMenuLine)
	{
		case 1:
			//0x3d750
			Data_4000318c = Data_40002c64;
			if (Data_4000318c != Data_40003190)
			{
				//3d77c
				func_394();				
				Data_40003190 = Data_4000318c;
			}
			//3d790
			switch (Data_40002c64)
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
							
								func_7e8(1, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(2, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(1, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(1, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(1, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(1, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(1, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
							
								func_7e8(0, 1, 3, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 3, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 3, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 3, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 3, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 3, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 3, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(1, 8, 3, (char)strlen(Data_4000337c), Data_4000337c);
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
						
						func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
						func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
						func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
						func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
						func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
						func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
						func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
						func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
					}
					//->0x4684c
					break;
				
				case 102:
					//0x3f230
					if (((Data_40003f64.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 1)) ||
						((Data_40003f50.bData_0 != 1) && (bData_40002e79_SkyLandTargetSeletion == 0)))
					{
						//0x3f274
						func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
						func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
						func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
						func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
						func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
						func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
						func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
						func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);						
						//->0x3f8cc
					}
					else
					{
						//0x3f3f8
						switch (bData_40002e79_SkyLandTargetSeletion)
						{
							case 0:
								//0x3f414
								func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 8, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 8, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 8, (char)strlen(Data_4000337c), Data_4000337c);
							
								func_864(0, 5, 15, (unsigned char*)Data_7906c);
								func_864(0, 5, 18, (unsigned char*)Data_79078);
								func_864(0, 5, 21, (unsigned char*)Data_79072);
								func_864(0, 6, 15, (unsigned char*)Data_7906c);
								func_864(0, 6, 18, (unsigned char*)Data_79078);
								func_864(0, 6, 21, (unsigned char*)Data_79072);
								func_864(0, 8, 15, (unsigned char*)Data_7906c);
								func_864(0, 8, 18, (unsigned char*)Data_79078);
								func_864(0, 8, 21, (unsigned char*)Data_79072);
								//->0x3f8c8
								break;
							
							case 1:
								//0x3f650
								func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
								func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
								func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
								func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
								func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
								func_7e8(0, 6, 8, (char)strlen(Data_40003374), Data_40003374);
								func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
								func_7e8(0, 8, 8, (char)strlen(Data_4000337c), Data_4000337c);
							
								func_864(0, 5, 15, (unsigned char*)Data_7906c);
								func_864(0, 5, 18, (unsigned char*)Data_79078);
								func_864(0, 5, 21, (unsigned char*)Data_79072);
								func_864(0, 6, 15, (unsigned char*)Data_7906c);
								func_864(0, 6, 18, (unsigned char*)Data_79078);
								func_864(0, 6, 21, (unsigned char*)Data_79072);
								func_864(0, 7, 15, (unsigned char*)Data_7906c);
								func_864(0, 7, 18, (unsigned char*)Data_79078);
								func_864(0, 7, 21, (unsigned char*)Data_79072);
								func_864(0, 8, 15, (unsigned char*)Data_7906c);
								func_864(0, 8, 18, (unsigned char*)Data_79078);
								func_864(0, 8, 21, (unsigned char*)Data_79072);
								break;
						}
					}
					//->0x4684c
					break;
				
				case 2:
					//0x3f8d0
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
				
					func_7950(1);
					func_2254(200);
					func_7950(1);
					func_2254(200);
					func_7950(1);
					func_2254(200);
					Data_40002c64 = 0;
					//->0x4684c
					break;
				
				case 12001:
					//0x3f9a4
					break;
				
				case 11102: //0x2b5e:
					//0x40480
				case 11101: //0x2b5d:
					//0x40488
				case 11103:
					//0x4048c
					break;
				
				case 11104:
					//0x40610
					break;
				
				case 11105:
					//0x407b4
					break;
				
				case 11202:
					//0x40958
					break;
				
				case 11201:
					//0x40960
					break;
				
				case 11203:
					//0x40964
					break;
				
				case 11204:
					//0x40ae8
					break;
				
				case 11205:
					//0x40c8c
					break;
				
				case 22001:
					//0x40e30
					break;
				
				case 24001: //0x5DC1:
					//0x40e38
					break;
				
				case 23002:
					//0x40e3c
					break;
				
				case 23005:
					//0x40e40
					break;
				
				case 23006: //0x59de:
					//0x40e44
					break;
				
				case 23007: //0x59DF:
					//0x40e48
					break;
				
				case 23003:
					//0x41080
					break;
				
				case 23004:
					//0x41088
					break;
				
				case 22111:
					//0x412f8
					break;
				
				case 24002: //0x5DC2:
					//0x41300
					break;
				
				case 25002: //0x61AA:
					//0x41304
					break;
				
				case 23022: //0x59EE:
					//0x41308
					break;
				
				case 0x59E7:
					//0x4130c
					break;
				
				case 0x59E8:
					//0x41310
					break;
				
				case 0x59E9:
					//0x41314
					break;
				
				case 0x59E5:
					//0x4161c
					break;
				
				case 0x59E6:
					//0x41624
					break;
				
				case 25001:
					//0x418fc
					break;
				
				case 0x59E4:
					//0x41af8
					break;
				
				case 101:
					//0x41c8c
					break;
				
				case 201:
					//0x41c80
					break;
				
				case 202: //0xca:
					//0x41c88
					break;
				
				case 203:
					//0x42788
					break;
				
				case 204:
					//0x4298c
					break;
				
				case 205:
					//0x42b90
					break;
				
				case 206:
					//0x42d94
					break;
				
				case 207:
					//0x43048
					break;
				
				case 208:
					//0x43328
					break;
				
				case 29001:
					//0x435dc
					break;
				
				case 29002: //???
					//0x437f0
					break;
				
				case 41001: //"Date and Time Set: "
					//0x43bc0
					switch (bData_40002e78)
					{
						case 0:
							//0x43be0
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);

							func_7e8(1, 3, bData_4000318a, 1, &Data_40003368[bData_4000318a - 1]);
							//->0x43f60
							break;
						
						case 1:
							//0x43d9c
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
						
							func_7e8(1, 5, bData_4000318a, 1, &Data_40003370[bData_4000318a - 1]);
							//->0x43f60
							break;
						
						default:
							//0x43f58
							break;
					}
					break;
				
				case 43011: //Country & City
					//0x43f68
					func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
					func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
					func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
					func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
					func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
					func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
					func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
					func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
				
					func_864(0, 3, 14, (unsigned char*)Data_7906c);
					func_864(0, 3, 17, (unsigned char*)Data_79078);
					func_864(0, 4, 14, (unsigned char*)Data_7906c);
					func_864(0, 4, 17, (unsigned char*)Data_79078);
					//->0x4684c
					break;
				
				case 43002:
					//0x44140
					break;
				
				case 47041:
					//0x444b4
					break;
				
				case 47011:
					//0x444bc
					break;
				
				case 100:
					//0x446e8
					break;
				
				case 33001: //0x80E9:
					//0x44760
					break;
				
				case 34001:
					//0x4477c
					break;
				
				case 35001:
					//0x44938
					break;
				
				case 28001: //0x6D61:
					//0x4575c
					break;
				
				case 48001: //0xBB81:
					//0x43a04
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
				
				default:
					//->459f8
					switch (bData_4000316e_FocusLineOn8LineDisplay)
					{
						case 0: 
							//0x45a34
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 1: 
							//0x45bbc
							func_7e8(1, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 2: 
							//0x45d44
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(1, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 3: 
							//0x45ecc
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(1, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 4: 
							//0x46054
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(1, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 5: 
							//0x461dc
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(1, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 6: 
							//0x46364
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(1, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 7: 
							//0x4652c
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(1, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(0, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						case 8: 
							//0x466b4
							func_7e8(0, 1, 1, (char)strlen(Data_40003360), Data_40003360);
							func_7e8(0, 2, 1, (char)strlen(Data_40003364), Data_40003364);
							func_7e8(0, 3, 1, (char)strlen(Data_40003368), Data_40003368);
							func_7e8(0, 4, 1, (char)strlen(Data_4000336c), Data_4000336c);
							func_7e8(0, 5, 1, (char)strlen(Data_40003370), Data_40003370);
							func_7e8(0, 6, 1, (char)strlen(Data_40003374), Data_40003374);
							func_7e8(0, 7, 1, (char)strlen(Data_40003378), Data_40003378);
							func_7e8(1, 8, 1, (char)strlen(Data_4000337c), Data_4000337c);
							//->0x46844
							break;
						
						default:
							//0x4683c
							break;
					} //switch (bData_4000316e_FocusLineOn8LineDisplay)
					break;
			} //switch (Data_40002c64)
			//46850 -> 4edd8			
			break;
		
		case 2:
			//0x46854
			Data_4000318c = Data_40002c64;
		
			if (Data_4000318c != Data_40003190)
			{
				Data_40003190 = Data_4000318c;
			}
			
			switch (Data_40002c64)
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
				
			} //switch (Data_40002c64)
		
			break;
	} //switch (bData_40003197_DisplayLinesPerMenuLine)
	//0x4edd0
	
#if 0
	//3dab8
	if (bData_40002f14 != 0)
	{
		//3dacc
		switch (bData_4000316e_FocusLineOn8LineDisplay)
		{
			#if 0
			case 0:
				//->3efa0
				break;
			#endif
			
			case 1:
				//3db08
				func_7e8(1, 1, 1, 2, Data_40003380);
				func_7e8(0, 2, 1, 2, Data_40003384);
				func_7e8(0, 3, 1, 2, Data_40003388);
				func_7e8(0, 4, 1, 2, Data_4000338c);
				func_7e8(0, 5, 1, 2, Data_40003390);
				func_7e8(0, 6, 1, 2, Data_40003394);
				func_7e8(0, 7, 1, 2, Data_40003398);
				func_7e8(0, 8, 1, 2, Data_4000339c);	
				func_7e8(1, 1, 3, strlen(Data_40003360), Data_40003360);
				func_7e8(0, 2, 3, strlen(Data_40003364), Data_40003364);
				func_7e8(0, 3, 3, strlen(Data_40003368), Data_40003368);
				func_7e8(0, 4, 3, strlen(Data_4000336c), Data_4000336c);
				func_7e8(0, 5, 3, strlen(Data_40003370), Data_40003370);
				func_7e8(0, 6, 3, strlen(Data_40003374), Data_40003374);
				func_7e8(0, 7, 3, strlen(Data_40003378), Data_40003378);
				func_7e8(0, 8, 3, strlen(Data_4000337c), Data_4000337c);
				//->3efa8
			
			case 2:
				//3dd8c
				break;
			
			case 3:
				//0x3e014
				break;
			
			case 4:
				//0x3e29c
				break;
			
			case 5:
				//0x3e524
				break;
			
			case 6:
				//0x3e7ac
				break;
			
			case 7:
				//0x3ea90
				break;
			
			case 8:
				//0x3ed18
				break;
			
			default:
				//->3efa0
				break;
		}
	}
	//3efac
#endif
}

