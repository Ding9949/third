#ifndef __sys_includes_h
#define __sys_includes_h

#include "sys_bsp.h"


/*base driver*/
#include "timer.h"
#include "drv_io.h"
#include "drv_ang.h"
#include "drv_eprom.h"
#include "drv_sci.h"
#include "drv_flash.h"
#include "can.h"



/* api */
#include "buffer.h"
#include "api_data.h"
#include "api_canbus.h"
#include "api_com_vfd.h"
#include "api_com_qs.h"
#include "api_com_dis.h"
#include "api_spd_test.h"
#include "api_request.h"

/* usr */
#include "sys_err.h"
#include "sys_hard.h"
#include "sys_power_up.h"
#include "sys_logic_main.h"
#include "sys_task.h"
#include "sys_main.h"


#endif
