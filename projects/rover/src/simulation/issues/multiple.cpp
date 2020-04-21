#include "global.h"
#include "simulation/Rover.h"

void Rover::checkForMultipleIssues() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::MULTIPLE_ISSUES);
    unsigned int numberOfIssues = 0;
    for (WheelState state : this->states.get()) {
      if (state != WheelState::OK) {
        numberOfIssues++;
      }
    }
    if (numberOfIssues > 1) {
      this->command = RoverCommands::CALL_FOR_HELP;
      this->control.giveControlTo(ControlHierarchy::RESOLVE);
    } else {
      this->control.giveControlTo(ControlHierarchy::MULTIPLE_ISSUES + 1);
    }
  }
}
