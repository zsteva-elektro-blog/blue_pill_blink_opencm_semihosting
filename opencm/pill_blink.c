
#include <stdio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main(void) {
    rcc_periph_clock_enable(RCC_GPIOC);

	// init GPIO
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);
	
    while(1) {
		// set
        gpio_set(GPIOC, GPIO13);
        for (int i = 0; i < (1000000 >> 2); ++i) __asm__("nop");

		// clear
        gpio_clear(GPIOC, GPIO13);
        for (int i = 0; i <  500000; ++i) __asm__("nop");
    }
}
