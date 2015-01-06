#include <util/delay.h>
#include "I2C.h"

int main(void){
  uint8_t state = 0;
  
  while(1){
    state ^= 0xFF; 
    i2c_start();
    i2c_write(0x40);
    i2c_write(state);
    i2c_stop();
    _delay_ms(500);
  }
}
