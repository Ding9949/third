#ifndef __api_com_qs_h
#define __api_com_qs_h

#include "sys_bsp.h"

#define QS_COM_FRAM_LEN 120


#define QS_CMD_Addr 0x11
#define QS_CMD_Stop 0x12
#define QS_CMD_Start 0x13
#define QS_CMD_Param 0x22
#define QS_CMD_Flash 0x23
#define QS_CMD_Noise 0x24
#define QS_CMD_Sensitivity 0x25
#define QS_CMD_Version 0x26
#define QS_CMD_Zero 0x27
#define QS_CMD_Dust 0x28
#define QS_CMD_Cut 0x29
#define QS_CMD_Debug 0x2A

typedef struct _QsCom_s
{
	u8 RxdIndex;
	u8 RxdFlag; // 接收完成标志
	u16 RxdTicker;
	u8 RxdLen;
	
	u8 TxdSts;
	u8 TxdFlag;//通信发送使能标志
	u8 TxdLen;//发送的字节数
	u8 TxdCnt;
	u16 TxdErr;
	u16 TxdDly;

	
	u32 ConnectTicker;	//群通信连接判断计数器
	u8 ConnectFlag;//群通信连接判断标志

	u8 ParOk ;//群通信参数已更新标志
	u8 ParRequestFlag; //参数请求标志
	u8 ParRxFlag; //参数标志标志
	
	u8 ParSave;
	u32 ParSaveDlyCnt;
	

	u32 rx_ok;
	u32 chk_ok;
	u32 tx_ok;

	u8 CurSpindle;

	
	u8 RecBuf[QS_COM_FRAM_LEN];
	u8 TxdBuf[QS_COM_FRAM_LEN];

}QsCom_t;

extern QsCom_t gQsCom;

void qs_com_init(void);
void qs_com_rx(u8 temp);
void qs_com_tx(u8 len);
void qs_com_task(void);


#endif
