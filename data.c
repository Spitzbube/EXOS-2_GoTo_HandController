
#include "my_types.h"
//#include "data.h"

unsigned char Data_40000000[28][10]; //40000000
unsigned char Data_40000118[28][22]; //40000118, size??

char bData_40002837; //40002837

union
{
	unsigned char bData[2]; 
	unsigned short wData;
} Data_40002c24; //40002c24
union
{
	unsigned char bData[4]; 
	int Data;
} Data_40002c28; //40002c28
