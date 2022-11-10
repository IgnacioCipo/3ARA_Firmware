#include "Encoder.hpp"

float ticks_1;
uint32_t angle_2_ticks;

Encoder::Encoder(TIM_HandleTypeDef* encoder_timer, float count_per_turn){
	timer = encoder_timer;
	encoder_resolution = 360.0f / count_per_turn;
	HAL_TIM_Encoder_Start(timer, TIM_CHANNEL_ALL);
}

float Encoder::getAngle(){
	ticks_1 = __HAL_TIM_GetCounter(timer);
	angle = (__HAL_TIM_GetCounter(timer) - 32767) * encoder_resolution;
	angle_2_ticks = __HAL_TIM_GetCounter(timer);
	return angle;
}

float Encoder::getPulses(){
	ticks = __HAL_TIM_GET_COUNTER(timer);
	return ticks;
}

void Encoder::resetTicksCounter(){
	__HAL_TIM_SetCounter(timer, 0);
}
