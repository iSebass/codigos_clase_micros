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

// get/set S1 aliases
#define S1_TRIS                 TRISAbits.TRISA0
#define S1_LAT                  LATAbits.LATA0
#define S1_PORT                 PORTAbits.RA0
#define S1_ANS                  ANSELAbits.ANSA0
#define S1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define S1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define S1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define S1_GetValue()           PORTAbits.RA0
#define S1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define S1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define S1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define S1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set S3 aliases
#define S3_TRIS                 TRISAbits.TRISA1
#define S3_LAT                  LATAbits.LATA1
#define S3_PORT                 PORTAbits.RA1
#define S3_ANS                  ANSELAbits.ANSA1
#define S3_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define S3_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define S3_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define S3_GetValue()           PORTAbits.RA1
#define S3_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define S3_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define S3_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define S3_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA2
#define POT_LAT                  LATAbits.LATA2
#define POT_PORT                 PORTAbits.RA2
#define POT_ANS                  ANSELAbits.ANSA2
#define POT_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define POT_GetValue()           PORTAbits.RA2
#define POT_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set A1 aliases
#define A1_TRIS                 TRISAbits.TRISA3
#define A1_LAT                  LATAbits.LATA3
#define A1_PORT                 PORTAbits.RA3
#define A1_ANS                  ANSELAbits.ANSA3
#define A1_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define A1_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define A1_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define A1_GetValue()           PORTAbits.RA3
#define A1_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define A1_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define A1_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define A1_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set A2 aliases
#define A2_TRIS                 TRISAbits.TRISA4
#define A2_LAT                  LATAbits.LATA4
#define A2_PORT                 PORTAbits.RA4
#define A2_ANS                  ANSELAbits.ANSA4
#define A2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define A2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define A2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define A2_GetValue()           PORTAbits.RA4
#define A2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define A2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define A2_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define A2_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set B1 aliases
#define B1_TRIS                 TRISAbits.TRISA5
#define B1_LAT                  LATAbits.LATA5
#define B1_PORT                 PORTAbits.RA5
#define B1_ANS                  ANSELAbits.ANSA5
#define B1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define B1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define B1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define B1_GetValue()           PORTAbits.RA5
#define B1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define B1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define B1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define B1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set B2 aliases
#define B2_TRIS                 TRISAbits.TRISA6
#define B2_LAT                  LATAbits.LATA6
#define B2_PORT                 PORTAbits.RA6
#define B2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define B2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define B2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define B2_GetValue()           PORTAbits.RA6
#define B2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define B2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSD1 = 0; } while(0)

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