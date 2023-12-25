/*
  Controls servo position from 0-180 degrees and back
  https://wokwi.com/projects/350037178957431378
  by dlloydev, December 2022.
*/

#include "ServoControl.h"

//const int sp1 = 5;
//const int sp2 = 8;
//const int sp3 = 25;
//const int sp4 = 26;
//const int sp5 = 12;
ServoControl s1(5);
ServoControl s2(8);

void setup() {
}

void loop() {
  for (int pos = 0; pos <= 100; pos++) {  // go from 0-180 degrees
    s1.move(pos);
    s2.move(100-pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos--) {  // go from 180-0 degrees
    s1.move(pos);
    s2.move(100-pos);          // set the servo position (degrees)
    delay(15);
  }
}