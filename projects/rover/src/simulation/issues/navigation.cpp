#include "global.h"
#include "simulation/Rover.h"

void Rover::checkForNavigationIssues() {
  while (true) {
    this->control.waitForControl(ControlHierarchy::NAVIGATION);
    if (!Global::running || this->finished) {
      break;
    }
    
    for (WheelState state : this->states.get()) {
      if (state == WheelState::BLOCKED_LARGE_OBSTACLE) {
        this->command = RoverCommands::CHANGE_DIRECTION;
        this->control.giveControlTo(ControlHierarchy::RESOLVE);
      }
    }
    this->control.giveControlTo(ControlHierarchy::NAVIGATION + 1);
  }
}
