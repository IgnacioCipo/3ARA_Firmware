/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MOTOR_2_R_Pin GPIO_PIN_2
#define MOTOR_2_R_GPIO_Port GPIOE
#define MOTOR_2_L_Pin GPIO_PIN_4
#define MOTOR_2_L_GPIO_Port GPIOE
#define LED_1_Pin GPIO_PIN_1
#define LED_1_GPIO_Port GPIOC
#define MOTOR_1_R_Pin GPIO_PIN_3
#define MOTOR_1_R_GPIO_Port GPIOC
#define MOTOR_2_Pin GPIO_PIN_0
#define MOTOR_2_GPIO_Port GPIOA
#define MOTOR_1_Pin GPIO_PIN_1
#define MOTOR_1_GPIO_Port GPIOA
#define MOTOR_1_L_Pin GPIO_PIN_4
#define MOTOR_1_L_GPIO_Port GPIOA
#define USER_BUTTON_Pin GPIO_PIN_8
#define USER_BUTTON_GPIO_Port GPIOE
#define LED_2_Pin GPIO_PIN_15
#define LED_2_GPIO_Port GPIOE
#define MOTOR_3_Pin GPIO_PIN_10
#define MOTOR_3_GPIO_Port GPIOB
#define MOTOR_3_R_Pin GPIO_PIN_9
#define MOTOR_3_R_GPIO_Port GPIOD
#define MOTOR_3_L_Pin GPIO_PIN_11
#define MOTOR_3_L_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
