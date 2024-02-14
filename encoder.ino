#include <Sabertooth.h>

volatile unsigned int temp, counter = 0; //This variable will increase or decrease depending on the rotation of encoder

const int potPin = A0;  // Analog pin for potentiometer
int potValue;           // Variable to store potentiometer value

// Create an instance of Sabertooth by specifying the address and the Serial port
Sabertooth ST(128, Serial);  // Address 128, using the hardware serial port

void setup() {
  // Set the baud rate for the Serial port (should match Sabertooth's baud rate)
  Serial.begin(9600);  // Change baud rate if your Sabertooth is set to a different rate

  // Initialize communication with Sabertooth
  ST.autobaud(); // Autobaud sets the correct baud rate for the Sabertooth


  pinMode(5, INPUT_PULLUP); // internal pullup input pin 2 
  
  pinMode(6, INPUT_PULLUP); // internalเป็น pullup input pin 3
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(0, ai0, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(1, ai1, RISING);
}

void loop() {
  // Read the potentiometer value (values range from 0 to 1023)
  potValue = analogRead(potPin);

  // Map the potentiometer value to the motor speed range (-127 to 127)
  int motorSpeed = map(potValue, 0, 1023, -127, 127);

  // Drive both motors forward with the speed controlled by the potentiometer
  ST.motor(1, motorSpeed);
  ST.motor(2, motorSpeed);

  // You can add additional functionality or control logic here

  delay(100); // Add a short delay to prevent rapid changes



    // Send the value of counter
  if( counter != temp ){
  Serial.println (counter);
  temp = counter;
  }
  }
   
  void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(6)==LOW) {
  counter++;
  }else{
  counter--;
  }
  }
   
  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if(digitalRead(5)==LOW) {
  counter--;
  }else{
  counter++;
  }
}
    
