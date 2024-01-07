#include "FingerControl.h"


Servo servo = Servo();

FingerControl::FingerControl(int Servo_pin, int Pot_pin) : Servo_pin(Servo_pin), Pot_pin(Pot_pin) {
  servo.attach(Servo_pin);

}

int FingerControl::fingerPos(){
  int pozitie = map(analogRead(Pot_pin), 0, 4095, 0,100);
  return pozitie;
}

void FingerControl::moveServo(int percentage) {
  
  if (percentage < 0) {
    percentage = 0;
  } else if (percentage > 100) {
    percentage = 100;
  }

  int angle = map(percentage, 0, 100, 0, 180);
  servo.write(Servo_pin, angle); 
}