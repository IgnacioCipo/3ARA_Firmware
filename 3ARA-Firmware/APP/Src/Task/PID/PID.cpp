#include "Task/PID/PID.hpp"


PID::PID(float kp, float kd, float ki, float max_output, float min_output, float update_rate){
	kp_ = kp;
	ki_ = ki;
	kd_ = kd;
	pid_update_seconds = update_rate;
	max_pid_output_ = max_output;
	min_pid_output_ = min_output;
	pid_.Kp = kp_;
	pid_.Ki = ki_;
	pid_.Kd = kd_;
	arm_pid_init_f32(&pid_, 1);
}

float PID::updatePID(float setpoint_position, float current_position){
	error_ = setpoint_position - current_position;
	output = arm_pid_f32(&pid_, error_);
	if(output > max_pid_output_) output = max_pid_output_;
	else if(output < min_pid_output_) output = min_pid_output_;
	if(error_ < 2.0f && error_ > -2.0f) output = 0;
	return output;
}
