#include <SPI.h>

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc.PCD_Init();
}

void loop() {
  if(!mfrc.PICC_IsNewCardPresent()) //카드 인식 안될 때
    return;
  if(!mfrc.PICC_ReadCardSerial()) //예외
    return;
  /*
  if(mfrc.uid.uidByte[0] == 51 &&
     mfrc.uid.uidByte[1] == 165 &&
     mfrc.uid.uidByte[2] == 225 &&
     mfrc.uid.uidByte[3] == 17) {
    Serial.println("Authorized access");
    delay(500);
  }
  else {
    Serial.println("Authorized denied");
    delay(500);
  }
  */
  Serial.print("Card UID:");
  for(byte i = 0; i < 4; i++) {
    Serial.print(mfrc.uid.uidByte[i]);
    Serial.print(" ");
  }
}
