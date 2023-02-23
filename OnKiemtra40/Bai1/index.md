Đề kiểm tra Arduino với Proteus, sử dụng đèn LED, DHT11, LCD và RTC như sau:

#### **Yêu cầu:** 
Thiết kế một hệ thống đo nhiệt độ và độ ẩm sử dụng Arduino, hiển thị kết quả trên màn hình LCD và điều khiển một đèn LED dựa trên giá trị nhiệt độ. Hệ thống cũng phải sử dụng một RTC để hiển thị thời gian và ngày tháng.

#### **Thiết bị**:

- Arduino UNO R3
- Mạch mô phỏng Proteus
- DHT11 Sensor
- Màn hình LCD 16x2
- Đèn LED
- Module RTC DS1307

#### **Yêu cầu kỹ thuật**:
- Hiển thị giá trị nhiệt độ và độ ẩm lên màn hình LCD. - Xong
- Điều khiển đèn LED dựa trên giá trị nhiệt độ: nếu giá trị nhiệt độ lớn hơn 30 độ C, đèn LED sẽ sáng; nếu giá trị nhiệt độ nhỏ hơn hoặc bằng 30 độ C, đèn LED sẽ tắt. - Xong
- Hiển thị thời gian và ngày tháng trên màn hình LCD. - Xong

#### **Hướng dẫn**:
- Kết nối DHT11 Sensor với Arduino theo sơ đồ.
- Kết nối màn hình LCD với Arduino theo sơ đồ.
- Kết nối đèn LED với Arduino theo sơ đồ.
- Kết nối module RTC DS1307 với Arduino theo sơ đồ.
- Viết code để đọc giá trị nhiệt độ và độ ẩm từ DHT11 Sensor và hiển thị chúng lên màn hình LCD.
- Viết code để điều khiển đèn LED dựa trên giá trị nhiệt độ.
- Viết code để đọc thời gian và ngày tháng từ module RTC DS1307 và hiển thị chúng lên màn hình LCD.

#### **Hướng dẫn bổ sung**:
Để đọc giá trị nhiệt độ và độ ẩm từ DHT11 Sensor, bạn có thể sử dụng thư viện DHT.h.
Để điều khiển đèn LED, bạn có thể sử dụng chân Digital Output của Arduino và ghi giá trị HIGH hoặc LOW cho chân đó để bật hoặc tắt đèn LED.
Để đọc thời gian và ngày tháng từ module RTC DS1307, bạn có thể sử dụng thư viện RTClib.h.