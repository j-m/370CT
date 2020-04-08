#include "global.h"
#include "io.h"
#include "simulations.h"

void Global::initialise() {
  if (Global::running == true) {
    return;
  }
  Global::running = true;
  IO::initialise();
  Simulations::initialise();  
}

void Global::terminate() {
  Global::running = false;
  IO::terminate();
  Simulations::terminate();  
}
