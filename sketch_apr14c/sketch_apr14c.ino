long randomNum;
unsigned long pre_time = 0;
unsigned long cur_time = 0;

void isr() { //인터럽트
  cur_time = millis(); //눌렸을 때 현재 시간 저장
  if(cur_time - pre_time >= 1000) {
    randomNum = random(1, 10);
    Serial.println(randomNum);
    pre_time = cur_time;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  randomSeed(analogRead(0));
  attachInterrupt(0, isr, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

}
