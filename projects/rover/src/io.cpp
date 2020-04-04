#include "io.h"

IO::initialise() {
  Input::initialise();
  Output::initialise();
}
 
IO::terminate() {
  Input::terminate();
  Output::terminate();
}
