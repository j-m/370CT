#include "io.h"

void IO::Input::Menu::modes() {
  std::cout << "Mode menu" << std::endl;
  std::cout << "1. Random (single event)" << std::endl;
  std::cout << "2. Simulation (several random occurrences)" << std::endl;
  std::cout << "3. Automatic (1-3 sequentially)" << std::endl;
  for (int seconds = 5; seconds > 0; --seconds) {
    std::cout << "\r" << "Use 1-6 to select a scenario. Scenario 6 will automatically run in " << seconds << "second(s). Press any key to cancel" << std::flush;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
