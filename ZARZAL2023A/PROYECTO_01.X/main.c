#include <xc.h>
#include <stdio.h>
#include "CONFIG.h"

char strLCD[20]=" ";

float pot, mcp, lm35;

enum{
    menuPAL=1,
    menuSelMotor,
    menuFuncM1,
    menuFuncM2,
    menuSen
};

int currentMenu=menuPAL;


void main(void){
    SystemInit();
    
    while(1){
        
        switch(currentMenu){
            case menuPAL:      menuPPAL();     break;
            case menuSelMotor: menuSelM();     break;
            case menuFuncM1:   menuM1();       break;
            case menuFuncM2:   menuM2();       break;
            case menuSen:      menuSensores(); break;
        }
   
        
    }
    
    return;
}
