#include "io/input.h"

void Input::initialise() {
  std::thread listener = std::thread(Input::listenToKeyPress);
  std::thread handler = std::thread(Input::handleKeyPress);
}

void Input::terminate() {
  listener.join();
  handler.join();
}

