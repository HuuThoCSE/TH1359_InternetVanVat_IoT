#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "RTClib.h"

#define DHTPIN A0
#define pinLED 8

#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27,20,4);

RTC_PCF8523 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};


void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(DHTPIN, INPUT);

  pinMode(pinLED, OUTPUT);

  lcd.init();

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.initialized() || rtc.lostPower()) {
    Serial.println("RTC is NOT initialized, let's set the time!");
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  rtc.start();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Nhiet do: ");
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("Do am KK: ");
  lcd.print(h);

  if(t > 30){
    digitalWrite(pinLED, 1);
  } else {
    digitalWrite(pinLED, 0);
  }

  DateTime now = rtc.now();
  lcd.setCursor(0,2);
  lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
  lcd.print(' ');
  lcd.print(now.hour());
  lcd.print(':');
  lcd.print(now.minute());
  lcd.print(':');
  lcd.print(now.second());
  lcd.print(' ');

  lcd.setCursor(0,3);
  lcd.print(now.day());
  lcd.print("/");
  lcd.print(now.month());
  lcd.print("/");
  lcd.print(now.year());

  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(' ');
  Serial.print(now.hour());
  Serial.print(':');
  Serial.print(now.minute());
  Serial.print(':');
  Serial.print(now.second());
  Serial.println();

  Serial.print(now.day());
  Serial.print("/");
  Serial.print(now.month());
  Serial.print("/");
  Serial.println(now.year());

  delay(5000);
}
