// Link: http://arduino.vn/bai-viet/113-dieu-khien-8-den-led-sang-nhap-nhay-theo-y-muon-cua-ban-de-hay-kho
byte ledPin[] = {2,3,4,5,6,7,8,9};
byte pinCount;

void setup() {
  pinCount = sizeof(ledPin);
  for (int i=0;i<pinCount;i++) {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
  }
}

void loop() {
  /*
    Bật tuần tự các đèn LED
  */
  for (int i=0; i < pinCount; i++) {
    digitalWrite(ledPin[i],HIGH); //Bật đèn
    delay(100); // Dừng để các đèn LED sáng dần
  }
  
  /*
    Tắt tuần tự các đèn LED
  */
  for (int i = 0;i < pinCount; i += 1) {
    digitalWrite(ledPin[i],LOW); // Tắt đèn
    delay(100); // Dừng để các đèn LED tắt dần
  }
}
