#include "global.h"
#include "simulation/Rover.h"

void Rover::checkForWheelMotionIssues() {
  while (Global::running && this->running()) {
    this->control.waitForControl(ControlHierarchy::WHEEL_MOTION);
    WheelState issue;
    for (WheelState state : this->states.get()) {
      if (state != WheelState::OK) {
        issue = state;
      }
    }
    if (issue == WheelState::FREEWHEELING) {
      this->command = RoverCommands::CHANGE_DIRECTION;
      this->control.giveControlTo(ControlHierarchy::RESOLVE);
    } else {
      this->control.giveControlTo(ControlHierarchy::WHEEL_MOTION + 1);
    }
  }  
}
