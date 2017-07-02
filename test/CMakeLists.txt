cmake_minimum_required(VERSION 3.2)
project(test_climate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lstdc++ -fpermissive")

#add_definitions(-DDEBUG -DCLIMATE_DEBUG)
include_directories(BEFORE stub)

set(HEADER_FILES_CLIMATE
        ClimateChangeService.hpp
        stub/EEPROM.h
        stub/Arduino.h
        stub/DHT.h
        stub/LedControl.h
        stub/SoftwareSerial.h
        stub/HardwareSerial.hpp
        ../climate/THSensors.hpp
        ../climate/Button.hpp
        ../climate/TemperatureControl.hpp
        ../climate/Display.hpp
        ../climate/Keys.hpp
        ../climate/Climate.hpp
        ../climate/Relays.hpp
        ../climate/Config.hpp
        ../climate/IntervalWorckerBase.hpp
        ../climate/Value.hpp
        ../climate/CO2Sensor.hpp
        ../climate/TimeUtils.hpp
        ../climate/Monitoring.hpp
        ../climate/DebugUtils.hpp)

set(SOURCE_FILES_CLIMATE
        ClimateChangeService.cpp
        stub/EEPROM.cpp
        stub/Arduino.cpp
        stub/DHT.cpp
        stub/LedControl.cpp
        stub/HardwareSerial.cpp
        ../climate/THSensors.cpp
        ../climate/Button.cpp
        ../climate/TemperatureControl.cpp
        ../climate/Display.cpp
        ../climate/Keys.cpp
        ../climate/Climate.cpp
        ../climate/Relays.cpp
        ../climate/IntervalWorckerBase.cpp
        ../climate/CO2Sensor.cpp
        ../climate/Monitoring.cpp ../climate/CO2Control.cpp ../climate/CO2Control.hpp ../climate/HumidityControl.cpp ../climate/HumidityControl.hpp stub/Adafruit_BME280.h ../climate/ExecutiveDevices.cpp ../climate/ExecutiveDevices.hpp)

set(SOURCE_FILES main.cpp ../climate/ServoMotors.cpp ../climate/ServoMotors.hpp stub/Servo.h stub/Adafruit_BME280.cpp)
add_executable(test_climate ${SOURCE_FILES} ${SOURCE_FILES_CLIMATE} ${SOURCE_FILES_CLIMATE})