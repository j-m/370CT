#include "global.h"
#include "simulation/Rover.h"

void Rover::checkForWheelHeightIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::WHEEL_MOTION);
    WheelState issue;
    for (WheelState state : this->states.get()) {
      if (state != WheelState::OK) {
        issue = state;
      }
    }    
    if (issue == WheelState::BLOCKED_SMALL_OBSTACLE) {
      this->command = RoverCommands::RAISE_WHEEL;
      this->control.giveControlTo(ControlHierarchy::RESOLVE);
    }
    else if (issue == WheelState::SUSPENDED) {
      this->command = RoverCommands::LOWER_WHEEL;
      this->control.giveControlTo(ControlHierarchy::RESOLVE);
    } 
    else {
      this->control.giveControlTo(ControlHierarchy::WHEEL_MOTION + 1);
    }
  }
}
