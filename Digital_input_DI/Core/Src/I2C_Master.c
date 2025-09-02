#include "main.h"
#include "I2C_Master.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;

//#define SIZE 30 ....This line may not be required
#define SLAVEADDRESS 0x12
// uint8_t txData[SIZE]; .....This line may not be required

void writeData(uint8_t *pdata, uint8_t len){
	if(HAL_I2C_Master_Transmit(&hi2c1, SLAVEADDRESS << 1, pdata, len, 1000) == HAL_OK){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_SET);
		HAL_Delay(100);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13,GPIO_PIN_RESET);
	}
}
