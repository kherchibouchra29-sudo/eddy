#include <Servo.h>

// Create servo objects for each finger
Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRingPinky;

// Arduino pins
const int pinThumb = 9;
const int pinIndex = 10;
const int pinMiddle = 11;
const int pinRingPinky = 6;  // <-- semicolon fixed

const int buzzer = 3;

// Simple open/close angles
const int OPEN = 180;  // fully straight
const int CLOSE = 0;   // fully bent

void setup() {
  servoThumb.attach(pinThumb);
  servoIndex.attach(pinIndex);
  servoMiddle.attach(pinMiddle);
  servoRingPinky.attach(pinRingPinky);

pinMode(buzzer, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    char move = Serial.read();

    if (move == 'R') {        // Rock
      rockFingers();
    } else if (move == 'P') { // Paper
      paperFingers();
    } else if (move == 'S') { // Scissors
      scissorsFingers();
    }
  }
}

// Rock = all fingers bent
void rockFingers() {
  servoThumb.write(CLOSE);
  servoIndex.write(CLOSE);
  servoMiddle.write(CLOSE);
  servoRingPinky.write(CLOSE);
}

// Paper = all fingers open
void paperFingers() {
  servoThumb.write(OPEN);
  servoIndex.write(OPEN);
  servoMiddle.write(OPEN);
  servoRingPinky.write(OPEN);
}

// Scissors = index & middle open, others closed
void scissorsFingers() {
  servoThumb.write(CLOSE);      // thumb bent
  servoIndex.write(OPEN);       // index straight
  servoMiddle.write(OPEN);      // middle straight
  servoRingPinky.write(CLOSE);  // ring bent
}

