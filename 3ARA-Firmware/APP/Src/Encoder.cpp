#include "Encoder.hpp"

Encoder::Encoder(TIM_HandleTypeDef* encoder_timer, float count_per_turn){
	timer = encoder_timer;
	encoder_resolution = 360.0f / count_per_turn;
	HAL_TIM_Encoder_Start(timer, TIM_CHANNEL_ALL);
}

float Encoder::getAngle(){
	angle = __HAL_TIM_GetCounter(timer) * encoder_resolution;
	return angle;
}

float Encoder::getPulses(){

}
