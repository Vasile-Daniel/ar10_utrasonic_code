// Vasile-Daniel DAN
// Date: 02 MAY 2024 

#include "SR04.h" // Including the library for interfacing with an ultrasonic sensor

const int trigPin = 12; // Assigning pin 12 for the trigger pin of the ultrasonic sensor
const int echoPin = 11; // Assigning pin 11 for the echo pin of the ultrasonic sensor
const int ledPin = 13;  // Assigning pin 13 for the LED

void setup() {
  Serial.begin(9600); // Initializing serial communication at 9600 baud
  pinMode(trigPin, OUTPUT); // Setting trigPin as an output
  pinMode(echoPin, INPUT);  // Setting echoPin as an input
  pinMode(ledPin, OUTPUT);  // Setting ledPin as an output
}

void loop() {
  int distance = readDistance(); // Reading the distance measured by the ultrasonic sensor
  Serial.println(distance); // Printing the distance to the serial monitor

  // Turning on the LED if the distance is less than 20 centimeters, else turning it off
  if (distance < 20) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(1000); // Adding a delay of 1 second
}

// Function to read the distance measured by the ultrasonic sensor
int readDistance() {
  digitalWrite(trigPin, LOW); // Sending a short LOW pulse to the trigger pin
  delayMicroseconds(2); // Delay for 2 microseconds

  digitalWrite(trigPin, HIGH); // Sending a HIGH pulse to the trigger pin
  delayMicroseconds(10); // Delay for 10 microseconds
  digitalWrite(trigPin, LOW); // Turning off the trigger pin

  long duration = pulseIn(echoPin, HIGH); // Measuring the duration of the pulse received on the echo pin
  int distance = duration * 0.034 / 2; // Calculating the distance based on the duration

  return distance; // Returning the calculated distance
}

