
#include "mcc_generated_files/mcc.h"

int statusBTNA, statusBTNB, statusBTNC;
int oldValueA, oldValueB, oldValueC;
void main(void)
{
  
    SYSTEM_Initialize();
    
    oldValueA = BTNA_GetValue();
    oldValueB = BTNB_GetValue();
    oldValueC = BTNC_GetValue();
    

    while (1)
    { 
        statusBTNA = BTNA_GetValue();
        statusBTNB = BTNB_GetValue();
        statusBTNC = BTNC_GetValue();
        
        if( statusBTNA != oldValueA ){
            oldValueA = statusBTNA;
            if(statusBTNA == 0){
                EUSART_Text("*btnA=on#");
            }
            else{
                 EUSART_Text("*btnA=off#");
            }
        }
        if( statusBTNB != oldValueB ){
            oldValueB = statusBTNB;
            if(statusBTNB == 0){
                printf("*btnB=on#");
            }
            else{
                 printf("*btnB=off#");
            }
        }
        if( statusBTNC != oldValueC ){
            oldValueC = statusBTNC;
            if(statusBTNC == 0){
                 printf("*btnC=on#");
            }
            else{
                 printf("*btnC=off#");
            }
        }
        __delay_ms(300);
        
        
    }
}
