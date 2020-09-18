#include<MiniCom.h>
#include <Ultra.h>
#include<Led.h>
#include <Servo.h>
MiniCom com;
Ultra ultra(2,3);
Led led(8);
Servo servo;
void checkDistance(){
    int distance = ultra.read();
    com.print(0, "distance", distance);
    if(distance<10){
        led.on();
        servo.write(90);
    }else{
        led.off();
        servo.write(0);
    }
}

void setup()
{
    com.init();
    servo.attach(9);
    servo.write(0);
    com.setInterval(1000, checkDistance);
}
void loop()
{
    com.run();
}

//10cm 이하 거리 되면 불 켜지고, 부저 울리고, 서보모터 90도 돌아감