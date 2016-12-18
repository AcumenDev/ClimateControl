#ifndef Sensors_h
#define Sensors_h
#include "DHT.h"
#include "Values.h"

class Sensors {

    unsigned long previousMillis;
    char sensorPin;
    DHT * dht;
    int interval;
    Values *values;

  public:

    Sensors( char sensorPin, int interval, Values *values);
    void update(unsigned long currentMillis);
};
#endif
