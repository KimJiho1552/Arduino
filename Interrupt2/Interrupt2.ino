volatile byte state = HIGH;

void isr() {
  digitalWrite(13, state);
  Serial.println(state);
  state = !state;
}

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  attachInterrupt(0, isr, RISING);
}

void loop() {
}
