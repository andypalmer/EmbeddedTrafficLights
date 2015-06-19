#pragma once

typedef struct LedDriverInternals* LedDriver;

typedef enum {Led_ON, Led_OFF} LedState;

LedState LedDriver_State(LedDriver);
void LedDriver_TurnOn(LedDriver);
void LedDriver_TurnOff(LedDriver);
void LedDriver_Destroy(LedDriver);

#include "LedDriverPrivate.h"
