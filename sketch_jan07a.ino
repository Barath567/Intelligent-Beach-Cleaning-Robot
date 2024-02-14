#include <Sabertooth.h>

const int straightSpeed = 100;  // Adjust speed for straight line motion
const int rotationSpeed = 100;  // Adjust speed for rotation
const int potPin = A0;          // Analog pin for potentiometer

// Create an instance of Sabertooth by specifying the address and the Serial port
Sabertooth ST(128, Serial);  // Address 128, using the hardware serial port

void setup() {
  // Set the baud rate for the Serial port (should match Sabertooth's baud rate)
  Serial.begin(9600);  // Change baud rate if your Sabertooth is set to a different rate

  // Initialize communication with Sabertooth
  ST.autobaud(); // Autobaud sets the correct baud rate for the Sabertooth
}

void loop() {
  // Move forward for 5 seconds with speed controlled by the potentiometer
  moveStraight(5);

  // Rotate in a semi-circle for a few seconds with a fixed speed
  rotateSemiCircle();

  // Move forward for 5 seconds again with speed controlled by the potentiometer
  moveStraight(5);

    // Rotate in a semi-circle for a few seconds with a fixed speed
  rotateSemiCircle();

  // Move forward for 5 seconds again with speed controlled by the potentiometer
  moveStraight(5);
}

void moveStraight(int seconds) {
  // Read the potentiometer value (values range from 0 to 1023)
  int potValue = analogRead(potPin);

  // Map the potentiometer value to the motor speed range (-127 to 127)
  int motorSpeed = map(potValue, 0, 1023, -127, 127);

  // Drive both motors forward with the speed controlled by the potentiometer
  ST.motor(1, motorSpeed);
  ST.motor(2, motorSpeed);

  // Delay for the specified number of seconds
  delay(seconds * 1000);

  // Stop both motors
  ST.motor(1, 0);
  ST.motor(2, 0);

  // Delay for a short time to prevent rapid changes
  delay(500);
}

void rotateSemiCircle() {
  // Drive one motor forward and the other backward to create a rotation
  ST.motor(1, rotationSpeed);
  ST.motor(2, -rotationSpeed);

  // Delay for a few seconds to complete the semi-circle
  delay(5000);

  // Stop both motors
  ST.motor(1, 0);
  ST.motor(2, 0);

  // Delay for a short time to prevent rapid changes
  delay(500);
}
