#include "drv_ang.h"




void drv_ang_init(void)
{
	ADC_CommonInitTypeDef	ADC_CommonInitStructure;
	ADC_InitTypeDef			ADC_InitStructure;
	NVIC_InitTypeDef		NVIC_InitStructure;

	gpio_config(IU1_PORT	, GPIO_Mode_AN, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_UP, 0);
	gpio_config(IU2_PORT	, GPIO_Mode_AN, GPIO_Speed_100MHz, GPIO_OType_OD, GPIO_PuPd_UP, 0);

	/* ADC1 Periph clock enable */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);	// ADC1 Periph clock enable
	
	ADC_CommonInitStructure.ADC_Mode = ADC_DualMode_InjecSimult;
	ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div6;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_7Cycles;
	ADC_CommonInit(&ADC_CommonInitStructure);

	ADC_StructInit(&ADC_InitStructure);		// ADC1 configuration, Initialize ADC structure
	// Configure the ADC1 in continous mode with a resolutuion equal to 12 bits
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b; // ADC_Mode_InjecSimult
	ADC_InitStructure.ADC_ScanConvMode = ENABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE ;
	ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;	// Èí¼þ´¥·¢
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_T8_TRGO; // ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfConversion = 2;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	// ADC1 Injected conversions configuration
	ADC_InjectedSequencerLengthConfig(ADC1, 2);
	ADC_InjectedChannelConfig(ADC1, IU1_CHANNEL, 1, ADC_SampleTime_15Cycles);
	ADC_InjectedChannelConfig(ADC1, IU2_CHANNEL, 2, ADC_SampleTime_15Cycles);
	
	//ADC_RegularChannelConfig(ADC1, IU1_CHANNEL, 1, ADC_SampleTime_15Cycles);
	//ADC_RegularChannelConfig(ADC1, IU2_CHANNEL, 2, ADC_SampleTime_15Cycles);

	// ADC1 Injected conversions trigger is TIM1 TRGO
	ADC_ExternalTrigInjectedConvConfig(ADC1, ADC_ExternalTrigInjecConv_T8_CC2); 
	ADC_ExternalTrigInjectedConvEdgeConfig(ADC1, ADC_ExternalTrigInjecConvEdge_Rising);
	ADC_AutoInjectedConvCmd(ADC1, ENABLE);		// 

	// ADC1 Injected group of conversions end and Analog Watchdog interrupts enabling
	//ADC_ClearFlag(ADC1, ADC_FLAG_JEOC);
	//ADC_ITConfig(ADC1, ADC_IT_JEOC, ENABLE);	// end of conversion
	ADC_Cmd(ADC1, ENABLE);						// Enable ADC1


	// Enable Interrupt
	//NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQn;	// ADC1-2 golbe interrupt
	//NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	//NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	//NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	//NVIC_Init(&NVIC_InitStructure);


	ADC_SoftwareStartConv(ADC1);
}

