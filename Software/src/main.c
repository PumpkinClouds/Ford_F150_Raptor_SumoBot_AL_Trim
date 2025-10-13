#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

/* Set STM32 to 64 MHz. */
static void clock_setup(void) {
    rcc_clock_setup_hsi(&rcc_hsi_configs[RCC_CLOCK_HSI_64MHZ]);
}

/**
 * Set the GPIO pins of the microcontroller
 */
static void gpio_setup(void) {
    // Enable clocks for GPIO Ports
    rcc_periph_clock_enable(RCC_GPIOE);

    /* Set GPIO12 (in GPIO port D) to 'output push-pull'. */
    gpio_mode_setup(
        GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO8 | GPIO9 | GPIO10 | GPIO11
    );
}

int main(void) {
    clock_setup();
    gpio_setup();

    while (1) {}

    return 0;
}
