#pragma once

#include <ESPAsyncTCP.h>
#include <Arduino.h>

class CustomClient{
    private:
        AsyncClient* client;
    public:
        CustomClient(AsyncClient* client);
        void sendMessage(String message);
};