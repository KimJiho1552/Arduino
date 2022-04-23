#include <IRremote.hpp>

int RECV_PIN = 2;
IRrecv ir(RECV_PIN);
decode_results results;

void setup() { //리모컨 - 수신기
  Serial.begin(9600);
  ir.enableIRIn();
  pinMode(13, OUTPUT);
}

void loop() {
  if(ir.decode(&results)) { //값을 받음
    Serial.println(results.value, HEX);
    if(results.value != 0xFFFFFFFF) {
      if(results.value == 0xFF30CF) {
        digitalWrite(13, HIGH);
      }
      else {
        digitalWrite(13, LOW);
      }
    }
    ir.resume(); //다음 값 받음
  }
  delay(100);
}
