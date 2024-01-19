/*
  Clear Display 
  Author: Bonezegei (Jofel Batutay)
  Date:  January 2024
*/

#include <Bonezegei_LCD1602_I2C.h>

Bonezegei_LCD1602_I2C lcd(0x27);

void setup() {
  lcd.begin();
  lcd.print("Bonezegei");
  lcd.setPosition(0, 1);      //param1 = X   param2 = Y
  lcd.print("HD44780");
  delay(2000);
  lcd.clear(); 
  lcd.setPosition(0, 0);
  lcd.print("Clear");
}

void loop() {
  delay(1000);
  lcd.setPosition(0, 0);
  lcd.print("Clear");
  delay(1000);
  lcd.clear();            
}
