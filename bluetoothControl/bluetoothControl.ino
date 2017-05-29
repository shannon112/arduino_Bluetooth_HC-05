#include <SoftwareSerial.h>   // 引用程式庫

// 定義連接藍牙模組的序列埠
#define bRX 9
#define bTX 8
#define ledPin 12
SoftwareSerial BTSerial(bTX, bRX); // 接收腳, 傳送腳
char Sinput;  // 儲存接收資料的變數
char Binput='1';  // 儲存接收資料的變數


void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  BTSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
  /*
    if (Serial.available()) {
    Sinput = Serial.read();
    BTSerial.print(Sinput);
    }
  */

  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BTSerial.available()) {
    Binput = BTSerial.read();
    Serial.print("Binput= ");
    Serial.println(Binput);
    switch (Binput) {
      case '0':
        Serial.println("turn off");
        digitalWrite(ledPin, LOW);
        break;
      case '1':
        Serial.println("turn on");
        digitalWrite(ledPin, HIGH);
        break;
      default:
        Serial.println("WTF?");
        break;
    }
  }
}
