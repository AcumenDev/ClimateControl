#include "Climate.hpp"

Climate::Climate() {
    values = new Values();
    thSensors = new THSensors(SENSOR_PIN, 5000, values);
    co2Sensor = new CO2Sensor(CO2_TX_PIN, CO2_RX_PIN, 5000, values);
    keys = new Keys(BUTTON_SELECT_PIN, BUTTON_MINUS_PIN, BUTTON_PLUS_PIN, values);
    display = new Display(DISPLAY_DATA_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, 100, 500, values);
    relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN, COOLING_RELAY_PIN);
    climateControl = new ClimateControl(values, relays, 1000);
    monitoring = new Monitoring(values, 10 * 1000);
    co2Control = new CO2Control(values);
    startTimeOut = false;
}

void Climate::setup() {
    Serial.begin(9600);
    values->loadFromEEprom();
}

void Climate::loop(unsigned long currentMillis) {
    if (!startTimeOut && currentMillis >= 40000) {
        startTimeOut = true;
    }

    thSensors->update(currentMillis);
    co2Sensor->update(currentMillis);
    keys->update(currentMillis);
    display->update(currentMillis);
    values->update(currentMillis);
    monitoring->update(currentMillis);
    co2Control->update();


    if (startTimeOut) { ////Что бы не счелкала релюхами пока идет старт и прогрев датчиков
        climateControl->update(currentMillis);
    }
}
