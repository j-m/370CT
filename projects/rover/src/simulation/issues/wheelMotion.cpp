#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::checkForWheelMotionIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::WHEEL_MOTION);
    WheelState issue;
    for (WheelState state : this->states.get() {
      if (state != WheelState::OK) {
        issue = state;
      }
    }   
    if (state == WheelState::FREEWHEELING) {
      this->resolution = RoverCommands::CHANGE_DIRECTION;
      this->control.giveControlTo(ControlHierarchy::RESOLVE);
    } else {
      this->control.giveControlTo(ControlHierarchy::WHEEL_MOTION + 1);
    }
  }  
}
