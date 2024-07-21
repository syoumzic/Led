#pragma once

#include <Arduino.h>

class CustomWiFi {
    public: 
        void setup(String ssid, String pass);
        void printIpAddress();
};

extern CustomWiFi Wifi;