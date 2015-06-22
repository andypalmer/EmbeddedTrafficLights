#include "LedDriver.h"
#include "ArduinoLed.h"
#include "TrafficLight.h"
#include "WProgram.h"

static LedDriver red,amber,green;
static TrafficLight traffic_light;

void setup() {}
void loop() {
  delay(2000);
  TrafficLight_NextState(traffic_light);

}

int main() {
  init();
  red = ArduinoLed_Create(13);
  amber = ArduinoLed_Create(12);
  green = ArduinoLed_Create(11);
  TrafficLightLamps lamps = {.red = red, .amber = amber, .green = green};
  traffic_light = TrafficLight_Create(lamps);

  while(1)
    loop();
}
