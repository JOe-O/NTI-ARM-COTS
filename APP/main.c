
#include "typedef.h"
#include "bitMath.h"

#include "RCC_int.h"

#include "DIO_int.h"
#include "DIO_Priv.h"
//#include "LCD_int.h"
#include "NVIC_int.h"

#include "EXTI_Private.h"
#include "EXTI_int.h"

#include "SYSTICK.h"

void _delay_ms(u32 ticks)
{
	u32 i;
	for(i=0;i<(ticks*500);i++)
	{
		asm("NOP");

	}
}


void EXTI0_IRQHandler()
{

	DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_HIGH);
	_delay_ms(5000);

	NVIC_voidSetPendingFlag(7);

	DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_HIGH);
	_delay_ms(5000);

	NVIC_voidClrPendingFlag(6);

}
void EXTI1_IRQHandler()
{

	DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_LOW);
	_delay_ms(5000);

	NVIC_voidClrPendingFlag(7);

}

void EXTI15_10_IRQHandler()
{
	DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_LOW);

	_delay_ms(2000);
	DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_HIGH);
	_delay_ms(2000);

	EXTI_voidDisableEXTI();

}
void ISR()
{
	//if(DIO_u8GetPinValue(PORTA, 5) == 0)
	//{
	//DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_HIGH);
	//_delay_ms(2000);
	//}else if(DIO_u8GetPinValue(PORTA, 5) == 1)
	//{
	//	DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_LOW);
	//	_delay_ms(2000);
	//}
//	SYSTICK_Stop();

	TGL_BIT(GPIOA_ODR,5);
	/*_delay_ms(2000);
	TGL_BIT(GPIOA_ODR,5);
	_delay_ms(2000);*///



}
int main(void)
{
	/*RCC
	 * GPIO_RCC
	 * GPIO_Direction
	 *
	 * NVIC_voidInit()
	 * NVIC_voidEnableInterrupt(6)
	 * NVIC_voidSetPriority(6,0b0111) //group1(01) sub 3(11)
	 * NVIC_voidSetPendingFlag(6);
	 *
	 * NVIC_voidEnableInterrupt(7)
	 * NVIC_voidSetPriority(7,0b0011) //group0(00) sub 3(11)
	 * NVIC_voidSetPendingFlag(7);
	 * */
	RCC_voidInit();
	RCC_voidPerepheralEN(AHBENR, 17);//port A enable
	RCC_voidPerepheralEN(AHBENR, 19);//port C enable
	RCC_voidPerepheralEN(APB2ENR,0); //sysconfig enable
	//LCD_voidInit();
	//NVIC_voidInit();
	SYSTICK_SetCallback(ISR);
	SYSTICK_Init();
	SYSTICK_SetTime(2000000);
	SYSTICK_Start();
	//EXTI_voidInit();
	//EXTI_voidEnableLine();
	//EXTI_voidSenseMode();

	//NVIC_voidEnabeInterrupt(40);
	//NVIC_voidSetPriority(6,0b0111);



	//NVIC_voidEnabeInterrupt(7);
	//NVIC_voidSetPriority(7,0b0011);

	DIO_voidSetPinDirection(PORTA, DIO_PIN5, DIO_OUTPUT_PUSH_PULL_LOW_FREQ);
	DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_LOW);


	//NVIC_voidSetPendingFlag(6);

	//SET_BIT(PORTA_MODE,10);
	//CLR_BIT(PORTA_MODE,11);
	//DIO_voidSetPinDirection(PORTC, DIO_PIN13, DIO_INPUT);
	//DIO_voidSetPinDirection(PORTA, DIO_PIN5, DIO_OUTPUT_PUSH_PULL_LOW_FREQ);
	//DIO_voidSetPinDirection(PORTA, DIO_PIN0, DIO_OUTPUT_PUSH_PULL_LOW_FREQ);
	//DIO_voidSetPinDirection(PORTC, DIO_PIN10, DIO_OUTPUT_PUSH_PULL_LOW_FREQ);


	//DIO_voidSetPinDirection(PORTC, DIO_PIN10, DIO_INPUT);

	//SET_BIT(GPIOx_ODR,5);
	//DIO_voidSetPinValue(PORTA, DIO_PIN0, DIO_HIGH);

	while(1)
	{
		//LCD_voidGoTo(0,0);
		//LCD_voidWriteString("hi");
		//_delay_ms(500);
		//		if(DIO_u8GetPinValue(PORTC, DIO_PIN13) == 0)
		//		{
		//			DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_HIGH);
		//			DIO_voidSetPinValue(PORTC, DIO_PIN10, DIO_HIGH);
		//
		//
		//		}else
		//		{
		//			DIO_voidSetPinValue(PORTA, DIO_PIN5, DIO_LOW);
		//			DIO_voidSetPinValue(PORTC, DIO_PIN10, DIO_LOW);
		//
		//		}
	}
}
