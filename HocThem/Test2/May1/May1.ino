#include <BlynkSimpleStream.h> // Blynk
#include <DHT.h> // Thư viện DHT11

#define pinLight 4
#define DHTPIN A0
#define pinSOIL A1

#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define BLYNK_PRINT DebugSerial
#define BLYNK_TEMPLATE_ID "TMPLSWy0uUgW"
#define BLYNK_DEVICE_NAME "CayTrai"
#define BLYNK_AUTH_TOKEN "Tts2WJWwPD_a1c0OejzikcYrdszZwrKk"
char auth[] = "Tts2WJWwPD_a1c0OejzikcYrdszZwrKk";

byte statusLight;
float valueDoAm, valueNhietDo = 0;
int statusSOIL = 0;

void setup() {
  pinMode(DHTPIN, INPUT);
  pinMode(pinSOIL, INPUT);
  pinMode(pinLight, INPUT);

  dht.begin();

  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop() {
  Blynk.run();
  statusSOIL = analogRead(pinSOIL); // CHECK - Độ ẩm đất
  statusLight = digitalRead(pinLight); // CHECK - AS

  valueDoAm = dht.readHumidity(); // CHECK - Độ ẩm không khí
  valueNhietDo = dht.readTemperature(); // CHECK - Nhiệt độ

  DebugSerial.println("Nhiet do: ");
  DebugSerial.println(valueNhietDo);
  DebugSerial.println("Do am KK: ");
  DebugSerial.println(valueDoAm);
  DebugSerial.println("Do am DAT: ");
  DebugSerial.println(statusSOIL);
  DebugSerial.println("Sang/Toi: ");
  DebugSerial.println(statusLight);

  Blynk.virtualWrite(V0, valueNhietDo); // Blynk - Nhiệt độ
  Blynk.virtualWrite(V1, valueDoAm); // Blynk - Đ.A Không khí
  Blynk.virtualWrite(V2, statusSOIL); // Blynk - Đ.A Đất
  Blynk.virtualWrite(V3, statusLight); // ANH SANG

}
