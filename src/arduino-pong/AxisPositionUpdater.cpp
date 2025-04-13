#include "AxisPositionUpdater.h"

#include <Arduino.h>
#include <math.h>

void AxisPositionUpdater::updatePosition()
{
    if (isTimeToUpdate())
    {
        *axisPosition += copysign(1, axisMovement->velocity);
        axisMovement->updatedAtMillis = millis();
    }
}

long AxisPositionUpdater::getTimeSinceLastUpdate()
{
    return millis() - axisMovement->updatedAtMillis;
}

bool AxisPositionUpdater::isTimeToUpdate()
{
    if (axisMovement->velocity == 0) {
        return false;
    }
    
    return getTimeSinceLastUpdate() > getUpdateInterval();
}

long AxisPositionUpdater::getUpdateInterval()
{
    return updateIntervalBase / abs(axisMovement->velocity);
}