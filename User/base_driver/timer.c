#include "sys_bsp.h"
#include "timer.h"
#include "gpio.h"



BldcSpeed_t gRollerSpeed1;
BldcSpeed_t gRollerSpeed2;
BldcSpeed_t gRollerSpeed3;
BldcSpeed_t gRollerSpeed4;

void TIM8_Init(void)
{    
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	//---------------------------------------------------------------------------------------------------------------//
	// TIM8 Peripheral Configuration
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8, ENABLE);

	//
	TIM_DeInit(TIM8);
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	// Time Base configuration
	TIM_TimeBaseStructure.TIM_Prescaler = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_CenterAligned1;
	TIM_TimeBaseStructure.TIM_Period = PWM_PERIOD;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	// Initial condition is REP=0 to set the UPDATE only on the underflow
	TIM_TimeBaseStructure.TIM_RepetitionCounter = REP_RATE;
	TIM_TimeBaseInit(TIM8, &TIM_TimeBaseStructure);

	

	TIM_ITConfig(TIM8, TIM_IT_Update, ENABLE);      //开定时器中断 

	TIM_ClearITPendingBit(TIM8,TIM_IT_Update);	

	
	TIM_Cmd(TIM8, DISABLE);		// counter enable

	NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_TIM13_IRQn;		
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;    
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		

}


void PLS01_Init(void)
{
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure;      	
	NVIC_InitTypeDef NVIC_InitStructure;

	gpio_config(PLS01_PORT, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, PLS01_GPIO_AF);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	//
	TIM_DeInit(PLS01_TIM);
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	// Time Base configuration
	TIM_TimeBaseStructure.TIM_Prescaler = PLS01_PRESC;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = REP_RATE; // Initial condition is REP=0 to set the UPDATE only on the underflow
	TIM_TimeBaseInit(PLS01_TIM, &TIM_TimeBaseStructure);
	TIM_ICInitStructure.TIM_Channel = PLS01_CHx;            //选择通道1
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; //输入上升沿捕获  
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;  //配置通道为输入，并映射到哪里
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;       //输入捕获预分频值
	TIM_ICInitStructure.TIM_ICFilter = 15;                      //输入滤波器带宽设置
	TIM_ICInit(PLS01_TIM, &TIM_ICInitStructure);
	

	TIM_ITConfig(PLS01_TIM, PLS01_TIM_IT_CCx, ENABLE);      //开定时器中断 
	TIM_Cmd(PLS01_TIM,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = PLS01_IRQn;		//?aTIM3?D??
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;    
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		


}

void PLS02_Init(void)
{
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure;      	
	NVIC_InitTypeDef NVIC_InitStructure;

	
	gpio_config(PLS02_PORT, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, PLS02_GPIO_AF);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	//
	TIM_DeInit(PLS02_TIM);
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	// Time Base configuration
	TIM_TimeBaseStructure.TIM_Prescaler = PLS02_PRESC;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = REP_RATE; // Initial condition is REP=0 to set the UPDATE only on the underflow
	TIM_TimeBaseInit(PLS02_TIM, &TIM_TimeBaseStructure);
	TIM_ICInitStructure.TIM_Channel = PLS02_CHx;            //选择通道1
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; //输入上升沿捕获  
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;  //配置通道为输入，并映射到哪里
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;       //输入捕获预分频值
	TIM_ICInitStructure.TIM_ICFilter = 15;                      //输入滤波器带宽设置
	TIM_ICInit(PLS02_TIM, &TIM_ICInitStructure);
	

	TIM_ITConfig(PLS02_TIM, PLS02_TIM_IT_CCx, ENABLE);      //开定时器中断 
	TIM_Cmd(PLS02_TIM,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = PLS02_IRQn;		//?aTIM3?D??
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;    
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		


}

void PLS03_Init(void)
{
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure;      	
	NVIC_InitTypeDef NVIC_InitStructure;

	gpio_config(PLS03_PORT, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, PLS03_GPIO_AF);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	//
	TIM_DeInit(PLS03_TIM);
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	// Time Base configuration
	TIM_TimeBaseStructure.TIM_Prescaler = PLS03_PRESC;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = REP_RATE; // Initial condition is REP=0 to set the UPDATE only on the underflow
	TIM_TimeBaseInit(PLS03_TIM, &TIM_TimeBaseStructure);
	TIM_ICInitStructure.TIM_Channel = PLS03_CHx;            //选择通道1
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; //输入上升沿捕获  
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;  //配置通道为输入，并映射到哪里
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;       //输入捕获预分频值
	TIM_ICInitStructure.TIM_ICFilter = 15;                      //输入滤波器带宽设置
	TIM_ICInit(PLS03_TIM, &TIM_ICInitStructure);
	

	TIM_ITConfig(PLS03_TIM, PLS03_TIM_IT_CCx, ENABLE);      //开定时器中断 
	TIM_Cmd(PLS03_TIM,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = PLS03_IRQn;		//?aTIM3?D??
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;    
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		


}

void PLS04_Init(void)
{
	TIM_TimeBaseInitTypeDef	TIM_TimeBaseStructure;
	TIM_ICInitTypeDef  TIM_ICInitStructure;      	
	NVIC_InitTypeDef NVIC_InitStructure;

	gpio_config(PLS04_PORT, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, PLS04_GPIO_AF);


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	//
	TIM_DeInit(PLS04_TIM);
	TIM_TimeBaseStructInit(&TIM_TimeBaseStructure);
	// Time Base configuration
	TIM_TimeBaseStructure.TIM_Prescaler = PLS04_PRESC;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 65535;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = REP_RATE; // Initial condition is REP=0 to set the UPDATE only on the underflow
	TIM_TimeBaseInit(PLS04_TIM, &TIM_TimeBaseStructure);
	TIM_ICInitStructure.TIM_Channel = PLS04_CHx;            //选择通道1
	TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; //输入上升沿捕获  
	TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;  //配置通道为输入，并映射到哪里
	TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;       //输入捕获预分频值
	TIM_ICInitStructure.TIM_ICFilter = 15;                      //输入滤波器带宽设置
	TIM_ICInit(PLS04_TIM, &TIM_ICInitStructure);
	

	TIM_ITConfig(PLS04_TIM, PLS04_TIM_IT_CCx, ENABLE);      //开定时器中断 
	TIM_Cmd(PLS04_TIM,ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = PLS04_IRQn;		//?aTIM3?D??
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;    
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		


}

void drv_timer_init(void)
{
	TIM8_Init();
}




void roller_speed_init(void)
{	

	memset(&gRollerSpeed1, 0, sizeof(BldcSpeed_t));
	gRollerSpeed1.Kspd = ROLLER_SPEED_BASEFRE*60*10;
	gRollerSpeed1.TimPrd = 65536;
	gRollerSpeed1.Poles = 2;

	memset(&gRollerSpeed2, 0, sizeof(BldcSpeed_t));
	gRollerSpeed2.Kspd = ROLLER_SPEED_BASEFRE1*60*10;
	gRollerSpeed2.TimPrd = 65536;
	gRollerSpeed2.Poles = 2;
	
	memset(&gRollerSpeed3, 0, sizeof(BldcSpeed_t));
	gRollerSpeed3.Kspd = ROLLER_SPEED_BASEFRE*60*10;
	gRollerSpeed3.TimPrd = 65536;
	gRollerSpeed3.Poles = 2;	

	memset(&gRollerSpeed4, 0, sizeof(BldcSpeed_t));
	gRollerSpeed4.Kspd = ROLLER_SPEED_BASEFRE*60*10;
	gRollerSpeed4.TimPrd = 65536;
	gRollerSpeed4.Poles = 2;

	
	PLS01_Init();
	PLS02_Init();
	PLS03_Init();
	PLS04_Init();

}


// PLS01
void roller1_speed_isr(void)
{
	u32 TimCur = 0;
	u32 Spd = 0;
	static u8 step = 0;
	
	gRollerSpeed1.TimCur = PLS01_TIM->CNT;
	PLS01_TIM->CNT = 0;
	
	
	if(gRollerSpeed1.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed1.CheckCnt = 0;	
		gRollerSpeed1.TimPrd = 0;
		step = 0;
		return;
	}
	
	
	if(gRollerSpeed1.TimCur < 200)
	{
		gRollerSpeed1.CheckCnt = 0;
		return;
	}
	
	

	gRollerSpeed1.CheckCnt = 0;


	gRollerSpeed1.TimPrd += gRollerSpeed1.TimCur;

	step++;
	if(step ==gRollerSpeed1.Poles)
	{
		step =0;		
		gRollerSpeed1.Spd  = (u16)(gRollerSpeed1.Kspd/gRollerSpeed1.TimPrd);
		gRollerSpeed1.TimPrd = 0;

	}
}


// PLS02
void roller2_speed_isr(void)
{
	u32 TimCur = 0;
	u32 Spd = 0;
	static u8 step = 0;
	
	gRollerSpeed2.TimCur = TIM_GetCounter(PLS02_TIM);
	PLS02_TIM->CNT = 0;
	
	
	if(gRollerSpeed2.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed2.CheckCnt = 0;	
		gRollerSpeed2.TimPrd = 0;
		step = 0;
		return;
	}
		
	
	if(gRollerSpeed2.TimCur < 200)
	{
		gRollerSpeed2.CheckCnt = 0;
		return;
	}
	
	

	gRollerSpeed2.CheckCnt = 0;


	gRollerSpeed2.TimPrd += gRollerSpeed2.TimCur;

	step++;
	if(step ==gRollerSpeed2.Poles)
	{
		step =0;		
		gRollerSpeed2.Spd  = (u16)(gRollerSpeed2.Kspd/gRollerSpeed2.TimPrd);
		gRollerSpeed2.TimPrd = 0;
	}
}


// PLS03
void roller3_speed_isr(void)
{
	u32 TimCur = 0;
	u32 Spd = 0;
	static u8 step = 0;
	
	gRollerSpeed3.TimCur = TIM_GetCounter(PLS03_TIM);
	PLS03_TIM->CNT = 0;
	
	
	if(gRollerSpeed3.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed3.CheckCnt = 0;	
		gRollerSpeed3.TimPrd = 0;
		step = 0;
		return;
	}
		
	
	if(gRollerSpeed3.TimCur < 200)
	{
		gRollerSpeed3.CheckCnt = 0;
		return;
	}
	
	

	gRollerSpeed3.CheckCnt = 0;


	gRollerSpeed3.TimPrd += gRollerSpeed3.TimCur;

	step++;
	if(step ==gRollerSpeed3.Poles)
	{
		step =0;		
		gRollerSpeed3.Spd  = (u16)(gRollerSpeed3.Kspd/gRollerSpeed3.TimPrd);
		gRollerSpeed3.TimPrd = 0;
	}
}

// PLS04
void roller4_speed_isr(void)
{
	u32 TimCur = 0;
	u32 Spd = 0;
	static u8 step = 0;
	
	gRollerSpeed4.TimCur = TIM_GetCounter(PLS04_TIM);
	PLS04_TIM->CNT = 0;
	
	
	if(gRollerSpeed4.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed4.CheckCnt = 0;	
		gRollerSpeed4.TimPrd = 0;
		step = 0;
		return;
	}
		
	
	if(gRollerSpeed4.TimCur < 200)
	{
		gRollerSpeed4.CheckCnt = 0;
		return;
	}
	
	

	gRollerSpeed4.CheckCnt = 0;


	gRollerSpeed4.TimPrd += gRollerSpeed4.TimCur;

	step++;
	if(step ==gRollerSpeed4.Poles)
	{
		step =0;		
		gRollerSpeed4.Spd  = (u16)(gRollerSpeed4.Kspd/gRollerSpeed4.TimPrd);
		gRollerSpeed4.TimPrd = 0;
	}
}


