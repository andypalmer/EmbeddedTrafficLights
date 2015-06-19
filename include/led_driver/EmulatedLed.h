#pragma once
#include "LedDriver.h"

typedef struct EmulatedLedInternals* EmulatedLed;

LedDriver EmulatedLed_Create(void);
