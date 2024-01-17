/*
  BackLight
  Author: Bonezegei (Jofel Batutay)
  Date:  January 2024
*/

#include <Bonezegei_LCD1602_I2C.h>

Bonezegei_LCD1602_I2C lcd(0x27);

void setup() {
  lcd.begin();
  lcd.print("BackLight");
}

void loop() {
  lcd.setBacklight(1);
  lcd.setPosition(0, 1);
  lcd.print("ON ");
  delay(1000);

  lcd.setBacklight(0);
  lcd.setPosition(0, 1);
  lcd.print("OFF");
  delay(1000);
}
