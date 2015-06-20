#include "LedDriver.h"
#include "ArduinoLed.h"
#include "WProgram.h"

static LedDriver red;
static LedDriver green;

void setup() {}
void loop() {
  delay(1000);
  LedDriver_TurnOff(green);
  delay(1000);
  LedDriver_TurnOn(green);
  delay(1000);
  LedDriver_TurnOff(red);
}

int main() {
  init();
  setup();
  red = ArduinoLed_Create(13);
  green = ArduinoLed_Create(11);
  while(1)
    loop();
}
