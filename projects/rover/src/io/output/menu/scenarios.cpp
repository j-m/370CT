#include "io.h"

void IO::Output::Menu::scenarios() {
  IO::Output::messages.buffer.push_back("Scenarios menu");
  IO::Output::messages.buffer.push_back("1. Obstacle");
  IO::Output::messages.buffer.push_back("2. Freewheel");
  IO::Output::messages.buffer.push_back("3. Unresponsive wheel");
}
