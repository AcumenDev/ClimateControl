//
// Created by vst on 4/21/17.
//

#ifndef TEST_CLIMATE_DEBUGUTILS_HPP
#define TEST_CLIMATE_DEBUGUTILS_HPP

// Define where debug output will be printed.
#define DEBUG_PRINTER Serial

// Setup debug printing macros.
#ifdef CLIMATE_DEBUG
  #define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
  #define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {}
#define DEBUG_PRINTLN(...) {}
#endif



/*class Utils {
public:
    static void log(const char msg[]) {
#ifdef DEBUG
        Serial.println(msg);
#endif
    }

    static void log(char msg) {
#ifdef DEBUG
        Serial.print(msg);
#endif
    }

    static void log(int msg) {
#ifdef DEBUG
        Serial.print(msg);
#endif
    }

    static void log(double msg) {
#ifdef DEBUG
        Serial.print(msg);
#endif
    }


    static void log(unsigned long msg) {
#ifdef DEBUG
        Serial.print(msg);
#endif
    }
};*/

#endif //TEST_CLIMATE_DEBUGUTILS_HPP
