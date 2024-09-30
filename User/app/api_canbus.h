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
	CMD_AD_REQUEST = 0x20,//换管请求
	CMD_AD_DONE = 0x21,//换管完成反馈
	CMD_AD_GET_PIPE = 0x22,//取管请求
	CMD_JN_REQUEST = 0x30,//接捻请求
	CMD_JN_DONE = 0x31,//接头完成反馈
	CMD_TRANS = 0x40,// 发送当前锭号
	
};




typedef struct _CanBusCtl_s
{
	//CAN1
	u8 State; // 0-加载命令  1-下发 2-等待  3-处理数据
	u8 NodeType; // 节点类型，Main or Sub Node
	u8 CurID;
	u8 CurCmd;
	u8 CurNode;
	u8 CurIndex;
	u8 CurSetType;//设置参数类型DJ  or Qs
	u16 MaxIndex;//最大帧数
	u8 RxFlag;//0-未收到  1-部分收到2-全部收到   
	u8 FinalFrame;// 1-表示为最后一帧数据
	u16 WaitCnt;//等待计数器


	u8 DataRequestMain[16];//主要数据请求，机身或者接捻小车
	u8 DataRequestQs[16];//清纱数据请求
	u8 DataRequestSub[2];//次要参数请求，机尾或者落纱小车

	u8 ComErrMain[16];//主节点通信异常
	u8 ComErrSub[2];//副节点通信异常
	
	u8 ReSendCnt;

	CanMsg_t TxMsg; //发送数据缓存
	CanMsg_t RxMsg; //接收数据缓存
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
