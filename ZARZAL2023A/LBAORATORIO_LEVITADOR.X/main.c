#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "UART_LIB.h"
#include "PWM_LIB.h"

#define PIN_TRI   PORTBbits.RB0
#define DIR_TRI   TRISBbits.TRISB0

#define PIN_ECHO  PORTBbits.RB1
#define DIR_ECHO  TRISBbits.TRISB1

#define DIR_M1A   TRISDbits.TRISD0
#define DIR_M1B   TRISDbits.TRISD1
#define PORT_M1A  PORTDbits.RD0
#define PORT_M1B  PORTDbits.RD1

uint16_t getDistance(void);
void Motor_Start();
void Motor_Stop();

float distancia;
char strUART[50]=" ";
uint8_t duty=70;

//VARIABLES DE CONTROL
float Kp=0.5, Kd=0.4, Ki=0.1;
float error, suma=0, ref=80, actual;

void main(void){
    ADCON1  = 0x0F;
    
    DIR_TRI   = 0;
    DIR_ECHO = 1; 
    
    DIR_M1A = 0;
    DIR_M1B = 0;
    
    PWM1_Init(2000);
    PWM1_Set_Duty(duty);
    PWM1_Start();
     
    UART_Config uartConfig;
    
    uartConfig.baud_rate    = 9600;       // VELOCIDAD DE BITS/SEG
    uartConfig.data_bits    = 8;          // 8 BITS DATOS
    uartConfig.parity       = 0;          // PARITY NONE
    uartConfig.stop_bits    = 1;          // 1 BIT PARADA
    
    UART_Init(uartConfig); 
    
    Motor_Start();
    
    while(1){
        actual = getDistance();
        error = ref - actual;
        suma += Ki*error;
        if(suma>100){
            suma=100;
        }
        else if(suma<0){
            suma = 0;
        }
        PWM1_Set_Duty(suma);
        
        sprintf(strUART,"distancia: %0.1f\r\n", actual);
        UART_Write_Text(strUART);
        __delay_ms(1);
    }
    
    return;
}

uint16_t getDistance(void){
    uint16_t count=0;
    PIN_TRI = 1;
    __delay_us(10);
    PIN_TRI = 0;
    
    while(PIN_ECHO == 0);
    while(PIN_ECHO == 1){
        count++;
        __delay_us(58);
    }
    
    return(count);
}

void Motor_Start(){
    PORT_M1A = 1;
    PORT_M1B = 0;
}
void Motor_Stop(){
    PORT_M1A = 0;
    PORT_M1B = 0;
}
