#pragma once

#include <ScreenInterface.h>

#include "Position.h"

using XC::Hardware::ScreenInterface;

class SpriteInterface {
    public:
        virtual void drawOn(ScreenInterface* screen, Position position) = 0;
        virtual void eraseFrom(ScreenInterface* screen, Position position) = 0;
};