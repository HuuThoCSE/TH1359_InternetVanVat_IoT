int pinLed = 13;
int btnLed = 12;
int value = 0;
void setup() {
  pinMode(btnLed, INPUT);
  pinMode(pinLed, OUTPUT);
}

void loop() {
  value = digitalRead(btnLed);
  if(value != 0){
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}
