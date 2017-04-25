#include "Climate.hpp"

Climate::Climate() {
    values = new Values();
    thSensors = new THSensors(SENSOR_PIN, 5000, values);
    co2Sensor = new CO2Sensor(CO2_TX_PIN, CO2_RX_PIN, 5000);
    keys = new Keys(BUTTON_SELECT_PIN, BUTTON_MINUS_PIN, BUTTON_PLUS_PIN);
    display = new Display(DISPLAY_DATA_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, 100, 500);
    relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN, COOLING_RELAY_PIN);
    temperatureControl = new TemperatureControl(TEMPERATURE_PID_KP, TEMPERATURE_PID_KI, TEMPERATURE_PID_KD,
                                                5000);
    monitoring = new Monitoring(10 * 1000);
    co2Control = new CO2Control(CO2_PID_KP, CO2_PID_KI, CO2_PID_KD, 5000);
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


    thSensors->update(values, currentMillis);
    co2Sensor->update(values, currentMillis);
    keys->update(values, currentMillis);
    display->update(values, currentMillis);
    values->update(currentMillis);
    monitoring->update(values, currentMillis);
    co2Control->update(values, currentMillis);
    temperatureControl->update(values, currentMillis);

    if (startTimeOut) { ////Что бы не счелкала релюхами пока идет старт и прогрев датчиков
        ////TODO Исполнительные устройства
    }
}
