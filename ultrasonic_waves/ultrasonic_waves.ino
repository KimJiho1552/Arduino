int trig = 2;
int echo = 3;

void setup() { //초음파
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int dis = pulseIn(echo, HIGH) * 340 / 2 / 10000; //cm 단위
  Serial.println(dis);
  delay(100);
}
