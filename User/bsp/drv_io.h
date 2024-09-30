#ifndef __drv_io_h
#define __drv_io_h


#include "sys_bsp.h"



#define IX10_PORT PE3
#define IX10_VAL ((PORTin(IX10_PORT)==0)?1:0)
#define IX11_PORT PE4
#define IX11_VAL ((PORTin(IX11_PORT)==0)?0:1)
#define IX12_PORT PE5
#define IX12_VAL ((PORTin(IX12_PORT)==0)?1:0)
#define IX13_PORT PE6
#define IX13_VAL ((PORTin(IX13_PORT)==0)?1:0)
#define IX14_PORT PC13
#define IX14_VAL ((PORTin(IX14_PORT)==0)?1:0)
#define IX15_PORT PC14
#define IX15_VAL ((PORTin(IX15_PORT)==0)?1:0)
#define IX16_PORT PC15
#define IX16_VAL ((PORTin(IX16_PORT)==0)?1:0)
#define IX17_PORT PE1
#define IX17_VAL ((PORTin(IX17_PORT)==0)?1:0)
#define IX18_PORT PE2
#define IX18_VAL ((PORTin(IX18_PORT)==0)?1:0)
#define IX19_PORT PG14
#define IX19_VAL ((PORTin(IX19_PORT)==0)?1:0)
#define IX1A_PORT PB9
#define IX1A_VAL ((PORTin(IX1A_PORT)==0)?1:0)
#define IX1B_PORT PG13
#define IX1B_VAL ((PORTin(IX1B_PORT)==0)?1:0)
#define IX1C_PORT PE0
#define IX1C_VAL ((PORTin(IX1C_PORT)==0)?1:0)
#define IX1D_PORT PG12
#define IX1D_VAL ((PORTin(IX1D_PORT)==0)?1:0)
#define IX1E_PORT PG15
#define IX1E_VAL ((PORTin(IX1E_PORT)==0)?1:0)
#define IX1F_PORT PB3
#define IX1F_VAL ((PORTin(IX1F_PORT)==0)?1:0)

#define IX20_PORT PB4
#define IX20_VAL ((PORTin(IX20_PORT)==0)?1:0)
#define IX21_PORT PB5
#define IX21_VAL ((PORTin(IX21_PORT)==0)?1:0)
#define IX22_PORT PG11
#define IX22_VAL ((PORTin(IX22_PORT)==0)?1:0)
#define IX23_PORT PG10
#define IX23_VAL ((PORTin(IX23_PORT)==0)?1:0)
#define IX24_PORT PG9
#define IX24_VAL ((PORTin(IX24_PORT)==0)?1:0)
#define IX25_PORT PD7
#define IX25_VAL ((PORTin(IX25_PORT)==0)?1:0)
#define IX26_PORT PD6
#define IX26_VAL ((PORTin(IX26_PORT)==0)?1:0)
#define IX27_PORT PD5
#define IX27_VAL ((PORTin(IX27_PORT)==0)?1:0)
#define IX28_PORT PD4
#define IX28_VAL ((PORTin(IX28_PORT)==0)?1:0)
#define IX29_PORT PD3
#define IX29_VAL ((PORTin(IX29_PORT)==0)?0:1)


#define OY10_PORT PF2
#define OY10_OUT(o) PORTout(OY10_PORT) =  (o)?0:1
#define OY11_PORT PF3
#define OY11_OUT(o) PORTout(OY11_PORT) =   (o)?0:1
#define OY12_PORT PF4
#define OY12_OUT(o) PORTout(OY12_PORT) =  (o)?0:1
#define OY13_PORT PF5
#define OY13_OUT(o) PORTout(OY13_PORT) =   (o)?0:1
#define OY14_PORT PF8
#define OY14_OUT(o) PORTout(OY14_PORT) =   (o)?0:1
#define OY15_PORT PF9
#define OY15_OUT(o) PORTout(OY15_PORT) = (o)?0:1
#define OY16_PORT PF10
#define OY16_OUT(o) PORTout(OY16_PORT) =   (o)?0:1
#define OY17_PORT PC0
#define OY17_OUT(o) PORTout(OY17_PORT) =   (o)?0:1
#define OY18_PORT PF7
#define OY18_OUT(o) PORTout(OY18_PORT) =   (o)?0:1
#define OY19_PORT PA3
#define OY19_OUT(o) PORTout(OY19_PORT) =   (o)?0:1
#define OY1A_PORT PA2
#define OY1A_OUT(o) PORTout(OY1A_PORT) =   (o)?0:1
#define OY1B_PORT PA1
#define OY1B_OUT(o) PORTout(OY1B_PORT) =   (o)?0:1
#define OY1C_PORT PA0
#define OY1C_OUT(o) PORTout(OY1C_PORT) =   (o)?0:1
#define OY1D_PORT PC3
#define OY1D_OUT(o) PORTout(OY1D_PORT) =   (o)?0:1
#define OY1E_PORT PC2
#define OY1E_OUT(o) PORTout(OY1E_PORT) =  (o)?0:1
#define OY1F_PORT PC1
#define OY1F_OUT(o) PORTout(OY1F_PORT) =   (o)?0:1
#define OY20_PORT PF6
#define OY20_OUT(o) PORTout(OY20_PORT) =   (o)?0:1

#define FAN01_EN_PORT PG7
#define FAN01_EN_OUT(o) PORTout(FAN01_EN_PORT) =   (o)?0:1
#define FAN01_DIR_PORT PG8
#define FAN01_DIR_OUT(o) PORTout(FAN01_DIR_PORT) =  (o)?0:1
#define FAN02_EN_PORT PG5
#define FAN02_EN_OUT(o) PORTout(FAN02_EN_PORT) =  (o)?0:1
#define FAN02_DIR_PORT PG6
#define FAN02_DIR_OUT(o) PORTout(FAN02_DIR_PORT) =  (o)?0:1
#define FAN03_EN_PORT PG3
#define FAN03_EN_OUT(o) PORTout(FAN03_EN_PORT) =  (o)?0:1
#define FAN03_DIR_PORT PG4
#define FAN03_DIR_OUT(o) PORTout(FAN03_DIR_PORT) =  (o)?0:1



#define VFD01_SHUT_PORT PC4
#define VFD01_SHUT_OUT(o)  PORTout(VFD01_SHUT_PORT) =  (o)?1:0
#define VFD01_ERR_PORT PC5
#define VFD01_ERR_VAL  ((PORTin(VFD01_ERR_PORT)==0)?0:1)
#define VFD02_SHUT_PORT PB0
#define VFD02_SHUT_OUT(o) PORTout(VFD02_SHUT_PORT) =  (o)?1:0
#define VFD02_ERR_PORT PB1
#define VFD02_ERR_VAL ((PORTin(VFD02_ERR_PORT)==0)?0:1)
#define VFD03_SHUT_PORT PB2
#define VFD03_SHUT_OUT(o) PORTout(VFD03_SHUT_PORT) =  (o)?1:0
#define VFD03_ERR_PORT PF11
#define VFD03_ERR_VAL ((PORTin(VFD03_ERR_PORT)==0)?0:1)
#define VFD04_SHUT_PORT PF12
#define VFD04_SHUT_OUT(o) PORTout(VFD04_SHUT_PORT) =  (o)?1:0
#define VFD04_ERR_PORT PF13
#define VFD04_ERR_VAL ((PORTin(VFD04_ERR_PORT)==0)?0:1)
#define VFD05_SHUT_PORT PF14
#define VFD05_SHUT_OUT(o) PORTout(VFD05_SHUT_PORT) =  (o)?1:0
#define VFD05_ERR_PORT PF15
#define VFD05_ERR_VAL ((PORTin(VFD05_ERR_PORT)==0)?0:1)
#define VFD06_SHUT_PORT PG0
#define VFD06_SHUT_OUT(o) PORTout(VFD06_SHUT_PORT) =   (o)?1:0
#define VFD06_ERR_PORT PG1
#define VFD06_ERR_VAL ((PORTin(VFD06_ERR_PORT)==0)?0:1)
#define VFD07_SHUT_PORT PE7
#define VFD07_SHUT_OUT(o) PORTout(VFD07_SHUT_PORT) =  (o)?1:0
#define VFD07_ERR_PORT PE8
#define VFD07_ERR_VAL ((PORTin(VFD07_ERR_PORT)==0)?0:1)
#define VFD08_SHUT_PORT PE9
#define VFD08_SHUT_OUT(o) PORTout(VFD08_SHUT_PORT) =  (o)?1:0
#define VFD08_ERR_PORT PE10
#define VFD08_ERR_VAL ((PORTin(VFD08_ERR_PORT)==0)?0:1)
#define VFD09_SHUT_PORT PE11
#define VFD09_SHUT_OUT(o) PORTout(VFD09_SHUT_PORT) =   (o)?1:0
#define VFD09_ERR_PORT PE12
#define VFD09_ERR_VAL ((PORTin(VFD09_ERR_PORT)==0)?0:1)
#define VFD10_SHUT_PORT PE13
#define VFD10_SHUT_OUT(o) PORTout(VFD10_SHUT_PORT) =  (o)?1:0
#define VFD10_ERR_PORT PE14
#define VFD10_ERR_VAL ((PORTin(VFD10_ERR_PORT)==0)?0:1)


#define STA01_PORT PD11
#define STA01_OUT(o) PORTout(STA01_PORT) =  (o)?0:1
#define STA02_PORT PD10
#define STA02_OUT(o) PORTout(STA02_PORT) =  (o)?0:1
#define STA03_PORT PD9
#define STA03_OUT(o) PORTout(STA03_PORT) =  (o)?0:1
#define STA04_PORT PD8
#define STA04_OUT(o) PORTout(STA04_PORT) =  (o)?0:1
#define STA05_PORT PB15
#define STA05_OUT(o) PORTout(STA05_PORT) =  (o)?0:1
#define STA06_PORT PB14
#define STA06_OUT(o) PORTout(STA06_PORT) =  (o)?0:1



#define AC_DET_PORT PG2
#define AC_DET_VAL ((PORTin(AC_DET_PORT)==0)?1:0)


#define RUN_PORT PD2
#define RUN_OUT(o) PORTout(RUN_PORT) =  o



void drv_io_init(void);

#endif
