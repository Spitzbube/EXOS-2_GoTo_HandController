
/* 20b94 - todo */
void DisplayMainScreen(void)
{
	lcd_display_string(0, 1, 1, strlen(g_pcstrMenuLine1), (unsigned char*)g_pcstrMenuLine1);
	lcd_display_string(0, 1, 14, strlen(g_pcstrMenuLine2), (unsigned char*)g_pcstrMenuLine2);

	if (g_bTargetSyncOpen == TRUE)
	{
		if (bData_400031eb == 0)
		{
			//20c18
			lcd_display_string(0, 2, 1, 22, ">>>>synchronizing<<<<");

			bData_400031eb = 1;
		}
		else
		{
			//0x20c44
			lcd_display_string(0, 2, 1, 22, "                      ");

			bData_400031eb = 0;
		}
	}
	else
	{
		//0x20c70
		lcd_display_string(0, 2, 1, 22, "                      ");
	}
	//0x20c8c
	lcd_display_string(0, 3, 1, strlen(g_pcstrMenuLine5), g_pcstrMenuLine5);
	lcd_display_string(0, 3, 6, 9, g_pcstrMenuLine6);
	lcd_display_string(0, 3, 16, 2, g_pcstrMenuLine6 + 10);
	lcd_display_string(0, 3, 19, 2, g_pcstrMenuLine6 + 13);

	lcd_display_bitmap(0, 3, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 3, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 3, 21, (unsigned char*)cBitmapSecond);

	if (abs(Data_40002e18_SiteLongitudeDegrees) < 100)
	{
		lcd_display_string(0, 3, 12, 1, " ");
	}

	if (abs(Data_40002e18_SiteLongitudeDegrees) < 10)
	{
		lcd_display_string(0, 3, 13, 1, " ");
	}

	if (abs(Data_40002e1c_SiteLongitudeMinutes) < 10)
	{
		lcd_display_string(0, 3, 16, 1, " ");
	}

	if (abs(fData_40002e20_SiteLongitudeSeconds) < 10)
	{
		lcd_display_string(0, 3, 19, 1, " ");
	}

	lcd_display_string(0, 4, 1, strlen(g_pcstrMenuLine7), g_pcstrMenuLine7);
	lcd_display_string(0, 4, 6, 9, g_pcstrMenuLine8);
	lcd_display_string(0, 4, 16, 2, g_pcstrMenuLine8 + 10);
	lcd_display_string(0, 4, 19, 2, g_pcstrMenuLine8 + 13);

	lcd_display_bitmap(0, 4, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 4, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 4, 21, (unsigned char*)cBitmapSecond);

	if (abs(Data_40002e38_SiteLatitudeDegrees) < 100)
	{
		lcd_display_string(0, 4, 12, 1, " ");
	}

	if (abs(Data_40002e38_SiteLatitudeDegrees) < 10)
	{
		lcd_display_string(0, 4, 13, 1, " ");
	}

	if (abs(Data_40002e3c_SiteLatitudeMinutes) < 10)
	{
		lcd_display_string(0, 4, 16, 1, " ");
	}

	if (abs(fData_40002e40_SiteLatitudeSeconds) < 10)
	{
		lcd_display_string(0, 4, 19, 1, " ");
	}

	lcd_display_string(0, 5, 1, strlen(g_pcstrMenuLine9), g_pcstrMenuLine9);
	lcd_display_string(0, 5, 6, 9, g_pcstrMenuLine10);
	lcd_display_string(0, 5, 16, 2, g_pcstrMenuLine10 + 10);
	lcd_display_string(0, 5, 19, 2, g_pcstrMenuLine10 + 13);

	if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
	{
#if 0
		//21138
		lcd_display_bitmap(0, 5, 15, (unsigned char*)cBitmapDegree);
		lcd_display_bitmap(0, 5, 18, (unsigned char*)cBitmapMinute);
		lcd_display_bitmap(0, 5, 21, (unsigned char*)cBitmapSecond);

		if (abs(Data_40002d20) < 100)
		{
			lcd_display_string(0, 5, 12, 1, " ");
		}

		if (abs(Data_40002d20) < 10)
		{
			lcd_display_string(0, 5, 13, 1, " ");
		}

		if (abs(Data_40002d24) < 10)
		{
			lcd_display_string(0, 5, 16, 1, " ");
		}

		if (abs(fData_40002d28) < 10)
		{
			lcd_display_string(0, 5, 19, 1, " ");
		}
#endif
	} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
	else
	{
		//0x2127c
		lcd_display_string(0, 5, 15, 1, "h");
		lcd_display_string(0, 5, 18, 1, "m");
		lcd_display_string(0, 5, 21, 1, "s");

		if (Data_40002cd8_ObjectRightAscensionHours < 100)
		{
			lcd_display_string(0, 5, 12, 1, " ");
		}

		if (Data_40002cd8_ObjectRightAscensionHours < 10)
		{
			lcd_display_string(0, 5, 13, 1, " ");
		}

		if (Data_40002cdc_ObjectRightAscensionMinutes < 10)
		{
			lcd_display_string(0, 5, 16, 1, " ");
		}

		if (fData_40002ce0_ObjectRightAscensionSeconds < 10)
		{
			lcd_display_string(0, 5, 19, 1, " ");
		}
	}
	//0x213c8
	lcd_display_string(0, 6, 1, strlen(g_pcstrMenuLine11), g_pcstrMenuLine11);
	lcd_display_string(0, 6, 6, 9, g_pcstrMenuLine12);
	lcd_display_string(0, 6, 16, 2, g_pcstrMenuLine12 + 10);
	lcd_display_string(0, 6, 19, 2, g_pcstrMenuLine12 + 13);

	lcd_display_bitmap(0, 6, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 6, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 6, 21, (unsigned char*)cBitmapSecond);

	if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
	{
#if 0
		//214ac
		if (abs(Data_40002d48) < 10)
		{
			lcd_display_string(0, 6, 13, 1, " ");
		}

		if (abs(Data_40002d4c) < 10)
		{
			lcd_display_string(0, 6, 16, 1, " ");
		}

		if (abs(fData_40002d50) < 10)
		{
			lcd_display_string(0, 6, 19, 1, " ");
		}
#endif
	} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
	else
	{
		//0x21574
		if (abs(Data_40002d00_ObjectDeclinationDegrees) < 10)
		{
			lcd_display_string(0, 6, 13, 1, " ");
		}

		if (abs(Data_40002d04_ObjectDeclinationMinutes) < 10)
		{
			lcd_display_string(0, 6, 16, 1, " ");
		}

		if (abs(fData_40002d08_ObjectDeclinationSeconds) < 10)
		{
			lcd_display_string(0, 6, 19, 1, " ");
		}
	}
	//0x21638
	lcd_display_string(0, 7, 1, strlen(g_pcstrMenuLine13), g_pcstrMenuLine13);
	lcd_display_string(0, 7, 6, 9, g_pcstrMenuLine14);
	lcd_display_string(0, 7, 16, 2, g_pcstrMenuLine14 + 10);
	lcd_display_string(0, 7, 19, 2, g_pcstrMenuLine14 + 13);

	if ((bData_400034b4 == 1) &&
		(bTrackingMode == MENU_TRACKING_MODE_TRACKING)) //2))
	{
		//216f0
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
#if 0
			lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
			lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
			lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);

			if (abs(Data_40002d20) < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}

			if (abs(Data_40002d20) < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}

			if (abs(Data_40002d24) < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}

			if (abs(fData_40002d28) < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
#endif
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21844
			lcd_display_string(0, 7, 15, 1, "h");
			lcd_display_string(0, 7, 18, 1, "m");
			lcd_display_string(0, 7, 21, 1, "s");

			if (Data_40002cd8_ObjectRightAscensionHours < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}

			if (Data_40002cd8_ObjectRightAscensionHours < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}

			if (Data_40002cdc_ObjectRightAscensionMinutes < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}

			if (fData_40002ce0_ObjectRightAscensionSeconds < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
		}
	}
	else
	{
		//0x21950
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			//21960
			lcd_display_bitmap(0, 7, 15, (unsigned char*)cBitmapDegree);
			lcd_display_bitmap(0, 7, 18, (unsigned char*)cBitmapMinute);
			lcd_display_bitmap(0, 7, 21, (unsigned char*)cBitmapSecond);

			if (abs(Data_40002dac) < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}

			if (abs(Data_40002dac) < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}

			if (abs(Data_40002db0) < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}

			if (abs(fData_40002db4) < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21aec
			lcd_display_string(0, 7, 15, 1, "h");
			lcd_display_string(0, 7, 18, 1, "m");
			lcd_display_string(0, 7, 21, 1, "s");

			if (Data_40002d68_OTARightAscensionHours < 100)
			{
				lcd_display_string(0, 7, 12, 1, " ");
			}

			if (Data_40002d68_OTARightAscensionHours < 10)
			{
				lcd_display_string(0, 7, 13, 1, " ");
			}

			if (Data_40002d6c_OTARightAscensionMinutes < 10)
			{
				lcd_display_string(0, 7, 16, 1, " ");
			}

			if (fData_40002d70_OTARightAscensionSeconds < 10)
			{
				lcd_display_string(0, 7, 19, 1, " ");
			}
		}
	}
	//0x21bf4
	lcd_display_string(0, 8, 1, strlen(g_pcstrMenuLine15), g_pcstrMenuLine15);
	lcd_display_string(0, 8, 6, 9, g_pcstrMenuLine16);
	lcd_display_string(0, 8, 16, 2, g_pcstrMenuLine16 + 10);
	lcd_display_string(0, 8, 19, 2, g_pcstrMenuLine16 + 13);

	lcd_display_bitmap(0, 8, 15, (unsigned char*)cBitmapDegree);
	lcd_display_bitmap(0, 8, 18, (unsigned char*)cBitmapMinute);
	lcd_display_bitmap(0, 8, 21, (unsigned char*)cBitmapSecond);

	if ((bData_400034b4 == 1) &&
		(bTrackingMode == MENU_TRACKING_MODE_TRACKING)) //2))
	{
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
#if 0
			if (abs(Data_40002d48) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}

			if (abs(Data_40002d4c) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}

			if (abs(fData_40002d50) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
#endif
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21dc0
			if (abs(Data_40002d00_ObjectDeclinationDegrees) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}

			if (abs(Data_40002d04_ObjectDeclinationMinutes) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}

			if (abs(fData_40002d08_ObjectDeclinationSeconds) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
		}
	}
	else
	{
		//0x21e88
		if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ) //0)
		{
			if (abs(Data_40002de0) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}

			if (abs(Data_40002de4) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}

			if (abs(fData_40002de8) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
		} //if (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
		else
		{
			//0x21f60
			if (abs(Data_40002d8c_OTADeclinationDegrees) < 10)
			{
				lcd_display_string(0, 8, 13, 1, " ");
			}

			if (abs(Data_40002d90_OTADeclinationMinutes) < 10)
			{
				lcd_display_string(0, 8, 16, 1, " ");
			}

			if (abs(fData_40002d94_OTADeclinationSeconds) < 10)
			{
				lcd_display_string(0, 8, 19, 1, " ");
			}
		}
	}
}

