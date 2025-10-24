#include "stm32f303xc.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_gpio.h"
#include "stm32f3xx_hal_rcc.h"

#include <pwm.h>
#include <stdint.h>

void gpio_setup() {
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    HAL_GPIO_Init(
        GPIOA, &(GPIO_InitTypeDef) {.Pin  = GPIO_PIN_3 | GPIO_PIN_15,
                                    .Mode = GPIO_MODE_INPUT,
                                    .Pull = GPIO_NOPULL}
    );
    HAL_GPIO_Init(
        GPIOB, &(GPIO_InitTypeDef) {.Pin  = GPIO_PIN_1 | GPIO_PIN_8,
                                    .Mode = GPIO_MODE_INPUT,
                                    .Pull = GPIO_NOPULL}
    );
    HAL_GPIO_Init(
        GPIOB,
        &(GPIO_InitTypeDef) {.Pin  = GPIO_PIN_10 | GPIO_PIN_12 | GPIO_PIN_13,
                             .Mode = GPIO_MODE_ANALOG,
                             .Pull = GPIO_NOPULL}
    );
}

int main() {
    /* PWM Section */
    TIM_HandleTypeDef tim1, tim2, tim3, tim4, tim15;

    HAL_Init();
    gpio_setup();
    timer_init(&tim1, TIM1, (uint32_t[]) {1}, 1);
    timer_init(&tim2, TIM2, (uint32_t[]) {1, 2}, 2);
    timer_init(&tim3, TIM3, (uint32_t[]) {1, 2}, 2);
    timer_init(&tim4, TIM4, (uint32_t[]) {1, 2}, 2);
    timer_init(&tim15, TIM15, (uint32_t[]) {1, 2}, 2);
    return 0;
}
