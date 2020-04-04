#include "io.h"

IO::initialise() {
  Input::initialise();
  Output::initialise();
}
 
IO::terminate() {
  Input::terminate();
  Output::terminate();
}


void initialise() {
  input.initialise();
  display.initialise();
  simulations.initialise();  
}

void terminate() {
  quit = true;
  input.terminate();
  display.terminate();
  simulations.terminate();  
}
