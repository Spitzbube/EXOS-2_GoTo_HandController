
#define FALSE 0
#define TRUE  1

typedef struct
{
	unsigned char bData_0[12]; //0
	unsigned char bData_12[12]; //12
	int Data_24; //24
	unsigned char bData_28[14]; //28
	unsigned char bData_42[10]; //42
	float fData_52; //52
	float fRightAscension; //56
	float fDeclination; //60
} Struct_FamousStarData;

typedef struct
{
	unsigned char bData_0[5]; //0
	unsigned char bData_5[21]; //5
	unsigned char bData_26[10]; //26
	float fRightAscension; //36
	float fDeclination; //40
	unsigned short wArea; //44 / Square Degrees?
	unsigned char bData_46; //46
	unsigned char bQuantity; //47 / Number of Stars >6Mag?
} Struct_ConstellationData;

typedef struct
{
	unsigned short wData_0; //0
	float fRightAscension; //4
	float fDeclination; //8
	float fData_12; //12
	double dData_16; //16
	unsigned char bData_24[8]; //24, size??
	unsigned char bData_32[16]; //32, size??
	unsigned char bData_48[12]; //48, size??
	unsigned char bData_60[26]; //60, size??
	unsigned char bData_86[22]; //86, size??
	unsigned char bData_108[36]; //108, size??
	char fill[8]; //???
} Struct_MessierData;

typedef struct
{
	unsigned char bData_0[18]; //0
	float fRightAscension; //20
	float fDeclination; //24
	float fData_28; //28
} Struct_BrightStarData;

typedef struct
{
	float fRightAscension; //0
	float fDeclination; //4
	
} Struct_Sh2Data;

typedef struct
{
	unsigned char bData_0[5]; //0
	float fRightAscension; //8
	float fDeclination; //12
	float fData_16; //16
	unsigned char bData_20[10]; //20 size??
} Struct_ICData;

typedef struct
{
	unsigned char bData_0[5]; //0
	float fRightAscension; //8
	float fDeclination; //12
	float fData_16; //16
	unsigned char bData_20[10]; //20 size??
	char fill_30[28]; //30
} Struct_NGCData;

typedef struct
{
	float ra; //0
	float dec; //4
	
} Struct_SAOData;

typedef struct
{
	unsigned char bData_0[10]; //0
	unsigned char bData_10[10]; //10
	float fData_20; //20
	float fData_24; //24
} Struct_4dd0;

typedef struct
{	
	unsigned char cCountry[20]; //0
	unsigned char cCity[20]; //20
	float fLongitude; //40
	float fLatitude; //44
	int Zone; //48
} Struct_SiteData;

typedef struct
{
	unsigned char bData_0; //0
	unsigned char bData_1[9]; //1
	float fData_12; //12
	float fData_16; //16
} Struct_5218;

typedef struct
{
	unsigned char bData_0;
	unsigned char bData_1[8]; //1
	float fData_12; //12
	float fData_16; //16
} Struct_54e0;

typedef struct
{
	unsigned short wYear; //0
	unsigned char bMonth; //2
	unsigned char bDay; //3
	unsigned char bHours; //4
	unsigned char bMinutes; //5
	unsigned char bSeconds; //6
	unsigned short wMilliSeconds; //8
} Struct_DateTime;

typedef struct
{
	double dData_0; //0
	double dData_8; //8 
	double dData_16; //16
	double dData_24; //24
	double dData_32; //32
	double dData_40; //40
} Struct_7978;

typedef struct
{
	double dLongitude; //0
	double dLatitude; //8
	
} Struct_GeographicCoordinates;

typedef struct
{
	double dRA; //0
	double dDec; //8
	double fill1; //16
	double fill2;	//24
} Struct_EquatorialCoordinates;

typedef struct
{
	double dData_0; 
	double dData_8; 
	double dData_16; 
	double dData_24; 
	double dData_32; 
	double dData_40; 
} Struct_b1a8;

typedef struct
{
	double dData_0; 
	double dData_8; 
	double dData_16; 
	double dData_24; 
	double dData_32; 
	double dData_40; 
} Struct_b7f4;


typedef struct
{
	double dData_0; 
	double dData_8; 
	double dData_16; 
	double dData_24; 
	//
} Struct_40004b70;


typedef struct
{
	double dData_0; 
	double dAzimuth; //8
	double dZenithDistance; //16
	double dAltitude; //24 
	double dData_32; 
	double dData_40; 
	double dData_48;
	double fill1; //56
	double fill2; //64
	//72
} Struct_HorizontalCoordinates;

typedef struct
{
	unsigned short wData_0; //0
	unsigned short wData_2; //2
	unsigned short wData_4; //4
	
} Struct_40003290;

typedef struct
{
	unsigned char bData_0; //0
	unsigned char bData_1; //1
	unsigned char bData_2; //2
	
} Struct_40003296;


typedef enum
{
	SLEW_STOP = 0,
	SLEW_RATE_1X = 1,
	SLEW_RATE_2X = 2,
	SLEW_RATE_8X = 3,
	SLEW_RATE_16X = 4,
	SLEW_RATE_64X = 5,
	SLEW_RATE_128X = 6,
	SLEW_RATE_256X = 7,
	SLEW_RATE_512X = 8,
	SLEW_RATE_MAX = 9,

} eSlewRate;


