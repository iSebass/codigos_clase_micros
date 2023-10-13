/* 
 * File:   SOLUCION.h
 * Author: iProf
 *
 * Created on October 12, 2023, 7:22 PM
 */

#ifndef SOLUCION_H
#define	SOLUCION_H

#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "LCD_LIB.h"
#include "ADC_LIB.h"

#define IN1A_Dir   TRISBbits.TRISB3
#define IN1A_Ansel ANSELBbits.ANSB3
#define IN1A_LAT   LATBbits.LATB3
#define IN2A_Dir   TRISBbits.TRISB4
#define IN2A_Ansel ANSELBbits.ANSB4
#define IN2A_LAT   LATBbits.LATB4

#define IN1B_Dir   TRISDbits.TRISD2
#define IN1B_Ansel ANSELDbits.ANSD2
#define IN1B_LAT   LATDbits.LATD2
#define IN2B_Dir   TRISDbits.TRISD3
#define IN2B_Ansel ANSELDbits.ANSD3
#define IN2B_LAT   LATDbits.LATD3

#define BTN_UP_Dir    TRISBbits.TRISB0
#define BTN_UP_Ansel  ANSELBbits.ANSB0
#define BTN_UP_PORT   PORTBbits.RB0

#define BTN_DOWN_Dir    TRISBbits.TRISB1
#define BTN_DOWN_Ansel  ANSELBbits.ANSB1
#define BTN_DOWN_PORT   PORTBbits.RB1

#define BTN_SEL_Dir    TRISBbits.TRISB2
#define BTN_SEL_Ansel  ANSELBbits.ANSB2
#define BTN_SEL_PORT   PORTBbits.RB2

#define LM35_Dir       TRISAbits.TRISA0
#define LM35_Ansel     ANSELAbits.ANSA0
#define LDR_Dir        TRISAbits.TRISA1
#define LDR_Ansel      ANSELAbits.ANSA1

#define IN  1
#define OUT 0
#define ANALOG 1
#define DIGITAL 0

void SystemInit();
void configurarPuertos();
void motorA_Derecha();
void motorA_Izquierda();
void motorA_Frenar();
void motorB_Derecha();
void motorB_Izquierda();
void motorB_Frenar();


void MenuPPAL();
void MenuSensores();
void MenuMotores();
void MenuRELOJ();
void MenuTemp();
void MenuLDR();
void MenuMotorA();
void MenuMotorB();
void MenuDHT();


#endif	/* SOLUCION_H */

