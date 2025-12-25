#include <Arduino.h>

#include "light_visualiser.h"
#include "moisture_measurement.h"

const int TOO_WET_BOUND = 80;
const int OK_BOUND = 40;
const int BAD_BOUND = 25;

void setup() {
  Serial.begin(9600);
  initPins();
}

void loop() {
  int measurement = measure();

  if(measurement >= TOO_WET_BOUND){
    displayColor(0, 0, 255); // BLUE
  }
  else if(measurement < TOO_WET_BOUND && measurement >= OK_BOUND){
    displayColor(0, 255, 0); // GREEN
  }
  else if(measurement < OK_BOUND && measurement >= BAD_BOUND){
    displayColor(255, 50, 0); // ORANGE
  }
  else{
    displayColor(255, 0, 0); // RED
  }
}