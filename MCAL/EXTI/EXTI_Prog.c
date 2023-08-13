/*
 * EXTI_Prog.c
 *
 *  Created on: Aug 13, 2023
 *      Author: ART
 */

#include "typedef.h"
#include "bitMath.h"

#include "EXTI_int.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"






void EXTI_voidInit(void)
{
#ifndef SYSCFG_EXTIC4
#define SYSCFG_EXTIC4	*((volatile u32 *)0x40010014)
#endif

#if INT_EXTI_PORT == INT_EXTI_PORTC

	//enable port c for our selected line
	SYSCFG_EXTIC4 = ((0b0010) << 4);

#elif INT_EXTI_PORT == INT_EXTI_PORTA

#endif


}
void EXTI_voidSenseMode(u8 EXTI_id,u8 EXTI_mode)
{

}
void EXTI_voidEnable(void)
{
	EXTI -> IMR1 = 1 << LINE;
}
