#include "global.h"
#include "io.h"
#include "simulation/Rover.h"

void Rover::checkNumberOfIssues() {
  while (true) {
    this->control.waitForControl(ControlHierarchy::NUMBER_ISSUES);
    if (!Global::running || this->finished) {
      break;
    }
    
    unsigned int numberOfIssues = 0;
    for (WheelState state : this->states.get()) {
      if (state != WheelState::OK) {
        numberOfIssues++;
      }
    }
    if (numberOfIssues == 0) {
      this->command = RoverCommands::NONE;
      this->control.giveControlTo(ControlHierarchy::RESOLVE); 
    } else if (numberOfIssues > 1) {
      this->command = RoverCommands::CALL_FOR_HELP;
      this->control.giveControlTo(ControlHierarchy::RESOLVE);
    } else {
      this->control.giveControlTo(ControlHierarchy::NUMBER_ISSUES + 1);
    }
  }
}
