#include "global.h"
#include "io.h"
#include "simulations.h"

bool Global::running = false;

void Global::initialise() {
  if (Global::running == true) {
    return;
  }
  Global::running = true;
  IO::initialise();
  Simulations::initialise();
}

void Global::quit() {
  Global::running = false;
}

void Global::join() {
  IO::join();
  Simulations::join();
}
