#include "TrafficLight.h"

typedef struct TrafficLightInternals {
  TrafficLightLamps lamps;
} TrafficLightInternals;

TrafficLight TrafficLight_Create(TrafficLightLamps lamps) {
  TrafficLight self = calloc(1, sizeof(TrafficLightInternals));
  self->lamps = lamps;
  LedDriver_TurnOn(self->lamps.red);
  LedDriver_TurnOff(self->lamps.amber);
  LedDriver_TurnOff(self->lamps.green);
  return self;
}

TrafficLightState TrafficLight_State(TrafficLight self) {
  return Traffic_STOP;
}

void TrafficLight_Destroy(TrafficLight self) {
  LedDriver_Destroy(self->lamps.red);
  LedDriver_Destroy(self->lamps.amber);
  LedDriver_Destroy(self->lamps.green);
  free(self); /*dereference Lamps too?*/
}
