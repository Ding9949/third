#include "sys_include.h"


request_t request_ad[MAX_REQUEST_NUM];
request_t request_jn[MAX_REQUEST_NUM];


request_list_t* request_list_ad = NULL;
request_list_t* request_list_jn = NULL;


int request_list_init(request_list_t** plist, unsigned char type)
{
	request_t* buf = NULL;

	if(plist == NULL)
		return 1;

	if(type == 0)
		buf = request_ad;
	else
		buf = request_jn;

	return request_list_create(plist, MAX_REQUEST_NUM, buf);
}

int request_list_stack_init(request_list_t* list)
{
	int err = 1;
	int i;

	if (list == NULL)
		return 1;
	
	list->head = NULL;
	err = create_stack(list->size, &list->stack);

	if(err == 0)
	{
		for( i = 0; i < list->size; i++ )
		{
			err = push_stack( &list->stack, ( void * ) &list->pRequests[i] );
			if(err)
			{
				delete_stack( &list->stack);
				break;
			}
		}

	}
	return err;
}



int request_list_create(request_list_t** plist, unsigned short size, request_t* buf)
{
	request_list_t* list = NULL;
	request_t* pRequests = NULL;

	if(size == 0 || plist == NULL)
		return 1;

	list = (request_list_t*)malloc(sizeof(request_list_t));
	if(list == NULL)
		return 1;
	memset(list, 0, sizeof(request_list_t));	


	if(buf == NULL)
	{
		free(list);
		return 1;
	}
	pRequests = buf;
	
	memset(pRequests, 0, size*sizeof(request_t));	
	list->pRequests = pRequests;
	list->size = size;
	if(request_list_stack_init(list))
	{
		free(list);
		return 1;
	}
	*plist = list;
	return 0;

}

int request_list_delete(request_list_t** plist)
{
	request_list_t* list = NULL;
	if(plist == NULL)
		return 1;
	list = *plist;
	if(list)
	{
		delete_stack( &list->stack);
		free(list);
	}
	*plist = NULL;
	return 0;	
}

int request_list_destroy(request_list_t* list)
{
	int i;

	if(list == NULL)
		return 1;

	list->stack.interator = 0;
	list->used = 0;
	list->head = NULL;
	for( i = 0; i < list->stack.size; i++ )
	{
		memset(&list->pRequests[i], 0, sizeof(request_t));
		push_stack( &list->stack, ( void * ) &list->pRequests[i] );
	}

	return 0;
}

int request_list_copy(request_list_t* des, request_list_t* src)
{
	request_t* cur = NULL;
	if(des == NULL || src == NULL)
		return 1;

	if(des->size < src->size)
		return 2;

	request_list_destroy(des);
	cur = src->head;
	while(cur)
	{
		request_list_add_request(&des, *cur);
		cur = cur->next;
	}

	return 0;	
}



//��ӵ�����ĩ��
int request_list_add_request(request_list_t** plist, request_t request)
{
	request_list_t* list = *plist;
	request_t* pNew = NULL;
	request_t* cur = NULL;
	request_t* next = NULL;
	int err = 1;

	if(plist == NULL || request.ads == 0)
		return 1;

		//�ռ䲻��
	if(list->used == list->size)
	{
		return 1;
	}

	//�����Ƿ���ads  ��ͬ�Ľڵ�

	cur = list->head;
	while(cur != NULL)
	{
		if(cur->ads == request.ads)
		{
			//�ҵ�������Ҫ����
			return 1;
		}
		//�ҵ�ĩ��
		if(cur->next == NULL)
			break;
		cur = cur->next;
	}
	
	

	//cur = list->head;
	if(NULL != ( pNew = ( request_t * )pop_stack( &list->stack)))
	{
		list->used ++;
		*pNew = request;

		if(cur == NULL)
		{
			//�嵽ͷ��
			list->head = pNew;

		}
		else
		{
			//�嵽ĩ��
			cur->next = pNew;
			pNew->prev = cur;
			pNew->next = NULL;	
		}


		return 0;

	}
	else
		return 1;
	
}

int request_list_del_request(request_list_t** plist, unsigned short ads)
{
	int err = 1;
	request_list_t* list = *plist;
	request_t* cur = NULL;
	request_t* prev = NULL;
	request_t* next = NULL;

	if(plist == NULL)
		return 1;


	cur = list->head;

	//�����
	if(cur ==NULL)
		return 1;

	while(cur->ads != ads)
	{
		//ĩ��δ�ҵ�
		if(cur->next == NULL)
			return 1;
		cur = cur->next;
	}

	//�ҵ���ͬ��
	list->used--;
	prev = cur->prev;
	next = cur->next;

	if(cur != list->head)
	{
		prev->next = next;
		if(next)
			next->prev = prev;
	}
	else
	{
		list->head = next;
		if(next!=NULL)
		{
			next->prev = NULL;
		}
	}
	err = push_stack( &list->stack, (void*)cur );
	return err;	
}



request_t*  request_list_get_request(request_list_t** plist, unsigned short ads)
{
	request_list_t* list = *plist;
	request_t* cur = NULL;
	request_t* tar = NULL;
	unsigned short err = 0;
	unsigned short min = 65535;
	
	if(plist == NULL)
		return NULL;

	//�ҵ�����ads ����ĵ�
	cur = list->head;
	tar = list->head;
	
	while(cur)
	{
		if(cur->ads >= ads)
		{
			err = cur->ads - ads;
		}
		else
		{
			err = ads - cur->ads;

		}
		if(err < min)
		{
			min = err;
			tar = cur;
		}
		 
		cur = cur->next;
	}

	return tar;

}



