#include "main.h"
#include "Data_converter.h"

// Function to create a byte from individual pin inputs
uint8_t getByteData(){

	uint8_t byteData = 0;

	if(HAL_GPIO_ReadPin(D0_GPIO_Port, D0_Pin) == GPIO_PIN_SET){
		byteData |= (1<<0); // LSB (D0 pin)
	}

	if(HAL_GPIO_ReadPin(D1_GPIO_Port, D1_Pin) == GPIO_PIN_SET){
		byteData |= (1<<1);
	}

	if(HAL_GPIO_ReadPin(D2_GPIO_Port, D2_Pin) == GPIO_PIN_SET){
		byteData |= (1<<2);
	}

	if(HAL_GPIO_ReadPin(D3_GPIO_Port, D3_Pin) == GPIO_PIN_SET){
		byteData |= (1<<3);
	}

	if(HAL_GPIO_ReadPin(D4_GPIO_Port, D4_Pin) == GPIO_PIN_SET){
		byteData |= (1<<4);
	}

	if(HAL_GPIO_ReadPin(D5_GPIO_Port, D5_Pin) == GPIO_PIN_SET){
		byteData |= (1<<5);
	}

	if(HAL_GPIO_ReadPin(D6_GPIO_Port, D6_Pin) == GPIO_PIN_SET){
		byteData |= (1<<6);
	}

	if(HAL_GPIO_ReadPin(D7_GPIO_Port, D7_Pin) == GPIO_PIN_SET){
		byteData |= (1<<7); // MSB (D7 pin)
	}

	return byteData;
}
