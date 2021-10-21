#include "Motor.hpp"
#include "tim.h"
#include "stm32f4xx_hal_gpio.h"
#include "cmsis_os.h"

Motor::Motor(MotorChannel &motor_timer, Pin &motor_1, Pin &motor_2){
	gpio_pin_1 = motor_1.pin;
	gpio_pin_2 = motor_2.pin;
	gpio_port_1 = motor_1.port;
	gpio_port_2 = motor_2.port;
	channel = motor_timer.channel;
	timer = motor_timer.timer;
	HAL_TIM_PWM_Start(motor_timer.timer, motor_timer.channel);
}

void Motor::turnLeft(uint32_t duty){
	HAL_GPIO_WritePin(gpio_port_1, gpio_pin_1, GPIO_PIN_SET);
	HAL_GPIO_WritePin(gpio_port_2, gpio_pin_2, GPIO_PIN_RESET);
	switch(channel){
		case TIM_CHANNEL_1:
			timer->Instance -> CCR1 = duty;
			break;
		case TIM_CHANNEL_2:
			timer->Instance -> CCR2 = duty;
			break;
		case TIM_CHANNEL_3:
			timer->Instance -> CCR3 = duty;
			break;
		case TIM_CHANNEL_4:
			timer->Instance -> CCR4 = duty;
			break;
	}
}

void Motor::turnRight(uint32_t duty){
	HAL_GPIO_WritePin(gpio_port_1, gpio_pin_1, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(gpio_port_2, gpio_pin_2, GPIO_PIN_SET);
	switch(channel){
			case TIM_CHANNEL_1:
				timer->Instance -> CCR1 = duty;
				break;
			case TIM_CHANNEL_2:
				timer->Instance -> CCR2 = duty;
				break;
			case TIM_CHANNEL_3:
				timer->Instance -> CCR3 = duty;
				break;
			case TIM_CHANNEL_4:
				timer->Instance -> CCR4 = duty;
				break;
	}
}

void Motor::goHomePosition(){
	switch(channel){
		// Motor 2
		case TIM_CHANNEL_1:
			Motor::turnRight(900);
			while(HAL_GPIO_ReadPin(HALL_SENSOR_2_GPIO_Port, HALL_SENSOR_2_Pin) == GPIO_PIN_SET){
				osDelay(10);
			}

			timer->Instance -> CCR1 = 0;
			__HAL_TIM_SetCounter(&ENCODER_2_TIMER, 0);
			break;
		// Motor 1
		case TIM_CHANNEL_2:
			Motor::turnLeft(900);
			while(HAL_GPIO_ReadPin(HALL_SENSOR_1_GPIO_Port, HALL_SENSOR_1_Pin) == GPIO_PIN_SET){
				osDelay(10);
			}

			timer->Instance -> CCR2 = 0;
			__HAL_TIM_SetCounter(&ENCODER_1_TIMER, 0);
			break;
	    // Motor 3
		case TIM_CHANNEL_3:
			Motor::turnLeft(900);
			while(HAL_GPIO_ReadPin(HALL_SENSOR_3_GPIO_Port, HALL_SENSOR_3_Pin) == GPIO_PIN_SET){
				osDelay(10);
			}
			timer->Instance -> CCR3 = 0;
			__HAL_TIM_SetCounter(&ENCODER_3_TIMER, 0);
			break;
		case TIM_CHANNEL_4:
			timer->Instance -> CCR4 = 0;
			//__HAL_TIM_SetCounter(timer, 0);
			break;
	}
}
