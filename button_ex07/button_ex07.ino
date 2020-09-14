#include "Led.h"
#include "Button.h"
Led led(4);
Button btn(11);
// int pin_button = 11;
// boolean state_previous = true;
// boolean state_current;


void setup()
{
    Serial.begin(9600);
//  pinMode(pin_button, INPUT_PULLUP);
//  pinMode(led, OUTPUT);
}
void work(){
    led.toggle();
//  int ledState=digitalRead(led);
//  digitalWrite(led, !ledState);
//  count++;
//  Serial.println(count);
}
void loop()
{
    led.set(btn.read()); // because it is pull up button, so do !
    
    // if (!state_current)
    // { // 누른 경우
    //     if (state_previous == true)
    //     {

    //         state_previous = false;
    //         work();
    //     }
    //     delay(5); // 추가
    // }
    // else
    // {
    //     state_previous = true;
    // }
}