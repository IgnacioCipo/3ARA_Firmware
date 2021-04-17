#ifndef ENCODER_HPP
#define ENCODER_HPP

#include "main.h"
#include "tim.h"
#include "stm32f4xx_hal_gpio.h"
#include "Settings.h"

class Encoder{
	public:
		Encoder(TIM_HandleTypeDef* encoder_timer, float count_per_turn);
		float getAngle();
		float getPulses();

	private:
		TIM_HandleTypeDef* timer;

		float angle;
		float encoder_resolution;
};

#endif
