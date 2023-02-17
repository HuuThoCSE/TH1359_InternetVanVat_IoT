#include <RTClib.h>

// RTC
RTC_DS1307 rtc; // Khai báo biến
char daysOfTheWeek[7][12]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  if (!rtc.begin()){
   Serial.println("Couldn't find RTC");
  //  while(1);
  }

  if (!rtc.isrunning()){
   Serial.println("RTC is NOT running!");
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
}

void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now();
  // LAY THOI GIAN TU RTC
  now=rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print(" ");
  Serial.print(now.month(), DEC);
  Serial.print(" ");
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(" ");
  Serial.print(now.minute(), DEC);
  Serial.print(" ");
  Serial.println(now.second(), DEC);
}
