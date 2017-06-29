#define CLIMATE_DEBUG

#define BUTTON_PLUS_PIN A0
#define BUTTON_MINUS_PIN A1

#define CO2_RX_PIN A2
#define CO2_TX_PIN A3
//bme_280 I2C(SDA) A4
//bme_280 I2C(SCL) A5

#define BUTTON_SELECT_PIN 13

#define DISPLAY_CS_PIN 2
#define DISPLAY_CLK_PIN 3
#define DISPLAY_DATA_PIN 4



#define HUMIDIFICATION_RELAY_PIN 5
#define HEATING_RELAY_PIN 6
#define COOLING_RELAY_PIN 7
#define VENTILATION_RELAY_PIN 8

#define HUMIDIFICATION_MOTOR_PIN 9
#define HEATING_MOTOR_PIN 10
#define COOLING_MOTOR_PIN 11

//12 unuse



#define TARGET_TEMPERATURE_EEPROM_ADR 0
#define TARGET_HUMIDITY_EEPROM_ADR 1
#define TARGET_CO2_EEPROM_ADR 3

#define MIN_TARGET_HUMIDITY 20
#define MAX_TARGET_HUMIDITY 99
#define HUMIDITY_GISTERIS 2

#define MIN_TARGET_TEMPERATURE 1
#define MAX_TARGET_TEMPERATURE 40
#define TEMPERATURE_GISTERIS 1

#define MIN_TAGET_CO2 300
#define MAX_TAGET_CO2 2500
#define CO2_GISTERIS 100


#define TEMPERATURE_PID_KP 2
#define TEMPERATURE_PID_KI 5
#define TEMPERATURE_PID_KD 1


#define HUMIDITY_PID_KP 2
#define HUMIDITY_PID_KI 5
#define HUMIDITY_PID_KD 1


#define CO2_PID_KP 2
#define CO2_PID_KI 5
#define CO2_PID_KD 1
