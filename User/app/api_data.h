#ifndef __api_data_h
#define __api_data_h

#include "sys_bsp.h"

#define AVG_BUF_LEN_MAX 32
#define MAX_SYSPAR_NUM (sizeof(SysPar_t)>>1)
#define MAX_QSPAR_NUM (sizeof(QsPar_t)>>1)
#define MAX_DBGPAR_NUM (sizeof(DbgPar_t)>>1)

enum {
	DAT_DJ = 0,  //������
	DAT_JW,//��β
	DAT_QS,//��ɴ
	DAT_JN,//����С��
	DAT_QS1,//��ɴ1 - ����С��
	DAT_AD//��ɴС��
};

/////////////////////////////////////////////////////////////////////////////////////
typedef struct _SysPar_s
{
	//��������
	u16 INDEX;
	u16 SX_Type;//ɴ������
	u16 SZS_Type;//ɴ֧������
	u16 SZS_Num;//ɴ֧��
	u32 MT_Len;//��Ͱ���� m
	u16 MT_Weight_g;//��Ͱ������
	u16 MT_Weight_b;//��Ͱ������
	u16 DZ_ContinueGQ;//���ӳ�����������
	u16 RES1;
	u16 DY_StartDW;//�����ö�����ʼ��λ0-��ʹ�øù���
	u16 DY_StopDW;//�����ö���������λ0-��ʹ�øù���
	u32 DY_Len;//������Ͱ���� m
	//��ɴ����
	u16 XSPD;//ɴ���ٶ�0.1rpm  
	u16 TDR;//��ǣ���TDR  Ħ�������͵����������ٶȱ�0.1
	u16 MDR;//��ǣ���MDR  Ħ��������������֮����ٱ�0.1
	u16 BDR;//��ǣ���BDR ���������͵�������֮����ٱ�0.1
	u16 WDR;//ι��� WDR Ħ��������ǰ����֮����ٱ�0.001
	u16 JDR;//�վ��JDR ��ȡ��Ͳ��Ħ������֮���ٱ�0.001
	u16 BR;//��ʼ��BR����ӻ����������к������ٶȵı任�ȣ�
	u16 JANG;//�ᶯ�Ƕ�
	//��������
	u16 SL_En;//����װ�ÿ���
	u16 SL_Spd;//�����ٶ�
	u16 SL_Dir;//��������
	//��ɴ������װ������
	u16 TEN_En;//��ɴ����������װ���(��������)����
	u16 TEN_HThd;//�������ޱ�����ֵ
	u16 TEN_LThd;//�������ޱ�����ֵ
	u16 TEN_BDThd;//����ǰ������������ֵ
	u16 TEN_Reset;//������λ
	//����������
	u16 JN_PZType;//ѡ���������������
	u16 JN_JieNianStartTime;//����ʼʱ��0.01S
	u16 JN_JieNianTime;//����ʱ��  0.01S
	u16 JN_JiaNianStartTime;//����ʼʱ��0.01S
	u16 JN_JiaNianTime;//����ʱ��  0.01S
	u16 JN_JiaNianStartTime3;// 3��ʽ���춨ʱ��������  0.01S
	u16 JN_JiaNianTime3;// 3��ʽ����������ʱ��  0.01S
	u16 JN_LnPos;//Ln��λ�� ���ڵ����������ӳ��ȡ�ֵԽ����ӳ���Խ��
	u16 JN_MonitorN;//��Ӽ����N%    ��Ӽ������N%�Ĵ�ϸ�趨
	u16 JN_MonitorS;//��Ӽ����S%    ��Ӽ������S���еĴ�ϸ�趨
	u16 JN_MonitorSLen;//��Ӽ����Scm   ��ӿؿ�����S���еĳ����趨

	//������������
	u16 MFJ_Fre;//���ķ��Ƶ�� 0.01hz
	u16 SFJ_Fre;//���ķ��Ƶ�� 0.01hz
	u16 FD_Rto;//�ᶯ�ŵ�������0.1%
	u16 FD_LT;//�ᶯ��������ʱ�� 1s
	u16 FD_HT;//�ᶯ��������ʱ��1s
	u16 PQ_Time;//�����ʱ��1s
	u16 PQ_Period;//��������1s
	u16 PQ_OpenTime;//������ʱ��1s
	u16 PQ_CloseTime;//�����ر�ʱ��1s
	u16 LL_AlarmTime;//����ѹ����ȷ��ʱ��1min
	u16 HHSD_AlarmTime;//���Źرգ��ػ��䳤�ڴ����ֶ�ģʽ����ȷ��ʱ��1min
	u16 FM_CloseTime;//��·���Źر�ʱ��1s
	u16 HH_RunTime;//�ػ��ų�װ������ʱ�� 1s
	u16 CFQJ_Period;//���������  min
	u16 CF_DlyClose;//����ر��ӳ�s
	u16 TransOverTimeThd;// ���Ͳɴͣ��ʱ�䳬����Ͳɴ���ʹ�������תʱ�䣬�������VOS��Ļ�л���ʾ����
	u16 LL_TimeThd;//��ѹ��ѹȷ��ʱ����ֵ
	u16 HL_TimeThd;//��ѹ��ѹȷ��ʱ����ֵ
	//������������
	u16 DD_JTTryN; //��ͷ���Դ���
	u16 DD_RedCtl;//����ƹ���
	u16 DD_TSEn;//̽ɴʹ��
	u32 DD_L1;//��װ��L1  m
	u32 DD_L2;//��װ��L2  m
	u32 DD_L3;//��װ��L3  m
	u32 DD_L4;//��װ��L4  m
	u32 DD_L5;//��װ��L5  m
	u32 DD_L6;//��װ��L6  m
	u32 DD_L7;//��װ��L7  m
	u32 DD_L8;//��װ��L8  m
	u16 DD_T1;//ҡ��̧��ʱ��T1  
	u16 DD_T2;//ҡ��̧��ʱ��T2  
	u16 DD_T3;//ҡ��̧��ʱ��T3  
	u16 DD_T4;//ҡ��̧��ʱ��T4  
	u16 DD_T5;//ҡ��̧��ʱ��T5  
	u16 DD_T6;//ҡ��̧��ʱ��T6  
	u16 DD_T7;//ҡ��̧��ʱ��T7  
	u16 DD_T8;//ҡ��̧��ʱ��T8  
	u16 DD_MTAlarmTime;//��ͰԤ��ʱ��
	//����С����������
	u16 JNC_JSQ_CloseDlyTime;// ��ɴ���ر���ʱ  �����ɵ��رռ�ɴ����ʱ��0.1s
	u16 JNC_TL_StayTime;// ͹����פ��ʱ��0.1s
	u16 JNC_SBS_CheckDlyTime;// �ϲ�ɴ�߼����ʱ0.1s
	u16 JNC_XBS_CheckDlyTime;// �²�ɴ�߼����ʱ0.1s
	u16 JNC_ST_UpDlyTime;// Ͳ��̧����ʱ0.1s
	u16 JNC_LL_SpdCtl;// ��ת��������ٹ���
	u16 JNC_LL_F1;// ��ת�����ٶ�1
	u16 JNC_LL_F2;// ��ת�����ٶ�2
	u16 JNC_LL_F3;// ��ת�����ٶ�3
	u16 JNC_LL_F4;// ��ת�����ٶ�4
	u16 JNC_LL_F5;// ��ת�����ٶ�5
	u16 JNC_LL_F6;// ��ת�����ٶ�6
	u16 JNC_LL_F7;// ��ת�����ٶ�7
	u16 JNC_LL_F8;// ��ת�����ٶ�8
	u16 JNC_LL_FwdTime;//��ת������תʱ��
	u16 JNC_LL_StartDlyTime;//��ת���������ӳ�
	u16 JNC_LL_QGOut_DlyTime;//��ת������������ӳ�
	u16 JNC_DXZ_XiShaTimeLT;//��������ɴʱ�䣨����L��T��LL��TT����ʱ��
	u16 JNC_DXZ_XiShaTimeHD;//��������ɴʱ��HD
	u16 JNC_SLQJ_OpenTime;//��������ʱ��
	u16 JNC_SLQJ_ColseTime;//�������ر�ʱ��
	u16 JNC_SLQJ_Time;//�������ʱ��
	u16 JNC_XXZ_JiaNianTime;//С��������ն�ʱ
	u16 JNC_XXZ_XiShaTime;//С������ɴ���ն�ʱ
	
	//��ɴС����������
	u16 LSC_TL_StayTime;// ͹����פ��ʱ��0.1s
	u16 LSC_RTJS_Time;// ��Ͳ��ɴʱ��0.01s
	u16 LSC_RTJS_Spd;// ��Ͳ��ɴ�ٶ�0.1rpm
	u16 LSC_ST_Mode;// ������ͷģʽ --- �Զ�����ģʽ 0-��ֹ 1-����
	u16 LSC_DB_OpenTime;// Ͳ�ӵ��忪��ʱ��0.1s
	u16 LSC_Manual_Mode;//�ֶ�ģʽ - 0-λ��ֹͣ  1-΢��ģʽ
	u16 LSC_Display_7;// 7����ʾ  0-��ǰ��ɴ����  1-Ŀ�굥��  2-͹������
	u16 LSC_SLQJ_EN;// ��������ʹ��  0-�ر�  1-����
	u16 LSC_YJ_OpenTime;// ҡ�ܴ�ʱ�� 0.1s
	u16 LSC_YARN_OpenDlyTime;//��ɴ��⴫�������ӳ� 0.01s
	u16 LSC_YARN_CloseDlyTime;//��ɴ��⴫�����ر��ӳ� 0.01s
	u16 LSC_YARN_CheckTime;//��ɴ��⴫�����ж�ʱ�� 0.1s
	u16 LSC_TQJS_BY;//������ǰ����
	u16 LSC_TQJS_LT;//��Ͳ��ǰ����

	//ϵͳ����
	u16 NodeNum;//�豸����	
	u16 JNC_CFG;//����С������  ȡ4��λ��ÿ��λ����һ̨����С��
	u16 JNC_S[4];//����С��1��ʼ����
	u16 JNC_E[4];//����С��1��������
	u16 JNC_SpdH;//����С�������ٶ�--����
	u16 JNC_SpdM;//����С�������ٶ�--����
	u16 JNC_SpdL;//����С�������ٶ�--����
	u16 JNC_TL_Spd;//����С��͹���ٶ�
	u16 JNC_DJ_Spd;//����С��������ٶ�
	u16 JNC_DXZ_WaitPos;//����������Ƭ覴õ��С��������ʱ����������λ��
	u16 JNC_JNJGQ;//��Ӽ��������
	u16 LSC_S1;//��ɴС��1��ʼ����
	u16 LSC_E1;//��ɴС��1��������
	u16 LSC_GGDEV_RunMode;//����װ����תģʽ --- 
	u16 LSC_GGDEV_EmptyFillMode;//�չܲ���ģʽ --- �򹩹�װ���ƶ�ģʽ 0-ɴ���ϲ�ȴ�� 1-ɴ��ȱ��
	u16 LSC_HSpd;//��ɴС�������ٶ�
	u16 LSC_MSpd;//��ɴС�������ٶ�
	u16 LSC_LSpd;//��ɴС�������ٶ�
	u16 MFJ_CFG;//������������� �Զ�/�ֶ�
	u16 SFJ_CFG;//������������� �Զ�/�ֶ�

	//���������������趨
	u16 STOP_AVG_ShortPeriod;//�����ھ��ȶ�ǿ��ֹͣ
	u16 STOP_AVG_CV;//CV���ȶ�ǿ��ֹͣ
	u16 STOP_HD;//HD �෢ǿ��ֹͣ
	u16 STOP_HD_Thd;//HD �෢��ֵ
	u16 STOP_DS;//��ɴǿ��ֹͣ
	u16 STOP_DS_TimeThd;//��ɴ�෢ʱ����ֵ
	u16 STOP_DS_CntThd;//��ɴ�෢��������
	u16 STOP_SL;//��������ֹͣ
	u16 STOP_SL_TimeThd;//��������ʱ��
	u16 STOP_ReleaseTime;//ǿ��ֹͣ���ʱ��
	u16 ERR_DectMode;//�쳣���ʱ����ģʽ
	u16 STOP_TEN_RefValErr;//������׼ֵ����ǿ��ֹͣ
	u16 STOP_TEN_RefValErrThd;//������׼ֵ�����
	u16 LL1_SpdErrThd;//���ٱ�������1
	u16 LL2_SpdErrThd;//���ٱ�������2
	u16 LL3_SpdErrThd;//���ٱ�������3
	u16 LL4_SpdErrThd;//���ٱ�������4
	u16 MFJ_HP;//�����ѹ������
	u16 MFJ_LP;//�����ѹ������
	u16 MFJ_AlarmThd;//�����ѹ����������
	u16 SFJ_HP;//�����ѹ������
	u16 SFJ_LP;//�����ѹ������
	u16 SFJ_AlarmThd;//�����ѹ����������
}SysPar_t;

typedef struct{
	//����
	u16 DD_QJ1_T1; // ���1_T1
	u16 DD_QJ1_T2; // ���1_T2
	u16 DD_QJ1_T3; // ���1_T3
	u16 DD_QJ1_T4; // ���1_T4
	u16 DD_QJ1_T5;// ���1_T5
	u16 DD_QJ1_T6;//���1_T6
	u16 DD_QJ1_T7;//���1_T7
	u16 DD_QJ1_T8;//���1_T8
	u16 DD_QJ1_T9; //���1_T9
	u16 DD_QJ1_T10; // ���1_T10
	u16 DD_QJ1_T11; // ���1_T11
	u16 DD_WT_T1; //�ȴ�_T1
	u16 DD_WT_T2;// �ȴ�_T2
	u16 DD_WT_T3;//�ȴ�_T3
	u16 DD_QJ2_T1;//���2_T1
	u16 DD_QJ2_T2;//���2_T2
	u16 DD_QJ2_T3; //���2_T3
	u16 DD_QJ2_T4; //���2_T4
	u16 DD_QJ2_T5; //���2_T5
	u16 DD_QJ2_T6; //���2_T6
	u16 DD_NJ_T1;// ���_T1
	u16 DD_NJ_T2;//���_T2
	u16 DD_NJ_T3;//���_T3
	u16 DD_NJ_T4;//���_T4
	u16 DD_NJ_T5; //���_T5
	u16 DD_NJ_T6; //���_T6
	u16 DD_NJ_T7; //���_T7
	u16 DD_NJ_T8; //���_T8


	//��β
	u16 JW_P01;//
	u16 JW_P02;//
	u16 JW_P03;//
	u16 JW_P04;//
	u16 JW_P05;//
	u16 JW_P06;//
	u16 JW_P07;//
	u16 JW_P08;//

}DbgPar_t;



//��ɴ����
typedef struct _QsPar_s
{
	//idx = 0
	u16 P01_0;//	ɴ���ٶ�
	u16 P01_1;//	ɴ�ߺ���
	u16 P02;//��ͷ��������
	u16 P03;//����ֱ��+����
	u16 P04;//ϸ��ֱ��+����
	//idx = 1
	u16 P11;	//SL1ֱ��D1+����L1
	u16 P12;//SL2ֱ��D2+����L2
	u16 P13;//SL3ֱ��D3+����L3
	u16 P14;//SL4ֱ��D4+����L4
	//idx = 2
	u16 P21;	//SL5ֱ��D5+����L5
	u16 P22;//HDdֱ��D6+����L6
	u16 P23;//TL1ֱ��D7+����L7
	u16 P24;//TL2ֱ��D8+����L8
	//idx = 3
	u16 P31;	//TL3ֱ��D9+����L9
	u16 P32_0;//��״ɴ��ֱ��
	u16 P32_1;//��״����mm
	u16 P33_0;//��״ɴ�ø���
	u16 P33_1;//��ⳤ��cm
	u16 P34_0;//��ɴ������
	u16 P34_1;//
}QsPar_t;




/////////////////////////////////////////////////////////////////////////////////////

typedef struct _StsVFD_s
{
	u16 Dat1;//���Ƶ��0.00`655.35  hz
	u16 Dat2;//���������Чֵ 0.00`399.99   0.01 %
	u16 Dat3;//�����ѹ��Чֵ0.00`1000.0   0.1 %
	u16 Dat4;//���Ĺ���0.00`399.99 0.01 %
	u16 Dat5;
}StsVFD_t;


//��ͷ״̬
typedef struct _StatusJT_s
{
	u16 RunSts;//����״̬0-�ϵ� 1-ͣ�� 2-���� 3-����
	u16 NP_MFan;//�������ѹ
	u16 NP_SFan;//�������ѹ
	u16 SpdFk_LL1;//��������1   0.1m/min
	u16 SpdFk_LL2;//��������2  0.1m/min
	u16 SpdFk_LL3;//��������3 0.1m/min
	u16 SpdFk_LL4;//��������4  0.1m/min
	u8 ERR1;//������Ԫ1  --- ��Ƶ������λ����λ��ʼ��ÿһλ����һ����Ƶ����������
	u8 ERR2;//������Ԫ2
	u8 ERR3;//������Ԫ3
	u8 ERR4;//������Ԫ4
	u8 ERR5;//������Ԫ5
	u8 ERR6;//������Ԫ6
	u8 ERR7;//������Ԫ7
	u8 ERR8;//������Ԫ8
	u8 ERR9;//������Ԫ9
	u8 ERR10;//������Ԫ10

	StsVFD_t VFD1;
	StsVFD_t VFD2;
	StsVFD_t VFD3;
	StsVFD_t VFD4;
	StsVFD_t VFD5;
	StsVFD_t VFD6;
	StsVFD_t VFD7;
	
	
}StatusJT_t;


//��β״̬
typedef struct _StsJW_s
{
	u8 Sts;//״̬
	u8 Err;//����
	u8 Version;//�汾
	u8 ComErr;//ͨ��״̬
	u16 Ang1;//ģ����1
	u16 Ang2;//ģ����2
	u16 Input;//����״̬
	u16 Output;//���״̬
}StatusJW_t;



//����״̬
typedef struct _StsDD_s
{
	u8 Version;// �汾
	u8 Sts;//״̬
	u8 Err;//����
	u8 ComSts;//0-ͨ������   1-ͨ�Ŵ���
	u32 CurLen;//��ǰ����
	u16 Xspd;//���ٶ�
	u16 Tension;//����
	u16 LLSpd3;//��3�����ٶ�
	u16 LLSpd4;//��4�����ٶ�
	u16 SLSpd;//�����ٶ�
	u16 CSSpd;//��ɴ�ٶ�
	u8 InputByte1;//����λ1
	u8 OutputByte1;//���λ1
	u8 OutputByte2;//���λ2
	u8 ComByte;//ͨ��λ
	u8 Ads;//����
	u8 State;//״̬��
	u8 InputByte2;//����λ2
	u8 StateByte;//״̬��λ
	u8 DebugData[16];//��������
}StsDD_t;

//��ɴ̽ͷ״̬
typedef struct _StsQS_s
{
	u8 Sts;//״̬
	u32 CV;//
	u8 CVs;//ë��
	u8 Noise;//����ֵ
	u8 Sensitivity;//������ֵ
	u8 Version;//�汾
	u16 Zero;//���
	u8 Driver;//����
	u8 Dust;//����
	u16 Avg;//ʵʱ��ֵ
	u16 Avg_Ref;//�ο���ֵ
	u8 DebugData[16];//��������
}StsQS_t;

//����״̬
typedef struct _StatusNode_s
{
	u8 Version;  //���ڰ�汾
	u8 ComErr;//ͨ��״̬
	u8 Version2[4];//һ�ض��汾
	StsDD_t DdSts[8];
	StsQS_t QsSts[8];
}StatusNode_t;

//AD С��״̬
typedef struct _StatusAD_s
{
	u8 Version;  //�汾
	u8 ComErr;//ͨ��״̬
	u8 Sts;//״̬
	u8 Err;//����
	u8 PosCur;//��ǰλ��
	u8 EmptyNum;//���Ͽչ�����
}StatusAD_t;

//����С��״̬
typedef struct _StatusJN_s
{
	u8 Version;  //�汾
	u8 ComErr;//ͨ��״̬
	u8 Sts;//״̬
	u8 Err;//����
	u8 PosCur;//��ǰλ��

	StsQS_t QsSts;
}StatusJN_t;


typedef struct _Status_s
{
	StatusJT_t JT;
	StatusJW_t JW[2];
	StatusNode_t Node[12];
	StatusJN_t JN[4];
	StatusAD_t AD;
}Status_t;


typedef struct{
	u8 pLen;
	u8 Index;
	u16 data[AVG_BUF_LEN_MAX];
	u32 add;
	u16 In;
	u16 Out;
}DataAvg_t;

typedef struct{
	u16 Index;
	u16 Size;
	u32 Max;
	u32 Min;
	u32 Default;
	u16 RstFlag;
}ParInitVar_t;


extern Status_t gStatus;
extern SysPar_t gSysPar;
extern DbgPar_t gDbgPar;
extern QsPar_t gQsPar;
extern DataAvg_t gSpdLL1;
extern DataAvg_t gSpdLL2;
extern DataAvg_t gSpdLL3;
extern DataAvg_t gSpdLL4;



u16 check_crc16(u8 *puchMsg, u16 usDataLen) ;
u16 sum_check(u8 * dpin,u16 len);
void data_avg_init(DataAvg_t *dp);
void data_avg_macro(DataAvg_t *dp);
void fill_data_flash(u8 type, u8 idx_s, u8 idx_e,u8 idx_s2, u8 idx_e2);
void fill_data_set(u8 type, u8 idx);
void data_upate_status(void);
void data_init(void);
#endif
