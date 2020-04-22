#include "global.h"
#include "io.h"
#include "simulations.h"

std::atomic<bool> Global::running;

void Global::initialise() {
  if (Global::running) {
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
  Simulations::join();
  IO::join();
}
