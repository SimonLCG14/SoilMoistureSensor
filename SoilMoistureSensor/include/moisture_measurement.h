#pragma once

#include <Arduino.h>

static const int sensorPin = A0;

static const int DRY_MEASUREMENT = 475;
static const int WET_MEASUREMENT = 152;

int measure();