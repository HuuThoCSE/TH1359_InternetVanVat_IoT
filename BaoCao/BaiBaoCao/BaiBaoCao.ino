// Import thư viện
#include <LiquidCrystal.h> // Khai báo thư viện LCD / Kết nối qua SPI (Được hỗ trợ sẵn)
#include <DHT.h> // Thư viện DHT11
#include <BlynkSimpleStream.h>

// Khởi tạo chân
LiquidCrystal lcd(9, 8, 5, 4, 3, 2); // Khởi tạo chân giao tiếp

#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(10, 11); // RX, TX

// Blynk
#define BLYNK_TEMPLATE_ID "TMPLp3s0eFuY"
#define BLYNK_DEVICE_NAME "HeThongVuonThongMinh"
#define BLYNK_AUTH_TOKEN "1-OlCZbBn0qtYwpZYQI0fnF3av7OvxKJ"
char auth[] = "1-OlCZbBn0qtYwpZYQI0fnF3av7OvxKJ";

const int ldrPin = A0;
const int DHTPIN = A1;  
const int pinSOIL = A2;    
const byte motorPin = 7;
const byte LAMpPin = 6;

const int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);

int lightAnalog = 0;
int valueDoAmDat = 0;
float giatriDoAm, t = 0;

void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2); // Khởi tạo LCD 16, 2
  dht.begin();

  pinMode(ldrPin, INPUT);
  pinMode(pinSOIL, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(LAMpPin, OUTPUT);

  DebugSerial.begin(9600);
  Blynk.begin(Serial, auth);
}

void DoNhietdoDoAm(){
  giatriDoAm = dht.readHumidity(); 
  // t = dht.readTemperature();
  t = random(30, 50);
  Blynk.virtualWrite(V1, t);
  DebugSerial.print("Nhiet do: ");
  DebugSerial.println(t);
}

void ChecklightAnalog(){
  // lightAnalog = analogRead(ldrPin); //lấy giá trị độ sáng từ 0 đến 1023
  // lightAnalog = map(lightAnalog, 0, 1023, 0, 100);
  lightAnalog = random(100);
  Blynk.virtualWrite(V0, lightAnalog);
  DebugSerial.print("Anh sang: ");
  DebugSerial.println(lightAnalog);
}

void DoDoAmDat(){
  // valueDoAmDat = analogRead(pinSOIL); //lấy giá trị độ sáng từ 0 đến 1023
  // valueDoAmDat = map(valueDoAmDat, 0, 1023, 0, 100);
  valueDoAmDat = random(100);
  Blynk.virtualWrite(V2, valueDoAmDat);
  DebugSerial.print("Do am dat: ");
  DebugSerial.println(valueDoAmDat);
}

void PrintLCD(){
  lcd.clear(); // Xóa dữ liệu LCD
  lcd.setCursor(0,0); // Đặt con trỏ ở vị trí cột 0, hàng 0
  lcd.print("T:");
  lcd.print(t);

  lcd.setCursor(8, 0);
  lcd.print("SOIL:");
  lcd.print(valueDoAmDat);

  lcd.setCursor(0, 1);
  lcd.print("DA:");
  lcd.print(giatriDoAm);
  lcd.print("%");

  lcd.setCursor(10, 1);
  lcd.print("AS:");
  lcd.print(lightAnalog);

}

void loop() {
  
  DoNhietdoDoAm();
  ChecklightAnalog();
  DoDoAmDat();
  PrintLCD();

  if(valueDoAmDat <= 70){
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  if(lightAnalog < 50){
    digitalWrite(LAMpPin, HIGH);
  } else {
    digitalWrite(LAMpPin, LOW);
  }

  Blynk.run();
  delay(200);
  DebugSerial.println();
}
