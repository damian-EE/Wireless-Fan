/*
  Wireless Automatic Fan
  2024 CSUB Summer Research Program
  Damian Delgado Ayon & Diego Excontitta

  A battery-powered fan that switches on when an ultrasonic sensor
  detects a person or object within about 2 feet (61 cm), and switches
  off again when nothing is in range.

  Hardware: Arduino Uno R3, ultrasonic distance sensor, L298N motor
  driver, 12V DC motor, dual battery holder, 3D-printed fan blade
  and holder (designed in OnShape).
*/

const int triggerPin = 7;   // Ultrasonic sensor TRIG pin
const int echoPin    = 6;   // Ultrasonic sensor ECHO pin
const int motorPin   = 10;  // L298N input that switches the DC motor on/off

const int TRIGGER_DISTANCE_CM = 61;  // Turn the fan on within ~2 feet

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // Send a 10-microsecond pulse to start an ultrasonic measurement
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Time how long the echo takes to come back (in microseconds)
  long duration = pulseIn(echoPin, HIGH);

  // Convert to distance: sound travels ~0.034 cm per microsecond,
  // and the pulse goes out and back, so divide by 2
  int distance = duration * 0.034 / 2;

  // Run the fan while something is within range
  if (distance <= TRIGGER_DISTANCE_CM) {
    digitalWrite(motorPin, HIGH);  // Fan on
  } else {
    digitalWrite(motorPin, LOW);   // Fan off
  }
}
