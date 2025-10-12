#pragma once
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi and MQTT config
const char* ssid = "EVBADM";
const char* password = "00000000";
const char* mqttServer = "172.20.10.2";
const int mqttPort = 1883;

extern WiFiClient espClient;
extern PubSubClient client;
