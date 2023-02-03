byte ledPin[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
byte pinCount;
unsigned long time1 = 0;
unsigned long time2 = 0;
int i;
void setup() {
  pinCount = sizeof(ledPin);
  for (i = 0; i < pinCount; i++) {
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], LOW);
  }
}

void loop() {
  for (i = 0; i < pinCount/2; i++) {
    digitalWrite(ledPin[i], HIGH);
    digitalWrite(ledPin[pinCount-1-i], HIGH);
    delay(200);
  }

  for (i = pinCount/2; i >= 0; i--) {
    digitalWrite(ledPin[i], LOW);
    digitalWrite(ledPin[pinCount-1-i], LOW);
    delay(200);
  }

}
