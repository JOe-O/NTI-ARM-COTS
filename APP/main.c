
#include "typedef.h"
#include "bitMath.h"

//#define PORTA_MODE         *((volatile u32 *)(0x48000000))
//#define GPIOx_ODR          *((volatile u32 *)(0x48000014))

#include "RCC_int.h"

#include "DIO_int.h"
//#include "LCD_int.h"
#include "NVIC_int.h"


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
void _delay_ms(u32 ticks)
{
	u32 i;
	for(i=0;i<(ticks*500);i++)
	{
		asm("NOP");

	}
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
	//LCD_voidInit();
	NVIC_voidInit();

	NVIC_voidEnabeInterrupt(6);
	NVIC_voidSetPriority(6,0b0111);

	NVIC_voidEnabeInterrupt(7);
	NVIC_voidSetPriority(7,0b0011);

	DIO_voidSetPinDirection(PORTA, DIO_PIN5, DIO_OUTPUT_PUSH_PULL_LOW_FREQ);

	NVIC_voidSetPendingFlag(6);

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
