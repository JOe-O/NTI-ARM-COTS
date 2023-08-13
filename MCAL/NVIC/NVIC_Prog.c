/*
 * NVIC_Prog.c
 *
 *  Created on: Aug 13, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "bitMath.h"



#include "NVIC_Private.h"
#include "NVIC_Config.h"
#include "NVIC_int.h"


void NVIC_voidInit(void)
{
#ifndef SCB_AIRCR
#define SCB_AIRCR		*((volatile u32 *)0xE000ED0C)     //0xE000ED0C
#endif

	SCB_AIRCR = NUM_OF_GRP_SUB; //configuration b #define fel private for example GRP_4_SUB_4
	//0x05FA0500
	//fel private #define NVIC_IPR0 (*(volatile u8*)(address))
	// NVIC_IPR		((volatile u8 *)address)
}
void NVIC_voidEnabeInterrupt(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ISER0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ISER1 = 1 << InterruptNum;
	}
}
void NVIC_voidDisableInterrupt(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ICER0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ICER1 = 1 << InterruptNum;
	}
}

void NVIC_voidSetPendingFlag(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ISPR0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ISPR1 = 1 << InterruptNum;
	}
}
void NVIC_voidClrPendingFlag(u8 InterruptNum)
{
	if(InterruptNum < 32)
	{
		NVIC_ICPR0 = 1 << InterruptNum;
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		NVIC_ICPR1 = 1 << InterruptNum;
	}
}

u8 NVIC_u8ReadActiveFlag(u8 InterruptNum)
{
	u8 Local_u8Acive = 0;
	if(InterruptNum < 32)
	{
		Local_u8Acive = GET_BIT(NVIC_IABR0,InterruptNum);
	}else if(InterruptNum < 64)
	{
		InterruptNum -= 32;
		Local_u8Acive = GET_BIT(NVIC_IABR1,InterruptNum);
	}
	return Local_u8Acive;
}

void NVIC_voidSetPriority(u8 InterruptNum,u8 priority)
{
	NVIC_IPR[InterruptNum] = (priority << 4);
}
