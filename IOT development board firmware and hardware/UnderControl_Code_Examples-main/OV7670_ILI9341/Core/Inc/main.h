/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#define BTN_CAP_Pin GPIO_PIN_7
#define BTN_CAP_GPIO_Port GPIOF
#define BTN_MODE_Pin GPIO_PIN_8
#define BTN_MODE_GPIO_Port GPIOF
#define SD_MISO_Pin GPIO_PIN_2
#define SD_MISO_GPIO_Port GPIOC
#define SD_MOSI_Pin GPIO_PIN_3
#define SD_MOSI_GPIO_Port GPIOC
#define SD_CS_Pin GPIO_PIN_2
#define SD_CS_GPIO_Port GPIOA
#define USER_LED_Pin GPIO_PIN_3
#define USER_LED_GPIO_Port GPIOA
#define ROT_A_Pin GPIO_PIN_0
#define ROT_A_GPIO_Port GPIOG
#define ROT_B_Pin GPIO_PIN_1
#define ROT_B_GPIO_Port GPIOG
#define BTN_ROT_Pin GPIO_PIN_7
#define BTN_ROT_GPIO_Port GPIOE
#define SD_SCK_Pin GPIO_PIN_10
#define SD_SCK_GPIO_Port GPIOB
#define CAMERA_RESET_Pin GPIO_PIN_7
#define CAMERA_RESET_GPIO_Port GPIOG
#define CAMERA_PWD_Pin GPIO_PIN_8
#define CAMERA_PWD_GPIO_Port GPIOG
#define TOUCH_IRQ_Pin GPIO_PIN_10
#define TOUCH_IRQ_GPIO_Port GPIOA
#define TOUCH_CS_Pin GPIO_PIN_15
#define TOUCH_CS_GPIO_Port GPIOA
#define LCD_SCK_Pin GPIO_PIN_10
#define LCD_SCK_GPIO_Port GPIOC
#define LCD_MISO_Pin GPIO_PIN_11
#define LCD_MISO_GPIO_Port GPIOC
#define LCD_MOSI_Pin GPIO_PIN_12
#define LCD_MOSI_GPIO_Port GPIOC
#define LCD_DC_Pin GPIO_PIN_2
#define LCD_DC_GPIO_Port GPIOD
#define LCD_RST_Pin GPIO_PIN_3
#define LCD_RST_GPIO_Port GPIOD
#define LCD_CS_Pin GPIO_PIN_4
#define LCD_CS_GPIO_Port GPIOD
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
