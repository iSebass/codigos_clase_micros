
#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
char dataRx;
char tramaRx[100]=" ";
char indiceRx = 0;
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    while (1){
        
        if(EUSART_is_rx_ready()){
            dataRx = EUSART_Read();
            tramaRx[indiceRx]=dataRx;
            if(dataRx == '#'){
                if( strstr(tramaRx,"btnA=on") ) {
                    LEDA_SetHigh();
                }
                if( strstr(tramaRx,"btnA=off") ) {
                    LEDA_SetLow();
                }
                if( strstr(tramaRx,"btnB=on") ) {
                    LEDB_SetHigh();
                }
                if( strstr(tramaRx,"btnB=off") ) {
                    LEDB_SetLow();
                }
                if( strstr(tramaRx,"btnC=on") ) {
                    LEDC_SetHigh();
                }
                if( strstr(tramaRx,"btnC=off") ) {
                    LEDC_SetLow();
                }
                memset(tramaRx,' ',50);
                indiceRx = 0;
            }
            else{
                indiceRx++;
            }
            
        }
        __delay_ms(1);
        
    }
}
/**
 End of File
*/