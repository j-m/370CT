#include "io.h"

std::thread IO::Input::listener;
std::thread IO::Input::handler;
char IO::Input::keyboardBuffer;
InterThreadControl IO::Input::control;

void IO::Input::initialise() {
  IO::Input::listener = std::thread(IO::Input::listenToKeyPress);
  IO::Input::handler = std::thread(IO::Input::Menu::poll);
}
 
void IO::Input::join() {
  IO::Input::control.notify();
  IO::Input::listener.join();
  IO::Input::handler.join();
}
