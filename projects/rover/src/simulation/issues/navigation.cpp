#include "global.h"
#include "simulation/Rover.h"

void Rover::checkForNavigationIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::NAVIGATION);
    for (WheelState state : this->states.get()) {
      if (state == WheelState::BLOCKED_LARGE_OBSTACLE) {
        this->command = RoverCommands::CHANGE_DIRECTION;
        this->control.giveControlTo(ControlHierarchy::RESOLVE);
      }
    }
    this->control.giveControlTo(ControlHierarchy::NAVIGATION + 1);
  }
}
