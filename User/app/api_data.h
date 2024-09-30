#ifndef __api_data_h
#define __api_data_h

#include "sys_bsp.h"

#define AVG_BUF_LEN_MAX 32
#define MAX_SYSPAR_NUM (sizeof(SysPar_t)>>1)
#define MAX_QSPAR_NUM (sizeof(QsPar_t)>>1)
#define MAX_DBGPAR_NUM (sizeof(DbgPar_t)>>1)

enum {
	DAT_DJ = 0,  //机身单节
	DAT_JW,//机尾
	DAT_QS,//清纱
	DAT_JN,//接捻小车
	DAT_QS1,//清纱1 - 接捻小车
	DAT_AD//落纱小车
};

/////////////////////////////////////////////////////////////////////////////////////
typedef struct _SysPar_s
{
	//生产设置
	u16 INDEX;
	u16 SX_Type;//纱线种类
	u16 SZS_Type;//纱支数类型
	u16 SZS_Num;//纱支数
	u32 MT_Len;//满桶长度 m
	u16 MT_Weight_g;//满桶重量克
	u16 MT_Weight_b;//满桶重量磅
	u16 DZ_ContinueGQ;//锭子持续给气开关
	u16 RES1;
	u16 DY_StartDW;//打样用定长开始锭位0-不使用该功能
	u16 DY_StopDW;//打样用定长结束锭位0-不使用该功能
	u32 DY_Len;//打样满桶长度 m
	//纺纱设置
	u16 XSPD;//纱线速度0.1rpm  
	u16 TDR;//总牵伸比TDR  摩擦罗拉和第四罗拉的速度比0.1
	u16 MDR;//主牵伸比MDR  摩擦罗拉和中罗拉之间的速比0.1
	u16 BDR;//后牵伸比BDR 第三罗拉和第四罗拉之间的速比0.1
	u16 WDR;//喂入比 WDR 摩擦罗拉和前罗拉之间的速比0.001
	u16 JDR;//收卷比JDR 卷取槽筒和摩擦罗拉之间速比0.001
	u16 BR;//起始率BR在捻接或生产过程中后罗拉速度的变换比％
	u16 JANG;//横动角度
	//上蜡设置
	u16 SL_En;//上蜡装置开关
	u16 SL_Spd;//上蜡速度
	u16 SL_Dir;//上蜡方向
	//纺纱传感器装置设置
	u16 TEN_En;//纺纱传感器控制装置澹(张力控制)开关
	u16 TEN_HThd;//张力上限报警阈值
	u16 TEN_LThd;//张力下限报警阈值
	u16 TEN_BDThd;//接捻前后，张力波动阈值
	u16 TEN_Reset;//张力复位
	//接捻器设置
	u16 JN_PZType;//选择接捻器喷嘴类型
	u16 JN_JieNianStartTime;//解捻开始时间0.01S
	u16 JN_JieNianTime;//解捻时间  0.01S
	u16 JN_JiaNianStartTime;//加捻开始时间0.01S
	u16 JN_JiaNianTime;//加捻时间  0.01S
	u16 JN_JiaNianStartTime3;// 3段式喷嘴定时启动加捻  0.01S
	u16 JN_JiaNianTime3;// 3段式喷嘴加捻持续时间  0.01S
	u16 JN_LnPos;//Ln杆位置 用于调整捻接起捻接长度。值越大捻接长度越短
	u16 JN_MonitorN;//捻接监控器N%    捻接监控器的N%的粗细设定
	u16 JN_MonitorS;//捻接监控器S%    捻接监控器的S剪切的粗细设定
	u16 JN_MonitorSLen;//捻接监控器Scm   捻接控空气的S剪切的长度设定

	//主机操作设置
	u16 MFJ_Fre;//主鼓风机频率 0.01hz
	u16 SFJ_Fre;//副鼓风机频率 0.01hz
	u16 FD_Rto;//横动放叠墅幅度0.1%
	u16 FD_LT;//横动防叠低速时长 1s
	u16 FD_HT;//横动防叠高速时长1s
	u16 PQ_Time;//排气最长时间1s
	u16 PQ_Period;//排气周期1s
	u16 PQ_OpenTime;//排气打开时间1s
	u16 PQ_CloseTime;//排气关闭时间1s
	u16 LL_AlarmTime;//低气压报警确认时间1min
	u16 HHSD_AlarmTime;//风门关闭，回花箱长期处于手动模式报警确认时间1min
	u16 FM_CloseTime;//旁路风门关闭时间1s
	u16 HH_RunTime;//回花排出装置运行时间 1s
	u16 CFQJ_Period;//吹风清洁间隔  min
	u16 CF_DlyClose;//吹风关闭延迟s
	u16 TransOverTimeThd;// 如果筒纱停留时间超过了筒纱输送带操作运转时间，则灯塔和VOS屏幕中会显示报警
	u16 LL_TimeThd;//静压低压确认时间阈值
	u16 HL_TimeThd;//静压高压确认时间阈值
	//单锭操作设置
	u16 DD_JTTryN; //接头尝试次数
	u16 DD_RedCtl;//面板红灯功能
	u16 DD_TSEn;//探纱使能
	u32 DD_L1;//卷装量L1  m
	u32 DD_L2;//卷装量L2  m
	u32 DD_L3;//卷装量L3  m
	u32 DD_L4;//卷装量L4  m
	u32 DD_L5;//卷装量L5  m
	u32 DD_L6;//卷装量L6  m
	u32 DD_L7;//卷装量L7  m
	u32 DD_L8;//卷装量L8  m
	u16 DD_T1;//摇架抬升时间T1  
	u16 DD_T2;//摇架抬升时间T2  
	u16 DD_T3;//摇架抬升时间T3  
	u16 DD_T4;//摇架抬升时间T4  
	u16 DD_T5;//摇架抬升时间T5  
	u16 DD_T6;//摇架抬升时间T6  
	u16 DD_T7;//摇架抬升时间T7  
	u16 DD_T8;//摇架抬升时间T8  
	u16 DD_MTAlarmTime;//满桶预警时间
	//接捻小车操作设置
	u16 JNC_JSQ_CloseDlyTime;// 夹纱器关闭延时  捻接完成到关闭夹纱器的时间0.1s
	u16 JNC_TL_StayTime;// 凸轮轴驻留时间0.1s
	u16 JNC_SBS_CheckDlyTime;// 上部纱线检测延时0.1s
	u16 JNC_XBS_CheckDlyTime;// 下部纱线检测延时0.1s
	u16 JNC_ST_UpDlyTime;// 筒子抬升延时0.1s
	u16 JNC_LL_SpdCtl;// 反转罗拉多段速功能
	u16 JNC_LL_F1;// 反转罗拉速度1
	u16 JNC_LL_F2;// 反转罗拉速度2
	u16 JNC_LL_F3;// 反转罗拉速度3
	u16 JNC_LL_F4;// 反转罗拉速度4
	u16 JNC_LL_F5;// 反转罗拉速度5
	u16 JNC_LL_F6;// 反转罗拉速度6
	u16 JNC_LL_F7;// 反转罗拉速度7
	u16 JNC_LL_F8;// 反转罗拉速度8
	u16 JNC_LL_FwdTime;//反转罗拉正转时间
	u16 JNC_LL_StartDlyTime;//反转罗拉启动延迟
	u16 JNC_LL_QGOut_DlyTime;//反转罗拉气缸伸出延迟
	u16 JNC_DXZ_XiShaTimeLT;//大吸嘴吸纱时间（发生L、T、LL、TT剪切时）
	u16 JNC_DXZ_XiShaTimeHD;//大吸嘴吸纱时间HD
	u16 JNC_SLQJ_OpenTime;//上蜡清洁打开时间
	u16 JNC_SLQJ_ColseTime;//上蜡清洁关闭时间
	u16 JNC_SLQJ_Time;//上蜡清洁时长
	u16 JNC_XXZ_JiaNianTime;//小吸嘴加捻开闭定时
	u16 JNC_XXZ_XiShaTime;//小吸嘴吸纱开闭定时
	
	//落纱小车操作设置
	u16 LSC_TL_StayTime;// 凸轮轴驻留时间0.1s
	u16 LSC_RTJS_Time;// 绕筒脚纱时间0.01s
	u16 LSC_RTJS_Spd;// 绕筒脚纱速度0.1rpm
	u16 LSC_ST_Mode;// 二次生头模式 --- 自动重试模式 0-禁止 1-开启
	u16 LSC_DB_OpenTime;// 筒子挡板开启时间0.1s
	u16 LSC_Manual_Mode;//手动模式 - 0-位置停止  1-微动模式
	u16 LSC_Display_7;// 7段显示  0-当前纺纱单锭  1-目标单锭  2-凸轮周期
	u16 LSC_SLQJ_EN;// 上蜡吹风使能  0-关闭  1-开启
	u16 LSC_YJ_OpenTime;// 摇架打开时间 0.1s
	u16 LSC_YARN_OpenDlyTime;//上纱检测传感器打开延迟 0.01s
	u16 LSC_YARN_CloseDlyTime;//上纱检测传感器关闭延迟 0.01s
	u16 LSC_YARN_CheckTime;//上纱检测传感器判断时间 0.1s
	u16 LSC_TQJS_BY;//边沿提前减速
	u16 LSC_TQJS_LT;//络筒提前减速

	//系统设置
	u16 NodeNum;//设备节数	
	u16 JNC_CFG;//接捻小车配置  取4个位，每个位代表一台接捻小车
	u16 JNC_S[4];//接捻小车1起始锭号
	u16 JNC_E[4];//接捻小车1结束锭号
	u16 JNC_SpdH;//接捻小车运行速度--高速
	u16 JNC_SpdM;//接捻小车运行速度--中速
	u16 JNC_SpdL;//接捻小车运行速度--低速
	u16 JNC_TL_Spd;//接捻小车凸轮速度
	u16 JNC_DJ_Spd;//接捻小车打结电机速度
	u16 JNC_DXZ_WaitPos;//持续消除长片瑕疵点后，小吸嘴上升时大吸嘴所处位置
	u16 JNC_JNJGQ;//捻接监控器配置
	u16 LSC_S1;//落纱小车1起始锭号
	u16 LSC_E1;//落纱小车1结束锭号
	u16 LSC_GGDEV_RunMode;//供管装置运转模式 --- 
	u16 LSC_GGDEV_EmptyFillMode;//空管补充模式 --- 向供管装置移动模式 0-纱库上部却管 1-纱库缺管
	u16 LSC_HSpd;//落纱小车高速速度
	u16 LSC_MSpd;//落纱小车中速速度
	u16 LSC_LSpd;//落纱小车低速速度
	u16 MFJ_CFG;//主风机控制配置 自动/手动
	u16 SFJ_CFG;//副风机控制配置 自动/手动

	//辅助参数及报警设定
	u16 STOP_AVG_ShortPeriod;//短周期均匀度强制停止
	u16 STOP_AVG_CV;//CV均匀度强制停止
	u16 STOP_HD;//HD 多发强制停止
	u16 STOP_HD_Thd;//HD 多发阈值
	u16 STOP_DS;//断纱强制停止
	u16 STOP_DS_TimeThd;//断纱多发时间阈值
	u16 STOP_DS_CntThd;//断纱多发报警次数
	u16 STOP_SL;//上蜡报警停止
	u16 STOP_SL_TimeThd;//上蜡报警时间
	u16 STOP_ReleaseTime;//强制停止解除时间
	u16 ERR_DectMode;//异常检测时工作模式
	u16 STOP_TEN_RefValErr;//张力标准值错误强制停止
	u16 STOP_TEN_RefValErrThd;//张力标准值错次数
	u16 LL1_SpdErrThd;//测速报警比例1
	u16 LL2_SpdErrThd;//测速报警比例2
	u16 LL3_SpdErrThd;//测速报警比例3
	u16 LL4_SpdErrThd;//测速报警比例4
	u16 MFJ_HP;//主风机压力上限
	u16 MFJ_LP;//主风机压力下限
	u16 MFJ_AlarmThd;//主风机压力报警比例
	u16 SFJ_HP;//副风机压力上限
	u16 SFJ_LP;//副风机压力下限
	u16 SFJ_AlarmThd;//副风机压力报警比例
}SysPar_t;

typedef struct{
	//单锭
	u16 DD_QJ1_T1; // 清洁1_T1
	u16 DD_QJ1_T2; // 清洁1_T2
	u16 DD_QJ1_T3; // 清洁1_T3
	u16 DD_QJ1_T4; // 清洁1_T4
	u16 DD_QJ1_T5;// 清洁1_T5
	u16 DD_QJ1_T6;//清洁1_T6
	u16 DD_QJ1_T7;//清洁1_T7
	u16 DD_QJ1_T8;//清洁1_T8
	u16 DD_QJ1_T9; //清洁1_T9
	u16 DD_QJ1_T10; // 清洁1_T10
	u16 DD_QJ1_T11; // 清洁1_T11
	u16 DD_WT_T1; //等待_T1
	u16 DD_WT_T2;// 等待_T2
	u16 DD_WT_T3;//等待_T3
	u16 DD_QJ2_T1;//清洁2_T1
	u16 DD_QJ2_T2;//清洁2_T2
	u16 DD_QJ2_T3; //清洁2_T3
	u16 DD_QJ2_T4; //清洁2_T4
	u16 DD_QJ2_T5; //清洁2_T5
	u16 DD_QJ2_T6; //清洁2_T6
	u16 DD_NJ_T1;// 捻接_T1
	u16 DD_NJ_T2;//捻接_T2
	u16 DD_NJ_T3;//捻接_T3
	u16 DD_NJ_T4;//捻接_T4
	u16 DD_NJ_T5; //捻接_T5
	u16 DD_NJ_T6; //捻接_T6
	u16 DD_NJ_T7; //捻接_T7
	u16 DD_NJ_T8; //捻接_T8


	//机尾
	u16 JW_P01;//
	u16 JW_P02;//
	u16 JW_P03;//
	u16 JW_P04;//
	u16 JW_P05;//
	u16 JW_P06;//
	u16 JW_P07;//
	u16 JW_P08;//

}DbgPar_t;



//清纱参数
typedef struct _QsPar_s
{
	//idx = 0
	u16 P01_0;//	纱线速度
	u16 P01_1;//	纱线号数
	u16 P02;//接头幅度正负
	u16 P03;//粗条直径+长度
	u16 P04;//细条直径+长度
	//idx = 1
	u16 P11;	//SL1直径D1+长度L1
	u16 P12;//SL2直径D2+长度L2
	u16 P13;//SL3直径D3+长度L3
	u16 P14;//SL4直径D4+长度L4
	//idx = 2
	u16 P21;	//SL5直径D5+长度L5
	u16 P22;//HDd直径D6+长度L6
	u16 P23;//TL1直径D7+长度L7
	u16 P24;//TL2直径D8+长度L8
	//idx = 3
	u16 P31;	//TL3直径D9+长度L9
	u16 P32_0;//链状纱疵直径
	u16 P32_1;//链状长度mm
	u16 P33_0;//链状纱疵个数
	u16 P33_1;//检测长度cm
	u16 P34_0;//纺纱灵敏度
	u16 P34_1;//
}QsPar_t;




/////////////////////////////////////////////////////////////////////////////////////

typedef struct _StsVFD_s
{
	u16 Dat1;//输出频率0.00`655.35  hz
	u16 Dat2;//输出电流有效值 0.00`399.99   0.01 %
	u16 Dat3;//输出电压有效值0.00`1000.0   0.1 %
	u16 Dat4;//消耗功率0.00`399.99 0.01 %
	u16 Dat5;
}StsVFD_t;


//机头状态
typedef struct _StatusJT_s
{
	u16 RunSts;//运行状态0-上电 1-停机 2-运行 3-测试
	u16 NP_MFan;//主风机负压
	u16 NP_SFan;//副风机负压
	u16 SpdFk_LL1;//罗拉测速1   0.1m/min
	u16 SpdFk_LL2;//罗拉测速2  0.1m/min
	u16 SpdFk_LL3;//罗拉测速3 0.1m/min
	u16 SpdFk_LL4;//罗拉测速4  0.1m/min
	u8 ERR1;//报警单元1  --- 变频器报警位，低位开始，每一位代表一个变频器报警反馈
	u8 ERR2;//报警单元2
	u8 ERR3;//报警单元3
	u8 ERR4;//报警单元4
	u8 ERR5;//报警单元5
	u8 ERR6;//报警单元6
	u8 ERR7;//报警单元7
	u8 ERR8;//报警单元8
	u8 ERR9;//报警单元9
	u8 ERR10;//报警单元10

	StsVFD_t VFD1;
	StsVFD_t VFD2;
	StsVFD_t VFD3;
	StsVFD_t VFD4;
	StsVFD_t VFD5;
	StsVFD_t VFD6;
	StsVFD_t VFD7;
	
	
}StatusJT_t;


//机尾状态
typedef struct _StsJW_s
{
	u8 Sts;//状态
	u8 Err;//报警
	u8 Version;//版本
	u8 ComErr;//通信状态
	u16 Ang1;//模拟量1
	u16 Ang2;//模拟量2
	u16 Input;//输入状态
	u16 Output;//输出状态
}StatusJW_t;



//单锭状态
typedef struct _StsDD_s
{
	u8 Version;// 版本
	u8 Sts;//状态
	u8 Err;//报警
	u8 ComSts;//0-通信正常   1-通信错误
	u32 CurLen;//当前长度
	u16 Xspd;//线速度
	u16 Tension;//张力
	u16 LLSpd3;//第3罗拉速度
	u16 LLSpd4;//第4罗拉速度
	u16 SLSpd;//上蜡速度
	u16 CSSpd;//储纱速度
	u8 InputByte1;//输入位1
	u8 OutputByte1;//输出位1
	u8 OutputByte2;//输出位2
	u8 ComByte;//通信位
	u8 Ads;//锭号
	u8 State;//状态机
	u8 InputByte2;//输入位2
	u8 StateByte;//状态机位
	u8 DebugData[16];//调试数据
}StsDD_t;

//清纱探头状态
typedef struct _StsQS_s
{
	u8 Sts;//状态
	u32 CV;//
	u8 CVs;//毛羽
	u8 Noise;//噪声值
	u8 Sensitivity;//灵敏度值
	u8 Version;//版本
	u16 Zero;//零点
	u8 Driver;//驱动
	u8 Dust;//积灰
	u16 Avg;//实时均值
	u16 Avg_Ref;//参考均值
	u8 DebugData[16];//调试数据
}StsQS_t;

//单节状态
typedef struct _StatusNode_s
{
	u8 Version;  //单节板版本
	u8 ComErr;//通信状态
	u8 Version2[4];//一控二版本
	StsDD_t DdSts[8];
	StsQS_t QsSts[8];
}StatusNode_t;

//AD 小车状态
typedef struct _StatusAD_s
{
	u8 Version;  //版本
	u8 ComErr;//通信状态
	u8 Sts;//状态
	u8 Err;//报警
	u8 PosCur;//当前位置
	u8 EmptyNum;//车上空管数量
}StatusAD_t;

//接捻小车状态
typedef struct _StatusJN_s
{
	u8 Version;  //版本
	u8 ComErr;//通信状态
	u8 Sts;//状态
	u8 Err;//报警
	u8 PosCur;//当前位置

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
