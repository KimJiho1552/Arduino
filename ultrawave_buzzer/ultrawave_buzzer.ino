int trig = 2;
int echo = 3;

void setup() { //초음파
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(8, OUTPUT); //buzzer
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int dis = pulseIn(echo, HIGH) * 340 / 2 / 10000; //cm 단위
  Serial.println(dis);
  delay(100);

  if(dis > 25) {
    digitalWrite(8, LOW);
  }
  else if((dis <= 25)&&(dis > 5)) {
    digitalWrite(8, HIGH);
    delay(dis * 10);
    digitalWrite(8, LOW);
  }
  else
    digitalWrite(8, HIGH);
}
