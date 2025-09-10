#include "servo_arm.h"

void updateArm(int angleUpdate, int id){
    if (angleUpdate < 0 ) angleUpdate = 0;
    if (angleUpdate > 180) angleUpdate = 180;
    switch(id){
        case 1 : 
            angle1 = angleUpdate;
            servo1.write(angle1);
            break;
        case 2 : 
            angle2 = angleUpdate;
            servo2.write(angle2);
            break;
        case 3 : 
            angle3 = angleUpdate;
            servo3.write(angle3);
            break;
    }
}

void setDefaultArm(){
    updateArm(angle1, 1);
    delay(500);
    updateArm(angle2, 2);
    delay(500);
    updateArm(angle3, 3);
    delay(500);
}

void servoUp(int id){
    if(id==1) updateArm(angle1 + stepAngle, 1);
    if(id==2) updateArm(angle2 + stepAngle, 2);
    if(id==3) updateArm(angle3 + stepAngle, 3);
    Serial.println(String(angle1) + " - " + String(angle2) + " - " + String(angle3));
}

void servoDown(int id){
    if(id==1) updateArm(angle1 - stepAngle, 1);
    if(id==2) updateArm(angle2 - stepAngle, 2);
    if(id==3) updateArm(angle3 - stepAngle, 3);
    Serial.println(String(angle1) + " - " + String(angle2) + " - " + String(angle3));
}

void receiveCommandFromEsp32(char cmd){
    switch(cmd){
    case 'Q': servoUp(1); break;
    case 'A': servoDown(1); break;
    case 'W': servoUp(2); break;
    case 'S': servoDown(2); break;
    case 'E': servoUp(3); break;
    case 'D': servoDown(3); break;
    case 'K': setDefaultArm();break;
    default : break;
  }
}

void initServo(){
    servo1.attach(35);
    servo2.attach(36);  
    servo3.attach(37);
    setDefaultArm();
}
