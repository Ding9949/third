#ifndef __sys_main_h
#define __sys_main_h

#include "sys_bsp.h"



typedef struct _IapMarkInfo_s
{
	u16 IapMarkWord;		// 01正常启动；02升级；FF无APP
	u16 Adress;
	u16 BaudRate;
	u16 BootVer;
}IapMarkInfo_t;


extern IapMarkInfo_t IapMarkInfo;


extern u16 gPwmIsrTacker;

extern u16 ISR_FREQUENCY; 				
extern u16  SPEED_LOOP_PSR;				
extern float  T_PWM;

extern void (*Sys_Logic_Ptr) (void);

void main_init(void);
void main_ticker(void);
void main_isr(void);
void main_task(void);

#endif
