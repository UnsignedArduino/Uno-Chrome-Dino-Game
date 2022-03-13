#include <Arduino.h>
#include "lcd.h"
#include "bitmaps.h"
#include "game.h"

unsigned int gameTickDelay = 500;
byte gameTimeInAir = 0;

byte lastCactusTick = 0;

char field[WIDTH];

void gameInit() {
  // Doesn't like const byte* so we cast to byte*
  lcd.createChar(DINO, (byte*)dino);
  lcd.createChar(CACTUS, (byte*)cactus);
  lcd.clear();
  lcd.noCursor();
  memset(field, SPACE, WIDTH);
}

void startScreen() {
  lcd.home();
  lcd.println("Chrome Dino game");
  lcd.setCursor(dinoX, HEIGHT - 1);  // Last row
  lcd.write(DINO);

  while (readButtons() == NONE) {
    ;
  }
}

void endScreen() {
  lcd.home();
  lcd.print("Game over");
  drawField();
}

bool gameTick() {
  lcd.clear();
  shiftFieldLeft();
  if (field[dinoX] != SPACE && gameTimeInAir == 0) {
    field[dinoX] = CACTUS;
    return false;
  }
  if (timeForCactus()) {
    field[WIDTH - 1] = CACTUS;
  }
  if (gameTimeInAir > 0) {
    if (field[dinoX] == DINO) {
      field[dinoX] = SPACE;
    }
    gameTimeInAir --;
  } else {
    field[dinoX] = DINO;
  }
  drawField();
  lcd.setCursor(dinoX, HEIGHT - 2);
  if (gameTimeInAir > 0) {
    lcd.write(DINO);
  } else {
    lcd.write(SPACE);
    lcd.setCursor(dinoX, HEIGHT - 1);
    lcd.write(DINO);
  }
  return true;
}

void gameJump() {
  if (gameTimeInAir != 0) {
    return;
  }
  gameTimeInAir = timeInAir;
}

void shiftFieldLeft() {
  // Normally we would store first value in temporary variable
  // But we don't need it here
  for (byte i = 0; i < WIDTH - 1; i ++) {
    if (field[i + 1] == DINO) {
      continue;
    }
    field[i] = field[i + 1];
  }
  field[WIDTH - 1] = SPACE;
}

void drawField() {
  lcd.setCursor(0, HEIGHT - 1);
  for (char bit : field) {
    lcd.write(bit);
  }
}

bool timeForCactus() {
  lastCactusTick ++;
  if (lastCactusTick <= minCactiGap) {
    return false;
  }
  if (random(chanceOfCacti) == 0) {
    lastCactusTick = 0;
    return true;
  } else {
    return false;
  }
}
