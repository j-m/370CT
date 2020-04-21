#include "io.h"

ProducerConsumer<char> IO::Input::keyboard;

void IO::Input::initialise() {
  IO::Input::keyboard.initialise(
    &std::thread(IO::Input::listenToKeyPress), 
    &std::thread(IO::Input::Menu::poll)
  );
}
 
void IO::Input::join() {
  IO::Input::keyboard.join();
}
