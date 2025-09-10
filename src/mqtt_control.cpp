#include "mqtt_control.h"
#include "robot.h"
#include "servo_arm.h"


void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  message.trim(); 
  Serial.println("Receive command from MQTT: " + message);
  if(String(topic) == "robot/cmd"){
    if( message.length() > 0){
      handleCommandWheel(message[0]);
  }
  
}

