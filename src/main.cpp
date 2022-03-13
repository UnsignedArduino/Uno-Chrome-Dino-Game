#include <Arduino.h>
#include <LiquidCrystal.h>
#include "lcd.h"
#include "config.h"
#include "game.h"

void setup() {
  initLCD();
  initButtons();

  gameInit();

  #if !defined(AUTO_PLAY)
  startScreen();
  #endif
  while (gameTick()) {
    #if defined(AUTO_PLAY)
    if (distanceToNextCacti() == 1) {
      gameJump();
    }
    delay(gameTickDelay);
    #else
    unsigned long startTickDelay = millis();
    while (millis() - startTickDelay < gameTickDelay) {
      if (readButtons() != NONE) {
        gameJump();
      }
    }
    #endif
  }
  endScreen();
}

void loop() {
  
}
