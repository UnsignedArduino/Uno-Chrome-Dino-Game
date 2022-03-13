#include <Arduino.h>

const byte dinoX = 1;
const byte timeInAir = 2;
const byte chanceOfCacti = 3;  // 1/3 chance
const byte minCactiGap = 1;

// Allows us to get specific button pressed if you have the hardware / shield
#define USE_RESISTOR_LADDER

// Set a seed for the random number generator
// Comment to read random value from analog pins 1 and 2 and to multiply them
// #define CONSTANT_SEED 1

// Logs the distance to the next cacti on serial
// Every game tick a number will be printed to serial
// -1 means you are jumping
// 0 means you are dead (on a cacti)
#define SERIAL_DISTANCE_CACTI
