#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시
int tempo = 200;
int notes[25] = { G, G, A, A, G, G, E,
                  G, G, E, E, D, G, G,
                  A, A, G, G, E, G, E, D, E, C };

int trig = 2;
int echo = 3;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.print(" Kim Jiho");

  lcd.setCursor(0, 1);
  lcd.print("distance:");

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(8, OUTPUT); //buzzer
  pinMode(7, OUTPUT);
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int dis = pulseIn(echo, HIGH) * 340 / 2 / 10000; //cm 단위
  delay(100);

  lcd.setCursor(9, 1);
  lcd.print("    ");
  lcd.setCursor(9, 1);
  lcd.print(dis);
  lcd.setCursor(13, 1);
  lcd.print("cm");

  if(dis > 25) {
    digitalWrite(8, LOW);

    for (int i = 0; i < 12; i++) {
      tone (7, notes[i], tempo);
      delay (300);
    }
    //if(dis <= 25) break;
  }
  else if((dis <= 25)&&(dis > 5)) {
    digitalWrite(8, HIGH);
    delay(dis * 10);
    digitalWrite(8, LOW);

    digitalWrite(7, LOW);
  }
  else {
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
  }
}
