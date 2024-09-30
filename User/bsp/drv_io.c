#include "drv_io.h"



void drv_io_init(void)
{
	//inport
	gpio_config(IX10_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX11_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX12_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX13_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX14_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX15_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX16_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX17_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX18_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX19_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX1A_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX1B_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX1C_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX1D_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);	
	gpio_config(IX1E_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX1F_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX20_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX21_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX22_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX23_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX24_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX25_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX26_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX27_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX28_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(IX29_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	

	gpio_config(OY10_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY11_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY12_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY13_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY14_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY15_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY16_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY17_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY18_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY19_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY1A_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY1B_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY1C_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY1D_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY1E_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY1F_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(OY20_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	
	gpio_config(VFD01_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD01_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD02_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD02_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD03_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD03_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD04_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD04_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD05_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD05_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD06_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD06_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD07_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD07_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD08_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD08_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD09_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD09_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	gpio_config(VFD10_SHUT_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(VFD10_ERR_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);
	
	gpio_config(STA01_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(STA02_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(STA03_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(STA04_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(STA05_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(STA06_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);

	
	gpio_config(AC_DET_PORT, GPIO_Mode_IN, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_UP, 0);


	gpio_config(FAN01_EN_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(FAN01_DIR_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(FAN02_EN_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(FAN02_DIR_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(FAN03_EN_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);
	gpio_config(FAN03_DIR_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);

	
	gpio_config(RUN_PORT, GPIO_Mode_OUT, GPIO_Speed_100MHz, GPIO_OType_PP, GPIO_PuPd_NOPULL, 0);

}

