#include "global.h"
#include "io.h"
#include "simulation/Rover.h"

void Rover::checkNumberOfIssues() {
  while (Global::running && this->running()) {
    this->control.waitForControl(ControlHierarchy::NUMBER_ISSUES);
    unsigned int numberOfIssues = 0;
    for (WheelState state : this->states.get()) {
      if (state != WheelState::OK) {
        numberOfIssues++;
      }
    }
    if (numberOfIssues == 0) {
      this->command = RoverCommands::NONE;
      IO::Output::control.waitForControl(Control::PRODUCER);
      IO::Output::messageBuffer = {"No issues detected"};
      IO::Output::control.giveControlTo(Control::CONSUMER);  
      this->control.giveControlTo(ControlHierarchy::ISSUER); 
    } else if (numberOfIssues > 1) {
      this->command = RoverCommands::CALL_FOR_HELP;
      this->control.giveControlTo(ControlHierarchy::RESOLVE);
    } else {
      this->control.giveControlTo(ControlHierarchy::NUMBER_ISSUES + 1);
    }
  }
}
