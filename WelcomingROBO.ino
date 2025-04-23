// Bluetooth-Controlled Car using HC-05 and Arduino
#include <SoftwareSerial.h>

// Define pins for the HC-05 module
SoftwareSerial BTSerial(2,3); // RX | TX (Connect TX of HC-05 to pin 10, RX to pin 11)

// Define motor control pins
#define ENA 10  // Enable pin for Motor A
#define IN1 9 // Input 1 for Motor A
#define IN2 8  // Input 2 for Motor A
#define ENB 5 // Enable pin for Motor B
#define IN3 7 // Input 1 for Motor B
#define IN4 6 // Input 2 for Motor B

char command; // Variable to store Bluetooth commands


void setup() {
  // Initialize motor control pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start serial communication
  Serial.begin(9600);   // For Arduino IDE monitor
  BTSerial.begin(9600); // For HC-05 Bluetooth module

  Serial.println("Bluetooth Car Ready");
}

void loop() {
  // Check if a command is received via Bluetooth
  if (BTSerial.available()) {
    command = BTSerial.read();
    Serial.println(command); // Print the received command to the Serial Monitor

    // Execute motor control based on the command
    if (command == 'F') {
      moveForward();
    } else if (command == 'B') {
      moveBackward();
    } else if (command == 'L') {
      turnLeft();
    } else if (command == 'R') {
      turnRight();
    } else if (command == 'S') {
      stopMotors();
    } else {
      stopMotors(); // Stop if an unknown command is received
    }
  }
}

// Function to move the car forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255);
}

// Function to move the car backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255);
}

// Function to turn the car left
void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255);
}

// Function to turn the car right
void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255); // Adjust speed (0-255)
  analogWrite(ENB, 255);
}

// Function to stop the motors
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
