#include "3ARAEntrypoint.h"
#include "main.h"
#include "Task/PID/PID.hpp"
#include "Motor.hpp"
#include "Encoder.hpp"
#include "Settings.h"
#include "stm32f4xx_it.h"

float output_pid_2 = 0;
float current_angle_2 = 0;
int hall_2_flag = 0;
float pulses_2;

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

	//float current_angle = 0;
	if(robot_info_handler->angle_2 == 0){
		// Check if the hall is in the initial position
		if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_6) == GPIO_PIN_RESET){
			current_angle_2 = 0;
			encoder2.resetTicksCounter();
		}
		else	motor2.goHomePosition();
	}

	while(1){
		if(hall_2_flag == 1){
			hall_2_flag = 0;
			motor2.stopMotor();
			current_angle_2 = 0;
		}
		//pulses_2 = encoder2.getPulses();
		current_angle_2 = encoder2.getAngle();
		output_pid_2 = pid2.updatePID(robot_info_handler->angle_2, current_angle_2);
		if(output_pid_2 > 0) motor2.turnLeft(output_pid_2);
		else if (output_pid_2 < 0) motor2.turnRight(-output_pid_2);
		osDelay(PID_UPDATE_TIME_mS);
	}
}


