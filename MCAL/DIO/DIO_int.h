/*
 * DIO_int.h
 *
 *  Created on: Aug 12, 2023
 *      Author: ART
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_



#define PORTA		1
#define PORTB		2
#define PORTC		3
#define PORTD		4
#define PORTE		5
#define PORTF		6


#define DIO_PIN0			0
#define DIO_PIN1			1
#define DIO_PIN2			2
#define DIO_PIN3			3
#define DIO_PIN4			4
#define DIO_PIN5			5
#define DIO_PIN6			6
#define DIO_PIN7			7
#define DIO_PIN8			8
#define DIO_PIN9			9
#define DIO_PIN10			10
#define DIO_PIN11			11
#define DIO_PIN12			12
#define DIO_PIN13			13
#define DIO_PIN14			14
#define DIO_PIN15			15


#define DIO_HIGH			1
#define DIO_LOW				0

#define ALL_OUTPUT			0x55555555
#define ALL_INPUT			0



#define DIO_INPUT			0
#define DIO_INPUT_PULLUP	1
#define DIO_INPUT_PULLDOWN	2
#define DIO_INPUT_ANALOG	3

#define DIO_OUTPUT_PUSH_PULL_LOW_FREQ			4
#define DIO_OUTPUT_PUSH_PULL_MEDIUM_FREQ		5
#define DIO_OUTPUT_PUSH_PULL_HIGH_FREQ			6
#define DIO_OUPTUT_OPEN_DRAIN_LOW_FREQ			7
#define DIO_OUPTUT_OPEN_DRAIN_MEDIUM_FREQ		8
#define DIO_OUPTUT_OPEN_DRAIN_HIGH_FREQ			9
#define DIO_OUTPUT_ALTERNATIVE_PUSH_PULL		10
#define DIO_OUTPUT_ALTERNATIVE_OPEN_DRAIN		11


void DIO_voidSetPinValue(u8 PortId,u8 PinId,u8 Value);
void DIO_voidSetPinDirection(u8 PortId,u8 PinId,u8 Direction);
u8   DIO_u8GetPinValue(u8 PortId,u8 PinId);
void DIO_voidSetPortValue(u8 Copy_PortX, u8 Copy_value);
void DIO_voidSetPortDirection(u8 Copy_PortX, u32 Copy_Direction);


#endif /* DIO_INT_H_ */
