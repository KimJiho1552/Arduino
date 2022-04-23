void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(7));
}
