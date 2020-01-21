
#include "my_types.h"
#include "data.h"

unsigned char strAlignStarsNames[28][10] = //40000000
{
	"Sirius   ",
	"Canopus  ",
	"Vega     ",
	"Alpha Cen",
	"Arcturus ",
	"Capella  ",
	"Rigel    ",
	"Procyon  ",
	"Achernar ",
	"Betelgeus",
	"Altair   ",
	"Aldebaran",
	"Spica    ",
	"Antares  ",
	"Fomalhaut",
	"Deneb    ",
	"Regulus  ",
	"Mirfak   ",
	"Castor   ",
	"Alphard  ",
	"Polaris  ",
	"Alpheratz",
	"Rasalhagu",
	"Denebola ",
	"Navi     ",
	"Suhail   ",
	"Mizar    ",
	"Albireo  "
}; 
unsigned char Data_40000118[28][22]; //40000118, size??
char Data_40000380[10]; //40000380, size???
char Data_4000038a[10]; //4000038a, size???
char Data_40000394[10]; //40000394, size???
char Data_4000039e[10]; //4000039e, size???
char Data_400003a8[10]; //400003a8, size???
char Data_400003b2[8]; //400003b2, size???
char Data_400003ba[8]; //400003ba, size???
char Data_400003c2[8]; //400003c2, size???
char Data_400003ca[10]; //400003ca, size???
char Data_400003d4[10]; //400003d4, size???
char strEngTelescopeAlign[] = "Telescope Align"; //400008ad
char Data_400008bd[] = "Navigation"; //400008bd
char Data_400008c8[] = "Utilities"; //400008c8
char Data_400008d2[] = "Setup"; //400008d2
char strEngOneStarAlign[] = "One Star Align"; //400008d8
char strEngTwoStarAlign[] = "Two Star Align"; //400008e7
char strEngThreeStarAlign[] = "Three Star Align"; //400008f6
char Data_40000907[12]; //40000907, size???
char Data_40000913[16]; //40000913, size???
char Data_40000923[16]; //40000923, size???
char Data_40000933[17]; //40000933, size???
char strEngSolarSystem[] = "Solar System"; //40000944
char strEngConstellation[] = "Constellation"; //40000951
char strEngFamousStar[] = "Famous Star"; //4000095f
char strEngMessierCatal[] = "Messier Catal."; //4000096b
char strEngNGCCatalog[] = "NGC Catalog."; //4000097a
char strEngICCatalogue[] = "IC Catalogue"; //40000987
char strEngSh2Catalog[] = "Sh2 Catalog."; //40000994
char strEngBrightStarCat[] = "Bright Star Cat."; //400009a1
char strEngSAOStarCatal[] = "SAO Star Catal."; //400009b2
char strEngCustomerObjects[] = "Customer Objects"; //400009c2
char strEngInputRAandDEC[] = "Input RA and DEC"; //400009d3
char strEngCustomLandGoal[] = "Custom Land Goal"; //400009e4
char strEngCurrentObjects[] = "Current Objects"; //400009f5
char strEngObjectRiseSet[] = "Object Rise/Set"; //40000a05
char strEngCurrLunarPhase[] = "Curr. Lunar Phase"; //40000a15
char strEngTimer[] = "Timer"; //40000a27
char strEngAlarm[] = "Alarm"; //40000a2d
char strEngEyepieceFOV[] = "Eyepiece FOV"; //40000a33
char strEngEyepieceMagn[] = "Eyepiece Magn."; //40000a40
char strEngDisplayIllumin[] = "Display Illumin."; //40000a4f
char strEngParkposition[] = "Parkposition"; //40000a60
char strEngTimeAndDate[] = "Time and Date "; //40000a6d
char strEngDaylightSaving[] = "Daylight Saving"; //40000a7c
char strEngSiteSetting[] = "Site Setting"; //40000a8c
char strEngSkyLand[] = "Sky/Land"; //40000a99
char strEngAzEqu[] = "AZ / EQU"; //40000aa2
char strEngTelescopeMount[] = "Telescope Mount"; //40000aab
char strEngTrackingRate[] = "Tracking Rate"; //40000abb
char strEngLanguage[] = "Language"; //40000ac9
char strEngReset[] = "Reset"; //40000ad2
char Data_40000ad8[42];
char Data_40000ae8[42];
char Data_40000af4[42];
char Data_40000aff[42];
char Data_40000b06[42];
char Data_40000b0a[42];
char Data_40000b11[42];
char Data_40000b18[42];
char Data_40000b1f[42];
char Data_40000b23[42];
char Data_40000b4d[42];
char Data_40000b55[42];
char Data_40000b5b[42];
char Data_40000b65[42];
char strEngCountryAndCity[] = "Country & City"; //40000b6f
char strEngCustomSite[] = "Custom Site"; //40000b7e
char Data_40000b8a[42];
char Data_40000b91[42];
char Data_40000b95[42];
char Data_40000b9c[42];
char Data_40000ba3[42];
char Data_40000baa[42];
char Data_40000bae[42];
char Data_40000bb5[42];
char strEngStarSpeed[] = "Star Speed"; //40000bbc
char strEngSolarSpeed[] = "Solar Speed"; //40000bc7
char strEngMoonSpeed[] = "Moon Speed"; //40000bd3
char strEngCustomizeSpeed[] = "Customize Speed"; //40000bde
char strEngGuidingSpeed[] = "Guiding Speed"; //40000bee
char strEngListAlignStars[] = "List align stars:"; //40000bfc, size?
char Data_40000c14[42];
char Data_40000c20[42];

char Data_40000c35[] = "  Please center this "; //40000c35
char Data_40000c4b[] = "star to the field of"; //40000c4b
char Data_40000c60[] = "view"; //40000c60, size???
char Data_40000c7a[] = "The telescope has be   "; //40000c7a, size?
char Data_40000c92[] = "aligned!           "; //40000c92, size?
char Data_40000ca6[] = "                       "; //40000ca6, size?
char Data_40000cbe[42];
char Data_40000cd3[42];
char Data_40000ce8[42];
char Data_40000cfb[42];
char Data_40000d06[42];
char Data_40000d1a[42];
char Data_40000d2f[42];
char Data_40000d44[42];
char Data_40000d59[42];
char Data_40000d66[42];
char Data_40000d7b[42];
char Data_40000d90[42];
char Data_40000da2[42];
char Data_40000db8[42];
char Data_40000dcf[42];
char Data_40000de3[42];
char Data_40000df9[42];
char Data_40000e0a[42];
char Data_40000e20[42];
char Data_40000e21[42];
char Data_40000e38[42];
char Data_40000e4e[42];
char Data_40000e62[32] = "Ausrichtung"; //40000e62
char Data_40000e82[32];
char Data_40000ea2[32];
char Data_40000ec2[32];
char Data_40000ee2[32];
char Data_40000f02[32];
char Data_40000f22[32];
char Data_40000f42[32];
char Data_40000f62[32];
char Data_40000f82[32];
char Data_40000fa2[32];
char Data_40000fc2[32];
char Data_40000fe2[32];
char Data_40001002[32];
char Data_40001022[32];
char Data_40001042[32];
char Data_40001062[32];
char Data_40001082[32];
char Data_400010a2[32];
char Data_400010c2[32];
char Data_400010e2[32];
char Data_40001102[32];
char Data_40001122[32];
char Data_40001142[32];
char Data_40001162[32];
char Data_40001182[32];
char Data_400011a2[32];
char Data_400011c2[32];
char Data_400011e2[32];
char Data_40001202[32];
char Data_40001222[32];
char Data_40001242[32];			
char Data_40001262[32];
char Data_40001282[32];
char Data_400012a2[32];
char Data_400012c2[32];
char Data_400012e2[32];
char Data_40001302[32];
char Data_40001322[32];
char Data_40001342[32];
char Data_40001362[32];
char Data_40001382[32];
char Data_400013a2[32];
char Data_400013c2[32];
char Data_400013e2[32];
char Data_40001402[32];
char Data_40001422[32];
char Data_40001442[32];
char Data_40001462[32];
char Data_40001482[32];
char Data_400014a2[32];
char Data_400014c2[32];		
char Data_400014e2[32];
char Data_40001502[32];
char Data_40001522[32];
char Data_40001542[32];
char Data_40001562[32];
char Data_40001582[32];
char Data_400015a2[32];
char Data_400015c2[32];
char Data_400015e2[32];
char Data_40001602[32];
char Data_40001622[32];
char Data_40001642[32];
char Data_40001662[32];
char Data_40001682[32];
char Data_400016a2[32];
char Data_400016c2[32];
char Data_400016e2[32];
char Data_40001702[32];
char Data_40001722[32];
char Data_40001742[32];
char Data_40001762[32];
char Data_40001782[32];
char Data_400017a2[32];
char Data_400017c2[32];
char Data_400017e2[32];
char Data_40001802[32];
char Data_40001822[32];
char Data_40001842[32];
char Data_40001862[32];
char Data_40001882[32];
char Data_400018a2[32];
char Data_400018c2[32];
char Data_400018e2[32];
char Data_40001902[32];
char Data_40001922[32];
char Data_40001942[32];
char Data_40001962[32];
char Data_40001982[32];
char Data_400019a2[32];
char Data_400019c2[32];
char Data_400019e2[32];
char Data_40001a02[32];
char Data_40001a22[32];
char Data_40001a42[32];
char Data_40001a62[32];
char Data_40001a82[32];
char Data_40001aa2[32];
char Data_40001ac2[32];
char Data_40001ae2[32];
char Data_40001b02[32];
char Data_40001b22[32];
char Data_40001b42[32];
char Data_40001b62[32];
char Data_40001b82[32];
char Data_40001ba2[32];
char Data_40001bc2[32];
char Data_40001be2[32];
char Data_40001c02[32];
char Data_40001c22[32];
char Data_40001c42[32];
char Data_40001c62[32];
char Data_40001c82[32];
char Data_40001ca2[32];
char Data_40001cc2[32];
char Data_40001ce2[32];
char Data_40001d02[32];
char Data_40001d22[32];
char Data_40001d42[32];
char Data_40001d62[32];
char Data_40001d82[32];
char Data_40001da2[32];
char Data_40001dc2[32];
char Data_40001de2[32];
char Data_40001e02[32];
char Data_40001e22[32];
char Data_40001e42[32];
char Data_40001e62[32];
char Data_40001e82[32];
char Data_40001ea2[32];
char Data_40001ec2[32];
char Data_40001ee2[32];
char Data_40001f02[32];		
char Data_40001f22[32];
char Data_40001f42[32];
char Data_40001f62[32];
char Data_40001f82[32];
char Data_40001fa2[32];
char Data_40001fc2[32];
char Data_40001fe2[32];
char Data_40002002[32];
char Data_40002022[32];
char Data_40002042[32];
char Data_40002062[32];
char Data_40002082[32];
char Data_400020a2[32];
char Data_400020c2[32];
char Data_400020e2[32];
char Data_40002102[32];
char Data_40002122[32];
char Data_40002142[32];
char Data_40002162[32];
char Data_40002182[32];
char Data_400021a2[32];
char Data_400021c2[32];
char Data_400021e2[32];
char Data_40002202[32];
char Data_40002222[32];
char Data_40002242[32];
char Data_40002262[32];
char Data_40002282[32];
char Data_400022a2[32];
char Data_400022c2[32];
char Data_400022f2[32]; //400022f2
char Data_40002302[32]; //40002302
char Data_40002387[19]; //40002387
char Data_4000239a[20]; //4000239a, size???
char Data_4000248c[21]; //4000248c
char Data_400024a1[20]; //400024a1, size??
char Data_400024b5[20]; //400024b5
char Data_400024c9[13]; //400024c9, size??
char Data_400024d6[11]; //400024d6, size??
char Data_400024e1[14]; //400024e1
char Data_400024ef[21]; //400024ef, size??
char Data_40002504[100]; //40002504, size???
char Data_40002655[11]; //40002655, size???
char Data_40002660[100]; //40002660, size???
char Data_40002789[9]; //40002789
char Data_40002792[50]; //40002792, size??
char Data_400027cf[] = "Input Ra Dec:  "; //400027cf
unsigned char Data_400027df[] = "R.a:           "; //400027df
unsigned char Data_400027ef[] = "Dec:           "; //400027ef
char Data_400027ff[16]; //400027ff
char fill_40002836; //40002836
unsigned char Data_40002827[16] = " Name:"; //40002827 size???
char Data_40002837[16] = "  Lon:"; //40002837 size??
char Data_40002847[15] = "  Lat:"; //40002847 size??
char Data_40002856[20] = " Zone:"; //40002856 size???
char Data_4000288e[11]; //4000288e
char Data_40002899[12]; //40002899, size???
char Data_400028a5[14]; //400028a5
char Data_400028b3[20]; //400028b3, size???
char strEngPleaseSetupOtaZero[] = "Please setup OTA zero"; //400028c1
char Data_400028d7[] = "Azi:000  "; //400028d7
char Data_400028e1[] = "Alt: 00  "; //400028e1
char Data_400028eb[] = "Data:error,try again!"; //400028eb
char Data_40002901[] = "ok,poweroff,restart!"; //40002901
char strEngEnglish[] = "English"; //40002916
char strEngGerman[] = "German"; //4000291e
char strEngFrench[] = "French"; //40002925
char strEngItalian[] = "Italian"; //4000292c
char strEngSpanish[] = "Spanish"; //40002934, size??
char Data_4000294a[] = "xxxx"; //4000294a, content, size?
char strEngSetTimer[] = "Set timer:"; //400029a1
char strEng00000s[] = "00000s"; //400029ac
char Data_400029b3[] = ""; //400029b3
char strEngStartBack[] = "      Start      Back"; //400029b4
char strEngCountingDown[] = "Counting down"; //400029ca, size???
char strEngTimeRemain[] = "Time remain:"; //400029da
char strEngTimeRemain00000s[] = "00000s"; //400029e7
char strEngStopBack[] = "       Stop      Back"; //400029ee, size???
char Data_40002a3f[] = "00"; //40002a3f

char Data_40002a42[] = "00"; //40002a42
char Data_40002a45[] = "00"; //40002a45
char strEngCloseAlarm[] =     "Close Alarm?  "; //40002a62
char strEngAlarmCloseBack[] = "      Close    Back"; //40002a71, size???
char strEngInputTime[] =      "Input time: "; //40002a87
char strEngAlarm21h34m23s[] = "21h34m23s"; //40002a94
char strEngAlarmOnBack[] =    "       On      Back "; //40002a9e, size???
char strEngBackgroundLight[] = "Background light"; //40002acb
char strEngPressUpDownKey[] = "Press up/down key"; //40002adc
char Data_40002aee[] = ""; //40002aee, content?
char Data_40002aef[22]; //40002aef, size???
char Data_40002b70[] = "daylight saving"; //40002b70
char Data_40002b80[] = "status:on"; //40002b80
char Data_40002b8a[16]; //40002b8a
char Data_40002b8b[22]; //40002b8b, size???
char Data_40002ba5[] = "Daylight saving"; //40002ba5
char Data_40002bb5[] = "status:off"; //40002bb5
char Data_40002bc0[] = ""; //40002bc0
char Data_40002bc1[] = ""; //40002bc1
int Data_40002bc4_DayYear[13] = 
{
	-1, -1, 30, 58, 89, 119, 150, 180, 211, 241, 272, 303, 333
}; //40002bc4
unsigned char Data_40002bf8[8]; //40002bf8, size??
unsigned char bData_40002c00; //40002c00
unsigned char bData_40002c01; //40002c01
unsigned char bData_40002c02; //40002c02
unsigned char bData_40002c03; //40002c03
unsigned char bData_40002c04; //40002c04
unsigned char bData_40002c05; //40002c05
unsigned char bData_40002c06; //40002c06
unsigned char bData_40002c07; //40002c07
unsigned char bData_40002c08; //40002c08
unsigned char bData_40002c09; //40002c09
unsigned char bData_40002c0a_uart0ReceiveDataCount; //40002c0a
char bData_40002c0b_uart0ReceiveComplete; //40002c0b
unsigned char bData_40002c0c_uart0ReceiveStep; //40002c0c
unsigned char Data_40002c0d_uart0ReceiveHeader[4]; //40002c0d
unsigned char uart0_bRxData; //40002c11
unsigned char bData_40002c12_uart1ReceiveDataCount; //40002c12
char bData_40002c13_uart1ReceiveComplete; //40002c13
unsigned char bData_40002c14_uart1ReceiveStep; //40002c14
unsigned char bData_40002c15_uart1ReceiveHeader[4]; //40002c15
int Data_40003214_UserTimerSeconds; //40003214
unsigned char uart1_bRxData; //40002c19
char bData_40002c1a; //40002c1a // V2.2: 40002c1e
int Data_40002c1c; //40002c1c
int Data_40002c20; //40002c20
Union_40002c24 Data_40002c24; //40002c24
Union_40002c28 Data_40002c28; //40002c28
char bData_40002c58; //40002c58
unsigned char bData_40002c59_MainScreenHelpPage; //40002c59
char bData_40002c5a; //40002c5a
int Data_40002c5c_AlignmentStarCount; //40002c5c
unsigned char bData_40002c60_CurrentAlignStarIndex; //40002c60
char bData_40002c61; //40002c61
char bData_40002c62_AlignmentStarMode; //40002c62
int Data_40002c64_MenuContextId; //40002c64
char bData_40002c68; //40002c68
char bData_40002c69_KeyCode; //40002c69
char bData_40002c6a; //40002c6a
double dData_40002c70; //40002c70
double dData_40002c78; //40002c78
double dData_40002c80; //40002c80
double dData_40002c88; //40002c88
double dData_40002c90; //40002c90
double dData_40002c98; //40002c98
double dData_40002ca0; //40002ca0
double dData_40002ca8; //40002ca8
double dData_40002cb0; //40002cb0
int Data_40002cb8; //40002cb8
int Data_40002cbc; //40002cbc
float fData_40002cc0; //40002cc0
double dData_40002cc8; //40002cc8
float fData_40002cd0_ObjectRightAscension; //40002cd0
int Data_40002cd8_ObjectRightAscensionHours; //40002cd8
int Data_40002cdc_ObjectRightAscensionMinutes; //40002cdc
float fData_40002ce0_ObjectRightAscensionSeconds; //40002ce0
double dData_40002ce8; //40002ce8
int Data_40002cf4; //40002cf4
int Data_40002cf8; //40002cf8
float fData_40002cfc; //40002cfc
int Data_40002d00_ObjectDeclinationDegrees; //40002d00
int Data_40002d04_ObjectDeclinationMinutes; //40002d04
float fData_40002d08_ObjectDeclinationSeconds; //40002d08
double dData_40002d10; //40002d10
float fData_40002d18_ObjectDeclination; //40002d18
int Data_40002d20; //40002d20
int Data_40002d24; //40002d24
float fData_40002d28; //40002d28
int Data_40002d40; //40002d40
int Data_40002d44; //40002d44
int Data_40002d48; //40002d48
int Data_40002d4c; //40002d4c
float fData_40002d50; //40002d50
int Data_40002d68_OTARightAscensionHours; //40002d68
int Data_40002d6c_OTARightAscensionMinutes; //40002d6c
float fData_40002d70_OTARightAscensionSeconds; //40002d70
double dData_40002d78; //40002d78
double dData_40002d80; //40002d80
char bData_40002d88; //40002d88
int Data_40002d8c_OTADeclinationDegrees; //40002d8c
int Data_40002d90_OTADeclinationMinutes; //40002d90
float fData_40002d94_OTADeclinationSeconds; //40002d94
double dData_40002d98; //40002d98
double dData_40002da0; //40002da0
char bData_40002da8; //40002da8
int Data_40002dac; //40002dac
int Data_40002db0; //40002db0
float fData_40002db4; //40002db4
double dData_40002db8; //40002db8
double dData_40002dc0; //40002dc0
double dData_40002dc8; //40002dc8
double dData_40002dd0; //40002dd0
int Data_40002de0; //40002de0
int Data_40002de4; //40002de4
float fData_40002de8; //40002de8
double dData_40002df0; //40002df0
double dData_40002df8; //40002df8
double dData_40002e00; //40002e00
double dData_40002e08; //40002e08
int Data_40002e18_SiteLongitudeDegrees; //40002e18
int Data_40002e1c_SiteLongitudeMinutes; //40002e1c
float fData_40002e20_SiteLongitudeSeconds; //40002e20
double dData_40002e28_SiteLongitude; //40002e28
float fData_40002e30; //40002e30
int Data_40002e34; //40002e34
int Data_40002e38_SiteLatitudeDegrees; //40002e38
int Data_40002e3c_SiteLatitudeMinutes; //40002e3c
float fData_40002e40_SiteLatitudeSeconds; //40002e40
int Data_40002e44; //40002e44
double dData_40002e48_SiteLatitude; //40002e48
float fData_40002e50; //40002e50
int Data_40002e54_Zone; //40002e54
int Data_40002e58; //40002e58
unsigned Data_40002e5c_Year; //40002e5c
unsigned char bData_40002e60_Month; //40002e60
unsigned char bData_40002e61_Day; //40002e61
unsigned char bData_40002e62_Hours; //40002e62
unsigned char bData_40002e63_Minutes; //40002e63
unsigned char bData_40002e64_Seconds; //40002e64
unsigned short wData_40002e66; //40002e66
unsigned char bData_40002e78; //40002e78
unsigned char bData_40002e79_SkyLandTargetSeletion; //40002e79
unsigned char bData_40002e7a_MountType; //40002e7a
unsigned char bData_40002e7b_GpsAvailable; //40002e7b
unsigned char bData_40002e7c_TrackingRateType; //40002e7c
unsigned char bData_40002e7d_RotatingSpeed; //40002e7d
char bData_40002e7e; //40002e7e
int Data_40002e80; //40002e80
int Data_40002e84; //40002e84
unsigned char bData_40002e88; //40002e88
char bData_40002e89; //40002e89
unsigned char bData_40002e8a; //40002e8a
char bData_40002e8b; //40002e8b
char bData_40002e8c; //40002e8c
float fData_40002e90; //40002e90
float Data_40002e94; //40002e94
float fData_40002e98; //40002e98
float Data_40002e9c; //40002e9c
float fData_40002ea0; //40002ea0
int Data_40002ea4; //40002ea4
float fData_40002ea8; //40002ea8
int Data_40002eac; //40002eac
int Data_40002eb0; //40002eb0
unsigned char bData_40002eb4; //40002eb4
unsigned char bData_40002eb5_SolarSystemObjectNr; //40002eb5
unsigned short wData_40002eb6; //40002eb6
unsigned short wData_40002eb8_MessierNr; //40002eb8
unsigned short wData_40002eba_NGCNr; //40002eba
unsigned short wData_40002ebc_ICNr; //40002ebc
unsigned short wData_40002ebe_ShNr; //40002ebe
unsigned short wData_40002ec0_BrightStarNr; //40002ec0
unsigned int Data_40002ec4_SAONr; //40002ec4
int Data_40002ec8; //40002ec8
unsigned short wData_40002ecc; //40002ecc
unsigned char bData_40002ece_ConstellationNr; //40002ece
unsigned short wData_40002ed0; //40002ed0
unsigned char bData_40002ed2_FamousStarNr; //40002ed2
unsigned short wData_40002ed4; //40002ed4
unsigned short wData_40002ed6; //40002ed6
unsigned short wData_40002ed8; //40002ed8
unsigned short wData_40002eda; //40002eda
char bData_40002edc; //40002edc
char bData_40002edd; //40002edd
char bData_40002ede; //40002ede
char bData_40002edf; //40002edf
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
char* Data_40002f20; //40002f20
char* Data_40002f24; //40002f24
char* Data_40002f28; //40002f28
char* Data_40002f2c; //40002f2c
char* Data_40002f30; //40002f30
char* Data_40002f34; //40002f34
char* Data_40002f38; //40002f38
char* Data_40002f3c; //40002f3c
char* Data_40002f40; //40002f40
char* Data_40002f44; //40002f44
char* Data_40002f48; //40002f48
char* Data_40002f4c; //40002f4c
char* Data_40002f50; //40002f50
char* Data_40002f54; //40002f54
char* Data_40002f58; //40002f58
char* Data_40002f5c; //40002f5c
char* Data_40002f60; //40002f60
char* Data_40002f64; //40002f64
char* Data_40002f68; //40002f68
char* Data_40002f6c; //40002f6c
char* Data_40002f70; //40002f70
char* Data_40002f74; //40002f74
char* Data_40002f78; //40002f78
char* Data_40002f7c; //40002f7c
char* Data_40002f80; //40002f80
char* Data_40002f84; //40002f84
char* Data_40002f88; //40002f88
char* Data_40002f8c; //40002f8c
char* Data_40002f90; //40002f90
char* Data_40002f94; //40002f94
char* Data_40002f98; //40002f98
char* Data_40002f9c; //40002f9c
char* Data_40002fa0; //40002fa0
char* Data_40002fa4; //40002fa4
char* Data_40002fa8; //40002fa8
char* Data_40002fac; //40002fac
char* Data_40002fb0; //40002fb0
char* Data_40002fb4; //40002fb4
char* Data_40002fb8; //40002fb8
char* Data_40002fbc; //40002fbc
char* Data_40002fc0; //40002fc0
char* Data_40002fc4; //40002fc4
char* Data_40002fc8; //40002fc8
char* Data_40002fcc; //40002fcc
char* Data_40002fd0; //40002fd0
char* Data_40002fd4; //40002fd4
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
char* Data_40003028;
char* Data_4000302c;
char* Data_40003030;
char* Data_40003034;
char* Data_40003038;
char* Data_4000303c;
char* Data_40003040;
char* Data_40003044;
char* Data_40003048;
char* Data_4000304c;
char* Data_40003050;
char* Data_40003054;
char* Data_40003058;
char* Data_4000305c;
char* Data_40003060;
char* Data_40003064;
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
char* Data_4000309c;
char* Data_400030a0;
char* Data_400030a4;
char* Data_400030a8;
char* Data_400030ac;
char* Data_400030b0;
char* Data_400030b4;
char* Data_400030b8;
char* Data_400030bc;
char* Data_400030c0; //400030c0
char* Data_400030c4; //400030c4
char* Data_400030c8; //400030c8
char* Data_400030cc; //400030cc
char* Data_400030d0;
char* Data_400030d4;
char* Data_400030d8;
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
char* Data_40003114;
char* Data_40003140; //40003140
unsigned char bData_40003144; //40003144
char* Data_4000314c_SolarSystemObjectName; //4000314c
char Data_40003150[9]; //40003150, size??
char Data_40003159[8]; //40003159, size??
unsigned char bData_40003161; //40003161
char bData_40003162; //40003162
int Data_40003164_LunarPhaseYear; //40003164
int Data_40003168_LunarPhaseMonth; //40003168
unsigned char bData_4000316d; //4000316d
unsigned char bData_4000316e_FocusLineOn8LineDisplay; //4000316e
unsigned char bData_4000316f_FocusLineOn4LineDisplay; //4000316f
unsigned char bData_40003170; //40003170
unsigned char bData_40003171; //40003171
unsigned char bData_40003172; //40003172
unsigned char bData_40003173; //40003173
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
unsigned char bData_40003182; //40003182
unsigned char bData_40003184; //40003184
unsigned char bData_40003186; //40003186
char bData_40003188; //40003188
char bData_40003189; //40003189
unsigned char bData_4000318a; //4000318a
int Data_4000318c; //4000318c
int Data_40003190; //40003190
char bData_40003194; //40003194
unsigned char bData_40003195; //40003195
unsigned char bData_40003196_CurrentLanguage; //40003196
unsigned char bData_40003197_DisplayLinesPerMenuLine; //40003197
char bData_40003198; //40003198
char bData_40003199; //40003199
unsigned char bData_4000319a_SkyLandTargetId; //4000319a
char bData_4000319b; //4000319b
char bData_4000319c; //4000319c
char bData_4000319d; //4000319d
Union_400031a0 Data_400031a0; //400031a0
int Data_400031a4; //400031a4
int Data_400031a8; //400031a8
int Data_400031b4; //400031b4
char bData_400031b8; //400031b8
char bData_400031b9; //400031b9
char bData_400031ba; //400031ba
char bData_400031bb; //400031bb
char bData_400031bc; //400031bc
char bData_400031bd; //400031bd
char bData_400031be; //400031be
char bData_400031bf; //400031bf
float fData_400031c0; //400031c0
float fData_400031c4; //400031c4
char bData_400031e0; //400031e0
char bData_400031e1; //400031e1
int Data_400031e4; //400031e4
char bData_400031e9; //400031e9
char bData_400031ea; //400031ea
char bData_400031eb; //400031eb
char bData_400031ec; //400031ec
char bData_400031ed; //400031ed
double dData_400031f0; //400031f0
double dData_400031f8; //400031f8
char bData_40003200; //40003200
char bData_40003201; //40003201
int Data_40003204; //40003204
int Data_40003208; //40003208
char bData_40003210; //40003210
char bData_40003211; //40003211
int Data_40003220_AlarmHours; //40003220
int Data_40003224_AlarmMinutes; //40003224
int Data_40003228_AlarmSeconds; //40003228
char bData_4000322c; //4000322c
char bData_4000322d_AlarmTimeElapsed; //4000322d
float fData_40003238; //40003238
int Data_40003248_CurrentDisplayPWM; //40003248
unsigned short wData_40003250; //40003250
unsigned short wData_40003252; //40003252
unsigned short wData_40003256; //40003256
unsigned char bData_40003258; //40003258
unsigned short wData_4000325a; //4000325a
unsigned char bData_4000325c; //4000325c
unsigned char bData_40003260; //40003260
unsigned char bData_40003261; //40003261
unsigned char bData_40003262; //40003262
unsigned char bData_40003263; //40003263
unsigned char bData_40003265; //40003265
float fData_4000329c; //4000329c
float fData_400032a0; //400032a0
unsigned char bData_400032a4_OTAZeroDataErrorCount; //400032a4
double dData_400032b0_SunRightAscension; //400032b0
double dData_400032b8_SunDeclination; //400032b8
double dData_400032c0; //400032c0
double dData_400032c8; //400032c8
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
char* Data_400033a8; //400033a8
char* Data_400033ac; //400033ac
char* Data_400033b0; //400033b0
char* Data_400033b4; //400033b4
Union_400033c8 Data_400033c8; //400033c8
Union_400033cc Data_400033cc; //400033cc
double dData_400033d8; //400033d8
double dData_400033e0; //400033e0
double dData_400033e8; //400033e8
double dData_400033f0; //400033f0
double dData_400033f8; //400033f8
double dData_40003400; //40003400
int Data_40003408; //40003408
int Data_4000340c; //4000340c
double dData_40003410; //40003410
double dData_40003418; //40003418
double dData_40003420; //40003420
double dData_40003428; //40003428
char bData_40003430; //40003430
char bData_40003431; //40003431
char bData_40003432; //40003432
double dData_40003448; //40003448
double dData_40003450; //40003450
double dData_40003458; //40003458
double dData_40003460; //40003460
int Data_40003488; //40003488
int Data_4000348c; //4000348c
double dData_40003490; //40003490
char bData_40003498; //40003498
double dData_400034a0_SiderealTimeGreenwich0UT; //400034a0
unsigned char bData_400034a8_CurrentAlignStarCount; //400034a8
char bData_400034a9; //400034a9
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
unsigned char bData_4000352d; //4000352d
unsigned char bData_4000352e; //4000352e
float fData_40003540; //40003540
float fData_40003544; //40003544
int Data_40003548; //40003548
unsigned char Data_40003588_uart0ReceiveDataBuffer[10]; //40003588
unsigned char Data_40003592_uart1ReceiveDataBuffer[10]; //40003592
int Data_4000359c_RecentTargetIdArray[8]; //4000359c, size??
unsigned char Data_400035bc[528]; //400035bc
char Data_400037cc[16]; //400037cc
char Data_400037dc[16]; //400037dc
char Data_400037ec[100]; //400037ec, size???
unsigned char Data_40003a14[100][10]; //40003a14, size??
unsigned char Data_40003b2c[100][22]; //40003b2c, size??
Struct_FamousStarData Data_40003d94_FlashFamousStarData; //40003d94
char Data_40003db0[36]; //40003db0, size???
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
char Data_4000410e[21]; //4000410e, size???
Struct_40004128 Data_40004128; //40004128
Struct_40004380 Data_40004380; //40004380
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
unsigned char Data_40004bb8[8]; //40004bb8 size???
char Data_40004c58[2 /*???*/]; //40004c58

