#include "global.h"
#include "simulation/Rover.h"
#include "simulation/RoverControlHierarchy.h"
#include "simulation/WheelState.h"

void Rover::resolve() {
  while (Global::running.get() && this->running->get()) {
    this->control.waitForControl(ControlHierarchy::RESOLVE);
    // log chosen solution
    // ground control 100% success
    // log solution success
    this->control.giveControlTo(ControlHierarchy::OVERSEER);
  }
}
