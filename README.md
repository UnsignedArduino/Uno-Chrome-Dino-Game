# Uno-Chrome-Dino-Game

Google Chrome's famous dinosaur game on a 16x2 LCD shield!

Works beautifully on an Arduino Uno.

## Running

### In PlatformIO

1. Download the repo.
2. Open the project in PlatformIO.
3. Change the port to upload in [`platformio.ini`](https://github.com/UnsignedArduino/Uno-Chrome-Dino-Game/blob/main/platformio.ini).
4. Upload.

### In Arduino IDE

1. Download the repo.
2. Create a new blank Arduino sketch called "Chrome_Dino_Game".
3. Close Arduino IDE.
4. Navigate to that sketch folder.
5. Copy the contents of the [`src`](https://github.com/UnsignedArduino/Uno-Chrome-Dino-Game/tree/main/src) folder to the sketch folder.
6. Rename [`main.cpp`](https://github.com/UnsignedArduino/Uno-Chrome-Dino-Game/blob/main/src/main.cpp) to `Chrome_Dino_Game.ino`.
7. Open the sketch back up in Arduino IDE.
8. Change board type and upload port if neccessary.
9. Upload.

## Configuration

Look in [`pinouts.h`](https://github.com/UnsignedArduino/Uno-Chrome-Dino-Game/blob/main/src/pinouts.h) to change the pins for the LCD and button.

Look in [`config.h`](https://github.com/UnsignedArduino/Uno-Chrome-Dino-Game/blob/main/src/config.h) to change game aspects. 
