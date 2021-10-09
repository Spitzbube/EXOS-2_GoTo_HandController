

/* 4ee90 - todo */
void SlewBothAxes(int a, int b, int speed1, int d, int e, int speed2)
{
	unsigned char sp[12];
	unsigned char i;

	bData_40003430 = 1;
	bData_40003200 = 0;
	bData_40003201 = 0;

	if (g_bCombinedSlewActive == 1)
	{
		//4eed4
		sp[0] = 0x55;
		sp[1] = 0xaa;
		sp[2] = 0x01;
		sp[3] = 0x04;

		switch (a)
		{
			case 1:
				//0x4ef18
				sp[4] = 0x01;
				break;

			case 2:
				//0x4ef28
				sp[4] = 0x21;
				break;

			case 3:
				//0x4ef38
				sp[4] = 0x41;
				break;

			case 4:
				//0x4ef48
				sp[4] = 0x61;
				break;

			default:
				//0x4ef58
				break;
		}

		switch (b)
		{
			case 3:
				//0x4ef88
			case 1:
				//0x4ef90
				sp[5] = 0x00;
				break;

			case 4:
				//0x4ef9c
			case 2:
				//0x4efa4
				sp[5] = 0x01;
				break;

			default:
				//0x4efb0
				break;
		}

		if (g_bMountType == 1)
		{
			//4efcc
			switch (speed1)
			{
				case SLEW_STOP: //0:
					//0x4f000
					sp[6] = 0x00; sp[7] = 0x00;
					bTrackingMode = 0;
					break;

				case SLEW_RATE_1X: //1:
					//0x4f06c
					sp[6] = 0x00; sp[7] = 0x05;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_2X: //2:
					//0x4f090
					sp[6] = 0x00; sp[7] = 0x0a;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_8X: //3:
					//0x4f0b0
					sp[6] = 0x00; sp[7] = 0x28;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_16X: //4:
					//0x4f0d4
					sp[6] = 0x00; sp[7] = 0xa0;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_64X: //5:
					//0x4f0f8
					sp[6] = 0x01; sp[7] = 0x40;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_128X: //6:
					//0x4f11c
					sp[6] = 0x02; sp[7] = 0x80;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_256X: //7:
					//0x4f140
					sp[6] = 0x05; sp[7] = 0x00;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_512X: //8:
					//0x4f164
					sp[6] = 0x0a; sp[7] = 0x00;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_MAX: //9:
					//0x4f188
					sp[6] = 0x0a; sp[7] = 0x00;
					bTrackingMode = 10;
					break;
				#if 0
				default:
					//0x4f1ac
					break;
				#endif
			} //switch (c)
		} //if (g_bMountType == 1)
		//0x4f1b0
		if (g_bMountType == 2)
		{
			//4f1c0
			switch (speed1)
			{
				case SLEW_STOP: //0:
					//0x4f1f4
					sp[6] = 0; sp[7] = 0;
					bTrackingMode = 0;
					break;

				case SLEW_RATE_1X: //1:
					//0x4f210
					sp[6] = 0x00; sp[7] = 0x06;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_2X: //2:
					//0x4f234
					sp[6] = 0x00; sp[7] = 0x0c;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_8X: //3:
					//0x4f258
					sp[6] = 0x00; sp[7] = 0x30;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_16X: //4:
					//0x4f27c
					sp[6] = 0x00; sp[7] = 0x60;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_64X: //5:
					//0x4f2a0
					sp[6] = 0x00; sp[7] = 0xc0;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_128X: //6:
					//0x4f2c4
					sp[6] = 0x01; sp[7] = 0x80;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_256X: //7:
					//0x4f2e8
					sp[6] = 0x02; sp[7] = 0x1c;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_512X: //8:
					//0x4f30c
					sp[6] = 0x03; sp[7] = 0x38;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_MAX: //9:
					//0x4f330
					sp[6] = 0x03; sp[7] = 0xD4;
					bTrackingMode = 10;
					break;
				#if 0
				default:
					//0x4f354
					break;
				#endif
			} //switch (c)
		}
		//0x4f358
		for (i = 0; i < 8; i++)
		{
			//0x4f360
			uart1_write_byte(sp[i]);
		}

		switch (d)
		{
			case 1:
				//0x4f3a0
				sp[4] = 0x01;
				break;

			case 2:
				//0x4f3b0
				sp[4] = 0x21;
				break;

			case 3:
				//0x4f3c0
				sp[4] = 0x41;
				break;

			case 4:
				//0x4f3d0
				sp[4] = 0x61;
				break;

			default:
				//0x4f3e0
				break;
		}

		switch (e)
		{
			case 3:
				//0x4f410
			case 1:
				//0x4f418
				sp[5] = 0x00;
				break;

			case 4:
				//0x4f424
			case 2:
				//0x4f42c
				sp[5] = 0x01;
				break;

			default:
				//0x4f438
				break;
		}
		//0x4f440
		if (g_bMountType == 1)
		{
			//4f454
			switch (speed2)
			{
				case SLEW_STOP: //0:
					//0x4f488
					sp[6] = 0x00; sp[7] = 0x00;
					bTrackingMode = 0;
					break;

				case SLEW_RATE_1X: //1:
					//0x4f4a4
					sp[6] = 0x00; sp[7] = 0x05;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_2X: //2:
					//0x4f4c8
					sp[6] = 0x00; sp[7] = 0x0a;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_8X: //3:
					//0x4f4e8
					sp[6] = 0x00; sp[7] = 0x28;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_16X: //4:
					//0x4f50c
					sp[6] = 0x00; sp[7] = 0xa0;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_64X: //5:
					//0x4f530
					sp[6] = 0x01; sp[7] = 0x40;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_128X: //6:
					//0x4f554
					sp[6] = 0x02; sp[7] = 0x80;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_256X: //7:
					//0x4f578
					sp[6] = 0x05; sp[7] = 0x00;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_512X: //8:
					//0x4f59c
					sp[6] = 0x0a; sp[7] = 0x00;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_MAX: //9:
					//0x4f5c0
					sp[6] = 0x0a; sp[7] = 0x00;
					bTrackingMode = 10;
					break;
				#if 0
				default:
					//0x4f5e4
					break;
				#endif
			} //switch (f)
		}
		//0x4f5e8
		if (g_bMountType == 2)
		{
			//4f5f8
			switch (speed2)
			{
				case SLEW_STOP: //0:
					//0x4f62c
					sp[6] = 0; sp[7] = 0;
					bTrackingMode = 0;
					break;

				case SLEW_RATE_1X: //1:
					//0x4f648
					sp[6] = 0x00; sp[7] = 0x06;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_2X: //2:
					//0x4f66c
					sp[6] = 0x00; sp[7] = 0x0c;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_8X: //3:
					//0x4f690
					sp[6] = 0x00; sp[7] = 0x30;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_16X: //4:
					//0x4f6b4
					sp[6] = 0x00; sp[7] = 0x60;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_64X: //5:
					//0x4f6d8
					sp[6] = 0x00; sp[7] = 0xc0;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_128X: //6:
					//0x4f6fc
					sp[6] = 0x01; sp[7] = 0x80;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_256X: //7:
					//0x4f720
					sp[6] = 0x02; sp[7] = 0x1c;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_512X: //8:
					//0x4f744
					sp[6] = 0x03; sp[7] = 0x38;
					bTrackingMode = 10;
					break;

				case SLEW_RATE_MAX: //9:
					//0x4f768
					sp[6] = 0x03; sp[7] = 0xD4;
					bTrackingMode = 10;
					break;
				#if 0
				default:
					//0x4f78c
					break;
				#endif
			} //switch (f)
		} //if (g_bMountType == 2)
		//0x4f790
		for (i = 0; i < 8; i++)
		{
			//0x4f798
			uart1_write_byte(sp[i]);
		}
	} //if (g_bCombinedSlewActive == 1)
	else
	{
		//0x4f7b8
		g_bCombinedSlewActive = 1;

		if (g_bSingleSlewActive == 0)
		{
			UART1_WRITE_HEADER(1);
			uart1_write_byte(0xff);
		}
	}
}

/* 4f804 - todo */
void func_4f804(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
			//0x4f88c
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
			//0x4f894
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
			//0x4f898
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
			//0x4f89c
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
			//0x4f8a0
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
			//0x4f8a4
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
			//0x4f8a8
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
			//0x4f8ac
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
			//0x4f8b0
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			//0x4f8b4
			if (g_bLandTarget == 0)
			{
				//4f8c4
				if ((Data_40004128.bTrackingActive != 0) &&
					(g_bSlewingStop != 1))
				{
					//4f8e4
					g_iSlewStepRaAxis = 1;
					g_iSlewStepDecAxis = 1;
					bData_40003201 = 0;
					bData_40003200 = 0;
					//->4f9cc
				}
				//4f910
				else if (g_bMountType == 1)
				{
					//4f920
					//40002e7d
					SlewBothAxes(1, 4, g_eSlewRateIndex, 2, 1, g_eSlewRateIndex);
					//->4f9cc
				}
				else
				{
					//0x4f948
					SlewBothAxes(3, 4, g_eSlewRateIndex, 4, 1, g_eSlewRateIndex);
					//->4f9cc
				}
			}
			else
			{
				//0x4f970
				if (g_bMountType == 1)
				{
					//4f980
					SlewBothAxes(1, 4, g_eSlewRateIndex, 2, 1, g_eSlewRateIndex);
					//->4f9cc
				}
				else
				{
					//4f9a8
					SlewBothAxes(3, 4, g_eSlewRateIndex, 4, 1, g_eSlewRateIndex);
					//->4f9cc
				}
			}
			break;

		default:
			//0x4f9d0
			break;
	}
}

/* 4f9e4 - todo */
void func_4f9e4(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			if (g_bLandTarget == 0)
			{
				//4faa4
				if ((Data_40004128.bTrackingActive != 0) &&
					(g_bSlewingStop != 1))
				{
					g_iSlewStepRaAxis = 1;
					g_iSlewStepDecAxis = -1;
					bData_40003201 = 0;
					bData_40003200 = 0;
				}
				//0x4faf4
				else if (g_bMountType == 1)
				{
					SlewBothAxes(1, 4, g_eSlewRateIndex, 2, 2, g_eSlewRateIndex);
				}
				else
				{
					//0x4fb2c
					SlewBothAxes(3, 4, g_eSlewRateIndex, 4, 2, g_eSlewRateIndex);
				}
			}
			else
			{
				//0x4fb54
				if (g_bMountType == 1)
				{
					SlewBothAxes(1, 4, g_eSlewRateIndex, 2, 2, g_eSlewRateIndex);
				}
				else
				{
					SlewBothAxes(3, 4, g_eSlewRateIndex, 4, 2, g_eSlewRateIndex);
				}
			}
			break;

		default:
			break;
	}
}

/* 4fbc8 - todo */
void func_4fbc8(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			if (g_bLandTarget == 0)
			{
				//4fc88
				if ((Data_40004128.bTrackingActive != 0) &&
					(g_bSlewingStop != 1))
				{
					g_iSlewStepRaAxis = -1;
					g_iSlewStepDecAxis = -1;
					bData_40003201 = 0;
					bData_40003200 = 0;
				}
				//0x4fcd4
				else if (g_bMountType == 1)
				{
					SlewBothAxes(1, 3, g_eSlewRateIndex, 2, 2, g_eSlewRateIndex);
				}
				else
				{
					//0x4fd0c
					SlewBothAxes(3, 3, g_eSlewRateIndex, 4, 2, g_eSlewRateIndex);
				}
			}
			else
			{
				//0x4fd34
				if (g_bMountType == 1)
				{
					SlewBothAxes(1, 3, g_eSlewRateIndex, 2, 2, g_eSlewRateIndex);
				}
				else
				{
					SlewBothAxes(3, 3, g_eSlewRateIndex, 4, 2, g_eSlewRateIndex);
				}
			}
			break;

		default:
			break;
	}
}

/* 4fda8 - todo */
void func_4fda8(void)
{
	switch (Data_40002c64_MenuContextId)
	{
		case MENU_CONTEXT_MAIN: //0:
		case MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING: //22111:
		case MENU_CONTEXT_CONSTELLATION_TRACKING: //24002:
		case MENU_CONTEXT_FAMOUS_STAR_TRACKING: //25002:
		case MENU_CONTEXT_MESSIER_OBJECT_TRACKING: //23022:
		case MENU_CONTEXT_NGC_OBJECT_TRACKING: //23013:
		case MENU_CONTEXT_IC_OBJECT_TRACKING: //23014:
		case MENU_CONTEXT_SH2_OBJECT_TRACKING: //23015:
		case MENU_CONTEXT_BRIGHT_STAR_TRACKING: //23016:
		case MENU_CONTEXT_SAO_OBJECT_TRACKING: //23017:
			if (g_bLandTarget == 0)
			{
				//4fe68
				if ((Data_40004128.bTrackingActive != 0) &&
					(g_bSlewingStop != 1))
				{
					g_iSlewStepRaAxis = -1;
					g_iSlewStepDecAxis = 1;
					bData_40003201 = 0;
					//bData_40003200 = 0; //Bug??
				}
				//0x4feb0
				else if (g_bMountType == 1)
				{
					SlewBothAxes(1, 3, g_eSlewRateIndex, 2, 1, g_eSlewRateIndex);
				}
				else
				{
					//0x4fee8
					SlewBothAxes(3, 3, g_eSlewRateIndex, 4, 1, g_eSlewRateIndex);
				}
			}
			else
			{
				//0x4ff10
				if (g_bMountType == 1)
				{
					SlewBothAxes(1, 3, g_eSlewRateIndex, 2, 1, g_eSlewRateIndex);
				}
				else
				{
					SlewBothAxes(3, 3, g_eSlewRateIndex, 4, 1, g_eSlewRateIndex);
				}
			}
			break;

		default:
			break;
	}
}

