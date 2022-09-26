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

  digitalWrite(11, LOW);
  bt.println("AT+MODE=0"); // enter into command mode



}


void loop() {


  if (bt.available())
    Serial.write(bt.read());


  if (Serial.available()){
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(11, LOW);
  delay(100);
  digitalWrite(11, HIGH);
  delay(100); 
  digitalWrite(11, LOW);
  bt.write(Serial.read());}
  
}
