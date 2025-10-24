#include "pwm.h"

void timer_init(
    TIM_HandleTypeDef *tim, TIM_TypeDef *timType, uint32_t *channels,
    uint16_t channels_len
) {
    tim->Instance           = timType;
    tim->Init.Prescaler     = 0;
    tim->Init.CounterMode   = TIM_COUNTERMODE_UP;
    tim->Init.Period        = 0;
    tim->Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    HAL_TIM_PWM_Init(tim);

    TIM_MasterConfigTypeDef sMasterConfig = {
        .MasterOutputTrigger = TIM_TRGO_RESET,
        .MasterSlaveMode     = TIM_MASTERSLAVEMODE_DISABLE
    };
    HAL_TIMEx_MasterConfigSynchronization(tim, &sMasterConfig);

    TIM_OC_InitTypeDef sConfigOC = {
        .OCMode     = TIM_OCMODE_PWM1,
        .Pulse      = 0,
        .OCPolarity = TIM_OCPOLARITY_HIGH,
        .OCFastMode = TIM_OCFAST_DISABLE
    };

    // TODO: have argument to process multiple channels per timer
    for (int idx = 0; idx < channels_len; idx++) {
        HAL_TIM_PWM_ConfigChannel(tim, &sConfigOC, channels[idx]);
    }
}

// TODO: Study this from
// https://github.com/mnemocron/STM32-Tutorial/blob/master/STM32%20Tutorial%2002%20-%20PWM%20Generation%20using%20HAL%20(and%20FreeRTOS).pdf

void set_pwm(
    TIM_HandleTypeDef timer, uint32_t channel, uint16_t period, uint16_t pulse
) {
    HAL_TIM_PWM_Stop(&timer, channel);
    timer.Init.Period = period;
    HAL_TIM_PWM_Init(&timer);

    TIM_OC_InitTypeDef sConfigOC = {
        .OCMode     = TIM_OCMODE_PWM1,
        .Pulse      = pulse,
        .OCPolarity = TIM_OCPOLARITY_HIGH,
        .OCFastMode = TIM_OCFAST_DISABLE,
    };

    HAL_TIM_PWM_ConfigChannel(&timer, &sConfigOC, channel);
    HAL_TIM_PWM_Start(&timer, channel);
}

