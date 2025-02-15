#include <Servo.h>

// Define pins for ultrasonic sensor
const int trigPin = 2;
const int echoPin = 3;



// Define servo object
Servo servoMotor;

// Distance threshold (in cm)
const int distanceThreshold = 5;

// Variables for distance measurement
long duration;
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set up ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach servo to pin
  servoMotor.attach(9); // Connect servo to pin 6
  servoMotor.write(0);  // Ensure dustbin lid is closed at startup
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo time
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  // Debugging: Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the object is within the distance threshold
  if (distance > 0 && distance <= distanceThreshold) {
    servoMotor.write(90); // Open the dustbin lid
    delay(3000);          // Wait for 3 seconds
    servoMotor.write(0);  // Close the lid
  }

  delay(200); // Small delay for stability
}
