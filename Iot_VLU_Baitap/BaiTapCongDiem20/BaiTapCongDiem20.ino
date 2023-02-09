#include <DHT.h>

#define pinDHT A0
#define pinLed 9

#define DHTTYPE DHT11
DHT dht(pinDHT, DHTTYPE);

int value, buf[3], i = 0;
float avgValue = 0;
void setup() {
  pinMode(pinDHT, INPUT);
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  value= dht.readHumidity();
  Serial.println(value);
  buf[2] = buf[1];
  buf[1] = buf[0];
  buf[0]=value;
  avgValue = (buf[0]+buf[1]+buf[0])/3.0;
  Serial.print("=>");
  Serial.println(avgValue);
  if(avgValue < 40)
    digitalWrite(pinLed, 1);
  else 
    digitalWrite(pinLed, 0);
  delay(100);
}

