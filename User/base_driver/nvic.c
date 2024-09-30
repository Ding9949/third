#include "nvic.h" 

 //系统软复位   
void sys_soft_reset(void)
{  
	 NVIC_SystemReset();	  
}    

 void nvic_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//设置NVIC中断分组2:2位抢占优先级，2位响应优先级
}



























