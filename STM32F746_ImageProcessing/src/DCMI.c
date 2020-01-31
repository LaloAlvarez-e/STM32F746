/*
 * DCMI.c
 *
 *  Created on: 24/09/2018
 *      Author: InDev
 */


#include "DCMI.h"
uint32_t DCMIbusy=1;
uint32_t DCMIflag=0;
uint32_t DCMIflag1=0;


LTDC_TFT_TypeDef DCMIBuffer[2]={0};

LTDC_TFT_TypeDef* DCMIStorage=&DCMIBuffer[0];
LTDC_TFT_TypeDef* DCMIProcess=&DCMIBuffer[1];

uint32_t DCMI_Init(void)
{
	uint32_t delay=0;

	RCC_AHB1ENR->GPIOGEN=1;
	RCC_AHB1ENR->GPIOAEN=1;
	RCC_AHB1ENR->GPIOBEN=1;
	RCC_AHB1ENR->GPIODEN=1;
	RCC_AHB1ENR->GPIOHEN=1;
	RCC_AHB1ENR->GPIOCEN=1;
	RCC_AHB2ENR->DCMIEN=1;
	RCC_AHB1ENR->DMA2EN=1;
	delay=RCC_AHB2ENR->DCMIEN;
	delay=RCC_AHB1ENR->DMA2EN;

	//VSYNC PG9
	GPIOG_MODER->MODER9=2;
	GPIOG_OTYPER->OTYPER9=0;
	GPIOG_OSPEEDR->OSPEEDR9=3;
	GPIOG_PUPDR->PUPDR9=0;
	GPIOG_AFRH->AFR9=13;

	//HSYNC PA4
	GPIOA_MODER->MODER4=2;
	GPIOA_OTYPER->OTYPER4=0;
	GPIOA_OSPEEDR->OSPEEDR4=3;
	GPIOA_PUPDR->PUPDR4=0;
	GPIOA_AFRL->AFR4=13;

	//PIXCLK PA6
	GPIOA_MODER->MODER6=2;
	GPIOA_OTYPER->OTYPER6=0;
	GPIOA_OSPEEDR->OSPEEDR6=3;
	GPIOA_PUPDR->PUPDR6=0;
	GPIOA_AFRL->AFR6=13;

	//D7 PB9
	GPIOB_MODER->MODER9=2;
	GPIOB_OTYPER->OTYPER9=0;
	GPIOB_OSPEEDR->OSPEEDR9=3;
	GPIOB_PUPDR->PUPDR9=0;
	GPIOB_AFRH->AFR9=13;

	//D6 PB8
	GPIOB_MODER->MODER8=2;
	GPIOB_OTYPER->OTYPER8=0;
	GPIOB_OSPEEDR->OSPEEDR8=3;
	GPIOB_PUPDR->PUPDR8=0;
	GPIOB_AFRH->AFR8=13;

	//D5 PD3
	GPIOD_MODER->MODER3=2;
	GPIOD_OTYPER->OTYPER3=0;
	GPIOD_OSPEEDR->OSPEEDR3=3;
	GPIOD_PUPDR->PUPDR3=0;
	GPIOD_AFRL->AFR3=13;

	//D4 PH14
	GPIOH_MODER->MODER14=2;
	GPIOH_OTYPER->OTYPER14=0;
	GPIOH_OSPEEDR->OSPEEDR14=3;
	GPIOH_PUPDR->PUPDR14=0;
	GPIOH_AFRH->AFR14=13;

	//D3 PH12
	GPIOH_MODER->MODER12=2;
	GPIOH_OTYPER->OTYPER12=0;
	GPIOH_OSPEEDR->OSPEEDR12=3;
	GPIOH_PUPDR->PUPDR12=0;
	GPIOH_AFRH->AFR12=13;

	//D2 PH11
	GPIOH_MODER->MODER11=2;
	GPIOH_OTYPER->OTYPER11=0;
	GPIOH_OSPEEDR->OSPEEDR11=3;
	GPIOH_PUPDR->PUPDR11=0;
	GPIOH_AFRH->AFR11=13;

	//D1 PC7
	GPIOC_MODER->MODER7=2;
	GPIOC_OTYPER->OTYPER7=0;
	GPIOC_OSPEEDR->OSPEEDR7=3;
	GPIOC_PUPDR->PUPDR7=0;
	GPIOC_AFRL->AFR7=13;

	//D0 PC6
	GPIOC_MODER->MODER6=2;
	GPIOC_OTYPER->OTYPER6=0;
	GPIOC_OSPEEDR->OSPEEDR6=3;
	GPIOC_PUPDR->PUPDR6=0;
	GPIOC_AFRL->AFR6=13;

	//PWDN PA5
	GPIOA_MODER->MODER5=1;
	GPIOA_OTYPER->OTYPER5=0;
	GPIOA_OSPEEDR->OSPEEDR5=3;
	GPIOA_PUPDR->PUPDR5=0;
	GPIOA_AFRL->AFR5=0;
	GPIOA_ODR->ODR5=1;

	DCMI_CR->ENABLE=0;
	DCMI_CR->OELS=1;
	DCMI_CR->LSM=0;

	DCMI_CR->OEBS=1;
	DCMI_CR->BSM=0;

	DCMI_CR->EDM=0;
	DCMI_CR->FCRC=0;

	DCMI_CR->VSPOL=1;
	DCMI_CR->HSPOL=0;
	DCMI_CR->PCKPOL=0;

	DCMI_CR->ESS=0;
	DCMI_CR->JPEG=0;

	DCMI_CR->CROP=1;
	DCMI_CR->CM=0;

	DCMI_CWSTRT->VST=0;
	DCMI_CWSTRT->HOFFCNT=0;

	DCMI_CWSIZE->VLINE=240-1;
	DCMI_CWSIZE->CAPCNT=((320)*2)-1;

	DCMI_IER->ERR_IE=1;
	DCMI_IER->OVR_IE=1;
	DCMI_IER->FRAME_IE=0;
	DCMI_IER->VSYNC_IE=0;
/*
*/
	NVIC_ISER2->NVIC_DCMI=1;
	NVIC_IPR19->NVIC_DCMI=NVIC_PRIORITY_DCMI;

	DMA2_Stream1_CR->EN=0;
	while(DMA2_Stream1_CR->EN){} //DCMI

	DMA2_Stream1_PAR_R=(uint32_t)(DCMI_DR_OFFSET+DCMI_BASE);
	DMA2_Stream1_M0AR_R=(uint32_t)LTDC_LayerAux_ADDRESS;
	DMA2_Stream1_M1AR_R=(uint32_t)LTDC_LayerAux_ADDRESS+0x40000;
	DMA2_Stream1_NDTR_R=((320)*(240))/2;
	DMA2_Stream1_CR->CHSEL=1;
	DMA2_Stream1_CR->PL=3;

	DMA2_Stream1_CR->DBM=1;
	DMA2_Stream1_CR->DIR=0;
	DMA2_Stream1_CR->PFCTRL=0;
	DMA2_Stream1_CR->PBURST=0;
	DMA2_Stream1_CR->MBURST=0;
	DMA2_Stream1_CR->PINCOS=0;
	DMA2_Stream1_CR->MSIZE=2;
	DMA2_Stream1_CR->PSIZE=2;
	DMA2_Stream1_CR->PINC=0;
	DMA2_Stream1_CR->MINC=1;
	DMA2_Stream1_FCR->DMDIS=1;
	DMA2_Stream1_FCR->FTH=3;
	DMA2_Stream1_CR->CIRC=1;
/*
	*/
	DMA2_Stream1_CR->TEIE=1;
	DMA2_Stream1_FCR->FEIE=1;
	DMA2_Stream1_CR->TCIE=1;
	DMA2_Stream1_CR->HTIE=0;

	NVIC_ISER1->NVIC_DMA2_Stream1=1;
	NVIC_IPR14->NVIC_DMA2_Stream1=NVIC_PRIORITY_DMA2_Stream1;


	DMA2_LIFCR_R=0xFF;
	DMA2_Stream1_CR_R |= DMA2_Stream1_CR_EN_EN;

	DCMIBuffer[0].layerType=LAYER_TYPE_IMAGE_NOHEADER;
	DCMIBuffer[0].layerDataAddress=(uint32_t)LTDC_LayerAux_ADDRESS;
	DCMIBuffer[0].layerXInit=0;
	DCMIBuffer[0].layerYInit=0;
	DCMIBuffer[0].layerBGXInit=0;
	DCMIBuffer[0].layerBGYInit=0;
	DCMIBuffer[0].layerWidth=320;
	DCMIBuffer[0].layerHeight=240;
	DCMIBuffer[0].layerWidthTotal=320;
	DCMIBuffer[0].layerHeightTotal=240;
	DCMIBuffer[0].variableType = VARIABLETYPE_USHORT;


	DCMI_CR_R|= DCMI_CR_ENABLE;
	DCMIBuffer[1].layerType=LAYER_TYPE_IMAGE_NOHEADER;
	DCMIBuffer[1].layerDataAddress=(uint32_t)LTDC_LayerAux_ADDRESS+0x40000;
	DCMIBuffer[1].layerXInit=0;
	DCMIBuffer[1].layerYInit=0;
	DCMIBuffer[1].layerBGXInit=0;
	DCMIBuffer[1].layerBGYInit=0;
	DCMIBuffer[1].layerWidth=320;
	DCMIBuffer[1].layerHeight=240;
	DCMIBuffer[1].layerWidthTotal=320;
	DCMIBuffer[1].layerHeightTotal=240;
	DCMIBuffer[1].variableType = VARIABLETYPE_USHORT;

	DCMI_CR_R|= DCMI_CR_CAPTURE;

	return delay;
}


uint32_t DCMI_Capture(void)
{
	DCMIbusy=1;

	DCMI_CR_R&=~ (DCMI_CR_CAPTURE |DCMI_CR_ENABLE);
	DMA2_Stream1_CR_R &=~DMA2_Stream1_CR_R_EN_EN;
	while(DMA2_Stream1_CR_R & DMA2_Stream1_CR_R_EN_EN);
	DMA2_Stream1_NDTR_R=((320)*(240))/2;
	DMA2_LIFCR_R=0xFF;
	DMA2_Stream1_CR_R |=DMA2_Stream1_CR_R_EN_EN;
	while(!(DMA2_Stream1_CR_R & DMA2_Stream1_CR_R_EN_EN));
	DCMI_CR_R|= (DCMI_CR_CAPTURE |DCMI_CR_ENABLE);

	return 1;
}



uint32_t DCMI_Busy(void)
{
	return (DCMIbusy);
}

uint32_t DCMI_SetBusy(void)
{
	DCMIbusy=1;
	return (DCMIbusy);
}
/*
uint32_t DCMI_Abort(void)
{
	DCMIbusy=0;
	DCMI_CR_R &=~DCMI_CR_CAPTURE;
	DMA2_Stream1_CR_R&=~DMA2_Stream1_CR_R_EN_EN;
	while(DMA2_Stream1_CR_R & DMA2_Stream1_CR_R_EN_EN);
	DCMIflag1++;
	return 0;
}
*/

uint32_t valor=0,valor1=0,valor2=0;
__attribute__((section(".itcmram")))
void DMA2_Stream1_IRQHandler(void)
{
	if(DMA2_LISR_R & DMA2_LISR_R_TEIF1_OCCUR)
	{
		DMA2_LIFCR_R |= DMA2_LIFCR_R_CTEIF1_CLEAR;
		DMA2_LIFCR_R |= DMA2_LIFCR_R_CTEIF1_CLEAR;
	}
	if(DMA2_LISR_R & DMA2_LISR_R_FEIF1_OCCUR)
	{
		DMA2_LIFCR_R|=DMA2_LIFCR_R_CFEIF1_CLEAR;
		DMA2_LIFCR_R|=DMA2_LIFCR_R_CFEIF1_CLEAR;
	}
	if(DMA2_LISR_R & DMA2_LISR_R_TCIF1_OCCUR)
	{
		DMA2_LIFCR_R|=DMA2_LIFCR_R_CTCIF1_CLEAR;
		if (DMA2_Stream1_CR_R & DMA2_Stream1_CR_R_CT_MEM1)
			DCMIProcess=&DCMIBuffer[0];
		else
			DCMIProcess=&DCMIBuffer[1];

		DCMIbusy=0;

	}
	/*if(DMA2_LISR_R & DMA2_LISR_R_HTIF1_OCCUR)
	{
		DMA2_LIFCR_R |=DMA2_LIFCR_R_CHTIF1_CLEAR;
		DMA2_LIFCR_R |=DMA2_LIFCR_R_CHTIF1_CLEAR;
	}*/

}

__attribute__((section(".itcmram")))
void DCMI_IRQHandler(void)
{
	if(DCMI_MIS_R & DCMI_MIS_ERR_MIS)
	{
		DCMI_ICR_R |= DCMI_ICR_ERR_ISC;
		DCMI_ICR_R |= DCMI_ICR_ERR_ISC;
	}
	if(DCMI_MIS_R & DCMI_MIS_OVR_MIS)
	{
		DCMI_ICR_R |= DCMI_ICR_OVR_ISC;
		DCMI_ICR_R |= DCMI_ICR_OVR_ISC;
	}
/*
	if(DCMI_MIS_R & DCMI_MIS_FRAME_MIS)
	{
		DCMI_ICR_R |= DCMI_ICR_FRAME_ISC;
		DCMI_ICR_R |= DCMI_ICR_FRAME_ISC
	}
	*/
	if(DCMI_MIS_R & DCMI_MIS_VSYNC_MIS)
	{
		DCMI_ICR_R |= DCMI_ICR_VSYNC_ISC;
	}

}