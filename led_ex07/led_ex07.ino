int red_led = 13;
int yellow_led = 12;
int green_led = 8;
void setup()
{
    pinMode(red_led, OUTPUT);
    pinMode(yellow_led, OUTPUT);
    pinMode(green_led, OUTPUT);
}
void go(int duration = 0)
{
    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(green_led, HIGH);
    if (duration != 0)
    {
        delay(duration);
    }
}
void stop(int duration = 0)
{
    digitalWrite(red_led, HIGH);
    digitalWrite(yellow_led, LOW);
    digitalWrite(green_led, LOW);
    if (duration != 0)
    {
        delay(duration);
    }
}
void leftTurn(int duration = 0)
{
    digitalWrite(red_led, LOW);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(green_led, HIGH);
    if (duration != 0)
    {
        delay(duration);
    }
}
void leftTurnWarning(int duration = 0)
{
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
    
    int interval=duration/5;
    for(int i=0; i<5; i++){
        blink(yellow_led, interval);
    }
}
void blink(int pin, int duration){
    digitalWrite(pin, HIGH);
    delay(duration/2);
    digitalWrite(pin, LOW);
    delay(duration/2);
}
void loop()
{
    go(5000);
    leftTurn(2000);
    leftTurnWarning(2000);
    stop(2000);
}