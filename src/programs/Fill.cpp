#include "programs/Fill.h"

#include "CLI/CLI.h"
#include "CLI/TypeParser.h"

#include "Led/CustomLed.h"
#include "wireless/CustomServer.h"

#include "Led/Color.h"
#include <EffectManager.h>

#define COLOR "-color"
#define BRIGHTNESS "-brightness"

void Programs::Fill::setup(){
    Command command = CLI.addCommand("fill", typeCheck);
    command.addPositionalArgument(COLOR);
    command.addPositionalArgument(BRIGHTNESS, "255");
}

void Programs::Fill::typeCheck(cmd* cmd){
    Command command = Command(cmd);
    
    Led::Color color = typeParser.toColor(command.getArgument(COLOR));
    int brightness = typeParser.toInt(command.getArgument(BRIGHTNESS), 0, 255);

    typeParser.setCallback([color, brightness](){
        effectManager.reset();
        Lamp.fill(rawColor(lerp(brightness/255.0, Led::Color{0, 0, 0}, color)));
        Server.sendAnswer("success fill");
    });
}