#pragma once

struct MovementComponent {
    struct Velocity {
        int x;
        int y;
    };

    struct AxisMovement {
        int velocity;
        long updatedAtMillis;
    };

    AxisMovement xMovement = {0, 0};
    AxisMovement yMovement = {0, 0};

    Velocity velocity;

    long updateIntervalBase = 20;

    long xUpdatedAtMillis = 0;
    long yUpdatedAtMillis = 0;
};