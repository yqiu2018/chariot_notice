#ifndef __HARDWARE_H
#define __HARDWARE_H
#include "sys.h"

void GPIO_Config(void);

void TIMX_Config(u16 arr,u16 psc);

void SetMotorSpeed(int16_t Duty);

void Encoder_Init(void);

int Read_Encoder(u8 TIMX);

void TIM1_IRQHandler(void);
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);


#endif
