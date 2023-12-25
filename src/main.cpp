#include "ServoControl.h"
#include <Servo.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
const int sp1 = 5;
const int sp2 = 8;
const int sp3 = 25;
const int sp4 = 26;
const int sp5 = 12;

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

  move(sp1,values[0]);
  move(sp2,values[1]);
  move(sp3,values[2]);
  move(sp4,values[3]);
  move(sp5,values[4]);
  delay(10);

}