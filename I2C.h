#pragma once

#define I2C_FAST 4
#define I2C_SLOW 1

#define I2C_ACK 1
#define I2C_NOACK 0

void i2c_speed(uint8_t speed);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(uint8_t data);
uint8_t i2c_read(uint8_t ack);
