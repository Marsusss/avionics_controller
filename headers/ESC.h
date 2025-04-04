#ifndef ESC_H
#define ESC_H

#include <Arduino.h> // Include the Arduino mock header

class ESC {
public:
    // Shared parameters (hardcoded for this use case)
    static const unsigned short int cycleDuration = 20000;   // Full cycle time in microseconds
    static const unsigned short int minPulseLength = 1000;     // Minimum pulse length in microseconds
    static const unsigned short int maxPulseLength = 2000;     // Maximum pulse length in microseconds
    static const unsigned short int pulseLengthRange = maxPulseLength - minPulseLength; // Range of pulse lengths
    static const unsigned char functionRuntime = 50;      // Estimated function runtime (for precision timing)

    // Unique per-channel data
    unsigned char pulsePin;           // Output pin used for this ESC
    unsigned short int currentPulseLength; // Current pulse width in microseconds
    unsigned int nextOffTime;  // When this channel should be turned off
    bool pulseOn;           // Current state of the channel (HIGH when on)

    // Constructor – simply initialize data members
    ESC(unsigned char pin)
      : pulsePin(pin),
        currentPulseLength(minPulseLength),
        nextOffTime(0),
        pulseOn(false)
    {}

    // Initialize the channel pin
    void init() {
        pinMode(pulsePin, OUTPUT);
        digitalWrite(pulsePin, LOW);
    }

    // Set the pulse length using a float from 0.0 to 1.0.
    // Scales between minPulseLength and cycleDuration.
    void setPulseLength(float value) {
        if (value < 0.0f) // Consider whether this can be skipped
            value = 0.0f;
        if (value > 1.0f)
            value = 1.0f;
        currentPulseLength = minPulseLength + (int)(value * (maxPulseLength - minPulseLength));
    }
    /* One could maximize performance of the above by simply setting
    if (value < 0)
                value = 0;
            if (value > pulseLengthRange)
                value = pulseLengthRange;
            currentPulseLength = minPulseLength + value;
    */

    void turnOn() {
        digitalWrite(pulsePin, HIGH);
        pulseOn = true;
        nextOffTime = micros() + currentPulseLength;
    }

    void turnOff() {
        digitalWrite(pulsePin, LOW);
        pulseOn = false;
    }
};

#endif
