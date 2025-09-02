#ifndef INC_I2C_SLAVE_H_
#define INC_I2C_SLAVE_H_
#include "stdint.h"
extern uint8_t decodedBits[8];

void decodeByte(uint8_t byte, uint8_t* bitArray);

#endif /* INC_I2C_SLAVE_H_ */
