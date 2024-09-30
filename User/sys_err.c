#include "sys_include.h"


SysErr_t gSysErr;

void sys_err_init(void)
{
	memset(&gSysErr,0,sizeof(SysErr_t));
}

u16 sys_err_get_id(void)
{
	u16 i=0;


	if(gSysErr.ErrHd.all)
	{
		for(i=0;i<32;i++)
		{
			if((gSysErr.ErrHd.all>>i)&0x0001)
			{
				if(i<=6)
					return (i+1);
				else 
					return (i+3);
			}
		}
	}

	return 0;
}



