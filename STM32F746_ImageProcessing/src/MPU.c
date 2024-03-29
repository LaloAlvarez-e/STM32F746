/*
 * MPU.c
 *
 *  Created on: 12 ago. 2018
 *      Author: InDev
 */

#include "MPU.h"

void MPU_DiscableCacheSRAM2(void)
{
    __DSB();
    __ISB();
	MPU_CTRL->ENABLE=0;

	MPU_RNR->REGION=7;
	MPU_RBAR_R=0x2004C000|0x10|7; //SRAM2
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=1;
	MPU_RASR->TEX=0;
	MPU_RASR->SIZE=13;
	MPU_RASR->XN=1;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;

	MPU_RNR->REGION=6;
	MPU_RBAR_R=0x20000000|0x10|6;  //DTCM
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=1;
	MPU_RASR->TEX=0;
	MPU_RASR->SIZE=15;
	MPU_RASR->XN=1;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;

	MPU_RNR->REGION=5;
	MPU_RBAR_R=0x20010000|0x10|5; //SRAM1
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=1;
	MPU_RASR->TEX=0;
	MPU_RASR->SIZE=17;
	MPU_RASR->XN=1;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;


	MPU_RNR->REGION=4;
	MPU_RBAR_R=0xD0000000|0x10|4; //SDRAM
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=1;
	MPU_RASR->TEX=0;
	MPU_RASR->SIZE=22;
	MPU_RASR->XN=1;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;
/*
	MPU_RNR->REGION=3;
	MPU_RBAR_R=0xD0400000|0x10|3; //SDRAM
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=0;
	MPU_RASR->TEX=4;
	MPU_RASR->SIZE=20;
	MPU_RASR->XN=1;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;
*/
	MPU_RNR->REGION=3;
	MPU_RBAR_R=0x00000000|0x10|3; //ITCM
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=1;
	MPU_RASR->TEX=0;
	MPU_RASR->SIZE=13;
	MPU_RASR->XN=0;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;

	MPU_RNR->REGION=2;
	MPU_RBAR_R=0x08000000|0x10|2; //FLASH
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=1;
	MPU_RASR->TEX=0;
	MPU_RASR->SIZE=19;
	MPU_RASR->XN=0;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;

	MPU_RNR->REGION=1;
	MPU_RBAR_R=0x00200000|0x10|1; //ITCMFLASH
	MPU_RASR->AP=3;
	MPU_RASR->S=1;
	MPU_RASR->B=0;
	MPU_RASR->C=1;
	MPU_RASR->TEX=0;
	MPU_RASR->SIZE=19;
	MPU_RASR->XN=0;
	MPU_RASR->ENABLE=1;
	MPU_CTRL->PRIVDEFENA=1;

	MPU_CTRL->ENABLE=1;
	__DSB();
    __ISB();
}
void MPU_SDRAM(void)
{

	MPU_CTRL->ENABLE=0;

	MPU_CTRL->ENABLE=1;
}
