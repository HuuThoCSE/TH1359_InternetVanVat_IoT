#include "DHT.h"

#define pinDHT A0
#define pinLed1 2
#define pinLed2 3
#define pinLed3 4
#define pinLed4 5

#define DHTTYPE DHT11

DHT dht(pinDHT, DHTTYPE);

float buf[10], t, h, sumbuf, avg = 0;
unsigned long Time, TimeLed, Time2Led, TimeCheckNhietDo = 0;
unsigned long Time4Led = 0;
bool led_state = false;

void setup() {
  Serial.begin(9600);
  pinMode(pinDHT, INPUT);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  dht.begin();
}

void loop() {
  Time = millis();
  if(Time - TimeCheckNhietDo <= 50000){
    // h = dht.readHumidity();
    // t = dht.readTemperature();
    h = random(100);
    t = random(100);
    TimeCheckNhietDo = Time;
    Serial.print("Nhiet do: ");
    Serial.print(t);
    Serial.print(" - Do am: ");
    Serial.println(h);
  }
  // Kich ban 1
  if(t < 30){
    digitalWrite(pinLed1, 1);
  } else {
    digitalWrite(pinLed1, 0);
  }

  // Kich ban 2
  for(int i=6; i>=0; i--){
    buf[i] = t;
    buf[i-1] = buf[i];
  }

  for(int i=0; i<7; i++)
    sumbuf = sumbuf+buf[i];
  avg = sumbuf/7;

  if(avg < 32)
    digitalWrite(pinLed2, 1);
  else
    digitalWrite(pinLed2, 0);

  // Kich ban 3
  if (led_state) {
    if (Time - Time2Led >= 200) {
      led_state = false;
      digitalWrite(pinLed3, LOW);
      Time2Led = Time;
    }
  } else {
    if (Time - Time2Led >= 3000-200) {
      led_state = true;
      digitalWrite(pinLed3, HIGH);
      Time2Led = Time;
    }
  }
  Bai tap them
  t = 45; h = 50;
  if(Time - Time4Led <= 1000){
    if(t > 30 && h < 80){
      digitalWrite(pinLed4, !digitalRead(pinLed4));
    }
  }
}
