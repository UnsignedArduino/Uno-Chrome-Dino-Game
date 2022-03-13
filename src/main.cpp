#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd.h"
#include "game.h"

void setup() {
  initLCD();
  initButtons();

  gameInit();

  startScreen();
}

void loop() {
  
}
