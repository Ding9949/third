#ifndef __sys_logic_main_h
#define __sys_logic_main_h

#include "sys_bsp.h"
#include "api_request.h"

#define LLF_D 32  //   ǰ����ֱ��  mm   
#define LLM_D 27  //   ������ֱ��  mm   + Ƥ�׺��mm   25+2
#define LL3_D 25  //   ��������ֱ��  mm   
#define LL4_D 25  //   ��������ֱ��  mm   
#define CW_D 65  //   ιɴ����ֱ��  mm   
#define JR_D 80   //   ����ֱ��  mm   

#define LLF_C    0.1005309632f
#define LLF_Cn    9.947184112924126f  //  1/LLF_C
#define LLM_C    0.0848230002f
#define LLM_Cn    11.78925524494711f
#define LL3_C    0.078539815f
#define LL3_Cn    12.73239566454288f
#define LL4_C    0.078539815f
#define LL4_Cn    12.73239566454288f
#define CW_C    0.204203519f
#define CW_Cn    4.897075255593416f
#define JR_C    0.251327408f
#define JR_Cn    3.978873645169651f

// ��Ƶ��ÿһȦ��Ӧ����Ƶ�� (0.01Hz)
#define LLF_HzPR 3.33333333333333f  //  ǰ���� 4 �� ��1500rpm ��Ӧ50hz   ----VFD �ڲ��ջ�
#define LLM_HzPR 3.33333333333333f  //  ������ 4 �� ��1500rpm ��Ӧ50hz   ----VFD �ڲ��ջ�
#define HD_HzPR 3.6231884057971f  //  �ᶯ4 �� ��1380rpm ��Ӧ50hz   ----VFD ����
#define JR_HzPR 3.33333333333333f  //  ����4 �� ��1500rpm ��Ӧ50hz   ----VFD �ڲ��ջ�
#define MFJ_HzPR 1.70357751277683f  //  �����2�� ��2935rpm ��Ӧ50hz   ----VFD ����
#define SFJ_HzPR 1.71821305841924f  //  �����2�� ��2910rpm ��Ӧ50hz   ----VFD ����
#define PG_HzPR 3.57142857142857f  //  �����4�� ��1400rpm ��Ӧ50hz   ----VFD ����

//��е���ֱ�
#define LLF_GEAR 0.3793103448275862f //  ���ת�� * 58/22  = �����
#define LLM_GEAR 7.43801652892562f //  ���ת�� * (22*22)/(60*60)  = �����
#define HD_GEAR 3.5714285714285714f //  ���ת�� * 14/50  = �����
#define JR_GEAR 1.0f //  ���ת�� * 36/36  = ������


#define HD_LEN 0.154f  //m
#define HD_LENn 6.493506493506494f  


enum {
	STS_POWER_UP = 0,
	STS_WAIT = 1,
	STS_RUN = 2,
	STS_TEST = 3,
};


enum {
	VFD_LLM = 0, //������
	VFD_LLF = 1,//ǰ����
	VFD_HD = 2,//�ᶯ
	VFD_JR= 3,//�ᶯ
	VFD_MFJ= 4,//�����
	VFD_SFJ= 5,//�����
	VFD_PG= 6,//�����
};


struct SYS_CTL_BIT
{
	u8 ctl0:1;
	u8 ctl1:1;
	u8 ctl2:1;
	u8 ctl3:1;
	u8 ctl4:1;
	u8 ctl5:1;
	u8 ctl6:1;
	u8 ctl7:1;
};

union SYS_CTL
{
	u8 all;
	struct SYS_CTL_BIT bit;
};

typedef struct _AD_Ctl_s
{
	// ��������
	request_t RequestNew;
	request_t* pRequestExec;//��ǰִ������  ��ads = 0��ʾС������
	request_t* pRequestTemp;//
	
	u8 FlagNew;//������
	u8 FlagDone;//  1-�������  2- AD �б���
	u8 FlagCancel;//ȡ����������
	u8 FlagRequest;//��������
	u8 FlagUpdate;//
	u8 FlagTransErr;
	u8 FlagIsEmpty;// 0-С���пչ�   1- С��û�пչ�

	u8 TransSts;// 0- �������� 
				// 1-�������������� 
				//  2- ����ȡ��������	
				//  3- �յ���������ظ�
				//  4- �յ�ȡ������ظ�
	u16 TransDlyTicker;  //���ͼ��ticker
	u8 TransCnt;//���ʹ���

	u8 CurAds;//  С����ǰλ�� 
	u8 PreAds;//  С����һ��ʱ��λ�� 
	u8 EmptyNum;//С���Ͽչ�����

	
	u16 TotalCnt;//�������
	u16 RequestCnt;//�������
	u16 CancelCnt;//ȡ������
	u16 DoneCnt;//��ɼ���
	u16 DoneCnt_OK;//��ȷ��ɼ���
	u16 DoneCnt_ERR;//��ɳ������

}AD_Ctl_t;

typedef struct _JN_Ctl_s
{
	// ��ͷ����
	request_t RequestNew;
	request_t* pRequestExec[4];//��ǰִ������  ��ads = 0��ʾС������
	request_t* pRequestTemp[4];//
	
	u8 FlagNew;//������
	u8 FlagDone[4];//  1-�������  2- �б���
	u8 FlagCancel[4];//ȡ����������
	u8 FlagRequest[4];//��������
	u8 FlagUpdate[4];//
	u8 FlagTransErr[4];

	u8 TransSts[4];// 0- �������� 
				// 1-�������������� 
				//  2- ����ȡ��������	
				//  3- �յ���������ظ�
				//  4- �յ�ȡ������ظ�
	u16 TransDlyTicker[4];  //���ͼ��ticker
	u8 TransCnt[4];//���ʹ���



	u8 CurAds[4];//  С��1��ǰλ�� 
	u8 PreAds[4];//  С����һ��ʱ��λ�� 
	// ��������
	u16 CancelCnt;//ȡ������
	u16 TotalCnt[4];//�������
	u16 RequestCnt[4];//�������
	u16 DoneCnt[4];//��ɼ���
	u16 DoneCnt_OK[4];//��ȷ��ɼ���
	u16 DoneCnt_ERR[4];//��ɳ������

}JN_Ctl_t;


typedef struct _SysCtlVal_s
{

	//AD С������
	AD_Ctl_t AD_Ctl;
	//JN С������
	JN_Ctl_t JN_Ctl;


	u16 Sts;
	u16 Ticker;

	//����
	u16 XSPD_Gvn;//ɴ���ٶ�rpm  
	u16 TDR_Gvn;//��ǣ���TDR  Ħ�������͵����������ٶȱ�0.1
	u16 MDR_Gvn;//��ǣ���MDR  Ħ��������������֮����ٱ�0.1
	u16 BDR_Gvn;//��ǣ���BDR ���������͵�������֮����ٱ�0.1
	u16 WDR_Gvn;//ι��� WDR Ħ��������ǰ����֮����ٱ�0.001
	u16 JDR_Gvn;//�վ��JDR ��ȡ��Ͳ��Ħ������֮���ٱ�0.001
	u16 BR_Gvn;//��ʼ��BR����ӻ����������к������ٶȵı任�ȣ�
	u16 JANG_Gvn;//�ᶯ�Ƕ�

	u16 MFJ_Fre_Gvn;//�����Ƶ��
	u16 SFJ_Fre_Gvn;//�����Ƶ��

	
	float XSPD;//ɴ���ٶ�rpm  
	float TDR;//��ǣ���TDR  Ħ�������͵����������ٶȱ�0.1
	float MDR;//��ǣ���MDR  Ħ��������������֮����ٱ�0.1
	float BDR;//��ǣ���BDR ���������͵�������֮����ٱ�0.1
	float WDR;//ι��� WDR Ħ��������ǰ����֮����ٱ�0.001
	float JDR;//�վ��JDR ��ȡ��Ͳ��Ħ������֮���ٱ�0.001
	float BR;//��ʼ��BR����ӻ����������к������ٶȵı任�ȣ�
	float JANG;//�ᶯ�Ƕ�


	float JR_Xspd;//Ħ���������ٶ�m/min
	float JR_Spd;// �����ٶ�  rpm
	float CW_Xspd;//Ħ���������ٶ�m/min
	float CW_Spd;// ��ι�ٶ�  rpm
	float LLF_Xspd;//ǰ�������ٶ�m/min
	float LLF_Spd;// ǰ�����ٶ�  rpm
	float LLM_Xspd;//���������ٶ�m/min
	float LLM_Spd;// �������ٶ�  rpm
	float LL3_Xspd;//���������ٶ�m/min
	float LL3_Spd;//  3 �����ٶ�  rpm
	float LL4_Xspd;//���������ٶ�m/min
	float LL4_Spd;//  4 �����ٶ�  rpm	
	float HD_Xspd;//Ħ���������ٶ�m/min
	float HD_Spd;// �����ٶ�  rpm
	float HD_Fre;//�ᶯƵ�� 0.01hz

	float FD_Rre;//����Ƶ�� 0.01hz

	u16 FD_Sts;
	u32 FD_Ticker;
	u32 FD_HT;
	u32 FD_LT;

	//��Ƶ�������
	u16 FreGvn[10];// 0.01hz
	u16 FreOut[10];// 0.01hz
	u8 Son[10];//��Ƶ����ͣ���� 0-ͣ��  1-����
	u8 SonBk[10];


	//���Թ���
	u8 TestMode;// 0-����ģʽ�ر�   1- ����ģʽ����
	u16 TestFre1;// 0.01hz
	u16 TestFre1Bk;
	u16 TestFre2;// 0.01hz
	u16 TestFre2Bk;
	u16 TestFre3;// 0.01hz
	u16 TestFre3Bk;
	u16 TestFre4;// 0.01hz
	u16 TestFre4Bk;
	u16 TestFre5;// 0.01hz
	u16 TestFre5Bk;
	u16 TestFre6;// 0.01hz
	u16 TestFre6Bk;
	u16 TestFre7;// 0.01hz
	u16 TestFre7Bk;
	union SYS_CTL TestCtl1;//��Ƶ����ͣ���� 0-ͣ��  1-����
	union SYS_CTL TestCtl1Bk;
	union SYS_CTL TestCtl2;//�����Y017 ~Y010	
	union SYS_CTL TestCtl2Bk;
	union SYS_CTL TestCtl3;//�����Y01F ~Y018	
	union SYS_CTL TestCtl3Bk;	
	union SYS_CTL TestCtl4;//�����Y027 ~Y020	
	union SYS_CTL TestCtl4Bk;	
	union SYS_CTL TestCtl5;//�����Y02F ~Y028	
	union SYS_CTL TestCtl5Bk;	
	union SYS_CTL TestCtl6;	
	union SYS_CTL TestCtl6Bk;	
	union SYS_CTL TestCtl7;	
	union SYS_CTL TestCtl8;
	union SYS_CTL TestCtl9;
	union SYS_CTL TestCtl10;
	union SYS_CTL TestCtl11;

	//���㹦��
	u8 ClrCmd;//����
	u8 ClrType;//����
	u8 ClrAds;//����

	//�������
	u32 BanSum_Len[MAX_NODE_NUM];//����m
	u32 BanSum_Weight[MAX_NODE_NUM];//����g
	u16 BanSum_Ds[MAX_NODE_NUM];//��ͷ����
	u16 BanSum_Mt[MAX_NODE_NUM];//��Ͱ����
	u16 BanSum_Xc[MAX_NODE_NUM];//覴�����
	
	//��������
	u16 DY_En;

	//��ɴ
	u16 CVAvg;
}SysCtlVal_t;

extern SysCtlVal_t gSysCtlVal;

extern void (*Sys_Logic_Ptr) (void);

void sys_logic_ad(void);
void sys_logic_jn(void);
void sys_logic_wait(void);
void sys_logic_test(void);
void sys_logic_run(void);
void sys_logic_main(void);

#endif
