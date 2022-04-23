const int duration = 1000;
unsigned long pre_time = 0;
unsigned long cur_time = 0;

void isr() {
  cur_time = millis(); //눌렸을 때 현재 시간 저장
  if(cur_time - pre_time >= duration) {
    Serial.println("인터럽트 발생");
    pre_time = cur_time;
  }
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, isr, CHANGE);
}

void loop() {
}
