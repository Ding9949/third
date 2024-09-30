#include "drv_sci.h"


void drv_sci_a_init(void)
{
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd (SCI_A_RCC_Periph ,ENABLE);

	gpio_config(SCI_A_TXD_PORT, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_USART1);
	gpio_config(SCI_A_RXD_PORT, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_USART1);
	gpio_config(SCI_A_DE_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_DOWN, 0);

	SCI_A_DE_CTL(USART_BUS_RXD);

	
	USART_DeInit(SCI_A_USART);
	USART_InitStructure.USART_BaudRate = SCI_A_BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_2;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_InitStructure.USART_Mode = USART_Mode_Rx| USART_Mode_Tx;
	/* Configure USART1 basic and asynchronous paramters */
	USART_Init(SCI_A_USART, &USART_InitStructure);

	USART_ITConfig(SCI_A_USART, USART_IT_RXNE, ENABLE);
	USART_ITConfig(SCI_A_USART, USART_IT_TC, ENABLE);
	/***************************************************/
	USART_Cmd(SCI_A_USART, ENABLE);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}


void drv_sci_b_init(void)
{
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	
	RCC_APB1PeriphClockCmd (SCI_B_RCC_Periph ,ENABLE);

	gpio_config(SCI_B_TXD_PORT, GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_AF_USART3);
	gpio_config(SCI_B_RXD_PORT, GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_AF_USART3);
	gpio_config(SCI_B_DE_PORT, GPIO_Mode_OUT, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_DOWN, 0);
	
	SCI_B_DE_CTL(USART_BUS_RXD);

	
	USART_DeInit(SCI_B_USART);
	USART_InitStructure.USART_BaudRate = SCI_B_BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_2;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_InitStructure.USART_Mode = USART_Mode_Rx| USART_Mode_Tx;
	/* Configure USART1 basic and asynchronous paramters */
	USART_Init(SCI_B_USART, &USART_InitStructure);

	USART_ITConfig(SCI_B_USART, USART_IT_RXNE, ENABLE);
	//USART_ITConfig(SCI_B_USART, USART_IT_TC, ENABLE);
	/***************************************************/
	USART_Cmd(SCI_B_USART, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


void drv_sci_c_init(void)
{
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef  NVIC_InitStructure;
	
	
	RCC_APB2PeriphClockCmd (SCI_C_RCC_Periph ,ENABLE);

	gpio_config(SCI_C_TXD_PORT, GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_AF_USART6);
	gpio_config(SCI_C_RXD_PORT, GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_AF_USART6);
	gpio_config(SCI_C_DE_PORT, GPIO_Mode_OUT, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	
	SCI_C_DE_CTL(USART_BUS_RXD);

	
	USART_DeInit(SCI_C_USART);
	USART_InitStructure.USART_BaudRate = SCI_C_BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	
	USART_InitStructure.USART_Mode = USART_Mode_Rx| USART_Mode_Tx;
	/* Configure USART1 basic and asynchronous paramters */
	USART_Init(SCI_C_USART, &USART_InitStructure);

	USART_ITConfig(SCI_C_USART, USART_IT_RXNE, ENABLE);
	USART_ITConfig(SCI_C_USART, USART_IT_TC, ENABLE);
	/***************************************************/
	USART_Cmd(SCI_C_USART, ENABLE);

	NVIC_InitStructure.NVIC_IRQChannel = USART6_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


void drv_sci_init(void)
{
	drv_sci_a_init();
	drv_sci_b_init();
	drv_sci_c_init();
}





