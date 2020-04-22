#include "io.h"

void IO::Output::Menu::scenarios() {
  IO::Output::messageBuffer = {
    "Scenarios menu",
    "█ 1. Obstacle",
    "█ 2. Freewheel",
    "█ 3. Unresponsive wheel"
  };
}
