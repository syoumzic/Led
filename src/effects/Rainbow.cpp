#include "effects/Rainbow.h"

#include <EffectManager.h>
#include "Led/CustomLed.h"

Effects::Rainbow::Rainbow(int speed, int saturation, int value): speedFactor(speed * 0.025f),
                                                                 saturationFactor(saturation),
                                                                 valueFactor(value) {}

void Effects::Rainbow::update(){
    int tick = effectManager.getUpdateCount() * speedFactor;
    Lamp.fill(Lamp.ColorHSV(tick % 65536, saturationFactor, valueFactor));
}
String Effects::Rainbow::getName() const{
    return "rainbow";
}