/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-April-2012
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_it.h"
#include "sys_include.h"
/** @addtogroup STM32F4xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup IOToggle
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
//void PendSV_Handler(void)
//{
//}


#if 0
/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{

	

}
#endif


//定时器3中断服务程序
void TIM8_UP_TIM13_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM8, TIM_IT_Update))
	{
		TIM_ClearITPendingBit(TIM8,TIM_IT_Update);	
		main_isr();
	}
}

//PLS01 
void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_CC4) != RESET) 
	{
		TIM_ClearITPendingBit(TIM3, TIM_IT_CC4  );  
		// do something here....
		roller1_speed_isr();

	}   
}

//PLS02 
void TIM1_CC_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM1, TIM_IT_CC1) != RESET) 
	{
		TIM_ClearITPendingBit(TIM1, TIM_IT_CC1  );  
		// do something here....
		roller2_speed_isr();

	}   
}


//PLS03
void TIM2_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM2, TIM_IT_CC1) != RESET) 
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_CC1  );  
		// do something here....
		roller3_speed_isr();

	}   
}

//PLS04
void TIM4_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM4, TIM_IT_CC1) != RESET) 
	{
		TIM_ClearITPendingBit(TIM4, TIM_IT_CC1  );  
		// do something here....
		roller4_speed_isr();

	}   
}


// 屏
void USART1_IRQHandler(void)
{
	if (USART_GetITStatus(USART1, USART_IT_RXNE) != RESET) 
	{
		// do something here....
		#ifdef TEST_FLAG
		{
			u8 dat = USARTA_RXD();
			SCI_A_DE_CTL(USART_BUS_TXD);
			USARTA_TXD(dat);
			while(1)
			{
				if(USARTA_TXD_OK())
					break;
			}
			SCI_A_DE_CTL(USART_BUS_RXD);
			
		}
		#else
		u8 dat = USARTA_RXD();
		dis_com_rx(dat);
		#endif
		//USART_ClearITPendingBit(USART1, USART_IT_RXNE  );  

	}   
	else if(USART_GetITStatus(USART1, USART_IT_TC))
	{
		USART_ClearITPendingBit(USART1, USART_IT_TC);   // 清发送完成状态
		if(gDisCom.TxdFlag)
		{
			gDisCom.TxdCnt++;
			if(gDisCom.TxdCnt < gDisCom.TxdLen)
			{
				USARTA_TXD(gDisCom.TxdBuf[gDisCom.TxdCnt ]);
			}
			else
			{
				gDisCom.tx_ok ++;
				//状态恢复
				gDisCom.TxdFlag = 0;
				gDisCom.TxdSts = 0;
				gDisCom.RxdFlag = 0;
				gQsCom.RxdIndex = 0;	
				SCI_A_DE_CTL(USART_BUS_RXD);
			}
		}
	}
}

// 变频
void USART3_IRQHandler(void)
{
	if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) 
	{
		// do something here....
		#ifdef TEST_FLAG
		{
			u8 dat = USARTB_RXD();
			SCI_B_DE_CTL(USART_BUS_TXD);
			USARTB_TXD(dat);
			while(1)
			{
				if(USARTB_TXD_OK())
					break;
			}
			SCI_B_DE_CTL(USART_BUS_RXD);
			
		}
		#else
		vfd_com_isr();
		#endif
		
		//USART_ClearITPendingBit(USART3, USART_IT_RXNE  );  

	}   
}

// 清纱
void USART6_IRQHandler(void)
{
	if (USART_GetITStatus(USART6, USART_IT_RXNE) != RESET) 
	{
		// do something here.... 
		#ifdef TEST_FLAG
		{
			u8 dat = USARTC_RXD();
			SCI_C_DE_CTL(USART_BUS_TXD);
			USARTC_TXD(dat);
			while(1)
			{
				if(USARTC_TXD_OK())
					break;
			}
			SCI_C_DE_CTL(USART_BUS_RXD);
			
		}
		#else
		u8 dat = USARTC_RXD();
		qs_com_rx(dat);
		#endif
		//USART_ClearITPendingBit(USART6, USART_IT_RXNE  );  

	}   
	else if(USART_GetITStatus(USART6, USART_IT_TC))
	{
		USART_ClearITPendingBit(USART6, USART_IT_TC);   // 清发送完成状态
		if(gQsCom.TxdFlag)
		{
			gQsCom.TxdCnt++;
			if(gQsCom.TxdCnt < gQsCom.TxdLen)
			{
				USARTC_TXD(gQsCom.TxdBuf[gQsCom.TxdCnt ]);
			}
			else
			{
				gQsCom.tx_ok ++;
				//状态恢复
				gQsCom.TxdFlag = 0;
				gQsCom.TxdSts = 0;
				gQsCom.RxdFlag = 0;
				gQsCom.RxdIndex = 0;	
				SCI_C_DE_CTL(USART_BUS_RXD);
			}
		}
	}
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
