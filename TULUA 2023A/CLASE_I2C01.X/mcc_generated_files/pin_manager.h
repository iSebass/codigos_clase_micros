
#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LEDB0 aliases
#define LEDB0_TRIS                 TRISBbits.TRISB0
#define LEDB0_LAT                  LATBbits.LATB0
#define LEDB0_PORT                 PORTBbits.RB0
#define LEDB0_WPU                  WPUBbits.WPUB0
#define LEDB0_ANS                  ANSELBbits.ANSB0
#define LEDB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define LEDB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define LEDB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define LEDB0_GetValue()           PORTBbits.RB0
#define LEDB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define LEDB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define LEDB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define LEDB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define LEDB0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define LEDB0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)

void PIN_MANAGER_Initialize (void);
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/