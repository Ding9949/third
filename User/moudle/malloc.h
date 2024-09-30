#ifndef __MALLOC_H
#define __MALLOC_H

#include "stm32f4xx.h"



#define SRAMIN	0	//�ڲ��ڴ��
#define SRAMEX  1	//�ⲿ�ڴ��

#include "sys_conf.h"

//mem1�ڴ�����趨.mem1��ȫ�����ڲ�SRAM����
#define MEM1_BLOCK_SIZE			32  	  						//�ڴ���СΪ32�ֽ�
#if SRAM_TYPE == SRAMIN
#define MEM1_MAX_SIZE			1*1024   						//�������ڴ� 45K
#else
#define MEM1_MAX_SIZE			32  						//�������ڴ� 45K
#endif
#define MEM1_ALLOC_TABLE_SIZE	MEM1_MAX_SIZE/MEM1_BLOCK_SIZE 	//�ڴ���С

//mem2�ڴ�����趨.mem2���ڴ�ش����ⲿSRAM����,�����Ĵ����ڲ�SRAM����
#define MEM2_BLOCK_SIZE			32  	  						//�ڴ���СΪ32�ֽ�
#if SRAM_TYPE == SRAMEX
#define MEM2_MAX_SIZE			128*1024  						//�������ڴ� 256K
#else
#define MEM2_MAX_SIZE			32  						//�������ڴ� 128K
#endif
#define MEM2_ALLOC_TABLE_SIZE	MEM2_MAX_SIZE/MEM2_BLOCK_SIZE 	//�ڴ���С
		 
#if 0
//�ڴ���������
struct _m_mallco_dev
{
	void (*init)(u8);					//��ʼ��
	u8 (*perused)(u8);		  	    	//�ڴ�ʹ����
	u8 	*membase[2];					//�ڴ�� ����2��������ڴ�
	u16 *memmap[2]; 					//�ڴ����״̬��
	u8  memrdy[2]; 						//�ڴ�����Ƿ����
};
#else
typedef struct _malloc_dev_s
{
	void (*init)(u8);					//��ʼ��
	u8 (*perused)(u8);		  	    	//�ڴ�ʹ����
	u8 	*membase[2];					//�ڴ�� ����2��������ڴ�
	u16 *memmap[2]; 					//�ڴ����״̬��
	u8  memrdy[2]; 						//�ڴ�����Ƿ����
}malloc_dev_t;
#endif
//extern struct _m_mallco_dev mallco_dev;	 //��mallco.c���涨��

void mymemset(void *s,u8 c,u32 count);	 //�����ڴ�
void mymemcpy(void *des,void *src,u32 n);//�����ڴ� 

void mem_init(u8 memx);					 //�ڴ�����ʼ������(��/�ڲ�����)
u32 mem_malloc(u8 memx,u32 size);		 //�ڴ����(�ڲ�����)
u8 mem_free(u8 memx,u32 offset);		 //�ڴ��ͷ�(�ڲ�����)
u8 mem_perused(u8 memx);				 //����ڴ�ʹ����(��/�ڲ�����) 
////////////////////////////////////////////////////////////////////////////////
//�û����ú���
void myfree(u8 memx,void *ptr);  			//�ڴ��ͷ�(�ⲿ����)
void *mymalloc(u8 memx,u32 size);			//�ڴ����(�ⲿ����)
void *myrealloc(u8 memx,void *ptr,u32 size);//���·����ڴ�(�ⲿ����)
#endif













