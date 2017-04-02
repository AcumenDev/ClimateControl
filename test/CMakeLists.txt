cmake_minimum_required(VERSION 3.2)
project(test_climate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lstdc++")

#add_definitions(-DDEBUG)
include_directories(BEFORE stub)

set(HEADER_FILES_CLIMATE
        ClimateChangeService.hpp
        stub/EEPROM.h
        stub/Arduino.h
        stub/DHT.h
        stub/LedControl.h
        stub/HardwareSerial.hpp
        ../climate/Sensors.hpp
        ../climate/Button.hpp
        ../climate/ClimateControl.hpp
        ../climate/Display.hpp
        ../climate/Keys.hpp
        ../climate/Climate.hpp
        ../climate/Relays.hpp
        ../climate/Config.hpp
        ../climate/IntervalWorckerBase.hpp
        ../climate/Value.hpp)

set(SOURCE_FILES_CLIMATE
        ClimateChangeService.cpp
        stub/EEPROM.cpp
        stub/Arduino.cpp
        stub/DHT.cpp
        stub/LedControl.cpp
        stub/HardwareSerial.cpp
        ../climate/Sensors.cpp
        ../climate/Button.cpp
        ../climate/ClimateControl.cpp
        ../climate/Display.cpp
        ../climate/Keys.cpp
        ../climate/Climate.cpp
        ../climate/Relays.cpp
        ../climate/IntervalWorckerBase.cpp)

set(SOURCE_FILES main.cpp)
add_executable(test_climate ${SOURCE_FILES} ${SOURCE_FILES_CLIMATE} ${SOURCE_FILES_CLIMATE})