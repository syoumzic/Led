#pragma once

#include "effects/Effect.h"

namespace Effects {
    class Rainbow : public Effect{
        private:
            int speedFactor, saturationFactor, valueFactor;
        public:
            Rainbow(int speed, int saturation, int value);
            void update();
            String getName() const;
    };
}