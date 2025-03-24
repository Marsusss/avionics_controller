// Define the pin for the LED and the ultrasonic sensor
const int ledPin = 13; // Use the built-in LED or an external one
const int trigPin = 9;
const int echoPin = 10;

// Variables for calculating distance
long duration;
float distance;

void setup() {
  // Initialize the LED pin as an output
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  // Set trigPin as output and echoPin as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Send a 10µs HIGH pulse to the TRIG pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time for the pulse to return
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  distance = (duration * 0.0343) / 2;

  // Control the LED based on distance
  if (distance <= 10) {
    digitalWrite(ledPin, HIGH); // Turn LED on
  } else {
    digitalWrite(ledPin, LOW); // Turn LED off
  }

  // Print the distance to Serial Monitor for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(10); // Wait 500 ms before the next reading
}
