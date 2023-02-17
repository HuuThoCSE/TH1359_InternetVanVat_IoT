#include "DHT.h"
#include <LiquidCrystal.h>
#define pinDHT A0
#define typeDHT DHT11

DHT dht(pinDHT, typeDHT);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // float h = dht.readHumidity();
  // float t = dht.readTemperature();
  float h = random(100);
  float t = random(100);

  Serial.print("Do am: ");
  Serial.print(h);
  Serial.print(". Nhiet do: ");
  Serial.println(t);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Do am: ");
  lcd.print(h);
  lcd.setCursor(0, 1);
  lcd.print("Nhiet do: ");
  lcd.print(t);
}
