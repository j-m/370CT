#include "io.h"

void IO::initialise() {
  IO::Menu.initialise(IO::Input::listenToKeyPress, IO::Output::Menu::poll);
}
 
void IO::terminate() {
  IO::Menu.terminate();
}
