#ifndef __sys_err_h
#define __sys_err_h

#include "sys_bsp.h"


#define LV_ERR_ID 9


//报警
struct ERR_HD_BIT
{
/*Bit00*/	u32 OverVoltage:1;			//过电压					E-1
/*Bit01*/	u32 LowVoltage:1;			//输入欠压				E-2
/*Bit02*/	u32 PowerUpErr:1;			//上电故障，启动电阻坏		E-3
/*Bit03*/	u32 EPROMError:1;			//EEPROM读或写错误 			E-4
/*Bit04*/	u32 SysParErr:1;			//系统参数异常				E-5
/*Bit05*/	u32 RES0:1;			//				E-6
/*Bit06*/	u32 RES1:1;			//				E-7


/*Bit07*/	u32 SC_M1:1;				// M1 过流   					E-10
/*Bit08*/	u32 CurSensorErrorU1:1;  	//U1中点电流采样异常			E-11
/*Bit09*/	u32 CurSensorErrorV1:1;  	//V1中点电流采样异常			E-12
/*Bit10*/	u32 OverPhaseCurrent1:1;		//M1 相电流过大				E-13
/*Bit11*/	u32 OverPosition1:1;			//M1 位置超差				E-14
/*Bit12*/	u32 OverSpeed1:1;			//M1 超速					E-15
/*Bit13*/	u32 OverPower1:1;			//M1 过功率					E-16
/*Bit14*/	u32 OverTemp1:1;				//M1  过温E-17
/*Bit15*/	u32 EncErrUVW1:1;				//M1编码器UVW信号异常				E-18
/*Bit16*/	u32 EncErr_ABZ1:1;			//M1编码器ABZ信号异常		E-19

	
/*Bit17*/	u32 SC_M2:1;				//M2 过流					E-20
/*Bit18*/	u32 CurSensorErrorU2:1;  	//U2中点电流采样异常			E-21
/*Bit19*/	u32 CurSensorErrorV2:1;  	//V2中点电流采样异常			E-22
/*Bit20*/	u32 OverPhaseCurrent2:1;		//M2 相电流过大				E-23
/*Bit21*/	u32 OverPosition2:1;			//M2 位置超差			E-24
/*Bit22*/	u32 OverSpeed2:1;			//M2 超速					E-25
/*Bit23*/	u32 OverPower2:1;			//M2 过功率					E-26
/*Bit24*/	u32 OverTemp2:1;				// M2 过温E-27
/*Bit25*/	u32 EncErrUVW2:1;				//M2编码器UVW信号异常				E-28
/*Bit26*/	u32 EncErr_ABZ2:1;			//M2编码器ABZ信号异常		E-29


};


union ERR_HD
{
	u32 all;
	struct ERR_HD_BIT bit;
};

/*********************************************************************************************/
//报警
struct ERR_CTL_BIT
{
	u16 DX_ERR:1;				//断线故障
	u16 ZERO_ERR:1;				//零点错误
	u16 JQEP_ERR:1;				//卷绕电机编码器错误
	u16 MT_ALM:1;				//满桶
	u16 ArmCom_ERR:1;			//Arm通信错误
	u16 LOCK:1;					//加密
};

union ERR_CTL
{
	u16 all;
	struct ERR_CTL_BIT bit;
};

/*********************************************************************************************/

typedef struct{
	u16 all;
	union ERR_CTL Err;
	union ERR_HD ErrHd;
	
	u16 ErrId;
	u16 ErrSaveFlag;
	u16 ErrClr;
}SysErr_t;


extern SysErr_t gSysErr;
void sys_err_init(void);
u16 sys_err_get_id(void);

#endif
