#ifndef ROBOT_H
#define ROBOT_H

const int freg = 1000;
const int resolution = 8;

#define ENA1 12 // trước trái
#define IN1_1 13
#define IN2_1 14

#define ENB1 9 // trước phải
#define IN3_1 10
#define IN4_1 11

#define ENA2  8 // sau trái
#define IN1_2  3
#define IN2_2 46 

#define ENB2 16 // sau phải
#define IN3_2 17
#define IN4_2 18 

void initRobot(){
}

void mecanumWheel(int v1, int v2, int v3, int v4){}

void moveForward(int speed=200){}
void moveBackward(int speed=200){}
void turnRight(int speed=200){}
void turnLeft(int speed=200){}
void rorateRight(int speed=200){}
void rorateLeft(int speed=200){}
void stop(){}

#endif