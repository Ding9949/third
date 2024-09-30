#include "fsmc.h"


const static uint32_t fsmc_norsram_bank[4] = 
{
	FSMC_Bank1_NORSRAM1,
	FSMC_Bank1_NORSRAM2,
	FSMC_Bank1_NORSRAM3,
	FSMC_Bank1_NORSRAM4
};

const static uint32_t fsmc_norsram_addr[4] = 
{
	FSMC_NORSRAM1_ADDR,
	FSMC_NORSRAM2_ADDR,
	FSMC_NORSRAM3_ADDR,
	FSMC_NORSRAM4_ADDR
};

const static uint8_t fsmc_norsram_ne[4] = 
{
	FSMC_NE1,
	FSMC_NE2,
	FSMC_NE3,
	FSMC_NE4
};

const static uint32_t fsmc_nand_bank[2] = 
{
	FSMC_Bank2_NAND,
	FSMC_Bank3_NAND
};

const static uint8_t fsmc_nand_int[2] = 
{
	FSMC_INT2,
	FSMC_INT3,
};

const static uint8_t fsmc_nand_nce[2] = 
{
	FSMC_NCE2,
	FSMC_NCE3,
};


void fsmc_init(uint8_t mode, uint8_t bank, void* timing_param)
{

	// Enable FSMC clock 
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE); 

	// config share signal gpio
	gpio_config(FSMC_D0, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D1, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D2, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D3, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D4, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D5, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D6, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D7, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D8, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D9, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D10, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D11, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D12, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D13, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D14, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_D15, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);

	gpio_config(FSMC_A0, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A1, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A2, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A3, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A4, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A5, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A6, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A7, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A8, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A9, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A10, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A11, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A12, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A13, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A14, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A15, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A16, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A17, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A18, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A19, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A20, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A21, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A22, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_A23, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);

	gpio_config(FSMC_NOE, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_NWE, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
	gpio_config(FSMC_NWAIT, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);

	if(mode == FSMC_MODE_NORSRAM)
	{
		FSMC_NORSRAMInitTypeDef  FSMC_NORSRAMInitStructure;
		FSMC_NORSRAMTimingInitTypeDef*  p = (FSMC_NORSRAMTimingInitTypeDef*)timing_param;
		
		//config norsram signal gpio
		gpio_config(fsmc_norsram_ne[bank], GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);

		//gpio_config(FSMC_NL, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);

		gpio_config(FSMC_NBL0, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
		gpio_config(FSMC_NBL0, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
		
		//gpio_config(FSMC_CLK, GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);
		
		/*-- FSMC Configuration ------------------------------------------------------*/



		FSMC_NORSRAMInitStructure.FSMC_Bank = fsmc_norsram_bank[bank];
		FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable;
		FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_PSRAM;
		FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b;
		FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode = FSMC_BurstAccessMode_Disable;
		FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait = FSMC_AsynchronousWait_Disable;  
		FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity = FSMC_WaitSignalPolarity_Low;
		FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable;
		FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive = FSMC_WaitSignalActive_BeforeWaitState;
		FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
		FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable;
		FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Disable;
		FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable;
		FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct = p;
		FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct = p;

		FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure); 

		// Enable FSMC Bank1_SRAMx Bank 
		FSMC_NORSRAMCmd(fsmc_norsram_bank[bank], ENABLE); 
	}

	else if( mode == FSMC_MODE_NAND)
	{
		FSMC_NANDInitTypeDef FSMC_NANDInitStructure;
		FSMC_NAND_PCCARDTimingInitTypeDef*  p = (FSMC_NAND_PCCARDTimingInitTypeDef*)timing_param;
		
		gpio_config(fsmc_nand_int[bank], GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
		gpio_config(fsmc_nand_nce[bank], GPIO_Mode_AF, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, GPIO_AF_FSMC);

		/*--------------FSMC 总线 存储器参数配置------------------------------*/

		FSMC_NANDInitStructure.FSMC_Bank = fsmc_nand_bank[bank]; //使用FSMC BANKx
		FSMC_NANDInitStructure.FSMC_Waitfeature = FSMC_Waitfeature_Enable; //使能FSMC的等待功能
		FSMC_NANDInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_8b; //NAND Flash的数据宽度为8位
		FSMC_NANDInitStructure.FSMC_ECC = FSMC_ECC_Enable;                  //使能ECC特性
		FSMC_NANDInitStructure.FSMC_ECCPageSize = FSMC_ECCPageSize_2048Bytes; //ECC页大小2048
		FSMC_NANDInitStructure.FSMC_TCLRSetupTime = 0x00;             
		FSMC_NANDInitStructure.FSMC_TARSetupTime = 0x00;
		FSMC_NANDInitStructure.FSMC_CommonSpaceTimingStruct = p;
		FSMC_NANDInitStructure.FSMC_AttributeSpaceTimingStruct = p;

		FSMC_NANDInit(&FSMC_NANDInitStructure);

		/*!使能FSMC BANK2 */
		FSMC_NANDCmd(fsmc_nand_bank[bank], ENABLE);

	}

}

void fsmc_norsram_write_buffer(uint8_t bank, uint16_t* pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite)
{
	for (; NumHalfwordToWrite != 0; NumHalfwordToWrite--) /* while there is data to write */
	{
		/* Transfer data to the memory */
		*(uint16_t *) (fsmc_norsram_addr[bank] + WriteAddr) = *pBuffer++;

		/* Increment the address*/
		WriteAddr += 2;
	}
}

void fsmc_norsram_read_buffer(uint8_t bank, uint16_t* pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead)
{
	for (; NumHalfwordToRead != 0; NumHalfwordToRead--) /* while there is data to read */
	{
		/* Read a half-word from the memory */
		*pBuffer++ = *(__IO uint16_t*) (fsmc_norsram_addr[bank] + ReadAddr);

		/* Increment the address*/
		ReadAddr += 2;
	}
}




