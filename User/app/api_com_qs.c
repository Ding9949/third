#include "sys_include.h"

QsCom_t gQsCom;

//加载数据
static void _parse_data(void)
{
	u8 i = 0;
	u8 node = 0;
	u8 ads = 0;
	u16 temp = 0;
	switch(gQsCom.RecBuf[3])
	{
	case QS_CMD_Addr: 
		break;
	case QS_CMD_Stop:
		break;
	case QS_CMD_Start:
		break;
	case QS_CMD_Cut:
		break;
	case QS_CMD_Param:
		gQsPar.P01_0 =  gQsCom.RecBuf[4]; //
		gQsPar.P01_1 =  gQsCom.RecBuf[5]; //
		gQsPar.P02 =  (gQsCom.RecBuf[6]<<8) +  gQsCom.RecBuf[7]; //
		gQsPar.P03 =  (gQsCom.RecBuf[8]<<8) +  gQsCom.RecBuf[9]; //
		gQsPar.P04 =  (gQsCom.RecBuf[10]<<8) +  gQsCom.RecBuf[11]; //
		
		gQsPar.P11 =  (gQsCom.RecBuf[12]<<8) +  gQsCom.RecBuf[13]; //
		gQsPar.P12 =  (gQsCom.RecBuf[14]<<8) +  gQsCom.RecBuf[15]; //
		gQsPar.P13 =  (gQsCom.RecBuf[16]<<8) +  gQsCom.RecBuf[17]; //
		gQsPar.P14 =  (gQsCom.RecBuf[18]<<8) +  gQsCom.RecBuf[19]; //
		
		gQsPar.P21 =  (gQsCom.RecBuf[20]<<8) +  gQsCom.RecBuf[21]; //
		gQsPar.P22 =  (gQsCom.RecBuf[22]<<8) +  gQsCom.RecBuf[23]; //
		gQsPar.P23 =  (gQsCom.RecBuf[24]<<8) +  gQsCom.RecBuf[25]; //
		gQsPar.P24 =  (gQsCom.RecBuf[26]<<8) +  gQsCom.RecBuf[27]; //
		
		gQsPar.P31 =  (gQsCom.RecBuf[28]<<8) +  gQsCom.RecBuf[29]; //
		gQsPar.P32_0 =  gQsCom.RecBuf[30]; //
		gQsPar.P32_1 =  gQsCom.RecBuf[31]; //
		gQsPar.P33_0 =  gQsCom.RecBuf[32]; //
		gQsPar.P33_1 =  gQsCom.RecBuf[33]; //
		gQsPar.P34_0 =  gQsCom.RecBuf[34]; //

		for(i=0;i<MAX_NODE_NUM;i++)
			gCanBusCtl1.DataRequestQs[i] = 1;


		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;

		temp = check_crc16(gQsCom.TxdBuf, 2);
		gQsCom.TxdBuf[2] = temp&0xff;
		gQsCom.TxdBuf[3] = (temp>>8)&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 4;
		gQsCom.TxdDly = 5;
		break;
	case QS_CMD_Flash:

		node =  gQsCom.RecBuf[2]-1;
	
		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;
		if(node < MAX_NODE_NUM)
		{
			gQsCom.TxdBuf[2] = gStatus.Node[node].QsSts[0].Sts;
			gQsCom.TxdBuf[3] = gStatus.Node[node].QsSts[1].Sts;
			gQsCom.TxdBuf[4] = gStatus.Node[node].QsSts[2].Sts;
			gQsCom.TxdBuf[5] = gStatus.Node[node].QsSts[3].Sts;
			gQsCom.TxdBuf[6] = gStatus.Node[node].QsSts[4].Sts;
			gQsCom.TxdBuf[7] = gStatus.Node[node].QsSts[5].Sts;
			gQsCom.TxdBuf[8] = gStatus.Node[node].QsSts[6].Sts;
			gQsCom.TxdBuf[9] = gStatus.Node[node].QsSts[7].Sts;
			gQsCom.TxdBuf[10] = 0;
			gQsCom.TxdBuf[11] = 0;
			gQsCom.TxdBuf[12] = 0;
			gQsCom.TxdBuf[13] = 0;
			gQsCom.TxdBuf[14] = 0;
			gQsCom.TxdBuf[15] = 0;
			gQsCom.TxdBuf[16] = 0;
			gQsCom.TxdBuf[17] = 0;
			gQsCom.TxdBuf[18] = 0;
			gQsCom.TxdBuf[19] = 0;
			gQsCom.TxdBuf[20] = 0;
			gQsCom.TxdBuf[21] = 0;

			gQsCom.TxdBuf[22] = gStatus.Node[node].QsSts[gQsCom.CurSpindle].CV;
			gQsCom.TxdBuf[23] = gStatus.Node[node].QsSts[gQsCom.CurSpindle].CVs;
			gQsCom.TxdBuf[24] = gQsCom.CurSpindle+1;
			gQsCom.CurSpindle++;
			if(gQsCom.CurSpindle>=MAX_SPINDLE_NUM)gQsCom.CurSpindle = 0;
		}
		else
		{
			for(u8 i=2;i<=24;i++)
				gQsCom.TxdBuf[i] = 0;

		}
		
		gQsCom.TxdBuf[25] = gQsCom.ParRequestFlag;

		temp = check_crc16(gQsCom.TxdBuf, 26);
		gQsCom.TxdBuf[27] = temp&0xff;
		gQsCom.TxdBuf[26] = (temp>>8)&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 28;
		gQsCom.TxdDly = 5;
		
		break;
	case QS_CMD_Noise:
		node =  gQsCom.RecBuf[2]-1;
		ads =  gQsCom.RecBuf[4]-1;
		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;
		if(node < MAX_NODE_NUM && ads < MAX_SPINDLE_NUM)
		{
			gQsCom.TxdBuf[2] = gStatus.Node[node].QsSts[ads].Noise;
		}
		else
		{
			gQsCom.TxdBuf[2] = 0;
		}
		temp = check_crc16(gQsCom.TxdBuf, 3);
		gQsCom.TxdBuf[3] = (temp>>8)&0xff;
		gQsCom.TxdBuf[4] = temp&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 5;
		gQsCom.TxdDly = 5;		
		break;	
	case QS_CMD_Sensitivity:
		node =  gQsCom.RecBuf[2]-1;
		ads =  gQsCom.RecBuf[4]-1;
		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;
		if(node < MAX_NODE_NUM && ads < MAX_SPINDLE_NUM)
		{
			gQsCom.TxdBuf[2] = gStatus.Node[node].QsSts[ads].Sensitivity;
		}
		else
		{
			gQsCom.TxdBuf[2] = 0;
		}
		temp = check_crc16(gQsCom.TxdBuf, 3);
		gQsCom.TxdBuf[3] = temp&0xff;
		gQsCom.TxdBuf[4] = (temp>>8)&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 5;
		gQsCom.TxdDly = 5;
		break;
	case QS_CMD_Version:
		node =  gQsCom.RecBuf[2]-1;
		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;
		if(node < MAX_NODE_NUM )
		{
			gQsCom.TxdBuf[2] = gStatus.Node[node].QsSts[0].Version;
			gQsCom.TxdBuf[3] = gStatus.Node[node].QsSts[1].Version;
			gQsCom.TxdBuf[4] = gStatus.Node[node].QsSts[2].Version;
			gQsCom.TxdBuf[5] = gStatus.Node[node].QsSts[3].Version;
			gQsCom.TxdBuf[6] = gStatus.Node[node].QsSts[4].Version;
			gQsCom.TxdBuf[7] = gStatus.Node[node].QsSts[5].Version;
			gQsCom.TxdBuf[8] = gStatus.Node[node].QsSts[6].Version;
			gQsCom.TxdBuf[9] = gStatus.Node[node].QsSts[7].Version;
			gQsCom.TxdBuf[10] = 0;
			gQsCom.TxdBuf[11] = 0;
			gQsCom.TxdBuf[12] = 0;
			gQsCom.TxdBuf[13] = 0;
			gQsCom.TxdBuf[14] = 0;
			gQsCom.TxdBuf[15] = 0;
			gQsCom.TxdBuf[16] = 0;
			gQsCom.TxdBuf[17] = 0;
			gQsCom.TxdBuf[18] = 0;
			gQsCom.TxdBuf[19] = 0;
			gQsCom.TxdBuf[20] = 0;
			gQsCom.TxdBuf[21] = 0;
		}
		else
		{
			for(u8 i=2;i<=21;i++)
				gQsCom.TxdBuf[i] = 0;
		}
		
		gQsCom.TxdBuf[22] = gStatus.Node[node].Version;
		temp = check_crc16(gQsCom.TxdBuf, 23);
		gQsCom.TxdBuf[24] = temp&0xff;
		gQsCom.TxdBuf[23] = (temp>>8)&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 25;
		gQsCom.TxdDly = 5;
		
		break;
	case QS_CMD_Zero:
		node =  gQsCom.RecBuf[2]-1;
		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;
		if(node < MAX_NODE_NUM )
		{
			gQsCom.TxdBuf[2] = (gStatus.Node[node].QsSts[0].Zero>>8);
			gQsCom.TxdBuf[3] = (gStatus.Node[node].QsSts[0].Zero&0xff);
			gQsCom.TxdBuf[4] =gStatus.Node[node].QsSts[0].Driver;
			gQsCom.TxdBuf[5] =  (gStatus.Node[node].QsSts[1].Zero>>8);
			gQsCom.TxdBuf[6] =  (gStatus.Node[node].QsSts[1].Zero&0xff);
			gQsCom.TxdBuf[7] = gStatus.Node[node].QsSts[1].Driver;
			gQsCom.TxdBuf[8] =  (gStatus.Node[node].QsSts[2].Zero>>8);
			gQsCom.TxdBuf[9] =  (gStatus.Node[node].QsSts[2].Zero&0xff);
			gQsCom.TxdBuf[10] = gStatus.Node[node].QsSts[2].Driver;
			gQsCom.TxdBuf[11] =  (gStatus.Node[node].QsSts[3].Zero>>8);
			gQsCom.TxdBuf[12] =  (gStatus.Node[node].QsSts[3].Zero&0xff);
			gQsCom.TxdBuf[13] = gStatus.Node[node].QsSts[3].Driver;
			gQsCom.TxdBuf[14] =  (gStatus.Node[node].QsSts[4].Zero>>8);
			gQsCom.TxdBuf[15] =  (gStatus.Node[node].QsSts[4].Zero&0xff);
			gQsCom.TxdBuf[16] = gStatus.Node[node].QsSts[4].Driver;
			gQsCom.TxdBuf[17] =  (gStatus.Node[node].QsSts[5].Zero>>8);
			gQsCom.TxdBuf[18] =  (gStatus.Node[node].QsSts[5].Zero&0xff);
			gQsCom.TxdBuf[19] = gStatus.Node[node].QsSts[5].Driver;
			gQsCom.TxdBuf[20] =  (gStatus.Node[node].QsSts[6].Zero>>8);
			gQsCom.TxdBuf[21] =  (gStatus.Node[node].QsSts[6].Zero&0xff);
			gQsCom.TxdBuf[22] = gStatus.Node[node].QsSts[6].Driver;
			gQsCom.TxdBuf[23] =  (gStatus.Node[node].QsSts[7].Zero>>8);
			gQsCom.TxdBuf[24] =  (gStatus.Node[node].QsSts[7].Zero&0xff);
			gQsCom.TxdBuf[25] = gStatus.Node[node].QsSts[7].Driver;
			gQsCom.TxdBuf[26] = 0;//8
			gQsCom.TxdBuf[27] = 0;
			gQsCom.TxdBuf[28] = 0;
			gQsCom.TxdBuf[29] = 0;//9
			gQsCom.TxdBuf[30] = 0;
			gQsCom.TxdBuf[31] = 0;
			gQsCom.TxdBuf[32] = 0;//10
			gQsCom.TxdBuf[33] = 0;
			gQsCom.TxdBuf[34] = 0;
			gQsCom.TxdBuf[35] = 0;//11
			gQsCom.TxdBuf[36] = 0;
			gQsCom.TxdBuf[37] = 0;
			gQsCom.TxdBuf[38] = 0;//12
			gQsCom.TxdBuf[39] = 0;
			gQsCom.TxdBuf[40] = 0;
			gQsCom.TxdBuf[41] = 0;//13
			gQsCom.TxdBuf[42] = 0;
			gQsCom.TxdBuf[43] = 0;
			gQsCom.TxdBuf[44] = 0;//14
			gQsCom.TxdBuf[45] = 0;
			gQsCom.TxdBuf[46] = 0;
			gQsCom.TxdBuf[47] = 0;//15
			gQsCom.TxdBuf[48] = 0;
			gQsCom.TxdBuf[49] = 0;
			gQsCom.TxdBuf[50] = 0;//16
			gQsCom.TxdBuf[51] = 0;
			gQsCom.TxdBuf[52] = 0;
			gQsCom.TxdBuf[53] = 0;//17
			gQsCom.TxdBuf[54] = 0;
			gQsCom.TxdBuf[55] = 0;
			gQsCom.TxdBuf[56] = 0;//18
			gQsCom.TxdBuf[57] = 0;
			gQsCom.TxdBuf[58] = 0;
			gQsCom.TxdBuf[59] = 0;//19
			gQsCom.TxdBuf[60] = 0;
			gQsCom.TxdBuf[61] = 0;

			
		}
		else
		{
			for(u8 i=2;i<=61;i++)
				gQsCom.TxdBuf[i] = 0;
		}		
		temp = check_crc16(gQsCom.TxdBuf, 62);
		gQsCom.TxdBuf[62] = temp&0xff;
		gQsCom.TxdBuf[63] = (temp>>8)&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 64;
		gQsCom.TxdDly = 5;
		
		break;	
	case QS_CMD_Dust:
		node =  gQsCom.RecBuf[2]-1;
		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;
		if(node < MAX_NODE_NUM )
		{
			gQsCom.TxdBuf[2] = gStatus.Node[node].QsSts[0].Dust;
			gQsCom.TxdBuf[3] = (gStatus.Node[node].QsSts[0].Avg>>8);
			gQsCom.TxdBuf[4] = (gStatus.Node[node].QsSts[0].Avg&0xff);
			gQsCom.TxdBuf[5] = (gStatus.Node[node].QsSts[0].Avg_Ref>>8);
			gQsCom.TxdBuf[6] = (gStatus.Node[node].QsSts[0].Avg_Ref&0xff);
			gQsCom.TxdBuf[7] = gStatus.Node[node].QsSts[1].Dust;
			gQsCom.TxdBuf[8] = (gStatus.Node[node].QsSts[1].Avg>>8);
			gQsCom.TxdBuf[9] = (gStatus.Node[node].QsSts[1].Avg&0xff);
			gQsCom.TxdBuf[10] = (gStatus.Node[node].QsSts[1].Avg_Ref>>8);
			gQsCom.TxdBuf[11] = (gStatus.Node[node].QsSts[1].Avg_Ref&0xff);
			gQsCom.TxdBuf[12] = gStatus.Node[node].QsSts[2].Dust;
			gQsCom.TxdBuf[13] = (gStatus.Node[node].QsSts[2].Avg>>8);
			gQsCom.TxdBuf[14] = (gStatus.Node[node].QsSts[2].Avg&0xff);
			gQsCom.TxdBuf[15] = (gStatus.Node[node].QsSts[2].Avg_Ref>>8);
			gQsCom.TxdBuf[16] = (gStatus.Node[node].QsSts[2].Avg_Ref&0xff);
			gQsCom.TxdBuf[17] = gStatus.Node[node].QsSts[3].Dust;
			gQsCom.TxdBuf[18] = (gStatus.Node[node].QsSts[3].Avg>>8);
			gQsCom.TxdBuf[19] = (gStatus.Node[node].QsSts[3].Avg&0xff);
			gQsCom.TxdBuf[20] = (gStatus.Node[node].QsSts[3].Avg_Ref>>8);
			gQsCom.TxdBuf[21] = (gStatus.Node[node].QsSts[3].Avg_Ref&0xff);
			gQsCom.TxdBuf[22] = gStatus.Node[node].QsSts[4].Dust;
			gQsCom.TxdBuf[23] = (gStatus.Node[node].QsSts[4].Avg>>8);
			gQsCom.TxdBuf[24] = (gStatus.Node[node].QsSts[4].Avg&0xff);
			gQsCom.TxdBuf[25] = (gStatus.Node[node].QsSts[4].Avg_Ref>>8);
			gQsCom.TxdBuf[26] = (gStatus.Node[node].QsSts[4].Avg_Ref&0xff);
			gQsCom.TxdBuf[27] = gStatus.Node[node].QsSts[5].Dust;
			gQsCom.TxdBuf[28] = (gStatus.Node[node].QsSts[5].Avg>>8);
			gQsCom.TxdBuf[29] = (gStatus.Node[node].QsSts[5].Avg&0xff);
			gQsCom.TxdBuf[30] = (gStatus.Node[node].QsSts[5].Avg_Ref>>8);
			gQsCom.TxdBuf[31] = (gStatus.Node[node].QsSts[5].Avg_Ref&0xff);
			gQsCom.TxdBuf[32] = gStatus.Node[node].QsSts[6].Dust;
			gQsCom.TxdBuf[33] = (gStatus.Node[node].QsSts[6].Avg>>8);
			gQsCom.TxdBuf[34] = (gStatus.Node[node].QsSts[6].Avg&0xff);
			gQsCom.TxdBuf[35] = (gStatus.Node[node].QsSts[6].Avg_Ref>>8);
			gQsCom.TxdBuf[36] = (gStatus.Node[node].QsSts[6].Avg_Ref&0xff);
			gQsCom.TxdBuf[37] = gStatus.Node[node].QsSts[7].Dust;
			gQsCom.TxdBuf[38] = (gStatus.Node[node].QsSts[7].Avg>>8);
			gQsCom.TxdBuf[39] = (gStatus.Node[node].QsSts[7].Avg&0xff);
			gQsCom.TxdBuf[40] = (gStatus.Node[node].QsSts[7].Avg_Ref>>8);
			gQsCom.TxdBuf[41] = (gStatus.Node[node].QsSts[7].Avg_Ref&0xff);
			gQsCom.TxdBuf[42] = 0;//8
			gQsCom.TxdBuf[43] = 0;
			gQsCom.TxdBuf[44] = 0;
			gQsCom.TxdBuf[45] = 0;
			gQsCom.TxdBuf[46] = 0;
			gQsCom.TxdBuf[47] = 0;//9
			gQsCom.TxdBuf[48] = 0;
			gQsCom.TxdBuf[49] = 0;
			gQsCom.TxdBuf[50] = 0;
			gQsCom.TxdBuf[51] = 0;
			gQsCom.TxdBuf[52] = 0;//10
			gQsCom.TxdBuf[53] = 0;
			gQsCom.TxdBuf[54] = 0;
			gQsCom.TxdBuf[55] = 0;
			gQsCom.TxdBuf[56] = 0;
			gQsCom.TxdBuf[57] = 0;//11
			gQsCom.TxdBuf[58] = 0;
			gQsCom.TxdBuf[59] = 0;
			gQsCom.TxdBuf[60] = 0;
			gQsCom.TxdBuf[61] = 0;
			gQsCom.TxdBuf[62] = 0;//12
			gQsCom.TxdBuf[63] = 0;
			gQsCom.TxdBuf[64] = 0;
			gQsCom.TxdBuf[65] = 0;
			gQsCom.TxdBuf[66] = 0;
			gQsCom.TxdBuf[67] = 0;//13
			gQsCom.TxdBuf[68] = 0;
			gQsCom.TxdBuf[69] = 0;
			gQsCom.TxdBuf[70] = 0;
			gQsCom.TxdBuf[71] = 0;
			gQsCom.TxdBuf[72] = 0;//14
			gQsCom.TxdBuf[73] = 0;
			gQsCom.TxdBuf[74] = 0;
			gQsCom.TxdBuf[75] = 0;
			gQsCom.TxdBuf[76] = 0;
			gQsCom.TxdBuf[77] = 0;//15
			gQsCom.TxdBuf[78] = 0;
			gQsCom.TxdBuf[79] = 0;
			gQsCom.TxdBuf[80] = 0;
			gQsCom.TxdBuf[81] = 0;
			gQsCom.TxdBuf[82] = 0;//16
			gQsCom.TxdBuf[83] = 0;
			gQsCom.TxdBuf[84] = 0;
			gQsCom.TxdBuf[85] = 0;
			gQsCom.TxdBuf[86] = 0;
			gQsCom.TxdBuf[87] = 0;//17
			gQsCom.TxdBuf[88] = 0;
			gQsCom.TxdBuf[89] = 0;
			gQsCom.TxdBuf[90] = 0;
			gQsCom.TxdBuf[91] = 0;
			gQsCom.TxdBuf[92] = 0;//18
			gQsCom.TxdBuf[93] = 0;
			gQsCom.TxdBuf[94] = 0;
			gQsCom.TxdBuf[95] = 0;
			gQsCom.TxdBuf[96] = 0;
			gQsCom.TxdBuf[97] = 0;//19
			gQsCom.TxdBuf[98] = 0;
			gQsCom.TxdBuf[99] = 0;
			gQsCom.TxdBuf[100] = 0;
			gQsCom.TxdBuf[101] = 0;

			
		}
		else
		{
			for(u8 i=2;i<=101;i++)
				gQsCom.TxdBuf[i] = 0;
		}	
		temp = check_crc16(gQsCom.TxdBuf, 102);
		gQsCom.TxdBuf[102] = temp&0xff;
		gQsCom.TxdBuf[103] = (temp>>8)&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 104;
		gQsCom.TxdDly = 5;
		
		break;	
	case QS_CMD_Debug:
		node =  gQsCom.RecBuf[2]-1;
		ads =  gQsCom.RecBuf[4]-1;
		gQsCom.TxdBuf[0] = 0x5A;
		gQsCom.TxdBuf[1] = 0x4B;
		if(node < MAX_NODE_NUM && ads < MAX_SPINDLE_NUM)
		{
			gQsCom.TxdBuf[2] = gStatus.Node[node].QsSts[ads].DebugData[0];
			gQsCom.TxdBuf[3] = gStatus.Node[node].QsSts[ads].DebugData[1];
			gQsCom.TxdBuf[4] = gStatus.Node[node].QsSts[ads].DebugData[2];
			gQsCom.TxdBuf[5] = gStatus.Node[node].QsSts[ads].DebugData[3];
			gQsCom.TxdBuf[6] = gStatus.Node[node].QsSts[ads].DebugData[4];
			gQsCom.TxdBuf[7] = gStatus.Node[node].QsSts[ads].DebugData[5];
			gQsCom.TxdBuf[8] = gStatus.Node[node].QsSts[ads].DebugData[6];
			gQsCom.TxdBuf[9] = gStatus.Node[node].QsSts[ads].DebugData[7];
			gQsCom.TxdBuf[10] = gStatus.Node[node].QsSts[ads].DebugData[8];
			gQsCom.TxdBuf[11] = gStatus.Node[node].QsSts[ads].DebugData[9];
			gQsCom.TxdBuf[12] = gStatus.Node[node].QsSts[ads].DebugData[10];
			gQsCom.TxdBuf[13] = gStatus.Node[node].QsSts[ads].DebugData[11];
			gQsCom.TxdBuf[14] = gStatus.Node[node].QsSts[ads].DebugData[12];
			gQsCom.TxdBuf[15] = gStatus.Node[node].QsSts[ads].DebugData[13];
			gQsCom.TxdBuf[16] = gStatus.Node[node].QsSts[ads].DebugData[14];
			gQsCom.TxdBuf[17] = gStatus.Node[node].QsSts[ads].DebugData[15];
			gQsCom.TxdBuf[18] = 0;
			gQsCom.TxdBuf[19] = 0;
			gQsCom.TxdBuf[20] = 0;
			gQsCom.TxdBuf[21] = 0;
			gQsCom.TxdBuf[22] = 0;
			gQsCom.TxdBuf[23] = 0;
			gQsCom.TxdBuf[24] = 0;
			gQsCom.TxdBuf[25] = 0;
			gQsCom.TxdBuf[26] = 0;
			gQsCom.TxdBuf[27] = 0;
			gQsCom.TxdBuf[28] = 0;
			gQsCom.TxdBuf[29] = 0;
			gQsCom.TxdBuf[30] = 0;
			gQsCom.TxdBuf[31] = 0;

		}
		else
		{
			for(u8 i=2;i<=31;i++)
				gQsCom.TxdBuf[i] = 0;
		}	
		temp = check_crc16(gQsCom.TxdBuf, 32);
		gQsCom.TxdBuf[32] = temp&0xff;
		gQsCom.TxdBuf[33] = (temp>>8)&0xff;

		gQsCom.TxdFlag = TRUE;
		gQsCom.TxdLen = 34;
		gQsCom.TxdDly = 5;
		
		break;		
	default:		break;	
	}
}



//数据发送
static u8 _send_intervl(u8 *dp)
{
	static u8 n=0;
	u8 sci_state =0;
	
	
	if(gQsCom.TxdSts == 0)//发送数据
	{
		SCI_C_DE_CTL(USART_BUS_TXD);
		n = 0;
		gQsCom.TxdSts = 1;
	}else if(gQsCom.TxdSts==1)//等待发送完成
	{
		USARTC_TXD(dp[n]);
		gQsCom.TxdSts = 2;
		n++;
		gQsCom.TxdErr = 0;
	}
	else if(gQsCom.TxdSts==2)//等待发送完成
	{
		sci_state = USARTC_TXD_OK();
		if(sci_state)//发送完成单个字节
		{
			if(n>=gQsCom.TxdLen)//发送完成
			{
				gQsCom.TxdSts = 0;
				n = 0;
				SCI_C_DE_CTL(USART_BUS_RXD);
				return 1;
			}else{
				gQsCom.TxdSts = 1;
			}
		}
		else
		{
			gQsCom.TxdErr ++;
			if(gQsCom.TxdErr  > 1000)
			{
				gQsCom.TxdErr  = 0;
				SCI_C_DE_CTL(USART_BUS_RXD);
				return 2;
			}
		}
	}
	return 0;		
}


void qs_com_init(void)
{
	memset(&gQsCom, 0, sizeof(QsCom_t));

	gQsCom.RxdLen =  40;
	//gQsCom.ParRequestFlag = EXCOM_UP_ALL;


	
}


void qs_com_rx(u8 temp)
{
	if(gQsCom.RxdFlag) 
	{
		// 上一帧数据未处理
		return;
	}


	//--------------------------------------------------------------//
	//长度判断	
	if(gQsCom.RxdIndex>= gQsCom.RxdLen && gQsCom.RxdLen){
		gQsCom.RxdIndex= 0;
	}
	if(gQsCom.RxdTicker == 0 && gQsCom.RxdIndex)
	{
		gQsCom.RxdIndex= 0;
	}
	gQsCom.RxdTicker = 5;
	//--------------------------------------------------------------//	
	
	//--------------------------------------------------------------//
	//数据缓存	
	gQsCom.RecBuf[gQsCom.RxdIndex] = temp;
	//--------------------------------------------------------------//

	//--------------------------------------------------------------//
	//头码判断
	if(gQsCom.RecBuf[0] != 0xA5)
	{
		gQsCom.RxdIndex= 0;
		return;
	}
	else if(gQsCom.RecBuf[1] != 0xB4 && gQsCom.RxdIndex ==1)
	{
		gQsCom.RxdIndex= 0;
		return;
	}

	else if(gQsCom.RxdIndex ==3)
	{

		if(gQsCom.RecBuf[3] == QS_CMD_Stop && gQsCom.RecBuf[2] == 0xff)gQsCom.RxdLen =  6;
		else if(gQsCom.RecBuf[3] == QS_CMD_Start  && gQsCom.RecBuf[2] == 0xff)gQsCom.RxdLen =  6;
		else if(gQsCom.RecBuf[3] == QS_CMD_Addr  && gQsCom.RecBuf[2] == 0xff)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Param)gQsCom.RxdLen =  38;
		else if(gQsCom.RecBuf[3] == QS_CMD_Flash)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Noise)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Sensitivity)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Version)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Zero)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Dust)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Cut)gQsCom.RxdLen =  7;
		else if(gQsCom.RecBuf[3] == QS_CMD_Debug)gQsCom.RxdLen =  7;
		else
		{
			gQsCom.RxdLen =  7;
		}
	}
	//--------------------------------------------------------------//
	if(gQsCom.RxdIndex== gQsCom.RxdLen-1&& gQsCom.RxdIndex >3)
	{

		gQsCom.RxdFlag = TRUE;
		gQsCom.RxdIndex = 0;
	}else{
		gQsCom.RxdIndex++;
	}
	
}






void qs_com_tx(u8 len)
{
	if(gQsCom.TxdSts == 0)//发送数据
	{
		SCI_C_DE_CTL(USART_BUS_TXD);
		gQsCom.TxdSts = 1;
	}
	else if(gQsCom.TxdSts==1)//等待发送完成
	{
		USARTC_TC_CLR();           // 清发送完成状态
		USARTC_TXD(gQsCom.TxdBuf[0]);
		 
		gQsCom.TxdCnt = 0;
		gQsCom.TxdLen = len;	
		gQsCom.TxdSts = 2;
	}
	else
	{
	
	}



}


void qs_com_task(void)
{
	u16 temp = 0;
	u8 sum_checkk = 0,Fmsum_checkk = 0;
	u8* data = NULL;
	

	if(gQsCom.ConnectFlag)
	{
		//USARTC_COM_REST = 0;
		//gQsCom.TxdFlag = 0;
		//gQsCom.RxdFlag = 0;
		//gQsCom.RxdIndex = 0;
		//gQsCom.RxdLen = 0;
		//USARTC_COM_REST = 1;
		//gQsCom.ConnectFlag = 0;
		//gQsCom.ConnectTicker = 0;


	}


	
	if(gQsCom.TxdFlag)
	{	
		#if 0
		if(gQsCom.TxdDly == 0)
		{
			u8 sts = _send_intervl(gQsCom.TxdBuf);
			if(sts == 1)
			{
				gQsCom.tx_ok ++;
				//状态恢复
				memset(gQsCom.TxdBuf,0,QS_COM_FRAM_LEN);
				gQsCom.TxdFlag = 0;
				gQsCom.TxdSts = 0;
				memset(gQsCom.RecBuf,0,QS_COM_FRAM_LEN);
				gQsCom.RxdFlag = 0;
				gQsCom.RxdIndex = 0;
			}
			else if(sts == 2)
			{
				//USARTC_COM_REST = 0;
				gQsCom.TxdFlag = 0;
				gQsCom.RxdFlag = 0;
				gQsCom.RxdIndex = 0;
				//USARTC_COM_REST = 1;

			}
		}
		else
		{

		}
		#else
		if(gQsCom.TxdDly)
		{
			SCI_C_DE_CTL(USART_BUS_TXD);			
		}
		else
		{
			qs_com_tx(gQsCom.TxdLen);
		}
		
		#endif
		return;

	}




	if(gQsCom.ParSave && gQsCom.ParSaveDlyCnt == 0)
	{
		gQsCom.ParSave = 0;
		//SysParP0.SAVE = 1;
		//gComMaster.ParUpdate = 0x1;
	}
		
	
	if(gQsCom.RxdFlag == FALSE){
		// 等待接收完成
		return;
	}
	gQsCom.rx_ok ++;



	//判断校验码是否正确

	temp = check_crc16(gQsCom.RecBuf,gQsCom.RxdLen-2);
	sum_checkk = (temp>>8)&0xff;
	 Fmsum_checkk = temp&0xff;
	if((gQsCom.RecBuf[gQsCom.RxdLen-2] != sum_checkk)||(gQsCom.RecBuf[gQsCom.RxdLen-1] != Fmsum_checkk))
	{
		
		goto LoopErrEnd;
	}

	gQsCom.chk_ok ++;

	data = gQsCom.RecBuf;



	
	gQsCom.ConnectFlag= FALSE;
	gQsCom.ConnectTicker = 0;		

	_parse_data();
	
	if(gQsCom.TxdFlag)
		return ;

LoopErrEnd:	
	memset(gQsCom.RecBuf,0,QS_COM_FRAM_LEN);
	gQsCom.RxdFlag = 0;
	gQsCom.RxdIndex = 0;
}
