/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <console.h>
#include <stdint.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
 UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
/* USER CODE BEGIN PFP */
int LongArray(int* LongArr1,int* LongArr2);
void ReceiveNumber(int* Arr1,int* Arr2, int* LongArr1,int* LongArr2);
void PrintArray(int* Arr1,int* Arr2, int* LongArr1,int* LongArr2);
void SwapArray(int* Arr1,int* Arr2, int* LongArr1,int* LongArr2);



/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */

//  OPTION 1- FUNCTION
fflush(stdout);
setvbuf( stdin, NULL, _IONBF, 0 );

int LongArr1;
int LongArr2;
LongArray(&LongArr1,&LongArr2);

int Arr1[LongArr1];
int Arr2[LongArr2];
ReceiveNumber(&Arr1,&Arr2,&LongArr1,&LongArr2);
printf("Contents of Array1 and Array2  before the swap \r\n");
PrintArray(&Arr1,&Arr2,&LongArr1,&LongArr2);
SwapArray(&Arr1,&Arr2,&LongArr1,&LongArr2);
printf("Contents of Array1 and Array2 after the swap \r\n");
PrintArray(&Arr1,&Arr2,&LongArr1,&LongArr2);


//  OPTION 2
//  int LongArr1;
//  int LongArr2;
//  int temp;
//  int i=0;
//  int j=0;
//  int lenSwap;
//
//  fflush(stdout);
//  setvbuf( stdin, NULL, _IONBF, 0 );
//
//  printf("Array swap \r\n");
//  printf("Enter long Array1 and Array2  \r\n");
//  scanf("%d %d",&LongArr1,&LongArr2);
//
//  if(LongArr1<=0 || LongArr2<=0 )
//  {
//	  printf("error \r\n");
//	  return 0;
//  }
//
//  int Arr1[LongArr1];
//  int Arr2[LongArr2];
//
//// receive number to Arr1
//  for(i=0;i<LongArr1;i++){
//	  printf("Enter index %d of Array-1: \r\n",i);
//	  scanf("%d",&Arr1[i]);
//}
//
//// receive number to Arr2
//  for(j=0;j<LongArr2;j++){
//	  printf("Enter index %d of Array-2: \r\n",j);
//	  scanf("%d",&Arr2[j]);
//}
//
//// Contents of Array1 before the swap
//  printf("Contents of Array1 before the swap \r\n");
//  for(i=0;i<LongArr1;i++){
//  	  printf("%d \r\n",Arr1[i]);
//  }
//// Contents of Array2 before the swap
//  printf("Contents of Array2 before the swap \r\n");
//  for(j=0;j<LongArr2;j++){
//    	  printf("%d \r\n",Arr2[j]);
//    }
//
////Swap Arr1 and Arr2
//  if(LongArr1 < LongArr2)
//  {
//	  lenSwap=LongArr1;
//  }
//  else{
//	  lenSwap=LongArr2;
//  }
//
//    for(i=0,j=0;i<lenSwap;i++,j++)
//    {
//  	 temp=Arr2[j];
//  	  Arr2[j]=Arr1[i];
//  	  Arr1[i]=temp;
//    }
//
//// Contents of Array1 after the swap
//    printf("Contents of Array1 after the swap \r\n");
//      for(i=0;i<LongArr1;i++){
//      	  printf("%d \r\n",Arr1[i]);
//      }
//// Contents of Array2 after the swap
//     printf("Contents of Array2 after the swap \r\n");
//       for(j=0;j<LongArr2;j++){
//         	  printf("%d \r\n",Arr2[j]);
//         }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  huart1.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */
int LongArray(int* LongArr1,int* LongArr2)
  {
	printf("Array swap \r\n");
	printf("Enter long Array1 and Array2 \r\n");
	scanf("%d %d",LongArr1,LongArr2);

	  if(*LongArr1<=0 || *LongArr2<=0 )
	  {
		  printf("error \r\n");
		  return 0;
	  }
  }

void ReceiveNumber(int* Arr1,int* Arr2,int* LongArr1,int* LongArr2)
{
	int i=0;
	int j=0;
	//receive number to Arr1
	  for(i=0;i<*LongArr1;i++){
		  printf("Enter index %d of Array-1: \r\n",i);
		  scanf("%d",&Arr1[i]);
	}

	// receive number to Arr2
	  for(j=0;j<*LongArr2;j++){
		  printf("Enter index %d of Array-2: \r\n",j);
		  scanf("%d",&Arr2[j]);
	}
}

void PrintArray(int* Arr1,int* Arr2, int* LongArr1,int* LongArr2)
{
	int i=0;
	int j=0;
    //	Array1
	  for(i=0;i<*LongArr1;i++){
	  	  printf("%d \r\n",Arr1[i]);
	  }
	// Array2
	  for(j=0;j<*LongArr2;j++){
	    	  printf("%d \r\n",Arr2[j]);
	    }
}

void SwapArray(int* Arr1,int* Arr2, int* LongArr1,int* LongArr2)
{
	//Swap Arr1 and Arr2
	int temp;
	int i=0;
	int j=0;
	int lenSwap;
	  if(*LongArr1 < *LongArr2)
	  {
		  lenSwap=*LongArr1;
	  }
	  else{
		  lenSwap=*LongArr2;
	  }

	    for(i=0,j=0;i<lenSwap;i++,j++)
	    {
	  	 temp=Arr2[j];
	  	  Arr2[j]=Arr1[i];
	  	  Arr1[i]=temp;
	    }
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
