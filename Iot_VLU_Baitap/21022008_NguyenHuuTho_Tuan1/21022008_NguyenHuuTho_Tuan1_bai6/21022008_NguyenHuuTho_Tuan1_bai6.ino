byte led = 3; // Biến khai báo chân đèn LED được nối vào Arduino
byte button = 2; // Biến khai báo chân của button

unsigned long waitTime = 500; // Bạn cần nhấn giữ 500 mili giây để hệ thống xem đó là một sự kiến nhấn giữ.

boolean ledStatus = 0; // tương tự với LOW - mặc định đèn sẽ tắt

boolean lastButtonStatus = 0; //Biến dùng để lưu trạng thái của phím bấm. Mặc định là 0 <=> LOW <=> chưa nhấn
boolean buttonLongPress = 0; // Mặc định là không có sự kiện nhấn giữ.

unsigned long lastChangedTime;

void setup() {
  pinMode(led,OUTPUT);   // Đặt chân LED là OUTPUT - hiển nhiên rồi
  pinMode(button,INPUT); // Đặt chân button là INPUT - hiển nhiên rồi
  
  digitalWrite(led,ledStatus); //Xuất trạng thái mặc định
  
  Serial.begin(9600); //Bật Serial để debug
  Serial.println("Bat dau");
}

void loop() {
  boolean reading = digitalRead(button); // đọc giá trị của button
  if (reading != lastButtonStatus) { // Nếu bạn đang nhấn button rồi thả ra giữa chừng hoặc đang thả button rồi nhấn lại 
                                     // thì ta cần phải cập nhập lại thời gian thay đổi cuối cùng
        
    lastButtonStatus = reading; //Cập nhập trạng thái cuối cùng.
    lastChangedTime = millis(); //Cập nhập thời gian
    
    Serial.print("Thay doi trang thai cua Button luc : ");
    Serial.print(lastChangedTime);
    Serial.print(". Bay gio trang thai la : ");
    Serial.println(lastButtonStatus);
  } // Còn nếu bạn đang nhấn giữ button hoặc thả nó thời gian dài chỉ sẽ không ảnh hưởng đến việc này
  
  if (millis() - lastChangedTime > waitTime) { // Nếu sự chênh lệch giữa thời điểm đang xét và thời điểm cuối cùng thay đổi trạng thái của button lớn hơn thời gian đợi để tạo sự kiện nhấn giữ THÌ nó là một sự kiến nhấn giữ
    buttonLongPress = reading; // Cập nhập trạng thái của button = với trạng thái của button
    lastChangedTime = millis();
    Serial.print("Xay ra su kien nhan giu: ");
    Serial.println(buttonLongPress);
    
  }
  
  if (buttonLongPress == true) { // Nếu có sự kiện nhấn giữ, ta thay đổi trạng thái của đèn LED
    ledStatus = !ledStatus; //Dấu ! là dấu phủ định, 0 thành 1, 1 thành 0, tắt thành sáng, sáng thành tắt
    buttonLongPress = false; // Kết thúc sự kiện nhấn giữ
  }
  digitalWrite(led,ledStatus); // Xuất giá trị của đèn LED ra đèn LED
}