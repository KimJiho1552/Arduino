#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.print(" Kim Jiho");

  lcd.setCursor(0, 1);
  lcd.print("CDS:");

  lcd.setCursor(9, 1);
  lcd.print("LED:");

  pinMode(A0, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int cds = analogRead(A0);
 
  lcd.setCursor(4, 1);
  lcd.print("    ");
  lcd.setCursor(4, 1);
  lcd.print(cds);
  
  if(cds < 100) {
    digitalWrite(13, HIGH);
    lcd.setCursor(13, 1);
    lcd.print("ON ");
  }
  else {
    digitalWrite(13, LOW);
    lcd.setCursor(13, 1);
    lcd.print("OFF");
  }

  delay(500);
}
