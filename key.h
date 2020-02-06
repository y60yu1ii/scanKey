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
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define DEBOUNCING 50            //debouncing delay
#define LONG_PRESS_INTERVAL 5000 //long press delay

#define KEY HAL_GPIO_ReadPin(GPIOA, BTN_Pin)

#define ACTIVE_HIGH

  void keyScan(void);
  __weak void onClick();
  __weak void onLongPress();

  /** uncomment these if you are using arduino
__attribute__((weak)) void onClick();
__attribute__((weak)) void onLongPress();
*/

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
