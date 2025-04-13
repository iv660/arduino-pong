#pragma once

#include "Entity.h"

struct GoalComponent {
    Entity* entity;
    Entity* service;
    int height = 0;
};
