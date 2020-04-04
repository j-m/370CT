#include "io/input.h"

void Input::handleKeyPress() {
  while (true) {
    waitForControl(Input::Control::HANDLER);
    switch(Input::key) {
      case 'm':
        //modes();
        break;
      case 'q':
        quit();
        break;
      case 's':
        //scenarios();
        break;
      case 't':
        threads();
        break;
      case 'n':
        simulations.push_back(new Simulation());
        break;
      default:
        break;
    }
    giveControlTo(Input::Control::LISTENER);
  }
}
