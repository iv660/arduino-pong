#pragma once

struct MovementComponent {
    struct Velocity {
        int x;
        int y;
    };

    Velocity velocity;

    long updatePeriod = 10;

    long xUpdatedAtMillis = 0;
    long yUpdatedAtMillis = 0;
};