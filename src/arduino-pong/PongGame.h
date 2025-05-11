#pragma once

#include "StageInterface.h"

class PongGame {
    private:
        StageInterface* stage;

    public:
        void init();
        void tick();
};
