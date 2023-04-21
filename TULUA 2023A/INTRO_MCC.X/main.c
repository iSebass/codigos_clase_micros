

#include "mcc_generated_files/mcc.h"

int contador = 0;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1)
    {
        if( BTN_GetValue() == 0 ){
            while(BTN_GetValue() == 0);
            contador++;
        }
        
        PORTA = contador & 0x0F;
    }
}
/**
 End of File
*/