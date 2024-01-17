/*
  This Library is written for HD44780 LCD with PCF8574 I2C IO expander
  Author: Bonezegei (Jofel Batutay)
  Date:  January 2024
  
  PCF8574    HD44780
       P0    RS
       P1    R/W
       P2    E
       P3    *LED+
       P4    D4
       P5    D5
       P6    D6
       P7    D7
*/

#ifndef _BONEZEGEI_LCD1602_I2C_H_
#define _BONEZEGEI_LCD1602_I2C_H_

#include <Arduino.h>
#include <Wire.h>

class Bonezegei_LCD1602_I2C{
public:
  Bonezegei_LCD1602_I2C();
  Bonezegei_LCD1602_I2C(uint8_t addr);

  char begin();
  void write(uint8_t data);

  uint8_t _addr;
  uint8_t p_write;
};

#endif
