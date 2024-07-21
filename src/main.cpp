#include <Arduino.h>

#include "wireless/CustomOTA.h"
#include "wireless/CustomServer.h"
#include "wireless/CustomWiFi.h"

#include "EffectManager.h"
#include <CLI/CLI.h>

#include "Led/CustomLed.h"

#define NETWORK_NAME "your name"
#define NETWORK_PASSWORD "your pass"

void setup(){
    Lamp.setup();
    Serial.begin(115200);
    Wifi.setup(NETWORK_NAME, NETWORK_PASSWORD);
    Ota.setup();
    Server.setup();
    CLI.setup();
}

void loop(){
    Ota.handle();
    effectManager.update();
}