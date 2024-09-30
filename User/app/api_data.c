#include "sys_include.h"

Status_t gStatus;
SysPar_t gSysPar;
DbgPar_t gDbgPar;
QsPar_t gQsPar;
DataAvg_t gSpdLL1;
DataAvg_t gSpdLL2;
DataAvg_t gSpdLL3;
DataAvg_t gSpdLL4;

const ParInitVar_t SysPar_InitVar[MAX_SYSPAR_NUM]=
{
//生产设置
{0,		1,	255,		0,	0,		1},	//纱线种类
{0,		1,	255,		0,	0,		1},	//纱线种类
{1,		1,	255,		0,	0,		1},	//纱支数类型
{2,		1,	65535,	0,	30,		1},	//纱支数
{3,		2,	9000000,	0,	300000,	1},	//满桶长度 m
{4,		1,	65535,	0,	2000,	1},	//满桶重量克
{5,		1,	65535,	0,	470,		1},	//满桶重量磅
{6,		1,	255,		0,	0,		1},	//锭子持续给气开关
{6,		1,	255,		0,	0,		1},	//
{7,		1,	65535,	0,	0,		1},	//打样用定长开始锭位0-不使用该功能
{8,		1,	65535,	0,	0,		1},	//打样用定长结束锭位0-不使用该功能
{9,		2,	9000000,	0,	0,		1},	//打样满桶长度 m
//纺纱设置
{10,		1,	65535,	0,	3500,	1},	//纱线速度0.1rpm  
{11,		1,	65535,	0,	1300,	1},	//总牵伸比TDR  摩擦罗拉和第四罗拉的速度比0.1
{12,		1,	65535,	0,	200,		1},	//主牵伸比MDR  摩擦罗拉和中罗拉之间的速比0.1
{13,		1,	65535,	0,	25,		1},	//后牵伸比BDR 第三罗拉和第四罗拉之间的速比0.1
{14,		1,	65535,	0,	980,		1},	//喂入比 WDR 摩擦罗拉和前罗拉之间的速比0.001
{15,		1,	65535,	0,	1000,	1},	//收卷比JDR 卷取槽筒和摩擦罗拉之间速比0.001
{16,		1,	65535,	0,	100,		1},	//起始率BR在捻接或生产过程中后罗拉速度的变换比％
{17,		1,	65535,	0,	14,		1},	//横动角度
//上蜡设置
{18,		1,	255,		0,	0,		1},	//上蜡装置开关
{19,		1,	65535,	0,	10,		1},	//上蜡速度
{20,		1,	255,		0,	0,		1},	//上蜡方向
//纺纱传感器装置设置
{21,		1,	255,		0,	0,		1},	//纺纱传感器控制装置澹(张力控制)开关
{22,		1,	65535,	0,	0,		1},	//张力上限报警阈值
{23,		1,	65535,	0,	30,		1},	//张力下限报警阈值
{24,		1,	65535,	0,	10,		1},	//接捻前后，张力波动阈值
{25,		1,	255,		0,	0,		1},	//张力复位
//接捻器设置
{26,		1,	65535,	0,	0,		1},	//选择接捻器喷嘴类型
{27,		1,	65535,	0,	50,		1},	//定时启动解捻  0.01S
{28,		1,	65535,	0,	25,		1},	//接捻持续时间  0.01S
{29,		1,	65535,	0,	105,		1},	//定时启动加捻  0.01S
{30,		1,	65535,	0,	12,		1},	//加捻持续时间  0.01S
{31,		1,	65535,	0,	0,		1},	// 3段式喷嘴定时启动加捻  0.01S
{32,		1,	65535,	0,	0,		1},	// 3段式喷嘴加捻持续时间  0.01S
{33,		1,	65535,	0,	0,		1},	//Ln杆位置 用于调整捻接起捻接长度。值越大捻接长度越短
{34,		1,	65535,	0,	0,		1},	//捻接监控器N%    捻接监控器的N%的粗细设定
{35,		1,	65535,	0,	0,		1},	//捻接监控器S%    捻接监控器的S剪切的粗细设定
{36,		1,	65535,	0,	30,		1},	//捻接监控器Scm   捻接控空气的S剪切的长度设定
//主机操作设置
{37,		1,	65535,	0,	4300,	1},	//主鼓风机频率 0.01hz
{38,		1,	65535,	0,	5700,	1},	//副鼓风机频率 0.01hz
{39,		1,	65535,	0,	40,		1},	//横动放叠墅幅度0.1%
{40,		1,	65535,	0,	5,		1},	//横动防叠低速时长 1s
{41,		1,	65535,	0,	5,		1},	//横动防叠高速时长1s
{42,		1,	65535,	0,	180,		1},	//排气最长时间1s
{43,		1,	65535,	0,	60,		1},	//排气周期1s
{44,		1,	65535,	0,	6,		1},	//排气打开时间1s
{45,		1,	65535,	0,	9,		1},	//排气关闭时间1s
{46,		1,	65535,	0,	1,		1},	//低气压报警确认时间1min
{47,		1,	65535,	0,	1,		1},	//风门关闭，回花箱长期处于手动模式报警确认时间1min
{48,		1,	65535,	0,	20,		1},	//旁路风门关闭时间1s
{49,		1,	65535,	0,	35,		1},	//回花排出装置运行时间 1s
{50,		1,	65535,	0,	10,		1},	//吹风清洁间隔  min
{51,		1,	65535,	0,	178,		1},	//吹风关闭延迟s
{52,		1,	65535,	0,	5,		1},	// 如果筒纱停留时间超过了筒纱输送带操作运转时间，则灯塔和VOS屏幕中会显示报警
{53,		1,	65535,	0,	10,		1},	//静压低压确认时间阈值
{54,		1,	65535,	0,	100,		1},	//静压高压确认时间阈值
//单锭操作设置
{55,		1,	255,		0,	2,		1},	//接头尝试次数
{56,		1,	255,		0,	0,		1},	//面板红灯功能
{56,		1,	255,		0,	0,		1},	//探纱使能
{57,		2,	65535,	0,	1950,	1},	//卷装量L1  m
{58,		2,	65535,	0,	4500,	1},	//卷装量L2  m
{59,		2,	65535,	0,	6500,	1},	//卷装量L3  m
{60,		2,	65535,	0,	13000,	1},	//卷装量L4  m
{61,		2,	65535,	0,	26000,	1},	//卷装量L5  m
{62,		2,	65535,	0,	39000,	1},	//卷装量L6  m
{63,		2,	65535,	0,	45000,	1},	//卷装量L7  m
{64,		2,	65535,	0,	58000,	1},	//卷装量L8  m
{65,		1,	65535,	0,	100,		1},	//摇架抬升时间T1  
{66,		1,	65535,	0,	100,		1},	//摇架抬升时间T2  
{67,		1,	65535,	0,	100,		1},	//摇架抬升时间T3  
{68,		1,	65535,	0,	100,		1},	//摇架抬升时间T4  
{69,		1,	65535,	0,	100,		1},	//摇架抬升时间T5  
{70,		1,	65535,	0,	100,		1},	//摇架抬升时间T6  
{71,		1,	65535,	0,	100,		1},	//摇架抬升时间T7 
{72,		1,	65535,	0,	100,		1},	//摇架抬升时间T8  
{73,		1,	65535,	0,	100,		1},	//满桶预警时间
//接捻小车操作设置
{74,		1,	65535,	0,	24,		1},	// 夹纱器关闭延时  捻接完成到关闭夹纱器的时间0.1s
{75,		1,	65535,	0,	30,		1},	// 凸轮轴驻留时间0.1s
{76,		1,	65535,	0,	60,		1},	// 上部纱线检测延时0.1s
{77,		1,	65535,	0,	10,		1},	// 下部纱线检测延时0.1s
{78,		1,	65535,	0,	18,		1},	// 筒子抬升延时0.1s
{79,		1,	65535,	0,	0,		1},	// 反转罗拉多段速功能
{80,		1,	65535,	0,	200,		1},	// 反转罗拉速度1
{81,		1,	65535,	0,	200,		1},	// 反转罗拉速度2
{82,		1,	65535,	0,	200,		1},	// 反转罗拉速度3
{83,		1,	65535,	0,	200,		1},	// 反转罗拉速度4
{84,		1,	65535,	0,	200,		1},	// 反转罗拉速度5
{85,		1,	65535,	0,	200,		1},	// 反转罗拉速度6
{86,		1,	65535,	0,	200,		1},	// 反转罗拉速度7
{87,		1,	65535,	0,	200,		1},	// 反转罗拉速度8
{88,		1,	65535,	0,	300,		1},	//反转罗拉正转时间
{88,		1,	65535,	0,	300,		1},	//反转罗拉启动延迟
{88,		1,	65535,	0,	300,		1},	//反转罗拉气缸伸出延迟
{89,		1,	65535,	0,	0,		1},	//大吸嘴吸纱时间（发生L、T、LL、TT剪切时）
{90,		1,	65535,	0,	0,		1},	//大吸嘴吸纱时间HD
{91,		1,	65535,	0,	0,		1},	//上蜡清洁打开时间
{92,		1,	65535,	0,	0,		1},	//上蜡清洁关闭时间
{93,		1,	65535,	0,	0,		1},	//上蜡清洁时长
{94,		1,	65535,	0,	0,		1},	//小吸嘴加捻开闭定时
{95,		1,	65535,	0,	0,		1},	//小吸嘴吸纱开闭定时
//落纱小车操作设置
{96,		1,	65535,	0,	30,		1},	// 凸轮轴驻留时间0.1s
{97,		1,	65535,	0,	120,		1},	// 绕筒脚纱时间0.01s
{98,		1,	65535,	0,	2000,	1},	// 绕筒脚纱速度0.1rpm
{99,		1,	255,		0,	0,		1},	// 二次生头模式-- 自动重试模式 0-禁止 1-开启
{100,	1,	65535,	0,	30,		1},	// 筒子挡板开启时间0.1s
{100,	1,	65535,	0,	0,		1},	//手动模式 - 0-位置停止  1-微动模式
{100,	1,	65535,	0,	0,		1},	// 7段显示  0-当前纺纱单锭  1-目标单锭  2-凸轮周期
{100,	1,	65535,	0,	0,		1},	// 上蜡吹风使能  0-关闭  1-开启
{97,		1,	65535,	0,	10,		1},	// 摇架打开时间 0.1s
{97,		1,	65535,	0,	0,		1},	//上纱检测传感器打开延迟 0.01s
{97,		1,	65535,	0,	0,		1},	//上纱检测传感器关闭延迟 0.01s
{100,	1,	65535,	0,	0,		1},	//上纱检测传感器判断时间 0.1s
{97,		1,	65535,	0,	4,		1},	//边沿提前减速	
{97,		1,	65535,	0,	1,		1},	//络筒提前减速

//系统设置
{101,	1,	255,		0,	12,		1},	//设备节数	
{102,	1,	255,		0,	1,		1},	//接捻小车配置  取4个位，每个位代表一台接捻小车
{103,	1,	65535,	0,	1,		1},	//接捻小车1起始锭号
{104,	1,	65535,	0,	30,		1},	//接捻小车1结束锭号
{105,	1,	65535,	0,	24,		1},	//接捻小车2起始锭号
{106,	1,	65535,	0,	48,		1},	//接捻小车2结束锭号
{107,	1,	65535,	0,	40,		1},	//接捻小车3起始锭号
{108,	1,	65535,	0,	72,		1},	//接捻小车3结束锭号
{109,	1,	65535,	0,	64,		1},	//接捻小车4起始锭号
{110,	1,	65535,	0,	96,		1},	//接捻小车4结束锭号
{111,	1,	65535,	0,	100,		1},	//接捻小车运行速度--高速
{111,	1,	65535,	0,	100,		1},	//接捻小车运行速度--中速
{111,	1,	65535,	0,	100,		1},	//接捻小车运行速度--低速
{111,	1,	65535,	0,	100,		1},	//接捻小车凸轮速度
{111,	1,	65535,	0,	100,		1},	//接捻小车打结电机速度
{112,	1,	65535,	0,	0,		1},	//持续消除长片瑕疵点后，小吸嘴上升时大吸嘴所处位置
{113,	1,	65535,	0,	0,		1},	//捻接监控器配置
{114,	1,	65535,	0,	1,		1},	//落纱小车1起始锭号
{115,	1,	65535,	0,	96,		1},	//落纱小车1结束锭号
{116,	1,	65535,	0,	0,		1},	//供管装置运转模式
{117,	1,	65535,	0,	0,		1},	//空管补充模式--- 向供管装置移动模式 0-纱库上部却管 1-纱库缺管
{118,	1,	65535,	0,	45,		1},	//落纱小车高速速度
{119,	1,	65535,	0,	15,		1},	//落纱小车中速速度
{120,	1,	65535,	0,	8,		1},	//落纱小车低速速度
{121,	1,	255,		0,	0,		1},	//主风机控制配置 自动/手动
{122,	1,	255,		0,	0,		1},	//副风机控制配置 自动/手动
//辅助参数及报警设定
{123,	1,	65535,	0,	0,		1},	//短周期均匀度强制停止
{124,	1,	65535,	0,	0,		1},	//CV均匀度强制停止
{125,	1,	65535,	0,	0,		1},	//HD 多发强制停止
{126,	1,	65535,	0,	0,		1},	//HD 多发阈值
{127,	1,	65535,	0,	0,		1},	//断纱强制停止
{128,	1,	65535,	0,	10,		1},	//断纱多发时间阈值
{129,	1,	65535,	0,	10,		1},	//断纱多发报警次数
{130,	1,	65535,	0,	0,		1},	//上蜡报警停止
{131,	1,	65535,	0,	1,		1},	//上蜡报警时间
{132,	1,	65535,	0,	5,		1},	//强制停止解除时间
{133,	1,	65535,	0,	0,		1},	//异常检测时工作模式
{134,	1,	65535,	0,	0,		1},	//张力标准值错误强制停止
{135,	1,	65535,	0,	10,		1},	//张力标准值错次数
{136,	1,	65535,	0,	30,		1},	//测速报警比例1	
{137,	1,	65535,	0,	30,		1},	//测速报警比例2
{138,	1,	65535,	0,	30,		1},	//测速报警比例3
{139,	1,	65535,	0,	30,		1},	//测速报警比例4
{140,	1,	65535,	0,	0,		1},	//主风机压力上限
{141,	1,	65535,	0,	0,		1},	//主风机压力下限
{142,	1,	65535,	0,	0,		1},	//主风机压力报警比例
{143,	1,	65535,	0,	0,		1},	//副风机压力上限
{144,	1,	65535,	0,	0,		1},	//副风机压力下限
{145,	1,	65535,	0,	0,		1},	//副风机压力报警比例


};

const ParInitVar_t QsPar_InitVar[MAX_QSPAR_NUM]=
{
//
{0,	1,	255,		0,	0,		1},	//	纱线速度
{1,	1,	255,		0,	0,		1},	//	纱线号数
{2,	1,	65535,	0,	0,		1},	//接头幅度正负
{3,	1,	65535,	0,	0,		1},	//粗条直径+长度
{4,	1,	65535,	0,	0,		1},	//细条直径+长度
{5,	1,	65535,	0,	0,		1},	//SL1直径D1+长度L1
{6,	1,	65535,	0,	0,		1},	//SL2直径D2+长度L2
{7,	1,	65535,	0,	0,		1},	//SL3直径D3+长度L3
{8,	1,	65535,	0,	0,		1},	//SL4直径D4+长度L4
{9,	1,	65535,	0,	0,		1},	//SL5直径D5+长度L5
{10,	1,	65535,	0,	0,		1},	//HDd直径D6+长度L6
{11,	1,	65535,	0,	0,		1},	//TL1直径D7+长度L7
{12,	1,	65535,	0,	0,		1},	//TL2直径D8+长度L8
{13,	1,	65535,	0,	0,		1},	//TL3直径D9+长度L9
{14,	1,	255,		0,	0,		1},	//链状纱疵直径
{15,	1,	255,		0,	0,		1},	//链状长度mm
{16,	1,	255,		0,	0,		1},	//链状纱疵个数
{17,	1,	255,		0,	0,		1},	//检测长度cm
{18,	1,	255,		0,	0,		1},	//纺纱灵敏度
{19,	1,	255,		0,	0,		1},	//	
};

const ParInitVar_t DbgPar_InitVar[MAX_DBGPAR_NUM]=
{
//
{0,	1,	255,		0,	0,		1},	// 清洁1_T1
{1,	1,	255,		0,	0,		1},	// 清洁1_T2
{2,	1,	255,		0,	0,		1},	// 清洁1_T3
{3,	1,	255,		0,	0,		1},	// 清洁1_T4
{4,	1,	255,		0,	0,		1},	// 清洁1_T5
{5,	1,	255,		0,	0,		1},	//清洁1_T6
{6,	1,	255,		0,	0,		1},	//清洁1_T7
{7,	1,	255,		0,	0,		1},	//清洁1_T8
{8,	1,	255,		0,	0,		1},	//清洁1_T9
{9,	1,	255,		0,	0,		1},	// 清洁1_T10
{10,	1,	255,		0,	0,		1},	// 清洁1_T11
{11,	1,	255,		0,	0,		1},	//等待_T1
{12,	1,	255,		0,	0,		1},	// 等待_T2
{13,	1,	255,		0,	0,		1},	//等待_T3
{14,	1,	255,		0,	0,		1},	//清洁2_T1
{15,	1,	255,		0,	0,		1},	//清洁2_T2
{16,	1,	255,		0,	0,		1},	 //清洁2_T3
{17,	1,	255,		0,	0,		1},	//清洁2_T4
{18,	1,	255,		0,	0,		1},	//清洁2_T5
{19,	1,	255,		0,	0,		1},	//清洁2_T6
{20,	1,	255,		0,	0,		1},	// 捻接_T1
{21,	1,	255,		0,	0,		1},	//捻接_T2
{22,	1,	255,		0,	0,		1},	//捻接_T3
{23,	1,	255,		0,	0,		1},	//捻接_T4
{24,	1,	255,		0,	0,		1},	//捻接_T5
{25,	1,	255,		0,	0,		1},	//捻接_T6
{26,	1,	255,		0,	0,		1},	//捻接_T7
{27,	1,	255,		0,	0,		1},	//捻接_T8

//机尾
{28,	1,	65535,	0,	0,		1},	//
{29,	1,	65535,	0,	0,		1},	//
{30,	1,	65535,	0,	0,		1},	//
{31,	1,	65535,	0,	0,		1},	//
{32,	1,	65535,	0,	0,		1},	//
{33,	1,	65535,	0,	0,		1},	//
{34,	1,	65535,	0,	0,		1},	//
};

const u8 auchCRCHi[] = {
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 
 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 0x80, 0x41, 0x00, 0xC1, 
 0x81, 0x40, 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 
 0x00, 0xC1, 0x81, 0x40, 0x01, 0xC0, 0x80, 0x41, 0x01, 0xC0, 
 0x80, 0x41, 0x00, 0xC1, 0x81, 0x40 
}; 

const u8 auchCRCLo[] = {
 0x00, 0xC0, 0xC1, 0x01, 0xC3, 0x03, 0x02, 0xC2, 0xC6, 0x06, 
 0x07, 0xC7, 0x05, 0xC5, 0xC4, 0x04, 0xCC, 0x0C, 0x0D, 0xCD, 
 0x0F, 0xCF, 0xCE, 0x0E, 0x0A, 0xCA, 0xCB, 0x0B, 0xC9, 0x09, 
 0x08, 0xC8, 0xD8, 0x18, 0x19, 0xD9, 0x1B, 0xDB, 0xDA, 0x1A, 
 0x1E, 0xDE, 0xDF, 0x1F, 0xDD, 0x1D, 0x1C, 0xDC, 0x14, 0xD4, 
 0xD5, 0x15, 0xD7, 0x17, 0x16, 0xD6, 0xD2, 0x12, 0x13, 0xD3, 
 0x11, 0xD1, 0xD0, 0x10, 0xF0, 0x30, 0x31, 0xF1, 0x33, 0xF3, 
 0xF2, 0x32, 0x36, 0xF6, 0xF7, 0x37, 0xF5, 0x35, 0x34, 0xF4, 
 0x3C, 0xFC, 0xFD, 0x3D, 0xFF, 0x3F, 0x3E, 0xFE, 0xFA, 0x3A, 
 0x3B, 0xFB, 0x39, 0xF9, 0xF8, 0x38, 0x28, 0xE8, 0xE9, 0x29, 
 0xEB, 0x2B, 0x2A, 0xEA, 0xEE, 0x2E, 0x2F, 0xEF, 0x2D, 0xED, 
 0xEC, 0x2C, 0xE4, 0x24, 0x25, 0xE5, 0x27, 0xE7, 0xE6, 0x26, 
 0x22, 0xE2, 0xE3, 0x23, 0xE1, 0x21, 0x20, 0xE0, 0xA0, 0x60, 
 0x61, 0xA1, 0x63, 0xA3, 0xA2, 0x62, 0x66, 0xA6, 0xA7, 0x67, 
 0xA5, 0x65, 0x64, 0xA4, 0x6C, 0xAC, 0xAD, 0x6D, 0xAF, 0x6F, 
 0x6E, 0xAE, 0xAA, 0x6A, 0x6B, 0xAB, 0x69, 0xA9, 0xA8, 0x68, 
 0x78, 0xB8, 0xB9, 0x79, 0xBB, 0x7B, 0x7A, 0xBA, 0xBE, 0x7E, 
 0x7F, 0xBF, 0x7D, 0xBD, 0xBC, 0x7C, 0xB4, 0x74, 0x75, 0xB5, 
 0x77, 0xB7, 0xB6, 0x76, 0x72, 0xB2, 0xB3, 0x73, 0xB1, 0x71, 
 0x70, 0xB0, 0x50, 0x90, 0x91, 0x51, 0x93, 0x53, 0x52, 0x92, 
 0x96, 0x56, 0x57, 0x97, 0x55, 0x95, 0x94, 0x54, 0x9C, 0x5C, 
 0x5D, 0x9D, 0x5F, 0x9F, 0x9E, 0x5E, 0x5A, 0x9A, 0x9B, 0x5B, 
 0x99, 0x59, 0x58, 0x98, 0x88, 0x48, 0x49, 0x89, 0x4B, 0x8B, 
 0x8A, 0x4A, 0x4E, 0x8E, 0x8F, 0x4F, 0x8D, 0x4D, 0x4C, 0x8C, 
 0x44, 0x84, 0x85, 0x45, 0x87, 0x47, 0x46, 0x86, 0x82, 0x42, 
 0x43, 0x83, 0x41, 0x81, 0x80, 0x40 
};

u16 check_crc16(u8 *puchMsg, u16 usDataLen) 
{   
/* CRC低位字节值表*/ 
  
	u8 uchCRCHi = 0xFF ; /* 高CRC字节初始化 */ 
	u8 uchCRCLo = 0xFF ; /* 低CRC 字节初始化 */ 
	u16 uIndex ; /* CRC循环中的索引 */ 
	while (usDataLen--) /* 传输消息缓冲区 */ 
	{ 
		uIndex = uchCRCHi ^ *puchMsg++ ; /* 计算CRC */ 
		uchCRCHi = uchCRCLo ^ auchCRCHi[uIndex] ; 
		uchCRCLo = auchCRCLo[uIndex] ; 
	} 
	return (uchCRCHi << 8 | uchCRCLo) ; 
}

u16 sum_check(u8 * dpin,u16 len)
{
	u16 i=0,sum=0;
	for(i=0;i<len;i++)
	{
		sum += *(dpin+i);
	}
	return sum;

}

void data_avg_init(DataAvg_t *dp)
{
	memset(dp,0,sizeof(DataAvg_t));
}
/***************************************************************************************/

/***************************************************************************************/
void data_avg_macro(DataAvg_t *dp)
{
	if(dp->pLen > (AVG_BUF_LEN_MAX-2)){dp->pLen = (AVG_BUF_LEN_MAX-2);}//长度保护
	if(dp->pLen == 0) dp->pLen = 1;
	if(dp->Index >= AVG_BUF_LEN_MAX){dp->Index = 0;}//防止数据溢出到未知地址
	dp->data[dp->Index] = dp->In;//覆盖最先进入的数据
	dp->add += dp->In;
	dp->Index++;
	if(dp->Index >= (dp->pLen+1)){dp->Index = 0;}	
	dp->add -= dp->data[dp->Index];
	dp->Out = dp->add/dp->pLen;
}
/***************************************************************************************/



void fill_data_flash(u8 type, u8 idx_s, u8 idx_e,u8 idx_s2, u8 idx_e2)
{
	if(type == DAT_DJ)
	{
		gCanBusCtl1.TxMsg.Data[0] = idx_s;
		gCanBusCtl1.TxMsg.Data[1] = idx_e;
		gCanBusCtl1.TxMsg.Data[2] = idx_s2;
		gCanBusCtl1.TxMsg.Data[3] = idx_e2;
		gCanBusCtl1.TxMsg.Data[4] = 0;
		gCanBusCtl1.TxMsg.Data[5] = 0;
		gCanBusCtl1.TxMsg.Data[6] = (gSysCtlVal.CVAvg) & 0xff;
		gCanBusCtl1.TxMsg.Data[7] = gCanBusCtl1.CurID;//gSysCtlVal.Sts;
		gCanBusCtl1.TxMsg.DLC  = 8;
		
	}	
	else if(type == DAT_JW)
	{
		gCanBusCtl1.TxMsg.Data[0] = idx_s;
		gCanBusCtl1.TxMsg.Data[1] = idx_e;
		gCanBusCtl1.TxMsg.Data[2] = 0;
		gCanBusCtl1.TxMsg.Data[3] = 0;
		gCanBusCtl1.TxMsg.Data[4] = 0;
		gCanBusCtl1.TxMsg.Data[5] = 0;
		gCanBusCtl1.TxMsg.Data[7] = gCanBusCtl1.CurID;//gSysCtlVal.Sts;
		gCanBusCtl1.TxMsg.DLC  = 8;

	}
	else if(type == DAT_JN)
	{
		gCanBusCtl2.TxMsg.Data[0] = idx_s;
		gCanBusCtl2.TxMsg.Data[1] = idx_e;
		gCanBusCtl1.TxMsg.Data[2] = gStatus.JN[0].PosCur;
		gCanBusCtl1.TxMsg.Data[3] = gStatus.JN[1].PosCur;
		gCanBusCtl1.TxMsg.Data[4] = gStatus.JN[2].PosCur;
		gCanBusCtl1.TxMsg.Data[5] = gStatus.JN[3].PosCur;
		gCanBusCtl1.TxMsg.Data[6] = 0;
		gCanBusCtl2.TxMsg.Data[7] = gCanBusCtl2.CurID;//gSysCtlVal.Sts;
		gCanBusCtl2.TxMsg.DLC  = 8;

	}
	else if(type == DAT_AD)
	{
		gCanBusCtl2.TxMsg.Data[0] = idx_s;
		gCanBusCtl2.TxMsg.Data[1] = idx_e;
		gCanBusCtl2.TxMsg.Data[2] = 0;
		gCanBusCtl2.TxMsg.Data[3] = 0;
		gCanBusCtl2.TxMsg.Data[4] = 0;
		gCanBusCtl2.TxMsg.Data[5] = 0;
		gCanBusCtl2.TxMsg.Data[7] = gCanBusCtl2.CurID;//gSysCtlVal.Sts;
		gCanBusCtl2.TxMsg.DLC  = 8;

	}

}


void fill_data_set(u8 type, u8 idx)
{
	if(type == DAT_DJ)
	{
		if(idx == 0)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.MT_Len>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.MT_Len>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.MT_Len>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.MT_Len & 0xff;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.SL_En;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DZ_ContinueGQ;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.TEN_En;
			gCanBusCtl1.TxMsg.Data[7] = 0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.BDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.BDR & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = 0;
			gCanBusCtl1.TxMsg.Data[3] = 0;
			gCanBusCtl1.TxMsg.Data[4] = (gSysPar.MDR>>8) & 0xff; 
			gCanBusCtl1.TxMsg.Data[5] =gSysPar.MDR & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = (gSysPar.TDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.TDR & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.JDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.JDR & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gSysPar.WDR>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] =gSysPar.WDR & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =(gSysPar.BR>>8) & 0xff; 
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.BR & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = 0;
			gCanBusCtl1.TxMsg.Data[7] = 0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.XSPD >>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.XSPD & 0xff;
			gCanBusCtl1.TxMsg.Data[2] =0;
			gCanBusCtl1.TxMsg.Data[3] =0;
			gCanBusCtl1.TxMsg.Data[4] =0;
			gCanBusCtl1.TxMsg.Data[5] =0;
			gCanBusCtl1.TxMsg.Data[6] =0;
			gCanBusCtl1.TxMsg.Data[7] =0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 4)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.TEN_HThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.TEN_HThd & 0xff;
			gCanBusCtl1.TxMsg.Data[2] =(gSysPar.TEN_LThd>>8) & 0xff; 
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.TEN_LThd & 0xff;
			gCanBusCtl1.TxMsg.Data[4] = (gSysPar.TEN_BDThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.TEN_BDThd & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = (gSysPar.TEN_Reset>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.TEN_Reset & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 5)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.STOP_SL;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.STOP_SL_TimeThd;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_TSEn;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.STOP_DS; 
			gCanBusCtl1.TxMsg.Data[4] = (gSysPar.STOP_DS_TimeThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.STOP_DS_TimeThd & 0xff;
			gCanBusCtl1.TxMsg.Data[6] = (gSysPar.STOP_DS_CntThd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.STOP_DS_CntThd & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 6)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.SL_Spd>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.SL_Spd & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.SL_Dir;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_JTTryN;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_RedCtl;
			gCanBusCtl1.TxMsg.Data[5] = 0;
			gCanBusCtl1.TxMsg.Data[6] = 0;
			gCanBusCtl1.TxMsg.Data[7] = 0;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 7)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gSysPar.DY_Len>>24) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = (gSysPar.DY_Len>>16) & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gSysPar.DY_Len>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DY_Len & 0xff;
			gCanBusCtl1.TxMsg.Data[4] = gSysCtlVal.DY_En & 0xff;;  
			gCanBusCtl1.TxMsg.DLC  = 5;
		}
		else if(idx == 8)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_QJ1_T1;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_QJ1_T2;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_QJ1_T3;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_QJ1_T4;
			gCanBusCtl1.TxMsg.Data[4] = gDbgPar.DD_QJ1_T5;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.DD_QJ1_T6;
			gCanBusCtl1.TxMsg.Data[6] = gDbgPar.DD_QJ1_T7;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.DD_QJ1_T8;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 9)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_QJ1_T9;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_QJ1_T10;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_QJ1_T11;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_WT_T1;
			gCanBusCtl1.TxMsg.Data[4] = gDbgPar.DD_WT_T2;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.DD_WT_T3;
			gCanBusCtl1.TxMsg.Data[6] = gDbgPar.DD_QJ2_T1;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.DD_QJ2_T2;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 10)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_QJ2_T3;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_QJ2_T4;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_QJ2_T5;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_QJ2_T6;
			gCanBusCtl1.TxMsg.Data[4] = gDbgPar.DD_NJ_T1;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.DD_NJ_T2;
			gCanBusCtl1.TxMsg.Data[6] = gDbgPar.DD_NJ_T3;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.DD_NJ_T4;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 11)
		{
			gCanBusCtl1.TxMsg.Data[0] = gDbgPar.DD_NJ_T5;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.DD_NJ_T6;
			gCanBusCtl1.TxMsg.Data[2] = gDbgPar.DD_NJ_T7;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.DD_NJ_T8;
			gCanBusCtl1.TxMsg.DLC  = 4;
		}
		else if(idx == 12)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L1>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L1>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L1>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L1 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L2>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L2>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L2>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L2 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 13)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L3>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L3>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L3>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L3 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L4>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L4>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L4>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L4 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 14)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L5>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L5>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L5>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L5 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L6>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L6>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L6>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L6 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 15)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_L7>>24;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_L7>>16;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_L7>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_L7 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_L8>>24;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_L8>>16;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_L8>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_L8 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 16)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_T1>>8;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_T1 & 0xFF;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_T2>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_T2 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_T3>>8;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_T3 & 0xFF;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_T4>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_T4 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 17)
		{
			gCanBusCtl1.TxMsg.Data[0] = gSysPar.DD_T5>>8;
			gCanBusCtl1.TxMsg.Data[1] = gSysPar.DD_T5 & 0xFF;
			gCanBusCtl1.TxMsg.Data[2] = gSysPar.DD_T6>>8;
			gCanBusCtl1.TxMsg.Data[3] = gSysPar.DD_T6 & 0xFF;
			gCanBusCtl1.TxMsg.Data[4] = gSysPar.DD_T7>>8;
			gCanBusCtl1.TxMsg.Data[5] = gSysPar.DD_T7 & 0xFF;
			gCanBusCtl1.TxMsg.Data[6] = gSysPar.DD_T8>>8;
			gCanBusCtl1.TxMsg.Data[7] = gSysPar.DD_T8 & 0xFF;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl1.TxMsg.Data[0] = gCanBusCtl1.CurID;
			gCanBusCtl1.TxMsg.Data[1] = gCanBusCtl1.CurCmd;
			gCanBusCtl1.TxMsg.DLC  = 2;
		}

	}
	else if(type == DAT_JW)
	{
		if(idx == 0)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gDbgPar.JW_P01>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.JW_P01 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gDbgPar.JW_P02>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.JW_P02 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gDbgPar.JW_P03>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.JW_P03 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gDbgPar.JW_P04>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.JW_P04 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gDbgPar.JW_P05>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gDbgPar.JW_P05 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gDbgPar.JW_P06>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gDbgPar.JW_P06 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gDbgPar.JW_P07>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gDbgPar.JW_P07 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gDbgPar.JW_P08>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gDbgPar.JW_P08 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl1.TxMsg.Data[0] = gCanBusCtl1.CurID;
			gCanBusCtl1.TxMsg.Data[1] = gCanBusCtl1.CurCmd;
			gCanBusCtl1.TxMsg.DLC  = 2;
		}

	}
	else if(type == DAT_QS)
	{
		if(idx == 0)
		{
			gCanBusCtl1.TxMsg.Data[0] = gQsPar.P01_0;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P01_1;
			gCanBusCtl1.TxMsg.Data[2] = (gQsPar.P02>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P02 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gQsPar.P03>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gQsPar.P03 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gQsPar.P04>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P04 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gQsPar.P11>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P11 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gQsPar.P12>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P12 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gQsPar.P13>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gQsPar.P13 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gQsPar.P14>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P14 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gQsPar.P21>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P21 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = (gQsPar.P22>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P22 & 0xff;
			gCanBusCtl1.TxMsg.Data[4] =  (gQsPar.P23>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[5] = gQsPar.P23 & 0xff;
			gCanBusCtl1.TxMsg.Data[6] =  (gQsPar.P24>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P24 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl1.TxMsg.Data[0] = (gQsPar.P31>>8) & 0xff;
			gCanBusCtl1.TxMsg.Data[1] = gQsPar.P31 & 0xff;
			gCanBusCtl1.TxMsg.Data[2] = gQsPar.P32_0;
			gCanBusCtl1.TxMsg.Data[3] = gQsPar.P32_1;
			gCanBusCtl1.TxMsg.Data[4] = gQsPar.P33_0;
			gCanBusCtl1.TxMsg.Data[5] =  gQsPar.P33_1;
			gCanBusCtl1.TxMsg.Data[6] = gQsPar.P34_0;
			gCanBusCtl1.TxMsg.Data[7] = gQsPar.P34_1;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl1.TxMsg.Data[0] = gCanBusCtl1.CurID;
			gCanBusCtl1.TxMsg.Data[1] = gCanBusCtl1.CurCmd;
			gCanBusCtl1.TxMsg.DLC  = 2;
		}

	}
	else if(type == DAT_JN)
	{
		if(idx == 0)
		{
			gCanBusCtl2.TxMsg.Data[0] =  (gSysPar.JNC_JSQ_CloseDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_JSQ_CloseDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_TL_StayTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_TL_StayTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_SBS_CheckDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_SBS_CheckDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_XBS_CheckDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_XBS_CheckDlyTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_ST_UpDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_ST_UpDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_LL_SpdCtl>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_LL_SpdCtl & 0xff;
			gCanBusCtl2.TxMsg.Data[4] = (gSysPar.JNC_LL_StartDlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_LL_StartDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_LL_QGOut_DlyTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_LL_QGOut_DlyTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_LL_F1>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_LL_F1 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_LL_F2>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_LL_F2 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_LL_F3>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_LL_F3 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_LL_F4>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_LL_F4 & 0xff;
			gCanBusCtl1.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_LL_F5>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_LL_F5 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_LL_F6>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_LL_F6 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_LL_F7>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_LL_F7 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_LL_F8>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_LL_F8 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 4)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_LL_FwdTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_LL_FwdTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_DXZ_XiShaTimeLT>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_DXZ_XiShaTimeLT & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_DXZ_XiShaTimeHD>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_DXZ_XiShaTimeHD & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_SLQJ_OpenTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_SLQJ_OpenTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 5)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_SLQJ_ColseTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_SLQJ_ColseTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_SLQJ_Time>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_SLQJ_Time & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_XXZ_JiaNianTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_XXZ_JiaNianTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gSysPar.JNC_XXZ_XiShaTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_XXZ_XiShaTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 6)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_SpdH>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_SpdH & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_DXZ_WaitPos>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_DXZ_WaitPos & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_JNJGQ>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_JNJGQ & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = (gSysPar.JNC_SpdM>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_SpdM & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 7)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JNC_SpdL>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_SpdL & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JNC_TL_Spd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_TL_Spd & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JNC_DJ_Spd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_DJ_Spd & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = (gSysPar.JN_LnPos>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JN_LnPos & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 8)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.JN_JiaNianStartTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JN_JiaNianStartTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.JN_JiaNianTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JN_JiaNianTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.JN_JieNianStartTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JN_JieNianStartTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = (gSysPar.JN_JieNianTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JN_JieNianTime & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 9)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L1>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L1>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L1>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L1 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L2>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L2>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L2>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L2 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 10)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L3>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L3>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L3>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L3 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L4>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L4>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L4>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L4 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 11)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L5>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L5>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L5>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L5 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L6>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L6>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L6>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L6 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 12)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.DD_L7>>24;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.DD_L7>>16;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.DD_L7>>8;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.DD_L7 & 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.DD_L8>>24;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.DD_L8>>16;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.DD_L8>>8;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.DD_L8 & 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}		
		else if(idx == 13)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.JNC_S[0]& 0xFF;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.JNC_E[0]& 0xFF;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.JNC_S[1]& 0xFF;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.JNC_E[1]& 0xFF;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.JNC_S[2]& 0xFF;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.JNC_E[2]& 0xFF;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.JNC_S[3]& 0xFF;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.JNC_E[3]& 0xFF;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}				
		else
		{
			gCanBusCtl2.TxMsg.Data[0] = gCanBusCtl2.CurID;
			gCanBusCtl2.TxMsg.Data[1] = gCanBusCtl2.CurCmd;
			gCanBusCtl2.TxMsg.DLC  = 2;
		}
	}
	else if(type == DAT_QS1)
	{
		if(idx == 0)
		{
			gCanBusCtl2.TxMsg.Data[0] = gQsPar.P01_0;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P01_1;
			gCanBusCtl2.TxMsg.Data[2] = (gQsPar.P02>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P02 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gQsPar.P03>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gQsPar.P03 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gQsPar.P04>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P04 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gQsPar.P11>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P11 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gQsPar.P12>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P12 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gQsPar.P13>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gQsPar.P13 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gQsPar.P14>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P14 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gQsPar.P21>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P21 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gQsPar.P22>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P22 & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gQsPar.P23>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gQsPar.P23 & 0xff;
			gCanBusCtl2.TxMsg.Data[6] =  (gQsPar.P24>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P24 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gQsPar.P31>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gQsPar.P31 & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = gQsPar.P32_0;
			gCanBusCtl2.TxMsg.Data[3] = gQsPar.P32_1;
			gCanBusCtl2.TxMsg.Data[4] = gQsPar.P33_0;
			gCanBusCtl2.TxMsg.Data[5] =  gQsPar.P33_1;
			gCanBusCtl2.TxMsg.Data[6] = gQsPar.P34_0;
			gCanBusCtl2.TxMsg.Data[7] = gQsPar.P34_1;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl2.TxMsg.Data[0] = gCanBusCtl2.CurID;
			gCanBusCtl2.TxMsg.Data[1] = gCanBusCtl2.CurCmd;
			gCanBusCtl2.TxMsg.DLC  = 2;
		}

	}	
	else if(type == DAT_AD)
	{
		if(idx == 0)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.LSC_HSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_MSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.LSC_LSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.LSC_TL_StayTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.LSC_ST_Mode & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.LSC_Manual_Mode & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.LSC_GGDEV_EmptyFillMode & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.LSC_SLQJ_EN & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 1)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.LSC_Display_7 & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_RTJS_Time & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = (gSysPar.LSC_RTJS_Spd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[3] =  gSysPar.LSC_RTJS_Spd & 0xff;
			gCanBusCtl2.TxMsg.Data[4] =  (gSysPar.LSC_DB_OpenTime>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[5] =  gSysPar.LSC_DB_OpenTime & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = gSysPar.LSC_S1 & 0xff;
			gCanBusCtl2.TxMsg.Data[7] = gSysPar.LSC_E1 & 0xff;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 2)
		{
			gCanBusCtl2.TxMsg.Data[0] = gSysPar.LSC_YJ_OpenTime & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_YARN_OpenDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = gSysPar.LSC_YARN_CloseDlyTime & 0xff;
			gCanBusCtl2.TxMsg.Data[3] = gSysPar.LSC_YARN_CheckTime & 0xff;
			gCanBusCtl2.TxMsg.Data[4] = gSysPar.LSC_TQJS_BY & 0xff;
			gCanBusCtl2.TxMsg.Data[5] = gSysPar.LSC_TQJS_LT & 0xff;
			gCanBusCtl2.TxMsg.Data[6] = 0;
			gCanBusCtl2.TxMsg.Data[7] = 0;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else if(idx == 3)
		{
			gCanBusCtl2.TxMsg.Data[0] = (gSysPar.LSC_LSpd>>8) & 0xff;
			gCanBusCtl2.TxMsg.Data[1] = gSysPar.LSC_LSpd & 0xff;
			gCanBusCtl2.TxMsg.Data[2] = 0;
			gCanBusCtl2.TxMsg.Data[3] = 0;
			gCanBusCtl2.TxMsg.Data[4] = 0;
			gCanBusCtl2.TxMsg.Data[5] = 0;
			gCanBusCtl2.TxMsg.Data[6] = 0;
			gCanBusCtl2.TxMsg.Data[7] = 0;
			gCanBusCtl2.TxMsg.DLC  = 8;
		}
		else
		{
			gCanBusCtl2.TxMsg.Data[0] = gCanBusCtl2.CurID;
			gCanBusCtl2.TxMsg.Data[1] = gCanBusCtl2.CurCmd;
			gCanBusCtl2.TxMsg.DLC  = 2;
		}
	}

}



void data_upate_status(void)
{
	gStatus.JT.RunSts = gSysCtlVal.Sts;

	//风机负压
	gStatus.JT.NP_MFan = gStatus.JW[0].Ang1;
	gStatus.JT.NP_MFan = gStatus.JW[0].Ang2;


	//罗拉速度反馈
	gSpdLL1.pLen = 20;//	200ms
	gSpdLL1.In =  gSysHard.Spd1;
	data_avg_macro(&gSpdLL1);
	gStatus.JT.SpdFk_LL1 = gSpdLL1.Out;
	gSpdLL2.pLen = 20;//	200ms
	gSpdLL2.In =  gSysHard.Spd2;
	data_avg_macro(&gSpdLL2);
	gStatus.JT.SpdFk_LL2 = gSpdLL2.Out;	
	gSpdLL3.pLen = 20;//	200ms
	gSpdLL3.In =  gSysHard.Spd3;
	data_avg_macro(&gSpdLL3);
	gStatus.JT.SpdFk_LL3 = gSpdLL3.Out;	
	gSpdLL4.pLen = 20;//	200ms
	gSpdLL4.In =  gSysHard.Spd4;
	data_avg_macro(&gSpdLL4);
	gStatus.JT.SpdFk_LL4 = gSpdLL4.Out;	


	//变频器状态
	gStatus.JT.VFD1.Dat1 = gVfdCom.Mxx[0].oFre_hz;
	gStatus.JT.VFD1.Dat2 = gVfdCom.Mxx[0].oCur;
	gStatus.JT.VFD1.Dat3 = gVfdCom.Mxx[0].oVol;
	gStatus.JT.VFD1.Dat4 = gVfdCom.Mxx[0].oP;
	gStatus.JT.VFD1.Dat5 = 0;
	gStatus.JT.VFD2.Dat1 = gVfdCom.Mxx[1].oFre_hz;
	gStatus.JT.VFD2.Dat2 = gVfdCom.Mxx[1].oCur;
	gStatus.JT.VFD2.Dat3 = gVfdCom.Mxx[1].oVol;
	gStatus.JT.VFD2.Dat4 = gVfdCom.Mxx[1].oP;
	gStatus.JT.VFD2.Dat5 = 0;
	gStatus.JT.VFD3.Dat1 = gVfdCom.Mxx[2].oFre_hz;
	gStatus.JT.VFD3.Dat2 = gVfdCom.Mxx[2].oCur;
	gStatus.JT.VFD3.Dat3 = gVfdCom.Mxx[2].oVol;
	gStatus.JT.VFD3.Dat4 = gVfdCom.Mxx[2].oP;
	gStatus.JT.VFD3.Dat5 = 0;
	gStatus.JT.VFD4.Dat1 = gVfdCom.Mxx[3].oFre_hz;
	gStatus.JT.VFD4.Dat2 = gVfdCom.Mxx[3].oCur;
	gStatus.JT.VFD4.Dat3 = gVfdCom.Mxx[3].oVol;
	gStatus.JT.VFD4.Dat4 = gVfdCom.Mxx[3].oP;
	gStatus.JT.VFD4.Dat5 = 0;
	gStatus.JT.VFD5.Dat1 = gVfdCom.Mxx[4].oFre_hz;
	gStatus.JT.VFD5.Dat2 = gVfdCom.Mxx[4].oCur;
	gStatus.JT.VFD5.Dat3 = gVfdCom.Mxx[4].oVol;
	gStatus.JT.VFD5.Dat4 = gVfdCom.Mxx[4].oP;
	gStatus.JT.VFD5.Dat5 = 0;
	gStatus.JT.VFD6.Dat1 = gVfdCom.Mxx[5].oFre_hz;
	gStatus.JT.VFD6.Dat2 = gVfdCom.Mxx[5].oCur;
	gStatus.JT.VFD6.Dat3 = gVfdCom.Mxx[5].oVol;
	gStatus.JT.VFD6.Dat4 = gVfdCom.Mxx[5].oP;
	gStatus.JT.VFD6.Dat5 = 0;
	gStatus.JT.VFD7.Dat1 = gVfdCom.Mxx[6].oFre_hz;
	gStatus.JT.VFD7.Dat2 = gVfdCom.Mxx[6].oCur;
	gStatus.JT.VFD7.Dat3 = gVfdCom.Mxx[6].oVol;
	gStatus.JT.VFD7.Dat4 = gVfdCom.Mxx[6].oP;
	gStatus.JT.VFD7.Dat5 = 0;

	gStatus.JT.ERR1 = gSysHard.VfdErr.All & 0x7F;
}

void sys_par_init(u8 type, u16* pbf)
{	
	u16 i=0;
	u16 num = 0;

	if(type == 0)
	{
		while(num < MAX_SYSPAR_NUM)
		{
			if(SysPar_InitVar[num].Size == 1)
			{
				if(SysPar_InitVar[num].RstFlag)
					*(pbf+i) = SysPar_InitVar[num].Default;
				i++;
			}
			else if(SysPar_InitVar[num].Size == 2)
			{	
				
				if(SysPar_InitVar[num].RstFlag)
					*(pbf+i) = SysPar_InitVar[num].Default&0xFFFF;
				i++;
				
				if(SysPar_InitVar[num].RstFlag)
					*(pbf+i) = SysPar_InitVar[num].Default>>16;
				i++;
			}
				
			num++;
		}
	}
	else if(type == 1)
	{
		while(num < MAX_QSPAR_NUM)
		{
			if(QsPar_InitVar[num].Size == 1)
			{
				if(QsPar_InitVar[num].RstFlag)
					*(pbf+i) = QsPar_InitVar[num].Default;
				i++;
			}
			else if(QsPar_InitVar[num].Size == 2)
			{	
				
				if(QsPar_InitVar[num].RstFlag)
					*(pbf+i) = QsPar_InitVar[num].Default&0xFFFF;
				i++;
				
				if(QsPar_InitVar[num].RstFlag)
					*(pbf+i) = QsPar_InitVar[num].Default>>16;
				i++;
			}
				
			num++;
		}
	}
	else if(type == 2)
	{
		while(num < MAX_DBGPAR_NUM)
		{
			if(DbgPar_InitVar[num].Size == 1)
			{
				if(DbgPar_InitVar[num].RstFlag)
					*(pbf+i) = DbgPar_InitVar[num].Default;
				i++;
			}
			else if(DbgPar_InitVar[num].Size == 2)
			{	
				
				if(DbgPar_InitVar[num].RstFlag)
					*(pbf+i) = DbgPar_InitVar[num].Default&0xFFFF;
				i++;
				
				if(DbgPar_InitVar[num].RstFlag)
					*(pbf+i) = DbgPar_InitVar[num].Default>>16;
				i++;
			}
				
			num++;
		}
	}
	
}

void data_init(void)
{

	memset(&gSysPar, 0, sizeof(SysPar_t));
	memset(&gQsPar, 0, sizeof(QsPar_t));
	memset(&gDbgPar, 0, sizeof(DbgPar_t));

	sys_par_init(0, (u16*)&gSysPar);
	
	data_avg_init(&gSpdLL1);
	data_avg_init(&gSpdLL2);
	data_avg_init(&gSpdLL3);
	data_avg_init(&gSpdLL4);



}
