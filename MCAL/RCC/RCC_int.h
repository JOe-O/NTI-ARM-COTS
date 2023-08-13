/*
 * RCC_int.h
 *
 *  Created on: Aug 11, 2023
 *      Author: JOe
 */

#ifndef RCC_INT_H_
#define RCC_INT_H_



#define AHBENR							1
#define APB2ENR							2
#define APB1ENR							3



void RCC_voidInit();
void RCC_voidPerepheralEN(u8 BusID,u8 PeripheralID);
void RCC_voidPerepheralDis(u8 BusID,u8 PeripheralID);






#endif /* RCC_INT_H_ */
