void setup() { //조도 센서
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  int val = analogRead(A0);
  int val2 = map(val, 0, 160, 0, 255);
  Serial.print("CDS : ");
  Serial.print(val);
  Serial.print("\t");
  Serial.print("map : ");
  Serial.println(val2);
}
