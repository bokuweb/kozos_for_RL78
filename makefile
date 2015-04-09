
PREFIX=rl78-elf

DEBUG_FLAGS=

# Specify compiler to be used
CC = $(PREFIX)-gcc

# Specify Assembler to be used
AS = $(PREFIX)-as

# Specify linker to be used
LD = $(PREFIX)-ld

# Specify CPU flag
CPU = 

# Common compiler flags
CFLAGS = -c -x c -nostdinc -g2 -g

ALL_FLAGS = $(CFLAGS) $(DEBUG_FLAGS) $(CPU)


# Application name
#APPNAME = 

# Specify all objects that you are going to link together
OBJS    =  startup.o serial.o vector.o main.o lib.o interrupt_handlers.o
SOURCES =  serial.c vector.c main.c lib.c interrupt_handlers.c 

kzload.hex : kzload.x
	$(PREFIX)-objcopy -O ihex kzload.x $@

# Define ROMSTART if compiling for ROM
kzload.x:$(SOURCES)  makefile
	$(CC) $(ALL_FLAGS) $(SOURCES)
	$(CC) -c -x c -Wa,-gdwarf2 -x assembler-with-cpp   -nostdinc  -g2 -g startup.asm
	$(LD) -o kzload.x  -T "ld.gsi"  *.o -M=kzload.map --start-group --end-group -e_start

all:kzload.hex
rom:kzload.hex

clean:
	rm -f *.o *.x *.mot *.map



