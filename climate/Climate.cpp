#include "Climate.hpp"

Climate::Climate() {
    values = new Values();
    sensors = new Sensors(SENSOR_PIN, 5000, values);
    keys = new Keys(COOLING_BUTTON_PLUS_PIN, COOLING_BUTTON_MINUS_PIN, HEATING_BUTTON_PLUS_PIN,
                    HEATING_BUTTON_MINUS_PIN, BUTTON_CONTROL_ON, values);
    display = new Display(DISPLAY_DATA_PIN, DISPLAY_CLK_PIN, DISPLAY_CS_PIN, 100, 5000, values);
    relays = new Relays(HUMIDIFICATION_RELAY_PIN, HEATING_RELAY_PIN, COOLING_RELAY_PIN);
    climateControl = new ClimateControl(values, relays, 1000);
    startTimeOut = false;
}

void Climate::setup() {
    Serial.begin(9600);
    values->loadFromEEprom();
}

void Climate::loop(unsigned long currentMillis) {
    if (!startTimeOut && currentMillis >=  40000) {
        startTimeOut = true;
    }

    sensors->update(currentMillis);
    keys->update(currentMillis);
    display->update(currentMillis);

    if (startTimeOut) { ////Что бы не счелкала релюхами пока идет старт и прогрев датчиков
        climateControl->update(currentMillis);
    }

    values->update(currentMillis);

    if ((currentMillis - previousMillis) < 10 * 1000) {
        return;
    }

    Serial.print(currentMillis / 1000);
    Serial.print("\t");
    //  Serial.print(" T: ");
    Serial.print(values->temperature);
    //  Serial.print(" H: ");
    Serial.print("\t");
    Serial.print(values->humidity);
    //  Serial.print(" set:");
    //  Serial.print(" T: ");
    Serial.print("\t");
    Serial.print(values->targetTemperature);
    //  Serial.print(" H: ");
    Serial.print("\t");
    Serial.print(values->targetHumidity);
    Serial.print("\t");
    //  Serial.print(" relays:");

    //  Serial.print(" HU: ");
    Serial.print(!digitalRead(HUMIDIFICATION_RELAY_PIN));
    //  Serial.print(" H: ");
    Serial.print("\t");
    Serial.print(!digitalRead(HEATING_RELAY_PIN));
    //  Serial.print(" C: ");
    Serial.print("\t");
    Serial.print(!digitalRead(COOLING_RELAY_PIN));
    Serial.print("\n");
    Serial.flush();

    previousMillis = currentMillis;
}
