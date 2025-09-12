#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include "servo_arm.h"
#include "robot.h"
#include "config.h"


void setup(){

  Serial.begin(115200); 
  Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1);
  // Initializating robot
  initRobot();
  initServo();
  Serial.println("Robot is ready");
}

void loop(){
  // Receive data from UART
  if (Serial1.available()){
    char cmd = Serial1.read();
    handleCommandMotor(cmd);
    handleCommandServo(cmd);
  }
}