
extern void uart0_init(int);
extern void uart1_write_byte(char);
extern void uart1_init(int);
extern void func_7e8(int, int, int, unsigned char, const unsigned char*);
extern void func_2254(unsigned int);
extern void func_2328(void);
extern void func_243c(int, int, int, char*);
extern void func_24d4(int, int, int, char*);
extern void func_27c4(float*, float*);

extern void func_659c(int);
extern void func_7590(void);
extern void func_d2cc(void);

extern void func_5099c(void);
extern void func_51368(void);

extern char bData_40002c13; //40002c13
extern char bData_40002c1a; //40002c1a
char bData_40002e7a; //40002e7a
float Data_40002e98; //40002e98
float Data_40002ea8; //40002ea8
char Data_40003196; //40003196
float Data_4000329c; //4000329c
float Data_400032a0; //400032a0
char bData_40003432; //40003432
double Data_400034d0; //400034d0
double Data_400034d8; //400034d8
unsigned char Data_40003588[3 /*???*/]; //40003588
unsigned char Data_40003592[3 /*???*/]; //40003592
extern struct
{
	int fill_0[48]; //0
	double Data_192; //192
	double Data_200; //200
} Data_40004128; //40004128
char Data_40004c58[2 /*???*/]; //40004c58

/* 50b40 - todo */
void func_50b40(void)
{
	//TODO
	//50c98
	Data_400034d0 = 0.05;
	Data_400034d8 = 0.045;
}

/* 6ab74 - todo */
double func_6ab74(int a)
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
void func_6c804(void)
{
	func_7e8(0, 3, 1, 22, " BRESSER GOTO SYSTEM  ");
	func_7e8(0, 5, 1, 22, "     EXOS EQ v2.3     ");
}

/* 6d054 - todo */
int main(void)
{
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
	
	Data_40002e98 = func_6ab74(1);

	func_659c(50);
	
	Data_40002ea8 = func_6ab74(2);

	func_659c(50);

	if (bData_40002c1a == 1)
	{
		bData_40002e7a = 1;
	}
	else
	{
		bData_40002e7a = 0;
	}
	
	bData_40003432 = 0;
		
	Data_400034d0 = 0.05; //?
	Data_400034d8 = 0.045; //?
	
	Data_40004128.Data_192 = 100.0; //?
	Data_40004128.Data_200 = 60.0; //?
	
	func_27c4(&Data_4000329c, &Data_400032a0);
	
	Data_40004128.Data_192 = Data_4000329c;
	Data_40004128.Data_200 = Data_400032a0;
	
	//TODO
}


