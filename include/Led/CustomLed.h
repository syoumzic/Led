#pragma once

#include "Led/Color.h"
#include <Adafruit_NeoPixel.h>

namespace Led {
    class CustomLed : public Adafruit_NeoPixel{
        public:
            CustomLed();
            void setup();
            void fill(uint32_t color);
            void setPixelColor(uint16_t position, uint32_t color);
    };

}

extern Led::CustomLed Lamp;