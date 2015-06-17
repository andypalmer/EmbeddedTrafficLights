#include "TrafficLight.h"

typedef struct TrafficLightInternals {
  TrafficLightLamps lamps;
} TrafficLightInternals;

TrafficLight TrafficLight_Create(TrafficLightLamps lamps) {
  TrafficLight self = calloc(1, sizeof(TrafficLightInternals));
  self->lamps = lamps;
  return self;
}

TrafficLightState TrafficLight_State(TrafficLight self) {
  return Traffic_STOP;
}

void TrafficLight_Destroy(TrafficLight self) {
  free(self->lamps.red); /* FIXME[20150617 - ap] This should use the (yet to be defined) destructor, but it works for now
  free(self); /*dereference Lamps too?*/
}
