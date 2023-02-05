#include <BlynkSimpleStream.h> // Blynk

#define pinLed 7

#define BLYNK_PRINT DebugSerial

#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#define BLYNK_TEMPLATE_ID "TMPLp3s0eFuY"
#define BLYNK_DEVICE_NAME "HeThongVuonThongMinh"
#define BLYNK_AUTH_TOKEN "1-OlCZbBn0qtYwpZYQI0fnF3av7OvxKJ"
char auth[] = "1-OlCZbBn0qtYwpZYQI0fnF3av7OvxKJ";

void setup() {
  DebugSerial.begin(9600);

  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}

void loop() {
  Blynk.run();
}
