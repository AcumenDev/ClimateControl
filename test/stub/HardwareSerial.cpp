#include "HardwareSerial.hpp"

void HardwareSerial::begin(unsigned long baud) {

}

size_t HardwareSerial::print(const char item[]) {
    cout << item;
}

size_t HardwareSerial::print(char item) {
    cout << item;
}

size_t HardwareSerial::print(int item) {
    cout << item;
}

size_t HardwareSerial::print(double item) {
    cout << item;
}

void HardwareSerial::flush() {
    cout << std::endl;
}

size_t HardwareSerial::println(const char item[]) {
    cout << item << std::endl;
}
