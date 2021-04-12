#include "Task/ROSComms/ROSComms.hpp"
#include "3ARAEntrypoint.h"
#include "ROSSerial/ros.h"
#include "ROSSerial/std_msgs/String.h"
#include "stm32f4xx_hal_conf.h"
#include "main.h"
#include "cmsis_os.h"

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart, ros::NodeHandle nodeHandler){
  nodeHandler.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart, ros::NodeHandle nodeHandler){
  nodeHandler.getHardware()->reset_rbuf();
}


void startROSSerialComms(){

	ros::NodeHandle nh;
	std_msgs::String str_msg;

	ros::Publisher chatter("chatter", &str_msg);
	char hello[] = "Hello world from STM32!";

	nh.initNode();
    nh.advertise(chatter);

    while(1){
    		HAL_GPIO_TogglePin(LED_1_GPIO_Port, LED_1_Pin);

    		str_msg.data = hello;
    		chatter.publish(&str_msg);
    		nh.spinOnce();
    		osDelay(2000);
    	}
}

