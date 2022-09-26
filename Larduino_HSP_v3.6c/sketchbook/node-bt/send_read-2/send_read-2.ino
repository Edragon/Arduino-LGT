#include <SoftwareSerial.h>
SoftwareSerial bt(9, 7); // BT RX, TX


void setup() {
  pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH); // pull down for low power mode
  Serial.begin(9600);
  bt.begin(9600);
  
  digitalWrite(11, HIGH);
  //delay(100);
  //digitalWrite(11, LOW);
  //delay(100);
  
  bt.println("AT+MODE=0"); // enter into command mode
}

void loop() {
  if (bt.available())
    Serial.write(bt.read());
  if (Serial.available())
    bt.write(Serial.read());
}
