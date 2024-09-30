#include "sys_include.h"

SysCtlVal_t gSysCtlVal;



void (*Sys_Logic_Ptr) (void);

static void _vfd_out(void)
{


	//修改频率
	if(gSysCtlVal.FreGvn[VFD_LLM]!= gSysCtlVal.FreOut[VFD_LLM])
	{
		gSysCtlVal.FreOut[VFD_LLM] = gSysCtlVal.FreGvn[VFD_LLM];
		gVfdCom.REGxx[VFD_LLM].Fre_hz = gSysCtlVal.FreOut[VFD_LLM];
		gVfdCom.RegWriteFlag[VFD_LLM].bit.Fre_hz = 1;

	}
	//启动
	if(gSysCtlVal.Son[VFD_LLM]== 1  && gSysCtlVal.SonBk[VFD_LLM] == 0)
	{
		
		gVfdCom.REGxx[VFD_LLM].CMD.bit.FWD =1;
		gVfdCom.REGxx[VFD_LLM].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_LLM].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_LLM] = 1;
	}
	//停止
	if(gSysCtlVal.Son[VFD_LLM]== 0  && gSysCtlVal.SonBk[VFD_LLM] == 1)
	{
		gVfdCom.REGxx[VFD_LLM].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_LLM].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_LLM].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_LLM] = 0;
	}

	//修改频率
	if(gSysCtlVal.FreGvn[VFD_LLF]!= gSysCtlVal.FreOut[VFD_LLF])
	{
		gSysCtlVal.FreOut[VFD_LLF] = gSysCtlVal.FreGvn[VFD_LLF];
		gVfdCom.REGxx[VFD_LLF].Fre_hz = gSysCtlVal.FreOut[VFD_LLF];
		gVfdCom.RegWriteFlag[VFD_LLF].bit.Fre_hz = 1;

	}
	//启动
	if(gSysCtlVal.Son[VFD_LLF]== 1  && gSysCtlVal.SonBk[VFD_LLF] == 0)
	{
		
		gVfdCom.REGxx[VFD_LLF].CMD.bit.FWD =1;
		gVfdCom.REGxx[VFD_LLF].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_LLF].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_LLF] = 1;
	}
	//停止
	if(gSysCtlVal.Son[VFD_LLF]== 0  && gSysCtlVal.SonBk[VFD_LLF] == 1)
	{
		gVfdCom.REGxx[VFD_LLF].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_LLF].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_LLF].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_LLF] = 0;
	}

	//修改频率
	if(gSysCtlVal.FreGvn[VFD_HD]!= gSysCtlVal.FreOut[VFD_HD])
	{
		gSysCtlVal.FreOut[VFD_HD] = gSysCtlVal.FreGvn[VFD_HD];
		gVfdCom.REGxx[VFD_HD].Fre_hz = gSysCtlVal.FreOut[VFD_HD];
		gVfdCom.RegWriteFlag[VFD_HD].bit.Fre_hz = 1;

	}
	//启动
	if(gSysCtlVal.Son[VFD_HD]== 1  && gSysCtlVal.SonBk[VFD_HD] == 0)
	{
		
		gVfdCom.REGxx[VFD_HD].CMD.bit.FWD =1;
		gVfdCom.REGxx[VFD_HD].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_HD].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_HD] = 1;
	}
	//停止
	if(gSysCtlVal.Son[VFD_HD]== 0  && gSysCtlVal.SonBk[VFD_HD] == 1)
	{
		gVfdCom.REGxx[VFD_HD].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_HD].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_HD].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_HD] = 0;
	}

	//修改频率
	if(gSysCtlVal.FreGvn[VFD_JR]!= gSysCtlVal.FreOut[VFD_JR])
	{
		gSysCtlVal.FreOut[VFD_JR] = gSysCtlVal.FreGvn[VFD_JR];
		gVfdCom.REGxx[VFD_JR].Fre_hz = gSysCtlVal.FreOut[VFD_JR];
		gVfdCom.RegWriteFlag[VFD_JR].bit.Fre_hz = 1;

	}
	//启动
	if(gSysCtlVal.Son[VFD_JR]== 1  && gSysCtlVal.SonBk[VFD_JR] == 0)
	{
		
		gVfdCom.REGxx[VFD_JR].CMD.bit.FWD =1;
		gVfdCom.REGxx[VFD_JR].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_JR].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_JR] = 1;
	}
	//停止
	if(gSysCtlVal.Son[VFD_JR]== 0  && gSysCtlVal.SonBk[VFD_JR] == 1)
	{
		gVfdCom.REGxx[VFD_JR].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_JR].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_JR].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_JR] = 0;
	}

	//修改频率
	if(gSysCtlVal.FreGvn[VFD_MFJ]!= gSysCtlVal.FreOut[VFD_MFJ])
	{
		gSysCtlVal.FreOut[VFD_MFJ] = gSysCtlVal.FreGvn[VFD_MFJ];
		gVfdCom.REGxx[VFD_MFJ].Fre_hz = gSysCtlVal.FreOut[VFD_MFJ];
		gVfdCom.RegWriteFlag[VFD_MFJ].bit.Fre_hz = 1;

	}
	//启动
	if(gSysCtlVal.Son[VFD_MFJ]== 1  && gSysCtlVal.SonBk[VFD_MFJ] == 0)
	{
		
		gVfdCom.REGxx[VFD_MFJ].CMD.bit.FWD =1;
		gVfdCom.REGxx[VFD_MFJ].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_MFJ].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_MFJ] = 1;
	}
	//停止
	if(gSysCtlVal.Son[VFD_MFJ]== 0  && gSysCtlVal.SonBk[VFD_MFJ] == 1)
	{
		gVfdCom.REGxx[VFD_MFJ].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_MFJ].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_MFJ].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_MFJ] = 0;
	}


	//修改频率
	if(gSysCtlVal.FreGvn[VFD_SFJ]!= gSysCtlVal.FreOut[VFD_SFJ])
	{
		gSysCtlVal.FreOut[VFD_SFJ] = gSysCtlVal.FreGvn[VFD_SFJ];
		gVfdCom.REGxx[VFD_SFJ].Fre_hz = gSysCtlVal.FreOut[VFD_SFJ];
		gVfdCom.RegWriteFlag[VFD_SFJ].bit.Fre_hz = 1;

	}
	//启动
	if(gSysCtlVal.Son[VFD_SFJ]== 1  && gSysCtlVal.SonBk[VFD_SFJ] == 0)
	{
		
		gVfdCom.REGxx[VFD_SFJ].CMD.bit.FWD =1;
		gVfdCom.REGxx[VFD_SFJ].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_SFJ].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_SFJ] = 1;
	}
	//停止
	if(gSysCtlVal.Son[VFD_SFJ]== 0  && gSysCtlVal.SonBk[VFD_SFJ] == 1)
	{
		gVfdCom.REGxx[VFD_SFJ].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_SFJ].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_SFJ].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_SFJ] = 0;
	}

	//修改频率
	if(gSysCtlVal.FreGvn[VFD_PG]!= gSysCtlVal.FreOut[VFD_PG])
	{
		gSysCtlVal.FreOut[VFD_PG] = gSysCtlVal.FreGvn[VFD_PG];
		gVfdCom.REGxx[VFD_PG].Fre_hz = gSysCtlVal.FreOut[VFD_PG];
		gVfdCom.RegWriteFlag[VFD_PG].bit.Fre_hz = 1;

	}
	//启动
	if(gSysCtlVal.Son[VFD_PG]== 1  && gSysCtlVal.SonBk[VFD_PG] == 0)
	{
		
		gVfdCom.REGxx[VFD_PG].CMD.bit.FWD =1;
		gVfdCom.REGxx[VFD_PG].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_PG].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_PG] = 1;
	}
	//停止
	if(gSysCtlVal.Son[VFD_PG]== 0  && gSysCtlVal.SonBk[VFD_PG] == 1)
	{
		gVfdCom.REGxx[VFD_PG].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_PG].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_PG].bit.CMD = 1;

		gSysCtlVal.SonBk[VFD_PG] = 0;
	}
}


void sys_logic_main(void)
{
	static u8 psr = 0;
	CanMsg_t TxMsg={0,}; //发送数据缓存

	//--------------------------------------------------------------------
	// 1K 分频
	psr++;
	if(psr < SYS_ISR_PSC)
		return ;
	psr = 0;
	//--------------------------------------------------------------------
	
	//--------------------------------------------------------------------
	//机头控制
	//--------------------------------------------------------------------
	(*Sys_Logic_Ptr)();
	//--------------------------------------------------------------------

	//--------------------------------------------------------------------
	//换管控制
	//--------------------------------------------------------------------
	sys_logic_ad();
	//--------------------------------------------------------------------

	//--------------------------------------------------------------------
	//接头控制
	//--------------------------------------------------------------------
	sys_logic_jn();
	//--------------------------------------------------------------------




}


void sys_logic_ad(void)
{
	CanMsg_t TxMsg={0,}; //发送数据缓存
	//--------------------------------------------------------------------
	//换管小车分配
	//--------------------------------------------------------------------
	// 更新当前小车位置
	gSysCtlVal.AD_Ctl.PreAds = gSysCtlVal.AD_Ctl.CurAds;
	gSysCtlVal.AD_Ctl.CurAds =gStatus.AD.PosCur;
	gSysCtlVal.AD_Ctl.EmptyNum = gStatus.AD.EmptyNum;
	gSysCtlVal.AD_Ctl.FlagIsEmpty = gSysCtlVal.AD_Ctl.EmptyNum?0:1;

	//--------------------------------------------------------------------
	//进行规划分配小车
	//条件: 当前无执行小车
	//条件: 小车上有空管
	if(gSysCtlVal.AD_Ctl.FlagIsEmpty == 0)
	{
		if(gSysCtlVal.AD_Ctl.pRequestExec == NULL)
		{
			//根据当前小车位置获取距离小车最近的锭位
			gSysCtlVal.AD_Ctl.pRequestExec = request_list_get_request(&request_list_ad, gSysCtlVal.AD_Ctl.CurAds);
			if(gSysCtlVal.AD_Ctl.pRequestExec)
			{
				//在工作范围内
				if(gSysCtlVal.AD_Ctl.pRequestExec->ads >= gSysPar.LSC_S1 || gSysCtlVal.AD_Ctl.pRequestExec->ads <= gSysPar.LSC_E1)
				{
					gSysCtlVal.AD_Ctl.FlagRequest = 1;
					gSysCtlVal.AD_Ctl.TotalCnt++;
					gSysCtlVal.AD_Ctl.RequestCnt++;
				}
				//从表中删除
				else
				{
					request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.pRequestExec->ads);
					gSysCtlVal.AD_Ctl.pRequestExec = NULL;
				}
			}
		}
		else if(gSysCtlVal.AD_Ctl.PreAds != gSysCtlVal.AD_Ctl.CurAds)
		{
			//根据当前小车位置获取距离小车最近的锭位
			gSysCtlVal.AD_Ctl.pRequestTemp = request_list_get_request(&request_list_ad, gSysCtlVal.AD_Ctl.CurAds);
			//有更近的
			if(gSysCtlVal.AD_Ctl.pRequestTemp && gSysCtlVal.AD_Ctl.pRequestTemp != gSysCtlVal.AD_Ctl.pRequestExec)
			{
				//在工作范围内
				if(gSysCtlVal.AD_Ctl.pRequestTemp->ads >= gSysPar.LSC_S1 || gSysCtlVal.AD_Ctl.pRequestTemp->ads <= gSysPar.LSC_E1)
				{
					gSysCtlVal.AD_Ctl.pRequestExec = gSysCtlVal.AD_Ctl.pRequestTemp;
					gSysCtlVal.AD_Ctl.pRequestTemp = NULL;
					gSysCtlVal.AD_Ctl.FlagRequest = 1;
					gSysCtlVal.AD_Ctl.TotalCnt++;
					gSysCtlVal.AD_Ctl.RequestCnt++;
				}
				//从表中删除
				else
				{
					request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.pRequestTemp->ads);
					gSysCtlVal.AD_Ctl.pRequestTemp = NULL;

				}
			}
			else
			{
				gSysCtlVal.AD_Ctl.pRequestTemp = NULL;
			}

		}
	}


	
	//--------------------------------------------------------------------
	//小车执行完毕
	if(gSysCtlVal.AD_Ctl.FlagDone)
	{
		gSysCtlVal.AD_Ctl.DoneCnt++;
		request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.pRequestExec->ads);
		gSysCtlVal.AD_Ctl.pRequestExec = NULL;
		//正常完成
		if(gSysCtlVal.AD_Ctl.FlagDone == 1)
		{
			gSysCtlVal.AD_Ctl.DoneCnt_OK++;
		}
		//出错
		else if(gSysCtlVal.AD_Ctl.FlagDone == 2)
		{
			gSysCtlVal.AD_Ctl.DoneCnt_ERR++;
		}
		gSysCtlVal.AD_Ctl.FlagDone = 0;
	}

	//--------------------------------------------------------------------
	//发送命令--- 数据传输控制
	if(gSysCtlVal.AD_Ctl.TransSts == 0)
	{
		if(gSysCtlVal.AD_Ctl.FlagCancel)
		{
			gSysCtlVal.AD_Ctl.TransSts = 2;
			gSysCtlVal.AD_Ctl.TransDlyTicker = 500;// 500ms
			gSysCtlVal.AD_Ctl.TransCnt = 3;
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (0x31<<23)+(CMD_AD_REQUEST<<16)+0;
			TxMsg.Data[0] = 0;
			TxMsg.Data[1] = gSysCtlVal.AD_Ctl.pRequestExec->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = 0;
			TxMsg.Data[5] = 0;
			TxMsg.Data[6] = 0;
			TxMsg.Data[7] = 0;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}
		else if(gSysCtlVal.AD_Ctl.FlagRequest)
		{
			gSysCtlVal.AD_Ctl.TransSts = 1;
			gSysCtlVal.AD_Ctl.TransDlyTicker = 500;// 500ms
			gSysCtlVal.AD_Ctl.TransCnt = 3;
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (0x31<<23)+(CMD_AD_REQUEST<<16)+0;
			TxMsg.Data[0] = 1;
			TxMsg.Data[1] = gSysCtlVal.AD_Ctl.pRequestExec->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur>>24;
			TxMsg.Data[5] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur>>16;
			TxMsg.Data[6] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur>>8;
			TxMsg.Data[7] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur&0xFF;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}


	}
	//收到回复
	else if(gSysCtlVal.AD_Ctl.TransSts == 3)
	{
		gSysCtlVal.AD_Ctl.TransSts = 0;
		gSysCtlVal.AD_Ctl.FlagRequest = 0;
		gSysCtlVal.AD_Ctl.FlagTransErr = 0;
	}
	else if(gSysCtlVal.AD_Ctl.TransSts == 4)
	{
		gSysCtlVal.AD_Ctl.TransSts = 0;
		gSysCtlVal.AD_Ctl.FlagCancel = 0;
		gSysCtlVal.AD_Ctl.FlagTransErr = 0;
		request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.pRequestExec->ads);
		gSysCtlVal.AD_Ctl.pRequestExec = NULL;
	}
	//重发超时
	else if(gSysCtlVal.AD_Ctl.TransSts == 2 && gSysCtlVal.AD_Ctl.TransDlyTicker ==0)
	{
		gSysCtlVal.AD_Ctl.TransCnt --;
		if(gSysCtlVal.AD_Ctl.TransCnt)
		{
			gSysCtlVal.AD_Ctl.TransDlyTicker = 500;// 500ms
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (0x31<<23)+(CMD_AD_REQUEST<<16)+0;
			TxMsg.Data[0] = 0;
			TxMsg.Data[1] = gSysCtlVal.AD_Ctl.pRequestExec->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = 0;
			TxMsg.Data[5] = 0;
			TxMsg.Data[6] = 0;
			TxMsg.Data[7] = 0;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}
		else //取消请求超时
		{
			gSysCtlVal.AD_Ctl.FlagCancel = 0;
			gSysCtlVal.AD_Ctl.TransSts = 0;
			gSysCtlVal.AD_Ctl.FlagTransErr ++;
			request_list_del_request(&request_list_ad, gSysCtlVal.AD_Ctl.pRequestExec->ads);
			gSysCtlVal.AD_Ctl.pRequestExec = NULL;
		}
	}
	else if(gSysCtlVal.AD_Ctl.TransSts == 1 && gSysCtlVal.AD_Ctl.TransDlyTicker ==0)
	{
		gSysCtlVal.AD_Ctl.TransCnt --;
		if(gSysCtlVal.AD_Ctl.TransCnt)
		{
			gSysCtlVal.AD_Ctl.TransDlyTicker = 500;// 500ms
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = (0x31<<23)+(CMD_AD_REQUEST<<16)+0;
			TxMsg.Data[0] = 1;
			TxMsg.Data[1] = gSysCtlVal.AD_Ctl.pRequestExec->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur>>24;
			TxMsg.Data[5] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur>>16;
			TxMsg.Data[6] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur>>8;
			TxMsg.Data[7] = gSysCtlVal.AD_Ctl.pRequestExec->len_cur&0xFF;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}
		else //请求超时
		{
			gSysCtlVal.AD_Ctl.pRequestExec = NULL;
			gSysCtlVal.AD_Ctl.FlagRequest = 0;
			gSysCtlVal.AD_Ctl.TransSts = 0;
			gSysCtlVal.AD_Ctl.FlagTransErr ++;
		}
	}
	else if(gSysCtlVal.AD_Ctl.TransDlyTicker)
	{
		gSysCtlVal.AD_Ctl.TransDlyTicker--;
	}
	//--------------------------------------------------------------------

}


void sys_logic_jn(void)
{

	CanMsg_t TxMsg={0,}; //发送数据缓存
	static u8 node = 0;
	u8 flag =0;
	u8 idx =0;
	//--------------------------------------------------------------------
	// 接捻小车分配
	gSysCtlVal.JN_Ctl.PreAds[node] = gSysCtlVal.JN_Ctl.CurAds[node];
	gSysCtlVal.JN_Ctl.CurAds[node] =gStatus.JN[node].PosCur;

	//进行规划分配小车
	//条件: 当前无执行小车
	//条件: 小车上有空管
	if(gSysPar.JNC_CFG & (0x1<< node))
	{
		if(gSysCtlVal.JN_Ctl.pRequestExec[node] == NULL)
		{
			//根据当前小车位置获取距离小车最近的锭位
			gSysCtlVal.JN_Ctl.pRequestExec[node] = request_list_get_request(&request_list_jn, gSysCtlVal.JN_Ctl.CurAds[node]);
			if(gSysCtlVal.JN_Ctl.pRequestExec[node] && gSysCtlVal.JN_Ctl.pRequestExec[node]->ads>=gSysPar.JNC_S[node] && gSysCtlVal.JN_Ctl.pRequestExec[node]->ads<=gSysPar.JNC_E[node])
			{	
				flag = 0;
				for(idx=0;idx<MAX_JN_NUM;idx++)
				{
					if(node == idx)
						continue;
					//其他小车在执行该锭
					else if(gSysCtlVal.JN_Ctl.pRequestExec[idx] &&  gSysCtlVal.JN_Ctl.pRequestExec[node]->ads == gSysCtlVal.JN_Ctl.pRequestExec[idx]->ads)
						flag = 1;
				}
				if(flag == 0)
				{
					gSysCtlVal.JN_Ctl.FlagRequest[node] = 1;
					gSysCtlVal.JN_Ctl.TotalCnt[node]++;
					gSysCtlVal.JN_Ctl.RequestCnt[node]++;
				}
				else
				{
					gSysCtlVal.JN_Ctl.pRequestExec[node] = NULL;

				}
			}
			else
			{
				gSysCtlVal.JN_Ctl.pRequestExec[node] = NULL;
			}
		}
		else if(gSysCtlVal.JN_Ctl.PreAds[node] != gSysCtlVal.JN_Ctl.CurAds[node])
		{
			//根据当前小车位置获取距离小车最近的锭位
			gSysCtlVal.JN_Ctl.pRequestTemp[node] = request_list_get_request(&request_list_jn, gSysCtlVal.JN_Ctl.CurAds[node]);
			//有更近的
			if(gSysCtlVal.JN_Ctl.pRequestTemp[node] && gSysCtlVal.JN_Ctl.pRequestTemp[node] != gSysCtlVal.JN_Ctl.pRequestExec[node] && gSysCtlVal.JN_Ctl.pRequestTemp[node]->ads>=gSysPar.JNC_S[node] && gSysCtlVal.JN_Ctl.pRequestTemp[node]->ads<=gSysPar.JNC_E[node])
			{

				flag = 0;
				for(idx=0;idx<MAX_JN_NUM;idx++)
				{
					if(node == idx)
						continue;
					//其他小车在执行该锭
					else if(gSysCtlVal.JN_Ctl.pRequestExec[idx] &&  gSysCtlVal.JN_Ctl.pRequestTemp[node]->ads == gSysCtlVal.JN_Ctl.pRequestExec[idx]->ads)
						flag = 1;
				}
				if(flag == 0)
				{
					gSysCtlVal.JN_Ctl.pRequestExec[node] = gSysCtlVal.JN_Ctl.pRequestTemp[node];
					gSysCtlVal.JN_Ctl.pRequestTemp[node] = NULL;
					gSysCtlVal.JN_Ctl.FlagRequest[node] = 1;
					gSysCtlVal.JN_Ctl.TotalCnt[node]++;
					gSysCtlVal.JN_Ctl.RequestCnt[node]++;
				}
				else
				{
					gSysCtlVal.JN_Ctl.pRequestTemp[node] = NULL;

				}
			}

		}

	}
	else
	{
		gSysCtlVal.JN_Ctl.pRequestExec[node] = NULL;
	}

	


	
	//--------------------------------------------------------------------
	//小车执行完毕
	if(gSysCtlVal.JN_Ctl.FlagDone[node])
	{
		gSysCtlVal.JN_Ctl.DoneCnt[node]++;
		request_list_del_request(&request_list_jn, gSysCtlVal.JN_Ctl.pRequestExec[node]->ads);
		gSysCtlVal.JN_Ctl.pRequestExec[node] = NULL;
		//正常完成
		if(gSysCtlVal.JN_Ctl.FlagDone[node] == 1)
		{
			gSysCtlVal.JN_Ctl.DoneCnt_OK[node]++;
		}
		//出错
		else if(gSysCtlVal.JN_Ctl.FlagDone[node] == 2)
		{
			gSysCtlVal.JN_Ctl.DoneCnt_ERR[node]++;
		}
		gSysCtlVal.JN_Ctl.FlagDone[node] = 0;
	}

	//--------------------------------------------------------------------
	//发送命令--- 数据传输控制
	if(gSysCtlVal.JN_Ctl.TransSts[node] == 0)
	{
		if(gSysCtlVal.JN_Ctl.FlagCancel[node])
		{
			gSysCtlVal.JN_Ctl.TransSts[node] = 2;
			gSysCtlVal.JN_Ctl.TransDlyTicker[node] = 125;// 500ms
			gSysCtlVal.JN_Ctl.TransCnt[node] = 3;
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = ((0x21+node)<<23)+(CMD_JN_REQUEST<<16)+0;
			TxMsg.Data[0] = 0;
			TxMsg.Data[1] = gSysCtlVal.JN_Ctl.pRequestExec[node]->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = 0;
			TxMsg.Data[5] = 0;
			TxMsg.Data[6] = 0;
			TxMsg.Data[7] = 0;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}
		else if(gSysCtlVal.JN_Ctl.FlagRequest[node])
		{
			gSysCtlVal.JN_Ctl.TransSts[node] = 1;
			gSysCtlVal.JN_Ctl.TransDlyTicker[node] = 125;// 500ms
			gSysCtlVal.JN_Ctl.TransCnt[node] = 3;
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = ((0x21+node)<<23)+(CMD_JN_REQUEST<<16)+0;
			TxMsg.Data[0] = 1;
			TxMsg.Data[1] = gSysCtlVal.JN_Ctl.pRequestExec[node]->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur>>24;
			TxMsg.Data[5] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur>>16;
			TxMsg.Data[6] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur>>8;
			TxMsg.Data[7] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur&0xFF;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}


	}
	//收到回复
	else if(gSysCtlVal.JN_Ctl.TransSts[node] == 3)
	{
		gSysCtlVal.JN_Ctl.TransSts[node] = 0;
		gSysCtlVal.JN_Ctl.FlagRequest[node] = 0;
		gSysCtlVal.JN_Ctl.FlagTransErr[node] = 0;
	}
	else if(gSysCtlVal.JN_Ctl.TransSts[node] == 4)
	{
		gSysCtlVal.JN_Ctl.TransSts[node] = 0;
		gSysCtlVal.JN_Ctl.FlagCancel[node] = 0;
		gSysCtlVal.JN_Ctl.FlagTransErr[node] = 0;
		request_list_del_request(&request_list_jn, gSysCtlVal.JN_Ctl.pRequestExec[node]->ads);
		gSysCtlVal.JN_Ctl.pRequestExec[node] = NULL;
	}
	//重发超时
	else if(gSysCtlVal.JN_Ctl.TransSts[node] == 2 && gSysCtlVal.JN_Ctl.TransDlyTicker[node] ==0)
	{
		gSysCtlVal.JN_Ctl.TransCnt[node] --;
		if(gSysCtlVal.JN_Ctl.TransCnt[node])
		{
			gSysCtlVal.JN_Ctl.TransDlyTicker[node] = 125;// 500ms
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = ((0x21+node)<<23)+(CMD_JN_REQUEST<<16)+0;
			TxMsg.Data[0] = 0;
			TxMsg.Data[1] = gSysCtlVal.JN_Ctl.pRequestExec[node]->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = 0;
			TxMsg.Data[5] = 0;
			TxMsg.Data[6] = 0;
			TxMsg.Data[7] = 0;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}
		else //取消请求超时
		{
			gSysCtlVal.JN_Ctl.FlagCancel[node] = 0;
			gSysCtlVal.JN_Ctl.TransSts[node] = 0;
			gSysCtlVal.JN_Ctl.FlagTransErr[node] ++;
			request_list_del_request(&request_list_jn, gSysCtlVal.JN_Ctl.pRequestExec[node]->ads);
			gSysCtlVal.JN_Ctl.pRequestExec[node] = NULL;
		}
	}
	else if(gSysCtlVal.JN_Ctl.TransSts[node] == 1 && gSysCtlVal.JN_Ctl.TransDlyTicker[node] ==0)
	{
		gSysCtlVal.JN_Ctl.TransCnt[node] --;
		if(gSysCtlVal.JN_Ctl.TransCnt[node])
		{
			gSysCtlVal.JN_Ctl.TransDlyTicker[node] = 125;// 500ms
			TxMsg.IDE = CAN_Id_Extended;
			TxMsg.RTR = 0;
			TxMsg.StdId = 0;
			TxMsg.ExtId = ((0x21+node)<<23)+(CMD_JN_REQUEST<<16)+0;
			TxMsg.Data[0] = 1;
			TxMsg.Data[1] = gSysCtlVal.JN_Ctl.pRequestExec[node]->ads;
			TxMsg.Data[2] = 0;
			TxMsg.Data[3] = 0;
			TxMsg.Data[4] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur>>24;
			TxMsg.Data[5] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur>>16;
			TxMsg.Data[6] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur>>8;
			TxMsg.Data[7] = gSysCtlVal.JN_Ctl.pRequestExec[node]->len_cur&0xFF;
			TxMsg.DLC  = 8;
			can2_buffer_add_msg(&TxMsg);
		}
		else //请求超时
		{
			gSysCtlVal.JN_Ctl.pRequestExec[node] = NULL;
			gSysCtlVal.JN_Ctl.FlagRequest[node] = 0;
			gSysCtlVal.JN_Ctl.TransSts[node] = 0;
			gSysCtlVal.JN_Ctl.FlagTransErr[node] ++;
		}
	}
	else if(gSysCtlVal.JN_Ctl.TransDlyTicker[node])
	{
		gSysCtlVal.JN_Ctl.TransDlyTicker[node]--;
	}


	node++;if(node >= MAX_JN_NUM)node = 0;
}

// 1K
void sys_logic_wait(void)
{
	static u16 start_cnt = 0;
	float temp_f = 0;
	gSysCtlVal.Sts = STS_WAIT;


	if(gSysCtlVal.TestMode == 1)
	{
		gSysCtlVal.TestFre1Bk = 0;
		gSysCtlVal.TestFre2Bk = 0;
		gSysCtlVal.TestFre3Bk = 0;
		gSysCtlVal.TestFre4Bk = 0;
		gSysCtlVal.TestFre5Bk = 0;
		gSysCtlVal.TestFre6Bk = 0;
		gSysCtlVal.TestFre7Bk = 0;
		gSysCtlVal.TestCtl1Bk.all = 0;
		
		gSysCtlVal.TestCtl2Bk.all = gSysHard.TestOut1.All & 0xFF;
		gSysCtlVal.TestCtl3Bk.all = gSysHard.TestOut1.All >> 8;
		gSysCtlVal.TestCtl4Bk.all = gSysHard.TestOut2.All & 0xFF;
		gSysCtlVal.TestCtl5Bk.all = gSysHard.TestOut2.All >> 8;
		gSysCtlVal.TestCtl6Bk.all = gSysHard.TestOut3.All & 0xFF;
		Sys_Logic_Ptr = &sys_logic_test;

		return ;
	}

	if(BT_START)
	{
		if(start_cnt >=10)
		{
			
			gSysCtlVal.FreOut[VFD_LLM]= 0;
			gSysCtlVal.FreOut[VFD_LLF]= 0;
			gSysCtlVal.FreOut[VFD_HD]= 0;
			gSysCtlVal.FreOut[VFD_JR]= 0;
			gSysCtlVal.FreOut[VFD_MFJ]= 0;
			gSysCtlVal.FreOut[VFD_SFJ]= 0;
			gSysCtlVal.FreOut[VFD_PG]= 0;
			
			gSysCtlVal.SonBk[VFD_LLM] = 0;
			gSysCtlVal.SonBk[VFD_LLF] = 0;
			gSysCtlVal.SonBk[VFD_HD] = 0;
			gSysCtlVal.SonBk[VFD_JR] = 0;
			gSysCtlVal.SonBk[VFD_MFJ] = 0;
			gSysCtlVal.SonBk[VFD_SFJ] = 0;
			gSysCtlVal.SonBk[VFD_PG] = 0;

			gSysCtlVal.XSPD_Gvn = gSysPar.XSPD;
			gSysCtlVal.TDR_Gvn = gSysPar.TDR;
			gSysCtlVal.MDR_Gvn = gSysPar.MDR;
			gSysCtlVal.BDR_Gvn = gSysPar.BDR;
			gSysCtlVal.WDR_Gvn = gSysPar.WDR;
			gSysCtlVal.JDR_Gvn = gSysPar.JDR;
			gSysCtlVal.BR_Gvn = gSysPar.BR;
			gSysCtlVal.JANG_Gvn = gSysPar.JANG;

			

			gSysCtlVal.XSPD = gSysCtlVal.XSPD_Gvn*0.1f;
			gSysCtlVal.TDR = gSysCtlVal.TDR_Gvn*0.1f;
			gSysCtlVal.MDR = gSysCtlVal.MDR_Gvn*0.1f;
			gSysCtlVal.BDR = gSysCtlVal.BDR_Gvn*0.1f;
			gSysCtlVal.WDR = gSysCtlVal.WDR_Gvn*0.001f;
			gSysCtlVal.JDR = gSysCtlVal.JDR_Gvn*0.001f;
			gSysCtlVal.BR = gSysCtlVal.BR_Gvn;
			gSysCtlVal.JANG = gSysCtlVal.JANG_Gvn;


			//卷绕
			gSysCtlVal.JR_Xspd = gSysCtlVal.XSPD/gSysCtlVal.JDR;
			gSysCtlVal.JR_Spd = gSysCtlVal.JR_Xspd*JR_Cn;
			gSysCtlVal.FreGvn[VFD_JR]= gSysCtlVal.JR_Spd*JR_GEAR*JR_HzPR;
			gSysCtlVal.Son[VFD_JR] = 1;
			//摩擦辊罗拉
			gSysCtlVal.CW_Xspd = gSysCtlVal.XSPD;
			gSysCtlVal.CW_Spd = gSysCtlVal.CW_Xspd*CW_Cn;
			
			//前罗拉
			gSysCtlVal.LLF_Xspd = gSysCtlVal.CW_Xspd/gSysCtlVal.WDR;
			gSysCtlVal.LLF_Spd = gSysCtlVal.LLF_Xspd*LLF_Cn;
			gSysCtlVal.FreGvn[VFD_LLF]= gSysCtlVal.LLF_Spd*LLF_GEAR*LLF_HzPR;
			gSysCtlVal.Son[VFD_LLF] = 1;
			//中罗拉
			gSysCtlVal.LLM_Xspd = gSysCtlVal.CW_Xspd/gSysCtlVal.MDR;
			gSysCtlVal.LLM_Spd = gSysCtlVal.LLM_Xspd*LLM_Cn;
			gSysCtlVal.FreGvn[VFD_LLM]= gSysCtlVal.LLM_Spd*LLM_GEAR*LLM_HzPR;
			gSysCtlVal.Son[VFD_LLM] = 1;
			//第4 罗拉
			gSysCtlVal.LL4_Xspd = gSysCtlVal.CW_Xspd/gSysCtlVal.TDR;
			gSysCtlVal.LL4_Spd = gSysCtlVal.LL4_Xspd*LL4_Cn;
			//第3 罗拉
			gSysCtlVal.LL3_Xspd = gSysCtlVal.LL4_Xspd*gSysCtlVal.BDR;
			gSysCtlVal.LL3_Spd = gSysCtlVal.LL3_Xspd*LL3_Cn;

			//横动
			temp_f =   gSysPar.JANG*0.0087266461111111f;//0.5f*gSysCtlVal.JANG*PI/180;
			temp_f = tan(temp_f);
			gSysCtlVal.HD_Xspd = gSysCtlVal.JR_Xspd*temp_f;
			gSysCtlVal.HD_Spd = 0.5f*gSysCtlVal.HD_Xspd*HD_LENn;//横动电机每转一圈，导纱一次来回
			gSysCtlVal.HD_Fre = gSysCtlVal.HD_Spd*HD_GEAR*HD_HzPR;
			gSysCtlVal.FreGvn[VFD_HD] = gSysCtlVal.HD_Fre;
			gSysCtlVal.Son[VFD_HD] = 1;
			
			gSysCtlVal.FD_Rre = gSysCtlVal.HD_Fre*gSysPar.FD_Rto*0.001f;
			gSysCtlVal.FD_Sts = 0;
			gSysCtlVal.FD_Ticker = 0;


			//主风机
			gSysCtlVal.MFJ_Fre_Gvn = gSysPar.MFJ_Fre;
			gSysCtlVal.FreGvn[VFD_MFJ]= gSysCtlVal.MFJ_Fre_Gvn;
			gSysCtlVal.Son[VFD_MFJ] = 1;


			//副风机
			gSysCtlVal.SFJ_Fre_Gvn = gSysPar.SFJ_Fre;
			gSysCtlVal.FreGvn[VFD_SFJ]= gSysCtlVal.SFJ_Fre_Gvn;
			gSysCtlVal.Son[VFD_SFJ] = 1;

			//打包机
			gSysCtlVal.FreGvn[VFD_PG]= 1000;
			gSysCtlVal.Son[VFD_PG] = 1;
			
			
			
			Sys_Logic_Ptr = &sys_logic_run;
		}
		else
		{
			start_cnt++;
		}
	}
	else
	{
		start_cnt = 0;
	}



	//变频器输出
	_vfd_out();

	START_LAMP(0);
	STOP_LAMP(1);

	
}



// 1K
void sys_logic_run(void)
{
	static u8 psr = 0;
	static u16 stop_cnt = 0;
	float temp_f =0;
	
	gSysCtlVal.Sts = STS_RUN;
	psr++;
	if(psr >= 10)
	{
		psr = 0;

		if(gSysPar.XSPD != gSysCtlVal.XSPD_Gvn 
			||gSysPar.TDR != gSysCtlVal.TDR_Gvn
			||gSysPar.MDR != gSysCtlVal.MDR_Gvn
			||gSysPar.BDR != gSysCtlVal.BDR_Gvn
			||gSysPar.WDR != gSysCtlVal.WDR_Gvn
			||gSysPar.JDR != gSysCtlVal.JDR_Gvn
			||gSysPar.JANG != gSysCtlVal.JANG_Gvn)
		{
			gSysCtlVal.XSPD_Gvn = gSysPar.XSPD;
			gSysCtlVal.TDR_Gvn = gSysPar.TDR;
			gSysCtlVal.MDR_Gvn = gSysPar.MDR;
			gSysCtlVal.BDR_Gvn = gSysPar.BDR;
			gSysCtlVal.WDR_Gvn = gSysPar.WDR;
			gSysCtlVal.JDR_Gvn = gSysPar.JDR;
			gSysCtlVal.JANG_Gvn = gSysPar.JANG;


			
			gSysCtlVal.XSPD = gSysCtlVal.XSPD_Gvn*0.1f;
			gSysCtlVal.TDR = gSysCtlVal.TDR_Gvn*0.1f;
			gSysCtlVal.MDR = gSysCtlVal.MDR_Gvn*0.1f;
			gSysCtlVal.BDR = gSysCtlVal.BDR_Gvn*0.1f;
			gSysCtlVal.WDR = gSysCtlVal.WDR_Gvn*0.001f;
			gSysCtlVal.JDR = gSysCtlVal.JDR_Gvn*0.001f;
			gSysCtlVal.JANG = gSysCtlVal.JANG_Gvn;


			//卷绕
			gSysCtlVal.JR_Xspd = gSysCtlVal.XSPD/gSysCtlVal.JDR;
			gSysCtlVal.JR_Spd = gSysCtlVal.JR_Xspd*JR_Cn;
			gSysCtlVal.FreGvn[VFD_JR]= gSysCtlVal.JR_Spd*JR_GEAR*JR_HzPR;
			//摩擦辊罗拉
			gSysCtlVal.CW_Xspd = gSysCtlVal.XSPD;
			gSysCtlVal.CW_Spd = gSysCtlVal.CW_Xspd*CW_Cn;
			
			//前罗拉
			gSysCtlVal.LLF_Xspd = gSysCtlVal.CW_Xspd/gSysCtlVal.WDR;
			gSysCtlVal.LLF_Spd = gSysCtlVal.LLF_Xspd*LLF_Cn;
			gSysCtlVal.FreGvn[VFD_LLF]= gSysCtlVal.LLF_Spd*LLF_GEAR*LLF_HzPR;
			//中罗拉
			gSysCtlVal.LLM_Xspd = gSysCtlVal.CW_Xspd/gSysCtlVal.MDR;
			gSysCtlVal.LLM_Spd = gSysCtlVal.LLM_Xspd*LLM_Cn;
			gSysCtlVal.FreGvn[VFD_LLM]= gSysCtlVal.LLM_Spd*LLM_GEAR*LLM_HzPR;
			//第4 罗拉
			gSysCtlVal.LL4_Xspd = gSysCtlVal.CW_Xspd/gSysCtlVal.TDR;
			gSysCtlVal.LL4_Spd = gSysCtlVal.LL4_Xspd*LL4_Cn;
			//第3 罗拉
			gSysCtlVal.LL3_Xspd = gSysCtlVal.LL4_Xspd*gSysCtlVal.BDR;
			gSysCtlVal.LL3_Spd = gSysCtlVal.LL3_Xspd*LL3_Cn;

			//横动
			temp_f =   gSysPar.JANG*0.0087266461111111f;//0.5f*gSysCtlVal.JANG*PI/180;//
			temp_f = tan(temp_f);
			gSysCtlVal.HD_Xspd = gSysCtlVal.JR_Xspd*temp_f;
			gSysCtlVal.HD_Spd = 0.5f*gSysCtlVal.HD_Xspd*HD_LENn;//横动电机每转一圈，导纱一次来回
			gSysCtlVal.HD_Fre = gSysCtlVal.HD_Spd*HD_GEAR*HD_HzPR;
			gSysCtlVal.FreGvn[VFD_HD] = gSysCtlVal.HD_Fre;
			gSysCtlVal.FD_Rre = gSysCtlVal.HD_Fre*gSysPar.FD_Rto*0.001f;

			gSysCtlVal.FD_Sts = 0;


		}


		if(gSysCtlVal.MFJ_Fre_Gvn != gSysPar.MFJ_Fre)
		{
			//主风机
			gSysCtlVal.MFJ_Fre_Gvn = gSysPar.MFJ_Fre;
			gSysCtlVal.FreGvn[VFD_MFJ]= gSysPar.MFJ_Fre;
			gSysCtlVal.Son[VFD_MFJ] = 1;


		}

		if(gSysCtlVal.SFJ_Fre_Gvn != gSysPar.SFJ_Fre)
		{
			//副风机
			gSysCtlVal.SFJ_Fre_Gvn = gSysPar.SFJ_Fre;
			gSysCtlVal.FreGvn[VFD_SFJ]= gSysPar.SFJ_Fre;
			gSysCtlVal.Son[VFD_SFJ] = 1;

		}




		if(gSysCtlVal.FD_Sts ==0 && gVfdCom.Mxx[VFD_HD].Fre_hz == gSysCtlVal.FreGvn[VFD_HD])
		{
			gSysCtlVal.FD_Sts = 1;
			gSysCtlVal.FD_Ticker = 0;
		}
		else
		{

			gSysCtlVal.FD_Rre = gSysCtlVal.HD_Fre*gSysPar.FD_Rto*0.001f;
			gSysCtlVal.FD_HT = gSysPar.FD_HT*100;
			gSysCtlVal.FD_LT = gSysPar.FD_LT*100;
		
			if(gSysCtlVal.FD_Ticker < gSysCtlVal.FD_HT)
			{
				gSysCtlVal.FreGvn[VFD_HD] = gSysCtlVal.HD_Fre;
			}
			else if(gSysCtlVal.FD_Ticker < gSysCtlVal.FD_HT+gSysCtlVal.FD_LT)
			{
				if(gSysCtlVal.HD_Fre >= gSysCtlVal.FD_Rre)
					gSysCtlVal.FreGvn[VFD_HD] = gSysCtlVal.HD_Fre - gSysCtlVal.FD_Rre;
			}
			else
			{
				gSysCtlVal.FD_Ticker = 0;
			}
			gSysCtlVal.FD_Ticker++;
		}
	}




	if(BT_STOP)
	{
		if(stop_cnt >=10)
		{
			gSysCtlVal.FreGvn[VFD_LLM] = 0;
			gSysCtlVal.FreGvn[VFD_LLF] = 0;
			gSysCtlVal.FreGvn[VFD_HD] = 0;
			gSysCtlVal.FreGvn[VFD_JR] = 0;
			gSysCtlVal.FreGvn[VFD_MFJ] = 0;
			gSysCtlVal.FreGvn[VFD_SFJ] = 0;
			gSysCtlVal.FreGvn[VFD_PG] = 0;
			
			gSysCtlVal.Son[VFD_LLM] = 0;
			gSysCtlVal.Son[VFD_LLF] = 0;
			gSysCtlVal.Son[VFD_HD] = 0;
			gSysCtlVal.Son[VFD_JR] = 0;
			gSysCtlVal.Son[VFD_MFJ] = 0;
			gSysCtlVal.Son[VFD_SFJ] = 0;
			gSysCtlVal.Son[VFD_PG] = 0;
			
			Sys_Logic_Ptr = &sys_logic_wait;
		}
		else
		{
			stop_cnt++;
		}
	}
	else
	{
		stop_cnt = 0;
	}



	//变频器输出
	_vfd_out();
	
	START_LAMP(1);
	STOP_LAMP(0);

}


// 1K
void sys_logic_test(void)
{
	static u8 psr = 0;
	gSysCtlVal.Sts = STS_TEST;

	psr++;
	if(psr >= 10)
		psr = 0;

	//变频器测试
	if(psr == 0)
	{
		//修改频率
		if(gSysCtlVal.TestFre1 != gSysCtlVal.TestFre1Bk)
		{
			gVfdCom.REGxx[0].Fre_hz = gSysCtlVal.TestFre1;
			gVfdCom.RegWriteFlag[0].bit.Fre_hz = 1;

			gSysCtlVal.TestFre1Bk = gSysCtlVal.TestFre1;
		}
		//启动
		if(gSysCtlVal.TestCtl1.bit.ctl0 && gSysCtlVal.TestCtl1Bk.bit.ctl0 == 0)
		{
			
			gVfdCom.REGxx[0].CMD.bit.FWD =1;
			gVfdCom.REGxx[0].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[0].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl0 = 1;
		}
		//停止
		if(gSysCtlVal.TestCtl1.bit.ctl0 == 0 && gSysCtlVal.TestCtl1Bk.bit.ctl0 == 1)
		{
			gVfdCom.REGxx[0].CMD.bit.FWD =0;
			gVfdCom.REGxx[0].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[0].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl0 = 0;
		}

		//修改频率
		if(gSysCtlVal.TestFre2 != gSysCtlVal.TestFre2Bk)
		{
			gVfdCom.REGxx[1].Fre_hz = gSysCtlVal.TestFre2;
			gVfdCom.RegWriteFlag[1].bit.Fre_hz = 1;

			gSysCtlVal.TestFre2Bk = gSysCtlVal.TestFre2;
		}
		//启动
		if(gSysCtlVal.TestCtl1.bit.ctl1 && gSysCtlVal.TestCtl1Bk.bit.ctl1 == 0)
		{
			
			gVfdCom.REGxx[1].CMD.bit.FWD =1;
			gVfdCom.REGxx[1].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[1].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl1 = 1;
		}
		//停止
		if(gSysCtlVal.TestCtl1.bit.ctl1 == 0 && gSysCtlVal.TestCtl1Bk.bit.ctl1 == 1)
		{
			gVfdCom.REGxx[1].CMD.bit.FWD =0;
			gVfdCom.REGxx[1].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[1].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl1 = 0;
		}

		//修改频率
		if(gSysCtlVal.TestFre3 != gSysCtlVal.TestFre3Bk)
		{
			gVfdCom.REGxx[2].Fre_hz = gSysCtlVal.TestFre3;
			gVfdCom.RegWriteFlag[2].bit.Fre_hz = 1;

			gSysCtlVal.TestFre3Bk = gSysCtlVal.TestFre3;
		}
		//启动
		if(gSysCtlVal.TestCtl1.bit.ctl2 && gSysCtlVal.TestCtl1Bk.bit.ctl2 == 0)
		{
			
			gVfdCom.REGxx[2].CMD.bit.FWD =1;
			gVfdCom.REGxx[2].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[2].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl2 = 1;
		}
		//停止
		if(gSysCtlVal.TestCtl1.bit.ctl2 == 0 && gSysCtlVal.TestCtl1Bk.bit.ctl2 == 1)
		{
			gVfdCom.REGxx[2].CMD.bit.FWD =0;
			gVfdCom.REGxx[2].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[2].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl2 = 0;
		}

		//修改频率
		if(gSysCtlVal.TestFre4 != gSysCtlVal.TestFre4Bk)
		{
			gVfdCom.REGxx[3].Fre_hz = gSysCtlVal.TestFre4;
			gVfdCom.RegWriteFlag[3].bit.Fre_hz = 1;

			gSysCtlVal.TestFre4Bk = gSysCtlVal.TestFre4;
		}
		//启动
		if(gSysCtlVal.TestCtl1.bit.ctl3 && gSysCtlVal.TestCtl1Bk.bit.ctl3 == 0)
		{
			
			gVfdCom.REGxx[3].CMD.bit.FWD =1;
			gVfdCom.REGxx[3].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[3].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl3 = 1;
		}
		//停止
		if(gSysCtlVal.TestCtl1.bit.ctl3 == 0 && gSysCtlVal.TestCtl1Bk.bit.ctl3 == 1)
		{
			gVfdCom.REGxx[3].CMD.bit.FWD =0;
			gVfdCom.REGxx[3].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[3].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl3 = 0;
		}

		//修改频率
		if(gSysCtlVal.TestFre5 != gSysCtlVal.TestFre5Bk)
		{
			gVfdCom.REGxx[4].Fre_hz = gSysCtlVal.TestFre5;
			gVfdCom.RegWriteFlag[4].bit.Fre_hz = 1;

			gSysCtlVal.TestFre5Bk = gSysCtlVal.TestFre5;
		}
		//启动
		if(gSysCtlVal.TestCtl1.bit.ctl4 && gSysCtlVal.TestCtl1Bk.bit.ctl4 == 0)
		{
			
			gVfdCom.REGxx[4].CMD.bit.FWD =1;
			gVfdCom.REGxx[4].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[4].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl4 = 1;
		}
		//停止
		if(gSysCtlVal.TestCtl1.bit.ctl4 == 0 && gSysCtlVal.TestCtl1Bk.bit.ctl4 == 1)
		{
			gVfdCom.REGxx[4].CMD.bit.FWD =0;
			gVfdCom.REGxx[4].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[4].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl4 = 0;
		}

		//修改频率
		if(gSysCtlVal.TestFre6 != gSysCtlVal.TestFre6Bk)
		{
			gVfdCom.REGxx[5].Fre_hz = gSysCtlVal.TestFre6;
			gVfdCom.RegWriteFlag[5].bit.Fre_hz = 1;

			gSysCtlVal.TestFre6Bk = gSysCtlVal.TestFre6;
		}
		//启动
		if(gSysCtlVal.TestCtl1.bit.ctl5 && gSysCtlVal.TestCtl1Bk.bit.ctl5 == 0)
		{
			
			gVfdCom.REGxx[5].CMD.bit.FWD =1;
			gVfdCom.REGxx[5].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[5].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl5 = 1;
		}
		//停止
		if(gSysCtlVal.TestCtl1.bit.ctl5 == 0 && gSysCtlVal.TestCtl1Bk.bit.ctl5 == 1)
		{
			gVfdCom.REGxx[5].CMD.bit.FWD =0;
			gVfdCom.REGxx[5].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[5].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl5 = 0;
		}

		//修改频率
		if(gSysCtlVal.TestFre7 != gSysCtlVal.TestFre7Bk)
		{
			gVfdCom.REGxx[6].Fre_hz = gSysCtlVal.TestFre7;
			gVfdCom.RegWriteFlag[6].bit.Fre_hz = 1;

			gSysCtlVal.TestFre7Bk = gSysCtlVal.TestFre7;
		}
		//启动
		if(gSysCtlVal.TestCtl1.bit.ctl6 && gSysCtlVal.TestCtl1Bk.bit.ctl6 == 0)
		{
			
			gVfdCom.REGxx[6].CMD.bit.FWD =1;
			gVfdCom.REGxx[6].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[6].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl6 = 1;
		}
		//停止
		if(gSysCtlVal.TestCtl1.bit.ctl6 == 0 && gSysCtlVal.TestCtl1Bk.bit.ctl6 == 1)
		{
			gVfdCom.REGxx[6].CMD.bit.FWD =0;
			gVfdCom.REGxx[6].CMD.bit.REV =0;
			gVfdCom.RegWriteFlag[6].bit.CMD = 1;

			gSysCtlVal.TestCtl1Bk.bit.ctl6 = 0;
		}

	}
	//输出口测试
	else if(psr == 1)
	{
		gSysHard.TestOutFlag = 1;
		gSysHard.TestOut1.All =  (gSysCtlVal.TestCtl3.all<<8) +gSysCtlVal.TestCtl2.all;
		gSysHard.TestOut2.All =  (gSysCtlVal.TestCtl5.all<<8) +gSysCtlVal.TestCtl4.all;
		gSysHard.TestOut3.All =  gSysCtlVal.TestCtl6.all;
	}

	

	if(gSysCtlVal.TestMode == 0)
	{

		gVfdCom.REGxx[VFD_LLM].Fre_hz = gSysCtlVal.FreGvn[VFD_LLM];
		gVfdCom.RegWriteFlag[VFD_LLM].bit.Fre_hz = 1;
		gVfdCom.REGxx[VFD_LLM].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_LLM].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_LLM].bit.CMD = 1;

		gVfdCom.REGxx[VFD_LLF].Fre_hz = gSysCtlVal.FreGvn[VFD_LLF];
		gVfdCom.RegWriteFlag[VFD_LLF].bit.Fre_hz = 1;
		gVfdCom.REGxx[VFD_LLF].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_LLF].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_LLF].bit.CMD = 1;

		gVfdCom.REGxx[VFD_HD].Fre_hz = gSysCtlVal.FreGvn[VFD_HD];
		gVfdCom.RegWriteFlag[VFD_HD].bit.Fre_hz = 1;
		gVfdCom.REGxx[VFD_HD].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_HD].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_HD].bit.CMD = 1;

		gVfdCom.REGxx[VFD_JR].Fre_hz = gSysCtlVal.FreGvn[VFD_JR];
		gVfdCom.RegWriteFlag[VFD_JR].bit.Fre_hz = 1;
		gVfdCom.REGxx[VFD_JR].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_JR].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_JR].bit.CMD = 1;

		gVfdCom.REGxx[VFD_MFJ].Fre_hz = gSysCtlVal.FreGvn[VFD_MFJ];
		gVfdCom.RegWriteFlag[VFD_MFJ].bit.Fre_hz = 1;
		gVfdCom.REGxx[VFD_MFJ].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_MFJ].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_MFJ].bit.CMD = 1;

		gVfdCom.REGxx[VFD_SFJ].Fre_hz = gSysCtlVal.FreGvn[VFD_SFJ];
		gVfdCom.RegWriteFlag[VFD_SFJ].bit.Fre_hz = 1;
		gVfdCom.REGxx[VFD_SFJ].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_SFJ].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_SFJ].bit.CMD = 1;

		gVfdCom.REGxx[VFD_PG].Fre_hz = gSysCtlVal.FreGvn[VFD_PG];
		gVfdCom.RegWriteFlag[VFD_PG].bit.Fre_hz = 1;
		gVfdCom.REGxx[VFD_PG].CMD.bit.FWD =0;
		gVfdCom.REGxx[VFD_PG].CMD.bit.REV =0;
		gVfdCom.RegWriteFlag[VFD_PG].bit.CMD = 1;


	
		gSysHard.TestOutFlag = 0;
		Sys_Logic_Ptr = &sys_logic_wait;
	}
}

