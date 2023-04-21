/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1939
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

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

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set LEDA aliases
#define LEDA_TRIS                 TRISDbits.TRISD0
#define LEDA_LAT                  LATDbits.LATD0
#define LEDA_PORT                 PORTDbits.RD0
#define LEDA_ANS                  ANSELDbits.ANSD0
#define LEDA_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define LEDA_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define LEDA_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define LEDA_GetValue()           PORTDbits.RD0
#define LEDA_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define LEDA_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define LEDA_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define LEDA_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set LEDB aliases
#define LEDB_TRIS                 TRISDbits.TRISD1
#define LEDB_LAT                  LATDbits.LATD1
#define LEDB_PORT                 PORTDbits.RD1
#define LEDB_ANS                  ANSELDbits.ANSD1
#define LEDB_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LEDB_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LEDB_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LEDB_GetValue()           PORTDbits.RD1
#define LEDB_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LEDB_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LEDB_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define LEDB_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set LEDC aliases
#define LEDC_TRIS                 TRISDbits.TRISD2
#define LEDC_LAT                  LATDbits.LATD2
#define LEDC_PORT                 PORTDbits.RD2
#define LEDC_ANS                  ANSELDbits.ANSD2
#define LEDC_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LEDC_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LEDC_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LEDC_GetValue()           PORTDbits.RD2
#define LEDC_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LEDC_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LEDC_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define LEDC_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/