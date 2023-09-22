#include "SEVEN_SEG_LIB.h"

char deco_cc_values[10]={63,6,91,79,102,109,125,7,127,103};
char deco_ac_values[10]={192,249,164,176,153,146,130,248,128,152};

void decoInit(){
    ANSEL_PORT = 0x00;
    TRIS_PORT = 0x00;
}

void decoAC(char num){
     SEGA = (deco_ac_values[num]&1)  != 0 ? 1:0;
     SEGB = (deco_ac_values[num]&2)  != 0 ? 1:0;
     SEGC = (deco_ac_values[num]&4)  != 0 ? 1:0;
     SEGD = (deco_ac_values[num]&8)  != 0 ? 1:0;
     SEGE = (deco_ac_values[num]&16) != 0 ? 1:0;
     SEGF = (deco_ac_values[num]&32) != 0 ? 1:0;
     SEGG = (deco_ac_values[num]&64) != 0 ? 1:0;
}

void decoCC(char num){
    
    SEGA = (deco_cc_values[num]&1)  != 0 ? 1:0;
    SEGB = (deco_cc_values[num]&2)  != 0 ? 1:0;
    SEGC = (deco_cc_values[num]&4)  != 0 ? 1:0;
    SEGD = (deco_cc_values[num]&8)  != 0 ? 1:0;
    SEGE = (deco_cc_values[num]&16) != 0 ? 1:0;
    SEGF = (deco_cc_values[num]&32) != 0 ? 1:0;
    SEGG = (deco_cc_values[num]&64) != 0 ? 1:0;

}