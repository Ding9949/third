#include "spi.h"

//////////////////////////////////////////////////////////////////////////////////	 
////////////////////////////////////////////////////////////////////////////////// 	  
 

//������SPIģ��ĳ�ʼ�����룬���ó�����ģʽ������SD Card/W25X16/24L01/JF24C							  
//SPI�ڳ�ʼ��
//�������Ƕ�SPI2�ĳ�ʼ��

//SPI1��ʼ��


void spi_init(void)
{
	SPI_InitTypeDef  SPI_InitStructure;

	// gpio config
	gpio_config(SPI_CS, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(SPI_SCK, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_AF_SPI1);
	gpio_config(SPI_MISO, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_AF_SPI1);
	gpio_config(SPI_MOSI, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIO_AF_SPI1);
	
	/* Deselect the FLASH: Chip Select high */
	SPI1_CS = 1;

	/* SPI1 configuration */
	// SPI1 Periph clock enable 
	RCC_APB2PeriphClockCmd(SPI1_CLK, ENABLE);
	
	// W25X16: data input on the DIO pin is sampled on the rising edge of the CLK. 
	// Data on the DO and DIO pins are clocked out on the falling edge of CLK.
	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_High;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_2Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1, &SPI_InitStructure);

	/* Enable SPI1  */
	SPI_Cmd(SPI1, ENABLE);




}

//SPI �ٶ����ú���
//SpeedSet:0~7
//SPI�ٶ�=fAPB2/2^(SpeedSet+1)
//APB2ʱ��һ��Ϊ72Mhz
void spi_set_speed(u8 speed)
{
	SPI1->CR1&=0XFFC7; 
	SPI1->CR1|=speed;
	SPI_Cmd(SPI1,ENABLE);	   
} 
//SPIx ��дһ���ֽ�
//TxData:Ҫд����ֽ�
//����ֵ:��ȡ�����ֽ�

u8 spi_readwrite_byte(u8 tdata)
{		
	u8 retry=0;				 	
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //���ָ����SPI��־λ�������:���ͻ���ձ�־λ
	{
		retry++;
		if(retry>200)return 0;
	}			  
	SPI_I2S_SendData(SPI1, tdata); //ͨ������SPIx����һ������
	retry=0;

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) //���ָ����SPI��־λ�������:���ܻ���ǿձ�־λ
	{
		retry++;
		if(retry>200)return 0;
	}	  						    
	return SPI_I2S_ReceiveData(SPI1); //����ͨ��SPIx������յ�����					    
}






























