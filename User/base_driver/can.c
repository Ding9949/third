#include <string.h>
#include "can.h"
#include "gpio.h"

u8 can1_send_mbox = CAN_TxStatus_NoMailBox;
u8 can2_send_mbox = CAN_TxStatus_NoMailBox;

//CAN��ʼ��
//tsjw:����ͬ����Ծʱ�䵥Ԫ.��Χ:1~3; CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
//tbs2:ʱ���2��ʱ�䵥Ԫ.��Χ:1~8;
//tbs1:ʱ���1��ʱ�䵥Ԫ.��Χ:1~16;	  CAN_BS1_1tq ~CAN_BS1_16tq
//brp :�����ʷ�Ƶ��.��Χ:1~1024;(ʵ��Ҫ��1,Ҳ����1~1024) tq=(brp)*tpclk1
typedef struct _can_baudrate_s
{
	unsigned char tsjw;
	unsigned char tbs1;
	unsigned char tbs2;
	unsigned short brp;
}can_baudrate_t;

//������=Fpclk1/((tsjw+tbs1+tbs2)*brp);
//Fpclk1��ʱ���ڳ�ʼ����ʱ������Ϊ42M,�������CAN_SJW_1tq, CAN_BS1_6tq, CAN_BS2_7tq, 6;
//������Ϊ:42M/((1+6+7)*6)=500Kbps
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


//CAN��ʼ��
u8 can1_conf(unsigned char baudrate)
{

	CAN_InitTypeDef        CAN_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	can_baudrate_t p;

	_get_baud_rate(baudrate, &p);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);//ʹ��CAN1ʱ��	
	
	gpio_config(PD0, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN1);
	gpio_config(PD1, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN1);
	
	CAN_DeInit(CAN1);
	CAN_StructInit(&CAN_InitStructure);                /* ���CAN�����ṹ���ԱΪȱʡֵ */
	//CAN��Ԫ����
	CAN_InitStructure.CAN_TTCM=DISABLE;						 //��ʱ�䴥��ͨ��ģʽ  //
	CAN_InitStructure.CAN_ABOM=ENABLE;						 //����Զ����߹���	 //
	CAN_InitStructure.CAN_AWUM=DISABLE;						 //˯��ģʽͨ���������(���CAN->MCR��SLEEPλ)//
	CAN_InitStructure.CAN_NART=DISABLE;						 	//��ֹ�����Զ����� //
	CAN_InitStructure.CAN_RFLM=DISABLE;						 //���Ĳ�����,�µĸ��Ǿɵ� // 
	CAN_InitStructure.CAN_TXFP=DISABLE;						 //���ȼ��ɱ��ı�ʶ������ //
	CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;	         //ģʽ���ã� mode:0,��ͨģʽ;1,�ػ�ģʽ; //
	//���ò�����
	CAN_InitStructure.CAN_SJW=p.tsjw;//����ͬ����Ծ���(Tsjw)Ϊtsjw+1��ʱ�䵥λ  CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
	CAN_InitStructure.CAN_BS1=p.tbs1;//Tbs1=tbs1+1��ʱ�䵥λCAN_BS1_1tq ~CAN_BS1_16tq
	CAN_InitStructure.CAN_BS2=p.tbs2;//Tbs2=tbs2+1��ʱ�䵥λCAN_BS2_1tq ~	CAN_BS2_8tq
	CAN_InitStructure.CAN_Prescaler=p.brp;            //��Ƶϵ��(Fdiv)Ϊbrp+1	//

	CAN_Init(CAN1, &CAN_InitStructure);            // ��ʼ��CAN1 


	CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);//FIFO0��Ϣ�Һ��ж�����.		    
	NVIC_InitStructure.NVIC_IRQChannel = CAN1_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     // �����ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;            // �����ȼ�Ϊ0
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

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);//ʹ��CAN2ʱ��	
	
	gpio_config(PB12, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN2);
	gpio_config(PB13, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_CAN2);
	
	CAN_DeInit(CAN2);
	CAN_StructInit(&CAN_InitStructure);                /* ���CAN�����ṹ���ԱΪȱʡֵ */
	//CAN��Ԫ����
	CAN_InitStructure.CAN_TTCM=DISABLE;						 //��ʱ�䴥��ͨ��ģʽ  //
	CAN_InitStructure.CAN_ABOM=ENABLE;						 //����Զ����߹���	 //
	CAN_InitStructure.CAN_AWUM=DISABLE;						 //˯��ģʽͨ���������(���CAN->MCR��SLEEPλ)//
	CAN_InitStructure.CAN_NART=DISABLE;						 	//��ֹ�����Զ����� //
	CAN_InitStructure.CAN_RFLM=DISABLE;						 //���Ĳ�����,�µĸ��Ǿɵ� // 
	CAN_InitStructure.CAN_TXFP=DISABLE;						 //���ȼ��ɱ��ı�ʶ������ //
	CAN_InitStructure.CAN_Mode= CAN_Mode_Normal;	         //ģʽ���ã� mode:0,��ͨģʽ;1,�ػ�ģʽ; //
	//���ò�����
	CAN_InitStructure.CAN_SJW=p.tsjw;//����ͬ����Ծ���(Tsjw)Ϊtsjw+1��ʱ�䵥λ  CAN_SJW_1tq	 CAN_SJW_2tq CAN_SJW_3tq CAN_SJW_4tq
	CAN_InitStructure.CAN_BS1=p.tbs1;//Tbs1=tbs1+1��ʱ�䵥λCAN_BS1_1tq ~CAN_BS1_16tq
	CAN_InitStructure.CAN_BS2=p.tbs2;//Tbs2=tbs2+1��ʱ�䵥λCAN_BS2_1tq ~	CAN_BS2_8tq
	CAN_InitStructure.CAN_Prescaler=p.brp;            //��Ƶϵ��(Fdiv)Ϊbrp+1	//

	CAN_Init(CAN2, &CAN_InitStructure);            // ��ʼ��CAN1 


	CAN_ITConfig(CAN2,CAN_IT_FMP0,ENABLE);//FIFO1��Ϣ�Һ��ж�����.		    
	NVIC_InitStructure.NVIC_IRQChannel = CAN2_RX0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;     // �����ȼ�Ϊ1
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;            // �����ȼ�Ϊ0
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	return 0;
	
}   


void can1_set_filter32(u8 num, Filter32ID id, Filter32Mask mask)
{

	CAN_FilterInitTypeDef can_filter;

	can_filter.CAN_FilterNumber=num;	  //������0
	can_filter.CAN_FilterMode=CAN_FilterMode_IdMask; 
	can_filter.CAN_FilterScale=CAN_FilterScale_32bit; //32λ 
	can_filter.CAN_FilterIdHigh= (id.all>>16)&0xFFFF;////32λID
	can_filter.CAN_FilterIdLow= id.all&0xFFFF;
	can_filter.CAN_FilterMaskIdHigh=(mask.all>>16)&0xFFFF;//32λMASK
	can_filter.CAN_FilterMaskIdLow=mask.all&0xFFFF;
	can_filter.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//������0������FIFO0
	can_filter.CAN_FilterActivation=ENABLE; //���������0


	CAN_FilterInit(&can_filter);//�˲�����ʼ��

}

void can2_set_filter32(u8 num, Filter32ID id, Filter32Mask mask)
{

	CAN_FilterInitTypeDef can_filter;

	can_filter.CAN_FilterNumber=num;	  //������0
	can_filter.CAN_FilterMode=CAN_FilterMode_IdMask; 
	can_filter.CAN_FilterScale=CAN_FilterScale_32bit; //32λ 
	can_filter.CAN_FilterIdHigh= (id.all>>16)&0xFFFF;////32λID
	can_filter.CAN_FilterIdLow= id.all&0xFFFF;
	can_filter.CAN_FilterMaskIdHigh=(mask.all>>16)&0xFFFF;//32λMASK
	can_filter.CAN_FilterMaskIdLow=mask.all&0xFFFF;
	can_filter.CAN_FilterFIFOAssignment=CAN_Filter_FIFO0;//������0������FIFO0
	can_filter.CAN_FilterActivation=ENABLE; //���������0


	CAN_FilterInit(&can_filter);//�˲�����ʼ��

}

void can1_parse_msg(CanRxMsg* pMsg);
void CAN1_RX0_IRQHandler(void)
{
	CanRxMsg Rx = {0,};
	CAN_Receive(CAN1, 0, &Rx);
	// ��Ҫ��һЩid������������
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
	// ��Ҫ��һЩid������������	
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

	TxMessage.StdId=pTxMsg->StdId;					 // ��׼��ʶ��Ϊ0
	TxMessage.ExtId=pTxMsg->ExtId;				 // ������չ��ʾ����29λ��
	TxMessage.IDE=pTxMsg->IDE;			 // ʹ����չ��ʶ��
	TxMessage.RTR=pTxMsg->RTR;		 // ��Ϣ����Ϊ����֡��һ֡8λ
	TxMessage.DLC=pTxMsg->DLC;							 // ������֡��Ϣ
	for(i=0;i<8;i++)
		TxMessage.Data[i]=pTxMsg->Data[i];				 // ��һ֡��Ϣ      
		
	mbox= CAN_Transmit(CAN2, &TxMessage);   
	
	//i=0;
	//while((CAN_TransmitStatus(CAN2, mbox)!=CAN_TxStatus_Ok)&&(i<0XFFF))//�ȴ����ͽ���
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
	//while((CAN_TransmitStatus(CAN1, can1_send_mbox)!=CAN_TxStatus_Ok)&&(i<0XFFF))//�ȴ����ͽ���
	//	i++;	
		
	//if(i>=0XFFF)
	//	return 1;
	//else 
		return 0;

}


//0-�ɹ�  1- ������  2 ʧ��
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
	//while((CAN_TransmitStatus(CAN2, can2_send_mbox)!=CAN_TxStatus_Ok)&&(i<0XFFF))//�ȴ����ͽ���
	//	i++;	
		
	//if(i>=0XFFF)
	//	return 1;
	//else 
		return 0;

}

//0-�ɹ�  1- ������  2 ʧ��
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

//can�ڽ������ݲ�ѯ
//buf:���ݻ�����;	 
//����ֵ:0,�����ݱ��յ�;
//		 ����,���յ����ݳ���;
u8 can_receive_msg(unsigned char *buf)
{		   		   
	u32 i;
	CanRxMsg RxMessage;
	
	//û�н��յ�����,ֱ���˳� 	
	if( CAN_MessagePending(CAN1,CAN_FIFO0)==0)
		return 0;		
		
	//��ȡ����			
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



