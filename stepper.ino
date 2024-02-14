// Define L298N motor controller pins
const int enA = 9;  // PWM speed control
const int in1 = 8;
const int in2 = 7;

void setup() {
  // Set motor control pins as OUTPUT
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Run the motor forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  // Set motor speed (0 to 255)
  analogWrite(enA, 150);

  Serial.println("Motor running forward");

  delay(2000);  // Run for 2 seconds

  // Stop the motor
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  Serial.println("Motor stopped");

  delay(1000);  // Wait for 1 second

  // Run the motor backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  Serial.println("Motor running backward");
}
