//
//  $Id: lcd_8bit.c 328 2008-11-09 05:00:23Z jcw $
//  $Revision: 328 $
//  $Author: jcw $
//  $Date: 2008-11-09 00:00:23 -0500 (Sun, 09 Nov 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/lcd/lcd_8bit.c $
//

#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "../main.h"
#include "../spi/spi.h"
#include "lcd.h"

//
//  This is where the various LCD control pins are assigned.  Currently they're
//  all assigned on port 0 except for LCD_RS.
//
#define LCD_DATA      GPIO_IO_P15
#define LCD_CLK       GPIO_IO_P12
#define LCD_E         GPIO_IO_P10
#define LCD_RS        GPIO_IO_P23
#define FONTROM_E     GPIO_IO_P25

#define ST7565_CMD_DISPLAY_ON             0xAF
#define ST7565_CMD_SET_PAGE               0xB0
#define ST7565_CMD_SET_COLUMN_UPPER       0x10
#define ST7565_CMD_SET_COLUMN_LOWER       0x00
#define ST7565_CMD_SET_BIAS_9             0xA2
#define ST7565_CMD_INTERNAL_RESET         0xE2
#define ST7565_CMD_SET_VOLUME_FIRST       0x81
#define ST7565_CMD_SET_DISP_NORMAL        0xA6
#define ST7565_CMD_SET_ALLPTS_NORMAL      0xA4
#define ST7565_CMD_SET_COM_REVERSE        0xC8

#if 0
//
//
//
#define LCD_PWM_FREQ 20000

//
//  If CFG_LCD is not defined, we still compile the code, it's just not included.
//  Define TASKHANDLE_LCD so we compile.  Normally this is defined in main.h,
//  but it's #ifndef'ed out so that we don't allocate a task handle slot for it
//  when LCD support isn't included.
//
#ifndef CFG_LCD
#define TASKHANDLE_LCD 0
#endif

#endif

//
//  Structure for passing messages to the LCD
//
typedef struct
{
  const char *pcMessage;
} 
xLCDMessage_t;

//
//
//
static xQueueHandle xLCDQueue;

static inline void lcdSelectCommandRegister (void)
{
  GPIO1_FIOCLR |= LCD_RS;
}

static inline void lcdSelectDataRegister (void)
{
  GPIO1_FIOSET |= LCD_RS;
}

static inline void lcdEnableHigh (void)
{
  GPIO0_FIOSET |= LCD_E;
}

static inline void lcdEnableLow (void)
{
  GPIO0_FIOCLR |= LCD_E;
}

static inline void lcdClockHigh (void)
{
  GPIO0_FIOSET |= LCD_CLK;
}

static inline void lcdClockLow (void)
{
  GPIO0_FIOCLR |= LCD_CLK;
}

static inline void lcdDataHigh (void)
{
  GPIO0_FIOSET |= LCD_DATA;
}

static inline void lcdDataLow (void)
{
  GPIO0_FIOCLR |= LCD_DATA;
}

static inline void fontRomEnableLow (void)
{
  GPIO1_FIOCLR |= FONTROM_E;
}

static inline void fontRomEnableHigh (void)
{
  GPIO1_FIOSET |= FONTROM_E;
}

//
//
//
static void lcdWriteData (unsigned char c)
{
  unsigned char i;

  lcdEnableLow ();
  lcdSelectDataRegister ();

  for (i = 0; i < 8; i++)
  {
    lcdClockLow ();

    if (c & 0x80)
      lcdDataHigh ();
    else
      lcdDataLow ();

    c <<= 1;
    lcdClockHigh ();
  }

  lcdEnableHigh ();
}

static void lcdWriteCommand (unsigned char c)
{
  unsigned char i;

  lcdEnableLow ();
  lcdSelectCommandRegister ();

  for (i = 0; i < 8; i++)
  {
    lcdClockLow ();

    if (c & 0x80)
      lcdDataHigh ();
    else
      lcdDataLow ();

    c <<= 1;
    lcdClockHigh ();
  }

  lcdEnableHigh ();
}

#if 0
//
//
//
static void lcdDisplay (unsigned char display)
{
  lcdWaitWhileBusy ();
  lcdWriteCommand (LCD_COMMAND_DISPLAY | (display & LCD_DISPLAY_MASK));
}

static void lcdMode (unsigned char mode)
{
  lcdWaitWhileBusy ();
  lcdWriteCommand (LCD_COMMAND_MODE | (mode & LCD_MODE_MASK));
}

#endif

static void lcdClear (void)
{
  int i, j;
  for (i = 0; i < 8; i++)
  {
    lcdWriteCommand((i & 0xff) | ST7565_CMD_SET_PAGE);
    lcdWriteCommand(ST7565_CMD_SET_COLUMN_LOWER);
    lcdWriteCommand(ST7565_CMD_SET_COLUMN_UPPER);

    for (j = 133; j > 0; j--)
    	lcdWriteData(0);
  }
}

#if 0

static void lcdHome (void)
{
  lcdWaitWhileBusy ();
  lcdWriteCommand (LCD_COMMAND_HOME);
}

#endif

static void lcdGotoXY (unsigned int x, unsigned int y)
{
  lcdWriteCommand((((x * 6 + 1) & 0x0f) >> 0) | ST7565_CMD_SET_COLUMN_LOWER);
  lcdWriteCommand((((x * 6 + 1) & 0xf0) >> 4) | ST7565_CMD_SET_COLUMN_UPPER);
  lcdWriteCommand((y & 0x0f) | ST7565_CMD_SET_PAGE);
}

static void lcdPutChar (char c)
{
  unsigned char i, j;
  unsigned char bitmap[6];
  unsigned int sp = 0;

  if ((c >= 0x20) && (c <= 0x7e))
    sp = 0x188bd8 + ((c - 0x20) << 3);

  fontRomEnableLow ();

  spiPut(0x0b);
  spiPut((sp >> 16) & 0xFF);
  spiPut((sp >> 8) & 0xFF);
  spiPut((sp >> 0) & 0xFF);

  for (i = 0; i < 8; i++)
  {
    unsigned char pixels = spiPut(0);

    for (j = 0; j < 6; j++)
    {
      if (pixels & (0x80 >> j))
        bitmap[j] |= (1 << i);
      else
        bitmap[j] &= ~(1 << i);
    }
  }

  fontRomEnableHigh ();

  for (i = 0; i < 6; i++)
    lcdWriteData(bitmap[i]);
}

static void lcdWriteStringCtl (const char *s)
{
  static unsigned char x = 0;
  static unsigned char y = 0;

  while (*s)
  {
    char c = *s++;

    switch (c)
    {
      case '\f' :
        lcdClear ();
        break;

      case 0x1e :
//        lcdHome ();
        break;

      case 0x1b :
        {
          switch (*s++)
          {
            case '=' :
              {
                x = *s++;
                y = *s++;

                lcdGotoXY (x, y);
              }
              break;

            case '*' :
              lcdClear ();
              break;

#if 0
            case '.' :
              {
                switch (*s++)
                {
                  case '0' : 
                    lcdDisplay (LCD_DISPLAY_DISPLAY_ON | LCD_DISPLAY_CURSOR_OFF | LCD_DISPLAY_BLINK_OFF);
                    break;

                  case '1' : 
                    lcdDisplay (LCD_DISPLAY_DISPLAY_ON | LCD_DISPLAY_CURSOR_ON | LCD_DISPLAY_BLINK_ON);
                    break;

                  case '2' : 
                    lcdDisplay (LCD_DISPLAY_DISPLAY_ON | LCD_DISPLAY_CURSOR_ON | LCD_DISPLAY_BLINK_OFF);
                    break;
                }
              }
#endif
          }
        }
        break;

      default : 
        lcdGotoXY (x, y);
        lcdPutChar (c);
        x++;
        break;
    }
  }
}

static void lcdBrightness(unsigned char a)
{
	a = a / 2 + 80;
	lcdWriteCommand(ST7565_CMD_SET_VOLUME_FIRST);
	lcdWriteCommand(a);
}

//
//
//
static void lcdControllerInit (void)
{
  lcdWriteCommand (ST7565_CMD_INTERNAL_RESET);
  lcdWriteCommand (ST7565_CMD_SET_BIAS_9);
  lcdWriteCommand (0x26);
  lcdWriteCommand (0x2f);
  lcdWriteCommand (ST7565_CMD_SET_VOLUME_FIRST);
  lcdWriteCommand (0x80);
  lcdWriteCommand (ST7565_CMD_SET_DISP_NORMAL);
  lcdWriteCommand (ST7565_CMD_SET_ALLPTS_NORMAL);
  lcdWriteCommand (ST7565_CMD_SET_COM_REVERSE);
  lcdWriteCommand (ST7565_CMD_DISPLAY_ON);
  lcdWriteCommand (0x60);

  lcdClear ();
  lcdBrightness(0x80);
}

void lcdWriteChar (char c)
{
  static char buffer [2];

  buffer [0] = c;
  buffer [1] = '\0';

  lcdWriteText (buffer);
}

void lcdWriteText (const char *s)
{
  xLCDMessage_t xLCDMessage;
  
  xLCDMessage.pcMessage = s;

  xQueueSend (xLCDQueue, &xLCDMessage, portMAX_DELAY);
}

#if 0

void lcdCursorXY (int x, int y)
{
  static char buffer [5];

  buffer [0] = '\033';
  buffer [1] = '=';
  buffer [2] = x;
  buffer [3] = y;
  buffer [4] = '\0';

  lcdWriteText (buffer);
}

#endif

//
//
//
void lcdInit (void)
{
  GPIO0_FIODIR |= (LCD_E | LCD_CLK | LCD_DATA);
  GPIO1_FIODIR |= (LCD_RS | FONTROM_E);
  GPIO1_FIOSET  = FONTROM_E;

  //
  //  Queue used to send LCD task messages, only 1 outstanding message
  //  (so static buffers, such as those used in lcdCursorAt() don't
  //  get lost)
  //
  if (!xLCDQueue)
    xLCDQueue = xQueueCreate (1, sizeof (xLCDMessage_t));
}

//
//
//
static portTASK_FUNCTION (vLCDTask, pvParameters __attribute__ ((unused)))
{
  lcdInit ();
  lcdControllerInit ();

  for (;;)
  {
    xLCDMessage_t xMessage;
      
    xQueueReceive (xLCDQueue, &xMessage, portMAX_DELAY);

    lcdWriteStringCtl (xMessage.pcMessage);
  }
}

//
//
//
signed portBASE_TYPE lcdTaskStart (void)
{
  return xTaskCreate (vLCDTask, (const signed portCHAR * const) "LCD", configMINIMAL_STACK_SIZE, NULL, (tskIDLE_PRIORITY + 1), &taskHandles [TASKHANDLE_LCD]);
}

signed portBASE_TYPE lcdTaskStop (void)
{
  if (!taskHandles [TASKHANDLE_LCD])
    return 0;

  vTaskDelete (taskHandles [TASKHANDLE_LCD]);
  taskHandles [TASKHANDLE_LCD] = NULL;
  return 1;
}
