/*
 * DIO_Prog.c
 *
 *  Created on: Aug 12, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "bitMath.h"



#include "DIO_Priv.h"
#include "DIO_int.h"
#include "DIO_conf.h"



void DIO_voidSetPinValue(u8 PortId,u8 PinId,u8 Value)
{
	if(Value == DIO_HIGH)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_ODR,PinId);
			break;
		case PORTB:
			SET_BIT(GPIOB_ODR,PinId);
			break;
		case PORTC:
			SET_BIT(GPIOC_ODR,PinId);
			break;
		case PORTD:
			SET_BIT(GPIOD_ODR,PinId);
			break;
		case PORTF:
			SET_BIT(GPIOF_ODR,PinId);
			break;
		}
	}else if(Value == DIO_LOW)
	{
		switch(PortId)
		{
		case PORTA:
			CLR_BIT(GPIOA_ODR,PinId);
			break;
		case PORTB:
			CLR_BIT(GPIOB_ODR,PinId);
			break;
		case PORTC:
			CLR_BIT(GPIOC_ODR,PinId);
			break;
		case PORTD:
			CLR_BIT(GPIOD_ODR,PinId);
			break;
		case PORTF:
			CLR_BIT(GPIOF_ODR,PinId);
			break;
		}
	}
}
void DIO_voidSetPinDirection(u8 PortId,u8 PinId,u8 Direction)
{
	if(Direction == DIO_INPUT)
	{
		switch(PortId)
		{
		case PORTA:
			CLR_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));
			break;
		case PORTB:
			CLR_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));
			break;
		case PORTC:
			CLR_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));
			break;
		case PORTD:
			CLR_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));
			break;
		case PORTF:
			CLR_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));
			break;

		}
	}else if(Direction == DIO_INPUT_PULLUP)
	{
		switch(PortId)
		{
		case PORTA:
			CLR_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			SET_BIT(GPIOA_PUPDR,PinId*2);
			CLR_BIT(GPIOA_PUPDR,((PinId*2)+1));
			break;
		case PORTB:
			CLR_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			SET_BIT(GPIOB_PUPDR,PinId*2);
			CLR_BIT(GPIOB_PUPDR,((PinId*2)+1));
			break;
		case PORTC:
			CLR_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			SET_BIT(GPIOC_PUPDR,PinId*2);
			CLR_BIT(GPIOC_PUPDR,((PinId*2)+1));
			break;
		case PORTD:
			CLR_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			SET_BIT(GPIOD_PUPDR,PinId*2);
			CLR_BIT(GPIOD_PUPDR,((PinId*2)+1));
			break;
		case PORTF:
			CLR_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			SET_BIT(GPIOF_PUPDR,PinId*2);
			CLR_BIT(GPIOF_PUPDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_INPUT_PULLDOWN)
	{
		switch(PortId)
		{
		case PORTA:
			CLR_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			CLR_BIT(GPIOA_PUPDR,PinId*2);
			SET_BIT(GPIOA_PUPDR,((PinId*2)+1));
			break;
		case PORTB:
			CLR_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			CLR_BIT(GPIOB_PUPDR,PinId*2);
			SET_BIT(GPIOB_PUPDR,((PinId*2)+1));
			break;
		case PORTC:
			CLR_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			CLR_BIT(GPIOC_PUPDR,PinId*2);
			SET_BIT(GPIOC_PUPDR,((PinId*2)+1));
			break;
		case PORTD:
			CLR_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			CLR_BIT(GPIOD_PUPDR,PinId*2);
			SET_BIT(GPIOD_PUPDR,((PinId*2)+1));
			break;
		case PORTF:
			CLR_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			CLR_BIT(GPIOF_PUPDR,PinId*2);
			SET_BIT(GPIOF_PUPDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_INPUT_ANALOG)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_MODER,PinId*2);
			SET_BIT(GPIOA_MODER,((PinId*2)+1));
			break;
		case PORTB:
			SET_BIT(GPIOB_MODER,PinId*2);
			SET_BIT(GPIOB_MODER,((PinId*2)+1));
			break;
		case PORTC:
			SET_BIT(GPIOC_MODER,PinId*2);
			SET_BIT(GPIOC_MODER,((PinId*2)+1));
			break;
		case PORTD:
			SET_BIT(GPIOD_MODER,PinId*2);
			SET_BIT(GPIOD_MODER,((PinId*2)+1));
			break;
		case PORTF:
			SET_BIT(GPIOF_MODER,PinId*2);
			SET_BIT(GPIOF_MODER,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_OUTPUT_PUSH_PULL_HIGH_FREQ)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			CLR_BIT(GPIOA_OTYPER,PinId);

			SET_BIT(GPIOA_OSPEEDR,PinId*2);
			SET_BIT(GPIOA_OSPEEDR,((PinId*2)+1));
			break;
		case PORTB:
			SET_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			CLR_BIT(GPIOB_OTYPER,PinId);

			SET_BIT(GPIOB_OSPEEDR,PinId*2);
			SET_BIT(GPIOB_OSPEEDR,((PinId*2)+1));
			break;
		case PORTC:
			SET_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			CLR_BIT(GPIOC_OTYPER,PinId);

			SET_BIT(GPIOC_OSPEEDR,PinId*2);
			SET_BIT(GPIOC_OSPEEDR,((PinId*2)+1));
			break;
		case PORTD:
			SET_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			CLR_BIT(GPIOD_OTYPER,PinId);

			SET_BIT(GPIOD_OSPEEDR,PinId*2);
			SET_BIT(GPIOD_OSPEEDR,((PinId*2)+1));
			break;
		case PORTF:
			SET_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			CLR_BIT(GPIOF_OTYPER,PinId);

			SET_BIT(GPIOF_OSPEEDR,PinId*2);
			SET_BIT(GPIOF_OSPEEDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_OUTPUT_PUSH_PULL_MEDIUM_FREQ)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			CLR_BIT(GPIOA_OTYPER,PinId);

			SET_BIT(GPIOA_OSPEEDR,PinId*2);
			CLR_BIT(GPIOA_OSPEEDR,((PinId*2)+1));
			break;
		case PORTB:
			SET_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			CLR_BIT(GPIOB_OTYPER,PinId);

			SET_BIT(GPIOB_OSPEEDR,PinId*2);
			CLR_BIT(GPIOB_OSPEEDR,((PinId*2)+1));
			break;
		case PORTC:
			SET_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			CLR_BIT(GPIOC_OTYPER,PinId);

			SET_BIT(GPIOC_OSPEEDR,PinId*2);
			CLR_BIT(GPIOC_OSPEEDR,((PinId*2)+1));
			break;
		case PORTD:
			SET_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			CLR_BIT(GPIOD_OTYPER,PinId);

			SET_BIT(GPIOD_OSPEEDR,PinId*2);
			CLR_BIT(GPIOD_OSPEEDR,((PinId*2)+1));
			break;
		case PORTF:
			SET_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			CLR_BIT(GPIOF_OTYPER,PinId);

			SET_BIT(GPIOF_OSPEEDR,PinId*2);
			CLR_BIT(GPIOF_OSPEEDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_OUTPUT_PUSH_PULL_LOW_FREQ)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			CLR_BIT(GPIOA_OTYPER,PinId);

			CLR_BIT(GPIOA_OSPEEDR,PinId*2);
			CLR_BIT(GPIOA_OSPEEDR,((PinId*2)+1));
			break;
		case PORTB:
			SET_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			CLR_BIT(GPIOB_OTYPER,PinId);

			CLR_BIT(GPIOB_OSPEEDR,PinId*2);
			CLR_BIT(GPIOB_OSPEEDR,((PinId*2)+1));
			break;
		case PORTC:
			SET_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			CLR_BIT(GPIOC_OTYPER,PinId);

			CLR_BIT(GPIOC_OSPEEDR,PinId*2);
			CLR_BIT(GPIOC_OSPEEDR,((PinId*2)+1));
			break;
		case PORTD:
			SET_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			CLR_BIT(GPIOD_OTYPER,PinId);

			CLR_BIT(GPIOD_OSPEEDR,PinId*2);
			CLR_BIT(GPIOD_OSPEEDR,((PinId*2)+1));
			break;
		case PORTF:
			SET_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			CLR_BIT(GPIOF_OTYPER,PinId);

			CLR_BIT(GPIOF_OSPEEDR,PinId*2);
			CLR_BIT(GPIOF_OSPEEDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_OUPTUT_OPEN_DRAIN_LOW_FREQ)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			SET_BIT(GPIOA_OTYPER,PinId);

			CLR_BIT(GPIOA_OSPEEDR,PinId*2);
			CLR_BIT(GPIOA_OSPEEDR,((PinId*2)+1));
			break;
		case PORTB:
			SET_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			SET_BIT(GPIOB_OTYPER,PinId);

			CLR_BIT(GPIOB_OSPEEDR,PinId*2);
			CLR_BIT(GPIOB_OSPEEDR,((PinId*2)+1));
			break;
		case PORTC:
			SET_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			SET_BIT(GPIOC_OTYPER,PinId);

			CLR_BIT(GPIOC_OSPEEDR,PinId*2);
			CLR_BIT(GPIOC_OSPEEDR,((PinId*2)+1));
			break;
		case PORTD:
			SET_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			SET_BIT(GPIOD_OTYPER,PinId);

			CLR_BIT(GPIOD_OSPEEDR,PinId*2);
			CLR_BIT(GPIOD_OSPEEDR,((PinId*2)+1));
			break;
		case PORTF:
			SET_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			SET_BIT(GPIOF_OTYPER,PinId);

			CLR_BIT(GPIOF_OSPEEDR,PinId*2);
			CLR_BIT(GPIOF_OSPEEDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_OUPTUT_OPEN_DRAIN_MEDIUM_FREQ)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			SET_BIT(GPIOA_OTYPER,PinId);

			SET_BIT(GPIOA_OSPEEDR,PinId*2);
			CLR_BIT(GPIOA_OSPEEDR,((PinId*2)+1));
			break;
		case PORTB:
			SET_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			SET_BIT(GPIOB_OTYPER,PinId);

			SET_BIT(GPIOB_OSPEEDR,PinId*2);
			CLR_BIT(GPIOB_OSPEEDR,((PinId*2)+1));
			break;
		case PORTC:
			SET_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			SET_BIT(GPIOC_OTYPER,PinId);

			SET_BIT(GPIOC_OSPEEDR,PinId*2);
			CLR_BIT(GPIOC_OSPEEDR,((PinId*2)+1));
			break;
		case PORTD:
			SET_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			SET_BIT(GPIOD_OTYPER,PinId);

			SET_BIT(GPIOD_OSPEEDR,PinId*2);
			CLR_BIT(GPIOD_OSPEEDR,((PinId*2)+1));
			break;
		case PORTF:
			SET_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			SET_BIT(GPIOF_OTYPER,PinId);

			SET_BIT(GPIOF_OSPEEDR,PinId*2);
			CLR_BIT(GPIOF_OSPEEDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_OUPTUT_OPEN_DRAIN_HIGH_FREQ)
	{
		switch(PortId)
		{
		case PORTA:
			SET_BIT(GPIOA_MODER,PinId*2);
			CLR_BIT(GPIOA_MODER,((PinId*2)+1));

			SET_BIT(GPIOA_OTYPER,PinId);

			SET_BIT(GPIOA_OSPEEDR,PinId*2);
			SET_BIT(GPIOA_OSPEEDR,((PinId*2)+1));
			break;
		case PORTB:
			SET_BIT(GPIOB_MODER,PinId*2);
			CLR_BIT(GPIOB_MODER,((PinId*2)+1));

			SET_BIT(GPIOB_OTYPER,PinId);

			SET_BIT(GPIOB_OSPEEDR,PinId*2);
			SET_BIT(GPIOB_OSPEEDR,((PinId*2)+1));
			break;
		case PORTC:
			SET_BIT(GPIOC_MODER,PinId*2);
			CLR_BIT(GPIOC_MODER,((PinId*2)+1));

			SET_BIT(GPIOC_OTYPER,PinId);

			SET_BIT(GPIOC_OSPEEDR,PinId*2);
			SET_BIT(GPIOC_OSPEEDR,((PinId*2)+1));
			break;
		case PORTD:
			SET_BIT(GPIOD_MODER,PinId*2);
			CLR_BIT(GPIOD_MODER,((PinId*2)+1));

			SET_BIT(GPIOD_OTYPER,PinId);

			SET_BIT(GPIOD_OSPEEDR,PinId*2);
			SET_BIT(GPIOD_OSPEEDR,((PinId*2)+1));
			break;
		case PORTF:
			SET_BIT(GPIOF_MODER,PinId*2);
			CLR_BIT(GPIOF_MODER,((PinId*2)+1));

			SET_BIT(GPIOF_OTYPER,PinId);

			SET_BIT(GPIOF_OSPEEDR,PinId*2);
			SET_BIT(GPIOF_OSPEEDR,((PinId*2)+1));
			break;
		}
	}else if(Direction == DIO_OUTPUT_ALTERNATIVE_PUSH_PULL)
	{
		switch(PortId)
		{
		case PORTA:
			CLR_BIT(GPIOA_MODER,PinId*2);
			SET_BIT(GPIOA_MODER,((PinId*2)+1));

			CLR_BIT(GPIOA_OTYPER,PinId);
			break;
		case PORTB:
			CLR_BIT(GPIOB_MODER,PinId*2);
			SET_BIT(GPIOB_MODER,((PinId*2)+1));

			CLR_BIT(GPIOB_OTYPER,PinId);
			break;
		case PORTC:
			CLR_BIT(GPIOC_MODER,PinId*2);
			SET_BIT(GPIOC_MODER,((PinId*2)+1));

			CLR_BIT(GPIOC_OTYPER,PinId);
			break;
		case PORTD:
			CLR_BIT(GPIOD_MODER,PinId*2);
			SET_BIT(GPIOD_MODER,((PinId*2)+1));

			CLR_BIT(GPIOD_OTYPER,PinId);
			break;
		case PORTF:
			CLR_BIT(GPIOF_MODER,PinId*2);
			SET_BIT(GPIOF_MODER,((PinId*2)+1));

			CLR_BIT(GPIOF_OTYPER,PinId);
			break;
		}
	}else if(Direction == DIO_OUTPUT_ALTERNATIVE_OPEN_DRAIN)
	{
		switch(PortId)
		{
		case PORTA:
			CLR_BIT(GPIOA_MODER,PinId*2);
			SET_BIT(GPIOA_MODER,((PinId*2)+1));

			SET_BIT(GPIOA_OTYPER,PinId);
			break;
		case PORTB:
			CLR_BIT(GPIOB_MODER,PinId*2);
			SET_BIT(GPIOB_MODER,((PinId*2)+1));

			SET_BIT(GPIOB_OTYPER,PinId);
			break;
		case PORTC:
			CLR_BIT(GPIOC_MODER,PinId*2);
			SET_BIT(GPIOC_MODER,((PinId*2)+1));

			SET_BIT(GPIOC_OTYPER,PinId);
			break;
		case PORTD:
			CLR_BIT(GPIOD_MODER,PinId*2);
			SET_BIT(GPIOD_MODER,((PinId*2)+1));

			SET_BIT(GPIOD_OTYPER,PinId);
			break;
		case PORTF:
			CLR_BIT(GPIOF_MODER,PinId*2);
			SET_BIT(GPIOF_MODER,((PinId*2)+1));

			SET_BIT(GPIOF_OTYPER,PinId);
			break;

		}
	}
}
u8   DIO_u8GetPinValue(u8 PortId,u8 PinId)
{
	switch(PortId)
	{
	case PORTA:
		return GET_BIT(GPIOA_IDR,PinId);
		break;
	case PORTB:
		return GET_BIT(GPIOB_IDR,PinId);
		break;
	case PORTC:
		return GET_BIT(GPIOC_IDR,PinId);
		break;
	case PORTD:
		return GET_BIT(GPIOD_IDR,PinId);
		break;
	case PORTF:
		return GET_BIT(GPIOF_IDR,PinId);
		break;


	}
}
void DIO_voidSetPortValue(u8 Copy_PortX, u8 Copy_value)
{

	switch(Copy_PortX)
	{
	case PORTA:
		GPIOA_ODR = Copy_value;
		break;
	case PORTB:
		GPIOB_ODR = Copy_value;
		break;
	case PORTC:
		GPIOC_ODR = Copy_value;
		break;
	case PORTD:
		GPIOD_ODR = Copy_value;
		break;
	case PORTF:
		GPIOF_ODR = Copy_value;
		break;
	}


}
void DIO_voidSetPortDirection(u8 Copy_PortX, u32 Copy_Direction)
{

	switch(Copy_PortX)
	{
	case PORTA:
		GPIOA_MODER = Copy_Direction;
		break;
	case PORTB:
		GPIOB_MODER = Copy_Direction;
		break;
	case PORTC:
		GPIOC_MODER = Copy_Direction;
		break;
	case PORTD:
		GPIOD_MODER = Copy_Direction;
		break;
	case PORTF:
		GPIOF_MODER = Copy_Direction;
		break;
	}


}
