/**
  ******************************************************************************
  * File Name          : key.c
  * Description        : This file contains some thoughts about the key event.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2019 PQDUSA Inc.
  * All rights reserved.
  * Author: yaoyu
  * Date: 2019/09/04
  ******************************************************************************
  **/
#include "key.h"
#include "usart.h"

unsigned char trg = 0x00;
unsigned char cnt = 0x00; //check is key press continued
unsigned char rls = 0x00;
unsigned char cnt_plus = 0x00;
unsigned char lock = 0x00;//lock for longpress

void keyScan(){
  /**
   * TouchDown trg 1 cnt 1 rls 0
   * Touch     trg 0 cnt 1 rls 0
   * TouchUp   trg 0 cnt 0 rls 1 
   **/
  unsigned char read = KEY;//pull up resistor

  trg = read & ( read ^ cnt);
  rls = ~read & ( read ^ cnt);
  cnt = read;//old data

  // log_printf("============= keyScan: read %d\n", read);
  // log_printf("============= keyScan: trg %d cnt %d rls %d\n", trg, cnt, rls);
  if(trg){
    //clear status
    lock = 0x00;
    cnt_plus = 0x00;
  }

  if(rls & ~lock){
     onClick();
      //consume event
      lock = 0x00;
      cnt_plus = 0x00;
  }

  if(cnt & ~lock){//not yet long press, add counter
    cnt_plus++;
    if(cnt_plus >= LONG_PRESS_INTERVAL / DEBOUNCING){
      onLongPress();
      //consume event
      lock = 0x01;
      cnt_plus = 0x00;
    }
  }
}

__weak void onClick(){
/** Inplement this in your code **/
}
__weak void onLongPress(){
/** Inplement this in your code **/
}