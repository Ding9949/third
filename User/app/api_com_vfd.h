#ifndef __api_com_vfd_h
#define __api_com_vfd_h

#include "sys_bsp.h"


#define COM_VFD_FRAME_LEN 200

enum {
	CMD_VFD_FLASH = 0, 
	CMD_VFD_READ_REG, 
	CMD_VFD_WRITE_REG,

};


#define  REG_00_MASK       0x00000001
#define  REG_01_MASK       0x00000002
#define  REG_02_MASK       0x00000004
#define  REG_03_MASK       0x00000008
#define  REG_04_MASK       0x00000010
#define  REG_05_MASK       0x00000020
#define  REG_06_MASK       0x00000040
#define  REG_07_MASK       0x00000080
#define  REG_08_MASK       0x00000100
#define  REG_09_MASK       0x00000200
#define  REG_10_MASK       0x00000400
#define  REG_11_MASK       0x00000800
#define  REG_12_MASK       0x00001000
#define  REG_13_MASK       0x00002000
#define  REG_14_MASK       0x00004000
#define  REG_15_MASK       0x00008000
#define  REG_16_MASK       0x00010000
#define  REG_17_MASK       0x00020000
#define  REG_18_MASK       0x00040000
#define  REG_19_MASK       0x00080000

#define ADR_Fxx 0x00 //��������
#define ADR_Exx 0x01 //���ӹ���
#define ADR_Cxx 0x02 //���ƹ���
#define ADR_Pxx 0x03 //���1����
#define ADR_Hxx 0x04 //�߼�����
#define ADR_Axx 0x05 //���2����
#define ADR_Oxx 0x06 //ѡ������
#define ADR_Sxx 0x07 //ָ���������
#define ADR_Mxx 0x08 //�������
#define ADR_Rxx 0x0A //���4����
#define ADR_Jxx 0x0D //Ӧ�ù���1
#define ADR_Yxx 0x0E //���ӹ���
#define ADR_Wxx 0x0F //���2
#define ADR_Xxx 0x10 //����1
#define ADR_Zxx 0x11 //����2
#define ADR_Bxx 0x12 //���3����
#define ADR_Dxx 0x13 //Ӧ�ù���2

#define REG_Sxx(no) ((ADR_Sxx<<8) + no) //S
#define REG_Fxx(no) ((ADR_Fxx<<8) + no) //F

#define REG_FRE_PU  REG_Sxx(1)   //S01-Ƶ��ָ��pu   -32768`32767
#define REG_FRE_HZ  REG_Sxx(5)   //S05-Ƶ�� ָ��0.00`655.35  hz
#define REG_CMD  REG_Sxx(6)   //S06-���в���ָ��   0x0000~0xFFFF
#define REG_OUT  REG_Sxx(7)   //S07-���������Ϣ0x0000~0xFFFF
#define REG_ACC_TIME REG_Sxx(8)  // S08-����ʱ��1  0.00~3000s
#define REG_DEC_TIME REG_Sxx(9)  // S09-����ʱ��1  0.00~3000s
#define REG_RST_ERR  REG_Sxx(14)   //S14-������λָ��0or1

#define REG_FRE1_MODE REG_Fxx(1)  // F01 - ����1 �趨ģʽ 
#define REG_RUN_MODE REG_Fxx(2)  // F02 - ���в���ģʽ
#define REG_FRE1_LIMIT REG_Fxx(3)  // F03 - ������Ƶ��25.0hz~500.0hz
#define REG_FRE1_REF REG_Fxx(4)  // F04 - ������Ƶ��25.0hz~500.0hz
#define REG_CTL_MODE REG_Fxx(42)  // F42 - ����ģʽ0-VF  3-������VF


//����ָ��
struct S06_Bit
{
	u16 FWD:1;//  1= ��ת
	u16 REV:1;//  1= ��ת	     
	u16 X1:1;// ͨ���������		       
	u16 X2:1;// ͨ���������			       
	u16 X4:1;// ͨ���������		       
	u16 X5:1;// ͨ���������		       
	u16 bit7:1;	       
	u16 bit8:1;	       
	u16 bit9:1;	       
	u16 bit10:1;	       
	u16 bit11:1;	       
	u16 bit12:1;	       
	u16 bit13:1;	       
	u16 XF:1;// ͨ���������	       
	u16 XR:1;// ͨ���������     
	u16 RST:1;// 0->1ʱ��λ	
};

union S06_u
{
	u16 All;
	struct S06_Bit bit;
};


//����״̬���
struct M14_Bit
{
	u16 FWD:1;// 1 = ��ת��
	u16 REV:1;//	 1 =  ��ת��    
	u16 EXT:1;// 1 = ֱ���ƶ��л򼤴���	       
	u16 INT:1;//	 1 = 	��Ƶ���ж�       
	u16 BRK:1;//	  1 =  �ƶ���     
	u16 MUV:1;//  1 = ֱ���м�ȷ��	       
	u16 TL:1;//  1 = ת��������	       
	u16 VL:1;// 1 = ��ѹ������	       
	u16 IL:1;// 1 = ����������	       
	u16 ACC:1;// 1 = 	������       
	u16 DEC:1;// 1 = 	������       
	u16 ALM:1;// 1 = 	�ܱ���       
	u16 RL:1;// 1 = ͨ����Ч	       
	u16 bit13:1;// 1 = 	       
	u16 bit14:1;// 1 = 	       
	u16 BUSY:1;// 1 = ���ܴ���д����	
};

union M14_u
{
	u16 All;
	struct M14_Bit bit;
};




typedef struct _Mxx_s
{
	u16 Fre_pu;//M01-Ƶ��ָ��pu   -32768`32767
	u16 Tor;//M02-ת��ָ�� -327.68`327.67    0.01  %
	u16 TorCur;//M03-ת�ص���ָ��-327.68`327.67    0.01  %
	u16 Flux;// M04- ��ͨ��ָ��-327.68`327.67    0.01   %
	u16 Fre_hz;//M05-Ƶ�� ָ��0.00`655.35  hz
	u16 oFre_pu;//M06-���Ƶ��pu   -32768`32767
	u16 oTor;//M07-�������-327.68`327.67    0.01  %
	u16 oTorCur;//M08-���ת�ص���-327.68`327.67    0.01  %
	u16 oFre_hz;//M09-���Ƶ��0.00`655.35  hz
	u16 oP;//M10-���Ĺ���0.00`399.99 0.01 %
	u16 oCur;//M11-���������Чֵ 0.00`399.99   0.01 %
	u16 oVol;//M12-�����ѹ��Чֵ0.00`1000.0   0.1 %
	u16 CMD;//M13-���в���ָ��   0x0000~0xFFFF
	u16 RunST;//M14-����״̬0x0000~0xFFFF
	u16 OutST;//M15-���������Ϣ0x0000~0xFFFF
	u16 ERR;//M16-���±���  0~127
	u16 ERR_1;//M17-��һ�α��� 0~127
	u16 ERR_2;//M18-����һ�α��� 0~127
	u16 ERR_3;//M19-����һ�α��� 0~127
}Mxx_t;


typedef struct _REGxx_s
{
	//Sxx
	u16 Fre_pu;//S01-Ƶ��ָ��pu   -32768`32767
	u16 Fre_hz;//S05-Ƶ�� ָ��0.00`655.35  hz
	union S06_u CMD;//S06-���в���ָ��   0x0000~0xFFFF
	u16 OutST;//S07-���������Ϣ0x0000~0xFFFF
	u16 AccTime;//S08-����ʱ�� 0.0~3600.0    0.1s
	u16 DecTime;//S09-����ʱ�� 0.0~3600.0    0.1s
	u16 RstErr;//S14-������λָ��0or1
	//Fxx
	u16 FRE1_MODE; // F01 - ����1 �趨ģʽ 
	u16 RUN_MODE;  // F02 - ���в���ģʽ
	u16 FRE1_LIMIT;  // F03 - ������Ƶ��25.0hz~500.0hz
	u16 FRE1_REF; // F04 - ������Ƶ��25.0hz~500.0hz


}REGxx_t;

struct REG_FLAG_Bit
{
	//Sxx
	u32 Fre_pu:1;
	u32 Fre_hz:1;
	u32 CMD:1;
	u32 OutST:1;
	u32 AccTime:1;
	u32 DecTime:1;
	u32 RstErr:1;
	//Fxx
	u32 FRE1_MODE:1;
	u32 RUN_MODE:1;  
	u32 FRE1_LIMIT:1; 
	u32 FRE1_REF:1; 
};

union REG_FLAG_u
{
	u32 All;
	struct REG_FLAG_Bit bit;
};




typedef struct _VfdCom_s
{
	u8 RxdIndex;
	u8 RxdFlag; // ������ɱ�־
	u8 RxdLen;
	u16 RxdFrameTicker;// ֡���������
	u16 RxdWaitCnt;// ���յȴ�ʱ�������
	
	u8 TxdSts;
	u8 TxdFlag;//ͨ�ŷ���ʹ�ܱ�־
	u8 TxLen;

	u8 State;//����״̬��
	u8 CurNode;//
	u8 MaxNode;
	u8 CurCmd;
	u8 CurIdx;
	u16 CurReg;
	u16 TaskTicker;//ͨ������Ƭ


	
	u32 ErrCnt[10];	//ͨ�ų��������
	union REG_FLAG_u RegWriteFlag[10];//����д
	union REG_FLAG_u RegReadFlag[10];//�����ض�
	Mxx_t  Mxx[10]; // ���״̬ r
	REGxx_t REGxx[10];//�Ĵ��� rw
 
	
	u8 VfdRecBuf[COM_VFD_FRAME_LEN];
	u8 VfdTxdBuf[40];
}VfdCom_t;

extern VfdCom_t gVfdCom;


void vfd_com_init(void);
void vfd_com_isr(void);
void vfd_com_task(void);

#endif
