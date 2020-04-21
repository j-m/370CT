#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::checkForNavigationIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::NAVIGATION);
    
    this->control.giveControlTo(ControlHierarchy::NAVIGATION + 1);
  }
}
