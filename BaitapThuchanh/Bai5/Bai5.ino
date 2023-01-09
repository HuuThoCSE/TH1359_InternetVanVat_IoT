int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
}

void loop() {
  digitalWrite(led1, 1);
  delay(60);
  digitalWrite(led2, 1);
  delay(60);
  digitalWrite(led3, 1);
  delay(60);
  digitalWrite(led4, 1);
  delay(60);
  digitalWrite(led5, 1);
  delay(60);
  digitalWrite(led6, 1);
  delay(60);
  digitalWrite(led7, 1);
  delay(60);
  digitalWrite(led8, 1);
  delay(60);
  // 
  digitalWrite(led1, 0);
  delay(60);
  digitalWrite(led2, 0);
  delay(60);
  digitalWrite(led3, 0);
  delay(60);
  digitalWrite(led4, 0);
  delay(60);
  digitalWrite(led5, 0);
  delay(60);
  digitalWrite(led6, 0);
  delay(60);
  digitalWrite(led7, 0);
  delay(60);
  digitalWrite(led8, 0);
  delay(60);
}
