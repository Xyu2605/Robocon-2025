#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <PubSubClient.h>
#include "servo_arm.h"
#include "robot.h"
#include "mqtt_control.h"
#include "config.h"
                                   

WiFiClient espClient;
PubSubClient client(espClient);

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("Connected");
      client.subscribe("robot/cmd");
    } else {
      Serial.print("Error, 2=");                                  
      Serial.print(client.state());
      Serial.println(" try again after 5s");
      delay(5000);
    }
  }
}

void setup(){

  Serial.begin(115200); 
  // WiFi connect
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wifi...");
  int retry = 0;
  while (WiFi.status() != WL_CONNECTED && retry < 20)
  {
    delay(500);
    Serial.print(".");
    retry++;
  }
  
  if (WiFi.status() != WL_CONNECTED){
    Serial.println("\nFailed to connect to WiFi, restarting...");
    ESP.restart();
  }
  
  Serial.print("\nWiFi connected, IP: ");
  Serial.print(WiFi.localIP());
  // MQTT config
  client.setServer(mqtt_server,1883);
  client.setCallback(mqttCallback);
  // Initializating robot
  initRobot();
  setDefaultArm();
  Serial.println("Robot is ready");
}


void loop(){
  // Try to connect to wifi if esp32 lost connection
  if(WiFi.status() != WL_CONNECTED){
    Serial.println("WiFi disconnected!");
    WiFi.reconnect();
    delay(5000);
  }
  
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  // Receive data from UART
  if (Serial1.available()){
    char cmd = Serial1.read();
    handleCommandWheel(cmd);
    receiveCommandFromEsp32(cmd);
  }
}



