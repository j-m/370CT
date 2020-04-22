#include "global.h"
#include "simulation/Rover.h"
#include "io.h"

void Rover::resolve() {
  while (Global::running.get() && this->running()) {
    this->control.waitForControl(ControlHierarchy::RESOLVE);
    
    IO::Output::control.waitForControl(Control::PRODUCER);
    IO::Output::messageBuffer = {"Chosen solution: ", std::to_string(this->command)};
    IO::Output::control.giveControlTo(Control::CONSUMER);
    
    // log chosen solution
    // ground control 100% success
    // log solution success
    // encountered++
    this->control.giveControlTo(ControlHierarchy::ISSUER);
  }
}
