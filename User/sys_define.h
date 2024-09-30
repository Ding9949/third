#ifndef __sys_define_h
#define __sys_define_h


/****************************************************************************/
 //版本号、发布时间
#define SW_VERSION 110
#define SW_CODE_DATE 20240923
/****************************************************************************/

//#define TEST_FLAG 

/****************************************************************************/
/* F4中HCK = 168M  APB1CLK = HCK/4 = 42M APB2CLK = HCLK/2=84M  */
/*TIM1\TIM8\TIM9\TIM10\TIM11 CLK = APB2CLK*2 = 168M   其他TIMx CLK = APB1CLK*2=84M*/
#define CKTIM	((u32)168000000uL) 	
#define CKTIMx	((u32)80000000uL) 		/* F4中TIM1和TIM8时钟 是168M   其他TIMx 84M*/
#define PWM_PRSC ((u8)0)
#define PWM_FREQ ((u16) 10000) // in Hz  (N.b.: pattern type is center aligned)
#define PWM_PERIOD ((u16) (CKTIM / (u32)(2*PWM_FREQ *(PWM_PRSC+1)))) 
#define PWM_PERIODx ((u16) (CKTIMx / (u32)(2*PWM_FREQ *(PWM_PRSC+1)))) 
/****	ADC IRQ-HANDLER frequency, related to PWM  ****/
#define REP_RATE (1)  // (N.b): Internal current loop is performed every 
                      //             (REP_RATE + 1)/(2*PWM_FREQ) seconds.
                      // REP_RATE has to be an odd number in case of three-shunt
                      // current reading; this limitation doesn't apply to ICS

//Not to be modified
#define SAMPLING_FREQ   ((u16)PWM_FREQ/((REP_RATE+1)/2))   // Resolution: 1Hz

/****    Deadtime Value   ****/
#define DEADTIME_NS	((u16) 110)  //in nsec; range is [0...350] 1.5us
#define DEADTIME  (u16)((unsigned long long)CKTIM \
          *(unsigned long long)DEADTIME_NS/100000000uL) 
/****************************************************************************/
#define SYS_ISR_PSC 10
/****************************************************************************/


#define POWUP_DELAY (SYS_ISR_PSC*1500)	// 1.5S 
#define DC_BUS_BASE  3000  //(0.1V)
#define VOLT_BASE_VALUE 1861
#define LOW_VOLT_THD  (VOLT_BASE_VALUE*0.6)
#define POWUP_VOLT_THD  (VOLT_BASE_VALUE*0.75)
#define HIGH_VOLT_THD  (VOLT_BASE_VALUE*1.35)

/****************************************************************************/

#define PI 3.1415926f 


#define API_SPD_NO_PLUSE_TIME	(30000) //3000ms

/************************************************************************************************************/

#define STMFLASH_ReadHalfWord(addr)		(*(vu32*)addr)
/************************************************************************************************************/


#endif
