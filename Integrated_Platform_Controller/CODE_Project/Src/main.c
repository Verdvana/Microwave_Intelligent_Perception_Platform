/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
	uint8_t	key1;
	uint8_t	key2;
	uint8_t	key3;
	uint8_t	key4;
	uint8_t	key5;
	uint8_t	key6;
	
	int			rem_joggle_time = 800;
	double		off_time		= 9000000;
	int			off_flag		= 0;
	
	uint8_t UART_TX_BUF[1] = "G";
	uint8_t UART_RX_BUF[1];
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
	HAL_UART_Transmit(&huart1,UART_TX_BUF,1,0xffff);
	HAL_UART_Receive_IT(&huart1,(uint8_t*)UART_RX_BUF,1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		

		
		/*
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin|LED3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin|LED5_Pin|LED6_Pin, GPIO_PIN_RESET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin|LED3_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED4_Pin|LED5_Pin|LED6_Pin, GPIO_PIN_SET);
		*/

		if(off_flag){
			if(off_time==0){
				off_flag = 0;
				HAL_GPIO_WritePin(GPIOB, LED1_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, LED6_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
			}
			else
				off_time--;
			};


		
		key1=HAL_GPIO_ReadPin(GPIOB,KEY1_Pin);
		key2=HAL_GPIO_ReadPin(GPIOB,KEY2_Pin);
		key3=HAL_GPIO_ReadPin(GPIOB,KEY3_Pin);
		key4=HAL_GPIO_ReadPin(GPIOA,KEY4_Pin);
		key5=HAL_GPIO_ReadPin(GPIOA,KEY5_Pin);
		key6=HAL_GPIO_ReadPin(GPIOA,KEY6_Pin);
	
		
		if(key1){
			UART_TX_BUF[0] = 'A';
			HAL_UART_Transmit(&huart1,UART_TX_BUF,1,0xffff);
			HAL_Delay(rem_joggle_time);
			off_flag = 1;
			off_time = 9000000;
		}
		if(key2){
			UART_TX_BUF[0] = 'B';
			HAL_UART_Transmit(&huart1,UART_TX_BUF,1,0xffff);
			HAL_Delay(rem_joggle_time);
			off_flag = 0;
			off_time = 9000000;
		}
		if(key3){
			UART_TX_BUF[0] = 'C';
			HAL_UART_Transmit(&huart1,UART_TX_BUF,1,0xffff);
			HAL_Delay(rem_joggle_time);
			off_flag = 1;
			off_time = 9000000;
		}
		if(key4){
			UART_TX_BUF[0] = 'D';
			HAL_UART_Transmit(&huart1,UART_TX_BUF,1,0xffff);
			HAL_Delay(rem_joggle_time);
			off_flag = 1;
			off_time = 9000000;
		}
		if(key5){
			UART_TX_BUF[0] = 'E';
			HAL_UART_Transmit(&huart1,UART_TX_BUF,1,0xffff);
			HAL_Delay(rem_joggle_time);
			off_flag = 0;
			off_time = 9000000;
		}
		if(key6){
			UART_TX_BUF[0] = 'F';
			HAL_UART_Transmit(&huart1,UART_TX_BUF,1,0xffff);
			HAL_Delay(rem_joggle_time);
			off_flag = 1;
			off_time = 9000000;
		}
		
	key1=key2=key3=key4=key5=key6=0;
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
		//UNUSED(huart);
		if(UART_RX_BUF[0] == 'O'){
			HAL_GPIO_WritePin(GPIOB, LED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED6_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
		}
		else if(UART_RX_BUF[0] == 'P'){
			HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_RESET);
		}
		else if(UART_RX_BUF[0] == 'Q'){
			HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_SET);
		}
		else if(UART_RX_BUF[0] == 'R'){
			HAL_GPIO_WritePin(GPIOA, LED6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOB, LED3_Pin, GPIO_PIN_RESET);
		}
		else if(UART_RX_BUF[0] == 'U'){
			HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_RESET);
		}
		else if(UART_RX_BUF[0] == 'V'){
			HAL_GPIO_WritePin(GPIOA, LED5_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED4_Pin, GPIO_PIN_SET);
		}
		else{
			UART_RX_BUF[0] = 'X';
		}
		
		HAL_UART_Receive_IT(&huart1,UART_RX_BUF,1);
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
