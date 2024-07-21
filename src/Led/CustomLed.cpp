#include "Led/CustomLed.h"

#define LENGTH 40
#define PIN 13

Led::CustomLed::CustomLed(): Adafruit_NeoPixel(LENGTH, PIN, NEO_GRB + NEO_KHZ800) {}

void Led::CustomLed::setup(){
  begin();
  fill(rawColor(lerp(200.0/255.0, Led::Color{0,0,0}, Led::Color{12, 112, 190})));
}

void Led::CustomLed::fill(uint32_t color){
  Adafruit_NeoPixel::fill(gamma32(color), 0, LENGTH);
  show();
}

void Led::CustomLed::setPixelColor(uint16_t position, uint32_t color) {
  Adafruit_NeoPixel::setPixelColor(position, gamma32(color));
}

Led::CustomLed Lamp;