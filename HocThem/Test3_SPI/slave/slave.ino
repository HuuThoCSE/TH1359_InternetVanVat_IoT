#include "SPI.h"
#include "SoftwareSerial.h"
SoftwareSerial DebugSerial(17, 16);

void setup() {
  DebugSerial.begin(9600); // Bật kết nối Serial
  SPI.begin(); // Bật giao thức SPI
  SPI.setBitOrder(MSBFIRST); // Thiết lập thứ tự truyền bit lớn nhất trước
  SPI.setDataMode(SPI_MODE0); // Thiết lập chế độ truyền dữ liệu
  SPI.setClockDivider(SPI_CLOCK_DIV8); // Thiết lập tốc độ truyền dữ liệu
  pinMode(MISO, OUTPUT); // Chuyển chân MISO thành đầu ra để có thể nhận dữ liệu
}

void loop() {
  digitalWrite(SS, LOW); // Kích hoạt chân SS để nhận dữ liệu
  byte data = SPI.transfer(0x00); // Nhận dữ liệu qua giao thức SPI
  digitalWrite(SS, HIGH); // Tắt chân SS khi hoàn thành việc nhận
  DebugSerial.print("Data received: ");
  DebugSerial.println(data); // In ra dữ liệu đã nhận
}