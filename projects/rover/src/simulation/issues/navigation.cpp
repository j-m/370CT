#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::checkForNavigationIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::NAVIGATION);
    for (WheelState state : this->states.get() {
      if (state == WheelState::BLOCKED_LARGE_OBSTACLE) {
        this->resolution = RoverCommands::CHANGE_DIRECTION;
        this->control.giveControlTo(ControlHierarchy::RESOLVE);
      }
    }
    this->control.giveControlTo(ControlHierarchy::NAVIGATION + 1);
  }
}
