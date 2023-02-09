#include <BlynkSimpleStream.h> // Blynk
#include <DHT.h> // Thư viện DHT11
BlynkTimer timer;

#define pinLight 4
#define DHTPIN A0
#define pinSOIL A1

#include <SoftwareSerial.h>
SoftwareSerial DebugSerial(2, 3); // RX, TX

#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define BLYNK_PRINT DebugSerial
#define BLYNK_TEMPLATE_ID "TMPLSWy0uUgW"
#define BLYNK_DEVICE_NAME "CayTrai"
#define BLYNK_AUTH_TOKEN "Tts2WJWwPD_a1c0OejzikcYrdszZwrKk"
char auth[] = "Tts2WJWwPD_a1c0OejzikcYrdszZwrKk";

byte statusLight;
float valueDoAm, valueNhietDo = 0;
int statusSOIL = 0;

void setup() {
  pinMode(DHTPIN, INPUT);
  pinMode(pinSOIL, INPUT);
  pinMode(pinLight, INPUT);

  dht.begin();

  DebugSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
}
BLYNK_CONNECTED() {
    // Send requests for different internal data
    // Request what is actually needed for your use-case
    Blynk.sendInternal("utc", "Asia/Ho_Chi_Minh");   // Name of timezone
    Blynk.sendInternal("utc", "iso");       // ISO-8601 formatted time
    Blynk.sendInternal("utc", "time");      // Unix timestamp (with msecs)
    Blynk.sendInternal("utc", "tz");        // Timezone and DST offsets
    Blynk.sendInternal("utc", "tz_rule");   // POSIX TZ rule
    Blynk.sendInternal("utc", "dst_next");  // Up to 2 next time offset changes (due to DST)
}

BLYNK_CONNECTED() {
    // Send requests for different internal data
    // Request what is actually needed for your use-case
    Blynk.sendInternal("utc", "tz_name");   // Name of timezone
    Blynk.sendInternal("utc", "iso");       // ISO-8601 formatted time
    Blynk.sendInternal("utc", "time");      // Unix timestamp (with msecs)
    Blynk.sendInternal("utc", "tz");        // Timezone and DST offsets
    Blynk.sendInternal("utc", "tz_rule");   // POSIX TZ rule
    Blynk.sendInternal("utc", "dst_next");  // Up to 2 next time offset changes (due to DST)
}

// Receive UTC data
BLYNK_WRITE(InternalPinUTC) {
    String cmd = param[0].asStr();
    if (cmd == "time") {
        uint64_t utc_time = param[1].asLongLong();
        Serial.print("Unix time (UTC): "); Serial.println(utc_time);
        
    } else if (cmd == "iso") {
        String iso_time = param[1].asStr();
        Serial.print("ISO-8601 time:   "); Serial.println(iso_time);
        
    } else if (cmd == "tz") {
        long tz_offset = param[1].asInt();
        long dst_offset = param[2].asInt();
        Serial.print("TZ offset:       "); Serial.print(tz_offset);  Serial.println(" minutes");
        Serial.print("DST offset:      "); Serial.print(dst_offset); Serial.println(" minutes");
    
    } else if (cmd == "tz_name") {
        String tz_name = param[1].asStr();
        Serial.print("Timezone:        "); Serial.println(tz_name);
    
    } else if (cmd == "tz_rule") {
        String tz_rule = param[1].asStr(); 
        Serial.print("POSIX TZ rule:   "); Serial.println(tz_rule);
   
    } else if (cmd == "dst_next") {
        uint32_t next1_ts  = param[1].asLong();
        int next1_off       = param[2].asInt();

        uint32_t next2_ts  = param[3].asLong();
        int next2_off       = param[4].asInt();
        
        Serial.print("Next offset changes: ");
        Serial.print(next1_off); Serial.print("min. on "); Serial.print(next1_ts);
        Serial.print(", ");
        Serial.print(next2_off); Serial.print("min. on "); Serial.print(next2_ts);
        Serial.println();
    }
}

uint64_t ts = (uint64_t)UTC.now() * 1000 + UTC.ms(LAST_READ);
Blynk.beginGroup(ts);
  Blynk.virtualWrite(V0, valueNhietDo); // Blynk - Nhiệt độ
  Blynk.virtualWrite(V1, valueDoAm); // Blynk - Đ.A Không khí
  Blynk.virtualWrite(V2, statusSOIL); // Blynk - Đ.A Đất
  Blynk.virtualWrite(V3, statusLight); // ANH SANG
Blynk.endGroup();

void loop() {
  Blynk.run();
  statusSOIL = analogRead(pinSOIL); // CHECK - Độ ẩm đất
  statusLight = digitalRead(pinLight); // CHECK - AS

  valueDoAm = dht.readHumidity(); // CHECK - Độ ẩm không khí
  valueNhietDo = dht.readTemperature(); // CHECK - Nhiệt độ

  DebugSerial.println("Nhiet do: ");
  DebugSerial.println(valueNhietDo);
  DebugSerial.println("Do am KK: ");
  DebugSerial.println(valueDoAm);
  DebugSerial.println("Do am DAT: ");
  DebugSerial.println(statusSOIL);
  DebugSerial.println("Sang/Toi: ");
  DebugSerial.println(statusLight);
  timer.run();
}
