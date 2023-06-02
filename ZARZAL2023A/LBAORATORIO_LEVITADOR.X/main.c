#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
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

#define TOPE_MAX 50

uint16_t getDistance(void);
void Motor_Start();
void Motor_Stop();

float distancia;
char strUART[50]=" ";
int duty=70;

//VARIABLES DE CONTROL
float Kp=0.5, Kd=0.4, Ki=0.1;
float error, suma=0, ref=80, actual, errorAnte;

char letra;
char bufferRx[50]= " ";
int indiceRx = 0, flag_Rx_completed = 0, flag_start_Rx = 0;

void __interrupt() dataRx(){
    
    if( PIR1bits.RC1IF == 1  ){
        
        letra = UART_Read();
        if(letra == '#'){
                flag_Rx_completed = 1;
        }
        else{
            if( letra != '*'){
                bufferRx[indiceRx] = letra;
                indiceRx++;
            }
            
        }
        
        PIR1bits.RC1IF = 0;
    }
    
}

float array_constantes[4];
int indice_array=0;

void main(void){
    ADCON1  = 0x0F;
    
    DIR_TRI   = 0;
    DIR_ECHO = 1; 
    
    DIR_M1A = 0;
    DIR_M1B = 0;
    
    
    
    PWM1_Init(2000);
    PWM1_Set_Duty( (uint8_t)(duty) );
    PWM1_Start();
     
    UART_Config uartConfig;
    
    uartConfig.baud_rate    = 9600;       // VELOCIDAD DE BITS/SEG
    uartConfig.data_bits    = 8;          // 8 BITS DATOS
    uartConfig.parity       = 0;          // PARITY NONE
    uartConfig.stop_bits    = 1;          // 1 BIT PARADA
    
    UART_Init(uartConfig); 
    
    Motor_Start();
    
    INTCONbits.GIE  = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.RC1IE  = 1;
    
    while(1){
        
        if(flag_Rx_completed== 1){
            char *pch;
            char *pch2;
            pch = strtok(bufferRx, "/");
            while (pch != NULL) {
                array_constantes[indice_array]=atof(pch);
                pch = strtok(NULL, "/");
                indice_array++;
            }
            ref = array_constantes[0];
            Kp = array_constantes[1];
            Kd = array_constantes[2];
            Ki = array_constantes[3];
            indice_array=0;
            indiceRx = 0;
            memset(bufferRx,' ',49);
            flag_Rx_completed=0;
        }
        
        
        actual = TOPE_MAX - getDistance();
        error = ref - actual;
        suma += Kp*error + Kd*(error-errorAnte)+Ki*error;
        if(suma>100){
            suma=100;
        }
        else if(suma<0){
            suma = 0;
        }
        PWM1_Set_Duty( (uint8_t) (suma));
        
        sprintf(strUART,"*%0.1f/%03d/%0.2f/%0.2f/%0.2f#\r\n",actual,duty,Kp,Kd,Ki);
        UART_Write_Text(strUART);
        __delay_ms(1);
        errorAnte = error;
    }
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
