#include <util/delay.h>
#include "I2C.h"

int main(void){
  uint8_t state = 0;
  
  while(1){
    state ^= 0xFF; 
    twi_start();
    twi_write(0x40);
    twi_write(state);
    twi_stop();
    _delay_ms(500);
  }
}
