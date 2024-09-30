#ifndef __sys_hard_h
#define __sys_hard_h

#include "sys_bsp.h"

#define IX0010  gSysHard.InPort1.bit.In0
#define IX0011  gSysHard.InPort1.bit.In1
#define IX0012  gSysHard.InPort1.bit.In2
#define IX0013  gSysHard.InPort1.bit.In3
#define IX0014  gSysHard.InPort1.bit.In4
#define IX0015  gSysHard.InPort1.bit.In5
#define IX0016  gSysHard.InPort1.bit.In6
#define IX0017  gSysHard.InPort1.bit.In7
#define IX0018  gSysHard.InPort1.bit.In8
#define IX0019  gSysHard.InPort1.bit.In9
#define IX001A  gSysHard.InPort1.bit.InA
#define IX001B  gSysHard.InPort1.bit.InB
#define IX001C  gSysHard.InPort1.bit.InC
#define IX001D  gSysHard.InPort1.bit.InD
#define IX001E  gSysHard.InPort1.bit.InE
#define IX001F  gSysHard.InPort1.bit.InF
#define IX0020  gSysHard.InPort2.bit.In0
#define IX0021  gSysHard.InPort2.bit.In1
#define IX0022  gSysHard.InPort2.bit.In2
#define IX0023  gSysHard.InPort2.bit.In3
#define IX0024  gSysHard.InPort2.bit.In4
#define IX0025  gSysHard.InPort2.bit.In5
#define IX0026  gSysHard.InPort2.bit.In6
#define IX0027  gSysHard.InPort2.bit.In7
#define IX0028  gSysHard.InPort2.bit.In8
#define IX0029  gSysHard.InPort2.bit.In9
#define VFDERR1 gSysHard.VfdErr.bit.In0
#define VFDERR2 gSysHard.VfdErr.bit.In1
#define VFDERR3 gSysHard.VfdErr.bit.In2
#define VFDERR4 gSysHard.VfdErr.bit.In3
#define VFDERR5 gSysHard.VfdErr.bit.In4
#define VFDERR6 gSysHard.VfdErr.bit.In5
#define VFDERR7 gSysHard.VfdErr.bit.In6
#define VFDERR8 gSysHard.VfdErr.bit.In7
#define VFDERR9 gSysHard.VfdErr.bit.In8
#define VFDERR10 gSysHard.VfdErr.bit.In9

 
#define BT_START  IX0010 
#define BT_STOP  IX0011  
#define BT_CUT  IX0012 
#define CLEANER_CONTINUE_RUN  IX0013 
#define CLEANER_INTERRUPT_RUN  IX0014
#define PACKAGE_START IX0015  
#define BT_RESET IX0016 
#define AIR_PRESSURE2_ERR IX0017 
#define AIR_PRESSURE1_ERR IX0018 
#define POWER_ERR IX0019 
#define SHORT_CIRCUIT_ERR IX001A
#define CLEANER_OL_ERR  IX001B 
#define OVER_LOAD_ERR  IX001C 
#define CLEANER_ZERO  IX001D
#define POLYMASTER_PRESSURE IX001E 
#define MEDICAL_AGENT_LEVER_OFF IX001F
#define POLYMASTER_HP_ERR IX0020
#define HUMAN_DETECT IX0022
#define PACKAGE_END IX0023  
#define PACKAGE_SPD_DOWN IX0024  
#define FAN1_ERR IX0025  
#define FAN2_ERR IX0026  
#define FAN3_ERR IX0027  
#define EMERGENCY_STOP IX0028 
#define POWER_24V_ERR IX0029 

#define START_LAMP(o) gSysHard.OutPort1.bit.Out0 = o
#define STOP_LAMP(o) gSysHard.OutPort1.bit.Out1 = o
#define PACKAGE_LAMP(o) gSysHard.OutPort1.bit.Out2 = o
#define RESET_LAMP(o) gSysHard.OutPort1.bit.Out3 = o
#define TOWER_LAMP_GREEN(o) gSysHard.OutPort1.bit.Out4 = o
#define TOWER_LAMP_BLUE(o) gSysHard.OutPort1.bit.Out5 = o
#define TOWER_LAMP_RED(o) gSysHard.OutPort1.bit.Out6 = o
#define TOWER_LAMP_YELLOW(o) gSysHard.OutPort1.bit.Out7 = o
#define DECOMPRESSION_SV(o) gSysHard.OutPort1.bit.Out8 = o
#define CLEANER_RUN(o) gSysHard.OutPort1.bit.Out9 = o
#define POLYMASTER_MIST_SV(o) gSysHard.OutPort1.bit.OutA= o
#define POLYMASTER_SPARE(o) gSysHard.OutPort1.bit.OutB= o
#define PACKAGE_BRAKE(o) gSysHard.OutPort1.bit.OutC= o
#define PACKAGE_RUN(o) gSysHard.OutPort1.bit.OutD= o
#define PACKAGE_HSPD(o) gSysHard.OutPort1.bit.OutE= o
#define PACKAGE_2SPD(o) gSysHard.OutPort1.bit.OutF= o
#define HICOMPRESSION_SV(o) gSysHard.OutPort2.bit.Out0 = o


struct InPort_Bit
{
	u16 In0:1;
	u16 In1:1;	     
	u16 In2:1;	       
	u16 In3:1;		       
	u16 In4:1;	       
	u16 In5:1;	       
	u16 In6:1;	       
	u16 In7:1;	       
	u16 In8:1;	       
	u16 In9:1;	       
	u16 InA:1;	       
	u16 InB:1;	       
	u16 InC:1;	       
	u16 InD:1;	       
	u16 InE:1;	       
	u16 InF:1;	
};

union InPort_u
{
	u16 All;
	struct InPort_Bit bit;
};



struct OutPort_Bit
{
	u16 Out0:1;// OY10  VFD_SHUT1 STA01_OUT
	u16 Out1:1;// OY11  VFD_SHUT2 STA02_OUT
	u16 Out2:1;// OY12  VFD_SHUT3 STA03_OUT
	u16 Out3:1;// OY13  VFD_SHUT4 STA04_OUT
	u16 Out4:1;// OY14  VFD_SHUT5 STA05_OUT
	u16 Out5:1;// OY15  VFD_SHUT6 STA06_OUT
	u16 Out6:1;// OY16  VFD_SHUT7 OY20_OUT
	u16 Out7:1;// OY17  VFD_SHUT8
	u16 Out8:1;// OY18  VFD_SHUT9
	u16 Out9:1;// OY19  VFD_SHUT10
	u16 OutA:1;// OY1A  FAN01_EN
	u16 OutB:1;// OY1B  FAN01_DIR
	u16 OutC:1;// OY1C  FAN02_EN
	u16 OutD:1;// OY1D  FAN02_DIR
	u16 OutE:1;// OY1E  FAN03_EN
	u16 OutF:1;// OY1F  FAN03_DIR
};

union OutPort_u
{
	u16 All;
	struct OutPort_Bit bit;
};

typedef struct 
{
	u16 Led;

	u16 Spd1;
	u16 Spd2;
	u16 Spd3;
	u16 Spd4;

	u16 AcDet;

	u16 AngU1;
	u16 AngU2;
	u16 VBus;
	float AngOffSet_U1;
	float AngOffSet_U2;

	float k1;
	

	
	union InPort_u InPort1;
	union InPort_u InPort2;
	union InPort_u VfdErr;
	union OutPort_u OutPort1;
	union OutPort_u OutPort2;
	union OutPort_u OutPort3;

	u16 TestOutFlag;
	union OutPort_u  TestOut1;
	union OutPort_u  TestOut2;
	union OutPort_u  TestOut3;
	
	u16 data_out1;
	u16 data_out2;
	u16 data_out3;
	u16 data_out4;
	
}SysHart_t;

extern SysHart_t gSysHard;


void sys_hard_init(void);
void sys_hard_read_port(void);
void sys_hard_load_port(void);


#endif
