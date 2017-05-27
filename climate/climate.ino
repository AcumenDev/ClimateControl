#include "Climate.hpp"

Climate climate;


void setup() {
  climate.setup();
}

void loop() {
  climate.loop(millis());
 // Serial.println("\n[memCheck]");
 // Serial.println(DebugUtils::getfreeRam());


}



