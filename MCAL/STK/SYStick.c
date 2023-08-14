#include "typedef.h"
#include "bitMath.h"
#include "SYSTICK_priv.h"
#include "SYSTICK.h"
#include "SYSTICK_config.h"

systickcbf_t APPcbf ;

void SYSTICK_Init (void)
{
	// clk src and int enable
#if SYSTICK_CLK_SRC == SYSTICK_CLK_AHB_DIV_8
	CLR_BIT(STK_CTRL,2);

#elif SYSTICK_CLK_SRC == SYSTICK_CLK_AHB
	SET_BIT(STK_CTRL,2);
#endif

#if SYSTICK_TICK_INT == SYSTICK_TICK_INT_ENABLE
	SET_BIT(STK_CTRL,1);

#elif SYSTICK_TICK_INT == SYSTICK_TICK_INT_DISABLE
	CLR_BIT(STK_CTRL,1);
#endif

}
void SYSTICK_Start (void)
{
	//systick enable
	SET_BIT(STK_CTRL,0);
}
void SYSTICK_Stop (void)
{
	//systick disable
	CLR_BIT(STK_CTRL,0);
}
void SYSTICK_SetCallback (systickcbf_t cbf)
{
	//setcallback
	APPcbf = cbf;
}
void SYSTICK_SetTime (u32 timeus)
{
	// added value to systick load register based on equation 

	STK_LOAD = timeus;


}
void SysTick_Handler(void)
{
	// call function needed 
	APPcbf();
}
