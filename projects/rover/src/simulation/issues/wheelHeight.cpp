#include "global.h"
#include "simulation/Rover.h"

void Rover::checkForWheelHeightIssues() {
  while (Global::running && this->running()) {
    this->control.waitForControl(ControlHierarchy::WHEEL_HEIGHT);
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
      this->control.giveControlTo(ControlHierarchy::WHEEL_HEIGHT + 1);
    }
  }
}
