#include "sys_include.h"

SysHart_t gSysHard;


void sys_hard_init(void)
{

	memset(&gSysHard, 0, sizeof(SysHart_t));
}




// 10K, 100us
void sys_hard_read_port(void)
{
	static u8 psr = 0;
	static union InPort_u In1;
	static union InPort_u In1_bk;
	static union InPort_u In2;
	static union InPort_u In2_bk;
	static union InPort_u Vfd_err;
	static union InPort_u Vfd_err_bk;


	gSysHard.AngU1 = IU1_VAL;
	gSysHard.AngU2 = IU2_VAL;
	
	gSysHard.AcDet = AC_DET_VAL;

	if(psr == 0)
	{
		In1_bk.All =In1.All;
		In1.bit.In0 = IX10_VAL;
		In1.bit.In1 = IX11_VAL;
		In1.bit.In2 = IX12_VAL;
		In1.bit.In3 = IX13_VAL;
		In1.bit.In4 = IX14_VAL;
		In1.bit.In5 = IX15_VAL;
		In1.bit.In6 = IX16_VAL;
		In1.bit.In7 = IX17_VAL;
		In1.bit.In8 = IX18_VAL;
		In1.bit.In9 = IX19_VAL;
		In1.bit.InA = IX1A_VAL;
		In1.bit.InB = IX1B_VAL;
		In1.bit.InC = IX1C_VAL;
		In1.bit.InD = IX1D_VAL;
		In1.bit.InE = IX1E_VAL;
		In1.bit.InF = IX1F_VAL;
	}else if(psr == 1)
	{
		In2_bk.All =In2.All;
		In2.bit.In0 = IX20_VAL;
		In2.bit.In1 = IX21_VAL;
		In2.bit.In2 = IX22_VAL;
		In2.bit.In3 = IX23_VAL;
		In2.bit.In4 = IX24_VAL;
		In2.bit.In5 = IX25_VAL;
		In2.bit.In6 = IX26_VAL;
		In2.bit.In7 = IX27_VAL;
		In2.bit.In8 = IX28_VAL;
		In2.bit.In9 = IX29_VAL;
	}
	else if(psr == 2)
	{
		Vfd_err_bk.All =Vfd_err.All;
		Vfd_err.bit.In0 = VFD01_ERR_VAL;
		Vfd_err.bit.In1 = VFD02_ERR_VAL;
		Vfd_err.bit.In2 = VFD03_ERR_VAL;
		Vfd_err.bit.In3 = VFD04_ERR_VAL;
		Vfd_err.bit.In4 = VFD05_ERR_VAL;
		Vfd_err.bit.In5 = VFD06_ERR_VAL;
		Vfd_err.bit.In6 = VFD07_ERR_VAL;
		Vfd_err.bit.In7 = VFD08_ERR_VAL;
		Vfd_err.bit.In8 = VFD09_ERR_VAL;
		Vfd_err.bit.In9 = VFD10_ERR_VAL;
	}
	else if(psr == 3)
	{
		if(In1.bit.In0 == In1_bk.bit.In0)gSysHard.InPort1.bit.In0 = In1.bit.In0;
		if(In1.bit.In1 == In1_bk.bit.In1)gSysHard.InPort1.bit.In1 = In1.bit.In1;
		if(In1.bit.In2 == In1_bk.bit.In2)gSysHard.InPort1.bit.In2 = In1.bit.In2;
		if(In1.bit.In3 == In1_bk.bit.In3)gSysHard.InPort1.bit.In3 = In1.bit.In3;
		if(In1.bit.In4 == In1_bk.bit.In4)gSysHard.InPort1.bit.In4 = In1.bit.In4;
		if(In1.bit.In5 == In1_bk.bit.In5)gSysHard.InPort1.bit.In5 = In1.bit.In5;
		if(In1.bit.In6 == In1_bk.bit.In6)gSysHard.InPort1.bit.In6 = In1.bit.In6;
		if(In1.bit.In7 == In1_bk.bit.In7)gSysHard.InPort1.bit.In7 = In1.bit.In7;
		if(In1.bit.In8 == In1_bk.bit.In8)gSysHard.InPort1.bit.In8 = In1.bit.In8;
		if(In1.bit.In9 == In1_bk.bit.In9)gSysHard.InPort1.bit.In9 = In1.bit.In9;
		if(In1.bit.InA == In1_bk.bit.InA)gSysHard.InPort1.bit.InA = In1.bit.InA;
		if(In1.bit.InB == In1_bk.bit.InB)gSysHard.InPort1.bit.InB = In1.bit.InB;
		if(In1.bit.InC == In1_bk.bit.InC)gSysHard.InPort1.bit.InC = In1.bit.InC;
		if(In1.bit.InD == In1_bk.bit.InD)gSysHard.InPort1.bit.InD = In1.bit.InD;
		if(In1.bit.InE == In1_bk.bit.InE)gSysHard.InPort1.bit.InE = In1.bit.InE;
		if(In1.bit.InF == In1_bk.bit.InF)gSysHard.InPort1.bit.InF = In1.bit.InF;
	}
	else if(psr == 4)
	{
		if(In2.bit.In0 == In2_bk.bit.In0)gSysHard.InPort2.bit.In0 = In2.bit.In0;
		if(In2.bit.In1 == In2_bk.bit.In1)gSysHard.InPort2.bit.In1 = In2.bit.In1;
		if(In2.bit.In2 == In2_bk.bit.In2)gSysHard.InPort2.bit.In2 = In2.bit.In2;
		if(In2.bit.In3 == In2_bk.bit.In3)gSysHard.InPort2.bit.In3 = In2.bit.In3;
		if(In2.bit.In4 == In2_bk.bit.In4)gSysHard.InPort2.bit.In4 = In2.bit.In4;
		if(In2.bit.In5 == In2_bk.bit.In5)gSysHard.InPort2.bit.In5 = In2.bit.In5;
		if(In2.bit.In6 == In2_bk.bit.In6)gSysHard.InPort2.bit.In6 = In2.bit.In6;
		if(In2.bit.In7 == In2_bk.bit.In7)gSysHard.InPort2.bit.In7 = In2.bit.In7;
		if(In2.bit.In8 == In2_bk.bit.In8)gSysHard.InPort2.bit.In8 = In2.bit.In8;
		if(In2.bit.In9 == In2_bk.bit.In9)gSysHard.InPort2.bit.In9 = In2.bit.In9;
	}
	else if(psr == 5)
	{
		if(Vfd_err.bit.In0 == Vfd_err_bk.bit.In0)gSysHard.VfdErr.bit.In0 = Vfd_err.bit.In0;
		if(Vfd_err.bit.In1 == Vfd_err_bk.bit.In1)gSysHard.VfdErr.bit.In1 = Vfd_err.bit.In1;
		if(Vfd_err.bit.In2 == Vfd_err_bk.bit.In2)gSysHard.VfdErr.bit.In2 = Vfd_err.bit.In2;
		if(Vfd_err.bit.In3 == Vfd_err_bk.bit.In3)gSysHard.VfdErr.bit.In3 = Vfd_err.bit.In3;
		if(Vfd_err.bit.In4 == Vfd_err_bk.bit.In4)gSysHard.VfdErr.bit.In4 = Vfd_err.bit.In4;
		if(Vfd_err.bit.In5 == Vfd_err_bk.bit.In5)gSysHard.VfdErr.bit.In5 = Vfd_err.bit.In5;
		if(Vfd_err.bit.In6 == Vfd_err_bk.bit.In6)gSysHard.VfdErr.bit.In6 = Vfd_err.bit.In6;
		if(Vfd_err.bit.In7 == Vfd_err_bk.bit.In7)gSysHard.VfdErr.bit.In7 = Vfd_err.bit.In7;
		if(Vfd_err.bit.In8 == Vfd_err_bk.bit.In8)gSysHard.VfdErr.bit.In8 = Vfd_err.bit.In8;
		if(Vfd_err.bit.In9 == Vfd_err_bk.bit.In9)gSysHard.VfdErr.bit.In9 = Vfd_err.bit.In9;
	}
	psr++;
	if(psr >= SYS_ISR_PSC)
		psr = 0;

	//START_LAMP(BT_START);
	//STOP_LAMP(BT_STOP);
	PACKAGE_LAMP(PACKAGE_START);
	RESET_LAMP(BT_RESET);


	if(gRollerSpeed1.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed1.CheckCnt = API_SPD_NO_PLUSE_TIME;
		gRollerSpeed1.Spd = 0;
	}
	else
	{
		gRollerSpeed1.CheckCnt++;
	}
	if(gRollerSpeed2.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed2.CheckCnt = API_SPD_NO_PLUSE_TIME;
		gRollerSpeed2.Spd = 0;
	}
	else
	{
		gRollerSpeed2.CheckCnt++;
	}
	if(gRollerSpeed3.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed3.CheckCnt = API_SPD_NO_PLUSE_TIME;
		gRollerSpeed3.Spd = 0;
	}
	else
	{
		gRollerSpeed3.CheckCnt++;
	}
	if(gRollerSpeed4.CheckCnt >= API_SPD_NO_PLUSE_TIME)
	{
		gRollerSpeed4.CheckCnt = API_SPD_NO_PLUSE_TIME;
		gRollerSpeed4.Spd = 0;
	}
	else
	{
		gRollerSpeed4.CheckCnt++;
	}

	gSysHard.Spd1 = gRollerSpeed1.Spd;
	gSysHard.Spd2 = gRollerSpeed2.Spd;
	gSysHard.Spd3 = gRollerSpeed3.Spd;
	gSysHard.Spd4 = gRollerSpeed4.Spd;
}



void sys_hard_load_port(void)
{
	static u8 psr = 0;
	static u32 cnt = 0;

	//gSysHard.k1 = gRollerSpeed1.Spd*1.0f/gRollerSpeed2.Spd;
	//gSysHard.data_out1 = (u16)(gSysHard.k1*1000);

	psr++;
	if(psr>= SYS_ISR_PSC)
	{
		psr = 0;
		cnt ++;
		if(cnt >=19000)
		{
			cnt = 0;
		}
	}

	
	RUN_OUT(gSysHard.Led);

	if(gSysHard.TestOutFlag == 0)
	{
		OY10_OUT(gSysHard.OutPort1.bit.Out0);
		OY11_OUT(gSysHard.OutPort1.bit.Out1);
		OY12_OUT(gSysHard.OutPort1.bit.Out2);
		OY13_OUT(gSysHard.OutPort1.bit.Out3);
		OY14_OUT(gSysHard.OutPort1.bit.Out4);
		OY15_OUT(gSysHard.OutPort1.bit.Out5);
		OY16_OUT(gSysHard.OutPort1.bit.Out6);
		OY17_OUT(gSysHard.OutPort1.bit.Out7);
		OY18_OUT(gSysHard.OutPort1.bit.Out8);
		OY19_OUT(gSysHard.OutPort1.bit.Out9);
		OY1A_OUT(gSysHard.OutPort1.bit.OutA);
		OY1B_OUT(gSysHard.OutPort1.bit.OutB);
		OY1C_OUT(gSysHard.OutPort1.bit.OutC);
		OY1D_OUT(gSysHard.OutPort1.bit.OutD);
		OY1E_OUT(gSysHard.OutPort1.bit.OutE);
		OY1F_OUT(gSysHard.OutPort1.bit.OutF);

		VFD01_SHUT_OUT(gSysHard.OutPort2.bit.Out0);
		VFD02_SHUT_OUT(gSysHard.OutPort2.bit.Out1);
		VFD03_SHUT_OUT(gSysHard.OutPort2.bit.Out2);
		VFD04_SHUT_OUT(gSysHard.OutPort2.bit.Out3);
		VFD05_SHUT_OUT(gSysHard.OutPort2.bit.Out4);
		VFD06_SHUT_OUT(gSysHard.OutPort2.bit.Out5);
		VFD07_SHUT_OUT(gSysHard.OutPort2.bit.Out6);
		VFD08_SHUT_OUT(gSysHard.OutPort2.bit.Out7);
		VFD09_SHUT_OUT(gSysHard.OutPort2.bit.Out8);
		VFD10_SHUT_OUT(gSysHard.OutPort2.bit.Out9);
		FAN01_EN_OUT(gSysHard.OutPort2.bit.OutA);
		FAN01_DIR_OUT(gSysHard.OutPort2.bit.OutB);
		FAN02_EN_OUT(gSysHard.OutPort2.bit.OutC);
		FAN02_DIR_OUT(gSysHard.OutPort2.bit.OutD);
		FAN03_EN_OUT(gSysHard.OutPort2.bit.OutE);
		FAN03_DIR_OUT(gSysHard.OutPort2.bit.OutF);

		STA01_OUT(gSysHard.OutPort3.bit.Out0);
		STA02_OUT(gSysHard.OutPort3.bit.Out1);
		STA03_OUT(gSysHard.OutPort3.bit.Out2);
		STA04_OUT(gSysHard.OutPort3.bit.Out3);
		STA05_OUT(gSysHard.OutPort3.bit.Out4);
		STA06_OUT(gSysHard.OutPort3.bit.Out5);	
		OY20_OUT(gSysHard.OutPort3.bit.Out6);	
	

	}
	else
	{
		#if 0
		u16 tmp = 0;
		tmp = cnt/1000;
		if(tmp < 16)
		{
			gSysHard.TestOut1.All = 0x1<<tmp;
			gSysHard.TestOut2.All = 0x1<<tmp;
			gSysHard.TestOut3.bit.Out6 = 0;
			if(tmp < 6)
				gSysHard.TestOut3.All = 0x1<<tmp;
			else
				gSysHard.TestOut3.All = 0;
				
		}
		else if(tmp == 16)
		{
			gSysHard.TestOut1.All = 0;
			gSysHard.TestOut2.All = 0;
			gSysHard.TestOut3.bit.Out6 = 1;

		}
		else if(tmp == 17)
		{
			gSysHard.TestOut1.All = 0xFFFF;
			gSysHard.TestOut2.All = 0xFFFF;
			gSysHard.TestOut3.bit.Out1 = 1;
			gSysHard.TestOut3.bit.Out2 = 1;
			gSysHard.TestOut3.bit.Out3 = 1;
			gSysHard.TestOut3.bit.Out4 = 1;
			gSysHard.TestOut3.bit.Out5 = 1;
			gSysHard.TestOut3.bit.Out6 = 1;
		}
		else if(tmp == 18)
		{
			gSysHard.TestOut1.All = 0;
			gSysHard.TestOut2.All = 0;
			gSysHard.TestOut3.All = 0;
		}
		#endif

		//gSysHard.TestOut1.bit.Out0 = gSysHard.InPort1.bit.In0 ||  gSysHard.InPort2.bit.In0 ||  gSysHard.VfdErr.bit.In0;
		//gSysHard.TestOut1.bit.Out1 = gSysHard.InPort1.bit.In1 ||  gSysHard.InPort2.bit.In1 ||  gSysHard.VfdErr.bit.In1;
		//gSysHard.TestOut1.bit.Out2 = gSysHard.InPort1.bit.In2 ||  gSysHard.InPort2.bit.In2 ||  gSysHard.VfdErr.bit.In2;
		//gSysHard.TestOut1.bit.Out3 = gSysHard.InPort1.bit.In3 ||  gSysHard.InPort2.bit.In3 ||  gSysHard.VfdErr.bit.In3;
		//gSysHard.TestOut1.bit.Out4 = gSysHard.InPort1.bit.In4 ||  gSysHard.InPort2.bit.In4 ||  gSysHard.VfdErr.bit.In4;
		//gSysHard.TestOut1.bit.Out5 = gSysHard.InPort1.bit.In5 ||  gSysHard.InPort2.bit.In5 ||  gSysHard.VfdErr.bit.In5;
		//gSysHard.TestOut1.bit.Out6 = gSysHard.InPort1.bit.In6 ||  gSysHard.InPort2.bit.In6 ||  gSysHard.VfdErr.bit.In6;
		//gSysHard.TestOut1.bit.Out7 = gSysHard.InPort1.bit.In7 ||  gSysHard.InPort2.bit.In7 ||  gSysHard.VfdErr.bit.In7;
		//gSysHard.TestOut1.bit.Out8 = gSysHard.InPort1.bit.In8 ||  gSysHard.InPort2.bit.In8 ||  gSysHard.VfdErr.bit.In8;
		//gSysHard.TestOut1.bit.Out9 = gSysHard.InPort1.bit.In9 ||  gSysHard.VfdErr.bit.In9;
		//gSysHard.TestOut1.bit.OutA = gSysHard.InPort1.bit.InA; 
		//gSysHard.TestOut1.bit.OutB = gSysHard.InPort1.bit.InB;
		//gSysHard.TestOut1.bit.OutC = gSysHard.InPort1.bit.InC;
		//gSysHard.TestOut1.bit.OutD= gSysHard.InPort1.bit.InD;
		//gSysHard.TestOut1.bit.OutE= gSysHard.InPort1.bit.InE;
		//gSysHard.TestOut1.bit.OutF = gSysHard.InPort1.bit.InF;
	
		OY10_OUT(gSysHard.TestOut1.bit.Out0);
		OY11_OUT(gSysHard.TestOut1.bit.Out1);
		OY12_OUT(gSysHard.TestOut1.bit.Out2);
		OY13_OUT(gSysHard.TestOut1.bit.Out3);
		OY14_OUT(gSysHard.TestOut1.bit.Out4);
		OY15_OUT(gSysHard.TestOut1.bit.Out5);
		OY16_OUT(gSysHard.TestOut1.bit.Out6);
		OY17_OUT(gSysHard.TestOut1.bit.Out7);
		OY18_OUT(gSysHard.TestOut1.bit.Out8);
		OY19_OUT(gSysHard.TestOut1.bit.Out9);
		OY1A_OUT(gSysHard.TestOut1.bit.OutA);
		OY1B_OUT(gSysHard.TestOut1.bit.OutB);
		OY1C_OUT(gSysHard.TestOut1.bit.OutC);
		OY1D_OUT(gSysHard.TestOut1.bit.OutD);
		OY1E_OUT(gSysHard.TestOut1.bit.OutE);
		OY1F_OUT(gSysHard.TestOut1.bit.OutF);

		VFD01_SHUT_OUT(gSysHard.TestOut2.bit.Out0);
		VFD02_SHUT_OUT(gSysHard.TestOut2.bit.Out1);
		VFD03_SHUT_OUT(gSysHard.TestOut2.bit.Out2);
		VFD04_SHUT_OUT(gSysHard.TestOut2.bit.Out3);
		VFD05_SHUT_OUT(gSysHard.TestOut2.bit.Out4);
		VFD06_SHUT_OUT(gSysHard.TestOut2.bit.Out5);
		VFD07_SHUT_OUT(gSysHard.TestOut2.bit.Out6);
		VFD08_SHUT_OUT(gSysHard.TestOut2.bit.Out7);
		VFD09_SHUT_OUT(gSysHard.TestOut2.bit.Out8);
		VFD10_SHUT_OUT(gSysHard.TestOut2.bit.Out9);
		FAN01_EN_OUT(gSysHard.TestOut2.bit.OutA);
		FAN01_DIR_OUT(gSysHard.TestOut2.bit.OutB);
		FAN02_EN_OUT(gSysHard.TestOut2.bit.OutC);
		FAN02_DIR_OUT(gSysHard.TestOut2.bit.OutD);
		FAN03_EN_OUT(gSysHard.TestOut2.bit.OutE);
		FAN03_DIR_OUT(gSysHard.TestOut2.bit.OutF);

		STA01_OUT(gSysHard.TestOut3.bit.Out0);
		STA02_OUT(gSysHard.TestOut3.bit.Out1);
		STA03_OUT(gSysHard.TestOut3.bit.Out2);
		STA04_OUT(gSysHard.TestOut3.bit.Out3);
		STA05_OUT(gSysHard.TestOut3.bit.Out4);
		STA06_OUT(gSysHard.TestOut3.bit.Out5);
		OY20_OUT(gSysHard.TestOut3.bit.Out6);	

	}


}



