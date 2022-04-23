void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) { //수신된 것이 있을 때만
    int data = Serial.read();
    if(data == 49)            //1
      digitalWrite(13, HIGH);
    else if(data == 50) {     //2
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
      digitalWrite(13, HIGH);
      delay(100);
      digitalWrite(13, LOW);
      delay(100);
    }
    else
      digitalWrite(13, LOW);
  }
}
