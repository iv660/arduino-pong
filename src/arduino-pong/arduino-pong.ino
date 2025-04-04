#include <ApplianceFactory.h>
#include <Appliance.h>

using XC::Hardware::Appliance;
using XC::SlimPad::ApplianceFactory;

ApplianceFactory applianceFactory;
Appliance appliance;

void setup() {
    applianceFactory.useJoystick().asAnalogJoystick();
    appliance = applianceFactory.createAppliance();
}

void loop() {
    
}