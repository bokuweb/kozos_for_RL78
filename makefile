
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
OBJS	=	  reset_program.o hardware_setup.o interrupt_handlers.o main.o  vector_table.o
SOURCES =	  hardware_setup.c interrupt_handlers.c main.c  vector_table.c

kzload.mot : kzload.x
	$(PREFIX)-objcopy -O srec kzload.x $@

# Define ROMSTART if compiling for ROM
kzload.x:$(SOURCES)  makefile
	$(CC) $(ALL_FLAGS) $(SOURCES)
	$(CC) -c -x c -Wa,-gdwarf2 -x assembler-with-cpp   -nostdinc  -g2 -g reset_program.asm
	$(LD) -o kzload.x  -T "ld.gsi"  *.o -M=kzload.map --start-group --end-group -e_PowerON_Reset
all:kzload.mot
rom:kzload.mot

clean:
	rm -f *.o *.x *.mot *.map



