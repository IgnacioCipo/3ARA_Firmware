#ifndef SETTINGS_H
#define SETTINGS_H

#include "main.h"
#include "stdint.h"

// Definitions for joint 1
#define MOTOR_1_TIMER htim2
#define MOTOR_1_CHANNEL TIM_CHANNEL_2
#define ENCODER_1_TIMER htim4

// Definitions for joint 2
#define MOTOR_2_TIMER htim2
#define MOTOR_2_CHANNEL TIM_CHANNEL_1
#define ENCODER_2_TIMER htim8

// Definitions for joint 3
#define MOTOR_3_TIMER htim2
#define MOTOR_3_CHANNEL TIM_CHANNEL_3
#define ENCODER_3_TIMER	htim3

// PID settings
#define MIN_PID_OUTPUT -1000			// Minimum pid output value
#define MAX_PID_OUTPUT	1000			// Maximum pid output value
#define PID_UPDATE_TIME_S 0.060			// Time required for re calculate PID in seconds
#define PID_UPDATE_TIME_mS 60			// Time required for re calculate PID in milliseconds

// PID 1 ctes
#define KI_CONST_1 8
#define KD_CONST_1 1
#define KP_CONST_1 800
// PID 2 ctes
#define KI_CONST_2 4
#define KD_CONST_2 0.1
#define KP_CONST_2 200
// PID 3 ctes
#define KI_CONST_3 8
#define KD_CONST_3 0.1
#define KP_CONST_3 70

#define ENCODER_1_STEPS 20127				// Ticks counted per turn of the reduction output of joint 1
#define ENCODER_2_STEPS 20127				// Ticks counted per turn of the reduction output of joint 2
#define ENCODER_3_STEPS	4324				// Ticks counted per turn of the reduction output of joint 3

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
