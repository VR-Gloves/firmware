#ifndef ServoControl_h
#define ServoControl_h

#include <Servo.h>

class ServoControl {
  private:
    Servo servo;
    int pin;

  public:
    ServoControl(int pin);
    void move(int percentage);
};

#endif