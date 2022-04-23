#define RED   13
#define GREEN 12
#define BLUE  11

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) { //수신된 것이 있을 때만
    int data = Serial.read();
    if(data == 49) {
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
      delay(500);
    }
    else if(data == 50) {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, HIGH);
      digitalWrite(BLUE, LOW);
      delay(500);
    }
    else if(data == 51) {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, HIGH);
      delay(500);
    }
    else {
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
      delay(500);
    }
  }
}
