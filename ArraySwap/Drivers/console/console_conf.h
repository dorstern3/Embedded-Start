/**
  ******************************************************************************
  * @file    ssd1315.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the ssd1315.c
  *          driver.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2020 STMicroelectronics</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */


/**
 * Private configuration file for the SSD1306 library.
 * This example is configured for STM32F0, I2C and including all fonts.
 */

#ifndef __CONSOLE_CONF_H__
#define __CONSOLE_CONF_H__

// Choose a microcontroller family
//#define STM32F0
//#define STM32F1
//#define STM32F4
//#define STM32L0
//#define STM32L4
#define STM32F3
//#define STM32H7
//#define STM32F7

// Choose a bus
#define SSD1306_USE_I2C
//#define SSD1306_USE_SPI

//you nedd to changh to handle usart tath created by cubemx
#define CONSOLE_UART_HANDLE        huart1
#define COM_POLL_TIMEOUT    	   HAL_MAX_DELAY



#endif /* __CONSOLE_CONF_H__ */




/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
