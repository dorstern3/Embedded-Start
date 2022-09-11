/*
 * console.h
 *
 *  Created on: 10 Jul 2022
 *      Author: User
 */

#ifndef CONSOLE_CONSOLE_H_
#define CONSOLE_CONSOLE_H_

#include <stddef.h>
#include <_ansi.h>

_BEGIN_STD_C

#include "console_conf.h"

#if defined(STM32F0)
#include "stm32f0xx_hal.h"
#elif defined(STM32F1)
#include "stm32f1xx_hal.h"
#elif defined(STM32F4)
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#elif defined(STM32L0)
#include "stm32l0xx_hal.h"
#elif defined(STM32L4)
#include "stm32l4xx_hal.h"
#elif defined(STM32F3)
#include "stm32f3xx_hal.h"
#elif defined(STM32H7)
#include "stm32h7xx_hal.h"
#elif defined(STM32F7)
#include "stm32f7xx_hal.h"
#else
#error "  Please modify MCU in consol_conf.h  STM32F0, STM32F1, STM32F3, STM32F4, STM32F7, STM32L0, STM32L4, STM32H7 MCU families. "
#endif

extern UART_HandleTypeDef CONSOLE_UART_HANDLE;


#ifndef CONSOLE_UART_HANDLE
#define CONSOLE_UART_HANDLE        huart1
#endif





_END_STD_C

#endif /* CONSOLE_CONSOLE_H_ */
