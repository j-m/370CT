#include "global.h"
#include "simulation/Rover.h"
#include "io.h"

void Rover::resolve() {
  while (Global::running.get() && this->running()) {
    this->control.waitForControl(ControlHierarchy::RESOLVE);
    
    std::vector<std::string> messages = {"Chosen solution: ", std::to_string(this->command)};
    IO::Output::messages.waitForControl(Control::PRODUCER);
    IO::Output::messages.set(messages);
    IO::Output::messages.giveControlTo(Control::CONSUMER);
    
    // log chosen solution
    // ground control 100% success
    // log solution success
    // encountered++
    this->control.giveControlTo(ControlHierarchy::ISSUER);
  }
}
