#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::checkForWheelStateIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::WHEEL_STATE);
    for (WheelState state : this->states.get() {
      if (state == WheelState::FAILURE) {
        this->resolution = RoverCommands::CALL_FOR_HELP;
        this->control.giveControlTo(ControlHierarchy::RESOLVE);
      }
    }
    this->control.giveControlTo(ControlHierarchy::WHEEL_STATE + 1);
  }   
}
