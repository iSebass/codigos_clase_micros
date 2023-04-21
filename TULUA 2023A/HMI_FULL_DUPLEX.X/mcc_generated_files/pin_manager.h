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

// get/set LM35 aliases
#define LM35_TRIS                 TRISAbits.TRISA0
#define LM35_LAT                  LATAbits.LATA0
#define LM35_PORT                 PORTAbits.RA0
#define LM35_ANS                  ANSELAbits.ANSA0
#define LM35_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LM35_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LM35_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LM35_GetValue()           PORTAbits.RA0
#define LM35_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LM35_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LM35_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LM35_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set POT aliases
#define POT_TRIS                 TRISAbits.TRISA1
#define POT_LAT                  LATAbits.LATA1
#define POT_PORT                 PORTAbits.RA1
#define POT_ANS                  ANSELAbits.ANSA1
#define POT_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define POT_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define POT_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define POT_GetValue()           PORTAbits.RA1
#define POT_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define POT_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set BTNA aliases
#define BTNA_TRIS                 TRISBbits.TRISB0
#define BTNA_LAT                  LATBbits.LATB0
#define BTNA_PORT                 PORTBbits.RB0
#define BTNA_WPU                  WPUBbits.WPUB0
#define BTNA_ANS                  ANSELBbits.ANSB0
#define BTNA_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define BTNA_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define BTNA_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define BTNA_GetValue()           PORTBbits.RB0
#define BTNA_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define BTNA_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define BTNA_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define BTNA_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define BTNA_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define BTNA_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set BTNB aliases
#define BTNB_TRIS                 TRISBbits.TRISB1
#define BTNB_LAT                  LATBbits.LATB1
#define BTNB_PORT                 PORTBbits.RB1
#define BTNB_WPU                  WPUBbits.WPUB1
#define BTNB_ANS                  ANSELBbits.ANSB1
#define BTNB_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define BTNB_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define BTNB_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define BTNB_GetValue()           PORTBbits.RB1
#define BTNB_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define BTNB_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define BTNB_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define BTNB_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define BTNB_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define BTNB_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set BTNC aliases
#define BTNC_TRIS                 TRISBbits.TRISB2
#define BTNC_LAT                  LATBbits.LATB2
#define BTNC_PORT                 PORTBbits.RB2
#define BTNC_WPU                  WPUBbits.WPUB2
#define BTNC_ANS                  ANSELBbits.ANSB2
#define BTNC_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define BTNC_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define BTNC_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define BTNC_GetValue()           PORTBbits.RB2
#define BTNC_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define BTNC_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define BTNC_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define BTNC_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define BTNC_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define BTNC_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set LEDA aliases
#define LEDA_TRIS                 TRISBbits.TRISB3
#define LEDA_LAT                  LATBbits.LATB3
#define LEDA_PORT                 PORTBbits.RB3
#define LEDA_WPU                  WPUBbits.WPUB3
#define LEDA_ANS                  ANSELBbits.ANSB3
#define LEDA_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LEDA_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LEDA_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LEDA_GetValue()           PORTBbits.RB3
#define LEDA_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LEDA_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LEDA_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define LEDA_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define LEDA_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define LEDA_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set LEBB aliases
#define LEBB_TRIS                 TRISBbits.TRISB4
#define LEBB_LAT                  LATBbits.LATB4
#define LEBB_PORT                 PORTBbits.RB4
#define LEBB_WPU                  WPUBbits.WPUB4
#define LEBB_ANS                  ANSELBbits.ANSB4
#define LEBB_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LEBB_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LEBB_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LEBB_GetValue()           PORTBbits.RB4
#define LEBB_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LEBB_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LEBB_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LEBB_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LEBB_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define LEBB_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set LEDC aliases
#define LEDC_TRIS                 TRISBbits.TRISB5
#define LEDC_LAT                  LATBbits.LATB5
#define LEDC_PORT                 PORTBbits.RB5
#define LEDC_WPU                  WPUBbits.WPUB5
#define LEDC_ANS                  ANSELBbits.ANSB5
#define LEDC_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LEDC_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LEDC_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LEDC_GetValue()           PORTBbits.RB5
#define LEDC_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LEDC_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LEDC_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define LEDC_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define LEDC_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define LEDC_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

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