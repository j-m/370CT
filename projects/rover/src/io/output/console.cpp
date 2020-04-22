#include <iostream>

#include "global.h"
#include "io.h"

void IO::Output::console() {
  while (true) {
    IO::Output::control.waitForControl(Control::CONSUMER);
    if (!Global::running) {
      break;
    }
    for (std::string message: IO::Output::messageBuffer) {
      std::cout << message << std::endl;
    }
    IO::Output::messageBuffer = {};
    IO::Output::control.giveControlTo(Control::PRODUCER);
  }
}
