#include "ServoControl.h"
#include <Servo.h>

ServoControl::ServoControl(int pin) {
  this->pin = pin;
  Servo servo = Servo();
}

void ServoControl::move(int percentage) {
  if (percentage < 0) {
    percentage = 0;
  } else if (percentage > 100) {
    percentage = 100;
  }

  int angle = map(percentage, 0, 100, 0, 180);
  servo.write(this->pin, angle); 
}