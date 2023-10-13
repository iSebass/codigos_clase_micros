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

extern char currentMenu;
char op=1;

void SystemInit(){
    OSCCON  = 0x38;
    OSCTUNE = 0x00;
    BORCON  = 0x00;
    configurarPuertos();
    lcd_init();
    lcd_disable_blink();
    lcd_disable_cursor();
}
void configurarPuertos(){
    //CONFIGURAMOS LAS ENTRADAS ANALOGICAS
    LM35_Ansel= ANALOG;
    LDR_Ansel = ANALOG;
    LM35_Dir  = IN;
    LDR_Dir   = IN;
    
    //CONFIGURAMOS LOS PINES DEL MOTOR
    IN1A_Ansel = DIGITAL;
    IN2A_Ansel = DIGITAL;
    IN1B_Ansel = DIGITAL;
    IN2B_Ansel = DIGITAL;
    
    IN1A_Dir = OUT;
    IN2A_Dir = OUT;
    IN1B_Dir = OUT;
    IN2B_Dir = OUT;
    
    IN1A_LAT = 0;
    IN2A_LAT = 0;
    IN1B_LAT = 0;
    IN2B_LAT = 0;
    
    //CONFIGURAMOS BTNS
    OPTION_REGbits.nWPUEN = 0;
    WPUB = 0x07;
    BTN_UP_Ansel   = DIGITAL;
    BTN_DOWN_Ansel = DIGITAL;
    BTN_SEL_Ansel  = DIGITAL;
    
    BTN_UP_Dir   = IN;
    BTN_DOWN_Dir = IN;
    BTN_SEL_Dir  = IN;
    
}
void motorA_Derecha(){
    IN1A_LAT = 1;
    IN2A_LAT = 0;
}
void motorA_Izquierda(){
    IN1A_LAT = 0;
    IN2A_LAT = 1;
}
void motorA_Frenar(){
    IN1A_LAT = 0;
    IN2A_LAT = 0;
}
void motorB_Derecha(){
    IN1B_LAT = 1;
    IN2B_LAT = 0;
}
void motorB_Izquierda(){
    IN1B_LAT = 0;
    IN2B_LAT = 1;
}
void motorB_Frenar(){
    IN1B_LAT = 0;
    IN2B_LAT = 0;
}

void MenuPPAL(){
    lcd_out(1,1,"     MENU PPAL      ");
    lcd_out(2,1,"1.Sensor  2.Motores ");
    lcd_out(3,1,"3.Reloj             ");
    lcd_out(4,1,"OP:                 ");
    lcd_char(4,4,op+48);
    switch(op){
        case 1: lcd_char(2,9,'<');
                lcd_char(2,20,' ');
                lcd_char(3,8,' ');
                break;
        case 2: lcd_char(2,9,' ');
                lcd_char(2,20,'<');
                lcd_char(3,8,' ');
                break;
        case 3: lcd_char(2,9,' ');
                lcd_char(2,20,' ');
                lcd_char(3,8,'<');
                break;
    }
    if( BTN_UP_PORT == 0 ){
        while(!BTN_UP_PORT);
        op++;
        if(op>3)
            op=1;
    }
    if( BTN_DOWN_PORT == 0 ){
        while(!BTN_DOWN_PORT);
        op--;
        if(op<1)
            op=3;
    }
    if( BTN_SEL_PORT == 0 ){
        while(!BTN_SEL_PORT);
        switch(op){
            case 1: currentMenu=SENSORES; break;
            case 2: currentMenu=MMOTORES; break;
            case 3: currentMenu=RELOJ; break;
        }
        op=1;
    }
    
}
void MenuSensores(){
    lcd_out(1,1,"   MENU SENSORES    ");
    lcd_out(2,1,"1.TEMP    2.LDR     ");
    lcd_out(3,1,"3.DHT     4.BACK    ");
    lcd_out(4,1,"OP:                 ");
    lcd_char(4,4,op+48);
    switch(op){
        case 1: lcd_char(2,7,'<');
                lcd_char(2,16,' ');
                lcd_char(3,6,' ');
                lcd_char(3,17,' ');
                break;
        case 2: lcd_char(2,7,' ');
                lcd_char(2,16,'<');
                lcd_char(3,6,' ');
                lcd_char(3,17,' ');
                break;
        case 3: lcd_char(2,7,' ');
                lcd_char(2,16,' ');
                lcd_char(3,6,'<');
                lcd_char(3,17,' ');
                break;
        case 4: lcd_char(2,7,' ');
                lcd_char(2,16,' ');
                lcd_char(3,6,' ');
                lcd_char(3,17,'<');
                break;
    }
    if( BTN_UP_PORT == 0 ){
        while(!BTN_UP_PORT);
        op++;
        if(op>4)
            op=1;
    }
    if( BTN_DOWN_PORT == 0 ){
        while(!BTN_DOWN_PORT);
        op--;
        if(op<1)
            op=4;
    }
    if( BTN_SEL_PORT == 0 ){
        while(!BTN_SEL_PORT);
        switch(op){
            case 1: currentMenu=MTEMP; break;
            case 2: currentMenu=MLDR; break;
            case 3: currentMenu=MDHT; break;
            case 4: currentMenu=MPPAL; break;
        }
        op=1;
    }
    
    
}
void MenuMotores(){
    //           1234567890123456789
    lcd_out(1,1,"   MENU MOTORES     ");
    lcd_out(2,1,"1.MOTORA            ");
    lcd_out(3,1,"2.MOTORB    3.BACK  ");
    lcd_out(4,1,"OP:                 ");
    lcd_char(4,4,op+48);
    
    switch(op){
        case 1: lcd_char(2,9,'<');
                lcd_char(3,9,' ');
                lcd_char(3,19,' ');
                break;
        case 2: lcd_char(2,9,' ');
                lcd_char(3,9,'<');
                lcd_char(3,19,' ');
                break;
        case 3: lcd_char(2,9,' ');
                lcd_char(3,9,' ');
                lcd_char(3,19,'<');
                break;
    
    }
    if( BTN_UP_PORT == 0 ){
        while(!BTN_UP_PORT);
        op++;
        if(op>3)
            op=1;
    }
    if( BTN_DOWN_PORT == 0 ){
        while(!BTN_DOWN_PORT);
        op--;
        if(op<1)
            op=3;
    }
    if( BTN_SEL_PORT == 0 ){
        while(!BTN_SEL_PORT);
        switch(op){
            case 1: currentMenu=MMOTORA; break;
            case 2: currentMenu=MMOTORB; break;
            case 3: currentMenu=MPPAL; break;
            
        }
        op=1;
    }
    
    
}
void MenuMotorA(){
    //           12345678901234567890
    lcd_out(1,1,"   MENU MOTOR A     ");
    lcd_out(2,1,"1.DERECHA           ");
    lcd_out(3,1,"2.IZQUIERDA  3.BCK  ");
    lcd_out(4,1,"OP:                 ");
    lcd_char(4,4,op+48);
    switch(op){
        case 1: lcd_char(2,10,'<');
                lcd_char(3,12,' ');
                lcd_char(3,19,' ');
                break;
        case 2: lcd_char(2,10,' ');
                lcd_char(3,12,'<');
                lcd_char(3,19,' ');
                break;
        case 3: lcd_char(2,10,' ');
                lcd_char(3,12,' ');
                lcd_char(3,19,'<');
                break;
    
    }
    if( BTN_UP_PORT == 0 ){
        while(!BTN_UP_PORT);
        op++;
        if(op>3)
            op=1;
    }
    if( BTN_DOWN_PORT == 0 ){
        while(!BTN_DOWN_PORT);
        op--;
        if(op<1)
            op=3;
    }
    if( BTN_SEL_PORT == 0 ){
        while(!BTN_SEL_PORT);
        switch(op){
            case 1: motorA_Derecha(); break;
            case 2: motorA_Izquierda(); break;
            case 3: currentMenu=MMOTORES; break;
            
        }
        op=1;
    }
}
void MenuMotorB(){
    lcd_out(1,1,"   MENU MOTOR B     ");
    lcd_out(2,1,"1.DERECHA           ");
    lcd_out(3,1,"2.IZQUIERDA  3.BCK  ");
    lcd_out(4,1,"OP:                 ");
}

void MenuRELOJ(){
    
}
void MenuTemp(){
    
}
void MenuLDR(){
    
}
void MenuDHT(){
    
}
