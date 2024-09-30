#ifndef __api_canbus_h
#define __api_canbus_h

#include "sys_bsp.h"


#define MAX_NODE_NUM 12  //
#define MAX_SPINDLE_NUM 8
#define MAX_JN_NUM 4  //
#define MAX_AD_NUM 1  //
#define MAX_JW_NUM 2  //

#define MAX_RESEND_NUM 1

#define MAX_IDX_DJ  18
#define MAX_IDX_QS  4
#define MAX_IDX_JW  2
#define MAX_IDX_JN  14
#define MAX_IDX_AD  4

#define MASK_DJ 0x03FFFF
#define MASK_QS 0x0F
#define MASK_JW 0x03
#define MASK_JN 0x3FFF
#define MASK_AD 0x0F

enum {
	STS_INIT = 0,
	STS_WAIT_SEND,
	STS_WAIT_OVER_TIME,
	STS_LOAD,
	STS_SEND,
	STS_OVER_TIME,
	STS_PARSE,
};

enum {
	CMD_FLASH = 0x1,  
	CMD_SET1 = 0x2,
	CMD_SET2 = 0x3,
	CMD_AD_REQUEST = 0x20,//��������
	CMD_AD_DONE = 0x21,//������ɷ���
	CMD_AD_GET_PIPE = 0x22,//ȡ������
	CMD_JN_REQUEST = 0x30,//��������
	CMD_JN_DONE = 0x31,//��ͷ��ɷ���
	CMD_TRANS = 0x40,// ���͵�ǰ����
	
};




typedef struct _CanBusCtl_s
{
	//CAN1
	u8 State; // 0-��������  1-�·� 2-�ȴ�  3-��������
	u8 NodeType; // �ڵ����ͣ�Main or Sub Node
	u8 CurID;
	u8 CurCmd;
	u8 CurNode;
	u8 CurIndex;
	u8 CurSetType;//���ò�������DJ  or Qs
	u16 MaxIndex;//���֡��
	u8 RxFlag;//0-δ�յ�  1-�����յ�2-ȫ���յ�   
	u8 FinalFrame;// 1-��ʾΪ���һ֡����
	u16 WaitCnt;//�ȴ�������


	u8 DataRequestMain[16];//��Ҫ�������󣬻�����߽���С��
	u8 DataRequestQs[16];//��ɴ��������
	u8 DataRequestSub[2];//��Ҫ�������󣬻�β������ɴС��

	u8 ComErrMain[16];//���ڵ�ͨ���쳣
	u8 ComErrSub[2];//���ڵ�ͨ���쳣
	
	u8 ReSendCnt;

	CanMsg_t TxMsg; //�������ݻ���
	CanMsg_t RxMsg; //�������ݻ���
	//CAN2
}CanBusCtl_t;

extern CanBusCtl_t gCanBusCtl1;
extern CanBusCtl_t gCanBusCtl2;

void can1_parse_msg(CanRxMsg* pMsg);
void can2_parse_msg(CanRxMsg* pMsg);
void can_task_init(void);
void can1_task(void);
void can2_task(void);

#endif
