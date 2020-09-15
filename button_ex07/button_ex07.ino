#include "Led.h"
#include "Button.h"
#include <SimpleTimer.h>

SimpleTimer timer;
Led led1(7);
Led led2(4);
Led led3(2);
Button btn1(11);
Button btn2(10);
Button btn3(9);

bool blinkPlay=false;
int blinkTimer=-1;

void led2OnOff(){
    led2.toggle();
}
void led3Blink(){
    led3.toggle();
}
void led3BlinkControl(){
    blinkPlay=!blinkPlay;
    if(!blinkPlay){
        led3.off();
    }
    timer.toggle(blinkTimer);
}
void setup()
{
    Serial.begin(9600);
    btn2.setCallback(led2OnOff);
    btn3.setCallback(led3BlinkControl);
    blinkTimer=timer.setInterval(500, led3Blink);
    timer.disable(blinkTimer);
//    btn.setCallback(work);
}
// void work(){
//     led.toggle();

// }

void loop()
{
    timer.run();
    led1.set(btn1.read());
    btn2.check();
    btn3.check();
}