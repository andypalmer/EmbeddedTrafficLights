#include "LedDriver.h"

LedState LedDriver_State(LedDriver self) {
  return self->vtable->state(self);
}

void LedDriver_TurnOff(LedDriver self) {
  self->vtable->off(self);
}

void LedDriver_TurnOn(LedDriver self) {
  self->vtable->on(self);
}

void LedDriver_Destroy(LedDriver self) {
  self->vtable->destroy(self);
}
