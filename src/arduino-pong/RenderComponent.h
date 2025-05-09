#pragma once

#include "SpriteInterface.h"
#include "Position.h"

struct Entity;

struct RenderComponent
{
    SpriteInterface* sprite;
    Position previousPosition = {-1, -1};
    Entity* entity;
    bool isBackground = false;
    bool redrawIsRequested = false;
};
