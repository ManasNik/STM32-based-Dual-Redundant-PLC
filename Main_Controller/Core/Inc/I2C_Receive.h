#ifndef INC_I2C_RECEIVE_H
#define INC_I2C_RECEIVE_H

#include "stdint.h"

extern uint8_t rxBuffer[3];
extern uint8_t digital_data;
extern uint8_t analog_data[2];
extern uint16_t analog_val;
extern uint8_t uart_buffer[4];

extern uint8_t decodedBits[8];
void decodeByte(uint8_t byte, uint8_t* bitArray);

#endif
