#include "io.h"

void IO::Output::Menu::modes() {
  IO::Output::console("Mode menu");
  IO::Output::console("1. Random (single event)");
  IO::Output::console("2. Simulation (several random occurrences)");
  IO::Output::console("3. Automatic (1-3 sequentially)");
  for (int seconds = 5; seconds > 0; --seconds) {
    IO::Output::console("\rUse 1-6 to select a scenario. Scenario 6 will automatically run in 5 second(s). Press any key to cancel"); // TODO
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
