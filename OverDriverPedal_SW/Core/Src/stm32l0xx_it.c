/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32l0xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32l0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <math.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
//#define DEBOUNCE_DELAY 500

uint16_t last_interrupt_time = 0;

// same value for sync, offset values for pan
uint16_t led_value1 = 0;
uint16_t led_value2 = 0;

uint8_t led_fade_up1 = 1;
uint8_t led_fade_up2 = 0;

uint8_t led1_fade_stop = 0;
uint8_t led2_fade_stop = 1;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_adc;
extern LPTIM_HandleTypeDef hlptim1;
extern TIM_HandleTypeDef htim21;
/* USER CODE BEGIN EV */
void ledprogram_syncfade()
{
	// led pwm ch1
	if(led_value1 < 1)
	{
		led_fade_up1 = 1;
	}
	if(led_value1 > LED_PERIOD_LIMIT) {
		led_fade_up1 = 0;
	}

	if(led_fade_up1)
	{
		led_value1++;
	}
	else
	{
		led_value1--;
	}

	// led pwm ch2
	if(led_value2 < 1)
	{
		led_fade_up2 = 1;
	}
	if(led_value2 > LED_PERIOD_LIMIT) {
		led_fade_up2 = 0;
	}

	if(led_fade_up2)
	{
		led_value2++;
	}
	else
	{
		led_value2--;
	}
}

void ledprogram_panfade()
{
	// led pwm ch1
	if(!led1_fade_stop)
	{

		if(led_value1 < 1)
		{
			led_fade_up1 = 1;
			led1_fade_stop = 1;
			led2_fade_stop = 0;

		}
		if(led_value1 > LED_PERIOD_LIMIT) {
			led_fade_up1 = 0;
		}

		if(led_fade_up1)
		{
			led_value1++;
		}
		else
		{
			led_value1--;
		}
	}
	if(!led2_fade_stop)
	{
		// led pwm ch2
		if(led_value2 < 1)
		{
			led_fade_up2 = 1;
			led2_fade_stop = 1;
			led1_fade_stop = 0;

		}
		if(led_value2 > LED_PERIOD_LIMIT) {
			led_fade_up2 = 0;
		}

		if(led_fade_up2)
		{
			led_value2++;
		}
		else
		{
			led_value2--;
		}
	}

}
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0+ Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32L0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32l0xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI line 4 to 15 interrupts.
  */
void EXTI4_15_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI4_15_IRQn 0 */

	uint16_t interrupt_time = TIM21->CNT;
	if (interrupt_time - last_interrupt_time > (adc_data[0]*2))
	{
		HAL_GPIO_TogglePin(CLEAN_ENABLE_GPIO_Port, CLEAN_ENABLE_Pin);
		HAL_GPIO_TogglePin(FX_ENABLE_GPIO_Port, FX_ENABLE_Pin);
	}
	last_interrupt_time = interrupt_time;

  /* USER CODE END EXTI4_15_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
  /* USER CODE BEGIN EXTI4_15_IRQn 1 */

  /* USER CODE END EXTI4_15_IRQn 1 */
}

/**
  * @brief This function handles DMA1 channel 1 interrupt.
  */
void DMA1_Channel1_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Channel1_IRQn 0 */

  /* USER CODE END DMA1_Channel1_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_adc);
  /* USER CODE BEGIN DMA1_Channel1_IRQn 1 */

  /* USER CODE END DMA1_Channel1_IRQn 1 */
}

/**
  * @brief This function handles LPTIM1 global interrupt / LPTIM1 wake-up interrupt through EXTI line 29.
  */
void LPTIM1_IRQHandler(void)
{
  /* USER CODE BEGIN LPTIM1_IRQn 0 */
	//ledprogram_syncfade();
	ledprogram_panfade();

	TIM2->CCR1 = led_value1;
	TIM2->CCR2 = led_value2;
	//TIM2->CCR3 = led_value;
  /* USER CODE END LPTIM1_IRQn 0 */
  HAL_LPTIM_IRQHandler(&hlptim1);
  /* USER CODE BEGIN LPTIM1_IRQn 1 */

  /* USER CODE END LPTIM1_IRQn 1 */
}

/**
  * @brief This function handles TIM21 global interrupt.
  */
void TIM21_IRQHandler(void)
{
  /* USER CODE BEGIN TIM21_IRQn 0 */

  /* USER CODE END TIM21_IRQn 0 */
  HAL_TIM_IRQHandler(&htim21);
  /* USER CODE BEGIN TIM21_IRQn 1 */

  /* USER CODE END TIM21_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
