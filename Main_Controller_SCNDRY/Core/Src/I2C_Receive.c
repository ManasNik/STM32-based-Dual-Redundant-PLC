#include "I2C_Receive.h"
#include "main.h"
#include "string.h"
/* This file contains the function to receive data from the input module via I2C.
 * IMPORTANT: For now, we will use separate I2C peripherals for receiving and transmitting to
 * keep it simple.For receiving, we will USE THE I2C1 PERIPHERAL.
 */



extern I2C_HandleTypeDef hi2c1;

/*
 */
uint8_t rxBuffer[3];
uint8_t digital_data;
uint8_t analog_data[2];
uint16_t analog_val;
uint8_t uart_buffer[4];
/* The received byte is then decoded into individual bits using decodeByte function
 * and stored in decodedBits.
 */
uint8_t decodedBits[8] = {0};        // Each bit represents one pin state

/* Function to decode the 8-bit binary value into individual bits
 * representing each pin state
 */
void decodeByte(uint8_t byte, uint8_t* bitArray)
{
    for (int i = 0; i < 8; i++) {
        bitArray[i] = (byte >> i) & 0x01;
    }
}

/* Callback function(Interrupt Service Routine(ISR))
 * Called when the I2C interrupt is triggered.
 */
void HAL_I2C_AddrCallback(I2C_HandleTypeDef *hi2c, uint8_t TransferDirection, uint16_t AddrMatchCode) {
  if (TransferDirection == I2C_DIRECTION_TRANSMIT) {
    HAL_I2C_Slave_Seq_Receive_IT(&hi2c1, rxBuffer, 3, I2C_FIRST_AND_LAST_FRAME); // Get 2 bytes
  } else {
    Error_Handler();
  }
}

/*	Called on completion of ISR
*/
void HAL_I2C_SlaveRxCpltCallback(I2C_HandleTypeDef *hi2c) {

	if(rxBuffer[0] == 0x01){
		digital_data = rxBuffer[1];
		memcpy(&uart_buffer[1],rxBuffer,3); // copy the data to UART buffer
		decodeByte(digital_data, decodedBits); // Decode into bits
	}
	else if(rxBuffer[0] == 0x02){
		analog_data[0] = rxBuffer[1]; //MSB
		analog_data[1] = rxBuffer[2]; //LSB
		memcpy(&uart_buffer[1],rxBuffer,3); // copy the data to UART buffer
		analog_val = ((uint16_t) analog_data[0] << 8) | analog_data[1];
	}
	HAL_I2C_EnableListen_IT(&hi2c1);
}

/* For handling errors
*/
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c) {
  HAL_I2C_DeInit(&hi2c1);
  HAL_Delay(10);
  HAL_I2C_Init(&hi2c1);
  HAL_I2C_EnableListen_IT(&hi2c1);
}
