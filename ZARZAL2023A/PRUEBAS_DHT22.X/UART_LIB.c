#include "UART_LIB.h"

static char _uart_buffer_[50];

void UART1_Init(unsigned long baudrate){
	
		unsigned int regUBRR = F_CPU/(baudrate*16) - 1;
		
		// Cargamos los valores de BAUDRATE en los registros UBRR;
		UBRR0H = (unsigned char) (regUBRR>>8);
		UBRR0L = (unsigned char) (regUBRR>>0);
		
		//Configuramos modo de operacion de 8 bits de datos;
		UCSR0B &= ~(1<<UCSZ00);
		UCSR0C |=  (1<<UCSZ01)|(1<<UCSZ00);
		
		//Sin paridad;
		UCSR0C &= ~( (1<<UPM01)|(1<<UPM00) );
		
		//Modo asincrono;
		UCSR0C &= ~( (1<<UMSEL01)|(1<<UMSEL00) );
		
		//Habilitamos los pines Tx Rx;
		UCSR0B |= ( (1<<RXEN0)|(1<<TXEN0) );
		
		
}

void UART1_Transmit_char(unsigned char data){
	// Espera a que el registro de transmisión esté vacío
	while (!(UCSR0A & (1 << UDRE0)));
	// Carga el dato en el registro de transmisión
	UDR0 = data;
}

void UART1_Transmit_Text(char *texto){
	while(*texto){
		UART1_Transmit_char(*texto);
		texto++;
	}
}

void UART1_Transmit_Printf(char *str, ...){
	
	va_list args;
	va_start(args,str);
	vsnprintf(_uart_buffer_, 51, str, args);
	va_end(args);
	UART1_Transmit_Text(_uart_buffer_);
	
}

bool UART1_DataAvailable(void){
	return ( UCSR0A &(1<<RXC0) );
}

unsigned char UART1_Receive(void) {
	while (!(UCSR0A & (1<<RXC0))); // Espera hasta que se reciba un byte completo
	return UDR0; // Retorna el byte recibido
}
