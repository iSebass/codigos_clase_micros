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

// get/set LED1 aliases
#define LED1_TRIS                 TRISAbits.TRISA0
#define LED1_LAT                  LATAbits.LATA0
#define LED1_PORT                 PORTAbits.RA0
#define LED1_ANS                  ANSELAbits.ANSA0
#define LED1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED1_GetValue()           PORTAbits.RA0
#define LED1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISAbits.TRISA1
#define LED2_LAT                  LATAbits.LATA1
#define LED2_PORT                 PORTAbits.RA1
#define LED2_ANS                  ANSELAbits.ANSA1
#define LED2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED2_GetValue()           PORTAbits.RA1
#define LED2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED3 aliases
#define LED3_TRIS                 TRISAbits.TRISA2
#define LED3_LAT                  LATAbits.LATA2
#define LED3_PORT                 PORTAbits.RA2
#define LED3_ANS                  ANSELAbits.ANSA2
#define LED3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED3_GetValue()           PORTAbits.RA2
#define LED3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED4 aliases
#define LED4_TRIS                 TRISAbits.TRISA3
#define LED4_LAT                  LATAbits.LATA3
#define LED4_PORT                 PORTAbits.RA3
#define LED4_ANS                  ANSELAbits.ANSA3
#define LED4_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define LED4_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define LED4_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define LED4_GetValue()           PORTAbits.RA3
#define LED4_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define LED4_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define LED4_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define LED4_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set BTN aliases
#define BTN_TRIS                 TRISAbits.TRISA4
#define BTN_LAT                  LATAbits.LATA4
#define BTN_PORT                 PORTAbits.RA4
#define BTN_ANS                  ANSELAbits.ANSA4
#define BTN_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define BTN_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define BTN_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define BTN_GetValue()           PORTAbits.RA4
#define BTN_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define BTN_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define BTN_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define BTN_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

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