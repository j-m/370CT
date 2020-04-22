#include <iostream>

#include "global.h"
#include "io.h"

void IO::Output::console() {
  while (Global::running.get()) {
    IO::Output::messages.waitForControl(Control::CONSUMER);
    for (std::string message: IO::Output::messages.get()) {
      std::cout << message << std::endl;
    }
    IO::Output::messages.set({});
    IO::Output::messages.giveControlTo(Control::PRODUCER);
  }
}
