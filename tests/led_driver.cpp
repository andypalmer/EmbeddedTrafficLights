#include "CppUTest/TestHarness.h"

extern "C" {
#include "LedDriver.h"
#include "EmulatedLed.h"
}

TEST_GROUP(LedDriver) {};

TEST(LedDriver, is_on_by_default) {
  LedDriver led = EmulatedLed_Create();

  LONGS_EQUAL(LedDriver_State(led), Led_ON);
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_switched_off) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_TurnOff(led);

  LONGS_EQUAL(LedDriver_State(led), Led_OFF);
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_toggled_on) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_TurnOff(led);
  LedDriver_Toggle(led);

  LONGS_EQUAL(LedDriver_State(led), Led_ON);
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_toggled_off) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_Toggle(led);

  LONGS_EQUAL(LedDriver_State(led), Led_OFF);
  LedDriver_Destroy(led);
}
