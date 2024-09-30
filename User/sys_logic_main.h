#ifndef __sys_logic_main_h
#define __sys_logic_main_h

#include "sys_bsp.h"
#include "api_request.h"

#define LLF_D 32  //   前罗拉直径  mm   
#define LLM_D 27  //   中罗拉直径  mm   + 皮套厚度mm   25+2
#define LL3_D 25  //   第三罗拉直径  mm   
#define LL4_D 25  //   第四罗拉直径  mm   
#define CW_D 65  //   喂纱罗拉直径  mm   
#define JR_D 80   //   卷绕直径  mm   

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

// 变频器每一圈对应多少频率 (0.01Hz)
#define LLF_HzPR 3.33333333333333f  //  前罗拉 4 极 ，1500rpm 对应50hz   ----VFD 内部闭环
#define LLM_HzPR 3.33333333333333f  //  中罗拉 4 极 ，1500rpm 对应50hz   ----VFD 内部闭环
#define HD_HzPR 3.6231884057971f  //  横动4 极 ，1380rpm 对应50hz   ----VFD 开环
#define JR_HzPR 3.33333333333333f  //  卷绕4 极 ，1500rpm 对应50hz   ----VFD 内部闭环
#define MFJ_HzPR 1.70357751277683f  //  主风机2极 ，2935rpm 对应50hz   ----VFD 开环
#define SFJ_HzPR 1.71821305841924f  //  副风机2极 ，2910rpm 对应50hz   ----VFD 开环
#define PG_HzPR 3.57142857142857f  //  打包机4极 ，1400rpm 对应50hz   ----VFD 开环

//机械齿轮比
#define LLF_GEAR 0.3793103448275862f //  电机转速 * 58/22  = 输出轴
#define LLM_GEAR 7.43801652892562f //  电机转速 * (22*22)/(60*60)  = 输出轴
#define HD_GEAR 3.5714285714285714f //  电机转速 * 14/50  = 输出轴
#define JR_GEAR 1.0f //  电机转速 * 36/36  = 卷绕轴


#define HD_LEN 0.154f  //m
#define HD_LENn 6.493506493506494f  


enum {
	STS_POWER_UP = 0,
	STS_WAIT = 1,
	STS_RUN = 2,
	STS_TEST = 3,
};


enum {
	VFD_LLM = 0, //中罗拉
	VFD_LLF = 1,//前罗拉
	VFD_HD = 2,//横动
	VFD_JR= 3,//横动
	VFD_MFJ= 4,//主风机
	VFD_SFJ= 5,//副风机
	VFD_PG= 6,//打包机
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
	// 换管请求
	request_t RequestNew;
	request_t* pRequestExec;//当前执行请求  ，ads = 0表示小车空闲
	request_t* pRequestTemp;//
	
	u8 FlagNew;//新命令
	u8 FlagDone;//  1-正常完成  2- AD 有报警
	u8 FlagCancel;//取消请求命令
	u8 FlagRequest;//请求命令
	u8 FlagUpdate;//
	u8 FlagTransErr;
	u8 FlagIsEmpty;// 0-小车有空管   1- 小车没有空管

	u8 TransSts;// 0- 命令传输完毕 
				// 1-传输请求命令中 
				//  2- 传输取消命令中	
				//  3- 收到请求命令回复
				//  4- 收到取消命令回复
	u16 TransDlyTicker;  //发送间隔ticker
	u8 TransCnt;//发送次数

	u8 CurAds;//  小车当前位置 
	u8 PreAds;//  小车上一个时刻位置 
	u8 EmptyNum;//小车上空管数量

	
	u16 TotalCnt;//请求计数
	u16 RequestCnt;//请求计数
	u16 CancelCnt;//取消计数
	u16 DoneCnt;//完成计数
	u16 DoneCnt_OK;//正确完成计数
	u16 DoneCnt_ERR;//完成出错计数

}AD_Ctl_t;

typedef struct _JN_Ctl_s
{
	// 接头请求
	request_t RequestNew;
	request_t* pRequestExec[4];//当前执行请求  ，ads = 0表示小车空闲
	request_t* pRequestTemp[4];//
	
	u8 FlagNew;//新命令
	u8 FlagDone[4];//  1-正常完成  2- 有报警
	u8 FlagCancel[4];//取消请求命令
	u8 FlagRequest[4];//请求命令
	u8 FlagUpdate[4];//
	u8 FlagTransErr[4];

	u8 TransSts[4];// 0- 命令传输完毕 
				// 1-传输请求命令中 
				//  2- 传输取消命令中	
				//  3- 收到请求命令回复
				//  4- 收到取消命令回复
	u16 TransDlyTicker[4];  //发送间隔ticker
	u8 TransCnt[4];//发送次数



	u8 CurAds[4];//  小车1当前位置 
	u8 PreAds[4];//  小车上一个时刻位置 
	// 换管请求
	u16 CancelCnt;//取消计数
	u16 TotalCnt[4];//请求计数
	u16 RequestCnt[4];//请求计数
	u16 DoneCnt[4];//完成计数
	u16 DoneCnt_OK[4];//正确完成计数
	u16 DoneCnt_ERR[4];//完成出错计数

}JN_Ctl_t;


typedef struct _SysCtlVal_s
{

	//AD 小车控制
	AD_Ctl_t AD_Ctl;
	//JN 小车控制
	JN_Ctl_t JN_Ctl;


	u16 Sts;
	u16 Ticker;

	//给定
	u16 XSPD_Gvn;//纱线速度rpm  
	u16 TDR_Gvn;//总牵伸比TDR  摩擦罗拉和第四罗拉的速度比0.1
	u16 MDR_Gvn;//主牵伸比MDR  摩擦罗拉和中罗拉之间的速比0.1
	u16 BDR_Gvn;//后牵伸比BDR 第三罗拉和第四罗拉之间的速比0.1
	u16 WDR_Gvn;//喂入比 WDR 摩擦罗拉和前罗拉之间的速比0.001
	u16 JDR_Gvn;//收卷比JDR 卷取槽筒和摩擦罗拉之间速比0.001
	u16 BR_Gvn;//起始率BR在捻接或生产过程中后罗拉速度的变换比％
	u16 JANG_Gvn;//横动角度

	u16 MFJ_Fre_Gvn;//主风机频率
	u16 SFJ_Fre_Gvn;//副风机频率

	
	float XSPD;//纱线速度rpm  
	float TDR;//总牵伸比TDR  摩擦罗拉和第四罗拉的速度比0.1
	float MDR;//主牵伸比MDR  摩擦罗拉和中罗拉之间的速比0.1
	float BDR;//后牵伸比BDR 第三罗拉和第四罗拉之间的速比0.1
	float WDR;//喂入比 WDR 摩擦罗拉和前罗拉之间的速比0.001
	float JDR;//收卷比JDR 卷取槽筒和摩擦罗拉之间速比0.001
	float BR;//起始率BR在捻接或生产过程中后罗拉速度的变换比％
	float JANG;//横动角度


	float JR_Xspd;//摩擦罗拉线速度m/min
	float JR_Spd;// 卷绕速度  rpm
	float CW_Xspd;//摩擦罗拉线速度m/min
	float CW_Spd;// 超喂速度  rpm
	float LLF_Xspd;//前罗拉线速度m/min
	float LLF_Spd;// 前罗拉速度  rpm
	float LLM_Xspd;//中罗拉线速度m/min
	float LLM_Spd;// 中罗拉速度  rpm
	float LL3_Xspd;//中罗拉线速度m/min
	float LL3_Spd;//  3 罗拉速度  rpm
	float LL4_Xspd;//中罗拉线速度m/min
	float LL4_Spd;//  4 罗拉速度  rpm	
	float HD_Xspd;//摩擦罗拉线速度m/min
	float HD_Spd;// 卷绕速度  rpm
	float HD_Fre;//横动频率 0.01hz

	float FD_Rre;//防叠频率 0.01hz

	u16 FD_Sts;
	u32 FD_Ticker;
	u32 FD_HT;
	u32 FD_LT;

	//变频控制输出
	u16 FreGvn[10];// 0.01hz
	u16 FreOut[10];// 0.01hz
	u8 Son[10];//变频器启停控制 0-停机  1-启动
	u8 SonBk[10];


	//测试功能
	u8 TestMode;// 0-调试模式关闭   1- 调试模式开启
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
	union SYS_CTL TestCtl1;//变频器启停控制 0-停机  1-启动
	union SYS_CTL TestCtl1Bk;
	union SYS_CTL TestCtl2;//输出口Y017 ~Y010	
	union SYS_CTL TestCtl2Bk;
	union SYS_CTL TestCtl3;//输出口Y01F ~Y018	
	union SYS_CTL TestCtl3Bk;	
	union SYS_CTL TestCtl4;//输出口Y027 ~Y020	
	union SYS_CTL TestCtl4Bk;	
	union SYS_CTL TestCtl5;//输出口Y02F ~Y028	
	union SYS_CTL TestCtl5Bk;	
	union SYS_CTL TestCtl6;	
	union SYS_CTL TestCtl6Bk;	
	union SYS_CTL TestCtl7;	
	union SYS_CTL TestCtl8;
	union SYS_CTL TestCtl9;
	union SYS_CTL TestCtl10;
	union SYS_CTL TestCtl11;

	//清零功能
	u8 ClrCmd;//命令
	u8 ClrType;//类型
	u8 ClrAds;//锭号

	//班产功能
	u32 BanSum_Len[MAX_NODE_NUM];//长度m
	u32 BanSum_Weight[MAX_NODE_NUM];//重量g
	u16 BanSum_Ds[MAX_NODE_NUM];//断头数量
	u16 BanSum_Mt[MAX_NODE_NUM];//满桶数量
	u16 BanSum_Xc[MAX_NODE_NUM];//瑕疵数量
	
	//打样控制
	u16 DY_En;

	//清纱
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
