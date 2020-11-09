//
//  $Id: main.c 328 2008-11-09 05:00:23Z jcw $
//  $Revision: 328 $
//  $Author: jcw $
//  $Date: 2008-11-09 00:00:23 -0500 (Sun, 09 Nov 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/main.c $
//

//
//  Standard includes
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//
// Scheduler includes
//
#include "FreeRTOS.h"
#include "task.h"

//
//  Demo application includes
//
#include "main.h"
#include "adc/adc.h"
#include "cpu/cpu.h"
#include "dac/dac.h"
#include "eints/eint0.h"
#include "eints/eint2.h"
#include "gps/gps.h"
#include "fiq/fiq.h"
#include "i2c/i2c.h"
#include "leds/leds.h"
#include "monitor/monitor.h"
#include "pwm/pwm.h"
#include "rtc/rtc.h"
#include "sensors/sensors.h"
#include "spi/spi.h"
#include "timer/timer.h"
#include "uart/uart0.h"
#include "uart/uart1.h"
#include "usbser/usbser.h"
#include "usbmass/usbmass.h"

#ifdef CFG_UGFX
#include "gfx.h"
#endif

//
//
//
#define BAUD_UART0 115200
#define BAUD_UART1 115200

#if defined CFG_CONSOLE_USB && defined CFG_USB_MSC
#error "Cannot have USB console and MSC defined at the same time"
#endif

#if defined CFG_CONSOLE_UART1 && defined CFG_UIP
#error "Cannot use UART1 and UIP at same time because of RXD1/EINT3 conflict"
#endif

//
//
//
xTaskHandle taskHandles [TASKHANDLE_LAST];


#ifdef CFG_UGFX


void vSemaphoreDelete(void)
{

}

#if 1//def SKYVISION_JOC

static GFX_THREAD_FUNCTION(uGFXMain, p)
{
	int bytesFree, bytesUsed, blocksFree;
	portTickType xLastWakeTime;
	coord_t width, height;
	gFont		font1, font2;
	GHandle		ghList1;
	GWidgetInit	wi;
	int activeItem = 0;

	(void) p;

	vPortUsedMem(&bytesFree, &bytesUsed, &blocksFree);
	printf("F:%d U:%d, B:%d\n", bytesFree, bytesUsed, blocksFree);

	gfxInit();


#if 0
	gdispDrawBox(0, 0, width, height, GFX_WHITE);

	font1 = gdispOpenFont("UI2*");
	gdispDrawStringBox(5, 5, width,  20, "Hello World", font1, GFX_WHITE, gJustifyCenter);

	font2 = gdispOpenFont("fixed_5x8");
	gdispDrawStringBox(0, 5+20, width,  20, "Links ä", font2, GFX_WHITE, gJustifyLeft);
#endif

	vPortUsedMem(&bytesFree, &bytesUsed, &blocksFree);
	printf("F:%d U:%d, B:%d\n", bytesFree, bytesUsed, blocksFree);

#if 1
	gwinSetDefaultFont(gdispOpenFont("fixed_5x8"));
	gwinSetDefaultStyle(&BlackWidgetStyle, gFalse);
//	gdispClear(GFX_WHITE);

		// Apply some default values for GWIN
		gwinWidgetClearInit(&wi);
		wi.g.show = gTrue;

		wi.g.width = width/2;
		wi.g.height = height/2 + 20;
		wi.g.y = 10;
		wi.g.x = 10;
		wi.text = "Name of list 1";

		vPortUsedMem(&bytesFree, &bytesUsed, &blocksFree);
		printf("F:%d U:%d, B:%d\n", bytesFree, bytesUsed, blocksFree);

		ghList1 = gwinListCreate(0, &wi, gFalse);
#endif

		vPortUsedMem(&bytesFree, &bytesUsed, &blocksFree);
		printf("F:%d U:%d, B:%d\n", bytesFree, bytesUsed, blocksFree);

		gwinListAddItem(ghList1, "Item 0", gFalse);

		vPortUsedMem(&bytesFree, &bytesUsed, &blocksFree);
		printf("F:%d U:%d, B:%d\n", bytesFree, bytesUsed, blocksFree);

		gwinListAddItem(ghList1, "Item 1", gFalse);
		gwinListAddItem(ghList1, "Item 2", gFalse);
		gwinListAddItem(ghList1, "Item 3", gFalse);
		gwinListAddItem(ghList1, "Item 4", gFalse);
		gwinListAddItem(ghList1, "Item 5", gFalse);
		gwinListAddItem(ghList1, "Item 6", gFalse);
		gwinListAddItem(ghList1, "Item 7", gFalse);

		vPortUsedMem(&bytesFree, &bytesUsed, &blocksFree);
		printf("F:%d U:%d, B:%d\n", bytesFree, bytesUsed, blocksFree);

	for (xLastWakeTime = xTaskGetTickCount (); ; )
	{
		printf("activeItem: %d\n", activeItem);
		gwinListSetSelected(ghList1, activeItem, gTrue);

		activeItem++;
		if (activeItem > gwinListItemCount(ghList1)) activeItem = 0;

//		printf("uGFXMain: xLastWakeTime=%d\n", xLastWakeTime);
	    vTaskDelayUntil (&xLastWakeTime, 1000 / portTICK_RATE_MS);
	}
}

#else // !SKYVISION_JOC

static GFX_THREAD_FUNCTION(uGFXMain, p)
{
	portTickType xLastWakeTime;
	coord_t width, height;

	gfxInit();

	width = gdispGetWidth();
	height = gdispGetHeight();

	gdispDrawBox(0, 0, width, height, GFX_WHITE);

	printf("w: %d, h: %d\n", width, height);

	for (xLastWakeTime = xTaskGetTickCount (); ; )
	{
		printf("uGFXMain: xLastWakeTime=%d\n", xLastWakeTime);

	    vTaskDelayUntil (&xLastWakeTime, 1000 / portTICK_RATE_MS);
	}
}

#endif

#endif


//
//
//
int main (void)
{
  cpuSetupHardware ();

#ifdef CFG_LED
  ledsInit ();
#endif

  uart0Init (BAUD_UART0, 64);
  uart1Init (BAUD_UART1, 64);

#if 0

#ifdef CFG_CONSOLE_USB
  usbserInit ();
#endif
#ifdef CFG_USB_MSC
  usbmassInit ();
#endif
#ifdef CFG_RTC
  rtcInit ();
#endif
  timerInit ();
  adcInit ();
  dacInit ();

#endif

#ifdef CFG_PWM
  pwmInit ();
#endif

#ifdef CFG_I2C
  i2cInit ();
#endif

#ifdef CFG_SPI
  spiInit ();
#endif

#if 0

  eint0Init ();
  eint2Init ();
#ifdef CFG_FIQ
  fiqInit ();
#endif

#endif

  memset (taskHandles, 0, sizeof (taskHandles));

  monitorTaskStart ();
#ifdef CFG_LED
  ledsTaskStart ();
#endif
#ifdef CFG_SENSORS
  sensorsTaskStart ();
#endif
#ifdef CFG_GPS
  gpsTaskStart ();
#endif

#ifdef CFG_UGFX
  gfxThreadCreate(0, GFX_OS_UGFXMAIN_STACKSIZE, gThreadpriorityNormal, uGFXMain, 0);
#endif

  vTaskStartScheduler ();

  return 0;
}

