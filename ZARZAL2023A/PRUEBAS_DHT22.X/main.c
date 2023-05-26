#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART_LIB.h"
#include "DHT22_LIB.h"

void main(void){
    UART1_Init(9600);
    while(1){
        
    }
    return;
}
