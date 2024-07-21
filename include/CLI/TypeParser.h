#pragma once 

#include <SimpleCLI.h>
#include "Led/Color.h"

class TypeParser {
    private:
        bool hasError;
    public:
        TypeParser();
        int toInt(Argument argument, int lowerBound, int upperBound);
        Led::Color toColor(Argument argument);
        void setCallback(const std::function<void(void)>& callback);
    private:
        int invalidInteger(Argument &argument, int lowerBound, int upperBound);
        Led::Color invalidColor(Argument& argument);
};

extern TypeParser typeParser;