#pragma once

#include <Arduino.h>

namespace Effects {
    class Effect {
        public:
            virtual ~Effect();
            virtual void update() = 0;
            virtual String getName() const = 0;
    };
}