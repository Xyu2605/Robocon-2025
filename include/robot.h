#pragma once

// trước trái
#define ENA1 16
#define IN1_1 17
#define IN2_1 13                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
// trước phải
#define ENB1 10
#define IN3_1 9
#define IN4_1 46
// sau trái
#define ENA2  39
#define IN1_2  38
#define IN2_2 40
// sau phải       
#define ENB2 37
#define IN3_2 36
#define IN4_2 35 

#define PWM_CHANNEL_0 0
#define PWM_CHANNEL_1 1
#define PWM_CHANNEL_2 2
#define PWM_CHANNEL_3 3

const int freq = 1000;     
const int resolution = 8;  
const int MOTOR_SPEED = 100; 

void initRobot();
void motorSpin(int v1, int v2, int v3, int v4);
void moveForward(int speed);
void moveBackward(int speed);
void turnRight(int speed);
void turnLeft(int speed);
void rotateRight(int speed);
void rotateLeft(int speed);
void handleCommandMotor(char cmd);
