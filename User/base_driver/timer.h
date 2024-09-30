#ifndef __TIMER_H
#define __TIMER_H

#include "stm32f4xx.h"


#define ROLLER_SPEED_BASEFRE 10000
#define ROLLER_SPEED_BASEFRE1 100000

#define PLS01_TIM TIM3
#define PLS01_PRESC	8399 // 83->1M   839->100K   8399 ->10K
#define PLS01_CHx TIM_Channel_4
#define PLS01_TIM_IT_CCx TIM_IT_CC4
#define PLS01_IRQn TIM3_IRQn
#define PLS01_GPIO_AF GPIO_AF_TIM3
#define PLS01_PORT PC9//TIM3 CH4
#define PLS01_VAL ((PORTin(PLS01_PORT)==0)?1:0)


#define PLS02_TIM TIM1
#define PLS02_PRESC	1679 // 167->1M   1679->100K   16799 ->10K
#define PLS02_CHx TIM_Channel_1
#define PLS02_TIM_IT_CCx TIM_IT_CC1
#define PLS02_IRQn TIM1_CC_IRQn
#define PLS02_GPIO_AF GPIO_AF_TIM1
#define PLS02_PORT PA8//TIM1 CH1
#define PLS02_VAL ((PORTin(PLS02_PORT)==0)?1:0)

#define PLS03_TIM TIM2
#define PLS03_PRESC	8399 // 83->1M   839->100K   8399 ->10K
#define PLS03_CHx TIM_Channel_1
#define PLS03_TIM_IT_CCx TIM_IT_CC1
#define PLS03_IRQn TIM2_IRQn
#define PLS03_GPIO_AF GPIO_AF_TIM2
#define PLS03_PORT PA15//TIM2 CH1
#define PLS03_VAL ((PORTin(PLS03_PORT)==0)?1:0)
 
#define PLS04_TIM TIM4
#define PLS04_PRESC	8399 // 83->1M   839->100K   8399 ->10K
#define PLS04_CHx TIM_Channel_1
#define PLS04_TIM_IT_CCx TIM_IT_CC1
#define PLS04_IRQn TIM4_IRQn
#define PLS04_GPIO_AF GPIO_AF_TIM4
#define PLS04_PORT PD12   //TIM4 CH1
#define PLS04_VAL ((PORTin(PLS04_PORT)==0)?1:0)





#define PWM_TIMER_EN()	{TIM_Cmd(TIM8,ENABLE);}



typedef struct _BldcSpeed_s
{
	u16 Index;
	u16 IsrTicker;
	u16 CheckCnt;
	u32 TimPrd;
	u32 AvgPrd;
	u32 TimCur;
	u32 Kspd;//转速换算系数,每分钟计数器的计数值
	u32 PrdAddRes;
	u16 Spd;//0.1rpm
	u8 Poles;
	u8 Mode;
}BldcSpeed_t;


extern BldcSpeed_t gRollerSpeed1;
extern BldcSpeed_t gRollerSpeed2;
extern BldcSpeed_t gRollerSpeed3;
extern BldcSpeed_t gRollerSpeed4;

void roller_speed_init(void);
void roller1_speed_isr(void);
void roller2_speed_isr(void);
void roller3_speed_isr(void);
void roller4_speed_isr(void);


void drv_timer_init(void);

#endif























