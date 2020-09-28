//
//  $Id: kbd.c 328 2008-11-09 05:00:23Z jcw $
//  $Revision: 328 $
//  $Author: jcw $
//  $Date: 2008-11-09 00:00:23 -0500 (Sun, 09 Nov 2008) $
//  $HeadURL: http://tinymicros.com/svn_public/arm/lpc2148_demo/trunk/kbd/kbd.c $
//

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "../main.h"
#include "kbd.h"

//Rows on P0
#define KBD_ROW1        GPIO_IO_P22 // Row 1 (input)
#define KBD_ROW2        GPIO_IO_P25 // Row 2 (input)
#define KBD_ROW3        GPIO_IO_P28 // Row 3 (input)
#define KBD_ROW4        GPIO_IO_P29 // Row 4 (input)
#define KBD_ROW5        GPIO_IO_P30 // Row 5 (input)
#define NUM_ROWS        5
//Columns on P1
#define KBD_COL1        GPIO_IO_P19 // Column 1 (output)
#define KBD_COL2        GPIO_IO_P18 // Column 2 (output)
#define KBD_COL3        GPIO_IO_P17 // Column 3 (output)
#define KBD_COL4        GPIO_IO_P16 // Column 4 (output)
#define NUM_COLS        4

#define KBD_ROW_MASK  (KBD_ROW1 | KBD_ROW2 | KBD_ROW3 | KBD_ROW4 | KBD_ROW5)

//
//  If CFG_KBD is not defined, we still compile the code, it's just not included.
//  Define TASKHANDLE_KBD so we compile.  Normally this is defined in main.h,
//  but it's #ifndef'ed out so that we don't allocate a task handle slot for it
//  when keyboard support isn't included.
//
#ifndef CFG_KBD
#define TASKHANDLE_KBD 0
#endif

#undef KBD_DEBUG

//
//  Structure for passing messages back from the keyboard
//
typedef struct
{
  char key;
} 
xKeyMessage_t;

//
//  The queue for keys
//
static xQueueHandle xKeyQueue;

//
//
//
#define delay166ns() do { asm volatile ("stmdb	sp!, {r0}\r\nldmia	sp!, {r0}\r\n"); } while (0)

//
//
//
static inline void kbdDelay1us (void)
{
  delay166ns ();
  delay166ns ();
  delay166ns ();
  delay166ns ();
  delay166ns ();
  delay166ns ();
}

static void kbdDelay10us (void)
{
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
  kbdDelay1us ();
}

static void kbdDelay100us (void)
{
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
  kbdDelay10us ();
}

static void kbdDelay (void)
{
  kbdDelay100us ();
}

static inline int kbdReadRow (void)
{
  int i = 0;

  if ((GPIO0_FIOPIN & KBD_ROW1) == 0)
    i |= 1;
  if ((GPIO0_FIOPIN & KBD_ROW2) == 0)
    i |= 2;
  if ((GPIO0_FIOPIN & KBD_ROW3) == 0)
    i |= 4;
  if ((GPIO0_FIOPIN & KBD_ROW4) == 0)
    i |= 8;
  if ((GPIO0_FIOPIN & KBD_ROW5) == 0)
    i |= 16;

  return i;
}

//
//  Contains short-circuit logic so if no key is pressed (99.9999% of the time)
//  then we return immediately.  Makes the (rash) assumption that there was at
//  least a 100us delay since the previous call, to allow the lines to settle.
//
//  The column drivers are normally low, so if any key is pressed, we'll detect
//  it immediately.  If this is the case, then we bring the column drivers
//  high, and start walking a 0 across them, checking each column for a press.
//  We then return a 16 bit map that has a 1 for each key that is pressed.
//
static int kbdGetKeys (void)
{
  unsigned int keys = 0;
  unsigned int col;
  for (col = 0; col < NUM_COLS; col++)
  {
    GPIO1_FIOSET |= (KBD_COL1 | KBD_COL2 | KBD_COL3 | KBD_COL4);
    GPIO1_FIOCLR = KBD_COL1 >> col;

    kbdDelay();

    if ((GPIO0_FIOPIN & KBD_ROW_MASK) ^ KBD_ROW_MASK)
    {
      unsigned int row = kbdReadRow();
#ifdef KBD_DEBUG
      if (row)
        printf("Key: col=%d, row=%d\n", col, row);
#endif
      keys |= row << (col * NUM_ROWS);
    }
  }

  return keys;
}

//
//
//
int kbdGetKey (void)
{
  xKeyMessage_t xKeyMessage;

  if (!uxQueueMessagesWaiting (xKeyQueue))
    return 0;

  xQueueReceive (xKeyQueue, &xKeyMessage, portMAX_DELAY);

  return xKeyMessage.key;
}

int kbdGetKeyBlock (void)
{
  xKeyMessage_t xKeyMessage;

  xQueueReceive (xKeyQueue, &xKeyMessage, portMAX_DELAY);

  return xKeyMessage.key;
}

int kbdGetKeyTimed (int ms)
{
  xKeyMessage_t xKeyMessage;

  if (xQueueReceive (xKeyQueue, &xKeyMessage, ms / portTICK_RATE_MS) == pdTRUE)
    return xKeyMessage.key;

  return 0;
}

//
//
//
void kbdInit (void)
{
  GPIO0_FIODIR &= ~(KBD_ROW5 | KBD_ROW4 | KBD_ROW3 | KBD_ROW2 | KBD_ROW1); // Inputs
  GPIO1_FIODIR |=  (KBD_COL4 | KBD_COL3 | KBD_COL2 | KBD_COL1); // Outputs
  GPIO1_FIOSET |=  (KBD_COL4 | KBD_COL3 | KBD_COL2 | KBD_COL1); // Set outputs high

  if (!xKeyQueue)
    xKeyQueue = xQueueCreate (16, sizeof (xKeyMessage_t));
}

//
//  Scan keypad every 10ms
//
static portTASK_FUNCTION (vKbdTask, pvParameters __attribute__ ((unused)))
{
  portTickType xLastWakeTime;
  unsigned char switchStateIndex = 0;
  unsigned int switchState [5];
  unsigned int lastState = 0;
  const unsigned char keyConvert [NUM_ROWS * NUM_COLS] =
  {
    '<', '1', '4', '7', 'h', '_', '2', '5', '8', '0', '>', '3', '6', '9', 'F', '^', '@', '+', '*', '-'
  };

  kbdInit ();

  xLastWakeTime = xTaskGetTickCount ();

  for (;;)
  {
    unsigned int i;
    unsigned int j;

    switchState [switchStateIndex++] = kbdGetKeys ();

    if (switchStateIndex >= arrsizeof (switchState))
      switchStateIndex = 0;

    for (j = -1, i = 0; i < arrsizeof (switchState); i++)
      j &= switchState [i];

    if ((lastState != j) && (lastState = j))
    {
      if (!(lastState & (lastState - 1)))
      {
#ifdef KBD_DEBUG
        printf("lastState = 0x%x\n", lastState);
#endif
        for (i = 0; i < (NUM_ROWS * NUM_COLS); i++)
        {
          if (lastState & (1 << i))
          {
            xKeyMessage_t xKeyMessage;
            xKeyMessage.key = keyConvert [i];
            xQueueSend (xKeyQueue, &xKeyMessage, 0);
          }
        }
      }
    }
  
    vTaskDelayUntil (&xLastWakeTime, 20 / portTICK_RATE_MS);
  }
}

signed portBASE_TYPE kbdTaskStart (void)
{
#ifdef KBD_DEBUG
  int stack = 1024;
#else
  int stack = configMINIMAL_STACK_SIZE;
#endif
  return xTaskCreate (vKbdTask, (const signed portCHAR * const) "KBD", stack, NULL, (tskIDLE_PRIORITY + 1), &taskHandles [TASKHANDLE_KBD]);
}

signed portBASE_TYPE kbdTaskStop (void)
{
  if (!taskHandles [TASKHANDLE_KBD])
    return 0;

  vTaskDelete (taskHandles [TASKHANDLE_KBD]);
  taskHandles [TASKHANDLE_KBD] = NULL;
  return 1;
}
