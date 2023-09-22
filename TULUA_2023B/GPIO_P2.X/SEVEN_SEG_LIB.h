
#ifndef SEVEN_SEG_LIB_H
#define	SEVEN_SEG_LIB_H

#include <xc.h>

#define ANSEL_PORT ANSELB
#define TRIS_PORT  TRISB
#define LAT_PORT   LATB

#define SEGA LATBbits.LATB6
#define SEGB LATBbits.LATB0
#define SEGC LATBbits.LATB2
#define SEGD LATBbits.LATB3
#define SEGE LATBbits.LATB4
#define SEGF LATBbits.LATB5
#define SEGG LATBbits.LATB1

void decoInit();
void decoCC(char num);
void decoAC(char num);

#endif	/* SEVEN_SEG_LIB_H */

