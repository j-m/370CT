#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::oversee() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::OVERSEER);
    unsigned int wheelsWithIssue = 0;
    for (WheelState state : this->states.get() {
      if (state != WheelState::OK) {
        wheelsWithIssue++;
      }
    }
    if (wheelsWithIssue > 0) {
      this->control.giveControlTo(ControlHierarchy::OVERSEER + 1);
    }
  }
}
