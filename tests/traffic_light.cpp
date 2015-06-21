#include "CppUTest/TestHarness.h"

extern "C" {
#include "TrafficLight.h"
#include "EmulatedLed.h"
}

TEST_GROUP(TrafficLight) {
};

TEST(TrafficLight, is_on_stop_by_default) {
  LedDriver red = EmulatedLed_Create();
  LedDriver amber = EmulatedLed_Create();
  LedDriver green = EmulatedLed_Create();
  TrafficLightLamps lamps = {
    .red = red,
    .amber = amber,
    .green = green};
  TrafficLight traffic_light = TrafficLight_Create(lamps);
  LONGS_EQUAL(TrafficLight_State(traffic_light), Traffic_STOP);
  LONGS_EQUAL(LedDriver_State(red), Led_ON);
  LONGS_EQUAL(LedDriver_State(amber), Led_OFF);
  LONGS_EQUAL(LedDriver_State(green), Led_OFF);
  TrafficLight_Destroy(traffic_light);
}

TEST(TrafficLight, is_ready_to_go_after_stop) {
  LedDriver red = EmulatedLed_Create();
  LedDriver amber = EmulatedLed_Create();
  LedDriver green = EmulatedLed_Create();
  TrafficLightLamps lamps = {
    .red = red,
    .amber = amber,
    .green = green};
  TrafficLight traffic_light = TrafficLight_Create(lamps);
  TrafficLight_NextState(traffic_light);

  LONGS_EQUAL(TrafficLight_State(traffic_light), Traffic_READY_TO_GO);
  LONGS_EQUAL(LedDriver_State(red), Led_ON);
  LONGS_EQUAL(LedDriver_State(amber), Led_ON);
  LONGS_EQUAL(LedDriver_State(green), Led_OFF);
  TrafficLight_Destroy(traffic_light);
}
