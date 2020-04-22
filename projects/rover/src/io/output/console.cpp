#include <iostream>

#include "global.h"
#include "io.h"

void IO::Output::console() {
  while (Global::running.get()) {
    IO::Output::control.waitForControl(Control::CONSUMER);
    for (std::string message: IO::Output::messageBuffer) {
      std::cout << message << std::endl;
    }
    IO::Output::messageBuffer = {};
    IO::Output::control.giveControlTo(Control::PRODUCER);
  }
}
