#include "global.h"
#include "simulation/Rover.h"

void Rover::oversee() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::OVERSEER);
    this->command = RoverCommands::NONE;
    unsigned int wheelsWithIssue = 0;
    for (WheelState state : this->states.get()) {
      if (state != WheelState::OK) {
        wheelsWithIssue++;
      }
    }
    if (wheelsWithIssue > 0) {
      this->control.giveControlTo(ControlHierarchy::OVERSEER + 1);
    }
  }
}
