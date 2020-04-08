#include "global.h"
#include "io.h"

void IO::Input::Menu::parseKey(char command) {
  switch(command) {
    case 'm':
      IO::Output::Menu::modes();
      break;
    case 'q':
      Global::terminate();
      break;
    case 's':
      IO::Output::Menu::scenarios();
      break;
    case 't':
      IO::Output::Menu::threads();
      break;
    case 'n':
      //IO::Output::Menu::simulations.push_back(new Simulation());
      break;
    default:
      break;
  }
}
