#define pinLDR A0
#define pinLed 8
void setup() {
  pinMode(pinLDR, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, 0);
  Serial.begin(9600);
}

void loop() {
  // digitalWrite(pinLed, !digitalRead(pinLDR)); # analog 0-1023: 0-200 bật đèn, lớn hơn 200 tắt đèn
  float value = analogRead(pinLDR);
  Serial.println(value);
  if(value <= 200){
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }
}
