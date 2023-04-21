/* 
 * File:   CONFIG.h
 * Author: iProf
 *
 * Created on 24 de marzo de 2023, 10:53 AM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#define _XTAL_FREQ 20000000UL

#include "ADC_LIB.h"
#include "LCD_LIB.h"

#define MCP_DIR    TRISAbits.TRISA0
#define MCP_SENSOR 0

#define LM35_DIR    TRISAbits.TRISA1
#define LM35_SENSOR 1

#define POT1_DIR    TRISAbits.TRISA2
#define POT1_SENSOR 2

#define BTN_UP_DIR  TRISBbits.TRISB0
#define BTN_UP_PORT PORTBbits.RB0

#define BTN_DOWN_DIR  TRISBbits.TRISB1
#define BTN_DOWN_PORT PORTBbits.RB1

#define BTN_SEL_DIR  TRISBbits.TRISB2
#define BTN_SEL_PORT PORTBbits.RB2

#define MOTOR_A1_DIR  TRISDbits.TRISD2
#define MOTOR_A1_PORT PORTDbits.RD2

#define MOTOR_A2_DIR  TRISBbits.TRISB4
#define MOTOR_A2_PORT PORTBbits.RB4

#define MOTOR_B1_DIR  TRISBbits.TRISB5
#define MOTOR_B1_PORT PORTBbits.RB5

#define MOTOR_B2_DIR  TRISBbits.TRISB6
#define MOTOR_B2_PORT PORTBbits.RB6

#define IN   1
#define OUT  0
#define HIGH 1
#define LOW  0
#define ON   1
#define OFF  0

void SystemInit(void);

void girarMA_Derecha(void);
void girarMA_Izquierda(void);
void pararMA(void);

void girarMB_Derecha(void);
void girarMB_Izquierda(void);
void pararMB(void);

float getLM35(void);
float getMCP(void);
float getPOT(void);


void menuPPAL(void);
void menuSelM(void);
void menuM1(void);
void menuM2(void);
void menuSensores(void);

#endif	

