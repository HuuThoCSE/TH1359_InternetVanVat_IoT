#define pinBtn 2
#define pinLed 13
unsigned long currentMillis, previousMillis = 0;
void setup() {
  Serial.begin(9600);
  pinMode(pinBtn, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(pinLed, 0); // Tắt trước khi chạy lần đầu
}

void loop() {
  // boolean reading = digitalRead(pinBtn);
  // currentMillis = millis();   // Lấy thời gian hiện tại
  // buttonState = digitalRead(pinBtn);   // Đọc trạng thái của nút nhấn
  // Serial.println(buttonState);
  // if (buttonState == HIGH) {   // Nếu nút đang nhấn
  //   if (currentMillis - previousMillis >= 500) {   // So sánh thời gian hiện tại với thời gian trước đó
  //     digitalWrite(pinLed, HIGH);
  //     previousMillis = currentMillis;   // Cập nhật lại thời gian trước đó
  //     timeLed = currentMillis;
  //   }
  // }
  // else {
  //   if(currentMillis - timeLed >= 5000){
  //       digitalWrite(pinLed, HIGH);   // Bật LED
  //       timeLed = currentMillis;
  //   } else {
  //     digitalWrite(pinLed, LOW);   // Tắt LED
  //     previousMillis = 0;   // Reset thời gian trước đó
  //   }
  // }

  currentMillis = millis();
  if(digitalRead(pinBtn)){
    do {
      previousMillis= currentMillis;
    } while(digitalRead(pinBtn) && millis() - previousMillis <= 5000);
    digitalWrite(pinLed, HIGH);
    previousMillis = millis();
  }
  if(currentMillis-previousMillis>=5000 && digitalRead(pinBtn)){
    digitalWrite(pinLed, LOW);
    previousMillis = millis();
  }
}
