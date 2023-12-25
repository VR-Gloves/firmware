#ifndef ServoControl_h
#define ServoControl_

#include <Servo.h>

class ServoControl {
public:
  ServoControl(int pin);
  void moveServo(int percentage);
private:
  int pin;
};

void move(int pin, int percentage);

#endif