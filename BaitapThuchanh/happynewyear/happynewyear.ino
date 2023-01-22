// Kết nối qua SPI (Được hỗ trợ sẵn)
#include <LiquidCrystal.h> // Khai báo thư viện LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Khởi tạo chân giao tiếp

void setup() {
  lcd.begin(16, 2); // Khợi tạo LCD 16, 2
}

void loop() {
  int i=15;
  //lcd.setCursor(0,0); // Đặt con trở ở vị trí cột 0
  while(i>=-22){
    lcd.setCursor(i, 0);
    lcd.print("HAPPY NEW YEAR 2023!!!                 ");
    delay(30);
    i--;
  }
}
