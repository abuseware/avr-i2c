#include <avr/io.h>

void i2c_speed(uint8_t speed){
  TWBR = ((F_CPU / ( speed * 100000)) - 16)/2;
}

void i2c_start(void){
  TWCR = _BV(TWINT) | _BV(TWSTA) | _BV(TWEN);
  loop_until_bit_is_set(TWCR, TWINT);
}

void i2c_stop(void){
  TWCR = _BV(TWINT)|_BV(TWEN)|_BV(TWSTO);
  loop_until_bit_is_clear(TWCR, TWSTO);
}

void i2c_write(uint8_t data){
  TWDR = data;
  TWCR = _BV(TWINT) | _BV(TWEN);
  loop_until_bit_is_set(TWCR, TWINT);
}

uint8_t i2c_read(uint8_t ack){
  TWCR = ack ? (_BV(TWINT) | _BV(TWEN) | _BV(TWEA)) : (_BV(TWINT) | _BV(TWEN));
  loop_until_bit_is_set(TWCR, TWINT);
  return TWDR;
}
