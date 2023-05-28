#ifndef DHT22_LIB_H_
#define DHT22_LIB_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define DHT22_PORT PORTB  // 
#define DHT22_DDR  DDRB   // 
#define DHT22_PIN  PINB   // 
#define DHT22_BIT  0      // 

#define SUCESS         0
#define ERROR_SINCRO1  1
#define ERROR_SINCRO2  2
#define ERROR_CHECKSUM 3

uint8_t DHT22_ReadData(float *temperature, float *humidity);




#endif /* DHT22_LIB_H_ */