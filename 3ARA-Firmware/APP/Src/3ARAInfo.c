/*
 * 3ARAInfo.c
 *
 *  Created on: Apr 14, 2021
 *      Author: Ignacio
 */

#include "3ARAInfo.h"

void robotInfoInit(RobotInfoHandler *info_handler, osMutexId *mutex){
	info_handler->mutexHandler = mutex;
	info_handler->angle_1 = 0;
	info_handler->angle_2 = 0;
	info_handler->angle_3 = 0;
}

void setAngle1(RobotInfoHandler *info_handler, float angle){
	osMutexWait(*(info_handler->mutexHandler), osWaitForever);
	info_handler->angle_1 = angle;
	osMutexRelease(*(info_handler->mutexHandler));
}

void setAngle2(RobotInfoHandler *info_handler){
	osMutexWait(*(info_handler->mutexHandler), osWaitForever);

	osMutexRelease(*(info_handler->mutexHandler));
}

void setAngle3(RobotInfoHandler *info_handler){
	osMutexWait(*(info_handler->mutexHandler), osWaitForever);

	osMutexRelease(*(info_handler->mutexHandler));
}

void getAngle1(RobotInfoHandler *info_handler){
	osMutexWait(*(info_handler->mutexHandler), osWaitForever);

	osMutexRelease(*(info_handler->mutexHandler));
}

void getAngle2(RobotInfoHandler *info_handler){
	osMutexWait(*(info_handler->mutexHandler), osWaitForever);

	osMutexRelease(*(info_handler->mutexHandler));
}

void getAngle3(RobotInfoHandler *info_handler){
	osMutexWait(*(info_handler->mutexHandler), osWaitForever);

	osMutexRelease(*(info_handler->mutexHandler));
}


