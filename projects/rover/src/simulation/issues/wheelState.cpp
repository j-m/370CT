#include "global.h"
#include "simulation/Rover.h"

void Rover::checkForWheelStateIssues() {
  while (true) {
    this->control.waitForControl(ControlHierarchy::WHEEL_STATE);
    if (!Global::running || this->finished) {
      break;
    }
    for (WheelState state : this->states.get()) {
      if (state == WheelState::FAILURE) {
        this->command = RoverCommands::CALL_FOR_HELP;
        this->control.giveControlTo(ControlHierarchy::RESOLVE);
      }
    }
    this->control.giveControlTo(ControlHierarchy::WHEEL_STATE + 1);
  }   
}
