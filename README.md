# TH1359_InternetVanVat_IoT
## Phần mềm TH
[Nhấn vào đây.](https://1drv.ms/u/s!ApRDEniQwnjolddPQiCrfwgT6lndpQ?e=ZsIhYu)

## Tài liệu tự soạn
[Nhấn vào đây.](https://www.notion.so/huutho-vlu210222008/TH1359_InternetVanVat_IoT-bc284d5c202a4ef58fbb3b00856049fd)

# Quy ước một số tên linh kiện trên Protues

|STT    |TÊN THỰC TẾ    |PROTUES    |
|---    |---            |---        |
|1|Điện trở|res|
|2|Nút nhấn|button|

# Kiến thức cơ bản
## Khai báo hằng
const <Kiểu dữ liệu> <Tên biến> = <Giá trị>;

1000 mili giây = 1 giây -  Dùng trong hàm **delay()**.

# Code cơ bản 
Khai báo chân. Ví dụ: 
```C++
int led = 13;
```

Trong hàm setup()
```C++
pinMode(led, OUTPUT);    
```

Trong hàm loop()
```
digitalWrite(led, HIGH/LOW);
delay
```
Có thể đổi HIGH/LOW thành 1/0

# Thông tin các linh kiện

## LED
Tên trong proteus: **led-** <br>
Chân 6: Thay đổi sáng/tối <br>
Chân 13: Tắt/mở