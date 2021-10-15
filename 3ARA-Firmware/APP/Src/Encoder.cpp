#include "Encoder.hpp"

float ticks_1;

Encoder::Encoder(TIM_HandleTypeDef* encoder_timer, float count_per_turn){
	timer = encoder_timer;
	encoder_resolution = 360.0f / count_per_turn;
	HAL_TIM_Encoder_Start(timer, TIM_CHANNEL_ALL);
}

float Encoder::getAngle(){
	ticks_1 = __HAL_TIM_GetCounter(timer);
	angle = __HAL_TIM_GetCounter(timer) * encoder_resolution;
	return angle;
}

float Encoder::getPulses(){
	ticks = __HAL_TIM_GET_COUNTER(timer);
	return ticks;
}

void Encoder::resetTicksCounter(){
	__HAL_TIM_SetCounter(timer, 0);
}
