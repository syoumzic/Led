#pragma once

#include "effects/Effect.h"
#include "Led/Color.h"

namespace Effects {
    class Noise: public Effect{
        private:
            double speedFactor, smoothingFactor, contrastFactor, shiftFactor;
            Led::Color lowerColor, upperColor;
        public:
            Noise(int speed, int smooth, int contrast, int level, Led::Color lowerColor, Led::Color upperColor);
            void update();
            String getName() const;
        private:
            double fade(double t);
            double grad(int hash, double x, double y, double z);
            double fnoise(double x, double y, double z);
            double pnoise(double x, double y, double z);
    };
}