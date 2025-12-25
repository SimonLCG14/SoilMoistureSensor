#include <Arduino.h>

#include "light_visualiser.h"
#include "moisture_measurement.h"
#include "display_visualiser.h"

static const int TOO_WET_BOUND = 80;
static const int OK_BOUND = 40;
static const int BAD_BOUND = 25;

void setup() {
  initPins();
  initDisplay();
}

void loop() {
  int measurement = measure();
  String infoMsg = "";

  if(measurement >= TOO_WET_BOUND){
    displayColor(0, 0, 255); // BLUE
    infoMsg = "Too much water!";
  }
  else if(measurement < TOO_WET_BOUND && measurement >= OK_BOUND){
    displayColor(0, 255, 0); // GREEN
  }
  else if(measurement < OK_BOUND && measurement >= BAD_BOUND){
    displayColor(255, 50, 0); // ORANGE
  }
  else{
    displayColor(255, 0, 0); // RED
    infoMsg = "Too little water!";
  }

  if(infoMsg.isEmpty()){
    display_measurement(measurement);
  }
  else{
    display_measurement(measurement, infoMsg);
  }
  
  delay(100);
}