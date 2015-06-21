#include "LedDriver.h"
#include "TrafficLight.h"

typedef struct TrafficLightInternals {
  TrafficLightLamps lamps;
  TrafficLightState state;
} TrafficLightInternals;

typedef struct TrafficLampStates {
  LedState red, amber, green;
  TrafficLightState next;
} TrafficLampStates;

static TrafficLampStates _states[4] = {
  {.red = Led_ON,  .amber = Led_OFF, .green = Led_OFF, .next = Traffic_READY_TO_GO  }, /* Traffic_STOP        */
  {.red = Led_ON,  .amber = Led_ON,  .green = Led_OFF, .next = Traffic_GO           }, /* Traffic_READY_TO_GO */
  {.red = Led_OFF, .amber = Led_OFF, .green = Led_ON,  .next = Traffic_READY_TO_STOP}, /* Traffic_GO */
  {.red = Led_OFF, .amber = Led_ON,  .green = Led_OFF, .next = Traffic_STOP         }, /* Traffic_READY_TO_STOP */
};

TrafficLight TrafficLight_Create(TrafficLightLamps lamps) {
  TrafficLight self = calloc(1, sizeof(TrafficLightInternals));
  self->lamps = lamps;
  self->state = Traffic_STOP;
  LedDriver_TurnOn(self->lamps.red);
  LedDriver_TurnOff(self->lamps.amber);
  LedDriver_TurnOff(self->lamps.green);
  return self;
}

TrafficLightState TrafficLight_State(TrafficLight self) {
  return self->state;
}

void TrafficLight_NextState(TrafficLight self) {
  self->state = _states[self->state].next;
  LedDriver_Switch(self->lamps.red,   _states[self->state].red);
  LedDriver_Switch(self->lamps.amber, _states[self->state].amber);
  LedDriver_Switch(self->lamps.green, _states[self->state].green);
}
void TrafficLight_Destroy(TrafficLight self) {
  LedDriver_Destroy(self->lamps.red);
  LedDriver_Destroy(self->lamps.amber);
  LedDriver_Destroy(self->lamps.green);
  free(self); /*dereference Lamps too?*/
}
