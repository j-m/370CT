#include "global.h"
#include "io.h"
#include "simulations.h"

void IO::Input::Menu::parseKey(char command) {
  switch(command) {
    case 'q':
      Global::quit();
      break;
    case 'n':
      Simulations::start();
      //IO::Output::Menu::modes();
      //IO::Output::Menu::simulations.push_back(new Simulation());
      break;
    default:
      break;
  }
}
