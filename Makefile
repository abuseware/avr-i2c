CFLAGS=-Os -std=c11 -pedantic -Wall -Wextra -mmcu=atmega328p -DF_CPU=8000000UL
LDFLAGS=-Wl,-O1,-s,--sort-common,--as-needed

all: lib test

lib:
	avr-gcc ${CFLAGS} -c I2C.c -o I2C.o

test: lib
	avr-gcc ${CFLAGS} ${LDFLAGS} I2C.o I2C_test.c -o I2C_test.bin
	avr-objcopy -O ihex I2C_test.bin I2C_test.hex

flash: test
	avrdude -q -c usbasp -p m8 -U flash:w:I2C_test.hex
