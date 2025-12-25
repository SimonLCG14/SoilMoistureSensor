#include "moisture_measurement.h"

int measure(){
    int measurementRaw = analogRead(sensorPin);

    Serial.print("Raw measurement value: ");
    Serial.println(measurementRaw);

    int measurementInPercent = map(measurementRaw, DRY_MEASUREMENT, WET_MEASUREMENT, 0, 100);
    measurementInPercent = constrain(measurementInPercent, 0, 100);

    Serial.print("Measurement value (%): ");
    Serial.println(measurementInPercent);

    return measurementInPercent;
}