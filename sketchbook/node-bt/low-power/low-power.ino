#include <SoftwareSerial.h>

//SoftwareSerial ms(5, 6); // Arduino RX, TX

SoftwareSerial bt(9, 7); // BT RX, TX

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  //pinMode(PB7, OUTPUT); //

  pinMode(11, OUTPUT);
  //digitalWrite(11, HIGH); // pull down for low power mode

  Serial.begin(9600);
  bt.begin(9600);
   
  digitalWrite(11, LOW); // low power mode
  
  //bt.println("AT+MODE=0"); // enter into command mode
  // bt.println("AT+STBY=0"); // normal mode 
  //bt.println("AT+STBY=1"); // low power mode
  
}

void loop() {
  if (bt.available())
    Serial.write(bt.read());

  if (Serial.available())
    bt.write(Serial.read());
  
}
