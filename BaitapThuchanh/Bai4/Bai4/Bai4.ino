int ledDo = 13;
int ledVang = 12;
int ledXanh = 8;

void setup() {
  pinMode(ledDo, OUTPUT);
  pinMode(ledVang, OUTPUT);
  pinMode(ledXanh, OUTPUT);
}
void loop() {
  digitalWrite(ledDo, 1);
  digitalWrite(ledVang, 0);
  digitalWrite(ledXanh, 0);
  delay(15000);

  digitalWrite(ledDo, 0);
  digitalWrite(ledVang, 1);
  digitalWrite(ledXanh, 0);
  delay(3000);

  digitalWrite(ledDo, 0);
  digitalWrite(ledVang, 0);
  digitalWrite(ledXanh, 1);
  delay(15000);
}
