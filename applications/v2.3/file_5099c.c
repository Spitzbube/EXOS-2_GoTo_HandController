
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
	bData_40002c1a = 0;
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


