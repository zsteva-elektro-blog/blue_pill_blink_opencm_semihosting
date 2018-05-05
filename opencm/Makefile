
CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
GDB = $(CROSS_COMPILE)gdb
OBJCOPY = $(CROSS_COMPILE)objcopy

CPUFLAGS = -mcpu=cortex-m3 -mthumb
CFLAGS = -Wall -Wextra -g3 -O0 -MD $(CPUFLAGS)
LDFLAGS = $(CPUFLAGS) -nostartfiles
LDLIBS = -lc

LDLIBS += -lnosys

# libopencm3
CFLAGS += -DSTM32F1 -I../libopencm3/include
LDFLAGS += -L../libopencm3/lib -Wl,-T,bluepill.ld
LDLIBS += -lopencm3_stm32f1

LDLIBS += -lc -lnosys

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

