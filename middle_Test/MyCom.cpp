#include "MyCom.h"

MyCom::MyCom() : lcd(0x27, 16, 2){  //A4:SDA, A5:SCL

}

void MyCom::init(){
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}

int MyCom::setInterval(unsigned long d, timer_callback f){
    return timer.setInterval(d, f);
}

void MyCom::run(){
    timer.run();
}

void MyCom::print(int col, int row, const char *pMsg){
    lcd.setCursor(col, row);
    char buf[17];
    sprintf(buf, "-16s", pMsg); //이전의 긴 문장 덮어쓰기
    lcd.print(pMsg); //buf
}

void MyCom::print(int row, const char *pMsg){
    print(0, row, pMsg);
}

void MyCom::print(int row, const char *pTitle1, const char *pTitle2, int value1, int value2){
    char buf[17];
    sprintf(buf, "%s: %3d %2s: %3d", pTitle1, value1, pTitle2, value2);
    print(0, row, buf);
}

void MyCom::print(int row, const char *pTitle, double value, int width){
    char buf[17];
    char temp[14];
    dtostrf(value, width, 2, temp);
    sprintf(buf, "%s: %s", pTitle, temp);
    print(0, row, buf);
}