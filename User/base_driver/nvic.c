#include "nvic.h" 

 //ϵͳ��λ   
void sys_soft_reset(void)
{  
	 NVIC_SystemReset();	  
}    

 void nvic_init(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
}



























