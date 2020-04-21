#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::checkForWheelStateIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::WHEEL_STATE);
    
    this->control.giveControlTo(ControlHierarchy::WHEEL_STATE + 1);
  }   
}
