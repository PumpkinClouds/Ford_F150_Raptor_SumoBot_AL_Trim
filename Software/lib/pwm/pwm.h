#ifndef PWM_H_
#define PWM_H_
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_tim.h"
#include "stm32f3xx_hal_tim_ex.h"

void timer_init(
    TIM_HandleTypeDef *tim, TIM_TypeDef *timType, uint32_t *channels,
    uint16_t channels_len
);

/**
 *
 */
void set_pwm(
    TIM_HandleTypeDef timer, uint32_t channel, uint16_t period, uint16_t pulse
);
#endif
