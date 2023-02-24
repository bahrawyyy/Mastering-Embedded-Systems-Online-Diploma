#@copyright : Abdalla Elbahrawy

CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project-name = learn-in-depth

all: $(Project-name).bin
	@echo "============ Build is done ============"

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(Project-name).elf: $(OBJ) startup.o
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) startup.o -o $@ 

$(Project-name).bin: $(Project-name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin 

clean: 
	rm *.elf *.bin