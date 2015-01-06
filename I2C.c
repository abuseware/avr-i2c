#include <avr/io.h>

void i2c_start(void){
  TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
  while (!(TWCR & (1<<TWINT)));
}

void i2c_stop(void){
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
  while ((TWCR & (1<<TWSTO)));
}

void i2c_write(uint8_t data){
  TWDR = data;
  TWCR = (1<<TWINT) | (1<<TWEN);
  while (!(TWCR & (1<<TWINT)));
}

uint8_t i2c_read(uint8_t ack){
  TWCR = (1 << TWINT) | (1 << TWEN) | (ack << TWEA);
  while (!(TWCR & (1<<TWINT)));
  return TWDR;
}
