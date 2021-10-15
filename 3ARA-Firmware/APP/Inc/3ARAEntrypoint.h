#ifndef INC_3ARAENTRYPOINT_H_
#define INC_3ARAENTRYPOINT_H_

#include "3ARAInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

void startSerialComms(RobotInfoHandler *info_handler);
void PID1Node(RobotInfoHandler *robot_info_handler);
void PID2Node(RobotInfoHandler *robot_info_handler);
void PID3Node(RobotInfoHandler *robot_info_handler);

#ifdef __cplusplus
}
#endif

#endif /* INC_3ARAENTRYPOINT_H_*/
