#include <ServoControl.h>

ServoControl servocontrol(9); // Initialize servo on pin 9

void setup() {
  // Nothing to do here
}

void loop() {
  for (int i = 0; i <= 100; i++) {
    servocontrol.move(i); // Move servo from 0% to 100%
    delay(15);
  }
}