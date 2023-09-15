#include "SEVEN_SEG_LIB.h"

void decoInit(){
    ANSEL_PORT = 0x00;
    TRIS_PORT = 0x00;
}

void decoAC(char num){
    
}

void decoCC(char num){
    LAT_PORT &= ~((1<<SEGA)|(1<<SEGB)|(1<<SEGC)|(1<<SEGD)|(1<<SEGE)|(1<<SEGF)|(1<<SEGG) );
    switch(num){
        case 0: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGB |
                              1<<SEGC |
                              1<<SEGD |
                              1<<SEGE |
                              1<<SEGF);
                break;
        case 1: LAT_PORT |= ( 1<<SEGC | 1<<SEGB);
                break;
        case 2: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGB |
                              1<<SEGD |
                              1<<SEGE |
                              1<<SEGG);
                break;
        case 3: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGB |
                              1<<SEGC |
                              1<<SEGD |
                              1<<SEGG);
                break;
        case 4: LAT_PORT |= ( 1<<SEGB |
                              1<<SEGC |
                              1<<SEGF |
                              1<<SEGG);
                break;
        case 5: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGC |
                              1<<SEGD |
                              1<<SEGG |
                              1<<SEGF);
                break;
        case 6: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGC |
                              1<<SEGD |
                              1<<SEGE |
                              1<<SEGG |
                              1<<SEGF);
                break;
        case 7: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGB |
                              1<<SEGC |
                              1<<SEGF);
                break;
        case 8: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGB |
                              1<<SEGC |
                              1<<SEGD |
                              1<<SEGE |
                              1<<SEGG |
                              1<<SEGF);
                break;
        case 9: LAT_PORT |= ( 1<<SEGA |
                              1<<SEGB |
                              1<<SEGC |
                              1<<SEGG |
                              1<<SEGF);
                break;
    }
}