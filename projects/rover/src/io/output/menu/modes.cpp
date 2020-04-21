#include "io.h"

void IO::Output::Menu::modes() {
  IO::Output::messages.buffer.push_back("Mode menu");
  IO::Output::messages.buffer.push_back("1. Random (single event)");
  IO::Output::messages.buffer.push_back("2. Simulation (several random occurrences)");
  IO::Output::messages.buffer.push_back("3. Automatic (1-3 sequentially)");
  IO::Output::messages.waitForControl(Control::CONSUMER);
  for (int seconds = 5; seconds > 0; --seconds) {
    IO::Output::messages.waitForControl(Control::PRODUCER);
    IO::Output::messages.buffer.push_back("\rUse 1-6 to select a scenario. Scenario 6 will automatically run in 5 second(s). Press any key to cancel"); // TODO
    IO::Output::messages.waitForControl(Control::CONSUMER);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
