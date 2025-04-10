# avionics_controller

## Purpose
This repository describes an Arduino UNO acting as an avionics controller. The avionics controller is intended to be part of a full flight controller unit when paired with a Raspberry Pi or preferably an NVIDIA Jetson NANO or similar acting as main processor. The avionics is responsible for gathering environment inputs, sending data to the main processor and controlling ESCs based on input from the main processor. The avionics controller is hereby distinct from a flight controller in that it is not the primary one responsible for decision-making. The avionics controller is intended to have its own emergency landing feature though in case communication with the main processor fails.

Considering its responsibility of handling real-time clock-based connections one could also consider it the real-time controller "shielding" the main processor from high-frequent interactions.

The avionics controllers responsibilities include:
### Collecting sensor inputs
- LDSM9DS1
  - Accelerometer
  - Gyroscope
  - Magnetometer
- HC-SR04 Ultrasonic Distance Module

### Communication with main processor
- Collecting sensor inputs in a reasonable format
- Send collected sensor inputs through USB connection
- Take inputs through the USB connection

### Speed control
- Transform instructions into ESC pulses

### Emergency controls
- Emergency landing feature in case:
  - Collision is emminent
  - Communication with main processor fails
- Object evasion in case of near collision

## Testing
Enter the root directory
compile `g++ -I<pwd> test.cpp -o test`
run `./test`

## Development

Below is a table of tasks and their completion status:

| Task                                | Completion Status | Assignee       | Branch          | Comment |
|-------------------------------------|-------------------|----------------|-----------------|---------|
| Framework for unittesting    | ⏳       | Marcus         |  | Prolly gonna use gtest |
| Mock Arduino.h | ⏳ | Marcus | | Need more sophisticated implementation that logs some information about calls |
| ESC | ⏳ | Marcus |  | Needs unittesting |
| ESCs | ⏳ | Marcus |  | Needs unittesting |
| Sonar | ⏳ | Marcus |  |  |
| Sonars | ⏳ | Marcus |  | Can use port manipulation for extra speed. Can couple all sonars to a single trigger pin. Can use diodes pointing to interrupt in additon to individual pins to save interrupt pins. (Only have two) |
| Scheduler | ❌ |  |  |  |
| Sonar | ❌ |  |  | Use SPI if possible |
| Communication with main processor | ❌ | | | |
| Data manipulation logic | ❌ | | | |
| Readings cache | ❌ | | | |

✅ for finished, ⏳ for in progress and ❌ for not started yet