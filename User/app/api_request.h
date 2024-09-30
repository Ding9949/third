#ifndef __api_request_h
#define __api_request_h

#include "stack.h"


#define MAX_REQUEST_NUM 100


typedef struct _request_s
{
	unsigned char cmd;  //0-取消  1-请求
	unsigned char ads;  //锭号
	unsigned long len_cur;//当前长度
	
	struct _request_s* prev;
	struct _request_s* next;
}request_t;





typedef struct _request_list_s
{
	unsigned short size;
	
	// 表存储空间
	stack_t stack;  
	request_t*pRequests;

	request_t* head;	// 表头
	unsigned short used;	// 表长度 	

}request_list_t;

extern request_t request_ad[MAX_REQUEST_NUM];
extern request_t request_jn[MAX_REQUEST_NUM];

extern request_list_t* request_list_ad;
extern request_list_t* request_list_jn;


int request_list_init(request_list_t** plist, unsigned char type);
int request_list_stack_init(request_list_t* list);
int request_list_create(request_list_t** plist, unsigned short size, request_t* buf);
int request_list_delete(request_list_t** plist);
int request_list_destroy(request_list_t* list);
int request_list_copy(request_list_t* des, request_list_t* src);
int request_list_add_request(request_list_t** plist, request_t request);
int request_list_del_request(request_list_t** plist, unsigned short ads);
request_t*  request_list_get_request(request_list_t** plist, unsigned short ads);



#endif
