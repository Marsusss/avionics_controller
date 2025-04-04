#ifndef Arduino_h
#define Arduino_h

#include <iostream>
#include <chrono>

// Mocked Arduino functions
void pinMode(int pin, int mode) {
    std::cout << "pinMode called on pin " << pin << " with mode " << mode << std::endl;
}

void digitalWrite(int pin, int value) {
    std::cout << "digitalWrite called on pin " << pin << " with value " << value << std::endl;
}

int LOW = 0;
int HIGH = 1;

int OUTPUT = 1;

unsigned long micros() {
    // Simulate micros() with std::chrono
    static auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(now - start).count();
}

#endif
