#include "wireless/CustomClient.h"

CustomClient::CustomClient(AsyncClient* client) : client(client) {}

void CustomClient::sendMessage(String message){
	String modifiedMessage = message + "\n";
	client->add(modifiedMessage.c_str(), modifiedMessage.length());
	client->send();
}