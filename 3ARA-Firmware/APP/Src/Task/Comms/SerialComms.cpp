/*
 * SerialComms.cpp
 *
 *  Created on: May 9, 2021
 *      Author: Ignacio
 */

#include "3ARAEntrypoint.h"
#include "usart.h"

#define RECEIVED_BYTES 		14			// Numbers of bytes received in each package
#define START_OF_PACKAGE	0xA1		// Start byte of each package
#define END_OF_PACKAGE		0xB1		// End byte of each package

// Union to split float value into four bytes or to obtain float value from it's four bytes
union {
	float float_value;
	uint8_t bytes[4];
}angle_1, angle_2, angle_3, ticks, test_angle;

// Buffer to save data received
uint8_t rx_buffer[RECEIVED_BYTES];
uint8_t tx_buffer[] = {0x00, 0x01, 0x02, 0x0A};

// Flag that activates when arrives a new package from serial port
bool data_received = false;
// Flag that indicates to send the data to the serial port
bool data_send = true;

void startSerialComms(RobotInfoHandler *info_handler){
	HAL_UART_Receive_IT(&huart2, (uint8_t*) rx_buffer, RECEIVED_BYTES);

	while(1){
		if(data_received == true){
			data_received = false;
			if(rx_buffer[0] == START_OF_PACKAGE && rx_buffer[13] == END_OF_PACKAGE){
				angle_1.bytes[0] = rx_buffer[1];
				angle_1.bytes[1] = rx_buffer[2];
				angle_1.bytes[2] = rx_buffer[3];
				angle_1.bytes[3] = rx_buffer[4];
				angle_2.bytes[0] = rx_buffer[5];
				angle_2.bytes[1] = rx_buffer[6];
				angle_2.bytes[2] = rx_buffer[7];
				angle_2.bytes[3] = rx_buffer[8];
				angle_3.bytes[0] = rx_buffer[9];
				angle_3.bytes[1] = rx_buffer[10];
				angle_3.bytes[2] = rx_buffer[11];
				angle_3.bytes[3] = rx_buffer[12];
				setAngle1(info_handler, angle_1.float_value);
				setAngle2(info_handler, angle_2.float_value);
				setAngle3(info_handler, angle_3.float_value);
			}
		}
		if(data_send == true){
			//ticks.float_value= info_handler->ticks;
			//HAL_UART_Transmit(&huart2, ticks.bytes, sizeof(ticks.bytes), 1000);

			HAL_UART_Transmit(&huart2, angle_1.bytes, sizeof(angle_1.bytes), 1000);
			HAL_UART_Transmit(&huart2, angle_2.bytes, sizeof(angle_2.bytes), 1000);
			HAL_UART_Transmit(&huart2, angle_3.bytes, sizeof(angle_3.bytes), 1000);

			osDelay(500);
		}
		osDelay(100);
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == USART2) {
		data_received = true;
	}
	HAL_UART_Receive_IT(&huart2, (uint8_t*) rx_buffer, RECEIVED_BYTES);
}
