#include "sys_include.h"


void sys_task_init(void)
{
	int i = 0;
	memset(&gSysCtlVal, 0 , sizeof(SysCtlVal_t));

	for(i=0;i<MAX_REQUEST_NUM;i++)
	{
		memset(&request_ad[i], 0 , sizeof(request_t));
		memset(&request_jn[i], 0 , sizeof(request_t));
	}

	request_list_init(&request_list_ad, 0);
	request_list_init(&request_list_jn, 1);


	can_buffer_init();
}



void sys_task(void)
{

	//10ms 
	if(gSysCtlVal.Ticker >= 10)
		gSysCtlVal.Ticker-=10;
	else
		return;

	//更新状态量
	data_upate_status();	
	//故障处理
	//gSysErr.ErrId = sys_err_get_id();
}


