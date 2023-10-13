#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "SOLUCION.h"

enum{
    MPPAL,
    MMOTORES,
    SENSORES,
    RELOJ,
    MTEMP,
    MLDR,
    MDHT,
    MMOTORA,
    MMOTORB           
};

char currentMenu = MPPAL;


void main(void){
    
    
    SystemInit();
    
    while(1){
        switch(currentMenu){
            case MPPAL:    MenuPPAL(); break;
            case MMOTORES: MenuMotores(); break;
            case RELOJ:    MenuRELOJ(); break;
            case SENSORES: MenuSensores(); break;
            case MTEMP:    MenuTemp(); break;
            case MLDR:     MenuLDR(); break;
            case MDHT:     MenuDHT; break;
            case MMOTORA:  MenuMotorA(); break;
            case MMOTORB:  MenuMotorB(); break;
        }
        __delay_ms(50);
    }
    return;
}
