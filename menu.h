
typedef enum
{
	MENU_CONTEXT_MAIN = 0,
	MENU_CONTEXT_MERIDIAN_FLIP = 3,
	
		MENU_CONTEXT_ALIGNMENT = 1000,
			MENU_CONTEXT_ONE_STAR_ALIGN = 1100,
			MENU_CONTEXT_TWO_STAR_ALIGN = 1200,
			MENU_CONTEXT_THREE_STAR_ALIGN = 1300,
				MENU_CONTEXT_ALIGNMENT_STAR_CONTROL = 12001,
			MENU_CONTEXT_TARGET_SYNC = 1400,
			MENU_CONTEXT_POLE_AXIS_DEV = 1500,
			MENU_CONTEXT_RA_BKBLASH_CORR = 1600,
			MENU_CONTEXT_DEC_BKLASH_CORR = 1700,
		MENU_CONTEXT_NAVIGATION = 2000,
			MENU_CONTEXT_NAVIGATION_SOLAR_SYSTEM = 2100,
				MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_SELECTION = 22001,
					MENU_CONTEXT_SOLAR_SYSTEM_OBJECT_TRACKING = 22111,
					MENU_CONTEXT_SUN_WARNING = 22112,
			MENU_CONTEXT_NAVIGATION_CONSTELLATION = 2200,
				MENU_CONTEXT_CONSTELLATION_SELECTION = 24001,
					MENU_CONTEXT_CONSTELLATION_TRACKING = 24002,
			MENU_CONTEXT_NAVIGATION_FAMOUS_STAR = 2300,
				MENU_CONTEXT_FAMOUS_STAR_SELECTION = 25001,
					MENU_CONTEXT_FAMOUS_STAR_TRACKING = 25002,
			MENU_CONTEXT_NAVIGATION_MESSIER_CAT = 2400,
				MENU_CONTEXT_MESSIER_OBJECT_DETAILS = 23012,
					MENU_CONTEXT_MESSIER_OBJECT_SELECTION = 23002,
						MENU_CONTEXT_MESSIER_OBJECT_TRACKING = 23022,
			MENU_CONTEXT_NAVIGATION_NGC_CAT = 2500,
				MENU_CONTEXT_NGC_OBJECT_SELECTION = 23003,
					MENU_CONTEXT_NGC_OBJECT_TRACKING = 23013,
			MENU_CONTEXT_NAVIGATION_IC_CAT = 2600,
				MENU_CONTEXT_IC_OBJECT_SELECTION = 23004,
					MENU_CONTEXT_IC_OBJECT_TRACKING = 23014,
			MENU_CONTEXT_NAVIGATION_SH2_CAT = 2700,
				MENU_CONTEXT_SH2_OBJECT_SELECTION = 23005,
					MENU_CONTEXT_SH2_OBJECT_TRACKING = 23015,
			MENU_CONTEXT_NAVIGATION_BRIGHT_STAR = 2800,
				MENU_CONTEXT_BRIGHT_STAR_SELECTION = 23006,
					MENU_CONTEXT_BRIGHT_STAR_TRACKING = 23016,
			MENU_CONTEXT_NAVIGATION_SAO_CAT = 2900,
				MENU_CONTEXT_SAO_OBJECT_SELECTION = 23007,
					MENU_CONTEXT_SAO_OBJECT_TRACKING = 23017,
			MENU_CONTEXT_NAVIGATION_CUST_OBJ = 2110,
			MENU_CONTEXT_NAVIGATION_RA_DEC = 2120,
			MENU_CONTEXT_NAVIGATION_CUST_LAND = 2130,
		MENU_CONTEXT_UTILITIES = 3000,
			MENU_CONTEXT_CURRENT_OBJECTS = 3100,
			MENU_CONTEXT_OBJECT_RISE_SET = 3200,
			MENU_CONTEXT_EYEPIECE_FOV = 3600,
			MENU_CONTEXT_EYEPIECE_MAGN = 3700,
			MENU_CONTEXT_DISPLAY_ILLUMINATION = 3800,
				MENU_CONTEXT_DISPLAY_ILLUMINATION_CONTROL = 380011,
			MENU_CONTEXT_PARK_POSITION = 3900,
		MENU_CONTEXT_SETUP = 4000,
			MENU_CONTEXT_TIME_DATE = 4100,
			MENU_CONTEXT_SITE_SETTING = 4300,
				MENU_CONTEXT_COUNTRY_CITY = 4301,
					MENU_CONTEXT_COUNTRY_CITY_SELECTION = 43011,
				MENU_CONTEXT_CUSTOM_SITE = 4302,
					MENU_CONTEXT_CUSTOM_SITE_INPUT = 43002,
			MENU_CONTEXT_AZ_EQU = 4500,
				MENU_CONTEXT_MOUNT_AZ = 46001,
				MENU_CONTEXT_MOUNT_EQU = 46002,
			MENU_CONTEXT_TELESCOPE_MOUNT = 4600,
			MENU_CONTEXT_TRACKING_RATE = 4700,
				MENU_CONTEXT_TRACKING_RATE_STAR_SPEED = 4801,
				MENU_CONTEXT_TRACKING_RATE_SOLAR_SPEED = 4802,
				MENU_CONTEXT_TRACKING_RATE_MOON_SPEED = 4803,
				MENU_CONTEXT_TRACKING_RATE_CUSTOM_SPEED = 4804,
				MENU_CONTEXT_TRACKING_RATE_GUIDING_SPEED = 4805,
					MENU_CONTEXT_GUIDING_SPEED1 = 48051,
					MENU_CONTEXT_GUIDING_SPEED2 = 48052,
					MENU_CONTEXT_GUIDING_SPEED3 = 48053,
					MENU_CONTEXT_GUIDING_SPEED4 = 48054,
					MENU_CONTEXT_GUIDING_SPEED5 = 48055,
					MENU_CONTEXT_GUIDING_SPEED6 = 48056,
					MENU_CONTEXT_GUIDING_SPEED7 = 48057,
					MENU_CONTEXT_GUIDING_SPEED8 = 48058,
			MENU_CONTEXT_RESET = 4900,
				MENU_CONTEXT_RESET_CONFIRM = 100,
	
} MENU_CONTEX_ID;

typedef enum
{
	MENU_ROTATING_SPEED_1 = 1,
	MENU_ROTATING_SPEED_2 = 2,
	MENU_ROTATING_SPEED_8 = 3,
	MENU_ROTATING_SPEED_16 = 4,
	MENU_ROTATING_SPEED_64 = 5,
	MENU_ROTATING_SPEED_128 = 6,
	MENU_ROTATING_SPEED_256 = 7,
	MENU_ROTATING_SPEED_512 = 8,
	MENU_ROTATING_SPEED_MAX = 9,
	
} MENU_ROTATING_SPEED;

typedef enum
{
	MENU_MOUNT_TYPE_AZ = 0,
	MENU_MOUNT_TYPE_EQU = 1,
	
} MENU_MOUNT_TYPE;

typedef enum
{
	MENU_TRACKING_RATE_STAR_SPEED = 0,
	MENU_TRACKING_RATE_SOLAR_SPEED = 1,
	MENU_TRACKING_RATE_MOON_SPEED = 2,
	
} MENU_TRACKING_RATE_TYPE;

typedef enum
{
	MENU_TRACKING_MODE_STOP = 0,
	MENU_TRACKING_MODE_POINTING = 1,
	MENU_TRACKING_MODE_TRACKING = 2,
	MENU_TRACKING_MODE_UNDER_HORIZON = 3,
	MENU_TRACKING_MODE_SLEWING = 10,
	
} MENU_TRACKING_MODE;	

typedef enum
{
	MENU_RECENT_TARGET_SOLAR_SYSTEM = 1,
	MENU_RECENT_TARGET_CONSTELLATION = 2,
	MENU_RECENT_TARGET_FAMOUS_STAR = 3,
	MENU_RECENT_TARGET_MESSIER = 4,
	MENU_RECENT_TARGET_NGC = 5,
	MENU_RECENT_TARGET_IC = 6,
	MENU_RECENT_TARGET_SH2 = 7,
	MENU_RECENT_TARGET_BRIGHT_STAR = 8,
	MENU_RECENT_TARGET_SAO_CAT = 9,
	
} MENU_RECENT_TARGET_TYPE;


