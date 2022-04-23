#include <SoftwareSerial.h>

SoftwareSerial beacon(2, 3);

String myStr = "";

void setup() {
  Serial.begin(9600);
  beacon.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  /*
  if(beacon.available()) {
    Serial.write(beacon.read());
  }
  if(Serial.available()) {
    beacon.write(Serial.read());
  }
  */
  while(beacon.available()) {
    char mychar = beacon.read();
    Serial.print(myStr);
    myStr += mychar;
    delay(5);
  }
  if(!myStr.equals("")) {
    if(myStr == "ledon\r\n")
      digitalWrite(13, HIGH);
    else if(myStr == "ledoff\r\n")
      digitalWrite(13, LOW);
  }
  myStr = "";
}
