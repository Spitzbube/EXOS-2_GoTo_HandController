
#include <LPC214x.h>
#include "my_types.h"
#include "data.h"

extern void func_243c(unsigned int PageAdr, int b, int Count, unsigned char* Data);
extern void func_2df8(int a, int b, int c, int d, unsigned char* e);
extern void func_5f40(void);


/* 5099c - todo */
void func_5099c(void)
{
	func_5f40();
	
	bData_4000316e_FocusLineOn8LineDisplay = 0;
	Data_4000318c = 0;
	Data_40003190 = 1;
	bData_40003194 = 0;
	bData_40003196_CurrentLanguage = 1;
	bData_4000319c = 0;
	bData_4000319d = 0;
	bData_40003198 = 0;
	bData_40003199 = 0;
	bData_40002c1a = 0;
	bData_40003431 = 0;
	bData_40003210 = 0;
	bData_40003211 = 0;
	bData_400031bf = 0x42;
	bData_400031be = 0;
	fData_400031c0 = 10.6;
	fData_400031c4 = 63.25;
	bData_400031e0 = 1;
	bData_40003188 = 0;
	bData_40003189 = 0;
	bData_40003195 = 0;
	bData_400031e1 = 0;
	bData_400032a4 = 0;
	bData_4000319b = 0;
	bData_400031e9 = 0;
	bData_400031b8 = 0;
	bData_400031b9 = 0;
	Data_40002e80 = 0;
	Data_40002e84 = 0;
	bData_4000322d = 0;
	bData_400031ea = 0;
	bData_400031eb = 0;
	bData_400031ec = 1;
	bData_400031ed = 1;
	dData_400031f0 = 0.0;
	dData_400031f8 = 0.0;
	bData_40003200 = 0;
	bData_40003201 = 0;
	Data_40003204 = 0;
	Data_40003208 = 0;
	bData_40002d88 = 0;
	bData_40002da8 = 0;
}


/* 51368 - todo */
int ValidateDateTimeSetRTC(void)
{
	int valid = 1;
	unsigned short y;
	unsigned char m;
	unsigned char d;
	unsigned char h;
	unsigned char min;
	unsigned char s;
	y = atoi(Data_40002655);
	m = atoi(&Data_40002655[5]);
	
	if ((m > 12) || (m == 0))
	{
		return 0;
	}
	
	d = atoi(&Data_40002655[8]);
	
	switch (m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d > 31) valid = 0;
			break;
		
		case 2:
			if (d > 29) valid = 0;
			break;
		
		case 4:
		case 6:
		case 9:
		case 11:
			if (d > 30) valid = 0;
			break;
		
		default:
			break;
	}
	
	if (d < 1) valid = 0;
	
	if (valid == 0) 
	{
		return 0;
	}
	
	h = atoi(Data_40002660);
	min = atoi(&Data_40002660[3]);
	s = atoi(&Data_40002660[6]);
	
	if ((h > 23) || (min > 59) || (s > 59))
	{
		return 0;
	}
	
	CCR = (1 << 4);
	YEAR = y;
	MONTH = m;
	DOM = d;
	HOUR = h;
	MIN = min;
	SEC = s;
	CCR = (1 << 4) | (1 << 0); //CLKEN = 1
	
	return 1;
}

