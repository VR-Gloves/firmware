#ifndef FingerControl_h
#define FingerControl_

#include <Servo.h>

class FingerControl {
public:
  FingerControl(int Servo_pin, int Pot_pin);
  void moveServo(int percentage);
  int fingerPos();
private:
  int Servo_pin, Pot_pin;
};

#endif