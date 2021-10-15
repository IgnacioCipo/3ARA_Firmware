/*
 * 3ARAInfo.h
 *
 *  Created on: Apr 14, 2021
 *      Author: Ignacio
 */

#ifndef INC_3ARAINFO_H_
#define INC_3ARAINFO_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "cmsis_os.h"

typedef struct{
	float angle_1;
	float angle_2;
	float angle_3;
	float ticks;
	osMutexId *mutexHandler;
} RobotInfoHandler;

void robotInfoInit(RobotInfoHandler *info_handler, osMutexId *mutex);

void setAngle1(RobotInfoHandler *info_handler, float angle);

void setAngle2(RobotInfoHandler *info_handler, float angle);

void setAngle3(RobotInfoHandler *info_handler, float angle);

float getAngle1(RobotInfoHandler *info_handler);

float getAngle2(RobotInfoHandler *info_handler);

float getAngle3(RobotInfoHandler *info_handler);

#ifdef __cplusplus
}
#endif

#endif /* INC_3ARAINFO_H_ */
