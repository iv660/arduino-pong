#pragma once

#include "Entity.h"

struct GoalComponent {
    Entity* entity;
    Entity* service;
    Entity* score;
    int height = 0;
};
