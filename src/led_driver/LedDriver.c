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

void LedDriver_Toggle(LedDriver self) {
  switch(LedDriver_State(self)) {
    case Led_ON:
      LedDriver_TurnOff(self); break;
    case Led_OFF:
      LedDriver_TurnOn(self); break;
  }
}

void LedDriver_Switch(LedDriver self, LedState state) {
  switch(state) {
    case Led_OFF:
      LedDriver_TurnOff(self); break;
    case Led_ON:
      LedDriver_TurnOn(self); break;
  }
}

void LedDriver_Destroy(LedDriver self) {
  self->vtable->destroy(self);
}
