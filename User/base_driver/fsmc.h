#ifndef __fsmc_h
#define __fsmc_h

#include "stm32f4xx.h"
#include "gpio.h"

#define FSMC_NORSRAM1_ADDR  ((uint32_t)0x60000000) 
#define FSMC_NORSRAM2_ADDR  ((uint32_t)0x64000000) 
#define FSMC_NORSRAM3_ADDR  ((uint32_t)0x68000000) 
#define FSMC_NORSRAM4_ADDR  ((uint32_t)0x6c000000) 


#define FSMC_NAND1_ADDR    ((u32)0x70000000)
#define FSMC_NAND2_ADDR    ((u32)0x80000000)

#define FSMC_NAND1_INT PGin(6)
#define FSMC_NAND2_INT PGin(7)

enum {
	FSMC_MODE_NORSRAM = 0,
	FSMC_MODE_NAND,
	FSMC_MODE_PCCORD
};

enum {
	FSMC_NORSRAM1 = 0, 
	FSMC_NORSRAM2, 
	FSMC_NORSRAM3,
	FSMC_NORSRAM4
};

enum {
	FSMC_NAND1 = 0, 
	FSMC_NAND2
};

//share signal
#define FSMC_D0 PD14
#define FSMC_D1 PD15
#define FSMC_D2 PD0
#define FSMC_D3 PD1
#define FSMC_D4 PE7
#define FSMC_D5 PE8
#define FSMC_D6 PE9
#define FSMC_D7 PE10
#define FSMC_D8 PE11
#define FSMC_D9 PE12
#define FSMC_D10 PE13
#define FSMC_D11 PE14
#define FSMC_D12 PE15
#define FSMC_D13 PD8
#define FSMC_D14 PD9
#define FSMC_D15 PD10

#define FSMC_A0 PF0
#define FSMC_A1 PF1
#define FSMC_A2 PF2
#define FSMC_A3 PF3
#define FSMC_A4 PF4
#define FSMC_A5 PF5
#define FSMC_A6 PF12
#define FSMC_A7 PF13
#define FSMC_A8 PF14
#define FSMC_A9 PF15
#define FSMC_A10 PG0
#define FSMC_A11 PG1
#define FSMC_A12 PG2
#define FSMC_A13 PG3
#define FSMC_A14 PG4
#define FSMC_A15 PG5
#define FSMC_A16 PD11
#define FSMC_A17 PD12
#define FSMC_A18 PD13
#define FSMC_A19 PE3
#define FSMC_A20 PE4
#define FSMC_A21 PE5
#define FSMC_A22 PE6
#define FSMC_A23 PE2
#define FSMC_A24 PG13
#define FSMC_A25 PG14

#define FSMC_NOE PD4
#define FSMC_NWE PD5
#define FSMC_NWAIT PD6


// for nor/sram signal
#define FSMC_NE1 PD7
#define FSMC_NE2 PG9
#define FSMC_NE3 PG10
#define FSMC_NE4 PG12

#define FSMC_NL PB7

#define FSMC_NBL0 PE0
#define FSMC_NBL1 PE1

#define FSMC_CLK PD3

// for nand signal
#define FSMC_INT2 PG6
#define FSMC_INT3 PG7

#define FSMC_NCE2 PD7
#define FSMC_NCE3 PG9


// for pc card signal
#define FSMC_INTR PF10
#define FSMC_NCE4_1 PG10
#define FSMC_NCE4_2 PG11
#define FSMC_NIORD PF6
#define FSMC_NIOWR PF8
#define FSMC_NREG PF7
#define FSMC_CD PF9



void fsmc_init(uint8_t mode, uint8_t bank, void* timing_param);
void fsmc_norsram_write_buffer(uint8_t bank, uint16_t* pBuffer, uint32_t WriteAddr, uint32_t NumHalfwordToWrite);
void fsmc_norsram_read_buffer(uint8_t bank, uint16_t* pBuffer, uint32_t ReadAddr, uint32_t NumHalfwordToRead);

#endif
