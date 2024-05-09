#include <Servo.h>
#include <pwmWrite.h>

#include "FingerControl.h"

#include <BluetoothSerial.h>

String device_name = "GloveR";

// Check if Bluetooth is available
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
  #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Check Serial Port Profile
#if !defined(CONFIG_BT_SPP_ENABLED)
  #error Serial Port Profile for Bluetooth is not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

FingerControl sp1 = FingerControl(27,32);
FingerControl sp2 = FingerControl(26,15);
FingerControl sp3 = FingerControl(25,13);
FingerControl sp4 = FingerControl(33,12);
FingerControl sp5 = FingerControl(4,14);



void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name);
  Serial.printf("started");
  SerialBT.setTimeout(100);
  pinMode(sp1.Pot_pin,INPUT);
  pinMode(sp2.Pot_pin,INPUT);
  pinMode(sp3.Pot_pin,INPUT);
  pinMode(sp4.Pot_pin,INPUT);
  pinMode(sp5.Pot_pin,INPUT);

}

int values[5]={0,0,0,0,0};
int mod=0;
void loop() {
  mod=0;
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
    mod=1;
    } 
    

    Serial.print(sp1.fingerPos());
    Serial.print(' ');
    Serial.print(sp2.fingerPos());
    Serial.print(' '); 
    Serial.print(sp3.fingerPos());
    Serial.print(' '); 
    Serial.print(sp4.fingerPos());
    Serial.print(' '); 
    Serial.println(sp5.fingerPos());
    delay(100);


  if(mod==1){
  sp1.moveServo(values[0]);delay(100);
  sp2.moveServo(values[1]);delay(100);
  sp3.moveServo(values[2]);delay(100);
  sp4.moveServo(values[3]);delay(100);
  sp5.moveServo(values[4]);delay(100);
  }

  

} 