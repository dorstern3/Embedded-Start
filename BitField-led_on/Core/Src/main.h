/*
 * main.h
 *
 *  Created on: Aug 8, 2022
 *      Author: user
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#include <stdio.h>
#include "stm32f3xx_hal.h"


typedef struct
{
	uint32_t DMA1_en:1;
	uint32_t DMA2_en:1;
	uint32_t SRAM_en:1;
	uint32_t RES1_en:1;
	uint32_t FLITF_en:1;
	uint32_t FMC_en:1;
	uint32_t CRC_en:1;
	uint32_t RES2_en :9;
	uint32_t IOPH_en:1;
	uint32_t IOPA_en:1;
	uint32_t IOPB_en:1;
	uint32_t IOPC_en:1;
	uint32_t IOPD_en:1;
	uint32_t IOPE_en:1;
	uint32_t IOPF_en:1;
	uint32_t IOPG_en:1;
	uint32_t TSCEN_en:1;
	uint32_t RES3_en :3;
	uint32_t ADC12_en :1;
	uint32_t ADC34_en :1;
	uint32_t RES4_en :2;

}RCC_AHBENR_t;

typedef struct
{
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
}GPIOx_MODE_t;

typedef struct
{
	uint32_t pin_0 :1;
	uint32_t pin_1 :1;
	uint32_t pin_2 :1;
	uint32_t pin_3 :1;
	uint32_t pin_4 :1;
	uint32_t pin_5 :1;
	uint32_t pin_6 :1;
	uint32_t pin_7 :1;
	uint32_t pin_8 :1;
	uint32_t pin_9 :1;
	uint32_t pin_10 :1;
	uint32_t pin_11 :1;
	uint32_t pin_12 :1;
	uint32_t pin_13 :1;
	uint32_t pin_14 :1;
	uint32_t pin_15 :1;
	uint32_t RES :16;
}GPIOx_ODR_t;






#endif /* SRC_MAIN_H_ */
