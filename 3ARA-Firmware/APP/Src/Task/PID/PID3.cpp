#include "3ARAEntrypoint.h"
#include "main.h"
#include "Task/PID/PID.hpp"
#include "Motor.hpp"
#include "Encoder.hpp"
#include "Settings.h"

float current_angle = 0, output_pid_3 = 0;

void PID3Node(RobotInfoHandler *robot_info_handler){
	// Pins definition for motor 3
	Pin motor_3_a{MOTOR_3_L_GPIO_Port, MOTOR_3_L_Pin};
	Pin motor_3_b{MOTOR_3_R_GPIO_Port, MOTOR_3_R_Pin};

	// Timer definition for motor 3
	MotorChannel motor_3_timer{&MOTOR_3_TIMER, MOTOR_3_CHANNEL};

	// Motor 3 object creation
	Motor motor3(motor_3_timer, motor_3_a, motor_3_b);

	// Encoder 3 object creation
	Encoder encoder3(&ENCODER_3_TIMER, ENCODER_3_STEPS);

	// PID 3 object creation
	PID pid3(KP_CONST_3, KD_CONST_3, KI_CONST_3, MAX_PID_OUTPUT, MIN_PID_OUTPUT, PID_UPDATE_TIME_S);

	//float current_angle = 0, output_pid_3 = 0;

	while(1){
		if(robot_info_handler->angle_3 == 0){
			motor3.goHomePosition();
		}
		else{
			current_angle = encoder3.getAngle();
			output_pid_3 = pid3.updatePID(robot_info_handler->angle_3, current_angle);
			if(output_pid_3 > 0) motor3.turnLeft(output_pid_3);
			else motor3.turnRight(-output_pid_3);
		}
		osDelay(PID_UPDATE_TIME_mS);
	}
}

