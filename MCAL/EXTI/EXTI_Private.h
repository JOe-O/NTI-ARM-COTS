/*
 * EXTI_Private.h
 *
 *  Created on: Aug 13, 2023
 *      Author: ART
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



#define INT_EXTI_PORTA			1
#define INT_EXTI_PORTB			2
#define INT_EXTI_PORTC			3
#define INT_EXTI_PORTD			4

typedef struct
{
	volatile u32 IMR1;
	volatile u32 EMR1;
	volatile u32 RTSR1;
	volatile u32 FTSR1;
	volatile u32 SWIER1;
	volatile u32 PR1;

}EXTI_type;

#define EXTI		((EXTI_type *)(0x40010400))


#endif /* EXTI_PRIVATE_H_ */
