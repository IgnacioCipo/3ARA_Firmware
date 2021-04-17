#include "Motor.hpp"
#include "tim.h"
#include "stm32f4xx_hal_gpio.h"

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

}
