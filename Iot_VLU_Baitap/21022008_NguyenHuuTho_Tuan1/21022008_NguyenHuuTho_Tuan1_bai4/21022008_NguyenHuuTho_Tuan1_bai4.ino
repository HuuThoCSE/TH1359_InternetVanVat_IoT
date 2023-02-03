byte pinLedR = 3;
byte pinLedY = 4;
byte pinLedG = 5;

void setup() {
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedY, OUTPUT);
  pinMode(pinLedG, OUTPUT);
}

void loop() {
  digitalWrite(pinLedR, HIGH);
  delay(5000);
  digitalWrite(pinLedR, LOW);
  digitalWrite(pinLedY, HIGH);
  delay(3000);
  digitalWrite(pinLedY, LOW);
  digitalWrite(pinLedG, HIGH);
  delay(1000);
  digitalWrite(pinLedG, LOW);
}
