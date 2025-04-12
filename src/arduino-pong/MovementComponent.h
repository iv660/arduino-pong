#pragma once

struct MovementComponent {
    struct Velocity {
        int x;
        int y;
    };

    // struct AxisMovementState {
    //     int velocity;
    //     long updatedAtMillis;
    // }

    // AxisMovementState xMovementState = {0, 0};
    // AxisMovementState yMovementState = {0, 0};

    Velocity velocity;

    long updateIntervalBase = 20;

    long xUpdatedAtMillis = 0;
    long yUpdatedAtMillis = 0;
};