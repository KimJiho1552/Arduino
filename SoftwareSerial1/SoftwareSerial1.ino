#include <SoftwareSerial.h>

#define TX 6
#define RX 7

SoftwareSerial soft_Serial(TX, RX);

void setup() {
  //Serial.begin(9600); // TX 1, RX 0
  soft_Serial.begin(9600); //TX 6, RX 7
  pinMode(13, OUTPUT);
}

void loop() {
  soft_Serial.print(1);
  digitalWrite(13, HIGH);
  delay(1000);
  ///digitalWrite(13, LOW);
  //delay(1000);
  soft_Serial.print(2);
  //digitalWrite(13, HIGH);
  //delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
