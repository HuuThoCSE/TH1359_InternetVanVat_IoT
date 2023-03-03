#include "SPI.h"
#include "SoftwareSerial.h"

SoftwareSerial Debug(17, 16);

void setup() {
  Debug.begin(9600);
  pinMode(SS, OUTPUT);
  SPI.begin(); // Bật giao thức SPI
  SPI.setBitOrder(MSBFIRST); // Thiết lập thứ tự truyền bit lớn nhất trước
  SPI.setDataMode(SPI_MODE0); // Thiết lập chế độ truyền dữ liệu
  SPI.setClockDivider(SPI_CLOCK_DIV8); // Thiết lập tốc độ truyền dữ liệu
}

void loop() {
  byte data = 0x55; // Dữ liệu muốn gửi
  digitalWrite(SS, LOW); // Kích hoạt chân SS để gửi dữ liệu
  SPI.transfer(data); // Gửi dữ liệu qua giao thức SPI
  digitalWrite(SS, HIGH); // Tắt chân SS khi hoàn thành việc gửi
}
