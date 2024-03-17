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
  Wire.begin();
  //if (Wire.begin()) {
    write(0x00);
    write4Bit(0x03);
    delayMicroseconds(4500);
    write4Bit(0x03);
    delayMicroseconds(4500);
    write4Bit(0x03);
    delayMicroseconds(150);
    write4Bit(0x02);

    write4Bit(0x02);
    write4Bit(0x0C);
    write4Bit(0x00);
    write4Bit(0x08);
    write4Bit(0x00);
    write4Bit(0x01);
    write4Bit(0x00);
    write4Bit(0x06);

    write4Bit(0x00);
    write4Bit(0x0F);
    setBacklight(1);
  //  return 1;
  //} else {
    return 1;
  //}
}

void Bonezegei_LCD1602_I2C::write(uint8_t data) {
  Wire.beginTransmission(_addr);
  Wire.write(data);
  Wire.endTransmission();
}

void Bonezegei_LCD1602_I2C::latch() {
  p_write = p_write & 0xF9;
  write(p_write);
  delay(1);
  p_write = p_write | 0x04;
  write(p_write);
  delay(1);
  p_write = p_write & 0xF9;
  write(p_write);
  delayMicroseconds(100);
}

void Bonezegei_LCD1602_I2C::write4Bit(uint8_t data) {
  p_write &= 0x0F;
  p_write |= data << 4;
  latch();
}

void Bonezegei_LCD1602_I2C::writeByte(uint8_t data) {
  write4Bit(data >> 4);
  write4Bit(data);
}

void Bonezegei_LCD1602_I2C::writeCommand(uint8_t data) {
  p_write = p_write & 0xF8;  // RS LOW
  write(p_write);
  writeByte(data);
}
void Bonezegei_LCD1602_I2C::writeData(uint8_t data) {
  p_write = p_write | 0x01;  // RS HIGH
  write(p_write);
  writeByte(data);
}

void Bonezegei_LCD1602_I2C::setPosition(uint8_t x, uint8_t y) {
  if (y == 0) {
    writeCommand(0x80 | x);
  }
  if (y == 1) {
    writeCommand(0x80 | 0x40 | x);
  }
}
void Bonezegei_LCD1602_I2C::print(const char *str) {
  while (*str) {
    writeData(*str);
    str += 1;
  }
}

void Bonezegei_LCD1602_I2C::clear(){
   writeCommand(0x01);
}

void Bonezegei_LCD1602_I2C::setBacklight(uint8_t data) {
  p_write=0;
  if (data) {
    p_write |= 0x08;
    write(p_write);
  } else {
    p_write &= 0xF7;
    write(p_write);
  }
  delay(50);
}
