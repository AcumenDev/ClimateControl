#include "Climate.hpp"

Climate::Climate() {

}

void Climate::setup() {
    Serial.begin(9600);
    values.loadFromEEprom();
    thSensors = new THSensors(5000);

    co2Sensor = new CO2Sensor(CO2_TX_PIN, CO2_RX_PIN, 10000);
    keys = new Keys(BUTTON_SELECT_PIN, BUTTON_MINUS_PIN, BUTTON_PLUS_PIN);
    display = new Display(DISPLAY_DATA_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, 100, 2500);
    relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN, COOLING_RELAY_PIN, VENTILATION_RELAY_PIN);
    temperatureControl = new TemperatureControl(TEMPERATURE_PID_KP, TEMPERATURE_PID_KI,
                                                TEMPERATURE_PID_KD, 5000);
    humidityControl = new HumidityControl(HUMIDITY_PID_KP, HUMIDITY_PID_KI, HUMIDITY_PID_KD, 5000);
    monitoring = new Monitoring(5 * 1000);
    co2Control = new CO2Control(CO2_PID_KP, CO2_PID_KI, CO2_PID_KD, 10000);
    servoMotors = new ServoMotors(HUMIDIFICATION_MOTOR_PIN, HEATING_MOTOR_PIN, COOLING_MOTOR_PIN);
    executiveDevices = new ExecutiveDevices(relays, servoMotors);
}

void Climate::loop(unsigned long currentMillis) {
    thSensors->update(&values, currentMillis);
    co2Sensor->update(&values, currentMillis);
    keys->update(&values, currentMillis);
    display->update(&values, currentMillis);
    values.update(currentMillis);
    monitoring->update(&values, currentMillis);
    co2Control->update(&values, currentMillis);
    temperatureControl->update(&values, currentMillis);
    humidityControl->update(&values, currentMillis);
    if (startTimeOut || currentMillis >= 5000) { ////Что бы не счелкала релюхами пока идет старт и прогрев датчиков
        executiveDevices->update(&values);
        startTimeOut = true;
    }
}
