#pragma once
#include "LedDriver.h"

typedef struct ArduinoLedInternals* ArduinoLed;

LedDriver ArduinoLed_Create(int);
