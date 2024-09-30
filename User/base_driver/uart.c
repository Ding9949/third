/**
  ******************************************************************************
  * @file    uart.c 
  * @author  Wangbao Dev Team
  * @version V1.0.0
  * @date    07-10-2012
  * @brief   uart program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 
#include <stdio.h>
#include "uart.h"
#include "gpio.h"



void uart_init(void)
{
	USART_InitTypeDef USART_InitStructure;   
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); /* Enable UART clock */

	gpio_config(PA9, GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_USART1);
	gpio_config(PA10, GPIO_Mode_AF, GPIO_Speed_50MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_USART1);
	
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART1, &USART_InitStructure);	/* USART configuration */ 
	USART_Cmd(USART1, ENABLE); /* Enable USART */

	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel 						= USART1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority 	= 3; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority 			= 3; 
	NVIC_InitStructure.NVIC_IRQChannelCmd 					= ENABLE; 
	NVIC_Init(&NVIC_InitStructure); 
	 
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

}


void uart_getc(uint8_t* c)
{
	while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
	{
		*c = (uint8_t)USART1->DR & 0xFF;
	}
	/* Loop until the end of transmission */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
	{
	}

	
 }

int fputc(int ch, FILE *f)
{
	/* Place your implementation of fputc here */
	/* e.g. write a character to the USART */
	USART_SendData(USART1, (uint8_t) ch);

	/* Loop until the end of transmission */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
	{}

	return ch;
}

