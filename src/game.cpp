#include <Arduino.h>
#include "lcd.h"
#include "bitmaps.h"
#include "game.h"

void gameInit() {
  // Doesn't like const byte* so we cast to byte*
  lcd.createChar(DINO, (byte*)dino);
  lcd.createChar(CACTUS, (byte*)cactus);
  lcd.clear();
  lcd.noCursor();
}

void startScreen() {
  lcd.home();
  lcd.println("Chrome Dino game");
  lcd.setCursor(1, HEIGHT - 1);  // Last row
  lcd.write(DINO);
}

void endScreen() {

}

bool tickGame() {

}
