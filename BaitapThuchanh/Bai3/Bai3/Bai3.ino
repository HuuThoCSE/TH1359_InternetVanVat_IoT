int led = 13;

// hằng số chỉ khoảng thời gian nháy đèn:
const long TgBlink = 5000; 

// Nên dùng biến "unsigned long" cho các biến lưu giữ thời gian
unsigned long TgTruoc = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}
int ledState;
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long TgHienTai = millis();

  if(TgHienTai - TgTruoc >= TgBlink){
    TgTruoc = TgHienTai;
    if (ledState == 0) {
      ledState = 1;
    } else {
      ledState = 0;
    };

    digitalWrite(led, ledState);
  }
}
