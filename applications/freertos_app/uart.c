
#include "my_types.h"
#include "data.h"
#include "FreeRTOS.h"
#include "queue.h"


void uart0_send(unsigned char* a, unsigned char b);


QueueHandle_t xQueueUart1;



/* 19f0 - complete */
#ifdef __GNUC__
void uart1_isr(void) __attribute__ ((interrupt ("IRQ")));
void uart1_isr(void)
#else
void uart1_isr(void) __irq
#endif
{
	uart1_bRxData = U1RBR;
	
	if (bData_40002c1a == 0)
	{
		//First Response from Mount
		bData_40002c1a = 3;
	}
	
	if (bData_40002c13_uart1ReceiveComplete == 0)
	{
		switch (bData_40002c14_uart1ReceiveStep)
		{
			case 0:
				//Check first byte of header signature
				if (bData_40002c15_uart1ReceiveHeader[0] == uart1_bRxData)
				{
					bData_40002c14_uart1ReceiveStep++;
				}
				break;
			
			case 1:
				//Check second byte of header signature
				if (bData_40002c15_uart1ReceiveHeader[1] == uart1_bRxData)
				{
					bData_40002c14_uart1ReceiveStep++;
				}
				else
				{
					bData_40002c14_uart1ReceiveStep = 0;
				}
				break;
			
			case 2:
				//Check third byte of header signature
				if (bData_40002c15_uart1ReceiveHeader[2] == uart1_bRxData)
				{
					bData_40002c14_uart1ReceiveStep++;
				}
				else
				{
					bData_40002c14_uart1ReceiveStep = 0;
				}
				break;
			
			case 3:
				//Check and store payload length information
				if (uart1_bRxData < 10)
				{
					bData_40002c15_uart1ReceiveHeader[3] = uart1_bRxData;
					bData_40002c14_uart1ReceiveStep++;
				}
				else
				{
					bData_40002c14_uart1ReceiveStep = 0;
				}
				break;
			
			case 4:
				//Store payload data
				if (bData_40002c15_uart1ReceiveHeader[3] > bData_40002c12_uart1ReceiveDataCount)
				{
					Data_40003592_uart1ReceiveDataBuffer[bData_40002c12_uart1ReceiveDataCount] = uart1_bRxData;
					bData_40002c12_uart1ReceiveDataCount++;
					if (bData_40002c12_uart1ReceiveDataCount == bData_40002c15_uart1ReceiveHeader[3])
					{
#if 1
#if 0
						BaseType_t xHigherPriorityTaskWokenByPost = pdFALSE;

						xQueueSendFromISR(xQueueUart1,
								&Data_40003592_uart1ReceiveDataBuffer[0],
								&xHigherPriorityTaskWokenByPost);

						if (xHigherPriorityTaskWokenByPost)
						{
							//portYIELD_FROM_ISR();
						}
#endif
#else
						int i;
						for (i = 0; i < bData_40002c12_uart1ReceiveDataCount; i++)
						{
							char buf[20];
							snprintf(buf, sizeof(buf)-1, "Rx%d=0x%02x\n\r", i,
									Data_40003592_uart1ReceiveDataBuffer[i]);
							uart0_send(buf, strlen(buf));
						}
#endif
						bData_40002c13_uart1ReceiveComplete = 1;
						bData_40002c14_uart1ReceiveStep = 0;
						bData_40002c12_uart1ReceiveDataCount = 0;
						
						if (!((bData_40002c1a == 1) && (bData_40002c1a == 2)))
						{
							//First Response from Mount
							switch (Data_40003592_uart1ReceiveDataBuffer[0])
							{
								case 0x04:
								case 0x24:
									//EQU
									bData_40002c1a = 1;
									break;
								
								case 0x44:
								case 0x64:
									//AZ
									bData_40002c1a = 2;
									break;
								
								default:
									break;
							}
						}
					}
				}
				break;

			default:
				break;
		}
	}
	
	VICVectAddr = 0;
}

/* 1c88 - complete */
#ifdef __GNUC__
void uart0_isr(void) __attribute__ ((interrupt ("IRQ")));
void uart0_isr(void)
#else
void uart0_isr(void) __irq
#endif
{
	uart0_bRxData = U0RBR;
	
	if (uart0ReceiveFlag == 0)
	{
		switch (bData_40002c0c_uart0ReceiveStep)
		{
			case 0:
				//Check first byte of header signature
				if (Data_40002c0d_uart0ReceiveHeader[0] == uart0_bRxData)
				{
					bData_40002c0c_uart0ReceiveStep++;
				}
				break;
			
			case 1:
				//Check second byte of header signature
				if (Data_40002c0d_uart0ReceiveHeader[1] == uart0_bRxData)
				{
					bData_40002c0c_uart0ReceiveStep++;
				}
				else
				{
					bData_40002c0c_uart0ReceiveStep = 0;
				}
				break;
			
			case 2:
				//Check third byte of header signature
				if (Data_40002c0d_uart0ReceiveHeader[2] == uart0_bRxData)
				{
					bData_40002c0c_uart0ReceiveStep++;
				}
				else
				{
					bData_40002c0c_uart0ReceiveStep = 0;
				}
				break;
			
			case 3:
				//Store payload length information
				if (uart0_bRxData < 10)
				{
					Data_40002c0d_uart0ReceiveHeader[3] = uart0_bRxData;
					bData_40002c0c_uart0ReceiveStep++;
				}
				else
				{
					bData_40002c0c_uart0ReceiveStep = 0;
				}
				break;
			
			case 4:
				//Store payload data
				if (Data_40002c0d_uart0ReceiveHeader[3] > bData_40002c0a_uart0ReceiveDataCount)
				{
					uart0ReceiveDataBuffer[bData_40002c0a_uart0ReceiveDataCount] = uart0_bRxData;
					bData_40002c0a_uart0ReceiveDataCount++;
					if (Data_40002c0d_uart0ReceiveHeader[3] == bData_40002c0a_uart0ReceiveDataCount)
					{
						uart0ReceiveFlag = 1;
						bData_40002c0c_uart0ReceiveStep = 0;
						bData_40002c0a_uart0ReceiveDataCount = 0;
						
						switch (uart0ReceiveDataBuffer[0])
						{
							case 1:
								g_iUart0GuideValueRa = -1;
								uart0ReceiveFlag = 0;
								break;
							
							case 2:
								g_iUart0GuideValueRa = 1;
								uart0ReceiveFlag = 0;
								break;
							
							case 4:
								g_iUart0GuideValueDec = -1;
								uart0ReceiveFlag = 0;
								break;
							
							case 8:
								g_iUart0GuideValueDec = 1;
								uart0ReceiveFlag = 0;
								break;
							
							default:
								break;
						}
					}
				}
				break;
		
			default:
				break;
		}
	}
	
	VICVectAddr = 0;
}

/* 1f30 - complete */
void uart0_init(int a)
{
	U0LCR = 0x83;

#ifdef OLIMEX_LPC2148
	// 12000000 * 2/2 / (16 * 78) = 9615.38 => 9600
	U0DLM = 0;
	U0DLL = 78;
#else
	// 11059200 * 2/2 / (16 * 72) = 9600
	U0DLM = 0;
	U0DLL = 72;
#endif

	U0LCR = 0x03;
	U0FCR = 0x01; //U0IIR = 0x01;?
	U0IER = 0x01;
	#if 1
	VICVectAddr1 = (unsigned int) uart0_isr; //UART0 -> Slot 1
	#else
	VICVectAddr2 = (unsigned int) uart0_isr; //UART0 -> Slot 2
	#endif
	
	bData_40002c0a_uart0ReceiveDataCount = 0;
	uart0ReceiveFlag = 0;
	bData_40002c0c_uart0ReceiveStep = 0;
	Data_40002c0d_uart0ReceiveHeader[0] = 0x55;
	Data_40002c0d_uart0ReceiveHeader[1] = 0xaa;
	Data_40002c0d_uart0ReceiveHeader[2] = 0x01;
	Data_40002c0d_uart0ReceiveHeader[3] = 0x00; //payload length information
}

/* 1fb0 - complete */
unsigned char uart0_read_byte(void)
{
	unsigned char b;
	while (!(U0LSR & 0x01)) {}
  b = U0RBR;
	return b;
}

/* 2054 - complete */
void uart0_receive(unsigned char* a, int b)
{
	while (b)
	{
		*a++ = uart0_read_byte();
		b--;
	}
}

/* 2080 - complete */
void uart0_write_byte(unsigned char a)
{
	U0THR = a;
	while (!(U0LSR & 0x40)) {}
}

/* 20a0 - complete */
void uart0_send(unsigned char* a, unsigned char b)
{
	while (b--)
	{
		uart0_write_byte(*a++);
	}
}

/* 20d0 - complete */
void uart0_send_packets(unsigned char* a)
{
	unsigned char i;
	
	while (1)
	{
		if (*a == 0) break;
		
		for (i = 0; i < 44; i++)
		{
			uart0_write_byte(*a++);
		}
	}
}

/* 211c - complete */
void uart1_init(int a)
{
	U1LCR = 0x83;

#ifdef OLIMEX_LPC2148
	// 12000000 * 2/2 / (16 * 78) = 9615.38 => 9600
	U1DLM = 0;
	U1DLL = 78;
#else
	// 11059200 * 2/2 / (16 * 72) = 9600
	U1DLM = 0;
	U1DLL = 72;
#endif

	U1LCR = 0x03;
	U1FCR = 0x01; //
	U1IER = 0x01;
	#if 1
	VICVectAddr2 = (unsigned int) uart1_isr; //UART1 -> Slot 2
	#else
	VICVectAddr3 = (unsigned int) uart1_isr; //UART1 -> Slot 3
	#endif
	
	bData_40002c12_uart1ReceiveDataCount = 0;
	bData_40002c13_uart1ReceiveComplete = 0;
	bData_40002c14_uart1ReceiveStep = 0;
	bData_40002c15_uart1ReceiveHeader[0] = 0x55;
	bData_40002c15_uart1ReceiveHeader[1] = 0xaa;
	bData_40002c15_uart1ReceiveHeader[2] = 0x01;
	bData_40002c15_uart1ReceiveHeader[3] = 0x00;

	xQueueUart1 = xQueueCreate(2, 10);
}

/* 219c - complete */
unsigned char uart1_read_byte(void)
{
	unsigned char b;
	while (!(U1LSR & 0x01)) {}
	b = U1RBR;
	return b;
}

/* 21bc - complete */
void uart1_receive(unsigned char* a, int b)
{
	while (b)
	{
		*a++ = uart1_read_byte();
		b--;
	}
}

/* 21e8 - complete */
void uart1_write_byte(unsigned char a)
{
	U1THR = a;
	while (!(U1LSR & 0x40)) {}
#if 0
	{
		char buf[20];
		snprintf(buf, sizeof(buf)-1, "Tx=0x%02x\n\r", a);
		uart0_send(buf, strlen(buf));
	}
#endif
}

#ifdef OLIMEX_LPC2148
void uart1_send(unsigned char* a, unsigned char b)
{
	while (b--)
	{
		uart1_write_byte(*a++);
	}
}
#endif

/* 2208 - complete */
void uart1_send_packets(unsigned char* a)
{
	unsigned char i;
	
	while (1)
	{
		if (*a == 0) break;
		
		for (i = 0; i < 44; i++)
		{
			uart1_write_byte(*a++);
		}
	}
}

