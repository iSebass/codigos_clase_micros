#include "DS1307LIB.h"


void setHH(char hh){
    I2C_Start();
    I2C_Wr(RTC_DIR);
    I2C_Wr(DIR_HH);
    I2C_Wr(hh);
    I2C_Stop();
}
void setMM(char mm){
    I2C_Start();
    I2C_Wr(RTC_DIR);
    I2C_Wr(DIR_MM);
    I2C_Wr(mm);
    I2C_Stop();
}
void setSS(char ss){
    I2C_Start();
    I2C_Wr(RTC_DIR);
    I2C_Wr(DIR_SS);
    I2C_Wr(ss);
    I2C_Stop();
}
void setDAY(char day){
    I2C_Start();
    I2C_Wr(RTC_DIR);
    I2C_Wr(DIR_DAY);
    I2C_Wr(day);
    I2C_Stop();
}
void setDATE(char date){
    I2C_Start();
    I2C_Wr(RTC_DIR);
    I2C_Wr(DIR_DATE);
    I2C_Wr(date);
    I2C_Stop();
}
void setMONTH(char month){
    I2C_Start();
    I2C_Wr(RTC_DIR);
    I2C_Wr(DIR_MONTH);
    I2C_Wr(month);
    I2C_Stop();
}
void setYEAR(char year){
    I2C_Start();
    I2C_Wr(RTC_DIR);
    I2C_Wr(DIR_YEAR);
    I2C_Wr(year);
    I2C_Stop();
}

char getHH(void);
char getMM(void);
char getSS(void);
char getDAY(void);
char getDATE(void);
char getMONTH(void);
char getYEAR(void);
