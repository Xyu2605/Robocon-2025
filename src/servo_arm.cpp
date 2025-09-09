#include "servo_arm.h"

Servo servo1;
Servo servo2;
Servo servo3;

void setInitServo(){
    servo1.attach(35);
    servo2.attach(36);
    servo3.attach(37);
}
