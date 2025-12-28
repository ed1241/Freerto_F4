#include "stm32f4xx_hal.h"
#include "sw.h"





void SW_InitEvent(void){
	GPIO_InitTypeDef GPIO_InitType;
	//SW8
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GPIO_InitType.Pin = GPIO_PIN_2;
	GPIO_InitType.Mode = GPIO_MODE_EVT_RISING_FALLING;//配置为事件模式
	GPIO_InitType.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA,&GPIO_InitType);
}



void SW_InitEventOut(void){
	GPIO_InitTypeDef GPIO_InitType;
	//PA3
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	GPIO_InitType.Pin = GPIO_PIN_3;
	GPIO_InitType.Mode = GPIO_MODE_AF_PP;
	GPIO_InitType.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_InitType);
    
	HAL_GPIOEx_ConfigEventout(AFIO_EVENTOUT_PORT_A,AFIO_EVENTOUT_PIN_3);
    //用于配置事件输出引脚，所有事件都会使该输出引脚输出一个脉冲
    
	HAL_GPIOEx_EnableEventout();//开启输出事件
}

