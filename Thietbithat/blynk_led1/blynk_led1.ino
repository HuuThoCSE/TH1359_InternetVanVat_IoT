#define led 9
void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, 1);
  delay(5000);
  digitalWrite(led, 0);
  delay(5000);
}
