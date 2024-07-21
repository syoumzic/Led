#include "programs/Off.h"

#include "Led/CustomLed.h"
#include "Led/Color.h"

#include "CLI/CLI.h"
#include "wireless/CustomServer.h"
#include <EffectManager.h>

void Programs::Off::setup(){
    Command command = CLI.addCommand("off", execute); 
}

void Programs::Off::execute(cmd *cmd){
    effectManager.reset();
    Lamp.fill(rawColor(Led::Color{0, 0, 0}));
    Server.sendAnswer("success off");
}
