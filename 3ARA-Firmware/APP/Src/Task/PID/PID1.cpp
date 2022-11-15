#include "3ARAEntrypoint.h"
#include "main.h"
#include "Task/PID/PID.hpp"
#include "Motor.hpp"
#include "Encoder.hpp"
#include "Settings.h"

float output_pid_1=0;
float current_angle_1 = 0;
int hall_1_flag = 0;

void PID1Node(RobotInfoHandler *robot_info_handler){

	// Pins definition for motor 1
	Pin motor_1_a{MOTOR_1_L_GPIO_Port, MOTOR_1_L_Pin};
	Pin motor_1_b{MOTOR_1_R_GPIO_Port, MOTOR_1_R_Pin};

	// Timer definition for motor 1
	MotorChannel motor_1_timer{&MOTOR_1_TIMER, MOTOR_1_CHANNEL};

	// Motor 1 object creation
	Motor motor1(motor_1_timer, motor_1_a, motor_1_b);

	// Encoder 1 object creation
	Encoder encoder1(&ENCODER_1_TIMER, ENCODER_1_STEPS);

	// PID 1 object creation
	PID pid1(KP_CONST_1, KD_CONST_1, KI_CONST_1, MAX_PID_OUTPUT, MIN_PID_OUTPUT, PID_UPDATE_TIME_S);

	if(robot_info_handler->angle_1 == 0){
		// Check if the hall is in the initial position
		if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7) == GPIO_PIN_RESET){		// Cambiar por el pin del hall 1
			current_angle_1 = 0;
			encoder1.resetTicksCounter();
		}
		else	motor1.goHomePosition();
	}

	while(1){
		if(hall_1_flag == 1){
			hall_1_flag = 0;
			motor1.stopMotor();
			current_angle_1 = 0;
		}
		current_angle_1 = encoder1.getAngle();
		output_pid_1 = pid1.updatePID(robot_info_handler->angle_1, current_angle_1);
		if(output_pid_1 > 0) motor1.turnRight(output_pid_1);
		else if (output_pid_1 < 0) motor1.turnLeft(-output_pid_1);
		osDelay(PID_UPDATE_TIME_mS);
	}
}

/*
// Callback function for external gpio interrupt
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_7){						// Change PIN for hall 1
		hall_1_flag = 1;
	}
}
*/
