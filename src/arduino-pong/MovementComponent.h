#pragma once

struct MovementComponent {
    struct AxisMovement {
        int velocity;
        long updatedAtMillis;
    };

    AxisMovement xMovement = {0, 0};
    AxisMovement yMovement = {0, 0};

    long updateIntervalBase = 20;
};