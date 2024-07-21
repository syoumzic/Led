#include "wireless/CustomWiFi.h"
#include <ESP8266WiFi.h>

void CustomWiFi::setup(String ssid, String pass){
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED){
        delay(500);
    }
}

void CustomWiFi::printIpAddress(){
    Serial.println();
    Serial.println("Ip address: " + WiFi.localIP().toString());
}

CustomWiFi Wifi;