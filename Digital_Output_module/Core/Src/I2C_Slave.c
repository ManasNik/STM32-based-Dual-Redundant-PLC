#include "main.h"
#include "I2C_Slave.h"


extern I2C_HandleTypeDef hi2c1;

uint8_t rxBuffer[1] = {0};           // Only 1 byte needed for digital inputs
uint8_t decodedBits[8] = {0};        // Each bit represents one pin state

void decodeByte(uint8_t byte, uint8_t* bitArray)
{
    for (int i = 0; i < 8; i++) {
        bitArray[i] = (byte >> i) & 0x01;
    }
}

void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode) {
  if (TransferDirection == I2C_DIRECTION_TRANSMIT) {
    HAL_I2C_Slave_Seq_Receive_IT(&hi2c1, rxBuffer, 1, I2C_FIRST_AND_LAST_FRAME); // Get 2 bytes
  } else {
    Error_Handler();
  }
}

void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c) {
	  decodeByte(rxBuffer[0], decodedBits); // Decode into bits
	  HAL_I2C_EnableListen_IT(&hi2c1);
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c) {
  HAL_I2C_DeInit(&hi2c1);
  HAL_Delay(10);
  HAL_I2C_Init(&hi2c1);
  HAL_I2C_EnableListen_IT(&hi2c1);
}
