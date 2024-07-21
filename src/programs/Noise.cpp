#include "programs/Noise.h"

#include "CLI/CLI.h"
#include "CLI/TypeParser.h"

#include "effects/Noise.h"
#include "EffectManager.h"
#include "wireless/CustomServer.h"

#define SPEED "-speed"       //--speed
#define SMOOTH "-smooth"     //--smooth
#define CONTRAST "-contrast" //--contrast
#define LEVEL "-level"       //--level
#define COLOR1 "-color1"     //--color1
#define COLOR2 "-color2"     //--color2

using namespace Programs;

void Noise::setup(){
    Command command = CLI.addCommand("noise", Noise::typeCheck);
    
    command.addArgument(SPEED, "1000");
    command.addArgument(SMOOTH, "100");
    command.addArgument(CONTRAST, "15");
    command.addArgument(LEVEL, "50");
    command.addPositionalArgument(COLOR1, "#000000");
    command.addPositionalArgument(COLOR2, "#2f22f2");
}
void Noise::typeCheck(cmd *cmd){
    Command command(cmd);

    int speed = typeParser.toInt(command.getArgument(SPEED), 0, 10000);
    int smooth = typeParser.toInt(command.getArgument(SMOOTH), 0, 10000);
    int contrast = typeParser.toInt(command.getArgument(CONTRAST), 1, 15);
    int level = typeParser.toInt(command.getArgument(LEVEL), 0, 100);
    Led::Color color1 = typeParser.toColor(command.getArgument(COLOR1));
    Led::Color color2 = typeParser.toColor(command.getArgument(COLOR2));

    typeParser.setCallback([speed, smooth, contrast, level, color1, color2](){
        Server.sendAnswer("success noise set");
        effectManager.set(new Effects::Noise(speed, smooth, contrast, level, color1, color2));
        });
}