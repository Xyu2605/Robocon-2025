#include "servo_arm.h"

int angle1 = 0;  
int angle2 = 80;
int angle3 = 145;  
int stepAngle = 5; 
Servo servo1;
Servo servo2;
Servo servo3;


void smoothMove(Servo *servo, int *currentAngle, int target) {
    target = constrain(target, 0, 180);
    int start = *currentAngle;
    int diff = abs(target - start);
    if (diff == 0) return;

    for (int i = 0; i <= diff; i++) {
        float t = (float)i / diff;
        float ease = 3 * t * t - 2 * t * t * t;
        int next = start + (target - start) * ease;
        servo->write(next);
        delay(15);
    }

    *currentAngle = target;
}

void updateArm(int angleUpdate, int id) {
    angleUpdate = constrain(angleUpdate, 0, 180);

    switch (id) {
        case 1: smoothMove(&servo1, &angle1, angleUpdate); break;
        case 2: smoothMove(&servo2, &angle2, angleUpdate); break;
        case 3: smoothMove(&servo3, &angle3, angleUpdate); break;
        default: return;
    }
}

void autoUpdateArm(int id, int target) {
    switch (id) {
        case 1: smoothMove(&servo1, &angle1, target); break;
        case 2: smoothMove(&servo2, &angle2, target); break;
        case 3: smoothMove(&servo3, &angle3, target); break;
        default: return;
    }
}

void takeTheBall() {
    autoUpdateArm(1, 60);   
    delay(200);
    autoUpdateArm(2, 100);  
    delay(200);
    autoUpdateArm(3, 120);  
    delay(300);
    autoUpdateArm(2, 85);   
    delay(200);
    autoUpdateArm(1, 90);   
}

void throwTheBall() {
    autoUpdateArm(1, 130); 
    autoUpdateArm(2, 60);  
    delay(200);
    autoUpdateArm(3, 180);  
    delay(200);
    autoUpdateArm(1, 90); 
    autoUpdateArm(2, 110);
    autoUpdateArm(3, 145);
}

void setDefaultArm() {
    autoUpdateArm(1, angle1);
    delay(300);
    autoUpdateArm(2, angle2);
    delay(300);
    autoUpdateArm(3, angle3);
    delay(300);
}

void servoUp(int id) {
    switch (id) {
        case 1: updateArm(angle1 + stepAngle, 1); break;
        case 2: updateArm(angle2 + stepAngle, 2); break;
        case 3: updateArm(angle3 + stepAngle, 3); break;
        default: return;
    }
    Serial.println(String("Up: ") + angle1 + " - " + angle2 + " - " + angle3);
}

void servoDown(int id) {
    switch (id) {
        case 1: updateArm(angle1 - stepAngle, 1); break;
        case 2: updateArm(angle2 - stepAngle, 2); break;
        case 3: updateArm(angle3 - stepAngle, 3); break;
        default: return;
    }
    Serial.println(String("Down: ") + angle1 + " - " + angle2 + " - " + angle3);
}

void handleCommandServo(char cmd) {
    switch(cmd){
        case 'Q': servoUp(1); break;
        case 'A': servoDown(1); break;
        case 'W': servoUp(2); break;
        case 'X': servoDown(2); break;
        case 'E': servoUp(3); break;
        case 'D': servoDown(3); break;
        case 'Z': takeTheBall(); break;
        case 'N': throwTheBall(); break;
        default : break;
    }
}

void initServo() {
    servo1.attach(14);
    delay(500);
    servo2.attach(13);
    delay(500);
    servo3.attach(15);
    delay(1000);
    setDefaultArm();
}
