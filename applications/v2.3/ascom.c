
/* 6c848 - complete */
unsigned char ProcessUart0ReceiverData(void)
{
	if (uart0ReceiveFlag == 1)
	{
		bAscomCmd = uart0ReceiveDataBuffer[0];

#ifdef OLIMEX_LPC2148
		{
			static char buf[105];

			snprintf(buf, 100, "ProcessUart0ReceiverData: bAscomCmd: 0x%x\n\r", bAscomCmd);
			uart1_send((unsigned char*)buf, strlen(buf));
		}
#endif

		switch (bAscomCmd)
		{
			case 35:
				//6c898: Goto
			case 36:
				//6c8a0: Sync
				Data_40002c28.bData[0] = uart0ReceiveDataBuffer[1];
				Data_40002c28.bData[1] = uart0ReceiveDataBuffer[2];
				Data_40002c28.bData[2] = uart0ReceiveDataBuffer[3];
				Data_40002c28.bData[3] = uart0ReceiveDataBuffer[4];
				fData_40003510 = Data_40002c28.fData;

				Data_40002c28.bData[0] = uart0ReceiveDataBuffer[5];
				Data_40002c28.bData[1] = uart0ReceiveDataBuffer[6];
				Data_40002c28.bData[2] = uart0ReceiveDataBuffer[7];
				Data_40002c28.bData[3] = uart0ReceiveDataBuffer[8];
				fData_40003514 = Data_40002c28.fData;
				//->6ca60
				break;

			case 37:
				//6c92c: "Standort einstellen"
				Data_40002c28.bData[0] = uart0ReceiveDataBuffer[1];
				Data_40002c28.bData[1] = uart0ReceiveDataBuffer[2];
				Data_40002c28.bData[2] = uart0ReceiveDataBuffer[3];
				Data_40002c28.bData[3] = uart0ReceiveDataBuffer[4];
				fData_40003518_ReceiveExternalSiteLongitude = Data_40002c28.fData;

				Data_40002c28.bData[0] = uart0ReceiveDataBuffer[5];
				Data_40002c28.bData[1] = uart0ReceiveDataBuffer[6];
				Data_40002c28.bData[2] = uart0ReceiveDataBuffer[7];
				Data_40002c28.bData[3] = uart0ReceiveDataBuffer[8];
				fData_4000351c_ReceiveExternalSiteLatitude = Data_40002c28.fData;
				//->6ca60
				break;

			case 38:
				//6c9bc: "Zeit einstellen"
				Data_40003524_ReceiveExternalYear = uart0ReceiveDataBuffer[1] * 100 +
												uart0ReceiveDataBuffer[2];
				bData_40003528_ReceiveExternalMonth = uart0ReceiveDataBuffer[3];
				bData_40003529_ReceiveExternalDay = uart0ReceiveDataBuffer[4];
				bData_4000352a_ReceiveExternalHours = uart0ReceiveDataBuffer[5];
				bData_4000352b_ReceiveExternalMinutes = uart0ReceiveDataBuffer[6];
				bData_4000352c_ReceiveExternalSeconds = uart0ReceiveDataBuffer[7];
				fData_40003520 = (float)uart0ReceiveDataBuffer[8] - 12;
#ifdef OLIMEX_LPC2148
				{
					static char buf[105];

					snprintf(buf, 100, "Date: %u-%u-%u\n\r",
							Data_40003524_ReceiveExternalYear,
							bData_40003528_ReceiveExternalMonth,
							bData_40003529_ReceiveExternalDay);
					uart1_send((unsigned char*)buf, strlen(buf));

					snprintf(buf, 100, "Time: %u:%u:%u\n\r",
							bData_4000352a_ReceiveExternalHours,
							bData_4000352b_ReceiveExternalMinutes,
							bData_4000352c_ReceiveExternalSeconds);
					uart1_send((unsigned char*)buf, strlen(buf));

					snprintf(buf, 100, "%d.%d\n\r",
							(int)fData_40003520,
							(fData_40003520 - (int)fData_40003520) * 1000);
					uart1_send((unsigned char*)buf, strlen(buf));
				}
#endif
				//->6ca60
				break;

			default:
				//6ca58
				break;
		}

		uart0ReceiveFlag = 0;
	} //if (uart0ReceiveFlag == 1)
	//6ca70
	return bAscomCmd;
}

/* 6cb38 - complete */
void ProcessAscomCommands(void)
{
	union
	{
		unsigned char bData[4];
		float fData;
	} sp60, sp56;
	unsigned char sp40[13];

	sp40[0] = 0x55;
	sp40[1] = 0xaa;
	sp40[2] = 0x01;
	sp40[3] = 0x09;

	bAscomCmd = ProcessUart0ReceiverData();

	switch (bAscomCmd)
	{
		case 29:
			//6cbd8: Abort Slew
			StopSlewing();

			bAscomCmd = 1;
			//->6d044
			break;

		case 30:
			//6cbf0: Park
			func_75c4();

			bGotoParkPosition = 1;
			bAscomCmd = 1;
			//->6d044
			break;

		case 31:
			//6cc10: Get Site info
			sp60.fData = dData_40002e28_SiteLongitude;
			sp56.fData = dData_40002e48_SiteLatitude;

			sp40[4] = 0xfe; //Site information
			sp40[5] = sp60.bData[0];
			sp40[6] = sp60.bData[1];
			sp40[7] = sp60.bData[2];
			sp40[8] = sp60.bData[3];
			sp40[9] = sp56.bData[0];
			sp40[10] = sp56.bData[1];
			sp40[11] = sp56.bData[2];
			sp40[12] = sp56.bData[3];

			uart0_send(sp40, 13);

			bAscomCmd = 1;
			//->6d044
			break;

		case 32:
			//6cc98: Get DateTime
			bAscomCmd = 1;
			//->6d044
			break;

		case 33:
			//6ccac: Get AlignmentMode
			if (bData_40002c1a == 1)
			{
				//Alignment Mode Polar
				sp40[4] = 0x50;
			}
			else if (bData_40002c1a == 2)
			{
				//Alignment Mode AltAz
				sp40[4] = 0x41;
			}

			uart0_send(sp40, 13);

			bAscomCmd = 1;
			//->6d044
			break;

		case 34:
			//6cd00: Disconnect
			bAscomCmd = 0;
			//->6d044
			break;

		case 35:
			//6cd14: Goto
			GotoEQCoordinates(fData_40003510, fData_40003514);

			dData_400031f0 = 0;
			dData_400031f8 = 0;
			bAscomCmd = 1;
			//->6d044
			break;

		case 36:
			//6cd7c: Sync
			dData_40003410 = dData_400033d8;
			dData_40003418 = -dData_400033e0;
			dData_40003420 = dData_400033d8;
			dData_40003428 = dData_400033e0;
			bAscomCmd = 1;
			//->6d044
			break;

		case 37:
			//6cdd4: Set Site info
			g_bSlewingStop = 1;

			StopSlewing();

			dData_40002e28_SiteLongitude = fData_40003518_ReceiveExternalSiteLongitude;
			dData_40002e48_SiteLatitude = fData_4000351c_ReceiveExternalSiteLatitude;
			Data_40004128.geographicLongitude = fData_40003518_ReceiveExternalSiteLongitude;
			Data_40004128.geographicLatitude = fData_4000351c_ReceiveExternalSiteLatitude;
			bAscomCmd = 1;
			//->6d044
			break;

		case 38:
			//6ce50: Set DateTime
			g_bSlewingStop = 1;

			StopSlewing();

			Data_40002e54_Zone = fData_40003520;
			Data_40004128.timeZone = fData_40003520;

			CCR = (1 << 4); //clock from the 32 kHz oscillator that�s connected to the RTCX1 and RTCX2 pins
			YEAR = Data_40003524_ReceiveExternalYear;
			MONTH = bData_40003528_ReceiveExternalMonth;
			DOM = bData_40003529_ReceiveExternalDay;
			HOUR = bData_4000352a_ReceiveExternalHours;
			MIN = bData_4000352b_ReceiveExternalMinutes;
			SEC = bData_4000352c_ReceiveExternalSeconds;
			CCR = (1 << 4) | (1 << 0); //CLKEN = 1

			bAscomCmd = 1;
			//->6d044
			break;

		case 1:
			//6cef8
			if (bData_4000352e > 2)
			{
				//6cf0c
				if (bData_40002c1a == 2)
				{
					//6cf1c
					double sp32, sp24;
					convert_horizontal_to_equatorial(fData_40003508, fData_4000350c, &sp32, &sp24);
					fData_40003508 = sp32;
					fData_4000350c = sp24;
					dData_40003448 = sp32;
					dData_40003450 = sp24;
				}
				//6cfa8
				sp60.fData = fData_40003508;
				sp56.fData = fData_4000350c;

				sp40[4] = 0xff; //Ra & Dec ---Tracked
				sp40[5] = sp60.bData[0];
				sp40[6] = sp60.bData[1];
				sp40[7] = sp60.bData[2];
				sp40[8] = sp60.bData[3];
				sp40[9] = sp56.bData[0];
				sp40[10] = sp56.bData[1];
				sp40[11] = sp56.bData[2];
				sp40[12] = sp56.bData[3];

				uart0_send(sp40, 13);

				bData_4000352e = 0;
				//->6d038
			}
			else
			{
				//6d024
				bData_4000352e++;
			}
			//6d038 -> 6d044
			break;

		default:
			//6d03c
			break;
	}
}

