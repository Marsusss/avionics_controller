#ifndef ESCS_H
#define ESCS_H

#include <Arduino.h>
#include "ESC.h"

class ESCS {
private:
    const unsigned char numEsc;
    const unsigned short int subCycleDuration; // Duration of each sub-cycle
    unsigned char currentSubCycleIndex = 0; // Current sub-cycle index
    unsigned int nextSubCycleStartTime;
    ESC** escArray;

public:
    unsigned int nextEventTime; // Time of the next event

    // Constructor: takes the number of channels and an array of pin numbers.
    ESCS(const unsigned char numEsc, const unsigned char pins[])
        : numEsc(numEsc), subCycleDuration(ESC::cycleDuration / numEsc) {
        escArray = new ESC*[numEsc];
        for (unsigned char i = 0; i < numEsc; i++) {
            escArray[i] = new ESC(pins[i]);
        }
    }

    // Destructor: release allocated memory.
    ~ESCS() {
        for (unsigned char i = 0; i < numEsc; i++) {
            delete escArray[i];
        }
        delete[] escArray;
    }

    // Initialize each ESC channel and start the first cycle.
    void init() {
        for (unsigned char i = 0; i < numEsc; i++) {
            escArray[i]->init();
        }
        // Start the cycle using the current time.
        nextSubCycleStartTime = micros();
        escArray[0]->turnOn();
        nextEventTime = escArray[0]->nextOffTime;
    }

    void act() { // called by scheduler
        if (escArray[currentSubCycleIndex]->pulseOn) {
            // If the current channel is on, turn it off.
            escArray[currentSubCycleIndex]->turnOff();
            currentSubCycleIndex++;
            if (currentSubCycleIndex >= numEsc) {
                currentSubCycleIndex = 0; // Reset to the first channel
            }
            //
            nextSubCycleStartTime += subCycleDuration;
            nextEventTime = nextSubCycleStartTime;
        }
        else {
            // If the current channel is off, turn it on.
            escArray[currentSubCycleIndex]->turnOn();
            nextEventTime = escArray[currentSubCycleIndex]->nextOffTime;
        }
    }

    // Optionally allow setting a channel's pulse length (to take effect on the next cycle).
    void setPulseLength(int index, float value) {
        if (index >= 0 && index < numEsc) {
            escArray[index]->setPulseLength(value);
        }
    }

    // --- Static callback functions for scheduled events ---

    // Called for per-channel events. Turns off the corresponding channel.
    static void channelTurnOff(ESCS* self, int idx) {
        if (idx >= 0 && idx < self->numEsc) {
            self->escArray[idx]->turnOff();
        }
    }

    static void channelTurnOn(ESCS* self, int idx) {
        if (idx >= 0 && idx < self->numEsc) {
            self->escArray[idx]->turnOn();
        }
    }
};

#endif