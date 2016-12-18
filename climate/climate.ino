#include "Climate.hpp"

Climate climate;


void setup() {
  climate.setup();
}

void loop() {
  climate.loop(millis());
}
