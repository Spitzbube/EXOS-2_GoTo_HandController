
#include "LPCUSB/usbapi.h"

#define INT_IN_EP    0x81
#define BULK_OUT_EP     0x05
#define BULK_IN_EP      0x82
#define MAX_PACKET_SIZE 64
#define LE_WORD(x)      ((x)&0xFF),((x)>>8)
#define CS_INTERFACE       0x24

#define  SET_LINE_CODING         0x20
#define  GET_LINE_CODING         0x21
#define  SET_CONTROL_LINE_STATE  0x22

static U8 abClassReqData[8];

// data structure for GET_LINE_CODING / SET_LINE_CODING class requests
typedef struct {
   U32      dwDTERate;
   U8    bCharFormat;
   U8    bParityType;
   U8    bDataBits;
} TLineCoding;

static TLineCoding LineCoding = {115200, 0, 0, 8};

static U8 abBulkBuf[64];

static const unsigned char abDescriptors[] = {

// device descriptor
   0x12,
   DESC_DEVICE,
   LE_WORD(0x0101),        // bcdUSB
   0x02,                // bDeviceClass
   0x00,                // bDeviceSubClass
   0x00,                // bDeviceProtocol
   MAX_PACKET_SIZE0,       // bMaxPacketSize
   LE_WORD(0xFFFF),        // idVendor
   LE_WORD(0x0005),        // idProduct
   LE_WORD(0x0100),        // bcdDevice
   0x01,                // iManufacturer
   0x02,                // iProduct
   0x03,                // iSerialNumber
   0x01,                // bNumConfigurations

// configuration descriptor
   0x09,
   DESC_CONFIGURATION,
   LE_WORD(67),            // wTotalLength
   0x02,                // bNumInterfaces
   0x01,                // bConfigurationValue
   0x00,                // iConfiguration
   0xC0,                // bmAttributes
   0x32,                // bMaxPower
// control class interface
   0x09,
   DESC_INTERFACE,
   0x00,                // bInterfaceNumber
   0x00,                // bAlternateSetting
   0x01,                // bNumEndPoints
   0x02,                // bInterfaceClass
   0x02,                // bInterfaceSubClass
   0x01,                // bInterfaceProtocol, linux requires value of 1 for the cdc_acm module
   0x00,                // iInterface
// header functional descriptor
   0x05,
   CS_INTERFACE,
   0x00,
   LE_WORD(0x0110),
// call management functional descriptor
   0x05,
   CS_INTERFACE,
   0x01,
   0x01,                // bmCapabilities = device handles call management
   0x01,                // bDataInterface
// ACM functional descriptor
   0x04,
   CS_INTERFACE,
   0x02,
   0x02,                // bmCapabilities
// union functional descriptor
   0x05,
   CS_INTERFACE,
   0x06,
   0x00,                // bMasterInterface
   0x01,                // bSlaveInterface0
// notification EP
   0x07,
   DESC_ENDPOINT,
   INT_IN_EP,              // bEndpointAddress
   0x03,                // bmAttributes = intr
   LE_WORD(8),             // wMaxPacketSize
   0x0A,                // bInterval
// data class interface descriptor
   0x09,
   DESC_INTERFACE,
   0x01,                // bInterfaceNumber
   0x00,                // bAlternateSetting
   0x02,                // bNumEndPoints
   0x0A,                // bInterfaceClass = data
   0x00,                // bInterfaceSubClass
   0x00,                // bInterfaceProtocol
   0x00,                // iInterface
// data EP OUT
   0x07,
   DESC_ENDPOINT,
   BULK_OUT_EP,            // bEndpointAddress
   0x02,                // bmAttributes = bulk
   LE_WORD(MAX_PACKET_SIZE),  // wMaxPacketSize
   0x00,                // bInterval
// data EP in
   0x07,
   DESC_ENDPOINT,
   BULK_IN_EP,             // bEndpointAddress
   0x02,                // bmAttributes = bulk
   LE_WORD(MAX_PACKET_SIZE),  // wMaxPacketSize
   0x00,                // bInterval

   // string descriptors
   0x04,
   DESC_STRING,
   LE_WORD(0x0409),

   0x0E,
   DESC_STRING,
   'L', 0, 'P', 0, 'C', 0, 'U', 0, 'S', 0, 'B', 0,

   0x14,
   DESC_STRING,
   'U', 0, 'S', 0, 'B', 0, 'S', 0, 'e', 0, 'r', 0, 'i', 0, 'a', 0, 'l', 0,

   0x12,
   DESC_STRING,
   'D', 0, 'E', 0, 'A', 0, 'D', 0, 'C', 0, '0', 0, 'D', 0, 'E', 0,

// terminating zero
   0
};


#ifdef __GNUC__
void usb_isr(void) __attribute__ ((interrupt ("IRQ")));
void usb_isr(void)
#else
void usb_isr(void) __irq
#endif
{
   USBHwISR();
   VICVectAddr = 0;
}

static BOOL HandleClassRequest(TSetupPacket *pSetup, int *piLen, U8 **ppbData)
{
   switch (pSetup->bRequest) {

   // set line coding
   case SET_LINE_CODING:
      memcpy((U8 *)&LineCoding, *ppbData, 7);
      *piLen = 7;
      break;

   // get line coding
   case GET_LINE_CODING:
      *ppbData = (U8 *)&LineCoding;
      *piLen = 7;
      break;

   // set control line state
   case SET_CONTROL_LINE_STATE:
      // bit0 = DTR, bit = RTS
      break;

   default:
      return FALSE;
   }
   return TRUE;
}

static void BulkIn(U8 bEP, U8 bEPStatus)
{
#if 0
   int i, iLen;

   if (fifo_avail(&txfifo) == 0) {
      // no more data, disable further NAK interrupts until next USB frame
      USBHwNakIntEnable(0);
      return;
   }

   // get bytes from transmit FIFO into intermediate buffer
   for (i = 0; i < MAX_PACKET_SIZE; i++) {
      if (!fifo_get(&txfifo, &abBulkBuf[i])) {
         break;
      }
   }
   iLen = i;

   // send over USB
   if (iLen > 0) {
      USBHwEPWrite(bEP, abBulkBuf, iLen);
   }
#else
   USBHwNakIntEnable(0);
#endif
}

static void USBFrameHandler(U16 wFrame)
{
#if 0
   if (fifo_avail(&txfifo) > 0) {
      // data available, enable NAK interrupt on bulk in
      USBHwNakIntEnable(INACK_BI);
   }
#endif
}

static void BulkOut(U8 bEP, U8 bEPStatus)
{
#if 0
   int i, iLen;

   if (fifo_free(&rxfifo) < MAX_PACKET_SIZE) {
      // may not fit into fifo
      return;
   }

   // get data from USB into intermediate buffer
   iLen = USBHwEPRead(bEP, abBulkBuf, sizeof(abBulkBuf));
   for (i = 0; i < iLen; i++) {
      // put into FIFO
      if (!fifo_put(&rxfifo, abBulkBuf[i])) {
         // overflow... :(
         ASSERT(FALSE);
         break;
      }
   }
#else
   USBHwEPRead(bEP, abBulkBuf, sizeof(abBulkBuf));
#endif
}

void usb_init(void)
{
   USBInit();

   USBRegisterDescriptors(abDescriptors);
   USBRegisterRequestHandler(REQTYPE_TYPE_CLASS, HandleClassRequest, abClassReqData);
   USBHwRegisterEPIntHandler(INT_IN_EP, NULL);
   USBHwRegisterEPIntHandler(BULK_IN_EP, BulkIn);
   USBHwRegisterEPIntHandler(BULK_OUT_EP, BulkOut);
   USBHwRegisterFrameHandler(USBFrameHandler);

   USBHwNakIntEnable(INACK_BI);

#if 1
   VICVectCntl4 = (1 << 5) | 22; // USB -> Slot 4
   VICVectAddr4 = (unsigned int) usb_isr;
   VICIntEnable = (1 << 22); // Enable USB
#else
   VICVectCntl0 = (1 << 5) | 22; // USB -> Slot 0
   VICVectAddr0 = (unsigned int) usb_isr;
   VICIntEnable = (1 << 22); // Enable USB
#endif

   USBHwConnect(1);
}


