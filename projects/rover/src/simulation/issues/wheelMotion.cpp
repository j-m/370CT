#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::checkForWheelMotionIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::WHEEL_MOTION);
    
    this->control.giveControlTo(ControlHierarchy::WHEEL_MOTION + 1);
  }  
}
