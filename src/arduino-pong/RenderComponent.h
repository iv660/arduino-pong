#pragma once

#include "SpriteInterface.h"

struct Entity;

struct RenderComponent
{
    SpriteInterface* sprite;
    Position previousPosition = {-1, -1};
    Entity* entity;
};
