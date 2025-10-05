#ifndef __I2C_SLAVE_H
#define __I2C_SLAVE_H

#include "main.h"

// External handles from CubeMX
extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

// Data variables
extern uint16_t analog_data;
extern uint16_t analog_data2;
extern uint8_t rxBuffer2[2];
// Functions to poll each bus
void Poll_I2C1(void);
void Poll_I2C2(void);

#endif
