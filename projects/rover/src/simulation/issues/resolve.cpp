#include <random>

#include "global.h"
#include "simulation/Rover.h"
#include "io.h"

extern std::default_random_engine generator;

void Rover::resolve() {
  while (Global::running && this->running()) {
    this->control.waitForControl(ControlHierarchy::RESOLVE);
    
    IO::Output::control.waitForControl(Control::PRODUCER);
    IO::Output::messageBuffer = {"Chosen solution: ", std::to_string(this->command)};
    IO::Output::control.giveControlTo(Control::CONSUMER);
    
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
    IO::Output::messageBuffer = { success ? "SUCCESSFUL" : "UNSUCCESSFUL"};
    IO::Output::control.giveControlTo(Control::CONSUMER);
    
    this->encountered.set(this->encountered.get() + 1);
    this->control.giveControlTo(ControlHierarchy::ISSUER);
  }
}
