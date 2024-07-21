#include "CLI/TypeParser.h"

#include "Format.h"
#include "wireless/CustomServer.h"
#include <Arduino.h>

TypeParser::TypeParser(): hasError(false) {}

int TypeParser::toInt(Argument argument, int lowerBound, int upperBound){
    if(hasError){
        return 0;
    }

    String strInteger = argument.getValue();
    if(strInteger.isEmpty() || strInteger.length() > 9) {
        return invalidInteger(argument, lowerBound, upperBound);
    }

    if(!isDigit(strInteger[0]) && strInteger[0] != '-') {
        return invalidInteger(argument, lowerBound, upperBound);
    }

    for(int i = 1; i < (int)strInteger.length(); i++){
        if(!isDigit(strInteger[i])) {
            return invalidInteger(argument, lowerBound, upperBound);;
        }
    }

    int result = strInteger.toInt();

    if(result < lowerBound || result > upperBound) {
        return invalidInteger(argument, lowerBound, upperBound);
    }

    return result;
}

Led::Color TypeParser::toColor(Argument argument){
    if(hasError){
        return Led::Color{};
    }

    String strColor = argument.getValue();

    if(strColor.isEmpty()) {
        return invalidColor(argument);
    }

    if(strColor[0] != '#' || strColor.length() != 7) {
        return invalidColor(argument);
    }

    for(int i = 1; i < 7; i++){
        char c = strColor[i];
        if(!(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
            return invalidColor(argument);
        }
    }

    uint8_t r = strtol(strColor.substring(1, 3).c_str(), NULL, 16);
    uint8_t g = strtol(strColor.substring(3, 5).c_str(), NULL, 16);
    uint8_t b = strtol(strColor.substring(5, 7).c_str(), NULL, 16);

    return Led::Color{r, g, b};
}

void TypeParser::setCallback(const std::function<void(void)>& callback){
    if(!hasError){
        callback();
    }
    hasError = false;
}

int TypeParser::invalidInteger(Argument& argument, int lowerBound, int upperBound){
    Server.sendAnswer(format("ERROR: type '-%s' must be integer in range from %d to %d", argument.getName().c_str(), lowerBound, upperBound));
    hasError = true;
    return int();
}

Led::Color TypeParser::invalidColor(Argument& argument){
    Server.sendAnswer(format("ERROR: type '-%s' must be color (#RRGGBB)", argument.getName().c_str()));
    hasError = true;
    return Led::Color();
}

TypeParser typeParser;