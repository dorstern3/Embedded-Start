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
#include <console.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef struct
{
	  int rollNumber;
	  char name[10];
	  char branch[20];
	  char dob[10];
	  int semister;
}student_info;
student_info students[10];

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define maxRecord 10

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
//int max_record=10;
// menu
void display_menu(void);
int read_menu_code(void);
void decode_menu_code(int status_menu);
// add new record
int add_new_record(student_info *pstudents);
//  display all records
void display_all_records(student_info *pstudents);
// check exist rollNumber
int check_rollNumber(student_info *pstudents,int rollNumber);
// delete record
int delete_record(student_info *pstudents);

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

//  scanf setting
  fflush(stdout);
  setvbuf( stdin, NULL, _IONBF, 0 );

  int app_continue=1;
  int status_menu;
  printf("Student record managment \r\n");
// if app_continue=0 -> stop
  while(app_continue)
 {
//  display menu
  display_menu();
  status_menu=read_menu_code();
//  if status_menu != 0 -> inside if
  if(status_menu)
  {
  	//Decode the menu code
  	decode_menu_code(status_menu);
  }
  else
  {
//end the application if status_menu = 0;
  	app_continue = 0;
  	printf("Exiting application\r\n");
  }
 }


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

// display_menu function
void display_menu()
{
	printf("Display all records --> 1 \r\n");
	printf("Add new record --> 2 \r\n");
	printf("Delete a record --> 3 \r\n");
	printf("Exit application --> 0 \r\n");
}

// read_menu_code function
int read_menu_code(void)
{
	int input_menu;
	scanf("%d",&input_menu);
	return input_menu;
}

// decode_menu_code function
void decode_menu_code(int status_menu)
{
	int varible;
	switch(status_menu)
	{
	case 1:
	    printf("Display all students records\r\n");
	    display_all_records(students);
	    break;
	case 2:
		printf("Add a new student record\r\n");
		varible=add_new_record(students);
// varible 1 : 0
		varible ? printf("New record added successfully\r\n") : printf("New record add unsuccessfully\r\n");
		break;
	case 3:
		printf("Delete a record\r\n");
		varible=delete_record(students);
// varible 1 : 0
		varible ? printf("record deleted successfully\r\n") : printf("record delete not found\r\n");
		break;
	default:
		printf("Invalid input\r\n");
	}
}

// display_all_records function
void display_all_records(student_info *pstudents)
{
	int list_record_found = 0;
//	goes over all list record students
	for(int i = 0 ; i < maxRecord ; i++)
	{
//		if rollNumber != 0 -> inside if
	   if( pstudents[i].rollNumber)
	     {
		   list_record_found = 1; // found rollNumber
// display the list students
	        printf("rollNumber: %d \r\n",pstudents[i].rollNumber);
	        printf("student Semister: %d \r\n",pstudents[i].semister);
	        printf("student DOB: %s \r\n",pstudents[i].dob);
	        printf("student Branch: %s\r\n",pstudents[i].branch);
	        printf("student Name: %s\r\n",pstudents[i].name);
	     }
	 }
// if list no exist / if list=0
	 if( ! list_record_found)
	    printf("No records found \r\n");

}

// add_new_record function
int add_new_record(student_info *pstudents){
int rollNumber;
int exist;
int i=0;
int flag_add=0;

for(i=0;i<maxRecord;i++)
{
// check if rollNumber exist
  if( ! pstudents[i].rollNumber)
  {
	printf("Enter the rollNumber: \r\n");
	scanf("%d",&rollNumber);
	exist=check_rollNumber(students,rollNumber);

	if(exist == 0)
	{
	  flag_add=1; // add new student in list
	  pstudents[i].rollNumber=rollNumber;
	  printf("Enter the Semister: \r\n");
	  scanf("%d",&pstudents[i].semister);
	  printf("Enter the DOB(mm/dd/yyyy): \r\n");
	  scanf("%s",&pstudents[i].dob);
	  printf("Enter the Branch: \r\n");
	  scanf("%s",&pstudents[i].branch);
	  printf("Enter the Name: \r\n");
	  scanf("%s",&pstudents[i].name);
	 }

	   else
	   {
		printf("roll number already exist \r\n");
	   }
//	Do for loop 1 time and break to menu
	break;
  }


}

// max list
if(i == maxRecord )
{
	printf("No space available\r\n");
}

return flag_add;
}

// check_rollNumber function
int check_rollNumber(student_info *pstudents,int rollNumber){
	int i=0;
	int exist_rollNumber=0;
	for(i=0;i<maxRecord;i++)
	{
		if(pstudents[i].rollNumber==rollNumber)
		{
//			rollNumber already exist
			exist_rollNumber=1;
			break;
		}

	}
	return exist_rollNumber;
}

// delete_record function
int delete_record(student_info *pstudents)
{
	int roll_number;
	int delete_flag=0;

	printf("Enter the roll number of the student you want Delete:\r\n");
	scanf("%d",&roll_number);

	for(int i = 0 ; i < maxRecord ; i++)
	 {
// check if rollNumber exist
	     if( roll_number == pstudents[i].rollNumber)
	       {
	    	 delete_flag=1;
//	    	 function delete
	          memset(&pstudents[i],0,sizeof(student_info));
	          break;
	       }
	  }
	return delete_flag;
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
