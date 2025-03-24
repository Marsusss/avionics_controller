#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM9DS1.h>

// Create an instance of the sensor
Adafruit_LSM9DS1 lsm = Adafruit_LSM9DS1();

// Addresses for the LSM9DS1 (defined by the breakout)
#define LSM9DS1_XG_ADDRESS (0x6B) // Accelerometer & Gyro
#define LSM9DS1_M_ADDRESS (0x1E)  // Magnetometer

void setup() {
  Serial.begin(115200); // Start serial communication
  while (!Serial) delay(10);

  // Initialize the LSM9DS1 sensor
  if (!lsm.begin()) {
    Serial.println("Failed to detect LSM9DS1. Check your wiring!");
    while (1);
  }
  Serial.println("LSM9DS1 detected!");
}

void loop() {
  // Read accelerometer data
  sensors_event_t a, g, m, temp;
  lsm.getEvent(&a, &g, &m, &temp);

  // Print accelerometer readings
  Serial.print("Accel X: "); Serial.print(a.acceleration.x); Serial.print(" m/s^2 ");
  Serial.print(" Y: "); Serial.print(a.acceleration.y); Serial.print(" m/s^2 ");
  Serial.print(" Z: "); Serial.print(a.acceleration.z); Serial.println(" m/s^2");

  delay(1000); // Wait 1 second between readings
}
