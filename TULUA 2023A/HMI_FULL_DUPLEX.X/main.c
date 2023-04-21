

#include "mcc_generated_files/mcc.h"

float temp, volt;
int conver;
int statusBTA,statusBTB,statusBTC;
int statusLA,statusLB,statusLC;

void main(void){
    
    SYSTEM_Initialize();

    while (1){
        
        conver = ADC_GetConversion(0);
        temp = (150.0/306.9)*conver;
        
        conver = ADC_GetConversion(1);
        volt   = (5.0*conver)/1023.0;
        
        statusBTA = BTNA_GetValue();
        statusBTB = BTNB_GetValue();
        statusBTC = BTNC_GetValue();
        
        statusLA = LEDA_GetValue();
        statusLB = LEBB_GetValue();
        statusLC = LEDC_GetValue();
        
        printf("#%5.1f/%3.1f/%d/%d/%d/%d/%d/%d*\r\n",
                temp,volt,statusBTA,statusBTB,statusBTC,
                statusLA,statusLB,statusLC);
        
        __delay_ms(20);
    }
}
