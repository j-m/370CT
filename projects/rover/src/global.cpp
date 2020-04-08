#include "global.h"
#include "io.h"
//#include "simulations.h" //TODO

bool Global::running = false;

void Global::initialise() {
  if (Global::running == true) {
    return;
  }
  Global::running = true;
  IO::initialise();
  //Simulations::initialise(); //TODO
}

void Global::terminate() {
  Global::running = false;
  IO::terminate();
  //Simulations::terminate(); //TODO
}
