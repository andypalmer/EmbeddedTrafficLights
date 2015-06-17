#include "CppUTest/TestHarness.h"

extern "C" {
#include "TrafficLight.h"
#include "EmulatedLed.h"
}

TEST_GROUP(TrafficLight) {
};

TEST(TrafficLight, is_on_stop_by_default) {
  TrafficLightLamps lamps = {EmulatedLed_Create(), 0, 0};
  TrafficLight traffic_light = TrafficLight_Create(lamps);
  LONGS_EQUAL(TrafficLight_State(traffic_light), Traffic_STOP);
  TrafficLight_Destroy(traffic_light);
}
