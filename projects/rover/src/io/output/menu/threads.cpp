#include "io.h"

void IO::Output::Menu::threads() {
  IO::Output::console("Thread menu");
  //if (simulations.size() == 0) {  // TODO
    IO::Output::console("There are currently no simulations running.");
    return; 
  //}
  IO::Output::console("There are currently 0 simulations running.");  // TODO
  IO::Output::console("Enter a number 1-1 to isolate output from that simulation.");
}
   