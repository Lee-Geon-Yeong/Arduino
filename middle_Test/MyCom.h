#pragma once

#include<Arduino.h>
#include<LiquidCrystal_I2C.h>
#include<SimpleTimer.h>

class MyCom{
protected:
    LiquidCrystal_I2C lcd;
    SimpleTimer timer;

public:
    MyCom();      //생성자
    void init();    //초기화코드
    int setInterval(unsigned long d, timer_callback f);   //타이머 콜백 등록
    void run();     //타이머 운영 및 기타 처리

    void print(int col, int row, const char *pMsg);
    void print(int row, const char *pMsg);
    void print(int row, const char *pTitle1, const char *pTitle2, int value1, int value2);
    void print(int row, const char *pTitle, double value, int width=6);

};