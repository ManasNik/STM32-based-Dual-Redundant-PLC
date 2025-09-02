#include "main.h"
#include "I2C_Slave.h"

extern I2C_HandleTypeDef hi2c1;

uint16_t analog_data; // Single variable for analog value
uint8_t rxBuffer[2];
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode) {
  if (TransferDirection == I2C_DIRECTION_TRANSMIT) {
    HAL_I2C_Slave_Seq_Receive_IT(&hi2c1, rxBuffer, 2, I2C_FIRST_AND_LAST_FRAME); // Get 2 bytes
  } else {
    Error_Handler();
  }
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c) {
	analog_data = ((uint16_t) rxBuffer[0] << 8) | rxBuffer[1];
	HAL_I2C_EnableListen_IT(&hi2c1);
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c) {
  HAL_I2C_DeInit(&hi2c1);
  HAL_Delay(10);
  HAL_I2C_Init(&hi2c1);
  HAL_I2C_EnableListen_IT(&hi2c1);
}
