#include "Task/ROSComms/ROSComms.hpp"
#include "3ARAEntrypoint.h"
#include "ROSSerial/ros.h"
#include "ROSSerial/std_msgs/String.h"
#include "ROSSerial/std_msgs/Float32.h"
#include "stm32f4xx_hal_conf.h"
#include "main.h"
#include "cmsis_os.h"
#include "3ARAInfo.h"

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart, ros::NodeHandle nodeHandler){
  nodeHandler.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart, ros::NodeHandle nodeHandler){
  nodeHandler.getHardware()->reset_rbuf();
}

extern RobotInfoHandler robot_info_handler;

void positionCallBack(const std_msgs::Float32 &position_msg);
void startROSSerialComms(RobotInfoHandler *info_handler){

	ros::NodeHandle nh;
	std_msgs::String str_msg;


	// Publishers
	ros::Publisher chatter("chatter", &str_msg);

	// Subscribers
	//ros::Subscriber<std_msgs::Float32> positionTopic("positionTopic", &positionCallBack, 10);

	char hello[] = "Hello world from STM32!";

	nh.initNode();
    nh.advertise(chatter);
    //nh.subscribe(positionTopic);

    while(1){

    	str_msg.data = hello;
    	chatter.publish(&str_msg);
		nh.spinOnce();
		osDelay(2000);
    		/*
    		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);
    		osDelay(2000);
    		*/
    	}
}

void positionCallBack(const std_msgs::Float32 &position_msg){
	setAngle1(&robot_info_handler, position_msg.data);
}
