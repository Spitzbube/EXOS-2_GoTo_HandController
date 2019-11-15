NAME   = lpc2148

CC      = $(CROSS_COMPILE)gcc
LD      = $(CROSS_COMPILE)gcc
AS      = $(CROSS_COMPILE)as
CP      = $(CROSS_COMPILE)objcopy

CFLAGS  = -I./ -c -O0 -g -mcpu=arm7tdmi -Wall
CFLAGS += -nostdlib -ffreestanding -fno-common
CFLAGS += -DOLIMEX_LPC2148
AFLAGS  = -ahls -mapcs-32 -mcpu=arm7tdmi
LFLAGS  = -Tlpc2148.ld -nostartfiles
CPFLAGS = -O binary
HEXFLAGS = -O ihex

all: test

clean:
	-rm crt0.lst crt0.o file_1f30.o file_5099c.o data.o syscalls.o main.o main.out main.hex

test: main.out
	@echo "...building hex"
	$(CP) $(HEXFLAGS) main.out main.hex

main.out: crt0.o file_1f30.o file_5099c.o main.o data.o syscalls.o
	@ echo "..linking"
	$(LD) $(LFLAGS) -o main.out crt0.o file_1f30.o file_5099c.o main.o data.o syscalls.o

crt0.o: crt0.s
	@ echo ".assembling"
	$(AS) $(AFLAGS) crt0.s -o crt0.o > crt0.lst

main.o: main.c
	@ echo ".compiling"
	$(CC) $(CFLAGS) main.c

syscalls.o: syscalls.c
	@ echo ".compiling"
	$(CC) $(CFLAGS) syscalls.c
	
data.o: data.c
	@ echo ".compiling"
	$(CC) $(CFLAGS) data.c
		
file_1f30.o: file_1f30.c		
	@ echo ".compiling"
	$(CC) $(CFLAGS) file_1f30.c
		
file_5099c.o: file_5099c.c		
	@ echo ".compiling"
	$(CC) $(CFLAGS) file_5099c.c
		
		