/**
  ******************************************************************************
  * File Name          : key.h
  * Description        : This file contains all the key functions prototypes for 
  *                      the keys  
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 PQDUSA Inc.
  * All rights reserved.
  * Author: yaoyu
  * Date: 2019/09/04
  *
  ******************************************************************************
**/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __key_H
#define __key_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define LONG_PRESS_INTERVAL 5000  //long press delay
#define DEBOUNCING 50 //debouncing delay

#ifdef PULLDOWN
#define KEY HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14) ^ 0x01
#else
#define KEY HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_14)//PULL_UP
#endif

void keyScan(void);
__weak void onClick();
__weak void onLongPress();
// __weak void init();
// __weak void onClick(uint16_t GPIO_PIN);
// __weak void onLongPress(uint16_t GPIO_PIN);
// __weak void onTouch(uint16_t GPIO_PIN);

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT PQDUSA Inc. *****END OF FILE****/
