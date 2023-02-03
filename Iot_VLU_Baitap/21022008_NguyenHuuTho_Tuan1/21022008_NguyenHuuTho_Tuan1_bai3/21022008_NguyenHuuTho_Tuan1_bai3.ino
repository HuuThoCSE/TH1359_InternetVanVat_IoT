int pinLed = 13;
unsigned long timeLed13 = 0;
unsigned long curTime = 0;

void setup() {
  pinMode(pinLed, OUTPUT);
}

void loop() {
  curTime = millis();
  if(curTime - timeLed13 >= 5000){
    timeLed13 = curTime;
    digitalWrite(pinLed, !digitalRead(pinLed));
  }
}
