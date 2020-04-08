#include "io.h"

void IO::initialise() {
  IO::Input::initialise();
  IO::Output::initialise();
}
 
void IO::join() {
  IO::Input::join();
  IO::Output::join();
}
