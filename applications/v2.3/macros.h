

#define DEGREES_MINUTES_ABS(a) \
	abs((int)a), abs((int)((a - (int)a) * 60))
		
	
#define DEGREES_MINUTES(a) \
	((int)a), ((int)((a - (int)a) * 60))
		
	
#define UART1_WRITE_HEADER(len) \
	uart1_write_byte(0x55); \
	uart1_write_byte(0xaa); \
	uart1_write_byte(0x01); \
	uart1_write_byte(len);

