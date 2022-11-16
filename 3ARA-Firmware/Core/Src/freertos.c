/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "3ARAEntrypoint.h"
#include "3ARAInfo.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
RobotInfoHandler robot_info_handler;
extern int hall_1_flag;
extern int hall_2_flag;
extern int hall_3_flag;

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId taskPID1Handle;
osThreadId taskPID2Handle;
osThreadId taskPID3Handle;
osThreadId ROSCommsHandle;
osMutexId mutexHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void startPID1(void const * argument);
void startPID2(void const * argument);
void startPID3(void const * argument);
void startROSComms(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */
  /* Create the mutex(es) */
  /* definition and creation of mutex */
  osMutexDef(mutex);
  mutexHandle = osMutexCreate(osMutex(mutex));

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 256);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of taskPID1 */
  osThreadDef(taskPID1, startPID1, osPriorityIdle, 0, 512);
  taskPID1Handle = osThreadCreate(osThread(taskPID1), NULL);

  /* definition and creation of taskPID2 */
  osThreadDef(taskPID2, startPID2, osPriorityIdle, 0, 512);
  taskPID2Handle = osThreadCreate(osThread(taskPID2), NULL);

  /* definition and creation of taskPID3 */
  osThreadDef(taskPID3, startPID3, osPriorityNormal, 0, 512);
  taskPID3Handle = osThreadCreate(osThread(taskPID3), NULL);

  /* definition and creation of ROSComms */
  osThreadDef(ROSComms, startROSComms, osPriorityNormal, 0, 1024);
  ROSCommsHandle = osThreadCreate(osThread(ROSComms), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
	HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
    osDelay(2000);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_startPID1 */
/**
* @brief Function implementing the taskPID1 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startPID1 */
void startPID1(void const * argument)
{
  /* USER CODE BEGIN startPID1 */
	PID1Node(&robot_info_handler);
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END startPID1 */
}

/* USER CODE BEGIN Header_startPID2 */
/**
* @brief Function implementing the taskPID2 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startPID2 */
void startPID2(void const * argument)
{
  /* USER CODE BEGIN startPID2 */
	PID2Node(&robot_info_handler);
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END startPID2 */
}

/* USER CODE BEGIN Header_startPID3 */
/**
* @brief Function implementing the taskPID3 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startPID3 */
void startPID3(void const * argument)
{
  /* USER CODE BEGIN startPID3 */
	PID3Node(&robot_info_handler);
  /* Infinite loop */
  for(;;)
  {
    osDelay(1000);
  }
  /* USER CODE END startPID3 */
}

/* USER CODE BEGIN Header_startROSComms */
/**
* @brief Function implementing the ROSComms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_startROSComms */
void startROSComms(void const * argument)
{
  /* USER CODE BEGIN startROSComms */
	robotInfoInit(&robot_info_handler, &mutexHandle);
	startSerialComms(&robot_info_handler);
  /* Infinite loop */
  for(;;)
  {
	osDelay(1);
  }
  /* USER CODE END startROSComms */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
// Callback function for external gpio interrupt
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_6){
		hall_2_flag = 1;
	}
	else if(GPIO_Pin == GPIO_PIN_5){						// Change for PIN for hall 3
		hall_3_flag = 1;
	}
	else if(GPIO_Pin == GPIO_PIN_7){						// Change PIN for hall 1
		hall_1_flag = 1;
	}
}
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
