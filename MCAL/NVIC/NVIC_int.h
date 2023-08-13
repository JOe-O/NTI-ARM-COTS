/*
 * NVIC_int.h
 *
 *  Created on: Aug 13, 2023
 *      Author: ART
 */

#ifndef NVIC_INT_H_
#define NVIC_INT_H_


void NVIC_voidInit(void);
void NVIC_voidEnabeInterrupt(u8 InterruptNum);
void NVIC_voidDisableInterrupt(u8 InterruptNum);
void NVIC_voidSetPendingFlag(u8 InterruptNum);
void NVIC_voidClrPendingFlag(u8 InterruptNum);
u8 NVIC_u8ReadActiveFlag(u8 InterruptNum);
void NVIC_voidSetPriority(u8 InterruptNum,u8 priority);
void EXTI0_IRQHandler();





#endif /* NVIC_INT_H_ */
