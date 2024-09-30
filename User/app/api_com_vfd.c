#include "sys_include.h"


VfdCom_t gVfdCom;




// 恢复接收器
static void _reset_rxd(void)
{
	memset(gVfdCom.VfdRecBuf,0,COM_VFD_FRAME_LEN);
	gVfdCom.RxdIndex = 0;
	gVfdCom.RxdFlag = 0;
}

//数据发送- 任务发送
static u8 _send_intervl(u8 *dp)
{
	static u8 n=0;
	u8 sci_state =0;
	
	
	if(gVfdCom.TxdSts == 0)//发送数据
	{
		SCI_B_DE_CTL(USART_BUS_TXD);
		n = 0;      //LC   发送数组的下标
		gVfdCom.TxdSts = 1;
	}
	else if(gVfdCom.TxdSts==1)//等待发送完成
	{
		USARTB_TXD(dp[n]);
		gVfdCom.TxdSts = 2;
		n++;
	}
	else if(gVfdCom.TxdSts==2)//等待发送完成
	{
		sci_state = USARTB_TXD_OK();     //LC:单个字节发送
		if(sci_state)//发送完成单个字节
		{
			if(n>=gVfdCom.TxLen)//发送完成
			{
				gVfdCom.TxdSts = 0;
				n = 0;
				SCI_B_DE_CTL(USART_BUS_RXD);	
				return 1;
			}
			else
			{
				gVfdCom.TxdSts = 1;
			}
		}
	}
	return 0;		
}
//加载数据
static void _load_data(u8 Nodex, u8 Cmd)
{
	u16 val = 0;
	u16 reg = 0;
	u8 addr = 0;
	u8 ofs = 0;
	u8 idx = 0;
	if(Cmd == CMD_VFD_FLASH)
	{
		gVfdCom.VfdTxdBuf[0] = Nodex+1;  //ADDR
		gVfdCom.VfdTxdBuf[1] = 3;  //CMD
		gVfdCom.VfdTxdBuf[2] = 8;  //Read Mxx
		gVfdCom.VfdTxdBuf[3] = 1;  // 
		gVfdCom.VfdTxdBuf[4] = 0;  
		gVfdCom.VfdTxdBuf[5] = 19;   //M01 - M19

		val = check_crc16(gVfdCom.VfdTxdBuf, 6);
		gVfdCom.VfdTxdBuf[6] = (val>>8)&0xff;   
		gVfdCom.VfdTxdBuf[7] = val&0xff;  

		gVfdCom.TxLen = 8;
		gVfdCom.CurCmd = Cmd;
		

	}
	else if(Cmd == CMD_VFD_READ_REG)
	{
		if(gVfdCom.RegReadFlag[Nodex].All & REG_00_MASK){idx = 0; reg = REG_FRE_PU; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_01_MASK){idx = 1;  reg = REG_FRE_HZ; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_02_MASK){idx = 2;  reg = REG_CMD; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_03_MASK){idx = 3;  reg = REG_OUT; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_04_MASK){idx = 4;  reg = REG_ACC_TIME; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_05_MASK){idx = 5;  reg = REG_DEC_TIME; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_06_MASK){idx = 6;  reg = REG_RST_ERR; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_07_MASK){idx = 7;  reg = REG_FRE1_MODE; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_08_MASK){idx = 8;  reg = REG_RUN_MODE; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_09_MASK){idx = 9;  reg = REG_FRE1_LIMIT; }
		else if(gVfdCom.RegReadFlag[Nodex].All & REG_10_MASK){idx = 10;  reg = REG_FRE1_REF; }
		else idx = 0xff;

		if(idx != 0xff)
		{
			addr = reg>>8;	
			ofs = reg & 0xff;
		
			gVfdCom.VfdTxdBuf[0] = Nodex+1;  //ADDR
			gVfdCom.VfdTxdBuf[1] = 3;  //CMD
			gVfdCom.VfdTxdBuf[2] = addr;  //REG addr
			gVfdCom.VfdTxdBuf[3] = ofs;  // REG ofs
			gVfdCom.VfdTxdBuf[4] = 0;  //len
			gVfdCom.VfdTxdBuf[5] = 1;   

			val = check_crc16(gVfdCom.VfdTxdBuf, 6);
			gVfdCom.VfdTxdBuf[6] = (val>>8)&0xff;   
			gVfdCom.VfdTxdBuf[7] = val&0xff;  

			gVfdCom.TxLen = 8;
			gVfdCom.CurCmd = Cmd;
			gVfdCom.CurIdx = idx;
			gVfdCom.CurReg = reg;
		}
		else
		{
			gVfdCom.TxLen = 0;
			gVfdCom.RegReadFlag[Nodex].All =0;
		}

	}
	else if(Cmd == CMD_VFD_WRITE_REG)
	{
		if(gVfdCom.RegWriteFlag[Nodex].All & REG_00_MASK)	{idx = 0; reg = REG_FRE_PU; val = gVfdCom.REGxx[Nodex].Fre_pu;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_01_MASK){idx = 1; reg = REG_FRE_HZ; val = gVfdCom.REGxx[Nodex].Fre_hz;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_02_MASK){idx = 2; reg = REG_CMD; val = gVfdCom.REGxx[Nodex].CMD.All;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_03_MASK){idx = 3; reg = REG_OUT; val = gVfdCom.REGxx[Nodex].OutST;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_04_MASK){idx = 4; reg = REG_ACC_TIME; val = gVfdCom.REGxx[Nodex].AccTime;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_05_MASK){idx = 5; reg = REG_DEC_TIME; val = gVfdCom.REGxx[Nodex].DecTime;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_06_MASK){idx = 6; reg = REG_RST_ERR; val = gVfdCom.REGxx[Nodex].RstErr;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_07_MASK){idx = 7; reg = REG_FRE1_MODE; val = gVfdCom.REGxx[Nodex].FRE1_MODE;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_08_MASK){idx = 8; reg = REG_RUN_MODE; val = gVfdCom.REGxx[Nodex].RUN_MODE;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_09_MASK){idx = 9; reg = REG_FRE1_LIMIT; val = gVfdCom.REGxx[Nodex].FRE1_LIMIT;}
		else if(gVfdCom.RegWriteFlag[Nodex].All & REG_10_MASK){idx = 10; reg = REG_FRE1_REF; val = gVfdCom.REGxx[Nodex].FRE1_REF;}
		else idx  = 0xff;
	
		if(idx != 0xff)
		{
			addr = reg>>8;	
			ofs = reg & 0xff;
			
			gVfdCom.VfdTxdBuf[0] = Nodex+1;  //ADDR
			gVfdCom.VfdTxdBuf[1] = 6;  //CMD
			gVfdCom.VfdTxdBuf[2] = addr;  //REG addr
			gVfdCom.VfdTxdBuf[3] = ofs;  // REG ofs
			gVfdCom.VfdTxdBuf[4] = val>>8;  //reg
			gVfdCom.VfdTxdBuf[5] = val&0xff;   

			val = check_crc16(gVfdCom.VfdTxdBuf, 6);
			gVfdCom.VfdTxdBuf[6] = (val>>8)&0xff;   
			gVfdCom.VfdTxdBuf[7] = val&0xff;  

			gVfdCom.TxLen = 8;
			gVfdCom.CurCmd = Cmd;
			gVfdCom.CurIdx = idx;
			gVfdCom.CurReg = reg;
		}
		else
		{
			gVfdCom.TxLen = 0;
			gVfdCom.RegWriteFlag[Nodex].All =0;
		}

	}
}
//加载数据
static void _parse_data(void)
{	
	u16 val = 0;
	u16 reg = 0;
	u8 addr = 0;
	u8 ofs = 0;
	u8 idx = 0;

	if(gVfdCom.VfdRecBuf[0] == gVfdCom.CurNode+ 1 && gVfdCom.CurNode < gVfdCom.MaxNode)
	{

		if(gVfdCom.VfdRecBuf[1] ==  3)
		{
			if(gVfdCom.CurCmd == CMD_VFD_FLASH)
			{
				gVfdCom.Mxx[gVfdCom.CurNode].Fre_pu = (gVfdCom.VfdRecBuf[3]<<8)+gVfdCom.VfdRecBuf[4];
				gVfdCom.Mxx[gVfdCom.CurNode].Tor = (gVfdCom.VfdRecBuf[5]<<8)+gVfdCom.VfdRecBuf[6];
				gVfdCom.Mxx[gVfdCom.CurNode].TorCur = (gVfdCom.VfdRecBuf[7]<<8)+gVfdCom.VfdRecBuf[8];
				gVfdCom.Mxx[gVfdCom.CurNode].Flux = (gVfdCom.VfdRecBuf[9]<<8)+gVfdCom.VfdRecBuf[10];
				gVfdCom.Mxx[gVfdCom.CurNode].Fre_hz = (gVfdCom.VfdRecBuf[11]<<8)+gVfdCom.VfdRecBuf[12];
				gVfdCom.Mxx[gVfdCom.CurNode].oFre_pu = (gVfdCom.VfdRecBuf[13]<<8)+gVfdCom.VfdRecBuf[14];
				gVfdCom.Mxx[gVfdCom.CurNode].oTor = (gVfdCom.VfdRecBuf[15]<<8)+gVfdCom.VfdRecBuf[16];
				gVfdCom.Mxx[gVfdCom.CurNode].oTorCur = (gVfdCom.VfdRecBuf[17]<<8)+gVfdCom.VfdRecBuf[18];
				gVfdCom.Mxx[gVfdCom.CurNode].oFre_hz = (gVfdCom.VfdRecBuf[19]<<8)+gVfdCom.VfdRecBuf[20];
				gVfdCom.Mxx[gVfdCom.CurNode].oP = (gVfdCom.VfdRecBuf[21]<<8)+gVfdCom.VfdRecBuf[22];
				gVfdCom.Mxx[gVfdCom.CurNode].oCur = (gVfdCom.VfdRecBuf[22]<<8)+gVfdCom.VfdRecBuf[24];
				gVfdCom.Mxx[gVfdCom.CurNode].oVol = (gVfdCom.VfdRecBuf[25]<<8)+gVfdCom.VfdRecBuf[26];
				gVfdCom.Mxx[gVfdCom.CurNode].CMD = (gVfdCom.VfdRecBuf[27]<<8)+gVfdCom.VfdRecBuf[28];
				gVfdCom.Mxx[gVfdCom.CurNode].RunST = (gVfdCom.VfdRecBuf[29]<<8)+gVfdCom.VfdRecBuf[30];
				gVfdCom.Mxx[gVfdCom.CurNode].OutST = (gVfdCom.VfdRecBuf[31]<<8)+gVfdCom.VfdRecBuf[32];
				gVfdCom.Mxx[gVfdCom.CurNode].ERR = (gVfdCom.VfdRecBuf[33]<<8)+gVfdCom.VfdRecBuf[34];
				gVfdCom.Mxx[gVfdCom.CurNode].ERR_1 = (gVfdCom.VfdRecBuf[35]<<8)+gVfdCom.VfdRecBuf[36];
				gVfdCom.Mxx[gVfdCom.CurNode].ERR_2 = (gVfdCom.VfdRecBuf[37]<<8)+gVfdCom.VfdRecBuf[38];
				gVfdCom.Mxx[gVfdCom.CurNode].ERR_3 = (gVfdCom.VfdRecBuf[39]<<8)+gVfdCom.VfdRecBuf[40];

			}
			else if(gVfdCom.CurCmd == CMD_VFD_READ_REG)
			{
				val = (gVfdCom.VfdRecBuf[3] << 8) + gVfdCom.VfdRecBuf[4];

				switch(gVfdCom.CurIdx)
				{
				case 0:	
					gVfdCom.REGxx[gVfdCom.CurNode].Fre_pu = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_00_MASK);
					break;
				case 1:	
					gVfdCom.REGxx[gVfdCom.CurNode].Fre_hz = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_01_MASK);
					break;
				case 2:	
					gVfdCom.REGxx[gVfdCom.CurNode].CMD.All = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_02_MASK);
					break;
				case 3:	
					gVfdCom.REGxx[gVfdCom.CurNode].OutST = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_03_MASK);
					break;
				case 4:	
					gVfdCom.REGxx[gVfdCom.CurNode].AccTime = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_04_MASK);
					break;
				case 5:	
					gVfdCom.REGxx[gVfdCom.CurNode].DecTime = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_05_MASK);
					break;
				case 6:	
					gVfdCom.REGxx[gVfdCom.CurNode].RstErr = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_06_MASK);
					break;
				case 7:	
					gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_07_MASK);
					break;
				case 8:	
					gVfdCom.REGxx[gVfdCom.CurNode].RUN_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_08_MASK);
					break;
				case 9:	
					gVfdCom.REGxx[gVfdCom.CurNode].FRE1_LIMIT = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_09_MASK);
					break;
				case 10:	
					gVfdCom.REGxx[gVfdCom.CurNode].FRE1_REF = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_10_MASK);
					break;
				case 11:	
					//gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_11_MASK);
					break;
				case 12:	
					//gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_12_MASK);
					break;
				case 13:	
					//gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_13_MASK);
					break;
				case 14:	
					gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_14_MASK);
					break;
				case 15:	
					//gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_15_MASK);
					break;
				case 16:	
					//gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_16_MASK);
					break;
				case 17:	
					//gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_17_MASK);
					break;
				case 18:	
					//gVfdCom.REGxx[gVfdCom.CurNode].FRE1_MODE = val;
					gVfdCom.RegReadFlag[gVfdCom.CurNode].All  = gVfdCom.RegReadFlag[gVfdCom.CurNode].All & (~REG_18_MASK);
					break;
				default: break;
				}
			}

		}

		else if(gVfdCom.VfdRecBuf[1] ==  6)
		{
			if(gVfdCom.CurCmd == CMD_VFD_WRITE_REG)
			{
				
				addr = gVfdCom.VfdRecBuf[2];	
				ofs = gVfdCom.VfdRecBuf[3];
				reg =( addr << 8) + ofs;
				val = (gVfdCom.VfdRecBuf[4] << 8) + gVfdCom.VfdRecBuf[5];
				if(gVfdCom.CurReg ==  reg)
				{
				
					switch(gVfdCom.CurIdx)
					{
					case 0:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_00_MASK);break;
					case 1:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_01_MASK);break;
					case 2:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_02_MASK);break;
					case 3:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_03_MASK);break;
					case 4:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_04_MASK);break;
					case 5:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_05_MASK);break;
					case 6:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_06_MASK);break;
					case 7:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_07_MASK);break;
					case 8:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_08_MASK);break;
					case 9:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_09_MASK);break;
					case 10:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_10_MASK);break;
					case 11:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_11_MASK);break;
					case 12:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_12_MASK);break;
					case 13:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_13_MASK);break;
					case 14:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_14_MASK);break;
					case 15:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_15_MASK);break;
					case 16:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_16_MASK);break;
					case 17:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_17_MASK);break;
					case 18:	gVfdCom.RegWriteFlag[gVfdCom.CurNode].All  = gVfdCom.RegWriteFlag[gVfdCom.CurNode].All & (~REG_18_MASK);break;
					default: break;
					}	
				}

			}
		}
	}
}


void vfd_com_init(void)
{
	memset(&gVfdCom, 0, sizeof(VfdCom_t));
	gVfdCom.MaxNode = 7;

	gVfdCom.RegReadFlag[0].All = 0x7FF;
	gVfdCom.RegReadFlag[1].All = 0x7FF;
	gVfdCom.RegReadFlag[2].All = 0x7FF;
	gVfdCom.RegReadFlag[3].All = 0x7FF;
	gVfdCom.RegReadFlag[4].All= 0x7FF;
	gVfdCom.RegReadFlag[5].All = 0x7FF;
	gVfdCom.RegReadFlag[6].All = 0x7FF;
}


void vfd_com_isr(void)
{
	
	u8 temp = USARTB_RXD();


	// 上一帧数据未处理
	if(gVfdCom.RxdFlag) 
	{
		return;
	}
	
	gVfdCom.RxdFrameTicker = 0;
	//长度判断	
	if(gVfdCom.RxdIndex>= COM_VFD_FRAME_LEN)
	{
		_reset_rxd();
	}
	//数据缓存	
	gVfdCom.VfdRecBuf[gVfdCom.RxdIndex] = temp;
	gVfdCom.RxdIndex++;
	

}





/***********************************************************************************************************/
//0.5ms
void vfd_com_task(void)
{
	u16 temp = 0;
	u8 check_l = 0,check_h = 0;

	//---------------------0.5ms ---------------------------------------//
	//发送数据
	if(gVfdCom.TxdFlag){
		if(_send_intervl(gVfdCom.VfdTxdBuf)== 1)
		{
			gVfdCom.TxdFlag = FALSE;
			_reset_rxd();
			gVfdCom.RxdWaitCnt = 0;
			gVfdCom.RxdFrameTicker = 0;
		}
		return;
	}
	gVfdCom.TxdSts = 0;// 恢复发送状态机

	//---------------------5ms ---------------------------------------//
	if(gVfdCom.TaskTicker < 10) 
		return;
	gVfdCom.TaskTicker = 0;


	//加载发送数据
	if(gVfdCom.State== 0)                   
	{
		//加载数据
		if(gVfdCom.RegWriteFlag[gVfdCom.CurNode].All)
		{
			//有参数下发
			_load_data(gVfdCom.CurNode, CMD_VFD_WRITE_REG);
		}
		else if(gVfdCom.RegReadFlag[gVfdCom.CurNode].All)
		{
			//有参数下发
			_load_data(gVfdCom.CurNode, CMD_VFD_READ_REG);
		}		
		else
		{
			//轮询
			_load_data(gVfdCom.CurNode, CMD_VFD_FLASH);
		}


		if(gVfdCom.TxLen)
		{
			gVfdCom.TxdFlag = 1;
			gVfdCom.State = 1;
		}
		return;
	}
	//接收数据
	else if(gVfdCom.State == 1)
	{
		//等待接收
		if(!gVfdCom.RxdFlag) 
		{
			gVfdCom.RxdWaitCnt++;
			if(gVfdCom.RxdWaitCnt >= 20)// 100mS
			{
				//超时
				goto LOOP_TIMEOUT;

			}
			return;

		}
		
		//判断校验码是否正确
		temp = check_crc16(gVfdCom.VfdRecBuf,gVfdCom.RxdLen-2);
		check_l = temp&0xff;
		check_h = (temp>>8)&0xff;
		if((gVfdCom.VfdRecBuf[gVfdCom.RxdLen-2] != check_h)||(gVfdCom.VfdRecBuf[gVfdCom.RxdLen-1] != check_l))
		{
			
			gVfdCom.State = 0;
			gVfdCom.ErrCnt[gVfdCom.CurNode]++;
			goto LOOP_REFLASH_END1;
		}

		// 数据处理
		_parse_data();

		gVfdCom.ErrCnt[gVfdCom.CurNode] = 0;
		goto LOOP_REFLASH_END1;
	}
LOOP_TIMEOUT:	
	
	gVfdCom.ErrCnt[gVfdCom.CurNode]++;
	if(gVfdCom.ErrCnt[gVfdCom.CurNode] > 30)
	{	
		gVfdCom.ErrCnt[gVfdCom.CurNode] = 30;
	}
LOOP_REFLASH_END1:
	//if(gVfdCom.CurCmd == CMD_VFD_FLASH)
	{
		gVfdCom.CurNode++;
		if(gVfdCom.CurNode >= gVfdCom.MaxNode)
			gVfdCom.CurNode = 0;
	}

	gVfdCom.State = 0;//切换到接收发送
	
}




