#include <Arduino.h>
#include "wifi_mqtt.h"
#include "servo_arm.h"
#include "robot.h"


void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  message.trim(); 
  Serial.println("Receive command from MQTT: " + message);

  if (message == "F") moveForward();
  else if (message == "B") moveBackward();
  else if (message == "L") turnLeft();
  else if (message == "R") turnRight();
  else if (message == "G") rorateRight();
  else if (message == "H") rorateLeft();
}
