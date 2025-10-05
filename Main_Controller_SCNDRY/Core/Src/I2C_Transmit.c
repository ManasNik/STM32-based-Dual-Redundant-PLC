#include "I2C_Transmit.h"
#include "main.h"
#include "string.h"

/* This file contains the function for transmitting the received 8-bit integer value from
 * the input module to the output module.
 * IMPORTANT: For now, we will use separate I2C peripherals for receiving and transmitting to
 * keep it simple. For transmitting, we USE I2C2 PERIPHERAL.
 * The slave address is chosen to be 0x14
 */

extern I2C_HandleTypeDef hi2c2;

//#define SIZE 30 ....This line may not be required

// uint8_t txData[SIZE]; .....This line may not be required

void writeData(uint8_t *pdata,uint8_t devAddress, uint8_t len){
	if(HAL_I2C_Master_Transmit(&hi2c2, devAddress << 1, pdata, len, 1000) == HAL_OK){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
	}
}
