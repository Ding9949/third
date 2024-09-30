/*
 *
 *  Created on: 2017年8月16日
 *      Author: Wuych
 */


#include "sys_include.h"

DisCom_t gDisCom = {0, };


static void _parse_data_flash(void)
{
	u8 temp = 0;
	u8 i = 0;
	gSysCtlVal.TestMode = gDisCom.RecBuf[3]?1:0;


	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_Flash;
	gDisCom.TxdBuf[3] = gStatus.JT.RunSts>>8;
	gDisCom.TxdBuf[4] = gStatus.JT.RunSts&0xFF;
	gDisCom.TxdBuf[5] = gStatus.JT.NP_MFan>>8;
	gDisCom.TxdBuf[6] = gStatus.JT.NP_MFan&0xFF;
	gDisCom.TxdBuf[7] = gStatus.JT.NP_SFan>>8;
	gDisCom.TxdBuf[8] = gStatus.JT.NP_SFan&0xFF;
	gDisCom.TxdBuf[9] = gStatus.JT.SpdFk_LL1>>8;
	gDisCom.TxdBuf[10] = gStatus.JT.SpdFk_LL1&0xFF;
	gDisCom.TxdBuf[11] = gStatus.JT.SpdFk_LL2>>8;
	gDisCom.TxdBuf[12] = gStatus.JT.SpdFk_LL2&0xFF;
	gDisCom.TxdBuf[13] = gStatus.JT.SpdFk_LL3>>8;
	gDisCom.TxdBuf[14] = gStatus.JT.SpdFk_LL3&0xFF;
	gDisCom.TxdBuf[15] = gStatus.JT.SpdFk_LL4>>8;
	gDisCom.TxdBuf[16] = gStatus.JT.SpdFk_LL4&0xFF;
	gDisCom.TxdBuf[17] = gStatus.JT.ERR1;
	gDisCom.TxdBuf[18] = gStatus.JT.ERR2;
	gDisCom.TxdBuf[19] = gStatus.JT.ERR3;
	gDisCom.TxdBuf[20] = gStatus.JT.ERR4;
	gDisCom.TxdBuf[21] = gStatus.JT.ERR5;
	gDisCom.TxdBuf[22] = gStatus.JT.ERR6;
	gDisCom.TxdBuf[23] = gStatus.JT.ERR7;
	gDisCom.TxdBuf[24] = gStatus.JT.ERR8;
	gDisCom.TxdBuf[25] = gStatus.JT.ERR9;
	gDisCom.TxdBuf[26] = gStatus.JT.ERR10;

	
	gDisCom.TxdBuf[27] = gDisCom.ParRequestFlag?1:0;
	
	gDisCom.TxdBuf[28] = SW_VERSION>>8;
	gDisCom.TxdBuf[29] = SW_VERSION&0xFF;
	gDisCom.TxdBuf[30] = gStatus.JW[0].Version>>8;
	gDisCom.TxdBuf[31] = gStatus.JW[0].Version&0xFF;
	gDisCom.TxdBuf[32] = gStatus.JW[1].Version>>8;
	gDisCom.TxdBuf[33] = gStatus.JW[1].Version&0xFF;
	gDisCom.TxdBuf[34] = gStatus.AD.Version>>8;
	gDisCom.TxdBuf[35] = gStatus.AD.Version&0xFF;
	gDisCom.TxdBuf[36] = gStatus.JN[0].Version>>8;
	gDisCom.TxdBuf[37] = gStatus.JN[0].Version&0xFF;
	gDisCom.TxdBuf[38] = gStatus.JN[1].Version>>8;
	gDisCom.TxdBuf[39] = gStatus.JN[1].Version&0xFF;
	gDisCom.TxdBuf[40] = gStatus.JN[2].Version>>8;
	gDisCom.TxdBuf[41] = gStatus.JN[2].Version&0xFF;
	gDisCom.TxdBuf[42] = gStatus.JN[3].Version>>8;
	gDisCom.TxdBuf[43] = gStatus.JN[3].Version&0xFF;
	gDisCom.TxdBuf[44] = 0;
	gDisCom.TxdBuf[45] = 0;
	gDisCom.TxdBuf[46] = 0;
	gDisCom.TxdBuf[47] = 0;
	gDisCom.TxdBuf[48] = 0;
	gDisCom.TxdBuf[49] = 0;
	
	gDisCom.TxdBuf[50] = gStatus.JT.VFD1.Dat1>>8;
	gDisCom.TxdBuf[51] = gStatus.JT.VFD1.Dat1&0xFF;
	gDisCom.TxdBuf[52] = gStatus.JT.VFD1.Dat2>>8;
	gDisCom.TxdBuf[53] = gStatus.JT.VFD1.Dat2&0xFF;
	gDisCom.TxdBuf[54] = gStatus.JT.VFD1.Dat3>>8;
	gDisCom.TxdBuf[55] = gStatus.JT.VFD1.Dat3&0xFF;
	gDisCom.TxdBuf[56] = gStatus.JT.VFD1.Dat4>>8;
	gDisCom.TxdBuf[57] = gStatus.JT.VFD1.Dat4&0xFF;
	gDisCom.TxdBuf[58] = gStatus.JT.VFD1.Dat5>>8;
	gDisCom.TxdBuf[59] = gStatus.JT.VFD1.Dat5&0xFF;

	gDisCom.TxdBuf[60] = gStatus.JT.VFD2.Dat1>>8;
	gDisCom.TxdBuf[61] = gStatus.JT.VFD2.Dat1&0xFF;
	gDisCom.TxdBuf[62] = gStatus.JT.VFD2.Dat2>>8;
	gDisCom.TxdBuf[63] = gStatus.JT.VFD2.Dat2&0xFF;
	gDisCom.TxdBuf[64] = gStatus.JT.VFD2.Dat3>>8;
	gDisCom.TxdBuf[65] = gStatus.JT.VFD2.Dat3&0xFF;
	gDisCom.TxdBuf[66] = gStatus.JT.VFD2.Dat4>>8;
	gDisCom.TxdBuf[67] = gStatus.JT.VFD2.Dat4&0xFF;
	gDisCom.TxdBuf[68] = gStatus.JT.VFD2.Dat5>>8;
	gDisCom.TxdBuf[69] = gStatus.JT.VFD2.Dat5&0xFF;

	gDisCom.TxdBuf[70] = gStatus.JT.VFD3.Dat1>>8;
	gDisCom.TxdBuf[71] = gStatus.JT.VFD3.Dat1&0xFF;
	gDisCom.TxdBuf[72] = gStatus.JT.VFD3.Dat2>>8;
	gDisCom.TxdBuf[73] = gStatus.JT.VFD3.Dat2&0xFF;
	gDisCom.TxdBuf[74] = gStatus.JT.VFD3.Dat3>>8;
	gDisCom.TxdBuf[75] = gStatus.JT.VFD3.Dat3&0xFF;
	gDisCom.TxdBuf[76] = gStatus.JT.VFD3.Dat4>>8;
	gDisCom.TxdBuf[77] = gStatus.JT.VFD3.Dat4&0xFF;
	gDisCom.TxdBuf[78] = gStatus.JT.VFD3.Dat5>>8;
	gDisCom.TxdBuf[79] = gStatus.JT.VFD3.Dat5&0xFF;

	gDisCom.TxdBuf[80] = gStatus.JT.VFD4.Dat1>>8;
	gDisCom.TxdBuf[81] = gStatus.JT.VFD4.Dat1&0xFF;
	gDisCom.TxdBuf[82] = gStatus.JT.VFD4.Dat2>>8;
	gDisCom.TxdBuf[83] = gStatus.JT.VFD4.Dat2&0xFF;
	gDisCom.TxdBuf[84] = gStatus.JT.VFD4.Dat3>>8;
	gDisCom.TxdBuf[85] = gStatus.JT.VFD4.Dat3&0xFF;
	gDisCom.TxdBuf[86] = gStatus.JT.VFD4.Dat4>>8;
	gDisCom.TxdBuf[87] = gStatus.JT.VFD4.Dat4&0xFF;
	gDisCom.TxdBuf[88] = gStatus.JT.VFD4.Dat5>>8;
	gDisCom.TxdBuf[89] = gStatus.JT.VFD4.Dat5&0xFF;

	gDisCom.TxdBuf[90] = gStatus.JT.VFD5.Dat1>>8;
	gDisCom.TxdBuf[91] = gStatus.JT.VFD5.Dat1&0xFF;
	gDisCom.TxdBuf[92] = gStatus.JT.VFD5.Dat2>>8;
	gDisCom.TxdBuf[93] = gStatus.JT.VFD5.Dat2&0xFF;
	gDisCom.TxdBuf[94] = gStatus.JT.VFD5.Dat3>>8;
	gDisCom.TxdBuf[95] = gStatus.JT.VFD5.Dat3&0xFF;
	gDisCom.TxdBuf[96] = gStatus.JT.VFD5.Dat4>>8;
	gDisCom.TxdBuf[97] = gStatus.JT.VFD5.Dat4&0xFF;
	gDisCom.TxdBuf[98] = gStatus.JT.VFD5.Dat5>>8;
	gDisCom.TxdBuf[99] = gStatus.JT.VFD5.Dat5&0xFF;	

	gDisCom.TxdBuf[100] = gStatus.JT.VFD6.Dat1>>8;
	gDisCom.TxdBuf[101] = gStatus.JT.VFD6.Dat1&0xFF;
	gDisCom.TxdBuf[102] = gStatus.JT.VFD6.Dat2>>8;
	gDisCom.TxdBuf[103] = gStatus.JT.VFD6.Dat2&0xFF;
	gDisCom.TxdBuf[104] = gStatus.JT.VFD6.Dat3>>8;
	gDisCom.TxdBuf[105] = gStatus.JT.VFD6.Dat3&0xFF;
	gDisCom.TxdBuf[106] = gStatus.JT.VFD6.Dat4>>8;
	gDisCom.TxdBuf[107] = gStatus.JT.VFD6.Dat4&0xFF;
	gDisCom.TxdBuf[108] = gStatus.JT.VFD6.Dat5>>8;
	gDisCom.TxdBuf[109] = gStatus.JT.VFD6.Dat5&0xFF;	

	gDisCom.TxdBuf[110] = gStatus.JT.VFD7.Dat1>>8;
	gDisCom.TxdBuf[111] = gStatus.JT.VFD7.Dat1&0xFF;
	gDisCom.TxdBuf[112] = gStatus.JT.VFD7.Dat2>>8;
	gDisCom.TxdBuf[113] = gStatus.JT.VFD7.Dat2&0xFF;
	gDisCom.TxdBuf[114] = gStatus.JT.VFD7.Dat3>>8;
	gDisCom.TxdBuf[115] = gStatus.JT.VFD7.Dat3&0xFF;
	gDisCom.TxdBuf[116] = gStatus.JT.VFD7.Dat4>>8;
	gDisCom.TxdBuf[117] = gStatus.JT.VFD7.Dat4&0xFF;
	gDisCom.TxdBuf[118] = gStatus.JT.VFD7.Dat5>>8;
	gDisCom.TxdBuf[119] = gStatus.JT.VFD7.Dat5&0xFF;	

	for(i=120;i<158;i++)
		gDisCom.TxdBuf[i] = 0;
	
	temp = sum_check(gDisCom.TxdBuf, 158);
	gDisCom.TxdBuf[158] = temp&0xff;
	gDisCom.TxdBuf[159] = 0xff-gDisCom.TxdBuf[158];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 160;
	gDisCom.TxdDly = 5;

}

static void _parse_data_flash1(void)
{
	u16 temp = 0;
	u8 i = 0;
	u8 node = 0;
	u8 cnt = 0;

	node = gDisCom.TxdBuf[3];
	gSysCtlVal.ClrCmd = gDisCom.TxdBuf[4];
	gSysCtlVal.ClrType = gDisCom.TxdBuf[5];
	gSysCtlVal.ClrAds = gDisCom.TxdBuf[6];

	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_Flash1;


	gDisCom.TxdBuf[3] = (node>=MAX_NODE_NUM)?MAX_NODE_NUM-1:0;

	temp = 0;cnt = 0;
	if(gStatus.Node[node].DdSts[0].Sts){temp += 0x1;cnt++;}
	if(gStatus.Node[node].DdSts[1].Sts){temp += 0x2;cnt++;}
	if(gStatus.Node[node].DdSts[2].Sts){temp += 0x4;cnt++;}
	if(gStatus.Node[node].DdSts[3].Sts){temp += 0x8;cnt++;}
	if(gStatus.Node[node].DdSts[4].Sts){temp += 0x10;cnt++;}
	if(gStatus.Node[node].DdSts[5].Sts){temp += 0x20;cnt++;}
	if(gStatus.Node[node].DdSts[6].Sts){temp += 0x40;cnt++;}
	if(gStatus.Node[node].DdSts[7].Sts){temp += 0x80;cnt++;}
	gDisCom.TxdBuf[4] = temp;
	gDisCom.TxdBuf[5] = gStatus.Node[node].ComErr;	
	temp = 0;
	if(gStatus.Node[node].DdSts[0].Err)temp += 0x1;
	if(gStatus.Node[node].DdSts[1].Err)temp += 0x2;
	if(gStatus.Node[node].DdSts[2].Err)temp += 0x4;
	if(gStatus.Node[node].DdSts[3].Err)temp += 0x8;
	if(gStatus.Node[node].DdSts[4].Err)temp += 0x10;
	if(gStatus.Node[node].DdSts[5].Err)temp += 0x20;
	if(gStatus.Node[node].DdSts[6].Err)temp += 0x40;
	if(gStatus.Node[node].DdSts[7].Err)temp += 0x80;
	gDisCom.TxdBuf[6] = temp;
	gDisCom.TxdBuf[7] = 0;
	gDisCom.TxdBuf[8] = cnt;
	gDisCom.TxdBuf[9] = (gSysCtlVal.BanSum_Len[node]>>16) & 0xFF;
	gDisCom.TxdBuf[10] = (gSysCtlVal.BanSum_Len[node]>>8) & 0xFF;
	gDisCom.TxdBuf[11] = gSysCtlVal.BanSum_Len[node]&0xFF;


	for(i=120;i<158;i++)
		gDisCom.TxdBuf[i] = 0;
	
	temp = sum_check(gDisCom.TxdBuf, 158);
	gDisCom.TxdBuf[158] = temp&0xff;
	gDisCom.TxdBuf[159] = 0xff-gDisCom.TxdBuf[158];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 160;
	gDisCom.TxdDly = 5;

}

static void _parse_data_test(void)
{
	u16 temp = 0;
	
	gSysCtlVal.TestFre1 = (gDisCom.RecBuf[3]<<8) + gDisCom.RecBuf[4];
	gSysCtlVal.TestFre2 = (gDisCom.RecBuf[5]<<8) + gDisCom.RecBuf[6];
	gSysCtlVal.TestFre3 = (gDisCom.RecBuf[7]<<8) + gDisCom.RecBuf[8];
	gSysCtlVal.TestFre4 = (gDisCom.RecBuf[9]<<8) + gDisCom.RecBuf[10];
	gSysCtlVal.TestFre5 = (gDisCom.RecBuf[11]<<8) + gDisCom.RecBuf[12];
	gSysCtlVal.TestFre6 = (gDisCom.RecBuf[13]<<8) + gDisCom.RecBuf[14];
	gSysCtlVal.TestFre7 = (gDisCom.RecBuf[15]<<8) + gDisCom.RecBuf[16];
	gSysCtlVal.TestCtl1.all =  gDisCom.RecBuf[17];
	gSysCtlVal.TestCtl2.all =  gDisCom.RecBuf[18];
	gSysCtlVal.TestCtl3.all =  gDisCom.RecBuf[19];
	gSysCtlVal.TestCtl4.all =  gDisCom.RecBuf[20];
	gSysCtlVal.TestCtl5.all =  gDisCom.RecBuf[21];
	gSysCtlVal.TestCtl6.all =  gDisCom.RecBuf[22];
	gSysCtlVal.TestCtl7.all =  gDisCom.RecBuf[23];
	gSysCtlVal.TestCtl8.all =  gDisCom.RecBuf[24];
	gSysCtlVal.TestCtl9.all =  gDisCom.RecBuf[25];
	gSysCtlVal.TestCtl10.all =  gDisCom.RecBuf[26];
	gSysCtlVal.TestCtl11.all =  gDisCom.RecBuf[27];


	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_Test;
	gDisCom.TxdBuf[3] = gSysHard.InPort1.All&0xff;
	gDisCom.TxdBuf[4] = gSysHard.InPort1.All>>8;
	gDisCom.TxdBuf[5] = gSysHard.InPort2.All&0xff;
	gDisCom.TxdBuf[6] = (gSysHard.InPort2.All>>8) + ((gSysHard.VfdErr.All & 0x0300) >> 2);
	gDisCom.TxdBuf[7] = gSysHard.VfdErr.All&0xff;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;



}

//功能码,设置1, 生产设置+纺纱工艺
static void _parse_data_p1(void)
{

	u16 temp = 0;

	gSysPar.SX_Type = gDisCom.RecBuf[3];
	gSysPar.SZS_Type = gDisCom.RecBuf[4];
	gSysPar.SZS_Num = (gDisCom.RecBuf[5]<<8) + gDisCom.RecBuf[6];
	gSysPar.MT_Len = (gDisCom.RecBuf[7]<<24) +  (gDisCom.RecBuf[8]<<16) +  (gDisCom.RecBuf[9]<<8) + gDisCom.RecBuf[10];
	gSysPar.MT_Weight_g = (gDisCom.RecBuf[11]<<8) + gDisCom.RecBuf[12];
	gSysPar.MT_Weight_b = (gDisCom.RecBuf[13]<<8) + gDisCom.RecBuf[14];
	gSysPar.SL_En = gDisCom.RecBuf[15];
	gSysPar.DZ_ContinueGQ = gDisCom.RecBuf[16];
	gSysPar.TEN_En = gDisCom.RecBuf[17];
	gSysPar.DY_StartDW = gDisCom.RecBuf[18];
	gSysPar.DY_StopDW = gDisCom.RecBuf[19];
	gSysPar.DY_Len = (gDisCom.RecBuf[20]<<24) +  (gDisCom.RecBuf[21]<<16) +  (gDisCom.RecBuf[22]<<8) + gDisCom.RecBuf[23];
	gSysPar.XSPD = (gDisCom.RecBuf[24]<<8) + gDisCom.RecBuf[25];
	gSysPar.TDR = (gDisCom.RecBuf[26]<<8) + gDisCom.RecBuf[27];
	gSysPar.MDR = (gDisCom.RecBuf[28]<<8) + gDisCom.RecBuf[29];
	gSysPar.BDR = (gDisCom.RecBuf[30]<<8) + gDisCom.RecBuf[31];
	gSysPar.WDR = (gDisCom.RecBuf[32]<<8) + gDisCom.RecBuf[33];
	gSysPar.JDR = (gDisCom.RecBuf[34]<<8) + gDisCom.RecBuf[35];
	gSysPar.BR = (gDisCom.RecBuf[36]<<8) + gDisCom.RecBuf[37];
	gSysPar.JANG = (gDisCom.RecBuf[38]<<8) + gDisCom.RecBuf[39];
	gSysPar.SL_Spd = (gDisCom.RecBuf[40]<<8) + gDisCom.RecBuf[41];
	gSysPar.SL_Dir = gDisCom.RecBuf[42];
	gSysPar.DD_TSEn = gDisCom.RecBuf[43];

	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x1);
	gDisCom.ParRxFlag = 0;
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x1;
	gDisCom.ParTransDlyCnt = 100;

	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P1;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;


}


//功能码,设置2 ， 纺纱传感器+接捻器
static void _parse_data_p2(void)
{


	u16 temp = 0;
	
	gSysPar.TEN_HThd = (gDisCom.RecBuf[3]<<8) + gDisCom.RecBuf[4];
	gSysPar.TEN_LThd = (gDisCom.RecBuf[5]<<8) + gDisCom.RecBuf[6];
	gSysPar.TEN_BDThd =  (gDisCom.RecBuf[7]<<8) + gDisCom.RecBuf[8];
	gSysPar.TEN_Reset = gDisCom.RecBuf[9];
	gSysPar.JN_PZType = gDisCom.RecBuf[10];
	gSysPar.JN_JieNianStartTime =  (gDisCom.RecBuf[11]<<8) + gDisCom.RecBuf[12];
	gSysPar.JN_JieNianTime =  (gDisCom.RecBuf[13]<<8) + gDisCom.RecBuf[14];
	gSysPar.JN_JiaNianStartTime =  (gDisCom.RecBuf[15]<<8) + gDisCom.RecBuf[16];
	gSysPar.JN_JiaNianTime =  (gDisCom.RecBuf[17]<<8) + gDisCom.RecBuf[18];
	gSysPar.JN_JiaNianStartTime3 =  (gDisCom.RecBuf[19]<<8) + gDisCom.RecBuf[20];
	gSysPar.JN_JiaNianTime3 =  (gDisCom.RecBuf[21]<<8) + gDisCom.RecBuf[22];
	gSysPar.JN_LnPos =  (gDisCom.RecBuf[23]<<8) + gDisCom.RecBuf[24];
	gSysPar.JN_MonitorN =  (gDisCom.RecBuf[25]<<8) + gDisCom.RecBuf[26];
	gSysPar.JN_MonitorS =  (gDisCom.RecBuf[27]<<8) + gDisCom.RecBuf[28];
	gSysPar.JN_MonitorSLen =  (gDisCom.RecBuf[29]<<8) + gDisCom.RecBuf[30];
	gSysPar.JNC_LL_StartDlyTime =  (gDisCom.RecBuf[31]<<8) + gDisCom.RecBuf[32];
	gSysPar.JNC_LL_QGOut_DlyTime =  (gDisCom.RecBuf[33]<<8) + gDisCom.RecBuf[34];
	gSysPar.JNC_TL_Spd =  (gDisCom.RecBuf[35]<<8) + gDisCom.RecBuf[36];
	gSysPar.JNC_DJ_Spd =  (gDisCom.RecBuf[37]<<8) + gDisCom.RecBuf[38];

	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x2);
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x2;
	gDisCom.ParTransDlyCnt = 100;


	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P2;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;

}


//'功能码,设置3 ， 单锭参数
static void _parse_data_p3(void)
{
	u16 temp = 0;

	gSysPar.DD_JTTryN = gDisCom.RecBuf[3];
	gSysPar.DD_RedCtl = gDisCom.RecBuf[4];
	gSysPar.DD_L1 =  (gDisCom.RecBuf[5]<<16) +  (gDisCom.RecBuf[6]<<8) + gDisCom.RecBuf[7];
	gSysPar.DD_L2 =  (gDisCom.RecBuf[8]<<16) +  (gDisCom.RecBuf[9]<<8) + gDisCom.RecBuf[10];
	gSysPar.DD_L3 =  (gDisCom.RecBuf[11]<<16) +  (gDisCom.RecBuf[12]<<8) + gDisCom.RecBuf[13];
	gSysPar.DD_L4 =  (gDisCom.RecBuf[14]<<16) +  (gDisCom.RecBuf[15]<<8) + gDisCom.RecBuf[16];
	gSysPar.DD_L5 =  (gDisCom.RecBuf[17]<<16) +  (gDisCom.RecBuf[18]<<8) + gDisCom.RecBuf[19];
	gSysPar.DD_L6 =  (gDisCom.RecBuf[20]<<16) +  (gDisCom.RecBuf[21]<<8) + gDisCom.RecBuf[22];
	gSysPar.DD_L7 =  (gDisCom.RecBuf[23]<<16) +  (gDisCom.RecBuf[24]<<8) + gDisCom.RecBuf[25];
	gSysPar.DD_L8 =  (gDisCom.RecBuf[26]<<16) +  (gDisCom.RecBuf[27]<<8) + gDisCom.RecBuf[28];
	gSysPar.DD_T1 =  (gDisCom.RecBuf[29]<<8) + gDisCom.RecBuf[30];
	gSysPar.DD_T2 =  (gDisCom.RecBuf[31]<<8) + gDisCom.RecBuf[32];
	gSysPar.DD_T3 =  (gDisCom.RecBuf[33]<<8) + gDisCom.RecBuf[34];
	gSysPar.DD_T4 =  (gDisCom.RecBuf[35]<<8) + gDisCom.RecBuf[36];
	gSysPar.DD_T5 =  (gDisCom.RecBuf[37]<<8) + gDisCom.RecBuf[38];
	gSysPar.DD_T6 =  (gDisCom.RecBuf[39]<<8) + gDisCom.RecBuf[40];
	gSysPar.DD_T7 =  (gDisCom.RecBuf[41]<<8) + gDisCom.RecBuf[42];
	gSysPar.DD_T8 =  (gDisCom.RecBuf[43]<<8) + gDisCom.RecBuf[44];
	gSysPar.DD_MTAlarmTime =  (gDisCom.RecBuf[45]<<8) + gDisCom.RecBuf[46];



	
	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x4);
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x4;
	gDisCom.ParTransDlyCnt = 100;

	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P3;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;



}

//功能码,设置4 ， 接捻小车
static void _parse_data_p4(void)
{

	u16 temp = 0;

	gSysPar.JNC_JSQ_CloseDlyTime =  (gDisCom.RecBuf[3]<<8) + gDisCom.RecBuf[4];
	gSysPar.JNC_TL_StayTime =  (gDisCom.RecBuf[5]<<8) + gDisCom.RecBuf[6];
	gSysPar.JNC_SBS_CheckDlyTime =  (gDisCom.RecBuf[7]<<8) + gDisCom.RecBuf[8];
	gSysPar.JNC_XBS_CheckDlyTime =  (gDisCom.RecBuf[9]<<8) + gDisCom.RecBuf[10];
	gSysPar.JNC_ST_UpDlyTime =  (gDisCom.RecBuf[11]<<8) + gDisCom.RecBuf[12];
	gSysPar.JNC_LL_SpdCtl =  gDisCom.RecBuf[13];
	gSysPar.JNC_LL_F1 =  (gDisCom.RecBuf[14]<<8) + gDisCom.RecBuf[15];
	gSysPar.JNC_LL_F2 =  (gDisCom.RecBuf[16]<<8) + gDisCom.RecBuf[17];
	gSysPar.JNC_LL_F3 =  (gDisCom.RecBuf[18]<<8) + gDisCom.RecBuf[19];
	gSysPar.JNC_LL_F4 =  (gDisCom.RecBuf[20]<<8) + gDisCom.RecBuf[21];
	gSysPar.JNC_LL_F5 =  (gDisCom.RecBuf[22]<<8) + gDisCom.RecBuf[23];
	gSysPar.JNC_LL_F6 =  (gDisCom.RecBuf[24]<<8) + gDisCom.RecBuf[25];
	gSysPar.JNC_LL_F7 =  (gDisCom.RecBuf[26]<<8) + gDisCom.RecBuf[27];
	gSysPar.JNC_LL_F8 =  (gDisCom.RecBuf[28]<<8) + gDisCom.RecBuf[29];
	gSysPar.JNC_LL_FwdTime =  (gDisCom.RecBuf[30]<<8) + gDisCom.RecBuf[31];
	gSysPar.JNC_DXZ_XiShaTimeLT =  (gDisCom.RecBuf[32]<<8) + gDisCom.RecBuf[33];
	gSysPar.JNC_DXZ_XiShaTimeHD =  (gDisCom.RecBuf[34]<<8) + gDisCom.RecBuf[35];
	gSysPar.JNC_SLQJ_OpenTime =  (gDisCom.RecBuf[36]<<8) + gDisCom.RecBuf[37];
	gSysPar.JNC_SLQJ_ColseTime =  (gDisCom.RecBuf[38]<<8) + gDisCom.RecBuf[39];
	gSysPar.JNC_SLQJ_Time =  (gDisCom.RecBuf[40]<<8) + gDisCom.RecBuf[41];
	gSysPar.JNC_XXZ_JiaNianTime =  (gDisCom.RecBuf[42]<<8) + gDisCom.RecBuf[43];
	gSysPar.JNC_XXZ_XiShaTime =  (gDisCom.RecBuf[44]<<8) + gDisCom.RecBuf[45];


	
	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x8);
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x8;
	gDisCom.ParTransDlyCnt = 100;

	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P4;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;


}

//批次：落纱小车+主机
static void _parse_data_p5(void)
{

	u16 temp = 0;

	gSysPar.LSC_TL_StayTime =  (gDisCom.RecBuf[3]<<8) + gDisCom.RecBuf[4];
	gSysPar.LSC_RTJS_Time =  (gDisCom.RecBuf[5]<<8) + gDisCom.RecBuf[6];
	gSysPar.LSC_RTJS_Spd =  (gDisCom.RecBuf[7]<<8) + gDisCom.RecBuf[8];
	gSysPar.LSC_ST_Mode =   gDisCom.RecBuf[9];
	gSysPar.LSC_DB_OpenTime =  (gDisCom.RecBuf[10]<<8) + gDisCom.RecBuf[11];
	
	gSysPar.MFJ_Fre =  (gDisCom.RecBuf[12]<<8) + gDisCom.RecBuf[13];
	gSysPar.SFJ_Fre =  (gDisCom.RecBuf[14]<<8) + gDisCom.RecBuf[15];
	gSysPar.FD_Rto =  (gDisCom.RecBuf[16]<<8) + gDisCom.RecBuf[17];
	gSysPar.FD_LT =  (gDisCom.RecBuf[18]<<8) + gDisCom.RecBuf[19];
	gSysPar.FD_HT =  (gDisCom.RecBuf[20]<<8) + gDisCom.RecBuf[21];
	gSysPar.PQ_Time =  (gDisCom.RecBuf[22]<<8) + gDisCom.RecBuf[23];
	gSysPar.PQ_Period =  (gDisCom.RecBuf[24]<<8) + gDisCom.RecBuf[25];
	gSysPar.PQ_OpenTime =  (gDisCom.RecBuf[26]<<8) + gDisCom.RecBuf[27];
	gSysPar.PQ_CloseTime =  (gDisCom.RecBuf[28]<<8) + gDisCom.RecBuf[29];
	gSysPar.LL_AlarmTime =  (gDisCom.RecBuf[30]<<8) + gDisCom.RecBuf[31];
	gSysPar.HHSD_AlarmTime =  (gDisCom.RecBuf[32]<<8) + gDisCom.RecBuf[33];
	gSysPar.FM_CloseTime =  (gDisCom.RecBuf[34]<<8) + gDisCom.RecBuf[35];
	gSysPar.HH_RunTime =  (gDisCom.RecBuf[36]<<8) + gDisCom.RecBuf[37];
	gSysPar.CFQJ_Period =  (gDisCom.RecBuf[38]<<8) + gDisCom.RecBuf[39];
	gSysPar.CF_DlyClose =  (gDisCom.RecBuf[40]<<8) + gDisCom.RecBuf[41];
	gSysPar.TransOverTimeThd =  (gDisCom.RecBuf[42]<<8) + gDisCom.RecBuf[43];
	gSysPar.LL_TimeThd =  (gDisCom.RecBuf[44]<<8) + gDisCom.RecBuf[45];
	gSysPar.HL_TimeThd =  (gDisCom.RecBuf[46]<<8) + gDisCom.RecBuf[47];


	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x10);
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x10;
	gDisCom.ParTransDlyCnt = 100;

	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P5;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;


}

//系统配置
static void _parse_data_p6(void)
{
	u16 temp = 0;

	gSysPar.NodeNum =   gDisCom.RecBuf[3];
	gSysPar.JNC_CFG =   gDisCom.RecBuf[4];
	gSysPar.JNC_S[0] =   gDisCom.RecBuf[5];
	gSysPar.JNC_E[0] =   gDisCom.RecBuf[6];
	gSysPar.JNC_S[1] =   gDisCom.RecBuf[7];
	gSysPar.JNC_E[1] =   gDisCom.RecBuf[8];
	gSysPar.JNC_S[2] =   gDisCom.RecBuf[9];
	gSysPar.JNC_E[2] =   gDisCom.RecBuf[10];
	gSysPar.JNC_S[3] =   gDisCom.RecBuf[11];
	gSysPar.JNC_E[3] =   gDisCom.RecBuf[12];
	gSysPar.JNC_SpdH =  (gDisCom.RecBuf[13]<<8) + gDisCom.RecBuf[14];
	gSysPar.JNC_DXZ_WaitPos =  (gDisCom.RecBuf[15]<<8) + gDisCom.RecBuf[16];
	gSysPar.JNC_JNJGQ =   gDisCom.RecBuf[17];
	gSysPar.LSC_S1 =   gDisCom.RecBuf[18];
	gSysPar.LSC_E1 =   gDisCom.RecBuf[19];
	gSysPar.LSC_GGDEV_RunMode =   gDisCom.RecBuf[20];
	gSysPar.LSC_GGDEV_EmptyFillMode =   gDisCom.RecBuf[21];
	gSysPar.LSC_HSpd =   gDisCom.RecBuf[22];
	gSysPar.LSC_MSpd =   gDisCom.RecBuf[23];
	gSysPar.LSC_LSpd =   gDisCom.RecBuf[24];
	gSysPar.MFJ_CFG =   gDisCom.RecBuf[25];
	gSysPar.SFJ_CFG =   gDisCom.RecBuf[26];
	gSysPar.JNC_SpdM =  (gDisCom.RecBuf[27]<<8) + gDisCom.RecBuf[28];
	gSysPar.JNC_SpdL  =  (gDisCom.RecBuf[29]<<8) + gDisCom.RecBuf[30];

	
	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x20);
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x20;
	gDisCom.ParTransDlyCnt = 100;

	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P6;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;


}
// 辅助参数及报警设定
static void _parse_data_p7(void)
{
	u16 temp = 0;

	gSysPar.STOP_AVG_ShortPeriod =   gDisCom.RecBuf[3];
	gSysPar.STOP_AVG_CV =   gDisCom.RecBuf[4];
	gSysPar.STOP_HD =   gDisCom.RecBuf[5];
	gSysPar.STOP_HD_Thd =   gDisCom.RecBuf[6];
	gSysPar.STOP_DS =   gDisCom.RecBuf[7];
	gSysPar.STOP_DS_TimeThd =   gDisCom.RecBuf[8];
	gSysPar.STOP_DS_CntThd =   gDisCom.RecBuf[9];
	gSysPar.STOP_SL =   gDisCom.RecBuf[10];
	gSysPar.STOP_SL_TimeThd =   gDisCom.RecBuf[11];
	gSysPar.STOP_ReleaseTime =   gDisCom.RecBuf[12];
	gSysPar.ERR_DectMode =   gDisCom.RecBuf[13];
	gSysPar.STOP_TEN_RefValErr =   gDisCom.RecBuf[14];
	gSysPar.STOP_TEN_RefValErrThd =   gDisCom.RecBuf[15];
	gSysPar.LL1_SpdErrThd =   gDisCom.RecBuf[16];
	gSysPar.LL2_SpdErrThd =   gDisCom.RecBuf[17];
	gSysPar.LL3_SpdErrThd =   gDisCom.RecBuf[18];
	gSysPar.LL4_SpdErrThd =   gDisCom.RecBuf[19];
	gSysPar.MFJ_HP =  (gDisCom.RecBuf[20]<<8) + gDisCom.RecBuf[21];
	gSysPar.MFJ_LP =  (gDisCom.RecBuf[22]<<8) + gDisCom.RecBuf[23];
	gSysPar.MFJ_AlarmThd =  (gDisCom.RecBuf[24]<<8) + gDisCom.RecBuf[25];
	gSysPar.SFJ_HP =  (gDisCom.RecBuf[26]<<8) + gDisCom.RecBuf[27];
	gSysPar.SFJ_LP =  (gDisCom.RecBuf[28]<<8) + gDisCom.RecBuf[29];
	gSysPar.SFJ_AlarmThd =  (gDisCom.RecBuf[30]<<8) + gDisCom.RecBuf[31];

	
	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x40);
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x40;
	gDisCom.ParTransDlyCnt = 100;
	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P7;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;



}
static void _parse_data_p11(void)
{
	u16 temp = 0;

	gDbgPar.DD_QJ1_T1 =   gDisCom.RecBuf[3];
	gDbgPar.DD_QJ1_T2 =   gDisCom.RecBuf[4];
	gDbgPar.DD_QJ1_T3 =   gDisCom.RecBuf[5];
	gDbgPar.DD_QJ1_T4 =   gDisCom.RecBuf[6];
	gDbgPar.DD_QJ1_T5 =   gDisCom.RecBuf[7];
	gDbgPar.DD_QJ1_T6 =    gDisCom.RecBuf[8];
	gDbgPar.DD_QJ1_T7 =   gDisCom.RecBuf[9];
	gDbgPar.DD_QJ1_T8 =   gDisCom.RecBuf[10];
	gDbgPar.DD_QJ1_T9 =   gDisCom.RecBuf[11];
	gDbgPar.DD_QJ1_T10 =   gDisCom.RecBuf[12];
	gDbgPar.DD_QJ1_T11 =   gDisCom.RecBuf[13];
	gDbgPar.DD_WT_T1 =   gDisCom.RecBuf[14];
	gDbgPar.DD_WT_T2 =   gDisCom.RecBuf[15];
	gDbgPar.DD_WT_T3 =   gDisCom.RecBuf[16];
	gDbgPar.DD_QJ2_T1 =   gDisCom.RecBuf[17];
	gDbgPar.DD_QJ2_T2 =   gDisCom.RecBuf[18];
	gDbgPar.DD_QJ2_T3 =   gDisCom.RecBuf[19];
	gDbgPar.DD_QJ2_T4 =   gDisCom.RecBuf[20];
	gDbgPar.DD_QJ2_T5 =   gDisCom.RecBuf[21];
	gDbgPar.DD_QJ2_T6 =   gDisCom.RecBuf[22];
	gDbgPar.DD_NJ_T1 =  gDisCom.RecBuf[23];
	gDbgPar.DD_NJ_T2 =   gDisCom.RecBuf[24];
	gDbgPar.DD_NJ_T3 =  gDisCom.RecBuf[25];
	gDbgPar.DD_NJ_T4 =   gDisCom.RecBuf[26];
	gDbgPar.DD_NJ_T5 =   gDisCom.RecBuf[27];
	gDbgPar.DD_NJ_T6 =   gDisCom.RecBuf[28];
	gDbgPar.DD_NJ_T7 =   gDisCom.RecBuf[29];
	gDbgPar.DD_NJ_T8 =   gDisCom.RecBuf[30];

	
	gDisCom.ParRequestFlag = gDisCom.ParRequestFlag & (~0x80);
	gDisCom.ParRxFlag = gDisCom.ParRxFlag + 0x80;
	gDisCom.ParTransDlyCnt = 100;
	//Ack
	gDisCom.TxdBuf[0] = 0x5A;
	gDisCom.TxdBuf[1] = 0x4B;
	gDisCom.TxdBuf[2] = EXCMD_P11;
	gDisCom.TxdBuf[3] = 0;
	gDisCom.TxdBuf[4] = 0;
	gDisCom.TxdBuf[5] = 0;
	gDisCom.TxdBuf[6] = 0;
	gDisCom.TxdBuf[7] = 0;
	temp = sum_check(gDisCom.TxdBuf, 8);
	gDisCom.TxdBuf[8] = temp&0xff;
	gDisCom.TxdBuf[9] = 0xff-gDisCom.TxdBuf[8];

	gDisCom.TxdFlag = 1;
	gDisCom.TxdLen = 10;
	gDisCom.TxdDly = 5;



}

static u8 _send_intervl(u8 *dp)
{
	static u8 n=0;
	u8 sci_state =0;
	
	if(gDisCom.TxdSts == 0)//发送数据
	{
		SCI_A_DE_CTL(USART_BUS_TXD);
		n = 0;
		gDisCom.TxdSts = 1;
	}else if(gDisCom.TxdSts==1)//等待发送完成
	{
		USARTA_TXD(dp[n]);
		gDisCom.TxdSts = 2;
		n++;
		gDisCom.TxdErr = 0;
	}
	else if(gDisCom.TxdSts==2)//等待发送完成
	{
		sci_state = USARTA_TXD_OK();
		if(sci_state)//发送完成单个字节
		{
			if(n>=gDisCom.TxdLen)//发送完成
			{
				gDisCom.TxdSts = 0;
				n = 0;
				SCI_A_DE_CTL(USART_BUS_RXD);
				return 1;
			}else{
				gDisCom.TxdSts = 1;
			}
		}
		else
		{
			gDisCom.TxdErr ++;
			if(gDisCom.TxdErr  > 1000)
			{
				gDisCom.TxdErr  = 0;
				SCI_A_DE_CTL(USART_BUS_RXD);
				return 2;
			}
		}
	}
	return 0;		
}

void dis_com_init(void)
{
	memset(&gDisCom, 0, sizeof(DisCom_t));

	gDisCom.RxdLen =  40;
	gDisCom.ParRequestFlag = DIS_COM_PAR_MASK;

	


}


void dis_com_rx(u8 temp)
{
	if(gDisCom.RxdFlag) 
	{
		// 上一帧数据未处理
		return;
	}


	//--------------------------------------------------------------//
	//长度判断	
	if(gDisCom.RxdIndex>= gDisCom.RxdLen && gDisCom.RxdLen){
		gDisCom.RxdIndex= 0;
	}
	if(gDisCom.RxdTicker == 0 && gDisCom.RxdIndex)
	{
		gDisCom.RxdIndex= 0;
	}
	gDisCom.RxdTicker = 5;
	//--------------------------------------------------------------//	
	
	//--------------------------------------------------------------//
	//数据缓存	
	gDisCom.RecBuf[gDisCom.RxdIndex] = temp;
	//--------------------------------------------------------------//

	//--------------------------------------------------------------//
	//头码判断
	if(gDisCom.RecBuf[0] != 0xA5)
	{
		gDisCom.RxdIndex= 0;
		return;
	}
	else if(gDisCom.RecBuf[1] != 0xB4 && gDisCom.RxdIndex== 1)
	{
		gDisCom.RxdIndex= 0;
		return;
	}
	else if(gDisCom.RxdIndex ==2)
	{

		if(gDisCom.RecBuf[2] == EXCMD_Flash
		|| gDisCom.RecBuf[2] == EXCMD_Test
		|| gDisCom.RecBuf[2] == EXCMD_Flash1)
		{
			gDisCom.RxdLen =  30;
		}
		else if(gDisCom.RecBuf[2] == EXCMD_P1 
		|| gDisCom.RecBuf[2] == EXCMD_P2 
		|| gDisCom.RecBuf[2] == EXCMD_P3 
		|| gDisCom.RecBuf[2] == EXCMD_P4 
		|| gDisCom.RecBuf[2] == EXCMD_P5
		|| gDisCom.RecBuf[2] == EXCMD_P6 
		|| gDisCom.RecBuf[2] == EXCMD_P7 
		|| gDisCom.RecBuf[2] == EXCMD_P11 )
		{
			gDisCom.RxdLen =  50;
		}
		else
		{
			gDisCom.RxdLen =  30;
		}
	}
	else if(gDisCom.RxdIndex== gDisCom.RxdLen-1&& gDisCom.RxdIndex >3)
	{

		gDisCom.RxdFlag = TRUE;
		gDisCom.RxdIndex = 0;
	}
	
	gDisCom.RxdIndex++;
	
}






void dis_com_tx(u8 len)
{
	if(gDisCom.TxdSts == 0)//发送数据
	{
		SCI_A_DE_CTL(USART_BUS_TXD);
		gDisCom.TxdSts = 1;
	}
	else if(gDisCom.TxdSts==1)//等待发送完成
	{
		USARTA_TC_CLR();           // 清发送完成状态
		USARTA_TXD(gDisCom.TxdBuf[0]);
		 
		gDisCom.TxdCnt = 0;
		gDisCom.TxdLen = len;	
		gDisCom.TxdSts = 2;
	}
	else
	{
	
	}



}


void dis_com_task(void)
{
	u16 temp = 0;
	u8 sum_checkk = 0,Fmsum_checkk = 0;
	u8* data = NULL;
	

	if(gDisCom.ConnectFlag)
	{
		//USARTB_COM_REST = 0;
		//gDisCom.TxdFlag = 0;
		//gDisCom.RxdFlag = 0;
		//gDisCom.RxdIndex = 0;
		//gDisCom.RxdLen = 0;
		//USARTB_COM_REST = 1;
		//gDisCom.ConnectFlag = 0;
		//gDisCom.ConnectTicker = 0;


	}


	
	if(gDisCom.TxdFlag)
	{	
		#if 0
		if(gDisCom.TxdDly == 0)
		{
			u8 sts = excom_send_intervl(ExComTxdBuf);
			if(sts == 1)
			{
				gDisCom.tx_ok ++;
				//状态恢复
				memset(ExComTxdBuf,0,DIS_COM_FRAM_LEN);
				gDisCom.TxdFlag = 0;
				gDisCom.TxdSts = 0;
				memset(ExComRecBuf,0,DIS_COM_FRAM_LEN);
				gDisCom.RxdFlag = 0;
				gDisCom.RxdIndex = 0;
			}
			else if(sts == 2)
			{
				//USARTB_COM_REST = 0;
				gDisCom.TxdFlag = 0;
				gDisCom.RxdFlag = 0;
				gDisCom.RxdIndex = 0;
				//USARTB_COM_REST = 1;

			}
		}
		else
		{

		}
		#else
		if(gDisCom.TxdDly)
		{
			SCI_B_DE_CTL(USART_BUS_TXD);			
		}
		else
		{
			dis_com_tx(gDisCom.TxdLen);
		}
		
		#endif
		return;

	}




	if(gDisCom.ParSave && gDisCom.ParSaveDlyCnt == 0)
	{
		gDisCom.ParSave = 0;
		//SysParP0.SAVE = 1;
		//gComMaster.ParUpdate = 0x1;
	}

	if(gDisCom.ParRxFlag && gDisCom.ParTransDlyCnt==0)
	{
		gDisCom.ParOk ++;
		gDisCom.ParRxFlag = 0;
		//单节参数需要转发
		for(u8 i=0;i<MAX_NODE_NUM;i++)
			gCanBusCtl1.DataRequestMain[i] = 1;
		//机尾参数需要转发
		gCanBusCtl1.DataRequestSub[0] = 1;
		gCanBusCtl1.DataRequestSub[1] = 1;
		//接捻小车参数需要转发
		for(u8 i=0;i<MAX_JN_NUM;i++)
			gCanBusCtl2.DataRequestMain[i] = 1;
		//AD 小车参数需要转发
		gCanBusCtl2.DataRequestSub[0] = 1;

	}
	
		
	
	if(gDisCom.RxdFlag == FALSE){
		// 等待接收完成
		return;
	}
	gDisCom.rx_ok ++;



	//判断校验码是否正确

	temp = sum_check(gDisCom.RecBuf,gDisCom.RxdLen-2);
	sum_checkk = temp&0xff;
	Fmsum_checkk = 0xff-sum_checkk;
	if((gDisCom.RecBuf[gDisCom.RxdLen-2] != sum_checkk)||(gDisCom.RecBuf[gDisCom.RxdLen-1] != Fmsum_checkk))
	{
		
		goto LoopErrEnd;
	}

	gDisCom.chk_ok ++;
	gDisCom.ConnectFlag= FALSE;
	gDisCom.ConnectTicker = 0;		

	switch(gDisCom.RecBuf[2])
	{
	case EXCMD_Flash: _parse_data_flash();	break;
	case EXCMD_Flash1: _parse_data_flash1();	break;
	case EXCMD_Test: _parse_data_test();	break;
	case EXCMD_P1: _parse_data_p1();	break;
	case EXCMD_P2: _parse_data_p2();	break;
	case EXCMD_P3: _parse_data_p3();	break;
	case EXCMD_P4: _parse_data_p4();	break;
	case EXCMD_P5: _parse_data_p5();	break;
	case EXCMD_P6: _parse_data_p6();	break;
	case EXCMD_P7: _parse_data_p7();	break;
	case EXCMD_P11: _parse_data_p11();	break;
	default:break;
	}



	
	
	if(gDisCom.TxdFlag)
		return ;

LoopErrEnd:	
	memset(gDisCom.RecBuf,0,DIS_COM_FRAM_LEN);
	gDisCom.RxdFlag = 0;
	gDisCom.RxdIndex = 0;
}
/***************************************************************/

