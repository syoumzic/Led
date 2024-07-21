#include "wireless/CustomServer.h"

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include "wireless/CustomClient.h"

#include "CLI/CLI.h"

#define PORT 10

void CustomServer::handleData(void* arg, AsyncClient* client, void *data, size_t len) {
    char* charData = static_cast<char*>(data);
	charData[len - 1] = '\0';

    String strData(charData);
	strData = strData.substring(0, strData.length() - 1);	//удалить последний символ новой строки

	if(!strData.isEmpty()){
		Server.mRecentClient.reset(new CustomClient(client));
    	CLI.parse(strData.c_str(), strData.length());
		Server.mRecentClient = nullptr;
	}
}

void CustomServer::handleDisconnect(void* arg, AsyncClient* client) {
    Server.mClients.erase(client);
	Serial.println("LOG: disconnect client");
}

void CustomServer::sendBroadcastMessage(String message){
	for(AsyncClient* pClient : Server.mClients){
		CustomClient customClient(pClient);
		customClient.sendMessage(message);
	}
}

void CustomServer::sendAnswer(String message){
	if(Server.mRecentClient != nullptr){
		Server.mRecentClient->sendMessage(message);
	}
	else{
		Serial.printf("LOG: message '%s' not received", message.c_str());
	}
}
void CustomServer::handleNewClient(void *arg, AsyncClient *client){
    client->onData(&handleData, NULL);
	client->onDisconnect(&handleDisconnect, NULL);

	CustomClient customClient(client);

	Server.mClients.insert(client);
	Serial.println("LOG: new client connected");
}

void CustomServer::setup() {
	AsyncServer* server = new AsyncServer(PORT); // start listening on tcp port 7050
	server->onClient(&handleNewClient, server);
	server->begin();
}

CustomServer Server;