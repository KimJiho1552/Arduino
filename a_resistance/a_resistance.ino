void setup() { //가변저항기
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int analog_In = analogRead(A0);
  int analog_Out = map(analog_In, 0, 1023, 0, 255);
  
  analogWrite(11, analog_Out);

  Serial.print(analog_In);
  Serial.print("\t");
  Serial.println(analog_Out);
}
