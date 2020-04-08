#include "io.h"

void IO::initialise() {
  IO::Input::initialise();
  IO::Output::initialise();
}
 
void IO::terminate() {
  IO::Input::terminate();
  IO::Output::terminate();
}
