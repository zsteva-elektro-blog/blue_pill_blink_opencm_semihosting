
#include <stdio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

extern void initialise_monitor_handles(void);

int main(void) {
    rcc_periph_clock_enable(RCC_GPIOC);

	// init GPIO
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

	initialise_monitor_handles();

	printf("hello world!\n");
	
    while(1) {
		// set
		printf("set\n");
        gpio_set(GPIOC, GPIO13);
        for (int i = 0; i < (1000000 >> 2); ++i) __asm__("nop");

		// clear
		printf("clear\n");
        gpio_clear(GPIOC, GPIO13);
        for (int i = 0; i <  500000; ++i) __asm__("nop");
    }
}
