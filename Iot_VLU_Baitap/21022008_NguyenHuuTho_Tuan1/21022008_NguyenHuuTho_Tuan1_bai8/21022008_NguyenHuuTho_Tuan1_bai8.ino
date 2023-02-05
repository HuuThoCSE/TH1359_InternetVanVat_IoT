#define pinLed 8
#define pinLDR 9

void setup() {
  pinMode(pinLDR, INPUT);
  pinMode(pinLed, OUTPUT);

}

void loop() {
  int temp =digitalRead(pinLDR);
  delay(300);
  if(temp==HIGH)
    digitalWrite(pinLed, 1);
  else
    digitalWrite(pinLed, 0);
}
