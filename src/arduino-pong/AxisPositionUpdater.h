#pragma once

#include "Entity.h"
#include "MovementComponent.h"

class AxisPositionUpdater {
    private:
        long updateIntervalBase = 20;
        MovementComponent::AxisMovement *axisMovement;
        int *axisPosition;

        long getTimeSinceLastUpdate();
        long getUpdateInterval();
        bool isTimeToUpdate();

    public:
        AxisPositionUpdater(
            MovementComponent::AxisMovement *axisMovement, 
            int *axisPosition, 
            long updateIntervalBase
        ):  axisMovement(axisMovement), 
            axisPosition(axisPosition), 
            updateIntervalBase(updateIntervalBase) {};

        void updatePosition();
};
