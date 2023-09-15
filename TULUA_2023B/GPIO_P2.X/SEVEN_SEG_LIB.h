
#ifndef SEVEN_SEG_LIB_H
#define	SEVEN_SEG_LIB_H

#include <xc.h>

#define ANSEL_PORT ANSELB
#define TRIS_PORT  TRISB
#define LAT_PORT   LATB

#define SEGA 0
#define SEGB 1
#define SEGC 2
#define SEGD 3
#define SEGE 4
#define SEGF 5
#define SEGG 6

void decoInit();
void decoCC(char num);
void decoAC(char num);

#endif	/* SEVEN_SEG_LIB_H */

