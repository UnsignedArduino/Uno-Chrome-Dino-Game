#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd.h"

void setup() {
  initLCD();
  initButtons();
}

void loop() {
  lcd.clear();
  lcd.home();
  switch (readButtons()) {
    case (UP): {
      lcd.print("UP");
      break;
    }
    case (RIGHT): {
      lcd.print("RIGHT");
      break;
    }
    case (DOWN): {
      lcd.print("DOWN");
      break;
    }
    case (LEFT): {
      lcd.print("LEFT");
      break;
    }
    case (SELECT): {
      lcd.print("SELECT");
      break;
    }
    case (NONE):
    default: {
      lcd.print("NONE");
      break;
    }
  }
  delay(50);
}
