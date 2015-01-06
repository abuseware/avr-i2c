CFLAGS=-Os -std=c99 -pedantic -mmcu=atmega8a -DF_CPU=8000000UL

all: bin hex

bin:
	avr-gcc ${CFLAGS} I2C.c I2C_test.c -o I2C_test.bin

hex:
	avr-objcopy -O ihex I2C_test.bin I2C_test.hex

flash:
	avrdude -c usbasp -p m8 -U flash:w:I2C_test.hex
