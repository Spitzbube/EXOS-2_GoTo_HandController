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

static GFX_THREAD_FUNCTION(uGFXMain, p)
{
	portTickType xLastWakeTime;
	coord_t width, height;
	gFont		font1;
	(void) p;

	gfxInit();

	width = gdispGetWidth();
	height = gdispGetHeight();

	gdispDrawBox(10, 10, width / 2, height / 2, GFX_WHITE);

	font1 = gdispOpenFont("UI2*");
	gdispDrawStringBox(5, 5, width,  20, "Hello World", font1, GFX_WHITE, gJustifyCenter);

	for (xLastWakeTime = xTaskGetTickCount (); ; )
	{
//		printf("uGFXMain: xLastWakeTime=%d\n", xLastWakeTime);
	    vTaskDelayUntil (&xLastWakeTime, 1000 / portTICK_RATE_MS);
	}
}

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

