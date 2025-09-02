/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

/* USER CODE END Variables */
osThreadId DebugMonitorHandle;
osThreadId ModeMgrHandle;
osThreadId LiveviewCtrlHandle;
osThreadId PlaybackCtrlHandle;
osThreadId InputHandle;
osMessageQId QueueModeMgrHandle;
osMessageQId QueueLiveviewCtrlHandle;
osMessageQId QueuePlaybackCtrlHandle;
osMessageQId QueueInputHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void debugMonitor_task(void const * argument);
extern void modeMgr_task(void const * argument);
extern void liveviewCtrl_task(void const * argument);
extern void playbackCtrl_task(void const * argument);
extern void input_task(void const * argument);

extern void MX_USB_DEVICE_Init(void);
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

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of QueueModeMgr */
  osMessageQDef(QueueModeMgr, 4, uint32_t);
  QueueModeMgrHandle = osMessageCreate(osMessageQ(QueueModeMgr), NULL);

  /* definition and creation of QueueLiveviewCtrl */
  osMessageQDef(QueueLiveviewCtrl, 4, uint32_t);
  QueueLiveviewCtrlHandle = osMessageCreate(osMessageQ(QueueLiveviewCtrl), NULL);

  /* definition and creation of QueuePlaybackCtrl */
  osMessageQDef(QueuePlaybackCtrl, 4, uint32_t);
  QueuePlaybackCtrlHandle = osMessageCreate(osMessageQ(QueuePlaybackCtrl), NULL);

  /* definition and creation of QueueInput */
  osMessageQDef(QueueInput, 4, uint32_t);
  QueueInputHandle = osMessageCreate(osMessageQ(QueueInput), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of DebugMonitor */
  osThreadDef(DebugMonitor, debugMonitor_task, osPriorityIdle, 0, 512);
  DebugMonitorHandle = osThreadCreate(osThread(DebugMonitor), NULL);

  /* definition and creation of ModeMgr */
  osThreadDef(ModeMgr, modeMgr_task, osPriorityBelowNormal, 0, 128);
  ModeMgrHandle = osThreadCreate(osThread(ModeMgr), NULL);

  /* definition and creation of LiveviewCtrl */
  osThreadDef(LiveviewCtrl, liveviewCtrl_task, osPriorityNormal, 0, 512);
  LiveviewCtrlHandle = osThreadCreate(osThread(LiveviewCtrl), NULL);

  /* definition and creation of PlaybackCtrl */
  osThreadDef(PlaybackCtrl, playbackCtrl_task, osPriorityNormal, 0, 512);
  PlaybackCtrlHandle = osThreadCreate(osThread(PlaybackCtrl), NULL);

  /* definition and creation of Input */
  osThreadDef(Input, input_task, osPriorityNormal, 0, 128);
  InputHandle = osThreadCreate(osThread(Input), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_debugMonitor_task */
/**
  * @brief  Function implementing the DebugMonitor thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_debugMonitor_task */
__weak void debugMonitor_task(void const * argument)
{
  /* init code for USB_DEVICE */
  MX_USB_DEVICE_Init();
  /* USER CODE BEGIN debugMonitor_task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END debugMonitor_task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
