#Kumar Sumeet - Makefile for USB kit atmega16 and equivalent.
.SUFFIXES: .hex .out
CC=avr-gcc
OBJCOPY=avr-objcopy

CFLAGS=-g -mmcu=atmega32 -Os

.out.hex:
	$(OBJCOPY) -j .text -O ihex $< rom.hex 
.o.out:
	$(CC) $(CFLAGS) -o $@ -Wl,-Map,rom.map $<
.c.o:
	$(CC) $(CFLAGS) -Os -c $<
all:$@



flash:rom.hex
	avrdude -p usbasp -P /dev/ttyUSB0 -c usb -U flash:w:rom.hex

