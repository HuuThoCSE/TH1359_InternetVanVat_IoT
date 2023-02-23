#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#define echoPin 6 
#define trigPin 7

long duration; 
int distance; 
const int motor = 13;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motor,OUTPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); 
  Serial.println("with Arduino UNO R3");
  lcd.init();
  lcd.backlight();
}
//Đọc giá trị khoảng cách hiển thị lên màn hình LCD
void hienthi(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 

  Serial.print("Khoang cach: ");
  Serial.print(distance);
  Serial.println(" cm");

//    lcd.clear();
    lcd.setCursor(0,0);
    lcd.println("Khoang cach:");
    lcd.print(distance);
    lcd.print("cm");
    delay(1000);
}
//Khi khoảng cách từ cảm biến đến mực nước trên 100CM thì điều khiển máy bơm nước cho đến khi mực nước cách cảm biến 20CM
void mucnuoc(){
  if(distance>=100)
  {
    digitalWrite(motor,HIGH);
  }
  if(distance<=20)
  {
    digitalWrite(motor,LOW);
  }
}
void loop() {
 hienthi(); //Đọc giá trị khoảng cách hiển thị lên màn hình LCD
 mucnuoc(); //Khi khoảng cách từ cảm biến đến mực nước trên 100CM thì điều khiển máy bơm nước cho đến khi mực nước cách cảm biến 20CM
}
