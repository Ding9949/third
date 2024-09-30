#include "sys_include.h"

#define PWM_OPEN_DLY 200
#define CUR_ZERO_LEARN_TIMES 1000L
#define POW_UP_DLY 10000L
#define BORD_INFO_DLY 1000L
#define RELAY_ON_DLY 1000L


void sys_power_up(void)
{
	//系统上电，零点学习 继电器控制 等任务
	static u32 isrticer = 0; //定义计数器，此任务退出后，需清零
	static u32 at_u1=0,at_u2=0;

	
	gSysCtlVal.Sts = STS_POWER_UP;



	if(isrticer == 0)
	{
		at_u1 = 0;
		at_u2 = 0;
		
	}else if(isrticer < PWM_OPEN_DLY){

	}else if(isrticer < (PWM_OPEN_DLY+CUR_ZERO_LEARN_TIMES) ){					
		at_u1 += gSysHard.AngU1;
		at_u2 += gSysHard.AngU2;
	}else if(isrticer == (PWM_OPEN_DLY+CUR_ZERO_LEARN_TIMES)){
		//零点计算
		gSysHard.AngOffSet_U1 = at_u1/1000.0f;
		gSysHard.AngOffSet_U2 = at_u2/1000.0f;

	}else 
	{
		isrticer = 0;
		Sys_Logic_Ptr = &sys_logic_wait;
		return;

	}

	isrticer++;
}
