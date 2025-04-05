#pragma once

struct MovementComponent {
    struct Velocity {
        int x;
        int y;
    };

    Velocity velocity;
};