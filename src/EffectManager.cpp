#include "EffectManager.h"
#include "effects/Nothing.h"

EffectManager::EffectManager(): mEffect(new Effects::Nothing()),
                                updateCount(0) {}

void EffectManager::update(){
    mEffect->update();
    updateCount += 1;
    delay(16);
}

void EffectManager::set(Effects::Effect* pEffect){
    mEffect.reset(pEffect);
    Serial.printf("LOG: set effect '%s'\n", pEffect->getName().c_str());
}

Effects::Effect* EffectManager::get(){
    return mEffect.get();
}

void EffectManager::reset(){
    set(new Effects::Nothing());
}

unsigned long long EffectManager::getUpdateCount(){
    return updateCount;
}

EffectManager effectManager;