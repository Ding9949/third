#ifndef __SPI_H
#define __SPI_H

#include "stm32f4xx.h"
#include "gpio.h"  


#define SPI1_CLK                       RCC_APB2Periph_SPI1

#define SPI_SCK PB3
#define SPI_MISO PB4
#define SPI_MOSI PB5
#define SPI_CS PA6
			 
#define SPI1_CS PORTout(SPI_CS)  //选中FLASH	
										 
void spi_init(void);			 //初始化SPI1口
void spi_set_speed(u8 speed); //设置SPI1速度  		
u8 spi_readwrite_byte(u8 tdata); //SPI1总线读写一个字节


#endif

