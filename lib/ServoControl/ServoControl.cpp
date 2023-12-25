#include "ServoControl.h"

Servo servo = Servo();

void move(int pin,int percentage) {
  if (percentage < 0) {
    percentage = 0;
  } else if (percentage > 100) {
    percentage = 100;
  }

  int angle = map(percentage, 0, 100, 0, 180);
  servo.write(pin, angle); 
}