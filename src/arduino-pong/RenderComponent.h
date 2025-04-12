#pragma once

#include "SpriteInterface.h"

struct RenderComponent
{
    SpriteInterface* sprite;
    Position previousPosition = {-1, -1};
};
