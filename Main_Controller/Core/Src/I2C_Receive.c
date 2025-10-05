#include "I2C_Receive.h"
#include "main.h"


/* This file contains the function to receive data from the input module via I2C.
 * IMPORTANT: For now, we will use separate I2C peripherals for receiving and transmitting to
 * keep it simple.For receiving, we will USE THE I2C1 PERIPHERAL.
 */
/*
#define DI_Address 0x10
#define AI_Address 0x11
/*
extern I2C_HandleTypeDef hi2c1;

uint8_t digitalData;
uint8_t analogBuffer[2];
uint16_t analogData;

void digitalRead(void){
	HAL_I2C_Master_Receive_DMA(&hi2c1, DI_Address << 1 , &digitalData, 1);
}

void analogRead(void){
	HAL_I2C_Master_Receive_DMA(&hi2c1, AI_Address << 1 , analogBuffer, 2);
}

void HAL_I2C_MasterRxCpltCallback(I2C_HandleTypeDef *hi2c){
	if(hi2c->Instance == I2C1){
		static uint8_t state = 0;

		if(state == 0){
			state = 1;
			analogRead();
		}
		else{
			analogData = ((uint16_t) analogBuffer[0] << 8) | analogBuffer[1];
			state = 0;
			digitalRead();
		}
	}
}
*/
