#include "io.h"

#include <iostream>

void IO::Output::Menu::introduction() {
  IO::Output::messages.waitForControl(Control::PRODUCER);
  IO::Output::messages.buffer.push_back("At any time press");
  IO::Output::messages.buffer.push_back("  n for a new simulation");
  IO::Output::messages.buffer.push_back("  q to quit");
  IO::Output::messages.waitForControl(Control::CONSUMER);
}
