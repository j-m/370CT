#include "io.h"

std::thread IO::Input::listener;
std::thread IO::Input::handler;
ProducerConsumer<char> IO::Input::keyboard;

void IO::Input::initialise() {
  IO::Input::listener = std::thread(IO::Input::listenToKeyPress);
  IO::Input::handler = std::thread(IO::Input::Menu::poll);
  IO::Input::keyboard.initialise(&listener,  &handler);
}
 
void IO::Input::join() {
  IO::Input::keyboard.join();
}
