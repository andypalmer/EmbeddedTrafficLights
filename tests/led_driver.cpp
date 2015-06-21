#include "CppUTest/TestHarness.h"

extern "C" {
#include "LedDriver.h"
#include "EmulatedLed.h"
}

TEST_GROUP(LedDriver) {};

TEST(LedDriver, is_on_by_default) {
  LedDriver led = EmulatedLed_Create();

  LONGS_EQUAL(Led_ON, LedDriver_State(led));
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_switched_off) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_TurnOff(led);

  LONGS_EQUAL(Led_OFF, LedDriver_State(led));
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_toggled_on) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_TurnOff(led);
  LedDriver_Toggle(led);

  LONGS_EQUAL(Led_ON, LedDriver_State(led));
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_toggled_off) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_Toggle(led);

  LONGS_EQUAL(Led_OFF, LedDriver_State(led));
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_switched_on_by_constant) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_TurnOff(led);
  LedDriver_Switch(led, Led_ON);

  LONGS_EQUAL(Led_ON, LedDriver_State(led));
  LedDriver_Destroy(led);
}

TEST(LedDriver, can_be_switched_off_by_constant) {
  LedDriver led = EmulatedLed_Create();
  LedDriver_Switch(led, Led_OFF);

  LONGS_EQUAL(Led_OFF, LedDriver_State(led));
  LedDriver_Destroy(led);
}
