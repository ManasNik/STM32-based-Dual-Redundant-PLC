#include "I2C_Slave.h"

// Buffers for raw I2C data
uint8_t rxBuffer[2];     // I2C1
uint8_t rxBuffer2[2];    // I2C2
uint16_t analog_data;
uint16_t analog_data2;

// Timeout for polling
#define I2C_TIMEOUT 2 // ms

// Poll I2C1 (blocking)
void Poll_I2C1(void) {
    if (HAL_I2C_Slave_Receive(&hi2c1, rxBuffer, 2, I2C_TIMEOUT) == HAL_OK) {
        analog_data = ((uint16_t)rxBuffer[0] << 8) | rxBuffer[1];
    }
}

// Poll I2C2 (blocking)
void Poll_I2C2(void) {
    if (HAL_I2C_Slave_Receive(&hi2c2, rxBuffer2, 2, I2C_TIMEOUT) == HAL_OK) {
        analog_data2 = ((uint16_t)rxBuffer2[0] << 8) | rxBuffer2[1];
    }
}
