#include <iostream>
#include "Relays.h"
#include "../climate/ClimateControl.hpp"
#include <chrono>
//#include "Arduino.h"
//#include "EEPROM.h"

using namespace std;
using namespace std::chrono;
bool humidificationRelay;
bool heatingRelay;
bool coolingRelay;

Values values;

RelaysBase *relays = new Relays(&humidificationRelay, &heatingRelay, &coolingRelay);

ClimateControl climateControl(&values, relays, 1000);
long debugPreviousMillis = 0;
long updateTempPreviousMillis = 0;
bool state = true;


float Humidity = 50;
float Temperature = 20.9;


float cof = 0.1;

long startTime = 0;


int hour = 60 * 60 * 1000;
int hour6 = hour * 6;
int hour12 = hour * 12;
int hour18 = hour * 18;
int hour24 = hour * 24;


void updateTemp(long currentMillis) {
    if ((currentMillis - updateTempPreviousMillis) < 1000) {
        return;
    }

    if (values.temperature > Temperature) {
        values.temperature = values.temperature - cof;
    } else if (values.temperature < Temperature) {
        values.temperature = values.temperature + cof;
    }


/*    if (currentMillis - startTime < hour6) {
        Temperature = -22;
    } else if (currentMillis - startTime < hour12) {
        Temperature = 0;
    } else if (currentMillis - startTime < hour18) {
        Temperature = 15;
    } else if (currentMillis - startTime < hour24) {
        Temperature = -20;
    }*/








/*
    if (values.humidity > Humidity) {
        values.humidity = values.humidity - cof;
    } else if (values.humidity < Humidity) {
        values.humidity = values.humidity + cof;
    }*/


    if (humidificationRelay) {
        values.humidity = values.humidity + cof * 2;
    }
    if (heatingRelay) {
        values.temperature = values.temperature + cof * 2;
    }
    if (coolingRelay) {
        values.temperature = values.temperature - cof * 2;
    }


    updateTempPreviousMillis = currentMillis;
}

void debug(long currentMillis) {
    if ((currentMillis - debugPreviousMillis) < 1 * 1000) {
        return;
    }
    cout.precision(2);
// std::ctime(&currentMillis)  << "\t" <<
    cout << std::fixed << values.temperature << "\t" << Temperature << "\t" << values.targetTemperature <<"\t" <<
    heatingRelay << "\t" << coolingRelay <<
    endl;
//    "\t" << values.targetHumidity << "\t" << humidificationRelay << "\t" <<

    debugPreviousMillis = currentMillis;
}

int main() {
    //cout << "Start!" << endl;
    cout   << "temperature\tOurTemperature\ttargetTemperature\theatingRelay\tcoolingRelay"<<endl;

    values.targetHumidity = 50;
    values.targetTemperature = 22;
    values.temperature = 24;
    values.humidity = 50;

    long currentMillis;
    long currentMillisFast;
    startTime = 0;
    while (state) {
        currentMillis = duration_cast<milliseconds>(
                system_clock::now().time_since_epoch()
        ).count();
        currentMillisFast =currentMillis;

        climateControl.update(currentMillisFast);
        updateTemp(currentMillisFast);


        debug(currentMillisFast);
      //  if (currentMillisFast - startTime >= hour24) {
      //      break;
    //    }


    }

    return 0;
}

