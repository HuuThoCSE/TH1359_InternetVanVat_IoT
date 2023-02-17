#include <HCSR04.h> // HCSR04 - gamegine
#include <LiquidCrystal.h>

#define pinMotor 8
#define pinBuzzor 9

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool statusRun = 0;
int KhCach = 0;
unsigned long curTime = 0, timeCheck = 0; 


HCSR04 hc(7, 6); // trig, echo

void setup() {
  lcd.begin(16, 2);
  pinMode(pinMotor, OUTPUT);
  pinMode(pinBuzzor, OUTPUT);
}

void loop() {
  curTime = millis();
  KhCach = hc.dist();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("KhCach: ");
  lcd.print(KhCach);
  delay(500);

  if(KhCach > 100){
    statusRun = 1;
    digitalWrite(pinMotor, statusRun);
  } else if(KhCach == 20){
    statusRun = 0;
    digitalWrite(pinMotor, statusRun);
  } 
  // if(KhCach != 20 && statusRun = 1 && curTime - timeCheck == 1000*60*15) { // Theo yêu cầu câu b, nếu máy bơm hoạt động quá 15 phút mà mực nước chưa cách cảm biến 20CM thì tắt máy bơm nước và bật còi báo động9
  //   tone(pinBuzzor, 2093, 1000);// frequency: tần số của sóng vuông (sóng âm), duration: thời gian phát nhạc, đơn vị là mili giây (tùy chọn)
  // }
  tone(pinBuzzor, 2093, 10000);
  delay(200000);
}
