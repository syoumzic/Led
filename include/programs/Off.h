#pragma once 

#include <SimpleCLI.h>

namespace Programs {
    class Off{
        public:
            static void setup();
            static void execute(cmd* cmd);
    };
}