/*
 * FMC.c
 *
 *  Created on: 20/08/2018
 *      Author: InDev
 */


#include "FMC.h"


int32_t SDRAM_Init(void)
{
	uint32_t delay=0;

	RCC_AHB1ENR->GPIODEN=1;
	delay=RCC_AHB1ENR_R;
	//PD0
	GPIOD_MODER->MODER0=2;
	GPIOD_OTYPER->OTYPER0=0;
	GPIOD_OSPEEDR->OSPEEDR0=3;
	GPIOD_PUPDR->PUPDR0=0;
	GPIOD_AFRL->AFR0=12;
	//PD1
	GPIOD_MODER->MODER1=2;
	GPIOD_OTYPER->OTYPER1=0;
	GPIOD_OSPEEDR->OSPEEDR1=3;
	GPIOD_PUPDR->PUPDR1=0;
	GPIOD_AFRL->AFR1=12;
	//PD8
	GPIOD_MODER->MODER8=2;
	GPIOD_OTYPER->OTYPER8=0;
	GPIOD_OSPEEDR->OSPEEDR8=3;
	GPIOD_PUPDR->PUPDR8=0;
	GPIOD_AFRH->AFR8=12;
	//PD9
	GPIOD_MODER->MODER9=2;
	GPIOD_OTYPER->OTYPER9=0;
	GPIOD_OSPEEDR->OSPEEDR9=3;
	GPIOD_PUPDR->PUPDR9=0;
	GPIOD_AFRH->AFR9=12;
	//PD10
	GPIOD_MODER->MODER10=2;
	GPIOD_OTYPER->OTYPER10=0;
	GPIOD_OSPEEDR->OSPEEDR10=3;
	GPIOD_PUPDR->PUPDR10=0;
	GPIOD_AFRH->AFR10=12;
	//PD14
	GPIOD_MODER->MODER14=2;
	GPIOD_OTYPER->OTYPER14=0;
	GPIOD_OSPEEDR->OSPEEDR14=3;
	GPIOD_PUPDR->PUPDR14=0;
	GPIOD_AFRH->AFR14=12;
	//PD15
	GPIOD_MODER->MODER15=2;
	GPIOD_OTYPER->OTYPER15=0;
	GPIOD_OSPEEDR->OSPEEDR15=3;
	GPIOD_PUPDR->PUPDR15=0;
	GPIOD_AFRH->AFR15=12;





	RCC_AHB1ENR->GPIOEEN=1;
	delay=RCC_AHB1ENR_R;
	//PE0
	GPIOE_MODER->MODER0=2;
	GPIOE_OTYPER->OTYPER0=0;
	GPIOE_OSPEEDR->OSPEEDR0=3;
	GPIOE_PUPDR->PUPDR0=0;
	GPIOE_AFRL->AFR0=12;
	//PE1
	GPIOE_MODER->MODER1=2;
	GPIOE_OTYPER->OTYPER1=0;
	GPIOE_OSPEEDR->OSPEEDR1=3;
	GPIOE_PUPDR->PUPDR1=0;
	GPIOE_AFRL->AFR1=12;
	//PE7
	GPIOE_MODER->MODER7=2;
	GPIOE_OTYPER->OTYPER7=0;
	GPIOE_OSPEEDR->OSPEEDR7=3;
	GPIOE_PUPDR->PUPDR7=0;
	GPIOE_AFRL->AFR7=12;
	//PE8
	GPIOE_MODER->MODER8=2;
	GPIOE_OTYPER->OTYPER8=0;
	GPIOE_OSPEEDR->OSPEEDR8=3;
	GPIOE_PUPDR->PUPDR8=0;
	GPIOE_AFRH->AFR8=12;
	//PE9
	GPIOE_MODER->MODER9=2;
	GPIOE_OTYPER->OTYPER9=0;
	GPIOE_OSPEEDR->OSPEEDR9=3;
	GPIOE_PUPDR->PUPDR9=0;
	GPIOE_AFRH->AFR9=12;
	//PE10
	GPIOE_MODER->MODER10=2;
	GPIOE_OTYPER->OTYPER10=0;
	GPIOE_OSPEEDR->OSPEEDR10=3;
	GPIOE_PUPDR->PUPDR10=0;
	GPIOE_AFRH->AFR10=12;
	//PE11
	GPIOE_MODER->MODER11=2;
	GPIOE_OTYPER->OTYPER11=0;
	GPIOE_OSPEEDR->OSPEEDR11=3;
	GPIOE_PUPDR->PUPDR11=0;
	GPIOE_AFRH->AFR11=12;
	//PE12
	GPIOE_MODER->MODER12=2;
	GPIOE_OTYPER->OTYPER12=0;
	GPIOE_OSPEEDR->OSPEEDR12=3;
	GPIOE_PUPDR->PUPDR12=0;
	GPIOE_AFRH->AFR12=12;
	//PE13
	GPIOE_MODER->MODER13=2;
	GPIOE_OTYPER->OTYPER13=0;
	GPIOE_OSPEEDR->OSPEEDR13=3;
	GPIOE_PUPDR->PUPDR13=0;
	GPIOE_AFRH->AFR13=12;
	//PE14
	GPIOE_MODER->MODER14=2;
	GPIOE_OTYPER->OTYPER14=0;
	GPIOE_OSPEEDR->OSPEEDR14=3;
	GPIOE_PUPDR->PUPDR14=0;
	GPIOE_AFRH->AFR14=12;
	//PE15
	GPIOE_MODER->MODER15=2;
	GPIOE_OTYPER->OTYPER15=0;
	GPIOE_OSPEEDR->OSPEEDR15=3;
	GPIOE_PUPDR->PUPDR15=0;
	GPIOE_AFRH->AFR15=12;




	RCC_AHB1ENR->GPIOFEN=1;
	delay=RCC_AHB1ENR_R;
	//PF0
	GPIOF_MODER->MODER0=2;
	GPIOF_OTYPER->OTYPER0=0;
	GPIOF_OSPEEDR->OSPEEDR0=3;
	GPIOF_PUPDR->PUPDR0=0;
	GPIOF_AFRL->AFR0=12;
	//PF1
	GPIOF_MODER->MODER1=2;
	GPIOF_OTYPER->OTYPER1=0;
	GPIOF_OSPEEDR->OSPEEDR1=3;
	GPIOF_PUPDR->PUPDR1=0;
	GPIOF_AFRL->AFR1=12;
	//PF2
	GPIOF_MODER->MODER2=2;
	GPIOF_OTYPER->OTYPER2=0;
	GPIOF_OSPEEDR->OSPEEDR2=3;
	GPIOF_PUPDR->PUPDR2=0;
	GPIOF_AFRL->AFR2=12;
	//PF3
	GPIOF_MODER->MODER3=2;
	GPIOF_OTYPER->OTYPER3=0;
	GPIOF_OSPEEDR->OSPEEDR3=3;
	GPIOF_PUPDR->PUPDR3=0;
	GPIOF_AFRL->AFR3=12;
	//PF4
	GPIOF_MODER->MODER4=2;
	GPIOF_OTYPER->OTYPER4=0;
	GPIOF_OSPEEDR->OSPEEDR4=3;
	GPIOF_PUPDR->PUPDR4=0;
	GPIOF_AFRL->AFR4=12;
	//PF5
	GPIOF_MODER->MODER5=2;
	GPIOF_OTYPER->OTYPER5=0;
	GPIOF_OSPEEDR->OSPEEDR5=3;
	GPIOF_PUPDR->PUPDR5=0;
	GPIOF_AFRL->AFR5=12;
	//PF11
	GPIOF_MODER->MODER11=2;
	GPIOF_OTYPER->OTYPER11=0;
	GPIOF_OSPEEDR->OSPEEDR11=3;
	GPIOF_PUPDR->PUPDR11=0;
	GPIOF_AFRH->AFR11=12;
	//PF12
	GPIOF_MODER->MODER12=2;
	GPIOF_OTYPER->OTYPER12=0;
	GPIOF_OSPEEDR->OSPEEDR12=3;
	GPIOF_PUPDR->PUPDR12=0;
	GPIOF_AFRH->AFR12=12;
	//PF13
	GPIOF_MODER->MODER13=2;
	GPIOF_OTYPER->OTYPER13=0;
	GPIOF_OSPEEDR->OSPEEDR13=3;
	GPIOF_PUPDR->PUPDR13=0;
	GPIOF_AFRH->AFR13=12;
	//PF14
	GPIOF_MODER->MODER14=2;
	GPIOF_OTYPER->OTYPER14=0;
	GPIOF_OSPEEDR->OSPEEDR14=3;
	GPIOF_PUPDR->PUPDR14=0;
	GPIOF_AFRH->AFR14=12;
	//PF15
	GPIOF_MODER->MODER15=2;
	GPIOF_OTYPER->OTYPER15=0;
	GPIOF_OSPEEDR->OSPEEDR15=3;
	GPIOF_PUPDR->PUPDR15=0;
	GPIOF_AFRH->AFR15=12;

	RCC_AHB1ENR->GPIOGEN=1;
	delay=RCC_AHB1ENR_R;
	//PG0
	GPIOG_MODER->MODER0=2;
	GPIOG_OTYPER->OTYPER0=0;
	GPIOG_OSPEEDR->OSPEEDR0=3;
	GPIOG_PUPDR->PUPDR0=0;
	GPIOG_AFRL->AFR0=12;
	//PG1
	GPIOG_MODER->MODER1=2;
	GPIOG_OTYPER->OTYPER1=0;
	GPIOG_OSPEEDR->OSPEEDR1=3;
	GPIOG_PUPDR->PUPDR1=0;
	GPIOG_AFRL->AFR1=12;
	//PG4
	GPIOG_MODER->MODER4=2;
	GPIOG_OTYPER->OTYPER4=0;
	GPIOG_OSPEEDR->OSPEEDR4=3;
	GPIOG_PUPDR->PUPDR4=0;
	GPIOG_AFRL->AFR4=12;
	//PG5
	GPIOG_MODER->MODER5=2;
	GPIOG_OTYPER->OTYPER5=0;
	GPIOG_OSPEEDR->OSPEEDR5=3;
	GPIOG_PUPDR->PUPDR5=0;
	GPIOG_AFRL->AFR5=12;
	//PG8
	GPIOG_MODER->MODER8=2;
	GPIOG_OTYPER->OTYPER8=0;
	GPIOG_OSPEEDR->OSPEEDR8=3;
	GPIOG_PUPDR->PUPDR8=0;
	GPIOG_AFRH->AFR8=12;
	//PG15
	GPIOG_MODER->MODER15=2;
	GPIOG_OTYPER->OTYPER15=0;
	GPIOG_OSPEEDR->OSPEEDR15=3;
	GPIOG_PUPDR->PUPDR15=0;
	GPIOG_AFRH->AFR15=12;

	RCC_AHB1ENR->GPIOHEN=1;
	delay=RCC_AHB1ENR_R;
	//PH5
	GPIOH_MODER->MODER5=2;
	GPIOH_OTYPER->OTYPER5=0;
	GPIOH_OSPEEDR->OSPEEDR5=3;
	GPIOH_PUPDR->PUPDR5=0;
	GPIOH_AFRL->AFR5=12;
	//PH6
	GPIOH_MODER->MODER6=2;
	GPIOH_OTYPER->OTYPER6=0;
	GPIOH_OSPEEDR->OSPEEDR6=3;
	GPIOH_PUPDR->PUPDR6=0;
	GPIOH_AFRL->AFR6=12;
	//PH7
	GPIOH_MODER->MODER7=2;
	GPIOH_OTYPER->OTYPER7=0;
	GPIOH_OSPEEDR->OSPEEDR7=3;
	GPIOH_PUPDR->PUPDR7=0;
	GPIOH_AFRL->AFR7=12;

	RCC_AHB3ENR->FMCEN=1;

	FMC_SRAM_NOR_CR1_R = 0x000030D2;

	FMC_SDRAM_CR1->SDCLK=2; //HCLK/2
	FMC_SDRAM_CR1->RBURST=1; //ALL READ ARE BURST
	FMC_SDRAM_CR1->RPIPE=3;//0; time delay after CAS

	FMC_SDRAM_CR2->NC=0;//8 COLUMNS
	FMC_SDRAM_CR2->NR=1;//12ROWS
	FMC_SDRAM_CR2->MWID=1;//16 BITS
	FMC_SDRAM_CR2->NB=1; //4 BANKS
	FMC_SDRAM_CR2->CAS=3; //3CYLCLES
	FMC_SDRAM_CR2->WP=0; //WRITE ALLOWED


	uint32_t RP=2;  //min 2 //optimum 2
	uint32_t RAS=4; //min 4 //optimum 4

	uint32_t RCD=2; //min 2 //optimum 2

	uint32_t SRX=7; //min 1 //optmim 7
	uint32_t RSC=2; //min 1 //optimum 2

	FMC_SDRAM_TR1->TRP=RP; //2 min 20ns
	FMC_SDRAM_TR2->TRP=RP; //2 min 20ns
	FMC_SDRAM_TR1->TRC=(RAS+RP); //7 min 70ns =50ns+20ns tRAS+tRP
	FMC_SDRAM_TR2->TRC=(RAS+RP); //7 min 70ns =50ns+20ns tRAS+tRP


	FMC_SDRAM_TR2->TRAS=RAS; //5 min 50ns tRAS
	FMC_SDRAM_TR2->TRCD=RCD; //2 min 20ns tRCD
	FMC_SDRAM_TR2->TWR=(RAS-RCD);//3 min 30ns =50ns-20ns tRAS-tRCD

	FMC_SDRAM_TR2->TXSR=SRX; //1 min 10ns tSRX
	FMC_SDRAM_TR2->TMRD=RSC;//1 min 10ns tRSC or tMRD

	NVIC_ISER1->NVIC_FMC=1;
	NVIC_IPR12->NVIC_FMC=NVIC_PRIORITY_FMC;
	while(FMC_SDRAM_SR->BUSY)
	{};



	FMC_SDRAM_CMR_R = 1 | FMC_SDRAM_CMR_R_CTB2_EN;// | (1 << 5);
	for(delay = 0; delay < 5000000; delay++)
	{};
	while(FMC_SDRAM_SR->BUSY)
	{};

	FMC_SDRAM_CMR_R = 2 | FMC_SDRAM_CMR_R_CTB2_EN;//| (1 << 5);
	for(delay = 0; delay < 500000; delay++)
	while(FMC_SDRAM_SR->BUSY)
	{};

	//CBR auto-refresh cycle minimum 8
	FMC_SDRAM_CMR_R = 3 | FMC_SDRAM_CMR_R_CTB2_EN | (8 << 5);
	while(FMC_SDRAM_SR->BUSY)
	{};


	//wrap type(3) 0:sequential 1:interleave
	//burst lenght(0:2) 0: 1 1:2 2:4 3:8 7: full
	// CAS(6:4) 2: 2 CAS 3:3 CAS
	// burs usage: (9) 0:en 1:off
	FMC_SDRAM_CMR_R = 4 | FMC_SDRAM_CMR_R_CTB2_EN | (0x231 << 9);// | (1 << 5) ;//0x221
	while(FMC_SDRAM_SR->BUSY)
	{};


	//1561-20
	FMC_SDRAM_RTR_R |= ((1561-20) << 1)|(1<<14);
	while(FMC_SDRAM_SR->BUSY)
	{};
	//MPU_SDRAM();
	// Clear SDRAM or fill with some pattern/color
	for(delay=0;delay<(1024*1024*4);delay+=4)
		*(uint32_t*)(SDRAM_BASE+delay)=0xFF;

	return 1;


}




__attribute__((section(".itcmram")))
void FMC_IRQHandler(void)
{
	if(FMC_SDRAM_SR->RE)
	{
		FMC_SDRAM_RTR->CRE=1;
	}
}
