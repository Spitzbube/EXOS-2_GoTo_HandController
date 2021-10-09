
/* 6a0e4 - todo */
unsigned char ConvertKeyCode(void)
{
#ifndef OLIMEX_LPC2148
	unsigned char hwKey = get_hw_key_code();
	unsigned char menuKey;

	if (hwKey & 0x20) //Valid?
	{
		hwKey &= 0x1f;

		ack_hw_key();

		bData_40002c68 = 0;
		Data_400031e4 = 0;
	}
	else
	{
		hwKey = 100;
	}

	switch (hwKey)
	{
		case 1:
			//0x6a18c: 10100001 / 11100001
			menuKey = 16;
			break;

		case 2:
			//0x6a198: 10100010 / 11100010
			menuKey = 1;
			break;

		case 3:
			//0x6a1a4: 10100011 / 11100011
			menuKey = 4;
			break;

		case 4:
			//0x6a1b0: 10100100 / 11100100
			menuKey = 7;
			break;

		case 5:
			//0x6a1bc: 10100101 / 11100101
			menuKey = 10;
			break;

		case 6:
			//0x6a1c8: 10100110 / 11100110
			menuKey = 15;
			break;

		case 7:
			//0x6a1d4: 10100111 / 11100111
			menuKey = 2;
			break;

		case 8:
			//0x6a1e0: 10101000 / 11101000
			menuKey = 5;
			break;

		case 9:
			//0x6a1ec: 10101001 / 11101001
			menuKey = 8;
			break;

		case 10:
			//0x6a1f8: 10101010 / 11101010
			menuKey = 0;
			break;

		case 11:
			//0x6a204: 10101011 / 11101011
			menuKey = 17;
			break;

		case 12:
			//0x6a210: 10101100 / 11101100
			menuKey = 3;
			break;

		case 13:
			//0x6a21c: 10101101 / 11101101
			menuKey = 6;
			break;

		case 14:
			//0x6a228: 10101110 / 11101110
			menuKey = 9;
			break;

		case 15:
			//0x6a234: 10101111 / 11101111
			menuKey = 11;
			break;

		case 16:
			//0x6a240: 10110000 / 11110000
			menuKey = 14;
			break;

		case 17:
			//0x6a24c: 10110001 / 11110001
			menuKey = 19;
			break;

		case 18:
			//0x6a258: 10110010 / 11110010
			menuKey = 12;
			break;

		case 19:
			//0x6a264: 10110011 / 11110011
			menuKey = 20;
			break;

		case 20:
			//0x6a270: 10110100 / 11110100
			menuKey = 13;
			break;

		case 21:
			//0x6a27c
			menuKey = 21;
			break;

		case 22:
			//0x6a288
			menuKey = 22;
			break;

		case 23:
			//0x6a294
			menuKey = 23;
			break;

		case 24:
			//0x6a2a0
			menuKey = 24;
			break;

		default:
			//6a2ac
			SlewStop();
			SlewStop();
			break;
	}

	return menuKey;
#else
	return 0xFF;
#endif
}

/* 6a2cc - todo */
void UserInterfaceCycle(void)
{
	get_rtc_date_time();

	if (bData_40003505 != 0)
	{
		func_659c(10);
		ack_hw_key();

		if (bData_4000322d_AlarmTimeElapsed == 1)
		{
			bData_4000322c = 0;
			bData_4000322d_AlarmTimeElapsed = 0;
		}
	}
	//6a314
	bData_40002c69_KeyCode = ConvertKeyCode();

#if 0
	{
		char buf[30];
		snprintf(buf, sizeof(buf)-1, "bData_40002c68=0x%02x\n\r", bData_40002c68);
		uart0_send(buf, strlen(buf));

		snprintf(buf, sizeof(buf)-1, "bData_40003505=0x%02x\n\r", bData_40003505);
		uart0_send(buf, strlen(buf));
	}
#endif

	if (bData_40002c68 == 0)
	{
		//6a330
		if (g_bKeyBeepEnabled == 1)
		{
			key_beep(1);
		}
		//6a348
		switch (bData_40002c69_KeyCode)
		{
			case 0:
				//0x6a3c0: "0 / Stop"
				Handle0Key();
				bData_40003505 = 1;
				break;

			case 1:
				//0x6a3d8: "1"
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a40c
					Handle1Key();
				}
				bData_40003505 = 1;
				break;

			case 2:
				//0x6a420
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a454
					Handle2Key();
				}
				bData_40003505 = 1;
				break;

			case 3:
				//0x6a468
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a49c
					Handle3Key();
				}
				bData_40003505 = 1;
				break;

			case 4:
				//0x6a4b0
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a4e4
					Handle4Key();
				}
				bData_40003505 = 1;
				break;

			case 5:
				//0x6a4f8
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a52c
					Handle5Key();
				}
				bData_40003505 = 1;
				break;

			case 6:
				//0x6a540
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a574
					Handle6Key();
				}
				bData_40003505 = 1;
				break;

			case 7:
				//0x6a588
				Handle7Key();
				bData_40003505 = 1;
				break;

			case 8:
				//0x6a5a0
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a5d4
					Handle8Key();
				}
				bData_40003505 = 1;
				break;

			case 9:
				//0x6a5e8
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a61c
					Handle9Key();
				}
				bData_40003505 = 1;
				break;

			case 10:
				//0x6a630: "Help"
				HandleHelpKey();
				bData_40003505 = 1;
				break;

			case 11:
				//0x6a648: "F"
				HandleFKey();
				bData_40003505 = 1;
				break;

			case 12:
				//0x6a660: "+"
				HandlePlusKey();
				bData_40003505 = 1;
				break;

			case 13:
				//0x6a678: "-"
				HandleMinusKey();
				bData_40003505 = 1;
				break;

			case 14:
				//0x6a690: "Up"
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a6c4
					HandleUpKey();
				}
				bData_40003505 = 1;
				break;

			case 15:
				//0x6a6d8: "Down"
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a70c
					HandleDownKey();
				}
				bData_40003505 = 1;
				break;

			case 16:
				//0x6a720: "Left"
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a754
					HandleLeftKey();
				}
				bData_40003505 = 1;
				break;

			case 17:
				//0x6a768: "Right"
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a79c
					HandleRightKey();
				}
				bData_40003505 = 1;
				break;

			#if 0
			case 18:
				//0x6a900
			#endif

			case 19:
				//0x6a7b0: "Enter"
				HandleEnterKey();
				bData_40003505 = 1;
				break;

			case 22:
				//0x6a7c8
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a7fc
					func_4fda8();
				}
				bData_40003505 = 1;
				break;

			case 21:
				//0x6a810
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a844
					func_4fbc8();
				}
				bData_40003505 = 1;
				break;

			case 23:
				//0x6a858
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a88c
					func_4f9e4();
				}
				bData_40003505 = 1;
				break;

			case 24:
				//0x6a8a0
				if (((Data_40004128.bTrackingRequest != 0) &&
					(bTrackingMode == MENU_TRACKING_MODE_TRACKING/*2*/)) ||
					(Data_40004128.bTrackingRequest == 0))
				{
					//6a8d4
					func_4f804();
				}
				bData_40003505 = 1;
				break;

			case 20:
				//0x6a8e8: "*"
				HandleStarKey();
				bData_40003505 = 1;
				break;

			default:
				//6a900
				break;
		} //switch (bData_40002c69_KeyCode)

		bData_40002c68 = 1;
		//->6a948
	} //if (bData_40002c68 == 0)
	else
	{
		//6a91c
		bData_40003505 = 0;
		g_iSlewStepRaAxis = 0;
		g_iSlewStepDecAxis = 0;
		Data_40002e80 = 0;
		Data_40002e84 = 0;
	}

	//6a948

#if 0 //Without any function
	if ((Data_40002c64_MenuContextId != MENU_CONTEXT_MAIN) && //0
		(Data_40002c64_MenuContextId != MENU_CONTEXT_ALIGNMENT_STAR_CONTROL) && //12001
		(Data_40002c64_MenuContextId != MENU_CONTEXT_RA_BKBLASH_CORR_3RD_STEP_MOVING_LEFT_RIGHT) && //11103
		(Data_40002c64_MenuContextId != MENU_CONTEXT_DEC_BKBLASH_CORR_2ND_STEP_MOVING_UP_DOWN) && //11203
		(Data_40002c64_MenuContextId != MENU_CONTEXT_RA_BKBLASH_CORR_1ST_STEP_AIM_TARGET) && //11102
		(Data_40002c64_MenuContextId != MENU_CONTEXT_DEC_BKBLASH_CORR_1ST_STEP_AIM_TARGET) && //11202
		(bData_40003505 == 0))
	{
		if (bData_40002ef6 == 0)
		{
			bData_40002ef6 = 1;
			Data_40002ef8 = 0;
		}
		//->6aa04
	}
	else
	{
		//6a9f8
		bData_40002ef6 = 0;
	}
#endif

	//6aa04

	if (bData_40002f1e_SetupLocalData == 1)
	{
		//6aa14
		if (bData_400031ec != 0)
		{
			//6aa24
			get_rtc_date_time();

			sprintf(Data_400037ec, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40003150, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);
			sprintf(Data_40002655, "%04d-%02d-%02d", Data_40002e5c_Year, bData_40002e60_Month, bData_40002e61_Day);
			sprintf(Data_40002660, "%02d:%02d:%02d", bData_40002e62_Hours, bData_40002e63_Minutes, bData_40002e64_Seconds);

			bData_400031ec = 0;
		}
		//6aad4
	}
	//6aad4
	if (bHelpActive == 0)
	{
		DisplayScreenItems();
	}
	else
	{
		//0x6aaec
		DisplayHelpScreen();
	}
	//6aaf0
	if ((bData_4000322c == 1) &&
		(Data_40003220_AlarmHours == bData_40002e62_Hours) &&
		(Data_40003224_AlarmMinutes == bData_40002e63_Minutes) &&
		(Data_40003228_AlarmSeconds == bData_40002e64_Seconds))
	{
		bData_4000322d_AlarmTimeElapsed = 1;
	}
	//6ab54
	if (bData_4000322d_AlarmTimeElapsed == 1)
	{
		beep1(10);
	}
}

