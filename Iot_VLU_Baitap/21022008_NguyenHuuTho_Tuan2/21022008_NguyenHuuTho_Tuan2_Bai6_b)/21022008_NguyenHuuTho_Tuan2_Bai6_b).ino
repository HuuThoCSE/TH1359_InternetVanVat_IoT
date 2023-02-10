#define pinLed 13
#define pinBtn 2
void setup() {
  pinMode(pinBtn, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, 0); // Tắt trước khi chạy lần đầu
}

void loop() {
  digitalWrite(pinLed, !digitalRead(pinLed));
}
