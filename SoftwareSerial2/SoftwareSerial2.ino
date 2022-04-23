#include <SoftwareSerial.h>

#define TX 6
#define RX 7

SoftwareSerial soft_Serial(TX, RX);

void setup() {
  Serial.begin(9600);
  soft_Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  /*if(soft_Serial.available() > 0) {
    int data = soft_Serial.read();
    if(data == 49) {
      digitalWrite(13, HIGH);
      //Serial.println("a");
    }
    else if(data == 50) {
      digitalWrite(13, HIGH);
      //Serial.println("b");
    }
    else {
      digitalWrite(13, LOW);
    }
  }*/

  String myString = soft_Serial.readString();

  if(myString == "YES")
    Serial.println("success");
  else if(myString == "NO")
    Serial.println("fall");
}
