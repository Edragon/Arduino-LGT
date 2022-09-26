#include <SoftwareSerial.h>
SoftwareSerial bt(9, 7); // RX, TX

void setup() {
  Serial.begin(9600);
  pinMode(PB7, OUTPUT); // test
  // pinMode(11, OUTPUT); //  enable send on low power mode
  bt.begin(9600);

}


void loop() {
  //digitalWrite(11, LOW);

  // bt.println("987654");
  //  ms.println("987654");
  //  delay(1000);
  //ms.listen();

  //  if (bt.available()) {
  //    ms.write(bt.read());
  //  }


  while (Serial.available() > 0) {
    char inByte = Serial.read();
    bt.write(inByte);
  }

  //  if (ms.available()) {
  //    bt.write(ms.read());
  //  }


}
