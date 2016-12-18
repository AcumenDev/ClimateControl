#include "Sensors.hpp"

Sensors::Sensors( char sensorPin, int interval, Values *values)
{

  this->sensorPin = sensorPin;
  this->values = values;
  this->interval = interval;
  dht = new DHT(sensorPin, DHT22);
  dht->begin();
}


void  Sensors::update(unsigned long currentMillis) {
  if ( (currentMillis - previousMillis) < interval) {
    return;
  }

  values->humidity = dht->readHumidity();
  values->temperature = dht->readTemperature();


#ifdef DEBUG
  // Check if any reads failed and exit early (to try again).
  if (isnan(values->humidity) || isnan(values->temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
  }


  // Compute heat index in Celsius (isFahreheit = false)
  // float hic = dht->computeHeatIndex(t, h, false);

 // Serial.print("Temperature: ");
//  Serial.print(values->temperature);

//  Serial.print(" *C\t");
//  Serial.print("Humidity: ");
 // Serial.print(values->humidity);
//  Serial.print(" % ");
//  Serial.println();
#endif
  previousMillis = currentMillis;
}
