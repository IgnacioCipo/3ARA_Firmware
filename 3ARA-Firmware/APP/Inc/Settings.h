#ifndef SETTINGS_H
#define SETTINGS_H

#include "main.h"
#include "stdint.h"

#define MOTOR_1_TIMER htim2
#define MOTOR_1_CHANNEL TIM_CHANNEL_2
#define ENCODER_1_TIMER htim4
#define ENCODER_STEPS 1000

/*
#define MOTOR_2_TIMER htim
#define MOTOR_2_CHANNEL TIM_CHANNEL_

#define MOTOR_3_TIMER htim
#define MOTOR_3_CHANNEL TIM_CHANNEL_
*/

// Struct for Pins definition
struct Pin{
	GPIO_TypeDef* port;
	uint16_t pin;
};

// Struct for timer and channel used for each motor
struct MotorChannel{
	TIM_HandleTypeDef* timer;
	uint32_t channel;
};

#endif
