/*
Data: 2017-6-17
Autor:  wuych
*/
#include "drv_flash.h"


u16 STMFLASH_BUF[STM_SECTOR_SIZE>>1];//�����2K�ֽ�


void FLASH_Erase(u32 PageAddr)
{
	FLASH_Unlock();
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
	FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);


	if(PageAddr >= ADDR_FLASH_SECTOR_0 && PageAddr < ADDR_FLASH_SECTOR_1)
		FLASH_EraseSector(FLASH_Sector_0, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_1 && PageAddr < ADDR_FLASH_SECTOR_2)
		FLASH_EraseSector(FLASH_Sector_1, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_2 && PageAddr < ADDR_FLASH_SECTOR_3)
		FLASH_EraseSector(FLASH_Sector_2, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_3 && PageAddr < ADDR_FLASH_SECTOR_4)
		FLASH_EraseSector(FLASH_Sector_3, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_4 && PageAddr < ADDR_FLASH_SECTOR_5)
		FLASH_EraseSector(FLASH_Sector_4, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_5 && PageAddr < ADDR_FLASH_SECTOR_6)
		FLASH_EraseSector(FLASH_Sector_5, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_6 && PageAddr < ADDR_FLASH_SECTOR_7)
		FLASH_EraseSector(FLASH_Sector_6, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_7 && PageAddr < ADDR_FLASH_SECTOR_8)
		FLASH_EraseSector(FLASH_Sector_7, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_8 && PageAddr < ADDR_FLASH_SECTOR_9)
		FLASH_EraseSector(FLASH_Sector_8, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_9 && PageAddr < ADDR_FLASH_SECTOR_10)
		FLASH_EraseSector(FLASH_Sector_9, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_10 && PageAddr < ADDR_FLASH_SECTOR_11)
		FLASH_EraseSector(FLASH_Sector_10, VoltageRange_3);
	else if(PageAddr >= ADDR_FLASH_SECTOR_11)
		FLASH_EraseSector(FLASH_Sector_11, VoltageRange_3);

	
	FLASH_Lock();
}



//��ָ����ַ��ʼ����ָ�����ȵ�����
//ReadAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��
void FLASH_Read(u32 ReadAddr,u16 *pBuffer,u16 NumToRead)   	
{
	u16 i;
	for(i=0;i<NumToRead;i++)
	{
		pBuffer[i]=FLASH_ReadHalfWord(ReadAddr);//��ȡ2���ֽ�.
		ReadAddr+=2;//ƫ��2���ֽ�.	
	}
}

//������д��
//WriteAddr:��ʼ��ַ
//pBuffer:����ָ��
//NumToWrite:����(16λ)��   
void FLASH_Write_NoCheck(u32 WriteAddr,u16 *pBuffer,u16 NumToWrite)   
{ 			 		 
	u16 i;
	FLASH_Unlock();
	
	FLASH_ClearFlag(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR | 
	FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR | FLASH_FLAG_PGSERR);


	for(i=0;i<NumToWrite;i++)
	{
		FLASH_ProgramHalfWord(WriteAddr,pBuffer[i]);
	    WriteAddr+=2;//��ַ����2.
	}  

	FLASH_Lock();

} 



