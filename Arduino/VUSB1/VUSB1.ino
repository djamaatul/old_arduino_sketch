#include <USBKeyboard.h>

#define LAYOUT LAYOUT_US

USBKeyboard mKeyboard = USBKeyboard();

bool key_d = false;
bool key_f = false;
bool key_j = false;
bool key_k = false;

void setup() {
  TIMSK0 = 0;
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
    mKeyboard.sendKeys(mKeyboard.asciiToKeycode('3'),0, 0, 0, 0, 0, 0);
    mKeyboard.sendKeys(mKeyboard.asciiToKeycode('1'),0, 0, 0, 0, 0, 0);
        mKeyboard.sendKeys(mKeyboard.asciiToKeycode('2'),0, 0, 0, 0, 0, 0);
            mKeyboard.sendKeys(mKeyboard.asciiToKeycode('3'),0, 0, 0, 0, 0, 0);
        mKeyboard.sendKeys(mKeyboard.asciiToKeycode('2'),0, 0, 0, 0, 0, 0);
            mKeyboard.sendKeys(mKeyboard.asciiToKeycode('1'),0, 0, 0, 0, 0, 0);
        mKeyboard.sendKeys(mKeyboard.asciiToKeycode('6'),0, 0, 0, 0, 0, 0);
            mKeyboard.sendKeys(mKeyboard.asciiToKeycode('\n'),0, 0, 0, 0, 0, 0);
}
uint8_t a;
void loop() {
   mKeyboard.update();

  delayMicroseconds(20000);
}
