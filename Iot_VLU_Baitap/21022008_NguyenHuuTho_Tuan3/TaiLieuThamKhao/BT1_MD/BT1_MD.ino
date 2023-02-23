//Khai báo chân tín hiệu motor A
int enA = 7;
int in1 = 6;
int in2 = 5;

//Khai báo chân tín hiệu cho motor B
int in3 = 4;
int in4 = 3;
int enB = 2;

int i;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void chaymotorA()
{
  for (i = 0; i <= 255; i++) {

    digitalWrite(in3, HIGH);
    digitalWrite(in1, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, i);
    analogWrite(enA, i);
    delay(100);

  }// Tăng tốc động cơ từ Min >> Max
  for (i = 255; i >= 0; i--) {
    digitalWrite(in3, HIGH);
    digitalWrite(in1, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enB, i);
    analogWrite(enA, i);
    delay(100);

  }// Giảm tốc từ Max >> Min

}

void loop()
{
  chaymotorA();
  delay(1000);
}
