#include <Servo.h>

Servo my_Servo;

void setup() {
  Serial.begin(9600);
  my_Servo.attach(11);
  pinMode(A0, INPUT);
}

void loop() {
  /*
  for(int i = 0; i < 180; i++) {
    my_Servo.write(i);
    delay(100);
  }
  */

  int analog_In = analogRead(A0);
  int analog_Out = map(analog_In, 0, 1023, 0, 180);

  my_Servo.write(analog_Out);

  Serial.print("가변저항 : ");
  Serial.print(analog_In);
  Serial.print("\t");
  Serial.print("Motor : ");
  Serial.println(analog_Out);
}
