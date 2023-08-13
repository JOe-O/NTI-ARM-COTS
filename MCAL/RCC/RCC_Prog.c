/*
 * RCC_Prog.c
 *
 *  Created on: Aug 11, 2023
 *      Author: JOe
 */


#include "typedef.h"
#include "bitMath.h"



#include "RCC_int.h"
#include "RCC_Priv.h"



void RCC_voidInit()
{
	//HSI enable
	//RCC_CR->Bits.BIT_0 = 1;
	SET_BIT(RCC_CR,0);

	//HSI as selected clock
	//RCC_CFGR->Bits.BIT_0 = 0;
	CLR_BIT(RCC_CFGR,0);
	//RCC_CFGR->Bits.BIT_1 = 0;
	CLR_BIT(RCC_CFGR,1);
}
void RCC_voidPerepheralEN(u8 BusID,u8 PeripheralID)
{
	switch(BusID)
	{
	case AHBENR:
		SET_BIT(RCC_AHBENR,PeripheralID);
		break;
	case APB1ENR:
		SET_BIT(RCC_APB1ENR,PeripheralID);
		break;
	case APB2ENR:
		SET_BIT(RCC_APB2ENR,PeripheralID);
		break;

	}
}
void RCC_voidPerepheralDis(u8 BusID,u8 PeripheralID)
{
	switch(BusID)
	{
	case AHBENR:
		CLR_BIT(RCC_AHBENR,PeripheralID);
		break;
	case APB1ENR:
		CLR_BIT(RCC_APB1ENR,PeripheralID);
		break;
	case APB2ENR:
		CLR_BIT(RCC_APB2ENR,PeripheralID);
		break;

	}
}
