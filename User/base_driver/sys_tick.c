
#include "sys_include.h"

void systick_init(void)
{
    RCC_ClocksTypeDef rcc_clocks;
    RCC_GetClocksFreq(&rcc_clocks);
    SysTick_Config(rcc_clocks.HCLK_Frequency/OS_TICKS_PER_SEC);
}


