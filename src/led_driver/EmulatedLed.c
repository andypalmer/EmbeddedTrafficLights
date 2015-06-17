#include "LedDriver.h"
#include "EmulatedLed.h"

LedDriver EmulatedLed_Create() {
  LedDriver self = calloc(1, sizeof(LedDriver));
  return self;
}
