#include "io.h"

ProducerConsumer<char> IO::Input::keyboard;

void IO::Input::initialise() {
  IO::Input::keyboard.initialise(IO::Input::listenToKeyPress, IO::Input::Menu::poll);
}
 
void IO::Input::join() {
  IO::Input::keyboard.join();
}
