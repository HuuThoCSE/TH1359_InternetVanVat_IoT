// Import thư viện
#include <LiquidCrystal.h> // Khai báo thư viện LCD / Kết nối qua SPI (Được hỗ trợ sẵn)
#include <DHT.h> // Thư viện DHT11

// Khởi tạo chân
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Khởi tạo chân giao tiếp

const int ldrPin = A0;
const int DHTPIN = A1;      
const int motorPin = 7;
const int LAMpPin = 6;

const int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);

int lightAnalog = 0;
float giatriDoAm, t = 0;

void setup() {
  lcd.begin(16, 2); // Khợi tạo LCD 16, 2
  dht.begin();

  pinMode(ldrPin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(LAMpPin, OUTPUT);

  Serial.begin(9600);
}

void DoNhietdoDoAm(){
  giatriDoAm = dht.readHumidity(); 
  t = dht.readTemperature();
}

void ChecklightAnalog(){
  lightAnalog = analogRead(ldrPin); //lấy giá trị độ sáng từ 0 đến 1023
  Serial.println(lightAnalog);
}

void PrintLCD(){
  lcd.clear(); // Xóa dữ liệu LCD
  lcd.setCursor(0,0); // Đặt con trỏ ở vị trí cột 0, hàng 0
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(9, 0);
  lcd.print("AS:");
  lcd.print(lightAnalog);

  lcd.setCursor(0, 1);
  lcd.print("DA:");
  lcd.print(giatriDoAm);
  lcd.print("%");
}

void loop() {
  DoNhietdoDoAm();
  ChecklightAnalog();
  PrintLCD();

  if(giatriDoAm < 60 || giatriDoAm > 70){
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  if(lightAnalog < 341){
    digitalWrite(LAMpPin, HIGH);
  } else {
    digitalWrite(LAMpPin, LOW);
  }

  delay(200);
}
