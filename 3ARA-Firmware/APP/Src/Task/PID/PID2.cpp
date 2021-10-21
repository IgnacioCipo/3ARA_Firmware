#include "3ARAEntrypoint.h"
#include "main.h"
#include "Task/PID/PID.hpp"
#include "Motor.hpp"
#include "Encoder.hpp"
#include "Settings.h"

//float current_angle = 0, output_pid_2 = 0;

void PID2Node(RobotInfoHandler *robot_info_handler){

	// Pins definition for motor 2
	Pin motor_2_a{MOTOR_2_L_GPIO_Port, MOTOR_2_L_Pin};
	Pin motor_2_b{MOTOR_2_R_GPIO_Port, MOTOR_2_R_Pin};

	// Timer definition for motor 2
	MotorChannel motor_2_timer{&MOTOR_2_TIMER, MOTOR_2_CHANNEL};

	// Motor 2 object creation
	Motor motor2(motor_2_timer, motor_2_a, motor_2_b);

	// Encoder 2 object creation
	Encoder encoder2(&ENCODER_2_TIMER, ENCODER_2_STEPS);

	// PID 2 object creation
	PID pid2(KP_CONST_2, KD_CONST_2, KI_CONST_2, MAX_PID_OUTPUT, MIN_PID_OUTPUT, PID_UPDATE_TIME_S);

	float current_angle = 0, output_pid_2 = 0;

	while(1){
		if(robot_info_handler->angle_2 == 0){
			motor2.goHomePosition();
		}
		else{
			current_angle = encoder2.getAngle();
			output_pid_2 = pid2.updatePID(robot_info_handler->angle_2, current_angle);
			if(output_pid_2 > 0) motor2.turnLeft(output_pid_2);
			else motor2.turnRight(-output_pid_2);
		}
		osDelay(PID_UPDATE_TIME_mS);
	}
}
