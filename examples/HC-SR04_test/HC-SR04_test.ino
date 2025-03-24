// Define pins for HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Define variable to store the distance
long duration;
float distance;

void setup() {
  // Initialize serial communication
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

  // Display the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100); // Delay for half a second
}
