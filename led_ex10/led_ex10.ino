#include<SimpleTimer.h>

int pin_LED1=13;
int pin_LED2=12;
int pin_LED3=8;
SimpleTimer timer;

void blink_1000(){
    int state=digitalRead(pin_LED1);
    digitalWrite(pin_LED1, !state);
}

void blink_500(){
    int state=digitalRead(pin_LED2);
    digitalWrite(pin_LED2, !state);
}

void blink_200(){
    int state=digitalRead(pin_LED3);
    digitalWrite(pin_LED3, !state);
}

void setup(){
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    pinMode(pin_LED3, OUTPUT);
    timer.setInterval(1000, blink_1000);
    timer.setInterval(500, blink_500);
    timer.setInterval(200, blink_200);
}
void loop(){
    timer.run();
}


// int pin_LED = 13;
// boolean LED_state = false;
// unsigned long time_previous, time_current;
// unsigned long count = 0;

// void setup()
// {
//     pinMode(pin_LED, OUTPUT);
//     digitalWrite(pin_LED, LED_state);
//     Serial.begin(9600);
//     time_previous = millis();
// }
// void loop()
// {
//     time_current = millis();
//     count++;
//     // 1초 이상 시간이 경과한 경우
//     if (time_current - time_previous >= 1000)
//     {
//         time_previous = time_current;
//         LED_state = !LED_state;
//         digitalWrite(pin_LED, LED_state);
//         Serial.println(count);
//         count = 0;
//     }
// }