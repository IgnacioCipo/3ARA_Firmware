#include "3ARAEntrypoint.h"
#include "main.h"
#include "Task/PID/PID.hpp"
#include "Motor.hpp"
#include "Encoder.hpp"
#include "Settings.h"

void PID1Node(RobotInfoHandler *robot_info_handler){

	// Pin definition for motor 1
	Pin motor_1_a{MOTOR_1_L_GPIO_Port, MOTOR_1_L_Pin};
	Pin motor_1_b{MOTOR_1_R_GPIO_Port, MOTOR_1_R_Pin};

	// Timer definition for motor 1
	MotorChannel motor_1_timer{&MOTOR_1_TIMER, MOTOR_1_CHANNEL};

	// Motor 1 object definition
	Motor motor1(motor_1_timer, motor_1_a, motor_1_b);

	// Encoder 1 object definition
	Encoder encoder1(&ENCODER_1_TIMER, ENCODER_STEPS);

	while(1){
		if(robot_info_handler->angle_1 == 1) motor1.turnLeft(1000);
		else motor1.turnLeft(0);
		osDelay(50);
	}
}
