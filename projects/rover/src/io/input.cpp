#include "io.h"

ProducerConsumer<char> IO::Input::keyboard;

void IO::Input::initialise() {
  ThreadWrapper listener = ThreadWrapper(std::thread(IO::Input::listenToKeyPress));
  ThreadWrapper handler = ThreadWrapper(std::thread(IO::Input::Menu::poll));
  IO::Input::keyboard.initialise(listener, handler);
}
 
void IO::Input::join() {
  IO::Input::keyboard.join();
}
