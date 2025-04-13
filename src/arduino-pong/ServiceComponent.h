#pragma once

#include "Entity.h"

struct ServiceComponent {
    Entity *entity = nullptr;
    int serviceXVelocity = 0;
    bool isRequested = false;
    long serveAtMillis = 0;
};

