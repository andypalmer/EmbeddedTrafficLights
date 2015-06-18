#include "CppUTest/TestHarness.h"

extern "C" {
#include "TrafficLight.h"
#include "EmulatedLed.h"
}

TEST_GROUP(TrafficLight) {
};

TEST(TrafficLight, is_on_stop_by_default) {
  TrafficLightLamps lamps = {
    .red = EmulatedLed_Create(),
    .amber = EmulatedLed_Create(),
    .green = EmulatedLed_Create()};
  TrafficLight traffic_light = TrafficLight_Create(lamps);
  LONGS_EQUAL(TrafficLight_State(traffic_light), Traffic_STOP);
   //LONGS_EQUAL(LedDriver_State(red), Led_ON);
   //LONGS_EQUAL(LedDriver_State(amber), Led_OFF);
   //LONGS_EQUAL(LedDriver_State(green), Led_OFF);
  TrafficLight_Destroy(traffic_light);
}
