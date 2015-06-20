#include "LedDriver.h"
#include "LedDriverPrivate.h"
#include "ArduinoLed.h"
#include "WProgram.h"

typedef struct ArduinoLedInternals {
  LedDriverInternals base;
  int pin;
} ArduinoLedInternals;

static LedState state(LedDriver super) {
  ArduinoLed self = (ArduinoLed)super;
  return digitalRead(self->pin);
}

static void on(LedDriver super) {
  digitalWrite(((ArduinoLed)super)->pin,HIGH);
}

static void off(LedDriver super) {
  digitalWrite(((ArduinoLed)super)->pin,LOW);
}

static void destroy(LedDriver super) {
  free((ArduinoLed)super);
}

static LedDriverInterfaceDefinition interface = {
  .state = state,
  .on = on,
  .off = off,
  .destroy = destroy
};

LedDriver ArduinoLed_Create(int pin) {
  ArduinoLed self = calloc(1, sizeof(ArduinoLedInternals));
  self->base.vtable = &interface;
  self->pin = pin;
  pinMode(self->pin, OUTPUT);
  on(self);
  return (LedDriver)self;
}

