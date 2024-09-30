#include "sys_include.h"

/******************************************************************************/
//定义系统中断计数器
IapMarkInfo_t IapMarkInfo;
//系统级宏定义
u16 ISR_FREQUENCY = SYS_ISR_PSC; 				// Define the ISR frequency (kHz)

/******************************************************************************/




void main_init(void)
{
	
	
}



void main_ticker(void)
{
	static u8 cnt = 0;
	static u16 LedTicker = 0;

	// 1ms
	cnt++;
	if(cnt >= SYS_ISR_PSC)
	{
		cnt =0;
		gSysCtlVal.Ticker++;
		E2PromWaitCnt++;	
		if(gDisCom.TxdDly)gDisCom.TxdDly--;
		if(gDisCom.RxdTicker)gDisCom.RxdTicker--;
		if(gQsCom.TxdDly)gQsCom.TxdDly--;
		if(gQsCom.RxdTicker)gQsCom.RxdTicker--;
		if(gDisCom.ParTransDlyCnt )	gDisCom.ParTransDlyCnt --;
		
		gVfdCom.TaskTicker ++;
		if(gVfdCom.RxdFrameTicker < 20)gVfdCom.RxdFrameTicker++;
		else 
		{
			if(gVfdCom.RxdIndex >=4)
			{
				gVfdCom.RxdFlag = 1;
				gVfdCom.RxdLen = gVfdCom.RxdIndex;
				gVfdCom.RxdIndex = 0;
			}
		}
		
		LedTicker++;
		if(LedTicker >= 500)
		{
			LedTicker = 0;
			gSysHard.Led = !gSysHard.Led;

		}

	}

	
}


// 100us
void main_isr(void)
{
	static u8 psr = 0;

	//RUN_OUT(1);
	/*******************************************************************************/
	main_ticker();		//系统计时器使用
	/*******************************************************************************/
	
	/*******************************************************************************/
	sys_hard_read_port();			//读取硬件接口数据值到相关的寄存器
	/*******************************************************************************/

	/*******************************************************************************/
	sys_logic_main();
	/*******************************************************************************/

	/*******************************************************************************/
	// 500us
	if(psr == 0)
		can1_task();
	else if(psr == 1)
		can2_task();
	else if(psr == 2)
		dis_com_task();
	else if(psr == 3)
		qs_com_task();
	else if(psr == 4)
		vfd_com_task();	
	psr ++;if(psr>=5)psr = 0;
	/*******************************************************************************/
	
	/*******************************************************************************/
	sys_hard_load_port();			//加载系统变量到相应的硬件接口
	/*******************************************************************************/

	//RUN_OUT(0);
}


void main_task(void)
{
	main_init();
	drv_timer_init();
	drv_ang_init();
	drv_io_init();
	drv_eprom_init();
	drv_sci_init();

	sys_hard_init();
	sys_err_init();


	drv_can_init();

	can_task_init();
	dis_com_init();
	qs_com_init();
	vfd_com_init();

	data_init();

	roller_speed_init();

	sys_task_init();
	Sys_Logic_Ptr= &sys_power_up; 

	
	PWM_TIMER_EN();

	while(1)
	{
		
		
		/*******************************************************************************/
		sys_task();				// 系统控制程序入口
		/*******************************************************************************/
		{
		#if 0
		CanTxMsg Tx;
		static u32 cnt = 0;
		static u16 kkk = 0;

		cnt ++;
		if(cnt > 5000000)
		{
			 cnt = 0;
			kkk++;
			Tx.ExtId = 1;
			Tx.IDE = CAN_Id_Extended;
			Tx.RTR = 0;
			Tx.DLC = 8;
			Tx.Data[7] = Tx.Data[6];
			Tx.Data[6] = Tx.Data[5];
			Tx.Data[5] = Tx.Data[4];
			Tx.Data[4] = Tx.Data[3];
			Tx.Data[3] = Tx.Data[2];
			Tx.Data[2] = Tx.Data[1];
			Tx.Data[1] = Tx.Data[0];
			Tx.Data[0] = kkk;
			can_send_msg(&Tx);
		}
		#endif
		}

	}
}
