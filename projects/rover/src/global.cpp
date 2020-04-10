#include "global.h"
#include "io.h"
#include "simulations.h"

InterThreadVariable<bool> Global::running;

void Global::initialise() {
  if (Global::running.get()) {
    return;
  }
  Global::running.set(true);
  IO::initialise();
  Simulations::initialise();
}

void Global::quit() {
  Global::running.set(false);
}

void Global::join() {
  IO::join();
  Simulations::join();
}
