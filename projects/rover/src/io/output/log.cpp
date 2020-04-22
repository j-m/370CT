#include <iostream>
#include <fstream>

#include "global.h"
#include "io.h"

void IO::Output::log() {
  while (true) {
    IO::Output::fileControl.waitForControl(Control::CONSUMER);
    if (!Global::running) {
      break;
    }
    for (std::string message: IO::Output::fileBuffer) {
      IO::Output::file << message << std::endl;
    }
    IO::Output::fileBuffer = {};
    IO::Output::fileControl.giveControlTo(Control::PRODUCER);
  }
}
