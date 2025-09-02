#include <Data_Output.h>
#include <I2C_Slave.h>
#include "main.h"


void outputs(){
	if(decodedBits[0] == 1){
		HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
	}

	if(decodedBits[1] == 1){
		HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
	}

	if(decodedBits[2] == 1){
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
	}

	if(decodedBits[3] == 1){
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
	}

	if(decodedBits[4] == 1){
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	}

	if(decodedBits[5] == 1){
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
	}

	if(decodedBits[6] == 1){
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
	}

	if(decodedBits[7] == 1){
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
	}
}
