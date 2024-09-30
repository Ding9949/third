#ifndef __drv_ang_h
#define __drv_ang_h

#include "sys_bsp.h"



#define IU1_PORT PA4
#define IU1_CHANNEL ADC_Channel_4
#define IU1_VAL 	ADC_GetInjectedConversionValue(ADC1, ADC_InjectedChannel_1)

#define IU2_PORT PA5
#define IU2_CHANNEL ADC_Channel_5
#define IU2_VAL 	ADC_GetInjectedConversionValue(ADC1, ADC_InjectedChannel_2)




void drv_ang_init(void);




#endif
