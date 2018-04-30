
CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
GDB = $(CROSS_COMPILE)gdb
OBJCOPY = $(CROSS_COMPILE)objcopy

CPUFLAGS = -mcpu=cortex-m3 -mthumb
CFLAGS = -Wall -Wextra -g3 -O0 -MD $(CPUFLAGS)
LDFLAGS = $(CPUFLAGS) -nostartfiles -Wl,-T,bluepill.ld
LDLIBS = -lc -lnosys

PROGNAME = pill_blink
CSRC = pill_blink.c
OBJ = $(CSRC:.c=.o)

all: $(PROGNAME).bin

$(PROGNAME).elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)

$(PROGNAME).bin: $(PROGNAME).elf
	$(OBJCOPY) -O binary $< $@

openocd:
	openocd -f openocd.cfg

gdb: $(PROGNAME).elf
	$(GDB) -ix gdbinit $(PROGNAME).elf

.PHONY: clean
clean:
	-rm -rf *.o *.bin *.elf *.map *.d

