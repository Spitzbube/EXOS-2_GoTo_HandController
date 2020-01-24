

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
					if (bData_4000318a < 13)
					{
						//56424
						bData_4000318a++;
					}
					else
					{
						//0x5643c
						bData_4000318a = 7;
					}
					//0x56448 -> 0x565f4
					break;
				
				case 1:
					//0x5644c
					switch (bData_4000318a)
					{
						case 7:
							//0x56488
							bData_4000318a = 8;
							break;
						
						case 8:
							//0x5649c
							bData_4000318a = 10;
							break;
						
						case 10:
							//0x564b0
							bData_4000318a = 11;
							break;
						
						case 11:
							//0x564c4
							bData_4000318a = 13;
							break;
						
						case 13:
							//0x564d8
							bData_4000318a = 14;
							break;
						
						case 14:
							//0x564ec
							bData_4000318a = 7;
							break;
						
						default:
							//0x56500
							break;
					} //switch (bData_4000318a)
					//->0x565f4
					break;
				
				case 2:
					//0x56510
					switch (bData_4000318a)
					{
						case 7:
							//0x56550
							bData_4000318a = 8;
							break;
						
						case 8:
							//0x56564
							bData_4000318a = 9;
							break;
						
						case 9:
							//0x56578
							bData_4000318a = 11;
							break;
												
						case 11:
							//0x5658c
							bData_4000318a = 12;
							break;
						
						case 12:
							//0x565a0
							bData_4000318a = 14;
							break;
						
						case 14:
							//0x565b4
							bData_4000318a = 15;
							break;
						
						case 15:
							//0x565c8
							bData_4000318a = 7;
							break;
						
						default:
							//0x565dc
							break;
					} //switch (bData_4000318a)
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
					if (bData_4000318a < 13)
					{
						bData_4000318a++;
					}
					else
					{
						//0x56670
						bData_4000318a = 7;
					}
					//->0x56828
					break;
				
				case 1:
					//0x56680
					switch (bData_4000318a)
					{
						case 7:
							//0x566c0
							bData_4000318a = 8;
							break;

						case 8:
							//0x566d4
							bData_4000318a = 9;
							break;

						case 9:
							//0x566e8
							bData_4000318a = 11;
							break;

						case 11:
							//0x566fc
							bData_4000318a = 12;
							break;

						case 12:
							//0x56710
							bData_4000318a = 14;
							break;

						case 14:
							//0x56724
							bData_4000318a = 15;
							break;

						case 15:
							//0x56738
							bData_4000318a = 7;
							break;

						default:
							//0x5674c
							break;
					}
					break;
				
				case 2:
					//0x5675c
					switch (bData_4000318a)
					{
						case 7:
							//0x56798
							bData_4000318a = 8;
							break;
						
						case 8:
							//0x567ac
							bData_4000318a = 10;
							break;
						
						case 10:
							//0x567c0
							bData_4000318a = 11;
							break;
						
						case 11:
							//0x567d4
							bData_4000318a = 13;
							break;
						
						case 13:
							//0x567e8
							bData_4000318a = 14;
							break;
						
						case 14:
							//0x567fc
							bData_4000318a = 7;
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
void func_56ac8(void)
{
	switch (bData_4000318a)
	{
		case 7:
			//0x56af4
			bData_4000318a = 8;
			break;
		
		case 8:
			//0x56b08
			bData_4000318a = 9;
			break;
		
		case 9:
			//0x56b1c
			bData_4000318a = 10;
			break;
		
		case 10:
			//0x56b30
			bData_4000318a = 7;
			break;
		
		default:
			//0x56b44
			break;
	}
}

/* 56b54 - todo */
void func_56b54(void)
{
	switch (bData_4000318a)
	{
		case 7:
			//0x56b84
			bData_4000318a = 8;
			break;
		
		case 8:
			//0x56b98
			bData_4000318a = 9;
			break;
		
		case 9:
			//0x56bac
			bData_4000318a = 11;
			break;
		
		case 11:
			//0x56bc0
			bData_4000318a = 12;
			break;
		
		case 12:
			//0x56bd4
			bData_4000318a = 7;
			break;
		
		default:
			//0x56be8
			break;
	}
}

/* 56bf8 - todo */
void func_56bf8(void)
{
	switch (bData_4000318a)
	{
		case 7:
			//0x56c14
			bData_4000318a = 8;
			break;
		
		case 8:
			//0x56c28
			bData_4000318a = 7;
			break;
				
		default:
			//0x56be8
			break;
	}
}

/* 56c4c - todo */
void func_56c4c(void)
{
	switch (bData_4000318a)
	{
		case 1:
			//0x56c84
			bData_4000318a = 2;
			break;
		
		case 2:
			//0x56c98
			bData_4000318a = 4;
			break;
		
		case 4:
			//0x56cac
			bData_4000318a = 5;
			break;
		
		case 5:
			//0x56cc0
			bData_4000318a = 7;
			break;
		
		case 7:
			//0x56cd4
			bData_4000318a = 8;
			break;
		
		case 8:
			//0x56ce8
			bData_4000318a = 1;
			break;
		
		default:
			//0x56cfc
			break;
	}
}

/* 56d0c - todo */
void func_56d0c(void)
{
	switch (bData_4000318a)
	{
		case 1:
			//0x56d38
			bData_4000318a = 2;
			break;
		
		case 2:
			//0x56d4c
			bData_4000318a = 3;
			break;
		
		case 3:
			//0x56d60
			bData_4000318a = 4;
			break;
		
		case 4:
			//0x56d74
			bData_4000318a = 5;
			break;
		
		case 5:
			//0x56d88
			bData_4000318a = 1;
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
			if (bData_4000318a < 7)
			{
				bData_4000318a++;
			}
			else
			{
				bData_4000318a = 5;
			}
			break;
		
		case 1:
			//0x56e04
			if (bData_4000318a < 7)
			{
				bData_4000318a++;
			}
			else
			{
				bData_4000318a = 6;
			}
			break;
		
		default:
			//0x56e40
			break;
	}
}

/* 56e50 - complete */
void func_56e50(void)
{
	switch (bData_40002edc)
	{
		case 1:
			//0x56e6c
		case 3:
			//0x56e74
			switch (bData_40003144)
			{
				case 0:
					//0x56e9c
					if (bData_4000318a < 14)
					{
						bData_4000318a++;
					}
					else
					{
						bData_4000318a = 7;
					}
					break;

				case 1:
					//0x56ed8
					switch (bData_4000318a)
					{
						case 7:
							//0x56f10
							bData_4000318a = 8;
							break;
						
						case 8:
							//0x56f24
							bData_4000318a = 9;
							break;
						
						case 9:
							//0x56f38
							bData_4000318a = 10;
							break;
						
						case 10:
							//0x56f4c
							bData_4000318a = 12;
							break;
						
						case 12:
							//0x56f60
							bData_4000318a = 13;
							break;
						
						case 13:
							//0x56f74
							bData_4000318a = 7;
							break;
						
						default:
							//0x56f88
							break;
					}
					break;

				case 2:
					//0x56f98
					switch (bData_4000318a)
					{
						case 7:
							//0x56fcc
							bData_4000318a = 8;
							break;
						
						case 8:
							//0x56fe0
							bData_4000318a = 9;
							break;
						
						case 9:
							//0x56ff4
							bData_4000318a = 11;
							break;
						
						case 11:
							//0x57008
							bData_4000318a = 12;
							break;
						
						case 12:
							//0x5701c
							bData_4000318a = 7;
							break;
												
						default:
							//0x57030
							break;
					}
					break;

				case 3:
					//0x57040
					switch (bData_4000318a)
					{
						case 7:
							//0x57068
							bData_4000318a = 8;
							break;
						
						case 8:
							//0x5707c
							bData_4000318a = 9;
							break;
						
						case 9:
							//0x57090
							bData_4000318a = 7;
							break;
																		
						default:
							//0x570a4
							break;
					}
					break;

				case 4:
					//0x570b4
					switch (bData_4000318a)
					{
						case 7:
							//0x570e4
							bData_4000318a = 8;
							break;
						
						case 8:
							//0x570f8
							bData_4000318a = 9;
							break;
						
						case 9:
							//0x5710c
							bData_4000318a = 10;
							break;
																		
						case 10:
							//0x57120
							bData_4000318a = 7;
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
void func_5718c(void)
{
	switch (bData_40002e78)
	{
		case 0:
			//0x571a8
			switch (bData_4000318a)
			{
				case 1:
					//0x571ec
					bData_4000318a = 2;
					break;

				case 2:
					//0x57200
					bData_4000318a = 3;
					break;

				case 3:
					//0x57214
					bData_4000318a = 4;
					break;

				case 4:
					//0x57228
					bData_4000318a = 6;
					break;

				case 6:
					//0x5723c
					bData_4000318a = 7;
					break;

				case 7:
					//0x57250
					bData_4000318a = 9;
					break;

				case 9:
					//0x57264
					bData_4000318a = 10;
					break;

				case 10:
					//0x57278
					bData_4000318a = 1;
					break;

				default:
					//0x5728c
					break;
			}
			break;
		
		case 1:
			//0x5729c
			switch (bData_4000318a)
			{
				case 1:
					//0x572d8
					bData_4000318a = 2;
					break;

				case 2:
					//0x572ec
					bData_4000318a = 4;
					break;

				case 4:
					//0x57300
					bData_4000318a = 5;
					break;

				case 5:
					//0x57314
					bData_4000318a = 7;
					break;

				case 7:
					//0x57328
					bData_4000318a = 8;
					break;

				case 8:
					//0x5733c
					bData_4000318a = 1;
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
	switch (bData_4000318a)
	{
		case 1:
			//0x573a0
			bData_4000318a = 2;
			break;

		case 2:
			//0x573b4
			bData_4000318a = 3;
			break;

		case 3:
			//0x573c8
			bData_4000318a = 5;
			break;

		case 5:
			//0x573dc
			bData_4000318a = 6;
			break;

		case 6:
			//0x573f0
			bData_4000318a = 1;
			break;
		
		default:
			//0x57404
			break;
	}
}

/* 57414 - todo */
void func_57414(int a, int b, int speed)
{
	unsigned char i;
	char sp12[12];
	char sp[12];
	
	bData_40003430 = 1;
	bData_40003200 = 0;
	bData_40003201 = 0;
	
	sp[0] = 0x55;
	sp[1] = 0xaa;
	sp[2] = 0x01;
	sp[3] = 0x04;
	
	switch (a)
	{
		case 1:
			//0x57488
			sp[4] = 0x21;
			break;
		
		case 2:
			//0x57498
			sp[4] = 0x01;
			break;
		
		case 3:
			//0x574a8
			sp[4] = 0x61;
			break;
		
		case 4:
			//0x574b8
			sp[4] = 0x41;
			break;
		
		default:
			//0x574c8
			break;
	}

	switch (b)
	{
		case 3:
			//0x574f8
		case 1:
			//0x57500
			sp[5] = 0;
			break;
		
		case 4:
			//0x5750c
		case 2:
			//0x57514
			sp[5] = 1;
			break;
		
		default:
			//0x57520
			break;
	}
	
	sp[6] = 0;
	sp[7] = 0;
	
	for (i = 0; i < 8; i++)
	{
		//0x57540
		uart1_write_byte(sp[i]);
	}
	
	if (bData_4000319c == 0)
	{
		//5756c
		bData_4000319c = 1;
		
		func_7590();
		
		sp12[0] = 0x55;
		sp12[1] = 0xaa;
		sp12[2] = 0x01;
		sp12[3] = 0x04;
		
		switch (a)
		{
			case 1:
				//0x575c0
				sp12[4] = 0x01;
				break;
			
			case 2:
				//0x575d0
				sp12[4] = 0x21;
				break;
			
			case 3:
				//0x575e0
				sp12[4] = 0x41;
				break;
			
			case 4:
				//0x575f0
				sp12[4] = 0x61;
				break;
			
			default:
				//0x57600
				break;
		}
		
		switch (b)
		{
			case 3:
				//0x57630
			case 1:
				//0x57638
				sp12[5] = 0;
				break;
			
			case 4:
				//0x57644
			case 2:
				//0x5764c
				sp12[5] = 1;
				break;
			
			default:
				//0x57658
				break;
		}
		
		if (bData_40002c1a == 1)
		{
			//57674
			switch (speed)
			{
				case 0:
					//0x576a8
					sp12[6] = 0;
					sp12[7] = 0;
					bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
					break;
				
				case MENU_ROTATING_SPEED_1: //1:
					//0x576c4
					sp12[6] = 0;
					sp12[7] = 5;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_2: //2:
					//0x576e8
					sp12[6] = 0;
					sp12[7] = 10;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_8: //3:
					//0x57708
					sp12[6] = 0;
					sp12[7] = 40;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_16: //4:
					//0x5772c
					sp12[6] = 0;
					sp12[7] = 160;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_64: //5:
					//0x57750
					sp12[6] = 1;
					sp12[7] = 64;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_128: //6:
					//0x57774
					sp12[6] = 2;
					sp12[7] = 128;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_256: //7:
					//0x57798
					sp12[6] = 5;
					sp12[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_512: //8:
					//0x577bc
					sp12[6] = 10;
					sp12[7] = 0;
					bData_40002e88 = 10;
					break;
				
				case MENU_ROTATING_SPEED_MAX: //9:
					//0x577e0
					sp12[6] = 10;
					sp12[7] = 0;
					Data_400031a4 = 2560;
					bData_400031b8 = 1;
					bData_400031ba = sp12[4];
					bData_400031bc = sp12[5];
					Data_400031b4 = 1;
					bData_400031b9 = 0;
					bData_400031bb = sp12[4];
					bData_400031bd = sp12[5];
					Data_400031a8 = 0;
					bData_40002e88 = 10;
					break;
				#if 0				
				default:
					//0x57870
					break;
				#endif
			}
		} //if (bData_40002c1a == 1)
		//0x57874
		if (bData_40002c1a == 2)
		{
			//57884
			switch (speed)
			{
				case 0:
					//0x578b8
					sp12[6] = 0;
					sp12[7] = 0;
					bData_40002e88 = MENU_TRACKING_MODE_STOP; //0;
					break;
				
				case MENU_ROTATING_SPEED_1: //1:
					//0x578d4
					sp12[6] = 0;
					sp12[7] = 6;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_2: //2:
					//0x578f8
					sp12[6] = 0;
					sp12[7] = 12;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_8: //3:
					//0x5791c
					sp12[6] = 0;
					sp12[7] = 48;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_16: //4:
					//0x57940
					sp12[6] = 0;
					sp12[7] = 96;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_64: //5:
					//0x57964
					sp12[6] = 0;
					sp12[7] = 192;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_128: //6:
					//0x57988
					sp12[6] = 1;
					sp12[7] = 128;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_256: //7:
					//0x579ac
					sp12[6] = 2;
					sp12[7] = 28;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_512: //8:
					//0x579d0
					sp12[6] = 3;
					sp12[7] = 56;
					bData_40002e88 = 10;
					break;

				case MENU_ROTATING_SPEED_MAX: //9:
					//0x579f4
					sp12[6] = 3;
					sp12[7] = 212;
					bData_40002e88 = 10;
					break;
				#if 0
				default:
					//0x57a18
					break;
				#endif
			}
		} //if (bData_40002c1a == 2)
		//0x57a1c
		for (i = 0; i < 8; i++)
		{
			//0x57a24
			uart1_write_byte(sp12[i]);
		}
	} //if (bData_4000319c == 0)
	//0x57a40
}

/* 57a4c - complete */
void func_57a4c(void)
{
	switch (bData_4000318a)
	{
		case 5:
			//0x57a90
			bData_4000318a = 6;
			break;

		case 6:
			//0x57aa4
			bData_4000318a = 7;
			break;

		case 7:
			//0x57ab8
			bData_4000318a = 9;
			break;

		case 9:
			//0x57acc
			bData_4000318a = 10;
			break;

		case 10:
			//0x57ae0
			bData_4000318a = 12;
			break;

		case 12:
			//0x57af4
			bData_4000318a = 13;
			break;

		case 13:
			//0x57b08
			bData_4000318a = 15;
			break;
		
		case 15:
			//0x57b1c
			bData_4000318a = 5;
			break;

		default:
			//0x57b30
			break;
	}
}

/* 57b40 - complete */
void func_57b40(void)
{
	switch (bData_4000318a)
	{
		case 6:
			//0x57b80
			bData_4000318a = 7;
			break;

		case 7:
			//0x57b94
			bData_4000318a = 9;
			break;

		case 9:
			//0x57ba8
			bData_4000318a = 10;
			break;

		case 10:
			//0x57bbc
			bData_4000318a = 12;
			break;

		case 12:
			//0x57bd0
			bData_4000318a = 13;
			break;

		case 13:
			//0x57be4
			bData_4000318a = 15;
			break;

		case 15:
			//0x57bf8
			bData_4000318a = 6;
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
		case 204:
			//0x57e44
			func_57b40();
			break;
		
		case 29002:
			//0x57e4c
		case 205:
			//0x57e54
		case 208:
			//0x57e58
		case 207:
			//0x57e5c
			func_57a4c();
			break;
		
		case 203:
			//0x57e64
		case 206:
			//0x57e6c
			bData_4000318a++;
			if (bData_4000318a > 13)
			{
				bData_4000318a = 6;
			}
			//->0x583d0
			break;
		
		case MENU_CONTEXT_MAIN: //0:
			//0x57ea0
		case 11102:
			//0x57ea8
		case 11202:
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
			if (bData_400034a9 == 0)
			{
				//57ee0
				if ((Data_40004128.bData_356 != 0) && (bData_40002e89 != 1))
				{
					//57f00
					Data_40003408 = 1;
					bData_40003200 = 0;
				}
				else
				{
					//0x57f1c
					if (bData_40002c1a == 1)
					{
						//57f2c
						func_57414(1, 4, bData_40002e7d_RotatingSpeed);
					}
					else
					{
						//0x57f44
						func_57414(3, 4, bData_40002e7d_RotatingSpeed);
					}
				}
			}
			else
			{
				//0x57f5c
				if (bData_40002c1a == 1)
				{
					//57f6c
					func_57414(1, 4, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x57f84
					func_57414(3, 4, bData_40002e7d_RotatingSpeed);
				}
			}
			//0x57f98 -> 0x583d0
			break;
		
		case MENU_CONTEXT_ALIGNMENT_STAR_CONTROL: //12001:
			//0x57f9c
			if (bData_40002c62_AlignmentStarMode != 0)
			{
				//57fb0
				Data_40003408 = 1;
				bData_40003200 = 0;
			}
			break;
		
		case 11101:
			//0x57fcc
			dData_40002dc8 = dData_40002dc0;
			if (bData_40002c1a == 1)
			{
				//57ff0
				func_57414(1, 4, MENU_ROTATING_SPEED_8); //3);
				
				bData_40002edd = 2;
			}
			else
			{
				//0x58010
				func_57414(3, 4, MENU_ROTATING_SPEED_8); //3);
				
				bData_40002edd = 0;
			}
			//0x5802c
			Data_40002eb0 = 1;
			bData_40003188 = 1;
			Data_40002c64_MenuContextId = 11103;
			break;
		
		case 11103:
			//0x58050
			if (bData_40003188 == 2)
			{
				//58064
				if (bData_40002c1a == 1)
				{
					//58074
					func_57414(1, 4, bData_40002e7d_RotatingSpeed);
				}
				else
				{
					//0x58120
					func_57414(3, 4, bData_40002e7d_RotatingSpeed);
				}
			}
			//0x58134
			//break; //Fall through?
		
		case 48001:
			//0x58138
			func_57370();
			break;
		
		case 41001:
			//0x58140
			func_5718c();
			break;
		
		case MENU_CONTEXT_CUSTOM_SITE_INPUT: //43002:
			//0x5814c
			func_56e50();
			break;
		
		case 201:
			//0x58158		
		case 202:
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
		
		case 34001:
			//0x582a4
			func_56d0c();
			break;
		
		case 35001:
			//0x582b0
			func_56c4c();
			break;
		
		case 360022:
			//0x582bc
		case 370022:
			//0x582c4
			func_56bf8();
			break;
		
		case 370023:
			//0x582cc
			func_56b54();
			break;
		
		case 360021:
			//0x582d8
		case 370021:
			//0x582e0
			func_56ac8();
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
		
		case 42001:
			//0x58368
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42002;
				bData_40002c6a = 0;
			}
			break;
		
		case 42002:
			//0x58398
			if (bData_40002f1e_SetupLocalData == 1)
			{
				Data_40002c64_MenuContextId = 42001;
				bData_40002c6a = 1;
			}
			break;
		
		default:
			//0x583c8
			break;
	}
}

