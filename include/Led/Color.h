#pragma once

#include <Arduino.h>

namespace Led {
    struct Color{
        uint8_t r, g, b;
        String toString() const;
    };
}

Led::Color lerp(double t, const Led::Color& color, const Led::Color& other);

uint32_t rawColor(const Led::Color& color);