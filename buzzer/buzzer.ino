void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  for(int i = 500; i > 0; i++) {
    digitalWrite(8, HIGH);
    delay(i);
    digitalWrite(8, LOW);
  }
}
