#include "spi.h"

//////////////////////////////////////////////////////////////////////////////////	 
////////////////////////////////////////////////////////////////////////////////// 	  
 

//以下是SPI模块的初始化代码，配置成主机模式，访问SD Card/W25X16/24L01/JF24C							  
//SPI口初始化
//这里针是对SPI2的初始化

//SPI1初始化


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

//SPI 速度设置函数
//SpeedSet:0~7
//SPI速度=fAPB2/2^(SpeedSet+1)
//APB2时钟一般为72Mhz
void spi_set_speed(u8 speed)
{
	SPI1->CR1&=0XFFC7; 
	SPI1->CR1|=speed;
	SPI_Cmd(SPI1,ENABLE);	   
} 
//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节

u8 spi_readwrite_byte(u8 tdata)
{		
	u8 retry=0;				 	
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) == RESET) //检查指定的SPI标志位设置与否:发送缓存空标志位
	{
		retry++;
		if(retry>200)return 0;
	}			  
	SPI_I2S_SendData(SPI1, tdata); //通过外设SPIx发送一个数据
	retry=0;

	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) == RESET) //检查指定的SPI标志位设置与否:接受缓存非空标志位
	{
		retry++;
		if(retry>200)return 0;
	}	  						    
	return SPI_I2S_ReceiveData(SPI1); //返回通过SPIx最近接收的数据					    
}






























