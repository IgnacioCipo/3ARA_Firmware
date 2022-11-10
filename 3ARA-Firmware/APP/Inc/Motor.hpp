#ifndef MOTOR_HPP
#define MOTOR_HPP

#include "main.h"
#include "tim.h"
#include "Settings.h"

class Motor{
	public:
		// Class constructor
		Motor(MotorChannel &motor_timer, Pin &motor_1, Pin &motor_2);

		void turnLeft(uint32_t duty);
		void turnRight(uint32_t duty);
		void goHomePosition();
		void stopMotor();

	private:
		uint16_t gpio_pin_1;
		uint16_t gpio_pin_2;
		GPIO_TypeDef* gpio_port_1;
		GPIO_TypeDef* gpio_port_2;
		TIM_HandleTypeDef* timer;
		uint32_t channel;
};

#endif
