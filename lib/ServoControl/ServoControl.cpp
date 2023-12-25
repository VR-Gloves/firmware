#include "ServoControl.h"


Servo servo = Servo();

ServoControl::ServoControl(int pin) : pin(pin) {
  servo.attach(pin);
}

void ServoControl::moveServo(int percentage) {
  
  if (percentage < 0) {
    percentage = 0;
  } else if (percentage > 100) {
    percentage = 100;
  }

  int angle = map(percentage, 0, 100, 0, 180);
  servo.write(pin, angle); 
}