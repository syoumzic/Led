#include "Led/Color.h"

#include <Adafruit_NeoPixel.h>
#include "Format.h"
#include "Math.h"

String Led::Color::toString() const {
    return format("Color{%zu, %zu, %zu}", r, g, b);
}
Led::Color lerp(double t, const Led::Color& color, const Led::Color& other){
    return Led::Color{ 
        lerp(t, color.r, other.r),
        lerp(t, color.g, other.g),
        lerp(t, color.b, other.b)
    };
}

uint32_t rawColor(const Led::Color &color){
    return Adafruit_NeoPixel::Color(color.r, color.g, color.b);
}
