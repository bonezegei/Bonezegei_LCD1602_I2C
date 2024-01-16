/*
  This Library is written for PCF8574 I2C Connected to HD44780 16x2 LCD
  Author: Bonezegei (Jofel Batutay)
  Date:  January 2024
*/

#include "Bonezegei_LCD1602_I2C.h"

Bonezegei_LCD1602_I2C::Bonezegei_LCD1602_I2C() {
}

Bonezegei_LCD1602_I2C::Bonezegei_LCD1602_I2C(uint8_t addr) {
  _addr = addr;
}

char Bonezegei_LCD1602_I2C::begin() {
  if (Wire.begin()) {
    return 1;
  } else {
    return 0;
  }
}

void Bonezegei_LCD1602_I2C::write(uint8_t data) {
}
