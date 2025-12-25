#include <Arduino.h>
#include "light_visualiser.h"

void setup() {
  setupPins();
}

void loop() {
  setColor(255, 0, 0);
  delay(1000);
  setColor(0, 255, 0);
  delay(1000);
  setColor(0, 0, 255);
  delay(1000);
  setColor(100, 100, 25);
  delay(1000);
}