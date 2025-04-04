#include "headers/ESC.h"
#include "headers/ESCS.h"
#include "mocks/Arduino.h"

int main() {
    const unsigned char pinNumber = 3;  // Pin number for the ESC
    ESC myEsc(pinNumber);  // Create an ESC object with pin 3
    myEsc.init();  // Initialize the ESC

    myEsc.setPulseLength(0.5);  // Set pulse length to 50%
    myEsc.turnOn();  // Simulate turning on the ESC

    // Wait for the simulated off time
    while (micros() < myEsc.nextOffTime) {
        // Simulated busy wait
    }
    
    myEsc.turnOff();  // Simulate turning off the ESC

    unsigned char pinNumberArray[] = {0, 1, 2};  // Array of pin numbers for the ESCS
    ESCS myEscs(3, pinNumberArray);  // Create an ESCS object with one ESC
    myEscs.init();  // Initialize the ESCS

    // Now iterate over the ESCs and print pin numbers currentCycleDuration and so on
    myEscs.setPulseLength(0, 0.75);  // Set pulse length for the first ESC to 75%

    // Simulate the act() function to turn on/off ESCs
    for (int i = 0; i < 10; i++) {
        std::cout << "Cycle " << i << ": " << std::endl;
        std::cout << "Next event time: " << myEscs.nextEventTime << std::endl;
        myEscs.act();  // Call the act function to update the ESC states
        // Simulate a delay
        for (unsigned long j = 0; j < 100000; j++) {
            // Simulated busy wait
        }
    }

    return 0;
}
