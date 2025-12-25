#include <Arduino.h>

#include "light_visualiser.h"
#include "moisture_measurement.h"

const int OK_BOUND = 40;
const int BAD_BOUND = 25;

void setup() {
  Serial.begin(9600);
  initPins();
}

void loop() {
  int measurement = measure();

  if(measurement >= OK_BOUND){
    displayColor(0, 255, 0);
  }
  else if(measurement < OK_BOUND && measurement >= BAD_BOUND){
    displayColor(255, 80, 0);
  }
  else{
    // Red
    displayColor(255, 0, 0);
    // + Sound alarm
  }
}