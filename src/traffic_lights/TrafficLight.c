#include "TrafficLight.h"

typedef struct TrafficLightInternals {
  TrafficLightLamps lamps;
} TrafficLightInternals;

TrafficLight TrafficLight_Create(TrafficLightLamps lamps) {
  TrafficLight self = calloc(1, sizeof(TrafficLight));
  self->lamps = lamps;
  return self;
}

TrafficLightState TrafficLight_State(TrafficLight self) {
  return Traffic_STOP;
}

void TrafficLight_Destroy(TrafficLight self) {
  free(self); /*dereference Lamps too?*/
}
