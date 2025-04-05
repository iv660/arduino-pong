#pragma once

#include "SpriteInterface.h"

struct RenderComponent
{
    SpriteInterface* sprite;
    Position previousPosition;
};
