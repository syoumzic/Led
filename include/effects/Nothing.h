#pragma once

#include "effects/Effect.h"

namespace Effects {
    class Nothing : public Effect{
        public:
            void update();
            String getName() const;
    };
}