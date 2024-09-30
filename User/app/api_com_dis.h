/*
 *
 *  Created on: 2017年8月16日
 *      Author: Wuych
 */

 #ifndef __api_excom_task_h
#define __api_excom_task_h

#include "sys_bsp.h"

#define DIS_COM_PAR_MASK  0xFF

#define DIS_COM_FRAM_LEN 200

#define EXCMD_Flash 0x0C
#define EXCMD_Flash1 0x0D
#define EXCMD_Test 0x0E
#define EXCMD_P1 0x1
#define EXCMD_P2 0x2
#define EXCMD_P3 0x3
#define EXCMD_P4 0x4
#define EXCMD_P5 0x5
#define EXCMD_P6 0x6
#define EXCMD_P7 0x7
#define EXCMD_P11 0x11




typedef struct _DisCom_s
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
	u16 ParRequestFlag; //参数请求标志
	u16 ParRxFlag; //参数标志标志
	u16 ParTransDlyCnt;
	
	u8 ParSave;
	u32 ParSaveDlyCnt;

	//


	u32 rx_ok;
	u32 chk_ok;
	u32 tx_ok;

	u8 RecBuf[DIS_COM_FRAM_LEN];
	u8 TxdBuf[DIS_COM_FRAM_LEN];

}DisCom_t;




extern DisCom_t gDisCom;


extern void (*ExCom_Task_Ptr)(void);

void dis_com_init(void);
void dis_com_rx(u8 temp);
void dis_com_tx(u8 len);
void dis_com_task(void);

#endif
