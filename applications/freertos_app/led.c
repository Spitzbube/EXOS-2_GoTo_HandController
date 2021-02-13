
#include "periph.h"
#include "led.h"

unsigned char g_iLedTorchLevel; //40003195


void HandleStarKey(void)
{
	switch (g_iLedTorchLevel)
	{
		case 0:
			GPIO_LED1_3_OFF;
			GPIO_LED2_OFF;
			g_iLedTorchLevel = 1;
			break;

		case 1:
			GPIO_LED1_3_OFF;
			GPIO_LED2_ON;
			g_iLedTorchLevel = 2;
			break;

		case 2:
			GPIO_LED1_3_ON;
			GPIO_LED2_ON;
			g_iLedTorchLevel = 0;
			break;

		default:
			break;
	}
}

#ifdef LED_TASK
void vLEDTask( void *pvParameters )
{
	int off = 1;

	GPIO_LED2_ON;

	for( ;; )
	{
		vTaskDelay( ( TickType_t ) 1000 / portTICK_PERIOD_MS );

		if (off)
		{
			GPIO_LED2_OFF;
			off = 0;
		}
		else
		{
			GPIO_LED2_ON;
			off = 1;
		}
	}
}
#endif

