#include "FingerControl.h"
#include <Servo.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
FingerControl sp1 = FingerControl(13,23);
FingerControl sp2 = FingerControl(14,24);
FingerControl sp3 = FingerControl(15,25);
FingerControl sp4 = FingerControl(12,22);
FingerControl sp5 = FingerControl(26,21);



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

  if(SerialBT.available()){
    int data_array[] = {sp1.fingerPos(), 
                        sp2.fingerPos(),
                        sp3.fingerPos(),
                        sp4.fingerPos(),
                        sp5.fingerPos()};
    byte byte_array[sizeof(data_array)/sizeof(int)];

    for(int i = 0; i < sizeof(data_array)/sizeof(int); i++) {
      byte_array[i] = (byte)data_array[i];
    }

    SerialBT.write(byte_array, sizeof(byte_array));


  }

  /* for(int i=0;i<5;i++){
    Serial.print(values[i]);
    Serial.print("\t");
    }
  Serial.println(""); */

  sp1.moveServo(values[0]);
  sp2.moveServo(values[1]);
  sp3.moveServo(values[2]);
  sp4.moveServo(values[3]);
  sp5.moveServo(values[4]);


  

} 