CFLAGS=-Os -std=c99 -pedantic -mmcu=atmega8a -DF_CPU=8000000UL

all: lib test

lib:
	avr-gcc ${CFLAGS} -c I2C.c -o I2C.o

test: lib
	avr-gcc ${CFLAGS} I2C.o I2C_test.c -o I2C_test.bin
	avr-objcopy -O ihex I2C_test.bin I2C_test.hex

flash: test
	avrdude -c usbasp -p m8 -U flash:w:I2C_test.hex
