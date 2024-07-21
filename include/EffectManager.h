#pragma once

#include <memory>
#include "effects/Effect.h"

class EffectManager {
    private:
        std::unique_ptr<Effects::Effect> mEffect;
        unsigned long long updateCount;
    public:
        EffectManager();
        void update();
        void set(Effects::Effect* pEffect);
        Effects::Effect* get();
        void reset();
        unsigned long long getUpdateCount();
};

extern EffectManager effectManager;