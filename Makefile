NAME   = lpc2148

CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)gcc
AS      = $(CROSS_COMPILE)as
CP      = $(CROSS_COMPILE)objcopy
DUMP    = $(CROSS_COMPILE)objdump

CFLAGS  = -I./ -c -Os -g -mcpu=arm7tdmi -Wall
#CFLAGS += -nostdlib -ffreestanding -fno-common
CFLAGS += -DOLIMEX_LPC2148
CFLAGS += -DUART0_DEBUG
AFLAGS  = -ahls -mapcs-32 -mcpu=arm7tdmi
LFLAGS  = -Tlpc2148.ld -nostartfiles
CPFLAGS = -O binary
HEXFLAGS = -O ihex
DUMPFLAGS = -hds

all: test

clean:
	-rm crt0.lst crt0.o data.o main.o usbinit.o usbhw_lpc.o usbcontrol.o usbstdreq.o main.elf main.hex main.bin

test: main.elf
	@echo "...building hex"
	$(CP) $(HEXFLAGS) main.elf main.hex
	@echo "...building bin"
	$(CP) $(CPFLAGS) main.elf main.bin
	@echo "...dumping elf"
	$(DUMP) $(DUMPFLAGS) main.elf > main.dump

main.elf: crt0.o main.o data.o usbinit.o usbhw_lpc.o usbcontrol.o usbstdreq.o
	@ echo "..linking"
	$(LD) $(LFLAGS) -o main.elf crt0.o main.o usbinit.o usbhw_lpc.o usbcontrol.o usbstdreq.o data.o -lm winarm_lib/libc.a

crt0.o: crt0.s
	@ echo ".assembling"
	$(AS) $(AFLAGS) crt0.s -o crt0.o > crt0.lst

main.o: main.c
	@ echo ".compiling"
	$(CC) $(CFLAGS) main.c

data.o: data.c
	@ echo ".compiling"
	$(CC) $(CFLAGS) data.c
	
usbinit.o: LPCUSB/usbinit.c	
	$(CC) $(CFLAGS) LPCUSB/usbinit.c
		
usbhw_lpc.o: LPCUSB/usbhw_lpc.c	
	$(CC) $(CFLAGS) LPCUSB/usbhw_lpc.c
	
usbcontrol.o: LPCUSB/usbcontrol.c
	$(CC) $(CFLAGS) LPCUSB/usbcontrol.c
	
usbstdreq.o: LPCUSB/usbstdreq.c
	$(CC) $(CFLAGS) LPCUSB/usbstdreq.c

