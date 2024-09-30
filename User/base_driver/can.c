#include <string.h>
#include "can.h"
#include "gpio.h"

u8 can1_send_mbox = CAN_TxStatus_NoMailBox;
u8 can2_send_mbox = CAN_TxStatus_NoMailBox;

//CAN初始化
//tsjw:重新同步跳跃时间单元.范围:1~3; CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
//tbs2:时间段2的时间单元.范围:1~8;
//tbs1:时间段1的时间单元.范围:1~16;	  CAN_BS1_1tq ~CAN_BS1_16tq
//brp :波特率分频器.范围:1~1024;(实际要加1,也就是1~1024) tq=(brp)*tpclk1
typedef struct _can_baudrate_s
{
	unsigned char tsjw;
	unsigned char tbs1;
	unsigned char tbs2;
	unsigned short brp;
}can_baudrate_t;

//波特率=Fpclk1/((tsjw+tbs1+tbs2)*brp);
//Fpclk1的时钟在初始化的时候设置为42M,如果设置CAN_SJW_1tq, CAN_BS1_6tq, CAN_BS2_7tq, 6;
//则波特率为:42M/((1+6+7)*6)=500Kbps
static void _get_baud_rate(unsigned char baudrate, can_baudrate_t* p)
{
	switch(baudrate)
	{
	case CAN_BAUDRATE_1M:
		p->tsjw = CAN_SJW_1tq;
		p->tbs1 = CAN_BS1_6tq;
		p->tbs2 = CAN_BS2_7tq;
		p->brp = 3;
		break;
	case CAN_BAUDRATE_800K: 
		p->tsjw = CAN_SJW_1tq;
		p->tbs1 = CAN_BS1_6tq;
		p->tbs2 = CAN_BS2_6tq;
		p->brp = 4;
		break;
	case CAN_BAUDRATE_500K: 
		p->tsjw = CAN_SJW_1tq;
		p->tbs1 = CAN_BS1_6tq;
		p->tbs2 = CAN_BS2_7tq;
		p->brp = 6;
		break;
	case CAN_BAUDRATE_250K: 
		p->tsjw = CAN_SJW_1tq;
		p->tbs1 = CAN_BS1_6tq;
		p->tbs2 = CAN_BS2_7tq;
		p->brp = 12;
		break;
	case CAN_BAUDRATE_100K: 
		p->tsjw = CAN_SJW_1tq;
		p->tbs1 = CAN_BS1_6tq;
		p->tbs2 = CAN_BS2_7tq;
		p->brp = 30;
		break;
	case CAN_BAUDRATE_10K: 
		p->tsjw = CAN_SJW_1tq;
		p->tbs1 = CAN_BS1_6tq;
		p->tbs2 = CAN_BS2_7tq;
		p->brp = 300;
		break;
	default:
		p->tsjw = CAN_SJW_1tq;
		p->tbs1 = CAN_BS1_6tq;
		p->tbs2 = CAN_BS2_7tq;
		p->brp = 6;
		break;
	}
}


//CAN初始化
u8 can1_conf(unsigned char baudrate)
{

	CAN_InitTypeDef        CAN_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	can_baudrate_t p;

	_get_baud_rate(baudrate, &p);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);//使能CAN1时钟	
	
	gpio_config(PD0, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN1);
	gpio_config(PD1, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN1);
	
	CAN_DeInit(CAN1);
	CAN_StructInit(&CAN_InitStructure);                /* 填充CAN参数结构体成员为缺省值 */
	//CAN单元设置
	CAN_InitStructure.CAN_TTCM=DISABLE;						 //非时间触发通信模式  //
	CAN_InitStructure.CAN_ABOM=ENABLE;						 //软件自动离线管理	 //
	CAN_InitStructure.CAN_AWUM=DISABLE;						 //睡眠模式通过软件唤醒(清除CAN->MCR的SLEEP位)//
	CAN_InitStructure.CAN_NART=DISABLE;						 	//禁止报文自动传送 //
	CAN_InitStructure.CAN_RFLM=DISABLE;						 //报文不锁定,新的覆盖旧的 // 
	CAN_InitStructure.CAN_TXFP=DISABLE;						 //优先级由报文标识符决定 //
	CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;	         //模式设置： mode:0,普通模式;1,回环模式; //
	//设置波特率
	CAN_InitStructure.CAN_SJW=p.tsjw;//重新同步跳跃宽度(Tsjw)为tsjw+1个时间单位  CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
	CAN_InitStructure.CAN_BS1=p.tbs1;//Tbs1=tbs1+1个时间单位CAN_BS1_1tq ~CAN_BS1_16tq
	CAN_InitStructure.CAN_BS2=p.tbs2;//Tbs2=tbs2+1个时间单位CAN_BS2_1tq ~	CAN_BS2_8tq
	CAN_InitStructure.CAN_Prescaler=p.brp;            //分频系数(Fdiv)为brp+1	//

	CAN_Init(CAN1, &CAN_InitStructure);            // 初始化CAN1 


	CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);//FIFO0消息挂号中断允许.		    
	NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     // 主优先级为1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;            // 次优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	return 0;
	
}   

u8 can2_conf(unsigned char baudrate)
{

	CAN_InitTypeDef        CAN_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	can_baudrate_t p;

	_get_baud_rate(baudrate, &p);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);//使能CAN2时钟	
	
	gpio_config(PB12, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN2);
	gpio_config(PB13, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN2);
	
	CAN_DeInit(CAN2);
	CAN_StructInit(&CAN_InitStructure);                /* 填充CAN参数结构体成员为缺省值 */
	//CAN单元设置
	CAN_InitStructure.CAN_TTCM=DISABLE;						 //非时间触发通信模式  //
	CAN_InitStructure.CAN_ABOM=ENABLE;						 //软件自动离线管理	 //
	CAN_InitStructure.CAN_AWUM=DISABLE;						 //睡眠模式通过软件唤醒(清除CAN->MCR的SLEEP位)//
	CAN_InitStructure.CAN_NART=DISABLE;						 	//禁止报文自动传送 //
	CAN_InitStructure.CAN_RFLM=DISABLE;						 //报文不锁定,新的覆盖旧的 // 
	CAN_InitStructure.CAN_TXFP=DISABLE;						 //优先级由报文标识符决定 //
	CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;	         //模式设置： mode:0,普通模式;1,回环模式; //
	//设置波特率
	CAN_InitStructure.CAN_SJW=p.tsjw;//重新同步跳跃宽度(Tsjw)为tsjw+1个时间单位  CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
	CAN_InitStructure.CAN_BS1=p.tbs1;//Tbs1=tbs1+1个时间单位CAN_BS1_1tq ~CAN_BS1_16tq
	CAN_InitStructure.CAN_BS2=p.tbs2;//Tbs2=tbs2+1个时间单位CAN_BS2_1tq ~	CAN_BS2_8tq
	CAN_InitStructure.CAN_Prescaler=p.brp;            //分频系数(Fdiv)为brp+1	//

	CAN_Init(CAN2, &CAN_InitStructure);            // 初始化CAN1 


	CAN_ITConfig(CAN2,CAN_IT_FMP0,ENABLE);//FIFO1消息挂号中断允许.		    
	NVIC_InitStructure.NVIC_IRQChannel = CAN2_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     // 主优先级为1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;            // 次优先级为0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	return 0;
	
}   


void can1_set_filter32(u8 num, Filter32ID id, Filter32Mask mask)
{

	CAN_FilterInitTypeDef can_filter;

	can_filter.CAN_FilterNumber=num;	  //过滤器0
	can_filter.CAN_FilterMode=CAN_FilterMode_IdMask; 
	can_filter.CAN_FilterScale=CAN_FilterScale_32bit; //32位 
	can_filter.CAN_FilterIdHigh= (id.all>>16)&0xFFFF;////32位ID
	can_filter.CAN_FilterIdLow= id.all&0xFFFF;
	can_filter.CAN_FilterMaskIdHigh=(mask.all>>16)&0xFFFF;//32位MASK
	can_filter.CAN_FilterMaskIdLow=mask.all&0xFFFF;
	can_filter.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//过滤器0关联到FIFO0
	can_filter.CAN_FilterActivation=ENABLE; //激活过滤器0


	CAN_FilterInit(&can_filter);//滤波器初始化

}

void can2_set_filter32(u8 num, Filter32ID id, Filter32Mask mask)
{

	CAN_FilterInitTypeDef can_filter;

	can_filter.CAN_FilterNumber=num;	  //过滤器0
	can_filter.CAN_FilterMode=CAN_FilterMode_IdMask; 
	can_filter.CAN_FilterScale=CAN_FilterScale_32bit; //32位 
	can_filter.CAN_FilterIdHigh= (id.all>>16)&0xFFFF;////32位ID
	can_filter.CAN_FilterIdLow= id.all&0xFFFF;
	can_filter.CAN_FilterMaskIdHigh=(mask.all>>16)&0xFFFF;//32位MASK
	can_filter.CAN_FilterMaskIdLow=mask.all&0xFFFF;
	can_filter.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//过滤器0关联到FIFO0
	can_filter.CAN_FilterActivation=ENABLE; //激活过滤器0


	CAN_FilterInit(&can_filter);//滤波器初始化

}

void can1_parse_msg(CanRxMsg* pMsg);
void CAN1_RX0_IRQHandler(void)
{
	CanRxMsg Rx = {0,};
	CAN_Receive(CAN1, 0, &Rx);
	// 需要做一些id、过滤器处理
	#ifdef TEST_FLAG
	{
		CanTxMsg Tx;

		Tx.ExtId = 1;
		Tx.IDE = CAN_Id_Extended;
		Tx.RTR = 0;
		Tx.DLC = 8;
		Tx.Data[7] = Rx.Data[6];
		Tx.Data[6] = Rx.Data[5];
		Tx.Data[5] = Rx.Data[4];
		Tx.Data[4] = Rx.Data[3];
		Tx.Data[3] = Rx.Data[2];
		Tx.Data[2] = Rx.Data[1];
		Tx.Data[1] = Rx.Data[0];
		Tx.Data[0] = Rx.Data[7];
		can1_send_msg(&Tx);

	}
	#else
	can1_parse_msg(&Rx);
	#endif
}

 void can2_parse_msg(CanRxMsg* pMsg);
void CAN2_RX0_IRQHandler(void)
{
	CanRxMsg Rx = {0,};
	CAN_Receive(CAN2, 0, &Rx);
	// 需要做一些id、过滤器处理	
	#ifdef TEST_FLAG
	{
		CanTxMsg Tx;

		Tx.ExtId = 1;
		Tx.IDE = CAN_Id_Extended;
		Tx.RTR = 0;
		Tx.DLC = 8;
		Tx.Data[7] = Rx.Data[6];
		Tx.Data[6] = Rx.Data[5];
		Tx.Data[5] = Rx.Data[4];
		Tx.Data[4] = Rx.Data[3];
		Tx.Data[3] = Rx.Data[2];
		Tx.Data[2] = Rx.Data[1];
		Tx.Data[1] = Rx.Data[0];
		Tx.Data[0] = Rx.Data[7];
		can2_send_msg(&Tx);

	}
	#else
	can2_parse_msg(&Rx);
	#endif
}


u8 can_send_msg(CanMsg_t *pTxMsg)
{	
	u8 mbox;
	u16 i=0;
	CanTxMsg TxMessage;

	TxMessage.StdId=pTxMsg->StdId;					 // 标准标识符为0
	TxMessage.ExtId=pTxMsg->ExtId;				 // 设置扩展标示符（29位）
	TxMessage.IDE=pTxMsg->IDE;			 // 使用扩展标识符
	TxMessage.RTR=pTxMsg->RTR;		 // 消息类型为数据帧，一帧8位
	TxMessage.DLC=pTxMsg->DLC;							 // 发送两帧信息
	for(i=0;i<8;i++)
		TxMessage.Data[i]=pTxMsg->Data[i];				 // 第一帧信息      
		
	mbox= CAN_Transmit(CAN2, &TxMessage);   
	
	//i=0;
	//while((CAN_TransmitStatus(CAN2, mbox)!=CAN_TxStatus_Ok)&&(i<0XFFF))//等待发送结束
	//	i++;	
		
	//if(i>=0XFFF)
	//	return 1;
		
	return 0;		

}


u8 can1_send_msg(CanMsg_t *pTxMsg)
{		
	u16 i=0;
	CanTxMsg TxMsg;

	TxMsg.StdId = pTxMsg->StdId;
	TxMsg.ExtId = pTxMsg->ExtId;
	TxMsg.IDE = pTxMsg->IDE;
	TxMsg.RTR = pTxMsg->RTR;
	TxMsg.DLC = pTxMsg->DLC;

	for(i=0;i<TxMsg.DLC;i++)
	{
		TxMsg.Data[i] = pTxMsg->Data[i];
	}

	
	can1_send_mbox= CAN_Transmit(CAN1, &TxMsg);   

	//i=0;
	//while((CAN_TransmitStatus(CAN1, can1_send_mbox)!=CAN_TxStatus_Ok)&&(i<0XFFF))//等待发送结束
	//	i++;	
		
	//if(i>=0XFFF)
	//	return 1;
	//else 
		return 0;

}


//0-成功  1- 发送中  2 失败
u8 can1_send_finish(void)
{
	if(can1_send_mbox != CAN_TxStatus_NoMailBox)
	{
		if(CAN_TransmitStatus(CAN1, can1_send_mbox)==CAN_TxStatus_Failed)
			return 2;
		else if(CAN_TransmitStatus(CAN1, can1_send_mbox)==CAN_TxStatus_Ok)
			return 0;
		else
			return 1;
	}
	else
	{
		return 2;
	}
}

u8 can2_send_msg(CanMsg_t *pTxMsg)
{	
	u16 i=0;
	CanTxMsg TxMsg;

	TxMsg.StdId = pTxMsg->StdId;
	TxMsg.ExtId = pTxMsg->ExtId;
	TxMsg.IDE = pTxMsg->IDE;
	TxMsg.RTR = pTxMsg->RTR;
	TxMsg.DLC = pTxMsg->DLC;

	for(i=0;i<TxMsg.DLC;i++)
	{
		TxMsg.Data[i] = pTxMsg->Data[i];
	}



	
	can2_send_mbox= CAN_Transmit(CAN2, &TxMsg);   
	
	//i=0;
	//while((CAN_TransmitStatus(CAN2, can2_send_mbox)!=CAN_TxStatus_Ok)&&(i<0XFFF))//等待发送结束
	//	i++;	
		
	//if(i>=0XFFF)
	//	return 1;
	//else 
		return 0;

}

//0-成功  1- 发送中  2 失败
u8 can2_send_finish(void)
{
	if(can2_send_mbox != CAN_TxStatus_NoMailBox)
	{
		if(CAN_TransmitStatus(CAN2, can2_send_mbox)==CAN_TxStatus_Failed)
			return 2;
		else if(CAN_TransmitStatus(CAN2, can2_send_mbox)==CAN_TxStatus_Ok)
			return 0;
		else
			return 1;
	}
	else
	{
		return 2;
	}
}

//can口接收数据查询
//buf:数据缓存区;	 
//返回值:0,无数据被收到;
//		 其他,接收的数据长度;
u8 can_receive_msg(unsigned char *buf)
{		   		   
	u32 i;
	CanRxMsg RxMessage;
	
	//没有接收到数据,直接退出 	
	if( CAN_MessagePending(CAN1,CAN_FIFO0)==0)
		return 0;		
		
	//读取数据			
	CAN_Receive(CAN1, CAN_FIFO0, &RxMessage);
		
	for(i=0;i<8;i++)
		buf[i]=RxMessage.Data[i];  

	
	return RxMessage.DLC;	
}

void drv_can_init(void)
{
	Filter32ID FilterID;
	Filter32Mask FilterMask;
	FilterID.all = 0;
	FilterID.bit.IDE = 1;
	FilterID.bit.EXID0 = 0;
	FilterID.bit.EXID1 = 0;
	FilterID.bit.EXID2 = 0;
	FilterID.bit.EXID3 = 0;
	FilterID.bit.EXID4 = 0;
	FilterID.bit.EXID5 = 0;
	FilterID.bit.EXID6 = 0;
	FilterID.bit.EXID7 = 0;//0x00
	
	FilterID.bit.EXID8 = 0;
	FilterID.bit.EXID9 = 0;
	FilterID.bit.EXID10 = 0;
	FilterID.bit.EXID11 = 0;
	FilterID.bit.EXID12 = 0;
	FilterID.bit.EXID13 = 0;
	FilterID.bit.EXID14 = 0;
	FilterID.bit.EXID15 = 0;//0x40
	FilterMask.all = 0;
	FilterMask.bit.IDE = 1;
	FilterMask.bit.EXID0 = 0;
	FilterMask.bit.EXID1 = 0;
	FilterMask.bit.EXID2 = 0;
	FilterMask.bit.EXID3 = 0;
	FilterMask.bit.EXID4 = 0;
	FilterMask.bit.EXID5 = 0;
	FilterMask.bit.EXID6 = 0;
	FilterMask.bit.EXID7 = 0;//0xFF
	
	FilterMask.bit.EXID8 = 0;
	FilterMask.bit.EXID9 = 0;
	FilterMask.bit.EXID10 = 0;
	FilterMask.bit.EXID11 = 0;
	FilterMask.bit.EXID12 = 0;
	FilterMask.bit.EXID13 = 0;
	FilterMask.bit.EXID14 = 0;
	FilterMask.bit.EXID15 = 0;//0x00	
	can1_conf(CAN_BAUDRATE_250K);
	can1_set_filter32(0, FilterID, FilterMask);
	can2_conf(CAN_BAUDRATE_250K);
	can2_set_filter32(15, FilterID, FilterMask);




	
}



