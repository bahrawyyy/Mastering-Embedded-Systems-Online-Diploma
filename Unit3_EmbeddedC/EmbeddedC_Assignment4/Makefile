CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
ASOBJ = $(AS:.s=.o)
Project-name = lab3_cortex_m4

all: $(Project-name).bin
	@echo "============ Build is done ============"

%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@
	
$(Project-name).elf: $(OBJ) 
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ)  -o $@ -Map=Map_file.map
	cp $(Project-name).elf $(Project-name).axf

$(Project-name).bin: $(Project-name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin 

clean: 
	rm *.elf *.bin