#pragma once
#include <avr/io.h>

typedef enum {
  SLOW =        100,
  FAST =        400,
  FAST_PLUS =   1000,
  HIGH =        3400
} i2c_speed_t;

typedef enum {
  ACK =         1,
  NACK =        0
} i2c_ack_t;


void i2c_speed(i2c_speed_t speed);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(uint8_t data);
uint8_t i2c_read(i2c_ack_t ack);
