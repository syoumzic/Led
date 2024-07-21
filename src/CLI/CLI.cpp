#include "CLI/CLI.h"

#include "programs/Fill.h"
#include "programs/Noise.h"
#include "programs/Off.h"
#include "programs/Rainbow.h"

#include "wireless/CustomServer.h"
#include "Format.h"

using namespace Programs;

void CustomCLI::setup(){
    Fill::setup();
    Noise::setup();
    Off::setup();
    Rainbow::setup();

    mCLI.setOnError(errorCallback);
}

Command CustomCLI::addCommand(const char *name, void (*callback)(cmd *c)){
    return mCLI.addCommand(name, callback);
}

void CustomCLI::errorCallback(cmd_error *e){
    CommandError cmdError(e);

    Server.sendAnswer(format("ERROR: %s", cmdError.toString().c_str()));

    if (cmdError.hasCommand()) {
        Server.sendAnswer(format("Command: %s", cmdError.getCommand().toString().c_str()));
    }
}

void CustomCLI::parse(String &input){
    mCLI.parse(input);
}
void CustomCLI::parse(const char *input){
    mCLI.parse(input);
}
void CustomCLI::parse(const char *input, size_t input_len){
    mCLI.parse(input, input_len);
}
CustomCLI CLI;