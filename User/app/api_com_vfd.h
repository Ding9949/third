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

#define ADR_Fxx 0x00 //基本功能
#define ADR_Exx 0x01 //端子功能
#define ADR_Cxx 0x02 //控制功能
#define ADR_Pxx 0x03 //电机1参数
#define ADR_Hxx 0x04 //高级功能
#define ADR_Axx 0x05 //电机2参数
#define ADR_Oxx 0x06 //选件功能
#define ADR_Sxx 0x07 //指令、功能数据
#define ADR_Mxx 0x08 //监控数据
#define ADR_Rxx 0x0A //电机4参数
#define ADR_Jxx 0x0D //应用功能1
#define ADR_Yxx 0x0E //链接功能
#define ADR_Wxx 0x0F //监控2
#define ADR_Xxx 0x10 //报警1
#define ADR_Zxx 0x11 //报警2
#define ADR_Bxx 0x12 //电机3参数
#define ADR_Dxx 0x13 //应用功能2

#define REG_Sxx(no) ((ADR_Sxx<<8) + no) //S
#define REG_Fxx(no) ((ADR_Fxx<<8) + no) //F

#define REG_FRE_PU  REG_Sxx(1)   //S01-频率指令pu   -32768`32767
#define REG_FRE_HZ  REG_Sxx(5)   //S05-频率 指令0.00`655.35  hz
#define REG_CMD  REG_Sxx(6)   //S06-运行操作指令   0x0000~0xFFFF
#define REG_OUT  REG_Sxx(7)   //S07-输出端子信息0x0000~0xFFFF
#define REG_ACC_TIME REG_Sxx(8)  // S08-加速时间1  0.00~3000s
#define REG_DEC_TIME REG_Sxx(9)  // S09-减速时间1  0.00~3000s
#define REG_RST_ERR  REG_Sxx(14)   //S14-报警复位指令0or1

#define REG_FRE1_MODE REG_Fxx(1)  // F01 - 评率1 设定模式 
#define REG_RUN_MODE REG_Fxx(2)  // F02 - 运行操作模式
#define REG_FRE1_LIMIT REG_Fxx(3)  // F03 - 最高输出频率25.0hz~500.0hz
#define REG_FRE1_REF REG_Fxx(4)  // F04 - 最高输出频率25.0hz~500.0hz
#define REG_CTL_MODE REG_Fxx(42)  // F42 - 控制模式0-VF  3-带反馈VF


//运行指令
struct S06_Bit
{
	u16 FWD:1;//  1= 正转
	u16 REV:1;//  1= 反转	     
	u16 X1:1;// 通信输入端子		       
	u16 X2:1;// 通信输入端子			       
	u16 X4:1;// 通信输入端子		       
	u16 X5:1;// 通信输入端子		       
	u16 bit7:1;	       
	u16 bit8:1;	       
	u16 bit9:1;	       
	u16 bit10:1;	       
	u16 bit11:1;	       
	u16 bit12:1;	       
	u16 bit13:1;	       
	u16 XF:1;// 通信输入端子	       
	u16 XR:1;// 通信输入端子     
	u16 RST:1;// 0->1时复位	
};

union S06_u
{
	u16 All;
	struct S06_Bit bit;
};


//运行状态监控
struct M14_Bit
{
	u16 FWD:1;// 1 = 正转中
	u16 REV:1;//	 1 =  反转中    
	u16 EXT:1;// 1 = 直流制动中或激磁中	       
	u16 INT:1;//	 1 = 	变频器切断       
	u16 BRK:1;//	  1 =  制动中     
	u16 MUV:1;//  1 = 直流中间确立	       
	u16 TL:1;//  1 = 转矩限制中	       
	u16 VL:1;// 1 = 电压限制中	       
	u16 IL:1;// 1 = 电流限制中	       
	u16 ACC:1;// 1 = 	加速中       
	u16 DEC:1;// 1 = 	减速中       
	u16 ALM:1;// 1 = 	总报警       
	u16 RL:1;// 1 = 通信有效	       
	u16 bit13:1;// 1 = 	       
	u16 bit14:1;// 1 = 	       
	u16 BUSY:1;// 1 = 功能代码写入中	
};

union M14_u
{
	u16 All;
	struct M14_Bit bit;
};




typedef struct _Mxx_s
{
	u16 Fre_pu;//M01-频率指令pu   -32768`32767
	u16 Tor;//M02-转矩指令 -327.68`327.67    0.01  %
	u16 TorCur;//M03-转矩电流指令-327.68`327.67    0.01  %
	u16 Flux;// M04- 磁通量指令-327.68`327.67    0.01   %
	u16 Fre_hz;//M05-频率 指令0.00`655.35  hz
	u16 oFre_pu;//M06-输出频率pu   -32768`32767
	u16 oTor;//M07-输出力矩-327.68`327.67    0.01  %
	u16 oTorCur;//M08-输出转矩电流-327.68`327.67    0.01  %
	u16 oFre_hz;//M09-输出频率0.00`655.35  hz
	u16 oP;//M10-消耗功率0.00`399.99 0.01 %
	u16 oCur;//M11-输出电流有效值 0.00`399.99   0.01 %
	u16 oVol;//M12-输出电压有效值0.00`1000.0   0.1 %
	u16 CMD;//M13-运行操作指令   0x0000~0xFFFF
	u16 RunST;//M14-运行状态0x0000~0xFFFF
	u16 OutST;//M15-输出端子信息0x0000~0xFFFF
	u16 ERR;//M16-最新报警  0~127
	u16 ERR_1;//M17-上一次报警 0~127
	u16 ERR_2;//M18-上上一次报警 0~127
	u16 ERR_3;//M19-上上一次报警 0~127
}Mxx_t;


typedef struct _REGxx_s
{
	//Sxx
	u16 Fre_pu;//S01-频率指令pu   -32768`32767
	u16 Fre_hz;//S05-频率 指令0.00`655.35  hz
	union S06_u CMD;//S06-运行操作指令   0x0000~0xFFFF
	u16 OutST;//S07-输出端子信息0x0000~0xFFFF
	u16 AccTime;//S08-加速时间 0.0~3600.0    0.1s
	u16 DecTime;//S09-减速时间 0.0~3600.0    0.1s
	u16 RstErr;//S14-报警复位指令0or1
	//Fxx
	u16 FRE1_MODE; // F01 - 评率1 设定模式 
	u16 RUN_MODE;  // F02 - 运行操作模式
	u16 FRE1_LIMIT;  // F03 - 最高输出频率25.0hz~500.0hz
	u16 FRE1_REF; // F04 - 最高输出频率25.0hz~500.0hz


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
	u8 RxdFlag; // 接收完成标志
	u8 RxdLen;
	u16 RxdFrameTicker;// 帧间隔计数器
	u16 RxdWaitCnt;// 接收等待时间计数器
	
	u8 TxdSts;
	u8 TxdFlag;//通信发送使能标志
	u8 TxLen;

	u8 State;//任务状态机
	u8 CurNode;//
	u8 MaxNode;
	u8 CurCmd;
	u8 CurIdx;
	u16 CurReg;
	u16 TaskTicker;//通信任务片


	
	u32 ErrCnt[10];	//通信出错计数器
	union REG_FLAG_u RegWriteFlag[10];//参数写
	union REG_FLAG_u RegReadFlag[10];//参数回读
	Mxx_t  Mxx[10]; // 监控状态 r
	REGxx_t REGxx[10];//寄存器 rw
 
	
	u8 VfdRecBuf[COM_VFD_FRAME_LEN];
	u8 VfdTxdBuf[40];
}VfdCom_t;

extern VfdCom_t gVfdCom;


void vfd_com_init(void);
void vfd_com_isr(void);
void vfd_com_task(void);

#endif
