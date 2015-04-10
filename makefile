
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
OBJS	=	  startup.o interrupt_handlers.o main.o  vector.o serial.o lib.o
SOURCES =	  interrupt_handlers.c main.c  vector.c serial.c lib.c

kzload.mot : kzload.x
	$(PREFIX)-objcopy -O srec kzload.x $@

# Define ROMSTART if compiling for ROM
kzload.x:$(SOURCES)  makefile
	$(CC) $(ALL_FLAGS) $(SOURCES)
	$(CC) -c -x c -Wa,-gdwarf2 -x assembler-with-cpp   -nostdinc  -g2 -g startup.asm
	$(LD) -o kzload.x  -T "ld.gsi"  *.o -M=kzload.map --start-group --end-group -e_start
all:kzload.mot
rom:kzload.mot

clean:
	rm -f *.o *.x *.mot *.map



