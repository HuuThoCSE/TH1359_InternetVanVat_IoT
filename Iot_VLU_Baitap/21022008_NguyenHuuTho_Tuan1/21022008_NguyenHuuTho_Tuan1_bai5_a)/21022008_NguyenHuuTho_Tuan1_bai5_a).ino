byte ledPin[] = {2,3,4,5,6,7,8,9};
byte pinCount;
int i;
void setup() { 
  pinCount = sizeof(ledPin);
  for(i=0;i<pinCount;i++){
    pinMode(ledPin[i], OUTPUT);
    digitalWrite(ledPin[i], LOW);
  }
}

void loop() {
  for(i=0; i<pinCount; i++){
    digitalWrite(ledPin[i], HIGH);
  }
  delay(1000);

  for(i=0; i<pinCount; i++){
    digitalWrite(ledPin[i], LOW);
  }
  delay(1000);
}
