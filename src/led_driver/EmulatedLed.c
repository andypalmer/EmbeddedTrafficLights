#include "LedDriver.h"
#include "LedDriverPrivate.h"
#include "EmulatedLed.h"

typedef struct EmulatedLedInternals {
  LedDriverInternals base;
  LedState state;
} EmulatedLedInternals;

static LedState state(LedDriver super) {
  return ((EmulatedLed)super)->state;
}

static void on(LedDriver super) {
  ((EmulatedLed)super)->state = Led_ON;
}

static void off(LedDriver super) {
  ((EmulatedLed)super)->state = Led_OFF;
}

static void destroy(LedDriver super) {
  free((EmulatedLed)super);
}

static LedDriverInterfaceDefinition interface = {
  .state = state,
  .on = on,
  .off = off,
  .destroy = destroy
};

LedDriver EmulatedLed_Create() {
  EmulatedLed self = calloc(1, sizeof(EmulatedLedInternals));
  self->base.vtable = &interface;
  self->state = Led_ON;
  return (LedDriver)self;
}
