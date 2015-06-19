#pragma once
#include "LedDriver.h"

typedef struct {
  LedDriver red;
  LedDriver amber;
  LedDriver green;
} TrafficLightLamps;

typedef struct TrafficLightInternals* TrafficLight;

typedef enum {
  Traffic_STOP
} TrafficLightState;

TrafficLight TrafficLight_Create(TrafficLightLamps);
TrafficLightState TrafficLight_State(TrafficLight);
void TrafficLight_Destroy(TrafficLight);
