/*
Data: 2017-6-17
Autor:  wuych
*/
#ifndef __drv_flash_h
#define __drv_flash_h


#include "sys_bsp.h"



#define FLASH_ZOOM_ALL 0
#define FLASH_ZOOM_BOOT 1
#define FLASH_ZOOM_APP 2
#define FLASH_ZOOM_PARAM 3
#define FLASH_ZOOM_MARK 4


#define FLASH_SIZE 0x40000 //256k
#define FLASH_BOOT_SIZE 0x8000 //32k
#define FLASH_MARK_SIZE 0x4000 // 16k
#define FLASH_APP_SIZE 0x30000 //192k
#define FLASH_PARAM_SIZE 0x4000 // 16k



#define FLASH_BASE_ADDR 0x08000000
#define FLASH_BOOT_ADDR FLASH_BASE_ADDR
#define FLASH_MARK_ADDR (FLASH_BOOT_ADDR+FLASH_BOOT_SIZE)
#define FLASH_APP_ADDR (FLASH_MARK_ADDR+FLASH_MARK_SIZE)
#define FLASH_PARAM_ADDR (FLASH_APP_ADDR+FLASH_APP_SIZE)


#define STM32_FLASH_SIZE 256 	 		//所选STM32的FLASH容量大小(单位为K)
#if STM32_FLASH_SIZE<256
#define STM_SECTOR_SIZE 1024 //字节
#else 
#define STM_SECTOR_SIZE	2048
#endif	

/* Base address of the Flash sectors  for stm32f4xx*/
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbytes */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbytes */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */

#define FLASH_ReadHalfWord(addr)  *(vu16*)addr
//#define FLASH_ProgramHalfWord(addr, data) *(vu16*)addr=data

void FLASH_Erase(u32 PageAddr);
void FLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead);
void FLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite);   



#endif
