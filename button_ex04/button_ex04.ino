#include<SimpleTimer.h>
int pin_LED1 = 4;
int pin_LED2 = 3;
int pin_button = 11;
boolean LED_state = false;

void blink(){
    LED_state=!LED_state;
    digitalWrite(pin_LED1, LED_state);
}

void setup()
{
    pinMode(pin_LED1, OUTPUT);
    digitalWrite(pin_LED1, LED_state);
    pinMode(pin_LED2, OUTPUT);
    digitalWrite(pin_LED2, false);
    
    pinMode(pin_button, INPUT_PULLUP);
    timer.setInterval(1000, blink);
}
void loop()
{
    timer.run();  
    digitalWrite(pin_LED2, !digitalRead(pin_button));
}