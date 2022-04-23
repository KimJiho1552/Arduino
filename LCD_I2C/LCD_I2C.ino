#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("hello, world");
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    lcd.clear();
    lcd.setCursor(0, 1); //두 번째 줄 출력
    delay(100);
    
    while(Serial.available() > 0) {
      lcd.write(Serial.read());
    }
  }
}
