#ifndef __sys_err_h
#define __sys_err_h

#include "sys_bsp.h"


#define LV_ERR_ID 9


//����
struct ERR_HD_BIT
{
/*Bit00*/	u32 OverVoltage:1;			//����ѹ					E-1
/*Bit01*/	u32 LowVoltage:1;			//����Ƿѹ				E-2
/*Bit02*/	u32 PowerUpErr:1;			//�ϵ���ϣ��������軵		E-3
/*Bit03*/	u32 EPROMError:1;			//EEPROM����д���� 			E-4
/*Bit04*/	u32 SysParErr:1;			//ϵͳ�����쳣				E-5
/*Bit05*/	u32 RES0:1;			//				E-6
/*Bit06*/	u32 RES1:1;			//				E-7


/*Bit07*/	u32 SC_M1:1;				// M1 ����   					E-10
/*Bit08*/	u32 CurSensorErrorU1:1;  	//U1�е���������쳣			E-11
/*Bit09*/	u32 CurSensorErrorV1:1;  	//V1�е���������쳣			E-12
/*Bit10*/	u32 OverPhaseCurrent1:1;		//M1 ���������				E-13
/*Bit11*/	u32 OverPosition1:1;			//M1 λ�ó���				E-14
/*Bit12*/	u32 OverSpeed1:1;			//M1 ����					E-15
/*Bit13*/	u32 OverPower1:1;			//M1 ������					E-16
/*Bit14*/	u32 OverTemp1:1;				//M1  ����E-17
/*Bit15*/	u32 EncErrUVW1:1;				//M1������UVW�ź��쳣				E-18
/*Bit16*/	u32 EncErr_ABZ1:1;			//M1������ABZ�ź��쳣		E-19

	
/*Bit17*/	u32 SC_M2:1;				//M2 ����					E-20
/*Bit18*/	u32 CurSensorErrorU2:1;  	//U2�е���������쳣			E-21
/*Bit19*/	u32 CurSensorErrorV2:1;  	//V2�е���������쳣			E-22
/*Bit20*/	u32 OverPhaseCurrent2:1;		//M2 ���������				E-23
/*Bit21*/	u32 OverPosition2:1;			//M2 λ�ó���			E-24
/*Bit22*/	u32 OverSpeed2:1;			//M2 ����					E-25
/*Bit23*/	u32 OverPower2:1;			//M2 ������					E-26
/*Bit24*/	u32 OverTemp2:1;				// M2 ����E-27
/*Bit25*/	u32 EncErrUVW2:1;				//M2������UVW�ź��쳣				E-28
/*Bit26*/	u32 EncErr_ABZ2:1;			//M2������ABZ�ź��쳣		E-29


};


union ERR_HD
{
	u32 all;
	struct ERR_HD_BIT bit;
};

/*********************************************************************************************/
//����
struct ERR_CTL_BIT
{
	u16 DX_ERR:1;				//���߹���
	u16 ZERO_ERR:1;				//������
	u16 JQEP_ERR:1;				//���Ƶ������������
	u16 MT_ALM:1;				//��Ͱ
	u16 ArmCom_ERR:1;			//Armͨ�Ŵ���
	u16 LOCK:1;					//����
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
