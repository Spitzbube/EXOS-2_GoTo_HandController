
#if 0
#include <LPC214x.h>
#include "my_types.h"
#include "data.h"

extern void func_2df8(int a, int b, int c, int d, unsigned char* e);
extern void initialize_variables(void);
#endif


/* 5099c - todo */
void func_5099c(void)
{
	initialize_variables();
	
	bData_4000316e_FocusLineOn8LineDisplay = 0;
	Data_4000318c = 0;
	Data_40003190 = 1;
	bData_40003194 = 0;
	bData_40003196_CurrentLanguage = MENU_LANGUAGE_ENGLISH; //1;
	g_bSingleSlewActive = 0;
	g_bCombinedSlewActive = 0;
	bCapsLock = 0;
	bMapKeyToCharIndex = 0;
	g_bMountType = 0;
	bGotoParkPosition = 0;
	bData_40003210 = 0;
	bData_40003211 = 0;
	bData_400031bf = 0x42;
	bData_400031be = 0;
	fData_400031c0 = 10.6;
	fData_400031c4 = 63.25;
	bData_400031e0 = 1;
	bRaBacklashCorrectionDirection = 0;
	bDecBacklashCorrectionDirection = 0;
	bData_40003195 = 0;
	bData_400031e1 = 0;
	bData_400032a4_OTAZeroDataErrorCount = 0;
	bData_4000319b = 0;
	bData_400031e9 = 0;
	g_bMaxSlewRampActive = 0;
	bData_400031b9 = 0;
	Data_40002e80 = 0;
	Data_40002e84 = 0;
	bData_4000322d_AlarmTimeElapsed = 0;
	g_bTargetSyncOpen = FALSE;
	bData_400031eb = 0;
	bData_400031ec = 1;
	bSystemInitialized = 1;
	dData_400031f0 = 0.0;
	dData_400031f8 = 0.0;
	bData_40003200 = 0;
	bData_40003201 = 0;
	iMountAutoguideRa = 0;
	iMountAutoguideDec = 0;
	bData_40002d88 = 0;
	bData_40002da8 = 0;
}


/* 50b40 - todo */
void HandleReset(void)
{
	char sp40[528];
	unsigned char customSiteName[20];
	float lon;
	float lat;
	int zone;
	unsigned short i;

	lcd_display_clear();
	lcd_display_string(0, 4, 1, 21, "System resetting...    ");

	i = 0;
	for (i = 0; i < 16; i++)
	{
		//0x50b74
		flash_read((unsigned short)(0xddd + i), 0, sizeof(sp40), sp40);
		flash_write((unsigned short)(0xdc9 + i), 0, sizeof(sp40), sp40);
	}

	func_d2cc();
	func_5099c();

	UART1_WRITE_HEADER(1);
	uart1_write_byte(0x44);

	UART1_WRITE_HEADER(1);
	uart1_write_byte(0x64);

	UART1_WRITE_HEADER(1);
	uart1_write_byte(0x04);

	UART1_WRITE_HEADER(1);
	uart1_write_byte(0x24);

	func_659c(10);

	if (g_bMountType == 1)
	{
		bData_40002e7a_MountType = MENU_MOUNT_TYPE_EQU; //1;
	}
	else
	{
		bData_40002e7a_MountType = MENU_MOUNT_TYPE_AZ; //0;
	}
	//50c98
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;

	flash_get_ota_zero_data(&fData_4000329c, &fData_400032a0);

	Data_40004128.dData_192 = fData_4000329c;
	Data_40004128.dData_200 = fData_400032a0;

	flash_get_custom_site_data(customSiteName, &lon, &lat, &zone);

	Data_40004128.geographicLongitude = lon;
	Data_40004128.geographicLatitude = lat;

	Data_40002e54_Zone = zone;

	strCustomSiteName[6] = customSiteName[0];
	strCustomSiteName[7] = customSiteName[1];
	strCustomSiteName[8] = customSiteName[2];
	strCustomSiteName[9] = customSiteName[3];
	strCustomSiteName[10] = customSiteName[4];
	strCustomSiteName[11] = customSiteName[5];
	strCustomSiteName[12] = customSiteName[6];
	strCustomSiteName[13] = customSiteName[7];

	if (lon > 0) //BUG? East is negative!
	{
		//50d90
		sprintf(strCustomSiteLongitude, "  Lon:E%03dd%02df ",
			DEGREES_MINUTES(lon));
	}
	else
	{
		//0x50edc
		sprintf(strCustomSiteLongitude, "  Lon:W%03dd%02df ",
			DEGREES_MINUTES(lon)); //Bug: abs()?
	}
	//0x50f30
	if (lat > 0)
	{
		//50f40
		sprintf(strCustomSiteLatitude, "  Lat:N%02dd%02df ",
			DEGREES_MINUTES(lat));
	}
	else
	{
		//0x50f98
		sprintf(strCustomSiteLatitude, "  Lat:S%02dd%02df ",
			DEGREES_MINUTES(lat)); //Bug: abs()
	}
	//0x50fec
	if (zone > 0)
	{
		sprintf(strCustomSiteTimezone, " Zone:E%02d", zone);
	}
	else
	{
		//0x5100c
		sprintf(strCustomSiteTimezone, " Zone:W%02d", zone);
	}

	func_659c(2000);
	beep1(2);
	func_659c(100);

	Data_40002c64_MenuContextId = MENU_CONTEXT_MAIN; //0;
}

