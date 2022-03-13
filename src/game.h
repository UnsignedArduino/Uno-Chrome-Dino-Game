#include <Arduino.h>

const byte dinoX = 1;
const byte timeInAir = 2;
const byte chanceOfCacti = 3;  // 1/3 chance
const byte minCactiGap = 1;

extern unsigned int gameTickDelay;

extern byte gameTimeInAir;

extern byte lastCactusTick;

extern unsigned long score;

extern char field[WIDTH];

void gameInit();

void startScreen();
void endScreen();

bool gameTick();
void gameJump();

void shiftFieldLeft();
void drawField();
bool timeForCactus();

byte widthOfNum(unsigned long num);
