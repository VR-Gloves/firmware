#include "ServoControl.h"
#include <Servo.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
ServoControl sp1 = ServoControl(5);
ServoControl sp2 = ServoControl(8);
ServoControl sp3 = ServoControl(25);
ServoControl sp4 = ServoControl(26);
ServoControl sp5 = ServoControl(12);

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Glove_R");
  SerialBT.setTimeout(100);
}

int values[5];

void loop() {
   if (SerialBT.available()) {
    String receivedString = SerialBT.readStringUntil('\n');
    for (int i = 0; i < 5; i++) {
      int idx = receivedString.indexOf(';');
      if (idx != -1) {
        values[i] = receivedString.substring(0, idx).toInt();
        receivedString = receivedString.substring(idx + 1);
      } else {
        values[i] = receivedString.toInt();
      }
    }
  } 


  for(int i=0;i<5;i++){
    Serial.print(values[i]);
    Serial.print("\t");
    }
  Serial.println("");

  sp1.moveServo(values[0]);
  sp2.moveServo(values[1]);
  sp3.moveServo(values[2]);
  sp4.moveServo(values[3]);
  sp5.moveServo(values[4]);


}