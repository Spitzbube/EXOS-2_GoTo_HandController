

#define _PI_180 0.0174532925199444438613127772442

typedef union
{
	unsigned char bData[4];
	int dwData; 
} Union_400033c8; //400033c8

typedef union
{
	unsigned char bData[4];
	int dwData; 
} Union_400033cc; //400033cc

typedef union
{
	unsigned char bData[2]; 
	unsigned short wData;
} Union_40002c24;

typedef union
{
	unsigned char bData[4]; 
	int Data;
	float fData;
} Union_40002c28;

typedef union
{
	unsigned char bData[4]; 
	int Data;
} Union_400031a0;

typedef union
{
	unsigned char bData[4];
	int dwData; 
} Union_40003500; //40003500

typedef struct
{
	int Data_0; //0
	double dData_8; //8
	double dData_16; //16
	double dData_24; //24
	double dData_32; //32
	int Data_40; //40
	unsigned char bData_44; //44
	double geographicLongitude; //48
	double geographicLatitude; //56
	int timeZone; //64
	int Data_68; //68
	double dObjRectascension; //72
	double dObjDeclination; //80
	double dData_88; //88
	double dJulianDay; //96
	double dFractionalDay; //104
	double dData_112; //112
	double dData_120; //120
	double dObjPositionRaAxis; //128
	double dObjPositionDecAxis; //136
	double dObjHourAngleDisplay; //144
	double dObjDeclinationDisplay; //152
	double dTargetPositionRaAxis; //160
	double dTargetPositionDecAxis; //168
	double dData_176; //176
	double dData_184; //184
	double dData_192; //192
	double dData_200; //200
	double dMotorPositionRaAxis; //208
	double dMotorPositionDecAxis; //216
	double dRaPositionDelta; //224
	double dDecPositionDelta; //232
	double dData_240; //240
	double dData_248; //248
	double dData_256; //256
	double dData_264; //264
	double dData_272; //272
	double dData_280; //280
	double dData_288; //288
	double dData_296; //296
	double dData_304; //304
	double dData_312; //312
	int fill_320[2]; //320
	double dOffsetRa; //328
	double dOffsetDec; //336
	char bData_344; //344
	char bData_345; //345
	int Data_348; //348
	int alignmentPause; //352
	unsigned char bTrackingActive; //356
	unsigned char bTrackingRequest; //357
	unsigned char bData_358; //358
	int numAlignmentStars; //360
	unsigned char bAlignmentComplete; //364
	char bData_365; //365
	int Data_368; //368
	int alignmentStarIndex; //372
	double dFirstAlignmentStarRa; //376
	double dFirstAlignmentStarDec; //384
	double dSecondAlignmentStarRa; //392
	double dSecondAlignmentStarDec; //400
	double dThirdAlignmentStarRa; //408
	double dThirdAlignmentStarDec; //416
	double dData_424; //424
	double dData_432; //432
	double dData_440; //440
	double dData_448; //448
	double dData_456; //456
	double dData_464; //464
	double dData_472; //472
	double dData_480; //480
	double dData_488; //488
	double dData_496; //496
	double dData_504; //504
	double dData_512; //512
	double dData_520; //520
	double dData_528; //528
	double dData_536; //536
	double dData_544; //544
	double dData_552; //552
	double dData_560; //560
	double dData_568; //568
	double dData_576; //576
	double dAutoguideRa; //584
	double dAutoguideDec; //592
	
} Struct_40004128;

typedef struct
{
	double dData_0; //0
	double dData_8; //8
	double dData_16; //16
	double dData_24; //24
	double dData_32; //32
	double dData_40; //40
	
} Struct_40004380;

extern char strCustomerObjectRaAziInputForTracking[]; //400022f2
extern char Data_40002302[]; //40002302
extern char strEngTelescopeOneMX51[]; //40002387
extern char Data_4000239a[]; //4000239a
extern char Data_40002474[]; //40002474
extern char Data_40002481[]; //40002487
extern char Data_4000248c[]; //4000248c
extern char Data_400024a1[]; //400024a1
extern char Data_400024b5[]; //400024b5
extern char Data_400024c9[]; //400024c9
extern char Data_400024d6[]; //400024d6
extern char Data_400024e1[]; //400024e1
extern char Data_400024ef[]; //400024ef
extern char Data_40002504[]; //40002504
extern unsigned char Data_4000251d[]; //4000251d
extern unsigned char Data_4000253d[]; //4000253d
extern unsigned char Data_4000255d[]; //4000255d
extern unsigned char Data_4000257e[]; //4000257e
extern unsigned char Data_4000258c[]; //4000258c
extern unsigned char Data_400025a0[]; //400025a0
extern unsigned char Data_400025b5[]; //400025b5
extern unsigned char Data_400025d9[]; //400025d9
extern unsigned char Data_400025fe[]; //400025fe
extern unsigned char Data_40002625[]; //40002625
extern unsigned char Data_40002634[]; //40002634
extern unsigned char Data_40002644[]; //40002644
extern char Data_40002655[]; //40002655
extern char Data_40002660[]; //40002660
extern unsigned char Data_400026c3[]; //400026c3
extern unsigned char Data_400026db[]; //400026db
extern unsigned char Data_400026f3[]; //400026f3
extern unsigned char Data_4000270a[]; //4000270a
extern unsigned char Data_4000271a[]; //4000271a
extern unsigned char Data_40002789[]; //40002789
extern unsigned char Data_40002792[]; //40002792
extern char strInputRaDec[]; //400027cf
extern unsigned char strCustomerObjectRaAziInputForStoring[]; //400027df
extern unsigned char strCustomerObjectDecAltInputForStoring[]; //400027ef
extern unsigned char strCustomerObjectNameInput[]; //400027ff
extern unsigned char strCustomSiteName[]; //40002827
extern unsigned char strCustomSiteLongitude[]; //40002837
extern unsigned char strCustomSiteLatitude[]; //40002847
extern unsigned char strCustomSiteTimezone[]; //40002856
extern unsigned char strCustomSiteAltitude[]; //40002861
extern char strSkyTarget[]; //4000288e
extern char strLandTarget[]; //40002899
extern char strAltTelescope[]; //400028a5
extern char strEquTelescope[]; //400028b3
extern char strEngPleaseSetupOtaZero[]; //400028c1
extern unsigned char Data_400028d7[]; //400028d7
extern unsigned char Data_400028e1[]; //400028e1
extern char Data_400028eb[]; //400028eb
extern char Data_40002901[]; //40002901
extern char strEngEnglish[]; //40002916
extern char strEngGerman[]; //4000291e
extern char strEngFrench[]; //40002925
extern char strEngItalian[]; //4000292c
extern char strEngSpanish[]; //40002934
extern char Data_4000294a[]; //4000294a
extern char strEngSetTimer[]; //400029a1
extern char strEng00000s[]; //400029ac
extern char Data_400029b3[]; //400029b3
extern char strEngStartBack[]; //400029b4
extern char strEngCountingDown[]; //400029ca
extern char strEngTimeRemain[]; //400029da
extern char strEngTimeRemain00000s[]; //400029e7
extern char strEngStopBack[]; //400029ee
extern char Data_40002a3f[]; //40002a3f
extern char Data_40002a42[]; //40002a42
extern char Data_40002a45[]; //40002a45
extern char strEngCloseAlarm[]; //40002a62
extern char strEngAlarmCloseBack[]; //40002a71
extern char strEngInputTime[]; //40002a87
extern char strEngAlarm21h34m23s[]; //40002a94
extern char strEngAlarmOnBack[]; //40002a9e
extern char strEngBackgroundLight[]; //40002acb
extern char strEngPressUpDownKey[]; //40002adc
extern char Data_40002aee[]; //40002aee
extern char Data_40002aef[]; //40002aef
extern char Data_40002b70[]; //40002b70
extern char Data_40002b80[]; //40002b80
extern char Data_40002b8a[]; //40002b8a
extern char Data_40002b8b[]; //40002b8b
extern char Data_40002ba5[]; //40002ba5
extern char Data_40002bb5[]; //40002bb5
extern char Data_40002bc0[]; //40002bc0
extern char Data_40002bc1[]; //40002bc1
extern int Data_40002bc4_DayYear[]; //40002bc4
extern unsigned char sHwKeyQueue[8]; //40002bf8, size??
extern unsigned char bHwKeyQueueReadPtr; //40002c00
extern unsigned char bHwKeyQueueWritePtr; //40002c01
extern unsigned char bData_40002c02; //40002c02
extern unsigned char bData_40002c03; //40002c03
extern unsigned char bHwKeyCode; //40002c04
extern unsigned char bData_40002c05; //40002c05
extern unsigned char bTimer10msCounter; //40002c06
extern unsigned char bData_40002c07; //40002c07
extern unsigned char bData_40002c08; //40002c08
extern unsigned char bData_40002c09; //40002c09
extern unsigned char bData_40002c0a_uart0ReceiveDataCount; //40002c0a
extern char uart0ReceiveFlag; //40002c0b
extern unsigned char bData_40002c0c_uart0ReceiveStep; //40002c0c
extern unsigned char Data_40002c0d_uart0ReceiveHeader[4]; //40002c0d
extern unsigned char uart0_bRxData; //40002c11
extern unsigned char bData_40002c12_uart1ReceiveDataCount; //40002c12
extern char bData_40002c13_uart1ReceiveComplete; //40002c13
extern unsigned char bData_40002c14_uart1ReceiveStep; //40002c14
extern unsigned char bData_40002c15_uart1ReceiveHeader[4]; //40002c15
extern unsigned char uart1_bRxData; //40002c19
extern unsigned char bData_40002c1a; //40002c1a // V2.2: 40002c1e
extern int g_iUart0GuideValueRa; //40002c1c
extern int g_iUart0GuideValueDec; //40002c20
extern Union_40002c24 Data_40002c24; //40002c24
extern Union_40002c28 Data_40002c28; //40002c28
extern char bHelpActive; //40002c58
extern unsigned char bData_40002c59_MainScreenHelpPage; //40002c59
extern char bData_40002c5a; //40002c5a
extern int Data_40002c5c_AlignmentStarCount; //40002c5c
extern unsigned char bData_40002c60_CurrentAlignStarIndex; //40002c60
extern unsigned char bData_40002c61; //40002c61
extern unsigned char bData_40002c62_AlignmentStarMode; //40002c62
extern int Data_40002c64_MenuContextId; //40002c64
extern char bData_40002c68; //40002c68
extern unsigned char bData_40002c69_KeyCode; //40002c69
extern char bDaylightSavingTime; //40002c6a
extern double dObjectRiseTime; //40002c70
extern double dObjectTransitTime; //40002c78
extern double dObjectSetTime; //40002c80
extern double dData_40002c88; //40002c88
extern double dData_40002c90; //40002c90
extern double dTrackingRate; //40002c98
extern double dGuidingSpeed; //40002ca0
extern double g_dPoleAxisDevEastWest; //40002ca8
extern double g_dPoleAxisDevNorthSouth; //40002cb0
extern int Data_40002cb8; //40002cb8
extern int Data_40002cbc; //40002cbc
extern float fData_40002cc0; //40002cc0
extern double dData_40002cc8; //40002cc8
extern float fData_40002cd0_ObjectRightAscension; //40002cd0
extern int Data_40002cd8_ObjectRightAscensionHours; //40002cd8
extern int Data_40002cdc_ObjectRightAscensionMinutes; //40002cdc
extern float fData_40002ce0_ObjectRightAscensionSeconds; //40002ce0
extern double g_dObjectRightAcension; //40002ce8
extern int Data_40002cf4; //40002cf4
extern int Data_40002cf8; //40002cf8
extern float fData_40002cfc; //40002cfc
extern int Data_40002d00_ObjectDeclinationDegrees; //40002d00
extern int Data_40002d04_ObjectDeclinationMinutes; //40002d04
extern float fData_40002d08_ObjectDeclinationSeconds; //40002d08
extern double dData_40002d10; //40002d10
extern float fData_40002d18_ObjectDeclination; //40002d18

#if 0 //(bData_40002c1a == 2) && (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
extern int Data_40002d20; //40002d20
extern int Data_40002d24; //40002d24
extern float fData_40002d28; //40002d28
extern double dData_40002d30; //40002d30
#endif

extern int Data_40002d40; //40002d40
extern int g_iObjectDeclinationSign; //40002d44

#if 0 //(bData_40002c1a == 2) && (bData_40002e7a_MountType == MENU_MOUNT_TYPE_AZ)
extern int Data_40002d48; //40002d48
extern int Data_40002d4c; //40002d4c
extern float fData_40002d50; //40002d50
extern double dData_40002d58; //40002d58
#endif

extern int Data_40002d68_OTARightAscensionHours; //40002d68
extern int Data_40002d6c_OTARightAscensionMinutes; //40002d6c
extern float fData_40002d70_OTARightAscensionSeconds; //40002d70
extern double dData_40002d78; //40002d78
extern double g_dMotorPositionRaAxis; //40002d80
extern char bData_40002d88; //40002d88
extern int Data_40002d8c_OTADeclinationDegrees; //40002d8c
extern int Data_40002d90_OTADeclinationMinutes; //40002d90
extern float fData_40002d94_OTADeclinationSeconds; //40002d94
extern double dData_40002d98; //40002d98
extern double g_dMotorPositionDecAxis; //40002da0
extern char bData_40002da8; //40002da8
extern int Data_40002dac; //40002dac
extern int Data_40002db0; //40002db0
extern float fData_40002db4; //40002db4
extern double g_dMotorPositionAziAxis; //40002db8
extern double dData_40002dc0_Azimuth; //40002dc0
extern double dRaBklashCorrStartAzimuth; //40002dc8
extern double dData_40002dd0; //40002dd0
extern int Data_40002de0; //40002de0
extern int Data_40002de4; //40002de4
extern float fData_40002de8; //40002de8
extern double g_dMotorPositionAltAxis; //40002df0
extern double dData_40002df8; //40002df8
extern double dData_40002e00; //40002e00
extern double dData_40002e08; //40002e08
extern int Data_40002e18_SiteLongitudeDegrees; //40002e18
extern int Data_40002e1c_SiteLongitudeMinutes; //40002e1c
extern float fData_40002e20_SiteLongitudeSeconds; //40002e20
extern double dData_40002e28_SiteLongitude; //40002e28
extern float fCustomSiteLongitude; //40002e30
extern int Data_40002e34; //40002e34
extern int Data_40002e38_SiteLatitudeDegrees; //40002e38
extern int Data_40002e3c_SiteLatitudeMinutes; //40002e3c
extern float fData_40002e40_SiteLatitudeSeconds; //40002e40
extern int Data_40002e44; //40002e44
extern double dData_40002e48_SiteLatitude; //40002e48
extern float fCustomSiteLatitude; //40002e50
extern int Data_40002e54_Zone; //40002e54
extern int iCustomSiteTimeZone; //40002e58
extern unsigned Data_40002e5c_Year; //40002e5c
extern unsigned char bData_40002e60_Month; //40002e60
extern unsigned char bData_40002e61_Day; //40002e61
extern unsigned char bData_40002e62_Hours; //40002e62
extern unsigned char bData_40002e63_Minutes; //40002e63
extern unsigned char bData_40002e64_Seconds; //40002e64
extern unsigned short wRtcMilliSeconds; //40002e66
extern unsigned char bDateTimeInputMode; //40002e78
extern unsigned char bData_40002e79_SkyLandTargetSeletion; //40002e79
extern unsigned char bData_40002e7a_MountType; //40002e7a
extern unsigned char bData_40002e7b_GpsAvailable; //40002e7b
extern unsigned char bData_40002e7c_TrackingRateType; //40002e7c
extern unsigned char g_eSlewRateIndex; //40002e7d
extern char bData_40002e7e; //40002e7e
extern int Data_40002e80; //40002e80
extern int Data_40002e84; //40002e84
extern unsigned char bTrackingMode; //40002e88
extern char g_bSlewingStop; //40002e89
extern unsigned char bTrackingModeMenu; //40002e8a
extern char bData_40002e8b; //40002e8b
extern char bData_40002e8c; //40002e8c
extern float fData_40002e90; //40002e90
extern float Data_40002e94; //40002e94
extern float fData_40002e98; //40002e98
extern float Data_40002e9c; //40002e9c
extern float fData_40002ea0; //40002ea0
extern float fData_40002ea4; //40002ea4
extern float fData_40002ea8; //40002ea8
extern float fData_40002eac; //40002eac
extern int iBacklashCorrectionSlewing; //40002eb0
extern unsigned char bData_40002eb4; //40002eb4
extern unsigned char bData_40002eb5_SolarSystemObjectNr; //40002eb5
extern unsigned short wData_40002eb6; //40002eb6
extern unsigned short wData_40002eb8_MessierNr; //40002eb8
extern unsigned short wData_40002eba_NGCNr; //40002eba
extern unsigned short wData_40002ebc_ICNr; //40002ebc
extern unsigned short wData_40002ebe_ShNr; //40002ebe
extern unsigned short wData_40002ec0_BrightStarNr; //40002ec0
extern unsigned int Data_40002ec4_SAONr; //40002ec4
extern unsigned int Data_40002ec8_NavigationDirectInputNr; //40002ec8
extern unsigned short wData_40002ecc; //40002ecc
extern unsigned char bData_40002ece_ConstellationNr; //40002ece
extern unsigned short wData_40002ed0; //40002ed0
extern unsigned char bData_40002ed2_FamousStarNr; //40002ed2
extern unsigned short wData_40002ed4; //40002ed4
extern unsigned short wData_40002ed6; //40002ed6
extern unsigned short wData_40002ed8; //40002ed8
extern unsigned short wData_40002eda; //40002eda
extern unsigned char bData_40002edc; //40002edc
extern unsigned char bData_40002edd; //40002edd
extern char bData_40002ede; //40002ede
extern char bData_40002edf; //40002edf
extern char bData_40002ef6; //40002ef6
extern char bData_40002ef7; //40002ef7
extern int Data_40002ef8; //40002ef8
extern float fData_40002efc; //40002efc
extern float fData_40002f00; //40002f00
extern int Data_40002f04; //40002f04
extern int Data_40002f08; //40002f08
extern char bData_40002f0c; //40002f0c
extern unsigned char bData_40002f0d_RecentTargetType; //40002f0d
extern int bData_40002f10_RecentTargetId; //40002f10
extern unsigned char bData_40002f14_RecentTargetCount; //40002f14
extern unsigned char Data_40002f15_RecentTargetTypeArray[]; //40002f15, size???
extern unsigned char bData_40002f1d; //40002f1d
extern char bData_40002f1e_SetupLocalData; //40002f1e

extern char* strTelescopeAlign; //40002f20
extern char* strNavigation; //40002f24
extern char* strUtilities; //40002f28
extern char* strSetup; //40002f2c
extern char* strOneStarAlign; //40002f30
extern char* strTwoStarAlign; //40002f34
extern char* strThreeStarAlign; //40002f38
extern char* strTargetSync; //40002f3c
extern char* strPoleAxisDev; //40002f40
extern char* strRaBklashCorr; //40002f44
extern char* strDecBklashCorr; //40002f48
extern char* strAlignmentSpare1; //40002f4c
extern char* strAlignmentSpare2; //40002f50
extern char* strAlignmentSpare3; //40002f54
extern char* strAlignmentSpare4; //40002f58
extern char* strSolarSystem; //40002f5c
extern char* strConstellation; //40002f60
extern char* strFamousStar; //40002f64
extern char* g_pcstrMessierCatalogue; //40002f68
extern char* g_pcstrNGCCatalogue; //40002f6c
extern char* g_pcstrICCatalogue; //40002f70
extern char* g_pcstrSh2Catalogue; //40002f74
extern char* g_pcstrBrightStarCatalogue; //40002f78
extern char* g_pcstrSAOStarCatalogue; //40002f7c
extern char* g_pcstrCustomerObjects; //40002f80
extern char* g_pcstrInputRAandDEC; //40002f84
extern char* g_pcstrCustomLandGoal; //40002f88
extern char* strCurrentObjects; //40002f8c
extern char* Data_40002f90; //40002f90
extern char* Data_40002f94; //40002f94
extern char* Data_40002f98; //40002f98
extern char* Data_40002f9c; //40002f9c
extern char* Data_40002fa0; //40002fa0
extern char* Data_40002fa4; //40002fa4
extern char* Data_40002fa8; //40002fa8
extern char* strParkposition; //40002fac
extern char* Data_40002fb0; //40002fb0
extern char* strTimeAndDate; //40002fb4
extern char* g_pcstrDaylightSaving; //40002fb8
extern char* g_pcstrEngSiteSetting; //40002fbc
extern char* g_pcstrSkyLand; //40002fc0
extern char* g_pcstrAzEqu; //40002fc4
extern char* strTelescopeMount; //40002fc8
extern char* strTrackingRate; //40002fcc
extern char* g_pcstrLanguage; //40002fd0
extern char* strReset; //40002fd4
extern char* g_pcstrSetupSpare1; //40002fd8
#if 1
extern char* g_pcstrSetupSpare2;
extern char* g_pcstrSetupSpare3;
#endif
extern char* Data_40002fdc; //40002fdc
extern char* Data_40002fe0; //40002fe0
extern char* Data_40002fe4; //40002fe4
extern char* Data_40002fe8; //40002fe8
extern char* Data_40002fec; //40002fec
extern char* Data_40002ff0; //40002ff0
extern char* Data_40002ff4; //40002ff4
extern char* Data_40002ff8; //40002ff8
extern char* Data_40002ffc; //40002ffc
extern char* Data_40003000; //40003000
extern char* Data_40003004; //40003004
extern char* Data_40003008; //40003008
extern char* Data_4000300c; //4000300c
extern char* Data_40003010; //40003010
extern char* Data_40003014; //40003014
extern char* Data_40003018; //40003018
extern char* Data_4000301c; //4000301c
extern char* Data_40003020; //40003020
extern char* Data_40003024; //40003024
extern char* strScientificName; //40003028
extern char* strSAOCatalog; //4000302c
extern char* strHRCatalog; //40003030
extern char* strSelect; //40003034
extern char* strAdd; //40003038
extern char* strDelete; //4000303c
extern char* strModify; //40003040
extern char* Data_40003044;
extern char* Data_40003048;
extern char* Data_4000304c;
extern char* strEyeshot; //40003050
extern char* strRatio; //40003054
extern char* strBackBoard; //40003058
extern char* strAccessory; //4000305c
extern char* strCountryAndCity; //40003060
extern char* strCustomSite; //40003064
extern char* Data_40003068;
extern char* Data_4000306c;
extern char* Data_40003070;
extern char* Data_40003074;
extern char* Data_40003078;
extern char* Data_4000307c;
extern char* Data_40003080;
extern char* Data_40003084;
extern char* strStarSpeed; //40003088
extern char* strSolarSpeed; //4000308c
extern char* strMoonSpeed; //40003090
extern char* Data_40003094;
extern char* Data_40003098;
extern char* strListAlignStars; //4000309c
extern char* strSlewingTo; //400030a0
extern char* strAutoloadAlignStars; //400030a4
extern char* Data_400030a8;
extern char* Data_400030ac;
extern char* Data_400030b0;
extern char* Data_400030b4;
extern char* Data_400030b8;
extern char* Data_400030bc;
extern char* strThereIsNoTele; //400030c0
extern char* strScopeToConnectThis; //400030c4
extern char* strControlTerminal; //400030c8
extern char* strPleaseAimAtThe; //400030cc
extern char* strTelescopeToDistant; //400030d0
extern char* strTargetThenPress; //400030d4
extern char* strEnterKey; //400030d8
extern char* Data_400030dc;
extern char* Data_400030e0;
extern char* Data_400030e4;
extern char* Data_400030e8;
extern char* Data_400030ec;
extern char* Data_400030f0;
extern char* Data_400030f4;
extern char* Data_400030f8;
extern char* Data_400030fc;
extern char* Data_40003100;
extern char* Data_40003104;
extern char* Data_40003108;
extern char* Data_4000310c;
extern char* Data_40003110;
extern char* Data_40003114;
extern char* Data_40003140; //40003140
extern unsigned char bCurrentCustomSiteInputLine; //40003144
extern char* Data_4000314c_SolarSystemObjectName; //4000314c
extern char Data_40003150[]; //40003150, size??
extern char arCustomSiteName[]; //40003159, size??
extern unsigned char bData_40003161; //40003161
extern char bData_40003162; //40003162
extern int Data_40003164_LunarPhaseYear; //40003164
extern int Data_40003168_LunarPhaseMonth; //40003168
extern unsigned char bData_4000316d; //4000316d
extern unsigned char bData_4000316e_FocusLineOn8LineDisplay; //4000316e
extern unsigned char bData_4000316f_FocusLineOn4LineDisplay; //4000316f
extern unsigned char g_bAlignmentEightLineMenuTopItem; //40003170
extern unsigned char g_bAlignmentFourLineMenuTopItem; //40003171
extern unsigned char g_bAlignmentEightLineMenuFocusItem; //40003172
extern unsigned char g_bAlignmentFourLineMenuFocusItem; //40003173
extern unsigned char bData_40003174; //40003174
extern unsigned char bData_40003175; //40003175
extern unsigned char bData_40003176; //40003176
extern unsigned char bData_40003177; //40003177
extern unsigned char bData_40003178; //40003178
extern unsigned char bData_40003179; //40003179
extern unsigned char bData_4000317a; //4000317a
extern unsigned char bData_4000317b; //4000317b
extern unsigned char g_bSetupEightLineMenuTopItem; //4000317c
extern unsigned char bData_4000317d; //4000317d
extern unsigned char g_bSetupEightLineMenuFocusItem; //4000317e
extern unsigned char bData_4000317f; //4000317f
extern unsigned char bData_40003180; //40003180
extern unsigned char bData_40003182; //40003182
extern unsigned char bData_40003184; //40003184
extern unsigned char bData_40003186; //40003186
extern char bRaBacklashCorrectionDirection; //40003188
extern char bDecBacklashCorrectionDirection; //40003189
extern unsigned char bCharacterInputPosition; //4000318a
extern int g_iMenuContextIdNew; //4000318c
extern int g_iMenuContextIdOld; //40003190
extern char bData_40003194; //40003194
extern unsigned char g_iLedTorchLevel; //40003195
extern unsigned char bData_40003196_CurrentLanguage; //40003196
extern unsigned char bData_40003197_DisplayLinesPerMenuLine; //40003197
extern char bCapsLock; //40003198
extern unsigned char bMapKeyToCharIndex; //40003199
extern unsigned char bData_4000319a_SkyLandTargetId; //4000319a
extern char bData_4000319b; //4000319b
extern char g_bSingleSlewActive; //4000319c
extern char g_bCombinedSlewActive; //4000319d
extern Union_400031a0 Data_400031a0; //400031a0
extern Union_400031a0 g_stCurrentSlewRampValue; //400031a4
extern int Data_400031a8; //400031a8
extern Union_400031a0 Data_400031ac; //400031ac
extern int g_iCurrentSlewRampIndex; //400031b4
extern char g_bMaxSlewRampActive; //400031b8
extern char bData_400031b9; //400031b9
extern char bData_400031ba; //400031ba
extern char bData_400031bb; //400031bb
extern char bData_400031bc; //400031bc
extern char bData_400031bd; //400031bd
extern char bData_400031be; //400031be
extern unsigned char bData_400031bf; //400031bf
extern float fData_400031c0; //400031c0
extern float fData_400031c4; //400031c4
extern char bData_400031e0; //400031e0
extern char bData_400031e1; //400031e1
extern int Data_400031e4; //400031e4
extern unsigned char bCustomerObjectNameChar; //400031e8
extern char bData_400031e9; //400031e9
extern char g_bTargetSyncOpen; //400031ea
extern char bData_400031eb; //400031eb
extern char bData_400031ec; //400031ec
extern char bSystemInitialized; //400031ed
extern double dData_400031f0; //400031f0
extern double dData_400031f8; //400031f8
extern char bData_40003200; //40003200
extern char bData_40003201; //40003201
extern int iMountAutoguideRa; //40003204
extern int iMountAutoguideDec; //40003208
extern char bData_40003210; //40003210
extern char bData_40003211; //40003211
extern int Data_40003214_UserTimerSeconds; //40003214
extern int Data_40003220_AlarmHours; //40003220
extern int Data_40003224_AlarmMinutes; //40003224
extern int Data_40003228_AlarmSeconds; //40003228
extern char bData_4000322c; //4000322c
extern char bData_4000322d_AlarmTimeElapsed; //4000322d
extern float fMainFocalLength; //40003230
extern float fSecondaryFocalLength; //40003234
extern float fEyepieceMagnification; //40003238
extern float fEyepieceFOV; //4000323c
extern float fFieldOfView; //40003240
extern int Data_40003248_CurrentDisplayPWM; //40003248
extern unsigned short wData_40003250; //40003250
extern unsigned short wData_40003252; //40003252
extern unsigned short wData_40003256; //40003256
extern unsigned char bData_40003258; //40003258
extern unsigned short wData_4000325a; //4000325a
extern unsigned char bData_4000325c; //4000325c
extern unsigned char bData_40003260; //40003260
extern unsigned char bData_40003261; //40003261
extern unsigned char bData_40003262; //40003262
extern unsigned char bData_40003263; //40003263
extern unsigned char bData_40003265; //40003265
extern unsigned char Data_4000327f[]; //4000327f
extern float fData_40003288; //40003288
extern float fData_4000328c; //4000328c
extern Struct_40003290 Data_40003290; //40003290
extern Struct_40003296 Data_40003296; //40003296
extern float g_fOtaZeroAzimuth; //4000329c
extern float g_fOtaZeroAltitude; //400032a0
extern unsigned char bData_400032a4_OTAZeroDataErrorCount; //400032a4
extern double dData_400032b0_SunRightAscension; //400032b0
extern double dData_400032b8_SunDeclination; //400032b8
extern double dData_400032c0_MoonRightAscension; //400032c0
extern double dData_400032c8_MoonDeclination; //400032c8
extern double dData_400032d0; //400032d0
extern double dData_400032d8; //400032d8
extern double dData_400032e0; //400032e0
extern double dData_400032e8; //400032e8
extern double dData_400032f0; //400032f0
extern double dData_400032f8; //400032f8
extern double dData_40003300; //40003300
extern double dData_40003308; //40003308
extern double dData_40003310; //40003310
extern double dData_40003318; //40003318
extern double dData_40003320; //40003320
extern double dData_40003328; //40003328
extern double dData_40003330; //40003330
extern double dData_40003338; //40003338
extern double dData_40003340; //40003340
extern double dData_40003348; //40003348
extern Struct_Sh2Data Data_40003350_FlashSh2Data; //40003350
extern Struct_SAOData Data_40003358_SAORecord; //40003358

extern char* g_pcstrMenuLine1; //40003360
extern char* g_pcstrMenuLine2; //40003364
extern unsigned char* g_pcstrMenuLine3; //40003368
extern char* g_pcstrMenuLine4; //4000336c
extern char* g_pcstrMenuLine5; //40003370
extern char* g_pcstrMenuLine6; //40003374
extern char* g_pcstrMenuLine7; //40003378
extern char* g_pcstrMenuLine8; //4000337c
extern char* g_pcstrMenuLine9; //40003380
extern char* g_pcstrMenuLine10; //40003384
extern char* g_pcstrMenuLine11; //40003388
extern char* g_pcstrMenuLine12; //4000338c
extern char* g_pcstrMenuLine13; //40003390
extern char* g_pcstrMenuLine14; //40003394
extern char* g_pcstrMenuLine15; //40003398
extern char* g_pcstrMenuLine16; //4000339c
extern char* Data_400033a0; //400033a0
#if 0
extern char* Data_400033a4; //400033a4
#endif
extern char* g_pcstrBigMenuLine1; //400033a8
extern char* g_pcstrBigMenuLine2; //400033ac
extern char* g_pcstrBigMenuLine3; //400033b0
extern char* g_pcstrBigMenuLine4; //400033b4
extern Union_400033c8 Data_400033c8; //400033c8
extern Union_400033cc Data_400033cc; //400033cc
extern double dData_400033d8; //400033d8
extern double dData_400033e0; //400033e0
extern double dData_400033e8; //400033e8
extern double dData_400033f0; //400033f0
extern double g_dSlewRateRaAxis; //400033f8
extern double g_dSlewRateDecAxis; //40003400
extern int g_iSlewStepRaAxis; //40003408
extern int g_iSlewStepDecAxis; //4000340c
extern double dData_40003410; //40003410
extern double dData_40003418; //40003418
extern double dData_40003420; //40003420
extern double dData_40003428; //40003428
extern char bData_40003430; //40003430
extern char bGotoParkPosition; //40003431
extern char bData_40003432; //40003432
extern double dData_40003448; //40003448
extern double dData_40003450; //40003450
extern double dData_40003458; //40003458
extern double dData_40003460; //40003460
extern int g_iAscomGuideValueRa; //40003488
extern int g_iAscomGuideValueDec; //4000348c
extern double dData_40003490; //40003490
extern char bData_40003498; //40003498
extern double dData_400034a0_SiderealTimeGreenwich0UT; //400034a0
extern unsigned char numVisibleAlignmentStars; //400034a8
extern char g_bLandTarget; //400034a9
extern char bData_400034aa; //400034aa
extern float fData_400034ac; //400034ac
extern float fData_400034b0; //400034b0
extern char bData_400034b4; //400034b4
extern char bData_400034b5; //400034b5
extern float fData_400034b8; //400034b8
extern float fData_400034bc; //400034bc
extern float fData_400034c0; //400034c0
extern float fData_400034c4; //400034c4
extern float g_fLocalSiderealTimerDuringTracking; //400034c8
extern char bData_400034cc; //400034cc
extern char bData_400034cd; //400034cd
extern double Data_400034d0; //400034d0
extern double Data_400034d8; //400034d8
extern double dData_400034e0; //400034e0
extern double dData_400034e8; //400034e8
extern double dData_400034f0; //400034f0
extern double dData_400034f8; //400034f8
extern Union_40003500 Data_40003500; //40003500
extern unsigned char bData_40003504; //40003504
extern char bData_40003505;  //40003505
extern float g_fSendToExternalRightAscension; //40003508
extern float g_fSendToExternalDeclination; //4000350c
extern float g_fReceiveExternalRightAscension; //40003510
extern float g_fReceiveExternalDeclination; //40003514
extern float fData_40003518_ReceiveExternalSiteLongitude; //40003518
extern float fData_4000351c_ReceiveExternalSiteLatitude; //4000351c
extern float g_fReceiveExternalTimezone; //40003520
extern int Data_40003524_ReceiveExternalYear; //40003524
extern unsigned char bData_40003528_ReceiveExternalMonth; //40003528
extern unsigned char bData_40003529_ReceiveExternalDay; //40003529
extern unsigned char bData_4000352a_ReceiveExternalHours; //4000352a
extern unsigned char bData_4000352b_ReceiveExternalMinutes; //4000352b
extern unsigned char bData_4000352c_ReceiveExternalSeconds; //4000352c
extern unsigned char bAscomCmd; //4000352d
extern unsigned char g_bSendToExternalCoordCount; //4000352e
extern float fInitialCustomSiteLongitude; //40003540
extern float fInitialCustomSiteLatitude; //40003544
extern int iInitialCustomSiteTimezone; //40003548
extern unsigned char uart0ReceiveDataBuffer[]; //40003588
extern unsigned char Data_40003592_uart1ReceiveDataBuffer[]; //40003592
extern int Data_4000359c_RecentTargetIdArray[]; //4000359c
extern unsigned char Data_400035bc[]; //400035bc
extern char strTrackingRateCustInput[]; //400037cc
extern char strTrackingRateCustDisplay[]; //400037dc
extern char Data_400037ec[]; //400037ec
extern float Data_400037f8[]; //400037f8
extern unsigned char Data_400038e8[][10]; //400038e8
extern unsigned char arAlignmentStarNames[][10]; //40003a14, size??
extern unsigned char Data_40003b2c[][22]; //40003b2c, size??
extern Struct_FamousStarData Data_40003d94_FlashFamousStarData; //40003d94
extern Struct_ConstellationData Data_40003dd4_FlashConstellationData; //40003dd4
extern Struct_MessierData Data_40003e08_FlashMessierData; //40003e08
extern Struct_BrightStarData Data_40003ea0_FlashBrightStarData; //40003ea0
extern Struct_ICData Data_40003ec0_FlashICData; //40003ec0
extern Struct_NGCData Data_40003ee0_FlashNGCData; //40003ee0
extern Struct_SiteData Data_40003f1c_FlashSiteData; //40003f1c
extern Struct_5218 Data_40003f50; //40003f50
extern Struct_54e0 Data_40003f64; //40003f64
extern unsigned char Data_40003f78[]; //40003f78
extern unsigned char Data_40003f90[]; //40003f90
extern char g_MenuStringBuffer1[]; //40003fa9
extern char g_MenuStringBuffer2[]; //40003fbe
extern char g_MenuStringBuffer3[]; //40003fd3
extern char g_MenuStringBuffer4[]; //40003fe8
extern char g_MenuStringBuffer5[]; //40003ffd
extern char g_MenuStringBuffer6[]; //40004012
extern char g_MenuStringBuffer7[]; //40004027
extern char g_MenuStringBuffer8[]; //4000403c
extern char g_MenuStringBuffer9[]; //40004066
extern char g_MenuStringBuffer10[]; //40004090
extern char g_MenuStringBuffer11[]; //400040ba
extern char g_MenuStringBuffer12[]; //400040e4
extern /*unsigned*/ char Data_4000410e[]; //4000410e

extern Struct_40004128 Data_40004128; //40004128
extern Struct_40004380 Data_40004380; //40004380
extern Struct_GeographicCoordinates Data_40004ad8; //40004ad8
#if 0
extern float Data_40004a68_CurrentAlignStarEquatorialCoord[][2]; //40004a68
#else
extern float Data_40004a68_CurrentAlignStarEquatorialCoord[]; //40004a68
#endif
extern Struct_EquatorialCoordinates Data_40004ae8; //40004ae8
extern Struct_HorizontalCoordinates Data_40004b08; //40004b08
extern Struct_EquatorialCoordinates Data_40004b50; //40004b50
extern Struct_HorizontalCoordinates Data_40004b70; //40004b70
extern unsigned char arInitialCustomSiteName[]; //40004bb8
extern unsigned char Data_40004c58[]; //40004c58, size???

