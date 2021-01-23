
#include "my_types.h"
#include "data.h"


unsigned char sHwKeyQueue[8]; //40002bf8, size??
unsigned char bHwKeyQueueReadPtr; //40002c00
unsigned char bHwKeyQueueWritePtr; //40002c01
unsigned char bData_40002c02; //40002c02
unsigned char bData_40002c03; //40002c03
unsigned char bHwKeyCode; //40002c04
unsigned char bData_40002c05; //40002c05
unsigned char bTimer10msCounter; //40002c06
unsigned char bData_40002c07; //40002c07
unsigned char bData_40002c08; //40002c08
unsigned char bData_40002c09; //40002c09
unsigned char bData_40002c0a_uart0ReceiveDataCount; //40002c0a
char uart0ReceiveFlag; //40002c0b
unsigned char bData_40002c0c_uart0ReceiveStep; //40002c0c
unsigned char Data_40002c0d_uart0ReceiveHeader[4]; //40002c0d
unsigned char uart0_bRxData; //40002c11
unsigned char bData_40002c12_uart1ReceiveDataCount; //40002c12
char bData_40002c13_uart1ReceiveComplete; //40002c13
unsigned char bData_40002c14_uart1ReceiveStep; //40002c14
unsigned char bData_40002c15_uart1ReceiveHeader[4]; //40002c15
unsigned char uart1_bRxData; //40002c19
unsigned char bData_40002c1a; //40002c1a // V2.2: 40002c1e
int g_iUart0GuideValueRa; //40002c1c
int g_iUart0GuideValueDec; //40002c20
Union_40002c24 Data_40002c24; //40002c24
Union_40002c28 Data_40002c28; //40002c28
int fill_40002c2c; //40002c2c
int fill_40002c30; //40002c30
int fill_40002c34; //40002c34
int fill_40002c38; //40002c38
int fill_40002c3c; //40002c3c
int fill_40002c40; //40002c40
int fill_40002c44; //40002c44
int fill_40002c48; //40002c48
int fill_40002c4c; //40002c4c
int fill_40002c50; //40002c50
int fill_40002c54; //40002c54
char bHelpActive; //40002c58
unsigned char bData_40002c59_MainScreenHelpPage; //40002c59
char bData_40002c5a; //40002c5a
int Data_40002c5c_AlignmentStarCount; //40002c5c
unsigned char bData_40002c60_CurrentAlignStarIndex; //40002c60
unsigned char bData_40002c61; //40002c61
unsigned char bData_40002c62_AlignmentStarMode; //40002c62
int Data_40002c64_MenuContextId; //40002c64
char bData_40002c68; //40002c68
unsigned char bData_40002c69_KeyCode; //40002c69
char bDaylightSavingTime; //40002c6a
double dObjectRiseTime; //40002c70
double dObjectTransitTime; //40002c78
double dObjectSetTime; //40002c80
double dData_40002c88; //40002c88
double dData_40002c90; //40002c90
double dTrackingRate; //40002c98
double dGuidingSpeed; //40002ca0
double g_dPoleAxisDevEastWest; //40002ca8
double g_dPoleAxisDevNorthSouth; //40002cb0
int Data_40002cb8; //40002cb8
int Data_40002cbc; //40002cbc
float fData_40002cc0; //40002cc0
double dData_40002cc8; //40002cc8
float fData_40002cd0_ObjectRightAscension; //40002cd0
int fill_40002cd4; //40002cd0
int Data_40002cd8_ObjectRightAscensionHours; //40002cd8
int Data_40002cdc_ObjectRightAscensionMinutes; //40002cdc
float fData_40002ce0_ObjectRightAscensionSeconds; //40002ce0
double g_dObjectRightAcension; //40002ce8
int fill_40002cf0; //40002cf0
int Data_40002cf4; //40002cf4
int Data_40002cf8; //40002cf8
float fData_40002cfc; //40002cfc
int Data_40002d00_ObjectDeclinationDegrees; //40002d00
int Data_40002d04_ObjectDeclinationMinutes; //40002d04
float fData_40002d08_ObjectDeclinationSeconds; //40002d08
double dData_40002d10; //40002d10
float fData_40002d18_ObjectDeclination; //40002d18
int fill_40002d1c; //40002d1c
int Data_40002d20; //40002d20
int Data_40002d24; //40002d24
float fData_40002d28; //40002d28
double dData_40002d30; //40002d30
int fill_40002d38; //40002d38
int fill_40002d3c; //40002d3c
int Data_40002d40; //40002d40
int g_iObjectDeclinationSign; //40002d44
int Data_40002d48; //40002d48
int Data_40002d4c; //40002d4c
float fData_40002d50; //40002d50
double dData_40002d58; //40002d58
int fill_40002d60; //40002d60
int fill_40002d64; //40002d64
int Data_40002d68_OTARightAscensionHours; //40002d68
int Data_40002d6c_OTARightAscensionMinutes; //40002d6c
float fData_40002d70_OTARightAscensionSeconds; //40002d70
double dData_40002d78; //40002d78
double g_dMotorPositionRaAxis; //40002d80
char bData_40002d88; //40002d88
int Data_40002d8c_OTADeclinationDegrees; //40002d8c
int Data_40002d90_OTADeclinationMinutes; //40002d90
float fData_40002d94_OTADeclinationSeconds; //40002d94
double dData_40002d98; //40002d98
double g_dMotorPositionDecAxis; //40002da0
char bData_40002da8; //40002da8
int Data_40002dac; //40002dac
int Data_40002db0; //40002db0
float fData_40002db4; //40002db4
double g_dMotorPositionAziAxis; //40002db8
double dData_40002dc0_Azimuth; //40002dc0
double dRaBklashCorrStartAzimuth; //40002dc8
double dData_40002dd0; //40002dd0
int fill_40002dd8; //40002dd8
int fill_40002ddc; //40002ddc
int Data_40002de0; //40002de0
int Data_40002de4; //40002de4
float fData_40002de8; //40002de8
double g_dMotorPositionAltAxis; //40002df0
double dData_40002df8; //40002df8
double dData_40002e00; //40002e00
double dData_40002e08; //40002e08
int fill_40002e10; //40002e10
int fill_40002e14; //40002e14
int Data_40002e18_SiteLongitudeDegrees; //40002e18
int Data_40002e1c_SiteLongitudeMinutes; //40002e1c
float fData_40002e20_SiteLongitudeSeconds; //40002e20
double dData_40002e28_SiteLongitude; //40002e28
float fCustomSiteLongitude; //40002e30
int Data_40002e34; //40002e34
int Data_40002e38_SiteLatitudeDegrees; //40002e38
int Data_40002e3c_SiteLatitudeMinutes; //40002e3c
float fData_40002e40_SiteLatitudeSeconds; //40002e40
int Data_40002e44; //40002e44
double dData_40002e48_SiteLatitude; //40002e48
float fCustomSiteLatitude; //40002e50
int Data_40002e54_Zone; //40002e54
int iCustomSiteTimeZone; //40002e58
unsigned Data_40002e5c_Year; //40002e5c
unsigned char bData_40002e60_Month; //40002e60
unsigned char bData_40002e61_Day; //40002e61
unsigned char bData_40002e62_Hours; //40002e62
unsigned char bData_40002e63_Minutes; //40002e63
unsigned char bData_40002e64_Seconds; //40002e64
unsigned short wRtcMilliSeconds; //40002e66
int fill_40002e68; //40002e68
int fill_40002e6c; //40002e6c
int fill_40002e70; //40002e70
int fill_40002e74; //40002e74
unsigned char bDateTimeInputMode; //40002e78
unsigned char bData_40002e79_SkyLandTargetSeletion; //40002e79
unsigned char bData_40002e7a_MountType; //40002e7a
unsigned char bData_40002e7b_GpsAvailable; //40002e7b
unsigned char bData_40002e7c_TrackingRateType; //40002e7c
unsigned char g_eSlewRateIndex; //40002e7d
char bData_40002e7e; //40002e7e
int Data_40002e80; //40002e80
int Data_40002e84; //40002e84
unsigned char bTrackingMode; //40002e88
char g_bSlewingStop; //40002e89
unsigned char bTrackingModeMenu; //40002e8a
char bData_40002e8b; //40002e8b
char bData_40002e8c; //40002e8c
float fData_40002e90; //40002e90
float Data_40002e94; //40002e94
float fData_40002e98; //40002e98
float Data_40002e9c; //40002e9c
float fData_40002ea0; //40002ea0
float fData_40002ea4; //40002ea4
float fData_40002ea8; //40002ea8
float fData_40002eac; //40002eac
int iBacklashCorrectionSlewing; //40002eb0
unsigned char bData_40002eb4; //40002eb4
unsigned char bData_40002eb5_SolarSystemObjectNr; //40002eb5
unsigned short wData_40002eb6; //40002eb6
unsigned short wData_40002eb8_MessierNr; //40002eb8
unsigned short wData_40002eba_NGCNr; //40002eba
unsigned short wData_40002ebc_ICNr; //40002ebc
unsigned short wData_40002ebe_ShNr; //40002ebe
unsigned short wData_40002ec0_BrightStarNr; //40002ec0
unsigned int Data_40002ec4_SAONr; //40002ec4
unsigned int Data_40002ec8_NavigationDirectInputNr; //40002ec8
unsigned short wData_40002ecc; //40002ecc
unsigned char bData_40002ece_ConstellationNr; //40002ece
unsigned short wData_40002ed0; //40002ed0
unsigned char bData_40002ed2_FamousStarNr; //40002ed2
unsigned short wData_40002ed4; //40002ed4
unsigned short wData_40002ed6; //40002ed6
unsigned short wData_40002ed8; //40002ed8
unsigned short wData_40002eda; //40002eda
unsigned char bData_40002edc; //40002edc
unsigned char bData_40002edd; //40002edd
char bData_40002ede; //40002ede
char bData_40002edf; //40002edf
int fill_40002ee0; //40002ee0
int fill_40002ee4; //40002ee4
int fill_40002ee8; //40002ee8
int fill_40002eec; //40002eec
int fill_40002ef0; //40002ef0
unsigned short fill_40002ef4; //40002ef4
char bData_40002ef6; //40002ef6
char bData_40002ef7; //40002ef7
int Data_40002ef8; //40002ef8
float fData_40002efc; //40002efc
float fData_40002f00; //40002f00
int Data_40002f04; //40002f04
int Data_40002f08; //40002f08
char bData_40002f0c; //40002f0c
unsigned char bData_40002f0d_RecentTargetType; //40002f0d
int bData_40002f10_RecentTargetId; //40002f10
unsigned char bData_40002f14_RecentTargetCount; //40002f14
unsigned char Data_40002f15_RecentTargetTypeArray[8]; //40002f15, size???
unsigned char bData_40002f1d; //40002f1d
char bData_40002f1e_SetupLocalData; //40002f1e

char* strTelescopeAlign; //40002f20
char* strNavigation; //40002f24
char* strUtilities; //40002f28
char* strSetup; //40002f2c

char* strOneStarAlign; //40002f30
char* strTwoStarAlign; //40002f34
char* strThreeStarAlign; //40002f38
char* strTargetSync; //40002f3c
char* strPoleAxisDev; //40002f40
char* strRaBklashCorr; //40002f44
char* strDecBklashCorr; //40002f48
char* strAlignmentSpare1; //40002f4c
char* strAlignmentSpare2; //40002f50
char* strAlignmentSpare3; //40002f54
char* strAlignmentSpare4; //40002f58

char* strSolarSystem; //40002f5c
char* strConstellation; //40002f60
char* strFamousStar; //40002f64
char* g_pcstrMessierCatalogue; //40002f68
char* g_pcstrNGCCatalogue; //40002f6c
char* g_pcstrICCatalogue; //40002f70
char* g_pcstrSh2Catalogue; //40002f74
char* g_pcstrBrightStarCatalogue; //40002f78
char* g_pcstrSAOStarCatalogue; //40002f7c
char* g_pcstrCustomerObjects; //40002f80
char* g_pcstrInputRAandDEC; //40002f84
char* g_pcstrCustomLandGoal; //40002f88

char* strCurrentObjects; //40002f8c
char* Data_40002f90; //40002f90
char* Data_40002f94; //40002f94
char* Data_40002f98; //40002f98
char* Data_40002f9c; //40002f9c
char* Data_40002fa0; //40002fa0
char* Data_40002fa4; //40002fa4
char* Data_40002fa8; //40002fa8
char* strParkposition; //40002fac
char* Data_40002fb0; //40002fb0
char* strTimeAndDate; //40002fb4
char* Data_40002fb8; //40002fb8
char* Data_40002fbc; //40002fbc
char* Data_40002fc0; //40002fc0
char* Data_40002fc4; //40002fc4
char* strTelescopeMount; //40002fc8
char* strTrackingRate; //40002fcc
char* Data_40002fd0; //40002fd0
char* strReset; //40002fd4
char* Data_40002fd8; //40002fd8
char* Data_40002fdc; //40002fdc
char* Data_40002fe0; //40002fe0
char* Data_40002fe4; //40002fe4
char* Data_40002fe8; //40002fe8
char* Data_40002fec; //40002fec
char* Data_40002ff0; //40002ff0
char* Data_40002ff4; //40002ff4
char* Data_40002ff8; //40002ff8
char* Data_40002ffc; //40002ffc
char* Data_40003000; //40003000
char* Data_40003004; //40003004
char* Data_40003008; //40003008
char* Data_4000300c; //4000300c
char* Data_40003010; //40003010
char* Data_40003014; //40003014
char* Data_40003018; //40003018
char* Data_4000301c; //4000301c
char* Data_40003020; //40003020
char* Data_40003024; //40003024
char* strScientificName; //40003028
char* strSAOCatalog; //4000302c
char* strHRCatalog; //40003030
char* strSelect; //40003034
char* strAdd; //40003038
char* strDelete; //4000303c
char* strModify; //40003040
char* Data_40003044;
char* Data_40003048;
char* Data_4000304c;
char* strEyeshot; //40003050
char* strRatio; //40003054
char* strBackBoard; //40003058
char* strAccessory; //4000305c
char* strCountryAndCity; //40003060
char* strCustomSite; //40003064
char* Data_40003068;
char* Data_4000306c;
char* Data_40003070;
char* Data_40003074;
char* Data_40003078;
char* Data_4000307c;
char* Data_40003080;
char* Data_40003084;
char* strStarSpeed; //40003088
char* strSolarSpeed; //4000308c
char* strMoonSpeed; //40003090
char* Data_40003094;
char* Data_40003098;
char* strListAlignStars; //4000309c
char* strSlewingTo; //400030a0
char* strAutoloadAlignStars; //400030a4
char* Data_400030a8;
char* Data_400030ac;
char* Data_400030b0;
char* Data_400030b4;
char* Data_400030b8;
char* Data_400030bc;
char* strThereIsNoTele; //400030c0
char* strScopeToConnectThis; //400030c4
char* strControlTerminal; //400030c8
char* strPleaseAimAtThe; //400030cc
char* strTelescopeToDistant; //400030d0
char* strTargetThenPress; //400030d4
char* strEnterKey; //400030d8
char* Data_400030dc;
char* Data_400030e0;
char* Data_400030e4;
char* Data_400030e8;
char* Data_400030ec;
char* Data_400030f0;
char* Data_400030f4;
char* Data_400030f8;
char* Data_400030fc;
char* Data_40003100;
char* Data_40003104;
char* Data_40003108;
char* Data_4000310c;
char* Data_40003110;
char* Data_40003114; //40003114
int fill_40003118; //40003118
int fill_4000311c; //4000311c
int fill_40003120; //40003120
int fill_40003124; //40003124
int fill_40003128; //40003128
int fill_4000312c; //4000312c
int fill_40003130; //40003130
int fill_40003134; //40003134
int fill_40003138; //40003138
int fill_4000313c; //4000313c
char* Data_40003140; //40003140
unsigned char bCurrentCustomSiteInputLine; //40003144
int fill_40003148; //40003148
char* Data_4000314c_SolarSystemObjectName; //4000314c
char Data_40003150[8]; //40003150, size??
char fill_40003158; //40003158
char arCustomSiteName[8]; //40003159, size??
unsigned char bData_40003161; //40003161
char bData_40003162; //40003162
int Data_40003164_LunarPhaseYear; //40003164
int Data_40003168_LunarPhaseMonth; //40003168
char fill_4000316c; //4000316c
unsigned char bData_4000316d; //4000316d
unsigned char bData_4000316e_FocusLineOn8LineDisplay; //4000316e
unsigned char bData_4000316f_FocusLineOn4LineDisplay; //4000316f
unsigned char g_bAlignmentEightLineMenuTopItem; //40003170
unsigned char g_bAlignmentFourLineMenuTopItem; //40003171
unsigned char g_bAlignmentEightLineMenuFocusItem; //40003172
unsigned char g_bAlignmentFourLineMenuFocusItem; //40003173
unsigned char bData_40003174; //40003174
unsigned char bData_40003175; //40003175
unsigned char bData_40003176; //40003176
unsigned char bData_40003177; //40003177
unsigned char bData_40003178; //40003178
unsigned char bData_40003179; //40003179
unsigned char bData_4000317a; //4000317a
unsigned char bData_4000317b; //4000317b
unsigned char bData_4000317c; //4000317c
unsigned char bData_4000317d; //4000317d
unsigned char bData_4000317e; //4000317e
unsigned char bData_4000317f; //4000317f
unsigned char bData_40003180; //40003180
char fill_40003181; //40003181
unsigned char bData_40003182; //40003182
char fill_40003183; //40003183
unsigned char bData_40003184; //40003184
char fill_40003185; //40003185
unsigned char bData_40003186; //40003186
char fill_40003187; //40003187
char bRaBacklashCorrectionDirection; //40003188
char bDecBacklashCorrectionDirection; //40003189
unsigned char bCharacterInputPosition; //4000318a
int Data_4000318c; //4000318c
int Data_40003190; //40003190
char bData_40003194; //40003194
unsigned char bData_40003195; //40003195
unsigned char bData_40003196_CurrentLanguage; //40003196
unsigned char bData_40003197_DisplayLinesPerMenuLine; //40003197
char bCapsLock; //40003198
unsigned char bMapKeyToCharIndex; //40003199
unsigned char bData_4000319a_SkyLandTargetId; //4000319a
char bData_4000319b; //4000319b
char g_bSingleSlewActive; //4000319c
char g_bCombinedSlewActive; //4000319d
Union_400031a0 Data_400031a0; //400031a0
Union_400031a0 g_stCurrentSlewRampValue; //400031a4
int Data_400031a8; //400031a8
Union_400031a0 Data_400031ac; //400031ac
int fill_400031b0; //400031b0
int g_iCurrentSlewRampIndex; //400031b4
char g_bMaxSlewRampActive; //400031b8
char bData_400031b9; //400031b9
char bData_400031ba; //400031ba
char bData_400031bb; //400031bb
char bData_400031bc; //400031bc
char bData_400031bd; //400031bd
char bData_400031be; //400031be
unsigned char bData_400031bf; //400031bf
float fData_400031c0; //400031c0
float fData_400031c4; //400031c4
int fill_400031c8; //400031c8
int fill_400031cc; //400031cc
int fill_400031d0; //400031d0
int fill_400031d4; //400031d4
int fill_400031d8; //400031d8
int fill_400031dc; //400031dc
char bData_400031e0; //400031e0
char bData_400031e1; //400031e1
int Data_400031e4; //400031e4
unsigned char bCustomerObjectNameChar; //400031e8
char bData_400031e9; //400031e9
char g_bTargetSyncOpen; //400031ea
char bData_400031eb; //400031eb
char bData_400031ec; //400031ec
char bSystemInitialized; //400031ed
double dData_400031f0; //400031f0
double dData_400031f8; //400031f8
char bData_40003200; //40003200
char bData_40003201; //40003201
int iMountAutoguideRa; //40003204
int iMountAutoguideDec; //40003208
int fill_4000320c; //4000320c
char bData_40003210; //40003210
char bData_40003211; //40003211
int Data_40003214_UserTimerSeconds; //40003214
int fill_40003218; //40003218
int fill_4000321c; //4000321c
int Data_40003220_AlarmHours; //40003220
int Data_40003224_AlarmMinutes; //40003224
int Data_40003228_AlarmSeconds; //40003228
char bData_4000322c; //4000322c
char bData_4000322d_AlarmTimeElapsed; //4000322d
float fMainFocalLength; //40003230
float fSecondaryFocalLength; //40003234
float fEyepieceMagnification; //40003238
float fEyepieceFOV; //4000323c
float fFieldOfView; //40003240
int fill_40003244; //40003244
int Data_40003248_CurrentDisplayPWM; //40003248
int fill_4000324c; //4000324c
unsigned short wData_40003250; //40003250
unsigned short wData_40003252; //40003252
unsigned short fill_40003254; //40003254
unsigned short wData_40003256; //40003256
unsigned char bData_40003258; //40003258
unsigned short wData_4000325a; //4000325a
unsigned char bData_4000325c; //4000325c
char fill_4000325d; //4000325d
char fill_4000325e; //4000325e
char fill_4000325f; //4000325f
unsigned char bData_40003260; //40003260
unsigned char bData_40003261; //40003261
unsigned char bData_40003262; //40003262
unsigned char bData_40003263; //40003263
char fill_40003264; //40003264
unsigned char bData_40003265; //40003265
int fill_40003268; //40003268
int fill_4000326c; //4000326c
int fill_40003270; //40003270
int fill_40003274; //40003274
int fill_40003278; //40003278
unsigned short fill_4000327c; //4000327c
char fill_4000327e; //4000327e
unsigned char Data_4000327f[8]; //4000327f, size???
float fData_40003288; //40003288
float fData_4000328c; //4000328c
Struct_40003290 Data_40003290; //40003290
Struct_40003296 Data_40003296; //40003296
float fData_4000329c; //4000329c
float fData_400032a0; //400032a0
unsigned char bData_400032a4_OTAZeroDataErrorCount; //400032a4
double fill_400032a8; //400032a8
double dData_400032b0_SunRightAscension; //400032b0
double dData_400032b8_SunDeclination; //400032b8
double dData_400032c0_MoonRightAscension; //400032c0
double dData_400032c8_MoonDeclination; //400032c8
double dData_400032d0; //400032d0
double dData_400032d8; //400032d8
double dData_400032e0; //400032e0
double dData_400032e8; //400032e8
double dData_400032f0; //400032f0
double dData_400032f8; //400032f8
double dData_40003300; //40003300
double dData_40003308; //40003308
double dData_40003310; //40003310
double dData_40003318; //40003318
double dData_40003320; //40003320
double dData_40003328; //40003328
double dData_40003330; //40003330
double dData_40003338; //40003338
double dData_40003340; //40003340
double dData_40003348; //40003348
Struct_Sh2Data Data_40003350_FlashSh2Data; //40003350
Struct_SAOData Data_40003358_SAORecord; //40003358
char* Data_40003360; //40003360
char* Data_40003364; //40003364
unsigned char* Data_40003368; //40003368
char* Data_4000336c; //4000336c
char* Data_40003370; //40003370
char* Data_40003374; //40003374
char* Data_40003378; //40003378
char* Data_4000337c; //4000337c
char* Data_40003380; //40003380
char* Data_40003384; //40003384
char* Data_40003388; //40003388
char* Data_4000338c; //4000338c
char* Data_40003390; //40003390
char* Data_40003394; //40003394
char* Data_40003398; //40003398
char* Data_4000339c; //4000339c
char* Data_400033a0; //400033a0
char* Data_400033a4; //400033a4

char* g_pcstrFourLineMenu1; //400033a8
char* g_pcstrFourLineMenu2; //400033ac
char* g_pcstrFourLineMenu3; //400033b0
char* g_pcstrFourLineMenu4; //400033b4

int fill_400033b8; //400033b8
int fill_400033bc; //400033bc
int fill_400033c0; //400033c0
int fill_400033c4; //400033c4
Union_400033c8 Data_400033c8; //400033c8
Union_400033cc Data_400033cc; //400033cc
double fill_400033d0; //400033d0
double dData_400033d8; //400033d8
double dData_400033e0; //400033e0
double dData_400033e8; //400033e8
double dData_400033f0; //400033f0
double g_dSlewRateRaAxis; //400033f8
double g_dSlewRateDecAxis; //40003400
int g_iSlewStepRaAxis; //40003408
int g_iSlewStepDecAxis; //4000340c
double dData_40003410; //40003410
double dData_40003418; //40003418
double dData_40003420; //40003420
double dData_40003428; //40003428
char bData_40003430; //40003430
char bGotoParkPosition; //40003431
char bData_40003432; //40003432
double fill_40003438; //40003438
double fill_40003440; //40003440
double dData_40003448; //40003448
double dData_40003450; //40003450
double dData_40003458; //40003458
double dData_40003460; //40003460
double fill_40003468; //40003468
double fill_40003470; //40003470
double fill_40003478; //40003478
double fill_40003480; //40003480
int g_iAscomGuideValueRa; //40003488
int g_iAscomGuideValueDec; //4000348c
double dData_40003490; //40003490
char bData_40003498; //40003498
double dData_400034a0_SiderealTimeGreenwich0UT; //400034a0
unsigned char numVisibleAlignmentStars; //400034a8
char g_bLandTarget; //400034a9
char bData_400034aa; //400034aa
float fData_400034ac; //400034ac
float fData_400034b0; //400034b0
char bData_400034b4; //400034b4
char bData_400034b5; //400034b5
float fData_400034b8; //400034b8
float fData_400034bc; //400034bc
float fData_400034c0; //400034c0
float fData_400034c4; //400034c4
float fData_400034c8; //400034c8
char bData_400034cc; //400034cc
char bData_400034cd; //400034cd
double Data_400034d0; //400034d0
double Data_400034d8; //400034d8
double dData_400034e0; //400034e0
double dData_400034e8; //400034e8
double dData_400034f0; //400034f0
double dData_400034f8; //400034f8
Union_40003500 Data_40003500; //40003500
unsigned char bData_40003504; //40003504
char bData_40003505;  //40003505
float fData_40003508; //40003508
float fData_4000350c; //4000350c
float fData_40003510; //40003510
float fData_40003514; //40003514
float fData_40003518_ReceiveExternalSiteLongitude; //40003518
float fData_4000351c_ReceiveExternalSiteLatitude; //4000351c
float fData_40003520; //40003520
int Data_40003524_ReceiveExternalYear; //40003524
unsigned char bData_40003528_ReceiveExternalMonth; //40003528
unsigned char bData_40003529_ReceiveExternalDay; //40003529
unsigned char bData_4000352a_ReceiveExternalHours; //4000352a
unsigned char bData_4000352b_ReceiveExternalMinutes; //4000352b
unsigned char bData_4000352c_ReceiveExternalSeconds; //4000352c
unsigned char bAscomCmd; //4000352d
unsigned char bData_4000352e; //4000352e
int fill_40003530; //40003530
int fill_40003534; //40003534
int fill_40003538; //40003538
int fill_4000353c; //4000353c
float fInitialCustomSiteLongitude; //40003540
float fInitialCustomSiteLatitude; //40003544
int iInitialCustomSiteTimezone; //40003548
int fill_4000354c; //4000354c
int fill_40003550; //40003550
int fill_40003554; //40003554
int fill_40003558; //40003558
int fill_4000355c; //4000355c
int fill_40003560; //40003560
int fill_40003564; //40003564
int fill_40003568; //40003568
int fill_4000356c; //4000356c
int fill_40003570; //40003570
int fill_40003574; //40003574
int fill_40003578; //40003578
int fill_4000357c; //4000357c
int fill_40003580; //40003580
int fill_40003584; //40003584
unsigned char uart0ReceiveDataBuffer[10]; //40003588
unsigned char Data_40003592_uart1ReceiveDataBuffer[10]; //40003592
int Data_4000359c_RecentTargetIdArray[8]; //4000359c, size??
unsigned char Data_400035bc[528]; //400035bc
char strTrackingRateCustInput[16]; //400037cc
char strTrackingRateCustDisplay[16]; //400037dc
char Data_400037ec[12]; //400037ec, size???
float Data_400037f8[60]; //400037f8, size???
unsigned char Data_400038e8[30][10]; //400038e8, size???
unsigned char arAlignmentStarNames[28][10]; //40003a14, size??
unsigned char Data_40003b2c[28][22]; //40003b2c, size??
Struct_FamousStarData Data_40003d94_FlashFamousStarData; //40003d94
Struct_ConstellationData Data_40003dd4_FlashConstellationData; //40003dd4
Struct_MessierData Data_40003e08_FlashMessierData; //40003e08
Struct_BrightStarData Data_40003ea0_FlashBrightStarData; //40003ea0
Struct_ICData Data_40003ec0_FlashICData; //40003ec0
Struct_NGCData Data_40003ee0_FlashNGCData; //40003ee0
Struct_SiteData Data_40003f1c_FlashSiteData; //40003f1c
Struct_5218 Data_40003f50; //40003f50
Struct_54e0 Data_40003f64; //40003f64
unsigned char Data_40003f78[24]; //40003f78
unsigned char Data_40003f90[25]; //40003f90, size???
char Data_40003fa9[21]; //40003fa9, size???
char Data_40003fbe[21]; //40003fbe, size???
char Data_40003fd3[21]; //40003fd3, size???
char Data_40003fe8[21]; //40003fe8, size???
char Data_40003ffd[21]; //40003ffd, size???
char Data_40004012[21]; //40004012, size???
char Data_40004027[21]; //40004027, size???
char Data_4000403c[42]; //4000403c, size???
char Data_40004066[42]; //40004066, size???
char Data_40004090[42]; //40004090, size???
char Data_400040ba[42]; //400040ba, size???
char Data_400040e4[42]; //400040e4, size???
/*unsigned*/ char Data_4000410e[21]; //4000410e, size???
Struct_40004128 Data_40004128; //40004128
Struct_40004380 Data_40004380; //40004380
int fill_40004380_[430]; //4000438????
#if 0
float Data_40004a68_CurrentAlignStarEquatorialCoord[2][2]; //40004a68
#else
float Data_40004a68_CurrentAlignStarEquatorialCoord[28]; //40004a68
#endif
Struct_GeographicCoordinates Data_40004ad8; //40004ad8
Struct_EquatorialCoordinates Data_40004ae8; //40004ae8
Struct_HorizontalCoordinates Data_40004b08; //40004b08
Struct_EquatorialCoordinates Data_40004b50; //40004b50
Struct_HorizontalCoordinates Data_40004b70; //40004b70
unsigned char arInitialCustomSiteName[160]; //40004bb8 size???
unsigned char Data_40004c58[100]; //40004c58, size?

