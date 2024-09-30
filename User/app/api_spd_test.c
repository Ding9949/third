#include "sys_include.h"


void drv_hall_roller_init(void)
{
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;	
	TIM_ICInitTypeDef  TIM_ICInitStructure;      	
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef	EXTI_InitStructure;

	gpio_config(PC9, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(PA8, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(PA15, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(PD12, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);

	

	
	EXTI_InitStructure.EXTI_Line = EXTI_Line9;//PlLS1  PC9
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = EXTI_Line8;//PlLS2 PA8
	EXTI_Init(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = EXTI_Line15;//PlLS3 PA15
	EXTI_Init(&EXTI_InitStructure);
	EXTI_InitStructure.EXTI_Line = EXTI_Line12;//PlLS4 PD12
	EXTI_Init(&EXTI_InitStructure);
	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);//Ê¹ÄÜSYSCFGÊ±ÖÓ
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOG, EXTI_PinSource13);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOG, EXTI_PinSource14);
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9, ENABLE);
	TIM_TimeBaseStructure.TIM_Prescaler = (CKTIM/1000000)-1;				   // 1M
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period =65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM9,&TIM_TimeBaseStructure); 
	TIM_Cmd(TIM9, ENABLE);


	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
	TIM_TimeBaseStructure.TIM_Prescaler = (CKTIM/1000000)-1;				   // 1M
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period =65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM10,&TIM_TimeBaseStructure); 
	TIM_Cmd(TIM10, ENABLE);

	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;		
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;    
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		

}




void EXTI15_10_IRQHandler(void)
{
	// X0019
	if (EXTI_GetITStatus(EXTI_Line14) != RESET) 
	{
		EXTI_ClearITPendingBit(EXTI_Line14);
		//roller1_speed_isr();
	}
	
	// X001B
	if (EXTI_GetITStatus(EXTI_Line13) != RESET) 
	{
		EXTI_ClearITPendingBit(EXTI_Line13);
		//roller2_speed_isr();
	}
	
}
