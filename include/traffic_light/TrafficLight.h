#pragma once
#include "LedDriver.h"

typedef struct {
  LedDriver red;
  LedDriver amber;
  LedDriver green;
} TrafficLightLamps;

typedef struct TrafficLightInternals* TrafficLight;

typedef enum {
  Traffic_STOP,
  Traffic_READY_TO_GO,
  Traffic_GO,
  Traffic_READY_TO_STOP
} TrafficLightState;

TrafficLight TrafficLight_Create(TrafficLightLamps);
TrafficLightState TrafficLight_State(TrafficLight);
void TrafficLight_NextState(TrafficLight);
void TrafficLight_Destroy(TrafficLight);
