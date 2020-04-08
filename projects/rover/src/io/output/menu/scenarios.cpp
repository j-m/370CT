#include "io.h"

void IO::Output::Menu::scenarios() {
  IO::Output::console("Scenarios menu");
  IO::Output::console("1. Obstacle");
  IO::Output::console("2. Freewheel");
  IO::Output::console("3. Unresponsive wheel");
}
