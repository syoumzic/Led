#pragma once

#include <ESPAsyncTCP.h>
#include "wireless/CustomClient.h"
#include <Arduino.h>

#include <set>

class CustomServer{
    private:
        std::set<AsyncClient*> mClients;
        std::unique_ptr<CustomClient> mRecentClient;
    public:
        void setup();
        void sendBroadcastMessage(String message);
        void sendAnswer(String message);
    private:
        static void handleNewClient(void* arg, AsyncClient* client);
        static void handleData(void* arg, AsyncClient* client, void *data, size_t len);
        static void handleDisconnect(void* arg, AsyncClient* client);
};

extern CustomServer Server;