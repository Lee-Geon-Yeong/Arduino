#include<MiniCom.h>
#include <Ultra.h>
#include <Pulse.h>
#include <Led.h>
#include <Servo.h>

MiniCom com;
Ultra ultra(2,3);
Led led(8);
Servo servo;
Pulse pulse(100, 500);
int delayTimes[]={
    50, 100, 200, 300, 1000
};
void pulseCallback(int value){
    // LED제어
    led.set(value);    

}
void checkDistance(){
    int distance = ultra.read();
    com.print(0, "distance", distance);
    if(distance<10){
        
        int offDelay=map(distance, 0, 9, 0, 4);
        pulse.setDelay(10, delayTimes[offDelay]);
        servo.write(90);
        if(pulse.getState()){   //처음 10cm 이하로 됬을 때 
            pulse.play();
        }
    }else{
        if(pulse.getState()){
            pulse.stop();
        }
        servo.write(0);
    }
}

void setup()
{
    com.init();
    servo.attach(9);
    servo.write(0);
    pulse.setCallback(pulseCallback);
    com.setInterval(1000, checkDistance);
}
void loop()
{
    com.run();
    pulse.run();
}