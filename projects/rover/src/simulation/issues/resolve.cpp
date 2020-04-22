#include <random>

#include "global.h"
#include "simulation/Rover.h"
#include "io.h"

extern std::default_random_engine generator;

void Rover::resolve() {
  while (this) {
    this->control.waitForControl(ControlHierarchy::RESOLVE);
    if (!Global::running || this->finished) {
      break;
    }
    
    if (this->command == RoverCommands::NONE) {
      IO::Output::control.waitForControl(Control::PRODUCER);
      IO::Output::messageBuffer = {"No issues detected",""};
      IO::Output::control.giveControlTo(Control::CONSUMER);  
      
      IO::Output::fileControl.waitForControl(Control::PRODUCER);
      IO::Output::fileBuffer = {"No issues detected",""};
      IO::Output::fileControl.giveControlTo(Control::CONSUMER);
    } else {
      IO::Output::control.waitForControl(Control::PRODUCER);
      IO::Output::messageBuffer = {"Solution: " + RoverCommandsToString[this->command]};
      IO::Output::control.giveControlTo(Control::CONSUMER);
      
      IO::Output::fileControl.waitForControl(Control::PRODUCER);
      IO::Output::fileBuffer = {"Solution: " + RoverCommandsToString[this->command]};
      IO::Output::fileControl.giveControlTo(Control::CONSUMER);
      
      bool success = false;
      if(this->command == RoverCommands::CALL_FOR_HELP) {
        success = true;
      } else {
        std::uniform_int_distribution<int> resolved(0, 100);
        if (resolved(generator) > Global::Constants::PERCENTAGE_PROBABILITY_RESOLVE_ISSUE) {
          success = true;
        }
      }
      
      IO::Output::control.waitForControl(Control::PRODUCER);
      IO::Output::messageBuffer = { success ? "SUCCESSFUL" : "UNSUCCESSFUL",""};
      IO::Output::control.giveControlTo(Control::CONSUMER);
  
      IO::Output::fileControl.waitForControl(Control::PRODUCER);
      IO::Output::fileBuffer = { success ? "SUCCESSFUL" : "UNSUCCESSFUL",""};
      IO::Output::fileControl.giveControlTo(Control::CONSUMER);
      
      if (this->encountered++ == Global::Constants::PROBLEMS_PER_SIMULATION) {
        this->finished = true;
      }
    }
    
    this->control.giveControlTo(ControlHierarchy::ISSUER);
  }
}
