#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd.h"
#include "game.h"

void setup() {
  initLCD();
  initButtons();

  gameInit();

  startScreen();
  while (gameTick()) {
    unsigned long startTickDelay = millis();
    while (millis() - startTickDelay < gameTickDelay) {
      if (readButtons() != NONE) {
        gameJump();
      }
    }
  }
  endScreen();
}

void loop() {
  
}
