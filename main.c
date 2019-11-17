
#include <LPC214x.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "my_types.h"
#include "data.h"



/* 6a0e4 - todo */
char func_6a0e4(int* a)
{
	char r4;
	int r3 = func_11d8();
	
	*a = r3;
	
	if (r3 & 0x20)
	{
		r3 &= 0x1f;
		
		func_1210();		
	}
	else
	{
		r3 = 100;
	}
	
	switch (r3)
	{
		case 1:
			//0x6a18c
			r4 = 16;
			break;
		
		case 2:
			//0x6a198
			r4 = 1;
			break;
		
		case 3:
			//0x6a1a4
			r4 = 4;
			break;
		
		case 4:
			//0x6a1b0
			r4 = 7;
			break;
		
		case 5:
			//0x6a1bc
			r4 = 10;
			break;
		
		case 6:
			//0x6a1c8
			r4 = 15;
			break;
		
		case 7:
			//0x6a1d4
			r4 = 2;
			break;
		
		case 8:
			//0x6a1e0
			r4 = 5;
			break;
		
		case 9:
			//0x6a1ec
			r4 = 8;
			break;
		
		case 10:
			//0x6a1f8
			r4 = 0;
			break;
		
		case 11:
			//0x6a204
			r4 = 17;
			break;
		
		case 12:
			//0x6a210
			r4 = 3;
			break;
		
		case 13:
			//0x6a21c
			r4 = 6;
			break;
		
		case 14:
			//0x6a228
			r4 = 9;
			break;
		
		case 15:
			//0x6a234
			r4 = 11;
			break;
		
		case 16:
			//0x6a240
			r4 = 14;
			break;
		
		case 17:
			//0x6a24c
			r4 = 19;
			break;
		
		case 18:
			//0x6a258
			r4 = 12;
			break;
		
		case 19:
			//0x6a264
			r4 = 20;
			break;
		
		case 20:
			//0x6a270
			r4 = 13;
			break;
		
		case 21:
			//0x6a27c
			r4 = 21;
			break;
		
		case 22:
			//0x6a288
			r4 = 22;
			break;
		
		case 23:
			//0x6a294
			r4 = 23;
			break;
		
		case 24:
			//0x6a2a0
			r4 = 24;
			break;

		default:
			//6a2ac
			break;
	}
	
	return r4;
}


int main(void)
{
	int j, i = 0;

	func_2328();
	uart0_init(360);
	uart1_init(360);

	func_7e8(0, 3, 1, 22, "Hello World!");
	
	while (1) //Main Loop
	{
		char buf[100];
		int key;
		char keyCode = func_6a0e4(&key);
		
		snprintf(buf, sizeof(buf)-1, "key=%d, code=%d", key, keyCode);

		func_7e8(0, 5, 1, 22, buf);

		i++;
		
		for (j = 0; j < 100000; j++) /*wait*/;
	}
}

