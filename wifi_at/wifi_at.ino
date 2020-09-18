#include <SoftwareSerial.h> 
#define BT_RXD 2 
#define BT_TXD 3 
SoftwareSerial softSerial(BT_RXD, BT_TXD); 
void setup() { 
  Serial.begin(9600); 
// 펌웨어로 설정된 디폴트 속도는 115200 bps
  softSerial.begin(9600); // 펌웨어 설정에 따라 조정
  softSerial.setTimeout(5000); 
  delay(1000); 
} 
void loop() { 
  if (Serial.available()){
    softSerial.write(Serial.read()); 
  } 
  if (softSerial.available()) { 
    Serial.write(softSerial.read()); 
  }
}

//AT+UART_DEF=9600,8,1,0,0
//AT+CWMODE=1
//AT+CWJAP="TP-Link_1450","01039964667"
