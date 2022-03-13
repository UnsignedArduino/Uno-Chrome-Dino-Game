#include <Arduino.h>
#include <LiquidCrystal.h>
#include "pinouts.h"

const byte width = 16;
const byte height = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(width, height);
}

void loop() {
  lcd.clear();
  lcd.home();
  lcd.print(millis());
  delay(50);
}
