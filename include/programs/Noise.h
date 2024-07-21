#pragma once

#include <SimpleCLI.h>

namespace Programs{
    class Noise{
        public:
            static void setup();
            static void typeCheck(cmd* cmd);
    };
}