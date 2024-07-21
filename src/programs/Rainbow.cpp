#include "programs/Rainbow.h"

#include "CLI/CLI.h"
#include "CLI/TypeParser.h"

#include "wireless/CustomServer.h"
#include <EffectManager.h>
#include "effects/Rainbow.h"

#define SPEED "-speed" //--speed
#define SATURATION "-saturation" //--saturation
#define VALUE "-value" //--value

void Programs::Rainbow::setup(){
    Command command = CLI.addCommand("rainbow", typeCheck);
    command.addArgument(SPEED, "100");
    command.addArgument(SATURATION, "100");
    command.addArgument(VALUE, "100");
}

void Programs::Rainbow::typeCheck(cmd *cmd){
    Command command(cmd);

    int speed = typeParser.toInt(command.getArgument(SPEED), 0, 1000);
    int saturation = typeParser.toInt(command.getArgument(SATURATION), 0, 255);
    int value = typeParser.toInt(command.getArgument(VALUE), 0, 255);

    typeParser.setCallback([speed, saturation, value]{
        effectManager.set(new Effects::Rainbow(speed, saturation, value));
        Server.sendAnswer("rainbow success set");
    });
}