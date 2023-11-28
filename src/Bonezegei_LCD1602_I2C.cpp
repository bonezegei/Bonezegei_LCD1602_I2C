/*
  This Library is written for HD44780 LCD with PCF8574 I2C IO expander
  Author: Bonezegei (Jofel Batutay)
  Date:  November 2023 
*/

#include "Bonezegei_LCD1602_I2C.h"

Bonezegei_LCD1602_I2C::Bonezegei_LCD1602_I2C(){
  
}

Bonezegei_LCD1602_I2C::Bonezegei_LCD1602_I2C(uint8_t addr){
  _addr = addr;
}

char Bonezegei_LCD1602_I2C::begin(){
  if ( pcf8574 ) {
    return 1;
  }
  else {
    return 0;
  }
  
}
