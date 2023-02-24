// Hiện đèn biểu tượng LCD
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte tym[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B11111,
  B11111,
  B01110,
  B00100
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(1, tym);
}

void loop() {
  lcd.setCursor(0, 0);
  for (int i=0; i<=10; i++){
    lcd.write(1);
  }
}
