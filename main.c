
extern void uart0_init(int);
extern void uart1_write_byte(char);
extern void uart1_init(int);
extern void func_2254(unsigned int);
extern void func_2328(void);
extern void func_243c(int, int, int, char*);
extern void func_24d4(int, int, int, char*);

extern void func_659c(int);
extern void func_7590(void);
extern void func_d2cc(void);

extern void func_5099c(void);
extern void func_51368(void);

extern char bData_40002c13; //40002c13
float /*???*/ Data_40002e98; //40002e98
char Data_40003196; //40003196

char Data_40003592[3 /*???*/]; //40003592
char Data_40004c58[2 /*???*/]; //40004c58

/* 6ab74 - todo */
long double func_6ab74(int a)
{
	char r5;
	union
	{
		char b[4];
		int i;
	} sp8;
	struct
	{
		double d;
	} ret;

	bData_40002c13 = 0;
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(0x01);
	uart1_write_byte(0x01);
	
	switch (a)
	{
		case 1:
			uart1_write_byte(0x10);
			break;
		
		case 2:
			uart1_write_byte(0x30);
			break;
		
		case 3:
			uart1_write_byte(0x50);
			break;
		
		case 4:
			uart1_write_byte(0x70);
			break;
		
		default:
			break;
	}

	bData_40002c13 = 0;
	
	func_2254(10);
	
	for (r5 = 50; (bData_40002c13 == 0) && (r5 > 2); r5--)
	{
		func_659c(5);
	}
	
	sp8.i = 0;
		
	if (bData_40002c13 == 1)
	{
		switch (a)
		{
			case 1:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  ret.d = sp8.i;
				break;
			
			case 2:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  ret.d = sp8.i;
				break;
			
			case 3:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  ret.d = sp8.i;
				break;
			
			case 4:
				sp8.b[1] = Data_40003592[1];
				sp8.b[0] = Data_40003592[2];
			  ret.d = sp8.i;
				break;
		}
		
		bData_40002c13 = 0;
	}

	return ret.d;
}

/* 6c804 */
void func_6c804()
{
	//TODO
}

/* 6d054 - todo */
int main(void)
{
	//struct
	//{
		double d;
	//} sp64;
	
	func_2328();
	uart0_init(360);
	uart1_init(360);
	func_7590();
	func_d2cc();
	func_5099c();
	func_243c(0xdcb, 0, 10, Data_40004c58);
	Data_40003196 = Data_40004c58[0];
	if (Data_40004c58[1] == 1)
	{
		func_51368();
		Data_40004c58[1] = 0;
		func_24d4(0xdcb, 0, 2, Data_40004c58);
	}

	func_6c804();
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x44);

	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x64);
	
	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x04);

	uart1_write_byte(0x55);
	uart1_write_byte(0xaa);
	uart1_write_byte(1);
	uart1_write_byte(1);
	uart1_write_byte(0x24);
	
	func_659c(10);
	
	Data_40002e98 = d = func_6ab74(1);
	
	d = d * 2;
//	d = sp64.d + sp64.d;
	
}


double float_test(double a)
{
	float f1 = (int) 28827267;
	float f2 = (unsigned int) 6376367;

	double d1 = (int) 2765262;
	double d2 = 784748;

	f1 = sqrt(f1);
	f1 = f1 * f2;
	f1 = f1 / f2;

    d1 = d1 + f1;
	d1 = d1 - f1;
	d1 = d1 + (f1 + f2);
	d1 = d1 + (f1 - f2);

	d1 = d1 + d2;
	d1 = d1 - d2;
	d1 = d1 * d2;
	d1 = d1 / d2;
//	d1 = d1 % d2;

    d1 = sqrt(d1);

	return d1;
}


