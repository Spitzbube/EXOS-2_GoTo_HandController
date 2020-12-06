

/* 57414 - todo */
void SlewRaw(int axis, int direction, int speed)
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

	switch (axis)
	{
		case 1:
			//0x57488: Equatorial East-West
			sp[4] = 0x21;
			break;

		case 2:
			//0x57498: Equatorial North-South
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

	switch (direction)
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

	if (g_bSingleSlewActive == 0)
	{
		//5756c
		g_bSingleSlewActive = 1;

		func_7590();

		sp12[0] = 0x55;
		sp12[1] = 0xaa;
		sp12[2] = 0x01;
		sp12[3] = 0x04;

		switch (axis)
		{
			case 1:
				//0x575c0: Equatorial East-West
				sp12[4] = 0x01;
				break;

			case 2:
				//0x575d0: Equatorial North-South
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

		switch (direction)
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
					sp12[6] = 0; sp12[7] = 0;
					bTrackingMode = MENU_TRACKING_MODE_STOP; //0;
					break;

				case SLEW_RATE_1X: //1:
					//0x576c4
					sp12[6] = 0x00; sp12[7] = 0x05; //5
					bTrackingMode = 10;
					break;

				case SLEW_RATE_2X: //2:
					//0x576e8
					sp12[6] = 0x00; sp12[7] = 0x0a; //10
					bTrackingMode = 10;
					break;

				case SLEW_RATE_8X: //3:
					//0x57708
					sp12[6] = 0x00; sp12[7] = 0x28; //40
					bTrackingMode = 10;
					break;

				case SLEW_RATE_16X: //4:
					//0x5772c
					sp12[6] = 0x00; sp12[7] = 0xa0; //160
					bTrackingMode = 10;
					break;

				case SLEW_RATE_64X: //5:
					//0x57750
					sp12[6] = 0x01; sp12[7] = 0x40; //320
					bTrackingMode = 10;
					break;

				case SLEW_RATE_128X: //6:
					//0x57774
					sp12[6] = 0x02; sp12[7] = 0x80; //640
					bTrackingMode = 10;
					break;

				case SLEW_RATE_256X: //7:
					//0x57798
					sp12[6] = 0x05; sp12[7] = 0x00; //1280
					bTrackingMode = 10;
					break;

				case SLEW_RATE_512X: //8:
					//0x577bc
					sp12[6] = 0x0a; sp12[7] = 0x00; //2560
					bTrackingMode = 10;
					break;

				case SLEW_RATE_MAX: //9:
					//0x577e0
					sp12[6] = 0x0a; sp12[7] = 0x00; //2560

					Data_400031a4.Data = 2560;
					bData_400031b8 = 1;
					bData_400031ba = sp12[4];
					bData_400031bc = sp12[5];
					Data_400031b4 = 1;
					bData_400031b9 = 0;
					bData_400031bb = sp12[4];
					bData_400031bd = sp12[5];
					Data_400031a8 = 0;

					bTrackingMode = 10;
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
					bTrackingMode = MENU_TRACKING_MODE_STOP; //0;
					break;

				case SLEW_RATE_1X: //1:
					//0x578d4
					sp12[6] = 0;
					sp12[7] = 6;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_2X: //2:
					//0x578f8
					sp12[6] = 0;
					sp12[7] = 12;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_8X: //3:
					//0x5791c
					sp12[6] = 0;
					sp12[7] = 48;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_16X: //4:
					//0x57940
					sp12[6] = 0;
					sp12[7] = 96;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_64X: //5:
					//0x57964
					sp12[6] = 0;
					sp12[7] = 192;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_128X: //6:
					//0x57988
					sp12[6] = 1;
					sp12[7] = 128;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_256X: //7:
					//0x579ac
					sp12[6] = 2;
					sp12[7] = 28;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_512X: //8:
					//0x579d0
					sp12[6] = 3;
					sp12[7] = 56;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_MAX: //9:
					//0x579f4
					sp12[6] = 3;
					sp12[7] = 212;
					bTrackingMode = 10;
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
	} //if (g_bSingleSlewActive == 0)
	//0x57a40
}

