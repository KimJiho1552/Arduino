#include <SoftwareSerial.h>

#include <SPI.h>
#include <deprecated.h> //RFID
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#define RST_PIN 9
#define SS_PIN 10
MFRC522 mfrc(SS_PIN, RST_PIN);

#define TX 3
#define RX 4

SoftwareSerial soft_Serial(TX, RX);
char* ary[4];
void setup() {
  Serial.begin(9600);
  soft_Serial.begin(9600);
}

void loop() {
  char card_num[30] = {'\0'};
  int i = 0;

  while(soft_Serial.available()){
    card_num[i] = soft_Serial.read();
    Serial.print(card_num[i]);
    i++;
    delay(1);
  }
    char* ptr = strtok(card_num, " ");
  int j = 0;
  
  while (ptr != '\0') {
    ary[j] = ptr;
    Serial.print(ptr);
    ptr = strtok(NULL, " ");
    j++;
    }
  
}
