#include "sys_include.h"

CanBusCtl_t gCanBusCtl1;
CanBusCtl_t gCanBusCtl2;





void can1_parse_msg(CanRxMsg* pMsg)
{
	CanMsg_t TxMsg = {0,};
	u32 MASK = 0;
	u8 ID = 0;
	u8 CMD = 0;
	u16 IDX = 0;
	u8 node_x = 0;
	u8 i = 0;

	IDX = pMsg->ExtId&0xFFFF;
	CMD = (pMsg->ExtId>>16)&0x7F;
	ID =  (pMsg->ExtId>>23)&0x3F;
	

	//单节数据
	if(ID >= 1 && ID <= MAX_NODE_NUM)
	{
		node_x = ID-1;
		 //机身控制
		 if(CMD == CMD_FLASH)
		 {
		 	if(IDX == 0)
		 	{
		 		//参数请求
		 		if(pMsg->Data[0] && gDisCom.ParRequestFlag == 0)
		 			gCanBusCtl1.DataRequestMain[gCanBusCtl1.CurNode] = 1;
		 		if(pMsg->Data[1] && gQsCom.ParRequestFlag == 0)
		 			gCanBusCtl1.DataRequestQs[gCanBusCtl1.CurNode] = 1;
				gStatus.Node[node_x].Version = pMsg->Data[7];
			}
			else if(IDX == 1)
			{
				gStatus.Node[node_x].DdSts[0].Version = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].Version = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].Version = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].Version = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].Version = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].Version = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].Version = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].Version = pMsg->Data[7];
			}
			else if(IDX == 2)
			{
				gStatus.Node[node_x].DdSts[0].Sts = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].Sts = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].Sts = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].Sts = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].Sts = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].Sts = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].Sts = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].Sts = pMsg->Data[7];

			}
			else if(IDX == 3)
			{
				gStatus.Node[node_x].DdSts[0].Err = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].Err = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].Err = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].Err = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].Err = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].Err = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].Err = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].Err = pMsg->Data[7];
			}
			else if(IDX == 4)
			{
				gStatus.Node[node_x].DdSts[0].CurLen = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +(pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[1].CurLen = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +(pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 5)
			{
				gStatus.Node[node_x].DdSts[2].CurLen = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +(pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[3].CurLen = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +(pMsg->Data[6]<<8) + pMsg->Data[6];

			}
			else if(IDX == 6)
			{
				gStatus.Node[node_x].DdSts[4].CurLen = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +(pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[5].CurLen = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +(pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 7)
			{
				gStatus.Node[node_x].DdSts[6].CurLen = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +(pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[7].CurLen = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +(pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 8)
			{
				gStatus.Node[node_x].DdSts[0].Xspd = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].Xspd = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].Xspd = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].Xspd = (pMsg->Data[6]<<8) + pMsg->Data[6];

			}
			else if(IDX == 9)
			{
				gStatus.Node[node_x].DdSts[4].Xspd = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].Xspd = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].Xspd = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].Xspd = (pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 10)
			{
				gStatus.Node[node_x].DdSts[0].Tension = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].Tension = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].Tension = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].Tension = (pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 11)
			{
				gStatus.Node[node_x].DdSts[4].Tension = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].Tension = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].Tension = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].Tension = (pMsg->Data[6]<<8) + pMsg->Data[6];

			}
			else if(IDX == 12)
			{
				gStatus.Node[node_x].DdSts[0].LLSpd3 = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].LLSpd3 = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].LLSpd3 = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].LLSpd3 = (pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 13)
			{
				gStatus.Node[node_x].DdSts[4].LLSpd3 = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].LLSpd3 = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].LLSpd3 = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].LLSpd3 = (pMsg->Data[6]<<8) + pMsg->Data[6];

			}
			else if(IDX == 14)
			{
				gStatus.Node[node_x].DdSts[0].LLSpd3 = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].LLSpd3 = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].LLSpd3 = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].LLSpd3 = (pMsg->Data[6]<<8) + pMsg->Data[6];

			}
			else if(IDX == 15)
			{
				gStatus.Node[node_x].DdSts[4].LLSpd4 = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].LLSpd4 = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].LLSpd4 = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].LLSpd4 = (pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 16)
			{
				gStatus.Node[node_x].DdSts[0].SLSpd = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].SLSpd = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].SLSpd = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].SLSpd = (pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 17)
			{
				gStatus.Node[node_x].DdSts[4].SLSpd = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].SLSpd = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].SLSpd = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].SLSpd = (pMsg->Data[6]<<8) + pMsg->Data[6];

			}
			else if(IDX == 18)
			{
				gStatus.Node[node_x].DdSts[0].CSSpd = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].CSSpd = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].CSSpd = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].CSSpd = (pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 19)
			{
				gStatus.Node[node_x].DdSts[4].CSSpd = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].CSSpd = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].CSSpd = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].CSSpd = (pMsg->Data[6]<<8) + pMsg->Data[6];
			}
			else if(IDX == 20)
			{
				gStatus.Node[node_x].DdSts[0].InputByte1 = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].InputByte1 = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].InputByte1 = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].InputByte1 = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].InputByte1 = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].InputByte1 = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].InputByte1 = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].InputByte1 = pMsg->Data[7];

			}
			else if(IDX == 21)
			{
				gStatus.Node[node_x].DdSts[0].OutputByte1 = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].OutputByte1 = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].OutputByte1 = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].OutputByte1 = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].OutputByte1 = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].OutputByte1 = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].OutputByte1 = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].OutputByte1 = pMsg->Data[7];
			}
			else if(IDX == 22)
			{
				gStatus.Node[node_x].DdSts[0].OutputByte2 = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].OutputByte2 = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].OutputByte2 = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].OutputByte2 = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].OutputByte2 = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].OutputByte2 = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].OutputByte2 = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].OutputByte2 = pMsg->Data[7];
			}
			else if(IDX == 23)
			{
				gStatus.Node[node_x].DdSts[0].ComByte = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].ComByte = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].ComByte = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].ComByte = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].ComByte = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].ComByte = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].ComByte = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].ComByte = pMsg->Data[7];

			}
			else if(IDX == 24)
			{
				gStatus.Node[node_x].DdSts[0].Ads = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].Ads = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].Ads = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].Ads = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].Ads = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].Ads = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].Ads = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].Ads = pMsg->Data[7];
			}
			else if(IDX == 25)
			{
				gStatus.Node[node_x].DdSts[0].State = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].State = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].State = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].State = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].State = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].State = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].State = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].State = pMsg->Data[7];
			}
			else if(IDX == 26)
			{
				gStatus.Node[node_x].DdSts[0].InputByte2 = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].InputByte2 = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].InputByte2 = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].InputByte2 = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].InputByte2 = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].InputByte2 = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].InputByte2 = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].InputByte2 = pMsg->Data[7];
			}
			else if(IDX == 27)
			{
				gStatus.Node[node_x].DdSts[0].StateByte = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].StateByte = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].StateByte = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].StateByte = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].StateByte = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].StateByte = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].StateByte = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].StateByte = pMsg->Data[7];

			}
			else if(IDX == 28)
			{
				gStatus.Node[node_x].DdSts[0].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[0].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[0].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[0].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[0].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[0].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[0].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[0].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 29)
			{
				gStatus.Node[node_x].DdSts[0].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[0].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[0].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[0].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[0].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[0].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[0].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[0].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 30)
			{
				gStatus.Node[node_x].DdSts[1].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[1].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[1].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[1].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[1].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[1].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 31)
			{
				gStatus.Node[node_x].DdSts[1].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[1].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[1].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[1].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[1].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[1].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[1].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[1].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 32)
			{
				gStatus.Node[node_x].DdSts[2].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[2].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[2].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[2].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[2].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[2].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 33)
			{
				gStatus.Node[node_x].DdSts[2].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[2].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[2].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[2].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[2].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[2].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[2].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[2].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 34)
			{
				gStatus.Node[node_x].DdSts[3].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[3].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[3].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[3].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[3].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[3].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 35)
			{
				gStatus.Node[node_x].DdSts[3].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[3].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[3].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[3].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[3].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[3].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[3].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[3].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 36)
			{
				gStatus.Node[node_x].DdSts[4].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[4].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[4].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[4].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[4].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[4].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[4].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 37)
			{
				gStatus.Node[node_x].DdSts[4].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[4].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[4].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[4].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[4].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[4].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[4].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[4].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 38)
			{
				gStatus.Node[node_x].DdSts[5].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[5].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[5].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[5].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[5].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[5].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 39)
			{
				gStatus.Node[node_x].DdSts[5].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[5].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[5].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[5].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[5].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[5].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[5].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[5].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 40)
			{
				gStatus.Node[node_x].DdSts[6].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[6].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[6].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[6].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[6].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[6].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 41)
			{
				gStatus.Node[node_x].DdSts[6].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[6].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[6].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[6].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[6].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[6].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[6].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[6].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 42)
			{
				gStatus.Node[node_x].DdSts[7].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[7].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[7].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[7].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[7].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[7].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].DebugData[7] = pMsg->Data[7];			
			}
			else if(IDX == 43)
			{
				gStatus.Node[node_x].DdSts[7].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].DdSts[7].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].DdSts[7].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].DdSts[7].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].DdSts[7].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].DdSts[7].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].DdSts[7].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].DdSts[7].DebugData[15] = pMsg->Data[7];	
			}
			else if(IDX == 101)
			{
				gStatus.Node[node_x].QsSts[0].Sts = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].Sts = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].Sts = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].Sts = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].Sts = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].Sts = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].Sts = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].Sts = pMsg->Data[7];
			}
			else if(IDX == 102)
			{
				gStatus.Node[node_x].QsSts[0].CV = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +  (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[1].CV = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +  (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 103)
			{
				gStatus.Node[node_x].QsSts[2].CV = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +  (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[3].CV = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +  (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 104)
			{
				gStatus.Node[node_x].QsSts[4].CV = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +  (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[5].CV = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +  (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 105)
			{
				gStatus.Node[node_x].QsSts[6].CV = (pMsg->Data[0]<<24) + (pMsg->Data[1]<<16) +  (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[7].CV = (pMsg->Data[4]<<24) + (pMsg->Data[5]<<16) +  (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 106)
			{
				gStatus.Node[node_x].QsSts[0].CVs = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].CVs = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].CVs = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].CVs = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].CVs = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].CVs = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].CVs = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].CVs = pMsg->Data[7];
			}
			else if(IDX == 107)
			{
				gStatus.Node[node_x].QsSts[0].Noise = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].Noise = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].Noise = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].Noise = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].Noise = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].Noise = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].Noise = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].Noise = pMsg->Data[7];
			}
			else if(IDX == 108)
			{
				gStatus.Node[node_x].QsSts[0].Sensitivity = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].Sensitivity = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].Sensitivity = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].Sensitivity = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].Sensitivity = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].Sensitivity = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].Sensitivity = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].Sensitivity = pMsg->Data[7];
			}
			else if(IDX == 109)
			{
				gStatus.Node[node_x].QsSts[0].Version = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].Version = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].Version = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].Version = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].Version = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].Version = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].Version = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].Version = pMsg->Data[7];
			}
			else if(IDX == 110)
			{
				gStatus.Node[node_x].QsSts[0].Zero = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].QsSts[1].Zero = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[2].Zero = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].QsSts[3].Zero = (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 111)
			{
				gStatus.Node[node_x].QsSts[4].Zero = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].QsSts[5].Zero = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[6].Zero = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].QsSts[7].Zero = (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 112)
			{
				gStatus.Node[node_x].QsSts[0].Driver = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].Driver = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].Driver = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].Driver = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].Driver = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].Driver = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].Driver = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].Driver = pMsg->Data[7];
			}
			else if(IDX == 113)
			{
				gStatus.Node[node_x].QsSts[0].Dust = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].Dust = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].Dust = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].Dust = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].Dust = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].Dust = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].Dust = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].Dust = pMsg->Data[7];
			}
			else if(IDX == 114)
			{
				gStatus.Node[node_x].QsSts[0].Avg = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].QsSts[1].Avg = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[2].Avg = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].QsSts[3].Avg = (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 115)
			{
				gStatus.Node[node_x].QsSts[4].Avg = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].QsSts[5].Avg = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[6].Avg = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].QsSts[7].Avg = (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 116)
			{
				gStatus.Node[node_x].QsSts[0].Avg_Ref = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].QsSts[1].Avg_Ref = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[2].Avg_Ref = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].QsSts[3].Avg_Ref = (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 117)
			{
				gStatus.Node[node_x].QsSts[4].Avg_Ref = (pMsg->Data[0]<<8) + pMsg->Data[1];
				gStatus.Node[node_x].QsSts[5].Avg_Ref = (pMsg->Data[2]<<8) + pMsg->Data[3];
				gStatus.Node[node_x].QsSts[6].Avg_Ref = (pMsg->Data[4]<<8) + pMsg->Data[5];
				gStatus.Node[node_x].QsSts[7].Avg_Ref = (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 118)
			{
				gStatus.Node[node_x].QsSts[0].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[0].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[0].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[0].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[0].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[0].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[0].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[0].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 119)
			{
				gStatus.Node[node_x].QsSts[0].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[0].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[0].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[0].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[0].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[0].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[0].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[0].DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 120)
			{
				gStatus.Node[node_x].QsSts[1].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[1].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[1].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[1].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[1].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[1].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[1].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 121)
			{
				gStatus.Node[node_x].QsSts[1].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[1].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[1].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[1].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[1].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[1].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[1].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[1].DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 122)
			{
				gStatus.Node[node_x].QsSts[2].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[2].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[2].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[2].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[2].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[2].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[2].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 123)
			{
				gStatus.Node[node_x].QsSts[2].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[2].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[2].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[2].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[2].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[2].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[2].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[2].DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 124)
			{
				gStatus.Node[node_x].QsSts[3].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[3].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[3].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[3].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[3].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[3].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[3].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 125)
			{
				gStatus.Node[node_x].QsSts[3].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[3].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[3].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[3].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[3].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[3].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[3].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[3].DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 126)
			{
				gStatus.Node[node_x].QsSts[4].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[4].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[4].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[4].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[4].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[4].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[4].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 127)
			{
				gStatus.Node[node_x].QsSts[4].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[4].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[4].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[4].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[4].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[4].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[4].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[4].DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 128)
			{
				gStatus.Node[node_x].QsSts[5].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[5].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[5].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[5].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[5].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[5].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[5].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 129)
			{
				gStatus.Node[node_x].QsSts[5].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[5].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[5].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[5].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[5].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[5].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[5].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[5].DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 130)
			{
				gStatus.Node[node_x].QsSts[6].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[6].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[6].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[6].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[6].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[6].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[6].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 131)
			{
				gStatus.Node[node_x].QsSts[6].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[6].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[6].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[6].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[6].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[6].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[6].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[6].DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 132)
			{
				gStatus.Node[node_x].QsSts[7].DebugData[0] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[7].DebugData[1] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[7].DebugData[2] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[7].DebugData[3] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[7].DebugData[4] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[7].DebugData[5] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[7].DebugData[6] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 133)
			{
				gStatus.Node[node_x].QsSts[7].DebugData[8] = pMsg->Data[0];
				gStatus.Node[node_x].QsSts[7].DebugData[9] = pMsg->Data[1];
				gStatus.Node[node_x].QsSts[7].DebugData[10] = pMsg->Data[2];
				gStatus.Node[node_x].QsSts[7].DebugData[11] = pMsg->Data[3];
				gStatus.Node[node_x].QsSts[7].DebugData[12] = pMsg->Data[4];
				gStatus.Node[node_x].QsSts[7].DebugData[13] = pMsg->Data[5];
				gStatus.Node[node_x].QsSts[7].DebugData[14] = pMsg->Data[6];
				gStatus.Node[node_x].QsSts[7].DebugData[15] = pMsg->Data[7];
			}			//结束帧
			else if(IDX == 0xFFFF)
			{
				gCanBusCtl1.RxFlag  = 2;

			}
		}
		 else if(CMD == CMD_SET1)
		 {
			if(gCanBusCtl1.State == STS_WAIT_OVER_TIME)
			{
				MASK = (pMsg->Data[2] << 16) + (pMsg->Data[1] << 8) + pMsg->Data[0];
				if(MASK != MASK_DJ)
					gCanBusCtl1.RxFlag  = 1;
				else
					gCanBusCtl1.RxFlag  = 2;
					
			}
		 }
		 else if(CMD == CMD_SET2)
		 {
			if(gCanBusCtl1.State == STS_WAIT_OVER_TIME)
			{
				MASK  = pMsg->Data[0];
				if(MASK != MASK_QS)
					gCanBusCtl1.RxFlag  = 1;
				else
					gCanBusCtl1.RxFlag  = 2;
					
			}

		 }
		 else if(CMD == CMD_AD_REQUEST)
		 {
		 	//有效请求
		 	if(pMsg->Data[1]>=1 && pMsg->Data[1]<= MAX_NODE_NUM*8)
		 	{
			 	gSysCtlVal.AD_Ctl.FlagNew = 1;
			 	gSysCtlVal.AD_Ctl.RequestNew.cmd = pMsg->Data[0]?1:0;
			 	gSysCtlVal.AD_Ctl.RequestNew.ads = pMsg->Data[1];
			 	gSysCtlVal.AD_Ctl.RequestNew.len_cur =(pMsg->Data[4]<<24)  +  (pMsg->Data[5]<<24)  +  (pMsg->Data[6]<<24)  + pMsg->Data[7];

				//--------------------------------------------------------------------
				//单锭请求或者取消
				if(gSysCtlVal.AD_Ctl.FlagNew)
				{
					gSysCtlVal.AD_Ctl.FlagNew = 0;
				
				 	if(gSysCtlVal.AD_Ctl.RequestNew.cmd)//请求
				 	{
				 		//添加到请求链表
					 	request_list_add_request(&request_list_ad, gSysCtlVal.AD_Ctl.RequestNew);
				 	}
				 	else //取消请求
				 	{
				 		//当前无换管
				 		if(gSysCtlVal.AD_Ctl.pRequestExec == NULL)
				 		{
				 			//直接取消, 从链表中删除
					 		request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.RequestNew.ads);
							gSysCtlVal.AD_Ctl.CancelCnt++;
					 	}
					 	else
					 	{
					 		//  当前在执行的锭位，需先让小车取消,再从链表删除
							if(gSysCtlVal.AD_Ctl.pRequestExec->ads == gSysCtlVal.AD_Ctl.RequestNew.ads)
							{
								//发送命令取消执行
								gSysCtlVal.AD_Ctl.FlagCancel = 1;
							}
					 		//  非当前在执行的锭位, 从链表中删除
							else
							{
					 			request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.RequestNew.ads);
								gSysCtlVal.AD_Ctl.CancelCnt++;
							}
					 	}
				 	}

				}



		 	}
			//ack 1
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = pMsg->ExtId;
			TxMsg.Data[0] = pMsg->Data[0];
			TxMsg.Data[1] = pMsg->Data[1];
			TxMsg.DLC  = 2;
			can1_buffer_add_msg(&TxMsg);
		 }
		 else if(CMD == CMD_JN_REQUEST)
		 {
		 	//有效请求
		 	if(pMsg->Data[1]>=1 && pMsg->Data[1]<= MAX_NODE_NUM*8)
		 	{
			 	gSysCtlVal.JN_Ctl.FlagNew = 1;
			 	gSysCtlVal.JN_Ctl.RequestNew.cmd = pMsg->Data[0]?1:0;
			 	gSysCtlVal.JN_Ctl.RequestNew.ads = pMsg->Data[1];
			 	gSysCtlVal.JN_Ctl.RequestNew.len_cur =(pMsg->Data[4]<<24)  +  (pMsg->Data[5]<<24)  +  (pMsg->Data[6]<<24)  + pMsg->Data[7];

				//--------------------------------------------------------------------
				//单锭请求或者取消
				if(gSysCtlVal.JN_Ctl.FlagNew)
				{
					gSysCtlVal.JN_Ctl.FlagNew = 0;
				
				 	if(gSysCtlVal.JN_Ctl.RequestNew.cmd)//请求
				 	{
				 		//添加到请求链表
					 	request_list_add_request(&request_list_jn, gSysCtlVal.JN_Ctl.RequestNew);
				 	}
				 	else //取消请求
				 	{
				 		//当前无换管
				 		if(gSysCtlVal.JN_Ctl.pRequestExec[0] == NULL && gSysCtlVal.JN_Ctl.pRequestExec[1] == NULL&& gSysCtlVal.JN_Ctl.pRequestExec[2] == NULL&& gSysCtlVal.JN_Ctl.pRequestExec[3] == NULL)
				 		{
				 			//直接取消, 从链表中删除
					 		request_list_del_request(&request_list_jn, gSysCtlVal.JN_Ctl.RequestNew.ads);
							//gSysCtlVal.JN_Ctl.CancelCnt++;
					 	}
					 	else
					 	{
					 		//  当前在执行的锭位，需先让小车取消,再从链表删除
							if(gSysCtlVal.JN_Ctl.pRequestExec[0]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
							{
								//发送命令取消执行
								gSysCtlVal.JN_Ctl.FlagCancel[0] = 1;
							}
							if(gSysCtlVal.JN_Ctl.pRequestExec[1]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
							{
								//发送命令取消执行
								gSysCtlVal.JN_Ctl.FlagCancel[1] = 1;
							}					 		
							if(gSysCtlVal.JN_Ctl.pRequestExec[2]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
							{
								//发送命令取消执行
								gSysCtlVal.JN_Ctl.FlagCancel[2] = 1;
							}					 		
							if(gSysCtlVal.JN_Ctl.pRequestExec[3]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
							{
								//发送命令取消执行
								gSysCtlVal.JN_Ctl.FlagCancel[3] = 1;
							}					 		
							//  非当前在执行的锭位, 从链表中删除
							else
							{
					 			request_list_del_request(&request_list_jn, gSysCtlVal.JN_Ctl.RequestNew.ads);
								//gSysCtlVal.JN_Ctl.CancelCnt++;
							}
					 	}
				 	}

				}



		 	}		 	
			//ack 1
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = pMsg->ExtId;
			TxMsg.Data[0] = pMsg->Data[0];
			TxMsg.Data[1] = pMsg->Data[1];
			TxMsg.DLC  = 2;
			can1_buffer_add_msg(&TxMsg);
		 }	
		 else if(CMD == CMD_TRANS)
		 {
		 	if(pMsg->Data[0] == 0x3C)// AD 小车
		 	{
				TxMsg.IDE = CAN_Id_Extended;
				TxMsg.RTR = 0;
				TxMsg.StdId = 0;
				TxMsg.ExtId = (0x31<<23)+(CMD_TRANS<<16)+0;
				for(i=0;i<pMsg->DLC;i++)
					TxMsg.Data[i] = pMsg->Data[i]; 
				TxMsg.DLC  = pMsg->DLC;
				can2_buffer_add_msg(&TxMsg);
		 	}
		 	else if(pMsg->Data[0] == 0x4A)// JN 小车1
		 	{
				TxMsg.IDE = CAN_Id_Extended;
				TxMsg.RTR = 0;
				TxMsg.StdId = 0;
				TxMsg.ExtId = (0x21<<23)+(CMD_TRANS<<16)+0;
				for(i=0;i<pMsg->DLC;i++)
					TxMsg.Data[i] = pMsg->Data[i]; 
				TxMsg.DLC  = pMsg->DLC;
				can2_buffer_add_msg(&TxMsg);

		 	}
		 	else if(pMsg->Data[0] == 0x4B)// JN 小车2
		 	{
				TxMsg.IDE = CAN_Id_Extended;
				TxMsg.RTR = 0;
				TxMsg.StdId = 0;
				TxMsg.ExtId = (0x22<<23)+(CMD_TRANS<<16)+0;
				for(i=0;i<pMsg->DLC;i++)
					TxMsg.Data[i] = pMsg->Data[i]; 
				TxMsg.DLC  = pMsg->DLC;
				can2_buffer_add_msg(&TxMsg);

		 	}
		 	else if(pMsg->Data[0] == 0x4C)// JN 小车3
		 	{
				TxMsg.IDE = CAN_Id_Extended;
				TxMsg.RTR = 0;
				TxMsg.StdId = 0;
				TxMsg.ExtId = (0x23<<23)+(CMD_TRANS<<16)+0;
				for(i=0;i<pMsg->DLC;i++)
					TxMsg.Data[i] = pMsg->Data[i]; 
				TxMsg.DLC  = pMsg->DLC;
				can2_buffer_add_msg(&TxMsg);

		 	}
		 	else if(pMsg->Data[0] == 0x4D)// JN 小车4
		 	{
				TxMsg.IDE = CAN_Id_Extended;
				TxMsg.RTR = 0;
				TxMsg.StdId = 0;
				TxMsg.ExtId = (0x24<<23)+(CMD_TRANS<<16)+0;
				for(i=0;i<pMsg->DLC;i++)
					TxMsg.Data[i] = pMsg->Data[i]; 
				TxMsg.DLC  = pMsg->DLC;
				can2_buffer_add_msg(&TxMsg);

		 	}

		 }	
	}
	//机尾数据
	else if(ID ==0x11 || ID == 0x12)
	{
		node_x = ID-0x11;
		 if(CMD == CMD_FLASH)
		 {
		 	if(IDX == 0)
		 	{
		 		//参数请求
		 		if(pMsg->Data[0] && gDisCom.ParRequestFlag == 0)
					gCanBusCtl1.DataRequestSub[gCanBusCtl1.CurNode] = 1;
				gStatus.JW[node_x].Sts = pMsg->Data[1];
				gStatus.JW[node_x].Err = pMsg->Data[2];
				gStatus.JW[node_x].Version = pMsg->Data[7];
			}
			else if(IDX == 1)
			{
				gStatus.JW[node_x].Ang1 = (pMsg->Data[1]<<8) + pMsg->Data[0];
				gStatus.JW[node_x].Ang2 = (pMsg->Data[3]<<8) + pMsg->Data[2];
				gStatus.JW[node_x].Input = (pMsg->Data[5]<<8) + pMsg->Data[4];
				gStatus.JW[node_x].Output = (pMsg->Data[7]<<8) + pMsg->Data[6];

			}
			//结束帧
			else if(IDX == 0xFFFF)
			{
				gCanBusCtl1.RxFlag  = 2;

			}

		 }
		 else if(CMD == CMD_SET1)
		 {
			if(gCanBusCtl1.State == STS_WAIT_OVER_TIME)
			{
				MASK = pMsg->Data[0];
				if(MASK != MASK_JW)
					gCanBusCtl1.RxFlag  = 1;
				else
					gCanBusCtl1.RxFlag  = 2;
					
			}

		 }
		 else if(CMD == CMD_AD_GET_PIPE)
		 {
		 	// Ack  转发到AD
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (0x31<<23)+(CMD_AD_GET_PIPE<<16)+0;
			TxMsg.Data[0] = pMsg->Data[0];
			TxMsg.Data[1] = pMsg->Data[1];
			TxMsg.DLC  = 2;
			can2_buffer_add_msg(&TxMsg);
		 }	

	}


	#if 0
	Tx.ExtId = pMsg->ExtId+1;
	Tx.IDE = pMsg->IDE;
	Tx.RTR = pMsg->RTR;
	Tx.DLC = pMsg->DLC;
	Tx.Data[0] = pMsg->Data[0];
	Tx.Data[1] = pMsg->Data[1];
	Tx.Data[2] = pMsg->Data[2];
	Tx.Data[3] = pMsg->Data[3];
	Tx.Data[4] = pMsg->Data[4];
	Tx.Data[5] = pMsg->Data[5];
	Tx.Data[6] = pMsg->Data[6];
	Tx.Data[7] = pMsg->Data[7];
	can1_send_msg(&Tx);
	#endif
}


void can1_task(void)
{
	u32 ID = 0;
	u32 CMD = 0;
	u32 IDX = 0;
	u8 tmp = 0;
	u8 tmp1= 0;
	CanMsg_t* pBuf = NULL;

	//初始化
	if(gCanBusCtl1.State == STS_INIT)
	{
		gCanBusCtl1.State = 0;
		gCanBusCtl1.CurNode = 0;
		gCanBusCtl1.CurIndex = 0;
		gCanBusCtl1.CurSetType = 0;
		gCanBusCtl1.NodeType = 0;
		gCanBusCtl1.ReSendCnt = MAX_RESEND_NUM;

		gCanBusCtl1.State = STS_LOAD;
	}
	//连续数据发送等待
	else	if(gCanBusCtl1.State == STS_WAIT_SEND)
	{
		if(gCanBusCtl1.WaitCnt)gCanBusCtl1.WaitCnt--;
		else 
		{
			gCanBusCtl1.CurIndex++;
			gCanBusCtl1.State = STS_LOAD;
		}
	}
	//超时等待
	else if(gCanBusCtl1.State == STS_WAIT_OVER_TIME)
	{
		if(gCanBusCtl1.WaitCnt)gCanBusCtl1.WaitCnt--;
		if(gCanBusCtl1.WaitCnt == 0)
		{
			gCanBusCtl1.State = STS_OVER_TIME;
		}

		//部分收到，超时重发处理
		if(gCanBusCtl1.RxFlag == 1)
		{
			gCanBusCtl1.State = STS_OVER_TIME;
		}
		//全部收到
		else if(gCanBusCtl1.RxFlag == 2)
		{
			gCanBusCtl1.State = STS_PARSE;

		}

	}
	//加载发送数据
	else if(gCanBusCtl1.State == STS_LOAD)
	{	
		//主节点 - 车身单节数据
		if(gCanBusCtl1.NodeType == 0)
		{

			//单节控制数据请求或者有更新
			if(gCanBusCtl1.DataRequestMain[gCanBusCtl1.CurNode] && gCanBusCtl1.CurSetType == 0)
			{
				gCanBusCtl1.CurCmd = CMD_SET1;  //单节控制参数
				gCanBusCtl1.MaxIndex = MAX_IDX_DJ;
				gCanBusCtl1.RxFlag  = 0;
				if(gCanBusCtl1.CurIndex == gCanBusCtl1.MaxIndex)// 最后一帧  IDX = 0xFFFF
				{
					IDX = 0xFFFF;
					gCanBusCtl1.FinalFrame = 1;
				}
				else 
				{
					IDX = gCanBusCtl1.CurIndex;
					gCanBusCtl1.FinalFrame = 0;
				}
				ID = gCanBusCtl1.CurID = gCanBusCtl1.CurNode+1;
				CMD  = gCanBusCtl1.CurCmd;

				gCanBusCtl1.TxMsg.ExtId = (gCanBusCtl1.CurID<<23)+(CMD<<16)+IDX;
				fill_data_set(DAT_DJ, IDX);
	
				
			}
			//单节清纱数据请求或者有更新
 			else if(gCanBusCtl1.DataRequestQs[gCanBusCtl1.CurNode])// && gCanBusCtl1.CurSetType == 1)
			{
				gCanBusCtl1.CurCmd = CMD_SET2;  //清纱参数
				gCanBusCtl1.MaxIndex = MAX_IDX_QS;
				gCanBusCtl1.RxFlag  = 0;
				if(gCanBusCtl1.CurIndex == gCanBusCtl1.MaxIndex)// 最后一帧  IDX = 0xFFFF
				{
					IDX = 0xFFFF;
					gCanBusCtl1.FinalFrame = 1;
				}
				else 
				{
					IDX = gCanBusCtl1.CurIndex;
					gCanBusCtl1.FinalFrame = 0;
				}
				ID = gCanBusCtl1.CurID = gCanBusCtl1.CurNode+1;
				CMD  = gCanBusCtl1.CurCmd;

				gCanBusCtl1.TxMsg.ExtId = (gCanBusCtl1.CurID<<23)+(CMD<<16)+IDX;
				fill_data_set(DAT_QS, IDX);
	
				
			}	
			// 轮询
			else
			{
					gCanBusCtl1.CurCmd = CMD_FLASH;  //轮询单节数据
					gCanBusCtl1.MaxIndex = 1;
					gCanBusCtl1.FinalFrame = 1;
					gCanBusCtl1.RxFlag  = 0;
					IDX = gCanBusCtl1.CurIndex;
					ID = gCanBusCtl1.CurID = gCanBusCtl1.CurNode+1;
					CMD  = gCanBusCtl1.CurCmd;

					gCanBusCtl1.TxMsg.ExtId = (gCanBusCtl1.CurID<<23)+(CMD<<16)+IDX;
					fill_data_flash(DAT_DJ, 0, 43, 101, 130);
				
			}



		}
		//副节点- 车尾
		else
		{
			//机尾数据请求或者有更新
			if(gCanBusCtl1.DataRequestSub[gCanBusCtl1.CurNode])
			{
				gCanBusCtl1.CurCmd = CMD_SET1;  //发送机尾数据
				gCanBusCtl1.MaxIndex = MAX_IDX_JW;
				gCanBusCtl1.RxFlag  = 0;
				if(gCanBusCtl1.CurIndex == gCanBusCtl1.MaxIndex)
				{
					IDX = 0xFFFF;
					gCanBusCtl1.FinalFrame = 1;
				}
				else 
				{
					IDX = gCanBusCtl1.CurIndex;
					gCanBusCtl1.FinalFrame = 0;
				}
				ID = gCanBusCtl1.CurID = gCanBusCtl1.CurNode+0x11;
				CMD  = gCanBusCtl1.CurCmd;

				gCanBusCtl1.TxMsg.ExtId = (gCanBusCtl1.CurID<<23)+(CMD<<16)+IDX;
				fill_data_set(DAT_JW, IDX);
			}
			// 轮询
			else
			{
				gCanBusCtl1.CurCmd = CMD_FLASH;  //轮询
				gCanBusCtl1.MaxIndex = 1;
				gCanBusCtl1.FinalFrame = 1;
				gCanBusCtl1.RxFlag  = 0;
				IDX = gCanBusCtl1.CurIndex;
				ID = gCanBusCtl1.CurID = gCanBusCtl1.CurNode+0x11;
				CMD  = gCanBusCtl1.CurCmd;

				gCanBusCtl1.TxMsg.ExtId = (gCanBusCtl1.CurID<<23)+(CMD<<16)+IDX;
				fill_data_flash(DAT_JW, 0, 1, 0, 0);

			}

		}

		gCanBusCtl1.State = STS_SEND;

	}
	//发送数据
	else if(gCanBusCtl1.State == STS_SEND)
	{
		can1_buffer_add_msg(&gCanBusCtl1.TxMsg);


		if(gCanBusCtl1.FinalFrame) //最后一帧
		{
			gCanBusCtl1.WaitCnt = 400;// 200ms
			gCanBusCtl1.State = STS_WAIT_OVER_TIME;
		}
		else
		{
			//gCanBusCtl1.WaitCnt = 1;// 500us
			//gCanBusCtl1.State = STS_WAIT_SEND;
			gCanBusCtl1.CurIndex++;
			gCanBusCtl1.State = STS_LOAD;
		}
	}
	//超时处理
	else if(gCanBusCtl1.State == STS_OVER_TIME)
	{

		//重发
		if(gCanBusCtl1.ReSendCnt> 1)
		{
			gCanBusCtl1.ReSendCnt--;
			if(gCanBusCtl1.FinalFrame == 1)
			{
				gCanBusCtl1.CurIndex = 0;
			}
			gCanBusCtl1.State = STS_LOAD;
		}
		//重发超次数
		else
		{
			//主节点
			if(gCanBusCtl1.NodeType == 0)
			{
				if(gCanBusCtl1.ComErrMain[gCanBusCtl1.CurNode] < 3)
					gCanBusCtl1.ComErrMain[gCanBusCtl1.CurNode] ++;
				else
					gStatus.Node[gCanBusCtl1.CurNode].ComErr = 1;

					
				if(gCanBusCtl1.CurCmd == CMD_SET1 )
				{
					if(gCanBusCtl1.DataRequestQs[gCanBusCtl1.CurNode] == 0)
					{
						gCanBusCtl1.CurNode++;
						gCanBusCtl1.CurSetType = 0;
					}
					else
					{
						gCanBusCtl1.CurSetType = 1;
					}
						
				}
				else if(gCanBusCtl1.CurCmd == CMD_SET2)//下发参数命令
				{
						gCanBusCtl1.CurNode++;
						gCanBusCtl1.CurSetType = 0;
				}
				else if(gCanBusCtl1.CurCmd == CMD_FLASH)
				{
					gCanBusCtl1.CurNode++;
					gCanBusCtl1.CurSetType = 0;

				}
				
				//主节点完成  切换到副节点
				if(gCanBusCtl1.CurNode >= MAX_NODE_NUM)
				{
					gCanBusCtl1.CurNode = 0;
					gCanBusCtl1.NodeType = 1;
				}
				gCanBusCtl1.CurIndex = 0;
				gCanBusCtl1.ReSendCnt = MAX_RESEND_NUM;
			

				gCanBusCtl1.State = STS_LOAD;
			}
			//副节点
			else
			{
				if(gCanBusCtl1.ComErrSub[gCanBusCtl1.CurNode] < 3)
					gCanBusCtl1.ComErrSub[gCanBusCtl1.CurNode] ++;
				else
					gStatus.JW[gCanBusCtl1.CurNode].ComErr = 1;

				gCanBusCtl1.CurNode++;
				//副节点完成  切换到主节点
				if(gCanBusCtl1.CurNode >= MAX_JW_NUM)
				{
					gCanBusCtl1.CurNode = 0;
					gCanBusCtl1.NodeType = 0;
				}
				gCanBusCtl1.CurIndex = 0;
				gCanBusCtl1.ReSendCnt = MAX_RESEND_NUM;

				gCanBusCtl1.State = STS_LOAD;
			}
		}
	}
	// 收到回复
	else if(gCanBusCtl1.State == STS_PARSE)
	{
		if(gCanBusCtl1.FinalFrame == 1) //最后一帧
		{
			//主节点
			if(gCanBusCtl1.NodeType == 0)
			{
				gCanBusCtl1.ComErrMain[gCanBusCtl1.CurNode]=0;
				if(gCanBusCtl1.CurCmd == CMD_SET1 )
				{
					gCanBusCtl1.DataRequestMain[gCanBusCtl1.CurNode] = 0;
					if(gCanBusCtl1.DataRequestQs[gCanBusCtl1.CurNode] == 0 )
					{
						gCanBusCtl1.CurNode++;
						gCanBusCtl1.CurSetType = 0;
					}
					else
					{
						gCanBusCtl1.CurSetType = 1;
					}
						
				}
				else if(gCanBusCtl1.CurCmd == CMD_SET2)
				{
					gCanBusCtl1.DataRequestQs[gCanBusCtl1.CurNode] = 0;
					gCanBusCtl1.CurSetType = 0;
					gCanBusCtl1.CurNode++;
				}
				else if(gCanBusCtl1.CurCmd == CMD_FLASH)
				{
					gCanBusCtl1.CurNode++;
					gCanBusCtl1.CurSetType = 0;

				}
				//主节点完成  切换到副节点
				if(gCanBusCtl1.CurNode >= MAX_NODE_NUM)
				{
					gCanBusCtl1.CurNode = 0;
					gCanBusCtl1.NodeType = 1;
				}
				
				gCanBusCtl1.CurIndex = 0;
				gCanBusCtl1.ReSendCnt = MAX_RESEND_NUM;
				gCanBusCtl1.State = STS_LOAD;

			}
			//副节点
			else
			{
				gCanBusCtl1.ComErrSub[gCanBusCtl1.CurNode]=0;
				if(gCanBusCtl1.CurCmd == CMD_SET1)//下发参数命令
				{
					gCanBusCtl1.DataRequestSub[gCanBusCtl1.CurNode] = 0;
					gCanBusCtl1.CurNode++;
				}
				else
				{
					if(gCanBusCtl1.DataRequestSub[gCanBusCtl1.CurNode] == 0)
						gCanBusCtl1.CurNode++;
				}
				//副节点完成  切换到主节点
				if(gCanBusCtl1.CurNode >= 2)
				{
					gCanBusCtl1.CurNode = 0;
					gCanBusCtl1.NodeType = 0;
				}
				gCanBusCtl1.CurIndex = 0;
				gCanBusCtl1.ReSendCnt = MAX_RESEND_NUM;
				gCanBusCtl1.State = STS_LOAD;
			}
		}
		else
		{
			gCanBusCtl1.CurIndex++;
			gCanBusCtl1.State = STS_LOAD;

		}

	}


	//发送
	pBuf = can1_buffer_get_msg();
	if(pBuf)
	{
		can1_send_msg(pBuf);	
	}
	
	#if 0
	//--------------------------------------------------------------------
	//单锭请求或者取消
	if(gSysCtlVal.AD_Ctl.FlagNew)
	{
		gSysCtlVal.AD_Ctl.FlagNew = 0;
	
	 	if(gSysCtlVal.AD_Ctl.RequestNew.cmd)//请求
	 	{
	 		//添加到请求链表
		 	request_list_add_request(&request_list_ad, gSysCtlVal.AD_Ctl.RequestNew);
	 	}
	 	else //取消请求
	 	{
	 		//当前无换管
	 		if(gSysCtlVal.AD_Ctl.pRequestExec == NULL)
	 		{
	 			//直接取消, 从链表中删除
		 		request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.RequestNew.ads);
				gSysCtlVal.AD_Ctl.CancelCnt++;
		 	}
		 	else
		 	{
		 		//  当前在执行的锭位，需先让小车取消,再从链表删除
				if(gSysCtlVal.AD_Ctl.pRequestExec->ads == gSysCtlVal.AD_Ctl.RequestNew.ads)
				{
					//发送命令取消执行
					gSysCtlVal.AD_Ctl.FlagCancel = 1;
				}
		 		//  非当前在执行的锭位, 从链表中删除
				else
				{
		 			request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.RequestNew.ads);
					gSysCtlVal.AD_Ctl.CancelCnt++;
				}
		 	}
	 	}

	}


			//--------------------------------------------------------------------
		//单锭请求或者取消
		if(gSysCtlVal.JN_Ctl.FlagNew)
		{
			gSysCtlVal.JN_Ctl.FlagNew = 0;
		
		 	if(gSysCtlVal.JN_Ctl.RequestNew.cmd)//请求
		 	{
		 		//添加到请求链表
			 	request_list_add_request(&request_list_jn, gSysCtlVal.JN_Ctl.RequestNew);
		 	}
		 	else //取消请求
		 	{
		 		//当前无换管
		 		if(gSysCtlVal.JN_Ctl.pRequestExec[0] == NULL && gSysCtlVal.JN_Ctl.pRequestExec[1] == NULL&& gSysCtlVal.JN_Ctl.pRequestExec[2] == NULL&& gSysCtlVal.JN_Ctl.pRequestExec[3] == NULL)
		 		{
		 			//直接取消, 从链表中删除
			 		request_list_del_request(&request_list_jn, gSysCtlVal.JN_Ctl.RequestNew.ads);
					//gSysCtlVal.JN_Ctl.CancelCnt++;
			 	}
			 	else
			 	{
			 		//  当前在执行的锭位，需先让小车取消,再从链表删除
					if(gSysCtlVal.JN_Ctl.pRequestExec[0]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
					{
						//发送命令取消执行
						gSysCtlVal.JN_Ctl.FlagCancel[0] = 1;
					}
					if(gSysCtlVal.JN_Ctl.pRequestExec[1]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
					{
						//发送命令取消执行
						gSysCtlVal.JN_Ctl.FlagCancel[1] = 1;
					}					 		
					if(gSysCtlVal.JN_Ctl.pRequestExec[2]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
					{
						//发送命令取消执行
						gSysCtlVal.JN_Ctl.FlagCancel[2] = 1;
					}					 		
					if(gSysCtlVal.JN_Ctl.pRequestExec[3]->ads == gSysCtlVal.JN_Ctl.RequestNew.ads)
					{
						//发送命令取消执行
						gSysCtlVal.JN_Ctl.FlagCancel[3] = 1;
					}					 		
					//  非当前在执行的锭位, 从链表中删除
					else
					{
			 			request_list_del_request(&request_list_jn, gSysCtlVal.JN_Ctl.RequestNew.ads);
						//gSysCtlVal.JN_Ctl.CancelCnt++;
					}
			 	}
		 	}

		}



	#endif

}

void can2_parse_msg(CanRxMsg* pMsg)
{
	CanMsg_t TxMsg = {0,};
	u32 MASK = 0;
	u8 ID = 0;
	u8 CMD = 0;
	u16 IDX = 0;
	u8 node_x = 0;
	u8 i = 0;

	IDX = pMsg->ExtId&0xFFFF;
	CMD = (pMsg->ExtId>>16)&0x7F;
	ID =  (pMsg->ExtId>>23)&0x3F;
	

	//接捻小车数据
	if((ID >= 0x21) && ID <= (0x20+MAX_JN_NUM))
	{
		node_x = ID-0x21;
		 //轮询数据
		 if(CMD == CMD_FLASH)
		 {
		 	if(IDX == 0)
		 	{
		 		//参数请求
		 		if(pMsg->Data[0] == 1 && gDisCom.ParRequestFlag == 0)
		 			gCanBusCtl2.DataRequestMain[gCanBusCtl2.CurNode] = 1;
		 		if(pMsg->Data[0] == 2 && gQsCom.ParRequestFlag == 0)
		 			gCanBusCtl2.DataRequestQs[gCanBusCtl2.CurNode] = 1;
				gStatus.JN[node_x].Sts = pMsg->Data[1];
				gStatus.JN[node_x].Err = pMsg->Data[2];
				gStatus.JN[node_x].PosCur = pMsg->Data[3];
				gStatus.JN[node_x].Version = pMsg->Data[7];
			}
			else if(IDX == 101)
			{
				gStatus.JN[node_x].QsSts.Sts = pMsg->Data[0];
				gStatus.JN[node_x].QsSts.CV = pMsg->Data[1];
				gStatus.JN[node_x].QsSts.CVs = pMsg->Data[2];
				gStatus.JN[node_x].QsSts.Noise = pMsg->Data[3];
				gStatus.JN[node_x].QsSts.Sensitivity = pMsg->Data[4];
				gStatus.JN[node_x].QsSts.Version = pMsg->Data[5];
				gStatus.JN[node_x].QsSts.Zero = (pMsg->Data[6]<<8) + pMsg->Data[7];
			}
			else if(IDX == 102)
			{
				gStatus.JN[node_x].QsSts.Driver = pMsg->Data[0];
				gStatus.JN[node_x].QsSts.Dust = pMsg->Data[1];		
				gStatus.JN[node_x].QsSts.Avg = (pMsg->Data[2]<<8) + pMsg->Data[3];	
				gStatus.JN[node_x].QsSts.Avg_Ref = (pMsg->Data[4]<<8) + pMsg->Data[5];	
			}
			else if(IDX == 103)
			{
				gStatus.JN[node_x].QsSts.DebugData[0] = pMsg->Data[0];
				gStatus.JN[node_x].QsSts.DebugData[1] = pMsg->Data[1];
				gStatus.JN[node_x].QsSts.DebugData[2] = pMsg->Data[2];
				gStatus.JN[node_x].QsSts.DebugData[3] = pMsg->Data[3];
				gStatus.JN[node_x].QsSts.DebugData[4] = pMsg->Data[4];
				gStatus.JN[node_x].QsSts.DebugData[5] = pMsg->Data[5];
				gStatus.JN[node_x].QsSts.DebugData[6] = pMsg->Data[6];
				gStatus.JN[node_x].QsSts.DebugData[7] = pMsg->Data[7];
			}
			else if(IDX == 104)
			{
				gStatus.JN[node_x].QsSts.DebugData[8] = pMsg->Data[0];
				gStatus.JN[node_x].QsSts.DebugData[9] = pMsg->Data[1];
				gStatus.JN[node_x].QsSts.DebugData[10] = pMsg->Data[2];
				gStatus.JN[node_x].QsSts.DebugData[11] = pMsg->Data[3];
				gStatus.JN[node_x].QsSts.DebugData[12] = pMsg->Data[4];
				gStatus.JN[node_x].QsSts.DebugData[13] = pMsg->Data[5];
				gStatus.JN[node_x].QsSts.DebugData[14] = pMsg->Data[6];
				gStatus.JN[node_x].QsSts.DebugData[15] = pMsg->Data[7];
			}
			else if(IDX == 0xFFFF)
			{
				gCanBusCtl2.RxFlag  = 2;

			}
		}
		 else if(CMD == CMD_SET1)
		 {
			if(gCanBusCtl2.State == STS_WAIT_OVER_TIME)
			{
				MASK = (pMsg->Data[1]<<8) + pMsg->Data[0];
				if(MASK != MASK_JN)
					gCanBusCtl2.RxFlag  = 1;
				else
					gCanBusCtl2.RxFlag  = 2;
					
			}
		 }
		 else if(CMD == CMD_SET2)
		 {
			if(gCanBusCtl2.State == STS_WAIT_OVER_TIME)
			{
				MASK  = pMsg->Data[0];
				if(MASK != MASK_QS)
					gCanBusCtl2.RxFlag  = 1;
				else
					gCanBusCtl2.RxFlag  = 2;
					
			}

		 }
		 else if(CMD == CMD_JN_REQUEST)
		 {
			if(gSysCtlVal.JN_Ctl.TransSts[node_x] == 1)
			{
				gSysCtlVal.JN_Ctl.TransSts[node_x] = 3;
			}
			if(gSysCtlVal.JN_Ctl.TransSts[node_x] == 2)
			{
				gSysCtlVal.JN_Ctl.TransSts[node_x] = 4;
			}
		 }
		 else if(CMD == CMD_JN_DONE)
		 {
		 	//完成状态
			if(pMsg->Data[0] == 0)
			{
				//正常完成
				gSysCtlVal.JN_Ctl.FlagDone[node_x] = 1;
			}
			else
			{
				//出错
				gSysCtlVal.JN_Ctl.FlagDone[node_x] = 2;

			}
			
			gStatus.JN[node_x].PosCur = pMsg->Data[1];

		 	// Ack
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (ID<<23)+(CMD_AD_DONE<<16)+0;
			TxMsg.Data[0] = 1;
			TxMsg.DLC  = 1;
			can2_buffer_add_msg(&TxMsg);
		 }
		 else if(CMD == CMD_TRANS)
		 {
		 	node_x = (pMsg->Data[1]-1)/8 + 1;
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (node_x<<23)+(CMD_TRANS<<16)+0;
			for(i=0;i<pMsg->DLC;i++)
				TxMsg.Data[i] = pMsg->Data[i]; 
			TxMsg.DLC  = pMsg->DLC;
			can1_buffer_add_msg(&TxMsg);

		 	
		 }
	}
	//AD 小车数据
	else if(ID ==0x31)
	{
		node_x = ID-0x31;
		 if(CMD == CMD_FLASH)
		 {
		 	if(IDX == 0)
		 	{
		 		//参数请求
		 		if(pMsg->Data[0] && gDisCom.ParRequestFlag == 0)
					gCanBusCtl2.DataRequestSub[gCanBusCtl2.CurNode] = 1;
				gStatus.AD.Sts = pMsg->Data[1];
				gStatus.AD.Err = pMsg->Data[2];
				gStatus.AD.PosCur = pMsg->Data[3];
				gStatus.AD.EmptyNum = pMsg->Data[4];
				gStatus.AD.Version = pMsg->Data[7];
			}
			//结束帧
			else if(IDX == 0xFFFF)
			{
				gCanBusCtl2.RxFlag  = 2;

			}

		 }
		 else if(CMD == CMD_SET1)
		 {
			if(gCanBusCtl2.State == STS_WAIT_OVER_TIME)
			{
				MASK = pMsg->Data[0];
				if(MASK != MASK_AD)
					gCanBusCtl2.RxFlag  = 1;
				else
					gCanBusCtl2.RxFlag  = 2;
					
			}

		 }
		 else if(CMD == CMD_AD_REQUEST)
		 {
			if(gSysCtlVal.AD_Ctl.TransSts == 1)
			{
				gSysCtlVal.AD_Ctl.TransSts = 3;
			}
			if(gSysCtlVal.AD_Ctl.TransSts == 2)
			{
				gSysCtlVal.AD_Ctl.TransSts = 4;
			}
		 }
		 else if(CMD == CMD_AD_DONE)
		 {
		 	//完成状态
			if(pMsg->Data[0] == 0)
			{
				//正常完成
				gSysCtlVal.AD_Ctl.FlagDone = 1;
			}
			else
			{
				//出错
				gSysCtlVal.AD_Ctl.FlagDone = 2;

			}
			gStatus.AD.PosCur = pMsg->Data[1];
			gStatus.AD.EmptyNum = pMsg->Data[2];


		 	// Ack
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (0x31<<23)+(CMD_AD_DONE<<16)+0;
			TxMsg.Data[0] = 1;
			TxMsg.DLC  = 1;
			can2_buffer_add_msg(&TxMsg);
		 }
		 else if(CMD == CMD_AD_GET_PIPE)
		 {
		 	// Ack  转发到机尾2
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (0x12<<23)+(CMD_AD_GET_PIPE<<16)+0;
			TxMsg.Data[0] = pMsg->Data[0];
			TxMsg.Data[1] = pMsg->Data[1];
			TxMsg.Data[2] = pMsg->Data[2];
			TxMsg.DLC  = 3;
			can1_buffer_add_msg(&TxMsg);
		 }	
		 else if(CMD == CMD_TRANS)
		 {
		 	node_x = (pMsg->Data[1]-1)/8 + 1;
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (node_x<<23)+(CMD_TRANS<<16)+0;
			for(i=0;i<pMsg->DLC;i++)
				TxMsg.Data[i] = pMsg->Data[i]; 
			TxMsg.DLC  = pMsg->DLC;
			can1_buffer_add_msg(&TxMsg);

		 	
		 }
	}

	#if 0
	CanTxMsg Tx = {0,};
	Tx.ExtId = pMsg->ExtId+1;
	Tx.IDE = pMsg->IDE;
	Tx.RTR = pMsg->RTR;
	Tx.DLC = pMsg->DLC;
	Tx.Data[0] = pMsg->Data[0];
	Tx.Data[1] = pMsg->Data[1];
	Tx.Data[2] = pMsg->Data[2];
	Tx.Data[3] = pMsg->Data[3];
	Tx.Data[4] = pMsg->Data[4];
	Tx.Data[5] = pMsg->Data[5];
	Tx.Data[6] = pMsg->Data[6];
	Tx.Data[7] = pMsg->Data[7];
	can2_send_msg(&Tx);
	#endif

}

void can2_task(void)
{
	u32 ID = 0;
	u32 CMD = 0;
	u32 IDX = 0;
	CanMsg_t* pBuf = NULL;

	//初始化
	if(gCanBusCtl2.State == STS_INIT)
	{
		gCanBusCtl2.State = 0;
		gCanBusCtl2.CurNode = 0;
		gCanBusCtl2.CurIndex = 0;		
		gCanBusCtl2.CurSetType = 0;
		gCanBusCtl2.NodeType = 0;
		gCanBusCtl2.ReSendCnt = MAX_RESEND_NUM;

		gCanBusCtl2.State = STS_LOAD;
	}
	//连续数据发送等待
	else	if(gCanBusCtl2.State == STS_WAIT_SEND)
	{
		if(gCanBusCtl2.WaitCnt)gCanBusCtl2.WaitCnt--;
		else 
		{
			gCanBusCtl2.CurIndex++;
			gCanBusCtl2.State = STS_LOAD;
		}
	}
	//超时等待
	else if(gCanBusCtl2.State == STS_WAIT_OVER_TIME)
	{
		if(gCanBusCtl2.WaitCnt)gCanBusCtl2.WaitCnt--;
		if(gCanBusCtl2.WaitCnt == 0)
		{
			gCanBusCtl2.State = STS_OVER_TIME;
		}

		//部分收到，超时重发处理
		if(gCanBusCtl2.RxFlag == 1)
		{
			gCanBusCtl2.State = STS_OVER_TIME;
		}
		//全部收到
		else if(gCanBusCtl2.RxFlag == 2)
		{
			gCanBusCtl2.State = STS_PARSE;

		}

	}
	//加载发送数据
	else if(gCanBusCtl2.State == STS_LOAD)
	{	
		//主节点 - 接捻小车数据
		if(gCanBusCtl2.NodeType == 0)
		{
			//接捻小车数据请求或者有更新
			if(gCanBusCtl2.DataRequestMain[gCanBusCtl2.CurNode] && gCanBusCtl2.CurSetType == 0)
			{
				gCanBusCtl2.CurCmd = CMD_SET1;  //接捻小车参数
				gCanBusCtl2.MaxIndex = MAX_IDX_JN;
				gCanBusCtl2.RxFlag  = 0;
				if(gCanBusCtl2.CurIndex == gCanBusCtl2.MaxIndex)// 最后一帧  IDX = 0xFFFF
				{
					IDX = 0xFFFF;
					gCanBusCtl2.FinalFrame = 1;
				}
				else 
				{
					IDX = gCanBusCtl2.CurIndex;
					gCanBusCtl2.FinalFrame = 0;
				}
				ID = gCanBusCtl2.CurID = gCanBusCtl2.CurNode+0x21;
				CMD  = gCanBusCtl2.CurCmd;

				gCanBusCtl2.TxMsg.ExtId = (ID<<23)+(CMD<<16)+IDX;
				fill_data_set(DAT_JN, IDX);
	
				
			}
			//清纱数据请求或者有更新
 			else if(gCanBusCtl2.DataRequestQs[gCanBusCtl2.CurNode])// && gCanBusCtl1.CurSetType == 1)
			{
				gCanBusCtl2.CurCmd = CMD_SET2;  //清纱参数
				gCanBusCtl2.MaxIndex = MAX_IDX_QS;
				gCanBusCtl2.RxFlag  = 0;
				if(gCanBusCtl2.CurIndex == gCanBusCtl2.MaxIndex)// 最后一帧  IDX = 0xFFFF
				{
					IDX = 0xFFFF;
					gCanBusCtl2.FinalFrame = 1;
				}
				else 
				{
					IDX = gCanBusCtl2.CurIndex;
					gCanBusCtl2.FinalFrame = 0;
				}
				ID = gCanBusCtl2.CurID = gCanBusCtl2.CurNode+0x21;
				CMD  = gCanBusCtl2.CurCmd;

				gCanBusCtl2.TxMsg.ExtId = (gCanBusCtl2.CurID<<23)+(CMD<<16)+IDX;
				fill_data_set(DAT_QS1, IDX);
	
				
			}				// 轮询
			else
			{
					gCanBusCtl2.CurCmd = CMD_FLASH;  //轮询单节数据
					gCanBusCtl2.MaxIndex = 1;
					gCanBusCtl2.FinalFrame = 1;
					gCanBusCtl2.RxFlag  = 0;
					IDX = gCanBusCtl2.CurIndex;
					ID = gCanBusCtl2.CurID = gCanBusCtl2.CurNode+0x21;
					CMD  = gCanBusCtl2.CurCmd;

					gCanBusCtl2.TxMsg.ExtId = (ID<<23)+(CMD<<16)+IDX;
					fill_data_flash(DAT_JN, 0, 0, 101, 104);
				
			}



		}
		//副节点- AD  小车
		else
		{
			//AD  小车数据请求或者有更新
			if(gCanBusCtl2.DataRequestSub[gCanBusCtl2.CurNode])
			{
				gCanBusCtl2.CurCmd = CMD_SET1;  //发送AD  小车数据
				gCanBusCtl2.MaxIndex = MAX_IDX_AD;
				gCanBusCtl2.RxFlag  = 0;
				if(gCanBusCtl2.CurIndex == gCanBusCtl2.MaxIndex)
				{
					IDX = 0xFFFF;
					gCanBusCtl2.FinalFrame = 1;
				}
				else 
				{
					IDX = gCanBusCtl2.CurIndex;
					gCanBusCtl2.FinalFrame = 0;
				}
				ID = gCanBusCtl2.CurID = gCanBusCtl2.CurNode+0x31;
				CMD  = gCanBusCtl2.CurCmd;

				gCanBusCtl2.TxMsg.ExtId = (ID<<23)+(CMD<<16)+IDX;
				fill_data_set(DAT_AD, IDX);
			}
			// 轮询
			else
			{
				gCanBusCtl2.CurCmd = CMD_FLASH;  //轮询
				gCanBusCtl2.MaxIndex = 1;
				gCanBusCtl2.FinalFrame = 1;
				gCanBusCtl2.RxFlag  = 0;
				IDX = gCanBusCtl2.CurIndex;
				ID = gCanBusCtl2.CurID = gCanBusCtl2.CurNode+0x31;
				CMD  = gCanBusCtl2.CurCmd;

				gCanBusCtl2.TxMsg.ExtId = (ID<<23)+(CMD<<16)+IDX;
				fill_data_flash(DAT_AD, 0, 0, 0, 0);

			}

		}

		gCanBusCtl2.State = STS_SEND;

	}
	//发送数据
	else if(gCanBusCtl2.State == STS_SEND)
	{
		can2_buffer_add_msg(&gCanBusCtl2.TxMsg);
		if(gCanBusCtl2.FinalFrame) //最后一帧
		{
			gCanBusCtl2.WaitCnt = 400;// 200ms
			gCanBusCtl2.State = STS_WAIT_OVER_TIME;
		}
		else
		{
			//gCanBusCtl1.WaitCnt = 1;// 500us
			//gCanBusCtl1.State = STS_WAIT_SEND;
			gCanBusCtl2.CurIndex++;
			gCanBusCtl2.State = STS_LOAD;
		}
	}
	//超时处理
	else if(gCanBusCtl2.State == STS_OVER_TIME)
	{

		//重发
		if(gCanBusCtl2.ReSendCnt> 1)
		{
			gCanBusCtl2.ReSendCnt--;
			if(gCanBusCtl2.FinalFrame == 1)
			{
				gCanBusCtl2.CurIndex = 0;
			}
			gCanBusCtl2.State = STS_LOAD;
		}
		//重发超次数
		else
		{
			//主节点
			if(gCanBusCtl2.NodeType == 0)
			{
				if(gCanBusCtl2.ComErrMain[gCanBusCtl2.CurNode] < 3)
					gCanBusCtl2.ComErrMain[gCanBusCtl2.CurNode] ++;
				else
					gStatus.JN[gCanBusCtl2.CurNode].ComErr = 1;

				if(gCanBusCtl2.CurCmd == CMD_SET1 )
				{
					if(gCanBusCtl2.DataRequestQs[gCanBusCtl2.CurNode] == 0)
					{
						gCanBusCtl2.CurNode++;
						gCanBusCtl2.CurSetType = 0;
					}
					else
					{
						gCanBusCtl2.CurSetType = 1;
					}
						
				}
				else if(gCanBusCtl2.CurCmd == CMD_SET2)//下发参数命令
				{
						gCanBusCtl2.CurNode++;
						gCanBusCtl2.CurSetType = 0;
				}
				else if(gCanBusCtl2.CurCmd == CMD_FLASH)
				{
					gCanBusCtl2.CurNode++;
					gCanBusCtl2.CurSetType = 0;

				}
				//主节点完成  切换到副节点
				if(gCanBusCtl2.CurNode >= MAX_JN_NUM)
				{
					gCanBusCtl2.CurNode = 0;
					gCanBusCtl2.NodeType = 1;
				}
				gCanBusCtl2.CurIndex = 0;
				gCanBusCtl2.ReSendCnt = MAX_RESEND_NUM;
			

				gCanBusCtl2.State = STS_LOAD;
			}
			//副节点
			else
			{
				if(gCanBusCtl2.ComErrSub[gCanBusCtl2.CurNode] < 3)
					gCanBusCtl2.ComErrSub[gCanBusCtl2.CurNode] ++;
				else
					gStatus.AD.ComErr = 1;

				gCanBusCtl2.CurNode++;
				//副节点完成  切换到主节点
				if(gCanBusCtl2.CurNode >= MAX_AD_NUM)
				{
					gCanBusCtl2.CurNode = 0;
					gCanBusCtl2.NodeType = 0;
				}
				gCanBusCtl2.CurIndex = 0;
				gCanBusCtl2.ReSendCnt = MAX_RESEND_NUM;

				gCanBusCtl2.State = STS_LOAD;
			}
		}
	}
	// 收到回复
	else if(gCanBusCtl2.State == STS_PARSE)
	{
		if(gCanBusCtl2.FinalFrame == 1) //最后一帧
		{
			//主节点
			if(gCanBusCtl2.NodeType == 0)
			{
				gCanBusCtl2.ComErrMain[gCanBusCtl2.CurNode]=0;
				if(gCanBusCtl2.CurCmd == CMD_SET1 )
				{
					gCanBusCtl2.DataRequestMain[gCanBusCtl2.CurNode] = 0;
					if(gCanBusCtl2.DataRequestQs[gCanBusCtl2.CurNode] == 0 )
					{
						gCanBusCtl2.CurNode++;
						gCanBusCtl2.CurSetType = 0;
					}
					else
					{
						gCanBusCtl2.CurSetType = 1;
					}
						
				}
				else if(gCanBusCtl2.CurCmd == CMD_SET2)
				{
					gCanBusCtl2.DataRequestQs[gCanBusCtl2.CurNode] = 0;
					gCanBusCtl2.CurSetType = 0;
					gCanBusCtl2.CurNode++;
				}
				else if(gCanBusCtl2.CurCmd == CMD_FLASH)
				{
					gCanBusCtl2.CurNode++;
					gCanBusCtl2.CurSetType = 0;

				}
				//主节点完成  切换到副节点
				if(gCanBusCtl2.CurNode >= MAX_JN_NUM)
				{
					gCanBusCtl2.CurNode = 0;
					gCanBusCtl2.NodeType = 1;
				}
				
				gCanBusCtl2.CurIndex = 0;
				gCanBusCtl2.ReSendCnt = MAX_RESEND_NUM;
				gCanBusCtl2.State = STS_LOAD;

			}
			//副节点
			else
			{
				gCanBusCtl2.ComErrSub[gCanBusCtl2.CurNode]=0;
				if(gCanBusCtl2.CurCmd == CMD_SET1)//下发参数命令
				{
					gCanBusCtl2.DataRequestSub[gCanBusCtl2.CurNode] = 0;
					gCanBusCtl2.CurNode++;
				}
				else
				{
					if(gCanBusCtl2.DataRequestSub[gCanBusCtl2.CurNode] == 0)
						gCanBusCtl2.CurNode++;
				}
				//副节点完成  切换到主节点
				if(gCanBusCtl2.CurNode >= MAX_AD_NUM)
				{
					gCanBusCtl2.CurNode = 0;
					gCanBusCtl2.NodeType = 0;
				}
				gCanBusCtl2.CurIndex = 0;
				gCanBusCtl2.ReSendCnt = MAX_RESEND_NUM;
				gCanBusCtl2.State = STS_LOAD;
			}
		}
		else
		{
			gCanBusCtl2.CurIndex++;
			gCanBusCtl2.State = STS_LOAD;

		}

	}

		//发送
	pBuf = can2_buffer_get_msg();
	if(pBuf)
	{
		can2_send_msg(pBuf);
	}

	
}

void can_task_init(void)
{
	memset(&gCanBusCtl1, 0, sizeof(CanBusCtl_t));
	memset(&gCanBusCtl2, 0, sizeof(CanBusCtl_t));

	gCanBusCtl1.TxMsg.IDE = CAN_Id_Extended;
	gCanBusCtl1.TxMsg.RTR = 0;
	gCanBusCtl1.TxMsg.StdId = 0;


	gCanBusCtl2.TxMsg.IDE = CAN_Id_Extended;
	gCanBusCtl2.TxMsg.RTR = 0;
	gCanBusCtl2.TxMsg.StdId = 0;

}



