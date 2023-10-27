/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define MODE0_Pin GPIO_PIN_0
#define MODE0_GPIO_Port GPIOA
#define MODE1_Pin GPIO_PIN_1
#define MODE1_GPIO_Port GPIOA
#define MODE2_Pin GPIO_PIN_2
#define MODE2_GPIO_Port GPIOA
#define LIMIT_A_Pin GPIO_PIN_0
#define LIMIT_A_GPIO_Port GPIOB
#define LIMIT_B_Pin GPIO_PIN_1
#define LIMIT_B_GPIO_Port GPIOB
#define STEPPER_PALSE_Pin GPIO_PIN_8
#define STEPPER_PALSE_GPIO_Port GPIOA
#define POWER_SAVE_Pin GPIO_PIN_3
#define POWER_SAVE_GPIO_Port GPIOB
#define ENABLE_Pin GPIO_PIN_4
#define ENABLE_GPIO_Port GPIOB
#define DIR_Pin GPIO_PIN_5
#define DIR_GPIO_Port GPIOB
#define LED_CAN_Pin GPIO_PIN_6
#define LED_CAN_GPIO_Port GPIOB
#define LED_MOTOR_Pin GPIO_PIN_7
#define LED_MOTOR_GPIO_Port GPIOB
#define LED_STATE1_Pin GPIO_PIN_8
#define LED_STATE1_GPIO_Port GPIOB
#define LED_STATE2_Pin GPIO_PIN_9
#define LED_STATE2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
